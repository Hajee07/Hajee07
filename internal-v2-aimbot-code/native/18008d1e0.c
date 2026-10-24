/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 * recovered_18008d1e0(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  
  lVar10 = *param_1;
  lVar9 = (param_1[1] - lVar10) / 0x38;
  if (lVar9 == 0x492492492492492) {
    recovered_18006aad0();
    pcVar3 = (code *)swi(3);
    puVar8 = (undefined4 *)(*pcVar3)();
    return puVar8;
  }
  uVar1 = lVar9 + 1;
  uVar2 = (param_1[2] - lVar10) / 0x38;
  if (0x492492492492492 - (uVar2 >> 1) < uVar2) {
    uVar11 = 0x492492492492492;
  }
  else {
    uVar2 = (uVar2 >> 1) + uVar2;
    uVar11 = uVar1;
    if (uVar1 <= uVar2) {
      uVar11 = uVar2;
    }
    if (0x492492492492492 < uVar11) {
      func_0x000180003980();
      pcVar3 = (code *)swi(3);
      puVar8 = (undefined4 *)(*pcVar3)();
      return puVar8;
    }
  }
  puVar7 = (undefined4 *)func_0x000180024110(uVar11 * 0x38);
  puVar12 = puVar7 + ((param_2 - lVar10) / 0x38) * 0xe;
  *puVar12 = *param_3;
  *(undefined8 *)(puVar12 + 1) = *(undefined8 *)(param_3 + 1);
  puVar12[3] = param_3[3];
  *(undefined (*) [16])(puVar12 + 4) = ZEXT816(0);
  *(undefined8 *)(puVar12 + 8) = 0;
  *(undefined8 *)(puVar12 + 10) = 0;
  uVar4 = param_3[5];
  uVar5 = param_3[6];
  uVar6 = param_3[7];
  puVar12[4] = param_3[4];
  puVar12[5] = uVar4;
  puVar12[6] = uVar5;
  puVar12[7] = uVar6;
  uVar4 = param_3[9];
  uVar5 = param_3[10];
  uVar6 = param_3[0xb];
  puVar12[8] = param_3[8];
  puVar12[9] = uVar4;
  puVar12[10] = uVar5;
  puVar12[0xb] = uVar6;
  *(undefined8 *)(param_3 + 8) = 0;
  *(undefined8 *)(param_3 + 10) = 0xf;
  *(undefined *)(param_3 + 4) = 0;
  puVar12[0xc] = param_3[0xc];
  lVar10 = param_1[1];
  lVar9 = *param_1;
  puVar8 = puVar7;
  if (param_2 != lVar10) {
    func_0x00018007a1d0(*param_1,param_2,puVar7);
    lVar10 = param_1[1];
    puVar8 = puVar12 + 0xe;
    lVar9 = param_2;
  }
  func_0x00018007a1d0(lVar9,lVar10,puVar8);
  func_0x00018007ab00(param_1,puVar7,uVar1,uVar11);
  return puVar12;
}

