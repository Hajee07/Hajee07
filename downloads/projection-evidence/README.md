# Viewport and screen-landmark evidence capture

Current goal: collect visual evidence first. The user has no independently known world-coordinate landmarks yet. A reprojection accuracy result therefore remains pending; this kit never manufactures world positions from the matrices being checked.

## Windows capture

Keep the spawned Free Fire Training scene/camera stationary, and use 64-bit Administrator Windows PowerShell:

```
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Capture-ProjectionEvidence.ps1
```

The download ZIP includes the unchanged checksum-pinned V6 camera package under camera/. No Python, Node, extra Windows SDK, new DLL or downloaded third-party DLL is needed for capture/review. The default ADB path is C:\Program Files\BlueStacks_nxt\HD-Adb.exe and endpoint is 127.0.0.1:5555. Pass -AdbPath / -Device only if your existing installation differs. The V6 runner retains all its build, identity, source, budget and cleanup checks.

The helper connects to the existing local ADB endpoint, requires Free Fire running, captures a guest PNG, runs one V6 projection probe, and captures a second PNG. Binary screenshot transport uses exec-out, not PowerShell text redirection. ADB requests time out; PNG header dimensions and <=32 MiB size are checked. PNG header checks do not constitute a full image decode; the review page also requires the browser to decode the image.

Both screenshots and the report are hashed. Successful ready-report parsing, stable guest PID, stable image dimensions and report-method interval within child invocation are required. Changed PID/dimensions or an unready report produces INCOMPLETE_CAPTURE with no accepted matrix object. Files are retained for troubleshooting. Transport/preflight failures can leave a partial output folder; do not treat it as a completed bundle.

The helper prints EvidenceDirectory and EvidenceZip, normally in Downloads. Share that generated ZIP for review. It contains guest screenshots and process diagnostic data; review it before sharing. No screenshots or reports are uploaded automatically.

## Measure the viewport

1. Open review.html inside the output folder. Keep all evidence files together.
2. Choose Before or After. Confirm both views appear stationary; animation/weapon/HUD movement alone does not establish camera movement or render synchronization.
3. Click “Mark viewport” and click two opposite corners of the actual game render area. If the entire image is the game render area, explicitly choose the full-image button instead.
4. Save viewport-review.json and share it with the original EvidenceZip. The JSON is labeled USER_DECLARED_RECTANGLE / PENDING_LANDMARKS, not a verified render viewport.

Screenshot dimensions are guest pixels, not Windows window dimensions, desktop DPI or emulator border sizes. Click positions are converted from displayed canvas coordinates back to natural image pixels. A screenshot's full dimensions do not automatically prove the active camera viewport or exclude letterboxing/cropping. Hashes in evidence.json/files.json must be checked against the original files separately; a browser click report is not an authenticity proof. The browser does not independently verify the screenshot's file digest.

## Future landmark comparison

The optional page can load landmarks-template.json after real independent world coordinates and their evidence source are available. The template intentionally contains null positions and is rejected as comparison input. Do not substitute guessed values or inverse-project chosen screen pixels. Use four or more distinct static visible landmarks with useful spatial spread, measured from the same scene/pose as the camera observation.

Select each landmark and click its visible image location. Predicted points remain hidden until all points are measured. Explicitly select the candidate matrix and clip-depth conventions, then compare. The tool never silently chooses/transposes a convention to produce a match. Exported match/mismatch reports include per-point errors, RMS and maximum errors. Labels remain supplied-data-only, actual rendered camera UNVERIFIED and frame alignment UNVERIFIED even on a numerical match.

These screenshot requests bracket a multi-read memory probe; they are not atomic render frames. Stationary appearance and hashes do not establish frame synchronization, cache age, projection variant, LOS, aim output or hit registration. Old screenshots cannot retroactively validate an earlier V6 matrix sample. This capture step supplies dimensions/images/timing evidence; it does not complete live screen accuracy validation without world landmarks.

## Host validation and limits

