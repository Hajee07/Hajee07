/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong recovered_180079580(undefined8 param_1,longlong **param_2)

{
  char cVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  undefined8 uVar7;
  longlong **pplVar8;
  longlong lVar9;
  
  pplVar2 = (longlong **)*param_2;
  lVar9 = 0;
  pplVar3 = (longlong **)param_2[1];
  pplVar4 = pplVar2;
  while (pplVar4 != pplVar3) {
    pplVar8 = (longlong **)pplVar4[2];
    lVar9 = lVar9 + 1;
    if (*(char *)((longlong)pplVar8 + 0x19) == '\0') {
      cVar1 = *(char *)((longlong)*pplVar8 + 0x19);
      pplVar4 = pplVar8;
      pplVar8 = (longlong **)*pplVar8;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((longlong)*pplVar8 + 0x19);
        pplVar4 = pplVar8;
        pplVar8 = (longlong **)*pplVar8;
      }
    }
    else {
      cVar1 = *(char *)((longlong)pplVar4[1] + 0x19);
      pplVar6 = (longlong **)pplVar4[1];
      pplVar8 = pplVar4;
      while ((pplVar4 = pplVar6, cVar1 == '\0' && (pplVar8 == (longlong **)pplVar4[2]))) {
        cVar1 = *(char *)((longlong)pplVar4[1] + 0x19);
        pplVar6 = (longlong **)pplVar4[1];
        pplVar8 = pplVar4;
      }
    }
  }
  if ((pplVar2 == (longlong **)*_DAT_181b2f4e8) && (*(char *)((longlong)pplVar3 + 0x19) != '\0')) {
    recovered_180078100();
    return lVar9;
  }
  while (pplVar2 != pplVar3) {
    pplVar4 = (longlong **)pplVar2[2];
    if (*(char *)((longlong)pplVar4 + 0x19) == '\0') {
      cVar1 = *(char *)((longlong)*pplVar4 + 0x19);
      pplVar8 = pplVar4;
      pplVar6 = (longlong **)*pplVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((longlong)*pplVar6 + 0x19);
        pplVar8 = pplVar6;
        pplVar6 = (longlong **)*pplVar6;
      }
      pplVar4 = (longlong **)*pplVar4;
      cVar1 = *(char *)((longlong)pplVar4 + 0x19);
      while (cVar1 == '\0') {
        pplVar4 = (longlong **)*pplVar4;
        cVar1 = *(char *)((longlong)pplVar4 + 0x19);
      }
    }
    else {
      cVar1 = *(char *)((longlong)pplVar2[1] + 0x19);
      pplVar6 = (longlong **)pplVar2[1];
      pplVar4 = pplVar2;
      while ((pplVar8 = pplVar6, cVar1 == '\0' && (pplVar4 == (longlong **)pplVar8[2]))) {
        cVar1 = *(char *)((longlong)pplVar8[1] + 0x19);
        pplVar6 = (longlong **)pplVar8[1];
        pplVar4 = pplVar8;
      }
      cVar1 = *(char *)((longlong)pplVar2[1] + 0x19);
      pplVar6 = (longlong **)pplVar2[1];
      pplVar4 = pplVar2;
      while ((pplVar5 = pplVar6, cVar1 == '\0' && (pplVar4 == (longlong **)pplVar5[2]))) {
        cVar1 = *(char *)((longlong)pplVar5[1] + 0x19);
        pplVar6 = (longlong **)pplVar5[1];
        pplVar4 = pplVar5;
      }
    }
    uVar7 = recovered_18007a550(&DAT_181b2f4e8,pplVar2);
    func_0x000180127e40(uVar7,0x28);
    pplVar2 = pplVar8;
  }
  return lVar9;
}

