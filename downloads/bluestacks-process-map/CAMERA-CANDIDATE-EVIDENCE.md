# V43 bounded native camera-component candidate discovery

Live V43 Windows validation pending. Run `Run-ProcessMap.ps1 -ProbeAimState`
with the game running, camera steady. It preserves the original local Quaternion,
source/native-code identity and read-only checks, then attempts bounded native
camera-component candidate discovery. No turns or controls are automated.

## Verified source path and remaining selection rule

The exact Unity Camera.main entry calls native selector 0x608a98. That selector
loads the tag manager through getter 0x52aa2c (global cell RVA 0x143dd68), looks
up literal tag 5 through 0x471588/0x47163c, walks its native list, finds a component
using type descriptor RVA 0x1409040 through 0x52aeac, and calls a virtual predicate
at native component vtable+0xd0. Only a predicate result with bit 0 set selects
that component. The managed wrapper path 0x720de4 also includes synchronization
and possible wrapper resolution, and is not emulated or executed here.

Build-TransformReference.py derives/verifies the manager cell and descriptor
from the exact ARM64 instructions and asserts literal tag 5. Complete selector,
global getter, tag lookup/hash and component lookup code join a separate
CameraSelectorAnchors array, checked and exactly rechecked by ObjectReads.
Existing head anchors, native-code identity and limits are unchanged.

The probe translates the recovered unsigned tag hash/probe order. It requires
a canonical bucket pointer, low-three-zero mask with power-of-two capacity
2..4096, probes at most 16 slots of 24 bytes, and accepts only matching stored
hash/key 5. Empty, null, unsupported/bounded cases produce explicit NOT_READY.
At most two native list nodes are visited in source order. Sentinel/node links,
canonical pointers, previous links and visited-node cycles are checked and
snapshotted. Node game-object component headers and up to 256 16-byte records
are bounded snapshots. The source's unsigned type-range test is preserved.

A candidate additionally requires native component owner+0x30 to match the tagged
game object, a canonical vtable and a four-byte-aligned predicate pointer within
the reference Unity executable PT_LOAD address range. Its predicate function
address and RVA are recorded only. Its code/semantics are not yet independently
verified; it is never invoked. A candidate is NOT the selected Camera.main.
The scan stops at the first matching component and does not treat an unevaluated
predicate as true or search past it for a supposedly selected camera.

## Output and snapshot scope

NativeCameraCandidate reports TYPE_RANGE_CANDIDATE_ONLY or a NOT_READY status,
NativeObject/Owner/PredicateFunction/PredicateRVA and visit counts. PredicateEvaluated
is always False, MatchesCameraMain=UNVERIFIED, ManagedCamera=NOT_READ and
CameraPose=UNVERIFIED. All recorded source/data bytes, native roots, ranges,
selected links/components/vtable/owner/predicate and local context/value/gates
must survive exact rechecks. Changes/faults/budget exhaustion discard tentative
candidate and Quaternion data. Null manager/type range/cache is not initialized.
Global roster flags remain audited with selected-local proof.

No native functions, locks, synchronization, managed wrapper resolution, memory
writes, VM pause or game getter/hotfix routes are invoked/emulated. No full-list
scan, predicate truth, managed camera, actual camera pose, camera/shot convention,
LOS, eligibility or aiming is claimed. V43's binding/code lines explicitly label
selected camera unverified and managed camera unread, because this new phase
may read native candidate fields. Prior manual correlations retain their scope.

## Bounds and validation

858 offline checks pass: previous 836, 20 new candidate/source-mutation/bounds
cases and two V43 compatibility cases. They cover recovered hash golden value,
first/second node, collision stepping, null manager, missing/empty tag list/type
range, probe/node/component limits including 256-record boundary, malformed mask,
owner/predicate/link/cycle refusal, changed selector, changed component snapshot
and original phase ceiling. Candidate fixture=3979 additional reads; null-manager
fixture=3843. All other mode phase costs remain unchanged. Existing global
30000-call/120-second, 6000 phase and 1500 final-reserve limits remain intact.

Reference generation reproduces byte-for-byte. C# 5 compilation, PowerShell
parsing/ten modes, all source/helper/plugin hashes and extracted-package checks
pass. Live V43 remains pending. The next needed evidence is the bounded native
candidate and its predicate RVA, so predicate source can be verified before any
claim about selected Camera.main or actual camera pose.
