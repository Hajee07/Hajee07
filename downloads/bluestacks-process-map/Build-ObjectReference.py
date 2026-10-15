import importlib.util,struct,json,argparse
from pathlib import Path
source=Path(__file__).resolve().parent
parser=argparse.ArgumentParser(description='Reproduce read-only object references from the exact input ELF and metadata.')
parser.add_argument('elf');parser.add_argument('metadata');parser.add_argument('output_directory');args=parser.parse_args()
root=Path(args.output_directory);root.mkdir(parents=True,exist_ok=True)
s=importlib.util.spec_from_file_location('recover',source/'Recover-GameLayout.py');r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
m=r.Metadata(r.decode_metadata(Path(args.metadata).read_bytes()));e=r.Elf(Path(args.elf).read_bytes())
def native_info(index):
 if index<0:return (-1,0)
 at=e.pointer(0xa64d6f0+index*8);data,bits=struct.unpack('<QI',e.bytes(at,12));return (data if bits>>16&255 in (17,18) else -1,bits)
parents={i:native_info(t[4])[0] for i,t in enumerate(m.types)}
def reaches(i,target):
 visited=set()
 while i>=0 and i not in visited:
  if i==target:return True
  visited.add(i);i=parents[i]
 return False
transform=next(i for i in range(len(m.types)) if m.type_name(i)=='UnityEngine.Transform')
selected={12418:1,37332:2,36294:32,transform:64}
for i in range(len(m.types)):
 for target,flag in [(12425,4),(32133,8),(31824,16)]:
  if reaches(i,target):selected[i]=selected.get(i,0)|flag
for i in [14528,31705,36295]:selected[i]=128
classes=[]
for i,flags in sorted(selected.items()):
 t=m.types[i];pos=m.header[40]+i*88;size=e.pointer(0xa925200+i*8);instance,_,statics,_=struct.unpack('<4I',e.bytes(size,16));bits=native_info(t[2])[1]
 classes.append(dict(index=i,name=m.type_name(i),family=flags,parent=parents[i],name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],record_hex=m.data[pos:pos+88].hex(),bits=bits,instance_size=instance,static_size=statics,token=t[-1],getter={14528:0x37987c4,31705:0x70e0ba8,36295:0x8259e90}.get(i,0)))
anchors=[]
for name,start,length in [('local_path',0x71c589c,0x130),('class_constructor',0xa32b6ec,0x174),('class_sizes',0xa32b798,0x38),('class_type_token',0xa32b888,0x10),('hotfix_dispatch',0x882aa50,0x78),('head_interface_dispatch',0x6f37ca0,0x74),('local_flag',0x6eff96c,12),('provider1',0x37987c4,8),('provider2',0x70e0ba8,8),('provider3',0x8259e90,8)]:
 for offset in range(0,length,32):anchors.append(dict(name=name+'_'+str(offset),rva=start+offset,hex=e.bytes(start+offset,min(32,length-offset)).hex()))
roots=[]
for name,got,index in [('Facade',0xa73f0c0,12418),('MatchGame',0xa7759c0,12425),('Hotfix',0xa899b98,37332),('HeadInterface',0xa74bec8,36294)]:
 cell=e.pointer(got);encoded=int.from_bytes(e.bytes(cell,8),'little');assert native_info((encoded>>1)&0xfffffff)[0]==index
 roots.append(dict(name=name,got=got,cell=cell,index=index,encoded=encoded));anchors.append(dict(name='got_'+name,rva=got,target_rva=cell))
hotfix=m.types[37332];hotfix_offsets=e.pointer(0xa8cfec0+37332*8)
wrapper_fields=[(j,m.fields[hotfix[8]+j]) for j in range(hotfix[18]) if m.string(m.fields[hotfix[8]+j][0])=='wrapperArray']
assert len(wrapper_fields)==1
j,f=wrapper_fields[0];wrapper_type=e.pointer(0xa64d6f0+f[1]*8)
assert int.from_bytes(e.bytes(hotfix_offsets+j*4,4),'little')==0
wrapper_bits=int.from_bytes(e.bytes(wrapper_type+8,4),'little')
assert wrapper_bits&16 and wrapper_bits>>16&255==0x1d
wrapper_element=e.pointer(wrapper_type)
assert int.from_bytes(e.bytes(wrapper_element,8),'little')==37332
# Find the local marker by the native offset, and verify its bool kind.
t=m.types[31824];offsets=e.pointer(0xa8cfec0+31824*8)
found=[]
for j in range(t[18]):
 if int.from_bytes(e.bytes(offsets+j*4,4),'little')==0x420:
  f=m.fields[t[8]+j];assert native_info(f[1])[1]>>16&255==2;found.append(m.string(f[0]))
assert found==['JKACLOCKKPH']
report=dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,transform_type_index=transform,roots=roots,classes=classes,anchors=anchors,local_flag=dict(name=found[0],offset=0x420),scope='Original-path local-player chain and managed head Transform; world coordinates and player enumeration are unimplemented.')
(root/'object-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified metadata/ELF inputs.','namespace HeadBridge.Mapping {','    internal static class ObjectReference {','        internal const int TransformIndex = %d;'%transform,'        internal static readonly ObjectClassProfile[] Classes = new ObjectClassProfile[] {']
for c in classes:
 lines.append('            new ObjectClassProfile(%d, %s, %d, %d, %dUL, %dUL, %s, %dU, %dU, %dU, %dU, %dUL),'%(c['index'],json.dumps(c['name']),c['family'],c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token'],c['getter']))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = new GameLayoutCheck[] {']
for a in anchors:
 val='0x%xUL'%a['target_rva'] if 'target_rva' in a else json.dumps(a['hex'])
 lines.append('            new GameLayoutCheck(%s, 0x%xUL, %s),'%(json.dumps(a['name']),a['rva'],val))
lines+=['        };']
for r0 in roots:lines.append('        internal const ulong %sCell = 0x%xUL;'%(r0['name'],r0['cell']))
lines+=['    }','}',''];(root/'ObjectReference.cs').write_text('\n'.join(lines))
print('ObjectReferenceClasses='+str(len(classes))+' Anchors='+str(len(anchors))+' TransformIndex='+str(transform))
