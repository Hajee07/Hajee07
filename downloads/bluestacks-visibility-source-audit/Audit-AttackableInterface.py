#!/usr/bin/env python3
"""Catalog a pinned interface declaration and source dispatch-slot evidence."""
import argparse
import importlib.util
import json
import struct
from pathlib import Path


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('elf');p.add_argument('metadata');p.add_argument('report')
    a=p.parse_args();root=Path(__file__).resolve().parent
    s=importlib.util.spec_from_file_location('reader',root.parent/'bluestacks-process-map/Recover-GameLayout.py')
    r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
    e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
    owner=31910;t=m.types[owner]
    assert m.type_name(owner)=='COW.GamePlay.OGKFEMJNCGM' and t[7]&0x20
    def descriptor(index):
        at=e.pointer(0xa64d6f0+index*8);data,bits=struct.unpack('<QI',e.bytes(at,12));kind=(bits>>16)&255
        return dict(index=index,rva=at,kind=kind,data=data,name=m.type_name(data) if kind in (17,18) else None)
    methods=[]
    for index,q in enumerate(m.methods):
        if q[1]!=owner:continue
        parameters=[]
        for j in range(q[11]):
            param=m.parameters[q[4]+j]
            parameters.append(dict(name=m.string(param[0]),type=descriptor(param[2])))
        methods.append(dict(index=index,name=m.string(q[0]),slot=q[10],return_type=descriptor(q[2]),parameters=parameters,flags=q[8]))
    assert len(methods)==22 and [x['slot'] for x in methods]==list(range(22))
    selected=next(x for x in methods if x['slot']==4)
    assert selected['name']=='IsStreamerVisible' and selected['return_type']['kind']==2 and not selected['parameters']
    usage_cell=0xa7b7520;storage=e.pointer(usage_cell);word=struct.unpack('<I',e.bytes(storage,4))[0]
    byval=t[2];expected=(1<<29)|(byval<<1)|1
    assert word==expected and descriptor(byval)['data']==owner
    # Exact source operands establish slot 4 on both fast and fallback paths.
    anchors=[(0x6f993d4,'82008052'),(0x6f993ec,'08110011'),(0x6f99400,'00013fd6')]
    for at,hexword in anchors:assert e.bytes(at,4).hex()==hexword
    report=dict(audit_version=1,elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,
                scope='OFFLINE DECLARATION AND SLOT EVIDENCE; NO CONCRETE IMPLEMENTATION',
                interface_index=owner,interface_name=m.type_name(owner),methods=methods,
                usage_reference=dict(got_cell_rva=usage_cell,storage_rva=storage,raw_word=word,
                    byval_descriptor_index=byval,expected_type_usage_word=expected,
                    status='MATCHES_TYPE_USAGE_MARKER_FORM; NOT A LIVE CLASS POINTER'),
                dispatch=dict(helper_rva=0x6f99220,slot=4,declared_method=selected['name'],
                    fallback_slot_argument_rva=0x6f993d4,fast_path_slot_add_rva=0x6f993ec,indirect_call_rva=0x6f99400,
                    concrete_target='UNRESOLVED',source_anchors=[dict(rva=x,word_hex=y) for x,y in anchors]),
                limitations=['The source marker matches the interface byval type descriptor; no runtime class pointer was captured.',
                    'Slot 4 is declared IsStreamerVisible. Its name alone does not prove line of sight, occlusion, head visibility or player eligibility.',
                    'Concrete interface implementation, overrides, hotfix selection and runtime vtable entries remain unverified.',
                    'Position, attackable center and damage position declarations are distinct contracts; none is established as a head coordinate.',
                    'Setters and damage/healing methods are declaration inventory only and were not invoked.'],
                functions_invoked=False,memory_writes=False,head_los_verified=False,concrete_target_verified=False)
    Path(a.report).write_text(json.dumps(report,indent=2)+'\n')
    print('AttackableInterfaceAudit=PASS Methods=22 SourceSlot=4 Declaration=IsStreamerVisible ConcreteTarget=UNRESOLVED')


if __name__=='__main__':main()
