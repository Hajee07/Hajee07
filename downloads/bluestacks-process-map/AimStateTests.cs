using System;
namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal void AimValue(float x,float y,float z,float w)
            { float[] v={x,y,z,w};for(int i=0;i<4;i++)Put(Player+0x614UL+(ulong)i*4UL,BitConverter.GetBytes(v[i])); }
            internal void SetupAim()
            {
                SetupCombat();
                foreach(GameLayoutCheck c in AimStateReference.Anchors)Put(Module.LoadBias+c.Address,c.Expected(Module.LoadBias));
                foreach(StateMethod m in new StateMethod[]{AimStateReference.Method,AimStateReference.VectorMethod}) {U64(Module.LoadBias+m.PointerRva,Module.LoadBias+m.Rva);Put(Layout.RuntimeMetadataBase+m.MetadataOffset,Reader.Hex(m.RecordHex)); }
                foreach(StateMethod cm in AimStateReference.CameraMethods){U64(Module.LoadBias+cm.PointerRva,Module.LoadBias+cm.Rva);Put(Layout.RuntimeMetadataBase+cm.MetadataOffset,Reader.Hex(cm.RecordHex));}
                U64(Module.LoadBias+AimStateReference.CameraMainCell,Unity+NativeTransformReference.CameraMainTarget);U64(Module.LoadBias+AimStateReference.ComponentTransformCell,Unity+NativeTransformReference.ComponentTransformTarget);
                foreach(GameLayoutCheck ca in NativeTransformReference.CameraAnchors)Put(Unity+ca.Address,ca.Expected(Unity));
                Put(Layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata,Reader.Hex(AimStateReference.QuaternionRecord));
                U64(Module.LoadBias+AimStateReference.ReturnDescriptor,Layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata);U32(Module.LoadBias+AimStateReference.ReturnDescriptor+8,AimStateReference.ReturnBits);
                foreach(StateField f in AimStateReference.Fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,(uint)f.Offset);Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    if(f.Owner==31824){ulong at=0xc0000000UL+(ulong)f.Owner*0x10000UL+(ulong)f.Local*32UL;U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);}
                }
                U64(Array+0x20+0x4b9UL*8UL,0);AimValue(0,0,0,1);
                Put(Player+0x1a8c,BitConverter.GetBytes(float.NaN));
            }
            internal PlayerStateResult Aim(PlayerObjectResult core)
            { return Reader.SampleAimState(Kernel,Game,Module,Layout,core,Progress.Add); }
        }
        private static Fixture AimFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupAim();return f; }
        private static PlayerStateObservation AimSample(Fixture f)
        { PlayerStateResult r=f.Aim(f.Run());if(r.Sampled!=1)throw new Exception("Aim sample failed "+r.StopReason+" "+r.Detail+(r.Samples.Length>0?" "+r.Samples[0].Detail:""));return r.Samples[0]; }
        private static void RunAimStateTests()
        {
            float[][] values={new float[]{0,0,0,1},new float[]{0,0,0,-1},new float[]{0,1,0,0},new float[]{1,0,0,0},new float[]{0,0,1,0}};
            float[][] expected={new float[]{0,0,1},new float[]{0,0,1},new float[]{0,0,-1},new float[]{0,0,-1},new float[]{0,0,1}};
            for(int i=0;i<values.Length;i++){float[] v=values[i],a=Reader.PositiveZBasis(v[0],v[1],v[2],v[3]);Check(a[0]==expected[i][0] && a[1]==expected[i][1] && a[2]==expected[i][2],"positive-Z basis identity/sign/half-turn case "+i);}
            float h=(float)Math.Sqrt(0.5);float[] yaw=Reader.PositiveZBasis(0,h,0,h),pitch=Reader.PositiveZBasis(h,0,0,h);
            Check(Math.Abs(yaw[0]-1)<0.000001 && yaw[1]==0 && Math.Abs(yaw[2])<0.000001,"positive yaw rotates positive-Z toward positive-X");
            Check(pitch[0]==0 && Math.Abs(pitch[1]+1)<0.000001 && Math.Abs(pitch[2])<0.000001,"positive pitch rotates positive-Z toward negative-Y");
            Fixture vectorCode=AimFixture();vectorCode.Put(vectorCode.Module.LoadBias+0x9fddc4c,new byte[]{0});PlayerStateResult badCode=vectorCode.Aim(vectorCode.Run());Check(badCode.Sampled==0 && badCode.Samples.Length==0,"changed Unity multiply code suppresses rotation and derived basis");
            Fixture vectorPointer=AimFixture();vectorPointer.U64(vectorPointer.Module.LoadBias+AimStateReference.VectorMethod.PointerRva,0);PlayerStateResult badPointer=vectorPointer.Aim(vectorPointer.Run());Check(badPointer.Sampled==0 && badPointer.Samples.Length==0,"Unity multiply requires its own registered CoreModule method pointer");
            Fixture basisFixture=AimFixture();PlayerStateObservation bs=AimSample(basisFixture);Check(bs.BasisX==0 && bs.BasisY==0 && bs.BasisZ==1,"derived basis is published only with the validated local quaternion");
            float[] cyclic=Reader.PositiveZBasis(0.5f,0.5f,0.5f,0.5f);Check(cyclic[0]==1 && cyclic[1]==0 && cyclic[2]==0,"mixed-axis Quaternion preserves component cross terms");
            Fixture notNormalized=AimFixture();notNormalized.AimValue(0.1f,0,0,1);PlayerStateObservation nn=AimSample(notNormalized);Check(Math.Abs(nn.BasisY.Value+0.2f)<0.000001 && Math.Abs(nn.BasisZ.Value-0.98f)<0.000001 && nn.AimW==1,"basis calculation preserves accepted source values without normalization");
            Fixture coreTable=AimFixture();coreTable.U64(coreTable.Module.LoadBias+0xa729480,0);PlayerStateResult ct=coreTable.Aim(coreTable.Run());Check(ct.Sampled==0 && ct.Samples.Length==0,"changed CoreModule table invalidates derived basis");
            Fixture vectorMetadata=AimFixture();vectorMetadata.Put(vectorMetadata.Layout.RuntimeMetadataBase+AimStateReference.VectorMethod.MetadataOffset,new byte[]{0});PlayerStateResult vm=vectorMetadata.Aim(vectorMetadata.Run());Check(vm.Sampled==0 && vm.Samples.Length==0,"multiply metadata identity is required");
            Fixture finalVector=AimFixture();PlayerObjectResult fvcore=finalVector.Run();ulong fva=finalVector.Physical(Fixture.Player+0x614);
            finalVector.Memory.AfterRead=delegate(ulong p,int n){if(p==fva && n==16)finalVector.Put(finalVector.Module.LoadBias+0x9fddc4c,new byte[]{0});};PlayerStateResult fvr=finalVector.Aim(fvcore);Check(fvr.Sampled==0 && fvr.Samples.Length==0 && fvr.StopReason=="FINAL_CONTEXT_FAILED","changed final multiply code clears tentative rotation and basis");
            Fixture camera=AimFixture();PlayerStateObservation cb=AimSample(camera);Check(cb.CameraBindingStatus=="NONZERO_FUNCTION_POINTERS_ONLY" && cb.CameraMainICall==Fixture.Unity+NativeTransformReference.CameraMainTarget && cb.ComponentTransformICall==Fixture.Unity+NativeTransformReference.ComponentTransformTarget,"camera icall caches expose function pointers only after source and local snapshot verification");
            foreach(ulong cell in new ulong[]{AimStateReference.CameraMainCell,AimStateReference.ComponentTransformCell}) {
                Fixture zero=AimFixture();zero.U64(zero.Module.LoadBias+cell,0);PlayerStateObservation zz=AimSample(zero);Check(zz.CameraBindingStatus=="NOT_READY_UNINITIALIZED_ICALL" && zz.CameraUnityCodeStatus=="NOT_READY_UNINITIALIZED_ICALL" && zz.CameraUnityLoadBias==0 && zz.AimW.HasValue,"uninitialized camera binding stays explicit without invoking initialization: "+cell);
                Fixture invalid=AimFixture();invalid.U64(invalid.Module.LoadBias+cell,0xffff000000000000);PlayerStateResult ir=invalid.Aim(invalid.Run());Check(ir.Sampled==0 && !ir.Samples[0].CameraMainICall.HasValue,"noncanonical icall address never publishes tentative binding: "+cell);
            }
            Fixture movedCamera=AimFixture();PlayerObjectResult movedCore=movedCamera.Run();ulong movedAt=movedCamera.Physical(movedCamera.Module.LoadBias+AimStateReference.CameraMainCell);bool moved=false;
            movedCamera.Memory.AfterRead=delegate(ulong p,int n){if(!moved && p==movedAt && n==8){moved=true;movedCamera.U64(movedCamera.Module.LoadBias+AimStateReference.CameraMainCell,0x7002000);}};PlayerStateResult mcr=movedCamera.Aim(movedCore);Check(mcr.Sampled==0 && !mcr.Samples[0].CameraMainICall.HasValue,"changing camera icall binding discards the tentative snapshot");
            Fixture cameraMethod=AimFixture();cameraMethod.U64(cameraMethod.Module.LoadBias+AimStateReference.CameraMethods[1].PointerRva,0);PlayerStateResult cmr=cameraMethod.Aim(cameraMethod.Run());Check(cmr.Sampled==0 && cmr.Samples.Length==0,"camera main method must use its verified owning CoreModule registration");
            Fixture cameraCode=AimFixture();cameraCode.Put(cameraCode.Module.LoadBias+0x9fa01d8,new byte[]{0});PlayerStateResult ccr=cameraCode.Aim(cameraCode.Run());Check(ccr.Sampled==0 && ccr.Samples.Length==0,"changed Camera.main wrapper cannot establish a typed binding");
            Fixture cameraMetadata=AimFixture();cameraMetadata.Put(cameraMetadata.Layout.RuntimeMetadataBase+AimStateReference.CameraMethods[1].MetadataOffset,new byte[]{0});PlayerStateResult cmm=cameraMetadata.Aim(cameraMetadata.Run());Check(cmm.Sampled==0 && cmm.Samples.Length==0,"camera wrapper metadata identity must match its original source record");
            Fixture cameraName=AimFixture();cameraName.Put(cameraName.Module.LoadBias+0x1966d4b,new byte[]{0});PlayerStateResult cn=cameraName.Aim(cameraName.Run());Check(cn.Sampled==0 && cn.Samples.Length==0,"camera native icall name bytes are verified rather than inferred from function names alone");
            Fixture finalCamera=AimFixture();PlayerObjectResult fcc=finalCamera.Run();ulong fca=finalCamera.Physical(Fixture.Player+0x614);finalCamera.Memory.AfterRead=delegate(ulong p,int n){if(p==fca && n==16)finalCamera.Put(finalCamera.Module.LoadBias+0x9fe7aa8,new byte[]{0});};PlayerStateResult fcr=finalCamera.Aim(fcc);Check(fcr.Sampled==0 && fcr.Samples.Length==0 && fcr.StopReason=="FINAL_CONTEXT_FAILED","changed final component wrapper clears all tentative binding and quaternion data");
            Fixture unityCamera=AimFixture();PlayerStateObservation uc=AimSample(unityCamera);Check(uc.CameraUnityCodeStatus=="REGISTERED_ENTRIES_AND_CODE_VERIFIED" && uc.CameraUnityLoadBias==Fixture.Unity,"two camera caches resolve to exact registered entries in the verified Unity ELF executable segment");
            Fixture splitBias=AimFixture();PlayerObjectResult sbc=splitBias.Run();splitBias.U64(splitBias.Module.LoadBias+AimStateReference.ComponentTransformCell,Fixture.Unity+NativeTransformReference.ComponentTransformTarget+4096);PlayerStateResult sbr=splitBias.Aim(sbc);Check(sbr.Sampled==0 && !sbr.Samples[0].CameraMainICall.HasValue,"camera native entries cannot come from different candidate load biases");
            Fixture underflow=AimFixture();PlayerObjectResult ufc=underflow.Run();underflow.U64(underflow.Module.LoadBias+AimStateReference.CameraMainCell,0x10000);PlayerStateResult ufr=underflow.Aim(ufc);Check(ufr.Sampled==0,"camera bias subtraction cannot underflow");
            Fixture misaligned=AimFixture();PlayerObjectResult mac=misaligned.Run();misaligned.U64(misaligned.Module.LoadBias+AimStateReference.CameraMainCell,Fixture.Unity+NativeTransformReference.CameraMainTarget+1);misaligned.U64(misaligned.Module.LoadBias+AimStateReference.ComponentTransformCell,Fixture.Unity+NativeTransformReference.ComponentTransformTarget+1);PlayerStateResult mar=misaligned.Aim(mac);Check(mar.Sampled==0,"consistent but non-page-aligned camera biases are rejected");
            foreach(ulong relative in new ulong[]{0,64,0x308,0x468ddc,0x46dabc,0x11aa87,0x125f6b,0x41d8c4,0x453d04,0x453dfc}) {
                Fixture mutation=AimFixture();PlayerObjectResult mutationCore=mutation.Run();byte original=relative==0?(byte)0x7f:relative==64?(byte)6:relative==0x308?(byte)4:(byte)0;foreach(GameLayoutCheck nativeCameraAnchor in NativeTransformReference.CameraAnchors){byte[] nativeAnchorBytes=nativeCameraAnchor.Expected(Fixture.Unity);if(relative>=nativeCameraAnchor.Address && relative<nativeCameraAnchor.Address+(ulong)nativeAnchorBytes.Length)original=nativeAnchorBytes[(int)(relative-nativeCameraAnchor.Address)];}mutation.Put(Fixture.Unity+relative,new byte[]{(byte)(original^1)});PlayerStateResult mutated=mutation.Aim(mutationCore);Check(mutated.Sampled==0 && mutated.Samples.Length==1 && !mutated.Samples[0].CameraMainICall.HasValue,"changed Unity header/program/note/registration/name/code suppresses tentative camera identity: "+relative);
            }
            Fixture lateUnity=AimFixture();PlayerObjectResult luc=lateUnity.Run();ulong lca=lateUnity.Physical(Fixture.Unity+NativeTransformReference.CameraMainTarget);bool lchanged=false;
            lateUnity.Memory.AfterRead=delegate(ulong p,int n){if(!lchanged && p==lca && n==24){lchanged=true;lateUnity.Put(Fixture.Unity+NativeTransformReference.CameraMainTarget,new byte[]{0xff});}};PlayerStateResult lur=lateUnity.Aim(luc);Check(lur.Sampled==0 && !lur.Samples[0].CameraMainICall.HasValue,"changing native camera code during capture invalidates the entire tentative snapshot");
            Fixture f=AimFixture();PlayerObjectResult core=f.Run();int start=f.Reader.PhysicalCalls;PlayerStateResult baseline=f.Aim(core);PlayerStateObservation b=baseline.Samples.Length>0?baseline.Samples[0]:new PlayerStateObservation();
            Check(baseline.Sampled==1 && b.AimRotationStatus=="ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED" && b.AimX==0 && b.AimY==0 && b.AimZ==0 && b.AimW==1 && b.AimNormSquared==1 && b.IsLocal && b.MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "original local getter reads verified +0x614 Quaternion, not separate m_CurrentAimRotation: "+baseline.StopReason+" "+baseline.Detail+" "+b.Detail);
            Check(f.Reader.PhysicalCalls-start<=6000,"aim-state phase retains 6000-call limit and final checks");Console.WriteLine("AIM_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            Fixture sign=AimFixture();sign.AimValue(0,0,0,-1);Check(AimSample(sign).AimW==-1,"negative Quaternion sign is preserved without changing orientation convention");
            Fixture rotated=AimFixture();float s=(float)Math.Sqrt(0.5);rotated.AimValue(0,s,0,s);PlayerStateObservation rs=AimSample(rotated);
            Check(rs.AimY==s && rs.AimW==s && Math.Abs(rs.AimNormSquared.Value-1)<0.00001,"component order follows verified Unity Quaternion x/y/z/w layout");
            foreach(float invalid in new float[]{float.NaN,float.PositiveInfinity,float.NegativeInfinity})
            { Fixture x=AimFixture();x.AimValue(invalid,0,0,1);PlayerStateObservation q=AimSample(x);Check(!q.AimX.HasValue && !q.AimW.HasValue && !q.BasisZ.HasValue && q.AimRotationStatus=="NOT_READY_AIM_ROTATION_NONFINITE","nonfinite quaternion never publishes tentative components: "+invalid); }
            foreach(float w in new float[]{0,0.5f,2})
            { Fixture x=AimFixture();x.AimValue(0,0,0,w);PlayerStateObservation q=AimSample(x);Check(!q.AimW.HasValue && q.AimRotationStatus=="NOT_READY_AIM_ROTATION_NONUNIT","nonunit quaternion is not silently normalized: "+w); }
            Fixture hot=AimFixture();hot.U64(Fixture.Array+0x20+0x4b9UL*8UL,Fixture.Player);PlayerStateObservation hs=AimSample(hot);
            Check(!hs.AimW.HasValue && hs.AimRotationStatus=="UNVERIFIED_AIM_GETTER_HOTFIX_ACTIVE","active aim getter hotfix suppresses the original field interpretation");
            Fixture offset=AimFixture();StateField field=AimStateReference.Fields[0];offset.U32(offset.Module.LoadBias+field.OffsetRva,0x1a8c);PlayerStateResult of=offset.Aim(offset.Run());
            Check(of.Sampled==0 && of.Samples.Length==0 && of.Detail.Contains("field registration"),"another plausible Quaternion field cannot replace the getter's actual backing field");
            Fixture runtime=AimFixture();runtime.U32(0xc0000000UL+31824UL*0x10000UL+280UL*32UL+24,0x1a8c);PlayerStateResult rt=runtime.Aim(runtime.Run());
            Check(rt.Sampled==0 && !rt.Samples[0].AimW.HasValue && rt.Samples[0].Detail.Contains("runtime field"),"runtime FieldInfo must agree with the original getter load");
            Fixture returnType=AimFixture();returnType.U32(returnType.Module.LoadBias+AimStateReference.ReturnDescriptor+8,AimStateReference.ReturnBits^0x10000U);PlayerStateResult re=returnType.Aim(returnType.Run());
            Check(re.Sampled==0 && re.Samples.Length==0 && re.Detail.Contains("return Quaternion"),"getter return type must remain the verified Quaternion value type");
            Fixture components=AimFixture();components.U32(components.Module.LoadBias+AimStateReference.Fields[2].OffsetRva,0x18);PlayerStateResult comp=components.Aim(components.Run());
            Check(comp.Sampled==0 && comp.Samples.Length==0,"component registration cannot reorder y and z");
            Fixture layout=AimFixture();layout.Put(layout.Layout.RuntimeMetadataBase+AimStateReference.QuaternionMetadata,new byte[]{0});PlayerStateResult lr=layout.Aim(layout.Run());
            Check(lr.Sampled==0 && lr.Samples.Length==0 && lr.Detail.Contains("Quaternion metadata"),"value-type metadata changes prevent a typed aim sample");
            Fixture changed=AimFixture();PlayerObjectResult cc=changed.Run();ulong ca=changed.Physical(Fixture.Player+0x614);bool flipped=false;
            changed.Memory.AfterRead=delegate(ulong p,int n){if(!flipped && p==ca && n==16){flipped=true;changed.AimValue(0,0,0,-1);}};PlayerStateResult cr=changed.Aim(cc);
            Check(cr.Sampled==0 && !cr.Samples[0].AimW.HasValue && !cr.Samples[0].BasisZ.HasValue,"changing quaternion invalidates the tentative snapshot without smoothing");
            Fixture gate=AimFixture();PlayerObjectResult gc=gate.Run();ulong ga=gate.Physical(Fixture.Player+0x614);
            gate.Memory.AfterRead=delegate(ulong p,int n){if(p==ga && n==16)gate.U64(Fixture.Array+0x20+0x4b9UL*8UL,Fixture.Player);};PlayerStateResult gr=gate.Aim(gc);
            Check(gr.Sampled==0 && !gr.Samples[0].AimW.HasValue,"hotfix changes during capture invalidate all quaternion values");
            Fixture member=AimFixture();PlayerObjectResult mc=member.Run();ulong ma=member.Physical(Fixture.Player+0x614);
            member.Memory.AfterRead=delegate(ulong p,int n){if(p==ma && n==16)member.U32(Fixture.REntries+0x20,uint.MaxValue);};PlayerStateResult mr=member.Aim(mc);
            Check(mr.Sampled==0 && !mr.Samples[0].AimW.HasValue,"selected local membership changes invalidate the aim snapshot");
            Fixture final=AimFixture();PlayerObjectResult fc=final.Run();ulong fa=final.Physical(Fixture.Player+0x614);
            final.Memory.AfterRead=delegate(ulong p,int n){if(p==fa && n==16)final.Put(final.Module.LoadBias+0x6f249e4,new byte[]{0});};PlayerStateResult fr=final.Aim(fc);
            Check(fr.Sampled==0 && fr.Samples.Length==0 && fr.StopReason=="FINAL_CONTEXT_FAILED","changed final aim getter code clears all tentative components");
            Fixture absent=AimFixture();PlayerObjectResult ac=absent.Run();ac.MatchPlayers=new MatchPlayerObservation[]{ac.MatchPlayers[1]};Check(absent.Aim(ac).Sampled==0,"aim snapshot never substitutes a nonlocal player");
            Fixture reserve=AimFixture();PlayerObjectResult rc=reserve.Run();while(reserve.Reader.PhysicalCalls<28500)reserve.Reader.Physical(0,1);Check(reserve.Aim(rc).StopReason=="READ_BUDGET_RESERVE","aim phase retains its final-check reserve");
            Fixture cap=AimFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27000)cap.Reader.Physical(0,1);PlayerStateResult capped=cap.Aim(capCore);Check(capped.Sampled==0 && cap.Reader.PhysicalCalls<=30000,"aim snapshot cannot reset the global read ceiling");
            Check(f.Aim(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","aim snapshot requires exact-build roster prerequisites");
        }
    }
}