- 16 JavaScript geometry/data-rejection checks pass.
- PowerShell ready/duplicate/failed/unready/nonfinite/short/timing report cases, PNG dimension/header checks and parser checks pass.
- Four mocked collector flows pass: ready, changed PID, resize, unready probe. Native ADB, PowerShell child invocation and screenshot transport are replaced only in generated test scripts. The authored production collector has no mock mode.
- Simulated DOM tests exercise natural-pixel canvas scaling, viewport export, manual landmark comparison and stale-result suppression. They are not a real-browser test.
- The actual user-uploaded V6 report parses successfully as saved-report data. Windows screenshot capture and browser interaction on the user's laptop are pending.

Developers can run test-core.js / test-review-ui.js with Node, and Test-ProjectionEvidence.ps1 / Test-CaptureOrchestration.ps1 with PowerShell 7. These test tools are not needed for the Windows capture command. No game getters/resolvers are called and no game memory is written by the new helper; the unchanged V6 reader performs its existing read-only diagnostics.

## Screenshot metadata recovery (v2 helper)

A user Windows run passed V6 and cleanup but failed collector metadata processing with "The property 'Width' cannot be found on this object." The screenshot copy task's GetResult call could emit an internal task-result object into PowerShell's success pipeline, producing an array instead of one screenshot record. The collector now explicitly suppresses that return with [void]. A regression test injects an object-valued awaiter result into the authored expression: old code emits two objects; fixed code emits only the metadata record. This reproduces the suspected pipeline cause on the host; actual Windows 5 task behavior remains to be confirmed by the saved JSON or fixed live capture.

Do not repeat the successful V6 game probe just to repair this saved metadata. Run:

```
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Recover-ProjectionEvidence.ps1 -SourceDirectory ORIGINAL_EVIDENCE_FOLDER
```

Recovery supports only the saved Schema 1 Width-metadata failure. It checks original files.json hashes, report digest and successful V6 report, PNG headers/dimensions, exactly one complete screenshot record per role and valid screenshot intervals bracketing the saved projection method. Only one empty/null serialized task artifact per role is ignored; unknown nonempty objects, competing metadata records, changed hashes/dimensions, bad timing or a different failure are rejected. No new game read, getter call, screenshot or write occurs. It does not re-query game PID or claim fresh process identity. The result is saved-files-only evidence.

A new sibling folder/ZIP is created; original metadata is copied as original-evidence.json. Original source files are retained unchanged. Status becomes PENDING_LANDMARKS only if all saved-file checks pass. Render-frame alignment, camera authority and actual viewport remain unverified. If saved metadata cannot be recovered, retain/share the original evidence ZIP for diagnosis instead of editing it or forcing a success status.

Seven host recovery/regression checks pass (valid recovery, ambiguous metadata, bad timing, unknown object, different failure, modified image, awaiter leakage suppression). The unchanged V6 package is still bundled. Windows saved-file recovery execution is pending.

## V3 recovery: Windows PowerShell 5 JSON root arrays

A subsequent user run stopped at the original evidence.json integrity check. The old expression wrapped a ConvertFrom-Json pipeline inside @(...). Windows PowerShell 5 can return the complete JSON root array as one pipeline item; this produced a nested manifest and compared a single digest with an array of digests. A host test using non-enumerated JSON arrays reproduces that misleading error. It does not prove the user's actual files are unchanged.

Recovery now assigns decoded JSON first, explicitly enumerates and validates scalar manifest records, requires exactly one entry per critical file, and compares the actual SHA256 against that entry's scalar digest. A genuine mismatch still stops recovery and reports Expected and Actual hashes. Nothing is rehashed into the old manifest to make a mismatch pass. Original files remain untouched.

Nine saved-file/awaiter checks pass under both current and emulated Windows PowerShell 5 root-array behavior. Added cases reject modified evidence.json bytes and duplicate manifest entries. Legacy-mode tests also reproduce the old nested-array comparison. The actual Windows 5 updated recovery run remains pending; no compatibility claim is based on PowerShell 7 alone.
