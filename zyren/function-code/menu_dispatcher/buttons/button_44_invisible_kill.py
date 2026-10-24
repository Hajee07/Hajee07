"""BRTL / Invisible Kill — recovered menu ID 532.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1677-1680.
Send command 532; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_44_invisible_kill(runtime: MenuRuntime, value: int) -> None:
    runtime.request(532, int(u32(value) == 1))
