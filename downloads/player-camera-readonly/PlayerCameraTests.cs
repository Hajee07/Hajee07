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
        private static Fixture IdentityFixture()
        {
            var f=new Fixture();f.SetupAim();f.SetupPlayerCamera();f.SetupControllerInventory();
            f.U64(Fixture.Transform+0x10,Fixture.CameraTransform);return f;
        }
        private static PlayerCameraIdentityResult Identity(Fixture f)
        {return f.Reader.InspectPlayerCameraIdentity(f.Kernel,f.Game,f.Module,f.Layout,f.CameraContext(),f.Progress.Add);}
        public static void RunPlayerCameraIdentityChecks()
        {
            var f=IdentityFixture();var r=Identity(f);
            Console.WriteLine("MEASURE IdentityStatus="+r.Status+" Reads="+r.AdditionalReads);
            CameraCheck(r.Sources!=null && r.OriginalMainTransformMatchesPlayer==true && r.Sources.ControllerNativeMatchesSelection==true,"identity typed Player/main/controller links match");
            CameraCheck(r.Status=="RECHECKED_IDENTITY_INVENTORY_ONLY"&&r.AdditionalReads<=6000,"identity stays within separate bounded phase");
            f=IdentityFixture();f.U64(Fixture.Transform+0x10,Fixture.NativeHead);r=Identity(f);
            CameraCheck(r.OriginalMainTransformMatchesPlayer==false,"identity different Player transform is reported, not forced equal");
            f=IdentityFixture();f.U64(f.Module.LoadBias+AimStateReference.CameraMainCell,0);r=Identity(f);
            CameraCheck(r.Sources!=null && r.OriginalMainTransformMatchesPlayer==null && r.OriginalMainNativeTransform==0,"identity unresolved native binding remains unknown");
            f=IdentityFixture();f.U64(Fixture.Current+0xd8,0);r=Identity(f);
            CameraCheck(r.Sources.CameraControllerInventoryStatus=="REGISTERED_MATCHGAME_MANAGER_FIELD_NULL","identity null controller field remains explicit");
            f=IdentityFixture();f.Put(f.Module.LoadBias+AimStateReference.GameCameraGetterInitCell,new byte[]{0});r=Identity(f);
            CameraCheck(r.Sources.GameCameraGateStatus=="NOT_READY_GETTER_METADATA_INITIALIZATION"&&r.Sources.ControllerNativeMatchesSelection==true,"identity uninitialized getter is not executed despite field match");
            f=IdentityFixture();f.U64(Fixture.Array+0x20UL+(ulong)AimStateReference.GameCameraGetterGate*8UL,1);r=Identity(f);
            CameraCheck(r.Sources.GameCameraGateStatus=="HOTFIX_ENTRY_BRANCH_PRESENT","identity active game-getter branch stays separate from native selector");
            f=IdentityFixture();f.Put(Fixture.CameraCandidate+NativeTransformReference.CameraPredicateByteOffset,new byte[]{0});r=Identity(f);
            CameraCheck(r.Sources.CameraSelectionComplete&&r.Sources.SelectedNativeCamera==0&&r.OriginalMainTransformMatchesPlayer==null,"identity false native predicate cannot select a camera");
            f=IdentityFixture();f.U64(Fixture.CameraVtable+0xd0,Fixture.Unity+0x601234);r=Identity(f);
            CameraCheck(r.Sources.CameraSelectionStatus=="UNVERIFIED_PREDICATE_OVERRIDE"&&r.OriginalMainTransformMatchesPlayer==null,"identity predicate override is not executed or assumed true");
            f=IdentityFixture();f.U64(Fixture.InventoryCamera+0x10,Fixture.CameraCandidate+0x100);r=Identity(f);
            CameraCheck(r.Sources.ControllerNativeMatchesSelection==false,"identity controller/native selector disagreement is preserved");
            f=IdentityFixture();var core=f.CameraContext();bool rejected=false;
            f.U64(Fixture.CameraCandidate+0x30,Fixture.CameraOwner+8);try{f.Reader.InspectPlayerCameraIdentity(f.Kernel,f.Game,f.Module,f.Layout,core,f.Progress.Add);}catch{rejected=true;}
            CameraCheck(rejected,"identity wrong native Camera owner rejects snapshot");
            f=IdentityFixture();core=f.CameraContext();rejected=false;
            f.Put(f.Module.LoadBias+AimStateReference.Anchors[0].Address,new byte[]{0});try{f.Reader.InspectPlayerCameraIdentity(f.Kernel,f.Game,f.Module,f.Layout,core,f.Progress.Add);}catch{rejected=true;}
            CameraCheck(rejected,"identity changed source anchor rejects snapshot");
            f=IdentityFixture();core=f.CameraContext();f.U64(Fixture.Match+0xd8,Fixture.Player+0x1000);rejected=false;
            try{f.Reader.InspectPlayerCameraIdentity(f.Kernel,f.Game,f.Module,f.Layout,core,f.Progress.Add);}catch{rejected=true;}
            CameraCheck(rejected,"identity changed local player rejects snapshot");
            f=IdentityFixture();core=f.CameraContext();using(f.Reader.PhysicalCallScope(20)){r=f.Reader.InspectPlayerCameraIdentity(f.Kernel,f.Game,f.Module,f.Layout,core,f.Progress.Add);}
            CameraCheck(r.Status=="NOT_READY_READ_BUDGET"&&r.Sources==null&&r.PlayerNativeTransform==0&&r.AdditionalReads<=20,"identity budget discards all tentative source data");
            f=IdentityFixture();core=f.CameraContext();ulong trigger=f.Physical(f.Module.LoadBias+AimStateReference.CameraMainCell);bool changed=false;
            f.Memory.AfterRead=delegate(ulong address,int length){if(!changed&&address==trigger){changed=true;f.U64(Fixture.Transform+0x10,Fixture.NativeHead);}};
            rejected=false;try{f.Reader.InspectPlayerCameraIdentity(f.Kernel,f.Game,f.Module,f.Layout,core,f.Progress.Add);}catch{rejected=true;}
            CameraCheck(rejected,"identity final recheck rejects changed native link");
            Console.WriteLine("PlayerCameraIdentityChecks=PASS Cases=15 ActualRenderedCamera=UNVERIFIED Projection=NOT_READ FunctionsInvoked=False");
        }
        private static Fixture ProjectionFixture()
        {
            var f=IdentityFixture();
            foreach(GameLayoutCheck a in PlayerProjectionReference.Il2CppAnchors)f.Put(f.Module.LoadBias+a.Address,a.Expected(f.Module.LoadBias));
            foreach(GameLayoutCheck a in PlayerProjectionReference.UnityAnchors)f.Put(Fixture.Unity+a.Address,a.Expected(Fixture.Unity));
            f.U64(f.Module.LoadBias+PlayerProjectionReference.ViewCacheCell,Fixture.Unity+PlayerProjectionReference.ViewTarget);
            f.U64(f.Module.LoadBias+PlayerProjectionReference.ProjectionCacheCell,Fixture.Unity+PlayerProjectionReference.ProjectionTarget);
            f.Put(Fixture.CameraCandidate+PlayerProjectionReference.ViewDirtyOffset,new byte[]{0});f.Put(Fixture.CameraCandidate+PlayerProjectionReference.ProjectionDirtyOffset,new byte[]{0});
            float[] view={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1},projection={1,0,0,0,0,2,0,0,0,0,-1.1f,-0.2f,0,0,-1,0};
            for(int i=0;i<16;i++){f.Put(Fixture.CameraCandidate+PlayerProjectionReference.ViewOffset+(ulong)i*4,BitConverter.GetBytes(view[i]));f.Put(Fixture.CameraCandidate+PlayerProjectionReference.ProjectionOffset+(ulong)i*4,BitConverter.GetBytes(projection[i]));}
            return f;
        }
        private static PlayerCameraIdentityResult Projection(Fixture f)
        {return f.Reader.SamplePlayerCameraProjection(f.Kernel,f.Game,f.Module,f.Layout,f.CameraContext(),f.Progress.Add);}
        public static void RunPlayerProjectionChecks()
        {
            int start=cameraChecks;var f=ProjectionFixture();var r=Projection(f);
            Console.WriteLine("MEASURE ProjectionStatus="+r.Status+" Projection="+(r.Projection==null?"NA":r.Projection.Status)+" Reads="+r.AdditionalReads);
            CameraCheck(r.Projection!=null&&r.Projection.Status=="SAMPLED_CLEAN_CACHE_READ_ONLY"&&r.Projection.ViewNativeSequence.Length==16&&r.Projection.ProjectionNativeSequence.Length==16&&r.AdditionalReads<=9000,"projection bounded clean-cache raw sequence sample");
            CameraCheck(r.Projection.ViewNativeSequence[0]==1&&Math.Abs(r.Projection.ProjectionNativeSequence[11]+0.2)<1e-6,"projection raw float sequence preserved without transpose");
            foreach(ulong offset in new[]{PlayerProjectionReference.ViewDirtyOffset,PlayerProjectionReference.ProjectionDirtyOffset})
            {f=ProjectionFixture();f.Put(Fixture.CameraCandidate+offset,new byte[]{1});r=Projection(f);CameraCheck(r.Projection.Status=="NOT_READY_DIRTY_CACHE"&&r.Projection.ViewNativeSequence==null,"projection dirty cache withheld offset "+offset);}
            f=ProjectionFixture();f.U64(f.Module.LoadBias+PlayerProjectionReference.ViewCacheCell,0);r=Projection(f);
            CameraCheck(r.Projection.Status=="NOT_READY_BINDING_UNINITIALIZED"&&r.Projection.ViewNativeSequence==null,"projection uninitialized target is not resolved or invoked");
            f=ProjectionFixture();f.U64(f.Module.LoadBias+PlayerProjectionReference.ProjectionCacheCell,Fixture.Unity+0x600000);r=Projection(f);
            CameraCheck(r.Projection.Status=="NOT_READY_BINDING_MISMATCH"&&r.Projection.ViewNativeSequence==null,"projection different function target withheld");
            f=ProjectionFixture();f.Put(Fixture.Unity+PlayerProjectionReference.UnityAnchors[0].Address,new byte[]{0});bool rejected=false;try{Projection(f);}catch{rejected=true;}
            CameraCheck(rejected,"projection changed code anchor rejected");
            f=ProjectionFixture();f.U64(Fixture.Transform+0x10,Fixture.NativeHead);r=Projection(f);
            CameraCheck(r.Projection.Status=="NOT_READY_SOURCE"&&r.Projection.ViewNativeSequence==null,"projection player/main Transform disagreement withheld");
            f=ProjectionFixture();f.U64(Fixture.InventoryCamera+0x10,Fixture.CameraCandidate+0x100);r=Projection(f);
            CameraCheck(r.Projection.Status=="NOT_READY_SOURCE"&&r.Projection.ViewNativeSequence==null,"projection controller/native disagreement withheld");
            f=ProjectionFixture();f.Put(Fixture.CameraCandidate+PlayerProjectionReference.ProjectionOffset,BitConverter.GetBytes(float.NaN));r=Projection(f);
            CameraCheck(r.Projection.Status=="NOT_READY_INVALID_MATRIX"&&r.Projection.ViewNativeSequence==null,"projection NaN matrix withheld");
            f=ProjectionFixture();f.Put(Fixture.CameraCandidate+PlayerProjectionReference.ViewOffset,new byte[64]);r=Projection(f);
            CameraCheck(r.Projection.Status=="NOT_READY_INVALID_MATRIX"&&r.Projection.ViewNativeSequence==null,"projection singular/zero matrix withheld");
            foreach(int mutation in new[]{0,1,2})
            {
                f=ProjectionFixture();var core=f.CameraContext();ulong trigger=f.Physical(Fixture.CameraCandidate+PlayerProjectionReference.ViewOffset);bool changed=false;int kind=mutation;Fixture current=f;
                f.Memory.AfterRead=delegate(ulong address,int length){if(address==trigger&&length==64&&!changed){changed=true;if(kind==0)current.Put(Fixture.CameraCandidate+PlayerProjectionReference.ViewOffset,BitConverter.GetBytes(2f));else if(kind==1)current.Put(Fixture.CameraCandidate+PlayerProjectionReference.ViewDirtyOffset,new byte[]{1});else current.U64(Fixture.Match+0xd8,Fixture.Player+0x1000);}};
                r=f.Reader.SamplePlayerCameraProjection(f.Kernel,f.Game,f.Module,f.Layout,core,f.Progress.Add);
                CameraCheck(changed&&r.Status=="NOT_READY_SOURCE_CHANGED"&&r.Projection==null&&r.Sources==null,"projection changed matrix/dirty/context suppresses tentative data case "+kind);
            }
            f=ProjectionFixture();var context=f.CameraContext();using(f.Reader.PhysicalCallScope(20)){r=f.Reader.SamplePlayerCameraProjection(f.Kernel,f.Game,f.Module,f.Layout,context,f.Progress.Add);}
            CameraCheck(r.Status=="NOT_READY_READ_BUDGET"&&r.Sources==null&&r.Projection==null&&r.AdditionalReads<=20,"projection nested budget discards all tentative data");
            Console.WriteLine("PlayerProjectionChecks=PASS Cases="+(cameraChecks-start)+" ActualRenderedCamera=UNVERIFIED FunctionsInvoked=False");
        }
    }
}
