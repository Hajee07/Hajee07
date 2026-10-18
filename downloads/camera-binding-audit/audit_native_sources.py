"""Verify named Unity registration stubs and record native code evidence, offline."""
import argparse
import hashlib
import importlib.util
import json
import struct
import sys
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
sys.dont_write_bytecode=True
UNITY_SHA='1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77'
BINDINGS=[
 ('get_fieldOfView',0x468954,0xfd182,0x4198d4,0xb839b4),
 ('get_aspect',0x468a94,0x138568,0x41a994,0xb8384c),
 ('get_pixelRect_Injected',0x468c60,0x161e00,0x41c380,0xb78930),
 ('get_worldToCameraMatrix_Injected',0x468cec,0xfd1f7,0x41cb48,0xb797e8),
 ('get_projectionMatrix_Injected',0x468d14,0xd49c3,0x41cd5c,0xb79858)]


def require(ok,label):
    if not ok:raise ValueError(label)


def adrp(word,pc):
    require(word&0x9f000000==0x90000000,'ADRP encoding')
    imm=((word>>5)&0x7ffff)*4+((word>>29)&3)
    if imm&(1<<20):imm-=1<<21
    return (pc&~4095)+imm*4096,word&31


def pair(base,word):
    require(word&0xffc00000==0x91000000 and (word>>5)&31==base[1] and word&31==base[1],'ADD encoding/register')
    return base[0]+((word>>10)&4095)


def transcript(elf,at,size):
    md=Cs(CS_ARCH_ARM64,CS_MODE_ARM)
    raw=elf.bytes(at,size)
    rows=[dict(rva=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in md.disasm(raw,at)]
    require(len(rows)*4==size,'Complete bounded instruction decoding')
    return dict(start_rva=hex(at),bytes=size,sha256=hashlib.sha256(raw).hexdigest(),
                scope='FIXED_CODE_WINDOW_NOT_FUNCTION_BOUNDARY',instructions=rows)


def audit(elf):
    result=[];registrars=set()
    for name,stub,text,target,helper in BINDINGS:
        words=struct.unpack('<5I',elf.bytes(stub,20))
        require(pair(adrp(words[0],stub),words[2])==text,'Registration name address')
        require(pair(adrp(words[1],stub+4),words[3])==target,'Registration target address')
        require(words[0]&31==0 and words[1]&31==1,'Registration argument registers')
        require(words[4]&0xfc000000==0x14000000,'Registration tail branch')
        imm=words[4]&0x3ffffff
        if imm&(1<<25):imm-=1<<26
        registrar=stub+16+imm*4;registrars.add(registrar)
        expected=('UnityEngine.Camera::'+name).encode()+b'\0'
        require(elf.bytes(text,len(expected))==expected,'Exact registered name')
        window=transcript(elf,target,0x140)
        require(any(i['mnemonic']=='bl' and i['operands']=='#'+hex(helper) for i in window['instructions']), 'Expected direct helper call')
        for at in (stub,target,helper):
            require(sum(bool(p[1]&1 and p[3]<=at< p[3]+p[5]) for p in elf.loads)==1,'Executable address')
        result.append(dict(name=name,registration_stub=hex(stub),native_entry=hex(target),
            helper=hex(helper),registrar_branch_target=hex(registrar),
            registration_sha256=hashlib.sha256(elf.bytes(stub,20)).hexdigest(),
            entry_window=window,helper_window=transcript(elf,helper,0x100)))
    require(len(registrars)==1,'Common registrar branch target')
    return dict(scope='PINNED_STATIC_NATIVE_SOURCE_EVIDENCE',unity_sha256=UNITY_SHA,
        bindings=result,live_cache_target_verified=False,native_data_layout_runtime_verified=False,
        projection_values_read=False,functions_invoked=False,aim_writes='NONE',
        limitations=['Fixed disassembly windows are not a complete control-flow or ABI proof.',
        'Registration and static calls do not prove the live selected Camera uses these paths.',
        'Matrix helpers contain conditional update paths; cached bytes need validity and frame checks.',
        'No raw native field is exposed as a live projection/FOV provider.'])


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('unity');p.add_argument('mapper');p.add_argument('output');a=p.parse_args()
    raw=Path(a.unity).read_bytes();require(hashlib.sha256(raw).hexdigest()==UNITY_SHA,'Pinned Unity SHA256')
    spec=importlib.util.spec_from_file_location('mapper',a.mapper)
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.ELF_SHA=UNITY_SHA
    report=audit(m.Elf(raw));Path(a.output).write_text(json.dumps(report,indent=2)+'\n')
    print('NativeSourceAudit=PASS Registrations=5 RuntimeProjection=UNVERIFIED FunctionsInvoked=False')
