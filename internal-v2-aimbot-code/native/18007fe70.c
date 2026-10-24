/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16]
recovered_18007fe70(undefined (*param_1) [16],undefined8 *param_2,undefined8 param_3)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  byte *pbVar10;
  undefined (*pauVar11) [16];
  ulonglong uVar12;
  undefined8 uVar13;
  longlong lVar14;
  byte *pbVar15;
  ulonglong uVar16;
  longlong lVar17;
  bool bVar18;
  undefined auStack_40 [16];
  longlong lStack_30;
  ulonglong uStack_28;
  
  puVar9 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar9 = (undefined8 *)*param_2;
  }
  uVar8 = recovered_180080250(puVar9,param_2[2],param_3,0x2d);
  if (uVar8 == 0xffffffffffffffff) goto LAB_1800800c8;
  uVar16 = uVar8 + 1;
  auStack_40 = ZEXT816(0);
  lStack_30 = 0;
  uStack_28 = 0;
  if ((ulonglong)param_2[2] < uVar16) {
    recovered_180067b60();
    pcVar2 = (code *)swi(3);
    pauVar11 = (undefined (*) [16])(*pcVar2)();
    return pauVar11;
  }
  lVar14 = param_2[2] - uVar16;
  lVar17 = -1;
  if (lVar14 != -1) {
    lVar17 = lVar14;
  }
  puVar9 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar9 = (undefined8 *)*param_2;
  }
  recovered_180066cc0(auStack_40,uVar16 + (longlong)puVar9,lVar17);
  uVar16 = uStack_28;
  pbVar15 = (byte *)auStack_40._0_8_;
  pbVar10 = auStack_40;
  if (0xf < uStack_28) {
    pbVar10 = (byte *)auStack_40._0_8_;
  }
  uVar7 = 0;
  if (lStack_30 != 1) {
LAB_18007ff3f:
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 2) {
      bVar1 = *pbVar10;
      if ((bVar1 != 0x49) || (bVar1 = pbVar10[1], uVar6 = uVar7, bVar1 != 0x49)) {
        uVar6 = -(uint)(bVar1 < 0x49) | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 3) {
      bVar18 = *pbVar10 < 0x49;
      if (((*pbVar10 != 0x49) || (bVar18 = pbVar10[1] < 0x49, pbVar10[1] != 0x49)) ||
         (bVar18 = pbVar10[2] < 0x49, uVar6 = uVar7, pbVar10[2] != 0x49)) {
        uVar6 = -(uint)bVar18 | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 1) {
      uVar6 = uVar7;
      if (*pbVar10 != 0x58) {
        uVar6 = -(uint)(*pbVar10 < 0x58) | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 1) {
      uVar6 = uVar7;
      if (*pbVar10 != 0x59) {
        uVar6 = -(uint)(*pbVar10 < 0x59) | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 1) {
      if (*pbVar10 != 0x32) {
        uVar7 = -(uint)(*pbVar10 < 0x32) | 1;
      }
      if (uVar7 == 0) goto LAB_180080013;
    }
    if (0xf < uStack_28) {
      if ((0xfff < uStack_28 + 1) &&
         (pbVar15 = *(byte **)(auStack_40._0_8_ + -8),
         (byte *)0x1f < (byte *)(auStack_40._0_8_ + (-8 - (longlong)pbVar15)))) goto LAB_1800800aa;
      func_0x000180127e40(pbVar15);
    }
LAB_1800800c8:
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    uVar8 = param_2[2];
    if (0xf < (ulonglong)param_2[3]) {
      param_2 = (undefined8 *)*param_2;
    }
    if (uVar8 < 0x8000000000000000) {
      if (uVar8 < 0x10) {
        *(ulonglong *)param_1[1] = uVar8;
        *(undefined8 *)(param_1[1] + 8) = 0xf;
        uVar3 = *(undefined4 *)((longlong)param_2 + 4);
        uVar4 = *(undefined4 *)(param_2 + 1);
        uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
        *(undefined4 *)*param_1 = *(undefined4 *)param_2;
        *(undefined4 *)(*param_1 + 4) = uVar3;
        *(undefined4 *)(*param_1 + 8) = uVar4;
        *(undefined4 *)(*param_1 + 0xc) = uVar5;
      }
      else {
        uVar12 = uVar8 | 0xf;
        uVar16 = 0x7fffffffffffffff;
        if ((uVar12 < 0x8000000000000000) && (uVar16 = uVar12, uVar12 < 0x16)) {
          uVar16 = 0x16;
        }
        uVar13 = func_0x000180024110(uVar16 + 1);
        *(undefined8 *)*param_1 = uVar13;
        *(ulonglong *)param_1[1] = uVar8;
        *(ulonglong *)(param_1[1] + 8) = uVar16;
        func_0x0001801ca88d(uVar13,param_2,uVar8 + 1);
      }
      return param_1;
    }
    func_0x000180052a50();
    pcVar2 = (code *)swi(3);
    pauVar11 = (undefined (*) [16])(*pcVar2)();
    return pauVar11;
  }
  uVar6 = uVar7;
  if (*pbVar10 != 0x49) {
    uVar6 = -(uint)(*pbVar10 < 0x49) | 1;
  }
  if (uVar6 != 0) goto LAB_18007ff3f;
LAB_180080013:
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  if ((ulonglong)param_2[2] < uVar8) {
    uVar8 = param_2[2];
  }
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  recovered_180066cc0(param_1,param_2,uVar8);
  if (uVar16 < 0x10) {
    return param_1;
  }
  pbVar10 = pbVar15;
  if ((uVar16 + 1 < 0x1000) ||
     (pbVar10 = *(byte **)(pbVar15 + -8), pbVar15 + (-8 - (longlong)pbVar10) < (byte *)0x20)) {
    func_0x000180127e40(pbVar10);
    return param_1;
  }
LAB_1800800aa:
  _invoke_watson(0,0,0,0,0);
  pcVar2 = (code *)swi(3);
  pauVar11 = (undefined (*) [16])(*pcVar2)();
  return pauVar11;
}

