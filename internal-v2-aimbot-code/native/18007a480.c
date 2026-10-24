/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18007a480(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  lVar1 = *param_1;
  if (lVar1 != 0) {
    lVar3 = lVar1;
    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 0x28) * 0x28)) &&
       (lVar3 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(lVar3);
  }
  *param_1 = param_2;
  param_1[1] = param_2 + param_3 * 0x28;
  param_1[2] = param_2 + param_4 * 0x28;
  return;
}

