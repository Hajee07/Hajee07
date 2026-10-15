# Exact kernel layout evidence

Both uploaded ZIPs are byte-identical. The archive passed CRC verification.

| Artifact | Bytes | SHA-256 |
| --- | ---: | --- |
| Uploaded ZIP | 8,328,738 | `c4e1b1320fe065ed4f200937b868932d83a1c7eeb9493a742521cecef90c5824` |
| fastboot.vdi | 11,534,336 | `91a53746e814a3c9350bc8c0a4050b73e92669613e60240c87835a044f1d1a4a` |
| Logical boot image | 8,430,080 | `0541bda4867ed3c4ce05ab25bc6ca6a04936cc4067de46a0bb57bcae8a4ba7e6` |
| Extracted vmlinux | 26,177,360 | `ef91958406d5fa8e57b9e1098c4227ca4eaea91c32e47c8031fa6649084458d3` |

The parentless VDI 1.1 has 1 MiB blocks, nine allocated blocks, a block map at
0x100000, and data at 0x200000. Its flat boot image contains a Linux boot image
at byte 512 and a gzip cpio initrd at 0x6be400. The kernel gzip payload begins
at 0x44e9 and consumes 7,022,677 bytes, matching the boot header's payload length.
Gzip termination, checksum, and size validation passed.

The boot-header version and full ELF banner match the user's live observation:
Linux 4.19.195, build `#1 SMP PREEMPT Fri Oct 17 10:22:49 IST 2025`,
`build@build_18`. The ELF is stripped x86-64 with BuildID
`8d99df4728f1fbff2903db925dd325b3ab15191d`. It has neither a symbol-table nor
DWARF type sections. Version/timestamp agreement alone does not prove live
identity; the runner independently verifies live bytes.

The embedded kallsyms table was recovered with checksum-verified
`vmlinux-to-elf` 1.3.6: 87,332 symbols. Its optional source-database reporting
failed on a date-format conversion; a subclass skipped that informational method
while leaving symbol parsing unchanged. Relative/base addresses were independently
checked against all 9,889 PREL32 exported symbols, with zero mismatches after
normalizing arithmetic to 64 bits. Per-CPU symbols are offsets, not ordinary
kernel virtual addresses; they are not used as process pointers.

| Symbol | Link-time virtual address |
| --- | --- |
| linux_banner | `0xffffffff81e00140` |
| init_top_pgt | `0xffffffff8220e000` |
| init_task | `0xffffffff822147c0` |
| init_mm | `0xffffffff8225ebe0` |

The reader uses these individually verified field offsets, rather than claiming
to have recovered a complete C type definition:

| Field | Offset | Exact binary/source evidence |
| --- | --- | --- |
| task.tasks | 0x470 | show_state_filter at 0xffffffff8111e2d8 loads +0x470 and subtracts 0x470 |
| task.mm | 0x4c0 | get_task_mm at 0xffffffff810e8a06 loads +0x4c0 |
| task.active_mm | 0x4c8 | __mmdrop at 0xffffffff810e8e72 compares +0x4c8; the static initializer points to init_mm, but scheduler changes this field at runtime |
| task.pid | 0x570 | sched_show_task at 0xffffffff81119da7 loads +0x570 for the task's PID |
| task.comm | 0x720 | __get_task_comm at 0xffffffff8126a3a0 forms +0x720; static init_task contains the idle name there |
| mm.pgd | 0x50 | __mmdrop at 0xffffffff810e8e7b loads +0x50 before page-table destruction; static init_mm points to init_top_pgt there |
| mm.mmap | 0x00 | __vma_link_list at 0xffffffff8121b147 writes the first VMA at mm+0 |
| vma.start/end | 0x00/0x08 | show_map_vma at 0xffffffff812da565–0xffffffff812da56d loads both fields |
| vma.next/prev | 0x10/0x18 | __vma_link_list updates both linked-list fields |
| vma.file_page_offset | 0x98 | show_map_vma loads +0x98 and shifts it by 12 |
| vma.file | 0xa0 | show_map_vma at 0xffffffff812da531 loads +0xa0 |
| file.path | 0x10 | file_path at 0xffffffff8125f1b1 adds 0x10 before d_path |
| path.dentry | 0x08 | Linux 4.19 path consists of mount and dentry pointers; file.path.dentry is consequently +0x18 |
| dentry.name length/pointer | 0x24/0x28 | take_dentry_name_snapshot at 0xffffffff8127d6ab / 0xffffffff8127d69e loads these fields |

Seven non-absolute code anchors bind the fields used for lookup to the extracted
image; the entire banner and initial task/mm invariants are also checked. Kernel
relocation is applied to static kernel addresses only. VM pointers, physical
addresses, and application virtual addresses remain separate.

The Windows DLL in this package is byte-identical to the previously successful
native probe: SHA-256
`ff00d9e49cd11f76582b3476b7efd01107f115518fd4dbf9f7be38534a912ee3`.
Its inspected VMM target remains SHA-256
`09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a`.

