/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong *
recovered_1800678e0(longlong *param_1,ulonglong param_2,undefined8 param_3,longlong param_4,
                   undefined8 param_5,longlong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  
  lVar10 = param_1[2];
  if (0x7fffffffffffffffU - lVar10 < param_2) {
    func_0x000180052a50();
    pcVar5 = (code *)swi(3);
    plVar7 = (longlong *)(*pcVar5)();
    return plVar7;
  }
  uVar3 = param_1[3];
  uVar8 = lVar10 + param_2 | 0xf;
  uVar9 = 0x7fffffffffffffff;
  if (((uVar8 < 0x8000000000000000) && (uVar3 <= 0x7fffffffffffffff - (uVar3 >> 1))) &&
     (uVar1 = uVar3 + (uVar3 >> 1), uVar9 = uVar8, uVar8 < uVar1)) {
    uVar9 = uVar1;
  }
  lVar6 = func_0x000180024110(uVar9 + 1);
  param_1[3] = uVar9;
  param_1[2] = lVar10 + param_2;
  lVar2 = lVar6 + param_4;
  if (uVar3 < 0x10) {
    func_0x0001801ca88d(lVar6,param_1,param_4);
    func_0x0001801ca88d(lVar2,param_5,param_6);
    func_0x0001801ca88d(param_6 + lVar2,param_4 + (longlong)param_1,(lVar10 - param_4) + 1);
  }
  else {
    lVar4 = *param_1;
    func_0x0001801ca88d(lVar6,lVar4,param_4);
    func_0x0001801ca88d(lVar2,param_5,param_6);
    func_0x0001801ca88d(param_6 + lVar2,lVar4 + param_4,(lVar10 - param_4) + 1);
    lVar10 = lVar4;
    if ((0xfff < uVar3 + 1) && (lVar10 = *(longlong *)(lVar4 + -8), 0x1f < (lVar4 - lVar10) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar5 = (code *)swi(3);
      plVar7 = (longlong *)(*pcVar5)();
      return plVar7;
    }
    func_0x000180127e40(lVar10);
  }
  *param_1 = lVar6;
  return param_1;
}

