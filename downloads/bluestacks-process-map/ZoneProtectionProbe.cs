using System;

namespace HeadBridge.Mapping
{
    internal sealed class ZonePool
    {
        internal readonly int Index,BaseIndex,DataIndex,InterfaceOffset;
        internal readonly ulong InterfaceMetadataOffset,ElementDescriptor;
        internal readonly string InterfaceHex;
        internal readonly TeamVirtual Dispatch;
        internal ZonePool(int index,int baseIndex,int dataIndex,int interfaceOffset,ulong interfaceMetadataOffset,string interfaceHex,TeamVirtual dispatch,ulong elementDescriptor)
        { Index=index;BaseIndex=baseIndex;DataIndex=dataIndex;InterfaceOffset=interfaceOffset;InterfaceMetadataOffset=interfaceMetadataOffset;InterfaceHex=interfaceHex;Dispatch=dispatch;ElementDescriptor=elementDescriptor; }
    }
    public sealed partial class Reader
    {
        private void ZoneCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            StateCode(kernel,game,module);
            foreach(GameLayoutCheck check in ZoneProtectionReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"zone code "+check.Name);
        }
        private static void ZoneSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            CombatSchema(reads,module,layout,ZoneProtectionReference.Methods,ZoneProtectionReference.Fields);
            foreach(ZonePool pool in ZoneProtectionReference.Pools)
            {
                StateField field=null;foreach(StateField f in ZoneProtectionReference.Fields)if(f.Owner==pool.BaseIndex && f.Local==0)field=f;
                Expect(field!=null && reads.Value(module.LoadBias+field.Descriptor)==module.LoadBias+pool.ElementDescriptor &&
                    reads.Value(module.LoadBias+pool.ElementDescriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)pool.DataIndex*88UL &&
                    reads.Word(module.LoadBias+pool.ElementDescriptor+8)==0x120000,"zone declared array element descriptor");
            }
        }
        private static ObjectClassProfile ZoneClass(ObjectReads reads,ulong klass,GameLayoutResult layout)
        { return CombatClass(reads,klass,layout,ZoneProtectionReference.Classes); }
        private static void ZoneFields(ObjectReads reads,ulong klass,int index,ModuleResult module,GameLayoutResult layout)
        { CombatFields(reads,klass,index,module,layout,ZoneProtectionReference.Fields); }
        private static ulong ZoneAncestor(ObjectReads reads,ulong klass,ObjectClassProfile p,int target,GameLayoutResult layout)
        {
            for(int depth=0;depth<12;depth++)
            {
                if(p.Index==target)return klass;
                int expected=p.Parent;klass=reads.Pointer(klass+0x58,"zone parent");p=ZoneClass(reads,klass,layout);
                Expect(p!=null && p.Index==expected,"zone class ancestry");
            }
            throw new InvalidOperationException("Zone ancestry bound exhausted.");
        }
        private static void ZoneValue(PlayerStateObservation sample,byte zone,ObjectReads reads,ulong wrappers,ulong length)
        {
            sample.TrainingZone=zone;sample.ZoneStatus="ORIGINAL_GETTER_SAMPLED";
            if(CombatGate(reads,wrappers,length,0x44d2))sample.InBattleZone=zone==2;
            if(CombatGate(reads,wrappers,length,0x3f0c))sample.InShootingRange=zone==3;
        }
        private void ReadTrainingZone(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,ulong baseClass,ulong wrappers,ulong length)
        {
            sample.ZoneStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x2558,0x2557,0x10a))return;
            if(sample.GameModeRaw==301){ZoneValue(sample,3,reads,wrappers,length);return;}
            ulong replication=reads.Pointer(baseClass+0x58,"zone Attackable parent");ObjectClassProfile rp=ZoneClass(reads,replication,layout);Expect(rp!=null && rp.Index==31911,"zone Attackable class");
            replication=reads.Pointer(replication+0x58,"zone COW replication parent");rp=ZoneClass(reads,replication,layout);Expect(rp!=null && rp.Index==31912,"zone COW replication class");
            replication=reads.Pointer(replication+0x58,"zone replication parent");rp=ZoneClass(reads,replication,layout);Expect(rp!=null && rp.Index==36302,"zone replication class");ZoneFields(reads,replication,36302,module,layout);
            ulong pool=reads.Value(sample.Player+0x70,"Zone.Pool");if(pool==0){ZoneValue(sample,0,reads,wrappers,length);return;}
            ObjectReads.User(pool,8,"zone pool");ulong klass=reads.Pointer(pool,"zone pool class");ObjectClassProfile p=ZoneClass(reads,klass,layout);
            sample.ZoneStatus="UNSUPPORTED_POOL_CLASS";if(p==null)return;sample.PoolClass=p.Name;
            ZonePool reference=null;foreach(ZonePool candidate in ZoneProtectionReference.Pools)if(candidate.Index==p.Index)reference=candidate;if(reference==null)return;
            ulong basePool=ZoneAncestor(reads,klass,p,reference.BaseIndex,layout);ZoneFields(reads,basePool,reference.BaseIndex,module,layout);
            ulong interfaceClass=reads.Pointer(module.LoadBias+ZoneProtectionReference.InterfaceCell,"zone interface root");ObjectClassProfile ip=ZoneClass(reads,interfaceClass,layout);Expect(ip!=null && ip.Index==36648,"zone interface identity");
            int count=BitConverter.ToUInt16(reads.Read(klass+0x12e,2),0);Expect(count>0 && count<=64 && count==BitConverter.ToUInt16(Hex(p.RecordHex),78),"zone interface count");
            ulong offsets=reads.Pointer(klass+0xb0,"zone interface offsets");int found=-1;
            for(int i=0;i<count;i++)
            { byte[] item=reads.Read(offsets+(ulong)i*16UL,16);if(BitConverter.ToUInt64(item,0)==interfaceClass){Expect(found<0,"zone unique interface");found=BitConverter.ToInt32(item,8);} }
            Expect(found==reference.InterfaceOffset && EqualBytes(reads.Read(layout.RuntimeMetadataBase+reference.InterfaceMetadataOffset,8),Hex(reference.InterfaceHex)),"zone interface offset metadata");
            TeamVirtual dispatch=reference.Dispatch;int slots=BitConverter.ToUInt16(reads.Read(klass+0x12a,2),0);
            Expect(slots==BitConverter.ToUInt16(Hex(p.RecordHex),74) && dispatch.Slot==found+11 && dispatch.Slot<slots &&
                reads.Word(layout.RuntimeMetadataBase+dispatch.MetadataOffset)==dispatch.Encoded && reads.Value(klass+0x138UL+(ulong)dispatch.Slot*16UL)==module.LoadBias+dispatch.Rva,"zone UInt8 interface dispatch");
            int maximum=unchecked((int)reads.Word(pool+0x18,"Zone.PoolMaximum"));if(maximum<=37){ZoneValue(sample,0,reads,wrappers,length);return;}
            Expect(maximum<=1000000,"zone pool maximum bound");ulong dataArray=reads.Value(pool+0x10,"Zone.Array");sample.ZoneStatus="NOT_READY_POOL_ARRAY_NULL";if(dataArray==0)return;
            ObjectReads.User(dataArray,8,"zone data array");ulong arrayClass=reads.Pointer(dataArray,"zone array class"),elementClass=reads.Pointer(arrayClass+0x40,"zone array element");ObjectClassProfile dp=ZoneClass(reads,elementClass,layout);
            ulong arraySelf=reads.Value(arrayClass+0x78,"Zone.ArraySelf"),arrayTypeData=reads.Value(arrayClass+0x20,"Zone.ArrayTypeData");
            uint arrayTypeBits=reads.Word(arrayClass+0x28,"Zone.ArrayTypeBits");
            bool elementMatches=dp!=null && dp.Index==reference.DataIndex,selfMatches=arraySelf==arrayClass,
                bitsMatch=arrayTypeBits==0x1d0000,dataMatches=arrayTypeData==module.LoadBias+reference.ElementDescriptor;
            if(!elementMatches || !selfMatches || !bitsMatch || !dataMatches)
            {
                ulong row=reads.Value(elementClass+0x68,"Zone.ElementTypeRow"),first=layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset;
                // ZoneClass already bounded and aligned this metadata row. These
                // failure observations do not authorize a typed array read.
                string diagnostic="zone array element type ZoneArrayDiagnostic Observation=UNVERIFIED_FAILURE_CONTEXT"+
                    " PoolTypeIndex="+p.Index+" DataArray=0x"+dataArray.ToString("x")+" ArrayClass=0x"+arrayClass.ToString("x")+
                    " ElementClass=0x"+elementClass.ToString("x")+" ExpectedElementTypeIndex="+reference.DataIndex+
                    " ActualElementTypeIndex="+((row-first)/88UL)+" ElementClassVerified="+(dp!=null)+
                    " ExpectedSelf=0x"+arrayClass.ToString("x")+" ActualSelf=0x"+arraySelf.ToString("x")+
                    " ExpectedBits=0x001d0000 ActualBits=0x"+arrayTypeBits.ToString("x8")+
                    " ExpectedTypeData=0x"+(module.LoadBias+reference.ElementDescriptor).ToString("x")+" ActualTypeData=0x"+arrayTypeData.ToString("x")+
                    " TypeDataEqualsElementClass="+(arrayTypeData==elementClass)+" TypeDataEqualsElementByvalArg="+(arrayTypeData==elementClass+0x20UL)+
                    " ElementMatch="+elementMatches+" SelfMatch="+selfMatches+" BitsMatch="+bitsMatch+" TypeDataMatch="+dataMatches;
                Expect(false,diagnostic);
            }
            ulong capacity=reads.Value(dataArray+0x18,"Zone.ArrayCapacity");Expect(capacity<=1000000,"zone array capacity bound");sample.ZoneStatus="NOT_READY_POOL_ARRAY_BOUNDS";if(capacity<=37)return;
            ulong data=reads.Value(dataArray+0x20+37*8,"Zone.Property37");if(data==0){ZoneValue(sample,0,reads,wrappers,length);return;}
            ObjectReads.User(data,8,"zone replication data");ulong dataClass=reads.Pointer(data,"zone data class");ObjectClassProfile actual=ZoneClass(reads,dataClass,layout);
            sample.ZoneStatus="UNSUPPORTED_DATA_CLASS";if(actual==null || actual.Index!=reference.DataIndex)return;ZoneFields(reads,dataClass,actual.Index,module,layout);
            byte value;
            if(reference.DataIndex==36653)
            {
                ulong at=reads.Value(data+0x18,"Zone.UnsafeValue");sample.ZoneStatus="NOT_READY_UNSAFE_VALUE_NULL";if(at==0)return;ObjectReads.User(at,1,"zone unsafe UInt8 value");value=reads.Byte(at,"Zone.Type");
            }
            else value=reads.Byte(data+0x18,"Zone.Type");
            ZoneValue(sample,value,reads,wrappers,length);
        }
        private static void ReadInvincibility(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,ulong baseClass,ulong wrappers,ulong length)
        {
            sample.ProtectionStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x49c2))return;
            ulong attributes=reads.Value(sample.Player+0x768,"Protection.Attributes");sample.ProtectionStatus="NOT_READY_ATTRIBUTES_NULL";if(attributes==0)return;
            ObjectReads.User(attributes,8,"zone player attributes");ulong klass=reads.Pointer(attributes,"zone attributes class");ObjectClassProfile p=ZoneClass(reads,klass,layout);
            sample.ProtectionStatus="UNSUPPORTED_ATTRIBUTES_CLASS";if(p==null || p.Index!=34539)return;ZoneFields(reads,klass,34539,module,layout);
            OtherContext(reads.Value(attributes+0x20,"Protection.Owner")==sample.Player,"zone attributes owner");
            ulong mask=reads.Value(attributes+0x2b0,"Protection.MaskObject");sample.ProtectionStatus="NOT_READY_INVINCIBILITY_OBJECT_NULL";if(mask==0)return;
            ObjectReads.User(mask,8,"zone invincibility mask");ulong maskClass=reads.Pointer(mask,"zone mask class");ObjectClassProfile mp=ZoneClass(reads,maskClass,layout);
            sample.ProtectionStatus="UNSUPPORTED_INVINCIBILITY_CLASS";if(mp==null || mp.Index!=36356)return;
            ulong parent=reads.Pointer(maskClass+0x58,"zone mask parent");ObjectClassProfile pp=ZoneClass(reads,parent,layout);Expect(pp!=null && pp.Index==36353,"zone BitArray parent");
            ZoneFields(reads,maskClass,36356,module,layout);ZoneFields(reads,parent,36353,module,layout);
            uint bits=reads.Word(mask+0x10,"Protection.Mask"),mode=reads.Word(mask+0x18,"Protection.Mode");sample.InvincibilityMask=bits;sample.InvincibilityMode=mode;
            sample.Invincible=mode==1?bits!=0:bits==uint.MaxValue;sample.ProtectionStatus="ORIGINAL_PREDICATE_SAMPLED";
        }
        private void ReadZoneProtection(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,PlayerStateObservation sample,ulong baseClass,ulong facade,ulong statics,ulong wrappers,ulong length)
        {
            ZoneFields(reads,baseClass,31824,module,layout);ZoneFields(reads,facade,12418,module,layout);
            sample.GameModeRaw=reads.Word(statics+0x114,"Zone.GameMode");sample.GameModeStatus=CombatGate(reads,wrappers,length,0x10a)?"ORIGINAL_GETTER_SAMPLED":"UNVERIFIED_HOTFIX_ACTIVE";
            ReadTrainingZone(reads,module,layout,sample,baseClass,wrappers,length);ReadInvincibility(reads,module,layout,sample,baseClass,wrappers,length);
        }
        public PlayerStateResult SampleZoneProtection(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,int rosterIndex,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,rosterIndex,true); }
    }
}