## User-reported version 1 result and version 2 correction

The user ran the package from commit `9f0fa75d49e06719f7c763650ee2b04adb525ced`.
Preflight (host PID 23620), ADB reconnect, game identity (PID 2942), plugin load,
bridge status, and paging context succeeded. The sampled roots at slide zero
passed the full kernel banner and all seven code anchors, then the combined
initial-task check rejected them. There were 195 native physical read calls.
Unload, handler cleanup, and shared-session release succeeded. No process lookup
or game-library read ran.

The combined version 1 check did not record which initial field differed. Its
requirement that `init_task.active_mm == init_mm` was invalid: Linux 4.19.195
`kernel/sched/core.c` assigns a borrowed mm to a kernel thread in `context_switch`
and clears the field when it switches away. The exact extracted binary confirms
both writes in `__schedule`: 0xffffffff8194219d stores the borrowed pointer at
task+0x4c8, and 0xffffffff819421c3 stores zero there.

Version 2 accepts null or a canonical, aligned kernel pointer for this transient
field, records it, and keeps all banner/code/PID/name/mm/initial-PGD checks.
Individual initial-field errors now have distinct messages. Twenty-two offline
checks pass, including realistic borrowed/null idle contexts and continued
rejection of other invalid fields. The subsequent live result follows.

## User-reported version 2 result and version 3 scan optimization

Version 2 passed kernel identity at root 0x220e000 / slide zero. The idle task's
observed active_mm was the current game's mm, confirming the borrowed-context
case. The probe located PID 2942 after 150 task-list nodes and translated its PGD
to physical root 0xb9cf4000. These are run-specific observations, not constants
used by the mapper.

The library scan reached its 30,000-call read budget and failed. Its totals and
intermediate candidates were not emitted by version 2, so the report does not
establish how many VMAs were scanned or whether an ELF header was reached.
Unload, handler cleanup, and shared-session release all passed.

Version 3 caches validated page translations by root/page while rewalking live
page tables after every data read. It deduplicates filenames, rechecks every
matched file before success, and reports partial progress and totals. Both caches
are bounded to 1024 entries. Read/time/task/VMA budgets remain unchanged.

Thirty-one offline checks pass. A controlled 1800-VMA scan with repeated file
objects and a final ARM64 library uses 9663 physical reads. Additional regressions
cover changed/unmapped cached translations, root separation, renamed matched
files, and failure progress. Live version 3 scan performance remains unverified.

The subsequent live result is recorded below. Offline fixtures contain synthetic
process/VMA records and do not demonstrate a working aim-control integration.

## User-reported version 3 result and version 4 targeted verification

Version 3 again passed kernel and process discovery. It observed an ARM64 Unity
header early, then two ARM64 IL2CPP header candidates between VMAs 768 and 896.
The first IL2CPP mapping started at 0x7f96b9e6b000 in this run. These are observed
addresses, not reusable constants or a verified module load bias.

The full scan continued until 30,000 physical calls at VMA 3300, with 915 file
objects inspected, 571 repeated file lookups skipped, and 4877 translation cache
hits. Candidate headers were read, but final filename/process checks did not
complete. Thus the report is evidence of provisional game-space reads and not a
completed `GameLibraryRead=PASS`. All three cleanup steps passed.

Version 4 uses targeted verification. At the first zero-offset ARM64 IL2CPP
header it rechecks the process identity, VMA fields and neighboring links (or mm
list head), filename, and exact header bytes, then checks the VMA/process again.
Only a revalidated candidate satisfies the runner. It records that the remaining
VMA list was not enumerated. The ADB PID and process rechecks before final success
remain in place, as do the native DLL and read/time/task/VMA budgets.

Forty-six offline checks pass. A 4500-VMA fixture with a target at VMA 800 returns
after 4372 reads without traversing the tail. Mutation tests cover target-file,
filename, ELF bytes, mm identity, VMA bounds, list head, and neighboring links.
The first three versions' results do not establish these new final rechecks on
Windows; version 4's live result remains pending. Entity/head/visibility layouts
and aim-control writes remain unimplemented.

## User-reported version 4 success

The user ran version 4 against Pie64, host PID 23620 and guest PID 2942. Kernel
identity and process discovery passed (147 task nodes). The selected IL2CPP
mapping at 0x7f96b9e6b000 passed the targeted VMA, filename, ARM64 header, and
process checks. The runner reported `GameLibraryRead=PASS` after 808 outer VMAs,
156 file objects, 217 repeated-file skips, and 8096 physical reads (905 cache
hits). The stop reason was TARGET_VERIFIED and the remaining VMA list was not
enumerated. Plugin unload, handler cleanup, and shared-session release passed.

This verifies the header-reading workflow on Windows. It does not identify a
loaded module base: that VMA is the same size as the entire page-rounded APK
library. Version 5's additional segment/fingerprint checks and static evidence
are documented in `MODULE-EVIDENCE.md`. Live version 5 verification is pending.
