using System;
namespace HeadBridge.Mapping.Targeting
{
    public static class Tests
    {
        private static int count;
        private static void Check(bool ok,string name){if(!ok)throw new Exception(name);count++;Console.WriteLine("PASS "+name);}
        private static Target T(string id,double x,double z,Proof alive,Proof hostile){return new Target(id,new Vector(x,0,z),Proof.Yes,Proof.Yes,alive,hostile,Proof.Yes);}
        private static Frame F(long seq,params Target[] targets){return new Frame("fixture",seq,100,new Vector(0,0,0),new Vector(0,0,1),Proof.Yes,targets);}
        private static BoxLineOfSight Clear(long seq){return new BoxLineOfSight("fixture",seq,true,new Box[0]);}
        private static Controller C(){return new Controller(100,30,100);}
        public static void Run()
        {
            count=0;Target a=T("a",0,10,Proof.Yes,Proof.Yes);Frame f=F(1,a);
            Check(C().Step(f,100,true,Clear(1)).TargetId=="a","verified target accepted");
            var wall=new Box(new Vector(-1,-1,4),new Vector(1,1,6));
            Check(C().Step(f,100,true,new BoxLineOfSight("fixture",1,true,new[]{wall})).TargetId==null,"wall blocks target");
            Check(C().Step(f,100,true,new BoxLineOfSight("fixture",1,false,new Box[0])).TargetId==null,"incomplete geometry fails closed");
            Check(C().Step(f,100,true,Clear(2)).TargetId==null,"LOS snapshot mismatch");
            Check(C().Step(F(1,T("a",0,10,Proof.Unknown,Proof.Yes)),100,true,Clear(1)).TargetId==null,"unknown life rejected");
            Check(C().Step(F(1,T("a",0,10,Proof.Yes,Proof.Unknown)),100,true,Clear(1)).TargetId==null,"unknown hostility rejected");
            Check(C().Step(f,201,true,Clear(1)).TargetId==null,"stale snapshot rejected");
            Check(C().Step(f,99,true,Clear(1)).TargetId==null,"future snapshot rejected");
            Check(C().Step(f,100,false,Clear(1)).Status=="DISABLED","disabled controller");
            Controller c=C();c.Step(f,100,true,Clear(1));Check(c.Step(f,100,true,Clear(1)).Status=="REPLAYED_FRAME","replay rejected");
            Check(C().Step(F(1,T("a",20,1,Proof.Yes,Proof.Yes)),100,true,Clear(1)).TargetId==null,"outside angle rejected");
            Check(C().Step(F(1,T("a",0,101,Proof.Yes,Proof.Yes)),100,true,Clear(1)).TargetId==null,"outside distance rejected");
            Check(C().Step(F(1,a,a),100,true,Clear(1)).Status=="INVALID_TARGET_IDENTITIES","duplicate identity rejected");
            Check(C().Step(F(1,T("z",0,10,Proof.Yes,Proof.Yes),a),100,true,Clear(1)).TargetId=="a","deterministic tie break");
            Check(C().Step(F(1,T("near",0,5,Proof.Yes,Proof.Yes),a),100,true,Clear(1)).TargetId=="near","distance tie break");
            Check(C().Step(F(1,T("invalid",double.NaN,10,Proof.Yes,Proof.Yes)),100,true,Clear(1)).TargetId==null,"nonfinite coordinate rejected");
            Check(new BoxLineOfSight("fixture",1,true,new[]{new Box(new Vector(-1,-1,20),new Vector(1,1,21))}).Query(f,a)==Proof.Yes,"obstacle beyond target ignored");
            Check(new BoxLineOfSight("fixture",1,true,new[]{new Box(new Vector(2,-1,4),new Vector(3,1,6))}).Query(f,a)==Proof.Yes,"parallel segment outside wall clear");
            Decision d=C().Step(f,100,true,Clear(1));Check(Math.Abs(d.Direction.Length-1)<1e-12,"unit direction output");
            Frame next=F(2,T("new",1,10,Proof.Yes,Proof.Yes));Check(c.Step(next,100,true,Clear(2)).TargetId=="new","next frame updates automatically");
            Console.WriteLine("TOTAL "+count+" passed; synthetic geometry only; live integration NOT_TESTED");
        }
    }
}
