"""Pinned ARM64 wrapper audit. No binary loading or runtime process access."""
import argparse
import hashlib
import importlib.util
import json
import re
import sys
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
sys.dont_write_bytecode = True
SHA = '549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657'
TARGETS = {
    'get_fieldOfView': 0x9f9e920,
    'get_aspect': 0x9f9ed48,
    'get_pixelRect_Injected': 0x9f9f658,
    'get_worldToCameraMatrix_Injected': 0x9f9f8ec,
    'get_projectionMatrix_Injected': 0x9f9fa24,
}


def audit(elf):
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    results = []
    for name, address in TARGETS.items():
        instructions = []
        for inst in decoder.disasm(elf.bytes(address, 96), address):
            instructions.append(inst)
            if inst.mnemonic in ('br', 'ret'):
                break
        text = [(i.mnemonic, i.op_str) for i in instructions]
        if not instructions or text[-1][0] != 'br':
            raise ValueError('Expected bounded tail-call wrapper: '+name)
        loads, stores, names, calls = [], [], [], []
        for a, b in zip(instructions, instructions[1:]):
            page = re.fullmatch(r'(x\d+), #0x([0-9a-f]+)', a.op_str)
            if a.mnemonic != 'adrp' or not page:
                continue
            reg, base = page[1], int(page[2],16)
            load = re.fullmatch(r'(x\d+), \['+reg+r', #0x([0-9a-f]+)\]', b.op_str)
            if b.mnemonic == 'ldr' and load:
                loads.append((base+int(load[2],16), load[1], reg, load[2]))
            add = re.fullmatch(reg+r', '+reg+r', #0x([0-9a-f]+)', b.op_str)
            if reg == 'x0' and b.mnemonic == 'add' and add:
                at = base+int(add[1],16)
                raw = elf.bytes(at, 32)
                names.append((at,raw.hex()))
        for i in instructions:
            if i.mnemonic == 'str': stores.append(i.op_str)
            if i.mnemonic == 'bl': calls.append(i.op_str)
        if len(loads)!=1 or len(names)!=1 or calls!=['#0xa354b98']:
            raise ValueError('Unexpected binding pattern: '+name)
        cell, target, reg, offset = loads[0]
        if text[-1][1]!=target or f'x0, [{reg}, #0x{offset}]' not in stores:
            raise ValueError('Cache load/store/tail target mismatch: '+name)
        results.append(dict(method=name, wrapper_rva=hex(address),
            cache_cell_rva=hex(cell), resolver_argument_rva=hex(names[0][0]),
            resolver_argument_prefix_hex=names[0][1], resolver_argument_text='UNVERIFIED', resolver_call_rva='0xa354b98',
            wrapper_sha256=hashlib.sha256(elf.bytes(address,len(instructions)*4)).hexdigest(),
            interpretation='FUNCTION_POINTER_CACHE_NOT_CAMERA_DATA',
            instructions=[dict(rva=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in instructions]))
    return dict(scope='STATIC_WRAPPER_BINDING_PATTERN_ONLY', il2cpp_sha256=SHA,
        bindings=results, functions_invoked=False, native_data_layout='UNVERIFIED',
        live_cache_targets='NOT_READ', projection_values='NOT_READ',
        actual_rendered_camera='UNVERIFIED', aim_writes='NONE')


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('il2cpp'); p.add_argument('mapper'); p.add_argument('output')
    args=p.parse_args()
    blob=Path(args.il2cpp).read_bytes()
    if hashlib.sha256(blob).hexdigest()!=SHA:
        raise ValueError('Pinned input SHA256 mismatch')
    spec=importlib.util.spec_from_file_location('mapper',args.mapper)
    module=importlib.util.module_from_spec(spec); spec.loader.exec_module(module)
    report=audit(module.Elf(blob))
    Path(args.output).write_text(json.dumps(report,indent=2)+'\n')
    print('StaticBindings=PASS Count=5 NativeDataLayout=UNVERIFIED FunctionsInvoked=False')
