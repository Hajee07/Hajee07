/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180072bf0(void)

{
  longlong **pplVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  char cVar7;
  short sVar8;
  int iVar9;
  longlong **pplVar10;
  longlong **pplVar11;
  longlong **pplVar12;
  float fVar13;
  double dVar14;
  double dVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fStackX_8;
  float fStackX_c;
  undefined8 uStackX_10;
  undefined4 uStack_108;
  undefined8 uStack_104;
  longlong *plStack_f8;
  float fStack_f0;
  longlong *aplStack_e8 [22];
  
  if ((((DAT_181b2b5b6 != '\0') && (_DAT_181b2bebc != 0)) &&
      (iVar9 = recovered_180069360((ulonglong)_DAT_181b2bebc + 0x48), iVar9 != 0)) &&
     ((iVar9 = recovered_180069360(iVar9 + 8), iVar9 != 0 &&
      (iVar9 = recovered_180069360(iVar9 + 0x20), iVar9 != 0)))) {
    iVar9 = recovered_180077d30(iVar9 + 0x10);
    if (((((ushort)(iVar9 - 4U) < 0x3e) &&
         ((0x3000020000020001U >> ((ulonglong)(iVar9 - 4U) & 0x3f) & 1) != 0)) ||
        (((sVar8 = (short)iVar9, (ushort)(sVar8 - 0x80U) < 2 || (sVar8 == 0x4b)) || (sVar8 == 0xc5))
        )) && (sVar8 = GetAsyncKeyState(1), cVar7 = DAT_181b2f649, iVar5 = _DAT_181b2becc,
              iVar4 = _DAT_181b2bec8, fVar3 = _DAT_181b2beb8, fVar2 = _DAT_181b2beb4,
              pplVar1 = _DAT_181b2be38, fVar19 = _DAT_181b2b5bc, iVar9 = _DAT_181b2b40c,
              fVar17 = _DAT_181a03230, sVar8 < 0)) {
      fVar16 = _DAT_181b2beb0;
      if (DAT_181b2f649 == '\0') {
        pplVar11 = (longlong **)0x0;
        pplVar10 = (longlong **)*_DAT_181b2be38;
        fVar21 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
        fVar22 = (float)_DAT_181b2becc * _DAT_181a031bc;
        fVar20 = _DAT_181a03460;
        if (pplVar10 != _DAT_181b2be38) {
          do {
            if (((*(char *)((longlong)pplVar10 + 0x1a) == '\0') &&
                ((DAT_181b2b406 == '\0' || (*(char *)((longlong)pplVar10 + 0x1b) == '\0')))) &&
               ((DAT_181b2b407 == '\0' || (*(char *)(pplVar10 + 3) == '\0')))) {
              pplVar12 = pplVar10 + 0x14;
              recovered_180067e80(&fStackX_8,&DAT_181b2be70,pplVar12,iVar4,iVar5);
              fVar6 = fStackX_c;
              fVar13 = fStackX_8;
              fVar16 = _DAT_181b2beb0;
              if ((fVar17 <= fStackX_8) && (fVar17 <= fStackX_c)) {
                plStack_f8 = *pplVar12;
                fVar16 = _DAT_181b2beb0 - SUB84(plStack_f8,0);
                fVar18 = fVar2 - (float)((ulonglong)plStack_f8 >> 0x20);
                fVar18 = fVar18 * fVar18 + fVar16 * fVar16 +
                         (fVar3 - *(float *)(pplVar12 + 1)) * (fVar3 - *(float *)(pplVar12 + 1));
                if (fVar18 < 0.0) {
                  fVar18 = (float)func_0x0001801cb525(fVar18);
                }
                else {
                  fVar18 = SQRT(fVar18);
                }
                fVar16 = _DAT_181b2beb0;
                if (fVar18 <= (float)iVar9) {
                  dVar14 = (double)func_0x0001801cb507((double)(fVar6 - fVar22));
                  dVar15 = (double)func_0x0001801cb507((double)(fVar13 - fVar21));
                  dVar14 = dVar14 + dVar15;
                  if (dVar14 < 0.0) {
                    dVar14 = (double)func_0x0001801cb51f(dVar14);
                  }
                  else {
                    dVar14 = SQRT(dVar14);
                  }
                  fVar13 = (float)dVar14;
                  fVar16 = _DAT_181b2beb0;
                  if ((fVar13 <= fVar19) && (fVar13 < fVar20)) {
                    pplVar11 = pplVar10 + 3;
                    fVar20 = fVar13;
                  }
                }
              }
            }
            pplVar10 = (longlong **)*pplVar10;
          } while (pplVar10 != pplVar1);
          if ((pplVar11 != (longlong **)0x0) && (*(int *)((longlong)pplVar11 + 0x84) != 0)) {
            cVar7 = '\x01';
            DAT_181b2f649 = '\x01';
            _DAT_181b302e8 = pplVar11;
          }
        }
      }
      pplVar1 = _DAT_181b302e8;
      if (cVar7 == '\0') {
        return;
      }
      if (_DAT_181b302e8 == (longlong **)0x0) {
        return;
      }
      if (*(int *)((longlong)_DAT_181b302e8 + 0x84) == 0) {
        return;
      }
      if (*(char *)((longlong)_DAT_181b302e8 + 2) == '\0') {
        pplVar11 = _DAT_181b302e8 + 0x11;
        plStack_f8 = *pplVar11;
        fVar17 = fVar16 - SUB84(plStack_f8,0);
        fVar19 = fVar2 - (float)((ulonglong)plStack_f8 >> 0x20);
        fVar17 = fVar19 * fVar19 + fVar17 * fVar17 +
                 (fVar3 - *(float *)(_DAT_181b302e8 + 0x12)) *
                 (fVar3 - *(float *)(_DAT_181b302e8 + 0x12));
        if (fVar17 < 0.0) {
          fVar17 = (float)func_0x0001801cb525(fVar17);
          fVar16 = _DAT_181b2beb0;
        }
        else {
          fVar17 = SQRT(fVar17);
        }
        if (fVar17 <= (float)iVar9) {
          if (_DAT_181b2b5b8 == 1) {
            pplVar11 = pplVar1 + 0x20;
          }
          aplStack_e8[0] = *pplVar11;
          uStack_108 = 0;
          uStack_104 = 0x3f800000;
          plStack_f8 = (longlong *)
                       CONCAT44(((float)((ulonglong)aplStack_e8[0] >> 0x20) + 0.0) - fVar2,
                                (SUB84(aplStack_e8[0],0) + 0.0) - fVar16);
          fStack_f0 = (*(float *)(pplVar11 + 1) + 0.0) - fVar3;
          func_0x00018006da10(aplStack_e8,&plStack_f8,&uStack_108);
          cVar7 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,&uStackX_10);
          if (cVar7 != '\0') {
            (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_10,aplStack_e8,0x10);
          }
          fStackX_8 = (float)recovered_180069360((ulonglong)
                                                 *(uint *)((longlong)_DAT_181b302e8 + 0x84) + 0x4e8)
          ;
          if (fStackX_8 == 0.0) {
            return;
          }
          cVar7 = recovered_180067cc0((ulonglong)*(uint *)((longlong)_DAT_181b302e8 + 0x84) + 0x54,
                                      &uStackX_10);
          if (cVar7 == '\0') {
            return;
          }
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_10,&fStackX_8,4);
          return;
        }
      }
    }
  }
  _DAT_181b302e8 = (longlong **)0x0;
  DAT_181b2f649 = 0;
  return;
}

