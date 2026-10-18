"""Pinned dirty-view arithmetic verification in isolated synthetic ARM64 memory."""
import argparse
import hashlib
import importlib.util
import json
import math
import random
import struct
import sys
from pathlib import Path
from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm64_const import UC_ARM64_REG_CPACR_EL1, UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X8, UC_ARM64_REG_SP, UC_ARM64_REG_LR, UC_ARM64_REG_PC
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
sys.dont_write_bytecode=True
SHA='1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77'
WINDOWS=[('dirty_view',0xb797e8,0x70),('scale_matrix',0xc0eae8,0x54),('matrix_multiply_in_place',0xc0e700,0x34),('matrix_multiply',0x53a844,0x68),('hierarchy_rigid_inverse',0x696884,0x230),('transform_access',0x69304c,0x44),('component_lookup',0x52aeac,0x44)]


def qmul(a,b):
    x,y,z,w=a;X,Y,Z,W=b
    return [w*X+x*W+y*Z-z*Y,w*Y-x*Z+y*W+z*X,w*Z+x*Y-y*X+z*W,w*W-x*X-y*Y-z*Z]


def rotation(q):
    x,y,z,w=q
    return [[1-2*(y*y+z*z),2*(x*y-z*w),2*(x*z+y*w)],
            [2*(x*y+z*w),1-2*(x*x+z*z),2*(y*z-x*w)],
            [2*(x*z-y*w),2*(y*z+x*w),1-2*(x*x+y*y)]]


def derive(records):
    """High precision mathematical model; output is column-major native sequence."""
    if not 1<=len(records)<=32:raise ValueError('Hierarchy bound')
    records=[[[struct.unpack('<f',struct.pack('<f',v))[0] for v in vec] for vec in rec] for rec in records]
    for t,q,s in records:
        if (len(t),len(q),len(s))!=(3,4,3) or not all(math.isfinite(v) for v in t+q+s):raise ValueError('Finite TRS dimensions required')
        if not .98<=sum(v*v for v in q)<=1.02:raise ValueError('Unit quaternion required')
    position,quaternion=records[0][0][:],records[0][1][:]
    for t,q,s in records[1:]:
        r=rotation(q);scaled=[position[k]*s[k] for k in range(3)]
        position=[t[i]+sum(r[i][k]*scaled[k] for k in range(3)) for i in range(3)]
        negative=[math.copysign(1,v)<0 for v in s]
        reflected=[quaternion[i]*(-1 if negative[(i+1)%3]!=negative[(i+2)%3] else 1) for i in range(3)]+[quaternion[3]]
        quaternion=qmul(q,reflected)
    r=rotation(quaternion)
    rigid=[[r[j][i] for j in range(3)]+[-sum(r[j][i]*position[j] for j in range(3))] for i in range(3)]+[[0,0,0,1]]
    view=[[(-1 if i==2 else 1)*v for v in row] for i,row in enumerate(rigid)]
    return [view[row][col] for col in range(4) for row in range(4)]


class SyntheticMachine:
    def __init__(self,elf):
        self.base=0x1000000;self.data=0x8000000;self.stack=0x9000000
        self.uc=Uc(UC_ARCH_ARM64,UC_MODE_ARM)
        end=max(p[3]+p[6] for p in elf.loads)
        self.uc.mem_map(self.base,(end+4095)&~4095)
        for p in elf.loads:self.uc.mem_write(self.base+p[3],elf.data[p[2]:p[2]+p[5]])
        self.uc.mem_map(self.data,0x10000);self.uc.mem_map(self.stack,0x10000)
        self.uc.reg_write(UC_ARM64_REG_CPACR_EL1,0x300000)
        self.uc.hook_add(UC_HOOK_CODE,self.boundary,begin=self.base+0x69304c,end=self.base+0x69304c)
        self.uc.hook_add(UC_HOOK_CODE,self.boundary,begin=self.base+0x52aeac,end=self.base+0x52aeac)
    def boundary(self,uc,address,size,_):
        if address==self.base+0x69304c:
            if uc.reg_read(UC_ARM64_REG_X0)!=self.data+0x300:raise ValueError('Unexpected synthetic Transform')
            uc.reg_write(UC_ARM64_REG_X0,self.data);uc.reg_write(UC_ARM64_REG_X1,0)
        elif address==self.base+0x52aeac:
            if uc.reg_read(UC_ARM64_REG_X0)!=self.data+0x200:raise ValueError('Unexpected synthetic owner')
            uc.reg_write(UC_ARM64_REG_X0,self.data+0x300)
        uc.reg_write(UC_ARM64_REG_PC,uc.reg_read(UC_ARM64_REG_LR))
    def run(self,records):
        if not 1<=len(records)<=32:raise ValueError('Synthetic hierarchy bound')
        uc=self.uc;d=self.data
        uc.mem_write(d,bytes(0x10000));uc.mem_write(self.stack,bytes(0x10000))
        uc.mem_write(d+0x18,struct.pack('<QQ',d+0x3000,d+0x4000))
        uc.mem_write(d+0x130,struct.pack('<Q',d+0x200));uc.mem_write(d+0x616,b'\x01') # Camera=d+0x100, dirty offset=0x516
        for i,(t,q,s) in enumerate(records):
            uc.mem_write(d+0x3000+i*48,struct.pack('<12f',*(t+[0]+q+s+[0])))
            uc.mem_write(d+0x4000+i*4,struct.pack('<i',i+1 if i+1<len(records) else -1))
        uc.reg_write(UC_ARM64_REG_X0,d+0x100);uc.reg_write(UC_ARM64_REG_X8,0)
        uc.reg_write(UC_ARM64_REG_SP,self.stack+0xf000);uc.reg_write(UC_ARM64_REG_LR,d+0xf000)
        uc.emu_start(self.base+0xb797e8,d+0xf000,count=50000)
        if uc.reg_read(UC_ARM64_REG_PC)!=d+0xf000 or uc.reg_read(UC_ARM64_REG_X0)!=d+0x180:raise ValueError('Emulation did not return expected cache pointer')
        return list(struct.unpack('<16f',uc.mem_read(d+0x180,64)))


