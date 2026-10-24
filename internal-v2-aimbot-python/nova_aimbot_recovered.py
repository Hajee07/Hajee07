"""Python translations of FOUR recovered NOVA INTERNAL V2 aim routines.

Translated: dispatcher1800ACFD0, projection180067E80, mode0 worker180073610,
mode1 worker1800731B0. This is not a translation of all151 analysis routines.
Input EXE SHA256: fb70eb9987a6a2f8a728b0eb8664c39458eafe2b566035f71808edfee4c065a0
Original inferred C: https://github.com/Hajee07/Hajee07/tree/apk-downloads/internal-v2-aimbot-code

Python3.10+, standard library only. No automatic process attachment, Windows
injection or game connection is implemented. An explicit NativeBackend adapter
must supply recovered native state, key state and unresolved engine operations.
Addresses below are ANALYSIS addresses. An adapter must map them to its state;
they are not assumed to be usable live addresses under Windows ASLR.

Native cache/address resolution(180067CC0), guest reads(180069360), rotation
helper18006DA10 and engine write callback remain backend dependencies. Types
and field meanings are inferred. Backend method contracts are Python adapters,
not claims about original C++ class names or exact native ABI signatures.

Mode0 deliberately has no extra FOV limit/ignore-bots filter: these conditions
are absent from its recovered branch. Mode1 has both. Projection accepts pixel
coordinates>=1.0, preserving the actual constant, rather than inventing>=0.
Linked-list iteration has an explicit Python safety limit/cycle check.
No original-source identity, live runtime behavior or complete app is claimed.
"""
from __future__ import annotations
from typing import Protocol
import math
import struct

class NativeBackendRequired(RuntimeError):
    pass

class NativeBackend(Protocol):
    def read(self, analysis_address: int, size: int) -> bytes:
        """Read recovered state/cache bytes; map analysis addresses explicitly."""
        ...
    def write(self, analysis_address: int, data: bytes) -> None:
        """Write recovered state bytes; used by the mode dispatcher."""
        ...
    def get_async_key_state(self, virtual_key: int) -> int:
        """Equivalent return bits to Windows GetAsyncKeyState, signed or unsigned16."""
        ...
    def read_guest_u32(self, guest_address: int) -> int:
        """Adapter for180069360 including its original resolve/read behavior."""
        ...
    def resolve_guest_address(self, guest_address: int) -> int | None:
        """Adapter for180067CC0: resolved address, or None on failure."""
        ...
    def write_resolved(self, resolved_address: int, data: bytes) -> None:
        """Adapter for engine callback*_DAT_181B4EFA8 using its engine context."""
        ...
    def rotation_18006da10(self, direction: tuple[float,float,float],
                         up: tuple[float,float,float]) -> bytes:
        """Return the first16 native output bytes. Algorithm is NOT guessed here."""
        ...


def f32(value: float | int) -> float:
    try:
        return struct.unpack('<f',struct.pack('<f',float(value)))[0]
    except OverflowError:
        return math.copysign(math.inf,value)

def add(a: float,b: float) -> float:return f32(a+b)
def sub(a: float,b: float) -> float:return f32(a-b)
def mul(a: float,b: float) -> float:return f32(a*b)
def div(a: float,b: float) -> float:
    if math.isnan(a) or math.isnan(b):return math.nan
    if b==0:
        if a==0:return math.nan
        return math.copysign(math.inf,math.copysign(1,a)*math.copysign(1,b))
    return f32(a/b)
def sqrt_native(value: float) -> float:
    # Native sqrt/sqrtf returns NaN for negative input under normal MSVCRT mode.
    return math.sqrt(value) if value>=0 else math.nan

def projection_180067e80(matrix, position, width: int, height: int):
    """Recovered float32 world-to-screen routine; returns(x,y), default(-1,-1).

    Constants0x181A03124=0.01f and0x181A031BC=0.5f were read from original PE.
    Non-default floating-point environment/rounding exceptions are not modeled.
    """
    width=struct.unpack('<i',struct.pack('<I',width&0xffffffff))[0]
    height=struct.unpack('<i',struct.pack('<I',height&0xffffffff))[0]
    if width<=0 or height<=0:return(-1.0,-1.0)
    if len(matrix)!=16 or len(position)!=3:raise ValueError('16 matrix and3 position floats required')
    m=tuple(map(f32,matrix));x,y,z=map(f32,position)
    w=add(add(add(mul(y,m[7]),mul(x,m[3])),mul(z,m[11])),m[15])
    if not f32(0.01)<=w:return(-1.0,-1.0)
    half_h=mul(f32(height),0.5)
    clip_x=add(add(add(mul(y,m[4]),mul(x,m[0])),mul(z,m[8])),m[12])
    clip_y=add(add(add(mul(x,m[1]),mul(y,m[5])),mul(z,m[9])),m[13])
    screen_x=add(div(mul(mul(clip_x,f32(width)),0.5),w),mul(f32(width),0.5))
    screen_y=sub(half_h,div(mul(clip_y,half_h),w))
    return(screen_x,screen_y)


