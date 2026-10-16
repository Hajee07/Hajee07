using System;
namespace HeadBridge.Mapping
{
    public sealed partial class Reader
    {
        private void WeaponFiringCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            StateCode(kernel,game,module);
            foreach(GameLayoutCheck check in WeaponFiringReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"weapon firing code "+check.Name);
        }
        private static void WeaponFiringSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            foreach(StateMethod method in WeaponFiringReference.Methods)
                Expect(reads.Value(module.LoadBias+method.PointerRva)==module.LoadBias+method.Rva &&
                    EqualBytes(reads.Read(layout.RuntimeMetadataBase+method.MetadataOffset,40),Hex(method.RecordHex)),"firing method registration/metadata");
            foreach(StateField field in WeaponFiringReference.Fields)
            {
                uint offset=reads.Word(module.LoadBias+field.OffsetRva);
                bool opaque=(field.Owner==32785 && field.Local==17) || (field.Owner==32884 && (field.Local==1 || field.Local==2)) || (field.Owner==32859 && field.Local==0);
                Expect((offset==field.Offset || opaque && offset==WeaponContextReference.OpaqueDataRegistration) &&
                    EqualBytes(reads.Read(layout.RuntimeMetadataBase+field.MetadataOffset,12),Hex(field.RecordHex)),"firing field registration "+field.Name);
                Expect(reads.Word(module.LoadBias+field.Descriptor+8)==field.Bits,"firing field type flags "+field.Name);
                if(field.TypeIndex>=0)Expect(reads.Value(module.LoadBias+field.Descriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)field.TypeIndex*88UL,"firing resolved field type "+field.Name);
            }
        }
        private static bool FiringFields(ObjectReads reads,ulong klass,int index,ModuleResult module,GameLayoutResult layout)
        { return WeaponFields(reads,klass,index,module,layout,WeaponFiringReference.Fields); }
        private static void ReadSelectedWeaponFiring(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,
            ulong itemClass,ObjectClassProfile item,ulong weaponBase,ulong wrappers,ulong length)
        {
            sample.WeaponFiringStatus="UNSUPPORTED_SELECTED_WEAPON_FIRING_OVERRIDE";TeamVirtual target=null;
            foreach(TeamVirtual v in WeaponFiringReference.Virtuals)if(v.Index==item.Index)target=v;
            Expect(target!=null,"selected weapon firing profile");int slots=BitConverter.ToUInt16(reads.Read(itemClass+0x12a,2),0);
            Expect(slots>218 && slots==BitConverter.ToUInt16(Hex(item.RecordHex),74) &&
                reads.Word(layout.RuntimeMetadataBase+target.MetadataOffset)==target.Encoded &&
                reads.Value(itemClass+0x138UL+218UL*16UL)==module.LoadBias+target.Rva,"selected weapon firing virtual dispatch");
            if(target.Rva!=0x7481a84)return;
            sample.WeaponFiringStatus="UNVERIFIED_FIRING_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x4c1))return;
            sample.WeaponFiringStatus="NOT_READY_FIRING_WEAPON_FIELD_TABLE";if(!FiringFields(reads,weaponBase,32785,module,layout))return;
            ulong machine=reads.Value(sample.Weapon.Value+0x90,"Firing.StateMachine");
            if(machine==0){sample.WeaponFiring=false;sample.WeaponFiringRoute="NULL_MACHINE";sample.WeaponFiringStatus="ORIGINAL_NULL_MACHINE_FALSE";return;}
            ObjectReads.User(machine,8,"firing state machine");ulong machineClass=reads.Pointer(machine,"firing machine class");ObjectClassProfile mp=WeaponClass(reads,machineClass,layout);
            sample.WeaponFiringStatus="UNSUPPORTED_FIRING_MACHINE_CLASS";if(mp==null || mp.Index!=32884)return;
            ulong feature=reads.Pointer(module.LoadBias+TeamPolicyReference.GameVarCell,"firing feature class");TeamClass(reads,feature,11718,layout);
            sample.WeaponFiringStatus="NOT_READY_FIRING_FEATURE_INITIALIZATION";if(reads.Word(feature+0xe0)==0)return;
            Expect(reads.Word(feature+0x10c)>=0x191e && reads.Word(feature+0x10c)<=1048576,"firing static extent");
            sample.WeaponFiringStatus="NOT_READY_FIRING_FEATURE_FIELD_TABLE";if(!FiringFields(reads,feature,11718,module,layout))return;
            ulong statics=reads.Pointer(feature+0xb8,"firing feature statics");sample.WeaponFiringCacheEnabled=StateBoolean(reads,statics+0x191d,"Firing.CacheEnabled");
            sample.WeaponFiringStatus="NOT_READY_FIRING_MACHINE_FIELD_TABLE";if(!FiringFields(reads,machineClass,32884,module,layout))return;
            if(sample.WeaponFiringCacheEnabled.Value)
            {
                sample.WeaponFiring=StateBoolean(reads,machine+0x20,"Firing.CachedBoolean");sample.WeaponFiringRoute="CACHE_BOOLEAN";
            }
            else
            {
                sample.WeaponFiringStatus="UNVERIFIED_FIRING_STATE_GETTER_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x4b5))return;
                ulong state=reads.Value(machine+0x18,"Firing.CurrentState");sample.WeaponFiringStatus="NOT_READY_FIRING_CURRENT_STATE_NULL";if(state==0)return;
                ObjectReads.User(state,8,"firing current state");ulong stateClass=reads.Pointer(state,"firing state class");ObjectClassProfile sp=WeaponClass(reads,stateClass,layout);
                sample.WeaponFiringStatus="UNSUPPORTED_FIRING_STATE_CLASS";if(sp==null || (sp.Family&32)==0)return;
                ulong stateBase=WeaponAncestor(reads,stateClass,sp,32859,layout);
                sample.WeaponFiringStatus="NOT_READY_FIRING_STATE_FIELD_TABLE";if(!FiringFields(reads,stateBase,32859,module,layout))return;
                uint raw=reads.Word(state+0x10,"Firing.StateId"),delta=unchecked(raw-3U);sample.WeaponStateRaw=unchecked((int)raw);
                sample.WeaponFiring=(delta<13 && ((0x1f9fU>>(int)delta)&1U)!=0) || (raw&0xfffffffeU)==0x10;
                sample.WeaponFiringRoute="STATE_ID_SET";
            }
            sample.WeaponFiringStatus="ORIGINAL_SELECTED_WEAPON_FIRING_PREDICATE_SAMPLED";
        }
        public PlayerStateResult SampleWeaponFiring(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1,false,false,true); }
    }
}
