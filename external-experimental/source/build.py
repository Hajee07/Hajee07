"""Linux/WSL rebuild recipe; requires Zig0.13.0, GNU objcopy, Python3.
Original Windows EXE is input data only and is never executed by this script.
"""
from pathlib import Path
import argparse,hashlib,os,subprocess,shutil,json
p=argparse.ArgumentParser();p.add_argument('--original-exe',type=Path,required=True);p.add_argument('--zig',required=True);p.add_argument('--output-dir',type=Path,default=Path('build'));a=p.parse_args()
root=Path(__file__).resolve().parent;out=a.output_dir.resolve();out.mkdir(parents=True,exist_ok=True)
raw=a.original_exe.read_bytes();assert hashlib.sha256(raw).hexdigest()=='fb70eb9987a6a2f8a728b0eb8664c39458eafe2b566035f71808edfee4c065a0','Unexpected original EXE'
engine=bytearray(raw[0xa59968:0xa59968+28582400]);assert hashlib.sha256(engine).hexdigest()=='c7a2d29ba5a9a01376ee78d0b91693794a39c9f1847309c9c561b946410035af'
for offset,before,after in [(0xb0b58,'e8f3b00800','9090909090'),(0xb2816,'0f85ba070000','e9bb07000090')]:
 old=bytes.fromhex(before);assert engine[offset:offset+len(old)]==old;engine[offset:offset+len(old)]=bytes.fromhex(after)
provenance=json.loads((root.parent/'ENGINE-PROVENANCE.json').read_text())
for patch in provenance['kernel32_import_redirects']:
 offset=int(patch['file_offset'],0);before=bytes.fromhex(patch['original']);after=bytes.fromhex(patch['replacement'])
 assert engine[offset:offset+len(before)]==before;engine[offset:offset+len(before)]=after
assert hashlib.sha256(engine).hexdigest()==provenance['external_host_engine_sha256']
(out/'engine.bin').write_bytes(engine)
env=os.environ.copy();env['ZIG_GLOBAL_CACHE_DIR']=str(out/'zig-global-cache');env['ZIG_LOCAL_CACHE_DIR']=str(out/'zig-local-cache')
def run(args):subprocess.run(args,cwd=out,env=env,check=True)
flags=['-target','x86_64-windows-gnu','-O1','-Wall','-Wextra','-Werror']
run([a.zig,'cc',*flags,'-shared',str(root/'proxy.c'),str(root/'vmm_core.c'),str(root/'proxy.def'),'-o','BstkVMM.dll'])
shutil.copy2(out/'BstkVMM.dll',out/'proxy.bin')
for source,target in [('engine.bin','engine_payload.o'),('proxy.bin','proxy_payload.o')]:run(['objcopy','-I','binary','-O','pe-x86-64','-B','i386:x86-64',source,target])
run([a.zig,'cc',*flags,str(root/'host.c'),'engine_payload.o','proxy_payload.o','-lbcrypt','-luser32','-o','NOVA-External-Experimental.exe'])
print('Built',out/'NOVA-External-Experimental.exe')
