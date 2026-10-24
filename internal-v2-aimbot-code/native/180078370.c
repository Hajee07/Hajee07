/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 recovered_180078370(longlong param_1,int *param_2)

{
  int iVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  
  pplVar2 = *(longlong ***)(param_1 + 8);
  pplVar5 = (longlong **)
            (((((((ulonglong)*(byte *)param_2 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                (ulonglong)*(byte *)((longlong)param_2 + 1)) * 0x100000001b3 ^
               (ulonglong)*(byte *)((longlong)param_2 + 2)) * 0x100000001b3 ^
              (ulonglong)*(byte *)((longlong)param_2 + 3)) * 0x100000001b3 &
             *(ulonglong *)(param_1 + 0x30)) * 0x10 + *(longlong *)(param_1 + 0x18));
  pplVar3 = (longlong **)pplVar5[1];
  if (pplVar3 == pplVar2) {
LAB_1800783f4:
    pplVar6 = (longlong **)0x0;
  }
  else {
    iVar1 = *(int *)(pplVar3 + 2);
    pplVar6 = pplVar3;
    while (*param_2 != iVar1) {
      if (pplVar6 == (longlong **)*pplVar5) goto LAB_1800783f4;
      pplVar6 = (longlong **)pplVar6[1];
      iVar1 = *(int *)(pplVar6 + 2);
    }
  }
  if (pplVar6 != (longlong **)0x0) {
    if (pplVar3 == pplVar6) {
      if ((longlong **)*pplVar5 == pplVar6) {
        *pplVar5 = (longlong *)pplVar2;
        pplVar5[1] = (longlong *)pplVar2;
      }
      else {
        pplVar5[1] = pplVar6[1];
      }
    }
    else if ((longlong **)*pplVar5 == pplVar6) {
      *pplVar5 = *pplVar6;
    }
    plVar4 = *pplVar6;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
    *pplVar6[1] = (longlong)plVar4;
    plVar4[1] = (longlong)pplVar6[1];
    recovered_180066e40(pplVar6 + 0xf);
    recovered_180066e40(pplVar6 + 0xb);
    recovered_180066e40(pplVar6 + 7);
    func_0x000180127e40(pplVar6,400);
    return 1;
  }
  return 0;
}

