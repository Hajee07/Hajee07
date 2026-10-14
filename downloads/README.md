# Standalone head-direction DLL core

Download `head-aim-dll-x64.zip` and extract it on Windows. The archive contains C++ source, a Windows x64 DLL, and an own-process DLL smoke loader.

This is a mathematical core that accepts caller-supplied head positions and calculates directions. It has no live Free Fire data provider or aim-control integration. It is not a working Free Fire aim-lock.

Validation: 57 native tests passed; native shared-library C ABI loading passed; Windows x64 cross-compilation and export inspection passed. Windows/BlueStacks execution remains untested. See the archive's README.md and VALIDATION.md for details.
