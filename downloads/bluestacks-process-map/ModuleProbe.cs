using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    internal sealed class ModuleSegment
    {
        internal readonly ulong Offset, Address, FileSize, MemorySize;
        internal readonly int Flags;
        internal ModuleSegment(ulong offset, ulong address, ulong fileSize, ulong memorySize, int flags)
        { Offset = offset; Address = address; FileSize = fileSize; MemorySize = memorySize; Flags = flags; }
    }
    internal sealed class ModuleSample
    {
        internal readonly string Name, Hex;
        internal readonly ulong Address;
        internal ModuleSample(string name, ulong address, string hex) { Name = name; Address = address; Hex = hex; }
    }
    public sealed class ModuleResult
    {
        public ulong LoadBias;
        public string BuildId;
        public string ReferenceFileSha256;
        public int LoadSegments, WindowVmas, Fingerprints;
    }
    public sealed partial class Reader
    {
        private sealed class ModuleArea
        {
            internal ulong Node, Start, End, File, Offset;
            internal byte[] Snapshot;
        }
        private static bool EqualBytes(byte[] actual, byte[] expected)
        {
            if (actual.Length != expected.Length) return false;
            for (int i = 0; i < actual.Length; i++) if (actual[i] != expected[i]) return false;
            return true;
        }
        private static ulong PageEnd(ulong address) { return checked(address + 4095UL) & ~4095UL; }
        private static void ModuleNote(Action<string> progress, ulong address, string reason)
        { if (progress != null) progress("ModuleCandidate Start=0x" + address.ToString("x") + " Status=REJECTED Reason=" + reason); }
        public ModuleResult ProbeModuleWithRetry(KernelContext kernel, GameProcess game, Action<string> progress)
        {
            // Rescan outer repeated nodes or inconsistent traversal order/backlinks once.
            // One Reader preserves the physical-call count and elapsed budget.
            for (int attempt = 1; attempt <= 2; attempt++)
            {
                if (progress != null) progress("LibraryScanAttempt Attempt=" + attempt + " MaximumAttempts=2");
                try { return ProbeModule(kernel, game, progress); }
                catch (VmaTraversalException error)
                {
                    if (!error.Retryable || attempt == 2) throw;
                    if (progress != null) progress("LibraryScanRetry Attempt=1 NextAttempt=2 Reason=" + error.Reason +
                        " DiscardedVmas=" + LastLibraries.VmasVisited + " DiscardedMappings=" + LastLibraries.Mappings.Count +
                        " PhysicalReadCalls=" + PhysicalCalls + " Detail=" + error.Message);
                    Recheck(kernel, game);
                    translations.Clear();
                    // ScanLibraries starts over at mm.mmap with new visited/file
                    // dictionaries. It never follows on from the repeated node.
                }
            }
            throw new InvalidOperationException("VMA scan attempts exhausted.");
        }
        public ModuleResult ProbeModule(KernelContext kernel, GameProcess game, Action<string> progress)
        {
            ModuleResult verified = null;
            ScanLibraries(kernel, game, progress, false, delegate(ulong node, byte[] area, LibraryMapping mapping, byte[] header)
            {
                VerifyTarget(kernel, game, node, area, mapping, header);
                verified = CheckModule(kernel, game, node, area, mapping, progress);
                return verified != null;
            });
            if (verified == null) throw new InvalidOperationException("No IL2CPP candidate matched the APK load layout and fingerprints.");
            return verified;
        }
        private ModuleResult CheckModule(KernelContext kernel, GameProcess game, ulong node, byte[] initial, LibraryMapping mapping, Action<string> progress)
        {
            ulong loadBias = mapping.Start;
            // This exact ELF has p_offset=p_vaddr=0 for its first PT_LOAD.
            // A whole-file mmap must not be mistaken for the runtime load bias.
            ulong firstEnd = checked(loadBias + PageEnd(ApkModule.Segments[0].Address + ApkModule.Segments[0].FileSize));
            if (mapping.End != firstEnd)
            {
                ModuleNote(progress, loadBias, mapping.End - mapping.Start == PageEnd(ApkModule.FileSize) ? "WHOLE_FILE_SIZED_MAPPING" : "FIRST_LOAD_BOUNDARY_MISMATCH");
                return null;
            }
            byte[] header = Hex(ApkModule.HeaderHex), programs = Hex(ApkModule.ProgramsHex);
            if (!EqualBytes(Virtual(game.Root, loadBias, header.Length), header) ||
                !EqualBytes(Virtual(game.Root, checked(loadBias + ApkModule.ProgramOffset), programs.Length), programs))
            { ModuleNote(progress, loadBias, "APK_ELF_HEADER_OR_PROGRAMS_MISMATCH"); return null; }
            ulong extent = 0;
            foreach (ModuleSegment segment in ApkModule.Segments)
                extent = Math.Max(extent, checked(segment.Address + segment.MemorySize));
            ulong moduleEnd = checked(loadBias + PageEnd(extent));
            if (moduleEnd > 0x0000800000000000UL) throw new InvalidOperationException("Module extent is outside user address space.");
            List<ModuleArea> window = new List<ModuleArea>();
            HashSet<ulong> seen = new HashSet<ulong>();
            ulong previous = BitConverter.ToUInt64(initial, 0x18), previousEnd = mapping.Start;
            while (node != 0)
            {
                KernelPointer(node);
                if (!seen.Add(node)) throw new InvalidOperationException("Module VMA cycle validation failed.");
                byte[] data = Virtual(kernel.Root, node, 0xa8);
                ulong start = BitConverter.ToUInt64(data, 0), end = BitConverter.ToUInt64(data, 8);
                if (start >= end || start < previousEnd || end > 0x0000800000000000UL || ((start | end) & 4095UL) != 0 ||
                    BitConverter.ToUInt64(data, 0x18) != previous)
                    throw new InvalidOperationException("Module VMA order, bounds, or links changed.");
                if (start >= moduleEnd) break;
                if (window.Count >= 128) throw new InvalidOperationException("Module VMA window bound validation failed.");
                window.Add(new ModuleArea { Node = node, Start = start, End = end, File = BitConverter.ToUInt64(data, 0xa0), Offset = BitConverter.ToUInt64(data, 0x98), Snapshot = data });
                previous = node; previousEnd = end; node = BitConverter.ToUInt64(data, 0x10);
            }
            Dictionary<ulong, string> names = new Dictionary<ulong, string>();
            HashSet<ModuleArea> used = new HashSet<ModuleArea>();
            foreach (ModuleSegment segment in ApkModule.Segments)
            {
                ulong cursor = checked(loadBias + segment.Address), fileEnd = checked(cursor + segment.FileSize), memoryEnd = checked(cursor + segment.MemorySize);
                while (cursor < memoryEnd)
                {
                    ModuleArea found = null;
                    foreach (ModuleArea candidate in window)
                        if (cursor >= candidate.Start && cursor < candidate.End) { found = candidate; break; }
                    if (found == null) { ModuleNote(progress, loadBias, "LOAD_SEGMENT_GAP_RVA_0x" + (cursor - loadBias).ToString("x")); return null; }
                    if (cursor < fileEnd)
                    {
                        if (found.File == 0) { ModuleNote(progress, loadBias, "FILE_SEGMENT_IS_ANONYMOUS"); return null; }
                        string name;
                        if (!names.TryGetValue(found.File, out name)) { name = FileName(kernel.Root, found.File); names.Add(found.File, name); }
                        ulong expected = checked(segment.Offset + cursor - loadBias - segment.Address);
                        ulong actual = checked(found.Offset * 4096UL + cursor - found.Start);
                        if (name != "libil2cpp.so" || actual != expected)
                        { ModuleNote(progress, loadBias, "LOAD_FILE_OFFSET_OR_NAME_MISMATCH_RVA_0x" + (cursor - loadBias).ToString("x")); return null; }
                    }
                    used.Add(found);
                    cursor = Math.Min(found.End, cursor < fileEnd ? fileEnd : memoryEnd);
                }
            }
            foreach (ModuleSample sample in ApkModule.Samples)
            {
                byte[] expected = Hex(sample.Hex);
                if (!EqualBytes(Virtual(game.Root, checked(loadBias + sample.Address), expected.Length), expected))
                { ModuleNote(progress, loadBias, "FINGERPRINT_MISMATCH_" + sample.Name); return null; }
            }
            // Repeat the fixed-byte observations and metadata checks before reporting.
            Recheck(kernel, game);
            foreach (ModuleArea area in used) RecheckVma(kernel, game, area.Node, area.Snapshot);
            foreach (KeyValuePair<ulong, string> name in names)
                if (FileName(kernel.Root, name.Key) != name.Value) throw new InvalidOperationException("Module file name changed during verification.");
            if (!EqualBytes(Virtual(game.Root, loadBias, header.Length), header) ||
                !EqualBytes(Virtual(game.Root, checked(loadBias + ApkModule.ProgramOffset), programs.Length), programs))
                throw new InvalidOperationException("Module ELF tables changed during verification.");
            foreach (ModuleSample sample in ApkModule.Samples)
                if (!EqualBytes(Virtual(game.Root, checked(loadBias + sample.Address), sample.Hex.Length / 2), Hex(sample.Hex)))
                    throw new InvalidOperationException("Module fingerprint changed during verification: " + sample.Name);
            foreach (ModuleArea area in used) RecheckVma(kernel, game, area.Node, area.Snapshot);
            Recheck(kernel, game);
            return new ModuleResult { LoadBias = loadBias, BuildId = ApkModule.BuildId, ReferenceFileSha256 = ApkModule.FileSha256,
                LoadSegments = ApkModule.Segments.Length, WindowVmas = window.Count, Fingerprints = ApkModule.Samples.Length };
        }
    }
}
