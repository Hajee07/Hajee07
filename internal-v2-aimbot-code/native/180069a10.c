/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180069a10(longlong param_1)

{
  longlong **pplVar1;
  longlong **pplVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  undefined8 *puVar7;
  longlong **in_RAX;
  longlong **pplVar8;
  longlong **pplVar9;
  longlong **pplVar10;
  longlong **pplVar11;
  longlong **pplVar12;
  
  if (*(ulonglong *)(param_1 + 0x10) != 0) {
    pplVar1 = *(longlong ***)(param_1 + 8);
    if (*(ulonglong *)(param_1 + 0x10) < *(ulonglong *)(param_1 + 0x38) >> 3) {
      pplVar2 = (longlong **)*pplVar1;
      if (pplVar2 == pplVar1) {
        return pplVar1;
      }
      lVar4 = *(longlong *)(param_1 + 0x18);
      pplVar5 = *(longlong ***)(param_1 + 8);
      pplVar6 = (longlong **)pplVar2[1];
      pplVar8 = (longlong **)
                ((((ulonglong)*(byte *)((longlong)pplVar2 + 0x17) ^
                  ((((((((ulonglong)*(byte *)(pplVar2 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       (ulonglong)*(byte *)((longlong)pplVar2 + 0x11)) * 0x100000001b3 ^
                      (ulonglong)*(byte *)((longlong)pplVar2 + 0x12)) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)pplVar2 + 0x13)) * 0x100000001b3 ^
                    (ulonglong)*(byte *)((longlong)pplVar2 + 0x14)) * 0x100000001b3 ^
                   (ulonglong)*(byte *)((longlong)pplVar2 + 0x15)) * 0x100000001b3 ^
                  (ulonglong)*(byte *)((longlong)pplVar2 + 0x16)) * 0x100000001b3) * 0x100000001b3 &
                 *(ulonglong *)(param_1 + 0x30)) * 0x10 + lVar4);
      pplVar10 = (longlong **)*pplVar8;
      pplVar12 = (longlong **)pplVar8[1];
      pplVar9 = pplVar2;
      do {
        pplVar11 = (longlong **)*pplVar9;
        func_0x000180127e40(pplVar9,0x20);
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
        if (pplVar9 == pplVar12) {
          pplVar12 = pplVar6;
          if (pplVar10 == pplVar2) {
            *pplVar8 = (longlong *)pplVar5;
            pplVar12 = pplVar5;
          }
          pplVar8[1] = (longlong *)pplVar12;
          while (pplVar11 != pplVar1) {
            pplVar12 = (longlong **)
                       (((((((((((ulonglong)*(byte *)(pplVar11 + 2) ^ 0xcbf29ce484222325) *
                                0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x11)) *
                               0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x12)) *
                              0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x13)) *
                             0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x14)) *
                            0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x15)) *
                           0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x16)) *
                          0x100000001b3 ^ (ulonglong)*(byte *)((longlong)pplVar11 + 0x17)) *
                         0x100000001b3 & *(ulonglong *)(param_1 + 0x30)) * 0x10 + lVar4);
            pplVar2 = (longlong **)pplVar12[1];
            pplVar10 = pplVar11;
            while( true ) {
              pplVar11 = (longlong **)*pplVar10;
              func_0x000180127e40(pplVar10,0x20);
              *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
              if (pplVar10 == pplVar2) break;
              pplVar10 = pplVar11;
              if (pplVar11 == pplVar1) {
                *pplVar12 = (longlong *)pplVar11;
                goto LAB_18006a774;
              }
            }
            *pplVar12 = (longlong *)pplVar5;
            pplVar12[1] = (longlong *)pplVar5;
          }
          goto LAB_18006a774;
        }
        pplVar9 = pplVar11;
      } while (pplVar11 != pplVar1);
      if (pplVar10 == pplVar2) {
        *pplVar8 = (longlong *)pplVar11;
      }
LAB_18006a774:
      *pplVar6 = (longlong *)pplVar11;
      pplVar11[1] = (longlong *)pplVar6;
      return pplVar1;
    }
    *pplVar1[1] = 0;
    puVar7 = *pplVar1;
    while (puVar7 != (undefined8 *)0x0) {
      puVar3 = (undefined8 *)*puVar7;
      func_0x000180127e40(puVar7,0x20);
      puVar7 = puVar3;
    }
    *(undefined8 *)*(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 8);
    *(longlong *)(*(longlong *)(param_1 + 8) + 8) = *(longlong *)(param_1 + 8);
    *(undefined8 *)(param_1 + 0x10) = 0;
    in_RAX = (longlong **)
             recovered_180067850(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),
                                 &stack0x00000008);
  }
  return in_RAX;
}

