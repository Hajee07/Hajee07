/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180067cc0(ulonglong param_1,longlong *param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  longlong lStackX_10;
  
  uVar6 = 0;
  *param_2 = 0;
  if (0x1000 < param_1) {
    plVar4 = (longlong *)
             ((((param_1 >> 0x30 & 0xff ^
                ((((((param_1 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^ param_1 >> 8 & 0xff) *
                    0x100000001b3 ^ param_1 >> 0x10 & 0xff) * 0x100000001b3 ^ param_1 >> 0x18 & 0xff
                  ) * 0x100000001b3 ^ param_1 >> 0x20 & 0xff) * 0x100000001b3 ^
                param_1 >> 0x28 & 0xff) * 0x100000001b3) * 0x100000001b3 ^ param_1 >> 0x38) *
               0x100000001b3 & _DAT_181b2bf50) * 0x10 + _DAT_181b2bf38);
    lVar3 = plVar4[1];
    if (lVar3 == _DAT_181b2bf28) {
LAB_180067dc1:
      lVar3 = 0;
    }
    else {
      uVar1 = *(ulonglong *)(lVar3 + 0x10);
      while (param_1 != uVar1) {
        if (lVar3 == *plVar4) goto LAB_180067dc1;
        lVar3 = *(longlong *)(lVar3 + 8);
        uVar1 = *(ulonglong *)(lVar3 + 0x10);
      }
    }
    lVar5 = _DAT_181b2bf28;
    if (lVar3 != 0) {
      lVar5 = lVar3;
    }
    if ((lVar5 != _DAT_181b2bf28) && (*(longlong *)(lVar5 + 0x18) != 0)) {
      *param_2 = *(longlong *)(lVar5 + 0x18);
      return 1;
    }
    do {
      lVar3 = (*_DAT_181b4efa0)(_DAT_181b4ef90,uVar6);
      if (lVar3 != 0) {
        lStackX_10 = 0;
        iVar2 = (*_DAT_181b4ef78)(lVar3,param_1,&lStackX_10);
        lVar3 = lStackX_10;
        if (iVar2 == 0) {
          *param_2 = lStackX_10;
          plVar4 = (longlong *)recovered_18006a2a0();
          *(longlong *)(*plVar4 + 0x18) = lVar3;
          return 1;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
  }
  return 0;
}

