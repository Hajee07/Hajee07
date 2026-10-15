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
selected={31706:256,12418:1,37332:2,36294:32,transform:64}
for i in range(len(m.types)):
 for target,flag in [(12425,4),(32133,8),(31824,16)]:
  if reaches(i,target):selected[i]=selected.get(i,0)|flag
for i in [14528,31705,36295]:selected[i]=128
def make_profile(i,flags,minimum=None):
 t=m.types[i];pos=m.header[40]+i*88;size=e.pointer(0xa925200+i*8);instance,_,statics,_=struct.unpack('<4I',e.bytes(size,16));bits=native_info(t[2])[1]
 if minimum is None:
  minimum = 0 if flags & 32 else 9328 if flags & 16 else 1592 if flags & 8 else 592 if flags & 4 else 24 if flags & 128 else 48 if flags & 256 else 40 if i == 37332 else 16
 return dict(minimum_instance_size=minimum, instance_size_exact=minimum <= instance <= 1048576, index=i,name=m.type_name(i),family=flags,parent=parents[i],name_offset=m.header[6]+t[0],namespace_offset=m.header[6]+t[1],record_hex=m.data[pos:pos+88].hex(),bits=bits,instance_size=instance,static_size=statics,token=t[-1],getter={14528:0x37987c4,31705:0x70e0ba8,36295:0x8259e90}.get(i,0))
classes=[make_profile(i,flags) for i,flags in sorted(selected.items())]
string_profile=make_profile(37434,0,20)
dictionary_profile=make_profile(38851,0,40)
anchors=[]
for name,start,length in [('local_path',0x71c589c,0x130),('class_constructor',0xa32b6ec,0x174),('class_sizes',0xa32b798,0x38),('class_type_token',0xa32b888,0x10),('hotfix_dispatch',0x882aa50,0x78),('head_interface_dispatch',0x6f37ca0,0x74),('local_flag',0x6eff96c,12),('provider1',0x37987c4,8),('provider2',0x70e0ba8,8),('provider3',0x8259e90,8),('dynamic_size1',0xa3817b0,40),('dynamic_size2',0xa3818e4,40),('static_alloc',0xa381910,24),('field_layout',0xa354c38,20),('head_lazy_path',0x6f37c58,0x48),('node_getter',0x7013344,0x70),('model_lookup',0x70e1318,0xa0),('dictionary_lookup',0x9155c64,0x80),('dictionary_layout',0x915499c,0x44),('generic_type',0xa345e7c,0x30),('generic_token',0xa345f28,0x10),('head_dictionary_version',0x9154cf4,16)]:
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
# Bound the IFix instance from its actual nonstatic fields, not the opaque
# initial native size. These exact fields use reference/int32/reference widths.
instance_extents=[]
for k in range(hotfix[18]):
 field=m.fields[hotfix[8]+k];kind=native_info(field[1])[1];offset=int.from_bytes(e.bytes(hotfix_offsets+k*4,4),'little')
 if not kind&16:
  width={0x12:8,0x1c:8,8:4}.get(kind>>16&255)
  assert width is not None and offset<1048576
  instance_extents.append(offset+width)
assert max(instance_extents)==40
wrapper_profile=dict(local_index=j, token=f[2], name_offset=m.header[6]+f[0], type_rva=wrapper_type,
                     metadata_offset=m.header[24]+(hotfix[8]+j)*12, record_hex=struct.pack('<iiI',*f).hex())
# Find the local marker by the native offset, and verify its bool kind.
t=m.types[31824];offsets=e.pointer(0xa8cfec0+31824*8)
found=[]
for j in range(t[18]):
 if int.from_bytes(e.bytes(offsets+j*4,4),'little')==0x420:
  f=m.fields[t[8]+j];assert native_info(f[1])[1]>>16&255==2;found.append(m.string(f[0]))
assert found==['JKACLOCKKPH']
# The lazy head getter passes string-literal usage index 43798, not a method.
head_cell=e.pointer(0xa753ac0);encoded=int.from_bytes(e.bytes(head_cell,8),'little')
assert encoded>>29==5 and (encoded>>1)&0xfffffff==43798
literal_length,literal_offset=struct.unpack_from('<II',m.data,m.header[2]+43798*8)
head_key=m.data[m.header[4]+literal_offset:m.header[4]+literal_offset+literal_length].decode('utf-8')
assert head_key=='bone_Head'
for player_index in [31824,32360]:
 t=m.types[player_index];vtable=struct.unpack_from('<I',m.data,m.header[36]+(t[14]+29)*4)[0]
 assert vtable==0x600677bf
