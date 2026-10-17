using System;
using System.Collections.Generic;
using HeadBridge.Mapping.Targeting;

namespace HeadBridge.IntegrationReview
{
    // Providers must establish each proof independently. This layer never derives
    // hostility from team IDs, lifetime from an address, or LOS from visibility flags.
    public sealed class TargetObservation
    {
        public readonly string ObjectId, Bone;
        public readonly long Generation;
        public readonly Vector Head;
        public readonly Proof Identity, Nonlocal, Hostile, Alive, Attackable, Membership, HeadIdentity, WorldSpace, NotDying, NotReviving, NotSpectator;
        public TargetObservation(string id,long generation,string bone,Vector head,Proof identity,Proof nonlocal,
            Proof hostile,Proof alive,Proof attackable,Proof membership,Proof headIdentity,Proof worldSpace,
            Proof notDying,Proof notReviving,Proof notSpectator)
        { ObjectId=id;Generation=generation;Bone=bone;Head=head;Identity=identity;Nonlocal=nonlocal;Hostile=hostile;
          Alive=alive;Attackable=attackable;Membership=membership;HeadIdentity=headIdentity;WorldSpace=worldSpace;NotDying=notDying;NotReviving=notReviving;NotSpectator=notSpectator; }
    }
    public sealed class ObservationBatch
    {
        public readonly string Epoch, Session;
        public readonly long Sequence, StartedAt, FinishedAt;
        public readonly Proof Coherent, CompleteRoster, Camera;
        public readonly Vector Origin, Forward;
        private readonly TargetObservation[] targets;
        public TargetObservation[] Targets { get { return targets==null?null:(TargetObservation[])targets.Clone(); } }
        public ObservationBatch(string epoch,string session,long sequence,long started,long finished,Proof coherent,
            Proof completeRoster,Proof camera,Vector origin,Vector forward,TargetObservation[] targets)
        { Epoch=epoch;Session=session;Sequence=sequence;StartedAt=started;FinishedAt=finished;Coherent=coherent;
          CompleteRoster=completeRoster;Camera=camera;Origin=origin;Forward=forward;if(targets!=null&&targets.Length>4096)throw new ArgumentException("Observation capacity");this.targets=targets==null?null:(TargetObservation[])targets.Clone(); }
    }
    public sealed class HeadSample
    {
        public readonly string Key;
        public readonly Vector Measured;
        public readonly long StartedAt, FinishedAt, Sequence;
        public HeadSample(string key,Vector measured,long started,long finished,long sequence)
        {Key=key;Measured=measured;StartedAt=started;FinishedAt=finished;Sequence=sequence;}
    }
    public sealed class TargetAssessment
    {
        public readonly TargetObservation Observation;
        public readonly Proof Eligibility;
        public readonly string Reason;
        internal TargetAssessment(TargetObservation observation,Proof proof,string reason)
        {Observation=observation;Eligibility=proof;Reason=reason;}
    }
    public sealed class ValidationResult
    {
        public readonly string Status;
        public readonly Proof Eligibility;
        public readonly Frame Frame;
        public readonly int Accepted, Rejected, Gaps;
        public readonly long OldestAge, CaptureUncertainty;
        private readonly TargetAssessment[] assessments;
        public TargetAssessment[] Assessments {get{return (TargetAssessment[])assessments.Clone();}}
        internal ValidationResult(string status,Proof eligibility,Frame frame,int accepted,int rejected,int gaps,long age,long uncertainty,TargetAssessment[] assessments)
        {Status=status;Eligibility=eligibility;Frame=frame;Accepted=accepted;Rejected=rejected;Gaps=gaps;OldestAge=age;CaptureUncertainty=uncertainty;this.assessments=(TargetAssessment[])assessments.Clone();}
    }
    public sealed class ObservationPipeline
    {
        private readonly int maxTargets;
        private readonly long maxAge, maxUncertainty;
        private string epoch,session;
        private long sequence=-1,finished=-1,lastNow=-1;
        private Dictionary<string,HeadSample> samples=new Dictionary<string,HeadSample>(StringComparer.Ordinal);
        public ObservationPipeline(int maxTargets,long maxAge,long maxUncertainty)
        {if(maxTargets<1||maxTargets>4096||maxAge<1||maxAge>60000||maxUncertainty<0||maxUncertainty>maxAge)throw new ArgumentException();
         this.maxTargets=maxTargets;this.maxAge=maxAge;this.maxUncertainty=maxUncertainty;}
        private static string Part(string s){return s.Length+":"+s;}
        public static string Key(string epoch,string session,string id,long generation)
        {return Part(epoch)+Part(session)+Part(id)+":"+generation.ToString(System.Globalization.CultureInfo.InvariantCulture);}
        public void Reset(){samples.Clear();epoch=null;session=null;sequence=-1;finished=-1;lastNow=-1;}
        private ValidationResult Fail(string status,Proof proof)
        {int gaps=samples.Count;samples.Clear();return new ValidationResult(status,proof,null,0,0,gaps,0,0,new TargetAssessment[0]);}
        private static Proof All(params Proof[] facts)
        {bool unknown=false;foreach(Proof p in facts){if(p==Proof.No)return Proof.No;if(p!=Proof.Yes)unknown=true;}return unknown?Proof.Unknown:Proof.Yes;}
        public ValidationResult Accept(ObservationBatch b,long now)
        {
            if(now<0||now<lastNow)return Fail("CLOCK_INVALID",Proof.Unknown);
            lastNow=now;
            if(b==null||string.IsNullOrWhiteSpace(b.Epoch)||string.IsNullOrWhiteSpace(b.Session)||b.Epoch.Length>256||b.Session.Length>256||b.Sequence<0||
               b.StartedAt<0||b.FinishedAt<b.StartedAt||b.FinishedAt>now)return Fail("INVALID_BATCH",Proof.Unknown);
            if(epoch!=null&&(epoch!=b.Epoch||session!=b.Session))return Fail("CONTEXT_CHANGED_RESET_REQUIRED",Proof.Unknown);
            if(b.Sequence<=sequence||b.FinishedAt<finished)return Fail("REPLAY_OR_TIME_REVERSAL",Proof.Unknown);
            epoch=b.Epoch;session=b.Session;sequence=b.Sequence;finished=b.FinishedAt;
            if(now-b.StartedAt>maxAge)return Fail("STALE",Proof.Unknown);
            if(b.FinishedAt-b.StartedAt>maxUncertainty)return Fail("CAPTURE_UNCERTAINTY",Proof.Unknown);
            Proof context=All(b.Coherent,b.CompleteRoster,b.Camera);
            if(context!=Proof.Yes)return Fail("CONTEXT_UNVERIFIED",context);
            if(!b.Origin.Finite||!b.Forward.Finite||(double.IsInfinity(b.Forward.Length)||b.Forward.Length<1e-9))return Fail("CAMERA_INVALID",Proof.Unknown);
            TargetObservation[] items=b.Targets;
            if(items==null||items.Length>maxTargets)return Fail("CANDIDATE_BOUND",Proof.Unknown);
            var ids=new HashSet<string>(StringComparer.Ordinal);
            foreach(TargetObservation t in items)
                if(t==null||string.IsNullOrWhiteSpace(t.ObjectId)||t.ObjectId.Length>256||t.Generation<0||!ids.Add(t.ObjectId))return Fail("IDENTITY_AMBIGUOUS",Proof.Unknown);
            var outcomes=new List<TargetAssessment>();
            var next=new Dictionary<string,HeadSample>(StringComparer.Ordinal);var targets=new List<Target>();int rejected=0;bool unknown=false;
            foreach(TargetObservation t in items)
            {
                Proof proof=All(t.Identity,t.Nonlocal,t.Hostile,t.Alive,t.Attackable,t.Membership,t.HeadIdentity,t.WorldSpace,t.NotDying,t.NotReviving,t.NotSpectator);
                if(proof!=Proof.Yes||!t.Head.Finite||string.IsNullOrWhiteSpace(t.Bone)||t.Bone.Length>128)
                {rejected++;if(proof!=Proof.No)unknown=true;
                 outcomes.Add(new TargetAssessment(t,proof==Proof.Yes?Proof.Unknown:proof,proof==Proof.Yes?"INVALID_HEAD_SAMPLE":"STATE_NOT_VERIFIED"));continue;}
                outcomes.Add(new TargetAssessment(t,Proof.Yes,"VERIFIED_BY_PROVIDER"));
                string key=Key(epoch,session,t.ObjectId,t.Generation);
                next.Add(key,new HeadSample(key,t.Head,b.StartedAt,b.FinishedAt,b.Sequence));
                targets.Add(new Target(key,t.Head,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes));
            }
            int gaps=0;foreach(string key in samples.Keys)if(!next.ContainsKey(key))gaps++;
            samples=next;
            var frame=new Frame(Key(epoch,session,"context",0),sequence,b.StartedAt,b.Origin,b.Forward,Proof.Yes,targets.ToArray());
            return new ValidationResult("ACCEPTED",unknown?Proof.Unknown:rejected>0?Proof.No:Proof.Yes,frame,targets.Count,rejected,gaps,now-b.StartedAt,b.FinishedAt-b.StartedAt,outcomes.ToArray());
        }
        // Real hosts should use this overload to recheck time after bounded validation.
        public ValidationResult Accept(ObservationBatch batch,IMonotonicClock clock)
        {
            if(clock==null)return Fail("CLOCK_MISSING",Proof.Unknown);
            try
            {
                long before=clock.Milliseconds;ValidationResult result=Accept(batch,before);
                long after=clock.Milliseconds;
                if(after<before||after<lastNow)return Fail("CLOCK_INVALID",Proof.Unknown);
                lastNow=after;
                if(result.Frame!=null&&(after-batch.StartedAt>maxAge||after-before>Math.Min(8,maxAge)))
                    return Fail("POST_VALIDATION_TIME_BUDGET",Proof.Unknown);
                return result;
            }
            catch{return Fail("CLOCK_EXCEPTION",Proof.Unknown);}
        }
        // Every access checks age; stale samples are removed, never interpolated.
        public HeadSample Sample(string key,long now)
        {
            if(string.IsNullOrWhiteSpace(key))return null;
            HeadSample value;
            if(now<lastNow){samples.Clear();return null;}
            lastNow=now;
            if(!samples.TryGetValue(key,out value))return null;
            if(now<value.FinishedAt||now-value.StartedAt>maxAge){samples.Remove(key);return null;}
            return value;
        }
    }
}
