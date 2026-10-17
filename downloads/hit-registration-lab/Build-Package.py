"""Rebuild source/evidence/portable-app ZIP after dotnet build -c Release."""
from pathlib import Path
import hashlib,json,zipfile
root=Path(__file__).resolve().parent
files={}
for p in root.rglob('*'):
    rel=p.relative_to(root)
    if p.is_file() and not any(x in ('bin','obj','app','__pycache__') for x in rel.parts) and p.suffix!='.zip':
        files[rel.as_posix()]=p.read_bytes()
for name in ['HitLab.dll','HitLab.deps.json','HitLab.runtimeconfig.json','game.html']:
    files['app/'+name]=(root/'bin/Release/net8.0'/name).read_bytes()
manifest={'scope':'OWNED_LOCAL_LAB_ONLY','files':[{'name':n,'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()} for n,b in sorted(files.items())]}
files['package-manifest.json']=(json.dumps(manifest,indent=2)+'\n').encode()
output=root.parent/'hit-registration-lab.zip'
with zipfile.ZipFile(output,'w',zipfile.ZIP_DEFLATED) as z:
    for name,data in sorted(files.items()):
        info=zipfile.ZipInfo(name,(2026,10,17,0,0,0));info.compress_type=zipfile.ZIP_DEFLATED;info.external_attr=0o100644<<16;z.writestr(info,data)
with zipfile.ZipFile(output) as z:
    assert z.testzip() is None
    for item in manifest['files']:assert hashlib.sha256(z.read(item['name'])).hexdigest()==item['sha256']
print(json.dumps({'archive':output.name,'bytes':output.stat().st_size,'sha256':hashlib.sha256(output.read_bytes()).hexdigest(),'manifest_files':len(manifest['files'])}))
