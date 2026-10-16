#!/usr/bin/env python3
"""Generate exact-build active-weapon selection and typed weapon-data references and original UInt32 GetId and selected-weapon reload predicate."""
import argparse, importlib.util, json, struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
def ti(index):
 at=e.pointer(0xa64d6f0+index*8);return at,*struct.unpack('<QI',e.bytes(at,12))
parents={i:ti(t[4])[1] if t[4]>=0 and ti(t[4])[2]>>16&255==18 else -1 for i,t in enumerate(m.types)}
def reaches(index,root):
 for depth in range(32):
  if index==root:return True
  if index<0:return False
  index=parents[index]
 return False
classes=[]
for index,t in enumerate(m.types):
 flags=(1 if reaches(index,32463) else 0)|(2 if reaches(index,32785) else 0)|(4 if reaches(index,31595) else 0)|(8 if index==32430 else 0)|(16 if index==32884 else 0)|(32 if reaches(index,32859) else 0)
 if not flags:continue
 size,_,statics,_=struct.unpack('<4I',e.bytes(e.pointer(0xa925200+index*8),16));minimum=2440 if flags&2 else 1144 if flags&4 else 400 if flags&8 else 48 if flags&16 else 32 if flags&32 else 104
 assert minimum<=size<=1048576,(index,size)
 classes.append(dict(index=index,name=m.type_name(index),family=flags,parent=parents[index],name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],record_hex=m.data[m.header[40]+index*88:m.header[40]+(index+1)*88].hex(),bits=ti(t[2])[2],instance_size=size,static_size=statics,token=t[-1],minimum=minimum,exact=minimum<=size<=1048576))
# The getter itself, rather than the opaque file registration, proves +0x98.
load=struct.unpack('<I',e.bytes(0x7452ac8,4))[0];assert load&0xffc003ff==0xf9400260
resolved=((load>>10)&4095)*8;assert resolved==0x98
fields=[]
for owner,local,name,offset in [(31824,278,'GGBNFECEPJG',0x608),(31824,319,'BKEPAKCAGNJ',0x740),(32430,37,'LMFNCLKHIIO',0xa0),(32430,38,'PDIMNGEMALB',0xa8),(32430,70,'OMHEPNBNEKL',0x148),(32785,18,'PIILKNEHNLB',resolved),(31595,20,'JAOECECKADN',0x68),(32785,17,'MCKDHCLGKLC',0x90),(32884,1,'NEDIHEOKFLG',0x18),(32859,0,'<CPEPAPMDFCA>k__BackingField',0x10)]:
 f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc,data,bits=ti(f[1]);raw=struct.unpack('<I',e.bytes(slot,4))[0]
 assert m.string(f[0])==name and raw==(0x81818181 if owner in (32785,32884,32859) else offset)
 fields.append(dict(owner=owner,local=local,name=name,offset=offset,registration_value=raw,offset_rva=slot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
methods=[];anchors=[]
for index,name,address,length in [(210492,'GetActiveWeapon',0x6f17f74,0x64),(210483,'GetWeaponOnHand',0x6f18290,0xc0),(221309,'DEIPJDIGKIP',0x7399188,0x4c),(220608,'PDAGHPAOBLP',0x734b8d4,0x5c),(220657,'CKIKAFHOBDC',0x734b930,0x48),(224710,'PLLDNGKJKKF',0x7452a90,0x48),(209340,'GetId',0x6ee2628,0x50),(225208,'NNHIONEDFJP',0x74819c4,0x5c),(226517,'MPJPIANCJAP',0x74e301c,0x50),(226238,'GMAKPBMBIDP',0x74d846c,0x8),(210849,'IsReloading',0x6f20e00,0x7c)]:
 q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8;assert m.string(q[0])==name and e.pointer(slot)==address
 methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex()))
 for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
cell=e.pointer(0xa752800);enc=e.pointer(cell);assert ti((enc>>1)&0xfffffff)[1]==32785
virtual=[]
for c in classes:
 if not c['family']&2:continue
 t=m.types[c['index']];assert t[21]>45;pos=m.header[36]+(t[14]+45)*4;enc=struct.unpack_from('<I',m.data,pos)[0];assert enc>>29==3
 q=m.methods[(enc>>1)&0xfffffff];virtual.append(dict(index=c['index'],slot=45,metadata_offset=pos,encoded=enc,rva=e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8)))
