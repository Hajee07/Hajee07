using System;

namespace HeadBridge.Mapping.Targeting
{
    public sealed class AimCommand
    {
        public readonly string Session,TargetId;
        public readonly long Sequence,ExpiresAt;
        public readonly Vector Direction;
        internal AimCommand(Frame frame,AdvancedDecision decision,long expiresAt)
        {Session=frame.Session;Sequence=frame.Sequence;TargetId=decision.TargetId;Direction=decision.Direction;ExpiresAt=expiresAt;}
    }
    public interface IFrameAuthority
    {
        // Must revalidate camera, target identity/eligibility and observation validity.
        bool IsCurrent(Frame frame,string targetId);
    }
    public interface IAimOutput
    {
        // Host adapter must atomically recheck session, sequence, authority and expiry
        // at actual application time. True means applied, not merely queued.
        bool TryApply(AimCommand command);
        // Clear any queued/held command; implement as idempotent.
        void Clear(UpdateStatus reason);
    }
    // Drives a bound host automatically once per observation, not a background game injector.
    public sealed class AimCoordinator
    {
        private readonly AdvancedController controller;
        private readonly IMonotonicClock clock;
        private readonly TargetingPolicy policy;
        private readonly IFrameAuthority authority;
        private readonly IAimOutput output;
        private readonly object gate=new object();
        private bool faulted,busy;
        public AimCoordinator(TargetingPolicy policy,IMonotonicClock clock,IFrameAuthority authority,IAimOutput output)
        {
            if(policy==null||clock==null||authority==null||output==null)throw new ArgumentNullException();
            this.policy=policy;this.clock=clock;this.authority=authority;this.output=output;controller=new AdvancedController(policy,clock);
        }
        private UpdateStatus Revoke(UpdateStatus reason)
        {
            try{output.Clear(reason);}catch{faulted=true;return UpdateStatus.OutputFault;}
            return reason;
        }
        public UpdateStatus Update(Frame frame,bool enabled,ILineOfSight los)
        {
            lock(gate)
            {
                if(busy)throw new InvalidOperationException("Aim callbacks cannot reenter coordinator");
                busy=true;
                try
                {
                    if(faulted){controller.ClearTracking();return Revoke(UpdateStatus.OutputFault);}
                    long begin=clock.Milliseconds;
                    AdvancedDecision d=controller.Step(frame,enabled,los);
                    if(d.Status!=UpdateStatus.Ready)return Revoke(d.Status);
                    if(!authority.IsCurrent(frame,d.TargetId)){controller.ClearTracking();return Revoke(UpdateStatus.ContextChanged);}
                    long now=clock.Milliseconds;
                    if(now<begin||now<frame.CapturedAt){controller.ClearTracking();return Revoke(UpdateStatus.ClockFailure);}
                    if(now-frame.CapturedAt>policy.MaxAgeMilliseconds){controller.ClearTracking();return Revoke(UpdateStatus.StaleFrame);}
                    if(now-begin>policy.MaxComputeMilliseconds){controller.ClearTracking();return Revoke(UpdateStatus.TimeBudget);}
                    var command=new AimCommand(frame,d,frame.CapturedAt+policy.MaxAgeMilliseconds);
                    if(output.TryApply(command))return UpdateStatus.Applied;
                    controller.ClearTracking();return Revoke(UpdateStatus.OutputRejected);
                }
                catch{faulted=true;controller.ClearTracking();return Revoke(UpdateStatus.OutputFault);}
                finally{busy=false;}
            }
        }
        // Explicit host action after recovering the adapter. Never auto-reset on failure.
        public void ResetFault()
        {
            lock(gate)
            {
                if(busy)throw new InvalidOperationException("Cannot reset inside callback");
                busy=true;faulted=true;
                try{output.Clear(UpdateStatus.Disabled);controller.ClearTracking();faulted=false;}
                finally{busy=false;}
            }
        }
    }
}
