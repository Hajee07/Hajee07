#!/usr/bin/env python3
"""Static inventory from pinned files; no runtime calls, field guesses or camera authority."""
import argparse,hashlib,importlib.util,json,struct,sys
sys.dont_write_bytecode=True
from pathlib import Path
p=argparse.ArgumentParser();p.add_argument('il2cpp');p.add_argument('metadata');p.add_argument('unity');p.add_argument('output');p.add_argument('--runtime-directory');args=p.parse_args()
root=Path(__file__).resolve().parent
runtime=Path(args.runtime_directory) if args.runtime_directory else root/'baseline'
if not runtime.exists():runtime=root.parent/'bluestacks-process-map'
spec=importlib.util.spec_from_file_location('camera_layout',runtime/'Recover-GameLayout.py');r=importlib.util.module_from_spec(spec);spec.loader.exec_module(r)
il_bytes=Path(args.il2cpp).read_bytes();meta_bytes=Path(args.metadata).read_bytes();unity_bytes=Path(args.unity).read_bytes()
assert hashlib.sha256(il_bytes).hexdigest()==r.ELF_SHA
assert hashlib.sha256(meta_bytes).hexdigest()==r.META_SHA
unity_sha='1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77';assert hashlib.sha256(unity_bytes).hexdigest()==unity_sha
il=r.Elf(il_bytes);m=r.Metadata(r.decode_metadata(meta_bytes));r.ELF_SHA=unity_sha;unity=r.Elf(unity_bytes)
assert m.type_name(40830)=='UnityEngine.Camera'
module=0xa729470;name=il.pointer(module);table=il.pointer(module+16);count=struct.unpack('<Q',il.bytes(module+8,8))[0]
assert il.bytes(name,27)==b'UnityEngine.CoreModule.dll\0' and table==0xaf5a718 and count==4752
names={'get_fieldOfView','get_aspect','get_projectionMatrix','get_projectionMatrix_Injected','get_worldToCameraMatrix','get_worldToCameraMatrix_Injected','get_pixelRect','get_pixelRect_Injected','get_pixelWidth','get_pixelHeight','WorldToScreenPoint','WorldToScreenPoint_Injected','get_nearClipPlane','get_farClipPlane','get_orthographic','get_orthographicSize'}
methods=[]
for i,q in enumerate(m.methods):
 if q[1]!=40830 or m.string(q[0]) not in names:continue
 name=m.string(q[0]);token=q[7];slot=(token&0xffffff)-1
 assert token>>24==6 and 0<=slot<count
 pointer=table+slot*8;address=il.pointer(pointer)
 methods.append(dict(index=i,name=name,parameter_count=q[11],metadata_token=hex(token),pointer_slot_rva=hex(pointer),registered_method_rva=hex(address),code_prefix_hex=il.bytes(address,32).hex() if address else None))
assert {'get_fieldOfView','get_projectionMatrix','get_worldToCameraMatrix','get_pixelRect'}<=set(x['name'] for x in methods)
strings=[]
for name in sorted(names):
 prefix=('UnityEngine.Camera::'+name).encode();start=0
 while True:
  at=unity_bytes.find(prefix,start)
  if at<0:break
  end=unity_bytes.find(b'\0',at,at+256)
  if end>=0:
   raw=unity_bytes[at:end]
   if all(32<=v<127 for v in raw):strings.append(dict(name=raw.decode(),file_offset=hex(at),rva=hex(unity.rva(at))))
  start=at+len(prefix)
report=dict(scope='PINNED_STATIC_REGISTRATION_AND_NAME_INVENTORY_ONLY',il2cpp_sha256=hashlib.sha256(il_bytes).hexdigest(),metadata_sha256=hashlib.sha256(meta_bytes).hexdigest(),unity_sha256=unity_sha,camera_type_index=40830,methods=methods,native_name_strings=strings,projection_values_read=False,fov_values_read=False,native_field_layout_verified=False,functions_invoked=False,actual_rendered_camera='UNVERIFIED',limitations=['A registered getter/name string does not establish a safe native data layout.','No getter, injected call, resolver or class initializer is executed.','No matrix is read from a guessed offset. Runtime binding and frame alignment are separate evidence gates.'])
Path(args.output).write_text(json.dumps(report,indent=2)+'\n');print('ProjectionAudit=STATIC_ONLY Methods='+str(len(methods))+' NativeNames='+str(len(strings))+' FieldLayout=UNVERIFIED')
