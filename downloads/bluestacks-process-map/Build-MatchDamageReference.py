#!/usr/bin/env python3
"""Generate exact-build references for the argument-independent match damage policy."""
import argparse, importlib.util, json, struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
def ti(index):
 at=e.pointer(0xa64d6f0+index*8);return at,*struct.unpack('<QI',e.bytes(at,12))
fields=[]
for owner,local,name,offset in [(12418,0,'CurrentGame',0),(12418,1,'CurrentMatchGame',8),(12418,43,'m_GameServerGameMode',0x114),(12425,0,'m_Match',0x90),(32133,30,'MHJCLOPOBAA',0xd8)]:
 f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc,data,bits=ti(f[1]);assert m.string(f[0])==name and struct.unpack('<I',e.bytes(slot,4))[0]==offset
 fields.append(dict(owner=owner,local=local,name=name,offset=offset,offset_rva=slot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
methods=[];anchors=[]
for index,name,address,length in [(35677,'CanTakeDamage',0x7327e50,0x78),(242331,'CanTakeDamage',0x7b10f2c,0),(34943,'get_GameServerGameMode',0x71bf5c0,0x80)]:
 q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8;assert m.string(q[0])==name and e.pointer(slot)==address
 methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex()))
 for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
# The complete original non-hotfix block restores registers and returns true;
# it reads none of attacker/victim/weaponData and performs no call or write.
assert struct.unpack('<5I',e.bytes(0x7327eb0,20))==(0xa9424ff4,0xa94157f6,0x52800020,0xf84307fe,0xd65f03c0)
q=m.methods[35677];assert q[10]==91 and q[11]==3
parameters=[dict(name=m.string(m.parameters[q[4]+i][0]),record=list(m.parameters[q[4]+i])) for i in range(3)]
assert [x['name'] for x in parameters]==['attacker','victim','weaponData']
virtual=[]
for c in json.loads(Path(__file__).with_name('object-reference.json').read_text())['classes']:
 if not c['family']&4:continue
 t=m.types[c['index']];assert t[21]>91;pos=m.header[36]+(t[14]+91)*4;enc=struct.unpack_from('<I',m.data,pos)[0];assert enc>>29==3
 q=m.methods[(enc>>1)&0xfffffff];virtual.append(dict(index=c['index'],slot=91,metadata_offset=pos,encoded=enc,rva=e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8)))
assert {v['rva'] for v in virtual}=={0x7327e50,0x7b10f2c}
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,fields=fields,methods=methods,anchors=anchors,virtual=virtual,parameters=parameters,gate=0x853d,
 scope='Original CurrentMatchGame.CanTakeDamage base implementation only when CurrentGame equals CurrentMatchGame. Argument-independent true is one policy, not full combat eligibility. Overrides and hotfixes unknown.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'match-damage-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class MatchDamageReference {','        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {']
for q in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','        internal static readonly TeamVirtual[] Virtuals = {']
for q in virtual:lines.append('            new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),'%(q['index'],q['slot'],q['metadata_offset'],q['encoded'],q['rva']))
lines+=['        };','    }','}',''];(out/'MatchDamageReference.cs').write_text('\n'.join(lines));print('MatchDamageReference=PASS Fields=%d Methods=%d DispatchProfiles=%d'%(len(fields),len(methods),len(virtual)))
