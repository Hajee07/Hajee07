using System;
using System.Collections.Generic;
namespace HeadBridge.Mapping
{
    public sealed class PlayerCameraPoseResult
    {
        public string Status="NOT_READY",Detail="";
        public ulong ManagedTransform,NativeTransform,UnityLoadBias;
        public int Attempts,Observations,ParentCount,AdditionalReads;
        public double[] Position,Rotation;
    }
    public sealed partial class Reader
    {
        private PlayerObjectResult CameraLocalContext(ObjectReads reads,ModuleResult module,GameLayoutResult layout,Action<string> progress)
        {
            ulong facade=RootClass(reads,module,layout,ObjectReference.FacadeCell,12418,progress);
            ulong matchBase=RootClass(reads,module,layout,ObjectReference.MatchGameCell,12425,progress);
            ulong hotfix=RootClass(reads,module,layout,ObjectReference.HotfixCell,37332,progress);
            Expect(reads.Word(facade+0xe0)!=0 && reads.Word(hotfix+0xe0)!=0,"camera static classes initialized");
            VerifyWrapperField(reads,hotfix,module,layout);
            ulong wrappers=reads.Pointer(reads.Pointer(hotfix+0xb8,"camera hotfix statics"),"camera wrappers");
            reads.Pointer(wrappers,"camera wrapper array class");ulong length=reads.Value(wrappers+0x18);
            Expect(length<=1000000,"camera wrapper array bound");
            foreach(int id in new[]{0x1c6,0x139,0x1c5,0x12b})Expect(!HotfixEntry(reads,wrappers,length,id),"camera local original path hotfix inactive");
            var result=new PlayerObjectResult();
            result.CurrentGame=reads.Pointer(reads.Pointer(facade+0xb8,"camera facade statics"),"camera current game");
            ObjectFamily(reads,result.CurrentGame,4,12425,matchBase,layout,progress);
            result.Match=reads.Pointer(result.CurrentGame+0x90,"camera match");ObjectFamily(reads,result.Match,8,32133,0,layout,progress);
            result.LocalPlayer=reads.Pointer(result.Match+0xd8,"camera local player");
            result.PlayerClass=ObjectFamily(reads,result.LocalPlayer,16,31824,0,layout,progress).Name;
            Expect(reads.Byte(result.LocalPlayer+0x420)==1,"camera local-player marker");return result;
        }
        private static void CameraVerifiedInputs(ModuleResult module,GameLayoutResult layout)
        {
            if(module==null||layout==null||module.BuildId!=ApkModule.BuildId||module.ReferenceFileSha256!=ApkModule.FileSha256||
               layout.MetadataSha256!=GameLayoutReference.MetadataSha256||layout.TypeDescriptors!=9||layout.Checks!=80)
                throw new ArgumentException("Verified module and layout required for player camera");
            ObjectReads.User(module.LoadBias,4096,"camera module base");ObjectReads.User(layout.RuntimeMetadataBase,4,"camera metadata base");
        }
        public PlayerObjectResult VerifyPlayerCameraContext(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,Action<string> progress)
        {
            CameraVerifiedInputs(module,layout);Recheck(kernel,game);ObjectAnchors(this,game,module);
            var reads=new ObjectReads(this,game.Root,true);var result=CameraLocalContext(reads,module,layout,progress);
            result.Observations=reads.Recheck();Recheck(kernel,game);ObjectAnchors(this,game,module);return result;
        }
        private static void PlayerCameraSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout,ulong playerClass)
        {
            Expect(reads.Word(module.LoadBias+PlayerCameraReference.OffsetRva)==PlayerCameraReference.Offset,"camera field source offset");
            Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+PlayerCameraReference.MetadataOffset,12),Hex(PlayerCameraReference.FieldRecordHex)),"camera field metadata record");
            ulong descriptor=module.LoadBias+PlayerCameraReference.DescriptorRva;
            Expect(reads.Word(descriptor+8)==PlayerCameraReference.DescriptorBits && reads.Value(descriptor)==layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)PlayerCameraReference.TransformTypeIndex*88UL,"camera field runtime type descriptor");
            int count=BitConverter.ToUInt16(reads.Read(playerClass+0x124,2),0);
            Expect(count>PlayerCameraReference.LocalIndex,"camera field count");
            ulong field=checked(reads.Pointer(playerClass+0x80,"Player camera field table")+(ulong)PlayerCameraReference.LocalIndex*32UL);
            Expect(reads.Value(field)==layout.RuntimeMetadataBase+PlayerCameraReference.NameOffset && reads.Value(field+8)==descriptor && reads.Value(field+0x10)==playerClass && reads.Word(field+0x18)==PlayerCameraReference.Offset && reads.Word(field+0x1c)==PlayerCameraReference.FieldToken,"camera runtime field registration");
        }
        public PlayerCameraPoseResult SamplePlayerCameraPose(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult objects,Action<string> progress)
        {
            CameraVerifiedInputs(module,layout);
            int start=PhysicalCalls;
            using(PhysicalCallScope(6000))
            {
                for(int attempt=1;attempt<=3;attempt++)
                {
                    if(progress!=null)progress("PlayerCameraAttempt="+attempt+" MaximumAttempts=3");
                    try{using(PhysicalCallScope(4500)){var result=PlayerCameraAttempt(kernel,game,module,layout,objects,progress);result.Attempts=attempt;result.AdditionalReads=PhysicalCalls-start;return result;}}
                    catch(NativeHeadMotionException error){if(progress!=null)progress("PlayerCameraDiscarded=MOTION Detail="+error.Message);if(attempt==3)return new PlayerCameraPoseResult{Status="NOT_READY_MOTION",Detail=error.Message,Attempts=attempt,AdditionalReads=PhysicalCalls-start};}
                    catch(NativeHeadJobChangedException error){if(progress!=null)progress("PlayerCameraDiscarded=JOB_CHANGED Detail="+error.Message);if(attempt==3)return new PlayerCameraPoseResult{Status="NOT_READY_JOB_CHANGED",Detail=error.Message,Attempts=attempt,AdditionalReads=PhysicalCalls-start};}
                    catch(PhysicalScopeLimitException error){return new PlayerCameraPoseResult{Status="NOT_READY_READ_BUDGET",Detail=error.Message,Attempts=attempt,AdditionalReads=PhysicalCalls-start};}
                }
            }
            throw new InvalidOperationException("Unreachable camera attempt state");
        }
        private static int PlayerCameraRecheck(ObjectReads context,ObjectReads tree,ulong hierarchy)
        {
            int count;
            try{count=tree.RecheckNativeHierarchy(hierarchy);}
            catch(NativeHeadJobChangedException){context.Recheck();throw;}
            return count+context.Recheck();
        }
        private PlayerCameraPoseResult PlayerCameraAttempt(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult objects,Action<string> progress)
        {
            Recheck(kernel,game);var reads=new ObjectReads(this,game.Root,true);var result=new PlayerCameraPoseResult();
            ObjectAnchors(this,game,module);var contextNow=CameraLocalContext(reads,module,layout,progress);
            Expect(contextNow.CurrentGame==objects.CurrentGame && contextNow.Match==objects.Match && contextNow.LocalPlayer==objects.LocalPlayer,"camera original local context unchanged");
            // CameraLocalContext already verifies this Player family in this same observation set.
            ulong klass=reads.Pointer(objects.LocalPlayer,"camera player class");
            for(int depth=0;;depth++){ObjectClassProfile profile=ReadObjectClass(reads,klass,layout,progress);if(profile.Index==31824)break;Expect(depth<15,"camera Player ancestry bound");klass=reads.Pointer(klass+0x58,"camera player parent");}
            PlayerCameraSchema(reads,module,layout,klass);
            ulong managed=reads.Value(objects.LocalPlayer+PlayerCameraReference.Offset,"Player.MainCameraTransform");result.ManagedTransform=managed;
            if(managed==0){result.Status="NOT_READY_CAMERA_FIELD_NULL";result.Observations=reads.Recheck();Recheck(kernel,game);return result;}
            ObjectFamily(reads,managed,64,PlayerCameraReference.TransformTypeIndex,0,layout,progress);
            NativeAnchors(reads,module.LoadBias,NativeTransformReference.Il2CppAnchors);
            ulong bias=0;ulong[] cells={0xafb9e00,0xafb9e10},targets={0x45ea4c,0x45ec64};
            for(int i=0;i<2;i++){ulong target=reads.Value(module.LoadBias+cells[i],"Camera.PositionIcall"+i);if(target==0)continue;ObjectReads.User(target,4,"camera position function");Expect(target>targets[i],"camera Unity bias subtraction");ulong value=target-targets[i];ObjectReads.User(value,4096,"camera Unity bias");Expect((value&4095)==0 && (bias==0||bias==value),"camera consistent Unity bindings");bias=value;}
            if(bias==0){result.Status="NOT_READY_UNITY_BINDING";result.Observations=reads.Recheck();Recheck(kernel,game);return result;}
            Expect(EqualBytes(reads.Read(bias,64),Hex(NativeTransformReference.HeaderHex)) && EqualBytes(reads.Read(bias+64,NativeTransformReference.ProgramsHex.Length/2),Hex(NativeTransformReference.ProgramsHex)) && EqualBytes(reads.Read(bias+0x308,24),Hex(NativeTransformReference.NoteHex)),"camera Unity ELF identity");
            NativeAnchors(reads,bias,NativeTransformReference.UnityAnchors);NativeAnchors(reads,bias,NativeTransformReference.CameraRotationAnchors);
            result.UnityLoadBias=bias;ulong native=reads.Value(managed+0x10,"CameraTransform.CachedNative");result.NativeTransform=native;
            if(native==0){result.Status="NOT_READY_NATIVE_NULL";result.Observations=reads.Recheck();Recheck(kernel,game);return result;}
            ObjectReads.User(native,8,"native player camera transform");var tree=new ObjectReads(this,game.Root);ulong hierarchy=tree.Pointer(native+0x38,"camera hierarchy");int index=unchecked((int)tree.Word(native+0x40,"camera hierarchy index"));
            if(tree.Value(hierarchy,"Hierarchy.JobHandle")!=0||tree.Word(hierarchy+8,"Hierarchy.JobTag")!=0){result.Status="NOT_READY_JOB_PENDING";result.Observations=reads.Recheck()+tree.Recheck();Recheck(kernel,game);return result;}
            uint capacity=tree.Word(hierarchy+0x10,"camera hierarchy capacity");Expect(capacity>0 && capacity<=65536,"camera hierarchy capacity bound");
            ulong matrices=tree.Pointer(hierarchy+0x18,"camera TRS"),parents=tree.Pointer(hierarchy+0x20,"camera parents"),links=tree.Pointer(hierarchy+0x30,"camera transform links");
            var chain=new List<int>();var visited=new HashSet<int>();ulong expected=native;
            for(int depth=0;;depth++){
                Expect(depth<32 && index>=0 && (uint)index<capacity && visited.Add(index),"camera hierarchy depth/index/cycle");chain.Add(index);
                ulong current=tree.Pointer(checked(links+(ulong)index*8),"camera transform backlink");Expect(current==expected && tree.Value(current+0x38)==hierarchy && tree.Word(current+0x40)==(uint)index,"camera hierarchy backlinks");
                int parent=unchecked((int)tree.Word(checked(parents+(ulong)index*4)));expected=tree.Value(current+0x90,"camera parent transform");
                if(parent==-1){Expect(expected==0,"camera root parent backlink");break;}Expect(parent>=0 && (uint)parent<capacity && expected!=0,"camera parent link");index=parent;
            }
            PlayerCameraRecheck(reads,tree,hierarchy);List<NativeTrsChunk> chunks=NativeChunks(chain);
            Dictionary<int,byte[]> first=NativeCapture(game,matrices,chunks,false),second=NativeCapture(game,matrices,chunks,true);
            foreach(int node in chain)if(!EqualBytes(first[node],second[node])){PlayerCameraRecheck(reads,tree,hierarchy);throw new NativeHeadMotionException("PLAYER_CAMERA_TRS_CHANGED Index="+node);}
            float[] position=null,rotation=null;
            foreach(int node in chain){byte[] trs=second[node];float[] q=NativeVector(trs,16,4);NativeVector(trs,32,3);position=position==null?NativeVector(trs,0,3):NativeParentPosition(position,trs);rotation=rotation==null?q:CameraParentRotation(rotation,trs);CameraQuaternionNorm(rotation);for(int axis=0;axis<3;axis++)Expect(!float.IsNaN(position[axis])&&!float.IsInfinity(position[axis])&&Math.Abs(position[axis])<=10000000,"bounded player camera position");}
            result.Observations=PlayerCameraRecheck(reads,tree,hierarchy)+chain.Count;Recheck(kernel,game);
            result.Position=Array.ConvertAll(position,delegate(float x){return (double)x;});result.Rotation=Array.ConvertAll(rotation,delegate(float x){return (double)x;});result.ParentCount=chain.Count-1;result.Status="SAMPLED_READ_ONLY";return result;
        }
    }
}
