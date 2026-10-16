#!/usr/bin/env python3
"""Reproduce bounded state references from the exact, hash-verified inputs."""
import argparse
import importlib.util
import json
import struct
from pathlib import Path

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('elf'); p.add_argument('metadata'); p.add_argument('output_directory')
a = p.parse_args()
spec = importlib.util.spec_from_file_location('recover', Path(__file__).with_name('Recover-GameLayout.py'))
r = importlib.util.module_from_spec(spec); spec.loader.exec_module(r)
e = r.Elf(Path(a.elf).read_bytes())
m = r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))

def type_info(index):
    at = e.pointer(0xa64d6f0 + index * 8)
    return at, *struct.unpack('<QI', e.bytes(at, 12))

classes = []
for index, minimum in [(31911, 128), (36356, 28), (36353, 20)]:
    t = m.types[index]
    size, _, statics, _ = struct.unpack('<4I', e.bytes(e.pointer(0xa925200 + index * 8), 16))
    assert minimum <= size <= 1048576
    classes.append(dict(index=index, name=m.type_name(index), parent=type_info(t[4])[1],
                        name_offset=m.header[6]+t[0], namespace_offset=m.header[6]+t[1],
                        record_hex=m.data[m.header[40]+index*88:m.header[40]+(index+1)*88].hex(),
                        bits=type_info(t[2])[2], instance_size=size, static_size=statics, token=t[-1], minimum=minimum))
fields = []
for owner, local, name, offset in [
    (31824,182,'<DJJMAHEIDID>k__BackingField',0x430),
    (31824,432,'<INNGIOBPAJM>k__BackingField',0xa6c),
    (31824,509,'NBIIBJBALJD',0xad0),
    (31911,0,'CGJLEBOGBNP',0x7c),
    (36353,2,'m_Value',0x10), (36356,1,'m_Mode',0x18)]:
    f = m.fields[m.types[owner][8]+local]
    slot = e.pointer(0xa8cfec0+owner*8)+local*4
    assert m.string(f[0]) == name and struct.unpack('<I',e.bytes(slot,4))[0] == offset
    desc, data, bits = type_info(f[1])
    fields.append(dict(owner=owner, local=local, name=name, offset=offset, offset_rva=slot,
                       descriptor=desc, bits=bits, type_index=data if bits>>16&255 in (17,18) else -1,
                       name_offset=m.header[6]+f[0], token=f[2],
                       metadata_offset=m.header[24]+(m.types[owner][8]+local)*12,
                       record_hex=struct.pack('<iiI',*f).hex()))
methods = []
anchors = []
for index, name, address, length in [
    (210083,'get_TeamIndex',0x6f2ff24,8),
    (210297,'get_IsReallyDead',0x6f36230,0x68),
    (210298,'get_IsPendingRevive',0x6f36298,8),
    (210384,'IsVisible',0x6f38834,0x54),
    (215855,'get_IsDead',0x717533c,0x48),
    (266312,'op_Implicit',0x8279898,0x34)]:
    d = m.methods[index]; slot = 0xa98efa8+((d[7]&0xffffff)-1)*8
    assert m.string(d[0]) == name and e.pointer(slot) == address
    methods.append(dict(index=index, name=name, rva=address, pointer_rva=slot,
                        metadata_offset=m.header[12]+index*40, record_hex=struct.pack('<8i4H',*d).hex()))
    for off in range(0,length,32):
        anchors.append(dict(name=name+'_'+str(off), rva=address+off, hex=e.bytes(address+off,min(32,length-off)).hex()))
# Pin the direct getters and Boolean conversion, not merely their method names.
assert e.bytes(0x6f2ff24,8).hex() == '003044b9c0035fd6'
assert e.bytes(0x6f36298,8).hex() == '00b06939c0035fd6'
visibility = []
core = json.loads(Path(__file__).with_name('object-reference.json').read_text())
for c in core['classes']:
    if not c['family'] & 16: continue
    t = m.types[c['index']]; assert t[21] > 70
    pos = m.header[36]+(t[14]+70)*4
    encoded = struct.unpack('<I',m.data[pos:pos+4])[0]
    assert encoded>>29 == 3
    method = m.methods[(encoded>>1)&0xfffffff]
    target = e.pointer(0xa98efa8+((method[7]&0xffffff)-1)*8)
    visibility.append(dict(index=c['index'], metadata_offset=pos, encoded=encoded, rva=target))
report = dict(elf_sha256=r.ELF_SHA, metadata_sha256=r.META_SHA, classes=classes, fields=fields,
              methods=methods, anchors=anchors, visibility=visibility,
              scope='Raw TeamIndex; original-branch dead/revive and model visibility only. No enemy, alive eligibility, knockout, line-of-sight or aim claim.')
out = Path(a.output_directory); out.mkdir(parents=True,exist_ok=True)
(out/'player-state-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines = ['// Generated from exact SHA-256-verified ELF/metadata inputs.', 'namespace HeadBridge.Mapping {',
         '    internal static class PlayerStateReference {', '        internal static readonly ObjectClassProfile[] Classes = {']
for c in classes:
    lines.append('            new ObjectClassProfile(%d,%s,0,%d,%dUL,%dUL,%s,%dU,%dU,%dU,%dU,0,%dU,true),' %
                 (c['index'],json.dumps(c['name']),c['parent'],c['name_offset'],c['namespace_offset'],json.dumps(c['record_hex']),c['bits'],c['instance_size'],c['static_size'],c['token'],c['minimum']))
lines += ['        };','        internal static readonly StateField[] Fields = {']
for f in fields:
    lines.append('            new StateField(%d,%d,%s,0x%xUL,0x%xUL,0x%xUL,%dU,%d,%dUL,%dU,%dUL,%s),' %
                 (f['owner'],f['local'],json.dumps(f['name']),f['offset'],f['offset_rva'],f['descriptor'],f['bits'],f['type_index'],f['name_offset'],f['token'],f['metadata_offset'],json.dumps(f['record_hex'])))
lines += ['        };','        internal static readonly StateMethod[] Methods = {']
for method in methods:
    lines.append('            new StateMethod(%dUL,0x%xUL,0x%xUL,%s),' %
                 (method['metadata_offset'],method['pointer_rva'],method['rva'],json.dumps(method['record_hex'])))
lines += ['        };','        internal static readonly GameLayoutCheck[] Anchors = {']
for anchor in anchors:
    lines.append('            new GameLayoutCheck(%s,0x%xUL,%s),' % (json.dumps(anchor['name']),anchor['rva'],json.dumps(anchor['hex'])))
lines += ['        };','        internal static readonly StateVisibility[] Visibility = {']
for v in visibility:
    lines.append('            new StateVisibility(%d,%dUL,0x%xU,0x%xUL),' % (v['index'],v['metadata_offset'],v['encoded'],v['rva']))
lines += ['        };','    }','}','']
(out/'PlayerStateReference.cs').write_text('\n'.join(lines))
print('PlayerStateReference=PASS Fields=%d Methods=%d Classes=%d VisibilityProfiles=%d Anchors=%d' %
      (len(fields),len(methods),len(classes),len(visibility),len(anchors)))
