/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * recovered_180085590(void)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined *puVar5;
  longlong lVar6;
  longlong unaff_GS_OFFSET;
  
  if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8) +
               4) < _DAT_181b50980) && (func_0x000180127a18(&DAT_181b50980), _DAT_181b50980 == -1))
  {
    _DAT_181b50940 = 0;
    _DAT_181b50948 = 0;
    _DAT_181b50950 = 0;
    lVar3 = func_0x000180127a94(0x38);
    *(longlong *)lVar3 = lVar3;
    *(longlong *)(lVar3 + 8) = lVar3;
    _DAT_181b50958 = (longlong *)0x0;
    _DAT_181b50960 = ZEXT816(0);
    _DAT_181b50970 = 7;
    _DAT_181b50978 = 8;
    _DAT_181b50940 = 0x3f800000;
    _DAT_181b50948 = lVar3;
    plVar4 = (longlong *)func_0x000180127a94(0x80);
    lVar6 = _DAT_181b50968 - (longlong)_DAT_181b50958 >> 3;
    if (lVar6 != 0) {
      if ((0xfff < (ulonglong)(lVar6 * 8)) &&
         (0x1f < ((longlong)_DAT_181b50958 - *(longlong *)((longlong)_DAT_181b50958 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        puVar5 = (undefined *)(*pcVar2)();
        return puVar5;
      }
      func_0x000180127e40();
    }
    plVar1 = plVar4 + 0x10;
    _DAT_181b50968 = (longlong)plVar1;
    _DAT_181b50960 = plVar1;
    _DAT_181b50958 = plVar4;
    for (; plVar4 != plVar1; plVar4 = plVar4 + 1) {
      *plVar4 = lVar3;
    }
    func_0x000180127e28(&DAT_1801d0900);
    func_0x0001801279ac(&DAT_181b50980);
  }
  return &DAT_181b50940;
}

