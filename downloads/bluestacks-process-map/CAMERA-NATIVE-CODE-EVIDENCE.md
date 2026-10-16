# V42 camera native-entry code identity

Live Windows validation pending. Run `Run-ProcessMap.ps1 -ProbeAimState` with
Free Fire already running, camera steady. No camera turns are required. In
addition to V41's function cache observations, CameraUnityCode verifies that
the two resolved entries match the exact reference Unity ELF and registered
icall entry windows, without invoking them or accessing camera objects/pose.

## Source proof

The Unity reference file SHA256 is
1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77,
GNU build ID 667862f2d29b22ee. Build-TransformReference.py decodes each exact
ARM64 registration stub's ADRP/ADD address pairs and verifies the names/targets:

| Name | Registration stub RVA | String RVA | Target RVA | Code bytes checked |
| --- | --- | --- | --- | --- |
| UnityEngine.Camera::get_main | 0x468ddc | 0x11aa87 | 0x41d8c4 | 24 |
| UnityEngine.Component::get_transform | 0x46dabc | 0x125f6b | 0x453d04 | 256 |

The exact string bytes and complete 20-byte registration stubs are checked.
Targets and code windows must lie in the source's file-backed executable PT_LOAD.
The main entry's complete 24-byte wrapper is captured; only the first 256 bytes
of the larger component accessor are captured. No full component semantics or
called-helper implementation is claimed. Existing local-head anchors and their
runtime path are unchanged; separate CameraAnchors are used only by aim-state.

## Runtime contract

The two existing source-verified icall cache pointers must yield the same
page-aligned canonical guest load bias when subtracting their registered RVAs.
Subtraction underflow, mismatched/nonaligned candidates, changed ELF header,
program tables, GNU note/build ID, registration/name bytes or checked code fail
the tentative snapshot. Header/program/note and all camera anchors participate
in ObjectReads exact final rechecks along with the original local identity,
Quaternion, gate and cache-cell checks. No pointed-to function is executed.

REGISTERED_ENTRIES_AND_CODE_VERIFIED means both entries at their expected RVAs
match the reference image's ELF identity, named registration and code windows.
It is not a full in-memory file SHA256 check, live filesystem/path attestation,
VMA/PTE executable-permission check, complete native call-graph validation or a
camera object/pose result. ReferenceFileSHA256 labels the pinned source file.
The ELF source's executable segment membership is checked; no native page is
made executable and no page protection is changed.

An unresolved zero cache retains NOT_READY_UNINITIALIZED_ICALL and zero bias;
it is not initialized or treated as verified Unity code. Existing noncanonical
pointer refusal remains. All other methods/modes retain their own contracts.
CameraObjects=NOT_READ, CameraPose=UNVERIFIED and FunctionsInvoked=False are
printed explicitly. Actual camera accessor context, pose, shot direction, LOS,
visibility/eligibility and aim integration remain unverified. No writes, calls,
VM pause, target selection, guessed offsets or control automation are added.

## Validation and bounds

836 offline checks pass: 819 previous, 15 new native-code cases and two version
compatibility cases. Tests cover exact-entry success, mixed biases, subtraction
underflow, page alignment, ELF/program/build ID mutations, both registration
stubs/names/code windows and changed code during capture. Existing zero-cache
cases explicitly retain NOT_READY and zero bias. C# 5 compilation, PowerShell
parsing/ten exclusive modes, source/helper/plugin hashes, exact reference
reproduction and the extracted-package suite pass. Live V42 remains pending.
The fixture phase uses 3697 reads. Global 30000-call/120-second, 6000 optional
phase and 1500 final-reserve limits remain unchanged. No automatic retries or
polling are added.

## Accepted V42 live native-entry identity

The uploaded V42 report returned REGISTERED_ENTRIES_AND_CODE_VERIFIED at Unity
bias 0x32fc000, build ID 667862f2d29b22ee. Main entry=0x37198c4 (RVA 0x41d8c4),
component entry=0x374fd04 (RVA 0x453d04), checked scopes 24/256 bytes. Original
local snapshot and unchanged local membership passed; aim phase reads=3757,
total=23790. Plugin unload, handler cleanup and session release passed.
Functions were not invoked and camera objects/pose were not read in V42.

V43 adds bounded candidate discovery; see [candidate evidence](CAMERA-CANDIDATE-EVIDENCE.md).
