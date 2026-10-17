# Current user-supplied V52 capture assessment

[v52-current-capture.json](v52-current-capture.json) records the strict parser result
and limited facts from the newly uploaded console transcript. The original transcript
is identified by SHA-256, not published here with its user-local paths. This is a
user-supplied live observation, parsed offline; it is not independent live validation.
No capture timestamp was supplied, so observation age cannot be established from
upload order. Never use this saved text as a current output-authority token.

Reported evidence: VMM/module/layout checks pass; local head motion on attempt 1
was rejected and attempt 2 sampled. The roster has 13 objects, 12 nonlocal; a
Player_Watching class is present. These are not 12 verified enemies. This aim-state
mode samples zero nonlocal heads. Native pose/controller link and object-null data
are reported verified within their narrow source/data scope. Getter metadata guard
is still zero; active gameplay camera and shot direction remain unknown.
Total reads are 24272, with 5199 in the optional aim phase. Cleanup passes.
No aim writes occurred. No runtime code or packaged source was changed.

Validation: the existing strict V52 assessment accepts the transcript; removing
plugin-unload evidence makes it reject. All missing live-binding proofs remain
Unknown and LiveBindingReady=false.

## Next controlled observation

Use the existing unchanged Run-CameraPoseCheck.ps1 from the extracted V52 package.
It guides eight manual stationary/right/restore/left/restore/up/restore/down captures.
Record the rendered game and the displayed stage together so screen movement can
be compared with the sampled pose. Keep the same Training session and do not move,
fire or aim-down-sights during a capture. Record build/mode and any timing uncertainty.
Keep the comparison JSON and its referenced eight raw result files together.

This checks pose/movement conventions for the observed scope. It does not by itself
prove which camera renders the view, which direction a shot accepts, full target
lifetime/eligibility or LOS. Do not force metadata initialization or reinterpret
those remaining Unknown facts as Yes. Repeating a stationary sample cannot resolve
the missing rendered-view/shot relationship or output ABI/thread contract.
