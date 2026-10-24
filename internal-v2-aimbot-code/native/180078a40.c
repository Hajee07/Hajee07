/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
recovered_180078a40(undefined8 param_1,undefined8 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  float fVar12;
  float fVar13;
  
  uVar9 = (((((ulonglong)*(byte *)param_3 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
            (ulonglong)*(byte *)((longlong)param_3 + 1)) * 0x100000001b3 ^
           (ulonglong)*(byte *)((longlong)param_3 + 2)) * 0x100000001b3 ^
          (ulonglong)*(byte *)((longlong)param_3 + 3)) * 0x100000001b3;
  uVar7 = uVar9 & _DAT_181b508c0;
  puVar8 = (undefined8 *)(uVar7 * 2);
  puVar5 = *(undefined8 **)(_DAT_181b508a8 + 8 + uVar7 * 0x10);
  puVar10 = _DAT_181b50898;
  if (puVar5 != _DAT_181b50898) {
    puVar8 = *(undefined8 **)(_DAT_181b508a8 + uVar7 * 0x10);
    iVar1 = *(int *)(puVar5 + 2);
    puVar10 = puVar5;
    while( true ) {
      if (*param_3 == iVar1) {
        *param_2 = puVar10;
        *(undefined *)(param_2 + 1) = 0;
        return param_2;
      }
      if (puVar10 == puVar8) break;
      puVar10 = (undefined8 *)puVar10[1];
      iVar1 = *(int *)(puVar10 + 2);
    }
  }
  if (_DAT_181b508a0 == 0xaaaaaaaaaaaaaaa) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar3 = (code *)swi(3);
    puVar5 = (undefined8 *)(*pcVar3)();
    return puVar5;
  }
  puVar5 = (undefined8 *)func_0x000180127a94(0x18,puVar8,param_3,param_4,&DAT_181b50898,0);
  *(int *)(puVar5 + 2) = *param_3;
  *(undefined4 *)((longlong)puVar5 + 0x14) = 0;
  uVar4 = _DAT_181b508c8;
  uVar7 = _DAT_181b508a0 + 1;
  if ((longlong)uVar7 < 0) {
    fVar12 = (float)(uVar7 >> 1 | (ulonglong)((uint)uVar7 & 1));
    fVar12 = fVar12 + fVar12;
  }
  else {
    fVar12 = (float)uVar7;
  }
  if ((longlong)_DAT_181b508c8 < 0) {
    fVar13 = (float)(_DAT_181b508c8 >> 1 | (ulonglong)((uint)_DAT_181b508c8 & 1));
    fVar13 = fVar13 + fVar13;
  }
  else {
    fVar13 = (float)_DAT_181b508c8;
  }
  if (_DAT_181b50890 < fVar12 / fVar13) {
    fVar12 = (float)func_0x0001801cb4e3(fVar12 / _DAT_181b50890);
    lVar6 = 0;
    if ((_DAT_181a03458 <= fVar12) && (fVar12 = fVar12 - _DAT_181a03458, fVar12 < _DAT_181a03458)) {
      lVar6 = -0x8000000000000000;
    }
    uVar7 = 8;
    if (8 < (ulonglong)((longlong)fVar12 + lVar6)) {
      uVar7 = (longlong)fVar12 + lVar6;
    }
    uVar11 = uVar4;
    if ((uVar4 < uVar7) && ((0x1ff < uVar4 || (uVar11 = uVar4 * 8, uVar4 * 8 < uVar7)))) {
      uVar11 = uVar7;
    }
    recovered_18007ac10(uVar7,uVar11);
    puVar8 = *(undefined8 **)(_DAT_181b508a8 + 8 + (_DAT_181b508c0 & uVar9) * 0x10);
    puVar10 = _DAT_181b50898;
    if (puVar8 != _DAT_181b50898) {
      iVar1 = *(int *)(puVar8 + 2);
      puVar10 = puVar8;
      while (*(int *)(puVar5 + 2) != iVar1) {
        if (puVar10 == *(undefined8 **)(_DAT_181b508a8 + (_DAT_181b508c0 & uVar9) * 0x10))
        goto LAB_180078c88;
        puVar10 = (undefined8 *)puVar10[1];
        iVar1 = *(int *)(puVar10 + 2);
      }
      puVar10 = (undefined8 *)*puVar10;
    }
  }
LAB_180078c88:
  puVar8 = (undefined8 *)puVar10[1];
  _DAT_181b508a0 = _DAT_181b508a0 + 1;
  *puVar5 = puVar10;
  puVar5[1] = puVar8;
  *puVar8 = puVar5;
  puVar10[1] = puVar5;
  lVar6 = _DAT_181b508a8;
  uVar9 = _DAT_181b508c0 & uVar9;
  puVar2 = *(undefined8 **)(_DAT_181b508a8 + uVar9 * 0x10);
  if (puVar2 == _DAT_181b50898) {
    *(undefined8 **)(_DAT_181b508a8 + uVar9 * 0x10) = puVar5;
  }
  else {
    if (puVar2 == puVar10) {
      *(undefined8 **)(_DAT_181b508a8 + uVar9 * 0x10) = puVar5;
      goto LAB_180078ce7;
    }
    if (*(undefined8 **)(_DAT_181b508a8 + 8 + uVar9 * 0x10) != puVar8) goto LAB_180078ce7;
  }
  *(undefined8 **)(lVar6 + 8 + uVar9 * 0x10) = puVar5;
LAB_180078ce7:
  *param_2 = puVar5;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}

