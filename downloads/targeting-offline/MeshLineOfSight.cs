using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Targeting
{
    internal static class Geometry
    {
        internal static Vector Add(Vector a, Vector b) { return new Vector(a.X+b.X,a.Y+b.Y,a.Z+b.Z); }
        internal static Vector Scale(Vector a, double k) { return new Vector(a.X*k,a.Y*k,a.Z*k); }
        internal static Vector Cross(Vector a, Vector b) { return new Vector(a.Y*b.Z-a.Z*b.Y,a.Z*b.X-a.X*b.Z,a.X*b.Y-a.Y*b.X); }
        internal static double Axis(Vector v,int axis) { return axis==0?v.X:axis==1?v.Y:v.Z; }
        internal static bool Bounded(Vector v) { return v.Finite && Math.Abs(v.X)<=1e8 && Math.Abs(v.Y)<=1e8 && Math.Abs(v.Z)<=1e8; }
        internal static Vector Min(Vector a,Vector b) { return new Vector(Math.Min(a.X,b.X),Math.Min(a.Y,b.Y),Math.Min(a.Z,b.Z)); }
        internal static Vector Max(Vector a,Vector b) { return new Vector(Math.Max(a.X,b.X),Math.Max(a.Y,b.Y),Math.Max(a.Z,b.Z)); }
    }

    public sealed class Triangle
    {
        public readonly Vector A,B,C;
        internal readonly Box Bounds;
        internal readonly Vector Centroid;
        public Triangle(Vector a,Vector b,Vector c)
        {
            if(!Geometry.Bounded(a)||!Geometry.Bounded(b)||!Geometry.Bounded(c))throw new ArgumentException("Triangle coordinates outside numeric domain");
            double area=Geometry.Cross(b-a,c-a).Length;
            if(!Vector.Valid(area)||area<1e-12)throw new ArgumentException("Degenerate triangle");
            A=a;B=b;C=c;
            // Conservative bounds padding includes near-boundary intersection uncertainty.
            Vector pad=new Vector(1e-6,1e-6,1e-6);
            Bounds=new Box(Geometry.Min(a,Geometry.Min(b,c))-pad,Geometry.Add(Geometry.Max(a,Geometry.Max(b,c)),pad));
            Centroid=Geometry.Scale(Geometry.Add(a,Geometry.Add(b,c)),1.0/3);
        }
        // Segment/triangle intersection, two-sided. Near-parallel/coplanar candidates
        // are Unknown, never silently classified as unobstructed.
        internal Proof Trace(Vector origin,Vector end)
        {
            if(!Bounds.Intersects(origin,end))return Proof.Yes;
            Vector delta=end-origin,e1=B-A,e2=C-A,p=Geometry.Cross(delta,e2);
            double determinant=Vector.Dot(e1,p),scale=e1.Length*e2.Length*delta.Length;
            if(!Vector.Valid(scale)||Math.Abs(determinant)<=1e-12*Math.Max(1,scale))return Proof.Unknown;
            Vector t=origin-A;double u=Vector.Dot(t,p)/determinant;
            Vector q=Geometry.Cross(t,e1);double v=Vector.Dot(delta,q)/determinant,along=Vector.Dot(e2,q)/determinant;
            const double tolerance=1e-9;
            if(u < -tolerance || v < -tolerance || u+v > 1+tolerance || along < -tolerance || along > 1+tolerance)return Proof.Yes;
            return Proof.No;
        }
    }

    public sealed class LosReport
    {
        public readonly Proof Result;
        public readonly string Reason;
        public readonly int NodesVisited,TrianglesTested;
        internal LosReport(Proof result,string reason,int nodes,int triangles)
        { Result=result;Reason=reason;NodesVisited=nodes;TrianglesTested=triangles; }
    }

    // Immutable BVH over a host-supplied collision snapshot. No inferred game geometry.
    public sealed class MeshLineOfSight : ILineOfSight
    {
        private sealed class Node { internal Box Bounds;internal Node Left,Right;internal int Start,Count; }
        private sealed class CentroidOrder : IComparer<Triangle>
        {
            private readonly int axis;internal CentroidOrder(int axis){this.axis=axis;}
            public int Compare(Triangle a,Triangle b){return Geometry.Axis(a.Centroid,axis).CompareTo(Geometry.Axis(b.Centroid,axis));}
        }
        private readonly string session;
        private readonly long sequence;
        private readonly bool complete;
        private readonly Triangle[] triangles;
        private readonly Node root;
        private readonly int maxNodes,maxTriangles;
        public MeshLineOfSight(string session,long sequence,bool completeGeometry,Triangle[] geometry,int maxNodes,int maxTriangleTests)
        {
            if(string.IsNullOrWhiteSpace(session)||sequence<0||geometry==null||geometry.Length>100000||maxNodes<1||maxTriangleTests<1)throw new ArgumentException("Invalid mesh snapshot or budget");
            this.session=session;this.sequence=sequence;complete=completeGeometry;this.maxNodes=maxNodes;maxTriangles=maxTriangleTests;
            triangles=(Triangle[])geometry.Clone();foreach(Triangle t in triangles)if(t==null)throw new ArgumentException("Null triangle");
            if(triangles.Length>0)root=Build(0,triangles.Length);
        }
        private Node Build(int start,int count)
        {
            Vector min=triangles[start].Bounds.Min,max=triangles[start].Bounds.Max;
            for(int i=start+1;i<start+count;i++){min=Geometry.Min(min,triangles[i].Bounds.Min);max=Geometry.Max(max,triangles[i].Bounds.Max);}
            var node=new Node {Bounds=new Box(min,max),Start=start,Count=count};
            if(count<=8)return node;
            Vector size=max-min;int axis=size.X>=size.Y&&size.X>=size.Z?0:size.Y>=size.Z?1:2;
            Array.Sort(triangles,start,count,new CentroidOrder(axis));int half=count/2;
            node.Left=Build(start,half);node.Right=Build(start+half,count-half);node.Count=0;return node;
        }
        public Proof Query(Frame frame,Target target){return Inspect(frame,target).Result;}
        public LosReport Inspect(Frame frame,Target target)
        {
            if(frame==null||target==null||frame.Session!=session||frame.Sequence!=sequence)return Report(Proof.Unknown,"SNAPSHOT_MISMATCH",0,0);
            if(!complete)return Report(Proof.Unknown,"INCOMPLETE_GEOMETRY",0,0);
            if(!Geometry.Bounded(frame.Origin)||!Geometry.Bounded(target.Head)||(target.Head-frame.Origin).Length<1e-9)return Report(Proof.Unknown,"INVALID_SEGMENT",0,0);
            if(root==null)return Report(Proof.Yes,"EMPTY_COMPLETE_GEOMETRY",0,0);
            int nodes=0,tests=0;bool uncertain=false;var stack=new Stack<Node>();stack.Push(root);
            while(stack.Count>0)
            {
                if(nodes>=maxNodes)return Report(Proof.Unknown,"NODE_BUDGET",nodes,tests);
                Node n=stack.Pop();nodes++;if(!n.Bounds.Intersects(frame.Origin,target.Head))continue;
                if(n.Left!=null){stack.Push(n.Right);stack.Push(n.Left);continue;}
                for(int i=n.Start;i<n.Start+n.Count;i++)
                {
                    if(tests>=maxTriangles)return Report(Proof.Unknown,"TRIANGLE_BUDGET",nodes,tests);
                    Proof hit=triangles[i].Trace(frame.Origin,target.Head);tests++;
                    if(hit==Proof.No)return Report(Proof.No,"OCCLUDED",nodes,tests);
                    if(hit==Proof.Unknown)uncertain=true;
                }
            }
            return Report(uncertain?Proof.Unknown:Proof.Yes,uncertain?"NUMERIC_UNCERTAINTY":"CLEAR",nodes,tests);
        }
        private static LosReport Report(Proof proof,string reason,int nodes,int tests){return new LosReport(proof,reason,nodes,tests);}
    }
}
