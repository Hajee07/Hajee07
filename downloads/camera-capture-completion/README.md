# Complete the interrupted camera experiment, preserving six reports

## Restart-safe alternative: fresh mode

The newest report has a different host process (6896 versus seed 23976). The
identity guard correctly rejects old/new sample mixing. **Use -Fresh after a
restart or when the old baseline is no longer reproducible.** This mode imports
zero saved reports and captures stages 1–8 from the current process. It does not
remove context checks. All new samples must remain in the same anchored process,
match and native camera context; a change mid-run still aborts with a journal.

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass `
  -File .\Complete-CameraCapture.ps1 `
  -SourceDirectory 'C:\path\to\original-extracted-v52' -Fresh
```

interrupted-seed.json and prior assessment files are retained for historical and
same-context seeded review only. They are not used in fresh mode. The uploaded
managed/native reference assessment is in ../phoenix-reference-review/README.md.

## What the helper changes

Complete-CameraCapture.ps1 imports the six specifically named reports in
interrupted-seed.json, parsing each file rather than trusting a prior PASS label.
It pins the four V52 source/manifest hashes before dot-sourcing helpers or running
the original reader. It requires all imported and new captures to share process,
guest, module, player, match and native camera identities. Filenames are bounded
basenames, duplicate reports and path traversal are rejected, files are size
bounded and their hashes are rechecked after parsing.

The helper journals accepted stages and failed attempt metadata. Fresh mode
requests all eight stages; seeded mode requests
RESTORE (stage 7, return to stage-5 landmark) and DOWN (stage 8). Each stage has
at most two attempts, with a fresh manual READY before each. A nonzero reader
exit does not become a valid sample. Additionally, an exit-zero report with the
specific zero-sample/collection-change records and successful cleanup is recorded
as rejected and can request the next bounded manual attempt. It is never added
to accepted reports. Other parser/context failures stop immediately.
Partial evidence stays in the journal even if completion fails; existing
journals are not replaced on a new invocation. A new invocation starts from the
same six seeds, not from an unvalidated partial journal.

The underlying V52 native plugin, reader, source checks, two internal roster
attempts, global/phase read limits and per-capture timeouts are unchanged. Up to
four new child captures in seeded mode, or sixteen in fresh mode, are possible; there is no automatic
unbounded retry. No initialization is forced and no game memory is written.

## Seeded completion on the same Windows session

Keep the original extracted V52 directory and its six report files. If the game,
emulator/process, match or camera context changed, do not combine old and new
captures: restart the original full eight-stage experiment. A same-address reread
is not proof of object lifetime. This tool only checks the stated saved-report
identity context; it does not establish global atomic snapshots or generations.

Extract the completion ZIP to a new directory and run Administrator PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass `
  -File .\Complete-CameraCapture.ps1 `
  -SourceDirectory 'C:\path\to\original-extracted-v52' `
  -SeedFile .\interrupted-seed.json
```

Do not move the character, fire or aim-down-sights. Restore the same landmark's
stage-5 centre/height for stage 7; then tilt down for stage 8. Record game view
and stage prompts together. The final ComparisonResultFile or PartialJournal is
the evidence to share. Imported report capture intervals remain unknown; saved
file modification times are not substituted for synchronized observation times.
New attempt intervals use host UTC wall-clock labels, not synchronized monotonic
render/game times. No saved report authorizes a current aim command.

`-ReviewOnly` imports/validates six reports without invoking a native process.
`-AdditionalReportNames` accepts exactly two existing basenames for offline
comparison; it does not claim they were captured now. All comparison results
retain ActualGameCamera/ShotDirection/LOS UNVERIFIED and LiveBindingReady=false.

## Validation and scope

Run Test-Completion.ps1 with -MappingSourceDirectory pointing to the pinned V52
source directory. Cloud PowerShell 7.4.6 executed 54 existing pose assertions and
20 new completion checks. Tests include partial evidence, duplicate/context/
cleanup rejection, helper tampering, path traversal, simulated rejected child
attempts, exit-zero zero-sample collection churn, completion only after strict valid
samples, stopping after two rejected attempts and fatal failed-cleanup handling. Child
execution and prompts are stubbed in those tests; no native process/plugin is
invoked. Fresh-mode tests additionally cover a new initial PID without imports, stage ordering,
initial zero-sample retry and rejection of process changes mid-run. Real Windows
child launch remains NOT_TESTED here.

The actual six uploaded reports were also accepted in ReviewOnly mode. The
seventh rejected report was not imported. See interrupted-assessment.json,
validation.json and test-summary.txt. The uploaded transcript is referenced by
SHA-256 rather than publishing its user-local paths. This ZIP is a capture helper,
not a new runtime version or live aim integration.
