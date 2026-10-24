# Fresh native core analysis

These results come from the DT_INIT-emulated original `libNOVAXITERS.so`, loaded at analysis base `0x10000000`. Addresses and modeled import pointers are not live game addresses. `.c` files are inferred Ghidra pseudocode, not original compilable source. Preserve and read their warning comments.

- `1012d110.c/.asm`: request-processing thread. 44 mapped request cases including LockPlayer525. It includes bad-instruction/control-flow warnings; complete gameplay logic is not established.
- `10189534.c/.asm`: separate TCP text-command thread, 33 resolved command literals. `thread3_transport.json` resolves socket imports and the static listener port21405. This is not HTTP or code download.
- `1010e708.c/.asm` and `10111bfc.c/.asm`: large initialization routines recovered after selecting Thumb mode. Emitted pseudocode does not prove all constructors execute successfully.
- `thread1/`: main thread at0x10177c20. High-level C attempts timed out90s and180s. First-pass output emitted no C; the separate P-code export recovered76,944 intermediate operations and assembly covers11,047 instructions. Two unresolved instruction locations remain. See `thread1/RECOVERY-STATUS.json`.
- `server_dispatcher_mapping.json`: request IDs, source snippets, line references and snapshot-relative target addresses.
- `request_field_instruction_checks.json`: actual instruction checks of the original offset8 numeric interpretation discrepancy, not a repair.
- `thread3_command_state_map.json` and `server_text_state_joins.json`: recovered text-command state writes and nine overlapping menu request cases.

`PROVENANCE.json`, status TSV files and the retained Java exporter scripts describe tool inputs and outcomes. Official Ghidra11.0.3 was used; the large tool distribution is not bundled. External imported functions and indirect calls remain unresolved in places. No Android/game execution was performed.
