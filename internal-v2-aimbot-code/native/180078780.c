/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180078780(undefined (*param_1) [16],longlong param_2,longlong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined (*pauVar4) [16];
  ulonglong uVar5;
  ulonglong uVar6;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  if (param_2 == param_3) {
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    (*param_1)[0] = 0;
  }
  else {
    uVar6 = param_3 - param_2;
    if (0x7fffffffffffffff < uVar6) {
      func_0x000180052a50();
      pcVar1 = (code *)swi(3);
      pauVar4 = (undefined (*) [16])(*pcVar1)();
      return pauVar4;
    }
    if (uVar6 < 0x10) {
      *(ulonglong *)param_1[1] = uVar6;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      func_0x0001801ca88d(0,param_2,uVar6);
      *(undefined *)(uVar6 + (longlong)param_1) = 0;
    }
    else {
      uVar2 = uVar6 | 0xf;
      uVar5 = 0x7fffffffffffffff;
      if ((uVar2 < 0x8000000000000000) && (uVar5 = uVar2, uVar2 < 0x16)) {
        uVar5 = 0x16;
      }
      lVar3 = func_0x000180024110(uVar5 + 1);
      *(longlong *)*param_1 = lVar3;
      *(ulonglong *)param_1[1] = uVar6;
      *(ulonglong *)(param_1[1] + 8) = uVar5;
      func_0x0001801ca88d(lVar3,param_2,uVar6);
      *(undefined *)(lVar3 + uVar6) = 0;
    }
  }
  return param_1;
}

