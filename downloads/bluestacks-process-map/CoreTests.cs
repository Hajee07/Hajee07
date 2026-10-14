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
        private static Reader ReaderFor(Memory memory) { return new Reader(memory.Transport, new RamRange[] { new RamRange(0, 0xffffffffUL) }); }
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
            Reader mapper = ReaderFor(live);
            KernelContext kernel = mapper.VerifyKernel(root | 5UL, 0);
            Assert(kernel.Root == root, "real extracted kernel anchors and initial task match");
            GameProcess game = mapper.FindProcess(kernel, 3806, ".dts.freefireth");
            Assert(game.Task == task && game.Mm == mm && game.Root == 0x5008000, "game PID and mm discover process root");
            LibraryResult libraries = mapper.Libraries(kernel, game);
            Assert(libraries.VmasVisited == 1 && libraries.Mappings.Count == 1 && libraries.Mappings[0].Arm64ElfHeader, "game virtual read verifies ARM64 library header");
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
