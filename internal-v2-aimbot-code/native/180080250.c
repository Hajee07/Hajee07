/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong recovered_180080250(longlong param_1,longlong param_2,undefined8 param_3,undefined param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    lVar2 = -1;
    if (param_2 + -1 != -1) {
      lVar2 = param_2 + -1;
    }
    lVar3 = lVar2 + 1 + param_1;
    lVar1 = func_0x000180127870(param_1,lVar3,param_4);
    lVar2 = -1;
    if (lVar1 != lVar3) {
      lVar2 = lVar1 - param_1;
    }
    return lVar2;
  }
  return -1;
}

