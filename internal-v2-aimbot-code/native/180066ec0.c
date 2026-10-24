/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180066ec0(longlong **param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong **pplVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  plVar3 = param_1[3];
  plVar8 = param_1[2];
  if ((ulonglong)((longlong)plVar3 - (longlong)plVar8) < param_3) {
    if (0x7fffffffffffffffU - (longlong)plVar8 < param_3) {
      func_0x000180052a50();
      pcVar4 = (code *)swi(3);
      pplVar5 = (longlong **)(*pcVar4)();
      return pplVar5;
    }
    plVar6 = (longlong *)((ulonglong)(longlong *)((longlong)plVar8 + param_3) | 0xf);
    plVar7 = (longlong *)0x7fffffffffffffff;
    if (((plVar6 < (longlong *)0x8000000000000000) &&
        (plVar3 <= (longlong *)(0x7fffffffffffffff - ((ulonglong)plVar3 >> 1)))) &&
       (plVar1 = (longlong *)((longlong)plVar3 + ((ulonglong)plVar3 >> 1)), plVar7 = plVar6,
       plVar6 < plVar1)) {
      plVar7 = plVar1;
    }
    plVar6 = (longlong *)func_0x000180024110((longlong)plVar7 + 1);
    param_1[2] = (longlong *)((longlong)plVar8 + param_3);
    param_1[3] = plVar7;
    lVar2 = (longlong)plVar8 + (longlong)plVar6;
    if (plVar3 < (longlong *)0x10) {
      func_0x0001801ca88d(plVar6,param_1,plVar8);
      func_0x0001801ca88d(lVar2,param_2,param_3);
      *(undefined *)(lVar2 + param_3) = 0;
    }
    else {
      plVar7 = *param_1;
      func_0x0001801ca88d(plVar6,plVar7,plVar8);
      func_0x0001801ca88d(lVar2,param_2,param_3);
      *(undefined *)(lVar2 + param_3) = 0;
      plVar8 = plVar7;
      if ((0xfff < (longlong)plVar3 + 1U) &&
         (plVar8 = (longlong *)plVar7[-1],
         0x1f < (ulonglong)((longlong)plVar7 + (-8 - (longlong)plVar8)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar4 = (code *)swi(3);
        pplVar5 = (longlong **)(*pcVar4)();
        return pplVar5;
      }
      func_0x000180127e40(plVar8);
    }
    *param_1 = plVar6;
  }
  else {
    param_1[2] = (longlong *)((longlong)plVar8 + param_3);
    pplVar5 = param_1;
    if ((longlong *)0xf < plVar3) {
      pplVar5 = (longlong **)*param_1;
    }
    func_0x0001801ca893((longlong)plVar8 + (longlong)pplVar5);
    *(undefined *)((longlong)plVar8 + (longlong)pplVar5 + param_3) = 0;
  }
  return param_1;
}

