/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180071340(void)

{
  longlong **pplVar1;
  longlong *plVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong **pplStackX_8;
  
  pplVar4 = _DAT_181b2f4a8;
  pplVar3 = _DAT_181b2f4a8;
  for (pplVar1 = (longlong **)*_DAT_181b2f4a8; _DAT_181b2f4a8 = pplVar3, pplVar1 != pplVar4;
      pplVar1 = (longlong **)*pplVar1) {
    func_0x0001800710b0(*(undefined4 *)(pplVar1 + 2),(longlong)pplVar1 + 0x14);
    pplVar3 = _DAT_181b2f4a8;
  }
  if (_DAT_181b2f4b0 != 0) {
    if (_DAT_181b2f4b0 < _DAT_181b2f4d8 >> 3) {
      func_0x0001800793c0(0x181b2f4a0,*pplVar3,pplVar3);
    }
    else {
      *pplVar3[1] = 0;
      pplVar1 = (longlong **)*pplVar3;
      while (pplVar1 != (longlong **)0x0) {
        plVar2 = *pplVar1;
        func_0x000180127e40(pplVar1,0x20);
        pplVar1 = (longlong **)plVar2;
      }
      *_DAT_181b2f4a8 = (longlong *)_DAT_181b2f4a8;
      _DAT_181b2f4a8[1] = (longlong *)_DAT_181b2f4a8;
      pplStackX_8 = _DAT_181b2f4a8;
      _DAT_181b2f4b0 = 0;
      recovered_180067850(_DAT_181b2f4b8,_DAT_181b2f4c0,&pplStackX_8);
    }
  }
  _DAT_181b2f8cc = 0;
  return;
}

