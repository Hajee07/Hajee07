using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace HeadBridge.Mapping.Tests
{
    public sealed class Memory
    {
        private readonly Dictionary<ulong, byte[]> pages = new Dictionary<ulong, byte[]>();
        private ulong nextPage = 0x30000000UL;
        public Action<ulong, int> AfterRead;
        public byte[] Page(ulong address)
        {
            ulong key = address & ~4095UL;
            byte[] data;
            if (!pages.TryGetValue(key, out data)) { data = new byte[4096]; pages.Add(key, data); }
            return data;
        }
        public void Write(ulong address, byte[] data)
        {
            for (int i = 0; i < data.Length; i++) Page(address + (ulong)i)[(address + (ulong)i) & 4095UL] = data[i];
        }
        public void Put64(ulong address, ulong value) { Write(address, BitConverter.GetBytes(value)); }
        public ulong Get64(ulong address) { return BitConverter.ToUInt64(Bytes(address, 8), 0); }
        public byte[] Bytes(ulong address, int count)
        {
            byte[] data = new byte[count];
            for (int i = 0; i < count; i++) data[i] = Page(address + (ulong)i)[(address + (ulong)i) & 4095UL];
            return data;
        }
        public string Transport(ulong address, int count)
        {
            byte[] data = Bytes(address, count);
            if (AfterRead != null) AfterRead(address, count);
            return "BridgeRead=PASS BytesRead=" + count + " Hex=" + BitConverter.ToString(data).Replace("-", "").ToLowerInvariant() + "\n";
        }
        public ulong Child(ulong table, ulong va, int shift)
        {
            ulong slot = table + ((va >> shift) & 511UL) * 8UL;
            ulong value = Get64(slot);
            if ((value & 1) != 0) return value & 0x000ffffffffff000UL;
            ulong child = nextPage; nextPage += 4096; Put64(slot, child | 3UL); return child;
        }
        public void Map4K(ulong root, ulong va, ulong physical)
        {
            ulong pdp = Child(root, va, 39), pd = Child(pdp, va, 30), pt = Child(pd, va, 21);
            Put64(pt + ((va >> 12) & 511UL) * 8UL, physical | 3UL);
        }
        public void Map2M(ulong root, ulong va, ulong physical)
        {
            ulong pdp = Child(root, va, 39), pd = Child(pdp, va, 30);
            Put64(pd + ((va >> 21) & 511UL) * 8UL, physical | 0x83UL);
        }
        public void Map1G(ulong root, ulong va, ulong physical)
        {
            ulong pdp = Child(root, va, 39);
            Put64(pdp + ((va >> 30) & 511UL) * 8UL, physical | 0x83UL);
        }
        public void LoadElf(string path)
        {
            byte[] elf = File.ReadAllBytes(path);
            ulong phoff = BitConverter.ToUInt64(elf, 32);
            int stride = BitConverter.ToUInt16(elf, 54), count = BitConverter.ToUInt16(elf, 56);
            for (int i = 0; i < count; i++)
            {
                int at = checked((int)phoff + stride * i);
                if (BitConverter.ToUInt32(elf, at) != 1) continue;
                ulong fileOffset = BitConverter.ToUInt64(elf, at + 8), physical = BitConverter.ToUInt64(elf, at + 24), size = BitConverter.ToUInt64(elf, at + 32);
                for (ulong used = 0; used < size; used += 4096)
                {
                    int length = (int)Math.Min(4096UL, size - used);
                    Buffer.BlockCopy(elf, checked((int)(fileOffset + used)), Page(physical + used), (int)((physical + used) & 4095UL), length);
                }
            }
        }
    }
    public static class Checks
    {
        private static int count;
        private static void Assert(bool condition, string name)
        {
            if (!condition) throw new Exception("FAIL: " + name);
            count++; Console.WriteLine("PASS: " + name);
        }
        private static void Reject(Action action, string name)
        {
            bool failed = false; try { action(); } catch { failed = true; }
            Assert(failed, name);
        }
        private static void RejectMessage(Action action, string expected, string name)
        {
            bool failed = false;
            try { action(); }
            catch (InvalidOperationException error) { failed = error.Message.Contains(expected); }
            Assert(failed, name);
        }
        private static Reader ReaderFor(Memory memory) { return new Reader(memory.Transport, new RamRange[] { new RamRange(0, 0xffffffffUL) }); }
        private static void TargetedChecks(Memory live, KernelContext kernel, GameProcess game, byte[] header)
        {
            const ulong direct = 0xffff888000000000UL, arenaPhysical = 0x5100000;
            ulong arena = direct + 0x100000;
            const int total = 4500, targetIndex = 799;
            for (ulong offset = 0; offset < (ulong)total * 256UL; offset += 4096)
                live.Map4K(kernel.Root, arena + offset, arenaPhysical + offset);
            for (int i = 0; i < total; i++)
            {
                ulong physical = arenaPhysical + (ulong)i * 256UL;
                live.Put64(physical, 0x10000000UL + (ulong)i * 4096UL);
                live.Put64(physical + 8, 0x10001000UL + (ulong)i * 4096UL);
                live.Put64(physical + 0x10, i == total - 1 ? 0 : arena + (ulong)(i + 1) * 256UL);
                live.Put64(physical + 0x18, i == 0 ? 0 : arena + (ulong)(i - 1) * 256UL);
                live.Put64(physical + 0x98, 0);
                live.Put64(physical + 0xa0, direct + (i == targetIndex ? 0xa000UL : 0xd000UL));
            }
            ulong targetPhysical = arenaPhysical + (ulong)targetIndex * 256UL;
            ulong targetNode = arena + (ulong)targetIndex * 256UL;
            ulong targetStart = 0x10000000UL + (ulong)targetIndex * 4096UL;
            live.Map4K(game.Root, targetStart, 0x6000000);
            live.Put64(0x5006000, arena);
            bool tailRead = false;
            live.AfterRead = delegate(ulong address, int length)
            {
                if (address > targetPhysical && address < arenaPhysical + (ulong)total * 256UL && length == 0xa8)
                    tailRead = true;
            };
            Reader targeted = ReaderFor(live);
            LibraryResult result = targeted.ProbeLibrary(kernel, game, null);
            Assert(result.StopReason == "TARGET_VERIFIED" && !result.CompleteVmaList && result.VmasVisited == 800,
                   "targeted scan stops after the 800th VMA in a 4500-VMA list");
            Assert(result.Mappings.Count == 1 && result.Mappings[0].Revalidated && !tailRead && targeted.PhysicalCalls < 10000,
                   "target is revalidated without traversing the remaining list");
            Console.WriteLine("TARGETED_FIXTURE_READ_CALLS=" + targeted.PhysicalCalls + " VMAS=" + result.VmasVisited + " TOTAL_VMAs=" + total);
            live.AfterRead = null;

            // Mutate the candidate between initial discovery and its final checks.
            // Keep the length consistent so failure specifically tests filename equality.
            Action<string> rename = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Write(0x500c000, Encoding.ASCII.GetBytes(new string('x', "libil2cpp.so".Length) + "\0"));
            };
            Reader renamed = ReaderFor(live);
            RejectMessage(delegate { renamed.ProbeLibrary(kernel, game, rename); }, "filename changed", "target filename changes reject early success");
            Assert(renamed.LastLibraries.StopReason == "INCOMPLETE" && !renamed.LastLibraries.Mappings[0].Revalidated,
                   "failed target revalidation retains provisional status");
            live.Write(0x500c000, Encoding.ASCII.GetBytes("libil2cpp.so\0"));

            Action<string> replace = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Put64(targetPhysical + 0xa0, direct + 0xd000);
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, replace); }, "Target VMA changed", "changed target VMA file object is rejected");
            live.Put64(targetPhysical + 0xa0, direct + 0xa000);
            Action<string> unlink = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Put64(targetPhysical - 256UL + 0x10UL, 0);
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, unlink); }, "predecessor", "detached target is rejected by neighbor link checks");
            live.Put64(targetPhysical - 256UL + 0x10UL, targetNode);
            Action<string> successor = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Put64(targetPhysical + 256UL + 0x18UL, 0);
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, successor); }, "successor", "changed successor backlink is rejected");
            live.Put64(targetPhysical + 256UL + 0x18UL, targetNode);
            Action<string> headerChange = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Write(0x6000000, new byte[] { 0 });
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, headerChange); }, "ELF header changed", "changed target ELF bytes reject early success");
            live.Write(0x6000000, header);
            Action<string> identityChange = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Put64(0x50044c0, direct + 0x7000);
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, identityChange); }, "Game identity", "changed process mm rejects early success");
            live.Put64(0x50044c0, game.Mm);
            int headerReads = 0;
            live.AfterRead = delegate(ulong address, int length)
            {
                if (address == 0x6000000 && length == 20 && ++headerReads == 2)
                    live.Put64(targetPhysical + 8, targetStart + 8192UL);
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, null); }, "Target VMA changed", "VMA mutation during final header read is detected");
            live.AfterRead = null;
            live.Put64(targetPhysical + 8, targetStart + 4096UL);

            // A one-element list covers end-of-list and list-head rechecks.
            live.Put64(0x5006000, targetNode);
            live.Put64(targetPhysical + 0x18, 0); live.Put64(targetPhysical + 0x10, 0);
            Action<string> headChange = delegate(string line)
            {
                if (line.Contains("LibraryCandidate")) live.Put64(0x5006000, arena);
            };
            RejectMessage(delegate { ReaderFor(live).ProbeLibrary(kernel, game, headChange); }, "list head", "detached head VMA is rejected");
            live.Put64(0x5006000, targetNode);
            live.Write(0x6000012, new byte[] { 62 });
            LibraryResult wrongArchitecture = ReaderFor(live).ProbeLibrary(kernel, game, null);
            Assert(wrongArchitecture.StopReason == "END_OF_LIST" && wrongArchitecture.CompleteVmaList && !wrongArchitecture.Mappings[0].Revalidated,
                   "wrong ELF architecture reaches end without target verification");
            live.Write(0x6000000, header);
            live.Put64(targetPhysical + 0x98, 1);
            LibraryResult nonzeroOffset = ReaderFor(live).ProbeLibrary(kernel, game, null);
            Assert(nonzeroOffset.StopReason == "END_OF_LIST" && !nonzeroOffset.Mappings[0].Arm64ElfHeader,
                   "nonzero file offset cannot satisfy the ELF header probe");
            live.Put64(targetPhysical + 0x98, 0);
            live.Write(0x500c000, Encoding.ASCII.GetBytes("libunity.so\0"));
            live.Write(0x500b024, BitConverter.GetBytes("libunity.so".Length));
            // A different ARM64 library cannot satisfy the IL2CPP goal.
            LibraryResult unity = ReaderFor(live).ProbeLibrary(kernel, game, null);
            Assert(unity.StopReason == "END_OF_LIST" && unity.Mappings[0].Arm64ElfHeader && !unity.Mappings[0].Revalidated,
                   "Unity ARM64 header alone does not satisfy the IL2CPP goal");
            live.Write(0x500c000, Encoding.ASCII.GetBytes("libil2cpp.so\0"));
            live.Write(0x500b024, BitConverter.GetBytes("libil2cpp.so".Length));
            LibraryResult first = ReaderFor(live).ProbeLibrary(kernel, game, null);
            Assert(first.StopReason == "TARGET_VERIFIED" && first.Mappings[0].Revalidated,
                   "single head VMA passes targeted verification");
        }
        public static void Run(string elfPath)
        {
            Memory simple = new Memory(); Reader r = ReaderFor(simple);
            simple.Map4K(0x1000, 0x401000, 0x200000);
            Assert(r.Translate(0x1007, 0x401234) == 0x200234, "4 KiB translation strips PCID");
            simple.Map2M(0x1000, 0x800000, 0x800000);
            Assert(r.Translate(0x1000, 0x923456) == 0x923456, "2 MiB page translation");
            simple.Map1G(0x1000, 0x40000000, 0x40000000);
            Assert(r.Translate(0x1000, 0x41234567) == 0x41234567, "1 GiB page translation");
            int before = r.PhysicalCalls;
            Reject(delegate { r.Translate(0x1000, 0x0000800000000000UL); }, "noncanonical virtual address rejected");
            Assert(r.PhysicalCalls == before, "noncanonical address causes no native read");
            Reject(delegate { r.Translate(0x1000, 0x20000000); }, "nonpresent page rejected");
            Reject(delegate { r.Physical(0x100000000UL, 1); }, "physical read outside RAM rejected");
            simple.Map4K(0x1000, 0x402000, 0x210000);
            simple.Write(0x200ffe, new byte[] { 1, 2 }); simple.Write(0x210000, new byte[] { 3, 4 });
            byte[] cross = r.Virtual(0x1000, 0x401ffe, 4);
            Assert(cross[0] == 1 && cross[1] == 2 && cross[2] == 3 && cross[3] == 4, "virtual read crosses physical page boundary");
            simple.AfterRead = delegate(ulong address, int length) { if (address == 0x200000 && length == 1) simple.Map4K(0x1000, 0x401000, 0x220000); };
            Reject(delegate { r.Virtual(0x1000, 0x401000, 1); }, "changed page mapping detected after read");
            simple.AfterRead = null; simple.Write(0x220000, new byte[] { 0x99 });
            Assert(r.Virtual(0x1000, 0x401000, 1)[0] == 0x99, "changed translation is evicted and fresh retry succeeds");
            simple.Map4K(0x2000, 0x401000, 0x330000); simple.Write(0x330000, new byte[] { 0x77 });
            Assert(r.Virtual(0x2000, 0x401000, 1)[0] == 0x77, "translation cache separates page-table roots");
            ulong pdp = simple.Child(0x2000, 0x401000, 39), pd = simple.Child(pdp, 0x401000, 30), pt = simple.Child(pd, 0x401000, 21);
            simple.Put64(pt + ((0x401000UL >> 12) & 511UL) * 8UL, 0);
            Reject(delegate { r.Virtual(0x2000, 0x401000, 1); }, "cached translation cannot pass after page is unmapped");
            Reader badReply = new Reader(delegate(ulong address, int length) { return "BridgeRead=PASS BytesRead=1 Hex=00"; }, new RamRange[] { new RamRange(0, 0xfffff) });
            Reject(delegate { badReply.Physical(0, 8); }, "incomplete native reply rejected");

            Memory live = new Memory(); live.LoadElf(elfPath);
            ulong root = 0x0220e000UL;
            for (ulong offset = 0; offset < 0x1800000; offset += 0x200000)
                live.Map2M(root, 0xffffffff81000000UL + offset, 0x1000000UL + offset);
            ulong taskPhysical = 0x22147c0UL;
            live.Write(taskPhysical + 0x720, Encoding.ASCII.GetBytes("swapper/0\0"));
            ulong direct = 0xffff888000000000UL;
            for (ulong offset = 0x4000; offset <= 0xc000; offset += 4096) live.Map4K(root, direct + offset, 0x5000000UL + offset);
            ulong task = direct + 0x4000, mm = direct + 0x6000, pgd = direct + 0x8000, vma = direct + 0x9000;
            ulong head = Reader.InitTaskVa + 0x470;
            live.Put64(taskPhysical + 0x470, task + 0x470); live.Put64(taskPhysical + 0x478, task + 0x470);
            live.Put64(0x5004470, head); live.Put64(0x5004478, head);
            live.Put64(0x50044c0, mm); live.Write(0x5004570, BitConverter.GetBytes(3806));
            live.Write(0x5004720, Encoding.ASCII.GetBytes(".dts.freefireth\0"));
            live.Put64(0x5006000, vma); live.Put64(0x5006050, pgd);
            live.Put64(0x5009000, 0x70000000); live.Put64(0x5009008, 0x70001000);
            live.Put64(0x50090a0, direct + 0xa000); live.Put64(0x500a018, direct + 0xb000);
            byte[] name = Encoding.ASCII.GetBytes("libil2cpp.so\0");
            live.Write(0x500b024, BitConverter.GetBytes(name.Length - 1)); live.Put64(0x500b028, direct + 0xc000); live.Write(0x500c000, name);
            live.Map4K(0x5008000, 0x70000000, 0x6000000);
            byte[] header = new byte[20]; header[0] = 0x7f; header[1] = 69; header[2] = 76; header[3] = 70; header[4] = 2; header[5] = 1; header[18] = 183;
            live.Write(0x6000000, header);
            // A scheduled idle task borrows a process mm, not necessarily init_mm.
            live.Put64(taskPhysical + 0x4c8, mm);
            Reader mapper = ReaderFor(live);
            KernelContext kernel = mapper.VerifyKernel(root | 5UL, 0);
            Assert(kernel.Root == root && kernel.InitialActiveMm == mm, "real kernel identity with borrowed idle active_mm");
            live.Put64(taskPhysical + 0x4c8, 0);
            Assert(mapper.VerifyKernel(root, 0).InitialActiveMm == 0, "switched-away idle active_mm can be null");
            live.Put64(taskPhysical + 0x4c8, Reader.InitMmVa);
            Assert(mapper.VerifyKernel(root, 0).InitialActiveMm == Reader.InitMmVa, "initial boot active_mm remains accepted");
            live.Put64(taskPhysical + 0x4c8, 0x1234);
            Reject(delegate { mapper.VerifyKernel(root, 0); }, "nonkernel idle active_mm rejected");
            live.Put64(taskPhysical + 0x4c8, mm);
            live.Write(taskPhysical + 0x570, BitConverter.GetBytes(1));
            Reject(delegate { mapper.VerifyKernel(root, 0); }, "wrong initial PID remains rejected");
            live.Write(taskPhysical + 0x570, BitConverter.GetBytes(0));
            live.Write(taskPhysical + 0x720, Encoding.ASCII.GetBytes("imposter\0"));
            Reject(delegate { mapper.VerifyKernel(root, 0); }, "wrong idle name remains rejected");
            live.Write(taskPhysical + 0x720, Encoding.ASCII.GetBytes("swapper/0\0"));
            live.Put64(taskPhysical + 0x4c0, mm);
            Reject(delegate { mapper.VerifyKernel(root, 0); }, "non-null idle mm remains rejected");
            live.Put64(taskPhysical + 0x4c0, 0);
            GameProcess game = mapper.FindProcess(kernel, 3806, ".dts.freefireth");
            Assert(game.Task == task && game.Mm == mm && game.Root == 0x5008000, "game PID and mm discover process root");
            LibraryResult libraries = mapper.Libraries(kernel, game);
            Assert(libraries.VmasVisited == 1 && libraries.Mappings.Count == 1 && libraries.Mappings[0].Arm64ElfHeader, "game virtual read verifies ARM64 library header");

            // Reproduce a scan whose last library would be unreachable within
            // 30,000 calls when every mapping rereads three filename fields.
            const int many = 1800;
            ulong arena = direct + 0x100000, arenaPhysical = 0x5100000;
            for (ulong offset = 0; offset < (ulong)many * 256UL; offset += 4096)
                live.Map4K(root, arena + offset, arenaPhysical + offset);
            for (ulong offset = 0xd000; offset <= 0xf000; offset += 4096)
                live.Map4K(root, direct + offset, 0x5000000UL + offset);
            live.Put64(0x500d018, direct + 0xe000);
            byte[] otherName = Encoding.ASCII.GetBytes("libother.so\0");
            live.Write(0x500e024, BitConverter.GetBytes(otherName.Length - 1));
            live.Put64(0x500e028, direct + 0xf000); live.Write(0x500f000, otherName);
            for (int i = 0; i < many; i++)
            {
                ulong physical = arenaPhysical + (ulong)i * 256UL;
                ulong start = i == many - 1 ? 0x70000000UL : 0x10000000UL + (ulong)i * 4096UL;
                live.Put64(physical, start); live.Put64(physical + 8, start + 4096UL);
                live.Put64(physical + 0x10, i == many - 1 ? 0 : arena + (ulong)(i + 1) * 256UL);
                live.Put64(physical + 0x18, i == 0 ? 0 : arena + (ulong)(i - 1) * 256UL);
                live.Put64(physical + 0xa0, direct + (i == many - 1 ? 0xa000UL : 0xd000UL));
            }
            live.Put64(0x5006000, arena);
            Reader large = ReaderFor(live); KernelContext largeKernel = large.VerifyKernel(root, 0);
            GameProcess largeGame = large.FindProcess(largeKernel, 3806, ".dts.freefireth");
            List<string> progress = new List<string>();
            LibraryResult manyLibraries = large.Libraries(largeKernel, largeGame, progress.Add);
            Assert(manyLibraries.VmasVisited == many && manyLibraries.Mappings.Count == 1 && manyLibraries.Mappings[0].Arm64ElfHeader,
                   "late ARM64 library is reached after 1800 VMAs");
            Assert(large.PhysicalCalls < 30000 && large.TranslationCacheHits > 0, "large scan completes within unchanged read budget");
            Assert(manyLibraries.FilesInspected == 2 && manyLibraries.RepeatedFilesSkipped == many - 2, "shared filename metadata is read once per file");
            Assert(progress.Exists(delegate(string line) { return line.Contains("LibraryCandidate") && line.Contains("PENDING_RECHECK"); }),
                   "candidate progress distinguishes pending verification");
            Console.WriteLine("LARGE_FIXTURE_READ_CALLS=" + large.PhysicalCalls + " CACHE_HITS=" + large.TranslationCacheHits);

            // A matching file renamed after its name is cached must not pass.
            live.Put64(arenaPhysical + 0xa0, direct + 0xa000UL); live.Put64(arenaPhysical + 0x98, 1);
            live.AfterRead = delegate(ulong address, int length)
            {
                if (address == arenaPhysical + (ulong)(many - 1) * 256UL && length == 0xa8)
                {
                    byte[] changedName = Encoding.ASCII.GetBytes("wrongname.so\0");
                    live.Write(0x500b024, BitConverter.GetBytes(changedName.Length - 1)); live.Write(0x500c000, changedName);
                }
            };
            Reader renamed = ReaderFor(live);
            Reject(delegate { renamed.Libraries(largeKernel, largeGame); }, "matched cached filename is revalidated before success");
            Assert(renamed.LastLibraries.VmasVisited == many && renamed.LastLibraries.Mappings.Count == 2,
                   "partial scan progress survives a final identity failure");
            live.AfterRead = null;
            live.Write(0x500b024, BitConverter.GetBytes(name.Length - 1)); live.Write(0x500c000, name);
            TargetedChecks(live, largeKernel, largeGame, header);
            Reject(delegate { mapper.FindProcess(kernel, 3806, "wrong-name"); }, "PID command-name mismatch rejected");
            live.Put64(0x50044c0, direct + 0x7000);
            Reject(delegate { mapper.Recheck(kernel, game); }, "changed game memory context rejected");
            live.Put64(0x50044c0, mm);
            live.Write(0x1e00140, new byte[] { 0 });
            Reject(delegate { mapper.VerifyKernel(root, 0); }, "mismatched live kernel rejected");
            Console.WriteLine("TOTAL=" + count + " (offline kernel and synthetic process fixture)");
        }
    }
}
