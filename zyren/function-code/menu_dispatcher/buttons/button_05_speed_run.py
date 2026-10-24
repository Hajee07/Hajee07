"""AIM / Speed Run — recovered menu ID 507.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1547-1549,2868-2874.
Send command 507; byte is int(u32(value) != 0).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_05_speed_run(runtime: MenuRuntime, value: int) -> None:
    runtime.request(507, int(u32(value) != 0))
