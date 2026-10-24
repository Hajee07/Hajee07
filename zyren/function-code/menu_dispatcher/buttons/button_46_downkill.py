"""BRTL / Downkill — recovered menu ID 5658.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 452-464.
Send command 504; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_46_downkill(runtime: MenuRuntime, value: int) -> None:
    runtime.request(504, int(u32(value) == 1))
