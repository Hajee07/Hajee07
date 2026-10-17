# Offline targeting module reviewed with V52 sources

The supplied `V49-Targeting-Advanced.zip` contains useful engine-independent
geometry, target selection, acquisition stability, bounded direction control and
host coordination code. This folder imports its reviewed **source**, separately
from the native BlueStacks bridge. It does not connect those algorithms to Free
Fire or replace the V52 reader.

## Verified here

- All 16 supplied manifest file lengths and SHA-256 values matched the upload.
  This is package consistency, not publisher authentication.
- The four library sources were compiled unchanged together with the current
  V52 runtime C# sources using C# 5 with warnings treated as errors.
- The supplied 20 baseline and 259 advanced assertions passed independently.
- 300 additional seeded tests used analytically selected rectangle coordinates,
  then rotated and translated the whole 3D scene. Their expected results did not
  reuse the triangle intersection algorithm. All passed.
- The source-rebuilt simulation acquired a target, applied a local command, then
  revoked it on obstruction and disable. Applied means the simulation received
  its command; it is not a game-camera or firing test.
- The V52 report assessment accepted the reported native pose/controller evidence
  while leaving all unestablished live-binding proofs Unknown. Removing cleanup
  evidence caused report parsing to fail instead of producing a binding approval.

Validation ran in the cloud with PowerShell 7.4.6 on Linux using the C# 5
compiler option. A fresh Windows/.NET Framework build and live gameplay were
not executed in this step.

See `validation.txt` (579 assertions plus simulation checks) and
`v52-binding-assessment.json`.

The uploaded precompiled DLL and EXE were inspected only as files and were not
loaded or executed. Their headers declare PE32/x86 with a CLR directory; no
native x64 injection or bridge compatibility is inferred. No precompiled binary
is included in this source package. Source compile compatibility is not binary
ABI compatibility, a verified host adapter, or end-to-end Windows gameplay.

## Run the reviewed source checks

Use a fresh PowerShell process so earlier type definitions do not conflict.
From this folder in a repository checkout:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-OfflineChecks.ps1
```

The standalone `targeting-offline-source.zip` also includes the exact V52 runtime
C# sources and two report-parser helpers in a sibling folder, so the same command
works after extracting that ZIP. No APK, kernel, vendor DLL, native plugin or
emulator is required for these offline checks. The root archive manifest lists
SHA-256 values for its source/doc/evidence files; the archive's public download
hash is separate.

To assess an existing complete V52 text report without executing its contents:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Assess-V52Binding.ps1 -ReportPath .\saved-v52-report.txt
```

That script reuses the existing strict V52 report parsers. It provides a contract
gap report only; it never fabricates a `Frame` or promotes fields to `Proof.Yes`.
`LiveBindingReady` is false for this current integration. It supplies no actuator.

## What remains unbound

`Proof.Yes` and `completeGeometry=true` are host assertions, not facts the library
can establish. In particular, V52 native camera/null comparisons do not establish
active game-camera/shot conventions, one coherent observation, target lifetime,
full combat eligibility, complete filtered collision geometry, or an authoritative
engine LOS result. Those facts cannot be supplied as optimistic constants.

The triangle mesh tests blocking surfaces; it is not solid-volume containment or
a reconstruction of the live game's collision world. Dynamic colliders, layer
and trigger policy, target exclusions, and coordinate/snapshot matching need an
actual authoritative provider. Unverified/incomplete geometry stays Unknown.

No live `IFrameAuthority` or `IAimOutput` implementation is supplied. A production
host must enforce command expiry and revocation even if observations stop; the
library starts no watchdog thread. Synchronous callbacks cannot be interrupted
by the library's time budget. The local simulation is not a Free Fire adapter.

`INTEGRATION.md` and `UPSTREAM-README.md` preserve the supplied contract and
original claims for reference; their original build filenames refer to that
upload. Use this folder's reviewed driver for the checks described here.

## Provenance

Upload ZIP SHA-256:
`1009161b6ad2ec55907ab8b9e019badc620a1eee2be031e037672d39f55ed421`.
The four runtime library sources are unchanged from that upload. The existing
Windows V52 runner, native plugin, read limits and checksum contracts are unchanged.
