# Read-only player camera and projection-cache diagnostics

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

## Visual-evidence assessment and bundle

`New-CameraEvidenceBundle.ps1 -ComparisonFile 'C:\path\camera-comparison-....json'` is an offline step. It validates and copies the three reports referenced by a completed comparison, checks same host/guest/game/match/player/managed/native transform context and ordered non-overlapping UTC capture intervals, computes finite position changes and a declared mathematical +Z quaternion basis. It preserves raw quaternions; normalization is only used for this explicitly labelled basis math. It does not infer game rendering or shot conventions.

The helper writes assessment.json, hashed capture copies, files.json, REVIEW.txt and a ZIP under a unique camera-visual-evidence-* directory beside the input comparison. It requires no game session or administrator access, and performs no live memory reads, inputs or writes. Missing source reports must be recovered from the original capture directory; they are not silently replaced.

Optional `-InitialView 'initial.png' -RightView 'right.png' -UpView 'up.png'` attaches three user-selected PNG/JPEG files (all or none, maximum 32 MiB each). These files are hashed/copied only, not decoded, feature-matched or accepted as frame-aligned. Their names and timestamps cannot prove correspondence. Images from a different session or later reenactment must not be claimed as the original evidence. If no corresponding visual evidence was recorded, a new documented recording/capture session is needed to continue visual validation.

The report remains VISUAL_EVIDENCE_REQUIRED / ActualRenderedCamera=UNVERIFIED even when screenshots are supplied. REVIEW.txt explains the missing manual landmark/frame correspondence. Method-call intervals are not render-frame timestamps. The mathematical basis is not a verified gameplay camera/shot forward vector. This helper does not close LOS or aim integration.

`Test-CameraEvidence.ps1` verifies independent +30-degree azimuth/+20-degree elevation oracles, evidence boundaries, malformed context/chronology/finite data and the actual offline ZIP bundle/hash path. `evidence/latest-transcript-assessment.json` analyses the user's successful three-capture console transcript. Those input report text sections were reconstructed with LF line endings: their hashes are not claimed to be hashes of the original Windows report files.

## Fresh recording-guided session

Run `Run-CameraComparison.ps1 -RecordVisualSession`. This is opt-in orchestration, not a recorder: the script never captures the desktop or starts/stops recording software. Arrange BlueStacks and PowerShell side by side. In Windows 11 Snipping Tool, choose Record, New, select a region containing both windows, and Start (or use OBS display/region recording). Only then type RECORDING at the first prompt. Keep recording for all three captures; keep the game view and VISUAL_MARKER lines visible. Do not move/shoot during a capture. Follow the same INITIAL, RIGHT_TURN, UP_TILT READY instructions. Stop recording only after the final EvidenceZip message, and retain the original video.

Each stage prints a session-specific marker and journals UTC plus process-monotonic elapsed time. Successfully parsed reports are hashed into recording-journal.json. Failed/cancelled sessions preserve an INCOMPLETE journal and any accepted reports. Saved two-stage seeds cannot be used in recording mode: all three captures must be fresh within that recording. No SDK/read-budget change or game input automation is introduced.

On success, the helper automatically creates the offline EvidenceZip, including the hashed journal and three captures. Journal validation requires matching comparison/report paths, stage order and hashes, monotonic event ordering, and report method-call intervals inside their process-start/accept brackets (one-second timestamp tolerance). These are provenance/timeline checks, not frame synchronization, video authentication or rendered-camera verification.

Upload **both** the EvidenceZip and the original recording. The script does not copy or attach video, so MediaStatus=NOT_ATTACHED / VisualEvidenceStatus=MISSING inside the metadata remains expected until separate media review. Typing RECORDING is a user assertion, not proof that a recording exists. RecordingJournalStatus remains USER_ASSERTED_RECORDING_NOT_FRAME_ALIGNED; ActualRenderedCamera stays UNVERIFIED. A new recording cannot validate the earlier unrecorded samples retroactively.

