#!/usr/bin/env python3
"""Generate exact original GetAimRotation and Quaternion layout references."""
import argparse,importlib.util,json,struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
def ti(i):
 at=e.pointer(0xa64d6f0+i*8);return at,*struct.unpack('<QI',e.bytes(at,12))
index=210726;q=m.methods[index];address=0x6f249ac;assert m.string(q[0])=='GetAimRotation' and q[1]==31824 and q[10]==65535 and q[6]==0x4b9
slot=0xa98efa8+((q[7]&0xffffff)-1)*8;assert e.pointer(slot)==address
ret_desc,ret_data,ret_bits=ti(q[2]);assert ret_data==40980 and ret_bits>>16&255==17 and m.type_name(ret_data)=='UnityEngine.Quaternion'
offsets=[]
for i in range(4):
 word=struct.unpack('<I',e.bytes(0x6f249e4+i*4,4))[0];assert word&0xffc00000==0xbd400000 and (word>>5)&31==19 and word&31==i
 offsets.append(((word>>10)&4095)*4)
assert offsets==[0x614,0x618,0x61c,0x620]
fields=[]
for owner,local in [(31824,280)]+[(40980,i) for i in range(4)]:
 f=m.fields[m.types[owner][8]+local];offslot=e.pointer(0xa8cfec0+owner*8)+local*4;offset=struct.unpack('<I',e.bytes(offslot,4))[0];desc,data,bits=ti(f[1])
 if owner==31824:assert offset==offsets[0] and data==40980 and m.string(f[0])=='<AKKPEKIHGAH>k__BackingField'
 else:assert offset==16+local*4 and m.string(f[0])=='xyzw'[local] and bits>>16&255==12
 fields.append(dict(owner=owner,local=local,name=m.string(f[0]),offset=offset,offset_rva=offslot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
sizes=struct.unpack('<4I',e.bytes(e.pointer(0xa925200+40980*8),16));assert sizes[:2]==(32,16)
record_offset=m.header[40]+40980*88;record=m.data[record_offset:record_offset+88].hex()
method=dict(index=index,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex());anchors=[dict(name='GetAimRotation_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,0x54-off)).hex()) for off in range(0,0x54,64)]
# Unity methods use CoreModule's own token table, never Assembly-CSharp's.
vector_index=317467;vq=m.methods[vector_index];assert m.type_name(vq[1])=='UnityEngine.Quaternion' and m.string(vq[0])=='op_Multiply' and vq[11]==2
assert ti(vq[2])[1]==ti(m.parameters[vq[4]+1][2])[1] and m.type_name(ti(vq[2])[1])=='UnityEngine.Vector3'
assert ti(m.parameters[vq[4]][2])[1]==40980
module=0xa729470;name=0x195af72;table=0xaf5a718;vector_rva=0x9fddc4c
assert e.pointer(module)==name and e.bytes(name,27)==b'UnityEngine.CoreModule.dll\0'
assert struct.unpack('<Q',e.bytes(module+8,8))[0]==4752 and e.pointer(module+16)==table
vector_slot=table+((vq[7]&0xffffff)-1)*8;assert e.pointer(vector_slot)==vector_rva
vector_method=dict(index=vector_index,rva=vector_rva,pointer_rva=vector_slot,metadata_offset=m.header[12]+vector_index*40,record_hex=struct.pack('<8i4H',*vq).hex())
for off in range(0,0xa4,64):anchors.append(dict(name='QuaternionVectorMultiply_'+str(off),rva=vector_rva+off,hex=e.bytes(vector_rva+off,min(64,0xa4-off)).hex()))
anchors.extend([dict(name='UnityCoreModuleName',rva=module,pointer=name),dict(name='UnityCoreModuleNameBytes',rva=name,hex=e.bytes(name,27).hex()),dict(name='UnityCoreModuleCount',rva=module+8,hex=struct.pack('<Q',4752).hex()),dict(name='UnityCoreModuleTable',rva=module+16,pointer=table)])
# Derive native icall wrapper cache/name addresses from the exact ARM64 instructions.
def adrp(at):
 word=struct.unpack('<I',e.bytes(at,4))[0];assert word&0x9f000000==0x90000000
 imm=((word>>5)&0x7ffff)*4+((word>>29)&3);imm=imm-(1<<21) if imm&(1<<20) else imm
 return (at&~4095)+imm*4096,word&31
def cache(at):
 base,reg=adrp(at);word=struct.unpack('<I',e.bytes(at+4,4))[0]
 assert word&0xffc00000==0xf9400000 and (word>>5)&31==reg
 return base+((word>>10)&4095)*8
def string_address(at):
 base,reg=adrp(at);word=struct.unpack('<I',e.bytes(at+4,4))[0]
 assert word&0xffc00000==0x91000000 and (word>>5)&31==reg
 return base+((word>>10)&4095)
camera_methods=[];camera_bindings=[]
for mi,owner,mn,rv,size,tab,image_name,cache_adrp,string_adrp,icall in [
 (210071,'COW.GamePlay.Player','GetRuntimeMainCameraTransform',0x6f2f368,0x130,0xa98efa8,'Assembly-CSharp.dll',None,None,None),
 (315161,'UnityEngine.Camera','get_main',0x9fa01d8,0x28,table,'UnityEngine.CoreModule.dll',0x9fa01dc,0x9fa01e8,'UnityEngine.Camera::get_main()'),
 (317874,'UnityEngine.Component','get_transform',0x9fe7aa8,0x3c,table,'UnityEngine.CoreModule.dll',0x9fe7ab0,0x9fe7ac0,'UnityEngine.Component::get_transform()')]:
 cq=m.methods[mi];assert m.type_name(cq[1])==owner and m.string(cq[0])==mn and cq[11]==0
 assert any(im[2]<=cq[1]<im[2]+im[3] and m.string(im[0])==image_name for im in m.images)
 cs=tab+((cq[7]&0xffffff)-1)*8;assert e.pointer(cs)==rv
 camera_methods.append(dict(index=mi,name=owner+'.'+mn,rva=rv,pointer_rva=cs,metadata_offset=m.header[12]+mi*40,record_hex=struct.pack('<8i4H',*cq).hex()))
 for off in range(0,size,64):anchors.append(dict(name=mn+'_'+str(off),rva=rv+off,hex=e.bytes(rv+off,min(64,size-off)).hex()))
 if cache_adrp is not None:
  cell=cache(cache_adrp);text=string_address(string_adrp);raw=icall.encode()+b'\0';assert e.bytes(text,len(raw))==raw
  anchors.append(dict(name=mn+'_icall_name',rva=text,hex=raw.hex()))
  camera_bindings.append(dict(method=mn,cell_rva=cell,string_rva=text,icall=icall))
assert [b['cell_rva'] for b in camera_bindings]==[0xafb7380,0xafb9668]
# Recover the game camera getter entry gates; never execute IFix or initialize metadata.
def byte_cell(adrp_at,load_at):
 base,reg=adrp(adrp_at);word=struct.unpack('<I',e.bytes(load_at,4))[0]
 assert word&0xffc00000==0x39400000 and (word>>5)&31==reg and word&31==8
 return base+((word>>10)&4095)
getter_init=byte_cell(0x6f2f370,0x6f2f374);patch_init=byte_cell(0x882aa24,0x882aa2c)
w0,w1=struct.unpack('<2I',e.bytes(0x6f2f3a0,8))
assert w0&0xff80001f==0x52800000 and w1&0xff80001f==0x72800000 and (w1>>21)&3==1 and (w0>>21)&3==0
camera_gate=((w0>>5)&65535)|(((w1>>5)&65535)<<16)
for at in (0x6f2f37c,0x882aa38):
 guard=struct.unpack('<I',e.bytes(at,4))[0];assert guard&0xff00001f==0x37000008 and (guard>>19)&31==0
call=struct.unpack('<I',e.bytes(0x6f2f3ac,4))[0];assert call&0xfc000000==0x94000000
imm=call&0x3ffffff;imm-= (1<<26) if imm&(1<<25) else 0
assert 0x6f2f3ac+imm*4==0x882aa1c
assert getter_init==0xafa571a and patch_init==0xafb07bd and camera_gate==m.methods[210071][6]==0x21bc0
for off in range(0,0xb4,64):anchors.append(dict(name='CameraCheckPatch_'+str(off),rva=0x882aa1c+off,hex=e.bytes(0x882aa1c+off,min(64,0xb4-off)).hex()))
report=dict(camera_getter_entry_gates=dict(getter_init_cell=getter_init,patch_init_cell=patch_init,slot=camera_gate,scope="Entry gates only; managed camera, hotfix function, class constructors and fallback not evaluated"),elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,method=method,vector_method=vector_method,camera_methods=camera_methods,camera_bindings=camera_bindings,fields=fields,anchors=anchors,return_descriptor=ret_desc,return_bits=ret_bits,quaternion_record_offset=record_offset,quaternion_record_hex=record,getter_offset=0x614,scope='Original local GetAimRotation and native camera icall cache observations only; actual camera objects/pose, m_CurrentAimRotation, target direction and aim update remain unverified.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'aim-state-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class AimStateReference {','        internal const ulong ReturnDescriptor=0x%xUL; internal const uint ReturnBits=%dU;'%(ret_desc,ret_bits),'        internal const ulong QuaternionMetadata=%dUL; internal const string QuaternionRecord=%s;'%(record_offset,json.dumps(record)),'        internal static readonly StateMethod Method=new StateMethod(%dUL,0x%xUL,0x%xUL,%s);'%(method['metadata_offset'],slot,address,json.dumps(method['record_hex'])),'        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod VectorMethod=new StateMethod(%dUL,0x%xUL,0x%xUL,%s);'%(vector_method['metadata_offset'],vector_slot,vector_rva,json.dumps(vector_method['record_hex'])),'        internal static readonly GameLayoutCheck[] Anchors = {']
# Close the anchor array below, then emit the camera method registration list.
for c in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(c['name']),c['rva'],('0x%xUL'%c['pointer']) if 'pointer' in c else json.dumps(c['hex'])))
lines+=['        };','        internal const ulong CameraMainCell=0xafb7380UL, ComponentTransformCell=0xafb9668UL;','        internal static readonly StateMethod[] CameraMethods={'];
for cm in camera_methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(cm['metadata_offset'],cm['pointer_rva'],cm['rva'],json.dumps(cm['record_hex'])))
lines+=['        };','        internal const ulong GameCameraGetterInitCell=0x%xUL, CameraPatchInitCell=0x%xUL;'%(getter_init,patch_init),'        internal const int GameCameraGetterGate=0x%x;'%camera_gate,'    }','}',''];(out/'AimStateReference.cs').write_text('\n'.join(lines));print('AimStateReference=PASS OriginalGetter=0x6f249ac Field=0x614 Quaternion=40980 Components=4')
