/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180080190(undefined (*param_1) [16],undefined8 *param_2)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined (*pauVar8) [16];
  ulonglong uVar9;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  uVar1 = param_2[2];
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  if (uVar1 < 0x8000000000000000) {
    if (uVar1 < 0x10) {
      *(ulonglong *)param_1[1] = uVar1;
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
      uVar6 = uVar1 | 0xf;
      uVar9 = 0x7fffffffffffffff;
      if ((uVar6 < 0x8000000000000000) && (uVar9 = uVar6, uVar6 < 0x16)) {
        uVar9 = 0x16;
      }
      uVar7 = func_0x000180024110(uVar9 + 1);
      *(undefined8 *)*param_1 = uVar7;
      *(ulonglong *)param_1[1] = uVar1;
      *(ulonglong *)(param_1[1] + 8) = uVar9;
      func_0x0001801ca88d(uVar7,param_2,uVar1 + 1);
    }
    return param_1;
  }
  func_0x000180052a50();
  pcVar2 = (code *)swi(3);
  pauVar8 = (undefined (*) [16])(*pcVar2)();
  return pauVar8;
}

