/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18007e960(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  recovered_180066e40(param_1 + 4);
  if (0xf < (ulonglong)param_1[3]) {
    lVar1 = *param_1;
    lVar3 = lVar1;
    if ((0xfff < param_1[3] + 1U) &&
       (lVar3 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(lVar3);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined *)param_1 = 0;
  return;
}

