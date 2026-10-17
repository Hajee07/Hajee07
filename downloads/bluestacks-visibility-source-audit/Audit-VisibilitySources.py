#!/usr/bin/env python3
"""Reproduce bounded, offline visibility-source evidence for the pinned APK only."""
import argparse
import importlib.util
import json
import re
import struct
from pathlib import Path


def branch_target(pc, word):
    if word & 0x7c000000 != 0x14000000:
        return None
    displacement = word & 0x3ffffff
    if displacement & (1 << 25):
        displacement -= 1 << 26
    return pc + displacement * 4


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('elf')
    parser.add_argument('metadata')
    parser.add_argument('report')
    args = parser.parse_args()
    helper = Path(__file__).resolve().parent.parent / 'bluestacks-process-map' / 'Recover-GameLayout.py'
    spec = importlib.util.spec_from_file_location('reference_reader', helper)
    reference = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reference)
    # Both parsers reject files whose complete SHA-256 differs from the reference.
    elf = reference.Elf(Path(args.elf).read_bytes())
    metadata = reference.Metadata(reference.decode_metadata(Path(args.metadata).read_bytes()))
    table = 0xa98efa8
    selected = [(34931, 'COW.GameFacade', 'CheckVisibleByCameraMode', 0x71bec74),
                (210384, 'COW.GamePlay.Player', 'IsVisible', 0x6f38834),
                (210385, 'COW.GamePlay.Player', 'IsVisibleByFlag', 0x6f38888),
                (211257, 'COW.GamePlay.Player', 'CheckVisibleByDis', 0x6fdc124),
                (266312, None, 'op_Implicit', 0x8279898)]
    methods = []
    for index, owner, name, expected in selected:
        record = metadata.methods[index]
        actual_owner = metadata.type_name(record[1])
        if metadata.string(record[0]) != name or (owner is not None and actual_owner != owner):
            raise ValueError('Selected method metadata mismatch')
        pointer_slot = table + ((record[7] & 0xffffff) - 1) * 8
        address = elf.pointer(pointer_slot)
        if address != expected:
            raise ValueError('Selected method registration mismatch')
        following = metadata.methods[index + 1]
        following_slot = table + ((following[7] & 0xffffff) - 1) * 8
        end = elf.pointer(following_slot)
        if not address < end <= address + 4096 or (end - address) % 4:
            raise ValueError('Unsupported source inspection window')
        code = elf.bytes(address, end - address)
        transfers = []
        for offset in range(0, len(code), 4):
            word = struct.unpack_from('<I', code, offset)[0]
            target = branch_target(address + offset, word)
            if target is not None:
                transfers.append({'rva': address + offset, 'kind': 'BL' if word >> 31 else 'B', 'target_rva': target})
        methods.append({'method_index': index, 'owner': actual_owner, 'name': name,
                        'rva': address, 'registration_slot_rva': pointer_slot,
                        'metadata_record_hex': struct.pack('<8i4H', *record).hex(),
                        'window_bytes': len(code), 'window_end_rva': end,
                        'window_bound': 'NEXT_METHOD_IN_METADATA_ORDER; NOT A GENERAL FUNCTION-SIZE ALGORITHM',
                        'source_hex': code.hex(), 'direct_unconditional_transfers': transfers})
    by_name = {row['name']: row for row in methods}
    visible = by_name['IsVisible']
    if visible['window_bytes'] != 0x54 or elf.bytes(0x6f38874, 4).hex() != '606a45f9':
        raise ValueError('Original visibility field load changed')
    if branch_target(0x6f38880, struct.unpack('<I', elf.bytes(0x6f38880, 4))[0]) != 0x8279898:
        raise ValueError('Original visibility conversion target changed')
    conversion = by_name['op_Implicit']
    if conversion['window_bytes'] != 0x34:
        raise ValueError('Unsupported visibility conversion window')
    if elf.bytes(0x71bed34, 4).hex() != '20008052':
        raise ValueError('Camera-mode fallback source changed')
    delegates = []
    for index, owner, name, expected in [(35021, 'COW.GameFacade', 'CurrentCameraModeManager', 0x71be30c),
                                          (217009, 'COW.GamePlay.ICCMOIAKHOE', 'CKHGHGPDGGO', 0x71f2e48),
                                          (266278, 'GCommon.BitArray', 'HasFlag', 0x8279204)]:
        record = metadata.methods[index]
        slot = table + ((record[7] & 0xffffff) - 1) * 8
        if metadata.type_name(record[1]) != owner or metadata.string(record[0]) != name or elf.pointer(slot) != expected:
            raise ValueError('Delegate method registration/metadata mismatch')
        delegates.append({'method_index': index, 'owner': owner, 'name': name, 'rva': expected,
                          'registration_slot_rva': slot, 'scope': 'IDENTITY ONLY; IMPLEMENTATION NOT FULLY EVALUATED'})
    inventory = []
    pattern = re.compile(r'lineofsight|raycast|occlu|isvisible|checkvisible|checkvisibility', re.I)
    owners = {}
    for index, record in enumerate(metadata.methods):
        name = metadata.string(record[0])
        if not pattern.search(name):
            continue
        owner = owners.setdefault(record[1], metadata.type_name(record[1]))
        if owner.startswith(('COW.', 'UnityEngine.')):
            inventory.append({'index': index, 'owner': owner, 'name': name,
                              'argument_count': record[11], 'token': record[7]})
    report = {'audit_version': 1, 'elf_sha256': reference.ELF_SHA,
              'metadata_sha256': reference.META_SHA, 'scope': 'OFFLINE SOURCE EVIDENCE ONLY',
              'functions_invoked': False, 'live_memory_access': False, 'aim_writes': False,
              'methods': methods, 'delegate_identities': delegates, 'name_inventory_count': len(inventory), 'name_inventory': inventory,
              'conclusions': [
                  'Original Player.IsVisible reads Player+0xad0 and tail-calls a stored mask conversion; this is not a verified target-head obstacle query.',
                  'CheckVisibleByCameraMode has a true-return fallback when its selected manager is absent. Its delegated implementation is not established as LOS here.',
                  'Method-name matches include UI, item marking and physics APIs; names alone do not establish gameplay LOS, query origin, target hit, mask or trigger policy.',
                  'Name filtering omits obfuscated methods. This is not an exhaustive call graph or proof that a LOS implementation is absent.',
                  'No live LOS result, combined eligibility, active aiming camera or working aim update is established.'
              ]}
    Path(args.report).write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print('VisibilitySourceAudit=PASS Methods=%d NameCandidates=%d RuntimeLOS=UNVERIFIED' % (len(methods), len(inventory)))


if __name__ == '__main__':
    main()
