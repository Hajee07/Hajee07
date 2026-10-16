using System;
namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong FiringFeatureStatics=0x5d000000;
            internal void SetupFiring()
            {
                SetupWeapon();
                foreach(GameLayoutCheck a in WeaponFiringReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod m in WeaponFiringReference.Methods)
                { U64(Module.LoadBias+m.PointerRva,Module.LoadBias+m.Rva);Put(Layout.RuntimeMetadataBase+m.MetadataOffset,Reader.Hex(m.RecordHex)); }
                foreach(StateField f in WeaponFiringReference.Fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,(f.Owner==32785 || f.Owner==32884 || f.Owner==32859)?WeaponContextReference.OpaqueDataRegistration:(uint)f.Offset);
                    Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    ulong table=0x110000000UL+(ulong)f.Owner*0x10000UL,at=table+(ulong)f.Local*32UL;
                    U64(Class(f.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);
                }
                foreach(TeamVirtual v in WeaponFiringReference.Virtuals)
                { U32(Layout.RuntimeMetadataBase+v.MetadataOffset,v.Encoded);U64(Class(v.Index)+0x138UL+218UL*16UL,Module.LoadBias+v.Rva); }
                foreach(int gate in new int[]{0x4c1,0x4b5})U64(Array+0x20UL+(ulong)gate*8UL,0);
                Put(FiringFeatureStatics+0x191d,new byte[]{0});Put(WeaponMachine+0x20,new byte[]{0});U32(WeaponCurrentState+0x10,3);
            }
            internal PlayerStateResult Firing(PlayerObjectResult core)
            { return Reader.SampleWeaponFiring(Kernel,Game,Module,Layout,core,Progress.Add); }
        }
        private static Fixture FiringFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupFiring();return f; }
        private static PlayerStateObservation FiringSample(Fixture f)
        { PlayerStateResult r=f.Firing(f.Run());if(r.Sampled!=1)throw new Exception("Firing sample failed "+r.StopReason+" "+r.Detail+(r.Samples.Length>0?" "+r.Samples[0].Detail:""));return r.Samples[0]; }
        private static void RunWeaponFiringTests()
        {
            Fixture baseFixture=FiringFixture();PlayerObjectResult core=baseFixture.Run();int start=baseFixture.Reader.PhysicalCalls;PlayerStateResult baseline=baseFixture.Firing(core);
            Check(baseline.Sampled==1 && baseline.Samples[0].WeaponFiring==true && baseline.Samples[0].WeaponFiringRoute=="STATE_ID_SET" && baseline.Samples[0].WeaponFiringStatus=="ORIGINAL_SELECTED_WEAPON_FIRING_PREDICATE_SAMPLED" && !baseline.Samples[0].WeaponIdRaw.HasValue && !baseline.Samples[0].WeaponReloading.HasValue,
                "separate firing mode accepts original predicate without combining ID/reload phases: "+baseline.StopReason+" "+baseline.Detail+(baseline.Samples.Length>0?" "+baseline.Samples[0].Detail:""));
            Check(baseFixture.Reader.PhysicalCalls-start<=6000,"firing phase retains its independent 6000-call allowance");Console.WriteLine("FIRING_FIXTURE_ADDITIONAL_READ_CALLS="+(baseFixture.Reader.PhysicalCalls-start));
            foreach(uint state in new uint[]{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,uint.MaxValue,0x80000000})
            {
                Fixture f=FiringFixture();f.U32(Fixture.WeaponCurrentState+0x10,state);PlayerStateObservation sample=FiringSample(f);
                bool expected=state==3 || state==4 || state==5 || state==6 || state==7 || state==10 || state==11 || state==12 || state==13 || state==14 || state==15 || state==16 || state==17;
                Check(sample.WeaponFiring==expected && sample.WeaponStateRaw==unchecked((int)state),"exact original firing state-set boundary: "+state);
            }
            foreach(byte value in new byte[]{0,1})
            {
                Fixture f=FiringFixture();f.Put(Fixture.FiringFeatureStatics+0x191d,new byte[]{1});f.Put(Fixture.WeaponMachine+0x20,new byte[]{value});f.U64(Fixture.WeaponMachine+0x18,0);f.U64(Fixture.Array+0x20+0x4b5UL*8UL,Fixture.Player);PlayerStateObservation s=FiringSample(f);
                Check(s.WeaponFiring==(value!=0) && s.WeaponFiringRoute=="CACHE_BOOLEAN" && !s.WeaponStateRaw.HasValue,"cache branch short-circuits unused state getter and null state: "+value);
            }
            Fixture hand=FiringFixture();hand.U64(Fixture.Player+0x608,0);PlayerObjectResult hc=hand.Run();int handStart=hand.Reader.PhysicalCalls;PlayerStateResult hr=hand.Firing(hc);
            Check(hr.Sampled==1 && hr.Samples[0].WeaponFiring==true && hr.Samples[0].WeaponSelectionPath=="ON_HAND_CONTROLLER_A0" && hand.Reader.PhysicalCalls-handStart<=6000,"A0 hand firing path retains selection checks and budget");Console.WriteLine("FIRING_HAND_FIXTURE_ADDITIONAL_READ_CALLS="+(hand.Reader.PhysicalCalls-handStart));
            Fixture alt=FiringFixture();alt.U64(Fixture.Player+0x608,0);alt.Put(Fixture.WeaponController+0x148,new byte[]{1});alt.U64(Fixture.WeaponObject,Fixture.Class(32613));PlayerStateObservation al=FiringSample(alt);
            Check(!al.WeaponFiring.HasValue && al.WeaponFiringStatus=="UNSUPPORTED_SELECTED_WEAPON_FIRING_OVERRIDE","custom firing override is not treated as the base method");
            Fixture noMachine=FiringFixture();noMachine.U64(Fixture.WeaponObject+0x90,0);noMachine.U32(Fixture.Class(11718)+0xe0,0);PlayerStateObservation nm=FiringSample(noMachine);
            Check(nm.WeaponFiring==false && nm.WeaponFiringRoute=="NULL_MACHINE","null machine yields original false without initializing feature metadata");
            foreach(int gate in new int[]{0x4c1,0x4b5})
            {
                Fixture f=FiringFixture();f.U64(Fixture.Array+0x20UL+(ulong)gate*8UL,Fixture.Player);PlayerStateObservation s=FiringSample(f);
                Check(!s.WeaponFiring.HasValue && s.WeaponFiringStatus.Contains("HOTFIX_ACTIVE"),"relevant firing hotfix suppresses interpretation: "+gate);
            }
            Fixture uninit=FiringFixture();uninit.U32(Fixture.Class(11718)+0xe0,0);PlayerStateObservation ui=FiringSample(uninit);
            Check(!ui.WeaponFiring.HasValue && ui.WeaponFiringStatus=="NOT_READY_FIRING_FEATURE_INITIALIZATION","feature static constructor is never invoked by the reader");
            foreach(int owner in new int[]{11718,32884,32859})
            {
                Fixture f=FiringFixture();f.U64(Fixture.Class(owner)+0x80,0);PlayerStateObservation s=FiringSample(f);
                Check(!s.WeaponFiring.HasValue && s.WeaponFiringStatus.Contains("FIELD_TABLE"),"lazy firing field metadata remains unknown: "+owner);
            }
            Fixture flag=FiringFixture();flag.Put(Fixture.FiringFeatureStatics+0x191d,new byte[]{2});PlayerStateResult fl=flag.Firing(flag.Run());
            Check(fl.Sampled==0 && !fl.Samples[0].WeaponFiring.HasValue,"noncanonical feature Boolean invalidates tentative values");
            Fixture cached=FiringFixture();cached.Put(Fixture.FiringFeatureStatics+0x191d,new byte[]{1});cached.Put(Fixture.WeaponMachine+0x20,new byte[]{2});PlayerStateResult ca=cached.Firing(cached.Run());
            Check(ca.Sampled==0 && !ca.Samples[0].WeaponFiring.HasValue,"noncanonical cached Boolean is not accepted as true");
            Fixture nullState=FiringFixture();nullState.U64(Fixture.WeaponMachine+0x18,0);PlayerStateObservation ns=FiringSample(nullState);
            Check(!ns.WeaponFiring.HasValue && ns.WeaponFiringStatus=="NOT_READY_FIRING_CURRENT_STATE_NULL","state-path null state remains unknown rather than false");
            Fixture wrongMachine=FiringFixture();wrongMachine.U64(Fixture.WeaponMachine,Fixture.Class(32463));PlayerStateObservation wm=FiringSample(wrongMachine);
            Check(!wm.WeaponFiring.HasValue && wm.WeaponFiringStatus=="UNSUPPORTED_FIRING_MACHINE_CLASS","unrelated machine class is not firing storage");
            Fixture derived=FiringFixture();derived.U64(Fixture.WeaponCurrentState,Fixture.Class(32607));Check(FiringSample(derived).WeaponFiring==true,"derived current state requires the verified parent chain");
            Fixture wrongState=FiringFixture();wrongState.U64(Fixture.WeaponCurrentState,Fixture.Class(32463));PlayerStateObservation ws=FiringSample(wrongState);
            Check(!ws.WeaponFiring.HasValue && ws.WeaponFiringStatus=="UNSUPPORTED_FIRING_STATE_CLASS","unrelated current state cannot provide a firing enum");
            Fixture dispatch=FiringFixture();dispatch.U64(Fixture.Class(32623)+0x138UL+218UL*16UL,dispatch.Module.LoadBias+0x74819c4);PlayerStateResult dr=dispatch.Firing(dispatch.Run());
            Check(dr.Sampled==0 && dr.Samples[0].Detail.Contains("firing virtual dispatch"),"actual slot-218 dispatch must match the selected class");
            Fixture extent=FiringFixture();extent.U32(Fixture.Class(11718)+0x10c,0x191d);PlayerStateResult er=extent.Firing(extent.Run());
            Check(er.Sampled==0 && er.Samples[0].Detail.Contains("static extent"),"feature offset cannot exceed verified static storage");
            Fixture field=FiringFixture();field.U32(0x110000000UL+32884UL*0x10000UL+2UL*32UL+24,0x21);PlayerStateResult fir=field.Firing(field.Run());
            Check(fir.Sampled==0 && !fir.Samples[0].WeaponFiring.HasValue,"opaque cache registration still requires the exact runtime +0x20 FieldInfo");
            foreach(bool cacheRoute in new bool[]{false,true})
            {
                Fixture f=FiringFixture();if(cacheRoute)f.Put(Fixture.FiringFeatureStatics+0x191d,new byte[]{1});PlayerObjectResult fc=f.Run();ulong at=f.Physical(cacheRoute?Fixture.WeaponMachine+0x20:Fixture.WeaponCurrentState+0x10);bool changed=false;
                f.Memory.AfterRead=delegate(ulong p,int n){if(!changed && p==at){changed=true;if(cacheRoute)f.Put(Fixture.WeaponMachine+0x20,new byte[]{1});else f.U32(Fixture.WeaponCurrentState+0x10,2);}};PlayerStateResult cr=f.Firing(fc);
                Check(cr.Sampled==0 && !cr.Samples[0].WeaponFiring.HasValue,"changing firing storage discards tentative values: "+cacheRoute);
            }
            Fixture route=FiringFixture();PlayerObjectResult rc=route.Run();ulong ra=route.Physical(Fixture.WeaponCurrentState+0x10);
            route.Memory.AfterRead=delegate(ulong p,int n){if(p==ra && n==4)route.Put(Fixture.FiringFeatureStatics+0x191d,new byte[]{1});};PlayerStateResult rr=route.Firing(rc);
            Check(rr.Sampled==0 && !rr.Samples[0].WeaponFiring.HasValue,"changing feature route invalidates the snapshot");
            Fixture hot=FiringFixture();PlayerObjectResult hotCore=hot.Run();ulong ha=hot.Physical(Fixture.WeaponCurrentState+0x10);
            hot.Memory.AfterRead=delegate(ulong p,int n){if(p==ha && n==4)hot.U64(Fixture.Array+0x20+0x4c1UL*8UL,Fixture.Player);};PlayerStateResult hor=hot.Firing(hotCore);
            Check(hor.Sampled==0 && !hor.Samples[0].WeaponFiring.HasValue,"firing hotfix activation during capture invalidates the snapshot");
            Fixture final=FiringFixture();PlayerObjectResult finalCore=final.Run();ulong fa=final.Physical(Fixture.WeaponCurrentState+0x10);
            final.Memory.AfterRead=delegate(ulong p,int n){if(p==fa && n==4)final.Put(final.Module.LoadBias+0x7481b48,new byte[]{0});};PlayerStateResult fr=final.Firing(finalCore);
            Check(fr.Sampled==0 && fr.Samples.Length==0 && fr.StopReason=="FINAL_CONTEXT_FAILED","final firing code failure clears all observations");
            Fixture reserve=FiringFixture();PlayerObjectResult reserveCore=reserve.Run();while(reserve.Reader.PhysicalCalls<28500)reserve.Reader.Physical(0,1);
            Check(reserve.Firing(reserveCore).StopReason=="READ_BUDGET_RESERVE","firing phase preserves the final-check reserve");
            Fixture cap=FiringFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27000)cap.Reader.Physical(0,1);PlayerStateResult capped=cap.Firing(capCore);
            Check(capped.Sampled==0 && cap.Reader.PhysicalCalls<=30000,"firing phase never resets the global ceiling");
            Fixture selection=FiringFixture();selection.U64(Fixture.Array+0x20+0x347UL*8UL,Fixture.Player);PlayerStateObservation sel=FiringSample(selection);
            Check(!sel.Weapon.HasValue && !sel.WeaponFiring.HasValue && sel.WeaponStatus=="UNVERIFIED_HOTFIX_ACTIVE","firing never bypasses the original weapon-selection hotfix");
            StateField cacheField=null,featureField=null;foreach(StateField f in WeaponFiringReference.Fields){if(f.Owner==32884 && f.Local==2)cacheField=f;if(f.Owner==11718)featureField=f;}
            Fixture registration=FiringFixture();PlayerObjectResult regCore=registration.Run();registration.U32(registration.Module.LoadBias+cacheField.OffsetRva,0x81818182);PlayerStateResult reg=registration.Firing(regCore);
            Check(reg.Sampled==0 && reg.Samples.Length==0 && reg.Detail.Contains("firing field registration"),"arbitrary opaque cache registration cannot be accepted");
            Fixture featureType=FiringFixture();PlayerObjectResult typeCore=featureType.Run();featureType.U32(featureType.Module.LoadBias+featureField.Descriptor+8,featureField.Bits^0x10000U);PlayerStateResult tr=featureType.Firing(typeCore);
            Check(tr.Sampled==0 && tr.Samples.Length==0 && tr.Detail.Contains("type flags"),"firing feature descriptor must remain Boolean");
            Fixture absent=FiringFixture();PlayerObjectResult ac=absent.Run();ac.MatchPlayers=new MatchPlayerObservation[]{ac.MatchPlayers[1]};
            Check(absent.Firing(ac).Sampled==0,"local-only firing mode never substitutes a nonlocal roster member");
            Fixture removed=FiringFixture();PlayerObjectResult remCore=removed.Run();ulong remAt=removed.Physical(Fixture.WeaponCurrentState+0x10);
            removed.Memory.AfterRead=delegate(ulong p,int n){if(p==remAt && n==4)removed.U32(Fixture.REntries+0x20,uint.MaxValue);};PlayerStateResult rem=removed.Firing(remCore);
            Check(rem.Sampled==0 && !rem.Samples[0].WeaponFiring.HasValue,"selected-member removal invalidates the firing result");
            Check(baseFixture.Firing(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","firing requires exact-build roster prerequisites");
        }
    }
}
