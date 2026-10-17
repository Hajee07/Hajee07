using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    internal sealed class StateField
    {
        internal readonly int Owner,Local,TypeIndex;
        internal readonly string Name,RecordHex;
        internal readonly ulong Offset,OffsetRva,Descriptor,NameOffset,MetadataOffset;
        internal readonly uint Bits,Token;
        internal StateField(int owner,int local,string name,ulong offset,ulong offsetRva,ulong descriptor,uint bits,int typeIndex,ulong nameOffset,uint token,ulong metadataOffset,string recordHex)
        { Owner=owner;Local=local;Name=name;Offset=offset;OffsetRva=offsetRva;Descriptor=descriptor;Bits=bits;TypeIndex=typeIndex;NameOffset=nameOffset;Token=token;MetadataOffset=metadataOffset;RecordHex=recordHex; }
    }
    internal sealed class StateMethod
    {
        internal readonly ulong MetadataOffset,PointerRva,Rva;
        internal readonly string RecordHex;
        internal StateMethod(ulong metadataOffset,ulong pointerRva,ulong rva,string recordHex)
        { MetadataOffset=metadataOffset;PointerRva=pointerRva;Rva=rva;RecordHex=recordHex; }
    }
    internal sealed class StateVisibility
    {
        internal readonly int Index;
        internal readonly ulong MetadataOffset,Rva;
        internal readonly uint Encoded;
        internal StateVisibility(int index,ulong metadataOffset,uint encoded,ulong rva)
        { Index=index;MetadataOffset=metadataOffset;Encoded=encoded;Rva=rva; }
    }
    public sealed class PlayerStateObservation
    {
        public int RosterIndex,Observations;
        public ulong Player;
        public bool IsLocal,CountersChangedSinceRoster,CountersChangedDuringCapture;
        public string Class,Status,Detail,MembershipProof,ReallyDeadStatus,ModelVisibilityStatus;
        public int? TeamIndex;
        public bool? BaseDeadRaw,PendingReviveRaw,ReallyDead,ModelVisible;
        public uint? VisibilityMask,VisibilityMode;
        public string WatchingStatus,WatchingGameClass,GhostStatus,DyingStatus,GameModeStatus,ControllerStateClass;
        public bool? IsWatching,IsInAnyGhost,IsDieing,DirectMovementSelector;
        public int? GhostKindRaw,MovementStateRaw,ControllerStateRaw;
        public uint? GameModeRaw;
        public string ZoneStatus,ProtectionStatus,PoolClass;
        public byte? TrainingZone;
        public bool? InBattleZone,InShootingRange,Invincible;
        public uint? InvincibilityMask,InvincibilityMode;
        public string WeaponStatus,WeaponSelectionPath,WeaponClass,WeaponDataClass,WeaponDataRegistration;
        public ulong? Weapon,WeaponData;
        public bool? AlternateHand;
        public uint? WeaponIdRaw;
        public string WeaponIdStatus;
        public string WeaponReloadStatus;
        public bool? WeaponReloading;
        public int? WeaponStateRaw;
        public string WeaponFiringStatus,WeaponFiringRoute;
        public bool? WeaponFiring,WeaponFiringCacheEnabled;
        public string WeaponAmmoStatus,WeaponAmmoFieldName,WeaponAmmoRegistration;
        public int? WeaponAmmoRaw,WeaponAmmoFieldIndex;
        public string AimRotationStatus; public float? AimX,AimY,AimZ,AimW; public double? AimNormSquared; public float? BasisX,BasisY,BasisZ; public ulong? CameraMainICall,ComponentTransformICall; public string CameraBindingStatus,CameraUnityCodeStatus; public ulong CameraUnityLoadBias,CameraCandidateObject,CameraCandidateOwner,CameraPredicateFunction,CameraPredicateRva; public string CameraCandidateStatus,CameraSelectionStatus; public byte? CameraPredicateRaw; public bool? CameraPredicateValue; public bool CameraSelectionComplete; public int CameraPredicatesEvaluated; public ulong SelectedNativeCamera,SelectedNativeCameraOwner; public string CameraPositionStatus; public ulong CameraNativeTransform; public float? CameraWorldX,CameraWorldY,CameraWorldZ; public int CameraParentCount; public string CameraRotationStatus,GameCameraGateStatus; public byte? GameCameraGetterInitRaw,GameCameraPatchInitRaw; public bool? GameCameraHotfixSlotPresent; public float? CameraQX,CameraQY,CameraQZ,CameraQW,CameraBasisX,CameraBasisY,CameraBasisZ; public double? CameraRotationNorm; public int CameraTagProbes,CameraNodesVisited;
    }
    public sealed class PlayerStateResult
    {
        public PlayerStateObservation[] Samples=new PlayerStateObservation[0];
        public int Sampled;
        public string StopReason,Detail;
    }
    public sealed partial class Reader
    {
        private void StateCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            OtherHeadCode(kernel,game,module);
            foreach(GameLayoutCheck check in PlayerStateReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"state code "+check.Name);
        }
        private static void StateSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            foreach(StateMethod method in PlayerStateReference.Methods)
            {
                Expect(reads.Value(module.LoadBias+method.PointerRva)==module.LoadBias+method.Rva,"state registered method target");
                Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+method.MetadataOffset,40),Hex(method.RecordHex)),"state method metadata");
            }
            foreach(StateField field in PlayerStateReference.Fields)
            {
                Expect(reads.Word(module.LoadBias+field.OffsetRva)==field.Offset,"state field offset "+field.Name);
                Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+field.MetadataOffset,12),Hex(field.RecordHex)),"state field metadata "+field.Name);
                ulong descriptor=module.LoadBias+field.Descriptor;
                Expect(reads.Word(descriptor+8)==field.Bits,"state field type flags "+field.Name);
                if(field.TypeIndex>=0)
                    Expect(reads.Value(descriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)field.TypeIndex*88UL,"state resolved field type "+field.Name);
            }
        }
        private static void StateClass(ObjectReads reads,ulong klass,int index,GameLayoutResult layout)
        {
            ObjectReads.User(klass,8,"state class");ObjectClassProfile profile=null;
            foreach(ObjectClassProfile p in PlayerStateReference.Classes)if(p.Index==index)profile=p;
            Expect(profile!=null,"state supported class");
            ulong row=layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)index*88UL;
            Expect(reads.Value(klass+0x68)==row && EqualBytes(reads.Read(row,88),Hex(profile.RecordHex)),"state class record "+profile.Name);
            Expect(reads.Value(klass+0x78)==klass && reads.Value(klass+0x20)==row && reads.Word(klass+0x28)==profile.Bits,"state class identity "+profile.Name);
            Expect(reads.Value(klass+0x10)==layout.RuntimeMetadataBase+profile.NameOffset && reads.Value(klass+0x18)==layout.RuntimeMetadataBase+profile.NamespaceOffset &&
                reads.Word(klass+0x11c)==profile.Token && reads.Word(klass+0xf8)==profile.InstanceSize,"state class layout "+profile.Name);
        }
        private static void StateRuntimeFields(ObjectReads reads,ulong klass,int index,ModuleResult module,GameLayoutResult layout)
        {
            byte[] record=reads.Read(layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)index*88UL,88);
            int count=BitConverter.ToUInt16(reads.Read(klass+0x124,2),0);
            Expect(count==BitConverter.ToUInt16(record,68),"state field count");
            ulong table=reads.Pointer(klass+0x80,"state runtime field table");
            foreach(StateField field in PlayerStateReference.Fields)
            {
                if(field.Owner!=index)continue;
                Expect(field.Local<count,"state field index");
                ulong at=table+(ulong)field.Local*32UL;
                byte[] info=reads.Read(at,32);
                Expect(BitConverter.ToUInt64(info,0)==layout.RuntimeMetadataBase+field.NameOffset && BitConverter.ToUInt64(info,8)==module.LoadBias+field.Descriptor &&
                    BitConverter.ToUInt64(info,16)==klass && BitConverter.ToUInt32(info,24)==field.Offset && BitConverter.ToUInt32(info,28)==field.Token,"state runtime field "+field.Name);
            }
        }
        private static bool StateBoolean(ObjectReads reads,ulong address,string label)
        { byte value=reads.Byte(address,label);Expect(value<=1,"canonical state Boolean "+label);return value!=0; }
        private PlayerStateObservation ReadPlayerState(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,
            PlayerObjectResult core,MatchPlayerObservation member,int index,bool combat=false,bool zone=false,bool weapon=false,bool firing=false,bool ammo=false,bool aimState=false)
        {
            ObjectReads reads=new ObjectReads(this,game.Root);
            PlayerStateObservation sample=new PlayerStateObservation { RosterIndex=index,Player=member.Address,Class=member.Class,IsLocal=member.IsLocal };
            ulong facade=RootClass(reads,module,layout,ObjectReference.FacadeCell,12418,null);
            ulong statics=reads.Pointer(facade+0xb8,"state facade statics");
            OtherContext(reads.Value(statics,"State.CurrentGame")==core.CurrentGame && reads.Value(core.CurrentGame+0x90,"State.Match")==core.Match &&
                reads.Value(core.Match+0xd8,"State.LocalPlayer")==core.LocalPlayer,"state current game/match/local");
            OtherContext(reads.Value(core.Match+0x128,"State.Dictionary")==core.RosterDictionary && reads.Value(core.RosterDictionary,"State.DictionaryClass")==core.RosterClass &&
                reads.Value(core.RosterDictionary+0x18,"State.Entries")==core.RosterEntries && reads.Value(core.RosterEntries,"State.ArrayClass")==core.RosterArrayClass &&
                reads.Value(core.RosterEntries+0x18,"State.Capacity")==core.RosterCapacity,"state selected collection identity");
            byte[] before=OtherCounterAudit(game,core,member,"STATE_BEFORE");
            OtherContext(member.EntrySnapshot!=null && member.EntrySnapshot.Length==40,"state selected entry snapshot length");
            byte[] entry=reads.Read(core.RosterEntries+0x20UL+(ulong)member.EntryIndex*40UL,40,"State.SelectedEntry");
            OtherContext(EqualBytes(entry,member.EntrySnapshot) && BitConverter.ToUInt64(entry,32)==member.Address,"state selected entry fingerprint");
            int next=BitConverter.ToInt32(entry,4);
            Expect(BitConverter.ToInt32(entry,0)>=0 && next>=-1 && next<BitConverter.ToUInt32(before,0),"state active entry/link");
            ObjectClassProfile profile=ObjectFamily(reads,member.Address,16,31824,0,layout,null);
            OtherContext(profile.Name==member.Class && (member.Address==core.LocalPlayer)==member.IsLocal &&
                reads.Byte(member.Address+0x420,"State.LocalMarker")== (member.IsLocal?1:0),"state member class/local role");
            ulong playerClass=reads.Pointer(member.Address,"state object class"),baseClass=playerClass;
            ObjectClassProfile current=profile;
            for(int depth=0;current.Index!=31824;depth++)
            { Expect(depth<16,"state base class bound");baseClass=reads.Pointer(baseClass+0x58,"state Player parent");current=ObjectProfile(current.Parent); }
            StateRuntimeFields(reads,baseClass,31824,module,layout);
            ulong attackable=reads.Pointer(baseClass+0x58,"state AttackableEntity parent");
            StateClass(reads,attackable,31911,layout);StateRuntimeFields(reads,attackable,31911,module,layout);
            ulong hotfix=RootClass(reads,module,layout,ObjectReference.HotfixCell,37332,null);VerifyWrapperField(reads,hotfix,module,layout);
            Expect(reads.Word(facade+0xe0)!=0 && reads.Word(hotfix+0xe0)!=0,"state static initialization complete");
            ulong wrappers=reads.Pointer(reads.Pointer(hotfix+0xb8,"state hotfix statics"),"state wrapper array");
            reads.Pointer(wrappers,"state wrapper array class");
            ulong length=reads.Value(wrappers+0x18);Expect(length<=1000000,"state wrapper array bound");
            foreach(int id in new int[]{0x1c6,0x139,0x1c5,0x12b,0x1bf})
                OtherContext(!HotfixEntry(reads,wrappers,length,id),"state original context hotfix 0x"+id.ToString("x"));
            sample.TeamIndex=unchecked((int)reads.Word(member.Address+0x430,"State.TeamIndex"));
            sample.BaseDeadRaw=StateBoolean(reads,member.Address+0x7c,"State.BaseDeadRaw");
            sample.PendingReviveRaw=StateBoolean(reads,member.Address+0xa6c,"State.PendingReviveRaw");
            bool reallyHotfix=HotfixEntry(reads,wrappers,length,0x4dd8),deadHotfix=HotfixEntry(reads,wrappers,length,0x447);
            sample.ReallyDeadStatus=reallyHotfix || deadHotfix ? "UNVERIFIED_HOTFIX_ACTIVE" : "ORIGINAL_BRANCH_SAMPLED";
            if(!reallyHotfix && !deadHotfix)sample.ReallyDead=sample.BaseDeadRaw.Value && !sample.PendingReviveRaw.Value;
            if(!combat && !zone && !weapon && !firing && !ammo && !aimState)
            {
            StateVisibility visibility=null;
            foreach(StateVisibility v in PlayerStateReference.Visibility)if(v.Index==profile.Index)visibility=v;
            Expect(visibility!=null,"state visibility class profile");
            int slots=BitConverter.ToUInt16(reads.Read(playerClass+0x12a,2),0);
            Expect(slots>70 && slots==BitConverter.ToUInt16(Hex(profile.RecordHex),74),"state visibility slot count");
            Expect(reads.Word(layout.RuntimeMetadataBase+visibility.MetadataOffset)==visibility.Encoded &&
                reads.Value(playerClass+0x138UL+70UL*16UL)==module.LoadBias+visibility.Rva,"state visibility dispatch target");
            sample.ModelVisibilityStatus="UNSUPPORTED_VISIBILITY_OVERRIDE";
            if(visibility.Encoded==0x60066ba1 && visibility.Rva==0x6f38834)
            {
                if(HotfixEntry(reads,wrappers,length,0x21bf3))sample.ModelVisibilityStatus="UNVERIFIED_HOTFIX_ACTIVE";
                else
                {
                    ulong maskObject=reads.Value(member.Address+0xad0,"State.VisibilityObject");
                    sample.ModelVisibilityStatus="NOT_READY_VISIBILITY_OBJECT_NULL";
                    if(maskObject!=0)
                    {
                        ObjectReads.User(maskObject,8,"state visibility object");
                        ulong maskClass=reads.Pointer(maskObject,"state visibility class");StateClass(reads,maskClass,36356,layout);
                        ulong parent=reads.Pointer(maskClass+0x58,"state BitArray parent");StateClass(reads,parent,36353,layout);
                        StateRuntimeFields(reads,maskClass,36356,module,layout);StateRuntimeFields(reads,parent,36353,module,layout);
                        uint mask=reads.Word(maskObject+0x10,"State.VisibilityMask"),mode=reads.Word(maskObject+0x18,"State.VisibilityMode");
                        sample.VisibilityMask=mask;sample.VisibilityMode=mode;sample.ModelVisible=mode==1 ? mask!=0 : mask==uint.MaxValue;
                        sample.ModelVisibilityStatus="ORIGINAL_BRANCH_SAMPLED";
                    }
                }
            }
            }
            else
            {
                sample.ModelVisibilityStatus=aimState?"NOT_REQUESTED_AIM_STATE_MODE":ammo?"NOT_REQUESTED_WEAPON_AMMO_MODE":firing?"NOT_REQUESTED_WEAPON_FIRING_MODE":weapon?"NOT_REQUESTED_WEAPON_MODE":zone?"NOT_REQUESTED_ZONE_MODE":"NOT_REQUESTED_COMBAT_MODE";
                if(aimState)ReadAimState(reads,module,layout,sample,baseClass,wrappers,length);
                else if(weapon || firing || ammo)ReadWeaponContext(reads,module,layout,sample,baseClass,wrappers,length,firing,ammo);
                else if(zone)ReadZoneProtection(reads,module,layout,core,sample,baseClass,facade,statics,wrappers,length);
                else ReadCombatState(reads,module,layout,core,sample,profile,playerClass,baseClass,facade,statics,wrappers,length);
            }
            byte[] after=OtherCounterAudit(game,core,member,"STATE_AFTER");
            Expect(next<BitConverter.ToUInt32(after,0),"state final entry link bound");
            sample.Observations=reads.Recheck();Recheck(kernel,game);
            sample.CountersChangedSinceRoster=!EqualBytes(before,core.RosterCounterSnapshot);
            sample.CountersChangedDuringCapture=!EqualBytes(before,after);
            sample.MembershipProof="SELECTED_ENTRY_REVALIDATED";sample.Status="SAMPLED_READ_ONLY";return sample;
        }
        public PlayerStateResult SamplePlayerStates(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        {
            return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1);
        }
        private PlayerStateResult SamplePlayerStatesCore(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress,bool combat,int rosterIndex,bool zone=false,bool weapon=false,bool firing=false,bool ammo=false,bool aimState=false)
        {
            PlayerStateResult result=new PlayerStateResult { StopReason="PREREQUISITES_UNVERIFIED" };
            if(core==null || module==null || layout==null || module.BuildId!=ApkModule.BuildId || module.ReferenceFileSha256!=ApkModule.FileSha256 ||
                layout.MetadataSha256!=GameLayoutReference.MetadataSha256 || core.RosterStatus!="TYPED_COLLECTION_VERIFIED" || core.RosterCounterSnapshot==null || core.RosterCounterSnapshot.Length!=16)return result;
            int allowance=Math.Min(6000,30000-PhysicalCalls);if(allowance<=1500){result.StopReason="READ_BUDGET_RESERVE";return result;}
            List<int> selected=new List<int>();
            if(weapon || firing || ammo || aimState)
            {
                for(int i=0;i<core.MatchPlayers.Length;i++)if(core.MatchPlayers[i].IsLocal){selected.Add(i);break;}
            }
            else if(combat || zone)
            {
                if(rosterIndex>=0)
                {
                    if(rosterIndex>=core.MatchPlayers.Length || core.MatchPlayers[rosterIndex].IsLocal){result.StopReason="SELECTED_MEMBER_NOT_NONLOCAL";return result;}
                    selected.Add(rosterIndex);
                }
                else for(int i=0;i<core.MatchPlayers.Length;i++)if(!core.MatchPlayers[i].IsLocal){selected.Add(i);break;}
            }
            else
            {
                for(int i=0;i<core.MatchPlayers.Length;i++)if(core.MatchPlayers[i].IsLocal){selected.Add(i);break;}
                for(int i=0;i<core.MatchPlayers.Length && selected.Count<2;i++)if(!core.MatchPlayers[i].IsLocal)selected.Add(i);
            }
            if(selected.Count==0){result.StopReason="NO_VERIFIED_OBJECTS";return result;}
            ObjectReads schema=new ObjectReads(this,game.Root);List<PlayerStateObservation> samples=new List<PlayerStateObservation>();
            result.StopReason="SELECTED_OBJECTS_EXHAUSTED";
            using(PhysicalCallScope(allowance))
            {
                try
                {
                    using(PhysicalCallScope(allowance-1500))
                    {
                        if(aimState)AimStateCode(kernel,game,module);else if(ammo)WeaponAmmoCode(kernel,game,module);else if(firing)WeaponFiringCode(kernel,game,module);else if(weapon)WeaponCode(kernel,game,module);else if(zone)ZoneCode(kernel,game,module);else if(combat)CombatCode(kernel,game,module);else StateCode(kernel,game,module);
                        OtherHeadSchema(schema,game,module,layout,core);StateSchema(schema,module,layout);
                        if(aimState)AimStateSchema(schema,module,layout);else if(ammo)WeaponAmmoSchema(schema,module,layout);else if(firing)WeaponFiringSchema(schema,module,layout);else if(weapon)WeaponSchema(schema,module,layout);else if(zone)ZoneSchema(schema,module,layout);else if(combat)CombatSchema(schema,module,layout);
                        foreach(int index in selected)
                        {
                            MatchPlayerObservation member=core.MatchPlayers[index];
                            if(progress!=null)progress((aimState?"AimStateCandidate Index=":ammo?"WeaponAmmoCandidate Index=":firing?"WeaponFiringCandidate Index=":weapon?"WeaponContextCandidate Index=":zone?"ZoneProtectionCandidate Index=":combat?"CombatStateCandidate Index=":"PlayerStateCandidate Index=")+index+" Class="+member.Class+" IsLocal="+member.IsLocal);
                            PlayerStateObservation sample;
                            try { sample=ReadPlayerState(kernel,game,module,layout,core,member,index,combat,zone,weapon,firing,ammo,aimState); }
                            catch(Exception error)
                            {
                                string status=error is PhysicalScopeLimitException ? "READ_LIMIT_REACHED" :
                                    error is OtherHeadContextException || error is ObjectObservationChangedException ? "NOT_READY_CONTEXT_CHANGED" : "FAIL";
                                sample=new PlayerStateObservation { RosterIndex=index,Player=member.Address,Class=member.Class,IsLocal=member.IsLocal,Status=status,Detail=error.Message };
                                samples.Add(sample);result.StopReason=status;break;
                            }
                            samples.Add(sample);
                        }
                    }
                }
                catch(Exception error){result.StopReason=error is PhysicalScopeLimitException?"READ_LIMIT_REACHED":"FAIL";result.Detail=error.Message;return result;}
                try { schema.Recheck();if(aimState)AimStateCode(kernel,game,module);else if(ammo)WeaponAmmoCode(kernel,game,module);else if(firing)WeaponFiringCode(kernel,game,module);else if(weapon)WeaponCode(kernel,game,module);else if(zone)ZoneCode(kernel,game,module);else if(combat)CombatCode(kernel,game,module);else StateCode(kernel,game,module); }
                catch(Exception error){result.StopReason="FINAL_CONTEXT_FAILED";result.Detail=error.Message;return result;}
                result.Samples=samples.ToArray();foreach(PlayerStateObservation sample in result.Samples)if(sample.Status=="SAMPLED_READ_ONLY")result.Sampled++;
                return result;
            }
        }
    }
}
