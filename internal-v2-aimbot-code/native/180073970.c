/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180073970(void)

{
  float fVar1;
  longlong **pplVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  short sVar10;
  int iVar11;
  undefined8 uVar12;
  uint uVar13;
  uint uVar14;
  longlong **pplVar15;
  longlong **pplVar16;
  longlong **pplVar17;
  double dVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined4 uStack_108;
  undefined8 uStack_104;
  longlong *plStack_f8;
  float fStack_f0;
  longlong *aplStack_e8 [22];
  
  if (((((DAT_181b2b431 != '\0') && (sVar10 = GetAsyncKeyState(_DAT_181b2b414), sVar10 < 0)) &&
       (_DAT_181b2bebc != 0)) &&
      ((iVar11 = recovered_180069360((ulonglong)_DAT_181b2bebc + 0x48), iVar11 != 0 &&
       (iVar11 = recovered_180069360(iVar11 + 8), iVar11 != 0)))) &&
     (iVar11 = recovered_180069360(iVar11 + 0x20), iVar11 != 0)) {
    pplVar15 = (longlong **)0x0;
    uStackX_8 = uStackX_8 & 0xffffffffffff0000;
    cVar9 = recovered_180067cc0(iVar11 + 0x10,&uStackX_10);
    if (cVar9 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar12 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                     &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar12,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_10,&uStackX_8,2);
    }
    iVar6 = _DAT_181b2becc;
    iVar11 = _DAT_181b2bec8;
    fVar5 = _DAT_181b2beb8;
    fVar4 = _DAT_181b2beb4;
    fVar3 = _DAT_181b2beb0;
    pplVar2 = _DAT_181b2be38;
    cVar9 = DAT_181b2b406;
    fVar1 = _DAT_181a03230;
    uVar13 = (uint)(short)(ushort)uStackX_8;
    uVar14 = uVar13 + 25000;
    if (-1 < (short)(ushort)uStackX_8) {
      uVar14 = uVar13;
    }
    if (((((uVar13 != 1) &&
          ((0x10 < (ushort)((ushort)uStackX_8 - 0x259) ||
           ((0x10087U >> ((ushort)((ushort)uStackX_8 - 0x259) & 0x1f) & 1) == 0)))) &&
         (uVar13 != 99)) &&
        (((((ushort)uStackX_8 != 0x579 && ((ushort)uStackX_8 != 0x3ee)) &&
          ((ushort)uStackX_8 != 0x3f7)) &&
         ((((ushort)uStackX_8 != 0x1780 && ((ushort)uStackX_8 != 0x2716)) &&
          ((1 < (ushort)((ushort)uStackX_8 + 0xadf7) && ((uVar14 != 0x2504 && (uVar14 != 0x2507)))))
          ))))) &&
       (((((ushort)uStackX_8 < 0x1f && ((0x7fbffffdU >> (uVar13 & 0x1f) & 1) != 0)) ||
         ((((ushort)(uVar13 - 0x20) < 0x3a &&
           ((0x3c75febf7effabfU >> ((ulonglong)(uVar13 - 0x20) & 0x3f) & 1) != 0)) ||
          (((ushort)(uVar13 - 0x5d) < 0x3a &&
           ((0x202787ffc007fa9U >> ((ulonglong)(uVar13 - 0x5d) & 0x3f) & 1) != 0)))))) ||
        (((ushort)((ushort)uStackX_8 - 0xb2) < 0x35 &&
         ((0x1c0000000f81dfU >> ((ulonglong)(ushort)((ushort)uStackX_8 - 0xb2) & 0x3f) & 1) != 0))))
       )) {
      pplVar16 = (longlong **)*_DAT_181b2be38;
      fVar24 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
      fVar25 = (float)_DAT_181b2becc * _DAT_181a031bc;
      fVar23 = _DAT_181a03460;
      if (pplVar16 != _DAT_181b2be38) {
        do {
          if ((((pplVar16 + 3 != (longlong **)0x0) && (*(int *)((longlong)pplVar16 + 0x9c) != 0)) &&
              (*(char *)((longlong)pplVar16 + 0x1a) == '\0')) &&
             ((cVar9 == '\0' || (*(char *)((longlong)pplVar16 + 0x1b) == '\0')))) {
            pplVar17 = pplVar16 + 0x14;
            recovered_180067e80(&uStackX_8,&DAT_181b2be70,pplVar17,iVar11,iVar6);
            fVar7 = (float)uStackX_8;
            if ((fVar1 <= (float)uStackX_8) && (fVar8 = uStackX_8._4_4_, fVar1 <= uStackX_8._4_4_))
            {
              plStack_f8 = *pplVar17;
              fVar21 = fVar3 - SUB84(plStack_f8,0);
              fVar20 = fVar5 - *(float *)(pplVar17 + 1);
              fVar22 = fVar4 - (float)((ulonglong)plStack_f8 >> 0x20);
              fVar20 = fVar22 * fVar22 + fVar21 * fVar21 + fVar20 * fVar20;
              if (fVar20 < 0.0) {
                fVar20 = (float)func_0x0001801cb525(fVar20);
              }
              else {
                fVar20 = SQRT(fVar20);
              }
              if (fVar20 <= (float)_DAT_181b2b40c) {
                dVar18 = (double)func_0x0001801cb507((double)(fVar8 - fVar25));
                dVar19 = (double)func_0x0001801cb507((double)(fVar7 - fVar24));
                dVar18 = dVar18 + dVar19;
                if (dVar18 < 0.0) {
                  dVar18 = (double)func_0x0001801cb51f(dVar18);
                }
                else {
                  dVar18 = SQRT(dVar18);
                }
                if ((float)dVar18 < fVar23) {
                  pplVar15 = pplVar16 + 3;
                  fVar23 = (float)dVar18;
                }
              }
            }
          }
          pplVar16 = (longlong **)*pplVar16;
        } while (pplVar16 != pplVar2);
        if ((pplVar15 != (longlong **)0x0) && (*(int *)((longlong)pplVar15 + 0x84) != 0)) {
          aplStack_e8[0] = pplVar15[0x11];
          uStack_108 = 0;
          uStack_104 = 0x3f800000;
          plStack_f8 = (longlong *)
                       CONCAT44(((float)((ulonglong)aplStack_e8[0] >> 0x20) + 0.0) - fVar4,
                                (SUB84(aplStack_e8[0],0) + 0.0) - fVar3);
          fStack_f0 = (*(float *)(pplVar15 + 0x12) + 0.0) - fVar5;
          func_0x00018006da10(aplStack_e8,&plStack_f8,&uStack_108);
          cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,&uStackX_8);
          if (cVar9 != '\0') {
            (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_8,aplStack_e8,0x10);
          }
          uStackX_8 = 0;
          recovered_1800693e0(&uStackX_8);
        }
      }
    }
  }
  return;
}

