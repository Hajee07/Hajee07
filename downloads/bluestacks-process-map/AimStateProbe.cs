using System;
namespace HeadBridge.Mapping
{
    public sealed partial class Reader
    {
        private void AimStateCode(KernelContext kernel,GameProcess game,ModuleResult module)
        {
            StateCode(kernel,game,module);
            foreach(GameLayoutCheck c in AimStateReference.Anchors)
                Expect(EqualBytes(Virtual(game.Root,module.LoadBias+c.Address,c.Expected(module.LoadBias).Length),c.Expected(module.LoadBias)),"aim getter code "+c.Name);
        }
        private static void AimStateSchema(ObjectReads reads,ModuleResult module,GameLayoutResult layout)
        {
            CombatSchema(reads,module,layout,new StateMethod[]{AimStateReference.Method,AimStateReference.VectorMethod},AimStateReference.Fields);
            CombatSchema(reads,module,layout,AimStateReference.CameraMethods,new StateField[0]);
            Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata,88),Hex(AimStateReference.QuaternionRecord)),"aim Quaternion metadata identity");
            Expect(reads.Word(module.LoadBias+AimStateReference.ReturnDescriptor+8)==AimStateReference.ReturnBits &&
                reads.Value(module.LoadBias+AimStateReference.ReturnDescriptor)==layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata,"aim getter return Quaternion type");
        }
        // Explicit float intermediates preserve the verified scalar ARM64 operation order.
        // This evaluates q * (0,0,1); it does not establish camera/shot convention.
        internal static float[] PositiveZBasis(float x,float y,float z,float w)
        {
            float x2=x+x,y2=y+y,z2=z+z;
            float xx=x*x2,yy=y*y2,zz=z*z2,xy=x*y2,xz=x*z2,yz=y*z2;
            float wx=w*x2,wy=w*y2,wz=w*z2;
            float yyzz=yy+zz,xxzz=xx+zz,xyMinusWz=xy-wz,xyPlusWz=xy+wz;
            float xzPlusWy=xz+wy,xzMinusWy=xz-wy,yzMinusWx=yz-wx,yzPlusWx=yz+wx,xxYy=xx+yy;
            float a=1f-yyzz,b=1f-xxzz,c=1f-xxYy;
            float p0=0f*xyMinusWz,p1=0f*xyPlusWz,p2=0f*xzMinusWy,p3=0f*yzPlusWx;
            float p4=0f*a,p5=0f*b,p6=1f*xzPlusWy,p7=1f*yzMinusWx;
            float t0=p2+p3,p8=1f*c,t1=p0+p4,t2=p1+p5;
            return new float[]{p6+t1,p7+t2,t0+p8};
        }
        private static void ReadCameraUnityCode(ObjectReads reads,PlayerStateObservation sample,ulong camera,ulong transform)
        {
            sample.CameraUnityCodeStatus="NOT_READY_UNINITIALIZED_ICALL";
            if(camera==0 || transform==0)return;
            Expect(camera>NativeTransformReference.CameraMainTarget && transform>NativeTransformReference.ComponentTransformTarget,"camera Unity bias subtraction");
            ulong bias=camera-NativeTransformReference.CameraMainTarget;
            Expect(transform-NativeTransformReference.ComponentTransformTarget==bias && (bias&4095UL)==0,"camera Unity consistent page-aligned bias");
            ObjectReads.User(bias,4096,"camera Unity load bias");
            Expect(camera>=checked(bias+NativeTransformReference.CameraExecutableStart) && camera<checked(bias+NativeTransformReference.CameraExecutableEnd) &&
                transform>=checked(bias+NativeTransformReference.CameraExecutableStart) && transform<checked(bias+NativeTransformReference.CameraExecutableEnd),"camera targets in expected executable ELF load segment");
            Expect(EqualBytes(reads.Read(bias,64),Hex(NativeTransformReference.HeaderHex)),"camera Unity ELF header");
            Expect(EqualBytes(reads.Read(bias+64,NativeTransformReference.ProgramsHex.Length/2),Hex(NativeTransformReference.ProgramsHex)),"camera Unity ELF program tables");
            Expect(EqualBytes(reads.Read(bias+0x308,24),Hex(NativeTransformReference.NoteHex)),"camera Unity build ID");
            NativeAnchors(reads,bias,NativeTransformReference.CameraAnchors);
            sample.CameraUnityLoadBias=bias;sample.CameraUnityCodeStatus="REGISTERED_ENTRIES_AND_CODE_VERIFIED";
        }
        internal static uint CameraTagHash(uint key)
        {
            unchecked {
                uint v=key+(key<<12)+0x7ed55d16U;v^=v>>19;v^=0xc761c23cU;v+=v<<5;
                v=(v+0xe9f8cc1dU)^(0xaccf6200U+(v<<9));v+=v<<3;v+=0xfd7046c5U;v^=v>>16;return v^0xb55a4f09U;
            }
        }
        private static void ReadNativeCameraCandidate(ObjectReads reads,PlayerStateObservation sample)
        {
            sample.CameraSelectionStatus="NOT_READY_SOURCE_SELECTION";
            sample.CameraCandidateStatus="NOT_READY_UNITY_CODE";
            if(sample.CameraUnityCodeStatus!="REGISTERED_ENTRIES_AND_CODE_VERIFIED")return;
            ulong bias=sample.CameraUnityLoadBias;NativeAnchors(reads,bias,NativeTransformReference.CameraSelectorAnchors);
            sample.CameraCandidateStatus="NOT_READY_TAG_MANAGER_NULL";
            ulong manager=reads.Value(bias+NativeTransformReference.CameraTagManagerCell,"Camera.TagManager");if(manager==0)return;
            ObjectReads.User(manager,8,"camera tag manager");byte[] header=reads.Read(manager,16,"Camera.TagMapHeader");
            ulong buckets=BitConverter.ToUInt64(header,0);uint mask=BitConverter.ToUInt32(header,8);
            uint capacity=(mask>>3)+1;Expect((mask&7)==0 && capacity>=2 && capacity<=4096 && (capacity&(capacity-1))==0,"camera tag map mask/capacity");
            ObjectReads.User(buckets,8,"camera tag buckets");uint hash=CameraTagHash(5),index=hash&mask,step=8;ulong head=0;
            sample.CameraCandidateStatus="NOT_READY_TAG_LOOKUP_LIMIT";
            for(int probe=0;probe<16;probe++)
            {
                sample.CameraTagProbes=probe+1;byte[] slot=reads.Read(checked(buckets+(ulong)index*3UL),24,"Camera.Tag5Probe"+probe);
                uint stored=BitConverter.ToUInt32(slot,0);
                if(stored==(hash&0xfffffffcU) && BitConverter.ToUInt32(slot,8)==5){head=BitConverter.ToUInt64(slot,16);break;}
                if(stored==uint.MaxValue){sample.CameraCandidateStatus="NOT_READY_TAG5_ABSENT";return;}
                index=unchecked(index+step)&mask;step=unchecked(step+8);
            }
            if(head==0){sample.CameraCandidateStatus="NOT_READY_TAG_LIST_NULL_OR_LOOKUP_LIMIT";return;}
            ObjectReads.User(head,8,"camera tag list sentinel");byte[] sentinel=reads.Read(head,16,"Camera.TagListSentinel");
            ulong node=BitConverter.ToUInt64(sentinel,8),previous=head;System.Collections.Generic.HashSet<ulong> visited=new System.Collections.Generic.HashSet<ulong>();
            byte[] range=reads.Read(bias+NativeTransformReference.CameraTypeDescriptor+0x30,8,"Camera.NativeTypeRange");uint first=BitConverter.ToUInt32(range,0),span=BitConverter.ToUInt32(range,4);
            sample.CameraCandidateStatus="NOT_READY_CAMERA_TYPE_RANGE";if(span==0 || span>4096)return;
            for(int n=0;n<2;n++)
            {
                if(node==head){if(sample.CameraCandidateObject==0)sample.CameraCandidateStatus="NOT_READY_NO_CAMERA_IN_VISITED_NODES";sample.CameraSelectionStatus="ORIGINAL_UNITY_MAIN_NULL_READ_ONLY";sample.CameraSelectionComplete=true;return;}
                ObjectReads.User(node,8,"camera tag node");Expect(visited.Add(node),"camera tag-list cycle");sample.CameraNodesVisited=n+1;
                byte[] item=reads.Read(node,24,"Camera.TagNode"+n);Expect(BitConverter.ToUInt64(item,0)==previous,"camera tag-list previous link");
                ulong obj=BitConverter.ToUInt64(item,16);ObjectReads.User(obj,8,"tagged native game object");
                byte[] components=reads.Read(obj+0x30,24,"Camera.ComponentArrayHeader"+n);ulong entries=BitConverter.ToUInt64(components,0),count=BitConverter.ToUInt64(components,16);
                sample.CameraCandidateStatus="NOT_READY_COMPONENT_BOUND";if(count>256)return;
                if(count!=0)
                {
                    ObjectReads.User(entries,8,"camera component array");byte[] rows=reads.Read(entries,checked((int)count*16),"Camera.ComponentArray"+n);
                    for(int c=0;c<(int)count;c++)
                    {
                        uint id=BitConverter.ToUInt32(rows,c*16);if(unchecked(id-first)>=span)continue;
                        ulong candidate=BitConverter.ToUInt64(rows,c*16+8);ObjectReads.User(candidate,8,"native camera component candidate");
                        Expect(reads.Value(candidate+0x30,"Camera.CandidateOwner")==obj,"native camera candidate owner");
                        ulong vtable=reads.Pointer(candidate,"native camera vtable"),predicate=reads.Value(vtable+0xd0,"Camera.NativePredicateFunction");ObjectReads.User(predicate,4,"native camera predicate function");
                        Expect(predicate>=bias+NativeTransformReference.CameraExecutableStart && predicate<bias+NativeTransformReference.CameraExecutableEnd,"camera predicate in reference executable range");
                        sample.CameraCandidateObject=candidate;sample.CameraCandidateOwner=obj;sample.CameraPredicateFunction=predicate;sample.CameraPredicateRva=predicate-bias;
                        sample.CameraCandidateStatus="TYPE_RANGE_CANDIDATE_ONLY";
                        sample.CameraPredicateRaw=null;sample.CameraPredicateValue=null;
                        if(predicate!=bias+NativeTransformReference.CameraPredicateTarget){sample.CameraSelectionStatus="UNVERIFIED_PREDICATE_OVERRIDE";return;}
                        NativeAnchors(reads,bias,NativeTransformReference.CameraPredicateAnchors);
                        byte rawPredicate=reads.Byte(candidate+NativeTransformReference.CameraPredicateByteOffset,"Camera.NativePredicateByte");
                        sample.CameraPredicateRaw=rawPredicate;sample.CameraPredicateValue=rawPredicate!=0;sample.CameraPredicatesEvaluated++;
                        if(rawPredicate!=0){sample.SelectedNativeCamera=candidate;sample.SelectedNativeCameraOwner=obj;sample.CameraSelectionStatus="ORIGINAL_UNITY_MAIN_SELECTED_READ_ONLY";sample.CameraSelectionComplete=true;return;}
                        // The original selector advances to the next tagged object after
                        // a false predicate, not a later component on this object.
                        break;
                    }
                }
                previous=node;node=BitConverter.ToUInt64(item,8);
            }
            if(node==head){if(sample.CameraCandidateObject==0)sample.CameraCandidateStatus="NOT_READY_NO_CAMERA_IN_VISITED_NODES";sample.CameraSelectionStatus="ORIGINAL_UNITY_MAIN_NULL_READ_ONLY";sample.CameraSelectionComplete=true;return;}
            sample.CameraSelectionStatus="NOT_READY_TAG_NODE_LIMIT";
            if(sample.CameraCandidateObject==0)sample.CameraCandidateStatus="NOT_READY_TAG_NODE_LIMIT";
        }
        // Only the native intermediate of Component.get_transform is evaluated.
        // Managed wrapper resolution, game getter selection and rotation are not inferred.
        private static void ReadCameraPosition(ObjectReads reads,PlayerStateObservation sample)
        {
            sample.CameraPositionStatus="NOT_READY_NATIVE_SELECTION";
            if(sample.CameraSelectionStatus!="ORIGINAL_UNITY_MAIN_SELECTED_READ_ONLY" || !sample.CameraSelectionComplete)return;
            ulong owner=sample.SelectedNativeCameraOwner;
            byte[] header=reads.Read(owner+0x30,24,"Camera.TransformComponentHeader");
            ulong entries=BitConverter.ToUInt64(header,0),count=BitConverter.ToUInt64(header,16);
            sample.CameraPositionStatus="NOT_READY_COMPONENT_BOUND";if(count==0 || count>256)return;
            ObjectReads.User(entries,8,"camera Transform component table");
            ulong native=reads.Value(entries+8,"Camera.FirstNativeComponent");
            sample.CameraPositionStatus="NOT_READY_FIRST_COMPONENT_IS_CAMERA";if(native==sample.SelectedNativeCamera)return;
            ObjectReads.User(native,8,"camera native Transform intermediate");
            Expect(reads.Value(native+0x30,"Camera.TransformOwner")==owner,"camera Transform owner backlink");
            ulong data=reads.Pointer(native+0x38,"camera Transform hierarchy");
            int index=unchecked((int)reads.Word(native+0x40,"Camera.TransformIndex"));
            sample.CameraPositionStatus="NOT_READY_HIERARCHY_JOB_PENDING";
            if(reads.Value(data,"Camera.HierarchyJob")!=0 || reads.Word(data+8,"Camera.HierarchyJobTag")!=0)return;
            uint capacity=reads.Word(data+0x10,"Camera.HierarchyCapacity");
            Expect(capacity>0 && capacity<=65536 && index>=0 && (uint)index<capacity,"camera hierarchy capacity/index");
            ulong matrices=reads.Pointer(data+0x18,"camera TRS array"),parents=reads.Pointer(data+0x20,"camera parent indices"),links=reads.Pointer(data+0x30,"camera Transform backlinks");
            NativeAnchors(reads,sample.CameraUnityLoadBias,NativeTransformReference.UnityAnchors);
            var visited=new System.Collections.Generic.HashSet<int>();float[] position=null;ulong expected=native;
            for(int depth=0;depth<32;depth++)
            {
                Expect(index>=0 && (uint)index<capacity && visited.Add(index),"camera parent bounds/cycle");
                ulong current=reads.Pointer(checked(links+(ulong)index*8),"camera hierarchy object");
                Expect(current==expected && reads.Value(current+0x38,"Camera.HierarchyBacklink")==data && reads.Word(current+0x40,"Camera.IndexBacklink")==unchecked((uint)index),"camera Transform hierarchy backlinks");
                byte[] trs=reads.Read(checked(matrices+(ulong)index*48),48,"Camera.SelectedTRS"+depth);
                NativeVector(trs,0,3);NativeVector(trs,16,4);NativeVector(trs,32,3);
                position=depth==0?NativeVector(trs,0,3):NativeParentPosition(position,trs);
                for(int axis=0;axis<3;axis++)Expect(!float.IsNaN(position[axis]) && !float.IsInfinity(position[axis]) && Math.Abs(position[axis])<=10000000,"finite bounded camera world position");
                int parent=unchecked((int)reads.Word(checked(parents+(ulong)index*4),"Camera.ParentIndex"));
                expected=reads.Value(current+0x90,"Camera.ParentTransform");
                if(parent==-1)
                {
                    Expect(expected==0,"camera root parent backlink");sample.CameraNativeTransform=native;sample.CameraParentCount=depth;
                    sample.CameraWorldX=position[0];sample.CameraWorldY=position[1];sample.CameraWorldZ=position[2];
                    sample.CameraPositionStatus="ORIGINAL_NATIVE_CAMERA_WORLD_POSITION_READ_ONLY";return;
                }
                Expect(parent>=0 && (uint)parent<capacity && expected!=0,"camera parent-index/object link");index=parent;
            }
            sample.CameraPositionStatus="NOT_READY_PARENT_LIMIT";
        }
        private static void ReadAimState(ObjectReads reads,ModuleResult module,GameLayoutResult layout,PlayerStateObservation sample,ulong playerBase,ulong wrappers,ulong length)
        {
            Expect(sample.IsLocal,"aim snapshot is local only");sample.AimRotationStatus="UNVERIFIED_AIM_GETTER_HOTFIX_ACTIVE";
            if(!CombatGate(reads,wrappers,length,0x4b9))return;
            sample.AimRotationStatus="NOT_READY_AIM_FIELD_TABLE";if(reads.Value(playerBase+0x80,"Aim.FieldTable")==0)return;
            CombatFields(reads,playerBase,31824,module,layout,AimStateReference.Fields);
            byte[] raw=reads.Read(sample.Player+0x614,16,"Aim.GetAimRotationBackingField");float[] value=new float[4];double norm=0;
            for(int i=0;i<4;i++)
            {
                value[i]=BitConverter.ToSingle(raw,i*4);
                if(float.IsNaN(value[i]) || float.IsInfinity(value[i])){sample.AimRotationStatus="NOT_READY_AIM_ROTATION_NONFINITE";return;}
                norm+=(double)value[i]*value[i];
            }
            if(norm<0.98 || norm>1.02){sample.AimRotationStatus="NOT_READY_AIM_ROTATION_NONUNIT";return;}
            sample.AimX=value[0];sample.AimY=value[1];sample.AimZ=value[2];sample.AimW=value[3];sample.AimNormSquared=norm;
            float[] basis=PositiveZBasis(value[0],value[1],value[2],value[3]);
            sample.BasisX=basis[0];sample.BasisY=basis[1];sample.BasisZ=basis[2];
            ulong camera=reads.Value(module.LoadBias+AimStateReference.CameraMainCell,"Camera.MainICallCache");
            ulong transform=reads.Value(module.LoadBias+AimStateReference.ComponentTransformCell,"Camera.ComponentTransformICallCache");
            if(camera!=0)ObjectReads.User(camera,1,"camera main icall function pointer");
            if(transform!=0)ObjectReads.User(transform,1,"component transform icall function pointer");
            sample.CameraMainICall=camera;sample.ComponentTransformICall=transform;
            sample.CameraBindingStatus=camera==0 || transform==0 ? "NOT_READY_UNINITIALIZED_ICALL" : "NONZERO_FUNCTION_POINTERS_ONLY";
            ReadCameraUnityCode(reads,sample,camera,transform);
            ReadNativeCameraCandidate(reads,sample);
            ReadCameraPosition(reads,sample);
            sample.AimRotationStatus="ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED";
        }
        public PlayerStateResult SampleAimState(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1,false,false,false,false,true); }
    }
}
