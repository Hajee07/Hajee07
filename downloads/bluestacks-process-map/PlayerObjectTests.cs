using System;
using System.Collections.Generic;
using System.Text;

namespace HeadBridge.Mapping.Tests
{
    public static class PlayerObjectTests
    {
        private static int count;
        private static void Check(bool condition, string label)
        { if (!condition) throw new Exception("FAIL: " + label); count++; Console.WriteLine("PASS: " + label); }
        private sealed class Fixture
        {
            internal readonly Memory Memory = new Memory();
            internal readonly KernelContext Kernel = new KernelContext(0x1000, 0, 0);
            internal readonly GameProcess Game;
            internal readonly ModuleResult Module = new ModuleResult { LoadBias = 0x60000000, BuildId = ApkModule.BuildId, ReferenceFileSha256 = ApkModule.FileSha256 };
            internal readonly GameLayoutResult Layout = new GameLayoutResult { RuntimeMetadataBase = 0x90000000, TypeDescriptors = 9, Checks = 80, FieldCandidates = 9, MethodCandidates = 9, MetadataSha256 = GameLayoutReference.MetadataSha256 };
            internal readonly Reader Reader;
            internal readonly List<string> Progress = new List<string>();
            private readonly Dictionary<ulong, ulong> pages = new Dictionary<ulong, ulong>();
            private ulong next = 0x8000000;
            internal const ulong FacadeStatics = 0x41000000, HotfixStatics = 0x41001000, Array = 0x42000000, ArrayClass = 0x43000000;
            internal const ulong Current = 0x44000000, Match = 0x45000000, Player = 0x46000000, Provider = 0x47000000, Transform = 0x48000000, Interfaces = 0x49000000;
            internal static ulong Class(int index) { return 0x20000000UL + (ulong)index * 4096UL; }
            internal Fixture()
            {
                const ulong k = 0xffff888000000000;
                Memory.Map4K(0x1000, k + 0x1000, 0x101000); Memory.Map4K(0x1000, k + 0x3000, 0x103000); Memory.Map4K(0x1000, k + 0x4000, 0x2000);
                Game = new GameProcess { Pid = 2942, Name = ".dts.freefireth", Task = k + 0x1000, Mm = k + 0x3000, PgdVirtual = k + 0x4000, Root = 0x2000 };
                Memory.Put64(0x1014c0, Game.Mm); Memory.Write(0x101570, BitConverter.GetBytes(Game.Pid));
                Memory.Write(0x101720, Encoding.ASCII.GetBytes(Game.Name + "\0")); Memory.Put64(0x103050, Game.PgdVirtual);
                foreach (GameLayoutCheck check in ObjectReference.Anchors) Put(Module.LoadBias + check.Address, check.Expected(Module.LoadBias));
                foreach (ObjectClassProfile profile in ObjectReference.Classes)
                {
                    ulong klass = Class(profile.Index), row = Layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + (ulong)profile.Index * 88UL;
                    Put(row, Reader.Hex(profile.RecordHex)); U64(klass + 0x68, row); U64(klass + 0x78, klass); U64(klass + 0x20, row); U32(klass + 0x28, profile.Bits);
                    U64(klass + 0x10, Layout.RuntimeMetadataBase + profile.NameOffset); U64(klass + 0x18, Layout.RuntimeMetadataBase + profile.NamespaceOffset);
                    U32(klass + 0x11c, profile.Token); U32(klass + 0xf8, profile.InstanceSizeExact ? profile.InstanceSize : profile.MinimumInstanceSize); U32(klass + 0xe0, 1);
                    byte[] counts = new byte[16]; System.Array.Copy(Reader.Hex(profile.RecordHex), 0x40, counts, 0, 16); Put(klass + 0x120, counts);
                    if (profile.Parent >= 0) U64(klass + 0x58, Class(profile.Parent));
                }
                U64(Module.LoadBias + ObjectReference.FacadeCell, Class(12418)); U64(Module.LoadBias + ObjectReference.MatchGameCell, Class(12425));
                U64(Module.LoadBias + ObjectReference.HotfixCell, Class(37332)); U64(Module.LoadBias + ObjectReference.HeadInterfaceCell, Class(36294));
                const ulong fieldTable = 0x4a000000;
                U64(Class(37332) + 0x80, fieldTable); U32(Class(37332) + 0x10c, 8);
                ulong field = fieldTable + (ulong)ObjectReference.WrapperFieldIndex * 32UL;
                U64(field, Layout.RuntimeMetadataBase + ObjectReference.WrapperFieldNameOffset);
                U64(field + 8, Module.LoadBias + ObjectReference.WrapperTypeRva); U64(field + 0x10, Class(37332));
                U32(field + 0x18, 0); U32(field + 0x1c, ObjectReference.WrapperFieldToken);
                Put(Layout.RuntimeMetadataBase + ObjectReference.WrapperMetadataOffset, Reader.Hex(ObjectReference.WrapperFieldRecordHex));
                U32(Module.LoadBias + ObjectReference.WrapperTypeRva + 8, ObjectReference.WrapperTypeBits);
                U64(Class(12418) + 0xb8, FacadeStatics); U64(Class(37332) + 0xb8, HotfixStatics); U64(HotfixStatics, Array);
                U64(Array, ArrayClass); U32(ArrayClass + 0x28, 0x1d0000); U64(ArrayClass + 0x40, Class(37332)); U64(Array + 0x18, 0x400);
                foreach (int id in new int[] { 0x1c6, 0x139, 0x1c5, 0x12b, 0x34e }) U64(Array + 0x20UL + (ulong)id * 8UL, 0);
                U64(FacadeStatics, Current); U64(Current, Class(12425)); U64(Current + 0x90, Match); U64(Match, Class(32133));
                U64(Match + 0xd8, Player); U64(Player, Class(31824)); Put(Player + 0x420, new byte[] { 1 }); U64(Player + 0xa00, Provider);
                U64(Player + 0x1530, 0);
                foreach (ObjectClassProfile c in ObjectReference.Classes)
                    if (c.Index == 31824 || c.Index == 32360)
                    {
                        U64(Class(c.Index) + 0x308, Module.LoadBias + 0x7013344);
                        int start = BitConverter.ToInt32(Reader.Hex(c.RecordHex), 0x38);
                        U32(Layout.RuntimeMetadataBase + ObjectReference.VtableTableOffset + ((ulong)start + 29UL) * 4UL, 0x600677bf);
                    }
                U64(Provider, Class(36295)); U64(Provider + 0x10, Transform); U64(Transform, Class(ObjectReference.TransformIndex));
                Put(Class(36295) + 0x12e, BitConverter.GetBytes((ushort)1)); U64(Class(36295) + 0xb0, Interfaces);
                Put(Interfaces, new byte[16]); U64(Interfaces, Class(36294)); U64(Class(36295) + 0x138, Module.LoadBias + 0x8259e90);
                Reader = new Reader(Memory.Transport, new RamRange[] { new RamRange(0, 0xffffffff) });
            }
            internal const ulong Model = 0x4a010000, DictionaryClass = 0x4b000000, Dictionary = 0x4b010000, Generic = 0x4c000000,
                Definition = 0x4c001000, Instance = 0x4c002000, Arguments = 0x4c003000, StringType = 0x4c004000, ValueType = 0x4c005000,
                StringClass = 0x4d000000, Key = 0x4e000000, Entries = 0x4f000000;
            private void MetadataIdentity(ulong klass, ObjectClassProfile profile)
            {
                ulong row = Layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + (ulong)profile.Index * 88UL;
                Put(row, Reader.Hex(profile.RecordHex)); U64(klass + 0x68, row); U64(klass + 0x78, klass); U32(klass + 0x11c, profile.Token);
                U64(klass + 0x10, Layout.RuntimeMetadataBase + profile.NameOffset); U64(klass + 0x18, Layout.RuntimeMetadataBase + profile.NamespaceOffset);
            }
            internal void SetupHeadCache()
            {
                U64(Player + 0xa00, 0); U64(Player + 0x1530, Model); U64(Model, Class(31706)); U64(Model + 0x10, Dictionary);
                MetadataIdentity(DictionaryClass, ObjectReference.HeadDictionaryProfile); MetadataIdentity(StringClass, ObjectReference.HeadStringProfile);
                U64(Dictionary, DictionaryClass); U64(DictionaryClass + 0x60, Generic); U64(DictionaryClass + 0x20, Generic); U32(DictionaryClass + 0x28, 0x150000);
                U32(DictionaryClass + 0xf8, 80); U64(Module.LoadBias + ObjectReference.HeadDictionaryTypeRva, Generic);
                U32(Module.LoadBias + ObjectReference.HeadDictionaryTypeRva + 8, ObjectReference.HeadDictionaryTypeBits);
                U64(Generic, Definition); U64(Generic + 8, Instance); U64(Generic + 0x18, DictionaryClass);
                U64(Definition, Layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + (ulong)ObjectReference.HeadDictionaryProfile.Index * 88UL);
                U32(Definition + 8, 0x120000); U32(Instance, 2); U64(Instance + 8, Arguments);
                U64(Arguments, StringType); U64(Arguments + 8, ValueType); U32(StringType + 8, 0xe0000);
                U32(ValueType + 8, 0x120000); U64(ValueType, Layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + 31705UL * 88UL);
                U32(StringClass + 0x28, 0xe0000); U64(Key, StringClass); U32(Key + 0x10, 9); Put(Key + 0x14, Reader.Hex(ObjectReference.HeadKeyUtf16Hex));
                U32(Dictionary + 0x20, 1); U32(Dictionary + 0x24, 1); U64(Dictionary + 0x18, Entries); U64(Entries, 0x4f100000); U64(Entries + 0x18, 1);
                Put(Entries + 0x20, new byte[24]); U32(Entries + 0x20, 1234); U32(Entries + 0x24, 0xffffffff); U64(Entries + 0x28, Key); U64(Entries + 0x30, Provider);
                U64(Provider, Class(31705)); U64(Class(31705) + 0xb0, Interfaces); U64(Class(31705) + 0x138, Module.LoadBias + 0x70e0ba8);
            }
            internal void Put(ulong address, byte[] bytes)
            {
                for (int i = 0; i < bytes.Length; i++)
                {
                    ulong at = address + (ulong)i, page = at & ~4095UL, physical;
                    if (!pages.TryGetValue(page, out physical)) { physical = next; next += 4096; pages.Add(page, physical); Memory.Map4K(Game.Root, page, physical); }
                    Memory.Write(physical + (at & 4095UL), new byte[] { bytes[i] });
                }
            }
            internal void U64(ulong address, ulong value) { Put(address, BitConverter.GetBytes(value)); }
            internal void U32(ulong address, uint value) { Put(address, BitConverter.GetBytes(value)); }
            internal ulong Physical(ulong address) { return pages[address & ~4095UL] + (address & 4095UL); }
            internal PlayerObjectResult Run() { return Reader.VerifyPlayerObjects(Kernel, Game, Module, Layout, Progress.Add); }
        }
        private static void Reject(Fixture fixture, string text, string label)
        {
            bool rejected = false;
            try { fixture.Run(); } catch (Exception error) { rejected = error.Message.Contains(text); }
            Check(rejected, label);
        }
        public static void Run()
        {
            Fixture valid = new Fixture(); PlayerObjectResult result = valid.Run();
            Check(result.LocalPlayer == Fixture.Player && result.Match == Fixture.Match && result.HeadTransform == Fixture.Transform && result.HeadStatus == "MANAGED_TRANSFORM_VERIFIED",
                "verified classes and original paths identify local player and managed head Transform");
            Check(valid.Reader.PhysicalCalls < 5000 && result.Observations < 1024, "object verification fits the shared read and snapshot bounds");
            Console.WriteLine("OBJECT_FIXTURE_READ_CALLS=" + valid.Reader.PhysicalCalls + " OBSERVATIONS=" + result.Observations);
            Fixture derived = new Fixture(); derived.U64(Fixture.Player, Fixture.Class(32360));
            Check(derived.Run().PlayerClass == "COW.GamePlay.PlayerNetwork", "supported derived Player validates its metadata and runtime parent chain");
            Fixture unresolved = new Fixture(); unresolved.U64(unresolved.Module.LoadBias + ObjectReference.FacadeCell, 0x20011e3b);
            Reject(unresolved, "not resolved", "unresolved metadata usage is never followed as a class pointer");
            Fixture missing = new Fixture(); missing.U64(Fixture.Match + 0xd8, 0);
            Reject(missing, "local player is null", "lobby or unspawned local-player state is reported as not ready");
            Fixture wrongFamily = new Fixture(); wrongFamily.U64(Fixture.Current, Fixture.Class(31824));
            Reject(wrongFamily, "object family", "a Player cannot replace the current MatchGame object");
            Fixture flag = new Fixture(); flag.Put(Fixture.Player + 0x420, new byte[] { 0 });
            Reject(flag, "local-player bool", "the selected Player must have its local-player marker set");
            Fixture metadata = new Fixture(); metadata.Put(metadata.Layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + 31824UL * 88UL, new byte[] { 0 });
            Reject(metadata, "type record", "live class metadata records must match the exact input");
            Fixture classSelf = new Fixture(); classSelf.U64(Fixture.Class(31824) + 0x78, Fixture.Class(37332));
            Reject(classSelf, "class self", "plausible class pointers do not bypass self identity");
            Fixture classSize = new Fixture(); classSize.U32(Fixture.Class(31824) + 0xf8, 16);
            Reject(classSize, "instance size", "incorrect runtime instance sizes are rejected");
            Fixture parent = new Fixture(); parent.U64(Fixture.Player, Fixture.Class(32360)); parent.U64(Fixture.Class(32360) + 0x58, Fixture.Class(37332));
            Reject(parent, "runtime parent", "derived object ancestry must match the decoded metadata");
            Fixture patched = new Fixture(); patched.U64(Fixture.Array + 0x20UL + 0x1c6UL * 8UL, 0x50000000);
            Reject(patched, "HOTFIX_ACTIVE", "an active local-player hotfix prevents accepting the original path");
            Fixture array = new Fixture(); array.U64(Fixture.Array + 0x18, 1000001);
            Reject(array, "array length bound", "malformed hotfix array lengths are bounded");
            Fixture providerNull = new Fixture(); providerNull.U64(Fixture.Player + 0xa00, 0);
            Check(providerNull.Run().HeadStatus == "NOT_READY_MODEL_CACHE_NULL", "a null lazy head provider does not fabricate a Transform");
            Fixture headPatch = new Fixture(); headPatch.U64(Fixture.Array + 0x20UL + 0x34eUL * 8UL, 0x50000000);
            Check(headPatch.Run().HeadStatus == "HOTFIX_ACTIVE_HEAD_GETTER", "a head getter hotfix is reported separately from the verified local-player chain");
            Fixture method = new Fixture(); method.U64(Fixture.Class(36295) + 0x138, method.Module.LoadBias + 0x37987c4);
            Reject(method, "getter target", "provider interface dispatch must select that class's exact getter");
            Fixture transform = new Fixture(); transform.U64(Fixture.Transform, Fixture.Class(31824));
            Reject(transform, "object family", "a non-Transform object cannot pass as the managed head Transform");
            Fixture changed = new Fixture(); ulong trigger = changed.Physical(Fixture.Player + 0x420);
            changed.Memory.AfterRead = delegate(ulong address, int length) { if (address == trigger && length == 1) changed.U64(Fixture.Match + 0xd8, Fixture.Provider); };
            Reject(changed, "final recheck", "changed local-player chain is rejected before a result is returned");
            Fixture identity = new Fixture(); ulong identityTrigger = identity.Physical(Fixture.Player + 0x420);
            identity.Memory.AfterRead = delegate(ulong address, int length) { if (address == identityTrigger && length == 1) identity.Memory.Put64(0x1014c0, 0xffff888000009000UL); };
            Reject(identity, "Game identity", "changed guest process memory context invalidates object observations");
            Fixture anchors = new Fixture(); GameLayoutCheck first = ObjectReference.Anchors[0]; anchors.Put(anchors.Module.LoadBias + first.Address, new byte[] { 0 });
            Reject(anchors, "object code anchor", "new object-path instruction samples must match before pointers are followed");
            Fixture profile = new Fixture(); profile.Layout.TypeDescriptors = 0;
            Reject(profile, "verified module and runtime layout", "object probe requires prior runtime metadata verification");
            Check(profile.Reader.PhysicalCalls == 0, "invalid prior profile causes no guest reads");
            Fixture interfaceCount = new Fixture(); interfaceCount.Put(Fixture.Class(36295) + 0x12e, BitConverter.GetBytes((ushort)65));
            Reject(interfaceCount, "provider interface count", "interface scans cannot exceed the exact profile count and hard bound");
            Fixture vtable = new Fixture(); vtable.U32(Fixture.Interfaces + 8, 4095);
            Reject(vtable, "vtable slot", "an interface offset cannot index beyond the class's actual vtable count");
            Fixture transformNull = new Fixture(); transformNull.U64(Fixture.Provider + 0x10, 0);
            Check(transformNull.Run().HeadStatus == "NOT_READY_TRANSFORM_NULL", "a null Transform is a distinct readiness result");
            Fixture misaligned = new Fixture(); misaligned.U64(Fixture.Player + 0xa00, Fixture.Provider + 1);
            Reject(misaligned, "Object pointer invalid", "misaligned provider addresses are rejected before following them");
            Check(classSize.Progress.Exists(delegate(string line) { return line.Contains("ObjectClassLayoutDifference") && line.Contains("ExpectedInstanceSize=9328") &&
                line.Contains("ActualInstanceSize=16") && line.Contains("ActualToken=0x"); }), "class layout diagnostics preserve expected and actual sizes and token");
            Fixture token = new Fixture(); token.U32(Fixture.Class(37332) + 0x11c, 0);
            bool tokenRejected = false;
            try { token.Run(); } catch (Exception error) { tokenRejected = error.Message.Contains("class token IFix"); }
            Check(tokenRejected && token.Progress.Exists(delegate(string line) { return line.Contains("ObjectClassLayoutDifference Name=IFix") &&
                line.Contains("ActualToken=0x0") && line.Contains("ActualInstanceSize="); }), "token and instance-size failures remain distinct and cannot become a PASS");
            bool sane = true; int bounded = 0, opaque = 0;
            foreach (ObjectClassProfile c in ObjectReference.Classes)
            {
                if (c.InstanceSizeExact) sane &= c.InstanceSize >= c.MinimumInstanceSize && c.InstanceSize <= 1048576;
                else bounded++;
                if (c.InstanceSize > 1048576) { opaque++; sane &= !c.InstanceSizeExact; }
            }
            Check(sane && bounded >= 6 && opaque == 6, "opaque native sizes are never promoted to exact runtime expectations");
            Fixture dynamicSize = new Fixture(); dynamicSize.U32(Fixture.Class(37332) + 0xf8, 48);
            Check(dynamicSize.Run().LocalPlayer == Fixture.Player && dynamicSize.Progress.Exists(delegate(string line) { return line.Contains("ObjectClassSizeObservation Name=IFix") &&
                line.Contains("ActualInstanceSize=48"); }), "bounded IFix runtime sizes require the independently verified runtime field layout");
            Fixture small = new Fixture(); small.U32(Fixture.Class(37332) + 0xf8, 32);
            Reject(small, "class instance size", "IFix runtime size cannot be smaller than its declared instance fields");
            Fixture staticSize = new Fixture(); staticSize.U32(Fixture.Class(37332) + 0x10c, 0);
            Reject(staticSize, "static storage extent", "runtime static storage must contain the wrapper reference");
            Fixture fieldOffset = new Fixture(); fieldOffset.U32(0x4a000000UL + (ulong)ObjectReference.WrapperFieldIndex * 32UL + 0x18, 8);
            Reject(fieldOffset, "static field offset", "runtime field offset must independently agree with static offset zero");
            Fixture fieldToken = new Fixture(); fieldToken.U32(0x4a000000UL + (ulong)ObjectReference.WrapperFieldIndex * 32UL + 0x1c, 0);
            Reject(fieldToken, "wrapper field identity", "an unrelated runtime field cannot masquerade as wrapperArray");
            bool interfaceZero = false;
            foreach (ObjectClassProfile c in ObjectReference.Classes) if (c.Index == 36294)
                interfaceZero = c.InstanceSizeExact && c.InstanceSize == 0 && c.MinimumInstanceSize == 0;
            Check(interfaceZero, "interface class size zero remains valid without treating it as an object instance");
            Fixture cache = new Fixture(); cache.SetupHeadCache(); PlayerObjectResult cached = cache.Run();
            Check(cached.HeadStatus == "MANAGED_TRANSFORM_VERIFIED" && cached.HeadSource == "MODEL_DICTIONARY" && cached.HeadCacheEntries == 1 && cached.HeadTransform == Fixture.Transform,
                "a null player cache can resolve the exact cached bone_Head Transform without initialization");
            Check(cache.Reader.PhysicalCalls < 7000 && cached.Observations < 1024, "model-cache lookup stays within the shared read and snapshot bounds");
            Console.WriteLine("HEAD_CACHE_FIXTURE_READ_CALLS=" + cache.Reader.PhysicalCalls + " OBSERVATIONS=" + cached.Observations);
            Fixture miss = new Fixture(); miss.SetupHeadCache(); miss.Put(Fixture.Key + 0x14, new byte[] { 0x78 });
            Check(miss.Run().HeadStatus == "NOT_READY_BONE_NOT_CACHED", "different bone names cannot substitute for bone_Head");
            Fixture removed = new Fixture(); removed.SetupHeadCache(); removed.U32(Fixture.Entries + 0x20, 0xffffffff);
            Check(removed.Run().HeadStatus == "NOT_READY_BONE_NOT_CACHED", "removed dictionary entries are ignored");
            Fixture duplicate = new Fixture(); duplicate.SetupHeadCache(); duplicate.U32(Fixture.Dictionary + 0x20, 2); duplicate.U64(Fixture.Entries + 0x18, 2);
            duplicate.Put(Fixture.Entries + 0x38, duplicate.Memory.Bytes(duplicate.Physical(Fixture.Entries + 0x20), 24));
            Reject(duplicate, "duplicate bone_Head", "duplicate active head keys fail rather than choosing an arbitrary entry");
            Fixture tooMany = new Fixture(); tooMany.SetupHeadCache(); tooMany.U32(Fixture.Dictionary + 0x20, 513);
            Reject(tooMany, "used-entry bound", "model dictionary scan is bounded to 512 used entries");
            Fixture wrongArgument = new Fixture(); wrongArgument.SetupHeadCache(); wrongArgument.U64(Fixture.ValueType,
                wrongArgument.Layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + 31824UL * 88UL);
            Reject(wrongArgument, "value must be BFOONIGAIFK", "closed generic dictionary arguments must match the exact declared cache type");
            Fixture cacheChanged = new Fixture(); cacheChanged.SetupHeadCache(); ulong chars = cacheChanged.Physical(Fixture.Key + 0x14);
            cacheChanged.Memory.AfterRead = delegate(ulong address, int length) { if (address == chars && length == 18) cacheChanged.U32(Fixture.Dictionary + 0x24, 2); };
            Reject(cacheChanged, "final recheck", "dictionary version changes invalidate the lookup result");
            Fixture lookupPatch = new Fixture(); lookupPatch.SetupHeadCache(); lookupPatch.U64(Fixture.Array + 0x18, 0x30000);
            lookupPatch.U64(Fixture.Array + 0x20UL + 0x21f1aUL * 8UL, 0x50000000);
            Check(lookupPatch.Run().HeadStatus == "HOTFIX_ACTIVE_MODEL_LOOKUP", "model lookup hotfixes prevent following the original cache path");
            Fixture target = new Fixture(); target.SetupHeadCache(); target.U64(Fixture.Class(31824) + 0x308, target.Module.LoadBias + 0x70e0ba8);
            Check(target.Run().HeadStatus == "UNSUPPORTED_MODEL_VIRTUAL_TARGET", "unsupported virtual overrides are reported without guessing their field layout");
            Fixture wrongNode = new Fixture(); wrongNode.SetupHeadCache(); wrongNode.U64(Fixture.Provider, Fixture.Class(36295));
            Reject(wrongNode, "cached head node value class", "cache values must match the declared concrete node type");
            Fixture longKey = new Fixture(); longKey.SetupHeadCache(); longKey.U32(Fixture.Key + 0x10, 257);
            Reject(longKey, "key length bound", "string reads remain bounded even for corrupted dictionary keys");
            Fixture wrongString = new Fixture(); wrongString.SetupHeadCache(); wrongString.U64(Fixture.Key, Fixture.Class(31824));
            Reject(wrongString, "head cache class identity", "cache key objects must be the exact System.String class");
            Console.WriteLine("OBJECT_TOTAL=" + count + " (synthetic exact-build objects and managed Transform)");
        }
    }
}
