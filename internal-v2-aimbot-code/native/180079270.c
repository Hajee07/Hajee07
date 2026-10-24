/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180079270(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (0x7ffffffffffffffe < param_3) {
    func_0x000180052a50();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (param_3 < 8) {
    param_1[2] = param_3;
    param_1[3] = 7;
    func_0x0001801ca88d(param_1,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + (longlong)param_1) = 0;
  }
  else {
    uVar2 = param_3 | 7;
    if (uVar2 < 0x7fffffffffffffff) {
      if (uVar2 < 10) {
        uVar2 = 10;
      }
      uVar4 = uVar2 + 1;
      if (0x7fffffffffffffff < uVar4) {
        func_0x000180003980();
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      uVar4 = 0x7fffffffffffffff;
      uVar2 = 0x7ffffffffffffffe;
    }
    lVar3 = func_0x000180024110(uVar4 * 2);
    param_1[2] = param_3;
    *param_1 = lVar3;
    param_1[3] = uVar2;
    func_0x0001801ca88d(lVar3,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + lVar3) = 0;
  }
  return;
}

