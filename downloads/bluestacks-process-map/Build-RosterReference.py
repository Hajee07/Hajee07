#!/usr/bin/env python3
"""Generate exact-match typed Player dictionary references; no enemy semantics."""
import argparse,importlib.util,json,struct
from pathlib import Path
p=argparse.ArgumentParser();p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
owner=m.types[32133];j=38;field=m.fields[owner[8]+j];offset_rva=e.pointer(0xa8cfec0+32133*8)+j*4
assert m.string(field[0])=='NOLEDCGOJKC' and int.from_bytes(e.bytes(offset_rva,4),'little')==0x128
type_rva=e.pointer(0xa64d6f0+field[1]*8);assert type_rva==0xa5eaa60
# The typed TryGetValue caller reads the adjacent +0x130 field of the same closed type.
assert e.pointer(0xa64d6f0+m.fields[owner[8]+39][1]*8)==type_rva
assert int.from_bytes(e.bytes(e.pointer(0xa8cfec0+32133*8)+39*4,4),'little')==0x130
branch=int.from_bytes(e.bytes(0x720bda4,4),'little');imm=branch&0x3ffffff
if imm&0x2000000:imm-=0x4000000
assert branch>>26==0b100101 and 0x720bda4+(imm<<2)==0x90231fc
bits=int.from_bytes(e.bytes(type_rva+8,4),'little');assert bits==0x150004
g=e.pointer(type_rva);definition=e.pointer(g);inst=e.pointer(g+8);argv=e.pointer(inst+8)
assert int.from_bytes(e.bytes(definition,8),'little')==38851 and int.from_bytes(e.bytes(inst,4),'little')==2
key=e.pointer(argv);value=e.pointer(argv+8)
assert struct.unpack('<QI',e.bytes(key,12))==(34565,0x80110000), struct.unpack('<QI',e.bytes(key,12))
assert struct.unpack('<QI',e.bytes(value,12))==(31824,0x120000)
entry=next(i for i,t in enumerate(m.types) if t[3]==m.types[38851][2] and m.string(t[0])=='Entry');assert entry==38845
assert [m.string(m.fields[m.types[entry][8]+k][0]) for k in range(4)]==['hashCode','next','key','value']
method=m.methods[217520];assert m.string(method[0])=='JJPLCPCJNCC' and e.pointer(0xa98efa8+((method[7]&0xffffff)-1)*8)==0x720bc30
# Explicit native count/version/entry instructions, in addition to full input hashes.
assert e.bytes(0x9020c28,16).hex()=='082040b9092840b90001094bc0035fd6'
assert e.bytes(0x9154cf4,16).hex()=='a82e40b9a90a40f908050011a82e00b9'
anchors=[]
for name,start,size in [('match_player_getter',0x720bc30,0x48),('player_lookup_call',0x720bd68,0x40),('typed_try_get_value',0x9023240,0x54),('typed_entry_key',0x9021df8,0x30),('dictionary_count',0x9020c28,16),('dictionary_version',0x90220cc,16),('head_dictionary_version',0x9154cf4,16)]:
 for off in range(0,size,32):anchors.append(dict(name=name+'_'+str(off),rva=start+off,hex=e.bytes(start+off,min(32,size-off)).hex()))
profiles=[]
for idx in [38851,entry,34565]:
 t=m.types[idx];pos=m.header[40]+idx*88;profiles.append(dict(index=idx,name=m.type_name(idx),name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],record_hex=m.data[pos:pos+88].hex(),token=t[-1]))
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,profiles=profiles,anchors=anchors,field_name=m.string(field[0]),field_offset=0x128,field_offset_rva=offset_rva,field_type_rva=type_rva,field_type_bits=bits,field_metadata_offset=m.header[24]+(owner[8]+j)*12,field_record_hex=struct.pack('<iiI',*field).hex(),entry_stride=40,entry_value_offset=32,version_offset=44,scope='One typed match dictionary, at most 16 verified Player objects; team/alive/visibility semantics unverified.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'roster-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class RosterReference {']
for label,profile in zip(['Dictionary','Entry','Key'],profiles):
 lines.append('        internal static readonly ObjectClassProfile %s = new ObjectClassProfile(%d,%s,0,-1,%dUL,%dUL,%s,0,0,0,%dU,0,0,false);'%(label,profile['index'],json.dumps(profile['name']),profile['name_offset'],profile['namespace_offset'],json.dumps(profile['record_hex']),profile['token']))
for label,val in [('FieldOffsetRva',offset_rva),('FieldTypeRva',type_rva),('FieldMetadataOffset',report['field_metadata_offset'])]:lines.append('        internal const ulong %s = 0x%xUL;'%(label,val))
lines+=['        internal const string FieldRecordHex = '+json.dumps(report['field_record_hex'])+';','        internal static readonly GameLayoutCheck[] Anchors = new GameLayoutCheck[] {']
for x in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(x['name']),x['rva'],json.dumps(x['hex'])))
lines+=['        };','    }','}',''];(out/'RosterReference.cs').write_text('\n'.join(lines));print('RosterReference=PASS EntryType='+str(entry)+' Anchors='+str(len(anchors)))
