using System;
namespace HeadBridge.Mapping
{
    public sealed partial class Reader
    {
        private void WeaponAmmoCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            StateCode(kernel,game,module);
            foreach(GameLayoutCheck c in WeaponAmmoReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+c.Address,c.Expected(module.LoadBias).Length),c.Expected(module.LoadBias)),"weapon ammo code "+c.Name);
        }
        private static void WeaponAmmoSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            foreach(StateMethod m in WeaponAmmoReference.Methods)
                Expect(reads.Value(module.LoadBias+m.PointerRva)==module.LoadBias+m.Rva && EqualBytes(reads.Read(layout.RuntimeMetadataBase+m.MetadataOffset,40),Hex(m.RecordHex)),"ammo method registration/metadata");
            CombatSchema(reads,module,layout,new StateMethod[0],WeaponAmmoReference.SelectionFields);
        }
        private static void ReadSelectedWeaponAmmo(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,ulong weaponBase,ulong wrappers,ulong length)
        {
            sample.WeaponAmmoStatus="UNVERIFIED_AMMO_GETTER_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x328))return;
            byte[] record=reads.Read(layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+32785UL*88UL,88);
            int count=BitConverter.ToUInt16(reads.Read(weaponBase+0x124,2),0);
            Expect(count==WeaponAmmoReference.FieldCount && count==BitConverter.ToUInt16(record,68),"ammo exact field-table count");
            ulong table=reads.Value(weaponBase+0x80,"Ammo.FieldTable");sample.WeaponAmmoStatus="NOT_READY_AMMO_FIELD_TABLE";if(table==0)return;
            ObjectReads.User(table,8,"ammo field table");byte[] rows=new byte[count*32];
            for(int off=0;off<rows.Length;off+=4096)
            { byte[] chunk=reads.Read(table+(ulong)off,Math.Min(4096,rows.Length-off),"Ammo.FieldTableChunk");Array.Copy(chunk,0,rows,off,chunk.Length); }
            int found=-1;
            for(int i=0;i<count;i++)if(BitConverter.ToUInt32(rows,i*32+24)==WeaponAmmoReference.GetterOffset)
            { Expect(found<0,"ammo unique field offset");found=i; }
            sample.WeaponAmmoStatus="NOT_READY_AMMO_OFFSET_UNRESOLVED";if(found<0)return;
            WeaponAmmoField field=null;foreach(WeaponAmmoField c in WeaponAmmoReference.Candidates)if(c.Local==found)field=c;
            sample.WeaponAmmoStatus="UNSUPPORTED_AMMO_FIELD_TYPE";if(field==null)return;
            uint registration=reads.Word(module.LoadBias+field.OffsetRva,"Ammo.OffsetRegistration");
            Expect((registration==WeaponContextReference.OpaqueDataRegistration || registration==WeaponAmmoReference.GetterOffset) &&
                EqualBytes(reads.Read(layout.RuntimeMetadataBase+field.MetadataOffset,12),Hex(field.RecordHex)),"ammo chosen field registration/metadata");
            Expect(reads.Word(module.LoadBias+field.Descriptor+8)==field.Bits && ((field.Bits>>16)&255)==8 && (field.Bits&16)==0,"ammo chosen field Int32 type");
            int at=found*32;Expect(BitConverter.ToUInt64(rows,at)==layout.RuntimeMetadataBase+field.NameOffset &&
                BitConverter.ToUInt64(rows,at+8)==module.LoadBias+field.Descriptor && BitConverter.ToUInt64(rows,at+16)==weaponBase &&
                BitConverter.ToUInt32(rows,at+28)==field.Token,"ammo chosen runtime FieldInfo identity");
            sample.WeaponAmmoFieldIndex=found;sample.WeaponAmmoFieldName=field.Name;
            sample.WeaponAmmoRegistration=registration==WeaponAmmoReference.GetterOffset?"RESOLVED_OFFSET":"OPAQUE_SOURCE_RUNTIME_FIELD_VERIFIED";
            sample.WeaponAmmoRaw=unchecked((int)reads.Word(sample.Weapon.Value+WeaponAmmoReference.GetterOffset,"Ammo.OriginalCounter"));
            sample.WeaponAmmoStatus="ORIGINAL_SELECTED_WEAPON_INT32_COUNTER_SAMPLED";
        }
        public PlayerStateResult SampleWeaponAmmo(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1,false,false,false,true); }
    }
}
