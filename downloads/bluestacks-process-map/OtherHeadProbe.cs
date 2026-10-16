using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    public sealed class OtherHeadObservation
    {
        public int RosterIndex,Attempts,ParentCount,Observations;
        public ulong Player,Provider,Transform;
        public string Class,Status,Source,Detail;
        public string MembershipProof;
        public bool CountersChangedSinceRoster,CountersChangedDuringCapture;
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
        private static void OtherHeadSchema(ObjectReads schema,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core)
        {
            OtherContext(schema.Value(core.Match+0x128)==core.RosterDictionary && schema.Value(core.RosterDictionary)==core.RosterClass &&
                schema.Value(core.RosterDictionary+0x18)==core.RosterEntries && schema.Value(core.RosterEntries)==core.RosterArrayClass,"collection schema storage identity");
            ulong generic=RosterGeneric(schema,core.RosterClass,RosterReference.Dictionary,0x12,layout);
            Expect(schema.Value(module.LoadBias+RosterReference.FieldTypeRva)==generic && schema.Word(module.LoadBias+RosterReference.FieldTypeRva+8)==0x150004 &&
                schema.Word(module.LoadBias+RosterReference.FieldOffsetRva)==0x128 &&
                EqualBytes(schema.Read(layout.RuntimeMetadataBase+RosterReference.FieldMetadataOffset,12),Hex(RosterReference.FieldRecordHex)),"other-head collection field registration");
            uint dictionarySize=schema.Word(core.RosterClass+0xf8);Expect(dictionarySize>=80 && dictionarySize<=1048576,"other-head dictionary storage size");
            RosterArray(schema,core.RosterEntries,layout);
        }
        private byte[] OtherCounterAudit(GameProcess game,PlayerObjectResult core,MatchPlayerObservation member,string phase)
        {
            byte[] first=Virtual(game.Root,core.RosterDictionary+0x20,16),second=Virtual(game.Root,core.RosterDictionary+0x20,16);
            OtherContext(EqualBytes(first,second),"counter audit changed at "+phase);
            uint used=BitConverter.ToUInt32(second,0),free=BitConverter.ToUInt32(second,8);int freeList=BitConverter.ToInt32(second,4);
            Expect(used<=256 && free<=used && freeList>=-1 && (freeList==-1 || (uint)freeList<used),"other-head current collection counter bounds Phase="+phase);
            Expect(core.RosterCapacity>=used && core.RosterCapacity<=8192,"other-head current entry-array capacity Phase="+phase);
            OtherContext(member.EntryIndex>=0 && member.EntryIndex<used,"selected entry index at "+phase);
            return second;
        }
        private void ReadOtherHead(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,
            PlayerObjectResult core,MatchPlayerObservation member,int rosterIndex,OtherHeadObservation sample,Action<string> progress)
        {
            ObjectReads reads=new ObjectReads(this,game.Root);
            ulong facade=RootClass(reads,module,layout,ObjectReference.FacadeCell,12418,null);
            ulong statics=reads.Pointer(facade+0xb8,"other-head GameFacade statics");
            OtherContext(reads.Value(statics,"OtherMembership.CurrentGame")==core.CurrentGame && reads.Value(core.CurrentGame+0x90,"OtherMembership.Match")==core.Match &&
                reads.Value(core.Match+0xd8,"OtherMembership.LocalPlayer")==core.LocalPlayer,"current game/match/local player");
            OtherContext(reads.Value(core.Match+0x128,"OtherMembership.Dictionary")==core.RosterDictionary && reads.Value(core.RosterDictionary,"OtherMembership.DictionaryClass")==core.RosterClass &&
                reads.Value(core.RosterDictionary+0x18,"OtherMembership.Entries")==core.RosterEntries,"collection identity");
            // Global counters can change when a different member is removed.
            // Audit bounded endpoint headers separately; the selected entry,
            // storage and object identity still use exact snapshot rechecks.
            byte[] counters=OtherCounterAudit(game,core,member,"BEFORE");uint used=BitConverter.ToUInt32(counters,0);
            sample.CountersChangedSinceRoster=!EqualBytes(counters,core.RosterCounterSnapshot);
            OtherContext(reads.Value(core.RosterEntries,"OtherMembership.ArrayClass")==core.RosterArrayClass &&
                reads.Value(core.RosterEntries+0x18,"OtherMembership.Capacity")==core.RosterCapacity,"entry array identity/length");
            OtherContext(member.EntrySnapshot!=null && member.EntrySnapshot.Length==40,"selected entry fingerprint length");
            byte[] entry=reads.Read(core.RosterEntries+0x20UL+(ulong)member.EntryIndex*40UL,40,"OtherMembership.SelectedEntry");
            OtherContext(EqualBytes(entry,member.EntrySnapshot),"selected entry fingerprint");
            int next=BitConverter.ToInt32(entry,4);Expect(BitConverter.ToInt32(entry,0)>=0 && next>=-1 && next<used,"other-head selected active entry/link");
            OtherContext(BitConverter.ToUInt64(member.EntrySnapshot,32)==member.Address && !member.IsLocal && member.Address!=core.LocalPlayer,"selected nonlocal member");
            ObjectClassProfile profile=ObjectFamily(reads,member.Address,16,31824,0,layout,null);
            OtherContext(profile.Name==member.Class && reads.Byte(member.Address+0x420,"OtherMembership.LocalMarker")==0,"selected class/local marker");
            ulong hotfix=RootClass(reads,module,layout,ObjectReference.HotfixCell,37332,null);VerifyWrapperField(reads,hotfix,module,layout);
            ulong hotfixStatics=reads.Pointer(hotfix+0xb8,"other-head hotfix statics"),wrappers=reads.Pointer(hotfixStatics,"other-head wrapper array");
            ulong length=reads.Value(wrappers+0x18);Expect(length<=1000000,"other-head hotfix array bound");
            foreach(int id in new int[]{0x1c6,0x139,0x1c5,0x12b,0x1bf})
                OtherContext(!HotfixEntry(reads,wrappers,length,id),"original path hotfix 0x"+id.ToString("x"));
            PlayerObjectResult head=new PlayerObjectResult { LocalPlayer=member.Address,PlayerClass=member.Class };
            Action<string> note=progress==null ? (Action<string>)null : delegate(string text){progress("OtherHeadProgress Index="+rosterIndex+" "+text);};
            ResolveManagedPlayerHead(reads,game,module,layout,head,profile,wrappers,length,note);
            sample.Provider=head.HeadProvider;sample.Transform=head.HeadTransform;sample.Source=head.HeadSource;
            try { ReadNativeHeadPosition(game,module,head,note); }
            catch(NativeHeadMotionException error){head.HeadWorldStatus="NOT_READY_MOTION";head.HeadWorldError=error.Message;}
            finally { sample.Attempts=head.HeadSampleAttempts; }
            Recheck(kernel,game);byte[] finalCounters=OtherCounterAudit(game,core,member,"AFTER");
            sample.CountersChangedDuringCapture=!EqualBytes(counters,finalCounters);
            int finalNext=BitConverter.ToInt32(entry,4);Expect(finalNext>=-1 && finalNext<BitConverter.ToUInt32(finalCounters,0),"other-head selected final link bound");
            int observations=reads.Recheck();Recheck(kernel,game);
            sample.MembershipProof="SELECTED_ENTRY_REVALIDATED";
            sample.Status=head.HeadWorldStatus=="SAMPLED_READ_ONLY" ? head.HeadWorldStatus : head.HeadStatus!="MANAGED_TRANSFORM_VERIFIED" ? head.HeadStatus : head.HeadWorldStatus;
            sample.Detail=head.HeadWorldError;sample.ParentCount=head.HeadParentCount;sample.Observations=observations+head.HeadWorldObservations;
            if(sample.Status=="SAMPLED_READ_ONLY"){sample.X=head.HeadWorldX;sample.Y=head.HeadWorldY;sample.Z=head.HeadWorldZ;}
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
            ObjectReads schema=new ObjectReads(this,game.Root);
            List<OtherHeadObservation> samples=new List<OtherHeadObservation>();result.StopReason="SELECTED_OBJECTS_EXHAUSTED";
            using(PhysicalCallScope(totalAllowance))
            {
                try
                {
                    using(PhysicalCallScope(allowance))
                    {
                        OtherHeadCode(kernel,game,module);OtherHeadSchema(schema,game,module,layout,core);
                        for(int i=0;i<core.MatchPlayers.Length;i++)
                        {
                            MatchPlayerObservation member=core.MatchPlayers[i];if(member.IsLocal)continue;
                            if(samples.Count==2){result.StopReason="TWO_OBJECT_LIMIT";break;}
                            if(progress!=null)progress("OtherHeadCandidate Index="+i+" Class="+member.Class+" Player=0x"+member.Address.ToString("x"));
                            OtherHeadObservation sample=new OtherHeadObservation { RosterIndex=i,Player=member.Address,Class=member.Class };
                            try { ReadOtherHead(kernel,game,module,layout,core,member,i,sample,progress); }
                            catch(PhysicalScopeLimitException error)
                            { sample.Status="READ_LIMIT_REACHED";sample.Detail=error.Message;samples.Add(sample);result.StopReason="READ_LIMIT_REACHED";break; }
                            catch(OtherHeadContextException error)
                            { sample.Status="NOT_READY_CONTEXT_CHANGED";sample.Detail=error.Message;samples.Add(sample);result.StopReason="CONTEXT_CHANGED";break; }
                            catch(ObjectObservationChangedException error)
                            { bool membership=error.Label.StartsWith("OtherMembership.",StringComparison.Ordinal);sample.Status=membership?"NOT_READY_CONTEXT_CHANGED":"FAIL";
                              sample.Detail=error.Message;samples.Add(sample);result.StopReason=membership?"CONTEXT_CHANGED":"SAMPLE_FAILED";break; }
                            catch(Exception error)
                            { sample.Status="FAIL";sample.Detail=error.Message;samples.Add(sample);result.StopReason="SAMPLE_FAILED";break; }
                            samples.Add(sample);
                        }
                    }
                }
                catch(PhysicalScopeLimitException error){result.StopReason="READ_LIMIT_REACHED";result.Detail=error.Message;}
                catch(OtherHeadContextException error){result.StopReason="CONTEXT_CHANGED";result.Detail=error.Message;return result;}
                catch(Exception error){result.StopReason="FAIL";result.Detail=error.Message;return result;}
                // The inner scope is disposed. The outer phase scope still caps
                // total additional calls at 6000, with 1000 reserved for final checks.
                try { schema.Recheck();OtherHeadCode(kernel,game,module); }
                catch(Exception error){result.StopReason="FINAL_CONTEXT_FAILED";result.Detail=error.Message;return result;}
                result.Samples=samples.ToArray();foreach(OtherHeadObservation sample in result.Samples)if(sample.Status=="SAMPLED_READ_ONLY")result.Sampled++;
                return result;
            }
        }
    }
}
