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
            sample.AimRotationStatus="ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED";
        }
        public PlayerStateResult SampleAimState(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1,false,false,false,false,true); }
    }
}
