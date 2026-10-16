using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong CombatController=0x5e000000,CombatStateObject=0x5e001000;
            internal void SetupCombat()
            {
                SetupState();SetupTeam();
                foreach(ObjectClassProfile p in CombatStateReference.Classes)
                {
                    ulong k=Class(p.Index),row=Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)p.Index*88UL;
                    MetadataIdentity(k,p);U64(k+0x20,row);U32(k+0x28,p.Bits);U32(k+0xf8,p.InstanceSize);U32(k+0xe0,1);
                    if(p.Parent>=0)U64(k+0x58,Class(p.Parent));
                    byte[] counts=new byte[16];System.Array.Copy(Reader.Hex(p.RecordHex),64,counts,0,16);Put(k+0x120,counts);
                }
                foreach(GameLayoutCheck a in CombatStateReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod q in CombatStateReference.Methods)
                { U64(Module.LoadBias+q.PointerRva,Module.LoadBias+q.Rva);Put(Layout.RuntimeMetadataBase+q.MetadataOffset,Reader.Hex(q.RecordHex)); }
                foreach(CombatMovement movement in CombatStateReference.Movement)
                { StateMethod q=movement.Method;U64(Module.LoadBias+q.PointerRva,Module.LoadBias+q.Rva);Put(Layout.RuntimeMetadataBase+q.MetadataOffset,Reader.Hex(q.RecordHex));Put(Module.LoadBias+q.Rva,Reader.Hex(movement.CodeHex)); }
                List<StateField> fields=new List<StateField>();fields.AddRange(PlayerStateReference.Fields);fields.AddRange(TeamPolicyReference.Fields);fields.AddRange(CombatStateReference.Fields);
                foreach(StateField f in fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,(uint)f.Offset);Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));
                    U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    ulong table=0xc0000000UL+(ulong)f.Owner*0x10000UL,at=table+(ulong)f.Local*32UL;
                    U64(Class(f.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);
                    U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);
                }
                foreach(TeamVirtual v in CombatStateReference.Virtuals)
                { U32(Layout.RuntimeMetadataBase+v.MetadataOffset,v.Encoded);U64(Class(v.Index)+0x138UL+(ulong)v.Slot*16UL,Module.LoadBias+v.Rva); }
                U64(Array+0x18,0x26000);
                foreach(int id in new int[]{0x447,0x4dd8,0x3c6a,0x25c3c,0x21f84,0x49b,0x49a,0x1d6,0x27a,0x279})U64(Array+0x20UL+(ulong)id*8UL,0);
                foreach(CombatMovement movement in CombatStateReference.Movement)U64(Array+0x20UL+(ulong)movement.Gate*8UL,0);
                U32(Other+0x1bb0,0);U64(Other+0x1d48,CombatController);U64(CombatController,Class(31716));U64(CombatController+0x10,Other);
                U32(CombatController+0x18,0);U64(CombatController+0x20,CombatStateObject);U64(CombatStateObject,Class(31738));U32(CombatStateObject+0x10,8);
                Put(0x5d0041fe,new byte[]{1});U32(FacadeStatics+0x114,23);
            }
            internal PlayerStateResult Combat(PlayerObjectResult core,int index=-1)
            { return Reader.SampleCombatState(Kernel,Game,Module,Layout,core,index,Progress.Add); }
        }
        private static Fixture CombatFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupCombat();return f; }
        private static PlayerStateObservation CombatSample(Fixture f)
        {
            PlayerStateResult r=f.Combat(f.Run());
            if(r.Sampled!=1)throw new Exception("Combat fixture sample failed: "+r.StopReason+" "+r.Detail+(r.Samples.Length>0?" "+r.Samples[0].Detail:""));
            return r.Samples[0];
        }
        private static void RunCombatTests()
        {
            Fixture f=CombatFixture();PlayerObjectResult c=f.Run();int start=f.Reader.PhysicalCalls;PlayerStateResult result=f.Combat(c);
            Check(result.Sampled==1 && result.Samples.Length==1 && !result.Samples[0].IsLocal && result.Samples[0].Player==Fixture.Other &&
                result.Samples[0].IsWatching==false && result.Samples[0].IsInAnyGhost==false && result.Samples[0].IsDieing==true &&
                result.Samples[0].GameModeRaw==23 && result.Samples[0].MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "combat samples one revalidated nonlocal member: "+result.StopReason+" "+result.Detail+(result.Samples.Length>0?" "+result.Samples[0].Detail:""));
            Check(f.Reader.PhysicalCalls-start<=6000,"combat phase stays within its 6000-read allowance");
            Console.WriteLine("COMBAT_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            Fixture watch=CombatFixture();watch.U64(Fixture.Other,Fixture.Class(34657));watch.U64(Fixture.Current,Fixture.Class(34188));watch.U32(Fixture.Current+0x29c,123);
            PlayerStateObservation w=CombatSample(watch);Check(w.IsWatching==true && w.WatchingGameClass!=null && BitConverter.ToUInt32(watch.Reader.Virtual(watch.Game.Root,Fixture.Current+0x29c,4),0)==123,
                "Watching Boolean is mode-dependent and its original side-effect counter remains unchanged");
            Fixture nonMatch=CombatFixture();nonMatch.U64(Fixture.Other,Fixture.Class(34657));
            Check(CombatSample(nonMatch).IsWatching==false,"Watching class name alone does not force IsWatching=true outside the required game family");
            foreach(uint ghost in new uint[]{0,1,2,99,uint.MaxValue})
            {
                Fixture x=CombatFixture();x.U32(Fixture.Other+0x1bb0,ghost);PlayerStateObservation s=CombatSample(x);
                Check(s.IsInAnyGhost==(ghost!=0) && s.GhostKindRaw==unchecked((int)ghost),"original ghost predicate retains signed raw enum: "+ghost);
            }
            Fixture dead=CombatFixture();dead.Put(Fixture.Other+0x7c,new byte[]{1});dead.U64(Fixture.CombatController+0x20,1);
            Check(CombatSample(dead).IsDieing==false,"base death short-circuits controller movement/state traversal");
            Fixture moving=CombatFixture();moving.U32(Fixture.CombatController+0x18,7);moving.U64(Fixture.CombatController+0x20,1);
            Check(CombatSample(moving).IsDieing==false,"nonzero direct movement short-circuits unused controller state");
            foreach(uint state in new uint[]{0,7,8,9,uint.MaxValue})
            {
                Fixture x=CombatFixture();x.U32(Fixture.CombatStateObject+0x10,state);
                Check(CombatSample(x).IsDieing==(state==8),"original dying final state comparison: "+state);
            }
            Fixture nullState=CombatFixture();nullState.U64(Fixture.CombatController+0x20,0);
            Check(CombatSample(nullState).IsDieing==false,"null state uses the original zero state ID");
            Fixture virtualMove=CombatFixture();virtualMove.Put(0x5d0041fe,new byte[]{0});PlayerStateObservation vm=CombatSample(virtualMove);
            Check(vm.IsDieing==true && vm.MovementStateRaw==0 && vm.DirectMovementSelector==false,"virtual movement getter supports the verified original zero-return implementation");
            foreach(CombatMovement movement in CombatStateReference.Movement)
            {
                TeamVirtual slot=null;foreach(TeamVirtual v in CombatStateReference.Virtuals)if(v.Slot==4 && v.Rva==movement.Rva){slot=v;break;}
                Fixture x=CombatFixture();x.Put(0x5d0041fe,new byte[]{0});x.U64(Fixture.CombatStateObject,Fixture.Class(slot.Index));
                PlayerStateObservation s=CombatSample(x);
                Check(s.MovementStateRaw==movement.Value && s.IsDieing==(movement.Value==0),"verified original movement dispatch: "+movement.Rva.ToString("x"));
            }
            foreach(int id in new int[]{0x49b,0x49a,0x447,0x1d6,0x27a,0x279})
            {
                Fixture x=CombatFixture();PlayerObjectResult xc=x.Run();x.U64(Fixture.Array+0x20UL+(ulong)id*8UL,Fixture.Other);
                PlayerStateResult r=x.Combat(xc);Check(r.Sampled==1 && !r.Samples[0].IsDieing.HasValue && r.Samples[0].DyingStatus=="UNVERIFIED_HOTFIX_ACTIVE","dying original-path gate: "+id);
            }
            foreach(int id in new int[]{0x3c6a,0x25c3c,0x21f84,0x10a})
            {
                Fixture x=CombatFixture();if(id==0x25c3c)x.U64(Fixture.Other,Fixture.Class(34657));PlayerObjectResult xc=x.Run();x.U64(Fixture.Array+0x20UL+(ulong)id*8UL,Fixture.Other);
                PlayerStateResult r=x.Combat(xc);PlayerStateObservation s=r.Samples[0];
                Check(r.Sampled==1 && (id==0x21f84?!s.IsInAnyGhost.HasValue:id==0x10a?s.GameModeStatus=="UNVERIFIED_HOTFIX_ACTIVE":!s.IsWatching.HasValue),"combat semantic gate suppresses its interpretation: "+id);
            }
            Fixture mvHot=CombatFixture();mvHot.Put(0x5d0041fe,new byte[]{0});PlayerObjectResult mh=mvHot.Run();CombatMovement zero=null;
            foreach(CombatMovement q in CombatStateReference.Movement)if(q.Rva==0x70e5d54)zero=q;
            mvHot.U64(Fixture.Array+0x20UL+(ulong)zero.Gate*8UL,Fixture.Other);
            Check(!mvHot.Combat(mh).Samples[0].IsDieing.HasValue,"virtual movement hotfix suppresses the dying predicate");
            Fixture nullControl=CombatFixture();nullControl.U64(Fixture.Other+0x1d48,0);
            Check(CombatSample(nullControl).DyingStatus=="NOT_READY_CONTROLLER_NULL","missing controller is unknown rather than alive");
            Fixture wrongOwner=CombatFixture();wrongOwner.U64(Fixture.CombatController+0x10,Fixture.Player);PlayerStateResult owner=wrongOwner.Combat(wrongOwner.Run());
            Check(owner.Sampled==0 && owner.Samples[0].Status=="NOT_READY_CONTEXT_CHANGED" && !owner.Samples[0].IsWatching.HasValue,"controller owner mismatch discards all tentative role values");
            Fixture badClass=CombatFixture();badClass.U32(Fixture.Class(31716)+0xf8,16);PlayerStateResult bc=badClass.Combat(badClass.Run());
            Check(bc.Sampled==0 && bc.Samples[0].Detail.Contains("combat class layout"),"controller class extent is verified before reads");
            Fixture badDispatch=CombatFixture();badDispatch.U64(Fixture.Class(32360)+0x138+144*16,badDispatch.Module.LoadBias+0x6f39998);
            PlayerStateResult bd=badDispatch.Combat(badDispatch.Run());Check(bd.Sampled==0 && bd.Samples[0].Detail.Contains("combat virtual dispatch"),"Watching runtime dispatch must match the exact metadata slot");
            Fixture badSelector=CombatFixture();badSelector.Put(0x5d0041fe,new byte[]{2});PlayerStateResult bs=badSelector.Combat(badSelector.Run());
            Check(bs.Sampled==0 && !bs.Samples[0].GhostKindRaw.HasValue,"invalid movement selector clears the entire tentative sample");
            Fixture mutation=CombatFixture();PlayerObjectResult mc=mutation.Run();ulong at=mutation.Physical(Fixture.Other+0x1bb0);bool changed=false;
            mutation.Memory.AfterRead=delegate(ulong p,int n){if(!changed && p==at && n==4){changed=true;mutation.U32(Fixture.Other+0x1bb0,1);}};
            PlayerStateResult mr=mutation.Combat(mc);Check(mr.Sampled==0 && !mr.Samples[0].IsDieing.HasValue && mr.Samples[0].Status=="NOT_READY_CONTEXT_CHANGED","state changes invalidate the whole combat sample");
            Fixture final=CombatFixture();PlayerObjectResult fc=final.Run();ulong ft=final.Physical(Fixture.CombatStateObject+0x10);
            final.Memory.AfterRead=delegate(ulong p,int n){if(p==ft && n==4)final.U32(final.Module.LoadBias+CombatStateReference.Fields[0].OffsetRva,0x118);};
            PlayerStateResult fr=final.Combat(fc);Check(fr.Sampled==0 && fr.Samples.Length==0 && fr.StopReason=="FINAL_CONTEXT_FAILED","final combat schema rejection discards all samples");
            Fixture unknown=CombatFixture();unknown.U64(Fixture.CombatController,Fixture.Class(11715));PlayerStateObservation us=CombatSample(unknown);
            Check(!us.IsDieing.HasValue && us.DyingStatus=="UNSUPPORTED_CONTROLLER_CLASS" && us.IsWatching==false,"unrecognized controller retains other independent predicates and unknown dying");
            Fixture uninit=CombatFixture();uninit.U32(Fixture.Class(11718)+0xe0,0);PlayerStateResult ur=uninit.Combat(uninit.Run());
            Check(ur.Sampled==0 && ur.Samples[0].Detail.Contains("GameVar initialized"),"probe does not initialize GameVar statics");
            Fixture field=CombatFixture();StateField sf=CombatStateReference.Fields[1];PlayerObjectResult fieldCore=field.Run();
            field.U32(0xc0000000UL+(ulong)sf.Owner*0x10000UL+(ulong)sf.Local*32UL+24,0x1bb4);PlayerStateResult fieldResult=field.Combat(fieldCore);
            Check(fieldResult.Sampled==0 && fieldResult.Samples[0].Detail.Contains("combat runtime field"),"runtime ghost FieldInfo offset must match registration");
            Fixture removed=CombatFixture();PlayerObjectResult rc=removed.Run();ulong ra=removed.Physical(Fixture.Other+0x1bb0);
            removed.Memory.AfterRead=delegate(ulong p,int n){if(p==ra && n==4)removed.U32(Fixture.REntries+0x20+40,uint.MaxValue);};
            PlayerStateResult rr=removed.Combat(rc);Check(rr.Sampled==0 && !rr.Samples[0].IsWatching.HasValue,"member removal invalidates every tentative combat predicate");
            Fixture cast=CombatFixture();cast.U64(Fixture.Other,Fixture.Class(34657));cast.U64(Fixture.Current,Fixture.Class(34188));
            cast.U64(0xd0000000UL+34188UL*0x100UL+8,Fixture.Class(12425));PlayerStateResult cr=cast.Combat(cast.Run());
            Check(cr.Sampled==0 && cr.Samples[0].Detail.Contains("runtime cast"),"Watching native hierarchy must agree with verified class ancestry");
            Fixture hotChange=CombatFixture();PlayerObjectResult hotCore=hotChange.Run();ulong ha=hotChange.Physical(Fixture.Other+0x1bb0);
            hotChange.Memory.AfterRead=delegate(ulong p,int n){if(p==ha && n==4)hotChange.U64(Fixture.Array+0x20UL+0x3c6aUL*8UL,Fixture.Other);};
            PlayerStateResult hr=hotChange.Combat(hotCore);Check(hr.Sampled==0 && !hr.Samples[0].IsWatching.HasValue,"mid-capture Watching hotfix activation discards all values");
            Fixture code=CombatFixture();code.Put(0x5d0041fe,new byte[]{0});PlayerObjectResult codeCore=code.Run();code.Put(code.Module.LoadBias+0x70e5d54,new byte[]{0});
            PlayerStateResult codeResult=code.Combat(codeCore);Check(codeResult.Sampled==0 && codeResult.Samples[0].Detail.Contains("selected movement implementation"),"selected movement code bytes are verified before its constant is reproduced");
            Fixture index=CombatFixture();PlayerObjectResult ic=index.Run();int reads=index.Reader.PhysicalCalls;
            Check(index.Combat(ic,0).StopReason=="SELECTED_MEMBER_NOT_NONLOCAL" && index.Combat(ic,999).StopReason=="SELECTED_MEMBER_NOT_NONLOCAL" && index.Reader.PhysicalCalls==reads,
                "explicit selection rejects a local or missing member without reads");
            Fixture budget=CombatFixture();PlayerObjectResult budgetCore=budget.Run();while(budget.Reader.PhysicalCalls<28500)budget.Reader.Physical(0,1);
            Check(budget.Combat(budgetCore).StopReason=="READ_BUDGET_RESERVE","combat phase preserves final-check reserve");
            Fixture cap=CombatFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27000)cap.Reader.Physical(0,1);PlayerStateResult capped=cap.Combat(capCore);
            Check(capped.Sampled==0 && cap.Reader.PhysicalCalls<=30000,"combat phase never resets or exceeds global read ceiling");
            Check(f.Combat(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","combat phase requires a verified roster");
        }
    }
}
