#!/usr/bin/env python3
"""Generate exact-build references for original zone and invincibility observations."""
import argparse, importlib.util, json, struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('elf');p.add_argument('metadata');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('r',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
def ti(index):
 at=e.pointer(0xa64d6f0+index*8);return at,*struct.unpack('<QI',e.bytes(at,12))
classes=[]
for index in [31911,31912,36302,34539,36356,36353,36648,36647,36654,36651,36655,36644,36653]:
 t=m.types[index];size,_,statics,_=struct.unpack('<4I',e.bytes(e.pointer(0xa925200+index*8),16));assert 0<=size<=1048576
 classes.append(dict(index=index,name=m.type_name(index),parent=ti(t[4])[1] if t[4]>=0 else -1,name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],record_hex=m.data[m.header[40]+index*88:m.header[40]+(index+1)*88].hex(),bits=ti(t[2])[2],instance_size=size,static_size=statics,token=t[-1]))
fields=[]
for owner,local,name,offset in [(12418,43,'m_GameServerGameMode',0x114),(31824,324,'IODLOCEJIOK',0x768),(36302,1,'m_PRIDataPool',0x70),
 (34539,0,'BDOEGBMMEOK',0x20),(34539,127,'KNODCJBPNAB',0x2b0),(36353,2,'m_Value',0x10),(36356,1,'m_Mode',0x18),
 (36647,0,'m_Datas',0x10),(36647,1,'m_MaxVarCount',0x18),(36654,0,'m_Datas',0x10),(36654,1,'m_MaxVarCount',0x18),
 (36644,1,'Value',0x18),(36653,1,'Value',0x18)]:
 f=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4;desc,data,bits=ti(f[1]);assert m.string(f[0])==name and struct.unpack('<I',e.bytes(slot,4))[0]==offset
 fields.append(dict(owner=owner,local=local,name=name,offset=offset,offset_rva=slot,descriptor=desc,bits=bits,type_index=data if bits>>16&255 in (17,18) else -1,name_offset=m.header[6]+f[0],token=f[2],metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,record_hex=struct.pack('<iiI',*f).hex()))
methods=[];anchors=[]
for index,name,address,length in [(212886,'get_CurrentTrainingZoneType',0x6f359e4,0x130),(210275,'get_IsInBattleZone',0x6f35990,0x54),
 (210276,'get_IsInShootingRange',0x6f35b14,0x54),(35231,'IsOfflineTrainingMode',0x71d6858,0x80),(34943,'get_GameServerGameMode',0x71bf5c0,0x80),
 (246131,'IsInvincible',0x7c2f324,0x50),(266309,'GetBooleanValue',0x82796d0,0x24),
 (268413,'GetDataUInt8',0x82efc88,0x50),(268509,'GetDataUInt8',0x82f27b4,0x54)]:
 q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8
 assert m.string(q[0])==name and e.pointer(slot)==address,(index,m.string(q[0]),hex(e.pointer(slot)))
 methods.append(dict(index=index,name=name,rva=address,pointer_rva=slot,metadata_offset=m.header[12]+index*40,record_hex=struct.pack('<8i4H',*q).hex()))
 for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(index)+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
# Exact IL2CPP array constructor: x21 is the element class, x22 its
# embedded byval_arg, and SZARRAY type data uses x22 (not the ELF type record).
for address,word in [(0xa336544,0xaa0003f5),(0xa336710,0x910082b6),(0xa33675c,0xf90022f5),
                     (0xa3367ac,0x528003a8),(0xa3367b0,0x3900aa68),(0xa3367b8,0xf9001276)]:
 assert struct.unpack('<I',e.bytes(address,4))[0]==word,hex(address)
for name,address,length in [('array_constructor_element_argument',0xa336538,0x14),('array_constructor_array_alias',0xa3366c4,4),('array_constructor_byval_and_szarray',0xa336700,0xdc)]:
 for off in range(0,length,64):anchors.append(dict(name=name+'_'+str(off),rva=address+off,hex=e.bytes(address+off,min(64,length-off)).hex()))
