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
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,method=method,fields=fields,anchors=anchors,return_descriptor=ret_desc,return_bits=ret_bits,quaternion_record_offset=record_offset,quaternion_record_hex=record,getter_offset=0x614,scope='Original local GetAimRotation value only, not m_CurrentAimRotation, camera orientation, target direction or aim update.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'aim-state-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class AimStateReference {','        internal const ulong ReturnDescriptor=0x%xUL; internal const uint ReturnBits=%dU;'%(ret_desc,ret_bits),'        internal const ulong QuaternionMetadata=%dUL; internal const string QuaternionRecord=%s;'%(record_offset,json.dumps(record)),'        internal static readonly StateMethod Method=new StateMethod(%dUL,0x%xUL,0x%xUL,%s);'%(method['metadata_offset'],slot,address,json.dumps(method['record_hex'])),'        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {']
for c in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(c['name']),c['rva'],json.dumps(c['hex'])))
lines+=['        };','    }','}',''];(out/'AimStateReference.cs').write_text('\n'.join(lines));print('AimStateReference=PASS OriginalGetter=0x6f249ac Field=0x614 Quaternion=40980 Components=4')
