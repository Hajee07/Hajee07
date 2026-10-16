using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong WeaponObject=0x61000000,WeaponController=0x61001000,WeaponDataObject=0x61002000;
            internal void SetupWeapon()
            {
                SetupCombat();
                foreach(ObjectClassProfile p in WeaponContextReference.Classes)
                {
                    ulong k=Class(p.Index),row=Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)p.Index*88UL;
                    MetadataIdentity(k,p);U64(k+0x20,row);U32(k+0x28,p.Bits);U32(k+0xf8,p.InstanceSize);U32(k+0xe0,1);
                    if(p.Parent>=0)U64(k+0x58,Class(p.Parent));byte[] counts=new byte[16];System.Array.Copy(Reader.Hex(p.RecordHex),64,counts,0,16);Put(k+0x120,counts);
                    if((p.Family&1)!=0)
                    {
                        List<int> chain=new List<int>();ObjectClassProfile current=p;
                        for(int depth=0;depth<24;depth++)
                        {
                            chain.Insert(0,current.Index);if(current.Index==32463)break;ObjectClassProfile parent=null;
                            foreach(ObjectClassProfile candidate in WeaponContextReference.Classes)if(candidate.Index==current.Parent)parent=candidate;
                            if(parent==null)throw new Exception("Missing fixture weapon parent.");current=parent;
                        }
                        ulong hierarchy=0x120000000UL+(ulong)p.Index*0x100UL;U64(k+0xc8,hierarchy);Put(k+0x130,new byte[]{(byte)chain.Count});
                        for(int i=0;i<chain.Count;i++)U64(hierarchy+(ulong)i*8UL,Class(chain[i]));
                    }
                }
                foreach(GameLayoutCheck a in WeaponContextReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod q in WeaponContextReference.Methods)
                { U64(Module.LoadBias+q.PointerRva,Module.LoadBias+q.Rva);Put(Layout.RuntimeMetadataBase+q.MetadataOffset,Reader.Hex(q.RecordHex)); }
                List<StateField> fields=new List<StateField>();fields.AddRange(PlayerStateReference.Fields);fields.AddRange(CombatStateReference.Fields);fields.AddRange(TeamPolicyReference.Fields);fields.AddRange(WeaponContextReference.Fields);
                foreach(StateField f in fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,f.Owner==32785?WeaponContextReference.OpaqueDataRegistration:(uint)f.Offset);Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    ulong table=0x110000000UL+(ulong)f.Owner*0x10000UL,at=table+(ulong)f.Local*32UL;
                    U64(Class(f.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);
                }
                foreach(TeamVirtual v in WeaponContextReference.Virtuals)
                { U32(Layout.RuntimeMetadataBase+v.MetadataOffset,v.Encoded);U64(Class(v.Index)+0x138UL+45UL*16UL,Module.LoadBias+v.Rva); }
                TeamVirtual idProfile=WeaponContextReference.IdVirtual;U32(Layout.RuntimeMetadataBase+idProfile.MetadataOffset,idProfile.Encoded);
                U64(Class(31595)+0x138UL+(ulong)idProfile.Slot*16UL,Module.LoadBias+idProfile.Rva);
                U64(Module.LoadBias+WeaponContextReference.WeaponTypeCell,Class(32785));
                foreach(int id in new int[]{0x347,0x345,0x346,0x286,0x285,0x267b,0x21a65})U64(Array+0x20UL+(ulong)id*8UL,0);
                U64(Player+0x608,WeaponObject);U64(Player+0x740,WeaponController);U64(WeaponController,Class(32430));
                U64(WeaponController+0xa0,WeaponObject);U64(WeaponController+0xa8,WeaponObject);Put(WeaponController+0x148,new byte[]{0});
                U64(WeaponObject,Class(32623));U64(WeaponObject+0x98,WeaponDataObject);U64(WeaponDataObject,Class(31595));U32(WeaponDataObject+0x68,1234);
            }
            internal PlayerStateResult Weapon(PlayerObjectResult core)
            { return Reader.SampleWeaponContext(Kernel,Game,Module,Layout,core,Progress.Add); }
        }
        private static Fixture WeaponFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupWeapon();return f; }
        private static PlayerStateObservation WeaponSample(Fixture f)
        {
            PlayerStateResult r=f.Weapon(f.Run());if(r.Sampled!=1)throw new Exception("Weapon sample failed: "+r.StopReason+" "+r.Detail+(r.Samples.Length>0?" "+r.Samples[0].Detail:""));return r.Samples[0];
        }
        private static void RunWeaponTests()
        {
            Fixture f=WeaponFixture();PlayerObjectResult core=f.Run();int start=f.Reader.PhysicalCalls;PlayerStateResult result=f.Weapon(core);
            Check(result.Sampled==1 && result.Samples.Length==1 && result.Samples[0].IsLocal && result.Samples[0].WeaponStatus=="ORIGINAL_WEAPON_DATA_REFERENCE_SAMPLED" &&
                result.Samples[0].Weapon==Fixture.WeaponObject && result.Samples[0].WeaponData==Fixture.WeaponDataObject && result.Samples[0].WeaponDataRegistration=="OPAQUE_FILE_VALUE_RUNTIME_FIELD_VERIFIED" && result.Samples[0].MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "local active weapon and typed data reference are independently verified: "+result.StopReason+" "+result.Detail+(result.Samples.Length>0?" "+result.Samples[0].Detail:""));
            Check(f.Reader.PhysicalCalls-start<=6000,"weapon phase respects the independent 6000-call allowance");Console.WriteLine("WEAPON_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            Fixture resolved=WeaponFixture();StateField dataField=null;foreach(StateField field in WeaponContextReference.Fields)if(field.Owner==32785)dataField=field;
            resolved.U32(resolved.Module.LoadBias+dataField.OffsetRva,0x98);PlayerStateObservation rs=WeaponSample(resolved);
            Check(rs.WeaponData.HasValue && rs.WeaponDataRegistration=="RESOLVED_OFFSET","resolved registration still requires the exact getter/runtime field offset");
            Fixture hand=WeaponFixture();hand.U64(Fixture.Player+0x608,0);PlayerObjectResult handCore=hand.Run();int handStart=hand.Reader.PhysicalCalls;PlayerStateResult handResult=hand.Weapon(handCore);PlayerStateObservation hs=handResult.Samples[0];
            Check(handResult.Sampled==1 && hand.Reader.PhysicalCalls-handStart<=6000,"live-observed A0 path retains phase and final-check budget");Console.WriteLine("WEAPON_HAND_FIXTURE_ADDITIONAL_READ_CALLS="+(hand.Reader.PhysicalCalls-handStart));
            Check(hs.WeaponStatus=="ORIGINAL_WEAPON_DATA_REFERENCE_SAMPLED" && hs.WeaponSelectionPath=="ON_HAND_CONTROLLER_A0" && hs.AlternateHand==false,"null active field follows verified on-hand controller and native cast");
            Fixture alternate=WeaponFixture();alternate.U64(Fixture.Player+0x608,0);alternate.Put(Fixture.WeaponController+0x148,new byte[]{1});alternate.U64(Fixture.WeaponObject,Fixture.Class(32613));PlayerStateObservation alt=WeaponSample(alternate);
            Check(alt.Weapon==Fixture.WeaponObject && alt.WeaponSelectionPath=="ON_HAND_CONTROLLER_A8" && alt.WeaponStatus=="UNSUPPORTED_WEAPON_DATA_OVERRIDE" && !alt.WeaponData.HasValue,"alternate hand preserves the actual unsupported data getter override");
            Fixture none=WeaponFixture();none.U64(Fixture.Player+0x608,0);none.U64(Fixture.Player+0x740,0);PlayerStateObservation ns=WeaponSample(none);
            Check(ns.Weapon==0 && ns.WeaponData==0 && ns.WeaponStatus=="ORIGINAL_NO_ACTIVE_WEAPON","null controller yields original no-weapon result");
            Fixture empty=WeaponFixture();empty.U64(Fixture.Player+0x608,0);empty.U64(Fixture.WeaponController+0xa0,0);Check(WeaponSample(empty).Weapon==0,"empty selected hand yields original no-weapon result");
            Fixture nonWeapon=WeaponFixture();nonWeapon.U64(Fixture.Player+0x608,0);nonWeapon.U64(Fixture.WeaponObject,Fixture.Class(32463));PlayerStateObservation cast=WeaponSample(nonWeapon);
            Check(cast.Weapon==0 && cast.WeaponSelectionPath=="ON_HAND_NON_WEAPON_CAST","verified non-weapon item follows the original failed HBIBDMMOOOK cast");
            foreach(int gate in new int[]{0x347,0x345,0x346,0x286,0x285})
            {
                Fixture x=WeaponFixture();if(gate!=0x347 && gate!=0x345)x.U64(Fixture.Player+0x608,0);PlayerObjectResult xc=x.Run();x.U64(Fixture.Array+0x20UL+(ulong)gate*8UL,Fixture.Player);PlayerStateResult r=x.Weapon(xc);
                Check(r.Sampled==1 && r.Samples[0].WeaponStatus=="UNVERIFIED_HOTFIX_ACTIVE" && !r.Samples[0].Weapon.HasValue,"weapon selection original gate: "+gate);
            }
            Fixture unused=WeaponFixture();PlayerObjectResult uc=unused.Run();unused.U64(Fixture.Array+0x20+0x346UL*8UL,Fixture.Player);
            Check(unused.Weapon(uc).Samples[0].WeaponStatus=="ORIGINAL_WEAPON_DATA_REFERENCE_SAMPLED","active field short-circuits the unused fallback hotfix");
            Fixture dataHot=WeaponFixture();PlayerObjectResult dh=dataHot.Run();dataHot.U64(Fixture.Array+0x20+0x267bUL*8UL,Fixture.Player);PlayerStateObservation hot=dataHot.Weapon(dh).Samples[0];
            Check(hot.Weapon==Fixture.WeaponObject && !hot.WeaponData.HasValue && hot.WeaponStatus=="UNVERIFIED_HOTFIX_ACTIVE","data hotfix suppresses only the unknown data interpretation");
            Fixture opaque=WeaponFixture();PlayerObjectResult oc=opaque.Run();opaque.U32(opaque.Module.LoadBias+dataField.OffsetRva,0x81818182);PlayerStateResult or=opaque.Weapon(oc);
            Check(or.Sampled==0 && or.Samples.Length==0 && or.Detail.Contains("weapon field registration"),"an arbitrary opaque registration is never accepted");
            Fixture runtime=WeaponFixture();PlayerObjectResult rc=runtime.Run();runtime.U32(0x110000000UL+32785UL*0x10000UL+18UL*32UL+24,0xa0);PlayerStateResult rr=runtime.Weapon(rc);
            Check(rr.Sampled==0 && !rr.Samples[0].Weapon.HasValue && rr.Samples[0].Detail.Contains("combat runtime field"),"opaque file entry cannot bypass the runtime +0x98 FieldInfo");
            Fixture lazy=WeaponFixture();lazy.U64(Fixture.Class(32785)+0x80,0);PlayerStateObservation ls=WeaponSample(lazy);
            Check(ls.Weapon==Fixture.WeaponObject && !ls.WeaponData.HasValue && ls.WeaponStatus=="NOT_READY_WEAPON_FIELD_TABLE","lazy field metadata is not initialized or guessed by the reader");
            Fixture nullData=WeaponFixture();nullData.U64(Fixture.WeaponObject+0x98,0);PlayerStateObservation nd=WeaponSample(nullData);
            Check(nd.WeaponData==0 && nd.WeaponStatus=="NOT_READY_WEAPON_DATA_NULL","null weapon data is explicit and not replaced by an invented data object");
            Fixture wrongData=WeaponFixture();wrongData.U64(Fixture.WeaponDataObject,Fixture.Class(32463));PlayerStateObservation wd=WeaponSample(wrongData);
            Check(!wd.WeaponData.HasValue && wd.WeaponStatus=="UNSUPPORTED_WEAPON_DATA_CLASS","wrong data class is not a typed weapon-data result");
            Fixture dispatch=WeaponFixture();dispatch.U64(Fixture.Class(32623)+0x138+45*16,dispatch.Module.LoadBias+0x7452a94);PlayerStateResult vr=dispatch.Weapon(dispatch.Run());
            Check(vr.Sampled==0 && vr.Samples[0].Detail.Contains("weapon data virtual dispatch"),"actual data virtual target must match source metadata");
            Fixture selector=WeaponFixture();selector.U64(Fixture.Player+0x608,0);selector.Put(Fixture.WeaponController+0x148,new byte[]{2});PlayerStateResult sr=selector.Weapon(selector.Run());
            Check(sr.Sampled==0 && !sr.Samples[0].Weapon.HasValue,"noncanonical hand selector invalidates all tentative values");
            Fixture invalidCast=WeaponFixture();invalidCast.U64(Fixture.Player+0x608,0);invalidCast.U64(0x120000000UL+32623UL*0x100UL+8,Fixture.Class(32463));PlayerStateResult ic=invalidCast.Weapon(invalidCast.Run());
            Check(ic.Sampled==0 && ic.Samples[0].Detail.Contains("runtime cast"),"native hand cast must agree with independently verified class ancestry");
            Fixture wrongActive=WeaponFixture();wrongActive.U64(Fixture.WeaponObject,Fixture.Class(32785));PlayerStateResult wa=wrongActive.Weapon(wrongActive.Run());
            Check(wa.Sampled==0 && wa.Samples[0].Detail.Contains("not assignable"),"active field requires its declared GEBIDMLCOJO family");
            Fixture changed=WeaponFixture();PlayerObjectResult cc=changed.Run();ulong ca=changed.Physical(Fixture.WeaponObject+0x98);bool flip=false;
            changed.Memory.AfterRead=delegate(ulong p,int n){if(!flip && p==ca && n==8){flip=true;changed.U64(Fixture.WeaponObject+0x98,0);}};PlayerStateResult cr=changed.Weapon(cc);
            Check(cr.Sampled==0 && !cr.Samples[0].Weapon.HasValue && !cr.Samples[0].WeaponData.HasValue,"weapon-data changes discard the entire tentative row");
            Fixture member=WeaponFixture();PlayerObjectResult mc=member.Run();ulong ma=member.Physical(Fixture.Player+0x608);
            member.Memory.AfterRead=delegate(ulong p,int n){if(p==ma && n==8)member.U32(Fixture.REntries+0x20,uint.MaxValue);};PlayerStateResult mr=member.Weapon(mc);
            Check(mr.Sampled==0 && !mr.Samples[0].Weapon.HasValue,"local member removal invalidates its weapon observation");
            Fixture final=WeaponFixture();PlayerObjectResult fc=final.Run();ulong fa=final.Physical(Fixture.WeaponDataObject);
            final.Memory.AfterRead=delegate(ulong p,int n){if(p==fa && n==8)final.Put(final.Module.LoadBias+0x7452ac8,new byte[]{0});};PlayerStateResult fr=final.Weapon(fc);
            Check(fr.Sampled==0 && fr.Samples.Length==0 && fr.StopReason=="FINAL_CONTEXT_FAILED","final getter-code failure clears the complete weapon sample");
            Fixture absent=WeaponFixture();PlayerObjectResult ac=absent.Run();ac.MatchPlayers=new MatchPlayerObservation[]{ac.MatchPlayers[1]};
            Check(absent.Weapon(ac).Sampled==0,"local-only weapon mode never substitutes another roster member");
            Fixture reserve=WeaponFixture();PlayerObjectResult reserveCore=reserve.Run();while(reserve.Reader.PhysicalCalls<28500)reserve.Reader.Physical(0,1);
            Check(reserve.Weapon(reserveCore).StopReason=="READ_BUDGET_RESERVE","weapon phase preserves its final reserve");
            Fixture cap=WeaponFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27000)cap.Reader.Physical(0,1);PlayerStateResult capped=cap.Weapon(capCore);
            Check(capped.Sampled==0 && cap.Reader.PhysicalCalls<=30000,"weapon phase never resets or exceeds the global read ceiling");
            Check(result.Samples[0].WeaponIdRaw==1234 && result.Samples[0].WeaponIdStatus=="ORIGINAL_GET_ID_UINT32_SAMPLED","exact data GetId returns the verified UInt32 field");
            Fixture idZero=WeaponFixture();idZero.U32(Fixture.WeaponDataObject+0x68,0);
            Check(WeaponSample(idZero).WeaponIdRaw==0,"zero ID is preserved without assigning a weapon name");
            Fixture idMax=WeaponFixture();idMax.U32(Fixture.WeaponDataObject+0x68,uint.MaxValue);
            Check(WeaponSample(idMax).WeaponIdRaw==uint.MaxValue,"UInt32 ID preserves all bits without signed conversion or a guessed range");
            Fixture idHot=WeaponFixture();idHot.U64(Fixture.Array+0x20+0x21a65UL*8UL,Fixture.Player);PlayerStateObservation ih=WeaponSample(idHot);
            Check(ih.WeaponData==Fixture.WeaponDataObject && !ih.WeaponIdRaw.HasValue && ih.WeaponIdStatus=="UNVERIFIED_HOTFIX_ACTIVE","GetId hotfix leaves the verified data reference but suppresses the ID");
            Fixture idLazy=WeaponFixture();idLazy.U64(Fixture.Class(31595)+0x80,0);PlayerStateObservation il=WeaponSample(idLazy);
            Check(il.WeaponData==Fixture.WeaponDataObject && !il.WeaponIdRaw.HasValue && il.WeaponIdStatus=="NOT_READY_DATA_FIELD_TABLE","uninitialized data FieldInfo remains unknown without initialization");
            Fixture idOffset=WeaponFixture();PlayerObjectResult io=idOffset.Run();idOffset.U32(0x110000000UL+31595UL*0x10000UL+20UL*32UL+24,0x64);PlayerStateResult ior=idOffset.Weapon(io);
            Check(ior.Sampled==0 && !ior.Samples[0].WeaponIdRaw.HasValue && ior.Samples[0].Detail.Contains("combat runtime field"),"ID runtime offset mismatch discards the tentative row");
            Fixture idDispatch=WeaponFixture();idDispatch.U64(Fixture.Class(31595)+0x138UL+14UL*16UL,idDispatch.Module.LoadBias+0x6ee2678);PlayerStateResult idr=idDispatch.Weapon(idDispatch.Run());
            Check(idr.Sampled==0 && idr.Samples[0].Detail.Contains("weapon ID virtual dispatch"),"GetUIntKey is not substituted for actual GetId dispatch");
            StateField idField=null;foreach(StateField field in WeaponContextReference.Fields)if(field.Owner==31595)idField=field;
            Fixture idRegistration=WeaponFixture();PlayerObjectResult irc=idRegistration.Run();idRegistration.U32(idRegistration.Module.LoadBias+idField.OffsetRva,0x64);PlayerStateResult ir=idRegistration.Weapon(irc);
            Check(ir.Sampled==0 && ir.Samples.Length==0 && ir.Detail.Contains("weapon field registration"),"ID source offset registration must match the exact getter");
            Fixture idType=WeaponFixture();PlayerObjectResult itc=idType.Run();idType.U32(idType.Module.LoadBias+idField.Descriptor+8,idField.Bits^0x10000U);PlayerStateResult itr=idType.Weapon(itc);
            Check(itr.Sampled==0 && itr.Samples.Length==0 && itr.Detail.Contains("weapon field type flags"),"ID field descriptor must remain UInt32");
            Fixture idChange=WeaponFixture();PlayerObjectResult idc=idChange.Run();ulong ida=idChange.Physical(Fixture.WeaponDataObject+0x68);bool idFlip=false;
            idChange.Memory.AfterRead=delegate(ulong p,int n){if(!idFlip && p==ida && n==4){idFlip=true;idChange.U32(Fixture.WeaponDataObject+0x68,1235);}};PlayerStateResult icr=idChange.Weapon(idc);
            Check(icr.Sampled==0 && !icr.Samples[0].WeaponIdRaw.HasValue,"ID changes during capture discard the tentative ID");
            Fixture idGateChange=WeaponFixture();PlayerObjectResult igc=idGateChange.Run();ulong iga=idGateChange.Physical(Fixture.WeaponDataObject+0x68);
            idGateChange.Memory.AfterRead=delegate(ulong p,int n){if(p==iga && n==4)idGateChange.U64(Fixture.Array+0x20+0x21a65UL*8UL,Fixture.Player);};PlayerStateResult igr=idGateChange.Weapon(igc);
            Check(igr.Sampled==0 && !igr.Samples[0].WeaponIdRaw.HasValue,"GetId gate activation during capture invalidates the snapshot");
            Fixture idFinal=WeaponFixture();PlayerObjectResult ifc=idFinal.Run();ulong ifa=idFinal.Physical(Fixture.WeaponDataObject+0x68);
            idFinal.Memory.AfterRead=delegate(ulong p,int n){if(p==ifa && n==4)idFinal.Put(idFinal.Module.LoadBias+0x6ee2668,new byte[]{0});};PlayerStateResult ifr=idFinal.Weapon(ifc);
            Check(ifr.Sampled==0 && ifr.Samples.Length==0 && ifr.StopReason=="FINAL_CONTEXT_FAILED","changed final GetId code clears every weapon/ID observation");
            Check(f.Weapon(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","weapon observation requires exact build and roster prerequisites");
        }
    }
}
