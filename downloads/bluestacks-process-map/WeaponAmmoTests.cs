using System;
namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong AmmoTable=0x110000000UL+32785UL*0x10000UL;
            internal void BindAmmo(int local)
            {
                Put(AmmoTable,new byte[WeaponAmmoReference.FieldCount*32]);U64(Class(32785)+0x80,AmmoTable);
                WeaponAmmoField chosen=null;foreach(WeaponAmmoField c in WeaponAmmoReference.Candidates)if(c.Local==local)chosen=c;
                if(chosen==null)throw new Exception("Fixture ammo candidate missing.");ulong at=AmmoTable+(ulong)local*32UL;
                U64(at,Layout.RuntimeMetadataBase+chosen.NameOffset);U64(at+8,Module.LoadBias+chosen.Descriptor);U64(at+16,Class(32785));U32(at+24,0x610);U32(at+28,chosen.Token);
            }
            internal void SetupAmmo()
            {
                SetupWeapon();
                foreach(GameLayoutCheck a in WeaponAmmoReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod m in WeaponAmmoReference.Methods)
                { U64(Module.LoadBias+m.PointerRva,Module.LoadBias+m.Rva);Put(Layout.RuntimeMetadataBase+m.MetadataOffset,Reader.Hex(m.RecordHex)); }
                foreach(WeaponAmmoField c in WeaponAmmoReference.Candidates)
                { U32(Module.LoadBias+c.OffsetRva,WeaponContextReference.OpaqueDataRegistration);Put(Layout.RuntimeMetadataBase+c.MetadataOffset,Reader.Hex(c.RecordHex));U32(Module.LoadBias+c.Descriptor+8,c.Bits); }
                BindAmmo(WeaponAmmoReference.Candidates[0].Local);U32(WeaponObject+0x610,30);U64(Array+0x20+0x328UL*8UL,0);
            }
            internal PlayerStateResult Ammo(PlayerObjectResult core)
            { return Reader.SampleWeaponAmmo(Kernel,Game,Module,Layout,core,Progress.Add); }
        }
        private static Fixture AmmoFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupAmmo();return f; }
        private static PlayerStateObservation AmmoSample(Fixture f)
        { PlayerStateResult r=f.Ammo(f.Run());if(r.Sampled!=1)throw new Exception("Ammo sample failed "+r.StopReason+" "+r.Detail+(r.Samples.Length>0?" "+r.Samples[0].Detail:""));return r.Samples[0]; }
        private static void RunWeaponAmmoTests()
        {
            Fixture f=AmmoFixture();PlayerObjectResult core=f.Run();int start=f.Reader.PhysicalCalls;PlayerStateResult baseline=f.Ammo(core);
            Check(baseline.Sampled==1 && baseline.Samples[0].WeaponAmmoRaw==30 && baseline.Samples[0].WeaponAmmoStatus=="ORIGINAL_SELECTED_WEAPON_INT32_COUNTER_SAMPLED" && baseline.Samples[0].WeaponAmmoRegistration=="OPAQUE_SOURCE_RUNTIME_FIELD_VERIFIED" && !baseline.Samples[0].WeaponFiring.HasValue && !baseline.Samples[0].WeaponIdRaw.HasValue,
                "separate ammo mode verifies the original counter with runtime-bound field identity: "+baseline.StopReason+" "+baseline.Detail+(baseline.Samples.Length>0?" "+baseline.Samples[0].Detail:""));
            Check(f.Reader.PhysicalCalls-start<=6000,"ammo phase retains its independent 6000-call allowance");Console.WriteLine("AMMO_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            foreach(WeaponAmmoField candidate in WeaponAmmoReference.Candidates)
            {
                Fixture c=AmmoFixture();c.BindAmmo(candidate.Local);PlayerStateObservation sample=AmmoSample(c);
                Check(sample.WeaponAmmoFieldIndex==candidate.Local && sample.WeaponAmmoFieldName==candidate.Name && sample.WeaponAmmoRaw==30,"field identity binds only after unique runtime +0x610 proof: "+candidate.Local);
            }
            foreach(uint value in new uint[]{0,1,2147483647U,2147483648U,uint.MaxValue})
            {
                Fixture c=AmmoFixture();c.U32(Fixture.WeaponObject+0x610,value);PlayerStateObservation sample=AmmoSample(c);
                Check(sample.WeaponAmmoRaw==unchecked((int)value),"Int32 counter preserves bits without inventing range or unlimited policy: "+value);
            }
            Fixture resolved=AmmoFixture();WeaponAmmoField first=WeaponAmmoReference.Candidates[0];resolved.U32(resolved.Module.LoadBias+first.OffsetRva,0x610);
            Check(AmmoSample(resolved).WeaponAmmoRegistration=="RESOLVED_OFFSET","resolved source registration still needs unique runtime FieldInfo");
            Fixture hand=AmmoFixture();hand.U64(Fixture.Player+0x608,0);PlayerObjectResult hc=hand.Run();int hs=hand.Reader.PhysicalCalls;PlayerStateResult hr=hand.Ammo(hc);
            Check(hr.Sampled==1 && hr.Samples[0].WeaponAmmoRaw==30 && hr.Samples[0].WeaponSelectionPath=="ON_HAND_CONTROLLER_A0" && hand.Reader.PhysicalCalls-hs<=6000,"A0 ammo path retains selection validation and phase budget");Console.WriteLine("AMMO_HAND_FIXTURE_ADDITIONAL_READ_CALLS="+(hand.Reader.PhysicalCalls-hs));
            Fixture unused=AmmoFixture();foreach(int gate in new int[]{0x267b,0x21a65,0x4c1,0x4c7})unused.U64(Fixture.Array+0x20UL+(ulong)gate*8UL,Fixture.Player);
            Check(AmmoSample(unused).WeaponAmmoRaw==30,"ammo does not combine unused data/firing/reload getters");
            Fixture hot=AmmoFixture();hot.U64(Fixture.Array+0x20+0x328UL*8UL,Fixture.Player);hot.U64(Fixture.Class(32785)+0x80,0);PlayerStateObservation ho=AmmoSample(hot);
            Check(!ho.WeaponAmmoRaw.HasValue && ho.WeaponAmmoStatus=="UNVERIFIED_AMMO_GETTER_HOTFIX_ACTIVE","ammo hotfix short-circuits unused runtime field metadata");
            Fixture lazy=AmmoFixture();lazy.U64(Fixture.Class(32785)+0x80,0);PlayerStateObservation la=AmmoSample(lazy);
            Check(!la.WeaponAmmoRaw.HasValue && la.WeaponAmmoStatus=="NOT_READY_AMMO_FIELD_TABLE","ammo never initializes lazy field metadata");
            Fixture missing=AmmoFixture();missing.U32(Fixture.AmmoTable+(ulong)first.Local*32UL+24,0);PlayerStateObservation mi=AmmoSample(missing);
            Check(!mi.WeaponAmmoRaw.HasValue && mi.WeaponAmmoStatus=="NOT_READY_AMMO_OFFSET_UNRESOLVED","missing runtime offset is unknown rather than a guessed field name");
            Fixture duplicate=AmmoFixture();duplicate.U32(Fixture.AmmoTable+24,0x610);PlayerStateResult du=duplicate.Ammo(duplicate.Run());
            Check(du.Sampled==0 && !du.Samples[0].WeaponAmmoRaw.HasValue && du.Samples[0].Detail.Contains("unique field offset"),"duplicate runtime offsets invalidate tentative values");
            Fixture wrongType=AmmoFixture();wrongType.U32(Fixture.AmmoTable+(ulong)first.Local*32UL+24,0);wrongType.U32(Fixture.AmmoTable+24,0x610);PlayerStateObservation wt=AmmoSample(wrongType);
            Check(!wt.WeaponAmmoRaw.HasValue && wt.WeaponAmmoStatus=="UNSUPPORTED_AMMO_FIELD_TYPE","noncandidate field type cannot be treated as the Int32 counter");
            foreach(int part in new int[]{0,8,16,28})
            {
                Fixture c=AmmoFixture();ulong at=Fixture.AmmoTable+(ulong)first.Local*32UL+(ulong)part;if(part==28)c.U32(at,0);else c.U64(at,0);PlayerStateResult r=c.Ammo(c.Run());
                Check(r.Sampled==0 && !r.Samples[0].WeaponAmmoRaw.HasValue && r.Samples[0].Detail.Contains("runtime FieldInfo"),"chosen runtime field name/type/owner/token must agree: "+part);
            }
            Fixture count=AmmoFixture();count.Put(Fixture.Class(32785)+0x124,new byte[]{252,0});PlayerStateResult co=count.Ammo(count.Run());
            Check(co.Sampled==0 && co.Samples[0].Detail.Contains("field-table count"),"ammo table count is exact and bounded");
            Fixture registration=AmmoFixture();registration.U32(registration.Module.LoadBias+first.OffsetRva,0x81818182);PlayerStateResult reg=registration.Ammo(registration.Run());
            Check(reg.Sampled==0 && !reg.Samples[0].WeaponAmmoRaw.HasValue,"arbitrary opaque source registration is never decoded or accepted");
            Fixture descriptor=AmmoFixture();descriptor.U32(descriptor.Module.LoadBias+first.Descriptor+8,first.Bits^0x10000U);PlayerStateResult de=descriptor.Ammo(descriptor.Run());
            Check(de.Sampled==0 && de.Samples[0].Detail.Contains("Int32 type"),"chosen native field descriptor must remain Int32");
            Fixture selection=AmmoFixture();selection.U64(Fixture.Array+0x20+0x347UL*8UL,Fixture.Player);PlayerStateObservation se=AmmoSample(selection);
            Check(!se.Weapon.HasValue && !se.WeaponAmmoRaw.HasValue,"ammo never bypasses original weapon selection");
            Fixture absent=AmmoFixture();PlayerObjectResult ac=absent.Run();ac.MatchPlayers=new MatchPlayerObservation[]{ac.MatchPlayers[1]};Check(absent.Ammo(ac).Sampled==0,"ammo selects only a verified local roster member");
            Fixture changed=AmmoFixture();PlayerObjectResult cc=changed.Run();ulong ca=changed.Physical(Fixture.WeaponObject+0x610);bool flip=false;
            changed.Memory.AfterRead=delegate(ulong p,int n){if(!flip && p==ca && n==4){flip=true;changed.U32(Fixture.WeaponObject+0x610,29);}};PlayerStateResult cr=changed.Ammo(cc);
            Check(cr.Sampled==0 && !cr.Samples[0].WeaponAmmoRaw.HasValue,"changing counter discards tentative ammo values");
            Fixture tableChange=AmmoFixture();PlayerObjectResult tc=tableChange.Run();ulong ta=tableChange.Physical(Fixture.WeaponObject+0x610);
            tableChange.Memory.AfterRead=delegate(ulong p,int n){if(p==ta && n==4)tableChange.U32(Fixture.AmmoTable+(ulong)first.Local*32UL+24,0);};PlayerStateResult tcr=tableChange.Ammo(tc);
            Check(tcr.Sampled==0 && !tcr.Samples[0].WeaponAmmoRaw.HasValue,"runtime field-table changes invalidate the counter binding");
            Fixture gateChange=AmmoFixture();PlayerObjectResult gc=gateChange.Run();ulong ga=gateChange.Physical(Fixture.WeaponObject+0x610);
            gateChange.Memory.AfterRead=delegate(ulong p,int n){if(p==ga && n==4)gateChange.U64(Fixture.Array+0x20+0x328UL*8UL,Fixture.Player);};PlayerStateResult gr=gateChange.Ammo(gc);
            Check(gr.Sampled==0 && !gr.Samples[0].WeaponAmmoRaw.HasValue,"ammo getter hotfix changes during capture invalidate the row");
            Fixture member=AmmoFixture();PlayerObjectResult mc=member.Run();ulong ma=member.Physical(Fixture.WeaponObject+0x610);
            member.Memory.AfterRead=delegate(ulong p,int n){if(p==ma && n==4)member.U32(Fixture.REntries+0x20,uint.MaxValue);};PlayerStateResult mr=member.Ammo(mc);
            Check(mr.Sampled==0 && !mr.Samples[0].WeaponAmmoRaw.HasValue,"selected-member removal invalidates the ammo observation");
            Fixture final=AmmoFixture();PlayerObjectResult fc=final.Run();ulong fa=final.Physical(Fixture.WeaponObject+0x610);
            final.Memory.AfterRead=delegate(ulong p,int n){if(p==fa && n==4)final.Put(final.Module.LoadBias+0x7457fdc,new byte[]{0});};PlayerStateResult fr=final.Ammo(fc);
            Check(fr.Sampled==0 && fr.Samples.Length==0 && fr.StopReason=="FINAL_CONTEXT_FAILED","final original getter code failure clears every tentative value");
            Fixture reserve=AmmoFixture();PlayerObjectResult reserveCore=reserve.Run();while(reserve.Reader.PhysicalCalls<28500)reserve.Reader.Physical(0,1);
            Check(reserve.Ammo(reserveCore).StopReason=="READ_BUDGET_RESERVE","ammo phase retains its final-check reserve");
            Fixture cap=AmmoFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27000)cap.Reader.Physical(0,1);PlayerStateResult capped=cap.Ammo(capCore);
            Check(capped.Sampled==0 && cap.Reader.PhysicalCalls<=30000,"ammo phase never resets the global read ceiling");
            Check(f.Ammo(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","ammo requires exact-build roster prerequisites");
        }
    }
}
