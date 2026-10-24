/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180072d7f(void)

{
  float fVar1;
  char cVar2;
  longlong *unaff_RBX;
  longlong *plVar3;
  char unaff_BPL;
  longlong *unaff_RSI;
  longlong *plVar4;
  undefined4 unaff_R12D;
  longlong unaff_R14;
  int unaff_R15D;
  float fVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float in_XMM4_Da;
  float unaff_XMM8_Da;
  float unaff_XMM9_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  float unaff_XMM14_Da;
  float unaff_XMM15_Da;
  undefined4 unaff_XMM15_Db;
  undefined4 in_stack_00000030;
  undefined8 uStack0000000000000034;
  longlong in_stack_00000040;
  float in_stack_00000048;
  longlong in_stack_00000050;
  float fStack0000000000000140;
  float fStack0000000000000144;
  undefined8 in_stack_00000148;
  
  fVar9 = _DAT_181b2b5bc;
  do {
    if (((*(char *)((longlong)unaff_RBX + 0x1a) == '\0') &&
        ((DAT_181b2b406 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) &&
       ((DAT_181b2b407 == '\0' || (*(char *)(unaff_RBX + 3) == '\0')))) {
      plVar4 = unaff_RBX + 0x14;
      recovered_180067e80(&stack0x00000140,&DAT_181b2be70,plVar4,unaff_R12D);
      fVar1 = fStack0000000000000144;
      fVar5 = fStack0000000000000140;
      in_XMM4_Da = _DAT_181b2beb0;
      if ((unaff_XMM9_Da <= fStack0000000000000140) && (unaff_XMM9_Da <= fStack0000000000000144)) {
        in_stack_00000040 = *plVar4;
        fVar8 = _DAT_181b2beb0 - (float)in_stack_00000040;
        fVar10 = unaff_XMM15_Da - (float)((ulonglong)in_stack_00000040 >> 0x20);
        fVar8 = fVar10 * fVar10 + fVar8 * fVar8 +
                (unaff_XMM14_Da - *(float *)(plVar4 + 1)) *
                (unaff_XMM14_Da - *(float *)(plVar4 + 1));
        if (fVar8 < 0.0) {
          fVar8 = (float)func_0x0001801cb525(CONCAT44(unaff_XMM15_Db,fVar8));
        }
        else {
          fVar8 = SQRT(fVar8);
        }
        in_XMM4_Da = _DAT_181b2beb0;
        if (fVar8 <= (float)unaff_R15D) {
          dVar6 = (double)func_0x0001801cb507((double)(fVar1 - unaff_XMM11_Da));
          dVar7 = (double)func_0x0001801cb507((double)(fVar5 - unaff_XMM10_Da));
          dVar6 = dVar6 + dVar7;
          if (dVar6 < 0.0) {
            dVar6 = (double)func_0x0001801cb51f(dVar6);
          }
          else {
            dVar6 = SQRT(dVar6);
          }
          fVar5 = (float)dVar6;
          in_XMM4_Da = _DAT_181b2beb0;
          if ((fVar5 <= fVar9) && (fVar5 < unaff_XMM8_Da)) {
            unaff_RSI = unaff_RBX + 3;
            unaff_XMM8_Da = fVar5;
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)unaff_R14);
  if ((unaff_RSI != (longlong *)0x0) && (*(int *)((longlong)unaff_RSI + 0x84) != 0)) {
    unaff_BPL = '\x01';
    DAT_181b2f649 = 1;
    _DAT_181b302e8 = unaff_RSI;
  }
  plVar4 = _DAT_181b302e8;
  if (((unaff_BPL != '\0') && (_DAT_181b302e8 != (longlong *)0x0)) &&
     (*(int *)((longlong)_DAT_181b302e8 + 0x84) != 0)) {
    if (*(char *)((longlong)_DAT_181b302e8 + 2) == '\0') {
      plVar3 = _DAT_181b302e8 + 0x11;
      in_stack_00000040 = *plVar3;
      fVar9 = in_XMM4_Da - (float)in_stack_00000040;
      fVar5 = unaff_XMM15_Da - (float)((ulonglong)in_stack_00000040 >> 0x20);
      fVar9 = fVar5 * fVar5 + fVar9 * fVar9 +
              (unaff_XMM14_Da - *(float *)(_DAT_181b302e8 + 0x12)) *
              (unaff_XMM14_Da - *(float *)(_DAT_181b302e8 + 0x12));
      if (fVar9 < 0.0) {
        fVar9 = (float)func_0x0001801cb525(CONCAT44(unaff_XMM15_Db,fVar9));
        in_XMM4_Da = _DAT_181b2beb0;
      }
      else {
        fVar9 = SQRT(fVar9);
      }
      if (fVar9 <= (float)unaff_R15D) {
        if (_DAT_181b2b5b8 == 1) {
          plVar3 = plVar4 + 0x20;
        }
        in_stack_00000050 = *plVar3;
        in_stack_00000030 = 0;
        uStack0000000000000034 = 0x3f800000;
        in_stack_00000040 =
             CONCAT44(((float)((ulonglong)in_stack_00000050 >> 0x20) + 0.0) - unaff_XMM15_Da,
                      ((float)in_stack_00000050 + 0.0) - in_XMM4_Da);
        in_stack_00000048 = (*(float *)(plVar3 + 1) + 0.0) - unaff_XMM14_Da;
        func_0x00018006da10(&stack0x00000050,&stack0x00000040,&stack0x00000030);
        cVar2 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,&stack0x00000148);
        if (cVar2 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,in_stack_00000148,&stack0x00000050,0x10);
        }
        fStack0000000000000140 =
             (float)recovered_180069360((ulonglong)*(uint *)((longlong)_DAT_181b302e8 + 0x84) +
                                        0x4e8);
        if (fStack0000000000000140 == 0.0) {
          return;
        }
        cVar2 = recovered_180067cc0((ulonglong)*(uint *)((longlong)_DAT_181b302e8 + 0x84) + 0x54,
                                    &stack0x00000148);
        if (cVar2 == '\0') {
          return;
        }
        (*_DAT_181b4efa8)(_DAT_181b4ef90,in_stack_00000148,&stack0x00000140,4);
        return;
      }
    }
    DAT_181b2f649 = 0;
    _DAT_181b302e8 = (longlong *)0x0;
  }
  return;
}

