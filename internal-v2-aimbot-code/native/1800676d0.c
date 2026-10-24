/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_1800676d0(longlong **param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  plVar1 = param_1[3];
  if (plVar1 < param_3) {
    if ((longlong *)0x7fffffffffffffff < param_3) {
      func_0x000180052a50();
      pcVar2 = (code *)swi(3);
      pplVar3 = (longlong **)(*pcVar2)();
      return pplVar3;
    }
    plVar4 = (longlong *)((ulonglong)param_3 | 0xf);
    plVar6 = (longlong *)0x7fffffffffffffff;
    if (((plVar4 < (longlong *)0x8000000000000000) &&
        (plVar1 <= (longlong *)(0x7fffffffffffffff - ((ulonglong)plVar1 >> 1)))) &&
       (plVar5 = (longlong *)((longlong)plVar1 + ((ulonglong)plVar1 >> 1)), plVar6 = plVar4,
       plVar4 < plVar5)) {
      plVar6 = plVar5;
    }
    plVar4 = (longlong *)func_0x000180024110((longlong)plVar6 + 1);
    param_1[2] = param_3;
    param_1[3] = plVar6;
    func_0x0001801ca88d(plVar4,param_2,param_3);
    *(undefined *)((longlong)plVar4 + (longlong)param_3) = 0;
    if ((longlong *)0xf < plVar1) {
      plVar6 = *param_1;
      plVar5 = plVar6;
      if ((0xfff < (longlong)plVar1 + 1U) &&
         (plVar5 = (longlong *)plVar6[-1],
         0x1f < (ulonglong)((longlong)plVar6 + (-8 - (longlong)plVar5)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        pplVar3 = (longlong **)(*pcVar2)();
        return pplVar3;
      }
      func_0x000180127e40(plVar5);
    }
    *param_1 = plVar4;
  }
  else {
    pplVar3 = param_1;
    if ((longlong *)0xf < plVar1) {
      pplVar3 = (longlong **)*param_1;
    }
    param_1[2] = param_3;
    func_0x0001801ca893(pplVar3);
    *(undefined *)((longlong)pplVar3 + (longlong)param_3) = 0;
  }
  return param_1;
}

