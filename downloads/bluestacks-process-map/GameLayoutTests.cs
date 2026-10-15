using System;
using System.Collections.Generic;
using System.Text;

namespace HeadBridge.Mapping.Tests
{
    public static class GameLayoutTests
    {
        private static int count;
        private static void Assert(bool condition, string name)
        { if (!condition) throw new Exception("FAIL: " + name); count++; Console.WriteLine("PASS: " + name); }
        private sealed class Fixture
        {
            internal readonly Memory Memory = new Memory();
            internal readonly Reader Reader;
            internal readonly KernelContext Kernel = new KernelContext(0x1000, 0, 0);
            internal readonly GameProcess Game;
            internal readonly ModuleResult Module = new ModuleResult { LoadBias = 0x60000000, BuildId = ApkModule.BuildId, ReferenceFileSha256 = ApkModule.FileSha256 };
            internal readonly Dictionary<ulong, ulong> Pages = new Dictionary<ulong, ulong>();
            internal readonly List<string> Progress = new List<string>();
            private ulong next = 0x8000000;
            internal readonly ulong MetadataRva;
            internal Fixture(ulong metadataRva = 0x20000000UL)
            {
                MetadataRva = metadataRva;
                const ulong k = 0xffff888000000000;
                Memory.Map4K(0x1000, k + 0x1000, 0x101000);
                Memory.Map4K(0x1000, k + 0x3000, 0x103000);
                Memory.Map4K(0x1000, k + 0x4000, 0x2000);
                Game = new GameProcess { Pid = 2942, Name = ".dts.freefireth", Task = k + 0x1000, Mm = k + 0x3000, PgdVirtual = k + 0x4000, Root = 0x2000 };
                Memory.Put64(0x1014c0, Game.Mm); Memory.Write(0x101570, BitConverter.GetBytes(Game.Pid));
                Memory.Write(0x101720, Encoding.ASCII.GetBytes(Game.Name + "\0")); Memory.Put64(0x103050, Game.PgdVirtual);
                foreach (GameLayoutCheck check in GameLayoutReference.Checks) Put(check.Address, check.Expected(Module.LoadBias));
                Put(MetadataRva, Reader.Hex(GameLayoutReference.RuntimeMetadataHeaderHex));
                foreach (GameLayoutCheck check in GameLayoutReference.Checks)
                    if (check.TypeDefinitionIndex >= 0)
                    {
                        Put(check.Address, DescriptorBytes(check, MetadataRva));
                        Put(MetadataRva + GameLayoutReference.TypeDefinitionsOffset + (ulong)check.TypeDefinitionIndex * 88UL, Reader.Hex(check.TypeDefinitionHex));
                    }
                Reader = new Reader(Memory.Transport, new RamRange[] { new RamRange(0, 0xffffffff) });
            }
            internal byte[] DescriptorBytes(GameLayoutCheck check, ulong metadataRva)
            {
                byte[] bytes = check.Expected(Module.LoadBias);
                BitConverter.GetBytes(Module.LoadBias + metadataRva + GameLayoutReference.TypeDefinitionsOffset + (ulong)check.TypeDefinitionIndex * 88UL).CopyTo(bytes, 0);
                return bytes;
            }
            internal void Put(ulong rva, byte[] data)
            {
                for (int i = 0; i < data.Length; i++)
                {
                    ulong address = Module.LoadBias + rva + (ulong)i, page = address & ~4095UL, physical;
                    if (!Pages.TryGetValue(page, out physical))
                    { physical = next; next += 4096; Pages.Add(page, physical); Memory.Map4K(Game.Root, page, physical); }
                    Memory.Write(physical + (address & 4095UL), new byte[] { data[i] });
                }
            }
            internal ulong Physical(ulong rva)
            { ulong address = Module.LoadBias + rva; return Pages[address & ~4095UL] + (address & 4095UL); }
            internal GameLayoutResult Run() { return Reader.VerifyGameLayout(Kernel, Game, Module, Progress.Add); }
        }
        private static GameLayoutCheck Find(string suffix)
        { foreach (GameLayoutCheck check in GameLayoutReference.Checks) if (check.Name.EndsWith(suffix, StringComparison.Ordinal)) return check; throw new Exception("Missing reference fixture"); }
        private static void Reject(Fixture fixture, string expected, string label)
        {
            bool rejected = false;
            try { fixture.Run(); }
            catch (Exception error) { rejected = error.Message.Contains(expected); }
            Assert(rejected, label);
        }
        public static void Run()
        {
            Fixture good = new Fixture(); GameLayoutResult result = good.Run();
            Assert(result.Checks == GameLayoutReference.Checks.Length && result.FieldCandidates == 9 && result.MethodCandidates == 9 && good.Progress.Count == 3,
                "native layout registration references pass both read-only verification rounds");
            Console.WriteLine("LAYOUT_FIXTURE_READ_CALLS=" + good.Reader.PhysicalCalls + " CHECKS=" + result.Checks);
            Fixture field = new Fixture(); GameLayoutCheck fieldCheck = Find(".offset"); field.Put(fieldCheck.Address, new byte[] { 0xff });
            Reject(field, "Layout registration mismatch", "changed field offset is rejected");
            Fixture pointer = new Fixture(); GameLayoutCheck method = Find(".method_pointer"); pointer.Put(method.Address, BitConverter.GetBytes(method.PointerTarget));
            Reject(pointer, "Layout registration mismatch", "unrelocated method RVA cannot pass as a runtime pointer");
            Fixture code = new Fixture(); GameLayoutCheck entry = Find(".entry"); code.Put(entry.Address, new byte[] { 0 });
            Reject(code, "Layout registration mismatch", "changed method entry bytes are rejected");
            Fixture changed = new Fixture(); ulong at = changed.Physical(fieldCheck.Address); bool mutated = false;
            changed.Memory.AfterRead = delegate(ulong address, int length)
            {
                if (!mutated && address == at && length == 4) { changed.Memory.Write(address, new byte[] { 0xff }); mutated = true; }
            };
            Reject(changed, "Pass=2", "registration mutation after first observation fails second round");
            Fixture identity = new Fixture(); ulong trigger = identity.Physical(entry.Address);
            identity.Memory.AfterRead = delegate(ulong address, int length) { if (address == trigger && length == 32) identity.Memory.Put64(0x1014c0, 0xffff888000009000UL); };
            Reject(identity, "Game identity", "layout checks reject a changed process mm");
            Fixture reference = new Fixture(); reference.Module.BuildId = "different";
            Reject(reference, "matching verified module", "layout checks require the matching module profile");
            Assert(reference.Reader.PhysicalCalls == 0, "wrong module profile causes no guest reads");
            Fixture descriptors = new Fixture(); GameLayoutCheck descriptor = Find(".type_descriptor");
            byte[] descriptorBytes = descriptor.Expected(descriptors.Module.LoadBias);
            descriptorBytes[0] ^= 0x55;
            descriptors.Put(descriptor.Address, descriptorBytes);
            Reject(descriptors, "Layout registration mismatch", "runtime descriptor differences remain failures");
            string expectedHex = BitConverter.ToString(descriptor.Expected(descriptors.Module.LoadBias)).Replace("-", "").ToLowerInvariant();
            string actualHex = BitConverter.ToString(descriptorBytes).Replace("-", "").ToLowerInvariant();
            Assert(descriptors.Progress.Exists(delegate(string line) { return line.Contains("Name=" + descriptor.Name) && line.Contains("Bytes=12") &&
                line.Contains("Expected=" + expectedHex) && line.Contains("Actual=" + actualHex); }), "diagnostics report exact bounded descriptor bytes");
            Assert(descriptors.Progress.Exists(delegate(string line) { return line.Contains("Pass=2") && line.Contains("ChangedSinceFirstPass=False"); }) &&
                descriptors.Progress.Exists(delegate(string line) { return line.Contains("DistinctMismatches=1 MismatchObservations=2 ChangedBetweenPasses=0"); }),
                "stable mismatches are compared in both rounds and remain unverified");
            Fixture multiple = new Fixture(); multiple.Put(descriptor.Address, descriptorBytes); multiple.Put(entry.Address, new byte[] { 0 });
            Reject(multiple, "DistinctMismatches=2", "diagnostics include later mismatches after the first failure");
            Assert(multiple.Progress.Exists(delegate(string line) { return line.Contains("Pass=2 ChecksCompared=80 ChecksMatched=78 ChecksMismatched=2"); }),
                "a mismatched round completes all fixed comparisons");
            Assert(changed.Progress.Exists(delegate(string line) { return line.Contains("ChangedSinceFirstPass=True"); }),
                "between-round mutation is identified in diagnostic output");
            bool nullRejected = false;
            try { descriptors.Reader.VerifyGameLayout(descriptors.Kernel, descriptors.Game, descriptors.Module, null); }
            catch (InvalidOperationException error) { nullRejected = error.Message.Contains("Layout registration mismatch"); }
            Assert(nullRejected, "omitting the diagnostic callback cannot turn mismatches into success");
            Assert(result.TypeDescriptors == 9 && result.RuntimeMetadataBase == good.Module.LoadBias + good.MetadataRva,
                "resolved descriptors verify all nine exact records against a shared metadata base");
            Fixture relocated = new Fixture(0x30000000UL); GameLayoutResult relocatedResult = relocated.Run();
            Assert(relocatedResult.RuntimeMetadataBase == relocated.Module.LoadBias + relocated.MetadataRva,
                "metadata base is derived from runtime descriptors instead of hardcoded");
            Fixture unresolved = new Fixture(); unresolved.Put(descriptor.Address, descriptor.Expected(unresolved.Module.LoadBias));
            Reject(unresolved, "INVALID_METADATA_POINTER", "on-disk type indexes cannot pass as resolved runtime descriptors");
            Fixture flags = new Fixture(); byte[] flagged = flags.DescriptorBytes(descriptor, flags.MetadataRva); flagged[8] ^= 1; flags.Put(descriptor.Address, flagged);
            Reject(flags, "DESCRIPTOR_FLAGS", "descriptor attributes remain exact despite accepting runtime pointers");
            Fixture badHeader = new Fixture(); badHeader.Put(badHeader.MetadataRva, new byte[] { 0xff });
            Reject(badHeader, "METADATA_HEADER", "a plausible pointer cannot bypass exact metadata header verification");
            Fixture badRecord = new Fixture(); ulong recordRva = badRecord.MetadataRva + GameLayoutReference.TypeDefinitionsOffset + (ulong)descriptor.TypeDefinitionIndex * 88UL;
            byte[] row = Reader.Hex(descriptor.TypeDefinitionHex); row[87] ^= 1; badRecord.Put(recordRva, row);
            Reject(badRecord, "TYPE_RECORD", "all 88 type-record bytes are checked including the last byte");
            Assert(badRecord.Progress.Exists(delegate(string line) { return line.Contains("TypeMetadataDifference") && line.Contains("Offset=87 Bytes=1"); }),
                "record mismatch diagnostics report a bounded sample at the actual difference");
            Fixture inconsistent = new Fixture(); GameLayoutCheck later = null;
            foreach (GameLayoutCheck check in GameLayoutReference.Checks)
                if (check.TypeDefinitionIndex >= 0 && check != descriptor) { later = check; break; }
            inconsistent.Put(later.Address, inconsistent.DescriptorBytes(later, 0x30000000UL));
            Reject(inconsistent, "INCONSISTENT_METADATA_BASE", "descriptors cannot point into different metadata tables");
            Fixture moving = new Fixture(); ulong descriptorPhysical = moving.Physical(descriptor.Address); bool moved = false;
            moving.Memory.AfterRead = delegate(ulong address, int length)
            {
                if (!moved && address == descriptorPhysical && length == 12)
                { moving.Put(descriptor.Address, descriptor.Expected(moving.Module.LoadBias)); moved = true; }
            };
            Reject(moving, "DESCRIPTOR_CHANGED_DURING_READ", "descriptor pointer is reread after checking its target record");
            Fixture kernelPointer = new Fixture(); byte[] kernelBytes = kernelPointer.DescriptorBytes(descriptor, kernelPointer.MetadataRva);
            BitConverter.GetBytes(0xffff888000001000UL).CopyTo(kernelBytes, 0); kernelPointer.Put(descriptor.Address, kernelBytes);
            Reject(kernelPointer, "INVALID_METADATA_POINTER", "kernel addresses cannot be followed as user metadata pointers");
            Fixture diskHeader = new Fixture(); diskHeader.Put(diskHeader.MetadataRva, Reader.Hex(GameLayoutReference.MetadataHeaderHex));
            Reject(diskHeader, "METADATA_HEADER", "decoded file prefix is not accepted as the observed runtime header");
            Fixture wrongVersion = new Fixture(); wrongVersion.Put(wrongVersion.MetadataRva + 4, BitConverter.GetBytes(25));
            Reject(wrongVersion, "METADATA_HEADER", "runtime metadata version must be exactly the observed 24");
            Fixture tableHeader = new Fixture(); tableHeader.Put(tableHeader.MetadataRva + 8, new byte[] { 0xff });
            Reject(tableHeader, "METADATA_HEADER", "runtime prefix acceptance does not relax metadata table offsets");
            Fixture tailHeader = new Fixture(); byte[] fullHeader = Reader.Hex(GameLayoutReference.RuntimeMetadataHeaderHex);
            fullHeader[255] ^= 1; tailHeader.Put(tailHeader.MetadataRva, fullHeader);
            Reject(tailHeader, "METADATA_HEADER", "all 256 runtime-header bytes remain checked");
            Fixture both = new Fixture(); both.Put(both.MetadataRva, new byte[] { 0xff });
            both.Put(both.MetadataRva + GameLayoutReference.TypeDefinitionsOffset + (ulong)descriptor.TypeDefinitionIndex * 88UL, row);
            bool bothRejected = false;
            try { both.Run(); } catch (InvalidOperationException error) { bothRejected = error.Message.Contains("METADATA_HEADER"); }
            Assert(bothRejected && both.Progress.Exists(delegate(string line) { return line.Contains("TypeMetadataDifference") && line.Contains(".metadata_header"); }) &&
                both.Progress.Exists(delegate(string line) { return line.Contains("TypeMetadataDifference") && line.Contains(".type_record"); }),
                "header and record differences are both reported while verification still fails");
            Console.WriteLine("LAYOUT_TOTAL=" + count + " (synthetic memory with recovered registration references)");
        }
    }
}
