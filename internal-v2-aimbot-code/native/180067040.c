/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16]
recovered_180067040(undefined (*param_1) [16],undefined8 param_2,undefined8 param_3,
                   undefined8 param_4,longlong param_5,undefined8 param_6,longlong param_7)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined (*pauVar3) [16];
  ulonglong uVar4;
  
  *param_1 = ZEXT816(0);
  uVar4 = 0xf;
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  uVar1 = param_5 + param_7;
  pauVar3 = param_1;
  if (0xf < uVar1) {
    uVar2 = uVar1 | 0xf;
    uVar4 = 0x7fffffffffffffff;
    if ((uVar2 < 0x8000000000000000) && (uVar4 = uVar2, uVar2 < 0x16)) {
      uVar4 = 0x16;
    }
    pauVar3 = (undefined (*) [16])func_0x000180024110(uVar4 + 1);
    *(undefined (**) [16])*param_1 = pauVar3;
  }
  *(ulonglong *)param_1[1] = uVar1;
  *(ulonglong *)(param_1[1] + 8) = uVar4;
  func_0x0001801ca88d(pauVar3,param_4,param_5);
  func_0x0001801ca88d(*pauVar3 + param_5,param_6,param_7);
  (*pauVar3)[uVar1] = 0;
  return param_1;
}

