using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    public sealed class OtherHeadObservation
    {
        public int RosterIndex,Attempts,ParentCount,Observations;
        public ulong Player,Provider,Transform;
        public string Class,Status,Source,Detail;
        public float X,Y,Z;
    }
    public sealed class OtherHeadResult
    {
        public OtherHeadObservation[] Samples=new OtherHeadObservation[0];
        public int Eligible,Sampled;
        public string StopReason,Detail;
    }
    public sealed partial class Reader
    {
        private sealed class OtherHeadContextException : InvalidOperationException
        { internal OtherHeadContextException(string label) : base("Other-head context changed: "+label) { } }
        private static void OtherContext(bool matches,string label)
        { if(!matches)throw new OtherHeadContextException(label); }
        private void OtherHeadCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            Recheck(kernel,game);ObjectAnchors(this,game,module);
            foreach(GameLayoutCheck check in RosterReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+check.Address,check.Expected(module.LoadBias).Length),check.Expected(module.LoadBias)),"other-head roster code "+check.Name);
        }
        private OtherHeadObservation ReadOtherHead(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,
            PlayerObjectResult core,MatchPlayerObservation member,int rosterIndex,Action<string> progress)
        {
            ObjectReads reads=new ObjectReads(this,game.Root);
            ulong facade=RootClass(reads,module,layout,ObjectReference.FacadeCell,12418,null);
            ulong statics=reads.Pointer(facade+0xb8,"other-head GameFacade statics");
            OtherContext(reads.Value(statics)==core.CurrentGame && reads.Value(core.CurrentGame+0x90)==core.Match &&
                reads.Value(core.Match+0xd8)==core.LocalPlayer,"current game/match/local player");
            OtherContext(reads.Value(core.Match+0x128)==core.RosterDictionary && reads.Value(core.RosterDictionary)==core.RosterClass &&
                reads.Value(core.RosterDictionary+0x18)==core.RosterEntries &&
                EqualBytes(reads.Read(core.RosterDictionary+0x20,16),core.RosterCounterSnapshot),"collection pointer/counters");
            OtherContext(reads.Value(core.RosterEntries)==core.RosterArrayClass && reads.Value(core.RosterEntries+0x18)==core.RosterCapacity,"entry array identity/length");
            OtherContext(member.EntryIndex>=0 && member.EntryIndex<core.RosterUsed && member.EntrySnapshot!=null && member.EntrySnapshot.Length==40 &&
                EqualBytes(reads.Read(core.RosterEntries+0x20UL+(ulong)member.EntryIndex*40UL,40),member.EntrySnapshot),"selected entry fingerprint");
            OtherContext(BitConverter.ToUInt64(member.EntrySnapshot,32)==member.Address && !member.IsLocal && member.Address!=core.LocalPlayer,"selected nonlocal member");
            ObjectClassProfile profile=ObjectFamily(reads,member.Address,16,31824,0,layout,null);
            OtherContext(profile.Name==member.Class && reads.Byte(member.Address+0x420)==0,"selected class/local marker");
            ulong hotfix=RootClass(reads,module,layout,ObjectReference.HotfixCell,37332,null);VerifyWrapperField(reads,hotfix,module,layout);
            ulong hotfixStatics=reads.Pointer(hotfix+0xb8,"other-head hotfix statics"),wrappers=reads.Pointer(hotfixStatics,"other-head wrapper array");
            ulong length=reads.Value(wrappers+0x18);Expect(length<=1000000,"other-head hotfix array bound");
            foreach(int id in new int[]{0x1c6,0x139,0x1c5,0x12b,0x1bf})
                OtherContext(!HotfixEntry(reads,wrappers,length,id),"original path hotfix 0x"+id.ToString("x"));
            PlayerObjectResult head=new PlayerObjectResult { LocalPlayer=member.Address,PlayerClass=member.Class };
            Action<string> note=progress==null ? (Action<string>)null : delegate(string text){progress("OtherHeadProgress Index="+rosterIndex+" "+text);};
            ResolveManagedPlayerHead(reads,game,module,layout,head,profile,wrappers,length,note);
            try { ReadNativeHeadPosition(game,module,head,note); }
            catch(NativeHeadMotionException error){head.HeadWorldStatus="NOT_READY_MOTION";head.HeadWorldError=error.Message;}
            Recheck(kernel,game);int observations=reads.Recheck();Recheck(kernel,game);
            return new OtherHeadObservation { RosterIndex=rosterIndex,Player=member.Address,Class=member.Class,Provider=head.HeadProvider,Transform=head.HeadTransform,
                Status=head.HeadWorldStatus=="SAMPLED_READ_ONLY" ? head.HeadWorldStatus : head.HeadStatus!="MANAGED_TRANSFORM_VERIFIED" ? head.HeadStatus : head.HeadWorldStatus,
                Source=head.HeadSource,Detail=head.HeadWorldError,X=head.HeadWorldX,Y=head.HeadWorldY,Z=head.HeadWorldZ,
                Attempts=head.HeadSampleAttempts,ParentCount=head.HeadParentCount,Observations=observations+head.HeadWorldObservations };
        }
        public OtherHeadResult SampleOtherPlayerHeads(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        {
            OtherHeadResult result=new OtherHeadResult { StopReason="PREREQUISITES_UNVERIFIED" };
            if(core==null || module==null || layout==null || module.BuildId!=ApkModule.BuildId || module.ReferenceFileSha256!=ApkModule.FileSha256 ||
                layout.MetadataSha256!=GameLayoutReference.MetadataSha256 || core.RosterStatus!="TYPED_COLLECTION_VERIFIED" || core.RosterCounterSnapshot==null || core.RosterCounterSnapshot.Length!=16)return result;
            foreach(MatchPlayerObservation member in core.MatchPlayers)if(!member.IsLocal)result.Eligible++;
            if(result.Eligible==0){result.StopReason="NO_VERIFIED_OTHER_OBJECTS";return result;}
            int totalAllowance=Math.Min(6000,30000-PhysicalCalls),allowance=totalAllowance-1000;
            if(allowance<1){result.StopReason="READ_BUDGET_RESERVE";return result;}
            List<OtherHeadObservation> samples=new List<OtherHeadObservation>();result.StopReason="SELECTED_OBJECTS_EXHAUSTED";
            using(PhysicalCallScope(totalAllowance))
            {
                try
                {
                    using(PhysicalCallScope(allowance))
                    {
                        OtherHeadCode(kernel,game,module);
                        for(int i=0;i<core.MatchPlayers.Length;i++)
                        {
                            MatchPlayerObservation member=core.MatchPlayers[i];if(member.IsLocal)continue;
                            if(samples.Count==2){result.StopReason="TWO_OBJECT_LIMIT";break;}
                            if(progress!=null)progress("OtherHeadCandidate Index="+i+" Class="+member.Class+" Player=0x"+member.Address.ToString("x"));
                            OtherHeadObservation sample;
                            try { sample=ReadOtherHead(kernel,game,module,layout,core,member,i,progress); }
                            catch(PhysicalScopeLimitException error)
                            { samples.Add(new OtherHeadObservation { RosterIndex=i,Player=member.Address,Class=member.Class,Status="READ_LIMIT_REACHED",Detail=error.Message });result.StopReason="READ_LIMIT_REACHED";break; }
                            catch(OtherHeadContextException error)
                            { samples.Add(new OtherHeadObservation { RosterIndex=i,Player=member.Address,Class=member.Class,Status="NOT_READY_CONTEXT_CHANGED",Detail=error.Message });result.StopReason="CONTEXT_CHANGED";break; }
                            catch(Exception error)
                            { samples.Add(new OtherHeadObservation { RosterIndex=i,Player=member.Address,Class=member.Class,Status="FAIL",Detail=error.Message });result.StopReason="SAMPLE_FAILED";break; }
                            samples.Add(sample);
                        }
                    }
                }
                catch(PhysicalScopeLimitException error){result.StopReason="READ_LIMIT_REACHED";result.Detail=error.Message;}
                catch(Exception error){result.StopReason="FAIL";result.Detail=error.Message;return result;}
                // The inner scope is disposed. The outer phase scope still caps
                // total additional calls at 6000, with 1000 reserved for final checks.
                try { OtherHeadCode(kernel,game,module); }
                catch(Exception error){result.StopReason="FINAL_CONTEXT_FAILED";result.Detail=error.Message;return result;}
                result.Samples=samples.ToArray();foreach(OtherHeadObservation sample in result.Samples)if(sample.Status=="SAMPLED_READ_ONLY")result.Sampled++;
                return result;
            }
        }
    }
}
