using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    public sealed class MatchPlayerObservation
    {
        public ulong Address; public string Class; public bool IsLocal;
        internal int EntryIndex;
        internal byte[] EntrySnapshot;
    }
    public sealed partial class Reader
    {
        private static ulong RosterGeneric(ObjectReads reads, ulong klass, ObjectClassProfile definition, int definitionKind, GameLayoutResult layout)
        {
            ulong table=checked(layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset);
            Expect(EqualBytes(reads.Read(table+(ulong)definition.Index*88UL,88),Hex(definition.RecordHex)),"roster generic metadata record");
            Expect(reads.Value(klass+0x78)==klass && reads.Word(klass+0x11c)==definition.Token &&
                reads.Value(klass+0x10)==layout.RuntimeMetadataBase+definition.NameOffset &&
                reads.Value(klass+0x18)==layout.RuntimeMetadataBase+definition.NamespaceOffset,"roster generic class identity "+definition.Name);
            ulong generic=reads.Pointer(klass+0x60,"roster generic class");
            Expect(reads.Value(klass+0x20)==generic && (reads.Word(klass+0x28)>>16&255)==0x15 &&
                reads.Value(generic+0x18)==klass && reads.Value(generic+0x10)==0,"roster closed generic context");
            ulong type=reads.Pointer(generic,"roster generic definition");
            Expect((reads.Word(type+8)>>16&255)==definitionKind && reads.Value(type)==table+(ulong)definition.Index*88UL,"roster generic definition type");
            ulong inst=reads.Pointer(generic+8,"roster generic arguments"); Expect(reads.Word(inst)==2,"roster generic arity");
            ulong args=reads.Pointer(inst+8,"roster generic argument table"),key=reads.Pointer(args,"roster key type"),value=reads.Pointer(args+8,"roster value type");
            Expect((reads.Word(key+8)>>16&255)==0x11 && reads.Value(key)==table+34565UL*88UL,"roster key must be BEADLMGGGGL");
            Expect((reads.Word(value+8)>>16&255)==0x12 && reads.Value(value)==table+31824UL*88UL,"roster value must be Player");
            Expect(EqualBytes(reads.Read(table+34565UL*88UL,88),Hex(RosterReference.Key.RecordHex)),"roster key type record");
            return generic;
        }
        private static void RosterArray(ObjectReads reads, ulong entries, GameLayoutResult layout)
        {
            ulong arrayClass=reads.Pointer(entries,"roster entry-array class");
            Expect(reads.Value(arrayClass+0x78)==arrayClass && (reads.Word(arrayClass+0x28)>>16&255)==0x1d,"roster entry array identity");
            ulong entryClass=reads.Pointer(arrayClass+0x40,"roster array element class");
            ulong generic=RosterGeneric(reads,entryClass,RosterReference.Entry,0x11,layout);
            ulong element=reads.Pointer(arrayClass+0x20,"roster array element descriptor");
            Expect((reads.Word(element+8)>>16&255)==0x15 && reads.Value(element)==generic,"roster array declared element type");
            Expect(reads.Word(entryClass+0xf8)==56,"roster entry runtime size must be boxed 16 plus stride 40");
        }
        private void ReadMatchPlayerDictionary(GameProcess game, ModuleResult module, GameLayoutResult layout, PlayerObjectResult result,
            ulong wrappers,ulong wrapperLength,Action<string> progress)
        {
            ObjectReads reads=new ObjectReads(this,game.Root);
            foreach(GameLayoutCheck anchor in RosterReference.Anchors)
                Expect(EqualBytes(reads.Read(module.LoadBias+anchor.Address,anchor.Expected(module.LoadBias).Length),anchor.Expected(module.LoadBias)),"roster code anchor "+anchor.Name);
            Expect(reads.Value(wrappers+0x18)==wrapperLength,"roster hotfix array length unchanged");
            if(HotfixEntry(reads,wrappers,wrapperLength,0x1bf))
            { result.RosterStatus="HOTFIX_ACTIVE_COLLECTION_GETTER";result.RosterObservations=reads.Recheck();return; }
            Expect(reads.Word(module.LoadBias+RosterReference.FieldOffsetRva)==0x128 &&
                reads.Word(module.LoadBias+RosterReference.FieldTypeRva+8)==0x150004 &&
                EqualBytes(reads.Read(layout.RuntimeMetadataBase+RosterReference.FieldMetadataOffset,12),Hex(RosterReference.FieldRecordHex)),"roster field registration");
            ulong dictionary=reads.Value(result.Match+0x128);result.RosterDictionary=dictionary;
            if(dictionary==0) { result.RosterStatus="NOT_READY_COLLECTION_NULL";result.RosterObservations=reads.Recheck();return; }
            ObjectReads.User(dictionary,8,"match player dictionary");
            ulong klass=reads.Pointer(dictionary,"match player dictionary class"),generic=RosterGeneric(reads,klass,RosterReference.Dictionary,0x12,layout);
            Expect(reads.Value(module.LoadBias+RosterReference.FieldTypeRva)==generic,"roster dictionary matches declared field type");
            uint size=reads.Word(klass+0xf8);Expect(size>=80 && size<=1048576,"roster dictionary storage size");
            byte[] counters=reads.Read(dictionary+0x20,16);
            uint used=BitConverter.ToUInt32(counters,0),free=BitConverter.ToUInt32(counters,8);
            Expect(used<=256 && free<=used,"roster dictionary used/free bound Used="+used+" Free="+free);
            if(used==0) { result.RosterStatus="EMPTY";result.RosterComplete=true;result.RosterObservations=reads.Recheck();return; }
            ulong entries=reads.Pointer(dictionary+0x18,"roster entries");RosterArray(reads,entries,layout);
            ulong capacity=reads.Value(entries+0x18);Expect(capacity>=used && capacity<=8192,"roster entry-array capacity");
            byte[] data=new byte[(int)used*40];
            for(int offset=0;offset<data.Length;offset+=4096)
            {
                int length=Math.Min(4096,data.Length-offset);byte[] part=reads.Read(entries+0x20UL+(ulong)offset,length);Array.Copy(part,0,data,offset,length);
            }
            List<ulong> candidates=new List<ulong>();HashSet<ulong> unique=new HashSet<ulong>();Dictionary<ulong,int> slots=new Dictionary<ulong,int>();int removed=0,active=0,nullValues=0;
            for(int i=0;i<used;i++)
            {
                int at=i*40;if(BitConverter.ToInt32(data,at)<0) { removed++;continue; }
                int next=BitConverter.ToInt32(data,at+4);Expect(next>=-1 && next<used,"roster entry link bound");active++;
                ulong pointer=BitConverter.ToUInt64(data,at+32);if(pointer==0) { nullValues++;continue; }
                ObjectReads.User(pointer,8,"roster Player candidate");if(unique.Add(pointer)){candidates.Add(pointer);slots.Add(pointer,i);}
            }
            Expect(removed==free,"roster removed count matches dictionary free count");
            bool localPresent=unique.Contains(result.LocalPlayer);
            if(localPresent) { candidates.Remove(result.LocalPlayer);candidates.Insert(0,result.LocalPlayer); }
            Dictionary<ulong,ObjectClassProfile> verifiedClasses=new Dictionary<ulong,ObjectClassProfile>();List<MatchPlayerObservation> verified=new List<MatchPlayerObservation>();
            for(int i=0;i<Math.Min(16,candidates.Count);i++)
            {
                ulong pointer=candidates[i],playerClass=reads.Pointer(pointer,"roster player class");ObjectClassProfile profile;
                if(!verifiedClasses.TryGetValue(playerClass,out profile))
                { profile=ObjectFamily(reads,pointer,16,31824,0,layout,progress);verifiedClasses.Add(playerClass,profile); }
                byte local=reads.Byte(pointer+0x420);Expect(local<=1 && (local==1)==(pointer==result.LocalPlayer),"roster local-player marker consistency");
                int entryIndex=slots[pointer];byte[] entrySnapshot=new byte[40];Array.Copy(data,entryIndex*40,entrySnapshot,0,40);
                verified.Add(new MatchPlayerObservation { Address=pointer,Class=profile.Name,IsLocal=local==1,EntryIndex=entryIndex,EntrySnapshot=entrySnapshot });
            }
            ulong arrayClass=reads.Value(entries);
            int observations=reads.Recheck();
            result.RosterCounterSnapshot=(byte[])counters.Clone();result.RosterEntries=entries;result.RosterCapacity=capacity;
            result.RosterClass=klass;result.RosterArrayClass=arrayClass;
            result.RosterUsed=(int)used;result.RosterRemoved=removed;result.RosterActive=active;result.RosterNullValues=nullValues;
            result.RosterCandidates=candidates.Count;result.RosterLocalPresent=localPresent;
            result.MatchPlayers=verified.ToArray();result.RosterOtherVerified=verified.Count-(localPresent?1:0);
            result.RosterComplete=verified.Count==candidates.Count;result.RosterObservations=observations;result.RosterStatus="TYPED_COLLECTION_VERIFIED";
        }
    }
}