class RecoveredAimbot:
    """One step of each recovered aim worker; scheduling is an external dependency."""
    def __init__(self, backend: NativeBackend | None = None, *, max_nodes=100000):
        if backend is None:raise NativeBackendRequired('Supply a NativeBackend; no live game backend is bundled')
        self.b=backend;self.max_nodes=max_nodes
    def raw(self,address,size):
        data=self.b.read(address,size)
        if len(data)!=size:raise ValueError(f'Short backend read at{address:#x}')
        return data
    def u8(self,a):return self.raw(a,1)[0]
    def u32(self,a):return struct.unpack('<I',self.raw(a,4))[0]
    def i32(self,a):return struct.unpack('<i',self.raw(a,4))[0]
    def u64(self,a):return struct.unpack('<Q',self.raw(a,8))[0]
    def float(self,a):return struct.unpack('<f',self.raw(a,4))[0]
    def vec3(self,a):return struct.unpack('<fff',self.raw(a,12))
    def down(self,key):return bool(self.b.get_async_key_state(key)&0x8000)

    def dispatcher_1800acfd0(self):
        """Exact visible toggle/mode writes, including word clear atB2B430."""
        previous=self.u8(0x181b2f8c9)
        self.b.write(0x181b2b403,b'\0')
        self.b.write(0x181b2b430,b'\0\0')
        self.b.write(0x181b2f8c9,bytes([int(previous==0)]))
        self.b.write(0x181b2b432,b'\0')
        if previous==0:
            mode=self.i32(0x181b30424)
            flag={0:0x181b2b403,1:0x181b2b430,3:0x181b2b432}.get(mode)
            if flag is not None:self.b.write(flag,b'\1')
        # Index2 is not filled with an invented internal mode.

    def nodes(self,head):
        node=self.u64(head);seen=set()
        while node!=head:
            if node in seen or len(seen)>=self.max_nodes:
                raise ValueError('Malformed/oversized native list; explicit Python safety adaptation')
            seen.add(node);yield node;node=self.u64(node)

    def _select(self,mode):
        """Preserve distinct mode0/mode1 filters and float comparison order."""
        width=self.i32(0x181b2bec8);height=self.i32(0x181b2becc)
        origin=self.vec3(0x181b2beb0)
        head=self.u64(0x181b2be38)
        maximum_distance=f32(self.i32(0x181b2b40c))
        ignore_knocked=self.u8(0x181b2b406)
        ignore_bots=self.u8(0x181b2b407) if mode==1 else 0
        fov=self.float(0x181b2b410) if mode==1 else None
        matrix=struct.unpack('<16f',self.raw(0x181b2be70,64))
        center_x=mul(f32(width),0.5);center_y=mul(f32(height),0.5)
        best=f32(3.4028234663852886e38);selected=None
        for node in self.nodes(head):
            if self.u8(node+0x1a):continue
            if ignore_knocked and self.u8(node+0x1b):continue
            if ignore_bots and self.u8(node+0x18):continue
            position=self.vec3(node+0xa0)
            x,y=projection_180067e80(matrix,position,width,height)
            if not(1.0<=x and 1.0<=y):continue
            dx=sub(origin[0],position[0]);dy=sub(origin[1],position[1]);dz=sub(origin[2],position[2])
            # Native order: y*y+x*x+z*z, with scalar float32 operations.
            distance=f32(sqrt_native(add(add(mul(dy,dy),mul(dx,dx)),mul(dz,dz))))
            if not distance<=maximum_distance:continue
            sx=sub(x,center_x);sy=sub(y,center_y)
            # Native pow(double,2.0) and sqrt(double); result converted tofloat.
            try:score=f32(sqrt_native(math.pow(float(sy),2.0)+math.pow(float(sx),2.0)))
            except OverflowError:score=math.inf
            if mode==1 and not score<=fov:continue
            if score<best:selected=node;best=score
        return selected

    def _copy_target_value(self,node):
        entity=self.u32(node+0x9c)
        if entity==0:return
        value=self.b.read_guest_u32(entity+0x4e8)&0xffffffff
        if value==0:return
        resolved=self.b.resolve_guest_address(entity+0x54)
        if resolved is not None:self.b.write_resolved(resolved,struct.pack('<I',value))

    def worker_mode0_180073610(self):
        """Recovered mode0 branch; returns None as the native void routine does."""
        if not self.u8(0x181b2b403):return
        if not self.down(self.i32(0x181b2b414)):return
        node=self._select(0)
        if node is not None:self._copy_target_value(node)

    def worker_mode1_1800731b0(self):
        """Recovered mode1 branch; requires the unresolved native rotation helper."""
        if not self.u8(0x181b2b430):return
        if not self.down(1):return
        node=self._select(1)
        if node is None or self.u32(node+0x9c)==0:return
        position=self.vec3(node+0xa0);origin=self.vec3(0x181b2beb0)
        direction=tuple(sub(add(v,0.0),o) for v,o in zip(position,origin))
        rotation=self.b.rotation_18006da10(direction,(0.0,1.0,0.0))
        if len(rotation)<16:raise ValueError('Native rotation adapter must supply at least16 output bytes')
        resolved=self.b.resolve_guest_address(self.u32(0x181b2bebc)+0x440)
        if resolved is not None:self.b.write_resolved(resolved,rotation[:16])
        self._copy_target_value(node)


if __name__=='__main__':
    print(__doc__)
    print('Available: projection_180067e80, RecoveredAimbot.dispatcher_1800acfd0,')
    print('RecoveredAimbot.worker_mode0_180073610, worker_mode1_1800731b0.')
    print('No game is attached. Supply a NativeBackend to call stateful routines.')
