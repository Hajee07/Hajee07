using System;
using System.Threading;
using HeadBridge.Mapping.Targeting;

namespace HeadBridge.IntegrationReview
{
    // Owned simulation output only. Applied means stored in this local lease.
    // A game adapter must supply its own verified thread/acknowledgement contract.
    public sealed class ExpiringCommandLease : IFrameAuthority, IAimOutput, IDisposable
    {
        private readonly object gate=new object();
        private readonly IMonotonicClock clock;
        private readonly long maxAge;
        private readonly Timer watchdog;
        private Frame current;
        private AimCommand held;
        private bool enabled,faulted,disposed;
        private long lastNow=-1,lastSequence=-1,appliedSequence=-1;
        private string session;
        private int expirations;
        private string lastFault;
        public string LastFault {get{lock(gate){return lastFault;}}}
        public int ExpirationCount {get{lock(gate){return expirations;}}}
        public ExpiringCommandLease(IMonotonicClock clock,long maxAgeMilliseconds,int watchdogPeriodMilliseconds)
        {
            if(clock==null||maxAgeMilliseconds<1||maxAgeMilliseconds>60000||watchdogPeriodMilliseconds<0||watchdogPeriodMilliseconds>1000)throw new ArgumentException();
            this.clock=clock;maxAge=maxAgeMilliseconds;
            // Zero selects deterministic host-owned Poll; production hosts must schedule it.
            if(watchdogPeriodMilliseconds>0)watchdog=new Timer(delegate(object ignored){Poll();},null,watchdogPeriodMilliseconds,watchdogPeriodMilliseconds);
        }
        public bool Faulted {get{lock(gate){return faulted;}}}
        private long Now()
        {
            long now=clock.Milliseconds;
            if(now<0||now<lastNow)throw new InvalidOperationException("Monotonic clock failed");
            lastNow=now;return now;
        }
        private bool Fresh(Frame f,long now)
        {return f!=null&&now>=f.CapturedAt&&now-f.CapturedAt<maxAge;}
        private bool Contains(string key)
        {if(current==null||current.Targets==null)return false;foreach(Target t in current.Targets)if(t.Id==key)return true;return false;}
        private void Fault(string reason){held=null;current=null;faulted=true;enabled=false;lastFault=reason;}
        public void Enable(bool value)
        {lock(gate){if(disposed)throw new ObjectDisposedException("ExpiringCommandLease");held=null;current=null;enabled=value&&!faulted;}}
        public bool Publish(ValidationResult result)
        {
            lock(gate)
            {
                held=null;
                if(disposed||faulted)return false;
                try
                {
                    long now=Now();Frame f=result==null?null:result.Frame;
                    if(f==null||f.CameraVerified!=Proof.Yes||!Fresh(f,now)){current=null;return false;}
                    if(session!=null&&session!=f.Session){Fault("SESSION_CHANGED");return false;}
                    if(f.Sequence<=lastSequence){current=null;return false;}
                    session=f.Session;lastSequence=f.Sequence;current=f;return true;
                }
                catch{Fault("CLOCK_OR_PROVIDER_EXCEPTION");return false;}
            }
        }
        public bool IsCurrent(Frame frame,string targetId)
        {
            lock(gate)
            {
                if(disposed||faulted||!enabled)return false;
                try{return object.ReferenceEquals(frame,current)&&Fresh(frame,Now())&&Contains(targetId);}
                catch{Fault("CLOCK_OR_PROVIDER_EXCEPTION");return false;}
            }
        }
        public bool TryApply(AimCommand command)
        {
            lock(gate)
            {
                held=null;
                if(disposed||faulted||!enabled||command==null)return false;
                try
                {
                    long now=Now();
                    if(!Fresh(current,now)||command.Sequence<=appliedSequence||command.Session!=current.Session||command.Sequence!=current.Sequence||
                       !Contains(command.TargetId)||command.ExpiresAt<=now||command.ExpiresAt-current.CapturedAt>maxAge||
                       !command.Direction.Finite||Math.Abs(command.Direction.Length-1)>1e-6)return false;
                    held=command;appliedSequence=command.Sequence;return true;
                }
                catch{Fault("CLOCK_OR_PROVIDER_EXCEPTION");return false;}
            }
        }
        public void Clear(UpdateStatus reason){lock(gate){held=null;current=null;}}
        public void Poll()
        {
            lock(gate)
            {
                if(disposed)return;
                try{long now=Now();if(!Fresh(current,now)||held!=null&&now>=held.ExpiresAt){if(held!=null)expirations++;held=null;current=null;}}
                catch{Fault("CLOCK_OR_PROVIDER_EXCEPTION");}
            }
        }
        public AimCommand Snapshot
        {get{lock(gate){Poll();return held;}}}
        // Explicit recovery drops context and requires new publication and Enable.
        public void Recover()
        {lock(gate){if(disposed)throw new ObjectDisposedException("ExpiringCommandLease");held=null;current=null;enabled=false;faulted=false;lastFault=null;session=null;lastSequence=-1;appliedSequence=-1;lastNow=-1;}}
        public void Dispose()
        {lock(gate){disposed=true;enabled=false;held=null;current=null;}if(watchdog!=null)watchdog.Dispose();}
    }
}
