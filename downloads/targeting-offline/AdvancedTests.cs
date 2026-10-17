using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Targeting
{
    public static class AdvancedTests
    {
        private static int count;
        private static void Check(bool yes,string name){if(!yes)throw new Exception("FAIL "+name);count++;Console.WriteLine("PASS "+name);}
        private sealed class Clock : IMonotonicClock
        {
            internal long Now=100;internal bool Throw;
            public long Milliseconds {get{if(Throw)throw new Exception("clock");return Now;}}
        }
        private sealed class Los : ILineOfSight
        {
            internal Func<Frame,Target,Proof> Handler=delegate{return Proof.Yes;};
            public Proof Query(Frame f,Target t){return Handler(f,t);}
        }
        private sealed class Authority : IFrameAuthority
        {
            internal bool Valid=true;internal Action OnCheck;
            public bool IsCurrent(Frame f,string target){if(OnCheck!=null)OnCheck();return Valid;}
        }
        private sealed class Output : IAimOutput
        {
            internal bool ThrowApply,ThrowClear,Reject;
            internal int Applied,Cleared;internal AimCommand Last;internal Func<AimCommand,bool> Validate;
            public bool TryApply(AimCommand c){if(ThrowApply)throw new Exception("output");if(Reject||(Validate!=null&&!Validate(c)))return false;Applied++;Last=c;return true;}
            public void Clear(UpdateStatus reason){if(ThrowClear)throw new Exception("clear");Cleared++;Last=null;}
        }
        private static Target T(string id,double x,double z){return new Target(id,new Vector(x,0,z),Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes);}
        private static Frame F(long seq,long time,params Target[] targets){return new Frame("test",seq,time,new Vector(),new Vector(0,0,1),Proof.Yes,targets);}
        private static TargetingPolicy Policy(int confirms,int rays,double margin){return new TargetingPolicy(100,60,0,margin,90,100,8,256,rays,confirms);}
        private static Triangle Wall(double x,double z){return new Triangle(new Vector(x-2,-2,z),new Vector(x+2,-2,z),new Vector(x,2,z));}
        private static MeshLineOfSight Mesh(Triangle[] triangles,int nodes,int tests){return new MeshLineOfSight("test",1,true,triangles,nodes,tests);}
        private static AdvancedDecision Run(Frame f,Los los,Clock clock){return new AdvancedController(Policy(1,16,0.1),clock).Step(f,true,los);}
        public static void Run()
        {
            count=0;Target a=T("a",0,10);Frame f=F(1,100,a);var clock=new Clock();var los=new Los();
            Check(Mesh(new[]{Wall(0,5)},100,100).Query(f,a)==Proof.No,"mesh blocks ray");
            Check(Mesh(new[]{Wall(10,5)},100,100).Query(f,a)==Proof.Yes,"mesh ray misses");
            Check(Mesh(new[]{Wall(0,20)},100,100).Query(f,a)==Proof.Yes,"mesh beyond endpoint ignored");
            Triangle triangle=Wall(0,5);
            Check(Mesh(new[]{new Triangle(triangle.C,triangle.B,triangle.A)},100,100).Query(f,a)==Proof.No,"two-sided triangle");
            Check(Mesh(new Triangle[0],100,100).Query(f,a)==Proof.Yes,"complete empty mesh");
            Check(new MeshLineOfSight("test",1,false,new Triangle[0],100,100).Query(f,a)==Proof.Unknown,"incomplete mesh unknown");
            Check(Mesh(new[]{triangle},100,100).Query(F(2,100,a),a)==Proof.Unknown,"mesh rejects stale sequence");
            Frame plane=new Frame("test",1,100,new Vector(0,0,5),new Vector(1,0,0),Proof.Yes,new[]{T("p",1,5)});
            Target p=T("p",1,5);
            Check(Mesh(new[]{triangle},100,100).Query(plane,p)==Proof.Unknown,"coplanar uncertainty");
            Check(Mesh(new[]{triangle,triangle},100,1).Inspect(plane,p).Reason=="TRIANGLE_BUDGET","triangle work ceiling");
            var many=new List<Triangle>();many.Add(triangle);for(int i=0;i<100;i++)many.Add(Wall(10+i*5,5));
            Check(Mesh(many.ToArray(),1,1000).Inspect(f,a).Reason=="NODE_BUDGET","BVH node ceiling");
            LosReport report=Mesh(many.ToArray(),1000,1000).Inspect(f,a);
            Check(report.Result==Proof.No&&report.TrianglesTested<many.Count,"BVH prunes unrelated triangles");
            bool bad=false;try{new Triangle(new Vector(),new Vector(),new Vector());}catch(ArgumentException){bad=true;}Check(bad,"degenerate triangle rejected");
            Triangle[] original={triangle};MeshLineOfSight immutable=Mesh(original,100,100);original[0]=Wall(10,5);Check(immutable.Query(f,a)==Proof.No,"mesh array defensive copy");
            Check(Run(f,los,clock).Status==UpdateStatus.Ready,"advanced verified target");
            Check(Run(new Frame("test",1,100,new Vector(),new Vector(0,0,1),Proof.Unknown,new[]{a}),los,clock).Status==UpdateStatus.InvalidCamera,"unknown camera rejected");
            Check(Run(F(1,100,new Target("a",a.Head,Proof.Yes,Proof.Unknown,Proof.Yes,Proof.Yes,Proof.Yes)),los,clock).Status==UpdateStatus.NoEligibleTarget,"unknown head rejected");
            Check(Run(F(1,100,new Target("a",a.Head,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Unknown)),los,clock).Status==UpdateStatus.NoEligibleTarget,"unknown attackability rejected");
            Check(Run(F(1,100,new Target("a",a.Head,Proof.Unknown,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes)),los,clock).Status==UpdateStatus.NoEligibleTarget,"unknown identity rejected");
            Check(Run(F(1,100,a,a),los,clock).Status==UpdateStatus.InvalidIdentities,"duplicate advanced identities");
            var unknown=new Los {Handler=delegate{return Proof.Unknown;}};
            Check(Run(f,unknown,clock).Status==UpdateStatus.NoVisibleTarget,"unknown LOS rejected");
            Check(new AdvancedController(Policy(1,1,0.1),clock).Step(F(1,100,a,T("b",1,10)),true,unknown).Status==UpdateStatus.RayBudget,"ray ceiling fails closed");
            var throws=new Los {Handler=delegate{throw new Exception("ray");}};
            Check(Run(f,throws,clock).Status==UpdateStatus.LosFailed,"LOS exception contained");
            var slow=new Los {Handler=delegate{clock.Now=109;return Proof.Yes;}};
            Check(Run(f,slow,clock).Status==UpdateStatus.TimeBudget,"post-LOS deadline enforced");clock.Now=100;
            var stale=new Los {Handler=delegate{clock.Now=201;return Proof.Yes;}};
            Check(Run(f,stale,clock).Status==UpdateStatus.StaleFrame,"post-LOS stale observation rejected");clock.Now=100;
            var reverse=new Los {Handler=delegate{clock.Now=99;return Proof.Yes;}};
            Check(Run(f,reverse,clock).Status==UpdateStatus.ClockFailure,"clock regression rejected");clock.Now=100;
            var controller=new AdvancedController(Policy(2,16,0.1),clock);
            Check(controller.Step(f,true,los).Status==UpdateStatus.Acquiring,"first observation confirmation");
            clock.Now=116;Check(controller.Step(F(2,116,a),true,los).Status==UpdateStatus.Ready,"second observation confirms");
            Check(controller.Step(F(2,116,a),true,los).Status==UpdateStatus.Replay,"advanced replay rejection");
            clock.Now=132;Check(controller.Step(F(3,132,a),true,los).Status==UpdateStatus.Acquiring,"replay resets acquisition");
            controller.Step(null,false,null);clock.Now=148;Check(controller.Step(F(4,148,a),true,los).Status==UpdateStatus.Acquiring,"disable resets acquisition");
            clock.Now=100;controller=new AdvancedController(Policy(1,16,0.1),clock);
            Check(controller.Step(F(1,100,T("held",1,10)),true,los).TargetId=="held","initial held target");
            clock.Now=116;Check(controller.Step(F(2,116,T("held",1,10),a),true,los).TargetId=="held","hysteresis prevents small switch");
            clock.Now=132;Check(controller.Step(F(3,132,T("held",8,10),a),true,los).TargetId=="a","large improvement switches target");
            clock.Now=148;var blocked=new Los {Handler=delegate(Frame fr,Target t){return t.Id=="a"?Proof.No:Proof.Yes;}};
            Check(controller.Step(F(4,148,a,T("b",1,10)),true,blocked).TargetId=="b","held target LOS revalidated");
            clock.Now=100;AdvancedDecision turn=Run(F(1,100,T("turn",5,10)),los,clock);
            double angle=Math.Acos(Math.Max(-1,Math.Min(1,turn.Direction.Z)))*180/Math.PI;
            Check(angle<=90*0.016+1e-9&&angle>0,"angular rate limit");
            Check(Math.Abs(turn.Direction.Length-1)<1e-12,"smoothed direction normalized");
            Vector anti=AdvancedController.RotateTowards(new Vector(0,0,1),new Vector(0,0,-1),0.1);
            Check(anti.Finite&&Math.Abs(anti.Length-1)<1e-12&&Math.Abs(anti.Z-Math.Cos(0.1))<1e-12,"antiparallel direction stable");
            var authority=new Authority();var output=new Output();var coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(f,true,los)==UpdateStatus.Applied&&output.Applied==1,"bound simulator receives command");
            Check(output.Last.ExpiresAt==200&&output.Last.Sequence==1&&output.Last.Session=="test","command carries expiry and observation identity");
            Check(coordinator.Update(null,false,null)==UpdateStatus.Disabled&&output.Last==null,"disable revokes command");
            output=new Output();authority.Valid=false;coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(f,true,los)==UpdateStatus.ContextChanged&&output.Applied==0&&output.Cleared==1,"commit-time context rejection");authority.Valid=true;
            authority.OnCheck=delegate{clock.Now=109;};coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(f,true,los)==UpdateStatus.TimeBudget&&output.Applied==0,"authority time included in deadline");authority.OnCheck=null;clock.Now=100;
            output=new Output {Reject=true};coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(f,true,los)==UpdateStatus.OutputRejected&&output.Cleared==1,"adapter rejection revokes");
            output=new Output {ThrowApply=true};coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(f,true,los)==UpdateStatus.OutputFault,"adapter fault contained");output.ThrowApply=false;clock.Now=116;
            Check(coordinator.Update(F(2,116,a),true,los)==UpdateStatus.OutputFault&&output.Applied==0,"adapter fault remains latched");coordinator.ResetFault();
            Check(coordinator.Update(F(2,116,a),true,los)==UpdateStatus.Applied,"explicit adapter recovery");
            output=new Output {ThrowClear=true};coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(null,false,null)==UpdateStatus.OutputFault,"revocation failure reported");
            clock.Now=100;output=new Output {Validate=delegate(AimCommand command){clock.Now=201;return clock.Now<=command.ExpiresAt;}};
            coordinator=new AimCoordinator(Policy(1,16,0.1),clock,authority,output);
            Check(coordinator.Update(f,true,los)==UpdateStatus.OutputRejected&&output.Applied==0,"host rejects expiry at actual application");clock.Now=100;
            clock.Throw=true;Check(Run(f,los,clock).Status==UpdateStatus.ClockFailure,"clock exception contained");clock.Throw=false;
            clock.Now=100;controller=new AdvancedController(Policy(1,16,0.1),clock);controller.Step(f,true,los);
            clock.Now=99;Check(controller.Step(F(2,99,a),true,los).Status==UpdateStatus.ClockFailure,"clock regression between updates");clock.Now=100;
            controller=new AdvancedController(Policy(1,16,0.1),clock);controller.Step(f,true,los);
            Check(controller.Step(new Frame("other",2,100,new Vector(),new Vector(0,0,1),Proof.Yes,new[]{a}),true,los).Status==UpdateStatus.SessionChanged,"session change requires new controller");
            Check(Run(F(1,101,a),los,clock).Status==UpdateStatus.ClockFailure,"future advanced observation rejected");
            clock.Now=201;Check(Run(f,los,clock).Status==UpdateStatus.StaleFrame,"stale advanced observation rejected");clock.Now=100;
            controller=new AdvancedController(Policy(1,16,0.1),clock);controller.Step(f,true,los);clock.Now=116;
            Target dead=new Target("a",a.Head,Proof.Yes,Proof.Yes,Proof.No,Proof.Yes,Proof.Yes);
            Check(controller.Step(F(2,116,dead),true,los).Status==UpdateStatus.NoEligibleTarget,"held target life revalidated");
            clock.Now=100;controller=new AdvancedController(Policy(2,16,0.1),clock);controller.Step(f,true,los);clock.Now=116;
            Check(controller.Step(F(2,116,a),true,unknown).Status==UpdateStatus.NoVisibleTarget,"confirmation interrupted by unknown LOS");clock.Now=132;
            Check(controller.Step(F(3,132,a),true,los).Status==UpdateStatus.Acquiring,"interrupted confirmation must restart");
            clock.Now=100;Target[] targets={a};Frame copied=F(1,100,targets);targets[0]=dead;
            Check(Run(copied,los,clock).Status==UpdateStatus.Ready,"frame array defensive copy");
            Check(Run(F(1,100,new Target[0]),los,clock).Status==UpdateStatus.NoEligibleTarget,"empty target set");
            bad=false;try{new TargetingPolicy(100,60,0,0,90,100,8,2,3,1);}catch(ArgumentException){bad=true;}Check(bad,"ray budget cannot exceed candidate budget");
            // Independent analytic rectangle oracle for randomized non-edge rays.
            // No reuse of the triangle algorithm to compute the expected result.
            var rectangle=new[]{new Triangle(new Vector(-1,-1,5),new Vector(1,-1,5),new Vector(1,1,5)),new Triangle(new Vector(-1,-1,5),new Vector(1,1,5),new Vector(-1,1,5))};
            var rng=new Random(49);var mesh=Mesh(rectangle,100,100);
            for(int i=0;i<200;i++)
            {
                double x=rng.NextDouble()*12-6,y=rng.NextDouble()*12-6;
                Target target=new Target("random",new Vector(x,y,10),Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes);
                bool hit=Math.Abs(x/2)<1&&Math.Abs(y/2)<1;
                Check(mesh.Query(f,target)==(hit?Proof.No:Proof.Yes),"analytic rectangle oracle "+i);
            }
            Console.WriteLine("ADVANCED TOTAL "+count+" assertions passed; synthetic only; live game integration NOT_TESTED");
        }
    }
}
