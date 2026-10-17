#!/usr/bin/env python3
"""Offline declaration inventory and inspected visibility-policy windows."""
import argparse
import importlib.util
import json
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('elf');p.add_argument('metadata');p.add_argument('report');a=p.parse_args()
    root=Path(__file__).resolve().parent
    s=importlib.util.spec_from_file_location('reader',root.parent/'bluestacks-process-map/Recover-GameLayout.py')
    r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
    e=r.Elf(Path(a.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
    candidates=[]
    for index,q in enumerate(m.methods):
        if m.string(q[0])!='IsStreamerVisible':continue
        candidates.append(dict(index=index,owner=m.type_name(q[1]),slot=q[10],
            interface=bool(m.types[q[1]][7]&0x20),
            scope='NAME MATCH ONLY; INTERFACE IMPLEMENTATION/VIRTUAL OVERRIDE NOT PROVEN'))
    assert len(candidates)==12
    windows=[]; decoded={}
    for index,address,length in [(210410,0x6f39828,188),(210411,0x6f398e4,104),(215868,0x717585c,72)]:
        q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8
        assert e.pointer(slot)==address
        body=e.bytes(address,length)
        instructions=list(Cs(CS_ARCH_ARM64,CS_MODE_LITTLE_ENDIAN).disasm(body,address))
        assert len(instructions)==length//4
        decoded.update({i.address:(i.mnemonic,i.op_str) for i in instructions})
        windows.append(dict(index=index,owner=m.type_name(q[1]),name=m.string(q[0]),rva=address,
            window_bytes=length,registration_slot_rva=slot,source_hex=body.hex(),
            scope='MANUALLY INSPECTED SOURCE WINDOW; NOT GENERAL FUNCTION BOUND RECOVERY',
            instructions=[dict(rva=i.address,mnemonic=i.mnemonic,operands=i.op_str) for i in instructions]))
    expected={0x6f398b0:('mov','w9, #0x1ebb'),0x6f398b4:('ldrb','w8, [x8, x9]'),
              0x6f398b8:('cbz','w8, #0x6f398d0'),0x6f398c4:('mov','w1, #4'),
              0x6f398cc:('b','#0x6f398e4'),0x6f398d4:('mov','w0, #1'),
              0x6f3992c:('ldr','x0, [x20, #0xad0]'),0x6f39944:('b','#0x8279204'),
              0x7175894:('mov','w0, #1')}
    assert all(decoded[address]==pair for address,pair in expected.items())
    report=dict(audit_version=1,elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,
        scope='OFFLINE POLICY SOURCE ONLY',named_declarations=candidates,windows=windows,
        findings=['Player original path reads a static byte at static-storage +0x1ebb; zero returns true.',
                  'When the static byte is nonzero, Player tail-calls IsPartialVisible with raw argument 4.',
                  'IsPartialVisible original path loads Player +0xad0 and tail-calls the previously identified BitArray.HasFlag helper.',
                  'AttackableEntity original path returns true; a selected hotfix can replace that path.',
                  'These inspected paths do not establish a fresh head-to-camera collision ray or authoritative LOS.',
                  'Twelve name matches include one interface; name matches alone do not prove concrete dispatch or override ownership.'],
        unverified=['live static flag','meaning/freshness of bit 4','hotfix selection','concrete runtime dispatch','head LOS'],
        functions_invoked=False,memory_writes=False,head_los_verified=False)
    Path(a.report).write_text(json.dumps(report,indent=2)+'\n')
    print('StreamerVisibilityAudit=PASS NamedDeclarations=12 Windows=3 HeadLOS=UNVERIFIED')


if __name__=='__main__':main()
