#!/usr/bin/env python3
"""Build exact offline query/layout evidence; no live cache or physics access."""
import argparse
import importlib.util
import json
import struct
from pathlib import Path


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('elf');parser.add_argument('metadata');parser.add_argument('report')
    args=parser.parse_args()
    helper=Path(__file__).resolve().parent.parent/'bluestacks-process-map'/'Recover-GameLayout.py'
    spec=importlib.util.spec_from_file_location('reference_reader',helper)
    r=importlib.util.module_from_spec(spec);spec.loader.exec_module(r)
    e=r.Elf(Path(args.elf).read_bytes());m=r.Metadata(r.decode_metadata(Path(args.metadata).read_bytes()))
    def descriptor(index):
        address=e.pointer(0xa64d6f0+index*8);data,bits=struct.unpack('<QI',e.bytes(address,12));kind=bits>>16&255
        return dict(rva=address,bits=bits,kind=kind,data=data,type_name=m.type_name(data) if kind in (17,18) else None)
    def field(owner,local):
        q=m.fields[m.types[owner][8]+local];slot=e.pointer(0xa8cfec0+owner*8)+local*4
        word=struct.unpack('<I',e.bytes(slot,4))[0]
        return dict(owner=owner,local=local,name=m.string(q[0]),registration_word=word,
                    source_offset_candidate=word if word<0x100000 else None,
                    offset_status='SOURCE_REGISTRATION_ONLY' if word<0x100000 else 'UNINTERPRETED_REGISTRATION_MARKER',
                    live_offset_verified=False,offset_registration_rva=slot,descriptor=descriptor(q[1]),metadata_record_hex=struct.pack('<iiI',*q).hex())
    def method(index,table,window=None):
        q=m.methods[index];slot=table+((q[7]&0xffffff)-1)*8;address=e.pointer(slot)
        if window is None:
            next_q=m.methods[index+1];end=e.pointer(table+((next_q[7]&0xffffff)-1)*8)
            window=end-address
        if not 0<window<=4096 or window%4:raise ValueError('Unsupported method source window')
        params=[]
        for j in range(q[11]):
            p=m.parameters[q[4]+j];params.append(dict(name=m.string(p[0]),descriptor=descriptor(p[2])))
        return dict(index=index,owner=m.type_name(q[1]),name=m.string(q[0]),rva=address,registration_slot_rva=slot,
                    return_descriptor=descriptor(q[2]),parameters=params,source_hex=e.bytes(address,window).hex(),window_bytes=window,
                    source_bound='PINNED INSPECTED WINDOW; NOT A GENERAL FUNCTION-SIZE ALGORITHM',metadata_record_hex=struct.pack('<8i4H',*q).hex())
    # Resolve the module through its exact name and relocation-backed registration.
    name=b'UnityEngine.PhysicsModule.dll\0';at=e.data.find(name);name_rva=e.rva(at)
    modules=[]
    for slot,target in e.relocations.items():
        if target==name_rva and struct.unpack('<I',e.bytes(slot+8,4))[0]==508:modules.append(slot)
    if len(modules)!=1:raise ValueError('PhysicsModule registration mismatch')
    physics_table=e.pointer(modules[0]+16)
    methods=[method(332884,physics_table),method(210965,0xa98efa8,0x200),method(333307,physics_table,0x40)]
    if methods[0]['rva']!=0xa0481fc or methods[0]['name']!='Raycast' or methods[1]['rva']!=0x6f99220:
        raise ValueError('Query/cache method identity mismatch')
    if [p['name'] for p in methods[0]['parameters']]!=['origin','direction','hitInfo','maxDistance','layerMask']:
        raise ValueError('Raycast argument contract mismatch')
    for index,q in enumerate(m.methods):
        if q[1]==43049 and m.string(q[0]) in ('get_collider','get_point','get_normal'):
            methods.append(method(index,physics_table))
    scene=methods[2]
    scene['source_bound']='PARTIAL 64-BYTE PREFIX ONLY; BODY NOT FULLY EVALUATED'
    if scene['rva']!=0xa047d4c or len(scene['parameters'])!=6:raise ValueError('PhysicsScene query contract changed')
    trigger=scene['parameters'][-1]['descriptor']
    if trigger['type_name']!='UnityEngine.QueryTriggerInteraction':raise ValueError('Trigger argument type mismatch')
    enum_owner=trigger['data'];enum_type=m.types[enum_owner];defaults={q[0]:q for q in m.records(16,'<3i')}
    trigger_storage=[]
    for local in range(enum_type[18]):
        field_index=enum_type[8]+local;q=m.fields[field_index];name=m.string(q[0])
        if name=='value__':continue
        default=defaults.get(field_index)
        if default is None or default[2]<0:raise ValueError('Missing trigger default storage record')
        at=m.header[18]+default[2]
        trigger_storage.append(dict(name=name,default_record=list(default),metadata_data_offset=at,raw_prefix_hex=m.data[at:at+8].hex(),numeric_value='UNVERIFIED'))
    if [row['name'] for row in trigger_storage]!=['UseGlobal','Ignore','Collide']:raise ValueError('Unexpected trigger field identities')
    if e.bytes(0xa0482a8,4).hex()!='e3031f2a':raise ValueError('Five-argument wrapper trigger source changed')
    layouts=[]
    for owner in (34264,43049,31910):
        t=m.types[owner];sizes=struct.unpack('<4I',e.bytes(e.pointer(0xa925200+owner*8),16))
        layouts.append(dict(index=owner,name=m.type_name(owner),type_attributes=t[7],interface_flag=bool(t[7]&0x20),
                            source_instance_size=sizes[0],source_native_size=sizes[1],parent_descriptor=descriptor(t[4]) if t[4]>=0 else None,type_record_hex=m.data[m.header[40]+owner*88:m.header[40]+(owner+1)*88].hex(),
                            fields=[field(owner,j) for j in range(t[18])]))
    cache_fields=[field(31824,j) for j in (670,671,675)]
    if [f['registration_word'] for f in cache_fields]!=[0xe50,0xe58,0xe68]:raise ValueError('Player cache field offsets changed')
    if not layouts[2]['interface_flag']:raise ValueError('Attackable declaration is not the expected interface')
    collider=next(f for f in layouts[1]['fields'] if f['name']=='m_Collider')
    if collider['descriptor']['kind']!=8:raise ValueError('RaycastHit collider storage is not Int32')
    resolver=[]
    for index,q in enumerate(m.methods):
        if q[1]!=41079 or m.string(q[0])!='FindObjectFromInstanceID':continue
        slot=0xaf5a718+((q[7]&0xffffff)-1)*8;address=e.pointer(slot)
        if address!=0x9ff122c:raise ValueError('Object-ID resolver identity changed')
        resolver.append(dict(index=index,owner=m.type_name(q[1]),name=m.string(q[0]),rva=address,registration_slot_rva=slot,
                             source_prefix_hex=e.bytes(address,32).hex(),scope='IDENTITY AND PREFIX ONLY; IMPLEMENTATION NOT FULLY EVALUATED'))
    if len(resolver)!=1:raise ValueError('Expected exactly one Object-ID resolver')
    report=dict(audit_version=1,elf_sha256=r.ELF_SHA,metadata_sha256=r.META_SHA,physics_module_rva=modules[0],
                scope='OFFLINE QUERY AND LAYOUT CONTRACT ONLY',object_id_resolver_identity=resolver[0],methods=methods,player_cache_fields=cache_fields,layouts=layouts,
                findings=['Raycast takes origin, direction, output hitInfo, maxDistance and layerMask, not a player/head identity.',
                          'RaycastHit.m_Collider is Int32 storage; it must not be interpreted as a managed Player address.',
                          'Several RaycastHit field registration words are encoded/uninterpreted markers; they are preserved and not promoted to runtime offsets.',
                          'The Player cached attackable reference is declared as an interface, not a concrete object layout.',
                          'This overload forwards raw trigger value zero; the enum default-data encoding and current live global trigger setting were not established.',
                          'The custom hit-data cache contains GameObject/Collider references and Vector3 values, but freshness, coordinate semantics, hit ownership and head association remain unverified.',
                          'No live object-ID resolver, collision snapshot, engine query, target association or aim adapter is supplied.'],
                collider_source_load=dict(rva=0xa04f6e8,payload_offset=0x28,word_hex=e.bytes(0xa04f6e8,4).hex(),scope='PROPERTY BODY LOAD ONLY; FIELD REGISTRATION MARKERS NOT DECODED'),trigger_policy=dict(enum_type=enum_owner,default_storage=trigger_storage,constant_decoding_status='UNVERIFIED_DEFAULT_DATA_ENCODING',forwarded_raw_value=0,mode='UNVERIFIED_RAW_ZERO',live_global_setting='NOT_CAPTURED'),runtime_cache_verified=False,head_los_verified=False,functions_invoked=False,aim_writes=False)
    Path(args.report).write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print('HitQueryContract=PASS Methods=%d CacheFields=3 Layouts=3 HeadLOS=UNVERIFIED'%len(methods))


if __name__=='__main__':
    main()
