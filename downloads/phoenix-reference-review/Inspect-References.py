#!/usr/bin/env python3
"""Parse uploaded PE/CLR bytes without loading either assembly or native DLL."""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path
import dnfile
from dncil.cil.body.reader import read_method_body_from_bytes


def inspect(path):
    data=path.read_bytes()
    if len(data)>32*1024*1024:raise ValueError('Input exceeds inspection bound')
    pe=dnfile.dnPE(data=data)
    return pe,dict(name=path.name,bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),machine=pe.FILE_HEADER.Machine,
                   pe_magic=pe.OPTIONAL_HEADER.Magic,sections=pe.FILE_HEADER.NumberOfSections,clr_present=bool(pe.net))


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--managed',type=Path,required=True);p.add_argument('--native',type=Path,required=True);p.add_argument('--report',type=Path,required=True)
    a=p.parse_args();managed,m=inspect(a.managed);native,n=inspect(a.native)
    if not managed.net or native.net:raise ValueError('Expected one CLR and one native image')
    fields={id(f.row):str(t.TypeName) for t in managed.net.mdtables.TypeDef.rows for f in t.FieldList}
    constants={}
    for row in managed.net.mdtables.Constant.rows:
        if fields.get(id(row.Parent.row))!='CameraPoseReference':continue
        value=row.Value.value
        if row.Type in (8,9):value=struct.unpack('<I',value)[0]
        elif row.Type in (10,11):value=struct.unpack('<Q',value)[0]
        elif row.Type==14:value=value.decode('utf-16le')
        else:value=value.hex()
        constants[str(row.Parent.row.Name)]=value
    def resolve(token):
        value=token.value;kind=value>>24;index=value&0xffffff
        if kind==0x70:return str(managed.net.user_strings.get(index))
        table={6:'MethodDef',10:'MemberRef',4:'Field'}.get(kind)
        if table:return str(getattr(managed.net.mdtables,table).rows[index-1].Name)
        return str(token)
    methods=[]
    for index,row in enumerate(managed.net.mdtables.MethodDef.rows,1):
        if str(row.Name) not in ('CameraSchema','ReadPlayerCameraPose','ReadPlayerCameraAttempt','ComposeCameraQuaternion'):continue
        body=read_method_body_from_bytes(managed.get_data(row.Rva,18000))
        refs=[]
        for ins in body.instructions:
            if ins.opcode.name in ('call','callvirt','newobj','ldstr'):
                refs.append(dict(il_offset=ins.offset,opcode=ins.opcode.name,reference=resolve(ins.operand)))
        methods.append(dict(token=0x06000000|index,name=str(row.Name),rva=row.Rva,signature_hex=row.Signature.value.hex(),
                            il_bytes=body.code_size,il_sha256=hashlib.sha256(body.get_instruction_bytes()).hexdigest(),references=refs))
    m.update(assembly=[dict(name=str(r.Name),version=[r.MajorVersion,r.MinorVersion,r.BuildNumber,r.RevisionNumber]) for r in managed.net.mdtables.Assembly.rows],
             types=len(managed.net.mdtables.TypeDef.rows),methods=len(managed.net.mdtables.MethodDef.rows),
             pinvoke_maps=len(managed.net.mdtables.ImplMap.rows) if managed.net.mdtables.ImplMap else 0,
             camera_reference_constants=constants,selected_il_methods=methods)
    exports=[r.name.decode(errors='replace') for r in native.DIRECTORY_ENTRY_EXPORT.symbols if r.name]
    imports={r.dll.decode(errors='replace'):[x.name.decode(errors='replace') for x in r.imports if x.name] for r in native.DIRECTORY_ENTRY_IMPORT}
    n.update(named_exports=len(exports),candidate_exports=[x for x in exports if re.search('Aim|Camera|Transform|Restore',x)],
             host_memory_imports={k:[x for x in v if re.search('ProcessMemory|VirtualMemory|OpenProcess|GetProcAddress|LoadLibrary|CreateThread',x)] for k,v in imports.items() if any(re.search('ProcessMemory|VirtualMemory|OpenProcess|GetProcAddress|LoadLibrary|CreateThread',x) for x in v)},
             trial_named_exports_present=any('TrialSystem' in x for x in exports),verified_callable_contract='NOT_ESTABLISHED')
    report=dict(scope='STATIC FILE PARSING ONLY',managed=m,native=n,assemblies_loaded=False,native_functions_invoked=False,
                findings=['Managed file declares a Reader.ReadPlayerCameraPose path and CameraPoseReference constants, useful for source comparison.',
                          'Its declared Player.MainCameraTransform field path is not proof of active rendered camera or accepted shot direction.',
                          'No P/Invoke maps appear in the managed metadata; its reader still requires an externally supplied read transport/context.',
                          'Native aim-related exports and host memory imports are names, not verified ABI/thread/lifetime or compatibility contracts.',
                          'Neither upload was executed. No licensing/trial or security behavior was changed.'])
    a.report.write_text(json.dumps(report,indent=2)+'\n')
    print('StaticInspection=PASS ManagedTypes=%d NativeNamedExports=%d Loaded=FALSE'%(m['types'],n['named_exports']))


if __name__=='__main__':main()
