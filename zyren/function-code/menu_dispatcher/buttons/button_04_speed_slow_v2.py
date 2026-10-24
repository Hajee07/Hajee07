"""AIM / Speed Slow V2 — recovered menu ID 1099.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1254-1258.
Send command 1099; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_04_speed_slow_v2(runtime: MenuRuntime, value: int) -> None:
    runtime.request(1099, int(u32(value) == 1))
