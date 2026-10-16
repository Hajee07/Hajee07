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
                StateMethod m=AimStateReference.Method;U64(Module.LoadBias+m.PointerRva,Module.LoadBias+m.Rva);Put(Layout.RuntimeMetadataBase+m.MetadataOffset,Reader.Hex(m.RecordHex));
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
            Fixture f=AimFixture();PlayerObjectResult core=f.Run();int start=f.Reader.PhysicalCalls;PlayerStateResult baseline=f.Aim(core);PlayerStateObservation b=baseline.Samples.Length>0?baseline.Samples[0]:new PlayerStateObservation();
            Check(baseline.Sampled==1 && b.AimRotationStatus=="ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED" && b.AimX==0 && b.AimY==0 && b.AimZ==0 && b.AimW==1 && b.AimNormSquared==1 && b.IsLocal && b.MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "original local getter reads verified +0x614 Quaternion, not separate m_CurrentAimRotation: "+baseline.StopReason+" "+baseline.Detail+" "+b.Detail);
            Check(f.Reader.PhysicalCalls-start<=6000,"aim-state phase retains 6000-call limit and final checks");Console.WriteLine("AIM_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            Fixture sign=AimFixture();sign.AimValue(0,0,0,-1);Check(AimSample(sign).AimW==-1,"negative Quaternion sign is preserved without changing orientation convention");
            Fixture rotated=AimFixture();float s=(float)Math.Sqrt(0.5);rotated.AimValue(0,s,0,s);PlayerStateObservation rs=AimSample(rotated);
            Check(rs.AimY==s && rs.AimW==s && Math.Abs(rs.AimNormSquared.Value-1)<0.00001,"component order follows verified Unity Quaternion x/y/z/w layout");
            foreach(float invalid in new float[]{float.NaN,float.PositiveInfinity,float.NegativeInfinity})
            { Fixture x=AimFixture();x.AimValue(invalid,0,0,1);PlayerStateObservation q=AimSample(x);Check(!q.AimX.HasValue && !q.AimW.HasValue && q.AimRotationStatus=="NOT_READY_AIM_ROTATION_NONFINITE","nonfinite quaternion never publishes tentative components: "+invalid); }
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
            Check(cr.Sampled==0 && !cr.Samples[0].AimW.HasValue,"changing quaternion invalidates the tentative snapshot without smoothing");
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
