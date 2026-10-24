/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * recovered_180085d80(float *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  float fVar15;
  float fVar16;
  undefined8 *puStack_38;
  longlong lStack_30;
  
  puVar8 = param_3;
  if (0xf < (ulonglong)param_3[3]) {
    puVar8 = (undefined8 *)*param_3;
  }
  uVar14 = 0xcbf29ce484222325;
  uVar9 = 0;
  if (param_3[2] != 0) {
    do {
      uVar14 = (uVar14 ^ *(byte *)((longlong)puVar8 + uVar9)) * 0x100000001b3;
      uVar9 = uVar9 + 1;
    } while (uVar9 < (ulonglong)param_3[2]);
  }
  recovered_180085cb0(param_1,&puStack_38,param_3,uVar14);
  if (lStack_30 != 0) {
    *param_2 = lStack_30;
    *(undefined *)(param_2 + 1) = 0;
    return param_2;
  }
  if (*(longlong *)(param_1 + 4) == 0x492492492492492) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar2 = (code *)swi(3);
    plVar7 = (longlong *)(*pcVar2)();
    return plVar7;
  }
  puVar8 = (undefined8 *)func_0x000180127a94(0x38);
  *(undefined (*) [16])(puVar8 + 2) = ZEXT816(0);
  puVar8[4] = 0;
  puVar8[5] = 0;
  uVar3 = *(undefined4 *)((longlong)param_3 + 4);
  uVar4 = *(undefined4 *)(param_3 + 1);
  uVar5 = *(undefined4 *)((longlong)param_3 + 0xc);
  *(undefined4 *)(puVar8 + 2) = *(undefined4 *)param_3;
  *(undefined4 *)((longlong)puVar8 + 0x14) = uVar3;
  *(undefined4 *)(puVar8 + 3) = uVar4;
  *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar5;
  uVar3 = *(undefined4 *)((longlong)param_3 + 0x14);
  uVar4 = *(undefined4 *)(param_3 + 3);
  uVar5 = *(undefined4 *)((longlong)param_3 + 0x1c);
  *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(param_3 + 2);
  *(undefined4 *)((longlong)puVar8 + 0x24) = uVar3;
  *(undefined4 *)(puVar8 + 5) = uVar4;
  *(undefined4 *)((longlong)puVar8 + 0x2c) = uVar5;
  param_3[2] = 0;
  param_3[3] = 0xf;
  *(undefined *)param_3 = 0;
  puVar8[6] = 0;
  uVar9 = *(ulonglong *)(param_1 + 0xe);
  uVar10 = *(longlong *)(param_1 + 4) + 1;
  if ((longlong)uVar10 < 0) {
    fVar15 = (float)(uVar10 >> 1 | (ulonglong)((uint)uVar10 & 1));
    fVar15 = fVar15 + fVar15;
  }
  else {
    fVar15 = (float)uVar10;
  }
  if ((longlong)uVar9 < 0) {
    fVar16 = (float)(uVar9 >> 1 | (ulonglong)((uint)uVar9 & 1));
    fVar16 = fVar16 + fVar16;
  }
  else {
    fVar16 = (float)uVar9;
  }
  if (*param_1 < fVar15 / fVar16) {
    fVar15 = (float)func_0x0001801cb4e3(fVar15 / *param_1);
    lVar11 = 0;
    if ((_DAT_181a03458 <= fVar15) && (fVar15 = fVar15 - _DAT_181a03458, fVar15 < _DAT_181a03458)) {
      lVar11 = -0x8000000000000000;
    }
    uVar10 = 8;
    if (8 < (ulonglong)((longlong)fVar15 + lVar11)) {
      uVar10 = (longlong)fVar15 + lVar11;
    }
    uVar13 = uVar9;
    if ((uVar9 < uVar10) && ((0x1ff < uVar9 || (uVar13 = uVar9 * 8, uVar9 * 8 < uVar10)))) {
      uVar13 = uVar10;
    }
    func_0x0001800860a0(param_1,uVar13);
    puVar12 = *(undefined8 **)
               (*(longlong *)(param_1 + 6) + 8 + (*(ulonglong *)(param_1 + 0xc) & uVar14) * 0x10);
    puStack_38 = *(undefined8 **)(param_1 + 2);
    if (puVar12 != *(undefined8 **)(param_1 + 2)) {
      puVar1 = *(undefined8 **)
                (*(longlong *)(param_1 + 6) + (*(ulonglong *)(param_1 + 0xc) & uVar14) * 0x10);
      lVar11 = puVar8[4];
      puStack_38 = puVar12;
      while( true ) {
        plVar7 = puStack_38 + 2;
        if (0xf < (ulonglong)puStack_38[5]) {
          plVar7 = (longlong *)*plVar7;
        }
        puVar12 = puVar8 + 2;
        if (0xf < (ulonglong)puVar8[5]) {
          puVar12 = (undefined8 *)puVar8[2];
        }
        if ((lVar11 == puStack_38[4]) &&
           ((lVar11 == 0 || (iVar6 = func_0x0001801ca8a5(puVar12,plVar7,lVar11), iVar6 == 0))))
        break;
        if (puStack_38 == puVar1) goto LAB_180085fe6;
        puStack_38 = (undefined8 *)puStack_38[1];
      }
      puStack_38 = (undefined8 *)*puStack_38;
    }
  }
LAB_180085fe6:
  puVar12 = (undefined8 *)puStack_38[1];
  *(longlong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + 1;
  *puVar8 = puStack_38;
  puVar8[1] = puVar12;
  *puVar12 = puVar8;
  puStack_38[1] = puVar8;
  uVar14 = *(ulonglong *)(param_1 + 0xc) & uVar14;
  lVar11 = *(longlong *)(param_1 + 6);
  puVar1 = *(undefined8 **)(lVar11 + uVar14 * 0x10);
  if (puVar1 == *(undefined8 **)(param_1 + 2)) {
    *(undefined8 **)(lVar11 + uVar14 * 0x10) = puVar8;
  }
  else {
    if (puVar1 == puStack_38) {
      *(undefined8 **)(lVar11 + uVar14 * 0x10) = puVar8;
      goto LAB_180086030;
    }
    if (*(undefined8 **)(lVar11 + 8 + uVar14 * 0x10) != puVar12) goto LAB_180086030;
  }
  *(undefined8 **)(lVar11 + 8 + uVar14 * 0x10) = puVar8;
LAB_180086030:
  *param_2 = (longlong)puVar8;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}

