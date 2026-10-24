"""AIM / Speed Timer — recovered menu ID 517.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1606-1609.
Send command 517; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_03_speed_timer(runtime: MenuRuntime, value: int) -> None:
    runtime.request(517, int(u32(value) == 1))
