# Verification and acceptance criteria

Run `dotnet run -c Release -- test`. It fails with exit 1 on an assertion or service error. Tests run real loopback HTTP servers on dynamically selected ports, then stop only their own instances. No emulator, proprietary binaries, public game server or user account is used.

The suite covers:

- Analytic sphere entry, tangent, inside-origin, miss, finite range and invalid bounds.
- Nearest body collider beating a head collider behind it.
- Known quaternion rotation, invalid quaternion, translated/rotated owned skeleton.
- Zero-gravity time-of-hit oracle and independently placed gravity projectile intersection.
- All six regions under both classification policies, preserving geometric truth and claim disagreement.
- Misses, walls, unknown sessions, duplicate sequence, zero/nonfinite direction.
- Actual HTTP readiness/page serving/scene/session/shot/report generation; malformed and oversized requests; service readiness after invalid inputs.
- A simulated 10ms server response delay and observed request RTT samples.

## Reading results

Client `--report` records all six rows. `geometricAgreementWithAnalyticCenter` counts accepted server region matches to independently chosen sphere centers. `serverPolicyAgreement` counts accepted awards matching the startup rule. `claimDisagreements` counts false Head claims against actual collision. With normal unobstructed geometry, expected counts are 6 geometric agreements and 6 policy agreements, with 5 client claim disagreements. With the wall: 0 accepted; this is not a zero-percent geometric classifier—no hit was admitted.

Conversion policy is expected to yield 6/6 Head awards in this fixture; geometric mode yields 1/6. This does not measure perfect aiming or commercial-server susceptibility. The all-headshot rule changes an owned server's award, not where the projectile intersects.

RTT is measured with a monotonic Stopwatch around HTTP request+response deserialization. The JSON report includes median and nearest-rank p95 over six observations. Six is a smoke sample, not a statistically credible latency distribution; p95 equals its maximum. No one-way delay, clock synchronization, internet jitter or packet loss is measured. Browser performance timestamps are also local round-trip measurements.

`evidence/tests.txt` and `validation.json` report the actual run environment, counts and pending checks. `evidence/v48-compile.txt` records a source-only V48 build. The test-game page is fetched through HTTP; visual clicks and native Windows execution remain separately untested. Published `app` assemblies require .NET 8 and were executed on Linux, not on the user's Windows laptop.

## Experimental controls

Run geometric, convert and wall modes as separate server processes. Preserve command lines and JSON outputs. Always retain geometric region, claim, award, rejection reason and scene revision. Compare the same deterministic target center rays. Do not label the client claim as server acceptance. Do not combine results across different game rules/builds and assume equivalence.

For a future dynamic authoritative game, add server-owned tick snapshots, validated player identity/origin, ammunition/fire cadence, collider/pose history, duplicate-shot IDs, deterministic projectile sweeps and an explicit bounded rewind policy. Tests must show that changing only the client region claim cannot alter server adjudication unless the server policy intentionally permits it.
