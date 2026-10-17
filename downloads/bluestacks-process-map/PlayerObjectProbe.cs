using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    internal sealed class ObjectClassProfile
    {
        internal readonly int Index, Family, Parent;
        internal readonly string Name, RecordHex;
        internal readonly ulong NameOffset, NamespaceOffset, Getter;
        internal readonly uint Bits, InstanceSize, StaticSize, Token, MinimumInstanceSize;
        internal readonly bool InstanceSizeExact;
        internal ObjectClassProfile(int index, string name, int family, int parent, ulong nameOffset, ulong namespaceOffset,
            string recordHex, uint bits, uint instanceSize, uint staticSize, uint token, ulong getter, uint minimumInstanceSize, bool instanceSizeExact)
        { Index = index; Name = name; Family = family; Parent = parent; NameOffset = nameOffset; NamespaceOffset = namespaceOffset;
          RecordHex = recordHex; Bits = bits; InstanceSize = instanceSize; StaticSize = staticSize; Token = token; Getter = getter; MinimumInstanceSize = minimumInstanceSize; InstanceSizeExact = instanceSizeExact; }
    }
    public sealed class PlayerObjectResult
    {
        public ulong CurrentGame, Match, LocalPlayer, HeadProvider, HeadTransform;
        public string PlayerClass, HeadStatus, HeadSource;
        public ulong HeadModel;
        public int HeadCacheEntries;
        public int Observations;
        public string HeadWorldStatus, HeadWorldError;
        public ulong UnityLoadBias, NativeHeadTransform;
        public uint HeadHierarchyCapacity;
        public int HeadParentCount, HeadWorldObservations, HeadSampleAttempts, HeadCaptureChunks;
        public float HeadWorldX, HeadWorldY, HeadWorldZ;
        public string RosterStatus,RosterError;
        public ulong RosterDictionary;
        public int RosterUsed,RosterRemoved,RosterActive,RosterNullValues,RosterCandidates,RosterOtherVerified,RosterObservations,RosterAttempts;
        public bool RosterLocalPresent,RosterComplete;
        public MatchPlayerObservation[] MatchPlayers=new MatchPlayerObservation[0];
        internal byte[] RosterCounterSnapshot;
        internal ulong RosterEntries,RosterCapacity,RosterClass,RosterArrayClass;
    }
    public sealed partial class Reader
    {
        private sealed class ObjectObservationChangedException : InvalidOperationException
        {
            internal readonly string Label;
            internal ObjectObservationChangedException(ulong address, byte[] before, byte[] after, bool final,string label)
                : base(ChangedDetail(address,before,after,final,label)) { Label=label; }
            private static string ChangedDetail(ulong address,byte[] before,byte[] after,bool final,string label)
            {
                int offset=0;while(offset<before.Length && before[offset]==after[offset])offset++;
                return "Object observation changed"+(final ? " on final recheck" : "")+" Address=0x"+address.ToString("x")+
                    " Bytes="+before.Length+" FirstChangedOffset="+offset+" Field="+label;
            }
        }
        private sealed class ObjectReads
        {
            private readonly Reader reader;
            private readonly ulong root;
            private readonly Dictionary<string, byte[]> values = new Dictionary<string, byte[]>();
            private readonly Dictionary<string, string> labels = new Dictionary<string, string>();
            private readonly List<ulong> addresses = new List<ulong>();
            private readonly List<byte[]> snapshots = new List<byte[]>();
            private int bytes;
            private readonly bool batchFinal;
            internal ObjectReads(Reader reader, ulong root, bool batchFinal=false)
            { this.reader = reader; this.root = root; this.batchFinal=batchFinal; }
            internal static void User(ulong value, int alignment, string label)
            {
                if (value < 0x10000 || value >= 0x0000800000000000UL || value % (ulong)alignment != 0)
                    throw new InvalidOperationException("Object pointer invalid: " + label + " Value=0x" + value.ToString("x"));
            }
            internal byte[] Read(ulong address, int length,string label=null)
            {
                User(address, 1, "read address");
                if (length < 1 || length > 4096 || checked(address + (ulong)length) > 0x0000800000000000UL)
                    throw new InvalidOperationException("Object read range invalid.");
                byte[] actual = reader.Virtual(root, address, length);
                string key = address.ToString("x") + ":" + length;
                byte[] previous;
                if (values.TryGetValue(key, out previous))
                { if(label!=null)labels[key]=label;
                  if (!EqualBytes(previous, actual)) throw new ObjectObservationChangedException(address,previous,actual,false,labels[key]); }
                else
                {
                    if (values.Count >= 1024 || bytes + length > 65536) throw new InvalidOperationException("Object observation bound exhausted.");
                    values.Add(key, actual); labels.Add(key,label??"UNLABELLED");addresses.Add(address); snapshots.Add(actual); bytes += length;
                }
                return actual;
            }
            internal ulong Value(ulong address,string label=null) { return BitConverter.ToUInt64(Read(address, 8,label), 0); }
            internal uint Word(ulong address,string label=null) { return BitConverter.ToUInt32(Read(address, 4,label), 0); }
            internal byte Byte(ulong address,string label=null) { return Read(address, 1,label)[0]; }
            internal ulong Pointer(ulong address, string label)
            {
                ulong pointer = Value(address,label);
                if (pointer == 0) throw new InvalidOperationException("Object not ready: " + label + " is null. Leave the spawned character in Training Ground.");
                User(pointer, 8, label); return pointer;
            }
            // Coalesce final transport requests only. Every originally observed byte
            // is still compared with its own snapshot; gap bytes are never evidence.
            // Merging stays within one page; an existing cross-page range stays
            // separate. Requests retain the existing maximum of 4096 bytes.
            private int RecheckBatched()
            {
                List<int> order=new List<int>();for(int i=0;i<addresses.Count;i++)order.Add(i);
                order.Sort(delegate(int a,int b){return addresses[a].CompareTo(addresses[b]);});
                int cursor=0;
                while(cursor<order.Count)
                {
                    int first=cursor;ulong start=addresses[order[cursor]],end=start+(ulong)snapshots[order[cursor]].Length;
                    cursor++;
                    while(cursor<order.Count)
                    {
                        int next=order[cursor];ulong at=addresses[next],finish=at+(ulong)snapshots[next].Length;
                        ulong combined=finish>end?finish:end;
                        if((start>>12)!=((combined-1)>>12) || combined-start>4096 || (at>end && at-end>64))break;
                        end=combined;cursor++;
                    }
                    byte[] actual=reader.Virtual(root,start,checked((int)(end-start)));
                    for(int j=first;j<cursor;j++)
                    {
                        int index=order[j],offset=checked((int)(addresses[index]-start));byte[] before=snapshots[index];
                        bool same=true;for(int k=0;k<before.Length;k++)if(before[k]!=actual[offset+k]){same=false;break;}
                        if(same)continue;
                        byte[] changed=new byte[before.Length];Array.Copy(actual,offset,changed,0,changed.Length);
                        string key=addresses[index].ToString("x")+":"+before.Length;
                        throw new ObjectObservationChangedException(addresses[index],before,changed,true,labels[key]);
                    }
                }
                return addresses.Count;
            }
            internal int Recheck() { return RecheckNativeHierarchy(0); }
            internal int RecheckNativeHierarchy(ulong hierarchy)
            {
                if(batchFinal && hierarchy==0)return RecheckBatched();
                ObjectObservationChangedException jobChange=null;
                for (int i=addresses.Count-1;i>=0;i--)
                {
                    byte[] actual=reader.Virtual(root,addresses[i],snapshots[i].Length);
                    if(EqualBytes(actual,snapshots[i]))continue;
                    string label=labels[addresses[i].ToString("x")+":"+snapshots[i].Length];
                    ObjectObservationChangedException error=new ObjectObservationChangedException(addresses[i],snapshots[i],actual,true,label);
                    bool job=hierarchy!=0 && ((addresses[i]==hierarchy && snapshots[i].Length==8 && label=="Hierarchy.JobHandle") ||
                        (addresses[i]==checked(hierarchy+8UL) && snapshots[i].Length==4 && label=="Hierarchy.JobTag"));
                    if(!job)throw error;
                    if(jobChange==null)jobChange=error;
                    // Do not accept a changed job or stop before checking other identities.
                }
                if(jobChange!=null)throw new NativeHeadJobChangedException(jobChange.Message);
                return addresses.Count;
            }
        }
        private static ObjectClassProfile ObjectProfile(int index)
        {
            foreach (ObjectClassProfile profile in ObjectReference.Classes) if (profile.Index == index) return profile;
            throw new InvalidOperationException("Object class is outside the supported exact-build profiles TypeIndex=" + index);
        }
        private static void Expect(bool matches, string label)
        { if (!matches) throw new InvalidOperationException("Object validation failed: " + label); }
        private ObjectClassProfile ReadObjectClass(ObjectReads reads, ulong klass, GameLayoutResult layout, Action<string> progress)
        {
            ObjectReads.User(klass, 8, "class");
            ulong type = reads.Value(klass + 0x68), table = checked(layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset);
            Expect(type >= table && type < table + 43624UL * 88UL && (type - table) % 88UL == 0, "class type-definition pointer");
            int index = checked((int)((type - table) / 88UL));
            if (progress != null) progress("ObjectClassObservation Address=0x" + klass.ToString("x") + " TypeIndex=" + index);
            ObjectClassProfile profile = ObjectProfile(index);
            Expect(EqualBytes(reads.Read(type, 88), Hex(profile.RecordHex)), "type record " + profile.Name);
            Expect(reads.Value(klass + 0x78) == klass, "class self " + profile.Name);
            Expect(reads.Value(klass + 0x20) == type && reads.Word(klass + 0x28) == profile.Bits, "class by-value type " + profile.Name);
            Expect(reads.Value(klass + 0x10) == checked(layout.RuntimeMetadataBase + profile.NameOffset) &&
                reads.Value(klass + 0x18) == checked(layout.RuntimeMetadataBase + profile.NamespaceOffset), "class name/namespace pointers " + profile.Name);
            uint token = reads.Word(klass + 0x11c), instanceSize = reads.Word(klass + 0xf8);
            bool sizeMatches = profile.InstanceSizeExact ? instanceSize == profile.InstanceSize :
                instanceSize >= profile.MinimumInstanceSize && instanceSize <= 1048576;
            if (!profile.InstanceSizeExact && progress != null)
                progress("ObjectClassSizeObservation Name=" + profile.Name + " Rule=BOUNDED_RUNTIME Minimum=" + profile.MinimumInstanceSize +
                    " ActualInstanceSize=" + instanceSize + " SourceInitialSize=0x" + profile.InstanceSize.ToString("x"));
            if ((token != profile.Token || !sizeMatches) && progress != null)
                progress("ObjectClassLayoutDifference Name=" + profile.Name + " TypeIndex=" + index +
                    " ExpectedToken=0x" + profile.Token.ToString("x") + " ActualToken=0x" + token.ToString("x") +
                    " ExpectedInstanceSize=" + (profile.InstanceSizeExact ? profile.InstanceSize.ToString() : "UNVERIFIED") + " ActualInstanceSize=" + instanceSize +
                    " SourceInitialStaticSize=0x" + profile.StaticSize.ToString("x") + " ActualStaticSize=" + reads.Word(klass + 0x10c) +
                    " GenericClass=0x" + reads.Value(klass + 0x60).ToString("x"));
            Expect(token == profile.Token, "class token " + profile.Name);
            Expect(sizeMatches, "class instance size " + profile.Name);
            return profile;
        }
        private ulong RootClass(ObjectReads reads, ModuleResult module, GameLayoutResult layout, ulong cell, int expected, Action<string> progress)
        {
            ulong klass = reads.Value(checked(module.LoadBias + cell));
            if ((klass & 1) != 0 || klass == 0)
                throw new InvalidOperationException("Object type usage is not resolved TypeIndex=" + expected + ". No initialization call was made.");
            Expect(ReadObjectClass(reads, klass, layout, progress).Index == expected, "root class identity");
            return klass;
        }
        private ObjectClassProfile ObjectFamily(ObjectReads reads, ulong instance, int family, int baseIndex, ulong expectedBase, GameLayoutResult layout, Action<string> progress)
        {
            ulong klass = reads.Pointer(instance, "object class");
            ObjectClassProfile actual = ReadObjectClass(reads, klass, layout, progress);
            Expect((actual.Family & family) != 0, "object family " + actual.Name);
            ObjectClassProfile current = actual;
            for (int depth = 0; depth < 16; depth++)
            {
                if (current.Index == baseIndex) { Expect(expectedBase == 0 || klass == expectedBase, "runtime base class matches resolved usage"); return actual; }
                klass = reads.Pointer(klass + 0x58, "parent class");
                ObjectClassProfile parent = ReadObjectClass(reads, klass, layout, progress);
                Expect(parent.Index == current.Parent, "runtime parent matches metadata"); current = parent;
            }
            throw new InvalidOperationException("Object class parent bound exhausted.");
        }
        private void VerifyWrapperField(ObjectReads reads, ulong hotfix, ModuleResult module, GameLayoutResult layout)
        {
            uint staticSize = reads.Word(hotfix + 0x10c);
            Expect(staticSize >= 8 && staticSize <= 65536, "IFix static storage extent");
            int fields = BitConverter.ToUInt16(reads.Read(hotfix + 0x124, 2), 0);
            Expect(fields == 4 && ObjectReference.WrapperFieldIndex < fields, "IFix field count");
            ulong table = reads.Pointer(hotfix + 0x80, "IFix runtime field table");
            ulong field = checked(table + (ulong)ObjectReference.WrapperFieldIndex * 32UL);
            Expect(EqualBytes(reads.Read(checked(layout.RuntimeMetadataBase + ObjectReference.WrapperMetadataOffset), 12),
                Hex(ObjectReference.WrapperFieldRecordHex)), "IFix wrapper field metadata");
            Expect(reads.Value(field) == checked(layout.RuntimeMetadataBase + ObjectReference.WrapperFieldNameOffset) &&
                reads.Value(field + 0x10) == hotfix && reads.Word(field + 0x1c) == ObjectReference.WrapperFieldToken,
                "IFix wrapper field identity");
            Expect(reads.Word(field + 0x18) == 0, "IFix wrapper static field offset");
            ulong type = checked(module.LoadBias + ObjectReference.WrapperTypeRva);
            Expect(reads.Value(field + 8) == type && reads.Word(type + 8) == ObjectReference.WrapperTypeBits,
                "IFix wrapper declared array type");
        }
        private static bool HotfixEntry(ObjectReads reads, ulong array, ulong length, int id)
        { return (ulong)id < length && reads.Value(checked(array + 0x20UL + (ulong)id * 8UL)) != 0; }
        private static void ObjectAnchors(Reader reader, GameProcess game, ModuleResult module)
        {
            foreach (GameLayoutCheck check in ObjectReference.Anchors)
                Expect(EqualBytes(reader.Virtual(game.Root, checked(module.LoadBias + check.Address), check.Expected(module.LoadBias).Length), check.Expected(module.LoadBias)), "object code anchor " + check.Name);
        }
        private void ResolveManagedPlayerHead(ObjectReads reads,GameProcess game,ModuleResult module,GameLayoutResult layout,
            PlayerObjectResult result,ObjectClassProfile player,ulong wrappers,ulong length,Action<string> progress)
        {
            result.HeadStatus = "NOT_READY_PROVIDER_NULL";
            result.HeadSource = "NONE";
            if (HotfixEntry(reads, wrappers, length, 0x34e)) result.HeadStatus = "HOTFIX_ACTIVE_HEAD_GETTER";
            else
            {
                result.HeadSource = "PLAYER_FIELD";
                result.HeadProvider = reads.Value(result.LocalPlayer + 0xa00);
                if (result.HeadProvider == 0)
                    result.HeadProvider = FindCachedHead(reads, game, module, layout, result, player, wrappers, length, progress);
                if (result.HeadProvider != 0)
                {
                    ObjectReads.User(result.HeadProvider, 8, "head provider");
                    ulong providerClass = reads.Pointer(result.HeadProvider, "head provider class");
                    ObjectClassProfile provider = ReadObjectClass(reads, providerClass, layout, progress);
                    Expect((provider.Family & 128) != 0 && provider.Getter != 0, "supported head provider");
                    ulong interfaceClass = RootClass(reads, module, layout, ObjectReference.HeadInterfaceCell, 36294, progress);
                    int count = BitConverter.ToUInt16(reads.Read(providerClass + 0x12e, 2), 0);
                    byte[] providerRecord = Hex(provider.RecordHex);
                    Expect(count > 0 && count <= 64 && count == BitConverter.ToUInt16(providerRecord, 0x4e), "provider interface count");
                    ulong interfaces = reads.Pointer(providerClass + 0xb0, "provider interface offsets");
                    int slot = -1;
                    for (int i = 0; i < count; i++)
                    {
                        byte[] item = reads.Read(checked(interfaces + (ulong)i * 16UL), 16);
                        if (BitConverter.ToUInt64(item, 0) == interfaceClass)
                        { Expect(slot == -1, "unique head interface"); slot = BitConverter.ToInt32(item, 8); }
                    }
                    int vtableCount = BitConverter.ToUInt16(reads.Read(providerClass + 0x12a, 2), 0);
                    Expect(vtableCount == BitConverter.ToUInt16(providerRecord, 0x4a) && vtableCount <= 4096 && slot >= 0 && slot < vtableCount,
                        "head interface vtable slot");
                    Expect(reads.Value(checked(providerClass + 0x138UL + (ulong)slot * 16UL)) == checked(module.LoadBias + provider.Getter), "head provider getter target");
                    result.HeadTransform = reads.Value(result.HeadProvider + 0x10);
                    result.HeadStatus = "NOT_READY_TRANSFORM_NULL";
                    if (result.HeadTransform != 0)
                    {
                        ObjectReads.User(result.HeadTransform, 8, "head Transform");
                        ObjectFamily(reads, result.HeadTransform, 64, ObjectReference.TransformIndex, 0, layout, progress);
                        result.HeadStatus = "MANAGED_TRANSFORM_VERIFIED";
                    }
                }
            }
        }
        public PlayerObjectResult VerifyPlayerObjects(KernelContext kernel, GameProcess game, ModuleResult module, GameLayoutResult layout, Action<string> progress)
        {
            if (module == null || layout == null || module.BuildId != ApkModule.BuildId || module.ReferenceFileSha256 != ApkModule.FileSha256 ||
                layout.MetadataSha256 != GameLayoutReference.MetadataSha256 || layout.TypeDescriptors != 9 || layout.Checks != 80)
                throw new ArgumentException("Matching verified module and runtime layout are required for object probing.");
            ObjectReads.User(module.LoadBias, 4096, "module base"); ObjectReads.User(layout.RuntimeMetadataBase, 4, "metadata base");
            Recheck(kernel, game); ObjectAnchors(this, game, module);
            ObjectReads reads = new ObjectReads(this, game.Root);
            ulong facade = RootClass(reads, module, layout, ObjectReference.FacadeCell, 12418, progress);
            ulong matchBase = RootClass(reads, module, layout, ObjectReference.MatchGameCell, 12425, progress);
            ulong hotfix = RootClass(reads, module, layout, ObjectReference.HotfixCell, 37332, progress);
            Expect(reads.Word(facade + 0xe0) != 0 && reads.Word(hotfix + 0xe0) != 0, "static class initialization complete");
            VerifyWrapperField(reads, hotfix, module, layout);
            ulong hotfixStatics = reads.Pointer(hotfix + 0xb8, "hotfix static storage");
            ulong wrappers = reads.Pointer(hotfixStatics, "hotfix wrapper array");
            reads.Pointer(wrappers, "wrapper array class");
            // The exact metadata declares wrapperArray as an IFix wrapper[].
            // Its length and element layout are taken from the verified dispatcher.
            ulong length = reads.Value(wrappers + 0x18);
            Expect(length <= 1000000, "hotfix array length bound");
            foreach (int id in new int[] { 0x1c6, 0x139, 0x1c5, 0x12b })
                if (HotfixEntry(reads, wrappers, length, id)) throw new InvalidOperationException("Object original path is overridden HOTFIX_ACTIVE Id=0x" + id.ToString("x"));
            ulong statics = reads.Pointer(facade + 0xb8, "GameFacade static storage");
            PlayerObjectResult result = new PlayerObjectResult();
            result.CurrentGame = reads.Pointer(statics, "CurrentGame");
            ObjectFamily(reads, result.CurrentGame, 4, 12425, matchBase, layout, progress);
            // The cast in CurrentLocalPlayer must name the same MatchGame class.
            Expect(reads.Value(matchBase + 0x68) == checked(layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + 12425UL * 88UL), "MatchGame root record");
            result.Match = reads.Pointer(result.CurrentGame + 0x90, "current match");
            ObjectFamily(reads, result.Match, 8, 32133, 0, layout, progress);
            result.LocalPlayer = reads.Pointer(result.Match + 0xd8, "local player");
            ObjectClassProfile player = ObjectFamily(reads, result.LocalPlayer, 16, 31824, 0, layout, progress);
            Expect(reads.Byte(result.LocalPlayer + 0x420) == 1, "local-player bool marker");
            result.PlayerClass = player.Name;
            ResolveManagedPlayerHead(reads,game,module,layout,result,player,wrappers,length,progress);
            try { ReadNativeHeadPosition(game, module, result, progress); }
            catch (NativeHeadJobChangedException error) { result.HeadWorldStatus = "NOT_READY_HIERARCHY_JOB_CHANGED"; result.HeadWorldError = error.Message; }
            catch (NativeHeadMotionException error) { result.HeadWorldStatus = "NOT_READY_MOTION"; result.HeadWorldError = error.Message; }
            catch (Exception error) { result.HeadWorldStatus = "FAIL"; result.HeadWorldError = error.Message; }
            try { ReadMatchPlayerDictionary(game,module,layout,result,wrappers,length,progress); }
            catch(Exception error) { result.RosterStatus="FAIL";result.RosterError=error.Message; }
            Recheck(kernel, game); ObjectAnchors(this, game, module);
            result.Observations = reads.Recheck(); Recheck(kernel, game);
            return result;
        }
    }
}
