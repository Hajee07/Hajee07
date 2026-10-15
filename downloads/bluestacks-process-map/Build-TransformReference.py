#!/usr/bin/env python3
"""Reproduce exact Unity ARM64 read-only Transform binding references."""
import argparse, hashlib, importlib.util, json, struct
from pathlib import Path
p=argparse.ArgumentParser();p.add_argument('unity_elf');p.add_argument('il2cpp_elf');p.add_argument('output_directory');a=p.parse_args()
s=importlib.util.spec_from_file_location('recover',Path(__file__).with_name('Recover-GameLayout.py'));r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
il=r.Elf(Path(a.il2cpp_elf).read_bytes())
sha='1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77'
r.ELF_SHA=sha;e=r.Elf(Path(a.unity_elf).read_bytes())
# The two exact icall registration stubs bind the named managed injected calls.
assert e.bytes(0xe0a64,len(b'UnityEngine.Transform::get_position_Injected\0'))==b'UnityEngine.Transform::get_position_Injected\0'
assert e.bytes(0xf245b,len(b'UnityEngine.Transform::get_localPosition_Injected\0'))==b'UnityEngine.Transform::get_localPosition_Injected\0'
# ADD x1 immediates in each registration stub resolve these native targets.
assert struct.unpack('<I',e.bytes(0x46e9f0,4))[0]==0x91293021
assert struct.unpack('<I',e.bytes(0x46ea18,4))[0]==0x91319021
anchors=[]
for name,start,size in [('position_binding',0x46e9e4,20),('local_position_binding',0x46ea0c,20),('managed_native_pointer',0x71f7d0,12),('position_icall',0x45ea4c,0x114),('local_position_icall',0x45ec64,0x114),('transform_access',0x69304c,0x44),('world_position',0x691584,0xd4),('local_position',0x690da4,0x34),('hierarchy_capacity',0x693cfc,20),('hierarchy_assignment',0x693d28,12),('hierarchy_backlinks',0x693d54,0x44),('capacity_resize',0x693698,0x24),('job_clear',0x5f7138,12),('rotation_coefficients_1',0x185040,16),('rotation_coefficients_2',0x182650,16),('rotation_coefficients_3',0x185bc0,16)]:
 for off in range(0,size,64):anchors.append(dict(name=name+'_'+str(off),rva=start+off,hex=e.bytes(start+off,min(64,size-off)).hex()))
coefficients=[struct.unpack('<4f',e.bytes(x,16)) for x in [0x185040,0x182650,0x185bc0]]
assert coefficients==[(-2.,2.,-2.,0.),(2.,-2.,-2.,0.),(-2.,-2.,2.,0.)],coefficients
ilanchors=[dict(name=name,rva=start,hex=il.bytes(start,size).hex()) for name,start,size in [('get_position',0x9ff5f40,0x5c),('get_position_injected',0x9ff5f9c,0x44),('get_local_position_injected',0x9ff6078,0x44)]]
header=e.bytes(0,64);phoff=struct.unpack_from('<Q',header,32)[0];stride,count=struct.unpack_from('<HH',header,54);programs=e.bytes(phoff,stride*count)
assert phoff==64 and stride==56 and count==10
note=e.bytes(0x308,24);assert note[:16].hex()=='040000000800000003000000474e5500'
report=dict(unity_sha256=sha,unity_build_id=note[16:].hex(),header_hex=header.hex(),programs_hex=programs.hex(),note_rva=0x308,note_hex=note.hex(),unity_anchors=anchors,il2cpp_anchors=ilanchors,coefficients=coefficients,bindings=[dict(cell=0xafb9e00,target=0x45ea4c),dict(cell=0xafb9e10,target=0x45ec64)],scope='Exact resolved icall binding and bounded sampled local-head native hierarchy; no game calls or writes.')
out=Path(a.output_directory);out.mkdir(parents=True,exist_ok=True);(out/'transform-reference.json').write_text(json.dumps(report,indent=2)+'\n')
lines=['// Generated from exact SHA-256-verified Unity/IL2CPP ELF inputs.','namespace HeadBridge.Mapping {','    internal static class NativeTransformReference {']
for name,val in [('FileSha256',sha),('BuildId',report['unity_build_id']),('HeaderHex',header.hex()),('ProgramsHex',programs.hex()),('NoteHex',note.hex())]:lines.append('        internal const string %s = %s;'%(name,json.dumps(val)))
for label,items in [('UnityAnchors',anchors),('Il2CppAnchors',ilanchors)]:
 lines.append('        internal static readonly GameLayoutCheck[] %s = new GameLayoutCheck[] {'%label)
 for x in items:lines.append('            new GameLayoutCheck(%s, 0x%xUL, %s),'%(json.dumps(x['name']),x['rva'],json.dumps(x['hex'])))
 lines.append('        };')
lines+=['    }','}',''];(out/'NativeTransformReference.cs').write_text('\n'.join(lines));print('UnityBuildId='+report['unity_build_id']+' UnityAnchors='+str(len(anchors))+' Il2CppAnchors='+str(len(ilanchors)))
