# V45 native camera Transform position

V45 is a read-only diagnostic increment. It does not complete automatic aiming.
Live Windows V45 position sampling and cleanup passed. See
CAMERA-ROTATION-EVIDENCE.md for the accepted observation and V46 scope.

## Accepted V44 live result

The supplied V44 report for Pie64, HostPID 12744, GuestPID 3058 selected
native camera 0x70cc3f0e3a10, owner 0x70cc4099be50. Predicate RVA 0x50700c
returned source-equivalent true for byte 1; complete native source selection
was reported. The aim phase used 4060 reads; total 23561. Plugin unload,
handler cleanup and shared-session release passed. These addresses are
historical observations, never reused as fixed runtime addresses.

## Source evidence and runtime scope

The exact SHA-256-pinned Unity image's named Component.get_transform target
is RVA 0x453d04. V45 extends its checked code window from 256 to all 460
bytes through the final exception dispatch. In its non-null native-component
branch, 0x453d90 loads the owner from native component +0x30;
0x453db0 loads owner +0x30, and 0x453db4 loads the first component's native
pointer at entry +8. Subsequent code converts/resolves managed wrappers;
V45 neither calls nor emulates that conversion.

Only after complete original native Camera.main selection, V45 reads that
first native intermediate, requires its owner backlink, checks hierarchy,
index and Transform backlinks, and checks exact Unity position/hierarchy
source anchors. A first pointer equal to the selected camera is explicitly
not sampled as a Transform. Nonzero pending job/tag prevents sampling.

At most 32 parent nodes are visited. The existing verified native position
arithmetic composes finite TRS rows to world position. Source bytes, selected
rows, job state, native identity and original local context participate in
final exact byte rechecks. Mutation discards the tentative sample. No retries,
VM pause, synchronization, calls, writes or read-budget increases are added.
Sequential rechecks do not constitute an atomic frame or detect every ABA change.

CameraWorldPosition reports the position of the original native selector's
Transform intermediate. It does not establish the game's actual camera,
managed camera identity, world rotation, projection, shot origin or shot direction.

## Remaining completion gates

1. V45 selected-native Transform/position validation and cleanup passed in the
   supplied live capture. Broader movement/scene-change checks remain pending.
2. Source-checked camera world rotation; manual pose correlation, including
   independent movement and rotation checks.
3. Game camera getter hotfix/fallback selection and managed-wrapper identity;
   reconcile this with the selected original Unity native camera.
4. Selected target/head consistency within the same context and time window;
   freshness, target changes and respawn handling.
5. Full LOS semantics from the actual source path and collision context;
   visible/rendered flags alone are insufficient.
6. Combine separately sampled team, combat, protection, match damage and weapon
   evidence into a source-correct eligibility policy. Separate snapshots do not
   prove simultaneous readiness.
7. Verified aim-update interface and direction/rotation convention, rollback
   behavior, lifecycle and failure handling. No aim-update implementation exists
   in V45; no foreign function or memory write is performed.
8. Live Windows end-to-end testing of the eventual integration, including
   moving targets, occlusion, reload, death, scene changes and cleanup.

No measured accuracy or completion percentage follows from passing diagnostics.
