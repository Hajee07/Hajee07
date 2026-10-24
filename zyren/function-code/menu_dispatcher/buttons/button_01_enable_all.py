"""AIM / Enable All — recovered menu ID 102.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1797-1807,2048-2066.
Write local flag; send commands 102 and 3, in that order. Does not enable every ESP flag.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_01_enable_all(runtime: MenuRuntime, value: int) -> None:
    enabled = int(u32(value) == 1)
    runtime.write_u8(0x1010DDE0, enabled)
    runtime.request(102, enabled)
    runtime.request(3, runtime.read_u8(0x1010DDE0))
