using System;
using System.Collections.Generic;

// Separate, engine-independent extension. No game memory reads or writes.
namespace HeadBridge.Mapping.Targeting
{
    public enum Proof { Unknown, No, Yes }
    public struct Vector
    {
        public readonly double X, Y, Z;
        public Vector(double x, double y, double z) { X=x; Y=y; Z=z; }
        public bool Finite { get { return Valid(X)&&Valid(Y)&&Valid(Z); } }
        internal static bool Valid(double n) { return !double.IsNaN(n)&&!double.IsInfinity(n); }
        public static Vector operator -(Vector a,Vector b) { return new Vector(a.X-b.X,a.Y-b.Y,a.Z-b.Z); }
        public double Length { get { return Math.Sqrt(X*X+Y*Y+Z*Z); } }
        public Vector Unit() { double n=Length; if(!Finite||!Valid(n)||n<1e-9) throw new ArgumentException("Invalid direction"); return new Vector(X/n,Y/n,Z/n); }
        internal static double Dot(Vector a,Vector b) { return a.X*b.X+a.Y*b.Y+a.Z*b.Z; }
    }
    public sealed class Target
    {
        public readonly string Id;
        public readonly Vector Head;
        public readonly Proof Identity, HeadVerified, Alive, Hostile, Attackable;
        public Target(string id,Vector head,Proof identity,Proof headVerified,Proof alive,Proof hostile,Proof attackable)
        { Id=id;Head=head;Identity=identity;HeadVerified=headVerified;Alive=alive;Hostile=hostile;Attackable=attackable; }
    }
    public sealed class Frame
    {
        public readonly string Session;
        public readonly long Sequence, CapturedAt;
        public readonly Vector Origin, Forward;
        public readonly Proof CameraVerified;
        private readonly Target[] targets;
        public Frame(string session,long sequence,long capturedAt,Vector origin,Vector forward,Proof cameraVerified,Target[] candidates)
        { Session=session;Sequence=sequence;CapturedAt=capturedAt;Origin=origin;Forward=forward;CameraVerified=cameraVerified;targets=candidates==null?null:(Target[])candidates.Clone(); }
        internal Target[] Targets { get { return targets; } }
    }
    public sealed class Box
    {
        public readonly Vector Min, Max;
        public Box(Vector min,Vector max)
        { if(!min.Finite||!max.Finite||min.X>max.X||min.Y>max.Y||min.Z>max.Z)throw new ArgumentException("Invalid box");Min=min;Max=max; }
        internal bool Intersects(Vector origin,Vector end)
        {
            Vector d=end-origin;double near=0,far=1;
            return Slab(origin.X,d.X,Min.X,Max.X,ref near,ref far)&&Slab(origin.Y,d.Y,Min.Y,Max.Y,ref near,ref far)&&Slab(origin.Z,d.Z,Min.Z,Max.Z,ref near,ref far);
        }
        private static bool Slab(double o,double d,double min,double max,ref double near,ref double far)
        {
            if(d==0)return o>=min&&o<=max;
            double a=(min-o)/d,b=(max-o)/d;
            if(a>b){double t=a;a=b;b=t;}near=Math.Max(near,a);far=Math.Min(far,b);return near<=far;
        }
    }
    public interface ILineOfSight { Proof Query(Frame frame,Target target); }
    // Only meaningful for a host supplying complete, matching collision geometry.
    // Never substitute game model-visibility flags for CompleteGeometry.
    public sealed class BoxLineOfSight : ILineOfSight
    {
        private readonly string session;private readonly long sequence;private readonly bool complete;private readonly Box[] boxes;
        public BoxLineOfSight(string session,long sequence,bool completeGeometry,Box[] obstacles)
        {
            this.session=session;this.sequence=sequence;complete=completeGeometry;
            boxes=obstacles==null?null:(Box[])obstacles.Clone();
        }
        public Proof Query(Frame frame,Target target)
        {
            if(frame==null||target==null||!complete||boxes==null||frame.Session!=session||frame.Sequence!=sequence||!frame.Origin.Finite||!target.Head.Finite)return Proof.Unknown;
            foreach(Box box in boxes){if(box==null)return Proof.Unknown;if(box.Intersects(frame.Origin,target.Head))return Proof.No;}
            return Proof.Yes;
        }
    }
    public sealed class Decision
    {
        public readonly string Status,TargetId;
        public readonly Vector Direction;
        internal Decision(string status,string id,Vector direction){Status=status;TargetId=id;Direction=direction;}
    }
    public sealed class Controller
    {
        private readonly double maxDistance,maxAngle;private readonly long maxAge;
        private string session;private long lastSequence=-1,lastTime=-1;
        // now/capturedAt use one host-owned monotonic clock, in milliseconds.
        public Controller(double maxDistance,double maxAngleDegrees,long maxAgeMilliseconds)
        {
            if(!Vector.Valid(maxDistance)||maxDistance<=0||!Vector.Valid(maxAngleDegrees)||maxAngleDegrees<=0||maxAngleDegrees>180||maxAgeMilliseconds<=0)throw new ArgumentException("Invalid policy");
            this.maxDistance=maxDistance;maxAngle=maxAngleDegrees;maxAge=maxAgeMilliseconds;
        }
        // One automatic update per new frame. Output is a direction only.
        // No orientation conversion or live-game actuator is assumed.
        public Decision Step(Frame frame,long now,bool enabled,ILineOfSight los)
        {
            if(!enabled)return Stop("DISABLED");
            if(frame==null||string.IsNullOrWhiteSpace(frame.Session)||frame.Sequence<0||frame.CapturedAt<0||now<frame.CapturedAt||now-frame.CapturedAt>maxAge)return Stop("STALE_OR_INVALID_FRAME");
            if(session!=null&&session!=frame.Session)return Stop("SESSION_CHANGED_RECREATE_CONTROLLER");
            if(frame.Sequence<=lastSequence||frame.CapturedAt<lastTime)return Stop("REPLAYED_FRAME");
            session=frame.Session;lastSequence=frame.Sequence;lastTime=frame.CapturedAt;
            if(frame.CameraVerified!=Proof.Yes||!frame.Origin.Finite||!frame.Forward.Finite||frame.Targets==null||frame.Targets.Length>256||los==null)return Stop("UNVERIFIED_CONTEXT");
            Vector forward;try{forward=frame.Forward.Unit();}catch(ArgumentException){return Stop("INVALID_FORWARD");}
            var ids=new HashSet<string>(StringComparer.Ordinal);
            foreach(Target t in frame.Targets)if(t==null||string.IsNullOrWhiteSpace(t.Id)||!ids.Add(t.Id))return Stop("INVALID_TARGET_IDENTITIES");
            Target best=null;Vector direction=new Vector();double bestAngle=double.MaxValue,bestDistance=double.MaxValue;
            foreach(Target t in frame.Targets)
            {
                if(t.Identity!=Proof.Yes||t.HeadVerified!=Proof.Yes||t.Alive!=Proof.Yes||t.Hostile!=Proof.Yes||t.Attackable!=Proof.Yes||!t.Head.Finite)continue;
                Vector delta=t.Head-frame.Origin;double distance=delta.Length;
                if(!Vector.Valid(distance)||distance<1e-9||distance>maxDistance)continue;
                Vector unit=delta.Unit();double angle=Math.Acos(Math.Max(-1,Math.Min(1,Vector.Dot(forward,unit))))*180/Math.PI;
                if(angle>maxAngle)continue;
                Proof visible;try{visible=los.Query(frame,t);}catch{return Stop("LOS_PROVIDER_FAILED");}
                if(visible!=Proof.Yes)continue;
                if(best==null||angle<bestAngle||(angle==bestAngle&&(distance<bestDistance||(distance==bestDistance&&StringComparer.Ordinal.Compare(t.Id,best.Id)<0))))
                {best=t;direction=unit;bestAngle=angle;bestDistance=distance;}
            }
            return best==null?Stop("NO_VERIFIED_TARGET"):new Decision("DIRECTION_READY",best.Id,direction);
        }
        private static Decision Stop(string status){return new Decision(status,null,new Vector());}
    }
}
