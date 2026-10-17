#!/usr/bin/env python3
"""Resolve a pinned visibility configuration field declaration offline."""
import argparse
import importlib.util
import json
import struct
from pathlib import Path


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('elf');p.add_argument('metadata');p.add_argument('report');a=p.parse_args()
    root=Path(__file__).resolve().parent
    s=importlib.util.spec_from_file_location('reader',root.parent/'bluestacks-process-map/Recover-GameLayout.py')
    r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
    e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
    cell=0xa73f5a8;storage=e.pointer(cell);word=struct.unpack('<I',e.bytes(storage,4))[0]
    descriptor_index=(word&0x1ffffffe)>>1
    assert word==(1<<29)|(descriptor_index<<1)|1
    at=e.pointer(0xa64d6f0+descriptor_index*8);owner,bits=struct.unpack('<QI',e.bytes(at,12))
    assert (bits>>16)&255==18 and owner==11718 and m.type_name(owner)=='COW.GameVarDef'
    t=m.types[owner];offset_table=e.pointer(0xa8cfec0+owner*8)
    matches=[]
    for local in range(t[18]):
        slot=offset_table+local*4;offset=struct.unpack('<I',e.bytes(slot,4))[0]
        if offset!=0x1ebb:continue
        field=m.fields[t[8]+local];desc=e.pointer(0xa64d6f0+field[1]*8)
        data,field_bits=struct.unpack('<QI',e.bytes(desc,12))
        matches.append(dict(local_index=local,name=m.string(field[0]),source_offset=offset,
            offset_registration_rva=slot,type_descriptor_rva=desc,type_bits=field_bits,
            type_kind=(field_bits>>16)&255,static_attribute=bool(field_bits&0x10)))
    assert len(matches)==1 and matches[0]['name']=='AimCheckPlayerStreamerVisibility'
    assert matches[0]['type_kind']==2 and matches[0]['static_attribute']
    q=m.methods[210411];param=m.parameters[q[4]];param_at=e.pointer(0xa64d6f0+param[2]*8)
    _,param_bits=struct.unpack('<QI',e.bytes(param_at,12))
    assert (param_bits>>16)&255==9
    report=dict(audit_version=1,elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,
        scope='OFFLINE CONFIG DECLARATION; NO LIVE FLAG CAPTURE',owner=m.type_name(owner),
        source_usage=dict(cell_rva=cell,storage_rva=storage,raw_word=word,descriptor_index=descriptor_index,
            status='MATCHES_TYPE_USAGE_MARKER; NOT LIVE CLASS ADDRESS'),field=matches[0],
        partial_visibility_argument=dict(method_index=210411,parameter_name=m.string(param[0]),
            type_kind=9,type_name='UInt32',source_argument=4,meaning='UNVERIFIED'),
        findings=['The static Boolean field is AimCheckPlayerStreamerVisibility on COW.GameVarDef.',
            'The previously inspected original Player path bypasses the partial-visibility check when this flag is zero.',
            'A configuration switch is not a target visibility result.',
            'Raw argument 4 is passed to a UInt32 parameter; no head-specific meaning is established.'],
        live_flag='NOT_CAPTURED',default_value='NOT_DECODED',writers='NOT_TRACED',
        head_los_verified=False,functions_invoked=False,memory_writes=False)
    Path(a.report).write_text(json.dumps(report,indent=2)+'\n')
    print('VisibilityConfigAudit=PASS StaticBoolean=AimCheckPlayerStreamerVisibility LiveValue=UNKNOWN')


if __name__=='__main__':main()
