#!/usr/bin/env python3
"""Derive exact original weapon counter getter and unbound Int32 field candidates."""
import argparse,importlib.util,json,struct,hashlib
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
fields=[]
for owner,local,name,offset in [(31824,278,'GGBNFECEPJG',0x608),(31824,319,'BKEPAKCAGNJ',0x740),(32430,37,'LMFNCLKHIIO',0xa0),(32430,38,'PDIMNGEMALB',0xa8),(32430,70,'OMHEPNBNEKL',0x148)]:
 f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc=e.pointer(0xa64d6f0+f[1]*8);data,bits=struct.unpack('<QI',e.bytes(desc,12));assert m.string(f[0])==name and struct.unpack('<I',e.bytes(slot,4))[0]==offset
 fields.append(dict(owner=owner,local=local,name=name,offset=offset,offset_rva=slot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
candidates=[];t=m.types[32785];assert t[18]==253
for local in range(t[18]):
 f=m.fields[t[8]+local];desc=e.pointer(0xa64d6f0+f[1]*8);data,bits=struct.unpack('<QI',e.bytes(desc,12))
 if bits>>16&255!=8 or bits&16:continue
 slot=e.pointer(0xa8cfec0+32785*8)+local*4;raw=struct.unpack('<I',e.bytes(slot,4))[0];assert raw==0x81818181
 candidates.append(dict(local=local,name=m.string(f[0]),offset_rva=slot,descriptor=desc,bits=bits,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(t[8]+local)*12,record_hex=struct.pack('<iiI',*f).hex(),source_registration=raw,instance_offset=None))
assert len(candidates)==11
methods=[];anchors=[]
for index,name,address,length in [(210492,'GetActiveWeapon',0x6f17f74,0x64),(210483,'GetWeaponOnHand',0x6f18290,0xc0),(221309,'DEIPJDIGKIP',0x7399188,0x4c),(220608,'PDAGHPAOBLP',0x734b8d4,0x5c),(220657,'CKIKAFHOBDC',0x734b930,0x48),(224776,'IHBDOPMADIE',0x7457fa4,0x48)]:
 q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8;assert m.string(q[0])==name and e.pointer(slot)==address
 methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex()))
 for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
assert m.methods[224776][1]==32785 and m.methods[224776][10]==65535
ret=e.pointer(0xa64d6f0+m.methods[224776][2]*8);assert struct.unpack('<I',e.bytes(ret+8,4))[0]>>16&255==8
instruction=struct.unpack('<I',e.bytes(0x7457fdc,4))[0];assert instruction&0xffc003ff==0xb9400260
offset=((instruction>>10)&4095)*4;assert offset==0x610
callers=[]
for index,address,length,call_at in [(123831,0x4ecd298,0x4d4,0x4ecd530),(168473,0x5f43640,0x1f8,0x5f437fc),(210671,0x6f7c394,0x130,0x6f7c498)]:
 q=m.methods[index];assert e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8)==address
 word=struct.unpack('<I',e.bytes(call_at,4))[0];imm=word&0x3ffffff;assert word&0xfc000000==0x94000000 and call_at+((imm-(1<<26) if imm&(1<<25) else imm)*4)==0x7457fa4
 callers.append(dict(index=index,owner=m.type_name(q[1]),name=m.string(q[0]),rva=address,call_rva=call_at,code_hex=e.bytes(address,length).hex(),scope='Static call-site evidence only; not a reproduced UI/game policy.'))
cell=e.pointer(0xa752800)
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,selection_fields=fields,candidates=candidates,methods=methods,anchors=anchors,source_callers=callers,owner_index=32785,owner_field_count=253,getter_offset=offset,scope='Original selected weapon Int32 counter used by ammo UI and throwing-knife count. No magazine/reserve, unlimited-ammo policy, firing readiness, LOS or aim assertion.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'weapon-ammo-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal sealed class WeaponAmmoField {','        internal readonly int Local; internal readonly string Name,RecordHex;','        internal readonly ulong OffsetRva,Descriptor,NameOffset,MetadataOffset; internal readonly uint Bits,Token;','        internal WeaponAmmoField(int local,string name,ulong registration,ulong descriptor,uint bits,ulong nameOffset,uint token,ulong metadata,string record)','        { Local=local;Name=name;OffsetRva=registration;Descriptor=descriptor;Bits=bits;NameOffset=nameOffset;Token=token;MetadataOffset=metadata;RecordHex=record; }','    }','    internal static class WeaponAmmoReference {','        internal const int FieldCount=253; internal const uint GetterOffset=0x610U;','        internal static readonly StateField[] SelectionFields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly WeaponAmmoField[] Candidates = {']
for f in candidates:lines.append('            new WeaponAmmoField(%d,%s,0x%xUL,0x%xUL,%dU,%dUL,%dU,%dUL,%s),'%(f['local'],json.dumps(f['name']),f['offset_rva'],f['descriptor'],f['bits'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {','            new GameLayoutCheck("ammo_weapon_cast_got",0xa752800UL,0x%xUL),'%cell]
for q in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','    }','}',''];(out/'WeaponAmmoReference.cs').write_text('\n'.join(lines));print('WeaponAmmoReference=PASS SelectionFields=5 Methods=6 UnboundInt32Candidates=11 RuntimeTableFields=253 GetterOffset=0x610')
