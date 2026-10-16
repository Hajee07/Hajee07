using System;

namespace HeadBridge.Mapping
{
    internal sealed class TeamVirtual
    {
        internal readonly int Index,Slot;
        internal readonly ulong MetadataOffset,Rva;
        internal readonly uint Encoded;
        internal TeamVirtual(int index,int slot,ulong offset,uint encoded,ulong rva)
        { Index=index;Slot=slot;MetadataOffset=offset;Encoded=encoded;Rva=rva; }
    }
    public sealed class TeamPolicyResult
    {
        public string Status,Detail,Route,GameClass,MembershipProof;
        public uint? GameModeRaw;
        public bool? EnableDynamicTeamID,DynamicDictionaryPresent,SameTeam;
        public byte? LocalTeamByte,OtherTeamByte;
        public ulong LocalPlayer,OtherPlayer;
        public int OtherRosterIndex,Observations;
        public bool ContextVerified,CountersChangedSinceRoster,CountersChangedDuringCapture;
    }
    public sealed partial class Reader
    {
        private void TeamCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            OtherHeadCode(kernel,game,module);
            foreach(GameLayoutCheck check in TeamPolicyReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"team code "+check.Name);
        }
        private static void TeamSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            foreach(StateMethod method in TeamPolicyReference.Methods)
            {
                Expect(reads.Value(module.LoadBias+method.PointerRva)==module.LoadBias+method.Rva,"team registered method");
                Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+method.MetadataOffset,40),Hex(method.RecordHex)),"team method metadata");
            }
            foreach(StateField field in TeamPolicyReference.Fields)
            {
                Expect(reads.Word(module.LoadBias+field.OffsetRva)==field.Offset &&
                    EqualBytes(reads.Read(layout.RuntimeMetadataBase+field.MetadataOffset,12),Hex(field.RecordHex)),"team field registration "+field.Name);
                Expect(reads.Word(module.LoadBias+field.Descriptor+8)==field.Bits,"team field type flags "+field.Name);
                if(field.TypeIndex>=0)Expect(reads.Value(module.LoadBias+field.Descriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)field.TypeIndex*88UL,"team field resolved type "+field.Name);
            }
        }
        private static void TeamClass(ObjectReads reads,ulong klass,int index,GameLayoutResult layout)
        {
            ObjectReads.User(klass,8,"team class");ObjectClassProfile profile=null;
            foreach(ObjectClassProfile p in TeamPolicyReference.Classes)if(p.Index==index)profile=p;
            Expect(profile!=null,"team extra class profile");
            ulong row=layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)index*88UL;
            Expect(reads.Value(klass+0x68)==row && EqualBytes(reads.Read(row,88),Hex(profile.RecordHex)),"team class record "+profile.Name);
            Expect(reads.Value(klass+0x78)==klass && reads.Value(klass+0x20)==row && reads.Word(klass+0x28)==profile.Bits,"team class identity "+profile.Name);
            Expect(reads.Value(klass+0x10)==layout.RuntimeMetadataBase+profile.NameOffset && reads.Value(klass+0x18)==layout.RuntimeMetadataBase+profile.NamespaceOffset &&
                reads.Word(klass+0x11c)==profile.Token && reads.Word(klass+0xf8)==profile.InstanceSize,"team class layout "+profile.Name);
        }
        private static void TeamFields(ObjectReads reads,ulong klass,int index,ModuleResult module,GameLayoutResult layout)
        {
            byte[] record=reads.Read(layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)index*88UL,88);
            int count=BitConverter.ToUInt16(reads.Read(klass+0x124,2),0);
            Expect(count==BitConverter.ToUInt16(record,68),"team runtime field count");
            ulong table=reads.Pointer(klass+0x80,"team field table");
            foreach(StateField field in TeamPolicyReference.Fields)
            {
                if(field.Owner!=index)continue;Expect(field.Local<count,"team runtime field index");
                byte[] info=reads.Read(table+(ulong)field.Local*32UL,32);
                Expect(BitConverter.ToUInt64(info,0)==layout.RuntimeMetadataBase+field.NameOffset && BitConverter.ToUInt64(info,8)==module.LoadBias+field.Descriptor &&
                    BitConverter.ToUInt64(info,16)==klass && BitConverter.ToUInt32(info,24)==field.Offset && BitConverter.ToUInt32(info,28)==field.Token,"team runtime field "+field.Name);
            }
        }
        // Called only after ObjectFamily has validated this complete ancestry.
        private static ulong TeamBase(ObjectReads reads,ulong klass,ObjectClassProfile profile,int index)
        {
            for(int depth=0;depth<16;depth++)
            {
                if(profile.Index==index)return klass;
                if(profile.Index==12425 || profile.Index==31824)return 0;
                klass=reads.Pointer(klass+0x58,"team verified parent");profile=ObjectProfile(profile.Parent);
            }
            throw new InvalidOperationException("Team class bound exhausted.");
        }
        private static ulong TeamDispatch(ObjectReads reads,ulong klass,ObjectClassProfile profile,int slot,ModuleResult module,GameLayoutResult layout)
        {
            TeamVirtual target=null;foreach(TeamVirtual v in TeamPolicyReference.Virtuals)if(v.Index==profile.Index && v.Slot==slot)target=v;
            Expect(target!=null,"team virtual profile");
            int count=BitConverter.ToUInt16(reads.Read(klass+0x12a,2),0);
            Expect(count>slot && count==BitConverter.ToUInt16(Hex(profile.RecordHex),74),"team virtual count");
            Expect(reads.Word(layout.RuntimeMetadataBase+target.MetadataOffset)==target.Encoded &&
                reads.Value(klass+0x138UL+(ulong)slot*16UL)==module.LoadBias+target.Rva,"team virtual dispatch");
            return target.Rva;
        }
        private static void TeamRuntimeCast(ObjectReads reads,ulong klass,ulong target,bool expected)
        {
            byte depth=reads.Byte(klass+0x130),targetDepth=reads.Byte(target+0x130);
            Expect(depth>0 && depth<=64 && targetDepth>0 && targetDepth<=64,"team runtime hierarchy depth");
            bool actual=false;
            if(depth>=targetDepth)
            { ulong hierarchy=reads.Pointer(klass+0xc8,"team runtime hierarchy");actual=reads.Value(hierarchy+(ulong)(targetDepth-1)*8UL)==target; }
            Expect(actual==expected,"team runtime cast agrees with verified ancestry");
        }
        private static bool TeamGates(ObjectReads reads,ulong wrappers,ulong length,TeamPolicyResult result,params int[] gates)
        {
            foreach(int gate in gates)if(HotfixEntry(reads,wrappers,length,gate))
            { result.Status="UNVERIFIED_HOTFIX_ACTIVE";result.Detail="Gate=0x"+gate.ToString("x");return false; }
            return true;
        }
        private static ulong TeamInitializedRoot(ObjectReads reads,ModuleResult module,GameLayoutResult layout,ulong cell,int index)
        {
            ulong klass=reads.Pointer(module.LoadBias+cell,"team initialized root");TeamClass(reads,klass,index,layout);
            Expect(reads.Word(klass+0xe0)!=0,"team root static initialization");return klass;
        }
        private void TeamMember(ObjectReads reads,MatchPlayerObservation member,PlayerObjectResult core,ModuleResult module,GameLayoutResult layout,uint used)
        {
            OtherContext(member.EntrySnapshot!=null && member.EntrySnapshot.Length==40,"team selected entry snapshot");
            byte[] entry=reads.Read(core.RosterEntries+0x20UL+(ulong)member.EntryIndex*40UL,40,"Team.SelectedEntry");
            OtherContext(EqualBytes(entry,member.EntrySnapshot) && BitConverter.ToUInt64(entry,32)==member.Address,"team selected entry fingerprint");
            int next=BitConverter.ToInt32(entry,4);Expect(BitConverter.ToInt32(entry,0)>=0 && next>=-1 && next<used,"team selected link");
            ObjectClassProfile player=ObjectFamily(reads,member.Address,16,31824,0,layout,null);
            OtherContext(player.Name==member.Class && (member.Address==core.LocalPlayer)==member.IsLocal &&
                reads.Byte(member.Address+0x420,"Team.LocalMarker")==(member.IsLocal?1:0),"team selected role");
            ulong playerBase=TeamBase(reads,reads.Pointer(member.Address,"team player class"),player,31824);
            Expect(playerBase!=0,"team Player base");TeamFields(reads,playerBase,31824,module,layout);
        }
        private void ReadTeamRoute(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,
            MatchPlayerObservation other,ulong facade,ulong statics,ulong wrappers,ulong length,TeamPolicyResult result)
        {
            TeamFields(reads,facade,12418,module,layout);
            Expect(reads.Word(facade+0x10c)>=0x118 && reads.Word(facade+0x10c)<=1048576,"team facade static extent");
            result.GameModeRaw=reads.Word(statics+0x114,"Team.GameMode");
            if(!TeamGates(reads,wrappers,length,result,0x4f5,0x149,0x148,0x10a))return;
            if(result.GameModeRaw==58){result.Route="FACTION";result.Status="UNSUPPORTED_FACTION_POLICY";return;}
            ulong matchGame=reads.Value(statics+8,"Team.CurrentMatchGame");
            if(matchGame==0){result.Route="FACADE_FALLBACK";result.Status="UNSUPPORTED_NO_CURRENT_MATCH_GAME";return;}
            if(matchGame!=core.CurrentGame){result.Status="UNSUPPORTED_DISTINCT_CURRENT_MATCH_GAME";return;}
            ObjectClassProfile profile=ObjectFamily(reads,matchGame,4,12425,0,layout,null);result.GameClass=profile.Name;
            ulong klass=reads.Pointer(matchGame,"team match-game class");
            if(TeamDispatch(reads,klass,profile,92,module,layout)!=0x7328844)
            { result.Route="MATCH_OVERRIDE";result.Status="UNSUPPORTED_MATCH_POLICY_OVERRIDE";return; }
            result.Route="BASE_MATCHGAME";
            if(!TeamGates(reads,wrappers,length,result,0x4f4,0x138,0x15e,0x15c,0x15b))return;
            TeamInitializedRoot(reads,module,layout,TeamPolicyReference.UnityObjectCell,TeamPolicyReference.UnityObjectIndex);
            if(reads.Value(core.LocalPlayer+0x10,"Team.LocalNativeObject")==0 || reads.Value(other.Address+0x10,"Team.OtherNativeObject")==0)
            { result.Status="NOT_READY_NATIVE_PLAYER_OBJECT";return; }
            // CurrentGame and CurrentMatchGame are the same verified MatchGame.
            // Both branches of CurrentGameModeSetting therefore select the same
            // virtual getter, regardless of its GameVar branch selector.
            ulong gameVar=TeamInitializedRoot(reads,module,layout,TeamPolicyReference.GameVarCell,TeamPolicyReference.GameVarIndex);
            Expect(reads.Word(gameVar+0x10c)>=0x420c && reads.Word(gameVar+0x10c)<=1048576,"team GameVar static extent");
            ulong gameVarStatics=reads.Pointer(gameVar+0xb8,"team GameVar statics");
            reads.Byte(gameVarStatics+0x420b,"Team.SettingsBranchSelector");
            if(TeamDispatch(reads,klass,profile,75,module,layout)!=0x7323464)
            { result.Status="UNSUPPORTED_SETTINGS_GETTER_OVERRIDE";return; }
            ulong baseClass=TeamBase(reads,klass,profile,12425);Expect(baseClass!=0,"team MatchGame base");
            ulong matchRoot=RootClass(reads,module,layout,ObjectReference.MatchGameCell,12425,null);
            Expect(matchRoot==baseClass,"team resolved MatchGame root");TeamRuntimeCast(reads,klass,matchRoot,true);
            TeamFields(reads,baseClass,12425,module,layout);
            ulong settings=reads.Value(matchGame+0x98,"Team.Settings");
            if(settings==0){result.Status="NOT_READY_CACHED_SETTINGS_NULL";return;}
            ObjectReads.User(settings,8,"team mode settings");ulong settingsClass=reads.Pointer(settings,"team mode settings class");
            TeamClass(reads,settingsClass,11715,layout);TeamFields(reads,settingsClass,11715,module,layout);
            result.EnableDynamicTeamID=StateBoolean(reads,settings+0xa55,"Team.EnableDynamicTeamID");
            ulong dynamicBase=TeamBase(reads,klass,profile,34107);
            if(result.EnableDynamicTeamID.Value)
            {
                ulong dynamicRoot=RootClass(reads,module,layout,TeamPolicyReference.DynamicClassCell,34107,null);
                Expect(dynamicBase==0 || dynamicBase==dynamicRoot,"team resolved dynamic root");TeamRuntimeCast(reads,klass,dynamicRoot,dynamicBase!=0);
            }
            if(result.EnableDynamicTeamID.Value && dynamicBase!=0)
            {
                result.Route="DYNAMIC_TEAM_DICTIONARY";
                if(!TeamGates(reads,wrappers,length,result,0x15d))return;
                TeamFields(reads,dynamicBase,34107,module,layout);
                ulong dictionary=reads.Value(matchGame+0x330,"Team.DynamicDictionary");result.DynamicDictionaryPresent=dictionary!=0;
                if(dictionary!=0)
                { ObjectReads.User(dictionary,8,"team dynamic dictionary");result.Status="UNSUPPORTED_DYNAMIC_TEAM_DICTIONARY";return; }
                // The inspected original helper returns 0xff when its dictionary
                // reference is null. This is a predicate result, not hostility.
                result.LocalTeamByte=255;result.OtherTeamByte=255;result.SameTeam=true;
                result.Status="ORIGINAL_DYNAMIC_NULL_DEFAULT";return;
            }
            result.Route="PACKED_PLAYER_ID_BYTE";
            ulong keyClass=reads.Pointer(module.LoadBias+TeamPolicyReference.KeyCell,"team resolved player-ID type");
            TeamClass(reads,keyClass,34565,layout);TeamFields(reads,keyClass,34565,module,layout);
            Expect(reads.Word(keyClass+0xe0)!=0,"team player-ID static initialization");
            byte[] localId=reads.Read(core.LocalPlayer+0x408,24,"Team.LocalPlayerID"),otherId=reads.Read(other.Address+0x408,24,"Team.OtherPlayerID");
            result.LocalTeamByte=localId[8];result.OtherTeamByte=otherId[8];result.SameTeam=localId[8]==otherId[8];
            result.Status="ORIGINAL_PREDICATE_SAMPLED";
        }
        public TeamPolicyResult SampleTeamPolicy(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        {
            TeamPolicyResult result=new TeamPolicyResult { Status="PREREQUISITES_UNVERIFIED" };
            if(core==null || module==null || layout==null || module.BuildId!=ApkModule.BuildId || module.ReferenceFileSha256!=ApkModule.FileSha256 ||
                layout.MetadataSha256!=GameLayoutReference.MetadataSha256 || core.RosterStatus!="TYPED_COLLECTION_VERIFIED" || core.RosterCounterSnapshot==null || core.RosterCounterSnapshot.Length!=16)return result;
            MatchPlayerObservation local=null,other=null;int otherIndex=-1;
            for(int i=0;i<core.MatchPlayers.Length;i++)
            { if(core.MatchPlayers[i].IsLocal)local=core.MatchPlayers[i];else if(other==null){other=core.MatchPlayers[i];otherIndex=i;} }
            if(local==null || other==null){result.Status="NO_VERIFIED_LOCAL_OTHER_PAIR";return result;}
            int allowance=Math.Min(6000,30000-PhysicalCalls);if(allowance<=1500){result.Status="READ_BUDGET_RESERVE";return result;}
            using(PhysicalCallScope(allowance))
            {
                ObjectReads schema=new ObjectReads(this,game.Root),reads=new ObjectReads(this,game.Root);
                try
                {
                    using(PhysicalCallScope(allowance-1500))
                    {
                        TeamCode(kernel,game,module);OtherHeadSchema(schema,game,module,layout,core);TeamSchema(schema,module,layout);
                        ulong facade=RootClass(reads,module,layout,ObjectReference.FacadeCell,12418,null),statics=reads.Pointer(facade+0xb8,"team facade statics");
                        OtherContext(reads.Value(statics,"Team.CurrentGame")==core.CurrentGame && reads.Value(core.CurrentGame+0x90,"Team.Match")==core.Match &&
                            reads.Value(core.Match+0xd8,"Team.LocalPlayer")==core.LocalPlayer,"team current context");
                        OtherContext(reads.Value(core.Match+0x128,"Team.Roster")==core.RosterDictionary && reads.Value(core.RosterDictionary,"Team.RosterClass")==core.RosterClass &&
                            reads.Value(core.RosterDictionary+0x18,"Team.Entries")==core.RosterEntries && reads.Value(core.RosterEntries,"Team.ArrayClass")==core.RosterArrayClass &&
                            reads.Value(core.RosterEntries+0x18,"Team.Capacity")==core.RosterCapacity,"team collection identity");
                        byte[] beforeLocal=OtherCounterAudit(game,core,local,"TEAM_LOCAL_BEFORE"),beforeOther=OtherCounterAudit(game,core,other,"TEAM_OTHER_BEFORE");
                        TeamMember(reads,local,core,module,layout,BitConverter.ToUInt32(beforeLocal,0));TeamMember(reads,other,core,module,layout,BitConverter.ToUInt32(beforeOther,0));
                        ulong hotfix=RootClass(reads,module,layout,ObjectReference.HotfixCell,37332,null);VerifyWrapperField(reads,hotfix,module,layout);
                        Expect(reads.Word(facade+0xe0)!=0 && reads.Word(hotfix+0xe0)!=0,"team static initialization");
                        ulong wrappers=reads.Pointer(reads.Pointer(hotfix+0xb8,"team hotfix statics"),"team wrapper array");reads.Pointer(wrappers,"team wrapper array class");
                        ulong length=reads.Value(wrappers+0x18);Expect(length<=1000000,"team hotfix array bound");
                        foreach(int id in new int[]{0x1c6,0x139,0x1c5,0x12b,0x1bf})OtherContext(!HotfixEntry(reads,wrappers,length,id),"team context hotfix");
                        if(progress!=null)progress("TeamPolicyCandidate OtherRosterIndex="+otherIndex+" Predicate=GameFacade.IsSameTeam(local,other)");
                        ReadTeamRoute(reads,module,layout,core,other,facade,statics,wrappers,length,result);
                        byte[] afterLocal=OtherCounterAudit(game,core,local,"TEAM_LOCAL_AFTER"),afterOther=OtherCounterAudit(game,core,other,"TEAM_OTHER_AFTER");
                        Expect(BitConverter.ToInt32(local.EntrySnapshot,4)<BitConverter.ToUInt32(afterLocal,0) &&
                            BitConverter.ToInt32(other.EntrySnapshot,4)<BitConverter.ToUInt32(afterOther,0),"team final selected links");
                        result.CountersChangedSinceRoster=!EqualBytes(beforeLocal,core.RosterCounterSnapshot)||!EqualBytes(beforeOther,core.RosterCounterSnapshot);
                        result.CountersChangedDuringCapture=!EqualBytes(beforeLocal,afterLocal)||!EqualBytes(beforeOther,afterOther);
                        result.Observations=reads.Recheck();Recheck(kernel,game);
                    }
                    schema.Recheck();TeamCode(kernel,game,module);
                    result.ContextVerified=true;result.MembershipProof="BOTH_SELECTED_ENTRIES_REVALIDATED";
                    result.LocalPlayer=local.Address;result.OtherPlayer=other.Address;result.OtherRosterIndex=otherIndex;return result;
                }
                catch(Exception error)
                {
                    return new TeamPolicyResult { Status=error is PhysicalScopeLimitException?"READ_LIMIT_REACHED":
                        error is OtherHeadContextException || error is ObjectObservationChangedException?"NOT_READY_CONTEXT_CHANGED":"FAIL",Detail=error.Message };
                }
            }
        }
    }
}
