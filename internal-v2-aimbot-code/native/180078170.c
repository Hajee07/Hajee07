/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * recovered_180078170(undefined8 param_1,uint *param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong **pplVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  bool bVar8;
  longlong *plStack_38;
  undefined8 uStack_30;
  longlong *plStack_28;
  uint uStack_20;
  undefined4 uStack_1c;
  
  plVar6 = _DAT_181b2f4e8;
  plStack_28 = (longlong *)_DAT_181b2f4e8[1];
  uStack_20 = 0;
  plVar5 = _DAT_181b2f4e8;
  if (*(char *)((longlong)plStack_28 + 0x19) == '\0') {
    plVar2 = plStack_28;
    plVar7 = _DAT_181b2f4e8;
    do {
      plStack_28 = plVar2;
      bVar8 = *param_2 <= *(uint *)((longlong)plStack_28 + 0x1c);
      plVar3 = plStack_28;
      plVar5 = plStack_28;
      if (!bVar8) {
        plVar3 = plStack_28 + 2;
        plVar5 = plVar7;
      }
      uStack_20 = (uint)bVar8;
      plVar2 = (longlong *)*plVar3;
      plVar7 = plVar5;
    } while (*(char *)((longlong)(longlong *)*plVar3 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)plVar5 + 0x19) != '\0') ||
     (*param_2 < *(uint *)((longlong)plVar5 + 0x1c))) {
    if (_DAT_181b2f4f0 == 0x666666666666666) {
      func_0x000180003a20();
      pcVar1 = (code *)swi(3);
      plVar6 = (longlong *)(*pcVar1)();
      return plVar6;
    }
    plStack_38 = (longlong *)&DAT_181b2f4e8;
    uStack_30 = 0;
    pplVar4 = (longlong **)func_0x000180127a94(0x28);
    *(uint *)((longlong)pplVar4 + 0x1c) = *param_2;
    *(undefined4 *)(pplVar4 + 4) = 0;
    *pplVar4 = plVar6;
    pplVar4[1] = plVar6;
    pplVar4[2] = plVar6;
    *(undefined2 *)(pplVar4 + 3) = 0;
    plStack_38 = plStack_28;
    uStack_30 = CONCAT44(uStack_1c,uStack_20);
    plVar5 = (longlong *)func_0x000180023e90(&DAT_181b2f4e8,&plStack_38);
  }
  return plVar5 + 4;
}

