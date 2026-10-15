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
            for (int pass = 1; pass <= 2; pass++)
            {
                foreach (GameLayoutCheck check in GameLayoutReference.Checks)
                {
                    byte[] expected = check.Expected(module.LoadBias);
                    bool covered = false;
                    foreach (ModuleSegment segment in ApkModule.Segments)
                        if (check.Address >= segment.Address && checked(check.Address + (ulong)expected.Length) <= checked(segment.Address + segment.MemorySize)) covered = true;
                    ulong address = checked(module.LoadBias + check.Address);
                    if (!covered || checked(address + (ulong)expected.Length) > 0x0000800000000000UL)
                        throw new InvalidOperationException("Layout reference is outside the verified module segments.");
                    if (!EqualBytes(Virtual(game.Root, address, expected.Length), expected))
                        throw new InvalidOperationException("Layout registration mismatch: " + check.Name + " RVA=0x" + check.Address.ToString("x") + " Pass=" + pass);
                }
                Recheck(kernel, game);
                if (progress != null) progress("GameLayoutProgress Pass=" + pass + " ChecksVerified=" + GameLayoutReference.Checks.Length);
            }
            return new GameLayoutResult { Checks = GameLayoutReference.Checks.Length, FieldCandidates = GameLayoutReference.Fields,
                MethodCandidates = GameLayoutReference.Methods, MetadataSha256 = GameLayoutReference.MetadataSha256 };
        }
    }
}
