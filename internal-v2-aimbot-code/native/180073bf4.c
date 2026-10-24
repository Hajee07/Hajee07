/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180073bf4(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  longlong *unaff_RBX;
  longlong unaff_RBP;
  longlong *unaff_RSI;
  longlong *plVar8;
  longlong unaff_R14;
  undefined4 unaff_R15D;
  double dVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  undefined4 in_stack_00000030;
  undefined8 uStack0000000000000034;
  longlong in_stack_00000040;
  float in_stack_00000048;
  longlong in_stack_00000050;
  
  fVar6 = _DAT_181b2beb8;
  fVar5 = _DAT_181b2beb4;
  fVar4 = _DAT_181b2beb0;
  cVar7 = DAT_181b2b406;
  fVar3 = _DAT_181a03230;
  do {
    if ((((unaff_RBX + 3 != (longlong *)0x0) && (*(int *)((longlong)unaff_RBX + 0x9c) != 0)) &&
        (*(char *)((longlong)unaff_RBX + 0x1a) == '\0')) &&
       ((cVar7 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) {
      plVar8 = unaff_RBX + 0x14;
      recovered_180067e80(unaff_RBP + 0x40,&DAT_181b2be70,plVar8,unaff_R15D);
      fVar1 = *(float *)(unaff_RBP + 0x40);
      if ((fVar3 <= fVar1) && (fVar2 = *(float *)(unaff_RBP + 0x44), fVar3 <= fVar2)) {
        in_stack_00000040 = *plVar8;
        fVar12 = fVar4 - (float)in_stack_00000040;
        fVar11 = fVar6 - *(float *)(plVar8 + 1);
        fVar13 = fVar5 - (float)((ulonglong)in_stack_00000040 >> 0x20);
        fVar11 = fVar13 * fVar13 + fVar12 * fVar12 + fVar11 * fVar11;
        if (fVar11 < 0.0) {
          fVar11 = (float)func_0x0001801cb525(fVar11);
        }
        else {
          fVar11 = SQRT(fVar11);
        }
        if (fVar11 <= (float)_DAT_181b2b40c) {
          dVar9 = (double)func_0x0001801cb507((double)(fVar2 - unaff_XMM11_Da));
          dVar10 = (double)func_0x0001801cb507((double)(fVar1 - unaff_XMM10_Da));
          dVar9 = dVar9 + dVar10;
          if (dVar9 < 0.0) {
            dVar9 = (double)func_0x0001801cb51f(dVar9);
          }
          else {
            dVar9 = SQRT(dVar9);
          }
          if ((float)dVar9 < unaff_XMM8_Da) {
            unaff_RSI = unaff_RBX + 3;
            unaff_XMM8_Da = (float)dVar9;
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)unaff_R14);
  if ((unaff_RSI != (longlong *)0x0) && (*(int *)((longlong)unaff_RSI + 0x84) != 0)) {
    in_stack_00000050 = unaff_RSI[0x11];
    in_stack_00000030 = 0;
    uStack0000000000000034 = 0x3f800000;
    in_stack_00000040 =
         CONCAT44(((float)((ulonglong)in_stack_00000050 >> 0x20) + 0.0) - fVar5,
                  ((float)in_stack_00000050 + 0.0) - fVar4);
    in_stack_00000048 = (*(float *)(unaff_RSI + 0x12) + 0.0) - fVar6;
    func_0x00018006da10(&stack0x00000050,&stack0x00000040,&stack0x00000030);
    cVar7 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,unaff_RBP + 0x40);
    if (cVar7 != '\0') {
      (*_DAT_181b4efa8)(_DAT_181b4ef90,*(undefined8 *)(unaff_RBP + 0x40),&stack0x00000050,0x10);
    }
    *(undefined8 *)(unaff_RBP + 0x40) = 0;
    recovered_1800693e0(unaff_RBP + 0x40);
  }
  return;
}

