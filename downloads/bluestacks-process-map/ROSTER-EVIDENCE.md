# V16 typed match Player dictionary observation

V15 passed one live local-head world-position sample. V16 adds a separate bounded
observation of one typed match dictionary. Its live Windows validation is
pending. No enemy/team/alive/visibility semantics are inferred from membership,
and no other-player head positions or aim-control writes are implemented.

## Exact source derivation

Build-RosterReference.py reproduces the JSON/C# references from the same full
SHA-256-verified IL2CPP ELF and metadata inputs used by the existing probes.

- Match base type 32133 (COW.GamePlay.JMAGGLCNGIG) field 38, NOLEDCGOJKC, has
  registered offset 0x128 and declared type descriptor 0xa5eaa60, bits 0x150004.
  Its closed type is Dictionary<COW.GamePlay.BEADLMGGGGL,COW.GamePlay.Player>.
  Key type definition is 34565; Player is 31824; Dictionary is 38851.
- Method 217520, JJPLCPCJNCC, token-resolved RVA 0x720bc30, checks hotfix ID 0x1bf
  and returns this field on its original path. The reader checks that gate and
  does not follow the field if an override is active.
- The adjacent field at 0x130 has the same exact declared closed type. Its lookup
  path at 0x720bd68 passes it to the concrete TryGetValue at 0x90231fc. This
  establishes that concrete dictionary implementation's key/value layout.
- The native lookup copies a 24-byte value-type key and indexes 40-byte entry
  records, loading Player at record+32 (array+0x20+index*40+32). FindEntry reads
  the signed hash at record+0 and next index at +4. Key bytes are neither
  interpreted as account identifiers nor logged.
- Nested Entry is definition **38845**, identified by name and declaring type;
  it is not the next metadata row after Dictionary. Metadata nested rows are
  reordered. Its fields are hashCode, next, key, value. At runtime the closed
  entry class must have boxed size 56 (16-byte header plus 40-byte value).
- Count code 0x9020c28 returns dictionary+0x20 minus +0x28. Version increment
  code 0x90220cc uses +0x2c. The full 16-byte counter header is captured.

The new references contain three full metadata definition profiles, one field
record/offset/type registration and 13 code anchors. The runtime validates the
field registration and exact original-path code, dictionary generic identity,
key/value arguments, and the entry array's closed generic element identity.
Generic class cached-class/self/name/namespace/token links and definition records
must agree. Array capacity and entry class size must match the supported layout.
No class initialization, resolver or managed function is invoked.

## Bounds and reporting

At most 256 used slots are copied, in reads no larger than 4096 bytes. Capacity
must cover the used slots and be at most 8192. Negative-hash removed slots are
counted and skipped; that count must equal the dictionary's free count. Active
next indices are bounded. Null values are counted; other values must be aligned
user-space pointers. Repeated value pointers are deduplicated. The probe does
not implement hash buckets, custom equality or entity-ID uniqueness semantics.

At most 16 unique candidate pointers are validated as supported Player classes,
including exact class metadata, size rules and parent chains. The already
verified local player is prioritized if present. Every checked object's local
marker must agree with pointer identity; another locally marked object fails.
Verified class contexts are reused within the snapshot, then all observations
are reread. Candidate pointers after the limit are explicitly unverified.

The report distinguishes used slots, active entries, null values, unique
candidate pointers, verified objects and verified other objects. Local membership
is observed, not required: this field's role among the match's several Player
collections is not established. CompleteObjectValidation describes the unique
non-null pointers in this one dictionary; it does not claim a complete match
roster or a list of enemies. Object lines are emitted only after final checks.

All observations are read-only and use the existing Reader-global 30000-call /
120-second limits, RAM/page-table checks and per-snapshot 1024-range/64-KiB bounds.
No engine lock or GC root is held. Snapshot rereads do not eliminate lifetime
races or changes that return to the same bytes. A collection failure preserves
earlier completed observations and sets runner exit status 1; it does not emit
verified roster object lines. Empty, null and overridden collections have
separate statuses.

## Head-cache version correction

The same audit exposed an earlier implementation/test defect: head-cache code
called +0x24 a version, but that is the free-list field. The actual String/BFOON
Dictionary version increment at 0x9154cf4 uses +0x2c. V16 captures +0x20..+0x2f,
adds that exact object code anchor, and changes the regression to mutate +0x2c.
The former test demonstrated free-list mutation detection; it did not validate
actual version changes. This correction preserves all previous identity checks.

## Offline validation

203 checks pass under PowerShell 7.4.6 with C# 5 compatibility: 46 core/kernel,
31 module, 30 metadata and 96 object/native/collection cases. New collection
cases cover exact generic/entry identity, local and derived Player classes,
null/empty/removed/duplicate values, capacity/count/link bounds, active/changed
hotfixes, local-marker errors, actual version mutations, the 16-object limit and
preservation of an earlier native head sample when collection validation fails.
The two-object collection fixture uses 3364 total physical calls including prior
stages and captures 94 collection observations. This is synthetic verification;
only the next Windows report can establish the live collection result.
