namespace HitLab;
public readonly record struct Vec(double X, double Y, double Z)
{
    public bool Finite => double.IsFinite(X) && double.IsFinite(Y) && double.IsFinite(Z);
    public double Length => Math.Sqrt(Dot(this, this));
    public Vec Unit() { if (!Finite || Length < 1e-9 || Length > 1e6) throw new ArgumentException("Invalid direction"); return this / Length; }
    public static Vec operator +(Vec a, Vec b) => new(a.X+b.X,a.Y+b.Y,a.Z+b.Z);
    public static Vec operator -(Vec a, Vec b) => new(a.X-b.X,a.Y-b.Y,a.Z-b.Z);
    public static Vec operator *(Vec a, double t) => new(a.X*t,a.Y*t,a.Z*t);
    public static Vec operator /(Vec a, double t) => a*(1/t);
    public static double Dot(Vec a, Vec b) => a.X*b.X+a.Y*b.Y+a.Z*b.Z;
    public static Vec Cross(Vec a, Vec b) => new(a.Y*b.Z-a.Z*b.Y,a.Z*b.X-a.X*b.Z,a.X*b.Y-a.Y*b.X);
}
public readonly record struct Rotation(double X, double Y, double Z, double W)
{
    public Vec Apply(Vec v)
    {
        double n=X*X+Y*Y+Z*Z+W*W;
        if (!double.IsFinite(n) || Math.Abs(n-1)>1e-9) throw new ArgumentException("Unit quaternion required");
        Vec q=new(X,Y,Z); Vec t=Vec.Cross(q,v)*2;
        return v+t*W+Vec.Cross(q,t);
    }
    public static Rotation Identity => new(0,0,0,1);
}
public enum Region { Head, Chest, Shoulder, Stomach, Arm, Leg }
public sealed record Hitbox(Region Region, Vec Center, double Radius);
public sealed record Collision(Region Region, double Distance, Vec Point);
public static class Geometry
{
    // Finite hitscan ray against a sphere; includes an origin inside the volume.
    public static double? RaySphere(Vec origin, Vec direction, Hitbox box, double range)
    {
        if(!origin.Finite || !box.Center.Finite || !double.IsFinite(box.Radius) || box.Radius<=0 || !double.IsFinite(range) || range<=0 || range>1e6) throw new ArgumentException("Invalid collision bounds");
        var d=direction.Unit(); var m=origin-box.Center; double c=Vec.Dot(m,m)-box.Radius*box.Radius;
        if (c<=0) return 0;
        double b=Vec.Dot(m,d), disc=b*b-c;
        if (disc<0) return null;
        double t=-b-Math.Sqrt(disc);
        return t>=0 && t<=range ? t : null;
    }
    public static Collision? First(Vec origin, Vec direction, IEnumerable<Hitbox> boxes, double range)
    {
        var d=direction.Unit(); Collision? best=null;
        foreach (var box in boxes)
        {
            var t=RaySphere(origin,d,box,range);
            if (t.HasValue && (best is null || t.Value<best.Distance)) best=new(box.Region,t.Value,origin+d*t.Value);
        }
        return best;
    }
    // Piecewise linear ballistic approximation, for owned offline experiments only.
    public static (Collision Hit,double Time)? Projectile(Vec origin, Vec velocity, Vec gravity, double duration, double step, Hitbox[] boxes)
    {
        if (!origin.Finite || !velocity.Finite || !gravity.Finite || !double.IsFinite(duration) || !double.IsFinite(step) || duration<=0 || duration>10 || step<0.001 || step>duration) throw new ArgumentException("Invalid ballistic bounds");
        double time=0; Vec previous=origin;
        while (time<duration)
        {
            double next=Math.Min(duration,time+step); Vec point=origin+velocity*next+gravity*(0.5*next*next); var delta=point-previous;
            if (delta.Length>1e-9)
            {
                var hit=First(previous,delta,boxes,delta.Length);
                if(hit is not null) return(hit,time+(next-time)*hit.Distance/delta.Length);
            }
            previous=point;time=next;
        }
        return null;
    }
}
