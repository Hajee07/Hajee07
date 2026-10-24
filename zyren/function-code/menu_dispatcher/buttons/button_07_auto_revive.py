"""AIM / Auto Revive — recovered menu ID 7896.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 430-433.
Send command 7896; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_07_auto_revive(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7896, int(u32(value) == 1))
