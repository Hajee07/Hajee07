using System;
namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private static int cameraChecks;
        private static void CameraCheck(bool ok,string name){cameraChecks++;if(!ok)throw new Exception(name);Console.WriteLine("PASS-PLAYER-CAMERA: "+name);}
        private sealed partial class Fixture
        {
            internal void SetupPlayerCamera()
            {
                SetupNative();foreach(GameLayoutCheck a in NativeTransformReference.CameraRotationAnchors)Put(Unity+a.Address,a.Expected(Unity));
                U64(Player+PlayerCameraReference.Offset,Transform);
                U32(Module.LoadBias+PlayerCameraReference.OffsetRva,(uint)PlayerCameraReference.Offset);
                Put(Layout.RuntimeMetadataBase+PlayerCameraReference.MetadataOffset,Reader.Hex(PlayerCameraReference.FieldRecordHex));
                U32(Module.LoadBias+PlayerCameraReference.DescriptorRva+8,PlayerCameraReference.DescriptorBits);
                U64(Module.LoadBias+PlayerCameraReference.DescriptorRva,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)PlayerCameraReference.TransformTypeIndex*88UL);
                const ulong table=0x79000000;U64(Class(31824)+0x80,table);ulong field=table+(ulong)PlayerCameraReference.LocalIndex*32;
                U64(field,Layout.RuntimeMetadataBase+PlayerCameraReference.NameOffset);U64(field+8,Module.LoadBias+PlayerCameraReference.DescriptorRva);
                U64(field+0x10,Class(31824));U32(field+0x18,(uint)PlayerCameraReference.Offset);U32(field+0x1c,PlayerCameraReference.FieldToken);
            }
            internal PlayerObjectResult CameraContext(){return Reader.VerifyPlayerCameraContext(Kernel,Game,Module,Layout,Progress.Add);}
            internal PlayerCameraPoseResult CameraPose(PlayerObjectResult context){return Reader.SamplePlayerCameraPose(Kernel,Game,Module,Layout,context,Progress.Add);}
        }
        private static void CameraReject(Action<Fixture> change,string name)
        {var f=new Fixture();f.SetupPlayerCamera();var context=f.CameraContext();change(f);bool rejected=false;try{f.CameraPose(context);}catch{rejected=true;}CameraCheck(rejected,name);}
        public static void RunPlayerCameraChecks()
        {
            var diagnostic=new Fixture();diagnostic.SetupPlayerCamera();
            diagnostic.Reader.CameraDiagnosticStage="FIXTURE_STAGE";
            diagnostic.Reader.Virtual(diagnostic.Game.Root,Fixture.Player,1);
            diagnostic.Memory.Map4K(diagnostic.Game.Root,Fixture.Player,0x7000000);
            diagnostic.Memory.Write(0x7000000,new byte[]{123});
            CameraCheck(diagnostic.Reader.Virtual(diagnostic.Game.Root,Fixture.Player,1)[0]==123,"stale cached mapping reads newly validated page");
            diagnostic.Memory.AfterRead=delegate(ulong diagnosticAddress,int diagnosticCount){if(diagnosticAddress==0x7000000)diagnostic.Memory.Map4K(diagnostic.Game.Root,Fixture.Player,0x7100000);};
            bool diagnosticRejected=false;
            try { diagnostic.Reader.Virtual(diagnostic.Game.Root,Fixture.Player,1); }
            catch(InvalidOperationException error) { diagnosticRejected=error.Message.Contains("Stage=FIXTURE_STAGE") && error.Message.Contains("RecheckedPhysical=0x7100000") && error.Message.Contains("ReadPhysical=0x7000000"); }
            CameraCheck(diagnosticRejected,"mapping change during read remains fatal with diagnostic addresses");
            diagnostic.Memory.AfterRead=null;
            diagnostic.Memory.Write(0x7100000,new byte[]{42});
            CameraCheck(diagnostic.Reader.Virtual(diagnostic.Game.Root,Fixture.Player,1)[0]==42,"failed mapping is evicted and fresh read uses current page");
            var f=new Fixture();f.SetupPlayerCamera();var context=f.CameraContext();var r=f.CameraPose(context);
            CameraCheck(r.Status=="SAMPLED_READ_ONLY"&&r.Attempts==1,"verified field yields read-only pose");
            CameraCheck(Math.Abs(r.Position[0]-104)<.0001&&Math.Abs(r.Position[1]-202)<.0001&&Math.Abs(r.Position[2]-312)<.0001,"rotated scaled hierarchy world position oracle");
            CameraCheck(Math.Abs(r.Rotation[2]-Math.Sqrt(.5))<.0001&&Math.Abs(r.Rotation[3]-Math.Sqrt(.5))<.0001,"parent rotation source math");
            Console.WriteLine("MEASURE PlayerCameraStableReads="+r.AdditionalReads);
            CameraCheck(r.AdditionalReads<=6000&&r.ParentCount==2,"phase and hierarchy bounds");
            var empty=new Fixture();empty.SetupPlayerCamera();var ec=empty.CameraContext();empty.U64(Fixture.Player+PlayerCameraReference.Offset,0);r=empty.CameraPose(ec);CameraCheck(r.Status=="NOT_READY_CAMERA_FIELD_NULL"&&r.Position==null,"null field never yields a pose");
            var noUnity=new Fixture();noUnity.SetupPlayerCamera();ec=noUnity.CameraContext();noUnity.U64(noUnity.Module.LoadBias+0xafb9e00,0);noUnity.U64(noUnity.Module.LoadBias+0xafb9e10,0);r=noUnity.CameraPose(ec);CameraCheck(r.Status=="NOT_READY_UNITY_BINDING"&&r.Position==null,"unresolved binding remains unknown");
            var pending=new Fixture();pending.SetupPlayerCamera();ec=pending.CameraContext();pending.U64(Fixture.Hierarchy,1234);r=pending.CameraPose(ec);CameraCheck(r.Status=="NOT_READY_JOB_PENDING"&&r.Position==null,"pending job not synchronized or sampled");
            CameraReject(delegate(Fixture x){x.U32(x.Module.LoadBias+PlayerCameraReference.OffsetRva,1008);},"wrong offset rejected");
            CameraReject(delegate(Fixture x){x.U32(x.Module.LoadBias+PlayerCameraReference.DescriptorRva+8,0);},"wrong type descriptor rejected");
            CameraReject(delegate(Fixture x){x.U64(Fixture.Match+0xd8,Fixture.Player+0x1000);},"local context change rejected");
            CameraReject(delegate(Fixture x){x.U64(Fixture.HotfixStatics,Fixture.Array);x.U64(Fixture.Array+0x20+0x1c6*8,0x78000000);},"active original-path hotfix rejected");
            CameraReject(delegate(Fixture x){x.U64(Fixture.Transform,Fixture.Class(31824));},"wrong managed transform class rejected");
            CameraReject(delegate(Fixture x){x.U64(Fixture.NativeRoot+0x90,Fixture.NativeHead);},"root backlink rejected");
            CameraReject(delegate(Fixture x){x.U32(Fixture.Parents,2);},"hierarchy cycle rejected");
            CameraReject(delegate(Fixture x){x.Trs(2,1,2,3,0,0,0,0,1,1,1);},"zero quaternion rejected");
            CameraReject(delegate(Fixture x){x.Trs(2,float.NaN,2,3,0,0,0,1,1,1,1);},"invalid coordinate rejected");
            var noRoster=new Fixture();noRoster.SetupPlayerCamera();noRoster.U64(Fixture.Match+0x128,1);r=noRoster.CameraPose(noRoster.CameraContext());CameraCheck(r.Status=="SAMPLED_READ_ONLY","no full-roster dependency or roster claim");
            var motion=new Fixture();motion.SetupPlayerCamera();ec=motion.CameraContext();ulong at=motion.Physical(Fixture.Matrices);int seen=0;
            motion.Memory.AfterRead=delegate(ulong address,int length){if(address==at&&length==144&&++seen==1)motion.Put(Fixture.Matrices+96,BitConverter.GetBytes(2f));};
            r=motion.CameraPose(ec);Console.WriteLine("MEASURE MotionStatus="+r.Status+" Attempts="+r.Attempts+" Reads="+r.AdditionalReads+" Detail="+r.Detail+" Y="+(r.Position==null?"NA":r.Position[1].ToString()));CameraCheck(r.Status=="NOT_READY_READ_BUDGET"&&r.Attempts==2&&r.Position==null&&r.AdditionalReads==6000,"motion discards capture and fresh attempt stops at shared budget");
            var continuous=new Fixture();continuous.SetupPlayerCamera();ec=continuous.CameraContext();at=continuous.Physical(Fixture.Matrices);int copies=0;
            continuous.Memory.AfterRead=delegate(ulong address,int length){if(address==at&&length==144)continuous.Put(Fixture.Matrices+96,BitConverter.GetBytes(100f+(++copies)));};
            r=continuous.CameraPose(ec);CameraCheck((r.Status=="NOT_READY_MOTION"||r.Status=="NOT_READY_READ_BUDGET")&&r.Attempts<=3&&r.Position==null&&r.AdditionalReads<=6000,"continuous motion stays unready within shared read/attempt bounds");
            var swapped=new Fixture();swapped.SetupPlayerCamera();ec=swapped.CameraContext();at=swapped.Physical(Fixture.Matrices);
            swapped.Memory.AfterRead=delegate(ulong address,int length){if(address==at&&length==144)swapped.U64(Fixture.Player+PlayerCameraReference.Offset,0);};
            bool failed=false;try{swapped.CameraPose(ec);}catch{failed=true;}CameraCheck(failed,"field pointer change on final recheck is fatal");
            var budget=new Fixture();budget.SetupPlayerCamera();ec=budget.CameraContext();
            using(budget.Reader.PhysicalCallScope(20)){r=budget.CameraPose(ec);CameraCheck(r.Status=="NOT_READY_READ_BUDGET"&&r.Position==null&&r.AdditionalReads<=20,"nested budget is respected without resetting counters");}
            var job=new Fixture();job.SetupPlayerCamera();ec=job.CameraContext();at=job.Physical(Fixture.Matrices);ulong jobAt=job.Physical(Fixture.Hierarchy);bool armed=false,cleared=false;
            job.Memory.AfterRead=delegate(ulong address,int length){if(address==at&&length==144&&!armed){armed=true;job.U64(Fixture.Hierarchy,1234);}else if(armed&&!cleared&&address==jobAt&&length==8){cleared=true;job.U64(Fixture.Hierarchy,0);}};
            r=job.CameraPose(ec);CameraCheck(((r.Status=="SAMPLED_READ_ONLY"&&r.Position!=null)||(r.Status=="NOT_READY_READ_BUDGET"&&r.Position==null))&&r.Attempts==2&&r.AdditionalReads<=6000,"transient job change discards and reacquires within shared budget");
            var mixed=new Fixture();mixed.SetupPlayerCamera();ec=mixed.CameraContext();at=mixed.Physical(Fixture.Matrices);
            mixed.Memory.AfterRead=delegate(ulong address,int length){if(address==at&&length==144){mixed.U64(Fixture.Hierarchy,1234);mixed.U64(Fixture.Player+PlayerCameraReference.Offset,0);}};
            failed=false;try{mixed.CameraPose(ec);}catch{failed=true;}CameraCheck(failed,"context identity failure wins over simultaneous retryable job change");
            var transport=new Fixture();transport.SetupPlayerCamera();ec=transport.CameraContext();at=transport.Physical(Fixture.Matrices);
            transport.Memory.AfterRead=delegate(ulong address,int length){if(address==at&&length==144)throw new InvalidOperationException("fixture transport failure");};
            failed=false;try{transport.CameraPose(ec);}catch(Exception e){failed=e.Message.Contains("transport failure");}CameraCheck(failed,"transport failure is fatal without retry or stale pose");
            Console.WriteLine("PlayerCameraChecks=PASS Assertions="+cameraChecks+" LiveCamera=UNVERIFIED");
        }
    }
}
