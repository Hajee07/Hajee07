using System;

namespace HeadBridge.Mapping
{
    public sealed class MatchDamagePolicyResult
    {
        public string Status,Detail,GameClass,GameModeStatus,MembershipProof;
        public bool ContextVerified,ArgumentIndependent,CountersChangedSinceRoster,CountersChangedDuringCapture;
        public bool? Predicate;
        public uint? GameModeRaw;
        public ulong LocalPlayer,OtherPlayer,CurrentMatchGame,MethodRva;
        public int OtherRosterIndex,Observations;
    }
    public sealed partial class Reader
    {
        private void DamageCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            OtherHeadCode(kernel,game,module);
            foreach(GameLayoutCheck check in MatchDamageReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"match-damage code "+check.Name);
        }
        private void DamageMember(ObjectReads reads,MatchPlayerObservation member,PlayerObjectResult core,GameLayoutResult layout,uint used)
        {
            OtherContext(member.EntrySnapshot!=null && member.EntrySnapshot.Length==40,"damage selected entry snapshot");
            byte[] entry=reads.Read(core.RosterEntries+0x20UL+(ulong)member.EntryIndex*40UL,40,"Damage.SelectedEntry");
            OtherContext(EqualBytes(entry,member.EntrySnapshot) && BitConverter.ToUInt64(entry,32)==member.Address,"damage selected entry fingerprint");
            int next=BitConverter.ToInt32(entry,4);Expect(BitConverter.ToInt32(entry,0)>=0 && next>=-1 && next<used,"damage selected link");
            ObjectClassProfile player=ObjectFamily(reads,member.Address,16,31824,0,layout,null);
            OtherContext(player.Name==member.Class && (member.Address==core.LocalPlayer)==member.IsLocal &&
                reads.Byte(member.Address+0x420,"Damage.LocalMarker")== (member.IsLocal?1:0),"damage member class/local role");
        }
        private static ulong DamageDispatch(ObjectReads reads,ulong klass,ObjectClassProfile profile,ModuleResult module,GameLayoutResult layout)
        {
            TeamVirtual target=null;foreach(TeamVirtual v in MatchDamageReference.Virtuals)if(v.Index==profile.Index)target=v;
            Expect(target!=null,"damage virtual class profile");int count=BitConverter.ToUInt16(reads.Read(klass+0x12a,2),0);
            Expect(count>91 && count==BitConverter.ToUInt16(Hex(profile.RecordHex),74),"damage virtual slot count");
            Expect(reads.Word(layout.RuntimeMetadataBase+target.MetadataOffset)==target.Encoded &&
                reads.Value(klass+0x138UL+91UL*16UL)==module.LoadBias+target.Rva,"damage virtual dispatch");return target.Rva;
        }
        public MatchDamagePolicyResult SampleMatchDamagePolicy(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        {
            MatchDamagePolicyResult result=new MatchDamagePolicyResult { Status="PREREQUISITES_UNVERIFIED" };
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
                        DamageCode(kernel,game,module);OtherHeadSchema(schema,game,module,layout,core);
                        CombatSchema(schema,module,layout,MatchDamageReference.Methods,MatchDamageReference.Fields);
                        ulong facade=RootClass(reads,module,layout,ObjectReference.FacadeCell,12418,null),statics=reads.Pointer(facade+0xb8,"damage facade statics");
                        Expect(reads.Word(facade+0xe0)!=0 && reads.Word(facade+0x10c)>=0x118 && reads.Word(facade+0x10c)<=1048576,"damage facade initialized static extent");
                        CombatFields(reads,facade,12418,module,layout,MatchDamageReference.Fields);
                        OtherContext(reads.Value(statics,"Damage.CurrentGame")==core.CurrentGame && reads.Value(core.CurrentGame+0x90,"Damage.Match")==core.Match &&
                            reads.Value(core.Match+0xd8,"Damage.LocalPlayer")==core.LocalPlayer,"damage current game/match/local");
                        ObjectClassProfile current=ObjectFamily(reads,core.CurrentGame,4,12425,0,layout,null);ulong currentClass=reads.Pointer(core.CurrentGame,"damage current class");
                        ulong baseClass=TeamBase(reads,currentClass,current,12425);Expect(baseClass!=0,"damage MatchGame ancestry");CombatFields(reads,baseClass,12425,module,layout,MatchDamageReference.Fields);
                        ObjectClassProfile match=ObjectFamily(reads,core.Match,8,32133,0,layout,null);ulong matchClass=reads.Pointer(core.Match,"damage match class");
                        ulong matchBase=TeamBase(reads,matchClass,match,32133);Expect(matchBase!=0,"damage Match ancestry");CombatFields(reads,matchBase,32133,module,layout,MatchDamageReference.Fields);
                        OtherContext(reads.Value(core.Match+0x128,"Damage.Roster")==core.RosterDictionary && reads.Value(core.RosterDictionary,"Damage.RosterClass")==core.RosterClass &&
                            reads.Value(core.RosterDictionary+0x18,"Damage.Entries")==core.RosterEntries && reads.Value(core.RosterEntries,"Damage.ArrayClass")==core.RosterArrayClass &&
                            reads.Value(core.RosterEntries+0x18,"Damage.Capacity")==core.RosterCapacity,"damage collection identity");
                        byte[] beforeLocal=OtherCounterAudit(game,core,local,"DAMAGE_LOCAL_BEFORE"),beforeOther=OtherCounterAudit(game,core,other,"DAMAGE_OTHER_BEFORE");
                        DamageMember(reads,local,core,layout,BitConverter.ToUInt32(beforeLocal,0));DamageMember(reads,other,core,layout,BitConverter.ToUInt32(beforeOther,0));
                        ulong hotfix=RootClass(reads,module,layout,ObjectReference.HotfixCell,37332,null);VerifyWrapperField(reads,hotfix,module,layout);
                        Expect(reads.Word(hotfix+0xe0)!=0,"damage hotfix initialization");ulong wrappers=reads.Pointer(reads.Pointer(hotfix+0xb8,"damage hotfix statics"),"damage wrapper array");reads.Pointer(wrappers,"damage wrapper array class");
                        ulong length=reads.Value(wrappers+0x18);Expect(length<=1000000,"damage wrapper array bound");
                        foreach(int id in new int[]{0x1c6,0x139,0x1c5,0x12b,0x1bf})OtherContext(!HotfixEntry(reads,wrappers,length,id),"damage original context gate");
                        result.CurrentMatchGame=reads.Value(statics+8,"Damage.CurrentMatchGame");result.GameModeRaw=reads.Word(statics+0x114,"Damage.GameMode");
                        result.GameModeStatus=CombatGate(reads,wrappers,length,0x10a)?"ORIGINAL_GETTER_SAMPLED":"UNVERIFIED_HOTFIX_ACTIVE";
                        result.GameClass=current.Name;result.Status="NOT_READY_CURRENT_MATCH_GAME_NULL";
                        if(result.CurrentMatchGame!=0)
                        {
                            result.Status="UNSUPPORTED_DISTINCT_CURRENT_MATCH_GAME";
                            if(result.CurrentMatchGame==core.CurrentGame)
                            {
                                result.MethodRva=DamageDispatch(reads,currentClass,current,module,layout);result.Status="UNSUPPORTED_DAMAGE_POLICY_OVERRIDE";
                                if(result.MethodRva==0x7327e50)
                                {
                                    result.Status="UNVERIFIED_HOTFIX_ACTIVE";
                                    if(CombatGate(reads,wrappers,length,0x853d))
                                    { result.Predicate=true;result.ArgumentIndependent=true;result.Status="ORIGINAL_ARGUMENT_INDEPENDENT_TRUE"; }
                                }
                            }
                        }
                        if(progress!=null)progress("MatchDamagePolicyCandidate OtherRosterIndex="+otherIndex+" Scope=CURRENT_MATCH_GAME_POLICY_ONLY");
                        byte[] afterLocal=OtherCounterAudit(game,core,local,"DAMAGE_LOCAL_AFTER"),afterOther=OtherCounterAudit(game,core,other,"DAMAGE_OTHER_AFTER");
                        Expect(BitConverter.ToInt32(local.EntrySnapshot,4)<BitConverter.ToUInt32(afterLocal,0) && BitConverter.ToInt32(other.EntrySnapshot,4)<BitConverter.ToUInt32(afterOther,0),"damage final selected link bounds");
                        result.CountersChangedSinceRoster=!EqualBytes(beforeLocal,core.RosterCounterSnapshot)||!EqualBytes(beforeOther,core.RosterCounterSnapshot);
                        result.CountersChangedDuringCapture=!EqualBytes(beforeLocal,afterLocal)||!EqualBytes(beforeOther,afterOther);
                        result.Observations=reads.Recheck();Recheck(kernel,game);
                    }
                    schema.Recheck();DamageCode(kernel,game,module);result.ContextVerified=true;result.MembershipProof="BOTH_SELECTED_ENTRIES_REVALIDATED";
                    result.LocalPlayer=local.Address;result.OtherPlayer=other.Address;result.OtherRosterIndex=otherIndex;return result;
                }
                catch(Exception error)
                { return new MatchDamagePolicyResult { Status=error is PhysicalScopeLimitException?"READ_LIMIT_REACHED":error is OtherHeadContextException || error is ObjectObservationChangedException?"NOT_READY_CONTEXT_CHANGED":"FAIL",Detail=error.Message }; }
            }
        }
    }
}
