using System;
using System.Threading;
using HeadBridge.Mapping.Targeting;

namespace HeadBridge.IntegrationReview
{
    public static class ReviewTests
    {
        private sealed class Clock : IMonotonicClock {public long Now;public long Milliseconds {get{return Now;}}}
        private sealed class AdvancingClock : IMonotonicClock
        {private long time=10;public long Milliseconds {get{long value=time;time+=20;return value;}}}
        private static int checks;
        private static void Check(bool ok,string name){checks++;if(!ok)throw new Exception(name);}
        private static TargetObservation Target(string id,long generation,Vector head,Proof[] facts)
        {return new TargetObservation(id,generation,"bone_Head",head,facts[0],facts[1],facts[2],facts[3],facts[4],facts[5],facts[6],facts[7],facts[8],facts[9],facts[10]);}
        private static Proof[] Yes(){return new[]{Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes};}
        private static TargetObservation Good(long generation){return Target("entity",generation,new Vector(1,0,10),Yes());}
        private static ObservationBatch Batch(long sequence,long time,TargetObservation[] targets,string epoch="process-1",string session="match-1",Proof coherent=Proof.Yes,Proof roster=Proof.Yes,Proof camera=Proof.Yes,long uncertainty=0)
        {return new ObservationBatch(epoch,session,sequence,time,time+uncertainty,coherent,roster,camera,new Vector(),new Vector(0,0,1),targets);}
        private static ObservationPipeline Pipeline(){return new ObservationPipeline(16,100,10);}
        private static string Key(long gen){return ObservationPipeline.Key("process-1","match-1","entity",gen);}
        private static TargetingPolicy Policy(){return new TargetingPolicy(100,30,.1,.08,180,100,8,16,16,2);}
        private static void Validation()
        {
            for(int fact=0;fact<11;fact++)foreach(Proof proof in new[]{Proof.Unknown,Proof.No})
            {
                var facts=Yes();facts[fact]=proof;var p=Pipeline();
                ValidationResult r=p.Accept(Batch(1,10,new[]{Target("entity",1,new Vector(1,0,10),facts)}),10);
                Check(r.Accepted==0&&r.Rejected==1,"individual proof rejected "+fact);
                Check(r.Eligibility==proof&&r.Assessments[0].Eligibility==proof,"proof preserved "+fact);
                Check(p.Sample(Key(1),10)==null,"no rejected head cached");
            }
            var delayed=Pipeline();
            Check(delayed.Accept(Batch(1,10,new[]{Good(1)}),new AdvancingClock()).Status=="POST_VALIDATION_TIME_BUDGET","expensive validation rejected");
            Check(delayed.Sample(Key(1),30)==null,"post-validation failure clears heads");
            var pipe=Pipeline();var first=pipe.Accept(Batch(1,10,new[]{Good(1)}),12);
            Check(first.Accepted==1&&first.OldestAge==2&&first.CaptureUncertainty==0,"age measured");
            Console.WriteLine("HEAD synthetic oldestAge="+first.OldestAge+" uncertainty="+first.CaptureUncertainty+" accepted="+first.Accepted);
            Check(pipe.Sample(Key(1),12).Measured.X==1,"sample measured");
            var moved=Target("entity",1,new Vector(2,3,12),Yes());
            Check(pipe.Accept(Batch(2,20,new[]{moved}),20).Accepted==1,"movement accepted");
            Check(pipe.Sample(Key(1),20).Measured.X==2,"movement not interpolation");
            Check(pipe.Accept(Batch(3,30,new[]{Good(2)}),30).Gaps==1,"generation invalidates old");
            Check(pipe.Sample(Key(1),30)==null&&pipe.Sample(Key(2),30)!=null,"address reuse reacquires generation");
            Check(pipe.Accept(Batch(4,40,new TargetObservation[0]),40).Gaps==1,"despawn gap");
            Check(pipe.Sample(Key(2),40)==null,"despawn removes sample");
            Check(pipe.Accept(Batch(5,50,new[]{Good(2)}),50).Accepted==1,"reacquire");
            Check(pipe.Sample(Key(2),151)==null,"stale lookup invalidates");
            Check(pipe.Accept(Batch(6,60,new[]{Good(2)}),152).Accepted==1,"fresh oldest-age boundary");
            Check(pipe.Accept(Batch(6,60,new[]{Good(2)}),152).Frame==null,"replay rejected");
            Check(pipe.Sample(Key(2),152)==null,"failure clears previous head");
            Check(pipe.Accept(Batch(7,160,new[]{Good(2)},"process-2"),160).Status=="CONTEXT_CHANGED_RESET_REQUIRED","restart needs reset");
            pipe.Reset();Check(pipe.Accept(Batch(1,170,new[]{Good(1)},"process-2"),170).Accepted==1,"explicit new context");
            Check(ObservationPipeline.Key("ab","c","d",1)!=ObservationPipeline.Key("a","bc","d",1),"identity delimiters");
            Check(Pipeline().Accept(Batch(1,0,new[]{Good(1)},uncertainty:11),11).Status=="CAPTURE_UNCERTAINTY","uncertainty rejected");
            Check(Pipeline().Accept(Batch(1,1,new[]{Good(1)}),102).Status=="STALE","stale batch");
            Check(Pipeline().Accept(Batch(1,20,new[]{Good(1)}),10).Frame==null,"future rejected");
            Check(Pipeline().Accept(Batch(1,1,new[]{Good(1),Good(2)}),1).Status=="IDENTITY_AMBIGUOUS","duplicate object IDs");
            foreach(Proof proof in new[]{Proof.No,Proof.Unknown})
            {
                Check(Pipeline().Accept(Batch(1,1,new[]{Good(1)},coherent:proof),1).Frame==null,"coherence proof");
                Check(Pipeline().Accept(Batch(1,1,new[]{Good(1)},roster:proof),1).Frame==null,"complete roster proof");
                Check(Pipeline().Accept(Batch(1,1,new[]{Good(1)},camera:proof),1).Frame==null,"active camera proof");
            }
            var unknownBone=new TargetObservation("entity",1,"",new Vector(),Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes);
            Check(Pipeline().Accept(Batch(1,1,new[]{unknownBone}),1).Accepted==0,"missing bone");
            Check(Pipeline().Accept(Batch(1,1,new[]{Target("entity",1,new Vector(double.NaN,0,1),Yes())}),1).Accepted==0,"invalid head");
            var arr=new[]{Good(1)};var batch=Batch(1,1,arr);arr[0]=null;batch.Targets[0]=null;
            Check(Pipeline().Accept(batch,1).Accepted==1,"batch copies provider array");
            var many=new TargetObservation[17];for(int i=0;i<many.Length;i++)many[i]=Target("id"+i,1,new Vector(0,0,10),Yes());
            Check(Pipeline().Accept(Batch(1,1,many),1).Status=="CANDIDATE_BOUND","candidate budget");
        }
        private static void AdapterAndSimulation()
        {
            var clock=new Clock();var pipe=Pipeline();
            using(var output=new ExpiringCommandLease(clock,100,0))
            {
                var coordinator=new AimCoordinator(Policy(),clock,output,output);output.Enable(true);
                AimCommand previous=null;
                for(int seq=1;seq<=3;seq++)
                {
                    clock.Now=seq*16;var r=pipe.Accept(Batch(seq,clock.Now,new[]{Good(1)}),clock.Now);
                    Check(output.Publish(r),"publish");
                    var obstacles=seq==3?new[]{new Box(new Vector(-2,-2,5),new Vector(2,2,6))}:new Box[0];
                    var los=new BoxLineOfSight(r.Frame.Session,seq,true,obstacles);
                    UpdateStatus status=coordinator.Update(r.Frame,true,los);
                    Console.WriteLine("SIMULATION sequence="+seq+" status="+status+" stored="+(output.Snapshot!=null));
                    Check(seq==1?status==UpdateStatus.Acquiring:seq==2?status==UpdateStatus.Applied:status==UpdateStatus.NoVisibleTarget,"scenario state");
                    if(seq==2){previous=output.Snapshot;Check(previous!=null,"local lease applied");
                        double angle=Math.Acos(Math.Max(-1,Math.Min(1,previous.Direction.Z)))*180/Math.PI;
                        Check(angle<=180*.016+1e-6,"angular change bounded");}
                    if(seq==3)Check(output.Snapshot==null,"obstruction revokes");
                }
                clock.Now=64;var generation=pipe.Accept(Batch(4,64,new[]{Good(2)}),64);output.Publish(generation);
                Check(!output.TryApply(previous),"old generation/sequence command rejected");
                var wrongTarget=new AdvancedDecision(UpdateStatus.Ready,Key(1),new Vector(0,0,1),1,0,0,4);
                Check(!output.TryApply(new AimCommand(generation.Frame,wrongTarget,164)),"same sequence wrong generation rejected");
                clock.Now=80;var r5=pipe.Accept(Batch(5,80,new[]{Good(2)}),80);output.Publish(r5);
                var clear=new BoxLineOfSight(r5.Frame.Session,5,true,new Box[0]);
                coordinator.Update(r5.Frame,true,clear);
                clock.Now=96;var r6=pipe.Accept(Batch(6,96,new[]{Good(2)}),96);output.Publish(r6);
                Check(coordinator.Update(r6.Frame,true,new BoxLineOfSight(r6.Frame.Session,6,true,new Box[0]))==UpdateStatus.Applied,"reacquire generation");
                clock.Now=196;output.Poll();Check(output.Snapshot==null&&output.ExpirationCount==1,"idle host poll expiry");
                Check(!output.TryApply(previous),"expired command cannot reapply");
                clock.Now=210;var loss=pipe.Accept(Batch(7,210,new[]{Good(2)},coherent:Proof.Unknown),210);
                Check(!output.Publish(loss)&&output.Snapshot==null,"context loss revokes");
                Check(coordinator.Update(null,false,null)==UpdateStatus.Disabled,"explicit disable");output.Enable(false);
                Check(!output.TryApply(previous),"disabled output");
                clock.Now=200;output.Poll();Check(output.Faulted&&output.LastFault=="CLOCK_OR_PROVIDER_EXCEPTION","clock fault latched and reported");
                output.Enable(true);Check(!output.Publish(r6),"fault cannot auto recover");
                output.Recover();Check(!output.Faulted&&!output.IsCurrent(r6.Frame,Key(2)),"recovery requires publication and enable");
                clock.Now=220;pipe.Reset();var fresh=pipe.Accept(Batch(1,220,new[]{Good(1)},"process-2"),220);
                Check(output.Publish(fresh),"explicit recovery new process");
                output.Dispose();Check(!output.TryApply(previous)&&output.Snapshot==null,"dispose revokes");
            }
        }
        private static void TimerExpiry()
        {
            var clock=new MonotonicClock();var pipe=Pipeline();
            using(var output=new ExpiringCommandLease(clock,100,5))
            {
                var policy=new TargetingPolicy(100,30,0,0,180,100,8,16,16,1);
                long now=clock.Milliseconds;var r=pipe.Accept(Batch(1,now,new[]{Good(1)}),now);
                output.Enable(true);Check(output.Publish(r),"timer fixture publish");
                var coordinator=new AimCoordinator(policy,clock,output,output);
                Check(coordinator.Update(r.Frame,true,new BoxLineOfSight(r.Frame.Session,1,true,new Box[0]))==UpdateStatus.Applied,"timer fixture applied");
                Check(SpinWait.SpinUntil(delegate{return output.ExpirationCount>0;},2000),"timer revokes without observation or Snapshot polling");
                Check(output.Snapshot==null,"timer cleared lease");
                Console.WriteLine("WATCHDOG observedElapsedMs="+clock.Milliseconds+" leaseAgeLimitMs=100 expirations="+output.ExpirationCount);
            }
        }
        private static void SessionAndExpiryGuards()
        {
            var clock=new Clock();clock.Now=10;
            var pipe=Pipeline();
            using(var output=new ExpiringCommandLease(clock,100,0))
            {
                output.Enable(true);var r=pipe.Accept(Batch(1,10,new[]{Good(1)}),10);Check(output.Publish(r),"guard fixture");
                var decision=new AdvancedDecision(UpdateStatus.Ready,Key(1),new Vector(0,0,1),1,0,0,1);
                Check(!output.TryApply(new AimCommand(r.Frame,decision,111)),"excess command lifetime rejected");
                var invalidDirection=new AdvancedDecision(UpdateStatus.Ready,Key(1),new Vector(0,0,2),1,0,0,1);
                Check(!output.TryApply(new AimCommand(r.Frame,invalidDirection,110)),"nonunit command rejected");
                Check(output.TryApply(new AimCommand(r.Frame,decision,110)),"application contract lease");
                Check(!output.TryApply(new AimCommand(r.Frame,decision,110)),"same sequence command replay rejected");
                output.Clear(UpdateStatus.Disabled);
                Check(!output.IsCurrent(r.Frame,Key(1)),"revocation removes authority");
                Check(!output.Publish(r),"duplicate publication rejected");
                Check(!output.IsCurrent(r.Frame,Key(1)),"duplicate publication drops current authority");
                pipe.Reset();clock.Now=20;var other=pipe.Accept(Batch(1,20,new[]{Good(1)},"process-2"),20);
                Check(!output.Publish(other)&&output.Faulted&&output.LastFault=="SESSION_CHANGED","context transition latches fault");
                output.Recover();output.Enable(true);Check(output.Publish(other),"explicit context recovery");
                Check(!output.IsCurrent(r.Frame,Key(1)),"old frame authority rejected");
            }
        }
        private static void GeometryContracts()
        {
            var t=new Target("synthetic",new Vector(0,0,10),Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes);
            var f=new Frame("synthetic",1,0,new Vector(),new Vector(0,0,1),Proof.Yes,new[]{t});
            Check(new BoxLineOfSight("synthetic",1,true,new Box[0]).Query(f,t)==Proof.Yes,"clear owned world");
            Check(new BoxLineOfSight("synthetic",1,false,new Box[0]).Query(f,t)==Proof.Unknown,"incomplete world unknown");
            Check(new BoxLineOfSight("synthetic",2,true,new Box[0]).Query(f,t)==Proof.Unknown,"world sequence mismatch");
            var fixtures=new[]{
                new Box(new Vector(-1,-1,5),new Vector(1,1,5.000001)),
                new Box(new Vector(-1,-1,-1),new Vector(1,1,1)),
                new Box(new Vector(-1,-1,10),new Vector(1,1,11)),
                new Box(new Vector(0,-1,5),new Vector(1,1,6))};
            foreach(Box b in fixtures)Check(new BoxLineOfSight("synthetic",1,true,new[]{b}).Query(f,t)==Proof.No,"closed solid boundary blocked");
            Check(new BoxLineOfSight("synthetic",1,true,new[]{new Box(new Vector(1,-1,5),new Vector(2,1,6))}).Query(f,t)==Proof.Yes,"off ray solid");
            var next=new Frame("synthetic",2,1,new Vector(),new Vector(0,0,1),Proof.Yes,new[]{t});
            Check(new BoxLineOfSight("synthetic",2,true,new[]{fixtures[0]}).Query(next,t)==Proof.No,"dynamic obstacle new snapshot");
        }
        public static void Run()
        {Validation();SessionAndExpiryGuards();GeometryContracts();AdapterAndSimulation();TimerExpiry();Console.WriteLine("ReviewChecks=PASS Assertions="+checks+" Scope=OWNED_SIMULATION LiveBinding=BLOCKED");}
    }
}
