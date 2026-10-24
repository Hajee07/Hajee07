/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180066cc0(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (param_3 < 0x8000000000000000) {
    if (param_3 < 0x10) {
      param_1[2] = param_3;
      param_1[3] = 0xf;
      func_0x0001801ca88d();
      *(undefined *)(param_3 + (longlong)param_1) = 0;
    }
    else {
      uVar2 = param_3 | 0xf;
      uVar4 = 0x7fffffffffffffff;
      if ((uVar2 < 0x8000000000000000) && (uVar4 = uVar2, uVar2 < 0x16)) {
        uVar4 = 0x16;
      }
      lVar3 = func_0x000180024110(uVar4 + 1);
      *param_1 = lVar3;
      param_1[2] = param_3;
      param_1[3] = uVar4;
      func_0x0001801ca88d(lVar3,param_2,param_3);
      *(undefined *)(lVar3 + param_3) = 0;
    }
    return;
  }
  func_0x000180052a50();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

