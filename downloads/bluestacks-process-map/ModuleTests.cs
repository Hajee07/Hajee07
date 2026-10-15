using System;
using System.Collections.Generic;
using System.Text;

namespace HeadBridge.Mapping.Tests
{
    public static class ModuleChecks
    {
        private static int count;
        private static void Check(bool condition, string name)
        { if (!condition) throw new Exception("FAIL: " + name); count++; Console.WriteLine("PASS: " + name); }
        private sealed class Fixture
        {
            internal readonly Memory Memory = new Memory();
            internal readonly List<string> Progress = new List<string>();
            internal readonly List<ulong> Areas = new List<ulong>();
            internal readonly Dictionary<ulong, ulong> DataPages = new Dictionary<ulong, ulong>();
            internal const ulong Bias = 0x60000000, Raw = 0x40000000, Kernel = 0xffff888000000000;
            internal readonly KernelContext Context = new KernelContext(0x1000, 0, 0);
            internal readonly GameProcess Game;
            internal readonly Reader Reader;
            internal readonly List<ulong[]> Mappings = new List<ulong[]>();
            private ulong nextPhysical = 0x8000000;
            internal Fixture(int executableFragments)
            {
                for (ulong i = 0; i < 64; i++) Memory.Map4K(0x1000, Kernel + i * 4096UL, 0x100000UL + i * 4096UL);
                Memory.Map4K(0x1000, Kernel + 0x4000, 0x2000);
                Game = new GameProcess { Pid = 2942, Name = ".dts.freefireth", Task = Kernel + 0x1000, Mm = Kernel + 0x3000, PgdVirtual = Kernel + 0x4000, Root = 0x2000 };
                Memory.Put64(0x1014c0, Game.Mm); Memory.Write(0x101570, BitConverter.GetBytes(Game.Pid));
                Memory.Write(0x101720, Encoding.ASCII.GetBytes(Game.Name + "\0")); Memory.Put64(0x103050, Game.PgdVirtual);
                Memory.Put64(0x105018, Kernel + 0x6000); Memory.Put64(0x106028, Kernel + 0x7000);
                Memory.Write(0x106024, BitConverter.GetBytes("libil2cpp.so".Length)); Memory.Write(0x107000, Encoding.ASCII.GetBytes("libil2cpp.so\0"));
                // A separate valid file object with a non-target filename.
                Memory.Put64(0x108018, Kernel + 0x9000); Memory.Put64(0x109028, Kernel + 0xa000);
                Memory.Write(0x109024, BitConverter.GetBytes("libother.so".Length)); Memory.Write(0x10a000, Encoding.ASCII.GetBytes("libother.so\0"));
                Mappings.Add(new ulong[] { Raw, Raw + Up(ApkModule.FileSize), 0, Kernel + 0x5000 });
                foreach (ModuleSegment segment in ApkModule.Segments)
                {
                    ulong start = Bias + (segment.Address & ~4095UL), end = Bias + Up(segment.Address + segment.FileSize), offset = segment.Offset / 4096UL;
                    if (executableFragments > 1 && segment.Address == ApkModule.Segments[1].Address)
                    {
                        for (int i = 0; i < executableFragments; i++) Mappings.Add(new ulong[] { start + (ulong)i * 4096UL, i == executableFragments - 1 ? end : start + (ulong)(i + 1) * 4096UL, offset + (ulong)i, Kernel + 0x5000 });
                    }
                    else Mappings.Add(new ulong[] { start, end, offset, Kernel + 0x5000 });
                    ulong memoryEnd = Bias + Up(segment.Address + segment.MemorySize);
                    if (memoryEnd > end) Mappings.Add(new ulong[] { end, memoryEnd, 0, 0 });
                }
                for (int i = 0; i < Mappings.Count; i++)
                {
                    ulong physical = 0x110000UL + (ulong)i * 256UL;
                    Areas.Add(physical);
                    Memory.Put64(physical, Mappings[i][0]); Memory.Put64(physical + 8, Mappings[i][1]);
                    Memory.Put64(physical + 0x10, i == Mappings.Count - 1 ? 0 : Kernel + 0x10000UL + (ulong)(i + 1) * 256UL);
                    Memory.Put64(physical + 0x18, i == 0 ? 0 : Kernel + 0x10000UL + (ulong)(i - 1) * 256UL);
                    Memory.Put64(physical + 0x98, Mappings[i][2]); Memory.Put64(physical + 0xa0, Mappings[i][3]);
                }
                Memory.Put64(0x103000, Kernel + 0x10000);
                Put(Raw, Reader.Hex(ApkModule.HeaderHex)); Put(Raw + ApkModule.ProgramOffset, Reader.Hex(ApkModule.ProgramsHex));
                Put(Bias, Reader.Hex(ApkModule.HeaderHex)); Put(Bias + ApkModule.ProgramOffset, Reader.Hex(ApkModule.ProgramsHex));
                foreach (ModuleSample sample in ApkModule.Samples) Put(Bias + sample.Address, Reader.Hex(sample.Hex));
                Reader = new Reader(Memory.Transport, new RamRange[] { new RamRange(0, 0xffffffff) });
            }
            internal Fixture() : this(1) { }
            private static ulong Up(ulong x) { return (x + 4095UL) & ~4095UL; }
            internal void Put(ulong address, byte[] data)
            {
                for (int i = 0; i < data.Length; i++)
                {
                    ulong at = address + (ulong)i, page = at & ~4095UL, physical;
                    if (!DataPages.TryGetValue(page, out physical))
                    { physical = nextPhysical; nextPhysical += 4096; DataPages.Add(page, physical); Memory.Map4K(Game.Root, page, physical); }
                    Memory.Write(physical + (at & 4095UL), new byte[] { data[i] });
                }
            }
            internal ulong Physical(ulong address) { return DataPages[address & ~4095UL] + (address & 4095UL); }
            internal ModuleResult Run() { return Reader.ProbeModule(Context, Game, Progress.Add); }
        }
        private static void Reject(Fixture fixture, string message, string reason, string name)
        {
            bool rejected = false;
            try { fixture.Run(); }
            catch (InvalidOperationException error) { rejected = error.Message.Contains(message); }
            Check(rejected && (reason == null || fixture.Progress.Exists(delegate(string line) { return line.Contains(reason); })), name);
        }
        private static void RepeatFirst(Fixture fixture, bool restore)
        {
            fixture.Memory.Put64(fixture.Areas[0] + 0xa0, 0);
            fixture.Memory.Put64(fixture.Areas[0] + 0x10, Fixture.Kernel + 0x10000);
            if (restore) fixture.Memory.AfterRead = delegate(ulong address, int length)
            {
                if (address == fixture.Areas[0] && length == 0xa8)
                {
                    fixture.Memory.Put64(fixture.Areas[0] + 0xa0, Fixture.Kernel + 0x5000);
                    fixture.Memory.Put64(fixture.Areas[0] + 0x10, Fixture.Kernel + 0x10100);
                }
            };
        }
        private static bool RetryReject(Fixture fixture, string text, Action<string> progress)
        {
            try { fixture.Reader.ProbeModuleWithRetry(fixture.Context, fixture.Game, progress); }
            catch (InvalidOperationException error) { return error.Message.Contains(text); }
            return false;
        }
        public static void Run()
        {
            Fixture valid = new Fixture(); ModuleResult result = valid.Run();
            Check(result.LoadBias == Fixture.Bias && result.BuildId == ApkModule.BuildId && result.LoadSegments == 8 && result.Fingerprints == 4,
                "APK tables, all PT_LOADs, build ID and code samples identify the loaded layout");
            Check(valid.Progress.Exists(delegate(string line) { return line.Contains("WHOLE_FILE_SIZED_MAPPING"); }), "whole-file mapping is rejected as a load bias");
            Check(valid.Reader.LastLibraries.StopReason == "MODULE_VERIFIED" && !valid.Reader.LastLibraries.CompleteVmaList,
                "module probe stops with an explicit partial-list status");
            Check(valid.Reader.PhysicalCalls < 2000, "bounded module fixture fits the existing read budget");
            Console.WriteLine("MODULE_FIXTURE_READ_CALLS=" + valid.Reader.PhysicalCalls + " WINDOW_VMAs=" + result.WindowVmas);
            Fixture header = new Fixture(); header.Put(Fixture.Bias + 24, new byte[] { 0 });
            Reject(header, "No IL2CPP candidate", "APK_ELF_HEADER_OR_PROGRAMS_MISMATCH", "changed ELF header is not accepted as the APK reference");
            Fixture programs = new Fixture(); programs.Put(Fixture.Bias + ApkModule.ProgramOffset, new byte[] { 0 });
            Reject(programs, "No IL2CPP candidate", "APK_ELF_HEADER_OR_PROGRAMS_MISMATCH", "changed program headers are rejected");
            Fixture build = new Fixture(); build.Put(Fixture.Bias + ApkModule.Samples[0].Address, new byte[] { 0 });
            Reject(build, "No IL2CPP candidate", "FINGERPRINT_MISMATCH_GNU_BUILD_ID", "wrong GNU build-ID note is rejected");
            Fixture code = new Fixture(); code.Put(Fixture.Bias + ApkModule.Samples[1].Address, new byte[] { 0 });
            Reject(code, "No IL2CPP candidate", "FINGERPRINT_MISMATCH_CODE_0", "changed executable sample is rejected");
            Fixture offset = new Fixture(); offset.Memory.Put64(offset.Areas[2] + 0x98, offset.Mappings[2][2] + 1);
            Reject(offset, "No IL2CPP candidate", "LOAD_FILE_OFFSET_OR_NAME_MISMATCH", "incorrect segment file offset is rejected");
            Fixture anonymous = new Fixture(); anonymous.Memory.Put64(anonymous.Areas[2] + 0xa0, 0);
            Reject(anonymous, "No IL2CPP candidate", "FILE_SEGMENT_IS_ANONYMOUS", "anonymous mapping cannot replace file-backed segment bytes");
            Fixture wrongFile = new Fixture(); wrongFile.Memory.Put64(wrongFile.Areas[2] + 0xa0, Fixture.Kernel + 0x8000);
            Reject(wrongFile, "No IL2CPP candidate", "LOAD_FILE_OFFSET_OR_NAME_MISMATCH", "non-target backing filename is rejected");
            Fixture gap = new Fixture(); gap.Memory.Put64(gap.Areas[2] + 8, gap.Mappings[2][1] - 4096);
            Reject(gap, "No IL2CPP candidate", "LOAD_SEGMENT_GAP", "gap inside a PT_LOAD is rejected");
            Fixture changedSample = new Fixture(); ulong sampleAddress = changedSample.Physical(Fixture.Bias + ApkModule.Samples[3].Address);
            changedSample.Memory.AfterRead = delegate(ulong address, int length) { if (address == sampleAddress && length == 64) changedSample.Memory.Write(address, new byte[] { 0 }); };
            Reject(changedSample, "Module fingerprint changed", null, "a sample changed after its first read fails the final recheck");
            Fixture changedVma = new Fixture(); ulong trigger = changedVma.Physical(Fixture.Bias + ApkModule.Samples[3].Address);
            changedVma.Memory.AfterRead = delegate(ulong address, int length) { if (address == trigger && length == 64) changedVma.Memory.Put64(changedVma.Areas[2] + 0xa0, Fixture.Kernel + 0x8000); };
            Reject(changedVma, "Target VMA changed", null, "module VMA mutation after fingerprint reads is rejected");
            Fixture changedMm = new Fixture(); ulong mmTrigger = changedMm.Physical(Fixture.Bias + ApkModule.Samples[3].Address);
            changedMm.Memory.AfterRead = delegate(ulong address, int length) { if (address == mmTrigger && length == 64) changedMm.Memory.Put64(0x1014c0, Fixture.Kernel + 0x8000); };
            Reject(changedMm, "Game identity", null, "module verification rejects a changed game mm");
            Fixture renamed = new Fixture(); ulong nameTrigger = renamed.Physical(Fixture.Bias + ApkModule.Samples[3].Address);
            renamed.Memory.AfterRead = delegate(ulong address, int length) { if (address == nameTrigger && length == 64) renamed.Memory.Write(0x107000, Encoding.ASCII.GetBytes(new string('x', "libil2cpp.so".Length) + "\0")); };
            Reject(renamed, "Module file name changed", null, "module filename is checked again before success");
            Fixture boundary = new Fixture(120);
            // Include a valid successor outside the module so the terminal
            // boundary read does not count as an extra in-window VMA.
            int tailIndex = boundary.Mappings.Count;
            ulong tail = 0x110000UL + (ulong)tailIndex * 256UL;
            boundary.Memory.Put64(boundary.Areas[tailIndex - 1] + 0x10, Fixture.Kernel + 0x10000UL + (ulong)tailIndex * 256UL);
            boundary.Memory.Put64(tail, 0x80000000); boundary.Memory.Put64(tail + 8, 0x80001000);
            boundary.Memory.Put64(tail + 0x18, Fixture.Kernel + 0x10000UL + (ulong)(tailIndex - 1) * 256UL);
            Check(boundary.Run().WindowVmas == 128, "exactly 128 module VMAs permit one outside-boundary observation");
            Fixture bounded = new Fixture(130);
            Reject(bounded, "Module VMA window bound", null, "excessively fragmented module cannot exceed the 128-VMA window");
            Fixture transient = new Fixture(); RepeatFirst(transient, true);
            ModuleResult retried = transient.Reader.ProbeModuleWithRetry(transient.Context, transient.Game, transient.Progress.Add);
            Check(retried.LoadBias == Fixture.Bias && transient.Progress.Exists(delegate(string line) { return line.Contains("LibraryScanRetry") && line.Contains("DiscardedVmas=1"); }),
                "transient repeated VMA is discarded and a fresh scan can verify the module");
            Check(transient.Progress.FindAll(delegate(string line) { return line.StartsWith("LibraryScanAttempt ", StringComparison.Ordinal); }).Count == 2 &&
                transient.Reader.PhysicalCalls > valid.Reader.PhysicalCalls && transient.Reader.LastLibraries.StopReason == "MODULE_VERIFIED",
                "retry preserves cumulative reads while replacing the provisional scan result");
            Fixture cycle = new Fixture(); RepeatFirst(cycle, false);
            Check(RetryReject(cycle, "Reason=REPEATED_NODE", cycle.Progress.Add) && cycle.Reader.LastLibraries.StopReason == "REPEATED_NODE" &&
                cycle.Progress.FindAll(delegate(string line) { return line.StartsWith("LibraryScanAttempt ", StringComparison.Ordinal); }).Count == 2,
                "persistent repeated node fails after exactly two attempts");
            Fixture identityRetry = new Fixture(); RepeatFirst(identityRetry, false);
            Action<string> identityProgress = delegate(string line)
            {
                identityRetry.Progress.Add(line);
                if (line.StartsWith("LibraryScanRetry ", StringComparison.Ordinal)) identityRetry.Memory.Put64(0x1014c0, Fixture.Kernel + 0x8000);
            };
            Check(RetryReject(identityRetry, "Game identity", identityProgress) && !identityRetry.Progress.Contains("LibraryScanAttempt Attempt=2 MaximumAttempts=2"),
                "changed process identity prevents starting the retry");
            Fixture noRetry = new Fixture(); noRetry.Put(Fixture.Bias + ApkModule.Samples[0].Address, new byte[] { 0 });
            Check(RetryReject(noRetry, "No IL2CPP candidate", noRetry.Progress.Add) && !noRetry.Progress.Contains("LibraryScanAttempt Attempt=2 MaximumAttempts=2"),
                "module fingerprint mismatch is not retried");
            Fixture budget = new Fixture(); RepeatFirst(budget, false);
            Action<string> budgetProgress = delegate(string line)
            {
                budget.Progress.Add(line);
                if (line.StartsWith("LibraryScanRetry ", StringComparison.Ordinal))
                    while (budget.Reader.PhysicalCalls < 30000) budget.Reader.Physical(0x100000, 1);
            };
            Check(RetryReject(budget, "Read budget exhausted", budgetProgress) && budget.Reader.PhysicalCalls == 30000,
                "retry cannot reset or exceed the shared physical-read budget");
            Fixture outerBound = new Fixture(); const ulong listPhysical = 0x20000000UL, listVirtual = Fixture.Kernel + 0x4000000UL;
            for (int i = 0; i < 4097; i++)
            {
                ulong offsetAt = (ulong)i * 256UL, at = listPhysical + offsetAt;
                if ((offsetAt & 4095UL) == 0) outerBound.Memory.Map4K(outerBound.Context.Root, listVirtual + offsetAt, at);
                outerBound.Memory.Put64(at, 0x10000UL + (ulong)i * 4096UL); outerBound.Memory.Put64(at + 8, 0x11000UL + (ulong)i * 4096UL);
                outerBound.Memory.Put64(at + 0x10, i == 4096 ? 0 : listVirtual + offsetAt + 256UL);
                outerBound.Memory.Put64(at + 0x18, i == 0 ? 0 : listVirtual + offsetAt - 256UL);
            }
            outerBound.Memory.Put64(0x103000, listVirtual);
            Check(RetryReject(outerBound, "Reason=NODE_LIMIT", outerBound.Progress.Add) && outerBound.Reader.LastLibraries.VmasVisited == 4096 &&
                outerBound.Reader.LastLibraries.StopReason == "NODE_LIMIT" && !outerBound.Progress.Contains("LibraryScanAttempt Attempt=2 MaximumAttempts=2"),
                "4096-node exhaustion is distinguished from repetition and is not retried");
            Fixture backlink = new Fixture(); backlink.Memory.Put64(backlink.Areas[0] + 0x18, Fixture.Kernel + 0x9000);
            backlink.Memory.AfterRead = delegate(ulong address, int length)
            { if (address == backlink.Areas[0] && length == 0xa8) backlink.Memory.Put64(backlink.Areas[0] + 0x18, 0); };
            Check(backlink.Reader.ProbeModuleWithRetry(backlink.Context, backlink.Game, backlink.Progress.Add).LoadBias == Fixture.Bias &&
                backlink.Progress.Exists(delegate(string line) { return line.Contains("LibraryScanRetry") && line.Contains("Reason=VMA_BACKLINK"); }),
                "an inconsistent backlink can recover only through a complete fresh scan");
            Fixture persistentLink = new Fixture(); persistentLink.Memory.Put64(persistentLink.Areas[0] + 0x18, Fixture.Kernel + 0x9000);
            Check(RetryReject(persistentLink, "Reason=VMA_BACKLINK", persistentLink.Progress.Add) &&
                persistentLink.Progress.FindAll(delegate(string line) { return line.StartsWith("LibraryScanAttempt ", StringComparison.Ordinal); }).Count == 2 &&
                persistentLink.Progress.Exists(delegate(string line) { return line.Contains("LibraryScanInconsistency") && line.Contains("Start=0x") && line.Contains("LinkPrevious=0x"); }),
                "persistent backlink failure stops after two attempts with the offending VMA fields");
            Fixture ordered = new Fixture(); ordered.Memory.Put64(ordered.Areas[1], Fixture.Raw + 4096); ordered.Memory.Put64(ordered.Areas[1] + 0xa0, 0);
            ordered.Memory.AfterRead = delegate(ulong address, int length)
            {
                if (address == ordered.Areas[1] && length == 0xa8)
                { ordered.Memory.Put64(ordered.Areas[1], Fixture.Bias); ordered.Memory.Put64(ordered.Areas[1] + 0xa0, Fixture.Kernel + 0x5000); }
            };
            Check(ordered.Reader.ProbeModuleWithRetry(ordered.Context, ordered.Game, ordered.Progress.Add).LoadBias == Fixture.Bias &&
                ordered.Progress.Exists(delegate(string line) { return line.Contains("LibraryScanRetry") && line.Contains("Reason=VMA_ORDER"); }),
                "an inconsistent traversal order can recover after a discarded first scan");
            Fixture invalidRange = new Fixture(); invalidRange.Memory.Put64(invalidRange.Areas[0], invalidRange.Mappings[0][1]);
            Check(RetryReject(invalidRange, "Reason=INVALID_RANGE", invalidRange.Progress.Add) &&
                !invalidRange.Progress.Contains("LibraryScanAttempt Attempt=2 MaximumAttempts=2"), "invalid VMA ranges are not retried");
            Fixture unaligned = new Fixture(); unaligned.Memory.Put64(unaligned.Areas[0], Fixture.Raw + 1);
            Check(RetryReject(unaligned, "Reason=PAGE_ALIGNMENT", unaligned.Progress.Add) &&
                !unaligned.Progress.Contains("LibraryScanAttempt Attempt=2 MaximumAttempts=2"), "unaligned VMA boundaries are not retried");
            Fixture userRange = new Fixture(); userRange.Memory.Put64(userRange.Areas[0] + 8, 0x0000800000001000UL);
            Check(RetryReject(userRange, "Reason=USER_RANGE", userRange.Progress.Add) &&
                !userRange.Progress.Contains("LibraryScanAttempt Attempt=2 MaximumAttempts=2"), "VMAs outside user space are rejected without retry");
            Console.WriteLine("MODULE_TOTAL=" + count + " (synthetic mappings with exact APK reference bytes)");
        }
    }
}
