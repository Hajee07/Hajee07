# V49 registered camera controller field inventory

Live V49 verification is pending. Run `Run-ProcessMap.ps1 -ProbeAimState` once
with Free Fire running and camera steady. No camera-turn experiment is needed.
This inventories current registered fields without forcing any getter to run.

## Accepted V48 capture

The uploaded V48 report passed native camera/aim snapshots and cleanup, with
4743 phase reads / 24035 total. GameCameraGetterGate reported
NOT_READY_GETTER_METADATA_INITIALIZATION: getter metadata byte 0, CheckPatch
metadata byte 1. IFix slot presence was not evaluated for that entry path and
its blank result is not false. This does not establish a BlueStacks failure,
that the function can never run, or which getter the game actually uses.

## Source and registration proof

The exact pinned IL2CPP/metadata inputs reproduce three further registered
Assembly-CSharp methods and their complete source bytes:

- GameFacade.CurrentCameraControllerManager, method 35118, RVA 0x71d0344,
  size 0x134, metadata guard RVA 0xafa67ed, IFix slot 0x370. Its original
  branch inspects GameFacade.CurrentGame, checks the MatchGame cast, then calls
  MatchGame.GetCameraControllerManager. V49 does not execute that branch.
- MatchGame.GetCameraControllerManager, method 35620, RVA 0x73238e0, size 0x48,
  IFix slot 0x36f; its original field load is this +0xd8.
- CameraControllerManager.get_GameCamera, method 216274, RVA 0x718ca94,
  size 0x48, IFix slot 0x42e; its original field load is this +0x20.

The generator checks method names, owners, tokens/tables, metadata records,
source field-load instructions and IFix immediates. It derives/checks registered
fields and their declared types, rather than guessing offsets:

| Declaring class | Registered field | Offset | Type |
| --- | --- | --- | --- |
| COW.MatchGame (12425) | m_CameraControllerManager, field 9 | 0xd8 | CameraControllerManager (32002) |
| COW.GamePlay.CameraControllerManager (32002) | EKIPKGNKILM, field 0 | 0x20 | UnityEngine.Camera (40830) |
| UnityEngine.Object (41079) | m_CachedPtr, field 0 | 0x10 | Native IntPtr |

Runtime schema checks verify the field records, native registration offsets,
descriptors and runtime field table ownership/offset/token. CurrentGame must
retain its verified MatchGame family and resolved base class. The controller
must be the supported exact 32002 class; the camera must be 40830. Its parent
chain must match Camera -> Behaviour (41031) -> Component (41037) -> Object
(41079) before the inherited native-pointer field is read. The five supported
class records, tokens, sizes, type/name/self pointers and metadata are checked.
Unknown types are not followed as supported instances.

## Bounded capture and report meanings

CameraControllerInventory records manager, typed field camera, cached native
pointer, optional equality to the already selected original Unity native
camera, facade metadata guard byte and the three getter-slot presence values.
Those slot booleans are array-entry presence observations, independent of
whether a method's metadata guard permits its entry path to be evaluated.
They do not validate or invoke a hotfix.

- REGISTERED_CAMERA_NATIVE_LINK_MATCH / DIFFERS: a supported typed managed
  Camera's registered cached native pointer equals / differs from this capture's
  selected original native camera. Neither result is forced or normalized.
- REGISTERED_CAMERA_NATIVE_LINK_UNCOMPARED: a supported nonzero cached native
  pointer exists, but no original native camera was selected for comparison.
- REGISTERED_MATCHGAME_MANAGER_FIELD_NULL / REGISTERED_CONTROLLER_CAMERA_FIELD_NULL:
  the respective registered field is null; no initialization or Unity object-null
  semantics are inferred.
- REGISTERED_CAMERA_CACHED_NATIVE_NULL: no nonzero native link is available;
  this is not proof of object destruction or liveness.
- UNVERIFIED_CONTROLLER_CLASS / UNVERIFIED_CAMERA_CLASS: unsupported runtime
  type; further field following stops.

The first full-chain offline attempt reached the unchanged read ceiling. V49
batches supported class header reads into 0x130-byte snapshots, preserving
all checks and exact final rechecks (including extra header bytes). It keeps
the original 6000 phase / 30000 global limits, reserves and time bound; no
polling, retries, VM pause, calls or writes are added. A grouped-header change,
field-link mutation, source/registration/parent mismatch or budget exhaustion
discards the tentative sample. Broader header capture may conservatively reject
concurrent metadata changes. Captures remain sequential, not an atomic frame.
The full-chain synthetic fixture uses 5572 phase reads after batching.

## Scope limits

Even a MATCH proves only the registered field/cached-pointer link in the checked
snapshot. It does not prove getter invocation, actual rendered/aiming camera,
managed-wrapper conversion, Unity object-null/liveness semantics, or active
hotfix/fallback return values. Existing ManagedCamera=NOT_READ rows describe
the original native selector's managed-wrapper conversion result; the separate
inventory row may contain a typed controller-field camera reference.

The facade entry metadata guard is recorded without initializing it. The
unused Player.GetRuntimeMainCameraTransform guard is not forced. ActualGameCamera
remains UNVERIFIED. Full getter/hotfix/fallback selection, LOS/eligibility,
aim updates and live Windows end-to-end aiming remain incomplete.