# GetId is a UInt32 virtual on the exact supported data class; no derived data class is accepted.
id_method=m.methods[209340];assert id_method[1]==31595 and id_method[10]==14 and ti(id_method[2])[2]>>16&255==9
id_field=next(f for f in fields if f['owner']==31595);assert id_field['owner']==31595 and id_field['bits']>>16&255==9
assert struct.unpack('<I',e.bytes(0x6ee2668,4))[0]==0xb9406a60
id_type=m.types[31595];id_pos=m.header[36]+(id_type[14]+14)*4;id_encoded=struct.unpack_from('<I',m.data,id_pos)[0]
assert id_encoded>>29==3 and (id_encoded>>1)&0xfffffff==209340
id_virtual=dict(index=31595,slot=14,metadata_offset=id_pos,encoded=id_encoded,rva=0x6ee2628)
# Each opaque field has an independent exact native load, then live FieldInfo proof.
for address,instruction in [(0x74819fc,0xf9404a60),(0x74e3054,0xf9400e68),(0x74e305c,0xb9401100),(0x74d846c,0xb9401000)]:
 assert struct.unpack('<I',e.bytes(address,4))[0]==instruction,(hex(address),e.bytes(address,4).hex())
enum_value=m.fields[m.types[32858][8]];assert m.string(enum_value[0])=='value__' and ti(enum_value[1])[2]>>16&255==8
assert m.methods[225208][10]==216 and m.methods[226517][1]==32884 and m.methods[226238][1]==32859
reload_virtual=[]
for c in classes:
 if not c['family']&2:continue
 t=m.types[c['index']];assert t[21]>216;pos=m.header[36]+(t[14]+216)*4;enc=struct.unpack_from('<I',m.data,pos)[0];assert enc>>29==3
 q=m.methods[(enc>>1)&0xfffffff];reload_virtual.append(dict(index=c['index'],slot=216,metadata_offset=pos,encoded=enc,rva=e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8)))
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,classes=classes,fields=fields,methods=methods,anchors=anchors,virtual=virtual,id_virtual=id_virtual,reload_virtual=reload_virtual,weapon_type_cell=cell,weapon_data_offset=resolved,opaque_data_registration=0x81818181,
 scope='Original local GetActiveWeapon selection, typed weapon-data reference and UInt32 GetId plus selected weapon reload predicate. No weapon-name mapping, ammo, ballistics, firing readiness, damage processing, LOS or aim assertion.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'weapon-context-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class WeaponContextReference {','        internal const ulong WeaponTypeCell = 0x%xUL;'%cell,'        internal const uint OpaqueDataRegistration = 0x81818181U;','        internal static readonly TeamVirtual IdVirtual = new TeamVirtual(31595,14,%dUL,0x%xU,0x6ee2628UL);'%(id_pos,id_encoded),'        internal static readonly ObjectClassProfile[] Classes = {']
for c in classes:lines.append('            new ObjectClassProfile(%d,%s,%d,%d,%dUL,%dUL,%s,%dU,%dU,%dU,%dU,0,%dU,%s),'%(c['index'],json.dumps(c['name']),c['family'],c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token'],c['minimum'],str(c['exact']).lower()))
lines+=['        };','        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {','            new GameLayoutCheck("weapon_cast_type_got",0xa752800UL,0x%xUL),'%cell]
for q in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','        internal static readonly TeamVirtual[] Virtuals = {']
for q in virtual:lines.append('            new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),'%(q['index'],q['slot'],q['metadata_offset'],q['encoded'],q['rva']))
lines+=['        };','        internal static readonly TeamVirtual[] ReloadVirtuals = {']
for q in reload_virtual:lines.append('            new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),'%(q['index'],q['slot'],q['metadata_offset'],q['encoded'],q['rva']))
lines+=['        };','    }','}',''];(out/'WeaponContextReference.cs').write_text('\n'.join(lines));print('WeaponContextReference=PASS Classes=%d Fields=%d Methods=%d DataDispatchProfiles=%d'%(len(classes),len(fields),len(methods),len(virtual)))