`Test-RecordedCameraSession.ps1` exercises no-confirmation/no-capture, complete fresh session + hashed journal bundle, hash mismatch, interval mismatch, cancellation and capture failure using mocked child probes. Live Windows recording-mode execution is pending. Recording duration and probe success depend on the existing bounded reader; a VMA scan retry can still exhaust its unchanged limit.

## V4 separate camera identity inventory

Run `Run-PlayerCamera.ps1 -ProbeCameraIdentity` once in Training with the camera held still. No manual turns or recording are required for this mode. It uses the same pinned game build, VMM, kernel, module/layout identity and cleanup checks. It does not support a different game edition by inference.

Instead of sampling camera pose, it checks the typed registered Player.MainCameraTransform field and cached native link, original Unity Camera.main selection using the already verified bounded tag/predicate source profile, the registered MatchGame/controller/managed-Camera/native link and the game getter's metadata/hotfix gates. It compares selected Camera's source-derived native Transform intermediate with the Player field's native Transform pointer. This is a rechecked source-link inventory, not a rendered-frame decision or proof the game invokes that getter.

15 synthetic-memory cases pass, alongside the existing 27 pose checks. Cases cover matched/different links, unresolved cache, null controller, uninitialized getter, active hotfix branch, false predicate, unknown predicate override, controller disagreement, owner/schema/context changes, budget exhaustion and final pointer mutation. The identity fixture uses 4733 additional physical calls. The optional phase stays capped at 6000; existing global 30000 calls, timeout and cleanup remain. A scan retry can still consume the global budget. Tentative pointers are not returned on failed final checks or exhausted scope.

Output explicitly distinguishes:

- `CameraIdentityOriginalMain` — verified original selector inventory, not an assertion of the active render Camera.
- `CameraIdentityController` — registered field/native link and equality/difference with that selector.
- `CameraIdentityGetter` — raw initialization gates and branch availability. Getter metadata not initialized is not an error to fix by forcing initialization. Active getter/override branches are not invoked or guessed.
- `CameraIdentityLimits` — projection/FOV NOT READ, rendered frame UNVERIFIED. `FunctionsInvoked=False` concerns game getters/icalls; host SDK/bridge read APIs still run normally.

A `True` link comparison closes only that pointer-equality observation under final rechecks. It does not establish active render-stack selection, projection/FOV/viewport, render synchronization, muzzle/shot direction, LOS or aim output. Unknown is printed UNVERIFIED rather than rendered as False. Structural or memory errors fail the probe and still run cleanup. `NOT_READY_READ_BUDGET` emits no tentative source pointers.

## Projection/FOV source audit

`Audit-CameraProjection.py IL2CPP METADATA UNITY OUTPUT_JSON` verifies the three full input hashes and inventories the exact UnityEngine.Camera owner, CoreModule registration table, 17 registered methods and 17 native name strings. It covers FOV/aspect, clipping planes, orthographic properties, pixel bounds, projection/world-to-camera matrices and WorldToScreenPoint wrappers. `--runtime-directory` can select the pinned mapper tools when needed. No supplied binary is loaded or executed.

The checked-in `evidence/projection-static-audit.json` is a static registration/name inventory only. It does not establish native camera field offsets or a safe matrix data layout. No runtime FOV/matrix values are read and no getter/resolver/initializer is called. Three altered-input cases are rejected before output. A native field/source profile and independently checked landmark reprojection are still required before implementing a live projection reader.

The earlier successful visual review supports manual turn-direction correlation only. It does not authorize treating the Player field, Camera.main tag or controller field as render authority. A user-supplied V4 Windows report completed the source-link identity inventory successfully; it did not verify render authority.


## V5 optional live native projection-cache reader

Use `Run-PlayerCamera.ps1 -ProbeProjection` in the pinned Free Fire Training scene, held stationary. Choose this switch or `-ProbeCameraIdentity`, not both. Default pose and the V4 identity mode remain available. This mode adds live guest-memory reads; it is no longer just an offline checker. The user V5 Windows report passed identity/source checks and returned ViewDirty=1 / ProjectionDirty=0; matrices were correctly withheld.

