using System;

namespace HeadBridge.Mapping
{
    internal sealed class GameLayoutCheck
    {
        internal readonly string Name, Hex, TypeDefinitionHex;
        internal readonly int TypeDefinitionIndex = -1;
        internal readonly ulong Address, PointerTarget;
        internal readonly bool IsPointer;
        internal GameLayoutCheck(string name, ulong address, string hex)
        { Name = name; Address = address; Hex = hex; }
        internal GameLayoutCheck(string name, ulong address, ulong target)
        { Name = name; Address = address; PointerTarget = target; IsPointer = true; }
        internal GameLayoutCheck(string name, ulong address, string hex, int definitionIndex, string definitionHex)
        { Name = name; Address = address; Hex = hex; TypeDefinitionIndex = definitionIndex; TypeDefinitionHex = definitionHex; }
        internal byte[] Expected(ulong loadBias)
        { return IsPointer ? BitConverter.GetBytes(checked(loadBias + PointerTarget)) : Reader.Hex(Hex); }
    }
    public sealed class GameLayoutResult
    {
        public int Checks, FieldCandidates, MethodCandidates;
        public string MetadataSha256;
        public ulong RuntimeMetadataBase;
        public int TypeDescriptors;
    }
    public sealed partial class Reader
    {
        private static string LayoutHex(byte[] bytes)
        { return BitConverter.ToString(bytes).Replace("-", "").ToLowerInvariant(); }
        private static bool MetadataBytesMatch(string name, byte[] expected, byte[] actual, int pass, Action<string> progress)
        {
            if (EqualBytes(actual, expected)) return true;
            int offset = 0;
            while (offset < expected.Length && expected[offset] == actual[offset]) offset++;
            int length = Math.Min(32, expected.Length - offset);
            byte[] expectedSample = new byte[length], actualSample = new byte[length];
            Array.Copy(expected, offset, expectedSample, 0, length); Array.Copy(actual, offset, actualSample, 0, length);
            if (progress != null) progress("TypeMetadataDifference Name=" + name + " Pass=" + pass + " Offset=" + offset +
                " Bytes=" + length + " Expected=" + LayoutHex(expectedSample) + " Actual=" + LayoutHex(actualSample));
            return false;
        }
        private string VerifyTypeDescriptor(GameProcess game, GameLayoutCheck check, byte[] actual, ulong descriptorAddress,
            ref ulong metadataBase, int pass, Action<string> progress)
        {
            byte[] disk = Hex(check.Hex), record = Hex(check.TypeDefinitionHex);
            if (disk.Length != 12 || record.Length != 88 || check.TypeDefinitionIndex < 0 ||
                BitConverter.ToUInt64(disk, 0) != (ulong)check.TypeDefinitionIndex)
                throw new InvalidOperationException("Invalid type descriptor reference.");
            // The descriptor's four attribute/kind bytes remain exact. The data union
            // changes from a file type index to a pointer to that metadata row.
            for (int i = 8; i < 12; i++) if (actual[i] != disk[i]) return "DESCRIPTOR_FLAGS";
            ulong pointer = BitConverter.ToUInt64(actual, 0);
            ulong offset = checked(GameLayoutReference.TypeDefinitionsOffset + (ulong)check.TypeDefinitionIndex * 88UL);
            if (offset + 88 > GameLayoutReference.MetadataSize) throw new InvalidOperationException("Type record exceeds metadata reference.");
            if (pointer < offset + 0x10000UL || pointer >= 0x0000800000000000UL || (pointer & 3UL) != 0)
                return "INVALID_METADATA_POINTER";
            ulong candidate = pointer - offset;
            if (GameLayoutReference.MetadataSize > 0x0000800000000000UL - candidate) return "INVALID_METADATA_RANGE";
            if (metadataBase != 0 && candidate != metadataBase) return "INCONSISTENT_METADATA_BASE";
            byte[] header = Hex(GameLayoutReference.MetadataHeaderHex);
            if (!MetadataBytesMatch(check.Name + ".metadata_header", header, Virtual(game.Root, candidate, header.Length), pass, progress))
                return "METADATA_HEADER";
            if (!MetadataBytesMatch(check.Name + ".type_record", record, Virtual(game.Root, pointer, record.Length), pass, progress))
                return "TYPE_RECORD";
            if (!EqualBytes(actual, Virtual(game.Root, descriptorAddress, 12))) return "DESCRIPTOR_CHANGED_DURING_READ";
            metadataBase = candidate;
            return null;
        }
        public GameLayoutResult VerifyGameLayout(KernelContext kernel, GameProcess game, ModuleResult module, Action<string> progress)
        {
            if (module == null || module.BuildId != ApkModule.BuildId || module.ReferenceFileSha256 != ApkModule.FileSha256 ||
                module.LoadBias == 0 || !Canonical(module.LoadBias) || module.LoadBias >= 0x0000800000000000UL)
                throw new ArgumentException("The matching verified module result is required.");
            Recheck(kernel, game);
            byte[][] firstObservations = new byte[GameLayoutReference.Checks.Length][];
            bool[] mismatched = new bool[GameLayoutReference.Checks.Length];
            int mismatchObservations = 0, changedChecks = 0;
            string firstFailure = null;
            ulong metadataBase = 0;
            int verifiedDescriptors = 0;
            for (int pass = 1; pass <= 2; pass++)
            {
                int matchedThisPass = 0, mismatchedThisPass = 0;
                verifiedDescriptors = 0;
                for (int index = 0; index < GameLayoutReference.Checks.Length; index++)
                {
                    GameLayoutCheck check = GameLayoutReference.Checks[index];
                    byte[] expected = check.Expected(module.LoadBias);
                    if (expected.Length < 1 || expected.Length > 32)
                        throw new InvalidOperationException("Layout diagnostic sample exceeds its 32-byte bound.");
                    bool covered = false;
                    foreach (ModuleSegment segment in ApkModule.Segments)
                        if (check.Address >= segment.Address && checked(check.Address + (ulong)expected.Length) <= checked(segment.Address + segment.MemorySize)) covered = true;
                    ulong address = checked(module.LoadBias + check.Address);
                    if (!covered || checked(address + (ulong)expected.Length) > 0x0000800000000000UL)
                        throw new InvalidOperationException("Layout reference is outside the verified module segments.");
                    byte[] actual = Virtual(game.Root, address, expected.Length);
                    string reason = null;
                    bool matches;
                    if (check.TypeDefinitionIndex >= 0)
                    {
                        reason = VerifyTypeDescriptor(game, check, actual, address, ref metadataBase, pass, progress);
                        matches = reason == null;
                        if (matches) verifiedDescriptors++;
                    }
                    else matches = EqualBytes(actual, expected);
                    bool changed = pass == 2 && !EqualBytes(actual, firstObservations[index]);
                    if (pass == 1) firstObservations[index] = actual;
                    if (changed) { changedChecks++; matches = false; reason = "CHANGED_BETWEEN_PASSES"; }
                    if (matches) matchedThisPass++;
                    else
                    {
                        mismatchedThisPass++; mismatchObservations++; mismatched[index] = true;
                        if (firstFailure == null) firstFailure = check.Name + " RVA=0x" + check.Address.ToString("x") + " Pass=" + pass + " Reason=" + (reason ?? "EXACT_REFERENCE_BYTES");
                    }
                    if ((!matches || changed) && progress != null)
                        progress("GameLayoutDifference Name=" + check.Name + " RVA=0x" + check.Address.ToString("x") +
                            " Pass=" + pass + " Bytes=" + actual.Length + " MatchesValidation=" + matches +
                            " Reason=" + (reason ?? "EXACT_REFERENCE_BYTES") +
                            " ReferenceEncoding=" + (check.TypeDefinitionIndex >= 0 ? "ON_DISK_TYPE_INDEX" : "RUNTIME_BYTES") +
                            " ChangedSinceFirstPass=" + (pass == 1 ? "NA" : changed.ToString()) +
                            " Expected=" + BitConverter.ToString(expected).Replace("-", "").ToLowerInvariant() +
                            " Actual=" + BitConverter.ToString(actual).Replace("-", "").ToLowerInvariant());
                }
                Recheck(kernel, game);
                if (progress != null) progress("GameLayoutProgress Pass=" + pass + " ChecksCompared=" + GameLayoutReference.Checks.Length +
                    " ChecksMatched=" + matchedThisPass + " ChecksMismatched=" + mismatchedThisPass + " ProcessRecheck=PASS");
            }
            int distinctMismatches = 0;
            foreach (bool mismatch in mismatched) if (mismatch) distinctMismatches++;
            if (progress != null) progress("GameLayoutComparisonSummary Checks=" + GameLayoutReference.Checks.Length +
                " Passes=2 DistinctMismatches=" + distinctMismatches + " MismatchObservations=" + mismatchObservations +
                " ChangedBetweenPasses=" + changedChecks);
            if (firstFailure != null)
                throw new InvalidOperationException("Layout registration mismatch: " + firstFailure +
                    "; DistinctMismatches=" + distinctMismatches + " MismatchObservations=" + mismatchObservations);
            if (verifiedDescriptors != GameLayoutReference.Fields || metadataBase == 0)
                throw new InvalidOperationException("Incomplete runtime type descriptor validation.");
            return new GameLayoutResult { RuntimeMetadataBase = metadataBase, TypeDescriptors = verifiedDescriptors, Checks = GameLayoutReference.Checks.Length, FieldCandidates = GameLayoutReference.Fields,
                MethodCandidates = GameLayoutReference.Methods, MetadataSha256 = GameLayoutReference.MetadataSha256 };
        }
    }
}
