# Single-capture Player.MainCameraTransform reader

This is a separate **read-only** source extension over the immutable V52 runtime.
It samples the registered `COW.GamePlay.Player.MainCameraTransform` field directly,
then computes its measured transform pose using the existing verified Unity
transform math. No eight-stage manual camera routine is required to run this
reader. The unknown uploaded DLLs are not loaded or bundled.

## Run on Windows

Open Free Fire 1.132.1 ARM64 in the supported BlueStacks Pie64 instance, enter
Training and leave the character spawned. In **64-bit Administrator PowerShell**,
from the extracted package directory:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-PlayerCamera.ps1
```

This performs one capture with bounded internal retry for observed TRS/job changes.
No camera controls or aim writes are automated. Keep the camera still during the
capture. Share the printed `ResultFile` text. The ZIP includes the exact baseline
runtime in its `baseline` directory, so it needs no old temporary capture directory
or saved seed reports. A restarted process starts a new observation rather than
mixing old/new samples. Restart/context changes during a capture still reject it.

The new report starts `PlayerCameraProbeVersion=1 BaseRunner=52 ReadOnly=1`.
SAMPLED_READ_ONLY means only that the stated field/hierarchy observation passed
its checks. Null/uninitialized/busy/changing/budget-exhausted cases do not publish
position/rotation and return a nonzero runner exit. Cleanup is always attempted.

## Validation retained and scope narrowed explicitly

- Exact SDK/VMM/plugin, kernel/process, ARM64 ELF/build and runtime metadata checks
  are inherited from V52. Baseline manifest and all compiled baseline source hashes
  are checked. New runner/reference/probe sources have separate integrity entries.
- Original local context verification retains initialized facade/hotfix classes,
  wrapper type/metadata, inactive original-path hotfix guards, typed current game,
  match and Player ancestry, plus the local marker. It does **not** sample or claim
  a complete match roster, nonlocal player state or a head dictionary. The separate
  original V52 roster mode is unchanged. This avoids its unrelated full-roster
  snapshot prerequisite for a narrowly scoped local camera-field observation.
- Field metadata, source offset registration, descriptor, declaring class, name,
  token and runtime field record must match the pinned game schema. The field's
  managed object must have the verified UnityEngine.Transform type hierarchy.
- Resolved position bindings establish the Unity image bias. Header, program
  tables, build ID and pinned position/rotation code anchors are checked; no
  resolved function is invoked.
- Hierarchy index/capacity, parent cycles/depth, transform backlinks, parent links,
  pending jobs, two opposite-order TRS captures, finite coordinates/quaternion
  norms and final context/process identities are checked before publication.
- Context/code/schema observations use the existing V52 final-read coalescing
  helper. Every observed byte is still compared; initial reads are not cached.
  Hierarchy observations retain the existing separate job-aware recheck path.
  A simultaneous hard context identity change wins over a retryable job change.

Global policies stay **30000 physical calls / 120 seconds**, with the existing
4096-byte transport maximum. The new phase is capped at **6000 additional reads
shared across all attempts**, each attempt at **4500**, at most **3** attempts.
Limits are never reset to obtain PASS. An outer stricter scope is respected.
Synchronous transport calls cannot be interrupted by elapsed-time checks.

## What this does not establish

A registered field called MainCameraTransform is not proof that it is the active
rendered camera in every mode or that its direction equals an accepted shot.
The report keeps ActualRenderedCamera, ShotDirection and LOS UNVERIFIED and
GlobalAtomicFrame NOT_ASSERTED. File timestamps and the recorded method interval
are not synchronized rendered-frame time or object generation/lifetime proof.
No Frame authority, target eligibility, nonlocal head tracking or aim-output
adapter is enabled by this reader. No getter/class initializer is forced.

The uploaded managed assembly was useful only as a reference to investigate.
The new field constants were independently regenerated from the pinned game ELF
and metadata; pose math and native checks reuse current V52 source, rather than
executing or blindly translating the uploaded assembly. PhoenixV5.dll supplies
no verified runtime contract here. Licensing/security behavior is untouched.

## Build/check/reproduce

The package contains C# source and the unchanged verified native read-only bridge.
C# 5 compilation with warnings as errors is tested in cloud PowerShell 7.4.6 on
Linux. Windows native execution of this new path remains NOT_TESTED until a user
capture is reviewed.

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-Checks.ps1
```

For the full inherited suite, add `-KernelElfPath C:\path\to\vmlinux`. In the
repository, sibling bluestacks-process-map supplies the original baseline; no
tracked original source files are modified. The standalone ZIP embeds those
same baseline files without changing their bytes.

```text
python Build-Reference.py libil2cpp.so global-metadata.dat /tmp/generated-reference
```

Reference generation verifies full ELF/metadata SHA-256 values through the
baseline parser. See reference.json and evidence files for measured fixture
results, exact counts and validation scope. Tests use an owned synthetic memory
transport, not uploaded binaries or a live game. They cannot measure headshot
accuracy or validate active rendering.

PowerShell compatibility fix: compiler options are supplied only when Add-Type exposes that parameter. Both parameter surfaces are covered by Test-CompilerCompatibility.ps1. Live Windows capture remains unverified.

Probe version 3 resolves live mappings before and after every data read. Cached translations cannot select an unvalidated data page. Changes during reads remain fatal and evict the cache entry. Local-context failures now carry LOCAL_CONTEXT. Offline: 27 assertions pass. Additional validation can exhaust existing retry budgets; no stale coordinates are returned. Live Windows validation is pending.

Run-CameraComparison.ps1 guides three fresh captures: initial, manually turn right, then manually tilt up. It compares full quaternion angular changes only, including q/-q equivalence. It does not infer turn direction or certify rendered-camera correspondence. Stay stationary and stop turning before typing READY. Share the resulting JSON and, if available, a recording of the three on-screen views. Same process/player/managed transform required. Failed or invalid captures stop the helper.

## Resume only a failed third comparison capture

Run-CameraComparison.ps1 now accepts `-InitialReport` and `-RightTurnReport` together. It validates both saved reports, rejects duplicate paths and incompatible identities, copies both into a unique `camera-seed-*` directory, and records their SHA-256 values in seed.json. Only one fresh capture is requested. The original reports are not modified. Seed hashes are checked again before comparison.

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-CameraComparison.ps1 `
  -InitialReport 'C:\path\initial-report.txt' `
  -RightTurnReport 'C:\path\right-turn-report.txt'
```

Only type READY if still at the prior UP-tilt view with the same stationary player/match. Do not tilt up a second time. If the game/player/match/camera changed or the prior view is no longer reproducible, cancel and run without these two parameters for a new three-capture experiment. Missing saved reports also require a fresh run. Process, current game, match, player, managed transform and native transform identities must match across all reports. A new attempt has its own original read budget; no limit is raised. Another failed capture leaves the saved pair intact and produces no completed comparison. Live Windows resume remains pending; successful comparisons still report OBSERVATIONS_ONLY and do not certify rendered-camera or shot direction semantics.
