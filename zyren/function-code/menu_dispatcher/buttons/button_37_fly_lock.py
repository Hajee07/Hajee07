"""BRTL / Fly Lock — recovered menu ID 5194.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1537-1542,469-472.
Ignore argument; XOR previous byte at 0x1010DDDC with 1; send command 5194.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_37_fly_lock(runtime: MenuRuntime, value: int) -> None:
    # The native handler ignores value and XORs its previous byte with 1.
    enabled = runtime.read_u8(0x1010DDDC) ^ 1
    runtime.write_u8(0x1010DDDC, enabled)
    runtime.request(5194, enabled)
