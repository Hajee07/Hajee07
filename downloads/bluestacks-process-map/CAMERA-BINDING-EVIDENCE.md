# V41 source-verified camera native-function cache observations

Live Windows validation pending. Run `Run-ProcessMap.ps1 -ProbeAimState` with
the game already running and camera steady. No manual turns are required.
The existing original local Quaternion/basis snapshot additionally reports
CameraNativeBindings. This reads two native-function pointer cache cells, not
camera object pointers or actual camera position/rotation.

## Camera source investigation

Exact SHA256-verified ELF and decoded metadata identify Player method 210071,
GetRuntimeMainCameraTransform, RVA 0x6f2f368, length 0x130, hotfix index 0x21bc0.
Its original path calls UnityEngine.Camera.get_main (method 315161, RVA 0x9fa01d8).
UnityEngine.Object equality/inequality checks gate a fallback and the final
Component.get_transform return (method 317874, RVA 0x9fe7aa8). The fallback calls
GameFacade.CurrentCameraControllerManager (method 35118, RVA 0x71d0344), then
CameraControllerManager.get_GameCamera (method 216274, RVA 0x718ca94).
CurrentCameraControllerManager uses a checked MatchGame path and calls
MatchGame.GetCameraControllerManager (method 35620, RVA 0x73238e0). Those source
fallback paths are not emulated or interpreted as live validated objects here.
The registered Player.MainCameraTransform field is not read by this original
runtime getter; a cached player field alone does not establish its result.

Camera.get_main resolves the exact icall string UnityEngine.Camera::get_main()
at RVA 0x1966d4b into a cache at RVA 0xafb7380. Component.get_transform resolves
UnityEngine.Component::get_transform() at RVA 0x19ab8ec into cache 0xafb9668.
Build-AimStateReference.py derives both cache/name RVAs from the exact ADRP plus
LDR/ADD instructions and verifies names, method records, owning metadata images,
and per-module token tables. Unity methods use CoreModule's own table, not
Assembly-CSharp's. Full original runtime-camera getter and both wrappers/name
bytes join the existing initial/final code checks; their method registration
and runtime metadata join the rechecked schema.

## Observation contract

Only after a verified local Quaternion snapshot, the two cache cells are read
as eight bytes and included in exact snapshot rechecks. Zero is allowed and
reported NOT_READY_UNINITIALIZED_ICALL; no resolution/initialization is invoked.
Nonzero values must be canonical guest user addresses and are reported as
NONZERO_FUNCTION_POINTERS_ONLY. Noncanonical values fail the tentative sample.
Changing cells or final code/schema fail the snapshot. Nonzero does not prove
that the address belongs to ARM64 libunity, is executable, or returns any valid
camera/Transform object. No pointed-to function bytes or objects are dereferenced.

CameraNativeBindings explicitly states Scope=ICALL_FUNCTION_POINTERS_ONLY,
CameraObjects=NOT_READ, CameraPose=UNVERIFIED, GameGetterHotfix=NOT_EVALUATED and
FunctionsInvoked=False. The game's runtime getter is not executed, and its hotfix
route is not asserted inactive. The source original path is not labeled as the
current live camera. Existing manual yaw/pitch results remain manual correlation
only. Camera/shot convention, actual pose, LOS, targets and aim integration remain
unverified. No writes, calls, pause or guessed field chain are introduced.

## Bounds and verification

819 offline checks pass (806 prior, 11 new camera-binding cases and two version
compatibility cases). New cases cover nonzero cache observations, either zero
cache without initialization, either noncanonical pointer, changing cache,
CoreModule method registration, wrapper/name bytes, method metadata and final
wrapper mutation. Existing local identity, hotfix, Quaternion and budget checks
remain passing. The phase fixture uses 3553 reads; global 30000-call/120-second,
6000 optional-phase and 1500 final-reserve bounds are unchanged.
Reference output reproduces byte-for-byte. Extracted-package checks compile C# 5,
parse PowerShell, verify ten exclusive modes and all source/helper/plugin hashes,
and run the complete suite. No live V41 result is claimed.

Next evidence is the live cache status/addresses. Actual camera-object access
still requires a separately verified native accessor/runtime context; this step
does not provide or execute that accessor.
