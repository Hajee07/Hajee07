"""Generate read-only cache-source anchors from the pinned ELF pair."""
import argparse,hashlib,importlib.util,json,struct,sys
from pathlib import Path
sys.dont_write_bytecode=True
p=argparse.ArgumentParser();p.add_argument('il2cpp');p.add_argument('unity');p.add_argument('mapper');p.add_argument('reference');p.add_argument('evidence');a=p.parse_args()
s=importlib.util.spec_from_file_location('mapper',a.mapper);r=importlib.util.module_from_spec(s);s.loader.exec_module(r)
il=r.Elf(Path(a.il2cpp).read_bytes());r.ELF_SHA='1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77';u=r.Elf(Path(a.unity).read_bytes())
def word(e,at):return struct.unpack('<I',e.bytes(at,4))[0]
def need(ok):
 if not ok:raise ValueError('Projection source instruction/profile mismatch')
# Exact clean-cache branch and return paths, dirty offsets, output copy and scalar type.
need(word(u,0xb797f4)==0x39400008+(0x516<<10))
need(word(u,0xb79860)==0x39400008+(0x514<<10))
need(u.bytes(0xb79844,4).hex()=='60020291') # add x0,x19,#0x80
need(u.bytes(0xb79904,4).hex()=='60020391') # add x0,x19,#0xc0
need(u.bytes(0xb79900,4).hex()=='7f521439') # strb wzr,[x19,#0x514]
need(u.bytes(0x71f7d0,12).hex()=='400000b4000840f9c0035fd6')
# Cache slots derive from adrp/ldr in the registered IL2CPP injected wrappers.
cells=[]
for at in (0x9f9f8f4,0x9f9fa2c):
 w,z=word(il,at),word(il,at+4);need(w&0x9f000000==0x90000000 and z&0xffc00000==0xf9400000 and (z>>5)&31==w&31)
 imm=((w>>5)&0x7ffff)*4+((w>>29)&3);imm-=(1<<21) if imm&(1<<20) else 0
 cells.append((at&~4095)+imm*4096+((z>>10)&4095)*8)
need(cells==[0xafb7430,0xafb7440])
def anchors(e,rows):
 return [(name+'_'+str(off),at+off,e.bytes(at+off,min(64,size-off)).hex()) for name,at,size in rows for off in range(0,size,64)]
il_rows=[('view_wrapper',0x9f9f8ec,0x44),('projection_wrapper',0x9f9fa24,0x44)]
u_rows=[('view_registration',0x468cec,20),('projection_registration',0x468d14,20),('view_name',0xfd1f7,len(b'UnityEngine.Camera::get_worldToCameraMatrix_Injected\0')),('projection_name',0xd49c3,len(b'UnityEngine.Camera::get_projectionMatrix_Injected\0')),('view_entry',0x41cb48,0x110),('projection_entry',0x41cd5c,0x110),('cached_native',0x71f7d0,12),('view_helper',0xb797e8,0x70),('projection_helper',0xb79858,0xbc)]
need(u.bytes(0xfd1f7,u_rows[2][2])==b'UnityEngine.Camera::get_worldToCameraMatrix_Injected\0')
need(u.bytes(0xd49c3,u_rows[3][2])==b'UnityEngine.Camera::get_projectionMatrix_Injected\0')
ia,ua=anchors(il,il_rows),anchors(u,u_rows)
da=anchors(u,[('rigid_inverse',0x696884,0x230),('scale_matrix',0xc0eae8,0x54),('multiply_in_place',0xc0e700,0x34),('multiply',0x53a844,0x68),('component_lookup',0x52aeac,0x44),('affine_constant',0x188120,8),('rigid_c0',0x185040,16),('rigid_c1',0x182650,16),('rigid_c2',0x185bc0,16),('rigid_sign',0x1847a0,16),('rigid_c3',0x185840,16),('rigid_c4',0x17ed30,16),('rigid_c5',0x185850,16),('rigid_c6',0x183140,16),('rigid_c7',0x185050,16),('rigid_c8',0x17e9b0,16)])
cs=['// Generated from pinned ELFs; cached native sequence is not render authority.','namespace HeadBridge.Mapping { internal static class PlayerProjectionReference {', 'internal const ulong ViewCacheCell=0xafb7430UL, ProjectionCacheCell=0xafb7440UL;', 'internal const ulong ViewTarget=0x41cb48UL, ProjectionTarget=0x41cd5cUL;', 'internal const ulong ViewOffset=0x80UL, ProjectionOffset=0xc0UL, ViewDirtyOffset=0x516UL, ProjectionDirtyOffset=0x514UL;']
for label,values in [('Il2CppAnchors',ia),('UnityAnchors',ua),('DerivationAnchors',da)]:
 cs.append('internal static readonly GameLayoutCheck[] '+label+'=new GameLayoutCheck[]{')
 cs.extend('new GameLayoutCheck("%s",0x%xUL,"%s"),'%v for v in values);cs.append('};')
cs.append('} }');Path(a.reference).write_text('\n'.join(cs)+'\n')
Path(a.evidence).write_text(json.dumps(dict(scope='CLEAN_NATIVE_CACHE_SEQUENCE_ONLY',view_cache_cell=hex(cells[0]),projection_cache_cell=hex(cells[1]),native_sequence_layout='UNVERIFIED',runtime_validation='PENDING',game_functions_invoked=False,il2cpp_anchors=ia,unity_anchors=ua,derivation_anchors=da),indent=2)+'\n')
print('ProjectionReference=GENERATED StaticSource=PINNED Runtime=UNVERIFIED')
