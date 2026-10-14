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
| task.active_mm | 0x4c8 | __mmdrop at 0xffffffff810e8e72 compares +0x4c8; static init_task points to init_mm there |
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

Live process mapping, game ELF reads, entity/head layouts, and aim updates remain
unverified. Offline fixtures contain synthetic process/VMA records and do not
demonstrate an active Free Fire integration.
