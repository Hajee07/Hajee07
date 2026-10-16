using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping.Tests
{
    public static partial class PlayerObjectTests
    {
        private sealed partial class Fixture
        {
            internal const ulong ZonePoolObject=0x5f000000,ZoneArray=0x5f001000,ZoneArrayClass=0x5f002000,ZoneData=0x5f003000,ZoneUnsafeValue=0x5f004000,
                ZoneAttributes=0x5f005000,ZoneMask=0x5f006000,ZoneInterfaceTable=0x5f007000;
            internal void SetupZone(bool unsafePool=true)
            {
                SetupCombat();
                foreach(ObjectClassProfile p in ZoneProtectionReference.Classes)
                {
                    ulong k=Class(p.Index),row=Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)p.Index*88UL;
                    MetadataIdentity(k,p);U64(k+0x20,row);U32(k+0x28,p.Bits);U32(k+0xf8,p.InstanceSize);U32(k+0xe0,1);
                    if(p.Parent>=0)U64(k+0x58,Class(p.Parent));byte[] counts=new byte[16];System.Array.Copy(Reader.Hex(p.RecordHex),64,counts,0,16);Put(k+0x120,counts);
                }
                foreach(GameLayoutCheck a in ZoneProtectionReference.Anchors)Put(Module.LoadBias+a.Address,a.Expected(Module.LoadBias));
                foreach(StateMethod q in ZoneProtectionReference.Methods)
                { U64(Module.LoadBias+q.PointerRva,Module.LoadBias+q.Rva);Put(Layout.RuntimeMetadataBase+q.MetadataOffset,Reader.Hex(q.RecordHex)); }
                List<StateField> fields=new List<StateField>();fields.AddRange(PlayerStateReference.Fields);fields.AddRange(CombatStateReference.Fields);fields.AddRange(TeamPolicyReference.Fields);fields.AddRange(ZoneProtectionReference.Fields);
                foreach(StateField f in fields)
                {
                    U32(Module.LoadBias+f.OffsetRva,(uint)f.Offset);Put(Layout.RuntimeMetadataBase+f.MetadataOffset,Reader.Hex(f.RecordHex));U32(Module.LoadBias+f.Descriptor+8,f.Bits);
                    if(f.TypeIndex>=0)U64(Module.LoadBias+f.Descriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)f.TypeIndex*88UL);
                    ulong table=0xe0000000UL+(ulong)f.Owner*0x10000UL,at=table+(ulong)f.Local*32UL;
                    U64(Class(f.Owner)+0x80,table);U64(at,Layout.RuntimeMetadataBase+f.NameOffset);U64(at+8,Module.LoadBias+f.Descriptor);U64(at+16,Class(f.Owner));U32(at+24,(uint)f.Offset);U32(at+28,f.Token);
                }
                U64(Module.LoadBias+ZoneProtectionReference.InterfaceCell,Class(36648));
                foreach(ZonePool pool in ZoneProtectionReference.Pools)
                {
                    U64(Class(pool.Index)+0xb0,ZoneInterfaceTable+(ulong)(pool.Index==36655?0x100:0));ulong table=ZoneInterfaceTable+(ulong)(pool.Index==36655?0x100:0);
                    U64(table,Class(36649));U32(table+8,48);U64(table+16,Class(36648));U32(table+24,49);
                    StateField arrayField=null;foreach(StateField field in ZoneProtectionReference.Fields)if(field.Owner==pool.BaseIndex && field.Local==0)arrayField=field;
                    U64(Module.LoadBias+arrayField.Descriptor,Module.LoadBias+pool.ElementDescriptor);
                    U64(Module.LoadBias+pool.ElementDescriptor,Layout.RuntimeMetadataBase+GameLayoutReference.TypeDefinitionsOffset+(ulong)pool.DataIndex*88UL);U32(Module.LoadBias+pool.ElementDescriptor+8,0x120000);
                    Put(Layout.RuntimeMetadataBase+pool.InterfaceMetadataOffset,Reader.Hex(pool.InterfaceHex));U32(Layout.RuntimeMetadataBase+pool.Dispatch.MetadataOffset,pool.Dispatch.Encoded);
                    U64(Class(pool.Index)+0x138UL+(ulong)pool.Dispatch.Slot*16UL,Module.LoadBias+pool.Dispatch.Rva);
                }
                ZonePool selected=null;foreach(ZonePool pool in ZoneProtectionReference.Pools)if(pool.Index==(unsafePool?36655:36651))selected=pool;
                U64(Other+0x70,ZonePoolObject);U64(ZonePoolObject,Class(selected.Index));U64(ZonePoolObject+0x10,ZoneArray);U32(ZonePoolObject+0x18,100);
                U64(ZoneArray,ZoneArrayClass);U64(ZoneArray+0x18,100);U64(ZoneArray+0x20+37*8,ZoneData);U64(ZoneArrayClass+0x78,ZoneArrayClass);
                U64(ZoneArrayClass+0x40,Class(selected.DataIndex));U32(ZoneArrayClass+0x28,0x1d0000);U64(ZoneArrayClass+0x20,Module.LoadBias+selected.ElementDescriptor);
                U64(ZoneData,Class(selected.DataIndex));if(unsafePool){U64(ZoneData+0x18,ZoneUnsafeValue);Put(ZoneUnsafeValue,new byte[]{2});}else Put(ZoneData+0x18,new byte[]{2});
                U64(Other+0x768,ZoneAttributes);U64(ZoneAttributes,Class(34539));U64(ZoneAttributes+0x20,Other);U64(ZoneAttributes+0x2b0,ZoneMask);
                U64(ZoneMask,Class(36356));U32(ZoneMask+0x10,0);U32(ZoneMask+0x18,1);
                foreach(int id in new int[]{0x2558,0x2557,0x10a,0x44d2,0x3f0c,0x49c2})U64(Array+0x20UL+(ulong)id*8UL,0);
            }
            internal PlayerStateResult Zone(PlayerObjectResult core,int index=-1)
            { return Reader.SampleZoneProtection(Kernel,Game,Module,Layout,core,index,Progress.Add); }
        }
        private static Fixture ZoneFixture(bool unsafePool=true)
        { Fixture f=new Fixture();f.SetupNative();f.SetupRoster();f.SetupZone(unsafePool);return f; }
        private static PlayerStateObservation ZoneSample(Fixture f)
        {
            PlayerStateResult r=f.Zone(f.Run());if(r.Sampled!=1)throw new Exception("Zone sample failed: "+r.StopReason+" "+r.Detail+(r.Samples.Length>0?" "+r.Samples[0].Detail:""));return r.Samples[0];
        }
        private static void RunZoneTests()
        {
            Fixture f=ZoneFixture();PlayerObjectResult core=f.Run();int start=f.Reader.PhysicalCalls;PlayerStateResult result=f.Zone(core);
            Check(result.Sampled==1 && result.Samples[0].TrainingZone==2 && result.Samples[0].InBattleZone==true && result.Samples[0].InShootingRange==false &&
                result.Samples[0].Invincible==false && result.Samples[0].PoolClass=="GCommon.PRIDataPoolUnsafe" && result.Samples[0].MembershipProof=="SELECTED_ENTRY_REVALIDATED",
                "zone and invincibility snapshot validates unsafe pool and membership: "+result.StopReason+" "+result.Detail+(result.Samples.Length>0?" "+result.Samples[0].Detail:""));
            Check(f.Reader.PhysicalCalls-start<=6000,"zone/protection phase stays within its 6000-read allowance");Console.WriteLine("ZONE_FIXTURE_ADDITIONAL_READ_CALLS="+(f.Reader.PhysicalCalls-start));
            foreach(bool unsafePool in new bool[]{false,true})foreach(byte zone in new byte[]{0,1,2,3,255})
            {
                Fixture x=ZoneFixture(unsafePool);x.Put(unsafePool?Fixture.ZoneUnsafeValue:Fixture.ZoneData+0x18,new byte[]{zone});PlayerStateObservation s=ZoneSample(x);
                Check(s.TrainingZone==zone && s.InBattleZone==(zone==2) && s.InShootingRange==(zone==3),"original UInt8 zone getter backend="+unsafePool+" value="+zone);
            }
            uint[] masks={0,1,uint.MaxValue,uint.MaxValue,1,0};uint[] modes={1,1,0,7,0,0};bool[] expected={false,true,true,true,false,false};
            for(int i=0;i<masks.Length;i++)
            { Fixture x=ZoneFixture();x.U32(Fixture.ZoneMask+0x10,masks[i]);x.U32(Fixture.ZoneMask+0x18,modes[i]);Check(ZoneSample(x).Invincible==expected[i],"original invincibility mask/mode case "+i); }
            Fixture offline=ZoneFixture();offline.U32(Fixture.FacadeStatics+0x114,301);offline.U64(Fixture.Other+0x70,1);PlayerStateObservation os=ZoneSample(offline);
            Check(os.TrainingZone==3 && os.InShootingRange==true,"offline-training mode short-circuits unused replication data");
            Fixture nullPool=ZoneFixture();nullPool.U64(Fixture.Other+0x70,0);Check(ZoneSample(nullPool).TrainingZone==0,"null zone pool retains the original zero result");
            foreach(uint count in new uint[]{0,37,uint.MaxValue})
            { Fixture x=ZoneFixture();x.U32(Fixture.ZonePoolObject+0x18,count);x.U64(Fixture.ZonePoolObject+0x10,1);Check(ZoneSample(x).TrainingZone==0,"signed property-count short circuit "+count); }
            Fixture nullData=ZoneFixture();nullData.U64(Fixture.ZoneArray+0x20+37*8,0);Check(ZoneSample(nullData).TrainingZone==0,"missing property entry returns original zero");
            foreach(int id in new int[]{0x2558,0x2557,0x10a,0x44d2,0x3f0c,0x49c2})
            {
                Fixture x=ZoneFixture();PlayerObjectResult c=x.Run();x.U64(Fixture.Array+0x20UL+(ulong)id*8UL,Fixture.Other);PlayerStateObservation s=x.Zone(c).Samples[0];
                Check(id==0x49c2?!s.Invincible.HasValue && s.TrainingZone==2:id==0x44d2?!s.InBattleZone.HasValue && s.TrainingZone==2:id==0x3f0c?!s.InShootingRange.HasValue && s.TrainingZone==2:!s.TrainingZone.HasValue && s.Invincible==false,
                    "zone/protection original gate suppresses only its dependent result: "+id);
            }
            Fixture attributes=ZoneFixture();attributes.U64(Fixture.Other+0x768,0);PlayerStateObservation missing=ZoneSample(attributes);Check(!missing.Invincible.HasValue && missing.ProtectionStatus=="NOT_READY_ATTRIBUTES_NULL" && missing.TrainingZone==2,"missing attributes produce unknown protection independently of zone");
            Fixture mask=ZoneFixture();mask.U64(Fixture.ZoneAttributes+0x2b0,0);Check(ZoneSample(mask).ProtectionStatus=="NOT_READY_INVINCIBILITY_OBJECT_NULL","null protection mask is never interpreted as false");
            Fixture pointer=ZoneFixture();pointer.U64(Fixture.ZoneData+0x18,0);Check(ZoneSample(pointer).ZoneStatus=="NOT_READY_UNSAFE_VALUE_NULL","null unsafe value pointer is unknown rather than zero");
            Fixture capacity=ZoneFixture();capacity.U64(Fixture.ZoneArray+0x18,37);Check(ZoneSample(capacity).ZoneStatus=="NOT_READY_POOL_ARRAY_BOUNDS","a short array cannot yield an accepted property value");
            Fixture wrongOwner=ZoneFixture();wrongOwner.U64(Fixture.ZoneAttributes+0x20,Fixture.Player);PlayerStateResult wr=wrongOwner.Zone(wrongOwner.Run());
            Check(wr.Sampled==0 && !wr.Samples[0].TrainingZone.HasValue && wr.Samples[0].Status=="NOT_READY_CONTEXT_CHANGED","attributes owner mismatch discards the entire tentative snapshot");
            Fixture dispatch=ZoneFixture();dispatch.U64(Fixture.Class(36655)+0x138+60*16,dispatch.Module.LoadBias+0x82efc88);PlayerStateResult dr=dispatch.Zone(dispatch.Run());
            Check(dr.Sampled==0 && dr.Samples[0].Detail.Contains("UInt8 interface dispatch"),"managed and unsafe pool targets cannot be interchanged");
            Fixture offset=ZoneFixture();offset.U32(Fixture.ZoneInterfaceTable+0x100+24,48);PlayerStateResult ir=offset.Zone(offset.Run());
            Check(ir.Sampled==0 && ir.Samples[0].Detail.Contains("interface offset metadata"),"native interface offset must match the exact metadata");
            Fixture array=ZoneFixture();array.U64(Fixture.ZoneArrayClass+0x40,Fixture.Class(36644));PlayerStateResult ar=array.Zone(array.Run());
            Check(ar.Sampled==0 && ar.Samples[0].Detail.Contains("array element type"),"unsafe replication data array requires its exact element type");
            Fixture changed=ZoneFixture();PlayerObjectResult cc=changed.Run();ulong ca=changed.Physical(Fixture.ZoneUnsafeValue);bool flip=false;
            changed.Memory.AfterRead=delegate(ulong p,int n){if(!flip && p==ca && n==1){flip=true;changed.Put(Fixture.ZoneUnsafeValue,new byte[]{3});}};
            PlayerStateResult cr=changed.Zone(cc);Check(cr.Sampled==0 && !cr.Samples[0].TrainingZone.HasValue && !cr.Samples[0].Invincible.HasValue,"zone byte mutation invalidates all tentative values");
            Fixture protect=ZoneFixture();PlayerObjectResult pc=protect.Run();ulong pa=protect.Physical(Fixture.ZoneMask+0x10);
            protect.Memory.AfterRead=delegate(ulong p,int n){if(p==pa && n==4)protect.U32(Fixture.ZoneMask+0x10,1);};PlayerStateResult pr=protect.Zone(pc);
            Check(pr.Sampled==0 && !pr.Samples[0].Invincible.HasValue,"protection-mask changes invalidate the snapshot");
            Fixture final=ZoneFixture();PlayerObjectResult fc=final.Run();ulong fa=final.Physical(Fixture.ZoneMask+0x10);
            final.Memory.AfterRead=delegate(ulong p,int n){if(p==fa && n==4)final.U32(final.Module.LoadBias+ZoneProtectionReference.Fields[0].OffsetRva,0x118);};PlayerStateResult fr=final.Zone(fc);
            Check(fr.Sampled==0 && fr.Samples.Length==0 && fr.StopReason=="FINAL_CONTEXT_FAILED","phase-final zone schema rejection discards all output values");
            Fixture typed=ZoneFixture();PlayerObjectResult tc=typed.Run();typed.U64(typed.Module.LoadBias+ZoneProtectionReference.Pools[0].ElementDescriptor,0);PlayerStateResult tr=typed.Zone(tc);
            Check(tr.Sampled==0 && tr.Samples.Length==0 && tr.Detail.Contains("declared array element descriptor"),"pool field descriptor must resolve the exact replication-data element type");
            Fixture member=ZoneFixture();PlayerObjectResult mc=member.Run();ulong ma=member.Physical(Fixture.ZoneUnsafeValue);
            member.Memory.AfterRead=delegate(ulong p,int n){if(p==ma && n==1)member.U32(Fixture.REntries+0x20+40,uint.MaxValue);};PlayerStateResult mr=member.Zone(mc);
            Check(mr.Sampled==0 && !mr.Samples[0].TrainingZone.HasValue,"selected member removal discards zone and protection values");
            Fixture selected=ZoneFixture();PlayerObjectResult sc=selected.Run();int calls=selected.Reader.PhysicalCalls;
            Check(selected.Zone(sc,0).StopReason=="SELECTED_MEMBER_NOT_NONLOCAL" && selected.Zone(sc,100).StopReason=="SELECTED_MEMBER_NOT_NONLOCAL" && selected.Reader.PhysicalCalls==calls,"explicit zone selection rejects local/missing members without reads");
            Fixture reserve=ZoneFixture();PlayerObjectResult rc=reserve.Run();while(reserve.Reader.PhysicalCalls<28500)reserve.Reader.Physical(0,1);
            Check(reserve.Zone(rc).StopReason=="READ_BUDGET_RESERVE","zone phase keeps its final-check reserve");
            Fixture cap=ZoneFixture();PlayerObjectResult capCore=cap.Run();while(cap.Reader.PhysicalCalls<27000)cap.Reader.Physical(0,1);PlayerStateResult capResult=cap.Zone(capCore);
            Check(capResult.Sampled==0 && cap.Reader.PhysicalCalls<=30000,"zone phase does not reset the global read ceiling");
            Check(f.Zone(new PlayerObjectResult()).StopReason=="PREREQUISITES_UNVERIFIED","zone phase requires exact verified prerequisites");
        }
    }
}
