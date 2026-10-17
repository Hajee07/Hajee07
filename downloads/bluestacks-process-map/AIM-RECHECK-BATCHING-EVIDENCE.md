## V50 aim-state final recheck batching

V49 live verification reached the unchanged inner read allowance even after a
stable head and complete 16-player roster sample. No controller-camera result
was accepted. Another V49 run rejected changing roster entry hash bytes; batching
does not bypass roster stability requirements.

V50 changes only final ObjectReads transport grouping in the aim-state sample
and schema. Initial and repeated reads still fetch fresh bytes. Final observations
are sorted by address and nearby ranges are fetched together, with gaps no more
than 64 bytes, within one page and at most 4096 bytes. Every observed range is
compared byte-for-byte with its own initial snapshot; unobserved gap bytes are
not used as evidence. Mismatch messages retain the original address, range,
changed offset and label. The observation count is unchanged.

No comparison, source/metadata check, identity check or read/time budget is
removed. Native hierarchy job-aware rechecks retain the original path. Other
probe modes retain individual final transport requests. The order/timing of
final reads changes; these remain sequential observations, not an atomic frame
or a guarantee against ABA changes or mutation after capture.

The full registered controller/camera synthetic fixture uses 4752 physical reads,
compared with 5572 in V49 (820 fewer; about 14.7%). This is offline fixture evidence,
not a live performance or completion claim. Live Windows V50 verification is
pending. Run Run-ProcessMap.ps1 -ProbeAimState once with the camera steady.

Expected output remains CameraControllerInventory and AimStateSamples. A matched
native link establishes registered field/reference agreement only, not actual
getter invocation, Unity object liveness, rendered/aiming camera selection, LOS
or firing direction. All functionality remains read-only with no game/native
function calls or aim writes.
