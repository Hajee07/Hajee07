using System;
using HeadBridge.Mapping.Targeting;

// Independent plane/rectangle oracle: choose local x/y coordinates first, then
// rotate and translate the whole synthetic scene. No triangle intersection code
// is used to obtain the expected answer. No game geometry is inferred.
public static class TiltedGeometryTests
{
    private static Vector Add(Vector a,Vector b){return new Vector(a.X+b.X,a.Y+b.Y,a.Z+b.Z);}
    private static Vector Scale(Vector v,double k){return new Vector(v.X*k,v.Y*k,v.Z*k);}
    public static void Run()
    {
        Random random=new Random(52);
        for(int i=0;i<300;i++)
        {
            double alpha=random.NextDouble()*2*Math.PI,beta=random.NextDouble()*Math.PI;
            double ca=Math.Cos(alpha),sa=Math.Sin(alpha),cb=Math.Cos(beta),sb=Math.Sin(beta);
            Vector u=new Vector(ca*cb,sa*cb,-sb),v=new Vector(-sa,ca,0),n=new Vector(ca*sb,sa*sb,cb);
            Vector center=new Vector(random.NextDouble()*200-100,random.NextDouble()*200-100,random.NextDouble()*200-100);
            double x,y;
            do{x=random.NextDouble()*6-3;y=random.NextDouble()*6-3;}while(Math.Abs(Math.Abs(x)-1)<0.02||Math.Abs(Math.Abs(y)-1)<0.02);
            Vector a=Add(center,Add(Scale(u,-1),Scale(v,-1))),b=Add(center,Add(u,Scale(v,-1)));
            Vector c=Add(center,Add(u,v)),d=Add(center,Add(Scale(u,-1),v));
            Vector onPlane=Add(center,Add(Scale(u,x),Scale(v,y)));
            Vector origin=Add(onPlane,Scale(n,-5)),end=Add(onPlane,Scale(n,5));
            Target target=new Target("synthetic",end,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes);
            Frame frame=new Frame("tilted-simulation",i,0,origin,n,Proof.Yes,new[]{target});
            MeshLineOfSight mesh=new MeshLineOfSight("tilted-simulation",i,true,new[]{new Triangle(a,b,c),new Triangle(a,c,d)},64,64);
            Proof expected=Math.Abs(x)<1&&Math.Abs(y)<1?Proof.No:Proof.Yes;
            if(mesh.Query(frame,target)!=expected)throw new Exception("Tilted rectangle oracle failed case "+i);
        }
        Console.WriteLine("TILTED TOTAL 300 assertions passed; independent synthetic rectangle coordinates, rotated and translated");
    }
}
