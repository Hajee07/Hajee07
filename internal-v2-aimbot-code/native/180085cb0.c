/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong **
recovered_180085cb0(longlong param_1,longlong **param_2,undefined8 *param_3,ulonglong param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  longlong **pplVar7;
  
  pplVar7 = (longlong **)
            ((*(ulonglong *)(param_1 + 0x30) & param_4) * 0x10 + *(longlong *)(param_1 + 0x18));
  pplVar6 = (longlong **)pplVar7[1];
  if (pplVar6 == *(longlong ***)(param_1 + 8)) {
    *param_2 = (longlong *)*(longlong ***)(param_1 + 8);
    param_2[1] = (longlong *)0x0;
    return param_2;
  }
  pplVar7 = (longlong **)*pplVar7;
  plVar1 = (longlong *)param_3[2];
  uVar2 = param_3[3];
  while( true ) {
    pplVar5 = pplVar6 + 2;
    if ((longlong *)0xf < pplVar6[5]) {
      pplVar5 = (longlong **)*pplVar5;
    }
    puVar4 = param_3;
    if (0xf < uVar2) {
      puVar4 = (undefined8 *)*param_3;
    }
    if ((plVar1 == pplVar6[4]) &&
       ((plVar1 == (longlong *)0x0 ||
        (iVar3 = func_0x0001801ca8a5(puVar4,pplVar5,plVar1), iVar3 == 0)))) break;
    if (pplVar6 == pplVar7) {
      *param_2 = (longlong *)pplVar6;
      param_2[1] = (longlong *)0x0;
      return param_2;
    }
    pplVar6 = (longlong **)pplVar6[1];
  }
  *param_2 = *pplVar6;
  param_2[1] = (longlong *)pplVar6;
  return param_2;
}

