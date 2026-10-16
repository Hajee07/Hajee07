using System;

namespace HeadBridge.Mapping
{
    public sealed partial class Reader
    {
        private void WeaponCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            StateCode(kernel,game,module);
            foreach(GameLayoutCheck check in WeaponContextReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"weapon code "+check.Name);
        }
        private static void WeaponSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            foreach(StateMethod method in WeaponContextReference.Methods)
            {
                Expect(reads.Value(module.LoadBias+method.PointerRva)==module.LoadBias+method.Rva &&
                    EqualBytes(reads.Read(layout.RuntimeMetadataBase+method.MetadataOffset,40),Hex(method.RecordHex)),"weapon method registration/metadata");
            }
            foreach(StateField field in WeaponContextReference.Fields)
            {
                uint offset=reads.Word(module.LoadBias+field.OffsetRva);
                bool offsetMatches=offset==field.Offset || ((field.Owner==32785 && (field.Local==17 || field.Local==18)) || (field.Owner==32884 && field.Local==1) || (field.Owner==32859 && field.Local==0)) && offset==WeaponContextReference.OpaqueDataRegistration;
                Expect(offsetMatches && EqualBytes(reads.Read(layout.RuntimeMetadataBase+field.MetadataOffset,12),Hex(field.RecordHex)),"weapon field registration "+field.Name);
                Expect(reads.Word(module.LoadBias+field.Descriptor+8)==field.Bits,"weapon field type flags "+field.Name);
                if(field.TypeIndex>=0)Expect(reads.Value(module.LoadBias+field.Descriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)field.TypeIndex*88UL,"weapon resolved field type "+field.Name);
            }
        }
        private static ObjectClassProfile WeaponClass(ObjectReads reads,ulong klass,GameLayoutResult layout)
        { return CombatClass(reads,klass,layout,WeaponContextReference.Classes); }
        private static bool WeaponFields(ObjectReads reads,ulong klass,int index,ModuleResult module,GameLayoutResult layout,StateField[] fields=null)
        {
            ulong table=reads.Value(klass+0x80,"Weapon.FieldTable");if(table==0)return false;
            CombatFields(reads,klass,index,module,layout,fields??WeaponContextReference.Fields);return true;
        }
        private static ulong WeaponAncestor(ObjectReads reads,ulong klass,ObjectClassProfile p,int target,GameLayoutResult layout)
        {
            for(int depth=0;depth<24;depth++)
            {
                if(p.Index==target)return klass;
                if(p.Index==32463 || p.Index==31595)break;
                int expected=p.Parent;klass=reads.Pointer(klass+0x58,"weapon parent");p=WeaponClass(reads,klass,layout);
                Expect(p!=null && p.Index==expected,"weapon class ancestry");
            }
            throw new InvalidOperationException("Weapon field type is not assignable to the verified declared class.");
        }
        private static void WeaponNone(PlayerStateObservation sample,string path)
        { sample.Weapon=0;sample.WeaponData=0;sample.WeaponSelectionPath=path;sample.WeaponStatus="ORIGINAL_NO_ACTIVE_WEAPON"; }
        private static void ReadWeaponContext(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,ulong playerBase,ulong wrappers,ulong length,bool firing=false)
        {
            Expect(sample.IsLocal,"weapon context selects local player only");sample.WeaponStatus="UNVERIFIED_HOTFIX_ACTIVE";sample.WeaponIdStatus="NOT_REQUESTED_UNVERIFIED_DATA";sample.WeaponReloadStatus="NOT_REQUESTED_UNVERIFIED_WEAPON";sample.WeaponFiringStatus="NOT_REQUESTED_UNVERIFIED_WEAPON";
            StateField[] selectedFields=firing?WeaponFiringReference.Fields:null;
            if(!CombatGate(reads,wrappers,length,0x347,0x345))return;
            sample.WeaponStatus="NOT_READY_PLAYER_FIELD_TABLE";if(!WeaponFields(reads,playerBase,31824,module,layout,selectedFields))return;
            ulong candidate=reads.Value(sample.Player+0x608,"Weapon.ActiveField");bool handCast=false;int declared=32623;
            sample.WeaponSelectionPath="ACTIVE_PLAYER_FIELD";
            if(candidate==0)
            {
                sample.WeaponStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x346))return;
                ulong controller=reads.Value(sample.Player+0x740,"Weapon.Controller");
                if(controller==0){WeaponNone(sample,"NULL_HAND_CONTROLLER");return;}
                ObjectReads.User(controller,8,"weapon controller");ulong controllerClass=reads.Pointer(controller,"weapon controller class");ObjectClassProfile cp=WeaponClass(reads,controllerClass,layout);
                sample.WeaponStatus="UNSUPPORTED_HAND_CONTROLLER_CLASS";if(cp==null || cp.Index!=32430)return;
                sample.WeaponStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x286,0x285))return;
                sample.WeaponStatus="NOT_READY_CONTROLLER_FIELD_TABLE";if(!WeaponFields(reads,controllerClass,32430,module,layout,selectedFields))return;
                bool alternate=StateBoolean(reads,controller+0x148,"Weapon.AlternateHand");sample.AlternateHand=alternate;
                candidate=reads.Value(controller+(alternate?0xa8UL:0xa0UL),"Weapon.SelectedHandItem");declared=alternate?32613:32463;handCast=true;
                sample.WeaponSelectionPath=alternate?"ON_HAND_CONTROLLER_A8":"ON_HAND_CONTROLLER_A0";
                if(candidate==0){WeaponNone(sample,sample.WeaponSelectionPath+"_NULL");return;}
            }
            ObjectReads.User(candidate,8,"weapon selected item");ulong itemClass=reads.Pointer(candidate,"weapon item class");ObjectClassProfile item=WeaponClass(reads,itemClass,layout);
            sample.WeaponStatus="UNSUPPORTED_SELECTED_ITEM_CLASS";if(item==null || (item.Family&1)==0)return;
            WeaponAncestor(reads,itemClass,item,declared,layout);
            if(handCast)
            {
                ulong target=reads.Pointer(module.LoadBias+WeaponContextReference.WeaponTypeCell,"weapon cast root");ObjectClassProfile targetProfile=WeaponClass(reads,target,layout);
                Expect(targetProfile!=null && targetProfile.Index==32785,"weapon cast root identity");TeamRuntimeCast(reads,itemClass,target,(item.Family&2)!=0);
                if((item.Family&2)==0){WeaponNone(sample,"ON_HAND_NON_WEAPON_CAST");return;}
            }
            Expect((item.Family&2)!=0,"selected weapon family");ulong weaponBase=WeaponAncestor(reads,itemClass,item,32785,layout);
            sample.Weapon=candidate;sample.WeaponClass=item.Name;
            if(firing){sample.WeaponStatus="ORIGINAL_SELECTED_WEAPON_VERIFIED";ReadSelectedWeaponFiring(reads,module,layout,sample,itemClass,item,weaponBase,wrappers,length);return;}
            ReadSelectedWeaponReload(reads,module,layout,sample,itemClass,item,weaponBase,wrappers,length);sample.WeaponStatus="UNSUPPORTED_WEAPON_DATA_OVERRIDE";
            TeamVirtual dispatch=null;foreach(TeamVirtual v in WeaponContextReference.Virtuals)if(v.Index==item.Index)dispatch=v;
            Expect(dispatch!=null,"weapon data dispatch profile");int slots=BitConverter.ToUInt16(reads.Read(itemClass+0x12a,2),0);
            Expect(slots>45 && slots==BitConverter.ToUInt16(Hex(item.RecordHex),74) && reads.Word(layout.RuntimeMetadataBase+dispatch.MetadataOffset)==dispatch.Encoded &&
                reads.Value(itemClass+0x138UL+45UL*16UL)==module.LoadBias+dispatch.Rva,"weapon data virtual dispatch");
            if(dispatch.Rva!=0x7452a90)return;
            sample.WeaponStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x267b))return;
            sample.WeaponStatus="NOT_READY_WEAPON_FIELD_TABLE";if(!WeaponFields(reads,weaponBase,32785,module,layout))return;
            StateField dataField=null;foreach(StateField f in WeaponContextReference.Fields)if(f.Owner==32785 && f.Local==18)dataField=f;
            Expect(dataField!=null && dataField.Offset==0x98,"weapon data getter offset reference");uint registration=reads.Word(module.LoadBias+dataField.OffsetRva,"Weapon.DataRegistration");
            Expect(registration==dataField.Offset || registration==WeaponContextReference.OpaqueDataRegistration,"weapon data registration state");
            sample.WeaponDataRegistration=registration==dataField.Offset?"RESOLVED_OFFSET":"OPAQUE_FILE_VALUE_RUNTIME_FIELD_VERIFIED";
            ulong data=reads.Value(candidate+dataField.Offset,"Weapon.Data");sample.WeaponData=data;sample.WeaponStatus="NOT_READY_WEAPON_DATA_NULL";if(data==0)return;
            ObjectReads.User(data,8,"weapon data object");ulong dataClass=reads.Pointer(data,"weapon data class");ObjectClassProfile dp=WeaponClass(reads,dataClass,layout);
            sample.WeaponStatus="UNSUPPORTED_WEAPON_DATA_CLASS";if(dp==null || (dp.Family&4)==0){sample.WeaponData=null;return;}
            WeaponAncestor(reads,dataClass,dp,31595,layout);sample.WeaponDataClass=dp.Name;sample.WeaponStatus="ORIGINAL_WEAPON_DATA_REFERENCE_SAMPLED";
            sample.WeaponIdStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x21a65))return;
            TeamVirtual id=WeaponContextReference.IdVirtual;int dataSlots=BitConverter.ToUInt16(reads.Read(dataClass+0x12a,2),0);
            Expect(dp.Index==id.Index && dataSlots>id.Slot && dataSlots==BitConverter.ToUInt16(Hex(dp.RecordHex),74) &&
                reads.Word(layout.RuntimeMetadataBase+id.MetadataOffset)==id.Encoded &&
                reads.Value(dataClass+0x138UL+(ulong)id.Slot*16UL)==module.LoadBias+id.Rva,"weapon ID virtual dispatch");
            sample.WeaponIdStatus="NOT_READY_DATA_FIELD_TABLE";if(!WeaponFields(reads,dataClass,31595,module,layout))return;
            sample.WeaponIdRaw=reads.Word(data+0x68,"Weapon.DataId");sample.WeaponIdStatus="ORIGINAL_GET_ID_UINT32_SAMPLED";
        }
        private static void ReadSelectedWeaponReload(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,
            ulong itemClass,ObjectClassProfile item,ulong weaponBase,ulong wrappers,ulong length)
        {
            sample.WeaponReloadStatus="UNSUPPORTED_SELECTED_WEAPON_RELOAD_OVERRIDE";TeamVirtual target=null;
            foreach(TeamVirtual v in WeaponContextReference.ReloadVirtuals)if(v.Index==item.Index)target=v;
            Expect(target!=null,"selected weapon reload dispatch profile");int slots=BitConverter.ToUInt16(reads.Read(itemClass+0x12a,2),0);
            Expect(slots>216 && slots==BitConverter.ToUInt16(Hex(item.RecordHex),74) &&
                reads.Word(layout.RuntimeMetadataBase+target.MetadataOffset)==target.Encoded &&
                reads.Value(itemClass+0x138UL+216UL*16UL)==module.LoadBias+target.Rva,"selected weapon reload virtual dispatch");
            if(target.Rva!=0x74819c4)return;
            sample.WeaponReloadStatus="UNVERIFIED_RELOAD_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x4c7))return;
            sample.WeaponReloadStatus="NOT_READY_RELOAD_WEAPON_FIELD_TABLE";if(!WeaponFields(reads,weaponBase,32785,module,layout))return;
            ulong machine=reads.Value(sample.Weapon.Value+0x90,"Weapon.StateMachine");
            if(machine==0){sample.WeaponReloading=false;sample.WeaponReloadStatus="ORIGINAL_NULL_MACHINE_FALSE";return;}
            ObjectReads.User(machine,8,"weapon state machine");ulong machineClass=reads.Pointer(machine,"weapon state machine class");ObjectClassProfile mp=WeaponClass(reads,machineClass,layout);
            sample.WeaponReloadStatus="UNSUPPORTED_RELOAD_MACHINE_CLASS";if(mp==null || mp.Index!=32884)return;
            sample.WeaponReloadStatus="UNVERIFIED_STATE_GETTER_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x4b5))return;
            sample.WeaponReloadStatus="NOT_READY_RELOAD_MACHINE_FIELD_TABLE";if(!WeaponFields(reads,machineClass,32884,module,layout))return;
            ulong state=reads.Value(machine+0x18,"Weapon.CurrentState");sample.WeaponReloadStatus="NOT_READY_CURRENT_STATE_NULL";if(state==0)return;
            ObjectReads.User(state,8,"weapon current state");ulong stateClass=reads.Pointer(state,"weapon current state class");ObjectClassProfile sp=WeaponClass(reads,stateClass,layout);
            sample.WeaponReloadStatus="UNSUPPORTED_RELOAD_STATE_CLASS";if(sp==null || (sp.Family&32)==0)return;
            ulong stateBase=WeaponAncestor(reads,stateClass,sp,32859,layout);
            sample.WeaponReloadStatus="NOT_READY_RELOAD_STATE_FIELD_TABLE";if(!WeaponFields(reads,stateBase,32859,module,layout))return;
            sample.WeaponStateRaw=unchecked((int)reads.Word(state+0x10,"Weapon.StateId"));
            sample.WeaponReloading=sample.WeaponStateRaw.Value==8;sample.WeaponReloadStatus="ORIGINAL_SELECTED_WEAPON_RELOAD_PREDICATE_SAMPLED";
        }
        public PlayerStateResult SampleWeaponContext(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1,false,true); }
    }
}
