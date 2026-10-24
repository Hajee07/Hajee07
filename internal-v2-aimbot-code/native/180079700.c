/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180079700(undefined8 param_1,longlong **param_2)

{
  char cVar1;
  longlong **pplVar2;
  undefined8 uVar3;
  longlong **pplVar4;
  
  pplVar4 = (longlong **)param_2[2];
  if (*(char *)((longlong)pplVar4 + 0x19) == '\0') {
    cVar1 = *(char *)((longlong)*pplVar4 + 0x19);
    pplVar2 = (longlong **)*pplVar4;
    while (cVar1 == '\0') {
      cVar1 = *(char *)((longlong)*pplVar2 + 0x19);
      pplVar4 = pplVar2;
      pplVar2 = (longlong **)*pplVar2;
    }
  }
  else {
    cVar1 = *(char *)((longlong)param_2[1] + 0x19);
    pplVar2 = (longlong **)param_2[1];
    while ((pplVar4 = pplVar2, cVar1 == '\0' && (param_2 == (longlong **)pplVar4[2]))) {
      cVar1 = *(char *)((longlong)pplVar4[1] + 0x19);
      pplVar2 = (longlong **)pplVar4[1];
      param_2 = pplVar4;
    }
  }
  uVar3 = recovered_18007a550(&DAT_181b2f4e8);
  func_0x000180127e40(uVar3,0x28);
  return pplVar4;
}

