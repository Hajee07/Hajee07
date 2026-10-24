/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_18009acc0(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong alStack_88 [7];
  longlong *plStack_50;
  longlong alStack_48 [7];
  longlong *plStack_10;
  
  plStack_50 = (longlong *)0x0;
  puVar1 = *(undefined8 **)(param_2 + 0x38);
  if (puVar1 != (undefined8 *)0x0) {
    plStack_50 = (longlong *)(**(code **)*puVar1)(puVar1,alStack_88);
  }
  plVar2 = plStack_50;
  if ((plStack_50 != alStack_88) && (_DAT_181b2f688 != (longlong *)0x181b2f650)) {
    plStack_50 = _DAT_181b2f688;
    goto LAB_18009ae2c;
  }
  plStack_10 = (longlong *)0x0;
  if (plStack_50 != (longlong *)0x0) {
    plVar2 = plStack_50;
    if (plStack_50 == alStack_88) {
      plStack_10 = (longlong *)(**(code **)(*plStack_50 + 8))(plStack_50,alStack_48);
      if (plStack_50 == (longlong *)0x0) goto LAB_18009ad94;
      (**(code **)(*plStack_50 + 0x20))(plStack_50,plStack_50 != alStack_88);
      plVar2 = plStack_10;
    }
    plStack_10 = plVar2;
    plStack_50 = (longlong *)0x0;
  }
LAB_18009ad94:
  if (_DAT_181b2f688 != (longlong *)0x0) {
    plVar2 = _DAT_181b2f688;
    if (_DAT_181b2f688 == (longlong *)0x181b2f650) {
      plStack_50 = (longlong *)(**(code **)(lRam0000000181b2f650 + 8))(0x181b2f650,alStack_88);
      if (_DAT_181b2f688 == (longlong *)0x0) goto LAB_18009ade5;
      (**(code **)(*_DAT_181b2f688 + 0x20))
                (_DAT_181b2f688,_DAT_181b2f688 != (longlong *)0x181b2f650);
      plVar2 = plStack_50;
    }
    plStack_50 = plVar2;
    _DAT_181b2f688 = (longlong *)0x0;
  }
LAB_18009ade5:
  plVar2 = _DAT_181b2f688;
  if ((plStack_10 != (longlong *)0x0) && (plVar2 = plStack_10, plStack_10 == alStack_48)) {
    _DAT_181b2f688 = (longlong *)(**(code **)(*plStack_10 + 8))(plStack_10,0x181b2f650);
    plVar2 = _DAT_181b2f688;
    if (plStack_10 != (longlong *)0x0) {
      (**(code **)(*plStack_10 + 0x20))(plStack_10,plStack_10 != alStack_48);
      plVar2 = _DAT_181b2f688;
    }
  }
LAB_18009ae2c:
  _DAT_181b2f688 = plVar2;
  if (plStack_50 != (longlong *)0x0) {
    (**(code **)(*plStack_50 + 0x20))(plStack_50,plStack_50 != alStack_88);
  }
  return 0x181b2f650;
}

