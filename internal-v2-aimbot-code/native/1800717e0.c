/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * recovered_1800717e0(void)

{
  bool bVar1;
  float fVar2;
  undefined8 *puVar3;
  longlong *unaff_RBX;
  longlong *unaff_RBP;
  longlong unaff_RSI;
  int unaff_R14D;
  float fVar4;
  float fVar5;
  float unaff_XMM7_Da;
  float fVar6;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  float unaff_XMM12_Da;
  float unaff_XMM13_Da;
  float unaff_XMM14_Da;
  float fStackX_20;
  float fStackX_24;
  float in_stack_00000028;
  float fStack0000000000000034;
  
  fVar2 = _DAT_181a03230;
  do {
    if (((((*(int *)((longlong)unaff_RBX + 0x9c) != 0) &&
          (*(int *)((longlong)unaff_RBX + 0x9c) != unaff_R14D)) &&
         (*(char *)((longlong)unaff_RBX + 0x19) != '\0')) &&
        ((*(char *)((longlong)unaff_RBX + 0x1a) == '\0' && (*(int *)(unaff_RBX + 6) != 0)))) &&
       ((DAT_181b2b406 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) {
      puVar3 = (undefined8 *)recovered_180071430(&stack0x00000040,unaff_RBX + 3);
      if ((((float)*puVar3 == 0.0) &&
          (fStack0000000000000034 = (float)((ulonglong)*puVar3 >> 0x20),
          fStack0000000000000034 == 0.0)) && (*(float *)(puVar3 + 1) == 0.0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((((bVar1) && (recovered_180071430(&fStackX_20,unaff_RBX + 3), 0 < _DAT_181b2bec8)) &&
          (0 < _DAT_181b2becc)) &&
         (fVar5 = fStackX_24 * _DAT_181b2be8c + fStackX_20 * _DAT_181b2be7c +
                  in_stack_00000028 * _DAT_181b2be9c + _DAT_181b2beac, _DAT_181a03124 <= fVar5)) {
        fVar6 = ((fStackX_24 * _DAT_181b2be80 + fStackX_20 * _DAT_181b2be70 +
                  in_stack_00000028 * _DAT_181b2be90 + _DAT_181b2bea0) *
                (float)_DAT_181b2bec8 * unaff_XMM7_Da) / fVar5 +
                (float)_DAT_181b2bec8 * unaff_XMM7_Da;
        fVar5 = (float)_DAT_181b2becc * unaff_XMM7_Da -
                ((fStackX_24 * _DAT_181b2be84 + fStackX_20 * _DAT_181b2be74 +
                  in_stack_00000028 * _DAT_181b2be94 + _DAT_181b2bea4) *
                (float)_DAT_181b2becc * unaff_XMM7_Da) / fVar5;
        if ((fVar2 <= fVar6) && (fVar2 <= fVar5)) {
          fVar4 = (_DAT_181b2beb4 - fStackX_24) * (_DAT_181b2beb4 - fStackX_24) +
                  (_DAT_181b2beb0 - fStackX_20) * (_DAT_181b2beb0 - fStackX_20) +
                  (_DAT_181b2beb8 - in_stack_00000028) * (_DAT_181b2beb8 - in_stack_00000028);
          if (fVar4 < 0.0) {
            fVar4 = (float)func_0x0001801cb525(fVar4);
          }
          else {
            fVar4 = SQRT(fVar4);
          }
          if (fVar4 <= unaff_XMM10_Da) {
            fVar5 = fVar5 - unaff_XMM14_Da;
            fVar6 = fVar6 - unaff_XMM13_Da;
            fVar5 = fVar5 * fVar5 + fVar6 * fVar6;
            if (fVar5 < 0.0) {
              fVar5 = (float)func_0x0001801cb525(fVar5);
            }
            else {
              fVar5 = SQRT(fVar5);
            }
            if ((fVar5 <= unaff_XMM12_Da) && (fVar5 < unaff_XMM11_Da)) {
              unaff_RBP = unaff_RBX + 3;
              unaff_XMM11_Da = fVar5;
            }
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
    unaff_XMM7_Da = _DAT_181a031bc;
  } while (unaff_RBX != (longlong *)unaff_RSI);
  return unaff_RBP;
}