The reader repeats the full local-player/main/controller identity inventory in the same observation set and requires both transform and controller links to match the original selected native Camera. It verifies new pinned IL2CPP/native registration, wrapper, managed-native extraction and complete matrix-helper code anchors. Both live injected-wrapper cache pointers must already equal the corresponding pinned Unity entry addresses. Null pointers return NOT_READY_BINDING_UNINITIALIZED; a different target returns NOT_READY_BINDING_MISMATCH. No resolver/getter/initializer is invoked to populate them. These wrapper caches might remain uninitialized even when the game renders normally; this reader will withhold values in that case.

The native helpers' observed clean-cache branches return two 64-byte data sequences. Both dirty bytes must be zero. The reader samples those sequences, reads them again in reverse order, rechecks dirty flags, and finally rechecks every source/code/binding/data observation plus process identity. It rejects nonfinite, excessively large (>1e12 absolute), zero or numerically rank-deficient matrices. Rank rejection is conservative (row-scaled pivot threshold 1e-12), not proof of correct camera semantics. Changing data/context produces NOT_READY_SOURCE_CHANGED with no tentative pointers or matrix arrays; dirty or invalid data produces an unready status without arrays. Transport/schema failures fail the runner and still clean up.

Success is `CameraProjection Status=SAMPLED_CLEAN_CACHE_READ_ONLY`. Exactly 16 invariant-culture float-derived numbers are printed per `CameraViewNativeSequence` / `CameraProjectionNativeSequence` line. They preserve native byte sequence order. They are **not** automatically transposed, assigned a graphics convention or fed into the offline screen-pixel checker. Source equality, clean flags, numerical checks and repeated reads do not establish an atomic frame, freshness age, actual render camera, GPU projection variant, coordinate convention, viewport, FOV, shot direction or LOS. Those remain explicitly UNVERIFIED/NOT_READ. FOV getter may have state-changing behavior, so it is not called or emulated here. No aim output is implemented.

This added mode has a 9000-call phase cap; existing identity mode retains 6000 and the overall 30000-call/timeout limits remain. It does not automatically retry a changing sample or reuse a stale one. The synthetic fixture uses 5147 additional physical calls. Real reads differ; a module scan retry may exhaust the global limit. Fifteen synthetic-memory checks cover clean data, raw sequence preservation, both dirty flags, null/different bindings, code changes, identity disagreement, invalid matrices, data/dirty/context changes and budget suppression. Five tests exercise the actual PowerShell renderer including fr-FR culture and no-value failure output. These are host tests, not a Windows live success claim.

`Build-ProjectionReference.py IL2CPP UNITY TRUSTED_MAPPER REFERENCE_CS EVIDENCE_JSON` reproduces the generated anchors from the full SHA256-pinned inputs. Original 124 V52 baseline files remain unchanged inside the ZIP. The source profile is pinned to Free Fire com.dts.freefireth v1.132.1 and does not imply Free Fire MAX support.


## V6 dirty-view fallback integration (current)

Run the same `Run-PlayerCamera.ps1 -ProbeProjection` command. The runner now reports PlayerCameraProbeVersion=6. Default pose, identity and the clean-cache path remain available. Live Windows V6 execution is pending.

When view dirty is nonzero **and projection dirty is zero**, the reader can return `DERIVED_VIEW_WITH_CLEAN_PROJECTION_READ_ONLY` with `ViewSource=DERIVED_FROM_RECHECKED_TRS`. It does not use the dirty view-cache bytes. It retains the existing requirement for matching player/main/controller identity and both already-initialized pinned wrapper targets. A dirty projection still blocks output; no projection/FOV recomputation is implemented.

