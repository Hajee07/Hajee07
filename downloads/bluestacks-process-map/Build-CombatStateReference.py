#!/usr/bin/env python3
"""Reproduce exact-build read-only combat-state inputs and original branches."""
import argparse, importlib.util, json, struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'))
r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
def ti(index):
    at=e.pointer(0xa64d6f0+index*8);return at,*struct.unpack('<QI',e.bytes(at,12))
def parent(index):
    t=m.types[index]
    if t[4]<0:return -1
    _,data,bits=ti(t[4]);return data if bits>>16&255==18 else -1
def family(index):
    for depth in range(16):
        if index==31737:return True
        if index<0:return False
        index=parent(index)
    return False
state_types=[i for i in range(len(m.types)) if family(i)]
classes=[]
for index in [11718,31716]+state_types:
    t=m.types[index];size,_,statics,_=struct.unpack('<4I',e.bytes(e.pointer(0xa925200+index*8),16))
    assert 16<=size<=1048576,(index,size)
    classes.append(dict(index=index,name=m.type_name(index),parent=parent(index),name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],
        record_hex=m.data[m.header[40]+index*88:m.header[40]+(index+1)*88].hex(),bits=ti(t[2])[2],instance_size=size,static_size=statics,token=t[-1]))
fields=[]
for owner,local,name,offset in [(12418,43,'m_GameServerGameMode',0x114),(31824,1271,'CINHNHDNFMF',0x1bb0),(31824,1337,'GBJCJJNPPEC',0x1d48),
    (31716,0,'BDOEGBMMEOK',0x10),(31716,1,'KFLCGJFEMPJ',0x18),(31716,2,'<BPIGJFNDGOP>k__BackingField',0x20),
    (31737,0,'OPHKBHDCEOD',0x10),(11718,5287,'EnableGetPhysXStateOpt',0x41fe)]:
    f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc,data,bits=ti(f[1])
    assert m.string(f[0])==name and struct.unpack('<I',e.bytes(slot,4))[0]==offset
    fields.append(dict(owner=owner,local=local,name=name,offset=offset,offset_rva=slot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,
        name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
methods=[];anchors=[]
def method(index,name,address,length):
    q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8
    assert m.string(q[0])==name and e.pointer(slot)==address
    methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex()))
    for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
for args in [(210413,'IsWatching',0x6f39994,0x48),(247110,'IsWatching',0x7c698e4,0x100),
    (212529,'IsInAnyJSGhost',0x70461d0,0x58),(34943,'get_GameServerGameMode',0x71bf5c0,0x80),
    (210197,'get_IsDieing',0x6f1deec,0x50),(214090,'ACDCHOCBLMK',0x70e2fcc,0x7c),
    (214084,'PJCCKDLGAPB',0x70e2d5c,0xd0),(214085,'OILOHAELLEC',0x70e2e2c,0x58),(214150,'JHBPLBBCOHG',0x70e5648,0x48)]:method(*args)
