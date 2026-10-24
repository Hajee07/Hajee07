"""Apply reviewed, fixed-size patches to the user-supplied local PE only.

This script does not execute Windows code or contact licensing services.
"""
from pathlib import Path
import json,hashlib,struct,sys
SOURCE_HASH='fb70eb9987a6a2f8a728b0eb8664c39458eafe2b566035f71808edfee4c065a0'
ROOT=Path(__file__).resolve().parent

def sha(raw):return hashlib.sha256(raw).hexdigest()

def pe_info(raw):
 assert raw[:2]==b'MZ'
 nt=struct.unpack_from('<I',raw,0x3c)[0]
 assert raw[nt:nt+4]==b'PE\0\0'
 machine,n=struct.unpack_from('<HH',raw,nt+4)
 optional=nt+24;optsize=struct.unpack_from('<H',raw,nt+20)[0]
 assert machine==0x8664 and struct.unpack_from('<H',raw,optional)[0]==0x20b
 sections=[]
 for i in range(n):
  off=optional+optsize+i*40
  name=raw[off:off+8].split(b'\0',1)[0].decode()
  vs,rva,size,ptr=struct.unpack_from('<IIII',raw,off+8)
  assert ptr+size<=len(raw)
  sections.append({'name':name,'rva':rva,'virtual_size':vs,'raw_offset':ptr,'raw_size':size})
 security=struct.unpack_from('<II',raw,optional+112+4*8)
 return {'machine':'x86-64','section_count':n,'sections':sections,'security_directory':list(security)}

def main():
 if len(sys.argv)!=4:raise SystemExit('Usage: python build_no_login.py ORIGINAL.exe PATCHES.json OUTPUT.exe')
 source,manifest,out=map(Path,sys.argv[1:]);original=source.read_bytes()
 assert sha(original)==SOURCE_HASH,'Unexpected original EXE hash'
 config=json.loads(manifest.read_text());raw=bytearray(original);intervals=[];log=[]
 for patch in config['patches']:
  offset=int(patch['outer_file_offset'],0);before=bytes.fromhex(patch['before']);after=bytes.fromhex(patch['after'])
  assert len(before)==len(after)>0
  assert 0<=offset and offset+len(before)<=len(raw)
  assert original[offset:offset+len(before)]==before,patch['name']
  assert not any(offset<end and offset+len(before)>start for start,end in intervals)
  intervals.append((offset,offset+len(before)))
  raw[offset:offset+len(before)]=after
  log.append({**patch,'length':len(before)})
 assert len(raw)==len(original)
 old_pe,new_pe=pe_info(original),pe_info(raw)
 assert old_pe==new_pe,'PE headers unexpectedly changed'
 assert old_pe['security_directory']==[0,0],'Expected unsigned input; signatures require separate review'
 changed=[i for i,(a,b) in enumerate(zip(original,raw)) if a!=b]
 assert all(any(start<=i<end for start,end in intervals) for i in changed)
 out.parent.mkdir(parents=True,exist_ok=True);out.write_bytes(raw)
 report={'source_sha256':sha(original),'output_sha256':sha(raw),'output_bytes':len(raw),
 'patches':log,'changed_bytes':len(changed),'PE_headers_unchanged':True,
 'all_changes_within_reviewed_patch_ranges':True,'Windows_runtime_tested':False,
 'authentication_service_contacted_by_analysis':False}
 out.with_suffix('.validation.json').write_text(json.dumps(report,indent=2)+'\n')
 print(json.dumps({k:v for k,v in report.items() if k!='patches'},indent=2))
if __name__=='__main__':main()
