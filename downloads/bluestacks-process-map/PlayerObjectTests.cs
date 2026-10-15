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
                foreach (GameLayoutCheck a in NativeTransformReference.Il2CppAnchors) Put(Module.LoadBias + a.Address, a.Expected(Module.LoadBias));
                U64(Module.LoadBias + 0xafb9e00, 0); U64(Module.LoadBias + 0xafb9e10, 0);
                Reader = new Reader(Memory.Transport, new RamRange[] { new RamRange(0, 0xffffffff) });
            }
            internal const ulong Model = 0x4a010000, DictionaryClass = 0x4b000000, Dictionary = 0x4b010000, Generic = 0x4c000000,
                Definition = 0x4c001000, Instance = 0x4c002000, Arguments = 0x4c003000, StringType = 0x4c004000, ValueType = 0x4c005000,
                StringClass = 0x4d000000, Key = 0x4e000000, Entries = 0x4f000000;
            internal const ulong Unity = 0x58000000, NativeHead = 0x50000000, NativeParent = 0x50001000, NativeRoot = 0x50002000,
                Hierarchy = 0x51000000, Matrices = 0x52000000, Parents = 0x53000000, Transforms = 0x54000000;
            internal void Trs(int index, float x, float y, float z, float qx, float qy, float qz, float qw, float sx, float sy, float sz)
            {
                float[] values = { x,y,z,0, qx,qy,qz,qw, sx,sy,sz,0 }; byte[] bytes = new byte[48];
                for (int i = 0; i < values.Length; i++) System.Array.Copy(BitConverter.GetBytes(values[i]), 0, bytes, i * 4, 4);
                Put(Matrices + (ulong)index * 48UL, bytes);
            }
            internal void SetupNative()
            {
                U64(Module.LoadBias + 0xafb9e00, Unity + 0x45ea4c); U64(Module.LoadBias + 0xafb9e10, Unity + 0x45ec64);
                foreach (GameLayoutCheck a in NativeTransformReference.Il2CppAnchors) Put(Module.LoadBias + a.Address, a.Expected(Module.LoadBias));
                foreach (GameLayoutCheck a in NativeTransformReference.UnityAnchors) Put(Unity + a.Address, a.Expected(Unity));
                Put(Unity, Reader.Hex(NativeTransformReference.HeaderHex)); Put(Unity + 64, Reader.Hex(NativeTransformReference.ProgramsHex));
                Put(Unity + 0x308, Reader.Hex(NativeTransformReference.NoteHex)); U64(Transform + 0x10, NativeHead);
                U64(Hierarchy, 0); U32(Hierarchy + 8, 0); U32(Hierarchy + 0x10, 3);
                U64(Hierarchy + 0x18, Matrices); U64(Hierarchy + 0x20, Parents); U64(Hierarchy + 0x30, Transforms);
                ulong[] objects = { NativeRoot, NativeParent, NativeHead };
                for (int i = 0; i < 3; i++)
                {
                    U64(Transforms + (ulong)i * 8UL, objects[i]); U64(objects[i] + 0x38, Hierarchy); U32(objects[i] + 0x40, (uint)i);
                    U64(objects[i] + 0x90, i == 0 ? 0 : objects[i-1]); U32(Parents + (ulong)i * 4UL, (uint)(i-1));
                }
                Trs(2,1,2,3,0,0,0,1,1,1,1);
                float half = (float)Math.Sqrt(0.5); Trs(1,10,0,0,0,0,half,half,2,3,4);
                Trs(0,100,200,300,0,0,0,1,1,1,1);
            }
            internal void NativeIndices(int parent,int head)
            {
                U32(Hierarchy+0x10,(uint)(head+1)); U32(NativeParent+0x40,(uint)parent); U32(NativeHead+0x40,(uint)head);
                U64(Transforms+(ulong)parent*8UL,NativeParent); U64(Transforms+(ulong)head*8UL,NativeHead);
                U32(Parents+(ulong)parent*4UL,0); U32(Parents+(ulong)head*4UL,(uint)parent);
                float half=(float)Math.Sqrt(0.5); Trs(parent,10,0,0,0,0,half,half,2,3,4); Trs(head,1,2,3,0,0,0,1,1,1,1);
            }
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
        private static void NativeFailure(Action<Fixture> change, string message, string label)
        {
            Fixture f = new Fixture(); f.SetupNative(); change(f); PlayerObjectResult result = f.Run();
            Check(result.HeadStatus == "MANAGED_TRANSFORM_VERIFIED" && result.HeadWorldStatus == "FAIL" &&
                result.HeadWorldError.IndexOf(message, StringComparison.OrdinalIgnoreCase) >= 0,
                label + " Detail=" + result.HeadWorldError);
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
            Fixture native = new Fixture(); native.SetupNative(); PlayerObjectResult world = native.Run();
            Check(world.HeadWorldStatus == "SAMPLED_READ_ONLY" && Math.Abs(world.HeadWorldX-104) < 0.0001 &&
                Math.Abs(world.HeadWorldY-202) < 0.0001 && Math.Abs(world.HeadWorldZ-312) < 0.0001 && world.HeadParentCount == 2,
                "native head hierarchy reproduces translation, nonuniform scale and rotation in parent order");
            Check(world.NativeHeadTransform == Fixture.NativeHead && world.HeadHierarchyCapacity == 3 && world.HeadWorldObservations < 128,
                "native sample keeps bounded hierarchy evidence and exact native identity");
            Check(new Fixture().Run().HeadWorldStatus == "NOT_READY_POSITION_ICALL_UNRESOLVED", "an unresolved icall is not initialized by the probe");
            NativeFailure(delegate(Fixture f) { f.U64(f.Module.LoadBias+0xafb9e00, Fixture.Unity+0x45ea50); }, "load bias", "incorrect icall binding fails exact module identification");
            NativeFailure(delegate(Fixture f) { f.Put(Fixture.Unity+0x693054,new byte[4]); }, "code identity", "changed native layout instructions fail the sample");
            NativeFailure(delegate(Fixture f) { f.Put(Fixture.Unity,new byte[4]); }, "ELF header", "native sampling requires the exact Unity ELF header");
            NativeFailure(delegate(Fixture f) { f.Put(Fixture.Matrices+96,BitConverter.GetBytes(float.NaN)); }, "finite native", "NaN local coordinates cannot produce a world sample");
            NativeFailure(delegate(Fixture f) { f.Trs(1,0,0,0,0,0,0,0,1,1,1); }, "quaternion norm", "invalid parent rotations fail the world calculation");
            NativeFailure(delegate(Fixture f) { f.U32(Fixture.Hierarchy+0x10,2); }, "capacity/index", "head index must fit the observed hierarchy allocation");
            NativeFailure(delegate(Fixture f) { f.U32(Fixture.Parents+8,3); }, "parent-index", "parent indices outside the hierarchy capacity fail");
            NativeFailure(delegate(Fixture f) { f.U32(Fixture.Parents+8,2); f.U64(Fixture.NativeHead+0x90,Fixture.NativeHead); }, "bound/cycle", "cyclic parent links fail without looping");
            NativeFailure(delegate(Fixture f) { f.U64(Fixture.Transforms+16,Fixture.NativeParent); }, "backlinks", "hierarchy slots must point back to the exact native Transform");
            NativeFailure(delegate(Fixture f) { f.U64(Fixture.NativeRoot+0x90,Fixture.NativeHead); }, "root parent", "root sentinel must agree with the native parent pointer");
            Fixture pending = new Fixture(); pending.SetupNative(); pending.U64(Fixture.Hierarchy,0x100000);
            Check(pending.Run().HeadWorldStatus == "NOT_READY_HIERARCHY_JOB_PENDING", "pending native jobs are reported without synchronizing or writing");
            Fixture nullNative = new Fixture(); nullNative.SetupNative(); nullNative.U64(Fixture.Transform+0x10,0);
            Check(nullNative.Run().HeadWorldStatus == "NOT_READY_NATIVE_TRANSFORM_NULL", "destroyed native objects do not invalidate the earlier managed-object observation");
            Fixture moving = new Fixture(); moving.SetupNative(); ulong movingAt = moving.Physical(Fixture.Matrices); int movingCopies=0;
            moving.Memory.AfterRead = delegate(ulong at,int length) {
                if(at==movingAt && length==144) { movingCopies++; moving.Put(Fixture.Matrices+96,BitConverter.GetBytes(movingCopies%2==1 ? 9f : 1f)); }
            };
            PlayerObjectResult motion = moving.Run();
            Check(motion.HeadWorldStatus=="FAIL" && motion.HeadWorldError.Contains("TRS_CHANGED") && motion.HeadSampleAttempts==3 && movingCopies==6,
                "continuously moving selected TRS rows fail after exactly three fresh attempts");
            Fixture settles = new Fixture(); settles.SetupNative(); ulong settlesAt=settles.Physical(Fixture.Matrices); int settleCopies=0;
            settles.Memory.AfterRead = delegate(ulong at,int length) {
                if(at==settlesAt && length==144 && ++settleCopies==1) settles.Put(Fixture.Matrices+96,BitConverter.GetBytes(9f));
            };
            PlayerObjectResult settled=settles.Run();
            Check(settled.HeadWorldStatus=="SAMPLED_READ_ONLY" && settled.HeadSampleAttempts==2 && Math.Abs(settled.HeadWorldY-218)<0.0001,
                "a fresh bounded attempt can capture a new stable pose after discarding a moving sample");
            Check(world.HeadCaptureChunks==1 && world.HeadSampleAttempts==1,
                "nearby head and ancestor rows share one bounded read per capture pass");
            Fixture identityChange=new Fixture(); identityChange.SetupNative(); ulong identityAt=identityChange.Physical(Fixture.Matrices);
            identityChange.Memory.AfterRead=delegate(ulong at,int length) {
                if(at==identityAt && length==144) identityChange.U64(Fixture.NativeHead+0x38,Fixture.Hierarchy+0x1000);
            };
            PlayerObjectResult changedIdentity=identityChange.Run();
            Check(changedIdentity.HeadWorldStatus=="FAIL" && changedIdentity.HeadWorldError.Contains("Native identity recheck") && changedIdentity.HeadSampleAttempts==1,
                "identity mutations fail immediately rather than taking the TRS-only retry path");
            Fixture gaps=new Fixture(); gaps.SetupNative(); gaps.NativeIndices(2,4); ulong gapsAt=gaps.Physical(Fixture.Matrices); int gapCopies=0;
            gaps.Memory.AfterRead=delegate(ulong at,int length) {
                if(at==gapsAt && length==240) gaps.Put(Fixture.Matrices+48,BitConverter.GetBytes(++gapCopies));
            };
            PlayerObjectResult gapResult=gaps.Run();
            Check(gapResult.HeadWorldStatus=="SAMPLED_READ_ONLY" && gapResult.HeadCaptureChunks==1 && gapCopies==2 && Math.Abs(gapResult.HeadWorldY-202)<0.0001,
                "unused gap bytes in a coalesced read do not masquerade as selected head-chain motion");
            Fixture sparse=new Fixture(); sparse.SetupNative(); sparse.NativeIndices(20,100); PlayerObjectResult sparseResult=sparse.Run();
            Check(sparseResult.HeadWorldStatus=="SAMPLED_READ_ONLY" && sparseResult.HeadCaptureChunks==3 && Math.Abs(sparseResult.HeadWorldX-104)<0.0001,
                "widely separated native rows use separate bounded capture chunks");
            Fixture readFailure=new Fixture(); readFailure.SetupNative(); ulong failAt=readFailure.Physical(Fixture.Matrices);
            readFailure.Memory.AfterRead=delegate(ulong at,int length) { if(at==failAt && length==144) throw new InvalidOperationException("Synthetic TRS transport failure"); };
            PlayerObjectResult readFailed=readFailure.Run();
            Check(readFailed.HeadWorldStatus=="FAIL" && readFailed.HeadSampleAttempts==1 && readFailed.HeadWorldError.Contains("transport failure"),
                "read failures are fatal rather than eligible for motion retries");
            Fixture bothChanges=new Fixture(); bothChanges.SetupNative(); ulong bothAt=bothChanges.Physical(Fixture.Matrices);
            bothChanges.Memory.AfterRead=delegate(ulong at,int length) {
                if(at==bothAt && length==144) { bothChanges.Put(Fixture.Matrices+96,BitConverter.GetBytes(9f)); bothChanges.U64(Fixture.NativeHead+0x38,Fixture.Hierarchy+0x1000); }
            };
            PlayerObjectResult both=bothChanges.Run();
            Check(both.HeadWorldStatus=="FAIL" && both.HeadSampleAttempts==1 && both.HeadWorldError.Contains("Native identity recheck"),
                "simultaneous TRS motion and identity changes cannot enter the retry path");
            Fixture negative = new Fixture(); negative.SetupNative(); negative.U64(negative.Module.LoadBias+0xafb9e00,0);
            negative.Trs(1,10,0,0,0,0,0,1,-2,3,4); PlayerObjectResult reflected = negative.Run();
            Check(reflected.HeadWorldStatus == "SAMPLED_READ_ONLY" && reflected.HeadWorldX==108 && reflected.HeadWorldY==206 && reflected.HeadWorldZ==312,
                "local-position binding fallback and reflected nonuniform scale retain signed coordinates");
            Fixture crossAxis = new Fixture(); crossAxis.SetupNative(); float sine = (float)Math.Sqrt(0.5);
            crossAxis.Trs(1,10,0,0,0,sine,0,sine,2,3,4); crossAxis.Trs(0,100,200,300,sine,0,0,sine,-1,2,0.5f);
            PlayerObjectResult cross = crossAxis.Run();
            Check(cross.HeadWorldStatus == "SAMPLED_READ_ONLY" && Math.Abs(cross.HeadWorldX-78)<0.0001 &&
                Math.Abs(cross.HeadWorldY-201)<0.0001 && Math.Abs(cross.HeadWorldZ-312)<0.0001,
                "noncommuting rotations across Y and X preserve native quaternion lane order");
            Fixture arbitrary = new Fixture(); arbitrary.SetupNative(); double divisor = Math.Sqrt(30);
            float qx=(float)(1/divisor), qy=(float)(2/divisor), qz=(float)(3/divisor), qw=(float)(4/divisor);
            arbitrary.Trs(1,10,0,0,qx,qy,qz,qw,2,3,4); PlayerObjectResult general = arbitrary.Run();
            // Independent double-precision rotation matrix oracle (XYZ only).
            double[] input={2,6,12}; double[,] matrix={
                {1-2*((double)qy*qy+(double)qz*qz),2*((double)qx*qy-(double)qz*qw),2*((double)qx*qz+(double)qy*qw)},
                {2*((double)qx*qy+(double)qz*qw),1-2*((double)qx*qx+(double)qz*qz),2*((double)qy*qz-(double)qx*qw)},
                {2*((double)qx*qz-(double)qy*qw),2*((double)qy*qz+(double)qx*qw),1-2*((double)qx*qx+(double)qy*qy)}};
            double[] expected={110,200,300}; for(int i=0;i<3;i++) for(int j=0;j<3;j++) expected[i]+=matrix[i,j]*input[j];
            Check(general.HeadWorldStatus=="SAMPLED_READ_ONLY" && Math.Abs(general.HeadWorldX-expected[0])<0.0001 &&
                Math.Abs(general.HeadWorldY-expected[1])<0.0001 && Math.Abs(general.HeadWorldZ-expected[2])<0.0001,
                "native SIMD reproduction agrees with an independent general quaternion matrix oracle");
            Console.WriteLine("NATIVE_HEAD_FIXTURE_READ_CALLS=" + native.Reader.PhysicalCalls + " OBSERVATIONS=" + world.HeadWorldObservations);
            Console.WriteLine("OBJECT_TOTAL=" + count + " (synthetic exact-build objects, managed Transform and native head sample)");
        }
    }
}
