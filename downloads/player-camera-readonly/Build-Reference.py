#!/usr/bin/env python3
"""Generate a field reference solely from exact pinned game ELF/metadata inputs."""
import argparse,importlib.util,json,struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('elf',type=Path);p.add_argument('metadata',type=Path);p.add_argument('output',type=Path);p.add_argument('--runtime',type=Path)
a=p.parse_args();root=Path(__file__).resolve().parent
runtime=a.runtime or (root/'baseline' if (root/'baseline').exists() else root.parent/'bluestacks-process-map')
s=importlib.util.spec_from_file_location('reader',runtime/'Recover-GameLayout.py');r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
e=r.Elf(a.elf.read_bytes());m=r.Metadata(r.decode_metadata(a.metadata.read_bytes()))
owner=31824;local=174;index=m.types[owner][8]+local;field=m.fields[index]
slot=e.pointer(0xa8cfec0+owner*8)+local*4;descriptor=e.pointer(0xa64d6f0+field[1]*8);data,bits=struct.unpack('<QI',e.bytes(descriptor,12))
assert m.type_name(owner)=='COW.GamePlay.Player' and m.string(field[0])=='MainCameraTransform' and m.type_name(data)=='UnityEngine.Transform'
c=dict(Offset=struct.unpack('<I',e.bytes(slot,4))[0],OffsetRva=slot,DescriptorRva=descriptor,NameOffset=m.header[6]+field[0],MetadataOffset=m.header[24]+index*12,DescriptorBits=bits,FieldToken=field[2],LocalIndex=local,TransformTypeIndex=data,FieldRecordHex=struct.pack('<iiI',*field).hex())
s='// Generated from pinned game field metadata; uploaded DLL never loaded.\nnamespace HeadBridge.Mapping {\ninternal static class PlayerCameraReference {\n'
for key,value in c.items():
 if isinstance(value,str):s+='internal const string '+key+' = "'+value+'";\n'
 elif key in ['LocalIndex','TransformTypeIndex']:s+='internal const int '+key+' = '+str(value)+';\n'
 elif key in ['DescriptorBits','FieldToken']:s+='internal const uint '+key+' = '+hex(value)+'U;\n'
 else:s+='internal const ulong '+key+' = '+hex(value)+'UL;\n'
s+='}\n}\n';a.output.mkdir(parents=True,exist_ok=True);(a.output/'PlayerCameraReference.cs').write_text(s)
(a.output/'reference.json').write_text(json.dumps(dict(elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,owner=m.type_name(owner),field=m.string(field[0]),constants=c),indent=2)+'\n')
print('PlayerCameraReference=PASS Fields=1 Constants=10')
