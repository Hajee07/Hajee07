# V33 bounded native hierarchy-job retry

Live Windows validation pending. Rerun `Run-ProcessMap.ps1 -ProbeWeaponAmmo` to
exercise the previously accepted counter path and the revised native sampler.
No field mappings, native code references or plugin ABI changed.

## Problem and resulting behavior

In the V32 report, two local-head attempts were discarded for TRS motion. The
third saw Hierarchy.JobHandle change during final recheck and returned FAIL.
The counter phase independently accepted value 2 / field 105. No head coordinate
from that report is valid.

V33 treats a precisely scoped job-handle/tag transition as a discarded attempt,
not a usable sample. A fresh attempt may succeed only after all original code,
bindings, hierarchy/index/backlinks, zero job state and two TRS captures pass.
Job and TRS transitions share the existing maximum of three total attempts.
If the last attempt changes a job, status is NOT_READY_HIERARCHY_JOB_CHANGED.
A fresh attempt that sees a stable pending job still returns
NOT_READY_HIERARCHY_JOB_PENDING without synchronizing or retrying pointlessly.

## Identity precedence and bounds

Ordinary ObjectReads.Recheck behavior remains strict. The native-only recheck
recognizes only the exact hierarchy address / 8-byte Hierarchy.JobHandle and
hierarchy+8 / 4-byte Hierarchy.JobTag observations. It records a changed job,
then finishes every remaining identity comparison. Any non-job change, transport
error or budget failure takes precedence; none enters the job retry path.
Only after all other observations match does it throw the dedicated job-change
exception. A changed job never passes recheck or publishes coordinates.
No snapshots are overwritten or carried forward into a retry.

Local and optional nonlocal head samplers share this behavior. Other-head
membership, context, phase-final verification and read reserve remain intact.
Non-job hierarchy pointers, managed/native pointers, parent links, code and
backlinks remain hard failures. Labels and exact addresses/sizes must all match
before a difference can be classified as a job transition.

There is no new sleep, job synchronization, VM pause, initialization or memory
write. Attempts never reset reader-global call/time budgets. Global bounds
remain 30000 physical calls / 120 seconds; optional phase bounds and reserves
are unchanged. Stable-path physical read counts remain unchanged.

## Validation

635 offline checks pass. Nine added cases cover settled handle/tag transitions,
persistent changes with exactly three attempts and no coordinates, hard identity
precedence before/after the job in reverse recheck order, transport errors,
combined TRS/job retries sharing one allowance, stable pending tags and hard
managed/native pointer mutations. Two prior job-transition tests now assert
fresh-attempt / pending outcomes for local and remote samplers. Existing strict
identity, transport, membership, schema and budget cases still pass.

Extracted-package checks compile C# 5, run the full suite, parse PowerShell,
verify nine mutually exclusive modes and validate all source/plugin digests.
Offline tests do not guarantee the live hierarchy will settle. Head, roster and
counter phases are sequential observations, not an atomic game snapshot.

Inspect NativeHeadSampleJobChange, LocalHeadWorldPosition, SelectedWeaponAmmoCounter,
WeaponAmmoField, cleanup statuses and ResultFile. The earlier counter success
does not establish magazine/reserve, full readiness, LOS or aiming.
