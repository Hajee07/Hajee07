# Static player-state research after V20

This historical V20 research now underpins the optional V21 read-only probe;
see [PLAYER-STATE-EVIDENCE.md](PLAYER-STATE-EVIDENCE.md) for implementation and
validation status. The remainder records the original research scope.

This is exact-build static evidence from the same SHA-256-verified IL2CPP ELF
and decoded metadata used by the probes. It is not compiled into the runtime
package, does not read live state values, and does not establish enemy, alive
or line-of-sight semantics. Source identifiers/registration slots are recorded
in player-state-research.json. The V20 runtime ZIP and its 248-test result are
unchanged; this note is separate repository research.

## Team index is not the complete teammate rule

Player.get_TeamIndex (method 210083, RVA 0x6f2ff24) is exactly a 32-bit load from
this+0x430 followed by return. The metadata field is the int32 backing field
<DJJMAHEIDID>k__BackingField (local index 182). The adjacent setter writes the
same storage. This establishes raw field access, not a teammate decision.

GameFacade.IsLocalTeammate at 0x71c6018 uses hotfix gate 0x3c79, object validity
checks, a current-local-player path and IsSameTeam at 0x71c6130. That method has
its own gate 0x4f5 and mode-dependent branches. One branch delegates to the
current match object's virtual method at class+0x6f8, and a fallback checks
packed player-ID data through other functions. IsSameTeam has another overload
at 0x71c86fc. Comparing two raw TeamIndex values does not reproduce this logic.
The active match policy and referenced runtime types remain to be verified.

## Dead and pending revive are separate inputs

Player.get_IsReallyDead (method 210297, RVA 0x6f36230) checks gate 0x4dd8. On
its original branch, it directly calls AttackableEntity.get_IsDead at 0x717533c
and, if true, returns the inverse of Player+0xa6c. Metadata and getter 0x6f36298
identify +0xa6c as the bool backing field for IsPendingRevive. The AttackableEntity
base getter has its own gate 0x447 and reads bool +0x7c on its original branch.

A future reproduction must validate both gates, the base class/field layout,
bool values and object identity. It must not equate a false IsReallyDead with
an alive combat target: revive, knockdown, ghost and other mode states require
separate handling. No live values or complete alive policy have been verified.

## Model visibility is not an occlusion test

Player.IsVisible (method 210384, RVA 0x6f38834) uses gate 0x21bf3. Its original
branch loads the GCommon.BitArrayBoolean reference at Player+0xad0, then calls
op_Implicit at 0x8279898. That helper reads a 32-bit mask at object+0x10 and mode
at +0x18: when mode equals 1 it returns mask != 0; otherwise mask == 0xffffffff.
It does not itself perform a camera-to-head raycast or wall/obstacle test.
The surrounding named visibility flags include camera, vehicle, alive, cutscene,
skill, streaming/PVS and other model-display conditions. A true model flag must
not be reported as clear line of sight.

Metadata virtual slot 70 resolves to the base Player.IsVisible for PlayerNetwork,
but Player_Watching overrides it with method 247113 at 0x7c6a7c4. A future reader
must validate the runtime virtual entry and support or explicitly decline each
implementation; following the base field path for every Player subclass would
be unjustified. No override behavior or actual line-of-sight path is verified.

## Validation and remaining integration

The source inputs passed their existing full-file SHA checks and metadata
ownership/token validation. Selected method pointers, field offset registrations
and correctly indexed vtable entries were cross-checked; ARM64 instructions were
inspected for the paths above. The evidence JSON contains no live state samples.
No runtime tests were rerun because no runtime code, manifest or ZIP changed.

The next state probe needs separate exact registration/code/runtime-class checks,
original/virtual/hotfix path validation, bounded read-only snapshots, and observed
state transitions on Windows. It must preserve accepted head results if the
optional state phase is incomplete. Current aim integration remains incomplete;
no target is classified and no memory write or game function is invoked here.
