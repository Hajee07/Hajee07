/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006e930(void)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  
  recovered_18006f2b0();
  lVar4 = _DAT_181b2f4e8;
  cVar1 = *(char *)((longlong)*(longlong **)(_DAT_181b2f4e8 + 8) + 0x19);
  plVar3 = *(longlong **)(_DAT_181b2f4e8 + 8);
  while (cVar1 == '\0') {
    func_0x000180023e30(&DAT_181b2f4e8,&DAT_181b2f4e8,plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    func_0x000180127e40(plVar3,0x28);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  *(longlong *)(lVar4 + 8) = lVar4;
  *(longlong *)lVar4 = lVar4;
  *(longlong *)(lVar4 + 0x10) = lVar4;
  _DAT_181b2f4f0 = 0;
  _DAT_181b302f4 = 0;
  _DAT_181b2bee0 = 0;
  _DAT_181b2bec0 = 0;
  DAT_181b2bedd = 0;
  return;
}

