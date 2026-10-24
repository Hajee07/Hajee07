/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool recovered_180085a10(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong lVar10;
  bool bVar11;
  longlong lStackX_8;
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined auStack_38 [16];
  
  if ((param_1 == 0) && (param_1 = _DAT_181b2f350, _DAT_181b2f350 == 0)) {
    bVar11 = false;
  }
  else {
    lVar6 = recovered_180085590();
    if (*(longlong *)(lVar6 + 0x10) == 0) {
      uVar9 = 0;
      do {
        lVar1 = *(longlong *)(&UNK_1802f5b80 + uVar9);
        if ((((param_1 != 0) && (lVar1 != 0)) && (*(longlong *)(&UNK_1802f5b88 + uVar9) != 0)) &&
           (*(ulonglong *)(&UNK_1802f5b90 + uVar9) != 0)) {
          lStackX_8 = 0;
          iVar5 = D3DX11CreateShaderResourceViewFromMemory
                            (param_1,*(longlong *)(&UNK_1802f5b88 + uVar9),
                             *(ulonglong *)(&UNK_1802f5b90 + uVar9) & 0xffffffff,0,0,&lStackX_8,0);
          lVar3 = lStackX_8;
          if ((-1 < iVar5) && (lStackX_8 != 0)) {
            uVar7 = recovered_180085590();
            auStack_48 = ZEXT816(0);
            auStack_38 = ZEXT816(0);
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (*(char *)(lVar1 + lVar10) != '\0');
            recovered_180066cc0(auStack_48,lVar1);
            plVar8 = (longlong *)recovered_180085d80(uVar7,auStack_58,auStack_48);
            *(longlong *)(*plVar8 + 0x30) = lVar3;
            if (0xf < (ulonglong)auStack_38._8_8_) {
              if (0xfff < auStack_38._8_8_ + 1) {
                if (0x1f < (auStack_48._0_8_ - *(longlong *)(auStack_48._0_8_ + -8)) - 8U) {
                  _invoke_watson(0,0,0,0,0);
                  pcVar2 = (code *)swi(3);
                  uVar4 = (*pcVar2)();
                  return (bool)uVar4;
                }
              }
              func_0x000180127e40();
            }
          }
        }
        uVar9 = uVar9 + 0x18;
      } while (uVar9 < 0x360);
      if (*(ulonglong *)(lVar6 + 0x10) < 0x24) {
        recovered_180085710(param_1);
      }
      bVar11 = *(longlong *)(lVar6 + 0x10) != 0;
    }
    else {
      bVar11 = true;
    }
  }
  return bVar11;
}

