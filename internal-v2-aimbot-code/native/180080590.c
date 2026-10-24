/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_180080590(undefined (*param_1) [16],int **param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined4 uVar5;
  longlong lVar6;
  int *piVar7;
  undefined (*pauVar8) [16];
  int iVar9;
  int **ppiVar10;
  ulonglong uVar11;
  undefined *puVar12;
  ulonglong uVar13;
  undefined *puStackX_10;
  undefined auStack_80 [16];
  undefined auStack_70 [16];
  undefined auStack_60 [4];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined auStack_40 [16];
  undefined8 uStack_30;
  ulonglong uStack_28;
  
  piVar7 = param_2[2];
  if (piVar7 != (int *)0x0) {
    piVar1 = param_2[3];
    ppiVar10 = param_2;
    if ((int *)0xf < piVar1) {
      ppiVar10 = (int **)*param_2;
    }
    if (piVar7 == (int *)0x3) {
      iVar9 = *(ushort *)ppiVar10 - 0x4f42;
      if (iVar9 == 0) {
        iVar9 = *(byte *)((longlong)ppiVar10 + 2) - 0x54;
      }
      if (iVar9 == 0) goto LAB_180080825;
    }
    ppiVar10 = param_2;
    if ((int *)0xf < piVar1) {
      ppiVar10 = (int **)*param_2;
    }
    if (piVar7 == (int *)0x7) {
      iVar9 = *(int *)ppiVar10 + -0x6e6b6e55;
      if ((iVar9 == 0) && (iVar9 = *(ushort *)((longlong)ppiVar10 + 4) - 0x776f, iVar9 == 0)) {
        iVar9 = *(byte *)((longlong)ppiVar10 + 6) - 0x6e;
      }
      if (iVar9 == 0) goto LAB_180080825;
    }
    ppiVar10 = param_2;
    if ((int *)0xf < piVar1) {
      ppiVar10 = (int **)*param_2;
    }
    lVar6 = recovered_180080250(ppiVar10,piVar7,piVar7,CONCAT71((int7)((ulonglong)piVar1 >> 8),0x28)
                               );
    ppiVar10 = param_2;
    if ((int *)0xf < param_2[3]) {
      ppiVar10 = (int **)*param_2;
    }
    piVar7 = (int *)recovered_180080250(ppiVar10,param_2[2]);
    if (((lVar6 != -1) && (piVar7 != (int *)0xffffffffffffffff)) &&
       (piVar1 = (int *)(lVar6 + 1), piVar1 < piVar7)) {
      auStack_80 = ZEXT816(0);
      auStack_70 = ZEXT816(0);
      if (param_2[2] < piVar1) {
        recovered_180067b60();
        pcVar2 = (code *)swi(3);
        pauVar8 = (undefined (*) [16])(*pcVar2)();
        return pauVar8;
      }
      uVar13 = (longlong)piVar7 + (-1 - lVar6);
      uVar11 = (longlong)param_2[2] - (longlong)piVar1;
      if (uVar11 < uVar13) {
        uVar13 = uVar11;
      }
      if ((int *)0xf < param_2[3]) {
        param_2 = (int **)*param_2;
      }
      recovered_180066cc0(auStack_80,(longlong)param_2 + (longlong)piVar1,uVar13);
      piVar7 = (int *)_errno();
      puVar12 = auStack_80;
      if (0xf < (ulonglong)auStack_70._8_8_) {
        puVar12 = (undefined *)auStack_80._0_8_;
      }
      *piVar7 = 0;
      uVar5 = strtol(puVar12,&puStackX_10,10);
      if (puVar12 == puStackX_10) {
        __Xinvalid_argument_std__YAXPEBD_Z(&UNK_1819d8238);
      }
      if (*piVar7 == 0x22) {
        __Xout_of_range_std__YAXPEBD_Z(&UNK_1819d8250);
      }
      if (0xf < (ulonglong)auStack_70._8_8_) {
        if ((0xfff < auStack_70._8_8_ + 1) &&
           (0x1f < (auStack_80._0_8_ - *(longlong *)(auStack_80._0_8_ + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          pauVar8 = (undefined (*) [16])(*pcVar2)();
          return pauVar8;
        }
        func_0x000180127e40();
      }
      uStack_30 = _DAT_181a03530;
      uStack_28 = _UNK_181a03538;
      auStack_40._1_15_ = SUB1615(ZEXT816(0),1);
      auVar3[15] = 0;
      auVar3._0_15_ = auStack_40._1_15_;
      auStack_40 = auVar3 << 8;
      uStack_50 = _DAT_181a03530;
      uStack_48 = _UNK_181a03538;
      stack0xffffffffffffffa1 = SUB1615(ZEXT816(0),1);
      auVar4[15] = 0;
      auVar4._0_15_ = stack0xffffffffffffffa1;
      _auStack_60 = auVar4 << 8;
      recovered_18006c300(uVar5,auStack_40,auStack_60);
      *(undefined (*) [4])*param_1 = auStack_60;
      *(undefined4 *)(*param_1 + 4) = uStack_5c;
      *(undefined4 *)(*param_1 + 8) = uStack_58;
      *(undefined4 *)(*param_1 + 0xc) = uStack_54;
      *(undefined4 *)param_1[1] = (undefined4)uStack_50;
      *(undefined4 *)(param_1[1] + 4) = uStack_50._4_4_;
      *(undefined4 *)(param_1[1] + 8) = (undefined4)uStack_48;
      *(undefined4 *)(param_1[1] + 0xc) = uStack_48._4_4_;
      if (uStack_28 < 0x10) {
        return param_1;
      }
      if ((0xfff < uStack_28 + 1) &&
         (0x1f < (auStack_40._0_8_ - *(longlong *)(auStack_40._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        pauVar8 = (undefined (*) [16])(*pcVar2)();
        return pauVar8;
      }
      func_0x000180127e40();
      return param_1;
    }
  }
LAB_180080825:
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  return param_1;
}

