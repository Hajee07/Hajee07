#!/usr/bin/env python3
"""Generate exact-build selected-weapon firing predicate evidence."""
import argparse,importlib.util,json,struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
w=json.loads(Path(__file__).with_name('weapon-context-reference.json').read_text());assert w['elf_sha256']==r.ELF_SHA and w['metadata_sha256']==r.META_SHA
# Existing entries are re-derived here rather than trusting the JSON's offset/code claims.
fields=[]
for owner,local,name,offset in [(31824,278,'GGBNFECEPJG',0x608),(31824,319,'BKEPAKCAGNJ',0x740),(32430,37,'LMFNCLKHIIO',0xa0),(32430,38,'PDIMNGEMALB',0xa8),(32430,70,'OMHEPNBNEKL',0x148),(32785,17,'MCKDHCLGKLC',0x90),(32884,1,'NEDIHEOKFLG',0x18),(32859,0,'<CPEPAPMDFCA>k__BackingField',0x10),(32884,2,'<MPDHPFHPENF>k__BackingField',0x20),(11718,2021,'EnableIsFiringCache',0x191d)]:
 f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc=e.pointer(0xa64d6f0+f[1]*8);data,bits=struct.unpack('<QI',e.bytes(desc,12));raw=struct.unpack('<I',e.bytes(slot,4))[0]
 assert m.string(f[0])==name and raw==(0x81818181 if owner in (32785,32884,32859) else offset)
 fields.append(dict(owner=owner,local=local,name=name,offset=offset,registration_value=raw,offset_rva=slot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
methods=[];anchors=[]
for index,name,address,length in [(210492,'GetActiveWeapon',0x6f17f74,0x64),(210483,'GetWeaponOnHand',0x6f18290,0xc0),(221309,'DEIPJDIGKIP',0x7399188,0x4c),(220608,'PDAGHPAOBLP',0x734b8d4,0x5c),(220657,'CKIKAFHOBDC',0x734b930,0x48),(225210,'NGGBEDBDEPA',0x7481a84,0xf4),(226517,'MPJPIANCJAP',0x74e301c,0x50),(226238,'GMAKPBMBIDP',0x74d846c,8),(211035,'IsFiring',0x6f20e7c,0x84)]:
 q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8;assert m.string(q[0])==name and e.pointer(slot)==address
 methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex()))
 for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
assert m.methods[225210][10]==218
# Exact field loads and state-set constants from the complete firing body.
for address,instruction in [(0x7481ae4,0xf9404a60),(0x7481b24,0x39408008),(0x7481b14,0x528323a9),(0x7481b48,0x5283f3e9)]:assert struct.unpack('<I',e.bytes(address,4))[0]==instruction,(hex(address),e.bytes(address,4).hex())
feature_cell=e.pointer(0xa73f5a8);assert feature_cell==0xac2f618
encoded=e.pointer(feature_cell);desc=e.pointer(0xa64d6f0+((encoded>>1)&0xfffffff)*8);assert e.pointer(desc)==11718
virtual=[]
for c in w['classes']:
 if not c['family']&2:continue
 t=m.types[c['index']];assert t[21]>218;pos=m.header[36]+(t[14]+218)*4;enc=struct.unpack_from('<I',m.data,pos)[0];assert enc>>29==3
 q=m.methods[(enc>>1)&0xfffffff];virtual.append(dict(index=c['index'],slot=218,metadata_offset=pos,encoded=enc,rva=e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8)))
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,fields=fields,methods=methods,anchors=anchors,virtual=virtual,feature_cell=feature_cell,feature_index=11718,cache_offset=0x191d,scope='Original selected weapon slot-218 predicate. No Player.IsFiring, ammo, firing readiness, LOS or aim assertion.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'weapon-firing-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class WeaponFiringReference {','        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {','            new GameLayoutCheck("firing_weapon_cast_got",0xa752800UL,0x%xUL),'%w['weapon_type_cell'],'            new GameLayoutCheck("firing_feature_got",0xa73f5a8UL,0xac2f618UL),']
for q in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','        internal static readonly TeamVirtual[] Virtuals = {']
for q in virtual:lines.append('            new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),'%(q['index'],q['slot'],q['metadata_offset'],q['encoded'],q['rva']))
lines+=['        };','    }','}',''];(out/'WeaponFiringReference.cs').write_text('\n'.join(lines));print('WeaponFiringReference=PASS Fields=%d Methods=%d DispatchProfiles=%d'%(len(fields),len(methods),len(virtual)))
