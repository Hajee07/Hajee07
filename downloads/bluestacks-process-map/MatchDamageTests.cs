using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal void SetupDamage()
            {
                SetupTeam();
                foreach(GameLayoutCheck a in MatchDamageReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod q in MatchDamageReference.Methods)
                { U64(Module.LoadBias+q.PointerRva,Module.LoadBias+q.Rva);Put(Layout.RuntimeMetadataBase+q.MetadataOffset,Reader.Hex(q.RecordHex)); }
                List<StateField> fields=new List<StateField>();fields.AddRange(TeamPolicyReference.Fields);fields.AddRange(MatchDamageReference.Fields);
                foreach(StateField f in fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,(uint)f.Offset);Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    ulong table=0xf0000000UL+(ulong)f.Owner*0x10000UL,at=table+(ulong)f.Local*32UL;
                    U64(Class(f.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);
                }
                foreach(TeamVirtual v in MatchDamageReference.Virtuals)
                { U32(Layout.RuntimeMetadataBase+v.MetadataOffset,v.Encoded);U64(Class(v.Index)+0x138UL+(ulong)v.Slot*16UL,Module.LoadBias+v.Rva); }
                U64(Array+0x18,0x853e);U64(Array+0x20+0x853dUL*8UL,0);U32(FacadeStatics+0x114,23);
            }
            internal MatchDamagePolicyResult Damage(PlayerObjectResult core,Action<string> progress=null)
            { return Reader.SampleMatchDamagePolicy(Kernel,Game,Module,Layout,core,progress??Progress.Add); }
        }
        private static Fixture DamageFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupDamage();return f; }
        private static void RunDamageTests()
        {
            Fixture f=DamageFixture();f.U64(Fixture.Current,Fixture.Class(34188));PlayerObjectResult core=f.Run();int start=f.Reader.PhysicalCalls;MatchDamagePolicyResult result=f.Damage(core);
            Check(result.ContextVerified && result.Status=="ORIGINAL_ARGUMENT_INDEPENDENT_TRUE" && result.Predicate==true && result.ArgumentIndependent &&
                result.GameModeRaw==23 && result.MethodRva==0x7327e50 && result.OtherRosterIndex==1 && result.MembershipProof=="BOTH_SELECTED_ENTRIES_REVALIDATED",
                "current mode class reproduces only the original argument-independent match policy: "+result.Status+" "+result.Detail);
            Check(f.Reader.PhysicalCalls-start<=6000,"match damage phase stays within its 6000-read allowance");Console.WriteLine("MATCH_DAMAGE_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            Fixture arbitrary=DamageFixture();arbitrary.Put(Fixture.Other+0x7c,new byte[]{1});arbitrary.U64(Fixture.Other+0x768,0);
            MatchDamagePolicyResult independent=arbitrary.Damage(arbitrary.Run());Check(independent.Predicate==true && independent.ArgumentIndependent,"base policy ignores victim state and cannot itself establish combat eligibility");
            Fixture hot=DamageFixture();PlayerObjectResult hc=hot.Run();hot.U64(Fixture.Array+0x20+0x853dUL*8UL,Fixture.Other);MatchDamagePolicyResult hr=hot.Damage(hc);
            Check(hr.ContextVerified && !hr.Predicate.HasValue && !hr.ArgumentIndependent && hr.Status=="UNVERIFIED_HOTFIX_ACTIVE","active base policy hotfix never inherits the constant true result");
            Fixture custom=DamageFixture();custom.U64(Fixture.Current,Fixture.Class(34170));MatchDamagePolicyResult customResult=custom.Damage(custom.Run());
            Check(customResult.ContextVerified && !customResult.Predicate.HasValue && customResult.Status=="UNSUPPORTED_DAMAGE_POLICY_OVERRIDE" && customResult.MethodRva==0x7b10f2c,
                "argument-dependent custom match override stays unknown");
            Fixture missing=DamageFixture();missing.U64(Fixture.FacadeStatics+8,0);MatchDamagePolicyResult absent=missing.Damage(missing.Run());
            Check(absent.ContextVerified && !absent.Predicate.HasValue && absent.Status=="NOT_READY_CURRENT_MATCH_GAME_NULL","null CurrentMatchGame does not become an implicit policy allow");
            Fixture distinct=DamageFixture();distinct.U64(Fixture.FacadeStatics+8,Fixture.Current+0x1000);MatchDamagePolicyResult separate=distinct.Damage(distinct.Run());
            Check(separate.ContextVerified && !separate.Predicate.HasValue && separate.Status=="UNSUPPORTED_DISTINCT_CURRENT_MATCH_GAME","distinct current-game objects do not borrow one another's policy");
            Fixture mode=DamageFixture();PlayerObjectResult modeCore=mode.Run();mode.U64(Fixture.Array+0x20+0x10aUL*8UL,Fixture.Other);MatchDamagePolicyResult modeResult=mode.Damage(modeCore);
            Check(modeResult.ContextVerified && modeResult.Predicate==true && modeResult.GameModeStatus=="UNVERIFIED_HOTFIX_ACTIVE","raw mode getter hotfix does not change argument-independent policy or validate mode semantics");
            Fixture dispatch=DamageFixture();dispatch.U64(Fixture.Class(12425)+0x138+91*16,dispatch.Module.LoadBias+0x7b10f2c);MatchDamagePolicyResult changed=dispatch.Damage(dispatch.Run());
            Check(!changed.ContextVerified && !changed.Predicate.HasValue && changed.Detail.Contains("damage virtual dispatch"),"actual policy target must match metadata virtual slot");
            Fixture count=DamageFixture();count.Put(Fixture.Class(12425)+0x12a,new byte[]{91,0});MatchDamagePolicyResult noSlot=count.Damage(count.Run());
            Check(!noSlot.ContextVerified && noSlot.Detail.Contains("virtual slot count"),"class vtable extent must cover the policy slot");
            Fixture field=DamageFixture();PlayerObjectResult fieldCore=field.Run();field.U32(field.Module.LoadBias+MatchDamageReference.Fields[0].OffsetRva,16);MatchDamagePolicyResult wrongField=field.Damage(fieldCore);
            Check(!wrongField.ContextVerified && !wrongField.Predicate.HasValue && wrongField.Detail.Contains("field registration"),"policy context field registration is verified");
            Fixture init=DamageFixture();PlayerObjectResult initCore=init.Run();init.U32(Fixture.Class(12418)+0xe0,0);MatchDamagePolicyResult uninitialized=init.Damage(initCore);
            Check(!uninitialized.ContextVerified && uninitialized.Detail.Contains("initialized static extent"),"policy reader never initializes facade statics");
            Fixture swapped=DamageFixture();PlayerObjectResult swappedCore=swapped.Run();ulong at=swapped.Physical(Fixture.FacadeStatics+8);bool flip=false;
            swapped.Memory.AfterRead=delegate(ulong p,int n){if(!flip && p==at && n==8){flip=true;swapped.U64(Fixture.FacadeStatics+8,0);}};MatchDamagePolicyResult stale=swapped.Damage(swappedCore);
            Check(!stale.ContextVerified && !stale.Predicate.HasValue && !stale.GameModeRaw.HasValue && stale.Status=="NOT_READY_CONTEXT_CHANGED","changed CurrentMatchGame discards every tentative policy value");
            Fixture removed=DamageFixture();PlayerObjectResult removedCore=removed.Run();ulong methodAt=removed.Physical(Fixture.Class(12425)+0x138+91*16);
            removed.Memory.AfterRead=delegate(ulong p,int n){if(p==methodAt && n==8)removed.U32(Fixture.REntries+0x20+40,uint.MaxValue);};MatchDamagePolicyResult gone=removed.Damage(removedCore);
            Check(!gone.ContextVerified && !gone.Predicate.HasValue,"selected victim entry removal invalidates the pair-bound observation");
            Fixture liveGate=DamageFixture();PlayerObjectResult gateCore=liveGate.Run();ulong gateAt=liveGate.Physical(Fixture.Array+0x20+0x853dUL*8UL);
            liveGate.Memory.AfterRead=delegate(ulong p,int n){if(p==gateAt && n==8)liveGate.U64(Fixture.Array+0x20+0x853dUL*8UL,Fixture.Other);};MatchDamagePolicyResult gateChanged=liveGate.Damage(gateCore);
            Check(!gateChanged.ContextVerified && !gateChanged.Predicate.HasValue,"policy hotfix activation during capture rejects its earlier constant");
            Fixture final=DamageFixture();PlayerObjectResult finalCore=final.Run();MatchDamagePolicyResult finalResult=final.Damage(finalCore,delegate(string line){final.Put(final.Module.LoadBias+0x7327eb8,new byte[]{0});});
            Check(!finalResult.ContextVerified && !finalResult.Predicate.HasValue && finalResult.Detail.Contains("match-damage code"),"final policy-code failure discards all tentative output");
            Fixture finalSchema=DamageFixture();PlayerObjectResult schemaCore=finalSchema.Run();MatchDamagePolicyResult schemaResult=finalSchema.Damage(schemaCore,delegate(string line){finalSchema.U32(finalSchema.Module.LoadBias+MatchDamageReference.Fields[0].OffsetRva,16);});
            Check(!schemaResult.ContextVerified && !schemaResult.Predicate.HasValue && !schemaResult.GameModeRaw.HasValue,"final context schema failure clears mode and predicate");
            Fixture churn=DamageFixture();PlayerObjectResult churnCore=churn.Run();MatchDamagePolicyResult churnResult=churn.Damage(churnCore,delegate(string line){churn.U32(Fixture.RDict+0x2c,2);});
            Check(churnResult.ContextVerified && churnResult.Predicate==true && churnResult.CountersChangedDuringCapture,
                "unrelated roster counter changes are audited without fabricating full-roster stability");
            Fixture modeChange=DamageFixture();PlayerObjectResult modeChangeCore=modeChange.Run();MatchDamagePolicyResult modeChanged=modeChange.Damage(modeChangeCore,delegate(string line){modeChange.U32(Fixture.FacadeStatics+0x114,9);});
            Check(!modeChanged.ContextVerified && !modeChanged.Predicate.HasValue && !modeChanged.GameModeRaw.HasValue,
                "mode change during capture discards the entire match-policy context");
            Fixture context=DamageFixture();PlayerObjectResult contextCore=context.Run();context.U64(Fixture.Array+0x20+0x1bfUL*8UL,Fixture.Other);MatchDamagePolicyResult unsupportedContext=context.Damage(contextCore);
            Check(!unsupportedContext.ContextVerified && !unsupportedContext.Predicate.HasValue,"an original context hotfix invalidates the policy observation");
            Fixture pair=DamageFixture();PlayerObjectResult pairCore=pair.Run();pairCore.MatchPlayers=new MatchPlayerObservation[]{pairCore.MatchPlayers[0]};
            Check(pair.Damage(pairCore).Status=="NO_VERIFIED_LOCAL_OTHER_PAIR","policy mode does not invent an unverified victim pair");
            Fixture reserve=DamageFixture();PlayerObjectResult reserveCore=reserve.Run();while(reserve.Reader.PhysicalCalls<28500)reserve.Reader.Physical(0,1);
            Check(reserve.Damage(reserveCore).Status=="READ_BUDGET_RESERVE","policy phase leaves its final reserve untouched");
            Fixture cap=DamageFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<28000)cap.Reader.Physical(0,1);MatchDamagePolicyResult capped=cap.Damage(capCore);
            Check(!capped.ContextVerified && !capped.Predicate.HasValue && cap.Reader.PhysicalCalls<=30000,"policy phase cannot reset or exceed the global read ceiling");
            Check(f.Damage(new PlayerObjectResult()).Status=="PREREQUISITES_UNVERIFIED","match policy requires verified roster and exact-build context");
        }
    }
}
