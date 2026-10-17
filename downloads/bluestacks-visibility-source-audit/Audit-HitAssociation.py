#!/usr/bin/env python3
"""Offline control-flow evidence for a pinned hit-association helper window."""
import argparse
import importlib.util
import json
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('elf'); p.add_argument('metadata'); p.add_argument('report')
    a = p.parse_args()
    root = Path(__file__).resolve().parent
    spec = importlib.util.spec_from_file_location('reference_reader', root.parent / 'bluestacks-process-map/Recover-GameLayout.py')
    r = importlib.util.module_from_spec(spec); spec.loader.exec_module(r)
    e = r.Elf(Path(a.elf).read_bytes())
    m = r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
    contract = json.loads((root / 'hit-query-contract.json').read_text())
    source = next(x for x in contract['methods'] if x['index'] == 210965)
    start = source['rva']; body = e.bytes(start, 512)
    assert body.hex() == source['source_hex']
    q = m.methods[210965]
    assert m.string(q[0]) == 'JGIEOGCGFEP'
    assert e.pointer(0xa98efa8 + ((q[7] & 0xffffff) - 1) * 8) == start
    instructions = list(Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN).disasm(body, start))
    assert len(instructions) == 128
    edges = []; calls = []; indirect = []
    for i in instructions:
        if i.mnemonic in ('bl', 'b') or i.mnemonic.startswith('b.') or i.mnemonic in ('cbz','cbnz','tbz','tbnz'):
            target = int(i.op_str.split('#')[-1], 16)
            record = dict(rva=i.address, instruction=i.mnemonic, operands=i.op_str, target_rva=target)
            if i.mnemonic == 'bl': calls.append(record)
            else:
                record['inside_window'] = start <= target < start + len(body)
                edges.append(record)
        if i.mnemonic in ('blr', 'br'):
            indirect.append(dict(rva=i.address, instruction=i.mnemonic, operands=i.op_str, resolved=False))
    assert all(x['inside_window'] for x in edges if x['instruction'] != 'b')
    assert [x['rva'] for x in indirect] == [0x6f99400]
    indexed = {i.address:i for i in instructions}
    assert indexed[0x6f992c8].op_str == 'x20, [x19, #0x18]'
    assert indexed[0x6f99398].op_str == 'x21, [x0]'
    assert indexed[0x6f99400].op_str == 'x8'
    known = {0x9fec060:'UnityEngine.Object.op_Equality',0x9feadf4:'UnityEngine.Object.op_Inequality'}
    for c in calls:
        if c['target_rva'] in known: c['previously_verified_identity'] = known[c['target_rva']]
    report = dict(audit_version=1, scope='PINNED OFFLINE 512-BYTE WINDOW; NO LIVE EVALUATION',
                  elf_sha256=r.ELF_SHA, metadata_sha256=r.META_SHA, method_index=210965,
                  rva=start, window_bytes=len(body), source_hex=body.hex(),
                  instructions=[dict(rva=i.address,mnemonic=i.mnemonic,operands=i.op_str) for i in instructions],
                  branch_edges=edges,direct_calls=calls,indirect_calls=indirect,
                  findings=['A hotfix-selected path tail-branches outside this window; its behavior is not evaluated.',
                            'The original path loads an input reference at +0x18 and uses Object equality/inequality checks.',
                            'The path includes external helper calls and interface-dispatch preparation, ending in BLR X8.',
                            'The final boolean result gates whether the candidate reference is returned or zero is returned.',
                            'The dynamic interface method target, concrete candidate type, ownership and head identity remain unverified.',
                            'The helper is not a pure pointer chain: metadata/class initialization and indirect calls occur in its source.'],
                  dynamic_dispatch='UNRESOLVED',hotfix_path='UNRESOLVED',
                  collider_to_player_verified=False,head_los_verified=False,
                  functions_invoked=False,memory_writes=False)
    Path(a.report).write_text(json.dumps(report,indent=2)+'\n')
    print('HitAssociationAudit=PASS Instructions=128 DirectCalls=%d IndirectCalls=1 LiveAssociation=UNVERIFIED' % len(calls))


if __name__ == '__main__': main()
