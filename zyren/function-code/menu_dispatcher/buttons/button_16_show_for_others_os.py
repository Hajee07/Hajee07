"""LOOK / Show For Others (OS) — recovered menu ID 7101.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1150-1153.
Send command 7101; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_16_show_for_others_os(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7101, int(u32(value) == 1))