cell=e.pointer(0xa8342a8);enc=e.pointer(cell);assert ti((enc>>1)&0xfffffff)[1]==36648
pools=[]
for index,base,data in [(36651,36647,36644),(36655,36654,36653)]:
 t=m.types[index];matches=[]
 for j in range(t[23]):
  pos=m.header[38]+(t[15]+j)*8;typ,off=struct.unpack_from('<ii',m.data,pos)
  if ti(typ)[1]==36648:matches.append((pos,off))
 assert len(matches)==1
 ipos,offset=matches[0];slot=offset+11;pos=m.header[36]+(t[14]+slot)*4;enc=struct.unpack_from('<I',m.data,pos)[0];assert enc>>29==3
 q=m.methods[(enc>>1)&0xfffffff];target=e.pointer(0xa98efa8+((q[7]&0xffffff)-1)*8);assert target=={36651:0x82efc88,36655:0x82f27b4}[index]
 f=m.fields[m.types[base][8]];desc,_,bits=ti(f[1]);element=e.pointer(desc);assert bits>>16&255==29 and e.pointer(element)==data and struct.unpack('<I',e.bytes(element+8,4))[0]==0x120000,(index,base,data,hex(element),hex(bits),e.pointer(element))
 pools.append(dict(index=index,base_index=base,data_index=data,interface_offset=offset,interface_metadata_offset=ipos,interface_hex=m.data[ipos:ipos+8].hex(),slot=slot,metadata_offset=pos,encoded=enc,rva=target,element_descriptor=element))
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,classes=classes,fields=fields,methods=methods,anchors=anchors,pools=pools,interface_cell=cell,
 array_element_byval_offset=32,scope='One selected nonlocal player: original CurrentTrainingZoneType and IsInvincible predicate only. No complete attackability, invulnerability policy, LOS or aim assertion.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'zone-protection-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified ELF/metadata inputs.','namespace HeadBridge.Mapping {','    internal static class ZoneProtectionReference {','        internal const ulong ArrayElementByvalOffset = 0x20UL;','        internal const ulong InterfaceCell = 0x%xUL;'%cell,'        internal static readonly ObjectClassProfile[] Classes = {']
for c in classes:lines.append('            new ObjectClassProfile(%d,%s,0,%d,%dUL,%dUL,%s,%dU,%dU,%dU,%dU,0,0,true),'%(c['index'],json.dumps(c['name']),c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token']))
lines+=['        };','        internal static readonly StateField[] Fields = {']
for f in fields:lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),'%(f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines+=['        };','        internal static readonly StateMethod[] Methods = {']
for q in methods:lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),'%(q['metadata_offset'],q['pointer_rva'],q['rva'],json.dumps(q['record_hex'])))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = {','            new GameLayoutCheck("zone_interface_got",0xa8342a8UL,0x%xUL),'%cell]
for q in anchors:lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),'%(json.dumps(q['name']),q['rva'],json.dumps(q['hex'])))
lines+=['        };','        internal static readonly ZonePool[] Pools = {']
for q in pools:lines.append('            new ZonePool(%d,%d,%d,%d,%dUL,%s,new TeamVirtual(%d,%d,%dUL,0x%xU,0x%xUL),0x%xUL),'%(q['index'],q['base_index'],q['data_index'],q['interface_offset'],q['interface_metadata_offset'],json.dumps(q['interface_hex']),q['index'],q['slot'],q['metadata_offset'],q['encoded'],q['rva'],q['element_descriptor']))
lines+=['        };','    }','}',''];(out/'ZoneProtectionReference.cs').write_text('\n'.join(lines));print('ZoneProtectionReference=PASS Fields=%d Methods=%d Classes=%d Pools=%d'%(len(fields),len(methods),len(classes),len(pools)))
