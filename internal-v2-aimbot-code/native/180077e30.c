/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180077e30(longlong param_1)

{
  uint uVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  
  pplVar2 = *(longlong ***)(param_1 + 8);
  pplVar6 = (longlong **)
            (((((((ulonglong)(byte)_DAT_181b4efb8 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                (ulonglong)(_DAT_181b4efb8 >> 8 & 0xff)) * 0x100000001b3 ^
               (ulonglong)(_DAT_181b4efb8 >> 0x10 & 0xff)) * 0x100000001b3 ^
              (ulonglong)(_DAT_181b4efb8 >> 0x18)) * 0x100000001b3 & *(ulonglong *)(param_1 + 0x30))
             * 0x10 + *(longlong *)(param_1 + 0x18));
  pplVar3 = (longlong **)pplVar6[1];
  if (pplVar3 == pplVar2) {
LAB_180077ec1:
    pplVar5 = (longlong **)0x0;
  }
  else {
    uVar1 = *(uint *)(pplVar3 + 2);
    pplVar5 = pplVar3;
    while (_DAT_181b4efb8 != uVar1) {
      if (pplVar5 == (longlong **)*pplVar6) goto LAB_180077ec1;
      pplVar5 = (longlong **)pplVar5[1];
      uVar1 = *(uint *)(pplVar5 + 2);
    }
  }
  if (pplVar5 != (longlong **)0x0) {
    if (pplVar3 == pplVar5) {
      if ((longlong **)*pplVar6 == pplVar5) {
        *pplVar6 = (longlong *)pplVar2;
        pplVar6[1] = (longlong *)pplVar2;
      }
      else {
        pplVar6[1] = pplVar5[1];
      }
    }
    else if ((longlong **)*pplVar6 == pplVar5) {
      *pplVar6 = *pplVar5;
    }
    plVar4 = *pplVar5;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
    *pplVar5[1] = (longlong)plVar4;
    plVar4[1] = (longlong)pplVar5[1];
    func_0x000180127e40(pplVar5,0x18);
    return 1;
  }
  return 0;
}

