using System;
using System.Collections.Generic;
using System.Text;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private static int count;
        private static void Check(bool condition, string label)
        { if (!condition) throw new Exception("FAIL: " + label); count++; Console.WriteLine("PASS: " + label); }
        private sealed partial class Fixture
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
                U64(Match+0x128,0);
                foreach(GameLayoutCheck a in RosterReference.Anchors) Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                U32(Module.LoadBias+RosterReference.FieldOffsetRva,0x128); U32(Module.LoadBias+RosterReference.FieldTypeRva+8,0x150004);
                Put(Layout.RuntimeMetadataBase+RosterReference.FieldMetadataOffset,Reader.Hex(RosterReference.FieldRecordHex));
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
                U32(Dictionary + 0x20, 1); U32(Dictionary + 0x24, 0xffffffff); U32(Dictionary + 0x28,0); U32(Dictionary + 0x2c,1); U64(Dictionary + 0x18, Entries); U64(Entries, 0x4f100000); U64(Entries + 0x18, 1);
                Put(Entries + 0x20, new byte[24]); U32(Entries + 0x20, 1234); U32(Entries + 0x24, 0xffffffff); U64(Entries + 0x28, Key); U64(Entries + 0x30, Provider);
                U64(Provider, Class(31705)); U64(Class(31705) + 0xb0, Interfaces); U64(Class(31705) + 0x138, Module.LoadBias + 0x70e0ba8);
            }
            internal const ulong RDict=0x56000000,RClass=0x56010000,REntries=0x56020000,RArrayClass=0x56030000,REntryClass=0x56040000,
                RGeneric=0x56050000,REntryGeneric=0x56060000,RDefinition=0x56070000,REntryDefinition=0x56080000,RInst=0x56090000,
                RArgs=0x560a0000,RKeyType=0x560b0000,RValueType=0x560c0000,RElement=0x560d0000,Other=0x57000000;
            private void RGenericClass(ulong klass,ObjectClassProfile profile,int kind,ulong generic,ulong definition,uint size)
            {
                MetadataIdentity(klass,profile); U64(klass+0x60,generic);U64(klass+0x20,generic);U32(klass+0x28,0x150000);U32(klass+0xf8,size);
                U64(generic,definition);U64(generic+8,RInst);U64(generic+0x10,0);U64(generic+0x18,klass);
                U64(definition,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)profile.Index*88UL);U32(definition+8,(uint)kind<<16);
            }
            internal void REntry(int index,ulong value)
            {
                byte[] bytes=new byte[40];System.Array.Copy(BitConverter.GetBytes(1),0,bytes,0,4);
                System.Array.Copy(BitConverter.GetBytes(-1),0,bytes,4,4);System.Array.Copy(BitConverter.GetBytes((ulong)(index+1)),0,bytes,8,8);
                System.Array.Copy(BitConverter.GetBytes(value),0,bytes,32,8);Put(REntries+0x20UL+(ulong)index*40UL,bytes);
            }
            internal void SetupRoster()
            {
                U64(Match+0x128,RDict);U64(RDict,RClass);
                RGenericClass(RClass,RosterReference.Dictionary,0x12,RGeneric,RDefinition,80);
                RGenericClass(REntryClass,RosterReference.Entry,0x11,REntryGeneric,REntryDefinition,56);
                MetadataIdentity(0x560e0000,RosterReference.Key);
                U64(Module.LoadBias+RosterReference.FieldTypeRva,RGeneric);U32(RInst,2);U64(RInst+8,RArgs);U64(RArgs,RKeyType);U64(RArgs+8,RValueType);
                U64(RKeyType,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+34565UL*88UL);U32(RKeyType+8,0x80110000);
                U64(RValueType,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+31824UL*88UL);U32(RValueType+8,0x120000);
                U64(RDict+0x18,REntries);U32(RDict+0x20,2);U32(RDict+0x24,0xffffffff);U32(RDict+0x28,0);U32(RDict+0x2c,1);
                U64(REntries,RArrayClass);U64(REntries+0x18,2);U64(RArrayClass+0x78,RArrayClass);U32(RArrayClass+0x28,0x1d0000);
                U64(RArrayClass+0x40,REntryClass);U64(RArrayClass+0x20,RElement);U64(RElement,REntryGeneric);U32(RElement+8,0x80150000);
                REntry(0,Player);REntry(1,Other);U64(Other,Class(32360));Put(Other+0x420,new byte[]{0});
            }
            internal void SetupOtherHead(ulong owner,ulong region,float x)
            {
                ulong provider=region,transform=region+0x1000,native=region+0x2000,hierarchy=region+0x3000,matrices=region+0x4000,
                    parents=region+0x6000,objects=region+0x7000;
                U64(owner,Class(32360));Put(owner+0x420,new byte[]{0});U64(owner+0xa00,provider);U64(owner+0x1530,0);
                U64(provider,Class(36295));U64(provider+0x10,transform);U64(transform,Class(ObjectReference.TransformIndex));U64(transform+0x10,native);
                U64(native+0x38,hierarchy);U32(native+0x40,0);U64(native+0x90,0);
                U64(hierarchy,0);U32(hierarchy+8,0);U32(hierarchy+0x10,1);U64(hierarchy+0x18,matrices);U64(hierarchy+0x20,parents);U64(hierarchy+0x30,objects);
                U32(parents,0xffffffff);U64(objects,native);float[] values={x,32,33,0,0,0,0,1,1,1,1,0};byte[] trs=new byte[48];
                for(int i=0;i<12;i++)System.Array.Copy(BitConverter.GetBytes(values[i]),0,trs,i*4,4);Put(matrices,trs);
            }
            internal void DeepOtherHead(ulong owner,ulong region)
            {
                SetupOtherHead(owner,region,31);ulong hierarchy=region+0x3000,head=region+0x2000;
                U32(hierarchy+0x10,128);U32(head+0x40,127);
                byte[] trs=new byte[48];System.Array.Copy(BitConverter.GetBytes(1f),0,trs,28,4);
                for(int axis=0;axis<3;axis++)System.Array.Copy(BitConverter.GetBytes(1f),0,trs,32+axis*4,4);
                for(int i=0;i<128;i++)
                {
                    ulong node=i==127?head:region+0x10000UL+(ulong)i*0x100UL;
                    ulong parent=i==0?0:region+0x10000UL+(ulong)(i-1)*0x100UL;
                    U64(node+0x38,hierarchy);U32(node+0x40,(uint)i);U64(node+0x90,parent);
                    U64(region+0x7000UL+(ulong)i*8UL,node);U32(region+0x6000UL+(ulong)i*4UL,(uint)(i-1));Put(region+0x4000UL+(ulong)i*48UL,trs);
                }
            }
            internal OtherHeadResult OtherHeads(PlayerObjectResult core)
            { return Reader.SampleOtherPlayerHeads(Kernel,Game,Module,Layout,core,Progress.Add); }
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
        private static void RosterFailure(Action<Fixture> change,string message,string label)
        {
            Fixture f=new Fixture();f.SetupRoster();change(f);PlayerObjectResult result=f.Run();
            Check(result.HeadStatus=="MANAGED_TRANSFORM_VERIFIED" && result.RosterStatus=="FAIL" && result.RosterAttempts==1 && result.RosterError.Contains(message),label+" Detail="+result.RosterError);
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
            cacheChanged.Memory.AfterRead = delegate(ulong address, int length) { if (address == chars && length == 18) cacheChanged.U32(Fixture.Dictionary + 0x2c, 2); };
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
            Check(motion.HeadWorldStatus=="NOT_READY_MOTION" && motion.HeadWorldError.Contains("TRS_CHANGED") && motion.HeadSampleAttempts==3 && movingCopies==6 && motion.HeadWorldX==0,
                "continuously moving selected TRS rows yield no pose after exactly three fresh attempts");
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
            Check(changedIdentity.HeadWorldError.Contains("Field=NativeTransform.Hierarchy"),"native identity diagnostics identify a changed hierarchy pointer without guessing from its address");
            Fixture jobChange=new Fixture();jobChange.SetupNative();ulong jobAt=jobChange.Physical(Fixture.Matrices);
            jobChange.Memory.AfterRead=delegate(ulong at,int length){if(at==jobAt && length==144)jobChange.U64(Fixture.Hierarchy,0x12340000);};
            PlayerObjectResult jobChanged=jobChange.Run();
            Check(jobChanged.HeadWorldStatus=="FAIL" && jobChanged.HeadSampleAttempts==1 && jobChanged.HeadWorldX==0 && jobChanged.HeadWorldError.Contains("Field=Hierarchy.JobHandle"),
                "a job handle that changes during native capture remains an identity failure with a precise field label");
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
            Fixture roster=new Fixture();roster.SetupRoster();PlayerObjectResult players=roster.Run();
            Check(players.RosterStatus=="TYPED_COLLECTION_VERIFIED" && players.RosterLocalPresent && players.RosterCandidates==2 &&
                players.MatchPlayers.Length==2 && players.RosterOtherVerified==1 && players.MatchPlayers[1].Class=="COW.GamePlay.PlayerNetwork" && players.RosterComplete,
                "typed match dictionary verifies local and other Player objects with exact generic context and entry stride");
            Check(roster.Reader.PhysicalCalls<8000 && players.RosterObservations<1024,"bounded roster sampling shares the existing Reader and snapshot limits");
            Check(new Fixture().Run().RosterStatus=="NOT_READY_COLLECTION_NULL","missing match collection is reported without initialization");
            Fixture empty=new Fixture();empty.SetupRoster();empty.U32(Fixture.RDict+0x20,0);
            Check(empty.Run().RosterStatus=="EMPTY","an empty typed collection does not require an allocated entry array");
            Fixture rosterPatched=new Fixture();rosterPatched.SetupRoster();rosterPatched.U64(Fixture.Array+0x20UL+0x1bfUL*8UL,Fixture.Other);
            Check(rosterPatched.Run().RosterStatus=="HOTFIX_ACTIVE_COLLECTION_GETTER","active collection getter hotfix prevents following the original field path");
            RosterFailure(delegate(Fixture f){ f.U64(Fixture.RValueType,f.Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+32133UL*88UL); },
                "value must be Player","collection value generic argument must be the exact Player definition");
            RosterFailure(delegate(Fixture f){ f.U32(Fixture.REntryClass+0xf8,48); },"entry runtime size","entry stride is checked against the runtime closed value-type size");
            RosterFailure(delegate(Fixture f){ f.U32(Fixture.RArrayClass+0x28,0x150000); },"entry array identity","an arbitrary object cannot substitute for the entry array");
            RosterFailure(delegate(Fixture f){ f.U64(Fixture.REntries+0x18,1); },"entry-array capacity","entry array must cover all used slots");
            RosterFailure(delegate(Fixture f){ f.U32(Fixture.RDict+0x20,257); },"used/free bound","roster scan is capped at 256 used entries");
            RosterFailure(delegate(Fixture f){ f.U32(Fixture.RDict+0x28,1); },"removed count","observed removed entries must agree with the dictionary free count");
            RosterFailure(delegate(Fixture f){ f.U32(Fixture.REntries+0x24,9); },"entry link bound","active entry chain indices remain bounded");
            RosterFailure(delegate(Fixture f){ f.U64(Fixture.REntries+0x40,8); },"roster Player candidate","noncanonical or low candidate addresses fail before dereference");
            RosterFailure(delegate(Fixture f){ f.U64(Fixture.Other,Fixture.Class(32133)); },"object family","collection values must be supported Player objects");
            RosterFailure(delegate(Fixture f){ f.Put(Fixture.Other+0x420,new byte[]{1}); },"local-player marker","an additional locally marked object is not silently treated as another player");
            Fixture removedRoster=new Fixture();removedRoster.SetupRoster();removedRoster.U32(Fixture.REntries+0x20,0xffffffff);removedRoster.U32(Fixture.RDict+0x28,1);
            PlayerObjectResult removedPlayers=removedRoster.Run();
            Check(removedPlayers.RosterStatus=="TYPED_COLLECTION_VERIFIED" && removedPlayers.RosterRemoved==1 && !removedPlayers.RosterLocalPresent && removedPlayers.RosterOtherVerified==1,
                "removed slots are ignored and local membership is observed rather than assumed for this collection");
            Fixture nullValue=new Fixture();nullValue.SetupRoster();nullValue.REntry(1,0);PlayerObjectResult nullPlayers=nullValue.Run();
            Check(nullPlayers.RosterStatus=="TYPED_COLLECTION_VERIFIED" && nullPlayers.RosterNullValues==1 && nullPlayers.RosterCandidates==1,
                "null active values are counted without being promoted to Player objects");
            Fixture duplicateRoster=new Fixture();duplicateRoster.SetupRoster();duplicateRoster.REntry(1,Fixture.Player);PlayerObjectResult duplicatePlayers=duplicateRoster.Run();
            Check(duplicatePlayers.RosterStatus=="TYPED_COLLECTION_VERIFIED" && duplicatePlayers.RosterCandidates==1 && duplicatePlayers.RosterActive==2,
                "repeated value pointers are deduplicated without equating entry count to unique players");
            Fixture rosterSettles=new Fixture();rosterSettles.SetupRoster();ulong rosterAt=rosterSettles.Physical(Fixture.REntries+0x20);
            rosterSettles.Memory.AfterRead=delegate(ulong p,int n){if(p==rosterAt && n==80)rosterSettles.U32(Fixture.RDict+0x2c,2);};
            PlayerObjectResult settledRoster=rosterSettles.Run();
            Check(settledRoster.RosterStatus=="TYPED_COLLECTION_VERIFIED" && settledRoster.RosterAttempts==2 && BitConverter.ToUInt32(settledRoster.RosterCounterSnapshot,12)==2,
                "a changed dictionary version discards the first attempt and accepts a fresh stable counter snapshot");
            Fixture changingRoster=new Fixture();changingRoster.SetupRoster();ulong changingAt=changingRoster.Physical(Fixture.REntries+0x20);uint version=1;
            changingRoster.Memory.AfterRead=delegate(ulong p,int n){if(p==changingAt && n==80)changingRoster.U32(Fixture.RDict+0x2c,++version);};
            PlayerObjectResult changedRoster=changingRoster.Run();
            Check(changedRoster.RosterStatus=="NOT_READY_COLLECTION_CHANGED" && changedRoster.RosterAttempts==2 && changedRoster.MatchPlayers.Length==0 &&
                changedRoster.RosterCounterSnapshot==null && changedRoster.RosterCandidates==0,
                "persistent roster motion stops after two fresh attempts without leaking discarded membership proofs");
            Check(changedRoster.RosterError.Contains("Bytes=16") && changedRoster.RosterError.Contains("FirstChangedOffset=12") &&
                changingRoster.Progress.FindAll(delegate(string text){return text.StartsWith("RosterSampleChanged");}).Count==2,
                "snapshot diagnostics locate the changed byte within the observed range without logging key contents");
            Fixture entrySettles=new Fixture();entrySettles.SetupRoster();ulong entryAt=entrySettles.Physical(Fixture.REntries+0x20);bool replaced=false;
            entrySettles.Memory.AfterRead=delegate(ulong p,int n){if(p==entryAt && n==80 && !replaced){replaced=true;entrySettles.REntry(1,0);}};
            PlayerObjectResult newEntries=entrySettles.Run();
            Check(newEntries.RosterStatus=="TYPED_COLLECTION_VERIFIED" && newEntries.RosterAttempts==2 && newEntries.MatchPlayers.Length==1 && newEntries.RosterNullValues==1 && newEntries.RosterOtherVerified==0,
                "retry rebuilds the entry snapshot and never merges a discarded member into a later accepted collection");
            Fixture rosterHotfix=new Fixture();rosterHotfix.SetupRoster();ulong patchAt=rosterHotfix.Physical(Fixture.REntries+0x20);
            rosterHotfix.Memory.AfterRead=delegate(ulong p,int n){if(p==patchAt && n==80)rosterHotfix.U64(Fixture.Array+0x20UL+0x1bfUL*8UL,Fixture.Other);};
            PlayerObjectResult patchedRoster=rosterHotfix.Run();
            Check(patchedRoster.RosterStatus=="HOTFIX_ACTIVE_COLLECTION_GETTER" && patchedRoster.RosterAttempts==2 && patchedRoster.MatchPlayers.Length==0,
                "a retry checks the hotfix gate again and cannot accept the original collection path after an override");
            Fixture rosterBudget=new Fixture();rosterBudget.SetupRoster();ulong budgetAt=rosterBudget.Physical(rosterBudget.Module.LoadBias+RosterReference.Anchors[0].Address);bool burn=false;int start=0;
            rosterBudget.Memory.AfterRead=delegate(ulong p,int n){if(p==budgetAt && !burn){burn=true;start=rosterBudget.Reader.PhysicalCalls;for(int i=0;i<4501;i++)rosterBudget.Reader.Physical(0,1);}};
            PlayerObjectResult budgetRoster=rosterBudget.Run();
            Check(budgetRoster.RosterStatus=="NOT_READY_READ_BUDGET" && budgetRoster.RosterAttempts==1 && budgetRoster.MatchPlayers.Length==0 && rosterBudget.Reader.PhysicalCalls>start+4500,
                "roster call scope stops a costly observation and restores allowance for final object checks");
            Fixture many=new Fixture();many.SetupRoster();many.U32(Fixture.RDict+0x20,20);many.U64(Fixture.REntries+0x18,20);
            for(int i=1;i<20;i++){ulong address=Fixture.Other+(ulong)(i-1)*4096UL;many.U64(address,Fixture.Class(32360));many.Put(address+0x420,new byte[]{0});many.REntry(i,address);}
            PlayerObjectResult rosterBounded=many.Run();
            Check(rosterBounded.RosterStatus=="TYPED_COLLECTION_VERIFIED" && rosterBounded.RosterCandidates==20 && rosterBounded.MatchPlayers.Length==16 &&
                rosterBounded.RosterOtherVerified==15 && !rosterBounded.RosterComplete && rosterBounded.MatchPlayers[0].IsLocal,
                "at most sixteen unique Player objects are verified and remaining candidates are reported as incomplete");
            Fixture staged=new Fixture();staged.SetupNative();staged.SetupRoster();staged.U32(Fixture.REntryClass+0xf8,48);PlayerObjectResult stagedResult=staged.Run();
            Check(stagedResult.HeadWorldStatus=="SAMPLED_READ_ONLY" && stagedResult.RosterStatus=="FAIL" && stagedResult.MatchPlayers.Length==0,
                "a failed roster stage preserves the earlier valid native head sample and emits no verified roster objects");
            const ulong otherRegion=0x57100000,secondOwner=0x57010000,secondRegion=0x57200000,thirdOwner=0x57020000;
            Fixture other=new Fixture();other.SetupNative();other.SetupRoster();other.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult otherCore=other.Run();
            int beforeOther=other.Reader.PhysicalCalls;OtherHeadResult one=other.OtherHeads(otherCore);
            Check(one.Sampled==1 && one.Samples.Length==1 && one.Samples[0].Status=="SAMPLED_READ_ONLY" && one.Samples[0].Player==Fixture.Other && one.Samples[0].X==31 && one.Samples[0].Y==32 && one.Samples[0].Z==33,
                "a verified nonlocal dictionary member resolves its own managed/native head rather than the local head");
            Check(otherCore.HeadWorldX==104 && one.Samples[0].Provider==otherRegion && one.Samples[0].RosterIndex==1,
                "other-head sampling preserves the local sample and reports the exact collection member");
            Check(one.Samples[0].MembershipProof=="SELECTED_ENTRY_REVALIDATED" && !one.Samples[0].CountersChangedSinceRoster,
                "an accepted other-head observation reports its fresh selected-entry proof separately from the earlier roster");
            Check(other.Reader.PhysicalCalls>beforeOther && other.Reader.PhysicalCalls-beforeOther<=6000,"other-head phase consumes the same shared Reader within its additional-call bound");
            moving.SetupRoster();moving.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult motionCore=moving.Run();OtherHeadResult despiteMotion=moving.OtherHeads(motionCore);
            Check(motionCore.HeadWorldStatus=="NOT_READY_MOTION" && despiteMotion.Sampled==1 && despiteMotion.Samples[0].X==31,
                "an unavailable moving local pose does not prevent an independently verified other-head sample");
            Fixture remoteMotion=new Fixture();remoteMotion.SetupNative();remoteMotion.SetupRoster();remoteMotion.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult remoteCore=remoteMotion.Run();
            ulong remoteAt=remoteMotion.Physical(otherRegion+0x4000);int remoteCopies=0;
            remoteMotion.Memory.AfterRead=delegate(ulong p,int n){if(p==remoteAt && n==48)remoteMotion.Put(otherRegion+0x4000,BitConverter.GetBytes(++remoteCopies%2==1 ? 41f : 31f));};
            OtherHeadResult noRemotePose=remoteMotion.OtherHeads(remoteCore);
            Check(noRemotePose.Sampled==0 && noRemotePose.Samples[0].Status=="NOT_READY_MOTION" && noRemotePose.Samples[0].Attempts==3 && remoteCopies==6 && noRemotePose.Samples[0].X==0,
                "an animated other head is reported as unavailable with no XYZ after the same three-attempt limit");
            Fixture absent=new Fixture();absent.SetupNative();absent.SetupRoster();absent.SetupOtherHead(Fixture.Other,otherRegion,31);absent.U64(Fixture.Other+0xa00,0);
            OtherHeadResult noHead=absent.OtherHeads(absent.Run());
            Check(noHead.Sampled==0 && noHead.Samples[0].Status=="NOT_READY_MODEL_CACHE_NULL","an uncached other head is reported without initializing Unity or substituting the local head");
            Fixture versionMove=new Fixture();versionMove.SetupNative();versionMove.SetupRoster();versionMove.SetupOtherHead(Fixture.Other,otherRegion,31);
            PlayerObjectResult versionCore=versionMove.Run();versionMove.U32(Fixture.RDict+0x2c,2);OtherHeadResult staleCollection=versionMove.OtherHeads(versionCore);
            Check(staleCollection.Sampled==1 && staleCollection.Samples[0].MembershipProof=="SELECTED_ENTRY_REVALIDATED" && staleCollection.Samples[0].CountersChangedSinceRoster &&
                BitConverter.ToUInt32(versionCore.RosterCounterSnapshot,12)==1,
                "a version changed before sampling permits a fresh exact selected-member proof without rewriting the old roster counters");
            Fixture removedOther=new Fixture();removedOther.SetupNative();removedOther.SetupRoster();removedOther.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult beforeRemoval=removedOther.Run();
            removedOther.U32(Fixture.RDict+0x28,1);removedOther.U32(Fixture.RDict+0x24,0);removedOther.U32(Fixture.RDict+0x2c,2);removedOther.U32(Fixture.REntries+0x20,0xffffffff);
            OtherHeadResult afterRemoval=removedOther.OtherHeads(beforeRemoval);
            Check(afterRemoval.Sampled==1 && afterRemoval.Samples[0].CountersChangedSinceRoster && beforeRemoval.RosterRemoved==0 && beforeRemoval.MatchPlayers.Length==2,
                "removing a different entry before capture does not invalidate the unchanged selected entry or revise the historical roster");
            Fixture selectedRemoved=new Fixture();selectedRemoved.SetupNative();selectedRemoved.SetupRoster();selectedRemoved.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult oldSelected=selectedRemoved.Run();
            selectedRemoved.U32(Fixture.RDict+0x28,1);selectedRemoved.U32(Fixture.RDict+0x24,1);selectedRemoved.U32(Fixture.REntries+0x20UL+40UL,0xffffffff);
            OtherHeadResult removedSelected=selectedRemoved.OtherHeads(oldSelected);
            Check(removedSelected.Sampled==0 && removedSelected.StopReason=="CONTEXT_CHANGED" && removedSelected.Samples[0].Detail.Contains("entry fingerprint"),
                "removing the selected entry before capture never passes fresh membership even if its old object pointer remains stored");
            Fixture shrunken=new Fixture();shrunken.SetupNative();shrunken.SetupRoster();shrunken.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult beforeShrink=shrunken.Run();shrunken.U32(Fixture.RDict+0x20,1);
            OtherHeadResult shrink=shrunken.OtherHeads(beforeShrink);
            Check(shrink.Sampled==0 && shrink.StopReason=="CONTEXT_CHANGED" && shrink.Samples[0].Detail.Contains("selected entry index"),
                "a saved entry outside the fresh used-slot count cannot be sampled");
            Fixture invalidCounters=new Fixture();invalidCounters.SetupNative();invalidCounters.SetupRoster();invalidCounters.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult counterCore=invalidCounters.Run();invalidCounters.U32(Fixture.RDict+0x28,3);
            OtherHeadResult invalidCount=invalidCounters.OtherHeads(counterCore);
            Check(invalidCount.Sampled==0 && invalidCount.StopReason=="SAMPLE_FAILED" && invalidCount.Samples[0].Detail.Contains("counter bounds"),
                "fresh collection counters still enforce hard bounds rather than accepting any changed header");
            Fixture fieldChanged=new Fixture();fieldChanged.SetupNative();fieldChanged.SetupRoster();fieldChanged.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult fieldCore=fieldChanged.Run();fieldChanged.U64(fieldChanged.Module.LoadBias+RosterReference.FieldTypeRva,Fixture.RGeneric+8);
            OtherHeadResult invalidField=fieldChanged.OtherHeads(fieldCore);
            Check(invalidField.Sampled==0 && invalidField.StopReason=="FAIL" && invalidField.Samples.Length==0 && invalidField.Detail.Contains("field registration"),
                "fresh selected membership revalidates exact field registration and rejects a changed declared generic type");
            Fixture keyMove=new Fixture();keyMove.SetupNative();keyMove.SetupRoster();keyMove.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult keyCore=keyMove.Run();
            keyMove.Put(Fixture.REntries+0x20UL+40UL+8UL,new byte[]{99});OtherHeadResult changedKey=keyMove.OtherHeads(keyCore);
            Check(changedKey.Sampled==0 && changedKey.Samples[0].Detail.Contains("entry fingerprint"),"selected entry key/value bytes must still match even when its header version is unchanged");
            Fixture actorMove=new Fixture();actorMove.SetupNative();actorMove.SetupRoster();actorMove.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult actorCore=actorMove.Run();
            actorMove.Put(Fixture.Other+0x420,new byte[]{1});OtherHeadResult changedActor=actorMove.OtherHeads(actorCore);
            Check(changedActor.Sampled==0 && changedActor.StopReason=="CONTEXT_CHANGED","a changed selected object's local marker invalidates its other-player role");
            Fixture overrideHead=new Fixture();overrideHead.SetupNative();overrideHead.SetupRoster();overrideHead.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult overrideCore=overrideHead.Run();
            overrideHead.U64(Fixture.Array+0x20UL+0x34eUL*8UL,Fixture.Other);OtherHeadResult hotfixHead=overrideHead.OtherHeads(overrideCore);
            Check(hotfixHead.Sampled==0 && hotfixHead.Samples[0].Status=="HOTFIX_ACTIVE_HEAD_GETTER","other-head sampling honors the existing head-getter hotfix gate");
            Fixture changeDuring=new Fixture();changeDuring.SetupNative();changeDuring.SetupRoster();changeDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult duringCore=changeDuring.Run();
            ulong otherPose=changeDuring.Physical(otherRegion+0x4000);changeDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==otherPose && length==48)changeDuring.U32(Fixture.RDict+0x2c,2);};
            OtherHeadResult during=changeDuring.OtherHeads(duringCore);
            Check(during.Sampled==1 && during.Samples[0].CountersChangedDuringCapture && during.Samples[0].Attempts==1 && during.Samples[0].X==31 && during.Samples[0].MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "a changed global version can accompany an unchanged revalidated selected entry without claiming a stable whole collection");
            Fixture freeDuring=new Fixture();freeDuring.SetupNative();freeDuring.SetupRoster();freeDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult freeCore=freeDuring.Run();
            ulong freePose=freeDuring.Physical(otherRegion+0x4000);freeDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==freePose && length==48){freeDuring.U32(Fixture.RDict+0x24,0);freeDuring.U32(Fixture.RDict+0x28,1);freeDuring.U32(Fixture.REntries+0x20,0xffffffff);}};
            OtherHeadResult changedFreeList=freeDuring.OtherHeads(freeCore);
            Check(changedFreeList.Sampled==1 && changedFreeList.Samples[0].CountersChangedDuringCapture && changedFreeList.Samples[0].X==31 && freeCore.RosterRemoved==0,
                "removal of a different entry during capture permits only the unchanged selected-entry observation and leaves the historical roster untouched");
            Fixture selectedDuring=new Fixture();selectedDuring.SetupNative();selectedDuring.SetupRoster();selectedDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult selectedCore=selectedDuring.Run();
            ulong selectedPose=selectedDuring.Physical(otherRegion+0x4000);selectedDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==selectedPose && length==48){selectedDuring.U32(Fixture.RDict+0x24,1);selectedDuring.U32(Fixture.RDict+0x28,1);selectedDuring.U32(Fixture.REntries+0x20UL+40UL,0xffffffff);}};
            OtherHeadResult removedDuring=selectedDuring.OtherHeads(selectedCore);
            Check(removedDuring.Sampled==0 && removedDuring.StopReason=="CONTEXT_CHANGED" && removedDuring.Samples[0].CountersChangedDuringCapture &&
                removedDuring.Samples[0].Detail.Contains("Field=OtherMembership.SelectedEntry") && removedDuring.Samples[0].X==0 && removedDuring.Samples[0].MembershipProof==null,
                "selected-entry removal during capture discards coordinates even though global counter changes are audited separately");
            Fixture shrinkDuring=new Fixture();shrinkDuring.SetupNative();shrinkDuring.SetupRoster();shrinkDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult shrinkCore=shrinkDuring.Run();
            ulong shrinkPose=shrinkDuring.Physical(otherRegion+0x4000);shrinkDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==shrinkPose && length==48)shrinkDuring.U32(Fixture.RDict+0x20,1);};
            OtherHeadResult shrunkDuring=shrinkDuring.OtherHeads(shrinkCore);
            Check(shrunkDuring.Sampled==0 && shrunkDuring.StopReason=="CONTEXT_CHANGED" && shrunkDuring.Samples[0].Detail.Contains("selected entry index at AFTER") && shrunkDuring.Samples[0].X==0,
                "the selected index must remain inside the final audited used-slot range");
            Fixture badFinal=new Fixture();badFinal.SetupNative();badFinal.SetupRoster();badFinal.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult badFinalCore=badFinal.Run();
            ulong badFinalPose=badFinal.Physical(otherRegion+0x4000);badFinal.Memory.AfterRead=delegate(ulong at,int length){if(at==badFinalPose && length==48)badFinal.U32(Fixture.RDict+0x28,3);};
            OtherHeadResult invalidFinal=badFinal.OtherHeads(badFinalCore);
            Check(invalidFinal.Sampled==0 && invalidFinal.StopReason=="SAMPLE_FAILED" && invalidFinal.Samples[0].Detail.Contains("counter bounds Phase=AFTER") && invalidFinal.Samples[0].X==0,
                "invalid final counter bounds remain a hard failure despite otherwise unchanged selected bytes");
            Fixture auditBefore=new Fixture();auditBefore.SetupNative();auditBefore.SetupRoster();auditBefore.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult beforeAuditCore=auditBefore.Run();
            ulong auditBeforeAt=auditBefore.Physical(Fixture.RDict+0x20);uint changingVersion=1;
            auditBefore.Memory.AfterRead=delegate(ulong at,int length){if(at==auditBeforeAt && length==16)auditBefore.U32(Fixture.RDict+0x2c,++changingVersion);};
            OtherHeadResult unstableBefore=auditBefore.OtherHeads(beforeAuditCore);
            Check(unstableBefore.Sampled==0 && unstableBefore.StopReason=="CONTEXT_CHANGED" && unstableBefore.Samples[0].Attempts==0 && unstableBefore.Samples[0].Detail.Contains("audit changed at BEFORE"),
                "both before-capture header copies must match and an unstable endpoint causes no native attempt");
            Fixture auditAfter=new Fixture();auditAfter.SetupNative();auditAfter.SetupRoster();auditAfter.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult afterAuditCore=auditAfter.Run();
            ulong auditAfterAt=auditAfter.Physical(Fixture.RDict+0x20),auditPose=auditAfter.Physical(otherRegion+0x4000);uint afterVersion=1;bool captured=false;
            auditAfter.Memory.AfterRead=delegate(ulong at,int length){if(at==auditPose && length==48)captured=true;if(captured && at==auditAfterAt && length==16)auditAfter.U32(Fixture.RDict+0x2c,++afterVersion);};
            OtherHeadResult unstableAfter=auditAfter.OtherHeads(afterAuditCore);
            Check(unstableAfter.Sampled==0 && unstableAfter.StopReason=="CONTEXT_CHANGED" && unstableAfter.Samples[0].Attempts==1 && unstableAfter.Samples[0].Detail.Contains("audit changed at AFTER") && unstableAfter.Samples[0].X==0,
                "an unstable final audit discards a native pose without retrying or relaxing endpoint comparisons");
            Fixture swappedDictionary=new Fixture();swappedDictionary.SetupNative();swappedDictionary.SetupRoster();swappedDictionary.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult swappedCore=swappedDictionary.Run();
            ulong swappedPose=swappedDictionary.Physical(otherRegion+0x4000);swappedDictionary.Memory.AfterRead=delegate(ulong at,int length){if(at==swappedPose && length==48)swappedDictionary.U64(Fixture.Match+0x128,Fixture.RDict+0x1000);};
            OtherHeadResult swappedResult=swappedDictionary.OtherHeads(swappedCore);
            Check(swappedResult.Sampled==0 && swappedResult.Samples.Length==0 && swappedResult.StopReason=="FINAL_CONTEXT_FAILED",
                "a dictionary pointer swap invalidates the phase rather than treating it as a global counter change");
            Fixture capacityDuring=new Fixture();capacityDuring.SetupNative();capacityDuring.SetupRoster();capacityDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult capacityCore=capacityDuring.Run();
            ulong capacityPose=capacityDuring.Physical(otherRegion+0x4000);capacityDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==capacityPose && length==48)capacityDuring.U64(Fixture.REntries+0x18,4);};
            OtherHeadResult capacityResult=capacityDuring.OtherHeads(capacityCore);
            Check(capacityResult.Sampled==0 && capacityResult.StopReason=="CONTEXT_CHANGED" && capacityResult.Samples[0].Detail.Contains("Field=OtherMembership.Capacity") && capacityResult.Samples[0].X==0,
                "a changed entry-array capacity is still rejected independently of the global counter audit");
            Fixture schemaDuring=new Fixture();schemaDuring.SetupNative();schemaDuring.SetupRoster();schemaDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult schemaCore=schemaDuring.Run();
            ulong schemaPose=schemaDuring.Physical(otherRegion+0x4000);schemaDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==schemaPose && length==48)schemaDuring.U32(schemaDuring.Module.LoadBias+RosterReference.FieldOffsetRva,0x130);};
            OtherHeadResult changedSchema=schemaDuring.OtherHeads(schemaCore);
            Check(changedSchema.Sampled==0 && changedSchema.Samples.Length==0 && changedSchema.StopReason=="FINAL_CONTEXT_FAILED",
                "a phase-wide schema change discards all tentative rows at final checks");
            Fixture entryDuring=new Fixture();entryDuring.SetupNative();entryDuring.SetupRoster();entryDuring.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult entryCore=entryDuring.Run();
            ulong entryPose=entryDuring.Physical(otherRegion+0x4000);entryDuring.Memory.AfterRead=delegate(ulong at,int length){if(at==entryPose && length==48)entryDuring.Put(Fixture.REntries+0x20UL+40UL+8UL,new byte[]{99});};
            OtherHeadResult changedEntry=entryDuring.OtherHeads(entryCore);
            Check(changedEntry.Sampled==0 && changedEntry.StopReason=="CONTEXT_CHANGED" && changedEntry.Samples[0].Detail.Contains("Field=OtherMembership.SelectedEntry") && changedEntry.Samples[0].Attempts==1,
                "selected key/value changes during capture are rejected even when the fresh counter bytes stay unchanged");
            Fixture remoteIdentity=new Fixture();remoteIdentity.SetupNative();remoteIdentity.SetupRoster();remoteIdentity.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult identityCore=remoteIdentity.Run();
            ulong identityPose=remoteIdentity.Physical(otherRegion+0x4000);remoteIdentity.Memory.AfterRead=delegate(ulong at,int length){if(at==identityPose && length==48)remoteIdentity.U64(otherRegion+0x3000,0x12340000);};
            OtherHeadResult badIdentity=remoteIdentity.OtherHeads(identityCore);
            Check(badIdentity.Sampled==0 && badIdentity.StopReason=="SAMPLE_FAILED" && badIdentity.Samples[0].Status=="FAIL" && badIdentity.Samples[0].Attempts==1 &&
                badIdentity.Samples[0].Detail.Contains("Field=Hierarchy.JobHandle") && badIdentity.Samples[0].X==0,
                "a remote native identity change remains a hard failure with the attempted count and field label");
            Fixture two=new Fixture();two.SetupNative();two.SetupRoster();two.U32(Fixture.RDict+0x20,4);two.U64(Fixture.REntries+0x18,4);
            two.SetupOtherHead(Fixture.Other,otherRegion,31);two.SetupOtherHead(secondOwner,secondRegion,41);two.U64(thirdOwner,Fixture.Class(32360));two.Put(thirdOwner+0x420,new byte[]{0});
            two.REntry(2,secondOwner);two.REntry(3,thirdOwner);OtherHeadResult twoResult=two.OtherHeads(two.Run());
            Check(twoResult.Eligible==3 && twoResult.Sampled==2 && twoResult.Samples.Length==2 && twoResult.Samples[1].X==41 && twoResult.StopReason=="TWO_OBJECT_LIMIT",
                "at most two verified other objects are sampled and each uses its own head position");
            Fixture deep=new Fixture();deep.SetupNative();deep.SetupRoster();deep.DeepOtherHead(Fixture.Other,otherRegion);PlayerObjectResult deepCore=deep.Run();int deepBefore=deep.Reader.PhysicalCalls;
            OtherHeadResult deepResult=deep.OtherHeads(deepCore);
            Check(deepResult.StopReason=="READ_LIMIT_REACHED" && deepResult.Sampled==0 && deep.Reader.PhysicalCalls-deepBefore<=6000,
                "an expensive native hierarchy stops at the optional phase's read cap while reserving final identity checks Stop="+deepResult.StopReason+" Detail="+deepResult.Detail+" Row="+(deepResult.Samples.Length==0?"NONE":deepResult.Samples[0].Detail)+" Calls="+(deep.Reader.PhysicalCalls-deepBefore));
            deep.Reader.Physical(0,1);Check(deep.Reader.PhysicalCalls>deepBefore+5000,"exhausting the optional read scope preserves the remaining global allowance");
            Fixture reserve=new Fixture();reserve.SetupNative();reserve.SetupRoster();reserve.SetupOtherHead(Fixture.Other,otherRegion,31);PlayerObjectResult reserveCore=reserve.Run();
            while(reserve.Reader.PhysicalCalls<29000)reserve.Reader.Physical(0,1);OtherHeadResult reserved=reserve.OtherHeads(reserveCore);
            Check(reserved.StopReason=="READ_BUDGET_RESERVE" && reserved.Samples.Length==0 && reserve.Reader.PhysicalCalls==29000,
                "the optional phase performs no reads when only its reserved global allowance remains");
            Check(other.OtherHeads(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","other-head reads require the verified collection snapshot");
            Fixture cachedOther=new Fixture();cachedOther.SetupNative();cachedOther.SetupRoster();cachedOther.SetupHeadCache();cachedOther.SetupOtherHead(Fixture.Other,otherRegion,31);
            ulong otherModel=otherRegion+0x9000,otherDictionary=otherRegion+0xa000,otherEntries=otherRegion+0xb000;
            cachedOther.U64(Fixture.Other+0xa00,0);cachedOther.U64(Fixture.Other+0x1530,otherModel);cachedOther.U64(otherModel,Fixture.Class(31706));cachedOther.U64(otherModel+0x10,otherDictionary);
            cachedOther.U64(otherDictionary,Fixture.DictionaryClass);cachedOther.U32(otherDictionary+0x20,1);cachedOther.U32(otherDictionary+0x24,0xffffffff);
            cachedOther.U32(otherDictionary+0x28,0);cachedOther.U32(otherDictionary+0x2c,1);cachedOther.U64(otherDictionary+0x18,otherEntries);
            cachedOther.U64(otherEntries,0x4f100000);cachedOther.U64(otherEntries+0x18,1);cachedOther.U32(otherEntries+0x20,1);cachedOther.U32(otherEntries+0x24,0xffffffff);
            cachedOther.U64(otherEntries+0x28,Fixture.Key);cachedOther.U64(otherEntries+0x30,otherRegion);cachedOther.U64(otherRegion,Fixture.Class(31705));
            OtherHeadResult cachedRemote=cachedOther.OtherHeads(cachedOther.Run());
            Check(cachedRemote.Sampled==1 && cachedRemote.Samples[0].Source=="MODEL_DICTIONARY" && cachedRemote.Samples[0].X==31 && cachedRemote.Samples[0].Provider==otherRegion,
                "a remote owner's cached bone_Head resolves through its own model dictionary with the shared strict resolver");
            Console.WriteLine("OTHER_HEAD_FIXTURE_ADDITIONAL_READ_CALLS="+(other.Reader.PhysicalCalls-beforeOther)+" OBSERVATIONS="+one.Samples[0].Observations);
            Console.WriteLine("ROSTER_FIXTURE_READ_CALLS="+roster.Reader.PhysicalCalls+" OBSERVATIONS="+players.RosterObservations);
            Console.WriteLine("NATIVE_HEAD_FIXTURE_READ_CALLS=" + native.Reader.PhysicalCalls + " OBSERVATIONS=" + world.HeadWorldObservations);
            RunStateTests();
            RunTeamTests();
            RunCombatTests();
            Console.WriteLine("OBJECT_TOTAL=" + count + " (synthetic exact-build objects, native head sample, match dictionary and state)");
        }
    }
}
