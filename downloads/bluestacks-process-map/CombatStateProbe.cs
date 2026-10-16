using System;

namespace HeadBridge.Mapping
{
    internal sealed class CombatMovement
    {
        internal readonly ulong Rva;
        internal readonly int Gate,Value;
        internal readonly StateMethod Method;
        internal readonly string CodeHex;
        internal CombatMovement(ulong rva,int gate,int value,StateMethod method,string codeHex) { Rva=rva;Gate=gate;Value=value;Method=method;CodeHex=codeHex; }
    }
    public sealed partial class Reader
    {
        private void CombatCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            StateCode(kernel,game,module);
            foreach(GameLayoutCheck check in CombatStateReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"combat code "+check.Name);
        }
        private static void CombatSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout,StateMethod[] methods=null,StateField[] fields=null)
        {
            foreach(StateMethod method in methods??CombatStateReference.Methods)
            {
                Expect(reads.Value(module.LoadBias+method.PointerRva)==module.LoadBias+method.Rva,"combat registered method");
                Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+method.MetadataOffset,40),Hex(method.RecordHex)),"combat method metadata");
            }
            foreach(StateField field in fields??CombatStateReference.Fields)
            {
                Expect(reads.Word(module.LoadBias+field.OffsetRva)==field.Offset &&
                    EqualBytes(reads.Read(layout.RuntimeMetadataBase+field.MetadataOffset,12),Hex(field.RecordHex)),"combat field registration "+field.Name);
                Expect(reads.Word(module.LoadBias+field.Descriptor+8)==field.Bits,"combat field type flags "+field.Name);
                if(field.TypeIndex>=0)Expect(reads.Value(module.LoadBias+field.Descriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)field.TypeIndex*88UL,"combat resolved field type "+field.Name);
            }
        }
        private static ObjectClassProfile CombatProfile(int index,ObjectClassProfile[] profiles=null)
        { foreach(ObjectClassProfile p in profiles??CombatStateReference.Classes)if(p.Index==index)return p;return null; }
        private static ObjectClassProfile CombatClass(ObjectReads reads,ulong klass,GameLayoutResult layout,ObjectClassProfile[] profiles=null)
        {
            ObjectReads.User(klass,8,"combat class");ulong row=reads.Value(klass+0x68),first=layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset;
            Expect(row>=first && (row-first)%88UL==0 && (row-first)/88UL<100000,"combat type row bound");
            ObjectClassProfile p=CombatProfile((int)((row-first)/88UL),profiles);if(p==null)return null;
            Expect(EqualBytes(reads.Read(row,88),Hex(p.RecordHex)),"combat class record "+p.Name);
            Expect(reads.Value(klass+0x78)==klass && reads.Value(klass+0x20)==row && reads.Word(klass+0x28)==p.Bits,"combat class identity "+p.Name);
            Expect(reads.Value(klass+0x10)==layout.RuntimeMetadataBase+p.NameOffset && reads.Value(klass+0x18)==layout.RuntimeMetadataBase+p.NamespaceOffset &&
                reads.Word(klass+0x11c)==p.Token && reads.Word(klass+0xf8)==p.InstanceSize,"combat class layout "+p.Name);
            return p;
        }
        private static void CombatFields(ObjectReads reads,ulong klass,int index,ModuleResult module,GameLayoutResult layout,StateField[] fields=null)
        {
            byte[] row=reads.Read(layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)index*88UL,88);
            int count=BitConverter.ToUInt16(reads.Read(klass+0x124,2),0);Expect(count==BitConverter.ToUInt16(row,68),"combat runtime field count");
            ulong table=reads.Pointer(klass+0x80,"combat field table");
            foreach(StateField f in fields??CombatStateReference.Fields)
            {
                if(f.Owner!=index)continue;Expect(f.Local<count,"combat runtime field index");byte[] info=reads.Read(table+(ulong)f.Local*32UL,32);
                Expect(BitConverter.ToUInt64(info,0)==layout.RuntimeMetadataBase+f.NameOffset && BitConverter.ToUInt64(info,8)==module.LoadBias+f.Descriptor &&
                    BitConverter.ToUInt64(info,16)==klass && BitConverter.ToUInt32(info,24)==f.Offset && BitConverter.ToUInt32(info,28)==f.Token,"combat runtime field "+f.Name);
            }
        }
        private static ulong CombatDispatch(ObjectReads reads,ulong klass,ObjectClassProfile p,int slot,ModuleResult module,GameLayoutResult layout)
        {
            TeamVirtual target=null;foreach(TeamVirtual v in CombatStateReference.Virtuals)if(v.Index==p.Index && v.Slot==slot)target=v;
            Expect(target!=null,"combat virtual profile");int count=BitConverter.ToUInt16(reads.Read(klass+0x12a,2),0);
            Expect(count>slot && count==BitConverter.ToUInt16(Hex(p.RecordHex),74),"combat virtual slot count");
            Expect(reads.Word(layout.RuntimeMetadataBase+target.MetadataOffset)==target.Encoded &&
                reads.Value(klass+0x138UL+(ulong)slot*16UL)==module.LoadBias+target.Rva,"combat virtual dispatch");return target.Rva;
        }
        private static bool CombatGate(ObjectReads reads,ulong wrappers,ulong length,params int[] gates)
        { foreach(int id in gates)if(HotfixEntry(reads,wrappers,length,id))return false;return true; }
        private static ulong CombatStateBase(ObjectReads reads,ulong klass,ObjectClassProfile p,GameLayoutResult layout)
        {
            for(int depth=0;depth<16;depth++)
            {
                if(p.Index==31737)return klass;
                ObjectClassProfile expected=CombatProfile(p.Parent);
                if(expected==null)return 0;
                klass=reads.Pointer(klass+0x58,"combat state parent");p=CombatClass(reads,klass,layout);
                Expect(p!=null && p.Index==expected.Index,"combat state ancestry");
            }
            throw new InvalidOperationException("Combat state ancestry bound exhausted.");
        }
        private void ReadCombatDying(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,ulong wrappers,ulong length)
        {
            sample.DyingStatus="UNVERIFIED_HOTFIX_ACTIVE";
            if(!CombatGate(reads,wrappers,length,0x49b,0x49a,0x447))return;
            ulong controller=reads.Value(sample.Player+0x1d48,"Combat.Controller");
            sample.DyingStatus="NOT_READY_CONTROLLER_NULL";if(controller==0)return;
            ObjectReads.User(controller,8,"combat controller");ulong ck=reads.Pointer(controller,"combat controller class");ObjectClassProfile cp=CombatClass(reads,ck,layout);
            sample.DyingStatus="UNSUPPORTED_CONTROLLER_CLASS";if(cp==null || cp.Index!=31716)return;
            CombatFields(reads,ck,31716,module,layout);
            OtherContext(reads.Value(controller+0x10,"Combat.ControllerOwner")==sample.Player,"combat controller owner");
            if(sample.BaseDeadRaw==true){sample.IsDieing=false;sample.DyingStatus="ORIGINAL_BRANCH_SAMPLED";return;}
            sample.DyingStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x1d6))return;
            ulong gk=reads.Pointer(module.LoadBias+TeamPolicyReference.GameVarCell,"combat GameVar root");ObjectClassProfile gp=CombatClass(reads,gk,layout);
            Expect(gp!=null && gp.Index==11718 && reads.Word(gk+0xe0)!=0,"combat GameVar initialized class");
            uint staticSize=reads.Word(gk+0x10c);Expect(staticSize>=0x41ff && staticSize<=1048576,"combat GameVar static extent");CombatFields(reads,gk,11718,module,layout);
            ulong gs=reads.Pointer(gk+0xb8,"combat GameVar statics");bool direct=StateBoolean(reads,gs+0x41fe,"Combat.DirectMovementSelector");sample.DirectMovementSelector=direct;
            int movement=0;
            if(direct)
            {
                movement=unchecked((int)reads.Word(controller+0x18,"Combat.MovementState"));sample.MovementStateRaw=movement;
                if(movement!=0){sample.IsDieing=false;sample.DyingStatus="ORIGINAL_BRANCH_SAMPLED";return;}
            }
            ulong state=reads.Value(controller+0x20,"Combat.ControllerState");ulong stateClass=0,stateBase=0;ObjectClassProfile sp=null;
            if(state!=0)
            {
                ObjectReads.User(state,8,"combat state object");stateClass=reads.Pointer(state,"combat state class");sp=CombatClass(reads,stateClass,layout);
                sample.DyingStatus="UNSUPPORTED_STATE_CLASS";if(sp==null)return;
                stateBase=CombatStateBase(reads,stateClass,sp,layout);if(stateBase==0)return;
                CombatFields(reads,stateBase,31737,module,layout);sample.ControllerStateClass=sp.Name;
            }
            if(!direct && state!=0)
            {
                sample.DyingStatus="UNSUPPORTED_MOVEMENT_DISPATCH";if(sp.Index==31737)return;
                ulong rva=CombatDispatch(reads,stateClass,sp,4,module,layout);CombatMovement original=null;
                foreach(CombatMovement candidate in CombatStateReference.Movement)if(candidate.Rva==rva)original=candidate;
                if(original==null)return;
                Expect(reads.Value(module.LoadBias+original.Method.PointerRva)==module.LoadBias+original.Rva &&
                    EqualBytes(reads.Read(layout.RuntimeMetadataBase+original.Method.MetadataOffset,40),Hex(original.Method.RecordHex)) &&
                    EqualBytes(reads.Read(module.LoadBias+original.Rva,80),Hex(original.CodeHex)),"combat selected movement implementation");
                sample.DyingStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,original.Gate))return;
                movement=original.Value;
            }
            sample.MovementStateRaw=movement;
            if(movement!=0){sample.IsDieing=false;sample.DyingStatus="ORIGINAL_BRANCH_SAMPLED";return;}
            sample.DyingStatus="UNVERIFIED_HOTFIX_ACTIVE";if(!CombatGate(reads,wrappers,length,0x27a))return;
            int stateId=0;
            if(state!=0)
            {
                if(!CombatGate(reads,wrappers,length,0x279))return;
                stateId=unchecked((int)reads.Word(state+0x10,"Combat.StateId"));
            }
            sample.ControllerStateRaw=stateId;sample.IsDieing=stateId==8;sample.DyingStatus="ORIGINAL_BRANCH_SAMPLED";
        }
        private void ReadCombatState(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,PlayerStateObservation sample,
            ObjectClassProfile player,ulong playerClass,ulong baseClass,ulong facade,ulong statics,ulong wrappers,ulong length)
        {
            CombatFields(reads,baseClass,31824,module,layout);CombatFields(reads,facade,12418,module,layout);
            sample.GameModeRaw=reads.Word(statics+0x114,"Combat.GameMode");
            sample.GameModeStatus=CombatGate(reads,wrappers,length,0x10a)?"ORIGINAL_GETTER_SAMPLED":"UNVERIFIED_HOTFIX_ACTIVE";
            ulong target=CombatDispatch(reads,playerClass,player,144,module,layout);sample.WatchingStatus="UNSUPPORTED_WATCHING_OVERRIDE";
            if(target==0x6f39994 || target==0x7c698e4)
            {
                sample.WatchingStatus="UNVERIFIED_HOTFIX_ACTIVE";
                if(CombatGate(reads,wrappers,length,target==0x6f39994?0x3c6a:0x25c3c))
                {
                    bool watching=false;
                    if(target==0x7c698e4)
                    {
                        ObjectClassProfile current=ObjectFamily(reads,core.CurrentGame,4,12425,0,layout,null);ulong currentClass=reads.Pointer(core.CurrentGame,"combat current game class");
                        ulong dynamicRoot=RootClass(reads,module,layout,TeamPolicyReference.DynamicClassCell,34107,null);
                        ulong dynamicBase=TeamBase(reads,currentClass,current,34107);
                        Expect(dynamicBase==0 || dynamicBase==dynamicRoot,"combat watching resolved game root");TeamRuntimeCast(reads,currentClass,dynamicRoot,dynamicBase!=0);
                        watching=dynamicBase!=0;sample.WatchingGameClass=current.Name;
                    }
                    // Reproduce only the Boolean. The Watching implementation also
                    // increments a game counter; this reader never performs that write.
                    sample.IsWatching=watching;sample.WatchingStatus="ORIGINAL_BOOLEAN_SAMPLED";
                }
            }
            sample.GhostKindRaw=unchecked((int)reads.Word(sample.Player+0x1bb0,"Combat.GhostKind"));
            sample.GhostStatus="UNVERIFIED_HOTFIX_ACTIVE";
            if(CombatGate(reads,wrappers,length,0x21f84)){sample.IsInAnyGhost=sample.GhostKindRaw!=0;sample.GhostStatus="ORIGINAL_BRANCH_SAMPLED";}
            ReadCombatDying(reads,module,layout,sample,wrappers,length);
        }
        public PlayerStateResult SampleCombatState(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,int rosterIndex,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,true,rosterIndex); }
    }
}