virtual=[];movement=[];seen=set()
core=json.loads(Path(__file__).with_name('object-reference.json').read_text())
for index,slot in [(c['index'],144) for c in core['classes'] if c['family']&16]+[(i,4) for i in state_types]:
    t=m.types[index];assert t[21]>slot
    pos=m.header[36]+(t[14]+slot)*4;enc=struct.unpack('<I',m.data[pos:pos+4])[0]
    if index==31737:
        assert slot==4 and enc==1 # abstract state base has no implementation
        continue
    assert enc>>29==3,(index,slot,hex(enc))
    mid=(enc>>1)&0xfffffff;q=m.methods[mid];addr=e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8)
    virtual.append(dict(index=index,slot=slot,metadata_offset=pos,encoded=enc,rva=addr))
    if slot!=4 or addr==0 or addr in seen:continue
    # These exact-build implementations have an IFix gate and then a constant
    # return. Check every instruction in the template before deriving constants.
    words=struct.unpack('<20I',e.bytes(addr,80))
    assert words[0:2]==(0xa9bf4ffe,0xaa0003f3)
    assert words[2]&0xffe0001f==0x52800000 and words[3]&0xffe0001f==0x72a00000
    gate=((words[2]>>5)&65535)|(((words[3]>>5)&65535)<<16)
    def branch_target(word,at):
        imm=word&0x3ffffff
        if imm&(1<<25):imm-=1<<26
        return at+imm*4
    assert words[4]==0xaa1f03e1 and words[5]>>26==0x25 and branch_target(words[5],addr+20)==0x882aa1c
    assert words[6]==0x36000140 # tbz w0,#0,original @+64
    assert words[7]==words[2] and words[8]==words[3] and words[9]==words[4]
    assert words[10]>>26==0x25 and branch_target(words[10],addr+40)==0x882aad0
    assert words[11:15]==(0xb4000100,0xaa1303e1,0xaa1f03e2,0xa8c14ffe)
    assert words[15]>>26==5 and branch_target(words[15],addr+60)==0x84369b4
    if words[16]==0x2a1f03e0:value=0
    else:
        assert words[16]&0xffe0001f==0x52800000
        value=(words[16]>>5)&65535
    assert words[17:19]==(0xa8c14ffe,0xd65f03c0)
    assert words[19]>>26==0x25 and branch_target(words[19],addr+76)==0xa354e78
    movement.append(dict(rva=addr,gate=gate,value=value));method(mid,m.string(q[0]),addr,80);seen.add(addr)
roots=[]
for name,got,expected in [('Facade',0xa73f0c0,12418),('Dynamic',0xa73ff50,34107),('GameVar',0xa73f5a8,11718)]:
    cell=e.pointer(got);enc=e.pointer(cell);assert ti((enc>>1)&0xfffffff)[1]==expected
    roots.append(dict(name=name,got=got,cell=cell,index=expected))
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,classes=classes,fields=fields,methods=methods,anchors=anchors,virtual=virtual,movement=movement,roots=roots,
    scope='One selected nonlocal player: original watching Boolean, dead/revive, ghost and IsDieing predicates. No combat eligibility, mode-zone, hostility, LOS or aim assertion.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'combat-state-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class CombatStateReference {',
       '        internal static readonly ObjectClassProfile[] Classes = {']
for c in classes:lines.append('            new ObjectClassProfile(%d,%s,0,%d,%dUL,%dUL,%s,%dU,%dU,%dU,%dU,0,16,true),'%(c['index'],json.dumps(c['name']),c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token']))
lines+=['        };','        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in [q for q in methods if q['rva'] not in seen]:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {']
for q in roots:lines.append('            new GameLayoutCheck(%s,0x%xUL,0x%xUL),'%(json.dumps(q['name']+'_got'),q['got'],q['cell']))
for q in [q for q in anchors if not any(at<=q['rva']<at+80 for at in seen)]:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','        internal static readonly TeamVirtual[] Virtuals = {']
for v in virtual:lines.append('            new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),'%(v['index'],v['slot'],v['metadata_offset'],v['encoded'],v['rva']))
lines+=['        };','        internal static readonly CombatMovement[] Movement = {']
for q in movement:
    method=next(method for method in methods if method['rva']==q['rva'])
    lines.append('            new CombatMovement(0x%xUL,0x%x,%d,new StateMethod(%dUL,0x%xUL,0x%xUL,%s),%s),'%(q['rva'],q['gate'],q['value'],method['metadata_offset'],method['pointer_rva'],method['rva'],json.dumps(method['record_hex']),json.dumps(e.bytes(q['rva'],80).hex())))
lines+=['        };','    }','}',''];(out/'CombatStateReference.cs').write_text('\n'.join(lines))
print('CombatStateReference=PASS Classes=%d Fields=%d Methods=%d Virtuals=%d MovementImplementations=%d'%(len(classes),len(fields),len(methods),len(virtual),len(movement)))
