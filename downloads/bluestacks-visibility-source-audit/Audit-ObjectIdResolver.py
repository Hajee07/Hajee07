#!/usr/bin/env python3
"""Inspect a pinned offline resolver wrapper; never invoke engine functions."""
import argparse
import importlib.util
import json
from pathlib import Path


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('elf'); p.add_argument('metadata'); p.add_argument('report')
    a = p.parse_args()
    helper = Path(__file__).resolve().parent.parent / 'bluestacks-process-map/Recover-GameLayout.py'
    spec = importlib.util.spec_from_file_location('reference_reader', helper)
    r = importlib.util.module_from_spec(spec); spec.loader.exec_module(r)
    e = r.Elf(Path(a.elf).read_bytes())
    m = r.Metadata(r.decode_metadata(Path(a.metadata).read_bytes()))
    q = m.methods[318208]
    assert m.type_name(q[1]) == 'UnityEngine.Object'
    assert m.string(q[0]) == 'FindObjectFromInstanceID'
    slot = 0xaf5a718 + ((q[7] & 0xffffff) - 1) * 8
    assert e.pointer(slot) == 0x9ff122c
    # This exact wrapper ends in BR X1. The following registration starts at +0x3c.
    expected = 'fe0f1ef8f44f01a9547e0090810245f9f303002ac10000b5c0cdfbd000d02791538e0d94e10300aa800205f9e003132af44f41a9fe0742f820001fd6'
    body = e.bytes(0x9ff122c, 0x3c)
    assert body.hex() == expected, 'Pinned resolver wrapper bytes changed'
    name = e.bytes(0x19ab9f4, 128).split(b'\0', 1)[0].decode('ascii')
    assert name == 'UnityEngine.Object::FindObjectFromInstanceID(System.Int32)'
    report = dict(audit_version=1, scope='OFFLINE WRAPPER ONLY', elf_sha256=r.ELF_SHA,
                  metadata_sha256=r.META_SHA, method_index=318208, registration_slot_rva=slot,
                  wrapper_rva=0x9ff122c, wrapper_bytes=60, source_hex=body.hex(),
                  internal_call_name=name, internal_call_name_rva=0x19ab9f4,
                  cached_function_cell_rva=0xafb9a00, lookup_call_rva=0x9ff124c,
                  lookup_target_rva=0xa354b98, tail_dispatch_rva=0x9ff1264,
                  behavior=['Loads a cached engine function pointer into X1.',
                            'If the cache is zero, resolves the named internal call and stores its pointer.',
                            'Preserves the Int32 argument and tail-dispatches through X1.'],
                  native_implementation='NOT_RESOLVED', live_cached_pointer='NOT_CAPTURED',
                  lifetime_and_thread_rules='UNVERIFIED', collider_to_player_association='UNVERIFIED',
                  functions_invoked=False, memory_writes=False, head_los_verified=False)
    Path(a.report).write_text(json.dumps(report, indent=2) + '\n')
    print('ObjectIdResolverAudit=PASS WrapperBytes=60 NativeImplementation=UNRESOLVED')


if __name__ == '__main__':
    main()
