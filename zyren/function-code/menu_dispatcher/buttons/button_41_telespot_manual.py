"""BRTL / TeleSpot [MANUAL] — recovered menu ID 59910.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 307-311.
Send command 59910; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_41_telespot_manual(runtime: MenuRuntime, value: int) -> None:
    runtime.request(59910, int(u32(value) == 1))
