"""AIM / Aimkill MultiTarget — recovered menu ID 110.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2345-2353,2594-2602,2843-2857.
Send 1049, then 1048; write 2000.0/0.0 locally; send float command 104. No invented aiming algorithm.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_02_aimkill_multitarget(runtime: MenuRuntime, value: int) -> None:
    enabled = int(u32(value) == 1)
    runtime.request(1049, enabled)
    runtime.request(1048, enabled)
    amount = 2000.0 if enabled else 0.0
    runtime.write_f32(0x100E1004, amount)
    runtime.request(104, 0, amount)
