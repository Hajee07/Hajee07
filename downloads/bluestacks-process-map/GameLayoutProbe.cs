using System;

namespace HeadBridge.Mapping
{
    internal sealed class GameLayoutCheck
    {
        internal readonly string Name, Hex;
        internal readonly ulong Address, PointerTarget;
        internal readonly bool IsPointer;
        internal GameLayoutCheck(string name, ulong address, string hex)
        { Name = name; Address = address; Hex = hex; }
        internal GameLayoutCheck(string name, ulong address, ulong target)
        { Name = name; Address = address; PointerTarget = target; IsPointer = true; }
        internal byte[] Expected(ulong loadBias)
        { return IsPointer ? BitConverter.GetBytes(checked(loadBias + PointerTarget)) : Reader.Hex(Hex); }
    }
    public sealed class GameLayoutResult
    {
        public int Checks, FieldCandidates, MethodCandidates;
        public string MetadataSha256;
    }
    public sealed partial class Reader
    {
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
            for (int pass = 1; pass <= 2; pass++)
            {
                int matchedThisPass = 0, mismatchedThisPass = 0;
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
                    bool matches = EqualBytes(actual, expected);
                    bool changed = pass == 2 && !EqualBytes(actual, firstObservations[index]);
                    if (pass == 1) firstObservations[index] = actual;
                    if (changed) changedChecks++;
                    if (matches) matchedThisPass++;
                    else
                    {
                        mismatchedThisPass++; mismatchObservations++; mismatched[index] = true;
                        if (firstFailure == null) firstFailure = check.Name + " RVA=0x" + check.Address.ToString("x") + " Pass=" + pass;
                    }
                    if ((!matches || changed) && progress != null)
                        progress("GameLayoutDifference Name=" + check.Name + " RVA=0x" + check.Address.ToString("x") +
                            " Pass=" + pass + " Bytes=" + actual.Length + " MatchesReference=" + matches +
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
            return new GameLayoutResult { Checks = GameLayoutReference.Checks.Length, FieldCandidates = GameLayoutReference.Fields,
                MethodCandidates = GameLayoutReference.Methods, MetadataSha256 = GameLayoutReference.MetadataSha256 };
        }
    }
}
