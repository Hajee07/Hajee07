/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800731b0(void)

{
  float fVar1;
  char cVar2;
  float fVar3;
  longlong **pplVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  char cVar10;
  short sVar11;
  longlong **pplVar12;
  longlong **pplVar13;
  longlong **pplVar14;
  float fVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  int aiStackX_8 [2];
  float fStackX_10;
  float fStackX_14;
  undefined4 uStack_118;
  undefined8 uStack_114;
  longlong *plStack_108;
  float fStack_100;
  undefined auStack_e8 [176];
  
  if ((DAT_181b2b430 != '\0') &&
     (sVar11 = GetAsyncKeyState(1), iVar8 = _DAT_181b2becc, iVar7 = _DAT_181b2bec8,
     fVar6 = _DAT_181b2beb8, fVar5 = _DAT_181b2beb4, pplVar4 = _DAT_181b2be38,
     fVar3 = _DAT_181b2b410, cVar2 = DAT_181b2b407, cVar10 = DAT_181b2b406, fVar1 = _DAT_181a03230,
     sVar11 < 0)) {
    pplVar13 = (longlong **)0x0;
    pplVar12 = (longlong **)*_DAT_181b2be38;
    fVar23 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar22 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    fVar21 = _DAT_181a03460;
    if (pplVar12 != _DAT_181b2be38) {
      do {
        if (((*(char *)((longlong)pplVar12 + 0x1a) == '\0') &&
            ((cVar10 == '\0' || (*(char *)((longlong)pplVar12 + 0x1b) == '\0')))) &&
           ((cVar2 == '\0' || (*(char *)(pplVar12 + 3) == '\0')))) {
          pplVar14 = pplVar12 + 0x14;
          recovered_180067e80(&fStackX_10,&DAT_181b2be70,pplVar14,iVar7,iVar8);
          fVar9 = fStackX_14;
          fVar15 = fStackX_10;
          if ((fVar1 <= fStackX_10) && (fVar1 <= fStackX_14)) {
            plStack_108 = *pplVar14;
            fVar19 = _DAT_181b2beb0 - SUB84(plStack_108,0);
            fVar18 = fVar6 - *(float *)(pplVar14 + 1);
            fVar20 = fVar5 - (float)((ulonglong)plStack_108 >> 0x20);
            fVar18 = fVar20 * fVar20 + fVar19 * fVar19 + fVar18 * fVar18;
            if (fVar18 < 0.0) {
              fVar18 = (float)func_0x0001801cb525(fVar18);
            }
            else {
              fVar18 = SQRT(fVar18);
            }
            if (fVar18 <= (float)_DAT_181b2b40c) {
              dVar16 = (double)func_0x0001801cb507((double)(fVar9 - fVar23));
              dVar17 = (double)func_0x0001801cb507((double)(fVar15 - fVar22));
              dVar16 = dVar16 + dVar17;
              if (dVar16 < 0.0) {
                dVar16 = (double)func_0x0001801cb51f(dVar16);
              }
              else {
                dVar16 = SQRT(dVar16);
              }
              fVar15 = (float)dVar16;
              if ((fVar15 <= fVar3) && (fVar15 < fVar21)) {
                pplVar13 = pplVar12 + 3;
                fVar21 = fVar15;
              }
            }
          }
        }
        pplVar12 = (longlong **)*pplVar12;
      } while (pplVar12 != pplVar4);
      if ((pplVar13 != (longlong **)0x0) && (*(int *)((longlong)pplVar13 + 0x84) != 0)) {
        uStack_118 = 0;
        uStack_114 = 0x3f800000;
        plStack_108 = (longlong *)
                      CONCAT44(((float)((ulonglong)pplVar13[0x11] >> 0x20) + 0.0) - fVar5,
                               (SUB84(pplVar13[0x11],0) + 0.0) - _DAT_181b2beb0);
        fStack_100 = (*(float *)(pplVar13 + 0x12) + 0.0) - fVar6;
        func_0x00018006da10(auStack_e8,&plStack_108,&uStack_118);
        cVar10 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,&fStackX_10);
        if (cVar10 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStackX_14,fStackX_10),auStack_e8,0x10);
        }
        aiStackX_8[0] = recovered_180069360((ulonglong)*(uint *)((longlong)pplVar13 + 0x84) + 0x4e8)
        ;
        if ((aiStackX_8[0] != 0) &&
           (cVar10 = recovered_180067cc0((ulonglong)*(uint *)((longlong)pplVar13 + 0x84) + 0x54,
                                         &fStackX_10), cVar10 != '\0')) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStackX_14,fStackX_10),aiStackX_8,4);
        }
      }
    }
  }
  return;
}

