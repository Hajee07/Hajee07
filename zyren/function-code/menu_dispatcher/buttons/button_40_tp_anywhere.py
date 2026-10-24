"""BRTL / Tp Anywhere — recovered menu ID 5198.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 452-472.
Ignore argument; XOR previous byte at 0x1010DDD4 with 1; send command 5198.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_40_tp_anywhere(runtime: MenuRuntime, value: int) -> None:
    # The native handler ignores value and XORs its previous byte with 1.
    enabled = runtime.read_u8(0x1010DDD4) ^ 1
    runtime.write_u8(0x1010DDD4, enabled)
    runtime.request(5198, enabled)
