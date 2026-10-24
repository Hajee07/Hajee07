/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18007ac10(undefined8 param_1,ulonglong param_2)

{
  longlong **pplVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong **pplVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong **pplVar8;
  longlong **pplVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong **pplVar12;
  
  pplVar9 = _DAT_181b50898;
  for (lVar11 = 0x3f; 0xfffffffffffffffU >> lVar11 == 0; lVar11 = lVar11 + -1) {
  }
  if ((ulonglong)(1L << ((byte)lVar11 & 0x3f)) < param_2) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d7808);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  uVar10 = param_2 - 1 | 1;
  lVar11 = 0x3f;
  if (uVar10 != 0) {
    for (; uVar10 >> lVar11 == 0; lVar11 = lVar11 + -1) {
    }
  }
  lVar11 = 1L << ((char)lVar11 + 1U & 0x3f);
  func_0x0001800674b0(&DAT_181b508a8,lVar11 * 2,_DAT_181b50898);
  _DAT_181b508c0 = lVar11 - 1;
  _DAT_181b508c8 = lVar11;
  pplVar8 = (longlong **)*_DAT_181b50898;
joined_r0x00018007ac92:
  do {
    while( true ) {
      while( true ) {
        if (pplVar8 == pplVar9) {
          return;
        }
        pplVar1 = (longlong **)*pplVar8;
        pplVar12 = (longlong **)
                   (((((((ulonglong)*(byte *)(pplVar8 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       (ulonglong)*(byte *)((longlong)pplVar8 + 0x11)) * 0x100000001b3 ^
                      (ulonglong)*(byte *)((longlong)pplVar8 + 0x12)) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)pplVar8 + 0x13)) * 0x100000001b3 &
                    _DAT_181b508c0) * 0x10 + _DAT_181b508a8);
        if ((longlong **)*pplVar12 != pplVar9) break;
        *pplVar12 = (longlong *)pplVar8;
        pplVar12[1] = (longlong *)pplVar8;
        pplVar8 = pplVar1;
      }
      pplVar2 = (longlong **)pplVar12[1];
      if (*(int *)(pplVar8 + 2) != *(int *)(pplVar2 + 2)) break;
      pplVar2 = (longlong **)*pplVar2;
      if (pplVar2 != pplVar8) {
        pplVar3 = (longlong **)pplVar8[1];
        *pplVar3 = (longlong *)pplVar1;
        pplVar4 = (longlong **)pplVar1[1];
        *pplVar4 = (longlong *)pplVar2;
        pplVar5 = (longlong **)pplVar2[1];
        *pplVar5 = (longlong *)pplVar8;
        pplVar2[1] = (longlong *)pplVar4;
        pplVar1[1] = (longlong *)pplVar3;
        pplVar8[1] = (longlong *)pplVar5;
      }
      pplVar12[1] = (longlong *)pplVar8;
      pplVar8 = pplVar1;
    }
    do {
      if ((longlong **)*pplVar12 == pplVar2) {
        pplVar3 = (longlong **)pplVar8[1];
        *pplVar3 = (longlong *)pplVar1;
        plVar6 = pplVar1[1];
        *plVar6 = (longlong)pplVar2;
        pplVar4 = (longlong **)pplVar2[1];
        *pplVar4 = (longlong *)pplVar8;
        pplVar2[1] = plVar6;
        pplVar1[1] = (longlong *)pplVar3;
        pplVar8[1] = (longlong *)pplVar4;
        *pplVar12 = (longlong *)pplVar8;
        pplVar8 = pplVar1;
        goto joined_r0x00018007ac92;
      }
      pplVar2 = (longlong **)pplVar2[1];
    } while (*(int *)(pplVar8 + 2) != *(int *)(pplVar2 + 2));
    lVar11 = (longlong)*pplVar2;
    pplVar12 = (longlong **)pplVar8[1];
    *pplVar12 = (longlong *)pplVar1;
    plVar6 = pplVar1[1];
    *plVar6 = lVar11;
    pplVar2 = *(longlong ***)(lVar11 + 8);
    *pplVar2 = (longlong *)pplVar8;
    *(longlong **)(lVar11 + 8) = plVar6;
    pplVar1[1] = (longlong *)pplVar12;
    pplVar8[1] = (longlong *)pplVar2;
    pplVar8 = pplVar1;
  } while( true );
}

