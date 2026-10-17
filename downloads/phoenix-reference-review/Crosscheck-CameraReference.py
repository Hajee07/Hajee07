#!/usr/bin/env python3
"""Compare extracted managed constants with pinned game files; no live access."""
import argparse
import importlib.util
import json
import struct
from pathlib import Path


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('elf','metadata','inspection','report'):p.add_argument(name,type=Path)
    a=p.parse_args();helper=Path(__file__).resolve().parent.parent/'bluestacks-process-map/Recover-GameLayout.py'
    s=importlib.util.spec_from_file_location('reader',helper);r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
    e=r.Elf(a.elf.read_bytes());m=r.Metadata(r.decode_metadata(a.metadata.read_bytes()))
    ref=json.loads(a.inspection.read_text())['managed']['camera_reference_constants']
    owner=31824;local=174;index=m.types[owner][8]+local;field=m.fields[index]
    slot=e.pointer(0xa8cfec0+owner*8)+local*4;descriptor=e.pointer(0xa64d6f0+field[1]*8)
    data,bits=struct.unpack('<QI',e.bytes(descriptor,12))
    expected=dict(Offset=struct.unpack('<I',e.bytes(slot,4))[0],OffsetRva=slot,DescriptorRva=descriptor,
                  NameOffset=m.header[6]+field[0],MetadataOffset=m.header[24]+index*12,
                  DescriptorBits=bits,FieldToken=field[2],LocalIndex=local,TransformTypeIndex=data,
                  FieldRecordHex=struct.pack('<iiI',*field).hex())
    assert ref==expected,'Uploaded reference does not match pinned metadata'
    assert m.type_name(owner)=='COW.GamePlay.Player' and m.string(field[0])=='MainCameraTransform'
    assert m.type_name(data)=='UnityEngine.Transform'
    report=dict(scope='OFFLINE FIELD IDENTITY ONLY',elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,
        owner=m.type_name(owner),field=m.string(field[0]),declared_type=m.type_name(data),matched_constants=expected,
        matches=10,live_field_read=False,active_game_camera_verified=False,shot_convention_verified=False,
        transport_binding='NOT_SUPPLIED_BY_THIS_CHECK',functions_invoked=False,
        limitations=['A correct field declaration is not a current field value, object lifetime guarantee or active-render camera proof.',
                     'The uploaded assembly contains separate HeadBridge.Mapping types; it is not a drop-in native V52 bridge.',
                     'Source-level review/rebuild and runtime revalidation are required before using a derived reader path.'])
    a.report.write_text(json.dumps(report,indent=2)+'\n')
    print('ReferenceCrosscheck=PASS Constants=10 Field=Player.MainCameraTransform LiveBinding=UNVERIFIED')


if __name__=='__main__':main()
