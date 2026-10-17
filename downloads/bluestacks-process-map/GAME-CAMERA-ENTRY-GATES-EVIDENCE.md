# V48 game camera getter entry gates

Live V48 verification is pending. Run `Run-ProcessMap.ps1 -ProbeAimState` once,
with Free Fire running and the camera steady. The eight-turn experiment does
not need to be repeated for this step. V48 adds `GameCameraGetterGate` to the
existing read-only native camera/aim capture.

## Accepted V47 experiment

All eight uploaded reports were independently parsed and the composite result
recomputed: REPORTED_NATIVE_CAMERA_TURNS_OBSERVED. Reported right yaw was
+17.0901157237345 degrees, left -19.4350291628016, up elevation
+6.66625144812099, down -7.16058445296935. Maximum camera/aim quaternion angle
metric was 4.82967307890293e-6 degrees for these printed samples. Every capture
retained the observed context/camera identifiers, passed source/snapshot checks
and cleanup, and stayed within read bounds (4682 phase reads each; total reads
22250..25423). These observations establish manual native-camera turn
correlation only, not a universal camera convention or actual game getter.

## Source proof

The SHA-pinned IL2CPP image and metadata remain unchanged. The complete
Player.GetRuntimeMainCameraTransform method at RVA 0x6f2f368 is already checked
against its method registration, metadata and source bytes. Its metadata guard
is tested at 0x6f2f374 and skips initialization only when bit zero of the byte
at RVA 0xafa571a is set. The following MOV/MOVK pair constructs IFix slot
0x21bc0, matching the method metadata's gate index. It calls CheckPatch at
0x882aa1c. The generator derives/asserts both guard addresses and slot value.

V48 adds the full 0xb4-byte CheckPatch implementation to the existing source
anchors. Its own metadata guard tests bit zero at RVA 0xafb07bd. Typed IFix
class/static wrapper-array identity and completed class state are checked by
the existing player-state context. With the two metadata guards already set,
CheckPatch is a bounded nonzero-entry test on that wrapper array: an out-of-
range slot returns false; an in-range nonzero value selects the hotfix branch.
The value is not dereferenced, interpreted or invoked by this diagnostic.

The original game getter branch calls UnityEngine.Camera.get_main, evaluates
UnityEngine.Object null/equality semantics, can fall back to the camera
controller manager's game camera, and ultimately gets a managed Transform.
The active-hotfix branch invokes another dynamic wrapper. Those remaining
operations are not evaluated by V48. Native camera selection plus matching
quaternions does not prove this getter is actually used by the rendering/aim
path.

## Report meanings

- NOT_READY_GETTER_METADATA_INITIALIZATION: getter metadata guard bit is clear;
  no initialization is performed and no hotfix branch is inferred.
- NOT_READY_PATCH_METADATA_INITIALIZATION: CheckPatch metadata guard bit is
  clear; no initialization or hotfix-slot evaluation is performed.
- HOTFIX_ENTRY_BRANCH_PRESENT: both guards are set and slot 0x21bc0 is nonzero.
  This reports presence, not valid/executable hotfix semantics or a camera.
- ORIGINAL_ENTRY_BRANCH_GATES_CLEAR: both guards are set and CheckPatch returns
  source-equivalent false. Only entry availability is established, not actual
  invocation, managed wrapper identity, Unity null semantics or fallback.

Raw guard bytes and the nullable slot-presence result are captured and finally
rechecked with the existing local aim/native pose context. Guard/slot changes
discard the tentative sample. Only bit zero is tested; raw byte 3 or 255 is not
silently rejected or normalized. Source, array bounds, global/per-phase read
budgets and cleanup remain enforced. No retries, VM pause, synchronization,
class/metadata initialization, game calls or writes are added.

Existing rows' GameGetterHotfix=NOT_EVALUATED refers to hotfix function
semantics, not this new entry-presence observation. ActualGameCamera remains
UNVERIFIED. Managed-wrapper/null/fallback verification, LOS, eligibility,
aim-update integration and live end-to-end testing remain incomplete.
