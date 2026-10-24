/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009a990(void)

{
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  if ((_DAT_181b2f368 != 0) && (_DAT_181b2f358 != 0)) {
    GetClientRect(_DAT_181b2f368,&iStack_28);
    MapWindowPoints(_DAT_181b2f368,0,&iStack_28,2);
    _DAT_181b2bec8 = iStack_20 - iStack_28;
    _DAT_181b2becc = iStack_1c - iStack_24;
    GetWindowRect(_DAT_181b2f358,&iStack_18);
    if ((iStack_18 != iStack_28) ||
       (((iStack_14 != iStack_24 || (iStack_10 - iStack_18 != iStack_20 - iStack_28)) ||
        (iStack_c - iStack_14 != iStack_1c - iStack_24)))) {
      MoveWindow(_DAT_181b2f358,iStack_28,iStack_24,iStack_20 - iStack_28,iStack_1c - iStack_24,1);
    }
  }
  return;
}