The fallback verifies added exact arithmetic-code/constant anchors. It reads the runtime native Transform type range used by the source component lookup, finds its first matching owner component, and requires that pointer to equal the player/main Transform already observed. An unavailable/inconsistent type range returns NOT_READY_TRANSFORM_TYPE, without a guessed component. The existing bounded hierarchy reader validates owner, capacity, index, parent links, cycles and zero job state. It captures selected TRS rows child-to-root, rereads them root-to-child and rechecks jobs. The final observation pass rechecks all identities, source code, type range, components, hierarchy/backlinks/TRS, dirty bytes and projection data before any matrices are published. Motion/state changes discard everything; transport/schema failures still fail with cleanup. There is no forced job completion or retry loop.

Host C# computes the verified `Z flip * rigid inverse(position, adjusted rotation)` formula from those observed TRS values. It uses double matrix arithmetic after the existing float hierarchy composition. This is an approximation to the traced float/SIMD arithmetic, not a bit-for-bit emulator. Parent scale magnitude/sign behavior is preserved by the existing hierarchy composition; it does not invert a full scaled matrix. The output `CameraViewNativeSequence` line retains native-compatible column-major sequence order for this derived arithmetic; `ViewSource` distinguishes it from cache bytes. It does not establish the projection matrix convention, graphics projection variant or screen coordinates.

The game's dirty flag and caches are never written. Remaining limits are unchanged: render authority, atomic frame alignment, cache age, viewport, FOV, shot direction and LOS are unverified. The getter's uninitialized metadata gate is not forced. Same-frame landmark verification remains pending. The 9000-call optional phase, overall 30000-call/timeout limits and 124 immutable baseline files are retained. The one-node derived fixture uses 6272 additional physical reads; Windows usage varies and may return NOT_READY.

Current host checks: 27 pose + 15 identity + 15 projection + 151 derivation checks (208 total). Derivation includes 137 C# comparisons with isolated ARM64 outputs, full live-reader fixtures with parent rotation/nonuniform/reflected scales, unknown type/job rejection, code/cycle rejection, TRS/job/projection mutation suppression, partial-capture budget exhaustion and fatal transport behavior. Six authored projection-renderer cases include the derived status and invariant numeric formatting. No live frame correctness is inferred from those tests.

`Generate-DerivedViewGolden.py UNITY TRUSTED_MAPPER VERIFIER_DIRECTORY OUTPUT_FRAGMENT` reproduces the 137 C# math cases using the separately published dirty-view-verification package and its pinned Capstone/Unicorn dependencies. The output fragment was compared byte-for-byte to the compiled fixture source. Those dependencies are needed only to regenerate arithmetic evidence, not to run the Windows live reader.


## V7 independent landmark-source candidates

`Run-PlayerCamera.ps1 -ProbeLandmarkSources` is a separate optional mode, mutually exclusive with projection/identity switches. It reuses the already pinned typed roster, membership validation and native head-transform readers. Positions come from object hierarchy/TRS, independently of camera projection math. It does not run a camera matrix sample in the same invocation. Old camera matrices must not be silently paired with new source points.

Source-only mode allows at most 14000 additional physical calls, reduced to leave 500 of the unchanged global 30000-call cap for completion. Underlying roster/head limits and at most two other sampled objects remain unchanged. Schema, transport and context failures retain their fail/withhold behavior. No targets are presumed visible, stationary, hostile or valid calibration landmarks. At most two head coordinates cannot meet the comparison tool's minimum four-point requirement.

The output labels each point LandmarkWorldCandidate with roster index, source and selected-entry membership proof. It reports source method times, not render-frame synchronization. Source-mode screenshots can support manual object association later; projected screen locations must not be used as the sole evidence to identify which object supplied a world point. Static/visible association and fresh camera-frame pairing remain unverified. Zero candidates or a budget stop does not establish absence of objects.

Three added host checks verify an independent coordinate oracle, partial-budget withholding and compatibility of the verified context with existing APIs. Together with the existing 208 checks, 211 selected host checks pass. Windows V7 source-mode execution is pending. All 124 baseline files remain unchanged.
