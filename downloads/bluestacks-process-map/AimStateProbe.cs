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
            CombatSchema(reads,module,layout,new StateMethod[]{AimStateReference.Method},AimStateReference.Fields);
            Expect(EqualBytes(reads.Read(layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata,88),Hex(AimStateReference.QuaternionRecord)),"aim Quaternion metadata identity");
            Expect(reads.Word(module.LoadBias+AimStateReference.ReturnDescriptor+8)==AimStateReference.ReturnBits &&
                reads.Value(module.LoadBias+AimStateReference.ReturnDescriptor)==layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata,"aim getter return Quaternion type");
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
            sample.AimRotationStatus="ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED";
        }
        public PlayerStateResult SampleAimState(KernelContext kernel,GameProcess game,ModuleResult module,GameLayoutResult layout,PlayerObjectResult core,Action<string> progress)
        { return SamplePlayerStatesCore(kernel,game,module,layout,core,progress,false,-1,false,false,false,false,true); }
    }
}