def cases():
    unit=[0,0,0,1];one=[1,1,1];zero=[0,0,0]
    output=[('identity',[(zero,unit,one)]),('translation',[([1,2,3],unit,one)]),
            ('local_nonuniform_scale_ignored',[([1,2,3],unit,[2,3,4])]),
            ('parent_nonuniform_position',[([1,2,3],unit,one),([4,5,6],unit,[2,3,4])])]
    for axis in range(3):
        q=[0,0,0,math.cos(math.pi/8)];q[axis]=math.sin(math.pi/8)
        output.append(('axis_rotation_'+str(axis),[([1,2,3],q,one)]))
    for mask in range(8):
        sc=[(-1 if mask&(1<<i) else 1)*(i+2) for i in range(3)]
        output.append(('reflection_'+str(mask),[([1,2,3],[.5,.5,.5,.5],one),([4,5,6],unit,sc)]))
    output.append(('negative_zero_parent',[([1,2,3],[.5,.5,.5,.5],one),(zero,unit,[-0.0,1,1])]))
    rng=random.Random(520061)
    for number in range(120):
        rows=[]
        for _ in range(rng.randint(1,8)):
            q=[rng.uniform(-1,1) for _ in range(4)];norm=math.sqrt(sum(v*v for v in q));q=[v/norm for v in q]
            rows.append(([rng.uniform(-10,10) for _ in range(3)],q,[rng.choice([-1,1])*rng.uniform(.5,1.5) for _ in range(3)]))
        output.append(('seeded_'+str(number),rows))
    output.append(('depth_32',[([.1,.2,.3],[0,math.sin(.01),0,math.cos(.01)],one) for _ in range(32)]))
    return output


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('unity');p.add_argument('mapper');p.add_argument('output');a=p.parse_args()
    raw=Path(a.unity).read_bytes()
    if hashlib.sha256(raw).hexdigest()!=SHA:raise ValueError('Pinned Unity SHA256 mismatch')
    spec=importlib.util.spec_from_file_location('mapper',a.mapper);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.ELF_SHA=SHA;elf=m.Elf(raw)
    machine=SyntheticMachine(elf);results=[]
    for name,records in cases():
        expected=derive(records);actual=machine.run(records)
        errors=[abs(x-y) for x,y in zip(expected,actual)]
        passed=all(abs(x-y)<=.001+.0001*abs(x) for x,y in zip(expected,actual))
        if not passed:raise ValueError('Differential mismatch: '+name+' maximum error='+str(max(errors)))
        results.append(dict(name=name,parent_count=len(records)-1,maximum_absolute_error=max(errors),status='PASS'))
    md=Cs(CS_ARCH_ARM64,CS_MODE_ARM);windows=[]
    for name,at,size in WINDOWS:
        blob=elf.bytes(at,size)
        windows.append(dict(name=name,rva=hex(at),bytes=size,sha256=hashlib.sha256(blob).hexdigest(),instructions=[dict(rva=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in md.disasm(blob,at)]))
    report=dict(scope='PINNED_STATIC_TRACE_AND_SYNTHETIC_ARITHMETIC_ONLY',unity_sha256=SHA,
        formula='Z_FLIP * RIGID_INVERSE(world_position, scale_sign_adjusted_world_rotation)',
        native_sequence='COLUMN_MAJOR_FOR_TRACED_ARITHMETIC',absolute_tolerance=.001,relative_tolerance=.0001,
        differential_cases=len(results),results=results,source_windows=windows,
        emulated_boundaries=['Component lookup returns a synthetic Transform','Transform access returns a synthetic clean hierarchy/index'],
        live_game_functions_invoked=False,live_memory_writes=False,synthetic_memory_writes=True,
        live_runtime_integration='NOT_IMPLEMENTED',actual_rendered_camera='UNVERIFIED',frame_alignment='UNVERIFIED')
    Path(a.output).write_text(json.dumps(report,indent=2)+'\n');print('DirtyViewArithmetic=PASS Cases='+str(len(results))+' LiveGetterCalls=0 LiveWrites=0')


if __name__=='__main__':main()
