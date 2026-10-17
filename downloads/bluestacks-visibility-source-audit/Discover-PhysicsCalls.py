#!/usr/bin/env python3
"""Discover offline direct physics-raycast transfer candidates for the exact APK."""
import argparse
import importlib.util
import struct
import json
import bisect
from pathlib import Path


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('elf');parser.add_argument('metadata');parser.add_argument('report')
    args=parser.parse_args()
    helper=Path(__file__).resolve().parent.parent/'bluestacks-process-map'/'Recover-GameLayout.py'
    spec=importlib.util.spec_from_file_location('reference_reader',helper)
    r=importlib.util.module_from_spec(spec);spec.loader.exec_module(r)
    e=r.Elf(Path(args.elf).read_bytes())
    m=r.Metadata(r.decode_metadata(Path(args.metadata).read_bytes()))
    name=b'UnityEngine.PhysicsModule.dll\0';at=e.data.find(name);assert at>=0;name_rva=e.rva(at);possible=[]
    for slot,target in e.relocations.items():
     if target==name_rva:
      try:
       count=struct.unpack('<I',e.bytes(slot+8,4))[0];table=e.pointer(slot+16)
       if 10<count<10000 and table>0:possible.append((slot,count,table))
      except ValueError:pass
    assert len(possible)==1,possible
    module,count,table=possible[0];physics=[]
    image=next(im for im in m.images if m.string(im[0])=='UnityEngine.PhysicsModule.dll')
    for i,q in enumerate(m.methods):
     if not image[2]<=q[1]<image[2]+image[3]:continue
     owner=m.type_name(q[1]);name=m.string(q[0])
     if owner not in ('UnityEngine.Physics','UnityEngine.PhysicsScene') or 'Raycast' not in name:continue
     slot=table+((q[7]&0xffffff)-1)*8;rv=e.pointer(slot)
     physics.append(dict(index=i,owner=owner,name=name,rva=rv,argument_count=q[11],registration_slot_rva=slot))
    cppimage=next(im for im in m.images if m.string(im[0])=='Assembly-CSharp.dll');cpp=[];addresses={}
    for i,q in enumerate(m.methods):
     if not cppimage[2]<=q[1]<cppimage[2]+cppimage[3]:continue
     slot=0xa98efa8+((q[7]&0xffffff)-1)*8;rv=e.pointer(slot)
     if rv:addresses.setdefault(rv,[]).append(i)
    starts=sorted(addresses);wanted={x['rva'] for x in physics if x['rva']};hits=[]
    for segment in e.loads:
     if not segment[1]&1:continue
     offset,base,size=segment[2],segment[3],segment[5]
     for index,(word,) in enumerate(struct.iter_unpack('<I',e.data[offset:offset+(size//4)*4])):
      if word&0x7c000000!=0x14000000:continue
      imm=word&0x3ffffff
      if imm&(1<<25):imm-=1<<26
      pc=base+index*4;target=pc+imm*4
      if target not in wanted:continue
      at=bisect.bisect_right(starts,pc)-1;nearest=starts[at] if at>=0 else None
      methods=[]
      if nearest is not None:
       for mi in addresses[nearest]:
        q=m.methods[mi];methods.append(dict(index=mi,owner=m.type_name(q[1]),name=m.string(q[0]),rva=nearest))
      hits.append(dict(callsite_rva=pc,target_rva=target,kind='BL' if word>>31 else 'B',nearest_registered_csharp_methods=methods))
    
    primary = []
    for index in [34931,217009,210743,211220,211221]:
     q=m.methods[index];slot=0xa98efa8+((q[7]&0xffffff)-1)*8;address=e.pointer(slot)
     next_q=m.methods[index+1];end=e.pointer(0xa98efa8+((next_q[7]&0xffffff)-1)*8)
     if not address<end<=address+16384 or (end-address)%4:raise ValueError('Unsupported primary source window')
     params=[]
     for j in range(q[11]):
      parameter=m.parameters[q[4]+j];descriptor=e.pointer(0xa64d6f0+parameter[2]*8);data,bits=struct.unpack('<QI',e.bytes(descriptor,12));kind=bits>>16&255
      params.append(dict(name=m.string(parameter[0]),kind=kind,type_name=m.type_name(data) if kind in (17,18) else None))
     transfers=[h for h in hits if address<=h['callsite_rva']<end]
     primary.append(dict(index=index,owner=m.type_name(q[1]),name=m.string(q[0]),rva=address,window_end_rva=end,window_bytes=end-address,
                         source_hex=e.bytes(address,end-address).hex(),parameters=params,direct_raycast_transfers_in_window=transfers,
                         scope='PINNED SOURCE WINDOW TO NEXT METADATA-ORDER METHOD; NOT A GENERAL FUNCTION-SIZE ALGORITHM'))
    report=dict(audit_version=1,elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,
                physics_module=dict(rva=module,method_count=count,table_rva=table),physics_raycast_methods=physics,
                direct_transfer_candidates=hits,primary_source_windows=primary,
                scope='OFFLINE DIRECT B/BL CANDIDATES ONLY; NEAREST REGISTERED METHOD IS NOT PROVEN OWNERSHIP OR LOS SEMANTICS',
                functions_invoked=False,live_memory_access=False,aim_writes=False,
                limitations=['Executable-load scanning can include literal/data words, and nearest CSharp registration can belong to another image or shared/generic method.',
                             'Primary windows establish only byte/registration context for these pinned cases; aliases, indirect calls and nested implementations remain unresolved.',
                             'No cached head-LOS result, query policy, closest target association, live scene validity or working aim control is established.'])
    Path(args.report).write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print('PhysicsCallAudit=PASS Bindings=%d TransferCandidates=%d PrimaryWindows=%d RuntimeLOS=UNVERIFIED'%(len(physics),len(hits),len(primary)))


if __name__=='__main__':
    main()
