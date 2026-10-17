using System.Diagnostics;
namespace HitLab;
public enum ClassificationPolicy { Geometric, AllValidatedHitsAreHeadshots }
public sealed record LabConfig(ClassificationPolicy Policy, bool Wall=false, int DelayMs=0);
public sealed record Shot(Guid Session, long Sequence, Vec Direction, Region? ClaimedRegion);
public sealed record Receipt(bool Accepted, string Reason, Region? GeometricRegion, Region? AwardedRegion, Region? ClientClaim, bool? ClaimMatchesGeometry, int Damage, string SceneRevision);
public sealed record Scene(Vec Origin, Hitbox[] Boxes, double Range, bool Wall, string Revision);
public sealed class Authority
{
    private sealed class Session { public long Sequence; public long Created=Stopwatch.GetTimestamp(); }
    private readonly Dictionary<Guid,Session> sessions=new();
    private readonly object gate=new();
    public LabConfig Config { get; }
    public Scene Scene { get; }
    public Authority(LabConfig config, Vec? targetPosition=null, Rotation? targetRotation=null)
    {
        if(!Enum.IsDefined(config.Policy)) throw new ArgumentException("Invalid classification policy");
        if(config.DelayMs<0||config.DelayMs>1000) throw new ArgumentException("Delay must be 0..1000ms");
        Config=config;
        var boxes=new[] {
            new Hitbox(Region.Head,new(0,1.95,0),0.16),new Hitbox(Region.Chest,new(0,1.48,0),0.21),
            new Hitbox(Region.Shoulder,new(0.45,1.63,0),0.13),new Hitbox(Region.Stomach,new(0,1.03,0),0.18),
            new Hitbox(Region.Arm,new(0.78,1.16,0),0.14),new Hitbox(Region.Leg,new(0.24,0.44,0),0.19)};
        var offset=targetPosition??new Vec(0,0,0); if(!offset.Finite)throw new ArgumentException("Invalid target position"); var rotation=targetRotation??Rotation.Identity;
        Scene=new(new(0,1.2,-6),boxes.Select(b=>b with{Center=rotation.Apply(b.Center)+offset}).ToArray(),100,config.Wall,"owned-static-v1");
    }
    public Guid OpenSession()
    {
        lock(gate)
        {
            foreach(var expiredId in sessions.Where(p=>Stopwatch.GetElapsedTime(p.Value.Created)>TimeSpan.FromMinutes(5)).Select(p=>p.Key).ToArray()) sessions.Remove(expiredId);
            if(sessions.Count>=1000) throw new InvalidOperationException("Lab session limit reached");
            var id=Guid.NewGuid();sessions.Add(id,new());return id;
        }
    }
    public Receipt Submit(Shot shot)
    {
        Receipt Reject(string why)=>new(false,why,null,null,shot.ClaimedRegion,null,0,Scene.Revision);
        lock(gate)
        {
            if(!sessions.TryGetValue(shot.Session,out var session)||Stopwatch.GetElapsedTime(session.Created)>TimeSpan.FromMinutes(5))return Reject("UNKNOWN_OR_EXPIRED_SESSION");
            if(shot.Sequence<=session.Sequence)return Reject("REPLAY_OR_OUT_OF_ORDER");
            // Consume sequence even for a miss or invalid intent; it cannot be replayed for damage.
            session.Sequence=shot.Sequence;
            if(shot.ClaimedRegion.HasValue&&!Enum.IsDefined(shot.ClaimedRegion.Value))return Reject("INVALID_CLAIM");
            if(!shot.Direction.Finite||shot.Direction.Length<1e-9||shot.Direction.Length>1e6)return Reject("INVALID_DIRECTION");
            var direction=shot.Direction.Unit();var collision=Geometry.First(Scene.Origin,direction,Scene.Boxes,Scene.Range);
            if(collision is null)return Reject("MISS");
            // Owned wall is z=-2 and spans the whole lab firing field.
            double wallDistance=direction.Z>1e-9?(-2-Scene.Origin.Z)/direction.Z:double.PositiveInfinity;
            if(Scene.Wall&&wallDistance>=0&&wallDistance<collision.Distance)return Reject("OCCLUDED");
            Region award=Config.Policy==ClassificationPolicy.AllValidatedHitsAreHeadshots?Region.Head:collision.Region;
            return new(true,"SERVER_VALIDATED",collision.Region,award,shot.ClaimedRegion,shot.ClaimedRegion.HasValue?shot.ClaimedRegion.Value==collision.Region:null,award==Region.Head?100:25,Scene.Revision);
        }
    }
}
