/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong ** recovered_180078f90(float *param_1,longlong **param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  longlong **pplVar2;
  code *pcVar3;
  longlong **pplVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong **pplVar9;
  ulonglong uVar10;
  longlong **pplVar11;
  float fVar12;
  float fVar13;
  
  uVar5 = (((((ulonglong)*(byte *)param_3 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
            (ulonglong)*(byte *)((longlong)param_3 + 1)) * 0x100000001b3 ^
           (ulonglong)*(byte *)((longlong)param_3 + 2)) * 0x100000001b3 ^
          (ulonglong)*(byte *)((longlong)param_3 + 3)) * 0x100000001b3;
  uVar8 = uVar5 & *(ulonglong *)(param_1 + 0xc);
  pplVar9 = (longlong **)(uVar8 * 2);
  pplVar2 = *(longlong ***)(*(longlong *)(param_1 + 6) + 8 + uVar8 * 0x10);
  pplVar4 = (longlong **)(param_1 + 2);
  pplVar11 = (longlong **)*pplVar4;
  if (pplVar2 != pplVar11) {
    pplVar9 = *(longlong ***)(*(longlong *)(param_1 + 6) + uVar8 * 0x10);
    iVar1 = *(int *)(pplVar2 + 2);
    while (*param_3 != iVar1) {
      pplVar11 = pplVar2;
      if (pplVar2 == pplVar9) goto LAB_18007905a;
      pplVar2 = (longlong **)pplVar2[1];
      iVar1 = *(int *)(pplVar2 + 2);
    }
    pplVar11 = (longlong **)*pplVar2;
    if (pplVar2 != (longlong **)0x0) {
      *param_2 = (longlong *)pplVar2;
      *(undefined *)(param_2 + 1) = 0;
      return param_2;
    }
  }
LAB_18007905a:
  if (*(longlong *)(param_1 + 4) == 0xa3d70a3d70a3d7) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar3 = (code *)swi(3);
    pplVar4 = (longlong **)(*pcVar3)();
    return pplVar4;
  }
  pplVar4 = (longlong **)func_0x000180127a94(400,pplVar9,pplVar4,param_4,pplVar4,0);
  *(int *)(pplVar4 + 2) = *param_3;
  func_0x0001801ca899(pplVar4 + 3,0,0x178);
  func_0x00018007af90(pplVar4 + 3);
  uVar8 = *(ulonglong *)(param_1 + 0xe);
  uVar6 = *(longlong *)(param_1 + 4) + 1;
  if ((longlong)uVar6 < 0) {
    fVar12 = (float)(uVar6 >> 1 | (ulonglong)((uint)uVar6 & 1));
    fVar12 = fVar12 + fVar12;
  }
  else {
    fVar12 = (float)uVar6;
  }
  if ((longlong)uVar8 < 0) {
    fVar13 = (float)(uVar8 >> 1 | (ulonglong)((uint)uVar8 & 1));
    fVar13 = fVar13 + fVar13;
  }
  else {
    fVar13 = (float)uVar8;
  }
  if (*param_1 < fVar12 / fVar13) {
    fVar12 = (float)func_0x0001801cb4e3(fVar12 / *param_1);
    lVar7 = 0;
    if ((_DAT_181a03458 <= fVar12) && (fVar12 = fVar12 - _DAT_181a03458, fVar12 < _DAT_181a03458)) {
      lVar7 = -0x8000000000000000;
    }
    uVar6 = 8;
    if (8 < (ulonglong)((longlong)fVar12 + lVar7)) {
      uVar6 = (longlong)fVar12 + lVar7;
    }
    uVar10 = uVar8;
    if ((uVar8 < uVar6) && ((0x1ff < uVar8 || (uVar10 = uVar8 * 8, uVar8 * 8 < uVar6)))) {
      uVar10 = uVar6;
    }
    recovered_18007add0(param_1,uVar10);
    pplVar2 = *(longlong ***)
               (*(longlong *)(param_1 + 6) + 8 + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10);
    pplVar11 = *(longlong ***)(param_1 + 2);
    if (pplVar2 != pplVar11) {
      iVar1 = *(int *)(pplVar2 + 2);
      pplVar11 = pplVar2;
      while (*(int *)(pplVar4 + 2) != iVar1) {
        if (pplVar11 ==
            *(longlong ***)
             (*(longlong *)(param_1 + 6) + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10))
        goto LAB_1800791f7;
        pplVar11 = (longlong **)pplVar11[1];
        iVar1 = *(int *)(pplVar11 + 2);
      }
      pplVar11 = (longlong **)*pplVar11;
    }
  }
LAB_1800791f7:
  pplVar2 = (longlong **)pplVar11[1];
  *(longlong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + 1;
  *pplVar4 = (longlong *)pplVar11;
  pplVar4[1] = (longlong *)pplVar2;
  *pplVar2 = (longlong *)pplVar4;
  pplVar11[1] = (longlong *)pplVar4;
  uVar5 = *(ulonglong *)(param_1 + 0xc) & uVar5;
  lVar7 = *(longlong *)(param_1 + 6);
  pplVar9 = *(longlong ***)(lVar7 + uVar5 * 0x10);
  if (pplVar9 == *(longlong ***)(param_1 + 2)) {
    *(longlong ***)(lVar7 + uVar5 * 0x10) = pplVar4;
  }
  else {
    if (pplVar9 == pplVar11) {
      *(longlong ***)(lVar7 + uVar5 * 0x10) = pplVar4;
      goto LAB_180079241;
    }
    if (*(longlong ***)(lVar7 + 8 + uVar5 * 0x10) != pplVar2) goto LAB_180079241;
  }
  *(longlong ***)(lVar7 + 8 + uVar5 * 0x10) = pplVar4;
LAB_180079241:
  *param_2 = (longlong *)pplVar4;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}

