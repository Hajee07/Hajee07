# APK module reference and runtime scope

The user supplied Free Fire 1.132.1 through their GitHub release asset. Earlier
inspection verified APK ZIP CRCs and APK v1/v2/v3 signatures. The APK SHA-256 is
`454a60ca730e3b2960cefed171d57dab84ec959f222b905f73bf1899e3ab64e8`.
The ARM64 `libil2cpp.so` extracted from it is 184,109,552 bytes, SHA-256
`549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657`.
It is little-endian AArch64 ELF64 ET_DYN, with fourteen program headers of 56
bytes at file offset 64. There are eight PT_LOAD entries.

| File offset | Relative virtual address | File bytes | Memory bytes | ELF flags |
| --- | --- | --- | --- | --- |
| 0x0 | 0x0 | 0x32278dc | 0x32278dc | R |
| 0x32278dc | 0x322b8dc | 0x71fcc74 | 0x71fcc74 | RX |
| 0xa424550 | 0xa42c550 | 0x49dd50 | 0x49dd50 | RW |
| 0xa8c22a0 | 0xa8ce2a0 | 0x6bcc80 | 0x9089e0 | RW |
| 0xaf80000 | 0xb1d8000 | 0x3370 | 0x3370 | RX |
| 0xaf80000 | 0xb1dc000 | 0x3660 | 0x4000 | RW |
| 0xaf80000 | 0xb1e0000 | 0x4470 | 0x447d | RW |
| 0xaf84000 | 0xb1e8000 | 0x103f0 | 0x103f0 | RW |

These are ELF declarations, not guest VMA permission observations. The probe
does not infer execute permissions from them or execute ARM64 code.

## Why version 4's header address is insufficient

The user verified a header in the VMA 0x7f96b9e6b000–0x7f96c4e00000. Its size,
0xaf95000, exactly equals the ELF file rounded up to 4096 bytes. This is consistent
with a whole-file mapping, not proof of a module load bias. The next header
candidate in the version 3 report covered 0x7f96c4e00000–0x7f96c8028000, of size
0x3228000. That size matches the rounded first PT_LOAD. The second candidate has
not yet passed version 5's module checks. Addresses are observations from one
run, never constants used by the probe.

The executable segment's virtual address differs from its file offset by 0x4000.
Other segments have different deltas. Adding a file offset to a header address
would therefore misidentify many runtime locations even for the correct copy.

## Bounded reference checks

`Build-ModuleReference.py` requires the exact library SHA-256 above, validates
ELF/program/note bounds, and emits `ModuleReference.cs`. It does not download or
execute the library. Reproduce with:

```sh
python3 Build-ModuleReference.py /path/to/arm64-v8a/libil2cpp.so ModuleReference.cs
```

The generated reference contains the 64-byte ELF header, 784-byte program-header
table, eight segment declarations, and four small fingerprints:

| Sample | Relative virtual address | File offset | Bytes |
| --- | --- | --- | ---: |
| GNU build-ID note | 0xa739c18 | 0xa731c18 | 36 |
| Code sample 0 | 0x322b8dc | 0x32278dc | 64 |
| Code sample 1 | 0x322c8dc | 0x32288dc | 64 |
| Code sample 2 | 0x322d8dc | 0x32298dc | 64 |

GNU build ID: `ee8bf32c4483429084fde022704ead01a94b6620`.
The combined header/program-header bytes have SHA-256
`ac499d6dee33d4ee11742e0541bd37be579c85f5bd5e1fa246653b1f879ea9ae`.
The chosen code samples are the start of the first executable segment and offsets
4096 and 8192 into that segment. They are identity samples, not identified game
APIs or verified entity/aim functions.

Version 5 checks candidate segment coverage and file-offset correspondence in a
local VMA window, including mapped memory-only tails. Each file-backed range must
name `libil2cpp.so`. It compares the fixed header/table/note/code bytes, then
rechecks them and the used VMA fields/links, filenames, and process identity. The
runner separately rechecks the ADB PID before its final success output.

`GameModuleIdentity=PASS` means the observed layout and sampled bytes agree with
this reference. It is not a full runtime image hash, proof of which matching
copy is executing, or recovery of metadata/field layouts. A missing, transformed,
or nonresident sample causes verification to fail. No game-memory writes occur.

## Validation

The existing 46 reader/header regression checks pass with the additional source
files. Eighteen module checks pass using exact reference bytes and synthetic VMA
records: normal selection after a whole-file candidate; changed ELF/program
tables, GNU note and code; wrong segment offsets/names; anonymous file ranges;
gaps; live filename/mm/VMA/fingerprint mutation; and the 128-entry window limit.
The normal fixture uses nine window VMAs and 681 physical reads. A 128-VMA case
with a successor outside the module passes, and an over-limit case fails.

The reference generator reproduces byte-identical C# output and rejects an
incorrect source digest without writing a reference. Runner syntax and the
existing real-report RAM/CPU parsers also pass. These are cloud checks; live
Windows version 5 subsequently passed, as recorded below.

## User-reported version 5 success

The user reported GameModuleIdentity=PASS with load bias 0x7f96c4e00000 and the
expected build ID. Eight PT_LOADs, 28 window VMAs, and four fingerprints passed.
The whole-file-sized mapping at 0x7f96b9e6b000 was rejected before selecting the
second mapping. The outer scan visited 891 VMAs and the run used 10847 reads.
Game identity and all cleanup steps passed. This establishes the version 5
module checks on that live instance, not game object semantics. Version 6's
metadata/registration evidence is in `GAME-LAYOUT-EVIDENCE.md`.

## Version 8 traversal interruption and version 9 bounded restart

The user reported kernel/process verification success for game PID 3775, then
`VMA traversal bound or cycle validation failed` with VmasVisited=349. The old
combined check used a 4096-node limit; at 349 nodes this was the repeated-node
branch. No module or runtime-metadata success was reached. The report used 4816
physical reads, 404 cache hits, 100 inspected files and 116 skipped repeats.
Plugin unload, handler cleanup, and session release passed.

Concurrent changes to a live VMA list can cause repetition, but the report does
not establish that cause or prove a persistent cycle. V9 reports REPEATED_NODE
and NODE_LIMIT separately with the current/previous node and visit count. Only
an outer repeated-node failure permits one fresh scan after process revalidation.
The failed partial result is discarded and logged; file/visited dictionaries
and translation cache are reset. The existing Reader preserves cumulative read
and elapsed-time budgets. A second repetition or any other failure terminates.
Metadata checks are unchanged from v8 and still require live validation.

96 offline checks pass (46 reader/header, 25 module, 25 registration). Seven
new retry assertions include a persistent cycle and a 4097-node fixture that
stops at exactly 4096 without retrying. Module and metadata verification still
require their complete existing checks on the successful attempt.
