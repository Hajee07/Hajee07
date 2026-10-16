# V34 manual HUD correlation experiment

Run `Run-AmmoCounterCheck.ps1` in Administrator Windows PowerShell with the
supported BlueStacks/Free Fire instance running. Interactive Windows validation
is pending. This tool automates read-only captures and comparison, not gameplay.

1. In Training, equip one firearm and stop firing/moving. Enter the HUD loaded
   ammo number at the baseline prompt. The tool captures a full -ProbeWeaponAmmo
   report and verifies its accepted counter contract and cleanup.
2. At the next prompt, fire exactly one shot manually, stop firing, then enter
   the new HUD loaded-ammo number. A fresh read-only capture runs.
3. At the final prompt, reload manually, wait for completion, then enter the HUD
   loaded-ammo number. A third fresh capture runs.

Keep the same weapon and character. Do not type reserve ammunition as the loaded
count. No shooting, reload, keyboard/mouse action, memory write or game method is
automated. If reserve/unlimited-mode behavior prevents the expected pattern, the
result remains inconclusive; no value or policy is patched to force a match.

## Acceptance and limits

The helper/runner SHA256 values are checked against the downloaded package's
manifest before invocation. Each child process must exit successfully and return
one newly named result file inside the package directory. Reports are read as
text, never evaluated as PowerShell. Each capture must have the exact module /
APK/layout checks, accepted Int32 counter and unique field binding, verified local
membership, successful cleanup, per-phase <=6000 and total <=30000 read records.
Missing, duplicate, malformed or unaccepted records are rejected.

All three samples must agree on machine, host PID, ADB device, guest PID, module
build/load bias, player, weapon address/class and field identity. Context changes
make the comparison INCONCLUSIVE_CONTEXT_CHANGED. This guards against accidental
cross-process/weapon comparisons, not allocator ABA or cryptographic report
attestation. Each report verifies its own runtime observations.

Only a match between all three raw counter values and manually reported HUD
values, a one-unit drop after the reported shot, and an increase after the
reported reload yields CONSISTENT_WITH_REPORTED_MAGAZINE_COUNTER. Action timing
and HUD numbers are user-reported, not automatically observed. Result evidence
is always MANUAL_HUD_CORRELATION_ONLY. This cannot establish universal weapon
semantics, reserve, unlimited policy, shot completion, damage, full readiness,
LOS or accuracy. Head and other optional phases are not combined into the claim.

The three source report paths, raw samples, reported HUD counts, deltas and
remaining unknowns are saved in ammo-counter-comparison-<guid>.json. Send the
complete console output or this JSON for review. A failed capture stops the
experiment and keeps any printed source ResultFile reports. INCONCLUSIVE is a
valid evidence outcome, not an instruction to adjust checks.

Each of the three independent runner processes retains its own existing
30000-call / 120-second global bound and 6000-call optional-phase bound/reserve.
These are per-capture limits, not a shared total for all three runs. No busy-loop
or background sampling is added; prompts wait for the user's manual actions.
The direct -ProbeWeaponAmmo / -ProbeWeaponFiring and earlier modes remain available.

## Validation

659 offline checks pass: all 635 native/core cases plus 24 parser/comparison cases.
The new cases cover accepted report contracts, missing cleanup/field/layout,
duplicate counters, over-budget/incorrect scope/locality and Int32 overflow,
positive correlation, HUD mismatch, changed context, shot/reload mismatches and
invalid/incomplete HUD input. All unknown semantic statuses remain in a matching
result. Release checks parse all PowerShell files and exercise the full suite
from the extracted package. Live interactive execution remains pending.
