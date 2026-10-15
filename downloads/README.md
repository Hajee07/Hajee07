# Standalone head-direction DLL core

Current process probe: **V15**. V14 passed local-player and managed-head checks
but rejected a changed native snapshot. V15 makes two short coalesced TRS copies
and retries selected TRS motion at most three times, with strict identity and
byte comparisons. 181 offline checks pass; live position validation is pending. See
[the current probe instructions](bluestacks-process-map/README.md). Other-player
visibility and aim control remain incomplete.

Download `head-aim-dll-x64.zip` and extract it on Windows. The archive contains C++ source, a Windows x64 DLL, and an own-process DLL smoke loader.

This is a mathematical core that accepts caller-supplied head positions and calculates directions. It has no live Free Fire data provider or aim-control integration. It is not a working Free Fire aim-lock.

Validation: 57 native tests passed; native shared-library C ABI loading passed; Windows x64 cross-compilation and export inspection passed. The user subsequently ran the Windows smoke loader successfully. Game integration remains incomplete.

The separate [native BlueStacks bridge](bluestacks-native-bridge/README.md) has
now passed its Windows one-byte guest physical read probe, including plug-in
loading and cleanup. See its [runtime results](bluestacks-native-bridge/RUNTIME-RESULTS.md).

[Get-GuestMappingContext.ps1](bluestacks-native-bridge/Get-GuestMappingContext.ps1)
collects kernel-layout and paging prerequisites on the user's Windows PC.
Aim-control writes remain unimplemented.

The uploaded fastboot disk subsequently supplied the matching kernel image and
87,332 recoverable kernel symbols. A [read-only process-mapping probe](bluestacks-process-map/README.md)
now implements kernel identity checks, process page-table discovery, and a
bounded ARM64 IL2CPP header read. Version 4 passed live kernel/process and final
header verification after 808 VMAs and 8096 reads. Version 5 subsequently passed
live module segment/build-ID/code verification in 10847 reads, with cleanup.
The exact metadata now yields validated type/method/field records and selected
native registrations. Version 6 verifies nine field and nine method candidates
against live memory. Seventy-two offline checks passed. Live registration checks,
player-object/head-position integration, and aim updates remain pending.

Version 7 isolated nine stable type-descriptor differences while the other 71
checks matched. Every differing payload points into one candidate metadata type
table. Version 8 checks the descriptor flags, derived metadata base, exact header
and complete type records. 89 offline checks pass; live version 8 verification
and player/head/aim integration remain pending.

The v8 run stopped on a repeated VMA node before module/metadata verification.
V9 adds one bounded fresh scan for this specific condition, preserves the global
budgets and all validation checks, and reports node limits separately. 96 offline
checks pass. Live metadata verification and aim integration remain incomplete.

V9 subsequently passed module verification on its first attempt and exposed a
runtime header prefix of zero/version 24. V10 validates that exact observed
prefix, the remaining 248 header bytes and complete type records. Input hashes
remain unchanged. 101 offline checks pass; live metadata validation is pending.

V10 then passed all 80 runtime registration checks in both rounds, including the
complete header and nine type records. V11 adds read-only local-player and managed
head Transform verification with class/parent/hotfix/interface checks. 127 offline
checks pass. Run after spawning in Training Ground; live object validation is
pending. Other-player enumeration, world coordinates and aim updates are pending.

V11 user reports exposed a traversal inconsistency and, on a later successful
module/metadata scan, an IFix class-layout mismatch. V12 corrects the generator's
use of opaque native-size words as exact expectations. It verifies bounded
runtime sizes and IFix's actual static-field metadata/layout, and adds a bounded
fresh scan for outer order/backlink inconsistencies. 142 offline checks pass.
Live player/head validation and aim integration still require further work.

V12 verified the live local PlayerNetwork chain, including the corrected IFix
runtime layout. Its head-provider cache was null. V13 adds a bounded exact-name
bone_Head lookup in the already populated model dictionary, with generic type,
vtable/hotfix, String and node checks. 155 offline checks pass. No initialization
or memory writes are used; live head Transform and world-position work is pending.
