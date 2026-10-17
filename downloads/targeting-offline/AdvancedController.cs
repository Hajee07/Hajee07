using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace HeadBridge.Mapping.Targeting
{
    public interface IMonotonicClock { long Milliseconds { get; } }
    public sealed class MonotonicClock : IMonotonicClock
    {
        private readonly Stopwatch timer=Stopwatch.StartNew();
        public long Milliseconds { get { return timer.ElapsedMilliseconds; } }
    }
    public sealed class TargetingPolicy
    {
        public readonly double MaxDistance,MaxAngle,DistanceWeight,SwitchMargin,DegreesPerSecond;
        public readonly long MaxAgeMilliseconds,MaxComputeMilliseconds;
        public readonly int MaxCandidates,MaxRays,ConfirmFrames;
        public TargetingPolicy(double maxDistance,double maxAngle,double distanceWeight,double switchMargin,double degreesPerSecond,long maxAgeMilliseconds,long maxComputeMilliseconds,int maxCandidates,int maxRays,int confirmFrames)
        {
            if(!Vector.Valid(maxDistance)||maxDistance<=0||maxDistance>1e8||!Vector.Valid(maxAngle)||maxAngle<=0||maxAngle>180||
               !Vector.Valid(distanceWeight)||distanceWeight<0||distanceWeight>1||!Vector.Valid(switchMargin)||switchMargin<0||switchMargin>1||
               !Vector.Valid(degreesPerSecond)||degreesPerSecond<=0||degreesPerSecond>3600||maxAgeMilliseconds<1||maxAgeMilliseconds>60000||
               maxComputeMilliseconds<1||maxComputeMilliseconds>maxAgeMilliseconds||maxCandidates<1||maxCandidates>4096||maxRays<1||maxRays>maxCandidates||confirmFrames<1||confirmFrames>120)
                throw new ArgumentException("Invalid targeting policy");
            MaxDistance=maxDistance;MaxAngle=maxAngle;DistanceWeight=distanceWeight;SwitchMargin=switchMargin;DegreesPerSecond=degreesPerSecond;
            MaxAgeMilliseconds=maxAgeMilliseconds;MaxComputeMilliseconds=maxComputeMilliseconds;MaxCandidates=maxCandidates;MaxRays=maxRays;ConfirmFrames=confirmFrames;
        }
        public static TargetingPolicy Default { get { return new TargetingPolicy(100,30,0.1,0.08,180,100,8,256,16,2); } }
    }
    public enum UpdateStatus
    {
        Ready,Disabled,InvalidFrame,StaleFrame,SessionChanged,Replay,InvalidCamera,InvalidIdentities,
        NoEligibleTarget,NoVisibleTarget,LosFailed,RayBudget,TimeBudget,ClockFailure,Acquiring,
        ContextChanged,OutputRejected,OutputFault,Applied
    }
    public sealed class AdvancedDecision
    {
        public readonly UpdateStatus Status;
        public readonly string TargetId;
        public readonly Vector Direction;
        public readonly int Eligible,Rejected,Rays;
        public readonly long Sequence;
        internal AdvancedDecision(UpdateStatus status,string id,Vector direction,int eligible,int rejected,int rays,long sequence)
        { Status=status;TargetId=id;Direction=direction;Eligible=eligible;Rejected=rejected;Rays=rays;Sequence=sequence; }
    }
    public sealed class AdvancedController
    {
        private sealed class Candidate { internal Target Target;internal Vector Direction;internal double Score,Distance; }
        private readonly TargetingPolicy policy;
        private readonly IMonotonicClock clock;
        private string session,held,pending;
        private long sequence=-1,captured=-1,lastClock=-1;
        private int confirmations;
        public AdvancedController(TargetingPolicy policy,IMonotonicClock clock)
        { if(policy==null||clock==null)throw new ArgumentNullException();this.policy=policy;this.clock=clock; }
        public void ClearTracking(){held=null;pending=null;confirmations=0;}
        private AdvancedDecision Stop(UpdateStatus status,int eligible,int rejected,int rays)
        { ClearTracking();return new AdvancedDecision(status,null,new Vector(),eligible,rejected,rays,sequence); }
        private UpdateStatus? CheckTime(Frame frame,long start)
        {
            long now;try{now=clock.Milliseconds;}catch{return UpdateStatus.ClockFailure;}
            if(now<start||now<frame.CapturedAt||now<lastClock)return UpdateStatus.ClockFailure;
            lastClock=now;
            if(now-frame.CapturedAt>policy.MaxAgeMilliseconds)return UpdateStatus.StaleFrame;
            if(now-start>policy.MaxComputeMilliseconds)return UpdateStatus.TimeBudget;
            return null;
        }
        // Host serializes calls. No target or LOS data is cached across observations.
        public AdvancedDecision Step(Frame frame,bool enabled,ILineOfSight los)
        {
            if(!enabled)return Stop(UpdateStatus.Disabled,0,0,0);
            long start;try{start=clock.Milliseconds;}catch{return Stop(UpdateStatus.ClockFailure,0,0,0);}
            if(start<lastClock)return Stop(UpdateStatus.ClockFailure,0,0,0);
            lastClock=start;
            if(start<0||frame==null||string.IsNullOrWhiteSpace(frame.Session)||frame.Sequence<0||frame.CapturedAt<0||frame.CapturedAt>long.MaxValue-policy.MaxAgeMilliseconds||frame.Targets==null||frame.Targets.Length>policy.MaxCandidates||los==null)
                return Stop(UpdateStatus.InvalidFrame,0,0,0);
            UpdateStatus? time=CheckTime(frame,start);if(time.HasValue)return Stop(time.Value,0,0,0);
            if(session!=null&&session!=frame.Session)return Stop(UpdateStatus.SessionChanged,0,0,0);
            if(frame.Sequence<=sequence||frame.CapturedAt<captured)return Stop(UpdateStatus.Replay,0,0,0);
            double dt=captured<0?0.016:Math.Min(0.05,(frame.CapturedAt-captured)/1000.0);
            session=frame.Session;sequence=frame.Sequence;captured=frame.CapturedAt;
            if(frame.CameraVerified!=Proof.Yes||!Geometry.Bounded(frame.Origin)||!Geometry.Bounded(frame.Forward))return Stop(UpdateStatus.InvalidCamera,0,0,0);
            Vector forward;try{forward=frame.Forward.Unit();}catch(ArgumentException){return Stop(UpdateStatus.InvalidCamera,0,0,0);}
            var ids=new HashSet<string>(StringComparer.Ordinal);var candidates=new List<Candidate>();int rejected=0;
            foreach(Target t in frame.Targets)
            {
                if(t==null||string.IsNullOrWhiteSpace(t.Id)||!ids.Add(t.Id))return Stop(UpdateStatus.InvalidIdentities,0,0,0);
                if(t.Identity!=Proof.Yes||t.HeadVerified!=Proof.Yes||t.Alive!=Proof.Yes||t.Hostile!=Proof.Yes||t.Attackable!=Proof.Yes||!Geometry.Bounded(t.Head)){rejected++;continue;}
                Vector delta=t.Head-frame.Origin;double distance=delta.Length;
                if(distance<1e-9||distance>policy.MaxDistance){rejected++;continue;}
                Vector direction=delta.Unit();double angle=Math.Acos(Math.Max(-1,Math.Min(1,Vector.Dot(forward,direction))))*180/Math.PI;
                if(angle>policy.MaxAngle){rejected++;continue;}
                candidates.Add(new Candidate {Target=t,Direction=direction,Distance=distance,Score=angle/policy.MaxAngle+policy.DistanceWeight*distance/policy.MaxDistance});
            }
            candidates.Sort(delegate(Candidate a,Candidate b){int order=a.Score.CompareTo(b.Score);if(order!=0)return order;order=a.Distance.CompareTo(b.Distance);return order!=0?order:StringComparer.Ordinal.Compare(a.Target.Id,b.Target.Id);});
            time=CheckTime(frame,start);if(time.HasValue)return Stop(time.Value,candidates.Count,rejected,0);
            if(candidates.Count==0)return Stop(UpdateStatus.NoEligibleTarget,0,rejected,0);
            // Keep the current target only while independently eligible in this frame
            // and the challenger does not improve its score beyond the switch margin.
            for(int i=1;i<candidates.Count;i++)if(candidates[i].Target.Id==held&&candidates[i].Score-candidates[0].Score<=policy.SwitchMargin)
            { Candidate retained=candidates[i];candidates.RemoveAt(i);candidates.Insert(0,retained);break; }
            int rays=0;Candidate selected=null;
            foreach(Candidate candidate in candidates)
            {
                time=CheckTime(frame,start);if(time.HasValue)return Stop(time.Value,candidates.Count,rejected,rays);
                if(rays>=policy.MaxRays)return Stop(UpdateStatus.RayBudget,candidates.Count,rejected,rays);
                Proof proof;try{proof=los.Query(frame,candidate.Target);rays++;}catch{return Stop(UpdateStatus.LosFailed,candidates.Count,rejected,rays);}
                time=CheckTime(frame,start);if(time.HasValue)return Stop(time.Value,candidates.Count,rejected,rays);
                if(proof==Proof.Yes){selected=candidate;break;}
            }
            if(selected==null)return Stop(UpdateStatus.NoVisibleTarget,candidates.Count,rejected,rays);
            if(selected.Target.Id!=held)
            {
                if(pending==selected.Target.Id)confirmations++;else{pending=selected.Target.Id;confirmations=1;}
                if(confirmations<policy.ConfirmFrames)return new AdvancedDecision(UpdateStatus.Acquiring,null,new Vector(),candidates.Count,rejected,rays,sequence);
                held=selected.Target.Id;pending=null;confirmations=0;
            }
            else {pending=null;confirmations=0;}
            Vector output=RotateTowards(forward,selected.Direction,policy.DegreesPerSecond*dt*Math.PI/180);
            time=CheckTime(frame,start);if(time.HasValue)return Stop(time.Value,candidates.Count,rejected,rays);
            return new AdvancedDecision(UpdateStatus.Ready,held,output,candidates.Count,rejected,rays,sequence);
        }
        internal static Vector RotateTowards(Vector from,Vector to,double maxRadians)
        {
            double dot=Math.Max(-1,Math.Min(1,Vector.Dot(from,to))),angle=Math.Acos(dot);
            if(angle<=maxRadians||angle<1e-12)return to;
            Vector perpendicular=to-Geometry.Scale(from,dot);
            if(perpendicular.Length<1e-9)
            { Vector axis=Math.Abs(from.X)<0.8?new Vector(1,0,0):new Vector(0,1,0);perpendicular=Geometry.Cross(from,axis); }
            perpendicular=perpendicular.Unit();
            return Geometry.Add(Geometry.Scale(from,Math.Cos(maxRadians)),Geometry.Scale(perpendicular,Math.Sin(maxRadians))).Unit();
        }
    }
}
