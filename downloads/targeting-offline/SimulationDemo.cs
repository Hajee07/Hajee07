using System;
using HeadBridge.Mapping.Targeting;

// Executable example of an actual bound output adapter, in a local simulation.
// Nothing in this demo opens a process or controls Free Fire/BlueStacks.
internal sealed class SimulationHost : IMonotonicClock,IFrameAuthority,IAimOutput
{
    private long now;
    private Frame current;
    private AimCommand applied;
    public long Milliseconds {get{return now;}}
    public bool IsCurrent(Frame f,string id)
    {return object.ReferenceEquals(current,f)&&id=="simulated-target"&&now>=f.CapturedAt&&now-f.CapturedAt<=100;}
    public bool TryApply(AimCommand command)
    {
        // Application and validation occur synchronously on the same host thread.
        if(current==null||command.Session!=current.Session||command.Sequence!=current.Sequence||
           command.TargetId!="simulated-target"||now>command.ExpiresAt)return false;
        applied=command;return true;
    }
    public void Clear(UpdateStatus reason){applied=null;}
    private static void Expect(bool condition){if(!condition)throw new Exception("Demo assertion failed");}
    public static int Main()
    {
        var host=new SimulationHost();var policy=TargetingPolicy.Default;
        var coordinator=new AimCoordinator(policy,host,host,host);
        var target=new Target("simulated-target",new Vector(1,0,10),Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes,Proof.Yes);
        for(int sequence=1;sequence<=3;sequence++)
        {
            host.now=sequence*16;
            host.current=new Frame("simulation",sequence,host.now,new Vector(),new Vector(0,0,1),Proof.Yes,new[]{target});
            Triangle[] geometry=sequence==3?new[]{new Triangle(new Vector(-2,-2,5),new Vector(2,-2,5),new Vector(0,2,5))}:new Triangle[0];
            var los=new MeshLineOfSight("simulation",sequence,true,geometry,1024,1024);
            UpdateStatus status=coordinator.Update(host.current,true,los);
            Console.WriteLine("Frame "+sequence+": "+status+"; command="+(host.applied==null?"cleared":host.applied.TargetId));
            Expect(sequence==1?status==UpdateStatus.Acquiring&&host.applied==null:
                   sequence==2?status==UpdateStatus.Applied&&host.applied!=null:
                   status==UpdateStatus.NoVisibleTarget&&host.applied==null);
        }
        Expect(coordinator.Update(null,false,null)==UpdateStatus.Disabled&&host.applied==null);
        Console.WriteLine("SIMULATION PASS: acquire -> apply -> obstruction revokes -> disabled. Live game integration NOT_TESTED.");
        return 0;
    }
}