method=m.methods[(vtable>>1)&0xfffffff]
assert m.string(method[0])=='GetTransformNode' and e.pointer(0xa98efa8+((method[7]&0xffffff)-1)*8)==0x7013344
# Exact Player field, model cache class and closed Dictionary<string,BFOONIGAIFK>.
player=m.types[31824];offsets=e.pointer(0xa8cfec0+31824*8)
player_fields=[m.fields[player[8]+j] for j in range(player[18]) if int.from_bytes(e.bytes(offsets+j*4,4),'little')==0x1530]
assert len(player_fields)==1 and native_info(player_fields[0][1])[0]==31706
model=m.types[31706];model_offsets=e.pointer(0xa8cfec0+31706*8)
dict_fields=[m.fields[model[8]+j] for j in range(model[18]) if int.from_bytes(e.bytes(model_offsets+j*4,4),'little')==0x10]
assert len(dict_fields)==1
native_type=e.pointer(0xa64d6f0+dict_fields[0][1]*8);native_bits=int.from_bytes(e.bytes(native_type+8,4),'little')
assert native_bits>>16&255==0x15
generic=e.pointer(native_type);definition=e.pointer(generic);inst=e.pointer(generic+8);argv=e.pointer(inst+8)
assert int.from_bytes(e.bytes(definition,8),'little')==38851 and int.from_bytes(e.bytes(inst,4),'little')==2
arg0=e.pointer(argv);arg1=e.pointer(argv+8)
assert int.from_bytes(e.bytes(arg0+8,4),'little')>>16&255==14 and int.from_bytes(e.bytes(arg1,8),'little')==31705
cache_reference=dict(key=head_key,key_utf16_hex=head_key.encode('utf-16-le').hex(),string_profile=string_profile,dictionary_profile=dictionary_profile,
                     dictionary_type_rva=native_type,dictionary_type_bits=native_bits,vtable_table_offset=m.header[36],vtable_slot=29,vtable_encoded=0x600677bf,node_getter_rva=0x7013344)
anchors.append(dict(name='head_literal_got',rva=0xa753ac0,target_rva=head_cell))
report=dict(cache_reference=cache_reference,wrapper_field=wrapper_profile, elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,transform_type_index=transform,roots=roots,classes=classes,anchors=anchors,local_flag=dict(name=found[0],offset=0x420),scope='Original-path local-player chain and managed head Transform; native position and match collection references are separate.')
(root/'object-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified metadata/ELF inputs.','namespace HeadBridge.Mapping {','    internal static class ObjectReference {','        internal const int TransformIndex = %d;'%transform,'        internal static readonly ObjectClassProfile[] Classes = new ObjectClassProfile[] {']
def profile_line(c):
 return '            new ObjectClassProfile(%d, %s, %d, %d, %dUL, %dUL, %s, %dU, %dU, %dU, %dU, %dUL, %dU, %s),'%(c['index'],json.dumps(c['name']),c['family'],c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token'],c['getter'],c['minimum_instance_size'],str(c['instance_size_exact']).lower())
for c in classes:lines.append(profile_line(c))
lines+=['        };','        internal static readonly GameLayoutCheck[] Anchors = new GameLayoutCheck[] {']
for a in anchors:
 val='0x%xUL'%a['target_rva'] if 'target_rva' in a else json.dumps(a['hex'])
 lines.append('            new GameLayoutCheck(%s, 0x%xUL, %s),'%(json.dumps(a['name']),a['rva'],val))
lines+=['        };']
for r0 in roots:lines.append('        internal const ulong %sCell = 0x%xUL;'%(r0['name'],r0['cell']))
lines += ['        internal const int WrapperFieldIndex = %d;' % wrapper_profile['local_index'],
          '        internal const uint WrapperFieldToken = %dU, WrapperTypeBits = %dU;' % (wrapper_profile['token'], wrapper_bits),
          '        internal const ulong WrapperFieldNameOffset = %dUL, WrapperTypeRva = %dUL, WrapperMetadataOffset = %dUL;' % (wrapper_profile['name_offset'],wrapper_profile['type_rva'],wrapper_profile['metadata_offset']),
          '        internal const string WrapperFieldRecordHex = "%s";' % wrapper_profile['record_hex']]
lines += ['        internal static readonly ObjectClassProfile HeadStringProfile = ' + profile_line(string_profile).strip().rstrip(',') + ';',
          '        internal static readonly ObjectClassProfile HeadDictionaryProfile = ' + profile_line(dictionary_profile).strip().rstrip(',') + ';',
          '        internal const ulong HeadDictionaryTypeRva = %dUL, VtableTableOffset = %dUL;' % (native_type,m.header[36]),
          '        internal const uint HeadDictionaryTypeBits = %dU;' % native_bits,
          '        internal const string HeadKeyUtf16Hex = "%s";' % cache_reference['key_utf16_hex']]
lines+=['    }','}',''];(root/'ObjectReference.cs').write_text('\n'.join(lines))
print('ObjectReferenceClasses='+str(len(classes))+' Anchors='+str(len(anchors))+' TransformIndex='+str(transform))
