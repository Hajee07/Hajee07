# Standalone head-direction DLL core

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
bounded ARM64 IL2CPP header read. Sixteen offline checks passed. Live Windows
validation and entity/head/aim integration remain outstanding.
