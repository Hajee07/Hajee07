"""Python translations of FOUR recovered NOVA INTERNAL V2 aim routines.

Translated: dispatcher1800ACFD0, projection180067E80, mode0 worker180073610,
mode1 worker1800731B0. This is not a translation of all151 analysis routines.
Input EXE SHA256: fb70eb9987a6a2f8a728b0eb8664c39458eafe2b566035f71808edfee4c065a0
Original inferred C: https://github.com/Hajee07/Hajee07/tree/apk-downloads/internal-v2-aimbot-code

Python3.10+, standard library only. Explicit Windows HD-Player enumeration,
process attachment and host-memory reads are included below. An explicit
NativeBackend adapter must still supply recovered state and engine operations.
Process attachment alone does not connect the native/game backend.
Addresses below are ANALYSIS addresses. An adapter must map them to its state;
they are not assumed to be usable live addresses under Windows ASLR.

Native cache/address resolution(180067CC0), guest reads(180069360), rotation
helper18006DA10 and engine write callback remain backend dependencies.
The original DLL references BstkVMM.dll exports PGMPhysRead, VMMGetCpuById,
PGMPhysGCPtr2GCPhys and PGMPhysSimpleWriteGCPhys. Their runtime VM/CPU
context and native cached state have not been connected by this Python module.
Host process module bases alone do not establish guest-memory mapping. Types
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


# Windows host process connection. This is separate from the unresolved game backend.
import os
import ctypes
import argparse
import json
from dataclasses import dataclass

_DWORD=ctypes.c_uint32
_LONG=ctypes.c_int32
_WORD=ctypes.c_uint16
_PTR=ctypes.c_void_p
_SIZE=ctypes.c_size_t
_INVALID_HANDLE=ctypes.c_void_p(-1).value

class _PROCESSENTRY32W(ctypes.Structure):
    _fields_=[('dwSize',_DWORD),('cntUsage',_DWORD),('th32ProcessID',_DWORD),
              ('th32DefaultHeapID',_SIZE),('th32ModuleID',_DWORD),('cntThreads',_DWORD),
              ('th32ParentProcessID',_DWORD),('pcPriClassBase',_LONG),('dwFlags',_DWORD),
              ('szExeFile',_WORD*260)]

class _MODULEENTRY32W(ctypes.Structure):
    _fields_=[('dwSize',_DWORD),('th32ModuleID',_DWORD),('th32ProcessID',_DWORD),
              ('GlblcntUsage',_DWORD),('ProccntUsage',_DWORD),('modBaseAddr',_PTR),
              ('modBaseSize',_DWORD),('hModule',_PTR),('szModule',_WORD*256),
              ('szExePath',_WORD*260)]

def _utf16(array):return bytes(array).decode('utf-16-le',errors='replace').split('\0',1)[0]

@dataclass(frozen=True)
class HDPlayerInfo:
    pid:int
    parent_pid:int
    threads:int
    name:str

class _WindowsAPI:
    def __init__(self):
        if os.name!='nt':raise OSError('HD-Player connection requires Windows; run this file on the emulator host')
        if ctypes.sizeof(_PTR)!=8:raise OSError('Use64-bit Python for the64-bit HD-Player host process')
        self.k=ctypes.WinDLL('kernel32',use_last_error=True)
        specs={
            'CreateToolhelp32Snapshot':([_DWORD,_DWORD],_PTR),
            'Process32FirstW':([_PTR,ctypes.POINTER(_PROCESSENTRY32W)],ctypes.c_int),
            'Process32NextW':([_PTR,ctypes.POINTER(_PROCESSENTRY32W)],ctypes.c_int),
            'Module32FirstW':([_PTR,ctypes.POINTER(_MODULEENTRY32W)],ctypes.c_int),
            'Module32NextW':([_PTR,ctypes.POINTER(_MODULEENTRY32W)],ctypes.c_int),
            'OpenProcess':([_DWORD,ctypes.c_int,_DWORD],_PTR),
            'CloseHandle':([_PTR],ctypes.c_int),
            'QueryFullProcessImageNameW':([_PTR,_DWORD,ctypes.c_wchar_p,ctypes.POINTER(_DWORD)],ctypes.c_int),
            'ReadProcessMemory':([_PTR,_PTR,_PTR,_SIZE,ctypes.POINTER(_SIZE)],ctypes.c_int),
            'GetExitCodeProcess':([_PTR,ctypes.POINTER(_DWORD)],ctypes.c_int),
        }
        for name,(args,result) in specs.items():
            f=getattr(self.k,name);f.argtypes=args;f.restype=result
    def error(self,action):
        code=ctypes.get_last_error()
        return OSError(code,f'{action}: {ctypes.FormatError(code).strip()}')
    def snapshot(self,flags,pid=0):
        for attempt in range(3):
            handle=self.k.CreateToolhelp32Snapshot(flags,pid)
            if handle not in (None,0,_INVALID_HANDLE):return handle
            if ctypes.get_last_error()!=24:break  # ERROR_BAD_LENGTH: retry module snapshot
        raise self.error('CreateToolhelp32Snapshot')


def list_hd_players() -> list[HDPlayerInfo]:
    """Discover exact case-insensitive HD-Player.exe matches, including multiple instances."""
    api=_WindowsAPI();snapshot=api.snapshot(0x2);rows=[]
    entry=_PROCESSENTRY32W();entry.dwSize=ctypes.sizeof(entry)
    try:
        ok=api.k.Process32FirstW(snapshot,ctypes.byref(entry))
        if not ok:
            if ctypes.get_last_error()==18:return []
            raise api.error('Process32FirstW')
        while ok:
            name=_utf16(entry.szExeFile)
            if name.casefold()=='hd-player.exe':
                rows.append(HDPlayerInfo(int(entry.th32ProcessID),int(entry.th32ParentProcessID),int(entry.cntThreads),name))
            ok=api.k.Process32NextW(snapshot,ctypes.byref(entry))
        if ctypes.get_last_error()!=18:raise api.error('Process32NextW')
    finally:api.k.CloseHandle(snapshot)
    return sorted(rows,key=lambda r:r.pid)


class HDPlayerProcess:
    """Concrete Windows read-only process handle; NOT the NativeBackend engine adapter.

    read_process_memory() takes a Windows host virtual address. Never pass the
    0x181... analysis addresses from RecoveredAimbot without a verified mapping.
    Android guest addresses, cached node pointers and DLL analysis state are
    distinct address spaces. Opening this handle does not resolve those spaces.
    """
    def __init__(self,pid:int):
        if isinstance(pid,bool) or not isinstance(pid,int) or not(0<pid<=0xffffffff):raise ValueError('Invalid PID')
        self.pid=pid;self._api=_WindowsAPI();self._handle=None
        # PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_VM_READ
        handle=self._api.k.OpenProcess(0x1000|0x10,False,pid)
        if not handle:raise self._api.error(f'OpenProcess PID{pid}')
        self._handle=handle
        try:
            buffer=ctypes.create_unicode_buffer(32768);length=_DWORD(len(buffer))
            if not self._api.k.QueryFullProcessImageNameW(handle,0,buffer,ctypes.byref(length)):
                raise self._api.error('QueryFullProcessImageNameW')
            self.image_path=buffer.value
            if self.image_path.replace('/','\\').rsplit('\\',1)[-1].casefold()!='hd-player.exe':
                raise ValueError('PID is not HD-Player.exe; refusing a different process')
            if not self.is_running():raise ProcessLookupError('HD-Player exited before attachment completed')
        except BaseException:self.close();raise
    @classmethod
    def attach(cls,pid:int|None=None):
        if pid is None:
            choices=list_hd_players()
            if not choices:raise ProcessLookupError('HD-Player.exe not found. Start your BlueStacks/MSI instance first')
            if len(choices)!=1:raise ValueError('Multiple HD-Player instances. Choose --pid from: '+', '.join(str(x.pid) for x in choices))
            pid=choices[0].pid
        return cls(pid)
    def _checked_handle(self):
        if not self._handle:raise OSError('HD-Player process handle is closed')
        return self._handle
    def is_running(self):
        code=_DWORD()
        if not self._api.k.GetExitCodeProcess(self._checked_handle(),ctypes.byref(code)):
            raise self._api.error('GetExitCodeProcess')
        return code.value==259  # STILL_ACTIVE
    def read_process_memory(self,address:int,size:int)->bytes:
        """Read known Windows host addresses. Exact-length reads; partial reads raise."""
        if isinstance(address,bool) or not isinstance(address,int) or not(0<=address<2**64):raise ValueError('Invalid64-bit address')
        if isinstance(size,bool) or not isinstance(size,int) or not(0<=size<=16*1024*1024):raise ValueError('Read size must be0..16MiB')
        if address+size>2**64:raise ValueError('Address range overflow')
        handle=self._checked_handle()
        if size==0:return b''
        buffer=(ctypes.c_ubyte*size)();done=_SIZE()
        ok=self._api.k.ReadProcessMemory(handle,_PTR(address),buffer,size,ctypes.byref(done))
        if not ok:raise self._api.error(f'ReadProcessMemory at{address:#x}')
        if done.value!=size:raise OSError(f'Partial process read: {done.value}/{size}bytes')
        return bytes(buffer)
    def modules(self):
        """List Windows modules; this does not list Android guest shared libraries."""
        self._checked_handle();api=self._api;snapshot=api.snapshot(0x8|0x10,self.pid)
        entry=_MODULEENTRY32W();entry.dwSize=ctypes.sizeof(entry);rows=[]
        try:
            ok=api.k.Module32FirstW(snapshot,ctypes.byref(entry))
            if not ok:
                if ctypes.get_last_error()==18:return []
                raise api.error('Module32FirstW')
            while ok:
                rows.append({'name':_utf16(entry.szModule),'base':hex(entry.modBaseAddr or 0),
                             'size':int(entry.modBaseSize),'path':_utf16(entry.szExePath)})
                ok=api.k.Module32NextW(snapshot,ctypes.byref(entry))
            if ctypes.get_last_error()!=18:raise api.error('Module32NextW')
        finally:api.k.CloseHandle(snapshot)
        return rows
    def close(self):
        handle=self._handle
        if handle:self._handle=None;self._api.k.CloseHandle(handle)
    def __enter__(self):self._checked_handle();return self
    def __exit__(self,*exc):self.close()


def main(argv=None):
    parser=argparse.ArgumentParser(description='Recovered aim logic plus explicit Windows HD-Player process connection')
    action=parser.add_mutually_exclusive_group()
    action.add_argument('--list-hd-player',action='store_true',help='List running HD-Player.exe PIDs')
    action.add_argument('--attach-hd-player',action='store_true',help='Open a query/read handle to HD-Player.exe')
    parser.add_argument('--pid',type=int,help='Select one instance when multiple emulators are running')
    parser.add_argument('--modules',action='store_true',help='Also list Windows modules after attachment')
    args=parser.parse_args(argv)
    if (args.pid is not None or args.modules) and not args.attach_hd_player:
        parser.error('--pid/--modules require --attach-hd-player')
    try:
        if args.list_hd_player:
            print(json.dumps([vars(x) for x in list_hd_players()],indent=2));return 0
        if args.attach_hd_player:
            with HDPlayerProcess.attach(args.pid) as target:
                result={'attached':True,'pid':target.pid,'image':target.image_path,'process_running':target.is_running(),
                        'access':'query/read','native_game_backend_connected':False}
                if args.modules:result['windows_modules']=target.modules()
                print(json.dumps(result,indent=2))
            return 0
        print(__doc__);parser.print_help();return 0
    except (OSError,ValueError) as error:
        print(f'HD-Player connection failed: {error}',file=__import__('sys').stderr);return 1

if __name__=='__main__':
    raise SystemExit(main())
