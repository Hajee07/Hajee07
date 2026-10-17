# Integration review: reusable infrastructure, live binding blocked

This review uses **V52**, not V49, as its current runtime baseline. The uploaded
V49-Targeting-Advanced library supplies four unchanged engine-independent sources.
Changes live in this separate directory; the reader, original library, manifests,
native plugin, security settings, licensing and bounded read policies are unchanged.
No AGENTS.md was found in the inspected workspace/repository paths.

## Build and run

From this directory in a checkout or extracted review source package:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ReviewChecks.ps1
```

This builds C# 5 with warnings treated as errors, verifies the packaged source manifest when present, and runs the owned simulation,
validation/lifecycle tests, geometry contract cases and a real scheduled timer
expiry test. It does not require or connect to BlueStacks. A new PowerShell
process avoids duplicate loaded types. The source package needs the sibling
`targeting-offline` folder containing the four library sources.

Optional full-checkout source compatibility check:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ReviewChecks.ps1 -MappingSourceDirectory ..\bluestacks-process-map
```

Cloud validation used PowerShell 7.4.6 on Linux. Fresh Windows/.NET Framework
execution and live gameplay were **not** tested. PowerShell `Add-Type` compiler
options support is required; no newer C# language features were introduced.

Full-checkout baseline reproduction (Python 3):

```text
python Verify-Baseline.py --extension-zip /path/to/V49-Targeting-Advanced.zip --report baseline.json
```

The optional upload is checked as ZIP data, never loaded as a DLL/EXE. This auditor
requires the original sibling runtime archive, source package manifest and all its
48 listed source/evidence files; these are in the repository, not the minimal
review ZIP. Package consistency is not publisher authentication.

## Dependency map

```text
V52 read-only reader
  -> camera pose/controller evidence [historical sample; active camera UNKNOWN]
  -> target-state provider [generation/life/hostility proofs UNBOUND]
  -> measured world-space head provider [live tracking UNBOUND]
  -> authoritative LOS provider [UNBOUND]
  -> unchanged AdvancedController / AimCoordinator
  -> ExpiringCommandLease [owned local simulation only]
  -> live engine output adapter [BLOCKED]
```

`ObservationPipeline` consumes explicit provider proofs; it does not create them
from memory addresses or infer them from field names. `TargetObservation` keeps
identity, nonlocal status, hostility, alive, attackability, membership, head identity,
world space, not-dying, not-reviving and not-spectating separately as Yes/No/Unknown.
A No or Unknown candidate is excluded. Its proof and rejection remain available
in `ValidationResult.Assessments`. Aggregated Eligibility summarizes candidates;
it is not an output permission. Only accepted candidates enter the Frame.

A batch needs proved coherent context, a complete roster, a verified camera,
a provider epoch/session, sequence and capture start/finish times on one monotonic
clock. Complete-roster assertions are a host responsibility, not inferred by counting.
Head samples preserve measured coordinates and capture uncertainty; no prediction,
interpolation or smoothing is performed. Bone names alone are not proof: the
provider must establish HeadIdentity and WorldSpace. Stale samples disappear.

Identity keys combine length-delimited process/emulator epoch, match session,
provider object identity and generation. Providers must supply authoritative
lifetime/generation evidence; an address or repeated pointer read does not satisfy
Identity. Despawn, invalid/uncertain batches and rejected samples remove prior
heads; generation changes produce a gap and a separate key. Epoch/session changes
require an explicit pipeline reset and output recovery/recreation. Unsupported
states and camera modes must remain Unknown.

Use the clock-taking `Accept(batch, clock)` overload in hosts: it checks time again
after validation and rejects work taking over min(8ms, max sample age). The explicit
`Accept(batch, now)` overload is for callers owning the observation-time contract,
such as deterministic tests; it does not measure processing duration itself.
The coordinator checks age again after LOS/selection, authority validation and
before submission. The lease rechecks context, sequence, generation-bearing key,
unit direction and expiry under its local application lock.

## Output semantics and bounds

`ExpiringCommandLease.TryApply=true` means **stored in a local memory lease**, not
queued/applied/acknowledged by a game. It implements the existing adapter contract
for the owned simulation. Explicit Enable is required. Disable, Clear, replacement
publication, context loss, expiry, disposal and faults revoke the stored command and authorization. Re-enabling requires a fresh publication.
Each sequence may apply at most once, so a revoked command cannot be replayed.
Clock failures/context changes latch a reported fault. Recover clears all context
and requires new publication plus explicit Enable; reset/recreate the coordinator
when its session changes. Recovery never resumes an old command.

A positive watchdog period starts a managed Timer; zero requires host-scheduled
Poll. The timer can revoke without new observations. Snapshot also checks expiry.
Timers have scheduling jitter and are not real-time guarantees. A future external
actuator must enforce expiry/revocation itself on its required execution thread;
clearing this local lease cannot undo an external effect. No generic thread wrapper
can invent that actuator's threading or acknowledgement contract.

Pipeline capacity is at most 4096 targets; configured tests use 16. IDs/context
components are bounded to 256 characters and bone labels to 128. Stored samples
are limited to the current accepted roster, with no unbounded history. Caller
serializes pipeline access. Lease access is locked. Existing controller candidate,
ray, angular-change and time limits remain in force. Synchronous budget checks
cannot interrupt a hung clock, LOS provider, authority callback or engine call.

See [evidence matrix](EVIDENCE.md) for task statuses and
[integration guide/experiments](INTEGRATION.md) for missing live contracts.
