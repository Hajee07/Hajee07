#!/usr/bin/env python3
"""Generate exact-build references for a bounded SameTeam policy probe."""
import argparse, importlib.util, json, struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'))
r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
def type_info(index):
    at=e.pointer(0xa64d6f0+index*8);return at,*struct.unpack('<QI',e.bytes(at,12))
roots=[]
for name,got,expected in [('GameVar',0xa73f5a8,'COW.GameVarDef'),('UnityObject',0xa739c68,'UnityEngine.Object')]:
    cell=e.pointer(got);encoded=struct.unpack('<Q',e.bytes(cell,8))[0];index=type_info((encoded>>1)&0xfffffff)[1]
    assert m.type_name(index)==expected
    roots.append(dict(name=name,got=got,cell=cell,index=index))
classes=[]
for index in [11715,34565]+[root['index'] for root in roots]:
    t=m.types[index];size,_,statics,_=struct.unpack('<4I',e.bytes(e.pointer(0xa925200+index*8),16))
    assert 16<=size<=1048576
    classes.append(dict(index=index,name=m.type_name(index),parent=type_info(t[4])[1],name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],
                        record_hex=m.data[m.header[40]+index*88:m.header[40]+(index+1)*88].hex(),bits=type_info(t[2])[2],instance_size=size,static_size=statics,token=t[-1]))
fields=[]
for owner,local,name,offset in [(12418,1,'CurrentMatchGame',8),(12418,43,'m_GameServerGameMode',0x114),
    (12425,1,'m_GameModeSetting',0x98),(11715,694,'EnableDynamicTeamID',0xa55),
    (31824,179,'MHGFKKALMDK',0x408),(34565,2,'JLIDCJLKLBD',0x18),(34107,40,'GCCOFKGEICG',0x330)]:
    f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc,data,bits=type_info(f[1])
    assert m.string(f[0])==name and struct.unpack('<I',e.bytes(slot,4))[0]==offset
    fields.append(dict(owner=owner,local=local,name=name,offset=offset,offset_rva=slot,descriptor=desc,bits=bits,
                       type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],
                       metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
methods=[];anchors=[]
for index,name,address,length in [(35095,'IsSameTeam',0x71c6130,0x228),(35276,'IsTeammateOfSameFaction',0x71ce8ec,0x74),
    (35274,'IsUGCInfectionMode',0x71d7e60,0x80),(34943,'get_GameServerGameMode',0x71bf5c0,0x80),
    (35687,'IsSameTeam',0x7328844,0x184),(35025,'CurrentGameModeSetting',0x71bee08,0x1a0),
    (35617,'GetGameModeSetting',0x7323464,0x114),(210078,'get_PlayerID',0x6f01b34,0x7c),
    (246436,'DPLMDPBINFL',0x7c36f24,0x12c),(239900,'OOKJOAIFNAP',0x79a8c90,0xec)]:
    d=m.methods[index];slot=0xa98efa8+((d[7]&0xffffff)-1)*8
    assert m.string(d[0])==name and e.pointer(slot)==address
    methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*d).hex()))
    for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
for name,address,length in [('object_not_equal',0x9feadf4,0x70),('object_compare',0x9feef94,0xa8),('native_alive',0x9fef0a0,0x20),('intptr_not_equal',0x9e4d19c,12)]:
    for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
assert e.bytes(0x7c37018,4).hex()=='60224039' # inline player ID byte 8
assert e.bytes(0x71bf630,4).hex()=='001541b9' # static mode +0x114
key_cell=e.pointer(0xa73f7a0);enc=struct.unpack('<Q',e.bytes(key_cell,8))[0]
assert type_info((enc>>1)&0xfffffff)[1]==34565
dynamic_cell=e.pointer(0xa73ff50);enc=struct.unpack('<Q',e.bytes(dynamic_cell,8))[0]
assert type_info((enc>>1)&0xfffffff)[1]==34107
virtual=[]
for c in json.loads(Path(__file__).with_name('object-reference.json').read_text())['classes']:
    if not c['family']&4:continue
    t=m.types[c['index']]
    for slot in [75,92]:
        assert t[21]>slot
        pos=m.header[36]+(t[14]+slot)*4;encoded=struct.unpack('<I',m.data[pos:pos+4])[0];assert encoded>>29==3
        method=m.methods[(encoded>>1)&0xfffffff]
        virtual.append(dict(index=c['index'],slot=slot,metadata_offset=pos,encoded=encoded,rva=e.pointer(0xa98efa8+((method[7]&0xffffff)-1)*8)))
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,classes=classes,fields=fields,methods=methods,anchors=anchors,virtual=virtual,key_cell=key_cell,dynamic_class_cell=dynamic_cell,roots=roots,
    scope='Original GameFacade.IsSameTeam(local,other) for validated non-faction base MatchGame routes; dynamic non-null dictionary/custom virtual/hotfix routes remain unknown. No hostility or aim claim.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'team-policy-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class TeamPolicyReference {',
       '        internal const ulong KeyCell = 0x%xUL;'%key_cell,'        internal const ulong DynamicClassCell = 0x%xUL;'%dynamic_cell]
for root in roots:lines+=['        internal const ulong %sCell = 0x%xUL;'%(root['name'],root['cell']),'        internal const int %sIndex = %d;'%(root['name'],root['index'])]
lines+=['        internal static readonly ObjectClassProfile[] Classes = {']
for c in classes:lines.append('            new ObjectClassProfile(%d,%s,0,%d,%dUL,%dUL,%s,%dU,%dU,%dU,%dU,0,16,true),'%(c['index'],json.dumps(c['name']),c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token']))
lines+=['        };','        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {']
lines.append('            new GameLayoutCheck("player_id_type_got",0xa73f7a0UL,0x%xUL),'%key_cell)
lines.append('            new GameLayoutCheck("dynamic_class_got",0xa73ff50UL,0x%xUL),'%dynamic_cell)
for root in roots:lines.append('            new GameLayoutCheck(%s,0x%xUL,0x%xUL),'%(json.dumps(root['name']+'_got'),root['got'],root['cell']))
for q in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','        internal static readonly TeamVirtual[] Virtuals = {']
for v in virtual:lines.append('            new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),'%(v['index'],v['slot'],v['metadata_offset'],v['encoded'],v['rva']))
lines+=['        };','    }','}',''];(out/'TeamPolicyReference.cs').write_text('\n'.join(lines))
print('TeamPolicyReference=PASS Fields=%d Methods=%d Virtuals=%d Anchors=%d'%(len(fields),len(methods),len(virtual),len(anchors)+2+len(roots)))
