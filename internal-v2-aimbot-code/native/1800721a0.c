/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong ** recovered_1800721a0(void)

{
  longlong **pplVar1;
  longlong *plVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  undefined8 *in_RAX;
  longlong **pplVar5;
  longlong **pplVar6;
  undefined8 *puVar7;
  longlong **pplStackX_8;
  longlong **pplStackX_10;
  longlong **pplStackX_18;
  ulonglong uStackX_20;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  
  pplVar3 = _DAT_181b2f468;
  pplVar4 = _DAT_181b2f468;
  for (pplVar1 = (longlong **)*_DAT_181b2f468; _DAT_181b2f468 = pplVar4, pplVar1 != pplVar3;
      pplVar1 = (longlong **)*pplVar1) {
    pplStackX_8 = (longlong **)((ulonglong)pplStackX_8 & 0xffffffff00000000);
    pplStackX_10 = (longlong **)((ulonglong)pplStackX_10 & 0xffffffff00000000);
    pplStackX_18 = (longlong **)((ulonglong)pplStackX_18 & 0xffffffff00000000);
    uStackX_20 = uStackX_20 & 0xffffffff00000000;
    in_RAX = (undefined8 *)
             recovered_180067cc0((ulonglong)*(uint *)(pplVar1 + 2) + _DAT_181a2b148,&uStack_68);
    if (((char)in_RAX != '\0') &&
       (in_RAX = (undefined8 *)(*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_68,&pplStackX_10,4),
       (int)in_RAX == 0)) {
      in_RAX = (undefined8 *)((ulonglong)pplStackX_10 & 0xffffffff);
      if (((int)pplStackX_10 != 0) &&
         ((in_RAX = (undefined8 *)recovered_180067cc0((int)pplStackX_10 + 8,&uStack_60),
          (char)in_RAX != '\0' &&
          (in_RAX = (undefined8 *)(*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,&pplStackX_18,4),
          (int)in_RAX == 0)))) {
        in_RAX = (undefined8 *)((ulonglong)pplStackX_18 & 0xffffffff);
        if (((int)pplStackX_18 != 0) &&
           ((in_RAX = (undefined8 *)recovered_180067cc0((int)pplStackX_18 + 8,&uStack_58),
            (char)in_RAX != '\0' &&
            (in_RAX = (undefined8 *)(*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_58,&uStackX_20,4),
            (int)in_RAX == 0)))) {
          in_RAX = (undefined8 *)(uStackX_20 & 0xffffffff);
          if (((int)uStackX_20 != 0) &&
             ((in_RAX = (undefined8 *)recovered_180067cc0((int)uStackX_20 + 0x20,&uStack_50),
              (char)in_RAX != '\0' &&
              (in_RAX = (undefined8 *)(*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_50,&pplStackX_8,4),
              (int)in_RAX == 0)))) {
            in_RAX = (undefined8 *)((ulonglong)pplStackX_8 & 0xffffffff);
            if (((int)pplStackX_8 != 0) &&
               ((in_RAX = (undefined8 *)recovered_180067cc0((int)pplStackX_8 + 0x60,&uStack_48),
                (char)in_RAX != '\0' &&
                (in_RAX = (undefined8 *)
                          (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_48,&stack0xffffffffffffffc8,0xc),
                (int)in_RAX == 0)))) {
              in_RAX = (undefined8 *)recovered_180067cc0((int)pplStackX_8 + 0x60,&uStack_40);
              if ((char)in_RAX != '\0') {
                in_RAX = (undefined8 *)
                         (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_40,(longlong)pplVar1 + 0x14,0xc);
              }
            }
          }
        }
      }
    }
    pplVar4 = _DAT_181b2f468;
  }
  if (_DAT_181b2f470 != 0) {
    if (_DAT_181b2f470 < _DAT_181b2f498 >> 3) {
      pplVar1 = (longlong **)*pplVar4;
      if (pplVar1 == pplVar4) {
        return pplVar4;
      }
      pplVar3 = (longlong **)pplVar1[1];
      puVar7 = (undefined8 *)
               (((((((ulonglong)*(byte *)(pplVar1 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                   (ulonglong)*(byte *)((longlong)pplVar1 + 0x11)) * 0x100000001b3 ^
                  (ulonglong)*(byte *)((longlong)pplVar1 + 0x12)) * 0x100000001b3 ^
                 (ulonglong)*(byte *)((longlong)pplVar1 + 0x13)) * 0x100000001b3 & _DAT_181b2f490) *
                0x10 + _DAT_181b2f478);
      pplStackX_10 = (longlong **)*puVar7;
      pplStackX_18 = (longlong **)puVar7[1];
      pplVar5 = pplVar1;
      uStackX_20 = _DAT_181b2f478;
      do {
        pplVar6 = (longlong **)*pplVar5;
        uStack_60 = 0x180079483;
        func_0x000180127e40(pplVar5,0x20);
        _DAT_181b2f470 = _DAT_181b2f470 - 1;
        if (pplVar5 == pplStackX_18) {
          pplVar5 = pplVar3;
          if (pplStackX_10 == pplVar1) {
            *puVar7 = pplVar4;
            pplVar5 = pplVar4;
          }
          puVar7[1] = pplVar5;
          while (pplVar6 != pplVar4) {
            puVar7 = (undefined8 *)
                     (((((((ulonglong)*(byte *)(pplVar6 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                         (ulonglong)*(byte *)((longlong)pplVar6 + 0x11)) * 0x100000001b3 ^
                        (ulonglong)*(byte *)((longlong)pplVar6 + 0x12)) * 0x100000001b3 ^
                       (ulonglong)*(byte *)((longlong)pplVar6 + 0x13)) * 0x100000001b3 &
                      _DAT_181b2f490) * 0x10 + uStackX_20);
            pplVar1 = (longlong **)puVar7[1];
            pplVar5 = pplVar6;
            while( true ) {
              pplVar6 = (longlong **)*pplVar5;
              uStack_60 = 0x180079555;
              func_0x000180127e40(pplVar5,0x20);
              _DAT_181b2f470 = _DAT_181b2f470 - 1;
              if (pplVar5 == pplVar1) break;
              pplVar5 = pplVar6;
              if (pplVar6 == pplVar4) goto LAB_18007949a;
            }
            *puVar7 = pplVar4;
            puVar7[1] = pplVar4;
          }
          goto LAB_18007949d;
        }
        pplVar5 = pplVar6;
      } while (pplVar6 != pplVar4);
      if (pplStackX_10 == pplVar1) {
LAB_18007949a:
        *puVar7 = pplVar6;
      }
LAB_18007949d:
      *pplVar3 = (longlong *)pplVar6;
      pplVar6[1] = (longlong *)pplVar3;
      return pplVar4;
    }
    *pplVar4[1] = 0;
    pplVar1 = (longlong **)*pplVar4;
    while (pplVar1 != (longlong **)0x0) {
      plVar2 = *pplVar1;
      func_0x000180127e40(pplVar1,0x20);
      pplVar1 = (longlong **)plVar2;
    }
    *_DAT_181b2f468 = (longlong *)_DAT_181b2f468;
    _DAT_181b2f468[1] = (longlong *)_DAT_181b2f468;
    pplStackX_8 = _DAT_181b2f468;
    _DAT_181b2f470 = 0;
    in_RAX = (undefined8 *)recovered_180067850(_DAT_181b2f478,_DAT_181b2f480,&pplStackX_8);
  }
  return (longlong **)in_RAX;
}

