using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong TeamSettings=0x5b000000;
            internal void SetupTeam()
            {
                foreach(ObjectClassProfile p in TeamPolicyReference.Classes)
                {
                    ulong klass=Class(p.Index),row=Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)p.Index*88UL;
                    MetadataIdentity(klass,p);U64(klass+0x20,row);U32(klass+0x28,p.Bits);U32(klass+0xf8,p.InstanceSize);U32(klass+0xe0,1);
                    U64(klass+0x58,Class(p.Parent));byte[] counts=new byte[16];System.Array.Copy(Reader.Hex(p.RecordHex),64,counts,0,16);Put(klass+0x120,counts);
                }
                foreach(GameLayoutCheck check in TeamPolicyReference.Anchors)Put(Module.LoadBias+check.Address,check.Expected(Module.LoadBias));
                foreach(StateMethod q in TeamPolicyReference.Methods)
                { U64(Module.LoadBias+q.PointerRva,Module.LoadBias+q.Rva);Put(Layout.RuntimeMetadataBase+q.MetadataOffset,Reader.Hex(q.RecordHex)); }
                foreach(StateField field in TeamPolicyReference.Fields)
                {
                    U32(Module.LoadBias+field.OffsetRva,(uint)field.Offset);Put(Layout.RuntimeMetadataBase+field.MetadataOffset,Reader.Hex(field.RecordHex));
                    U32(Module.LoadBias+field.Descriptor+8,field.Bits);
                    if(field.TypeIndex>=0)U64(Module.LoadBias+field.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)field.TypeIndex*88UL);
                    ulong table=0xb0000000UL+(ulong)field.Owner*0x10000UL,at=table+(ulong)field.Local*32UL;
                    U64(Class(field.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+field.NameOffset);U64(at+8,Module.LoadBias+field.Descriptor);
                    U64(at+16,Class(field.Owner));U32(at+24,(uint)field.Offset);U32(at+28,field.Token);
                }
                foreach(TeamVirtual v in TeamPolicyReference.Virtuals)
                { U32(Layout.RuntimeMetadataBase+v.MetadataOffset,v.Encoded);U64(Class(v.Index)+0x138UL+(ulong)v.Slot*16UL,Module.LoadBias+v.Rva); }
                foreach(ObjectClassProfile profile in ObjectReference.Classes)
                {
                    if((profile.Family&4)==0)continue;
                    List<int> ancestors=new List<int>();ObjectClassProfile current=profile;
                    while(true)
                    {
                        ancestors.Insert(0,current.Index);if(current.Index==12425)break;
                        foreach(ObjectClassProfile candidate in ObjectReference.Classes)if(candidate.Index==current.Parent){current=candidate;break;}
                    }
                    ulong hierarchy=0xd0000000UL+(ulong)profile.Index*0x100UL;
                    U64(Class(profile.Index)+0xc8,hierarchy);Put(Class(profile.Index)+0x130,new byte[]{(byte)ancestors.Count});
                    for(int j=0;j<ancestors.Count;j++)U64(hierarchy+(ulong)j*8UL,Class(ancestors[j]));
                }
                U64(Module.LoadBias+TeamPolicyReference.DynamicClassCell,Class(34107));
                U64(Module.LoadBias+TeamPolicyReference.KeyCell,Class(34565));U32(Class(12418)+0x10c,0x1000);
                U64(Module.LoadBias+TeamPolicyReference.UnityObjectCell,Class(TeamPolicyReference.UnityObjectIndex));
                U64(Module.LoadBias+TeamPolicyReference.GameVarCell,Class(TeamPolicyReference.GameVarIndex));
                U64(Class(TeamPolicyReference.GameVarIndex)+0xb8,0x5d000000);U32(Class(TeamPolicyReference.GameVarIndex)+0x10c,0x5000);Put(0x5d00420b,new byte[]{0});
                U64(FacadeStatics+8,Current);U32(FacadeStatics+0x114,9);U64(Current+0x98,TeamSettings);U64(TeamSettings,Class(11715));Put(TeamSettings+0xa55,new byte[]{0});
                U64(Current+0x330,0);U64(Player+0x10,0x5a000000);U64(Other+0x10,0x5a001000);
                Put(Player+0x408,new byte[24]);Put(Other+0x408,new byte[24]);Put(Player+0x410,new byte[]{3});Put(Other+0x410,new byte[]{4});
                U32(Player+0x430,0);U32(Other+0x430,0);U64(Array+0x18,0x1000);
                foreach(int id in new int[]{0x4f5,0x149,0x148,0x10a,0x4f4,0x138,0x15e,0x15c,0x15b,0x15d})U64(Array+0x20UL+(ulong)id*8UL,0);
            }
            internal TeamPolicyResult Team(PlayerObjectResult core)
            { return Reader.SampleTeamPolicy(Kernel,Game,Module,Layout,core,Progress.Add); }
        }
        private static Fixture TeamFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupTeam();return f; }
        private static void RunTeamTests()
        {
            Fixture f=TeamFixture();PlayerObjectResult core=f.Run();int before=f.Reader.PhysicalCalls;TeamPolicyResult result=f.Team(core);
            Check(result.ContextVerified && result.Status=="ORIGINAL_PREDICATE_SAMPLED" && result.SameTeam==false && result.LocalTeamByte==3 && result.OtherTeamByte==4 &&
                result.Route=="PACKED_PLAYER_ID_BYTE" && result.GameModeRaw==9 && result.MembershipProof=="BOTH_SELECTED_ENTRIES_REVALIDATED",
                "team predicate follows verified packed IDs despite equal raw TeamIndex: "+result.Status+" "+result.Detail);
            Check(f.Reader.PhysicalCalls-before<=6000,"team phase respects its independent 6000-read budget");
            Fixture equal=TeamFixture();equal.Put(Fixture.Other+0x410,new byte[]{3});TeamPolicyResult same=equal.Team(equal.Run());
            Check(same.ContextVerified && same.SameTeam==true,"matching original policy bytes reproduce SameTeam=true");
            Fixture signed=TeamFixture();signed.Put(Fixture.Player+0x410,new byte[]{255});signed.Put(Fixture.Other+0x410,new byte[]{255});
            TeamPolicyResult maximum=signed.Team(signed.Run());Check(maximum.SameTeam==true && maximum.LocalTeamByte==255,"policy comparison preserves unsigned byte 255");
            Fixture faction=TeamFixture();faction.U32(Fixture.FacadeStatics+0x114,58);TeamPolicyResult fac=faction.Team(faction.Run());
            Check(fac.ContextVerified && fac.Status=="UNSUPPORTED_FACTION_POLICY" && !fac.SameTeam.HasValue,"faction mode never falls back to packed team equality");
            foreach(int id in new int[]{0x4f5,0x149,0x148,0x10a,0x4f4,0x138,0x15e,0x15c,0x15b})
            {
                Fixture hot=TeamFixture();PlayerObjectResult hc=hot.Run();hot.U64(Fixture.Array+0x20UL+(ulong)id*8UL,Fixture.Other);
                TeamPolicyResult h=hot.Team(hc);Check(h.ContextVerified && h.Status=="UNVERIFIED_HOTFIX_ACTIVE" && !h.SameTeam.HasValue,"team original-path hotfix gate Id="+id);
            }
            Fixture missing=TeamFixture();missing.U64(Fixture.FacadeStatics+8,0);TeamPolicyResult noMatch=missing.Team(missing.Run());
            Check(noMatch.ContextVerified && noMatch.Status=="UNSUPPORTED_NO_CURRENT_MATCH_GAME" && !noMatch.SameTeam.HasValue,"absent CurrentMatchGame is not silently replaced by CurrentGame");
            Fixture distinct=TeamFixture();distinct.U64(Fixture.FacadeStatics+8,Fixture.Current+0x1000);TeamPolicyResult separate=distinct.Team(distinct.Run());
            Check(separate.ContextVerified && separate.Status=="UNSUPPORTED_DISTINCT_CURRENT_MATCH_GAME","distinct settings-selection branches remain unsupported");
            Fixture cache=TeamFixture();cache.U64(Fixture.Current+0x98,0);TeamPolicyResult empty=cache.Team(cache.Run());
            Check(empty.ContextVerified && empty.Status=="NOT_READY_CACHED_SETTINGS_NULL" && !empty.SameTeam.HasValue,"missing settings are never initialized by the read-only probe");
            Fixture dyn=TeamFixture();dyn.U64(Fixture.Current,Fixture.Class(34188));dyn.Put(Fixture.TeamSettings+0xa55,new byte[]{1});
            TeamPolicyResult defaultTeam=dyn.Team(dyn.Run());
            Check(defaultTeam.ContextVerified && defaultTeam.Status=="ORIGINAL_DYNAMIC_NULL_DEFAULT" && defaultTeam.SameTeam==true && defaultTeam.LocalTeamByte==255 && defaultTeam.DynamicDictionaryPresent==false,
                "verified dynamic null-dictionary path retains the original 255 default: "+defaultTeam.Status+" "+defaultTeam.Detail);
            Fixture populated=TeamFixture();populated.U64(Fixture.Current,Fixture.Class(34188));populated.Put(Fixture.TeamSettings+0xa55,new byte[]{1});populated.U64(Fixture.Current+0x330,0x5c000000);
            TeamPolicyResult dynamic=populated.Team(populated.Run());
            Check(dynamic.ContextVerified && dynamic.Status=="UNSUPPORTED_DYNAMIC_TEAM_DICTIONARY" && dynamic.DynamicDictionaryPresent==true && !dynamic.SameTeam.HasValue && !dynamic.LocalTeamByte.HasValue,
                "a populated dynamic dictionary never reuses packed ID or raw TeamIndex equality");
            Fixture dynHot=TeamFixture();dynHot.U64(Fixture.Current,Fixture.Class(34188));dynHot.Put(Fixture.TeamSettings+0xa55,new byte[]{1});PlayerObjectResult dc=dynHot.Run();dynHot.U64(Fixture.Array+0x20UL+0x15dUL*8UL,Fixture.Player);
            TeamPolicyResult dh=dynHot.Team(dc);Check(dh.ContextVerified && dh.Status=="UNVERIFIED_HOTFIX_ACTIVE" && !dh.SameTeam.HasValue,"dynamic lookup gate is honored before null-default interpretation");
            Fixture plain=TeamFixture();plain.Put(Fixture.TeamSettings+0xa55,new byte[]{1});TeamPolicyResult uncast=plain.Team(plain.Run());
            Check(uncast.ContextVerified && uncast.Route=="PACKED_PLAYER_ID_BYTE" && uncast.SameTeam==false,"dynamic flag alone does not apply a subclass-only dictionary path");
            Fixture selector=TeamFixture();selector.Put(0x5d00420b,new byte[]{1});TeamPolicyResult branch=selector.Team(selector.Run());
            Check(branch.ContextVerified && branch.SameTeam==false,"both original settings branches select the same verified CurrentGame/CurrentMatchGame object");
            Fixture uninitialized=TeamFixture();uninitialized.U32(Fixture.Class(TeamPolicyReference.GameVarIndex)+0xe0,0);TeamPolicyResult init=uninitialized.Team(uninitialized.Run());
            Check(!init.ContextVerified && !init.SameTeam.HasValue && init.Detail.Contains("root static initialization"),"probe never assumes an unexecuted GameVar static constructor");
            Fixture overrideMatch=TeamFixture();int overrideIndex=-1;
            foreach(TeamVirtual v in TeamPolicyReference.Virtuals)if(v.Slot==92 && v.Rva!=0x7328844){overrideIndex=v.Index;break;}
            Check(overrideIndex>=0,"exact-build reference includes unsupported match-policy overrides");
            overrideMatch.U64(Fixture.Current,Fixture.Class(overrideIndex));TeamPolicyResult overridden=overrideMatch.Team(overrideMatch.Run());
            Check(overridden.ContextVerified && overridden.Status=="UNSUPPORTED_MATCH_POLICY_OVERRIDE" && !overridden.SameTeam.HasValue,"custom match policy is not treated as base MatchGame");
            Fixture badFlag=TeamFixture();badFlag.Put(Fixture.TeamSettings+0xa55,new byte[]{2});TeamPolicyResult invalid=badFlag.Team(badFlag.Run());
            Check(!invalid.ContextVerified && invalid.Status=="FAIL" && !invalid.GameModeRaw.HasValue,"invalid settings Boolean clears the entire tentative result");
            Fixture native=TeamFixture();native.U64(Fixture.Other+0x10,0);TeamPolicyResult destroyed=native.Team(native.Run());
            Check(destroyed.ContextVerified && destroyed.Status=="NOT_READY_NATIVE_PLAYER_OBJECT" && !destroyed.SameTeam.HasValue,"native-null player is never classified by its leftover ID");
            Fixture vtable=TeamFixture();vtable.U64(Fixture.Class(12425)+0x6f8,vtable.Module.LoadBias+0x7328848);TeamPolicyResult badDispatch=vtable.Team(vtable.Run());
            Check(!badDispatch.ContextVerified && badDispatch.Status=="FAIL" && badDispatch.Detail.Contains("team virtual dispatch"),"actual match dispatch must match metadata and the original target");
            Fixture settings=TeamFixture();settings.U32(Fixture.Class(11715)+0xf8,0x10);TeamPolicyResult badSettings=settings.Team(settings.Run());
            Check(!badSettings.ContextVerified && badSettings.Detail.Contains("team class layout"),"mode settings class extent must match the inspected build");
            Fixture cast=TeamFixture();cast.U64(0xd0000000UL+12425UL*0x100UL,Fixture.Class(34107));TeamPolicyResult badCast=cast.Team(cast.Run());
            Check(!badCast.ContextVerified && badCast.Detail.Contains("runtime cast agrees"),"runtime MatchGame cast table must agree with metadata ancestry");
            Fixture dynamicCast=TeamFixture();dynamicCast.U64(Fixture.Current,Fixture.Class(34188));dynamicCast.Put(Fixture.TeamSettings+0xa55,new byte[]{1});
            dynamicCast.U64(0xd0000000UL+34188UL*0x100UL+8UL,Fixture.Class(12425));TeamPolicyResult badDynamicCast=dynamicCast.Team(dynamicCast.Run());
            Check(!badDynamicCast.ContextVerified && !badDynamicCast.SameTeam.HasValue && badDynamicCast.Detail.Contains("runtime cast agrees"),"dynamic subclass cast cannot be inferred from names alone");
            Fixture moving=TeamFixture();PlayerObjectResult mc=moving.Run();ulong moveAt=moving.Physical(Fixture.Other+0x408);bool changed=false;
            moving.Memory.AfterRead=delegate(ulong at,int length){if(at==moveAt && length==24 && !changed){changed=true;moving.Put(Fixture.Other+0x410,new byte[]{3});}};
            TeamPolicyResult stale=moving.Team(mc);Check(!stale.ContextVerified && stale.Status=="NOT_READY_CONTEXT_CHANGED" && !stale.SameTeam.HasValue && !stale.LocalTeamByte.HasValue,
                "player ID mutation clears both tentative team values and the predicate");
            Fixture member=TeamFixture();PlayerObjectResult memberCore=member.Run();ulong memberAt=member.Physical(Fixture.Other+0x408);
            member.Memory.AfterRead=delegate(ulong at,int length){if(at==memberAt && length==24)member.U32(Fixture.REntries+0x20UL+40UL,uint.MaxValue);};
            TeamPolicyResult removed=member.Team(memberCore);Check(!removed.ContextVerified && removed.Status=="NOT_READY_CONTEXT_CHANGED" && !removed.SameTeam.HasValue,"selected member removal invalidates the team pair");
            Fixture mode=TeamFixture();PlayerObjectResult modeCore=mode.Run();ulong modeAt=mode.Physical(Fixture.Other+0x408);
            mode.Memory.AfterRead=delegate(ulong at,int length){if(at==modeAt && length==24)mode.U32(Fixture.FacadeStatics+0x114,58);};
            TeamPolicyResult changedMode=mode.Team(modeCore);Check(!changedMode.ContextVerified && changedMode.Status=="NOT_READY_CONTEXT_CHANGED","mode changes during sampling invalidate the route and predicate");
            Fixture counters=TeamFixture();PlayerObjectResult cc=counters.Run();ulong counterAt=counters.Physical(Fixture.Other+0x408);
            counters.Memory.AfterRead=delegate(ulong at,int length){if(at==counterAt && length==24)counters.U32(Fixture.RDict+0x2c,7);};
            TeamPolicyResult audit=counters.Team(cc);Check(audit.ContextVerified && audit.CountersChangedDuringCapture && audit.SameTeam==false,"unrelated global version changes are audited while both selected entries remain exact");
            Fixture schema=TeamFixture();PlayerObjectResult sc=schema.Run();ulong schemaAt=schema.Physical(Fixture.Other+0x408);
            schema.Memory.AfterRead=delegate(ulong at,int length){if(at==schemaAt && length==24)schema.U32(schema.Module.LoadBias+TeamPolicyReference.Fields[1].OffsetRva,0x118);};
            TeamPolicyResult badFinal=schema.Team(sc);Check(!badFinal.ContextVerified && !badFinal.SameTeam.HasValue && !badFinal.GameModeRaw.HasValue,"final schema mismatch discards the entire team observation");
            Fixture missingPair=TeamFixture();PlayerObjectResult pc=missingPair.Run();pc.MatchPlayers=new MatchPlayerObservation[]{pc.MatchPlayers[0]};
            Check(missingPair.Team(pc).Status=="NO_VERIFIED_LOCAL_OTHER_PAIR","team probe requires both a verified local member and a nonlocal member");
            Fixture budget=TeamFixture();PlayerObjectResult bc=budget.Run();while(budget.Reader.PhysicalCalls<28500)budget.Reader.Physical(0,1);
            Check(budget.Team(bc).Status=="READ_BUDGET_RESERVE" && budget.Reader.PhysicalCalls==28500,"team phase preserves its final-check reserve");
            Fixture cap=TeamFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27500)cap.Reader.Physical(0,1);
            TeamPolicyResult capped=cap.Team(capCore);Check(!capped.ContextVerified && capped.Status=="READ_LIMIT_REACHED" && !capped.SameTeam.HasValue && cap.Reader.PhysicalCalls<=30000,"team sampling never resets the global physical read limit");
            Check(f.Team(new PlayerObjectResult()).Status=="PREREQUISITES_UNVERIFIED","team probe requires verified core prerequisites");
            Console.WriteLine("TEAM_POLICY_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-before));
        }
    }
}
