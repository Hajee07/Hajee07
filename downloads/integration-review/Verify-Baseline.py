#!/usr/bin/env python3
"""Verify immutable input manifests; optional upload is inspected as ZIP data only."""
import argparse
import hashlib
import json
import zipfile
from pathlib import Path


def digest(b): return hashlib.sha256(b).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--extension-zip',type=Path)
    p.add_argument('--report',type=Path,required=True)
    a=p.parse_args();downloads=Path(__file__).resolve().parent.parent
    manifest=json.loads((downloads/'targeting-offline/source-package-manifest.json').read_text())
    verified=[]
    for row in manifest['files']:
        b=(downloads/row['name']).read_bytes()
        assert len(b)==row['bytes'] and digest(b)==row['sha256'],row['name']
        verified.append(row['name'])
    runner=(downloads/'bluestacks-process-map/Run-ProcessMap.ps1').read_text()
    assert "Record 'ProcessMapVersion=52 ReadOnly=1'" in runner
    archive=downloads/'bluestacks-process-map-x64.zip'
    assert digest(archive.read_bytes())=='9e4ce6fbebf42e5e8398cc1dc7deb6ff238aa7760a82cb3bc0ea712ee5ef3279'
    report=dict(runner=52,source_manifest_matches=verified,v52_archive_sha256=digest(archive.read_bytes()),
                extension_zip='NOT_SUPPLIED',unknown_binaries_executed=False,
                source_reference_commit=manifest['mapping_reference_commit'],live_tests_run=False)
    if a.extension_zip:
        b=a.extension_zip.read_bytes();assert digest(b)==manifest['uploaded_zip_sha256']
        with zipfile.ZipFile(a.extension_zip) as z:
            prefix='V49-Targeting-Advanced/';up=json.loads(z.read(prefix+'manifest.json'))
            for row in up['files']:
                b=z.read(prefix+row['name']);assert len(b)==row['bytes'] and digest(b)==row['sha256']
            for name in ('Targeting.cs','MeshLineOfSight.cs','AdvancedController.cs','AimCoordinator.cs'):
                assert z.read(prefix+name)==(downloads/'targeting-offline'/name).read_bytes()
            report.update(extension_zip='VERIFIED',extension_manifest_matches=len(up['files']),library_sources_unchanged=4)
    a.report.write_text(json.dumps(report,indent=2)+'\n')
    print('BaselineAudit=PASS Runner=52 SourceManifestMatches='+str(len(verified)))


if __name__=='__main__':main()
