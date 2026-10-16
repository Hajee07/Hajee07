using System;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong LocalMask=0x59000000,OtherMask=0x59001000;
            internal void SetupState()
            {
                foreach(ObjectClassProfile p in PlayerStateReference.Classes)
                {
                    ulong klass=Class(p.Index),row=Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)p.Index*88UL;
                    MetadataIdentity(klass,p);U64(klass+0x20,row);U32(klass+0x28,p.Bits);U32(klass+0xf8,p.InstanceSize);
                    U64(klass+0x58,Class(p.Parent));byte[] counts=new byte[16];System.Array.Copy(Reader.Hex(p.RecordHex),64,counts,0,16);Put(klass+0x120,counts);
                }
                foreach(GameLayoutCheck a in PlayerStateReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod method in PlayerStateReference.Methods)
                { U64(Module.LoadBias+method.PointerRva,Module.LoadBias+method.Rva);Put(Layout.RuntimeMetadataBase+method.MetadataOffset,Reader.Hex(method.RecordHex)); }
                foreach(StateField f in PlayerStateReference.Fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,(uint)f.Offset);Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));
                    U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    ulong table=0xa0000000UL+(ulong)f.Owner*0x10000UL,at=table+(ulong)f.Local*32UL;
                    U64(Class(f.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);
                    U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);
                }
                foreach(StateVisibility v in PlayerStateReference.Visibility)
                { U32(Layout.RuntimeMetadataBase+v.MetadataOffset,v.Encoded);U64(Class(v.Index)+0x138UL+70UL*16UL,Module.LoadBias+v.Rva); }
                U64(Array+0x18,0x21bf4);
                foreach(int id in new int[]{0x447,0x4dd8,0x21bf3})U64(Array+0x20UL+(ulong)id*8UL,0);
                for(int i=0;i<2;i++)
                {
                    ulong owner=i==0?Player:Other,mask=i==0?LocalMask:OtherMask;
                    U32(owner+0x430,(uint)(i+3));Put(owner+0x7c,new byte[]{0});Put(owner+0xa6c,new byte[]{0});U64(owner+0xad0,mask);
                    U64(mask,Class(36356));U32(mask+0x10,1);U32(mask+0x18,1);
                }
            }
            internal PlayerStateResult States(PlayerObjectResult core)
            { return Reader.SamplePlayerStates(Kernel,Game,Module,Layout,core,Progress.Add); }
        }
        private static Fixture StateFixture()
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupState();return f; }
        private static void RunStateTests()
        {
            Fixture f=StateFixture();PlayerObjectResult core=f.Run();int before=f.Reader.PhysicalCalls;PlayerStateResult result=f.States(core);
            Check(result.Sampled==2 && result.Samples[0].IsLocal && !result.Samples[1].IsLocal && result.Samples[0].TeamIndex==3 && result.Samples[1].TeamIndex==4 &&
                result.Samples[1].ModelVisible==true && result.Samples[1].ReallyDead==false && result.Samples[1].MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "state sampling verifies separate local/nonlocal raw values and endpoint membership: "+result.StopReason+" "+result.Detail+
                (result.Samples.Length>0?" "+result.Samples[0].Detail:""));
            Check(f.Reader.PhysicalCalls-before<=6000,"state sampling stays inside its independent 6000-read phase budget");
            for(int bits=0;bits<4;bits++)
            {
                Fixture x=StateFixture();x.Put(Fixture.Player+0x7c,new byte[]{(byte)(bits&1)});x.Put(Fixture.Player+0xa6c,new byte[]{(byte)(bits>>1)});
                PlayerStateResult value=x.States(x.Run());
                Check(value.Sampled==2 && value.Samples[0].ReallyDead==(bits==1),"original really-dead truth table case "+bits);
            }
            uint[] masks={0,1,0xffffffff,0xffffffff,1};uint[] modes={1,0,0,7,1};bool[] expected={false,false,true,true,true};
            for(int i=0;i<masks.Length;i++)
            {
                Fixture x=StateFixture();x.U32(Fixture.LocalMask+0x10,masks[i]);x.U32(Fixture.LocalMask+0x18,modes[i]);
                PlayerStateResult value=x.States(x.Run());
                Check(value.Sampled==2 && value.Samples[0].ModelVisible==expected[i],"exact Boolean mask/mode branch case "+i);
            }
            foreach(int id in new int[]{0x447,0x4dd8,0x21bf3})
            {
                Fixture x=StateFixture();PlayerObjectResult c=x.Run();x.U64(Fixture.Array+0x20UL+(ulong)id*8UL,Fixture.Player);
                PlayerStateResult value=x.States(c);PlayerStateObservation s=value.Samples[0];
                Check(value.Sampled==2 && s.TeamIndex.HasValue && s.BaseDeadRaw.HasValue &&
                    (id==0x21bf3 ? !s.ModelVisible.HasValue && s.ModelVisibilityStatus=="UNVERIFIED_HOTFIX_ACTIVE" : !s.ReallyDead.HasValue && s.ReallyDeadStatus=="UNVERIFIED_HOTFIX_ACTIVE"),
                    "active hotfix suppresses only the unsupported interpretation Id="+id);
            }
            Fixture watching=StateFixture();watching.U64(Fixture.Other,Fixture.Class(34657));PlayerStateResult watch=watching.States(watching.Run());
            Check(watch.Sampled==2 && watch.Samples[1].ModelVisibilityStatus=="UNSUPPORTED_VISIBILITY_OVERRIDE" && !watch.Samples[1].ModelVisible.HasValue && watch.Samples[1].TeamIndex==4,
                "Player_Watching virtual override never inherits Player model visibility semantics");
            Fixture nullMask=StateFixture();nullMask.U64(Fixture.Player+0xad0,0);PlayerStateResult nullResult=nullMask.States(nullMask.Run());
            Check(nullResult.Sampled==2 && !nullResult.Samples[0].ModelVisible.HasValue && nullResult.Samples[0].ModelVisibilityStatus=="NOT_READY_VISIBILITY_OBJECT_NULL",
                "a null visibility object produces unknown rather than false");
            Fixture negative=StateFixture();negative.U32(Fixture.Player+0x430,uint.MaxValue);PlayerStateResult signed=negative.States(negative.Run());
            Check(signed.Sampled==2 && signed.Samples[0].TeamIndex==-1,"TeamIndex retains signed raw values without team classification");
            Fixture malformed=StateFixture();malformed.Put(Fixture.Player+0x7c,new byte[]{2});PlayerStateResult badBool=malformed.States(malformed.Run());
            Check(badBool.Sampled==0 && badBool.Samples[0].Status=="FAIL" && !badBool.Samples[0].TeamIndex.HasValue && badBool.Samples[0].Detail.Contains("canonical state Boolean"),
                "noncanonical Boolean rejects the entire row without exposing earlier tentative fields");
            Fixture wrongOffset=StateFixture();PlayerObjectResult offsetCore=wrongOffset.Run();wrongOffset.U32(wrongOffset.Module.LoadBias+PlayerStateReference.Fields[0].OffsetRva,0x434);
            PlayerStateResult badOffset=wrongOffset.States(offsetCore);
            Check(badOffset.Sampled==0 && badOffset.Samples.Length==0 && badOffset.Detail.Contains("state field offset"),"changed state registration rejects the phase");
            Fixture wrongTable=StateFixture();PlayerObjectResult tableCore=wrongTable.Run();StateField tf=PlayerStateReference.Fields[0];
            wrongTable.U32(0xa0000000UL+(ulong)tf.Owner*0x10000UL+(ulong)tf.Local*32UL+24,0x434);PlayerStateResult badTable=wrongTable.States(tableCore);
            Check(badTable.Sampled==0 && badTable.Samples[0].Detail.Contains("state runtime field"),"runtime field tables must match the verified registration");
            Fixture wrongClass=StateFixture();wrongClass.U32(Fixture.Class(36356)+0xf8,24);PlayerStateResult badClass=wrongClass.States(wrongClass.Run());
            Check(badClass.Sampled==0 && badClass.Samples[0].Detail.Contains("state class layout"),"visibility storage class extent is verified");
            Fixture target=StateFixture();target.U64(Fixture.Class(31824)+0x138UL+70UL*16UL,target.Module.LoadBias+0x6f38838);PlayerStateResult badTarget=target.States(target.Run());
            Check(badTarget.Sampled==0 && badTarget.Samples[0].Detail.Contains("state visibility dispatch"),"changed virtual dispatch cannot reuse original visibility semantics");
            Fixture changed=StateFixture();PlayerObjectResult changeCore=changed.Run();ulong fieldAt=changed.Physical(Fixture.Player+0x430);bool flipped=false;
            changed.Memory.AfterRead=delegate(ulong at,int length){if(!flipped && at==fieldAt && length==4){flipped=true;changed.U32(Fixture.Player+0x430,99);}};
            PlayerStateResult stale=changed.States(changeCore);
            Check(stale.Sampled==0 && stale.Samples[0].Status=="NOT_READY_CONTEXT_CHANGED" && !stale.Samples[0].TeamIndex.HasValue,
                "a state change during capture discards all tentative values");
            Fixture removed=StateFixture();PlayerObjectResult removedCore=removed.Run();ulong removedAt=removed.Physical(Fixture.Player+0x430);
            removed.Memory.AfterRead=delegate(ulong at,int length){if(at==removedAt && length==4)removed.U32(Fixture.REntries+0x20,uint.MaxValue);};
            PlayerStateResult missing=removed.States(removedCore);
            Check(missing.Sampled==0 && missing.Samples[0].Status=="NOT_READY_CONTEXT_CHANGED" && missing.Samples[0].MembershipProof==null,
                "selected-entry removal discards state observations");
            Fixture hotChange=StateFixture();PlayerObjectResult hc=hotChange.Run();ulong maskAt=hotChange.Physical(Fixture.LocalMask+0x10);
            hotChange.Memory.AfterRead=delegate(ulong at,int length){if(at==maskAt && length==4)hotChange.U64(Fixture.Array+0x20UL+0x21bf3UL*8UL,Fixture.Player);};
            PlayerStateResult changedHotfix=hotChange.States(hc);
            Check(changedHotfix.Sampled==0 && !changedHotfix.Samples[0].ModelVisible.HasValue,"hotfix activation during sampling invalidates the row");
            Fixture final=StateFixture();PlayerObjectResult finalCore=final.Run();ulong finalAt=final.Physical(Fixture.OtherMask+0x10);
            final.Memory.AfterRead=delegate(ulong at,int length){if(at==finalAt && length==4)final.U32(final.Module.LoadBias+PlayerStateReference.Fields[0].OffsetRva,0x434);};
            PlayerStateResult invalidPhase=final.States(finalCore);
            Check(invalidPhase.Sampled==0 && invalidPhase.Samples.Length==0 && invalidPhase.StopReason=="FINAL_CONTEXT_FAILED",
                "phase-final schema failure discards every tentative state row");
            Fixture budget=StateFixture();PlayerObjectResult budgetCore=budget.Run();while(budget.Reader.PhysicalCalls<28500)budget.Reader.Physical(0,1);
            PlayerStateResult reserved=budget.States(budgetCore);
            Check(reserved.Samples.Length==0 && reserved.StopReason=="READ_BUDGET_RESERVE" && budget.Reader.PhysicalCalls==28500,
                "state phase leaves its final-check reserve untouched when global budget is low");
            Fixture limited=StateFixture();PlayerObjectResult limitedCore=limited.Run();while(limited.Reader.PhysicalCalls<27000)limited.Reader.Physical(0,1);
            PlayerStateResult cap=limited.States(limitedCore);
            Check(cap.Sampled<2 && limited.Reader.PhysicalCalls<=30000 && (cap.StopReason=="READ_LIMIT_REACHED" || cap.StopReason=="FINAL_CONTEXT_FAILED"),
                "state read exhaustion does not reset the global ceiling: "+cap.StopReason);
            Check(f.States(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","state reads require the verified roster");
            Console.WriteLine("PLAYER_STATE_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-before));
        }
    }
}
