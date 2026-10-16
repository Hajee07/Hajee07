using System;
namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private static void RunNativeJobRetryTests()
        {
            foreach(bool tag in new bool[]{false,true})
            {
                Fixture f=new Fixture();f.SetupNative();ulong pose=f.Physical(Fixture.Matrices),job=f.Physical(Fixture.Hierarchy+(tag?8UL:0UL));bool changed=false,cleared=false;
                f.Memory.AfterRead=delegate(ulong at,int length){
                    if(at==pose && length==144 && !changed){changed=true;if(tag)f.U32(Fixture.Hierarchy+8,9);else f.U64(Fixture.Hierarchy,0x12340000);}
                    else if(changed && !cleared && at==job && length==(tag?4:8)){cleared=true;if(tag)f.U32(Fixture.Hierarchy+8,0);else f.U64(Fixture.Hierarchy,0);}
                };
                PlayerObjectResult r=f.Run();
                Check(r.HeadWorldStatus=="SAMPLED_READ_ONLY" && r.HeadSampleAttempts==2 && Math.Abs(r.HeadWorldX-104)<0.0001 &&
                    f.Progress.FindAll(delegate(string line){return line.Contains("NativeHeadSampleJobChange");}).Count==1,
                    "settled job-only transition requires one fully fresh native attempt: "+tag);
            }
            Fixture continuous=new Fixture();continuous.SetupNative();ulong cp=continuous.Physical(Fixture.Matrices),cj=continuous.Physical(Fixture.Hierarchy);int changes=0;
            continuous.Memory.AfterRead=delegate(ulong at,int length){
                if(at==cp && length==144){changes++;continuous.U64(Fixture.Hierarchy,(ulong)changes+0x12340000UL);}
                else if(at==cj && length==8 && changes>0)continuous.U64(Fixture.Hierarchy,0);
            };
            PlayerObjectResult cr=continuous.Run();
            Check(cr.HeadWorldStatus=="NOT_READY_HIERARCHY_JOB_CHANGED" && cr.HeadSampleAttempts==3 && cr.HeadWorldX==0 && cr.HeadWorldObservations==0 &&
                continuous.Progress.FindAll(delegate(string line){return line.Contains("NativeHeadSampleJobChange");}).Count==3,
                "persistent job changes discard every attempt and produce no coordinates after the shared three-attempt limit");
            foreach(bool early in new bool[]{false,true})
            {
                Fixture f=new Fixture();f.SetupNative();ulong pose=f.Physical(Fixture.Matrices);
                f.Memory.AfterRead=delegate(ulong at,int length){if(at==pose && length==144){f.U64(Fixture.Hierarchy,0x12340000);if(early)f.U64(Fixture.NativeHead+0x38,Fixture.Hierarchy+0x1000);else f.U64(Fixture.NativeRoot+0x90,Fixture.NativeHead);}};
                PlayerObjectResult r=f.Run();
                Check(r.HeadWorldStatus=="FAIL" && r.HeadSampleAttempts==1 && r.HeadWorldX==0 && r.HeadWorldError.Contains("Native identity recheck") &&
                    !f.Progress.Exists(delegate(string line){return line.Contains("NativeHeadSampleJobChange");}),
                    "hard identity changes take precedence over job changes regardless of reverse recheck order: "+early);
            }
            Fixture transport=new Fixture();transport.SetupNative();ulong tp=transport.Physical(Fixture.Matrices),tj=transport.Physical(Fixture.Hierarchy);bool armed=false;
            transport.Memory.AfterRead=delegate(ulong at,int length){if(at==tp && length==144){armed=true;transport.U64(Fixture.Hierarchy,0x12340000);}else if(armed && at==tj && length==8)throw new InvalidOperationException("Synthetic job recheck transport failure");};
            PlayerObjectResult tr=transport.Run();
            Check(tr.HeadWorldStatus=="FAIL" && tr.HeadSampleAttempts==1 && tr.HeadWorldError.Contains("transport failure"),"transport errors cannot be downgraded to retryable job changes");
            Fixture mixed=new Fixture();mixed.SetupNative();ulong mp=mixed.Physical(Fixture.Matrices),mj=mixed.Physical(Fixture.Hierarchy);int copies=0;bool jobArmed=false,jobCleared=false;
            mixed.Memory.AfterRead=delegate(ulong at,int length){
                if(at==mp && length==144){copies++;if(copies==1)mixed.Put(Fixture.Matrices+96,BitConverter.GetBytes(9f));if(copies==3){jobArmed=true;mixed.U64(Fixture.Hierarchy,0x12340000);}}
                else if(jobArmed && !jobCleared && at==mj && length==8){jobCleared=true;mixed.U64(Fixture.Hierarchy,0);}
            };
            PlayerObjectResult mr=mixed.Run();
            Check(mr.HeadWorldStatus=="SAMPLED_READ_ONLY" && mr.HeadSampleAttempts==3 && Math.Abs(mr.HeadWorldY-218)<0.0001 &&
                mixed.Progress.FindAll(delegate(string line){return line.Contains("NativeHeadSampleMotion");}).Count==1 && mixed.Progress.FindAll(delegate(string line){return line.Contains("NativeHeadSampleJobChange");}).Count==1,
                "TRS and job transitions share one three-attempt allowance and never reuse a discarded pose");
            Fixture tagged=new Fixture();tagged.SetupNative();tagged.U32(Fixture.Hierarchy+8,7);PlayerObjectResult pending=tagged.Run();
            Check(pending.HeadWorldStatus=="NOT_READY_HIERARCHY_JOB_PENDING" && pending.HeadSampleAttempts==1 && pending.HeadWorldX==0,
                "a stable pending tag remains unready without synchronizing or pointless retries");
            Fixture noJobButPointer=new Fixture();noJobButPointer.SetupNative();ulong pp=noJobButPointer.Physical(Fixture.Matrices);
            noJobButPointer.Memory.AfterRead=delegate(ulong at,int length){if(at==pp && length==144)noJobButPointer.U64(Fixture.Transform+0x10,Fixture.NativeParent);};PlayerObjectResult pr=noJobButPointer.Run();
            Check(pr.HeadWorldStatus=="FAIL" && pr.HeadSampleAttempts==1 && pr.HeadWorldError.Contains("ManagedTransform.NativePointer"),"managed/native pointer changes remain immediate hard failures");
        }
    }
}
