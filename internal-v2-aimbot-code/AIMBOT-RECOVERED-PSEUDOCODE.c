/* Recovered C-like pseudocode, not original or standalone compilable C++.
 * 151 linked analysis routines, including shared helpers, UI and configuration.
 * Read README.md and QUALITY.json for coverage and limitations.
 */


/* ===== ANALYSIS FUNCTION 0x180066c80 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180066c80(undefined (*param_1) [16],longlong param_2)

{
  longlong lVar1;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(char *)(param_2 + lVar1) != '\0');
  recovered_180066cc0();
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180066cc0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180066cc0(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (param_3 < 0x8000000000000000) {
    if (param_3 < 0x10) {
      param_1[2] = param_3;
      param_1[3] = 0xf;
      func_0x0001801ca88d();
      *(undefined *)(param_3 + (longlong)param_1) = 0;
    }
    else {
      uVar2 = param_3 | 0xf;
      uVar4 = 0x7fffffffffffffff;
      if ((uVar2 < 0x8000000000000000) && (uVar4 = uVar2, uVar2 < 0x16)) {
        uVar4 = 0x16;
      }
      lVar3 = func_0x000180024110(uVar4 + 1);
      *param_1 = lVar3;
      param_1[2] = param_3;
      param_1[3] = uVar4;
      func_0x0001801ca88d(lVar3,param_2,param_3);
      *(undefined *)(lVar3 + param_3) = 0;
    }
    return;
  }
  func_0x000180052a50();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x180066d80 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180066d80(longlong *param_1)

{
  code *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *param_1;
  if (lVar2 != 0) {
    lVar3 = param_1[1];
    for (; lVar2 != lVar3; lVar2 = lVar2 + 0x38) {
      recovered_180066e40(lVar2 + 0x10);
    }
    lVar2 = *param_1;
    lVar3 = lVar2;
    if ((0xfff < (ulonglong)(((param_1[2] - lVar2) / 0x38) * 0x38)) &&
       (lVar3 = *(longlong *)(lVar2 + -8), 0x1f < (lVar2 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40(lVar3);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180066e40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180066e40(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  if (0xf < (ulonglong)param_1[3]) {
    lVar1 = *param_1;
    lVar3 = lVar1;
    if ((0xfff < param_1[3] + 1U) &&
       (lVar3 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(lVar3);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined *)param_1 = 0;
  return;
}



/* ===== ANALYSIS FUNCTION 0x180066ec0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180066ec0(longlong **param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong **pplVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  plVar3 = param_1[3];
  plVar8 = param_1[2];
  if ((ulonglong)((longlong)plVar3 - (longlong)plVar8) < param_3) {
    if (0x7fffffffffffffffU - (longlong)plVar8 < param_3) {
      func_0x000180052a50();
      pcVar4 = (code *)swi(3);
      pplVar5 = (longlong **)(*pcVar4)();
      return pplVar5;
    }
    plVar6 = (longlong *)((ulonglong)(longlong *)((longlong)plVar8 + param_3) | 0xf);
    plVar7 = (longlong *)0x7fffffffffffffff;
    if (((plVar6 < (longlong *)0x8000000000000000) &&
        (plVar3 <= (longlong *)(0x7fffffffffffffff - ((ulonglong)plVar3 >> 1)))) &&
       (plVar1 = (longlong *)((longlong)plVar3 + ((ulonglong)plVar3 >> 1)), plVar7 = plVar6,
       plVar6 < plVar1)) {
      plVar7 = plVar1;
    }
    plVar6 = (longlong *)func_0x000180024110((longlong)plVar7 + 1);
    param_1[2] = (longlong *)((longlong)plVar8 + param_3);
    param_1[3] = plVar7;
    lVar2 = (longlong)plVar8 + (longlong)plVar6;
    if (plVar3 < (longlong *)0x10) {
      func_0x0001801ca88d(plVar6,param_1,plVar8);
      func_0x0001801ca88d(lVar2,param_2,param_3);
      *(undefined *)(lVar2 + param_3) = 0;
    }
    else {
      plVar7 = *param_1;
      func_0x0001801ca88d(plVar6,plVar7,plVar8);
      func_0x0001801ca88d(lVar2,param_2,param_3);
      *(undefined *)(lVar2 + param_3) = 0;
      plVar8 = plVar7;
      if ((0xfff < (longlong)plVar3 + 1U) &&
         (plVar8 = (longlong *)plVar7[-1],
         0x1f < (ulonglong)((longlong)plVar7 + (-8 - (longlong)plVar8)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar4 = (code *)swi(3);
        pplVar5 = (longlong **)(*pcVar4)();
        return pplVar5;
      }
      func_0x000180127e40(plVar8);
    }
    *param_1 = plVar6;
  }
  else {
    param_1[2] = (longlong *)((longlong)plVar8 + param_3);
    pplVar5 = param_1;
    if ((longlong *)0xf < plVar3) {
      pplVar5 = (longlong **)*param_1;
    }
    func_0x0001801ca893((longlong)plVar8 + (longlong)pplVar5);
    *(undefined *)((longlong)plVar8 + (longlong)pplVar5 + param_3) = 0;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180067040 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16]
recovered_180067040(undefined (*param_1) [16],undefined8 param_2,undefined8 param_3,
                   undefined8 param_4,longlong param_5,undefined8 param_6,longlong param_7)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined (*pauVar3) [16];
  ulonglong uVar4;
  
  *param_1 = ZEXT816(0);
  uVar4 = 0xf;
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  uVar1 = param_5 + param_7;
  pauVar3 = param_1;
  if (0xf < uVar1) {
    uVar2 = uVar1 | 0xf;
    uVar4 = 0x7fffffffffffffff;
    if ((uVar2 < 0x8000000000000000) && (uVar4 = uVar2, uVar2 < 0x16)) {
      uVar4 = 0x16;
    }
    pauVar3 = (undefined (*) [16])func_0x000180024110(uVar4 + 1);
    *(undefined (**) [16])*param_1 = pauVar3;
  }
  *(ulonglong *)param_1[1] = uVar1;
  *(ulonglong *)(param_1[1] + 8) = uVar4;
  func_0x0001801ca88d(pauVar3,param_4,param_5);
  func_0x0001801ca88d(*pauVar3 + param_5,param_6,param_7);
  (*pauVar3)[uVar1] = 0;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x1800676d0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_1800676d0(longlong **param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  plVar1 = param_1[3];
  if (plVar1 < param_3) {
    if ((longlong *)0x7fffffffffffffff < param_3) {
      func_0x000180052a50();
      pcVar2 = (code *)swi(3);
      pplVar3 = (longlong **)(*pcVar2)();
      return pplVar3;
    }
    plVar4 = (longlong *)((ulonglong)param_3 | 0xf);
    plVar6 = (longlong *)0x7fffffffffffffff;
    if (((plVar4 < (longlong *)0x8000000000000000) &&
        (plVar1 <= (longlong *)(0x7fffffffffffffff - ((ulonglong)plVar1 >> 1)))) &&
       (plVar5 = (longlong *)((longlong)plVar1 + ((ulonglong)plVar1 >> 1)), plVar6 = plVar4,
       plVar4 < plVar5)) {
      plVar6 = plVar5;
    }
    plVar4 = (longlong *)func_0x000180024110((longlong)plVar6 + 1);
    param_1[2] = param_3;
    param_1[3] = plVar6;
    func_0x0001801ca88d(plVar4,param_2,param_3);
    *(undefined *)((longlong)plVar4 + (longlong)param_3) = 0;
    if ((longlong *)0xf < plVar1) {
      plVar6 = *param_1;
      plVar5 = plVar6;
      if ((0xfff < (longlong)plVar1 + 1U) &&
         (plVar5 = (longlong *)plVar6[-1],
         0x1f < (ulonglong)((longlong)plVar6 + (-8 - (longlong)plVar5)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        pplVar3 = (longlong **)(*pcVar2)();
        return pplVar3;
      }
      func_0x000180127e40(plVar5);
    }
    *param_1 = plVar4;
  }
  else {
    pplVar3 = param_1;
    if ((longlong *)0xf < plVar1) {
      pplVar3 = (longlong **)*param_1;
    }
    param_1[2] = param_3;
    func_0x0001801ca893(pplVar3);
    *(undefined *)((longlong)pplVar3 + (longlong)param_3) = 0;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180067850 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180067850(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  uVar3 = (ulonglong)((longlong)param_2 + (7 - (longlong)param_1)) >> 3;
  if (param_2 < param_1) {
    uVar3 = 0;
  }
  if ((uVar3 != 0) && (1 < uVar3)) {
    uVar1 = *param_3;
    if ((param_3 < param_1) || (param_1 + (uVar3 - 1) < param_3)) {
      puVar4 = param_1;
      for (uVar2 = uVar3 & 0x1ffffffffffffffe; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      param_1 = param_1 + (uVar3 & 0xfffffffffffffffe);
    }
  }
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_1 = *param_3;
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800678e0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong *
recovered_1800678e0(longlong *param_1,ulonglong param_2,undefined8 param_3,longlong param_4,
                   undefined8 param_5,longlong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  
  lVar10 = param_1[2];
  if (0x7fffffffffffffffU - lVar10 < param_2) {
    func_0x000180052a50();
    pcVar5 = (code *)swi(3);
    plVar7 = (longlong *)(*pcVar5)();
    return plVar7;
  }
  uVar3 = param_1[3];
  uVar8 = lVar10 + param_2 | 0xf;
  uVar9 = 0x7fffffffffffffff;
  if (((uVar8 < 0x8000000000000000) && (uVar3 <= 0x7fffffffffffffff - (uVar3 >> 1))) &&
     (uVar1 = uVar3 + (uVar3 >> 1), uVar9 = uVar8, uVar8 < uVar1)) {
    uVar9 = uVar1;
  }
  lVar6 = func_0x000180024110(uVar9 + 1);
  param_1[3] = uVar9;
  param_1[2] = lVar10 + param_2;
  lVar2 = lVar6 + param_4;
  if (uVar3 < 0x10) {
    func_0x0001801ca88d(lVar6,param_1,param_4);
    func_0x0001801ca88d(lVar2,param_5,param_6);
    func_0x0001801ca88d(param_6 + lVar2,param_4 + (longlong)param_1,(lVar10 - param_4) + 1);
  }
  else {
    lVar4 = *param_1;
    func_0x0001801ca88d(lVar6,lVar4,param_4);
    func_0x0001801ca88d(lVar2,param_5,param_6);
    func_0x0001801ca88d(param_6 + lVar2,lVar4 + param_4,(lVar10 - param_4) + 1);
    lVar10 = lVar4;
    if ((0xfff < uVar3 + 1) && (lVar10 = *(longlong *)(lVar4 + -8), 0x1f < (lVar4 - lVar10) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar5 = (code *)swi(3);
      plVar7 = (longlong *)(*pcVar5)();
      return plVar7;
    }
    func_0x000180127e40(lVar10);
  }
  *param_1 = lVar6;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180067b60 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180067b60(void)

{
  code *pcVar1;
  
  __Xout_of_range_std__YAXPEBD_Z(&UNK_1819d7190);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x180067b80 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong * recovered_180067b80(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = _Query_perf_frequency();
  lVar2 = _Query_perf_counter();
  if (lVar1 == 10000000) {
    *param_1 = lVar2 * 100;
    return param_1;
  }
  if (lVar1 == 24000000) {
    lVar1 = lVar2 + SUB168(SEXT816(-0x4d0b03f86b6f730d) * SEXT816(lVar2),8);
    lVar3 = (lVar1 >> 0x18) - (lVar1 >> 0x3f);
    lVar1 = (lVar2 + lVar3 * -24000000) * 1000000000;
    lVar1 = SUB168(SEXT816(-0x4d0b03f86b6f730d) * SEXT816(lVar1),8) + lVar1;
    *param_1 = ((lVar1 >> 0x18) - (lVar1 >> 0x3f)) + lVar3 * 1000000000;
    return param_1;
  }
  *param_1 = ((lVar2 % lVar1) * 1000000000) / lVar1 + (lVar2 / lVar1) * 1000000000;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180067cc0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180067cc0(ulonglong param_1,longlong *param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  longlong lStackX_10;
  
  uVar6 = 0;
  *param_2 = 0;
  if (0x1000 < param_1) {
    plVar4 = (longlong *)
             ((((param_1 >> 0x30 & 0xff ^
                ((((((param_1 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^ param_1 >> 8 & 0xff) *
                    0x100000001b3 ^ param_1 >> 0x10 & 0xff) * 0x100000001b3 ^ param_1 >> 0x18 & 0xff
                  ) * 0x100000001b3 ^ param_1 >> 0x20 & 0xff) * 0x100000001b3 ^
                param_1 >> 0x28 & 0xff) * 0x100000001b3) * 0x100000001b3 ^ param_1 >> 0x38) *
               0x100000001b3 & _DAT_181b2bf50) * 0x10 + _DAT_181b2bf38);
    lVar3 = plVar4[1];
    if (lVar3 == _DAT_181b2bf28) {
LAB_180067dc1:
      lVar3 = 0;
    }
    else {
      uVar1 = *(ulonglong *)(lVar3 + 0x10);
      while (param_1 != uVar1) {
        if (lVar3 == *plVar4) goto LAB_180067dc1;
        lVar3 = *(longlong *)(lVar3 + 8);
        uVar1 = *(ulonglong *)(lVar3 + 0x10);
      }
    }
    lVar5 = _DAT_181b2bf28;
    if (lVar3 != 0) {
      lVar5 = lVar3;
    }
    if ((lVar5 != _DAT_181b2bf28) && (*(longlong *)(lVar5 + 0x18) != 0)) {
      *param_2 = *(longlong *)(lVar5 + 0x18);
      return 1;
    }
    do {
      lVar3 = (*_DAT_181b4efa0)(_DAT_181b4ef90,uVar6);
      if (lVar3 != 0) {
        lStackX_10 = 0;
        iVar2 = (*_DAT_181b4ef78)(lVar3,param_1,&lStackX_10);
        lVar3 = lStackX_10;
        if (iVar2 == 0) {
          *param_2 = lStackX_10;
          plVar4 = (longlong *)recovered_18006a2a0();
          *(longlong *)(*plVar4 + 0x18) = lVar3;
          return 1;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
  }
  return 0;
}



/* ===== ANALYSIS FUNCTION 0x180067e80 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * recovered_180067e80(float *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  *param_1 = -1.0;
  param_1[1] = -1.0;
  if ((0 < param_4) && (0 < param_5)) {
    fVar1 = *param_3;
    fVar2 = param_3[1];
    fVar3 = param_3[2];
    fVar9 = fVar2 * param_2[7] + fVar1 * param_2[3] + fVar3 * param_2[0xb] + param_2[0xf];
    if (_DAT_181a03124 <= fVar9) {
      fVar4 = param_2[1];
      fVar5 = param_2[5];
      fVar6 = param_2[9];
      fVar8 = (float)param_5 * _DAT_181a031bc;
      fVar7 = param_2[0xd];
      *param_1 = ((fVar2 * param_2[4] + fVar1 * *param_2 + fVar3 * param_2[8] + param_2[0xc]) *
                 (float)param_4 * _DAT_181a031bc) / fVar9 + (float)param_4 * _DAT_181a031bc;
      param_1[1] = fVar8 - ((fVar1 * fVar4 + fVar2 * fVar5 + fVar3 * fVar6 + fVar7) * fVar8) / fVar9
      ;
    }
    return param_1;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180069360 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 recovered_180069360(undefined8 param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 auStackX_10 [2];
  undefined8 auStackX_18 [2];
  
  auStackX_10[0] = 0;
  cVar1 = recovered_180067cc0(param_1,auStackX_18);
  if (cVar1 != '\0') {
    (*_DAT_181b4ef88)(_DAT_181b4ef90,auStackX_18[0],auStackX_10,4);
    return auStackX_10[0];
  }
  if (_DAT_181b4ef90 == 0) {
    uVar2 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819d77a0);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar2,&DAT_180069ca0);
  }
  return auStackX_10[0];
}



/* ===== ANALYSIS FUNCTION 0x1800693e0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800693e0(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lStackX_8;
  
  recovered_180067b80(&lStackX_8);
  lVar1 = *param_1;
  lVar3 = lStackX_8;
  if (0 < lVar1) {
    lVar3 = 0x7fffffffffffffff;
    if (lStackX_8 < lVar1 * -1000000 + 0x7fffffffffffffff) {
      lVar3 = lStackX_8 + lVar1 * 1000000;
    }
  }
  recovered_180067b80(&lStackX_8);
  while (lStackX_8 < lVar3) {
    lVar1 = lVar3 - lStackX_8;
    if (lVar1 < 0x4e94914f0001) {
      uVar2 = lVar1 / 1000000;
      if ((longlong)(uVar2 * 1000000) < lVar1) {
        uVar2 = (ulonglong)((int)uVar2 + 1);
      }
    }
    else {
      uVar2 = 86400000;
    }
    func_0x000180126aac(uVar2 & 0xffffffff);
    recovered_180067b80(&lStackX_8);
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800694f0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800694f0(longlong *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  
  puVar6 = (undefined8 *)param_1[1];
  if (puVar6 != (undefined8 *)param_1[2]) {
    *puVar6 = *param_2;
    param_1[1] = param_1[1] + 8;
    return;
  }
  lVar8 = (longlong)puVar6 - *param_1 >> 3;
  if (lVar8 == 0x1fffffffffffffff) {
    recovered_18006aad0();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  uVar5 = (longlong)(undefined8 *)param_1[2] - *param_1 >> 3;
  uVar1 = lVar8 + 1;
  if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {
    uVar7 = 0x1fffffffffffffff;
  }
  else {
    uVar5 = (uVar5 >> 1) + uVar5;
    uVar7 = uVar1;
    if (uVar1 <= uVar5) {
      uVar7 = uVar5;
    }
    if (0x1fffffffffffffff < uVar7) {
      func_0x000180003980();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
  }
  lVar4 = func_0x000180024110(uVar7 * 8);
  *(undefined8 *)(lVar4 + lVar8 * 8) = *param_2;
  puVar2 = (undefined8 *)*param_1;
  if (puVar6 == (undefined8 *)param_1[1]) {
    lVar9 = (longlong)(undefined8 *)param_1[1] - (longlong)puVar2;
    lVar8 = lVar4;
    puVar6 = puVar2;
  }
  else {
    func_0x0001801ca893(lVar4,puVar2,(longlong)puVar6 - (longlong)puVar2);
    lVar9 = param_1[1] - (longlong)puVar6;
    lVar8 = lVar4 + (lVar8 + 1) * 8;
  }
  func_0x0001801ca893(lVar8,puVar6,lVar9);
  lVar8 = *param_1;
  if (lVar8 != 0) {
    lVar9 = lVar8;
    if ((0xfff < (param_1[2] - lVar8 & 0xfffffffffffffff8U)) &&
       (lVar9 = *(longlong *)(lVar8 + -8), 0x1f < (lVar8 - lVar9) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    func_0x000180127e40(lVar9);
  }
  *param_1 = lVar4;
  param_1[1] = lVar4 + uVar1 * 8;
  param_1[2] = lVar4 + uVar7 * 8;
  return;
}



/* ===== ANALYSIS FUNCTION 0x180069a10 ===== */

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



/* ===== ANALYSIS FUNCTION 0x180069ac0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong *
recovered_180069ac0(longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  
  uVar5 = 0;
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(char *)(param_2 + lVar7) != '\0');
  lVar6 = *(longlong *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1);
  if ((lVar6 < 1) || (lVar6 <= lVar7)) {
    lVar6 = 0;
  }
  else {
    lVar6 = lVar6 - lVar7;
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  plVar8 = param_1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  cVar2 = _good_ios_base_std__QEBA_NXZ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
  if (cVar2 == '\0') {
    cVar2 = '\0';
  }
  else {
    plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x50 + (longlong)param_1);
    if ((plVar1 == (longlong *)0x0) || (plVar1 == param_1)) {
      cVar2 = '\x01';
    }
    else {
      _flush___basic_ostream_DU__char_traits_D_std___std__QEAAAEAV12_XZ();
      cVar2 = _good_ios_base_std__QEBA_NXZ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
    }
  }
  if (cVar2 == '\0') {
    uVar5 = 4;
  }
  else {
    lVar4 = *param_1;
    if ((*(uint *)((longlong)*(int *)(lVar4 + 4) + 0x18 + (longlong)param_1) & 0x1c0) != 0x40) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) goto LAB_180069c16;
      }
      lVar4 = *param_1;
    }
    lVar4 = _sputn___basic_streambuf_DU__char_traits_D_std___std__QEAA_JPEBD_J_Z
                      (*(undefined8 *)((longlong)*(int *)(lVar4 + 4) + 0x48 + (longlong)param_1),
                       param_2,lVar7,param_4,plVar8,cVar2);
    if (lVar4 == lVar7) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) goto LAB_180069c16;
      }
    }
    else {
LAB_180069c16:
      uVar5 = 4;
    }
    *(undefined8 *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1) = 0;
  }
  _setstate___basic_ios_DU__char_traits_D_std___std__QEAAXH_N_Z
            ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1,uVar5,0);
  cVar2 = _uncaught_exception_std__YA_NXZ();
  if (cVar2 == '\0') {
    __Osfx___basic_ostream_DU__char_traits_D_std___std__QEAAXXZ(param_1);
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18006a2a0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
recovered_18006a2a0(undefined8 param_1,undefined8 *param_2,longlong *param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  float fVar11;
  float fVar12;
  
  uVar8 = (((((((((ulonglong)*(byte *)param_3 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                (ulonglong)*(byte *)((longlong)param_3 + 1)) * 0x100000001b3 ^
               (ulonglong)*(byte *)((longlong)param_3 + 2)) * 0x100000001b3 ^
              (ulonglong)*(byte *)((longlong)param_3 + 3)) * 0x100000001b3 ^
             (ulonglong)*(byte *)((longlong)param_3 + 4)) * 0x100000001b3 ^
            (ulonglong)*(byte *)((longlong)param_3 + 5)) * 0x100000001b3 ^
           (ulonglong)*(byte *)((longlong)param_3 + 6)) * 0x100000001b3 ^
          (ulonglong)*(byte *)((longlong)param_3 + 7)) * 0x100000001b3;
  uVar6 = uVar8 & _DAT_181b2bf50;
  puVar7 = (undefined8 *)(uVar6 * 2);
  puVar4 = *(undefined8 **)(_DAT_181b2bf38 + 8 + uVar6 * 0x10);
  puVar9 = _DAT_181b2bf28;
  if (puVar4 != _DAT_181b2bf28) {
    puVar7 = *(undefined8 **)(_DAT_181b2bf38 + uVar6 * 0x10);
    lVar5 = puVar4[2];
    puVar9 = puVar4;
    while( true ) {
      if (*param_3 == lVar5) {
        *param_2 = puVar9;
        *(undefined *)(param_2 + 1) = 0;
        return param_2;
      }
      if (puVar9 == puVar7) break;
      puVar9 = (undefined8 *)puVar9[1];
      lVar5 = puVar9[2];
    }
  }
  if (_DAT_181b2bf30 == 0x7ffffffffffffff) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar2 = (code *)swi(3);
    puVar4 = (undefined8 *)(*pcVar2)();
    return puVar4;
  }
  puVar4 = (undefined8 *)func_0x000180127a94(0x20,puVar7,param_3,param_4,&DAT_181b2bf28,0);
  puVar4[2] = *param_3;
  puVar4[3] = 0;
  uVar3 = _DAT_181b2bf58;
  uVar6 = _DAT_181b2bf30 + 1;
  if ((longlong)uVar6 < 0) {
    fVar11 = (float)(uVar6 >> 1 | (ulonglong)((uint)uVar6 & 1));
    fVar11 = fVar11 + fVar11;
  }
  else {
    fVar11 = (float)uVar6;
  }
  if ((longlong)_DAT_181b2bf58 < 0) {
    fVar12 = (float)(_DAT_181b2bf58 >> 1 | (ulonglong)((uint)_DAT_181b2bf58 & 1));
    fVar12 = fVar12 + fVar12;
  }
  else {
    fVar12 = (float)_DAT_181b2bf58;
  }
  if (_DAT_181b2bf20 < fVar11 / fVar12) {
    fVar11 = (float)func_0x0001801cb4e3(fVar11 / _DAT_181b2bf20);
    lVar5 = 0;
    if ((_DAT_181a03458 <= fVar11) && (fVar11 = fVar11 - _DAT_181a03458, fVar11 < _DAT_181a03458)) {
      lVar5 = -0x8000000000000000;
    }
    uVar6 = 8;
    if (8 < (ulonglong)((longlong)fVar11 + lVar5)) {
      uVar6 = (longlong)fVar11 + lVar5;
    }
    uVar10 = uVar3;
    if ((uVar3 < uVar6) && ((0x1ff < uVar3 || (uVar10 = uVar3 * 8, uVar3 * 8 < uVar6)))) {
      uVar10 = uVar6;
    }
    func_0x00018006af60(uVar6,uVar10);
    puVar7 = *(undefined8 **)(_DAT_181b2bf38 + 8 + (_DAT_181b2bf50 & uVar8) * 0x10);
    puVar9 = _DAT_181b2bf28;
    if (puVar7 != _DAT_181b2bf28) {
      lVar5 = puVar7[2];
      puVar9 = puVar7;
      while (puVar4[2] != lVar5) {
        if (puVar9 == *(undefined8 **)(_DAT_181b2bf38 + (_DAT_181b2bf50 & uVar8) * 0x10))
        goto LAB_18006a520;
        puVar9 = (undefined8 *)puVar9[1];
        lVar5 = puVar9[2];
      }
      puVar9 = (undefined8 *)*puVar9;
    }
  }
LAB_18006a520:
  puVar7 = (undefined8 *)puVar9[1];
  _DAT_181b2bf30 = _DAT_181b2bf30 + 1;
  *puVar4 = puVar9;
  puVar4[1] = puVar7;
  *puVar7 = puVar4;
  puVar9[1] = puVar4;
  lVar5 = _DAT_181b2bf38;
  uVar8 = _DAT_181b2bf50 & uVar8;
  puVar1 = *(undefined8 **)(_DAT_181b2bf38 + uVar8 * 0x10);
  if (puVar1 == _DAT_181b2bf28) {
    *(undefined8 **)(_DAT_181b2bf38 + uVar8 * 0x10) = puVar4;
  }
  else {
    if (puVar1 == puVar9) {
      *(undefined8 **)(_DAT_181b2bf38 + uVar8 * 0x10) = puVar4;
      goto LAB_18006a57f;
    }
    if (*(undefined8 **)(_DAT_181b2bf38 + 8 + uVar8 * 0x10) != puVar7) goto LAB_18006a57f;
  }
  *(undefined8 **)(lVar5 + 8 + uVar8 * 0x10) = puVar4;
LAB_18006a57f:
  *param_2 = puVar4;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x18006aad0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18006aad0(void)

{
  code *pcVar1;
  
  __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77f8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x18006b2f0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


int recovered_18006b2f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 uStackX_20;
  
  uStackX_20 = param_4;
  puVar2 = (ulonglong *)func_0x000180002450();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 2,param_1,param_2,param_3,0,&uStackX_20);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}



/* ===== ANALYSIS FUNCTION 0x18006b9b0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_18006b9b0(undefined (*param_1) [16],longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined (*pauVar7) [16];
  uint auStackX_10 [2];
  ulonglong uStackX_18;
  ulonglong *puStackX_20;
  ulonglong uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined auStack_48 [32];
  
  auStackX_10[0] = 0;
  uStackX_18 = param_3;
  cVar3 = recovered_180067cc0(param_2 + 0x31c,&uStackX_18);
  if (((cVar3 == '\0') ||
      (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_18,auStackX_10,4), iVar4 != 0)) ||
     (uStack_70 = (ulonglong)auStackX_10[0], auStackX_10[0] == 0)) {
LAB_18006bd18:
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    (*param_1)[0] = 0;
    return param_1;
  }
  uStackX_18 = uStackX_18 & 0xffffffff00000000;
  cVar3 = recovered_180067cc0((ulonglong)auStackX_10[0] + 8,&puStackX_20);
  if (((cVar3 == '\0') ||
      (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,puStackX_20,&uStackX_18,4), iVar4 != 0)) ||
     (0x3f < (int)uStackX_18 - 1U)) goto LAB_18006bd18;
  puStackX_20 = &uStack_70;
  func_0x00018006b850(&puStackX_20,&uStack_68,(int)uStackX_18 * 5);
  if (uStack_58 == 0) {
LAB_18006bb20:
    puVar6 = (undefined4 *)func_0x00018006b850(&puStackX_20,auStack_48,(int)uStackX_18 * 2 + 2);
    if (&uStack_68 != puVar6) {
      if (0xf < uStack_50) {
        if ((0xfff < uStack_50 + 1) &&
           (0x1f < (CONCAT44(uStack_64,uStack_68) -
                   *(longlong *)(CONCAT44(uStack_64,uStack_68) + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar2)();
          return pauVar7;
        }
        func_0x000180127e40();
      }
      uStack_68 = *puVar6;
      uStack_64 = puVar6[1];
      uStack_60 = puVar6[2];
      uStack_5c = puVar6[3];
      uStack_58 = *(ulonglong *)(puVar6 + 4);
      uStack_50 = *(ulonglong *)(puVar6 + 6);
      *(undefined8 *)(puVar6 + 4) = 0;
      *(undefined8 *)(puVar6 + 6) = 0xf;
      *(undefined *)puVar6 = 0;
    }
    recovered_180066e40(auStack_48);
LAB_18006bbcd:
    if (uStack_58 != 0) {
      puVar6 = &uStack_68;
      if (0xf < uStack_50) {
        puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
      }
      if (((uStack_58 == 0) ||
          (lVar1 = uStack_58 + (longlong)puVar6, lVar5 = func_0x000180127880(puVar6,lVar1,0xef),
          lVar5 == lVar1)) || (lVar5 - (longlong)puVar6 == -1)) goto LAB_18006bd07;
      puVar6 = &uStack_68;
      if (0xf < uStack_50) {
        puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
      }
      if (((uStack_58 < 3) ||
          (lVar1 = (longlong)puVar6 + uStack_58,
          lVar5 = func_0x0001801278a0(puVar6,lVar1,&UNK_1819d7824,3), lVar5 == lVar1)) ||
         (lVar5 - (longlong)puVar6 == -1)) goto LAB_18006bd07;
    }
  }
  else {
    puVar6 = &uStack_68;
    if (0xf < uStack_50) {
      puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
    }
    if (uStack_58 != 0) {
      lVar1 = uStack_58 + (longlong)puVar6;
      lVar5 = func_0x000180127880(puVar6,lVar1,0xef);
      if ((lVar5 != lVar1) && (lVar5 - (longlong)puVar6 != -1)) {
        puVar6 = &uStack_68;
        if (0xf < uStack_50) {
          puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
        }
        if (((2 < uStack_58) &&
            (lVar1 = uStack_58 + (longlong)puVar6,
            lVar5 = func_0x0001801278a0(puVar6,lVar1,&UNK_1819d7824,3), lVar5 != lVar1)) &&
           (lVar5 - (longlong)puVar6 != -1)) goto LAB_18006bb20;
      }
      goto LAB_18006bbcd;
    }
  }
  puVar6 = (undefined4 *)func_0x00018006b850(&puStackX_20,auStack_48,(int)uStackX_18 * 2);
  if (&uStack_68 != puVar6) {
    if (0xf < uStack_50) {
      if ((0xfff < uStack_50 + 1) &&
         (0x1f < (CONCAT44(uStack_64,uStack_68) - *(longlong *)(CONCAT44(uStack_64,uStack_68) + -8))
                 - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        pauVar7 = (undefined (*) [16])(*pcVar2)();
        return pauVar7;
      }
      func_0x000180127e40();
    }
    uStack_68 = *puVar6;
    uStack_64 = puVar6[1];
    uStack_60 = puVar6[2];
    uStack_5c = puVar6[3];
    uStack_58 = *(ulonglong *)(puVar6 + 4);
    uStack_50 = *(ulonglong *)(puVar6 + 6);
    *(undefined8 *)(puVar6 + 4) = 0;
    *(undefined8 *)(puVar6 + 6) = 0xf;
    *(undefined *)puVar6 = 0;
  }
  recovered_180066e40(auStack_48);
LAB_18006bd07:
  *(undefined4 *)*param_1 = uStack_68;
  *(undefined4 *)(*param_1 + 4) = uStack_64;
  *(undefined4 *)(*param_1 + 8) = uStack_60;
  *(undefined4 *)(*param_1 + 0xc) = uStack_5c;
  *(undefined4 *)param_1[1] = (undefined4)uStack_58;
  *(undefined4 *)(param_1[1] + 4) = uStack_58._4_4_;
  *(undefined4 *)(param_1[1] + 8) = (undefined4)uStack_50;
  *(undefined4 *)(param_1[1] + 0xc) = uStack_50._4_4_;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18006bd40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_18006bd40(int param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int aiStackX_8 [2];
  int aiStackX_10 [2];
  int aiStackX_18 [2];
  int aiStackX_20 [2];
  undefined8 uStack_128;
  undefined8 uStack_120;
  float fStack_118;
  int iStack_110;
  int iStack_10c;
  undefined auStack_108 [8];
  float fStack_100;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined auStack_e8 [16];
  undefined8 uStack_d8;
  undefined8 auStack_d0 [23];
  
  iVar2 = 0;
  if (param_2 != auStack_d0) {
    *param_2 = 0;
    *(undefined4 *)(param_2 + 1) = 0;
  }
  uVar1 = recovered_180067cc0(param_1 + 8,&uStack_128);
  if (((((((char)uVar1 != '\0') &&
         (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_10,4), (int)uVar1 == 0)) &&
        (uVar1 = recovered_180067cc0(aiStackX_10[0] + 0x24,&uStack_128), (char)uVar1 != '\0')) &&
       ((uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_20,4), (int)uVar1 == 0 &&
        (uVar1 = recovered_180067cc0(aiStackX_10[0] + 0x20,&uStack_128), (char)uVar1 != '\0')))) &&
      ((uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_18,4), (int)uVar1 == 0 &&
       ((uVar1 = recovered_180067cc0(aiStackX_18[0] + 0x18,&uStack_128), (char)uVar1 != '\0' &&
        (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,&iStack_110,4), (int)uVar1 == 0))))))
     && ((uVar1 = recovered_180067cc0(aiStackX_18[0] + 0x1c,&uStack_128), (char)uVar1 != '\0' &&
         (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,&iStack_10c,4), (int)uVar1 == 0)))) {
    uStack_120 = 0;
    fStack_118 = 0.0;
    uVar1 = recovered_180067cc0(aiStackX_20[0] * 0x30 + iStack_110,&uStack_128);
    if (((((char)uVar1 != '\0') &&
         (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,&uStack_120,0xc), (int)uVar1 == 0)) &&
        (uVar1 = recovered_180067cc0(iStack_10c + aiStackX_20[0] * 4,&uStack_128),
        (char)uVar1 != '\0')) &&
       (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_8,4), (int)uVar1 == 0)) {
      while( true ) {
        if ((aiStackX_8[0] < 0) || (iVar2 = iVar2 + 1, iVar2 == 0x32)) {
          if (param_2 != &uStack_120) {
            uStack_120._4_4_ = (float)((ulonglong)uStack_120 >> 0x20);
            *(float *)param_2 = (float)uStack_120;
            *(float *)(param_2 + 1) = fStack_118;
            *(float *)((longlong)param_2 + 4) = uStack_120._4_4_;
          }
          return CONCAT71((int7)((ulonglong)&uStack_120 >> 8),iVar2 != 0x32);
        }
        _auStack_108 = ZEXT816(0);
        auStack_e8 = ZEXT816(0);
        fStack_f8 = _DAT_181a03830;
        fStack_f4 = _UNK_181a03834;
        fStack_f0 = _UNK_181a03838;
        fStack_ec = _UNK_181a0383c;
        uVar1 = recovered_180067cc0(aiStackX_8[0] * 0x30 + iStack_110,&uStack_128);
        if (((char)uVar1 == '\0') ||
           (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,auStack_108,0x30), (int)uVar1 != 0))
        break;
        fVar11 = (float)auStack_e8._0_4_ * (float)uStack_120;
        fStack_118 = (float)auStack_e8._8_4_ * fStack_118;
        fVar12 = uStack_120._4_4_ * (float)auStack_e8._0_4_;
        fVar5 = fStack_f0 * fStack_f0;
        fVar6 = fStack_f4 * fStack_f8;
        fVar9 = fStack_ec * fStack_f4 * _DAT_181a03498;
        fVar4 = fStack_ec * fStack_f0 * _DAT_181a03498;
        fVar7 = fStack_f0 * fStack_f8;
        fVar10 = fStack_f0 * fStack_f4;
        fVar13 = fStack_f4 * fStack_f4;
        fVar3 = fStack_f8 * fStack_f8;
        fVar8 = fStack_ec * fStack_f8 * _DAT_181a03498;
        uStack_120 = CONCAT44(((fVar6 + fVar6) - fVar4) * fVar11 + fVar12 + (float)auStack_108._4_4_
                              + (fVar5 * _DAT_181a03498 - (fVar3 + fVar3)) * fVar12 +
                              (fVar8 - fVar10 * _DAT_181a03498) * fStack_118,
                              (fVar13 * _DAT_181a03498 - (fVar5 + fVar5)) * fVar11 +
                              fVar11 + (float)auStack_108._0_4_ +
                              (fVar4 - fVar6 * _DAT_181a03498) * fVar12 +
                              ((fVar7 + fVar7) - fVar9) * fStack_118);
        fStack_118 = (fVar9 - fVar7 * _DAT_181a03498) * fVar11 + fStack_118 + fStack_100 +
                     ((fVar10 + fVar10) - fVar8) * fVar12 +
                     (fVar3 * _DAT_181a03498 - (fVar13 + fVar13)) * fStack_118;
        uVar1 = recovered_180067cc0(iStack_10c + aiStackX_8[0] * 4,&uStack_d8);
        if (((char)uVar1 == '\0') ||
           (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_d8,aiStackX_8,4), (int)uVar1 != 0))
        break;
      }
    }
  }
  return uVar1 & 0xffffffffffffff00;
}



/* ===== ANALYSIS FUNCTION 0x18006c300 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x00018006d893) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006c300(uint param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined auVar3 [12];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  undefined auVar8 [16];
  undefined auVar9 [16];
  undefined auVar10 [16];
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined (*pauVar13) [16];
  undefined (*pauVar14) [16];
  undefined8 *******pppppppuVar15;
  uint uVar16;
  longlong lVar17;
  ulonglong uVar18;
  char *pcVar19;
  char *pcVar20;
  longlong lVar21;
  undefined *puVar22;
  undefined8 *******pppppppuVar23;
  undefined auStackX_18 [16];
  undefined auStack_1d8 [16];
  undefined auStack_1c8 [16];
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined auStack_198 [6];
  undefined auStack_192 [3];
  undefined auStack_18f [2];
  undefined5 uStack_18d;
  undefined8 uStack_188;
  ulonglong uStack_180;
  undefined8 *******apppppppuStack_178 [2];
  longlong lStack_168;
  ulonglong uStack_160;
  undefined8 *******apppppppuStack_158 [2];
  longlong lStack_148;
  ulonglong uStack_140;
  undefined8 *******apppppppuStack_138 [2];
  longlong lStack_128;
  ulonglong uStack_120;
  undefined (*pauStack_118) [16];
  longlong lStack_108;
  ulonglong uStack_100;
  undefined8 *******apppppppuStack_f8 [2];
  longlong lStack_e8;
  ulonglong uStack_e0;
  undefined8 *******apppppppuStack_d8 [2];
  longlong lStack_c8;
  ulonglong uStack_c0;
  undefined8 *******apppppppuStack_b8 [2];
  longlong lStack_a8;
  ulonglong uStack_a0;
  undefined8 *******apppppppuStack_98 [2];
  longlong lStack_88;
  ulonglong uStack_80;
  undefined auStack_78 [32];
  undefined auStack_58 [32];
  
  pauVar14 = (undefined (*) [16])&pauStack_118;
  param_3[2] = 0;
  puVar11 = param_3;
  if (0xf < (ulonglong)param_3[3]) {
    puVar11 = (undefined8 *)*param_3;
  }
  *(undefined *)puVar11 = 0;
  uStack_180 = 0xf;
  _auStack_192 = SUB1610(ZEXT816(0),6);
  auVar3._2_10_ = _auStack_192;
  auVar3._0_2_ = _DAT_18020e774;
  auStack_198 = (undefined  [6])(auVar3._0_6_ << 0x20);
  _auStack_198 = CONCAT16(DAT_18020e776,auStack_198);
  if ((int)param_1 < 0x514) {
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d782c,_DAT_1819d7828);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    recovered_180078780(apppppppuStack_178,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_160 - lStack_168 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_178,3,lStack_168,0,&UNK_1819d7834,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_178;
      if (0xf < uStack_160) {
        pppppppuVar15 = apppppppuStack_178[0];
      }
      if ((&UNK_1819d7836 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_168) < &UNK_1819d7834)) {
        puVar22 = (undefined *)0x3;
      }
      else if (&UNK_1819d7834 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7834);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_168 + 1;
      lStack_168 = lStack_168 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7834,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7837 + (longlong)puVar22,3 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_178;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    recovered_180066e40(&uStack_1b8);
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar4[15] = 0;
    auVar4._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar4 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_178;
  }
  else if ((int)param_1 < 0x640) {
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d783c,_DAT_1819d7838);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    recovered_180078780(apppppppuStack_158,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_140 - lStack_148 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_158,3,lStack_148,0,&UNK_1819d7840,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_158;
      if (0xf < uStack_140) {
        pppppppuVar15 = apppppppuStack_158[0];
      }
      if ((&UNK_1819d7842 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_148) < &UNK_1819d7840)) {
        pppppppuVar23 = (undefined8 *******)0x3;
      }
      else if (&UNK_1819d7840 < pppppppuVar15) {
        pppppppuVar23 = pppppppuVar15 + -0x3033af08;
      }
      else {
        pppppppuVar23 = (undefined8 *******)0x0;
      }
      lVar17 = lStack_148 + 1;
      lStack_148 = lStack_148 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7840,pppppppuVar23);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)pppppppuVar23),
                          &UNK_1819d7843 + (longlong)pppppppuVar23,3 - (longlong)pppppppuVar23);
      pauVar14 = (undefined (*) [16])apppppppuStack_158;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    recovered_180066e40(&uStack_1b8);
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar5[15] = 0;
    auVar5._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar5 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_158;
  }
  else if ((int)param_1 < 0x834) {
    lVar21 = 4;
    uStack_188 = 4;
    stack0xfffffffffffffe6d = ZEXT211((ushort)(_auStack_198 >> 0x28));
    auStack_198._0_5_ = 0x646c6f47;
    recovered_180078780(apppppppuStack_138,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_120 - lStack_128 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_138,3,lStack_128,0,&UNK_1819d7844,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_138;
      if (0xf < uStack_120) {
        pppppppuVar15 = apppppppuStack_138[0];
      }
      if ((&UNK_1819d7846 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_128) < &UNK_1819d7844)) {
        puVar22 = (undefined *)0x3;
      }
      else if (&UNK_1819d7844 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7844);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_128 + 1;
      lStack_128 = lStack_128 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7844,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7847 + (longlong)puVar22,3 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_138;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    recovered_180066e40(&uStack_1b8);
    recovered_180066e40(auStack_1d8);
    pauVar14 = (undefined (*) [16])apppppppuStack_138;
  }
  else if ((int)param_1 < 0xa28) {
    lVar21 = 8;
    uStack_188 = 8;
    _auStack_198 = (unkuint9)0x6d756e6974616c50;
    _auStack_18f = 0;
    recovered_180078780(pauVar14,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_100 - lStack_108 < 3) {
      pauVar13 = (undefined (*) [16])recovered_1800678e0(pauVar14,3,lStack_108,0,&UNK_1819d7848,3);
    }
    else {
      pauVar13 = pauVar14;
      if (0xf < uStack_100) {
        pauVar13 = pauStack_118;
      }
      if (((undefined (*) [16])&UNK_1819d784a < pauVar13) ||
         (*pauVar13 + lStack_108 < &UNK_1819d7848)) {
        puVar22 = (undefined *)0x3;
      }
      else if ((undefined (*) [16])&UNK_1819d7848 < pauVar13) {
        puVar22 = pauVar13[-0x1819d785] + 8;
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_108 + 1;
      lStack_108 = lStack_108 + 3;
      func_0x0001801ca893(*pauVar13 + 3,pauVar13,lVar17);
      func_0x0001801ca88d(pauVar13,&UNK_1819d7848,puVar22);
      func_0x0001801ca88d(puVar22 + (longlong)*pauVar13,puVar22 + 0x1819d784b,3 - (longlong)puVar22)
      ;
      pauVar13 = pauVar14;
    }
    auStack_1d8 = *pauVar13;
    auStack_1c8 = pauVar13[1];
    *(undefined8 *)pauVar13[1] = 0;
    *(undefined8 *)(pauVar13[1] + 8) = 0xf;
    (*pauVar13)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar6[15] = 0;
    auVar6._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar6 << 8;
  }
  else if ((int)param_1 < 0xc80) {
    lVar21 = 7;
    uStack_188 = 7;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d7854,_DAT_1819d7850);
    _auStack_198 = CONCAT16(DAT_1819d7856,auStack_198);
    _auStack_198 = ZEXT716(_auStack_198);
    recovered_180078780(apppppppuStack_f8,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_e0 - lStack_e8 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_f8,3,lStack_e8,0,&UNK_1819d7858,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_f8;
      if (0xf < uStack_e0) {
        pppppppuVar15 = apppppppuStack_f8[0];
      }
      if ((&UNK_1819d785a < pppppppuVar15) ||
         ((undefined *)(lStack_e8 + (longlong)pppppppuVar15) < &UNK_1819d7858)) {
        pppppppuVar23 = (undefined8 *******)0x3;
      }
      else if (&UNK_1819d7858 < pppppppuVar15) {
        pppppppuVar23 = pppppppuVar15 + -0x3033af0b;
      }
      else {
        pppppppuVar23 = (undefined8 *******)0x0;
      }
      lVar17 = lStack_e8 + 1;
      lStack_e8 = lStack_e8 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7858,pppppppuVar23);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)pppppppuVar23),
                          &UNK_1819d785b + (longlong)pppppppuVar23,3 - (longlong)pppppppuVar23);
      pauVar14 = (undefined (*) [16])apppppppuStack_f8;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar7[15] = 0;
    auVar7._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar7 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_f8;
  }
  else if ((int)param_1 < 0x1194) {
    uVar16 = (int)(param_1 - 0xc80) / 0x104 + 1;
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d7860,_DAT_1819d785c);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    if ((int)uVar16 < 1) {
      uVar18 = 1;
    }
    else {
      if (5 < (int)uVar16) {
        uVar16 = 5;
      }
      uVar18 = (ulonglong)uVar16;
    }
    pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
    if ((int)uVar18 < 0) {
      uVar16 = -(int)uVar18;
      do {
        pcVar19 = pcVar20;
        pcVar20 = pcVar19 + -1;
        *pcVar20 = (char)uVar16 + (char)((ulonglong)uVar16 / 10) * -10 + '0';
        uVar16 = (uint)((ulonglong)uVar16 / 10);
      } while (uVar16 != 0);
      pcVar20 = pcVar19 + -2;
      *pcVar20 = '-';
    }
    else {
      do {
        pcVar20 = pcVar20 + -1;
        uVar2 = uVar18 / 10;
        *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
        uVar18 = uVar2;
      } while ((int)uVar2 != 0);
    }
    recovered_180078780(apppppppuStack_d8,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_c0 - lStack_c8 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_d8,3,lStack_c8,0,&UNK_1819d7864,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_d8;
      if (0xf < uStack_c0) {
        pppppppuVar15 = apppppppuStack_d8[0];
      }
      if ((&UNK_1819d7866 < pppppppuVar15) ||
         ((undefined *)(lStack_c8 + (longlong)pppppppuVar15) < &UNK_1819d7864)) {
        puVar22 = (undefined *)0x3;
      }
      else if (&UNK_1819d7864 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7864);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_c8 + 1;
      lStack_c8 = lStack_c8 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7864,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7867 + (longlong)puVar22,3 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_d8;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar8[15] = 0;
    auVar8._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar8 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_d8;
  }
  else if ((int)param_1 < 6000) {
    uVar16 = (int)(param_1 - 0x1194) / 300 + 1;
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d786c,_DAT_1819d7868);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    if ((int)uVar16 < 1) {
      uVar18 = 1;
    }
    else {
      if (5 < (int)uVar16) {
        uVar16 = 5;
      }
      uVar18 = (ulonglong)uVar16;
    }
    pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
    if ((int)uVar18 < 0) {
      uVar16 = -(int)uVar18;
      do {
        pcVar19 = pcVar20;
        pcVar20 = pcVar19 + -1;
        *pcVar20 = (char)uVar16 + (char)((ulonglong)uVar16 / 10) * -10 + '0';
        uVar16 = (uint)((ulonglong)uVar16 / 10);
      } while (uVar16 != 0);
      pcVar20 = pcVar19 + -2;
      *pcVar20 = '-';
    }
    else {
      do {
        pcVar20 = pcVar20 + -1;
        uVar2 = uVar18 / 10;
        *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
        uVar18 = uVar2;
      } while ((int)uVar2 != 0);
    }
    recovered_180078780(apppppppuStack_b8,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_a0 - lStack_a8 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_b8,3,lStack_a8,0,&UNK_1819d7870,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_b8;
      if (0xf < uStack_a0) {
        pppppppuVar15 = apppppppuStack_b8[0];
      }
      if ((&UNK_1819d7872 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_a8) < &UNK_1819d7870)) {
        pppppppuVar23 = (undefined8 *******)0x3;
      }
      else if (&UNK_1819d7870 < pppppppuVar15) {
        pppppppuVar23 = pppppppuVar15 + -0x3033af0e;
      }
      else {
        pppppppuVar23 = (undefined8 *******)0x0;
      }
      lVar17 = lStack_a8 + 1;
      lStack_a8 = lStack_a8 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7870,pppppppuVar23);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)pppppppuVar23),
                          &UNK_1819d7873 + (longlong)pppppppuVar23,3 - (longlong)pppppppuVar23);
      pauVar14 = (undefined (*) [16])apppppppuStack_b8;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar9[15] = 0;
    auVar9._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar9 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_b8;
  }
  else {
    uVar16 = (int)(param_1 - 6000) / 800 + 1;
    lVar21 = 0xb;
    uStack_188 = 0xb;
    stack0xfffffffffffffe70 = _DAT_1819d7880;
    _auStack_198 = _DAT_1819d7878;
    auStack_18f[1] = DAT_1819d7882;
    uStack_18d = 0;
    if ((int)uVar16 < 1) {
      uVar18 = 1;
    }
    else {
      uVar18 = (ulonglong)uVar16;
      if (6 < (int)uVar16) {
        uVar18 = 6;
      }
    }
    pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
    if ((int)uVar18 < 0) {
      uVar16 = -(int)uVar18;
      do {
        pcVar19 = pcVar20;
        pcVar20 = pcVar19 + -1;
        *pcVar20 = (char)uVar16 + (char)((ulonglong)uVar16 / 10) * -10 + '0';
        uVar16 = (uint)((ulonglong)uVar16 / 10);
      } while (uVar16 != 0);
      pcVar20 = pcVar19 + -2;
      *pcVar20 = '-';
    }
    else {
      do {
        pcVar20 = pcVar20 + -1;
        uVar2 = uVar18 / 10;
        *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
        uVar18 = uVar2;
      } while ((int)uVar2 != 0);
    }
    recovered_180078780(apppppppuStack_98,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_80 - lStack_88 < 4) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_98,4,lStack_88,0,&UNK_1819d7884,4);
    }
    else {
      pppppppuVar15 = apppppppuStack_98;
      if (0xf < uStack_80) {
        pppppppuVar15 = apppppppuStack_98[0];
      }
      if ((&UNK_1819d7887 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_88) < &UNK_1819d7884)) {
        puVar22 = (undefined *)0x4;
      }
      else if (&UNK_1819d7884 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7884);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_88 + 1;
      lStack_88 = lStack_88 + 4;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 4),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7884,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7888 + (longlong)puVar22,4 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_98;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar10[15] = 0;
    auVar10._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar10 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_98;
  }
  recovered_180066e40(pauVar14);
  pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
  uVar18 = (ulonglong)param_1;
  if ((int)param_1 < 0) {
    param_1 = -param_1;
    do {
      pcVar19 = pcVar20;
      pcVar20 = pcVar19 + -1;
      *pcVar20 = (char)param_1 + (char)((ulonglong)param_1 / 10) * -10 + '0';
      param_1 = (uint)((ulonglong)param_1 / 10);
    } while (param_1 != 0);
    pcVar20 = pcVar19 + -2;
    *pcVar20 = '-';
  }
  else {
    do {
      pcVar20 = pcVar20 + -1;
      uVar2 = uVar18 / 10;
      *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
      uVar18 = uVar2;
    } while ((int)uVar2 != 0);
  }
  recovered_180078780(auStack_58,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
  if (0x7fffffffffffffffU - lVar21 < 2) {
    func_0x000180052a50();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  recovered_180067040(&uStack_1b8,auStackX_18[0],auStack_198,auStack_198,lVar21,&UNK_1819d788c,2);
  recovered_180079c40(auStack_78,auStackX_18[0],&uStack_1b8,auStack_58);
  pauVar14 = (undefined (*) [16])recovered_180066ec0(auStack_78,&UNK_1819d7830,1);
  auStack_1d8 = *pauVar14;
  auStack_1c8 = pauVar14[1];
  *(undefined8 *)pauVar14[1] = 0;
  *(undefined8 *)(pauVar14[1] + 8) = 0xf;
  (*pauVar14)[0] = 0;
  recovered_1800785e0(param_2,auStack_1d8);
  if (0xf < (ulonglong)auStack_1c8._8_8_) {
    if ((0xfff < auStack_1c8._8_8_ + 1) &&
       (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  recovered_180066e40(auStack_78);
  recovered_180066e40(&uStack_1b8);
  recovered_180066e40(auStack_58);
  if (0xf < uStack_180) {
    if ((0xfff < uStack_180 + 1) && (0x1f < (_auStack_198 - *(longlong *)(_auStack_198 + -8)) - 8U))
    {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18006e7e0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


ulonglong recovered_18006e7e0(uint param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_1;
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = func_0x00018006e5f0(uVar5);
  uVar4 = recovered_180069360(uVar5 + 0x434);
  uVar3 = func_0x00018006e440(uVar4);
  if (uVar2 == 0) {
    uVar4 = recovered_180069360(uVar5 + 0x3f8);
    uVar2 = func_0x00018006e440(uVar4);
    uVar5 = (ulonglong)uVar2;
    if (uVar3 == 0) {
      return uVar5;
    }
  }
  else {
    if (((uVar3 == 0) || (cVar1 = func_0x00018006e8c0(uVar2), cVar1 != '\0')) ||
       (cVar1 = func_0x00018006e8c0(uVar3), cVar1 == '\0')) {
      uVar3 = uVar2;
    }
    uVar4 = recovered_180069360(uVar5 + 0x3f8);
    uVar2 = func_0x00018006e440(uVar4);
    uVar5 = (ulonglong)uVar2;
  }
  if ((short)uVar5 != 0) {
    cVar1 = func_0x00018006e8c0(uVar3);
    uVar2 = (ushort)uVar5;
    if ((cVar1 == '\0') && (cVar1 = func_0x00018006e8c0(uVar5 & 0xffff), cVar1 != '\0')) {
      uVar3 = uVar2;
    }
  }
  return (ulonglong)uVar3;
}



/* ===== ANALYSIS FUNCTION 0x18006e930 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006e930(void)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  
  recovered_18006f2b0();
  lVar4 = _DAT_181b2f4e8;
  cVar1 = *(char *)((longlong)*(longlong **)(_DAT_181b2f4e8 + 8) + 0x19);
  plVar3 = *(longlong **)(_DAT_181b2f4e8 + 8);
  while (cVar1 == '\0') {
    func_0x000180023e30(&DAT_181b2f4e8,&DAT_181b2f4e8,plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    func_0x000180127e40(plVar3,0x28);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  *(longlong *)(lVar4 + 8) = lVar4;
  *(longlong *)lVar4 = lVar4;
  *(longlong *)(lVar4 + 0x10) = lVar4;
  _DAT_181b2f4f0 = 0;
  _DAT_181b302f4 = 0;
  _DAT_181b2bee0 = 0;
  _DAT_181b2bec0 = 0;
  DAT_181b2bedd = 0;
  return;
}



/* ===== ANALYSIS FUNCTION 0x18006eb70 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006eb70(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  float fVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int aiStackX_10 [2];
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  float fStack_108;
  float fStack_104;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 auStack_88 [4];
  float afStack_68 [12];
  
  puVar5 = _DAT_181b2be38;
  fVar4 = _DAT_181a0337c;
  for (puVar3 = (undefined8 *)*_DAT_181b2be38; puVar3 != puVar5; puVar3 = (undefined8 *)*puVar3) {
    if (((*(char *)((longlong)puVar3 + 0x19) != '\0') &&
        (*(char *)((longlong)puVar3 + 0x1a) == '\0')) &&
       (func_0x00018006e9c0(puVar3 + 3,*(undefined4 *)(puVar3 + 2)),
       *(char *)((longlong)puVar3 + 0x1a) == '\0')) {
      puVar1 = puVar3 + 0x14;
      uVar2 = *puVar1;
      fVar8 = *(float *)(puVar3 + 0x15);
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b110,&uStackX_18);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_18,aiStackX_10,4), iVar7 == 0)) &&
         ((aiStackX_10[0] != 0 &&
          (cVar6 = func_0x00018006c290(aiStackX_10[0],puVar1), cVar6 != '\0')))) {
        fStack_108 = (float)uVar2;
        fStack_104 = (float)((ulonglong)uVar2 >> 0x20);
        if (((fStack_108 != 0.0) || (fStack_104 != 0.0)) || (fVar8 != 0.0)) {
          if ((float *)((longlong)puVar3 + 0x184) != afStack_68) {
            *(float *)((longlong)puVar3 + 0x184) = ((float)*puVar1 - fStack_108) * fVar4;
            *(float *)(puVar3 + 0x31) = (*(float *)((longlong)puVar3 + 0xa4) - fStack_104) * fVar4;
            *(float *)((longlong)puVar3 + 0x18c) = (*(float *)(puVar3 + 0x15) - fVar8) * fVar4;
          }
        }
        if (puVar3 + 0x2f != puVar1) {
          *(undefined4 *)(puVar3 + 0x2f) = *(undefined4 *)puVar1;
          *(undefined4 *)((longlong)puVar3 + 0x17c) = *(undefined4 *)((longlong)puVar3 + 0xa4);
          *(undefined4 *)(puVar3 + 0x30) = *(undefined4 *)(puVar3 + 0x15);
        }
        fVar10 = (float)((ulonglong)*param_1 >> 0x20);
        fVar8 = (float)*param_1 - (float)*puVar1;
        fVar9 = fVar10 - (float)((ulonglong)*puVar1 >> 0x20);
        fVar8 = fVar9 * fVar9 + fVar8 * fVar8 +
                (*(float *)(param_1 + 1) - *(float *)(puVar3 + 0x15)) *
                (*(float *)(param_1 + 1) - *(float *)(puVar3 + 0x15));
        if (fVar8 < 0.0) {
          fVar8 = (float)func_0x0001801cb525(CONCAT44(fVar10,fVar8));
        }
        else {
          fVar8 = SQRT(fVar8);
        }
        *(float *)((longlong)puVar3 + 0x24) = fVar8;
      }
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b148,&uStackX_20);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_20,aiStackX_10,4), iVar7 == 0)) &&
         (aiStackX_10[0] != 0)) {
        func_0x00018006c290(aiStackX_10[0],puVar3 + 0x2c);
      }
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b0f0,&uStack_f8);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_f8,aiStackX_10,4), iVar7 == 0)) &&
         (aiStackX_10[0] != 0)) {
        func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xac);
      }
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b128,&uStack_f0);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_f0,aiStackX_10,4), iVar7 == 0)) &&
         (aiStackX_10[0] != 0)) {
        func_0x00018006c290(aiStackX_10[0],puVar3 + 0x23);
      }
      if (DAT_181b2b538 != '\0') {
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b118,&uStack_e8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_e8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xc4);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b0f8,&uStack_e0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_e0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x17);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b100,&uStack_d8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_d8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xdc);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b120,&uStack_d0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_d0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x1a);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b108,&uStack_c8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_c8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xf4);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b150,&uStack_c0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_c0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x1d);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b178,&uStack_b8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_b8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x20);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b160,&uStack_b0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_b0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x10c);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b168,&uStack_a8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_a8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x124);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b170,&uStack_a0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_a0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x13c);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b158,&uStack_98);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_98,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x26);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b138,&uStack_90);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_90,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x29);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b130,auStack_88);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_88[0],aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x154);
        }
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18006f2b0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006f2b0(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined auStackX_8 [8];
  
  recovered_1800721a0();
  puVar2 = (undefined8 *)recovered_180067b80(auStackX_8);
  _DAT_181b302e0 = *puVar2;
  recovered_180069a10(&DAT_181b2bf20);
  recovered_180078290(0x181b2be30);
  lVar1 = _DAT_181b2bde0;
  _DAT_181b2bd7c = 0;
  lVar3 = _DAT_181b2bdd8;
  if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
    do {
      recovered_180066e40(lVar3 + 0x10);
      lVar3 = lVar3 + 0x38;
    } while (lVar3 != lVar1);
    _DAT_181b2bde0 = _DAT_181b2bdd8;
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18006f9b0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006f9b0(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  uStack_10 = auStack_18;
  if (DAT_181b2f6d8 != '\0') {
    return;
  }
  LOCK();
  DAT_181b2f6d8 = 1;
  UNLOCK();
  DAT_181b2b5ef = 1;
  puVar5 = (undefined8 *)func_0x000180127a94(8);
  *puVar5 = &DAT_18006f340;
  auStack_18 = (undefined  [8])_beginthreadex(0,0,&DAT_180079df0,puVar5,0,auStack_18 + 8);
  if (auStack_18 != (undefined  [8])0x0) {
    if (_DAT_181b2f520 != 0) {
      terminate();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _DAT_181b2f520 = uStack_10;
    _DAT_181b2f518 = auStack_18;
    auVar3 = ZEXT816(0);
    if ((int)uStack_10 != 0) {
      iVar4 = _Thrd_detach(auStack_18);
      auVar3 = _auStack_18;
      if (iVar4 == 0) {
        _DAT_181b2f518 = ZEXT816(0);
        puVar5 = (undefined8 *)func_0x000180127a94(8);
        *puVar5 = &DAT_18006f380;
        lVar6 = _beginthreadex(0,0,&DAT_180079df0,puVar5,0,auStack_18 + 8);
        auVar2 = _auStack_18;
        auStack_18 = (undefined  [8])lVar6;
        if (lVar6 == 0) {
          uStack_10._4_4_ = auVar2._12_4_;
          _auStack_18 = ZEXT812(0);
          __Throw_Cpp_error_std__YAXH_Z(6);
          auVar3 = _auStack_18;
        }
        else {
          if (_DAT_181b2f530 != 0) {
            terminate();
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          _DAT_181b2f530 = uStack_10;
          _DAT_181b2f528 = lVar6;
          auVar3 = ZEXT816(0);
          if (auVar2._8_4_ != 0) {
            iVar4 = _Thrd_detach(auStack_18);
            auVar3 = _auStack_18;
            if (iVar4 == 0) {
              _DAT_181b2f528 = ZEXT816(0);
              return;
            }
          }
        }
      }
    }
    _auStack_18 = auVar3;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_10._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x18006fb50 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006fb50(longlong param_1,float param_2,float param_3,char param_4)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float fVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  float *pfVar12;
  longlong lVar13;
  int iVar14;
  undefined8 *puVar15;
  undefined *puVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 uVar23;
  undefined8 uStackX_8;
  float fStackX_10;
  float fStackX_18;
  undefined4 uStackX_20;
  char acStack_1f8 [8];
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  float fStack_1dc;
  undefined4 uStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float afStack_1a0 [2];
  undefined auStack_198 [16];
  undefined auStack_188 [16];
  undefined auStack_178 [16];
  undefined auStack_168 [16];
  float fStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  float fStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  
  lVar10 = _DAT_181b2f2c0;
  if (param_4 == '\0') {
    return;
  }
  if (DAT_181b302f8 == '\0') {
    return;
  }
  if (_DAT_181b302fc == 0) {
    return;
  }
  uStackX_8 = param_1;
  fStackX_18 = param_3;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar10 = func_0x00018000a880(**(undefined8 **)(lVar10 + 0x4908),1,&UNK_18020ed38);
  if (lVar10 == 0) {
    return;
  }
  if (DAT_181b302f8 == '\0') {
    iVar14 = 0xb4;
  }
  else {
    if (DAT_181b302f9 == '\0') {
      recovered_180067b80(&uStackX_8);
      iVar8 = 0xb4 - (int)((uStackX_8 - _DAT_181b30300) / 1000000000);
      iVar14 = 0;
      if (-1 < iVar8) {
        iVar14 = iVar8;
      }
      if (iVar14 != 0) goto LAB_18006fc63;
    }
    else {
      iVar14 = 0;
    }
    DAT_181b302f9 = '\x01';
  }
LAB_18006fc63:
  auStack_198 = ZEXT816(0);
  auStack_188 = auStack_198;
  auStack_178 = auStack_198;
  auStack_168 = auStack_198;
  if (DAT_181b302f9 == '\0') {
    recovered_18006b2f0(auStack_198,0x40,&UNK_1819d7898,iVar14 / 0x3c,iVar14 % 0x3c);
  }
  else {
    recovered_18006b2f0(auStack_198,0x40,&UNK_1819d78a0);
  }
  uVar23 = _DAT_181a0348c;
  lVar1 = *(longlong *)(_DAT_181b2f2c0 + 0x3c30);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) {
    fVar21 = *(float *)(lVar1 + 0x14) * _DAT_181a03240;
    func_0x000180030a70(lVar1,&uStackX_8,fVar21,_DAT_181a03460,_DAT_181a0348c,auStack_198,0);
    fVar4 = _DAT_181a03230;
    fVar18 = _DAT_181a031bc;
    fVar6 = (float)uStackX_8;
    fVar22 = param_2 * _DAT_181a031bc - (float)uStackX_8 * _DAT_181a031bc;
    fStack_148 = _DAT_181a03920;
    uStack_144 = _UNK_181a03924;
    uStack_140 = _UNK_181a03928;
    uStack_13c = _UNK_181a0392c;
    fStack_158 = _DAT_181a03940;
    uStack_154 = _UNK_181a03944;
    uStack_150 = _UNK_181a03948;
    uStack_14c = _UNK_181a0394c;
    fStackX_10 = fVar22;
    uStack_1e4 = func_0x0001801cb4f5((float)*(double *)(_DAT_181b2f2c0 + 0x3e60) * _DAT_181a0320c);
    uStack_1e0 = func_0x0001801cb4f5();
    puVar16 = auStack_198;
    if (auStack_198[0] != '\0') {
      fStack_1e8 = fVar6;
      if (fVar6 <= fVar4) {
        fStack_1e8 = fVar4;
      }
      uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3f800000);
      uStackX_20 = 0;
      acStack_1f8[0] = auStack_198[0];
      do {
        acStack_1f8[1] = 0;
        func_0x000180030a70(lVar1,afStack_1a0,fVar21,_DAT_181a03460,uVar23,acStack_1f8,
                            acStack_1f8 + 1);
        fVar6 = afStack_1a0[0];
        cVar5 = DAT_181b302f9;
        fVar17 = (float)func_0x0001801cb4f5();
        fVar18 = (float)((uint)(fVar17 - fVar18) & _DAT_181a039d0);
        fStackX_18 = fVar4 - (fVar18 + fVar18);
        puVar15 = (undefined8 *)&uStackX_20;
        if (0.0 <= fStackX_18) {
          puVar15 = (undefined8 *)&fStackX_18;
        }
        puVar11 = &uStackX_8;
        if (fStackX_18 <= fVar4) {
          puVar11 = puVar15;
        }
        pfVar12 = &fStack_158;
        if (cVar5 == '\0') {
          pfVar12 = &fStack_148;
        }
        fVar18 = *pfVar12;
        fVar17 = pfVar12[1];
        fVar2 = pfVar12[2];
        fVar3 = pfVar12[3];
        fVar19 = _DAT_181a031f8;
        if (cVar5 != '\0') {
          fVar19 = _DAT_181a03214;
        }
        fVar19 = *(float *)puVar11 * fVar19;
        uVar23 = 0xdc000000;
        if (cVar5 != '\0') {
          uVar23 = 0xaa000000;
        }
        fStack_1ec = _DAT_181a03398;
        fStack_1f0 = fVar22;
        if (cVar5 != '\0') {
          uStack_1d8 = 0x42b80000;
          fStack_1dc = fVar22 - fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_138 = *(undefined4 *)(lVar10 + 0x88);
            uStack_134 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_130 = *(undefined4 *)(lVar10 + 0x90);
            uStack_12c = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1dc,uVar23,&uStack_138,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
          fStack_1d0 = fStack_1ec;
          fStack_1d4 = fStack_1f0 + fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_128 = *(undefined4 *)(lVar10 + 0x88);
            uStack_124 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_120 = *(undefined4 *)(lVar10 + 0x90);
            uStack_11c = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1d4,uVar23,&uStack_128,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
          fStack_1cc = fStack_1f0;
          fStack_1c8 = fStack_1ec - fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_118 = *(undefined4 *)(lVar10 + 0x88);
            uStack_114 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_110 = *(undefined4 *)(lVar10 + 0x90);
            uStack_10c = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1cc,uVar23,&uStack_118,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
          fStack_1c4 = fStack_1f0;
          fStack_1c0 = fStack_1ec + fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_108 = *(undefined4 *)(lVar10 + 0x88);
            uStack_104 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_100 = *(undefined4 *)(lVar10 + 0x90);
            uStack_fc = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1c4,uVar23,&uStack_108,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
        }
        fStack_1bc = fStack_1f0 + fVar4;
        fStack_1b8 = fStack_1ec + fVar4;
        lVar7 = -1;
        do {
          lVar13 = lVar7;
          lVar7 = lVar13 + 1;
        } while (acStack_1f8[lVar13 + 1] != '\0');
        if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
          fVar20 = fVar21;
          if (fVar21 == 0.0) {
            fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
          }
          if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
            _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
          }
          uStack_f8 = *(undefined4 *)(lVar10 + 0x88);
          uStack_f4 = *(undefined4 *)(lVar10 + 0x8c);
          uStack_f0 = *(undefined4 *)(lVar10 + 0x90);
          uStack_ec = *(undefined4 *)(lVar10 + 0x94);
          func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1bc,uVar23,&uStack_f8,acStack_1f8,
                              acStack_1f8 + lVar13 + 1,0,0);
        }
        fStack_1a4 = ((fVar4 - fVar3) * fVar19 + fVar3) * *(float *)(_DAT_181b2f2c0 + 0x37d0);
        fStack_1b0 = (fVar4 - fVar18) * fVar19 + fVar18;
        fStack_1ac = (fVar4 - fVar17) * fVar19 + fVar17;
        fStack_1a8 = (fVar4 - fVar2) * fVar19 + fVar2;
        uVar9 = func_0x000180004f90(&fStack_1b0);
        if ((uVar9 & 0xff000000) != 0) {
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar18 = fVar21;
            if (fVar21 == 0.0) {
              fVar18 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_e8 = *(undefined4 *)(lVar10 + 0x88);
            uStack_e4 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_e0 = *(undefined4 *)(lVar10 + 0x90);
            uStack_dc = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar18,&fStack_1f0,uVar9,&uStack_e8,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
        }
        acStack_1f8[0] = puVar16[1];
        fVar22 = fVar22 + fVar6;
        puVar16 = puVar16 + 1;
        fVar18 = _DAT_181a031bc;
        uVar23 = _DAT_181a0348c;
      } while (acStack_1f8[0] != '\0');
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800705d0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int recovered_1800705d0(longlong param_1)

{
  longlong alStackX_8 [4];
  
  if (DAT_181b302f8 == '\0') {
    return 0xb4;
  }
  if (DAT_181b302f9 != '\0') {
    return 0;
  }
  alStackX_8[0] = param_1;
  recovered_180067b80(alStackX_8);
  return 0xb4 - (int)((alStackX_8[0] - _DAT_181b30300) / 1000000000);
}



/* ===== ANALYSIS FUNCTION 0x180070640 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong *
recovered_180070640(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 uStack_34;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined8 uStack_1c;
  undefined4 uStack_14;
  undefined uStack_10;
  undefined uStack_f;
  undefined uStack_e;
  undefined uStack_d;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar4 = _DAT_181b2be40;
  if (_DAT_181b2be40 != 0) {
    if (0x666666666666666 < _DAT_181b2be40) {
      recovered_18006aad0(param_1,param_2,param_3,param_4,1);
      pcVar2 = (code *)swi(3);
      plVar6 = (longlong *)(*pcVar2)();
      return plVar6;
    }
    uVar5 = func_0x000180024110(_DAT_181b2be40 * 0x28);
    func_0x0001801ca893(uVar5,*param_1,param_1[1] - *param_1);
    recovered_18007a480(param_1,uVar5,0,uVar4);
  }
  puVar3 = _DAT_181b2be38;
  puVar7 = (undefined8 *)*_DAT_181b2be38;
  while (puVar7 != puVar3) {
    uStack_34 = puVar7[0x14];
    uStack_2c = *(undefined4 *)(puVar7 + 0x15);
    uStack_28 = puVar7[0x23];
    uStack_20 = *(undefined4 *)(puVar7 + 0x24);
    uStack_1c = puVar7[0x2c];
    uStack_14 = *(undefined4 *)(puVar7 + 0x2d);
    uStack_10 = *(undefined *)((longlong)puVar7 + 0x19);
    uStack_f = *(undefined *)((longlong)puVar7 + 0x1a);
    uStack_e = *(undefined *)((longlong)puVar7 + 0x1b);
    puVar1 = (undefined4 *)param_1[1];
    if (puVar1 == (undefined4 *)param_1[2]) {
      recovered_180079e50(param_1,puVar1,&uStack_34);
      puVar7 = (undefined8 *)*puVar7;
    }
    else {
      uStack_34._4_4_ = (undefined4)((ulonglong)uStack_34 >> 0x20);
      *puVar1 = (undefined4)uStack_34;
      puVar1[1] = uStack_34._4_4_;
      puVar1[2] = uStack_2c;
      puVar1[3] = (undefined4)uStack_28;
      uStack_28._4_4_ = (undefined4)((ulonglong)uStack_28 >> 0x20);
      uStack_1c._4_4_ = (undefined4)((ulonglong)uStack_1c >> 0x20);
      puVar1[4] = uStack_28._4_4_;
      puVar1[5] = uStack_20;
      puVar1[6] = (undefined4)uStack_1c;
      puVar1[7] = uStack_1c._4_4_;
      *(ulonglong *)(puVar1 + 8) =
           CONCAT17(uStack_d,CONCAT16(uStack_e,CONCAT15(uStack_f,CONCAT14(uStack_10,uStack_14))));
      param_1[1] = param_1[1] + 0x28;
      puVar7 = (undefined8 *)*puVar7;
    }
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x1800707c0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800707c0(void)

{
  char *pcVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  char *pcVar13;
  float fVar14;
  longlong lVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  char acStackX_8 [8];
  char cStackX_10;
  uint auStackX_18 [2];
  float fStackX_20;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  undefined8 uStack_1b0;
  float fStack_1a8;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  uint uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_160;
  float fStack_158;
  undefined8 uStack_150;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  undefined auStack_130 [16];
  longlong lStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_e8;
  
  do {
    do {
      iVar7 = _DAT_181b2becc;
      iVar11 = _DAT_181b2bec8;
      fVar6 = _DAT_181b2be80;
      fVar22 = _DAT_181b2be70;
      fVar5 = _DAT_181b2b428;
      cVar9 = DAT_181b2b406;
      if (DAT_181b4efd2 != '\0') {
        DAT_181b4efd1 = 0;
        return;
      }
    } while ((((DAT_181b2b41d == '\0') || (_DAT_181b2bec8 == -1)) || (_DAT_181b2becc == -1)) ||
            (DAT_181b2bec4 == '\0'));
    fStackX_20 = _DAT_181b2be70;
    fStack_194 = _DAT_181b2be74;
    fStack_184 = _DAT_181b2be7c;
    fStack_198 = _DAT_181b2be84;
    fStack_188 = _DAT_181b2be8c;
    fStack_1a0 = _DAT_181b2be90;
    fStack_190 = _DAT_181b2be94;
    fStack_180 = _DAT_181b2be9c;
    fStack_19c = _DAT_181b2bea0;
    fStack_18c = _DAT_181b2bea4;
    fStack_17c = _DAT_181b2beac;
    uStack_160 = _DAT_181b2beb0;
    fStack_158 = _DAT_181b2beb8;
    fVar25 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar24 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    acStackX_8[0] = DAT_181b2b406;
    uStack_178 = _DAT_181b2bebc;
    cStackX_10 = _DAT_181b2b420 == 2;
    recovered_180070640(auStack_130);
    iVar4 = _DAT_181b2b424;
    fStack_1c8 = 0.0;
    fStack_1c4 = 0.0;
    fStack_1c0 = 0.0;
    bVar3 = false;
    pcVar8 = (char *)auStack_130._8_8_;
    if (auStack_130._0_8_ != auStack_130._8_8_) {
      pcVar13 = (char *)(auStack_130._0_8_ + 0x25);
      fVar23 = _DAT_181a03460;
      do {
        if (((pcVar13[-1] != '\0') && (*pcVar13 == '\0')) &&
           ((cVar9 == '\0' || (pcVar13[1] == '\0')))) {
          if (iVar4 == 1) {
            uStack_f8 = *(undefined8 *)(pcVar13 + -0x19);
            if ((((float)uStack_f8 == 0.0) &&
                (uStack_f8._4_4_ = (float)((ulonglong)uStack_f8 >> 0x20), uStack_f8._4_4_ == 0.0))
               && (*(float *)(pcVar13 + -0x11) == 0.0)) {
              fVar19 = (float)*(undefined8 *)(pcVar13 + -0xd);
              fVar18 = (float)((ulonglong)*(undefined8 *)(pcVar13 + -0xd) >> 0x20);
              fVar14 = *(float *)(pcVar13 + -5);
            }
            else {
              fVar19 = (float)*(undefined8 *)(pcVar13 + -0x19);
              fVar18 = (float)((ulonglong)*(undefined8 *)(pcVar13 + -0x19) >> 0x20);
              fVar14 = *(float *)(pcVar13 + -0x11);
            }
LAB_180070af9:
            uStack_170 = CONCAT44(fVar18,fVar19);
          }
          else {
            uStack_150 = *(undefined8 *)(pcVar13 + -0x25);
            fVar19 = (float)uStack_150;
            fVar14 = *(float *)(pcVar13 + -0x1d);
            uStack_e8._4_4_ = (float)((ulonglong)uStack_150 >> 0x20);
            uStack_e8 = uStack_150;
            if (((fVar19 != 0.0) || (uStack_e8._4_4_ != 0.0)) ||
               (*(float *)(pcVar13 + -0x1d) != 0.0)) {
              fVar18 = uStack_e8._4_4_ + _DAT_181a0315c;
              uStack_150 = CONCAT44(fVar18,fVar19);
              goto LAB_180070af9;
            }
            fVar19 = 0.0;
            fVar14 = 0.0;
            fVar18 = 0.0;
          }
          if (((fVar19 != 0.0) || (fVar18 != 0.0)) || (cVar9 = acStackX_8[0], fVar14 != 0.0)) {
            if (cStackX_10 == '\0') {
              fVar17 = _DAT_181a0348c;
              fVar20 = _DAT_181a0348c;
              if ((0 < iVar11) && (0 < iVar7)) {
                fVar16 = fVar22 * fVar19;
                fVar21 = fStack_188 * fVar18 + fStack_184 * fVar19 + fStack_180 * fVar14 +
                         fStack_17c;
                fVar22 = fStackX_20;
                if (_DAT_181a03124 <= fVar21) {
                  fVar17 = ((fVar6 * fVar18 + fVar16 + fStack_1a0 * fVar14 + fStack_19c) * fVar24) /
                           fVar21 + fVar24;
                  fVar20 = fVar25 - ((fStack_198 * fVar18 + fStack_194 * fVar19 +
                                      fStack_190 * fVar14 + fStack_18c) * fVar25) / fVar21;
                }
              }
              fVar17 = (fVar25 - fVar20) * (fVar25 - fVar20) + (fVar24 - fVar17) * (fVar24 - fVar17)
              ;
              if (fVar17 < 0.0) {
                fVar17 = (float)func_0x0001801cb525(fVar17);
              }
              else {
                fVar17 = SQRT(fVar17);
              }
              if ((0.0 < fVar5) && (cVar9 = acStackX_8[0], fVar5 < fVar17)) goto LAB_180070cdc;
            }
            else {
              fVar17 = (uStack_160._4_4_ - fVar18) * (uStack_160._4_4_ - fVar18) +
                       ((float)uStack_160 - fVar19) * ((float)uStack_160 - fVar19) +
                       (fStack_158 - fVar14) * (fStack_158 - fVar14);
              if (fVar17 < 0.0) {
                fVar17 = (float)func_0x0001801cb525(fVar17);
              }
              else {
                fVar17 = SQRT(fVar17);
              }
            }
            cVar9 = acStackX_8[0];
            if (fVar17 < fVar23) {
              bVar3 = true;
              fVar23 = fVar17;
              fStack_1c0 = fVar14;
              fStack_1c8 = fVar19;
              fStack_1c4 = fVar18;
            }
          }
        }
LAB_180070cdc:
        pcVar1 = pcVar13 + 3;
        pcVar13 = pcVar13 + 0x28;
      } while (pcVar1 != pcVar8);
      if (((bVar3) && (uVar12 = (ulonglong)uStack_178, uStack_178 != 0)) &&
         ((fStack_1c8 != 0.0 || ((fStack_1c4 != 0.0 || (fStack_1c0 != 0.0)))))) {
        acStackX_8[0] = '\0';
        cVar9 = recovered_180067cc0(uVar12 + 0x58c,&uStack_118);
        if ((cVar9 != '\0') &&
           ((((uVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_118,acStackX_8,1), uVar10 == 0 &&
              (acStackX_8[0] != '\0')) &&
             (auStackX_18[0] = uVar10, cVar9 = recovered_180067cc0(uVar12 + 0x9d0,&uStack_110),
             cVar9 != '\0')) &&
            ((iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_110,auStackX_18,4), iVar11 == 0 &&
             (auStackX_18[0] != 0)))))) {
          uStack_1b0 = 0;
          fStack_1a8 = 0.0;
          cVar9 = recovered_180067cc0((ulonglong)auStackX_18[0] + 0x38,&uStack_108);
          if ((cVar9 != '\0') &&
             (iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_108,&uStack_1b0,0xc), iVar11 == 0)) {
            fStack_140 = fStack_1c8 - (float)uStack_1b0;
            fStack_13c = fStack_1c4 - uStack_1b0._4_4_;
            fStack_138 = fStack_1c0 - fStack_1a8;
            cVar9 = recovered_180067cc0((ulonglong)auStackX_18[0] + 0x2c,&uStack_100);
            if (cVar9 != '\0') {
              (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_100,&fStack_140,0xc);
            }
          }
        }
      }
    }
    if (auStack_130._0_8_ != 0) {
      lVar15 = auStack_130._0_8_;
      if ((0xfff < (ulonglong)(((lStack_120 - auStack_130._0_8_) / 0x28) * 0x28)) &&
         (lVar15 = *(longlong *)(auStack_130._0_8_ + -8), 0x1f < (auStack_130._0_8_ - lVar15) - 8U))
      {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      func_0x000180127e40(lVar15);
      auStack_130 = ZEXT816(0);
      lStack_120 = 0;
    }
  } while( true );
}



/* ===== ANALYSIS FUNCTION 0x180070fd0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_180070fd0(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined8 uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  uStack_10 = auStack_18;
  uVar4 = 0;
  LOCK();
  bVar5 = DAT_181b4efd1 == 0;
  if (bVar5) {
    DAT_181b4efd1 = 1;
  }
  else {
    uVar4 = (ulonglong)DAT_181b4efd1;
  }
  UNLOCK();
  if (!bVar5) {
    return uVar4;
  }
  DAT_181b4efd2 = 0;
  uVar3 = func_0x000180127a94(1);
  auStack_18 = (undefined  [8])_beginthreadex(0,0,&DAT_180079e20,uVar3,0,auStack_18 + 8);
  if (auStack_18 != (undefined  [8])0x0) {
    if (_DAT_181b50930 != 0) {
      terminate();
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _DAT_181b50930 = uStack_10;
    _DAT_181b50928 = auStack_18;
    auVar2 = ZEXT816(0);
    if ((int)uStack_10 != 0) {
      uVar4 = _Thrd_detach(auStack_18);
      auVar2 = _auStack_18;
      if ((int)uVar4 == 0) {
        _DAT_181b50928 = ZEXT816(0);
        return uVar4;
      }
    }
    _auStack_18 = auVar2;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_10._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  uVar4 = (*pcVar1)();
  return uVar4;
}



/* ===== ANALYSIS FUNCTION 0x180071220 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180071220(undefined8 *param_1,ulonglong param_2,longlong param_3)

{
  char cVar1;
  int iVar2;
  int aiStackX_10 [2];
  undefined4 uStackX_18;
  undefined4 uStackX_1c;
  undefined8 uStackX_20;
  undefined8 uStack_28;
  float fStack_20;
  
  aiStackX_10[0] = 0;
  cVar1 = recovered_180067cc0((param_2 & 0xffffffff) + param_3,&uStackX_18);
  if (((cVar1 != '\0') &&
      (iVar2 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),aiStackX_10,4),
      iVar2 == 0)) && (aiStackX_10[0] != 0)) {
    uStack_28 = 0;
    fStack_20 = 0.0;
    cVar1 = recovered_180067cc0(aiStackX_10[0] + 8,&uStackX_20);
    if ((((cVar1 != '\0') &&
         (iVar2 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_20,&uStackX_18,4), iVar2 == 0)) &&
        (cVar1 = recovered_18006bd40(uStackX_18,&uStack_28), cVar1 != '\0')) &&
       ((((float)uStack_28 != 0.0 || (uStack_28._4_4_ != 0.0)) || (fStack_20 != 0.0)))) {
      *param_1 = uStack_28;
      *(float *)(param_1 + 1) = fStack_20;
      return param_1;
    }
  }
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180071340 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180071340(void)

{
  longlong **pplVar1;
  longlong *plVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong **pplStackX_8;
  
  pplVar4 = _DAT_181b2f4a8;
  pplVar3 = _DAT_181b2f4a8;
  for (pplVar1 = (longlong **)*_DAT_181b2f4a8; _DAT_181b2f4a8 = pplVar3, pplVar1 != pplVar4;
      pplVar1 = (longlong **)*pplVar1) {
    func_0x0001800710b0(*(undefined4 *)(pplVar1 + 2),(longlong)pplVar1 + 0x14);
    pplVar3 = _DAT_181b2f4a8;
  }
  if (_DAT_181b2f4b0 != 0) {
    if (_DAT_181b2f4b0 < _DAT_181b2f4d8 >> 3) {
      func_0x0001800793c0(0x181b2f4a0,*pplVar3,pplVar3);
    }
    else {
      *pplVar3[1] = 0;
      pplVar1 = (longlong **)*pplVar3;
      while (pplVar1 != (longlong **)0x0) {
        plVar2 = *pplVar1;
        func_0x000180127e40(pplVar1,0x20);
        pplVar1 = (longlong **)plVar2;
      }
      *_DAT_181b2f4a8 = (longlong *)_DAT_181b2f4a8;
      _DAT_181b2f4a8[1] = (longlong *)_DAT_181b2f4a8;
      pplStackX_8 = _DAT_181b2f4a8;
      _DAT_181b2f4b0 = 0;
      recovered_180067850(_DAT_181b2f4b8,_DAT_181b2f4c0,&pplStackX_8);
    }
  }
  _DAT_181b2f8cc = 0;
  return;
}



/* ===== ANALYSIS FUNCTION 0x180071430 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180071430(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uStack_18;
  float fStack_10;
  
  iVar1 = *(int *)(param_2 + 0x84);
  if (iVar1 != 0) {
    if (_DAT_181b2b620 == 1) {
      recovered_180071220(&uStack_18,iVar1,_DAT_181a2b128);
      if ((((float)uStack_18 == 0.0) && (uStack_18._4_4_ == 0.0)) && (fStack_10 == 0.0)) {
        if ((((float)*(undefined8 *)(param_2 + 0x100) == 0.0) &&
            (uStack_18._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x100) >> 0x20),
            uStack_18._4_4_ == 0.0)) && (*(float *)(param_2 + 0x108) == 0.0)) {
          uStack_18 = 0;
          fStack_10 = 0.0;
        }
        else {
          fStack_10 = *(float *)(param_2 + 0x108);
          uStack_18 = *(undefined8 *)(param_2 + 0x100);
        }
      }
    }
    else {
      recovered_180071220(&uStack_18,iVar1,_DAT_181a2b110);
      if ((((float)uStack_18 == 0.0) && (uStack_18._4_4_ == 0.0)) && (fStack_10 == 0.0)) {
        if ((((float)*(undefined8 *)(param_2 + 0x88) == 0.0) &&
            (uStack_18._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x88) >> 0x20),
            uStack_18._4_4_ == 0.0)) && (*(float *)(param_2 + 0x90) == 0.0)) {
          uStack_18 = 0;
          fStack_10 = 0.0;
        }
        else {
          fStack_10 = *(float *)(param_2 + 0x90);
          uStack_18 = *(undefined8 *)(param_2 + 0x88);
        }
      }
    }
    *param_1 = uStack_18;
    *(float *)(param_1 + 1) = fStack_10;
    return param_1;
  }
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180071610 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 recovered_180071610(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  float fStack_24;
  undefined auStack_18 [24];
  
  if (((((*(int *)(param_1 + 0x84) != 0) && (*(int *)(param_1 + 0x84) != param_2)) &&
       (*(char *)(param_1 + 1) != '\0')) &&
      ((*(char *)(param_1 + 2) == '\0' && (*(int *)(param_1 + 0x18) != 0)))) &&
     ((DAT_181b2b406 == '\0' || (*(char *)(param_1 + 3) == '\0')))) {
    puVar1 = (undefined8 *)recovered_180071430(auStack_18,param_1);
    if ((((float)*puVar1 != 0.0) ||
        (fStack_24 = (float)((ulonglong)*puVar1 >> 0x20), fStack_24 != 0.0)) ||
       (*(float *)(puVar1 + 1) != 0.0)) {
      return 1;
    }
  }
  return 0;
}



/* ===== ANALYSIS FUNCTION 0x1800717e0 ===== */

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



/* ===== ANALYSIS FUNCTION 0x180071ae0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180071ae0(uint param_1)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  char cVar7;
  short sVar8;
  undefined2 uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  longlong *plVar13;
  ulonglong uVar14;
  longlong lVar15;
  longlong lVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  int aiStackX_10 [2];
  int iStackX_18;
  undefined4 uStackX_1c;
  undefined8 uStackX_20;
  undefined8 uStack_118;
  float fStack_110;
  undefined8 uStack_108;
  float fStack_100;
  undefined8 uStack_f8;
  float fStack_f0;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  
  if (DAT_181b2b61d == '\0') {
    if (_DAT_181b2f4b0 != 0) {
      recovered_180071340();
    }
    _DAT_181ade200 = 0xffffffff;
    return;
  }
  if (_DAT_181b2bec8 < 1) {
    return;
  }
  if (_DAT_181b2becc < 1) {
    return;
  }
  if (DAT_181b2bec4 == '\0') {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  uVar10 = (uint)(_DAT_181b2b620 == 1);
  if (_DAT_181ade200 != uVar10) {
    _DAT_181ade200 = uVar10;
    if (_DAT_181b2f4b0 != 0) {
      recovered_180071340();
    }
    _DAT_181b2f8cc = 0;
  }
  cVar7 = func_0x000180077db0((ulonglong)param_1 + _DAT_181b2bf70);
  sVar8 = GetAsyncKeyState(1);
  if ((cVar7 == '\0') && (-1 < sVar8)) {
    if (_DAT_181b2f4b0 != 0) {
      recovered_180071340();
    }
    _DAT_181b2f8cc = 0;
    return;
  }
  if (_DAT_181b2f8cc == 0) {
LAB_180071cae:
    lVar15 = func_0x000180071690();
    if (lVar15 == 0) {
      return;
    }
    _DAT_181b2f8cc = *(uint *)(lVar15 + 0x84);
  }
  else {
    uVar14 = (((((ulonglong)_DAT_181b2f8cc & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^
               (ulonglong)(_DAT_181b2f8cc >> 8) & 0xff) * 0x100000001b3 ^
              (ulonglong)(_DAT_181b2f8cc >> 0x10 & 0xff)) * 0x100000001b3 ^
             (ulonglong)(_DAT_181b2f8cc >> 0x18)) * 0x100000001b3 & _DAT_181b2be60;
    lVar12 = *(longlong *)(_DAT_181b2be48 + 8 + uVar14 * 0x10);
    if (lVar12 == _DAT_181b2be38) {
LAB_180071c81:
      lVar12 = 0;
    }
    else {
      uVar10 = *(uint *)(lVar12 + 0x10);
      while (_DAT_181b2f8cc != uVar10) {
        if (lVar12 == *(longlong *)(_DAT_181b2be48 + uVar14 * 0x10)) goto LAB_180071c81;
        lVar12 = *(longlong *)(lVar12 + 8);
        uVar10 = *(uint *)(lVar12 + 0x10);
      }
    }
    lVar15 = _DAT_181b2be38;
    if (lVar12 != 0) {
      lVar15 = lVar12;
    }
    if (lVar15 == _DAT_181b2be38) goto LAB_180071cae;
    lVar15 = lVar15 + 0x18;
    cVar7 = recovered_180071610(lVar15,_DAT_181b2bebc);
    if ((cVar7 == '\0') || (lVar15 == 0)) goto LAB_180071cae;
  }
  aiStackX_10[0] = 0;
  puVar1 = (uint *)(lVar15 + 0x84);
  cVar7 = recovered_180067cc0((ulonglong)*puVar1 + _DAT_181a2b148,&iStackX_18);
  if (cVar7 == '\0') {
    return;
  }
  iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),aiStackX_10,4);
  if (iVar11 != 0) {
    return;
  }
  if (aiStackX_10[0] == 0) {
    return;
  }
  uStack_118 = 0;
  fStack_110 = 0.0;
  cVar7 = recovered_180067cc0(aiStackX_10[0] + 8,&uStackX_20);
  if (cVar7 == '\0') {
    return;
  }
  iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_20,&iStackX_18,4);
  if (iVar11 != 0) {
    return;
  }
  cVar7 = recovered_18006bd40(iStackX_18,&uStack_118);
  fVar20 = fStack_110;
  if (cVar7 == '\0') {
    return;
  }
  uVar14 = (((((ulonglong)*(byte *)puVar1 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
             (ulonglong)*(byte *)(lVar15 + 0x85)) * 0x100000001b3 ^
            (ulonglong)*(byte *)(lVar15 + 0x86)) * 0x100000001b3 ^
           (ulonglong)*(byte *)(lVar15 + 0x87)) * 0x100000001b3 & _DAT_181b2f4d0;
  lVar12 = *(longlong *)(_DAT_181b2f4b8 + 8 + uVar14 * 0x10);
  lVar16 = 0;
  if (lVar12 != _DAT_181b2f4a8) {
    uVar10 = *(uint *)(lVar12 + 0x10);
    while ((lVar16 = lVar12, *puVar1 != uVar10 &&
           (lVar16 = 0, lVar12 != *(longlong *)(_DAT_181b2f4b8 + uVar14 * 0x10)))) {
      lVar12 = *(longlong *)(lVar12 + 8);
      uVar10 = *(uint *)(lVar12 + 0x10);
    }
  }
  fVar21 = uStack_118._4_4_;
  fVar22 = (float)uStack_118;
  lVar12 = _DAT_181b2f4a8;
  if (lVar16 != 0) {
    lVar12 = lVar16;
  }
  if (lVar12 == _DAT_181b2f4a8) {
    plVar13 = (longlong *)func_0x000180078d00(0x181b2f4a0,&uStack_f8,puVar1);
    lVar12 = *plVar13;
    if ((undefined8 *)(lVar12 + 0x14) != &uStack_118) {
      *(float *)(undefined8 *)(lVar12 + 0x14) = fVar22;
      *(float *)(lVar12 + 0x18) = fVar21;
      *(float *)(lVar12 + 0x1c) = fVar20;
    }
  }
  plVar13 = (longlong *)func_0x000180078d00(0x181b2f4a0,&uStack_f8,puVar1);
  uStack_108 = *(undefined8 *)(*plVar13 + 0x14);
  fStack_100 = *(float *)(*plVar13 + 0x1c);
  recovered_180071430(&uStack_f8,lVar15);
  fVar4 = _DAT_181b2be98;
  fVar3 = _DAT_181b2be88;
  fVar2 = _DAT_181b2be78;
  fVar19 = (float)uStack_f8;
  fVar6 = uStack_f8._4_4_;
  if ((((float)uStack_f8 == 0.0) && (uStack_f8._4_4_ == 0.0)) && (fStack_f0 == 0.0)) {
    return;
  }
  fVar22 = fVar22 - (float)uStack_f8;
  fVar21 = fVar21 - uStack_f8._4_4_;
  fVar18 = _DAT_181b2be78 * _DAT_181b2be78 + _DAT_181b2be88 * _DAT_181b2be88 +
           _DAT_181b2be98 * _DAT_181b2be98;
  if (fVar18 < 0.0) {
    fVar18 = (float)func_0x0001801cb525(fVar18);
  }
  else {
    fVar18 = SQRT(fVar18);
  }
  if (fVar18 < _DAT_181a0310c) {
    return;
  }
  uStack_f8 = _DAT_181b2beb0;
  uVar5 = uStack_f8;
  fVar17 = (float)((ulonglong)_DAT_181b2beb0 >> 0x20);
  uStack_f8._0_4_ = (float)_DAT_181b2beb0;
  fVar19 = (fVar6 - fVar17) * (fVar3 / fVar18) + (fVar19 - (float)uStack_f8) * (fVar2 / fVar18) +
           (fStack_f0 - _DAT_181b2beb8) * (fVar4 / fVar18);
  fStack_e8 = fVar19 * (fVar2 / fVar18) + (float)uStack_f8 + fVar22;
  fStack_e4 = fVar19 * (fVar3 / fVar18) + fVar17 + fVar21;
  fStack_e0 = fVar19 * (fVar4 / fVar18) + _DAT_181b2beb8 + (fVar20 - fStack_f0);
  fVar20 = _DAT_181b2b628;
  if (_DAT_181b2b628 <= 0.0) {
    fVar20 = _DAT_181a032e0;
  }
  fVar22 = _DAT_181b2b62c;
  if (_DAT_181b2b62c <= 0.0) {
    fVar22 = _DAT_181a03230;
  }
  uStack_f8 = uVar5;
  if (fVar22 < (float)((uint)(fStack_e4 - uStack_108._4_4_) & _DAT_181a039d0)) {
LAB_18007209c:
    func_0x0001800710b0(*puVar1,&uStack_108);
  }
  else {
    if (0.0 < fVar20) {
      fVar22 = (uStack_108._4_4_ - fStack_e4) * (uStack_108._4_4_ - fStack_e4) +
               ((float)uStack_108 - fStack_e8) * ((float)uStack_108 - fStack_e8) +
               (fStack_100 - fStack_e0) * (fStack_100 - fStack_e0);
      if (fVar22 < 0.0) {
        fVar22 = (float)func_0x0001801cb525(fVar22);
      }
      else {
        fVar22 = SQRT(fVar22);
      }
      if (fVar20 < fVar22) goto LAB_18007209c;
    }
    func_0x0001800710b0(*puVar1,&fStack_e8);
    uVar9 = recovered_18006e7e0((ulonglong)param_1);
    cVar7 = func_0x00018006e8c0(uVar9);
    if (cVar7 != '\0') {
      uVar10 = *puVar1;
      if (uVar10 != 0) {
        iStackX_18 = recovered_180069360((ulonglong)uVar10 + 0x4e8);
        if ((iStackX_18 != 0) &&
           (cVar7 = recovered_180067cc0((ulonglong)uVar10 + 0x54,&uStackX_20), cVar7 != '\0')) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_20,&iStackX_18,4);
        }
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800721a0 ===== */

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



/* ===== ANALYSIS FUNCTION 0x180072400 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180072400(char param_1,char param_2)

{
  undefined8 *puVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  undefined8 *puVar7;
  float fVar8;
  int iVar9;
  longlong lVar10;
  undefined8 *puVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fStack_e8;
  
  iVar9 = _DAT_181b2bebc;
  fVar8 = _DAT_181b2beac;
  puVar7 = _DAT_181b2be38;
  fVar6 = _DAT_181b2b63c;
  fVar5 = _DAT_181b2b410;
  cVar4 = DAT_181b2b406;
  fVar3 = _DAT_181a032ec;
  fVar2 = _DAT_181a03230;
  puVar11 = (undefined8 *)0x0;
  if (((_DAT_181b2bec8 < 1) || (_DAT_181b2becc < 1)) || (DAT_181b2bec4 == '\0')) {
    puVar11 = (undefined8 *)0x0;
  }
  else {
    fVar19 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar18 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    fVar17 = _DAT_181a03460;
    for (puVar1 = (undefined8 *)*_DAT_181b2be38; puVar1 != puVar7; puVar1 = (undefined8 *)*puVar1) {
      if ((((*(int *)((longlong)puVar1 + 0x9c) != 0) && (*(int *)((longlong)puVar1 + 0x9c) != iVar9)
           ) && ((*(char *)((longlong)puVar1 + 0x19) != '\0' &&
                 ((*(char *)((longlong)puVar1 + 0x1a) == '\0' && (*(int *)(puVar1 + 6) != 0)))))) &&
         ((cVar4 == '\0' || (*(char *)((longlong)puVar1 + 0x1b) == '\0')))) {
        lVar10 = 0x118;
        if (param_2 == '\0') {
          lVar10 = 0xa0;
        }
        fVar16 = *(float *)(lVar10 + 8 + (longlong)puVar1);
        fVar12 = (float)((ulonglong)*(undefined8 *)(lVar10 + (longlong)puVar1) >> 0x20);
        fStack_e8 = (float)*(undefined8 *)(lVar10 + (longlong)puVar1);
        fVar13 = fVar12 * _DAT_181b2be8c + fStack_e8 * _DAT_181b2be7c + fVar16 * _DAT_181b2be9c +
                 fVar8;
        if (_DAT_181a03124 <= fVar13) {
          fVar15 = ((fVar12 * _DAT_181b2be80 + fStack_e8 * _DAT_181b2be70 + fVar16 * _DAT_181b2be90
                    + _DAT_181b2bea0) * fVar18) / fVar13 + fVar18;
          fVar16 = fVar19 - ((fVar12 * _DAT_181b2be84 + fStack_e8 * _DAT_181b2be74 +
                              fVar16 * _DAT_181b2be94 + _DAT_181b2bea4) * fVar19) / fVar13;
          if ((fVar2 <= fVar15) && (fVar2 <= fVar16)) {
            fVar13 = _DAT_181b2beb0 - (float)*(undefined8 *)(lVar10 + (longlong)puVar1);
            fVar12 = _DAT_181b2beb8 - *(float *)(lVar10 + 8 + (longlong)puVar1);
            fVar14 = _DAT_181b2beb4 -
                     (float)((ulonglong)*(undefined8 *)(lVar10 + (longlong)puVar1) >> 0x20);
            fVar12 = fVar14 * fVar14 + fVar13 * fVar13 + fVar12 * fVar12;
            if (fVar12 < 0.0) {
              fVar12 = (float)func_0x0001801cb525(fVar12);
            }
            else {
              fVar12 = SQRT(fVar12);
            }
            if ((fVar12 <= fVar6) && (fVar3 < fVar12)) {
              fVar15 = fVar18 - fVar15;
              fVar16 = fVar19 - fVar16;
              fVar16 = fVar16 * fVar16 + fVar15 * fVar15;
              if (fVar16 < 0.0) {
                fVar16 = (float)func_0x0001801cb525(fVar16);
              }
              else {
                fVar16 = SQRT(fVar16);
              }
              if (((param_1 == '\0') || (fVar16 <= fVar5)) && (fVar16 < fVar17)) {
                puVar11 = puVar1 + 3;
                fVar17 = fVar16;
              }
            }
          }
        }
      }
    }
  }
  return puVar11;
}



/* ===== ANALYSIS FUNCTION 0x180072454 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong ** recovered_180072454(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  float fVar4;
  float fVar5;
  char cVar6;
  float fVar7;
  float fVar8;
  longlong **pplVar9;
  float fVar10;
  int iVar11;
  int in_EAX;
  longlong lVar12;
  undefined8 unaff_RBX;
  longlong **pplVar13;
  longlong **unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  longlong in_R11;
  undefined8 unaff_R12;
  char unaff_R13B;
  undefined8 unaff_R14;
  char unaff_R15B;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 unaff_XMM6_Da;
  float fVar17;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  float fVar18;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  float unaff_XMM8_Da;
  undefined4 unaff_XMM9_Da;
  float fVar19;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  float fVar20;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  float fStackX_20;
  
  *(undefined8 *)(in_R11 + 8) = unaff_RBX;
  *(undefined8 *)(in_R11 + 0x10) = unaff_RSI;
  pplVar9 = _DAT_181b2be38;
  *(undefined8 *)(in_R11 + -0x20) = unaff_R12;
  iVar11 = _DAT_181b2bebc;
  *(undefined8 *)(in_R11 + -0x28) = unaff_R14;
  cVar6 = DAT_181b2b406;
  pplVar13 = (longlong **)*pplVar9;
  *(undefined4 *)(in_R11 + -0x68) = unaff_XMM9_Da;
  *(undefined4 *)(in_R11 + -100) = unaff_XMM9_Db;
  *(undefined4 *)(in_R11 + -0x60) = unaff_XMM9_Dc;
  *(undefined4 *)(in_R11 + -0x5c) = unaff_XMM9_Dd;
  *(undefined4 *)(in_R11 + -0x78) = unaff_XMM10_Da;
  *(undefined4 *)(in_R11 + -0x74) = unaff_XMM10_Db;
  *(undefined4 *)(in_R11 + -0x70) = unaff_XMM10_Dc;
  *(undefined4 *)(in_R11 + -0x6c) = unaff_XMM10_Dd;
  fVar8 = _DAT_181b2b63c;
  fVar7 = _DAT_181b2b410;
  fVar20 = (float)in_EAX * _DAT_181a031bc;
  fVar19 = (float)param_3 * _DAT_181a031bc;
  if (pplVar13 != pplVar9) {
    *(undefined8 *)(in_R11 + 0x18) = unaff_RDI;
    auVar3._4_4_ = unaff_XMM11_Db;
    auVar3._0_4_ = unaff_XMM11_Da;
    auVar3._8_4_ = unaff_XMM11_Dc;
    auVar3._12_4_ = unaff_XMM11_Dd;
    *(undefined (*) [16])(in_R11 + -0x88) = auVar3;
    fVar10 = _DAT_181b2beac;
    fVar5 = _DAT_181a032ec;
    fVar4 = _DAT_181a03230;
    auVar1._4_4_ = unaff_XMM6_Db;
    auVar1._0_4_ = unaff_XMM6_Da;
    auVar1._8_4_ = unaff_XMM6_Dc;
    auVar1._12_4_ = unaff_XMM6_Dd;
    *(undefined (*) [16])(in_R11 + -0x38) = auVar1;
    auVar2._4_4_ = unaff_XMM7_Db;
    auVar2._0_4_ = unaff_XMM7_Da;
    auVar2._8_4_ = unaff_XMM7_Dc;
    auVar2._12_4_ = unaff_XMM7_Dd;
    *(undefined (*) [16])(in_R11 + -0x48) = auVar2;
    do {
      if ((((*(int *)((longlong)pplVar13 + 0x9c) != 0) &&
           (*(int *)((longlong)pplVar13 + 0x9c) != iVar11)) &&
          (*(char *)((longlong)pplVar13 + 0x19) != '\0')) &&
         (((*(char *)((longlong)pplVar13 + 0x1a) == '\0' && (*(int *)(pplVar13 + 6) != 0)) &&
          ((cVar6 == '\0' || (*(char *)((longlong)pplVar13 + 0x1b) == '\0')))))) {
        lVar12 = 0x118;
        if (unaff_R13B == '\0') {
          lVar12 = 0xa0;
        }
        fVar18 = *(float *)(lVar12 + 8 + (longlong)pplVar13);
        fVar14 = (float)((ulonglong)*(undefined8 *)(lVar12 + (longlong)pplVar13) >> 0x20);
        fStackX_20 = (float)*(undefined8 *)(lVar12 + (longlong)pplVar13);
        fVar15 = fVar14 * _DAT_181b2be8c + fStackX_20 * _DAT_181b2be7c + fVar18 * _DAT_181b2be9c +
                 fVar10;
        if (_DAT_181a03124 <= fVar15) {
          fVar17 = ((fVar14 * _DAT_181b2be80 + fStackX_20 * _DAT_181b2be70 + fVar18 * _DAT_181b2be90
                    + _DAT_181b2bea0) * fVar19) / fVar15 + fVar19;
          fVar18 = fVar20 - ((fVar14 * _DAT_181b2be84 + fStackX_20 * _DAT_181b2be74 +
                              fVar18 * _DAT_181b2be94 + _DAT_181b2bea4) * fVar20) / fVar15;
          if ((fVar4 <= fVar17) && (fVar4 <= fVar18)) {
            fVar15 = _DAT_181b2beb0 - (float)*(undefined8 *)(lVar12 + (longlong)pplVar13);
            fVar14 = _DAT_181b2beb8 - *(float *)(lVar12 + 8 + (longlong)pplVar13);
            fVar16 = _DAT_181b2beb4 -
                     (float)((ulonglong)*(undefined8 *)(lVar12 + (longlong)pplVar13) >> 0x20);
            fVar14 = fVar16 * fVar16 + fVar15 * fVar15 + fVar14 * fVar14;
            if (fVar14 < 0.0) {
              fVar14 = (float)func_0x0001801cb525(fVar14);
            }
            else {
              fVar14 = SQRT(fVar14);
            }
            if ((fVar14 <= fVar8) && (fVar5 < fVar14)) {
              fVar17 = fVar19 - fVar17;
              fVar18 = fVar20 - fVar18;
              fVar18 = fVar18 * fVar18 + fVar17 * fVar17;
              if (fVar18 < 0.0) {
                fVar18 = (float)func_0x0001801cb525(fVar18);
              }
              else {
                fVar18 = SQRT(fVar18);
              }
              if (((unaff_R15B == '\0') || (fVar18 <= fVar7)) && (fVar18 < unaff_XMM8_Da)) {
                unaff_RBP = pplVar13 + 3;
                unaff_XMM8_Da = fVar18;
              }
            }
          }
        }
      }
      pplVar13 = (longlong **)*pplVar13;
    } while (pplVar13 != pplVar9);
  }
  return unaff_RBP;
}



/* ===== ANALYSIS FUNCTION 0x1800727b0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800727b0(longlong param_1,ulonglong param_2)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  ulonglong uVar12;
  longlong lVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  int iStackX_8;
  undefined4 uStackX_c;
  ulonglong uStackX_10;
  int aiStackX_18 [2];
  int aiStackX_20 [2];
  undefined8 auStack_98 [2];
  undefined8 uStack_88;
  float fStack_80;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  undefined8 uStack_68;
  
  puVar1 = (uint *)(param_1 + 0x84);
  uStackX_10 = param_2 & 0xffffffff00000000;
  uStack_88 = 0;
  fStack_80 = 0.0;
  iStackX_8 = 0;
  aiStackX_18[0] = 0;
  aiStackX_20[0] = 0;
  cVar8 = recovered_180067cc0((ulonglong)*puVar1 + _DAT_181a2b148,auStack_98);
  if ((((((cVar8 != '\0') &&
         (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],&iStackX_8,4), iVar9 == 0)) &&
        (iStackX_8 != 0)) &&
       ((cVar8 = recovered_180067cc0(iStackX_8 + 8,auStack_98), cVar8 != '\0' &&
        (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],aiStackX_18,4), iVar9 == 0)))) &&
      ((aiStackX_18[0] != 0 &&
       ((cVar8 = recovered_180067cc0(aiStackX_18[0] + 8,auStack_98), cVar8 != '\0' &&
        (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],aiStackX_20,4), iVar9 == 0)))))) &&
     ((aiStackX_20[0] != 0 &&
      ((((cVar8 = recovered_180067cc0(aiStackX_20[0] + 0x20,auStack_98), cVar8 != '\0' &&
         (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],&uStackX_10,4), iVar9 == 0)) &&
        ((int)uStackX_10 != 0)) &&
       ((cVar8 = recovered_180067cc0((int)uStackX_10 + 0x60,auStack_98), cVar8 != '\0' &&
        (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],&uStack_88,0xc), iVar9 == 0))))))))
  {
    uVar12 = (((((ulonglong)*(byte *)puVar1 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
               (ulonglong)*(byte *)(param_1 + 0x85)) * 0x100000001b3 ^
              (ulonglong)*(byte *)(param_1 + 0x86)) * 0x100000001b3 ^
             (ulonglong)*(byte *)(param_1 + 0x87)) * 0x100000001b3 & _DAT_181b2f490;
    lVar10 = *(longlong *)(_DAT_181b2f478 + 8 + uVar12 * 0x10);
    lVar13 = 0;
    if (lVar10 != _DAT_181b2f468) {
      uVar2 = *(uint *)(lVar10 + 0x10);
      while ((lVar13 = lVar10, *puVar1 != uVar2 &&
             (lVar13 = 0, lVar10 != *(longlong *)(_DAT_181b2f478 + uVar12 * 0x10)))) {
        lVar10 = *(longlong *)(lVar10 + 8);
        uVar2 = *(uint *)(lVar10 + 0x10);
      }
    }
    lVar10 = _DAT_181b2f468;
    if (lVar13 != 0) {
      lVar10 = lVar13;
    }
    if (lVar10 == _DAT_181b2f468) {
      plVar11 = (longlong *)func_0x000180078d00(0x181b2f460,&uStack_68,puVar1);
      lVar10 = *plVar11;
      if ((undefined8 *)(lVar10 + 0x14) != &uStack_88) {
        *(float *)(undefined8 *)(lVar10 + 0x14) = (float)uStack_88;
        *(float *)(lVar10 + 0x18) = uStack_88._4_4_;
        *(float *)(lVar10 + 0x1c) = fStack_80;
      }
    }
    plVar11 = (longlong *)func_0x000180078d00(0x181b2f460,&uStack_68,puVar1);
    fVar6 = _DAT_181b2be98;
    fVar5 = _DAT_181b2be88;
    fVar16 = _DAT_181b2be78;
    fVar3 = *(float *)(*plVar11 + 0x1c);
    auStack_98[0] = *(undefined8 *)(*plVar11 + 0x14);
    fVar14 = _DAT_181b2be78 * _DAT_181b2be78 + _DAT_181b2be88 * _DAT_181b2be88 +
             _DAT_181b2be98 * _DAT_181b2be98;
    if (fVar14 < 0.0) {
      fVar14 = (float)func_0x0001801cb525(fVar14);
    }
    else {
      fVar14 = SQRT(fVar14);
    }
    fVar4 = _DAT_181a032e0;
    if (_DAT_181a0310c <= fVar14) {
      uStack_68 = _DAT_181b2beb0;
      uVar7 = uStack_68;
      uStack_68._4_4_ = (float)((ulonglong)_DAT_181b2beb0 >> 0x20);
      fVar15 = ((float)uStack_88 - (float)_DAT_181b2beb0) * (fVar16 / fVar14) +
               (uStack_88._4_4_ - uStack_68._4_4_) * (fVar5 / fVar14) +
               (fStack_80 - _DAT_181b2beb8) * (fVar6 / fVar14);
      fStack_78 = (fVar16 / fVar14) * fVar15 + (float)_DAT_181b2beb0;
      fStack_74 = (fVar5 / fVar14) * fVar15 + uStack_68._4_4_;
      fStack_70 = (fVar6 / fVar14) * fVar15 + _DAT_181b2beb8;
      fVar16 = fStack_70 - fVar3;
      uStack_68 = uVar7;
      if (_DAT_181a032e0 < (float)((uint)(fStack_78 - (float)auStack_98[0]) & _DAT_181a039d0)) {
        fStack_78 = (float)copysignf(_DAT_181a032e0);
        fStack_78 = fStack_78 + (float)auStack_98[0];
      }
      if (fVar4 < (float)((uint)fVar16 & _DAT_181a039d0)) {
        fStack_70 = (float)copysignf(fVar4);
        fStack_70 = fStack_70 + fVar3;
      }
      fStack_74 = uStack_88._4_4_;
      cVar8 = recovered_180067cc0((int)uStackX_10 + 0x60,&iStackX_8);
      if (cVar8 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_c,iStackX_8),&fStack_78,0xc);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180072bf0 ===== */

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



/* ===== ANALYSIS FUNCTION 0x180072d7f ===== */

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



/* ===== ANALYSIS FUNCTION 0x1800731b0 ===== */

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



/* ===== ANALYSIS FUNCTION 0x18007326a ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18007326a(void)

{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  longlong *unaff_RSI;
  longlong *plVar8;
  longlong unaff_R14;
  float fVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  undefined4 in_stack_00000030;
  undefined8 uStack0000000000000034;
  longlong in_stack_00000040;
  float in_stack_00000048;
  int in_stack_00000150;
  float fStack0000000000000158;
  float fStack000000000000015c;
  
  fVar5 = _DAT_181b2beb8;
  fVar4 = _DAT_181b2beb4;
  fVar3 = _DAT_181b2b410;
  cVar2 = DAT_181b2b407;
  cVar7 = DAT_181b2b406;
  fVar1 = _DAT_181a03230;
  do {
    if (((*(char *)((longlong)unaff_RBX + 0x1a) == '\0') &&
        ((cVar7 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) &&
       ((cVar2 == '\0' || (*(char *)(unaff_RBX + 3) == '\0')))) {
      plVar8 = unaff_RBX + 0x14;
      recovered_180067e80(&stack0x00000158,&DAT_181b2be70,plVar8,unaff_EBP);
      fVar6 = fStack000000000000015c;
      fVar9 = fStack0000000000000158;
      if ((fVar1 <= fStack0000000000000158) && (fVar1 <= fStack000000000000015c)) {
        in_stack_00000040 = *plVar8;
        fVar13 = _DAT_181b2beb0 - (float)in_stack_00000040;
        fVar12 = fVar5 - *(float *)(plVar8 + 1);
        fVar14 = fVar4 - (float)((ulonglong)in_stack_00000040 >> 0x20);
        fVar12 = fVar14 * fVar14 + fVar13 * fVar13 + fVar12 * fVar12;
        if (fVar12 < 0.0) {
          fVar12 = (float)func_0x0001801cb525(fVar12);
        }
        else {
          fVar12 = SQRT(fVar12);
        }
        if (fVar12 <= (float)_DAT_181b2b40c) {
          dVar10 = (double)func_0x0001801cb507((double)(fVar6 - unaff_XMM11_Da));
          dVar11 = (double)func_0x0001801cb507((double)(fVar9 - unaff_XMM10_Da));
          dVar10 = dVar10 + dVar11;
          if (dVar10 < 0.0) {
            dVar10 = (double)func_0x0001801cb51f(dVar10);
          }
          else {
            dVar10 = SQRT(dVar10);
          }
          fVar9 = (float)dVar10;
          if ((fVar9 <= fVar3) && (fVar9 < unaff_XMM8_Da)) {
            unaff_RSI = unaff_RBX + 3;
            unaff_XMM8_Da = fVar9;
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)unaff_R14);
  if ((unaff_RSI != (longlong *)0x0) && (*(int *)((longlong)unaff_RSI + 0x84) != 0)) {
    in_stack_00000030 = 0;
    uStack0000000000000034 = 0x3f800000;
    in_stack_00000040 =
         CONCAT44(((float)((ulonglong)unaff_RSI[0x11] >> 0x20) + 0.0) - fVar4,
                  ((float)unaff_RSI[0x11] + 0.0) - _DAT_181b2beb0);
    in_stack_00000048 = (*(float *)(unaff_RSI + 0x12) + 0.0) - fVar5;
    func_0x00018006da10(&stack0x00000060,&stack0x00000040,&stack0x00000030);
    cVar7 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,&stack0x00000158);
    if (cVar7 != '\0') {
      (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStack000000000000015c,fStack0000000000000158),
                        &stack0x00000060,0x10);
    }
    in_stack_00000150 =
         recovered_180069360((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x4e8);
    if (in_stack_00000150 != 0) {
      cVar7 = recovered_180067cc0((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x54,
                                  &stack0x00000158);
      if (cVar7 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStack000000000000015c,fStack0000000000000158),
                          &stack0x00000150,4);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180073610 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180073610(void)

{
  float fVar1;
  int iVar2;
  longlong **pplVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  char cVar11;
  short sVar12;
  longlong **pplVar13;
  longlong **pplVar14;
  longlong **pplVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  int aiStackX_8 [2];
  float fStackX_10;
  float fStackX_14;
  
  if ((DAT_181b2b403 != '\0') &&
     (sVar12 = GetAsyncKeyState(_DAT_181b2b414), iVar8 = _DAT_181b2becc, iVar7 = _DAT_181b2bec8,
     fVar6 = _DAT_181b2beb8, fVar5 = _DAT_181b2beb4, fVar4 = _DAT_181b2beb0,
     pplVar3 = _DAT_181b2be38, iVar2 = _DAT_181b2b40c, cVar11 = DAT_181b2b406,
     fVar1 = _DAT_181a03230, sVar12 < 0)) {
    pplVar14 = (longlong **)0x0;
    pplVar13 = (longlong **)*_DAT_181b2be38;
    fVar22 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar21 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    fVar20 = _DAT_181a03460;
    if (pplVar13 != _DAT_181b2be38) {
      do {
        if ((*(char *)((longlong)pplVar13 + 0x1a) == '\0') &&
           ((cVar11 == '\0' || (*(char *)((longlong)pplVar13 + 0x1b) == '\0')))) {
          pplVar15 = pplVar13 + 0x14;
          recovered_180067e80(&fStackX_10,&DAT_181b2be70,pplVar15,iVar7,iVar8);
          fVar10 = fStackX_14;
          fVar9 = fStackX_10;
          if ((fVar1 <= fStackX_10) && (fVar1 <= fStackX_14)) {
            fVar18 = fVar4 - SUB84(*pplVar15,0);
            fVar19 = fVar5 - (float)((ulonglong)*pplVar15 >> 0x20);
            fVar18 = fVar19 * fVar19 + fVar18 * fVar18 +
                     (fVar6 - *(float *)(pplVar15 + 1)) * (fVar6 - *(float *)(pplVar15 + 1));
            if (fVar18 < 0.0) {
              fVar18 = (float)func_0x0001801cb525(fVar18);
            }
            else {
              fVar18 = SQRT(fVar18);
            }
            if (fVar18 <= (float)iVar2) {
              dVar16 = (double)func_0x0001801cb507((double)(fVar10 - fVar22));
              dVar17 = (double)func_0x0001801cb507((double)(fVar9 - fVar21));
              dVar16 = dVar16 + dVar17;
              if (dVar16 < 0.0) {
                dVar16 = (double)func_0x0001801cb51f(dVar16);
              }
              else {
                dVar16 = SQRT(dVar16);
              }
              if ((float)dVar16 < fVar20) {
                pplVar14 = pplVar13 + 3;
                fVar20 = (float)dVar16;
              }
            }
          }
        }
        pplVar13 = (longlong **)*pplVar13;
      } while (pplVar13 != pplVar3);
      if ((((pplVar14 != (longlong **)0x0) && (*(uint *)((longlong)pplVar14 + 0x84) != 0)) &&
          (aiStackX_8[0] =
                recovered_180069360((ulonglong)*(uint *)((longlong)pplVar14 + 0x84) + 0x4e8),
          aiStackX_8[0] != 0)) &&
         (cVar11 = recovered_180067cc0((ulonglong)*(uint *)((longlong)pplVar14 + 0x84) + 0x54,
                                       &fStackX_10), cVar11 != '\0')) {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStackX_14,fStackX_10),aiStackX_8,4);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800736cb ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800736cb(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  char cVar8;
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  longlong *unaff_RSI;
  longlong *plVar9;
  longlong unaff_R14;
  double dVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  int in_stack_00000120;
  float fStack0000000000000128;
  float fStack000000000000012c;
  
  fVar5 = _DAT_181b2beb8;
  fVar4 = _DAT_181b2beb4;
  fVar3 = _DAT_181b2beb0;
  iVar2 = _DAT_181b2b40c;
  cVar8 = DAT_181b2b406;
  fVar1 = _DAT_181a03230;
  do {
    if ((*(char *)((longlong)unaff_RBX + 0x1a) == '\0') &&
       ((cVar8 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) {
      plVar9 = unaff_RBX + 0x14;
      recovered_180067e80(&stack0x00000128,&DAT_181b2be70,plVar9,unaff_EBP);
      fVar7 = fStack000000000000012c;
      fVar6 = fStack0000000000000128;
      if ((fVar1 <= fStack0000000000000128) && (fVar1 <= fStack000000000000012c)) {
        fVar12 = fVar3 - (float)*plVar9;
        fVar13 = fVar4 - (float)((ulonglong)*plVar9 >> 0x20);
        fVar12 = fVar13 * fVar13 + fVar12 * fVar12 +
                 (fVar5 - *(float *)(plVar9 + 1)) * (fVar5 - *(float *)(plVar9 + 1));
        if (fVar12 < 0.0) {
          fVar12 = (float)func_0x0001801cb525(fVar12);
        }
        else {
          fVar12 = SQRT(fVar12);
        }
        if (fVar12 <= (float)iVar2) {
          dVar10 = (double)func_0x0001801cb507((double)(fVar7 - unaff_XMM11_Da));
          dVar11 = (double)func_0x0001801cb507((double)(fVar6 - unaff_XMM10_Da));
          dVar10 = dVar10 + dVar11;
          if (dVar10 < 0.0) {
            dVar10 = (double)func_0x0001801cb51f(dVar10);
          }
          else {
            dVar10 = SQRT(dVar10);
          }
          if ((float)dVar10 < unaff_XMM8_Da) {
            unaff_RSI = unaff_RBX + 3;
            unaff_XMM8_Da = (float)dVar10;
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)unaff_R14);
  if ((unaff_RSI != (longlong *)0x0) && (*(uint *)((longlong)unaff_RSI + 0x84) != 0)) {
    in_stack_00000120 =
         recovered_180069360((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x4e8);
    if (in_stack_00000120 != 0) {
      cVar8 = recovered_180067cc0((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x54,
                                  &stack0x00000128);
      if (cVar8 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStack000000000000012c,fStack0000000000000128),
                          &stack0x00000120,4);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180073970 ===== */

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



/* ===== ANALYSIS FUNCTION 0x180073bf4 ===== */

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



/* ===== ANALYSIS FUNCTION 0x180073f10 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180073f10(void)

{
  uint uVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  float fVar5;
  undefined auVar6 [16];
  uint *puVar7;
  undefined8 *puVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined8 *puVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined8 uVar18;
  uint *puVar19;
  undefined4 *puVar20;
  int *piVar21;
  undefined8 *puVar22;
  int iVar23;
  ulonglong uVar24;
  uint *puVar25;
  longlong lVar26;
  undefined8 *puVar27;
  ulonglong uVar28;
  undefined8 *puVar29;
  ulonglong unaff_R15;
  longlong unaff_GS_OFFSET;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  undefined4 uVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  undefined8 uStackX_8;
  undefined4 uStackX_10;
  undefined4 uStackX_14;
  uint uStackX_18;
  undefined4 uStackX_1c;
  undefined8 uStackX_20;
  undefined8 uStack_1c8;
  float fStack_1c0;
  undefined8 uStack_1b8;
  float fStack_1b0;
  int iStack_1a8;
  undefined4 uStack_1a4;
  undefined8 uStack_198;
  float fStack_190;
  float fStack_188;
  undefined4 uStack_184;
  undefined8 uStack_178;
  undefined4 uStack_170;
  undefined auStack_168 [8];
  undefined8 uStack_160;
  uint *puStack_158;
  uint *puStack_150;
  uint *puStack_148;
  uint uStack_140;
  int iStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined auStack_128 [8];
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined auStack_118 [8];
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined auStack_108 [8];
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined auStack_f8 [8];
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float afStack_e0 [4];
  undefined auStack_d0 [152];
  
  puVar29 = (undefined8 *)0x0;
  DAT_181b2bec4 = 0;
  if ((DAT_181b2bede != '\0') &&
     (recovered_180067b80(&uStackX_8), uVar24 = uStackX_8,
     1999999999 < (longlong)(uStackX_8 - _DAT_181b2f4e0))) {
    recovered_18006e930();
    _DAT_181b2f4e0 = uVar24;
  }
  if (DAT_181b2bedd != '\0') {
    recovered_18006e930();
  }
  uVar1 = __tls_index;
  if (DAT_181b2bc70 != '\0') {
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8)
                 + 4) < _DAT_181b50884) &&
       (func_0x000180127a18(&DAT_181b50884), _DAT_181b50884 == -1)) {
      recovered_180067b80(&DAT_181b50920);
      func_0x0001801279ac(&DAT_181b50884);
    }
    recovered_180067b80(&uStackX_8);
    uVar24 = uStackX_8;
    if (29999999999 < (longlong)(uStackX_8 - _DAT_181b50920)) {
      if (0x400 < _DAT_181b2bf30) {
        recovered_180069a10(&DAT_181b2bf20);
      }
      _DAT_181b50920 = uVar24;
    }
  }
  if (_DAT_181b4efd8 == 0) {
    return;
  }
  iVar10 = recovered_180069360(_DAT_181b4efd8 + 0xa342efc);
  if (iVar10 == 0) {
    recovered_18006f2b0();
    return;
  }
  uVar11 = recovered_180069360(iVar10);
  if (uVar11 == 0) {
    recovered_18006f2b0();
    return;
  }
  iVar10 = recovered_180069360((ulonglong)uVar11 + 0x5c);
  if (iVar10 == 0) {
    recovered_18006f2b0();
    return;
  }
  uVar11 = recovered_180069360(iVar10);
  uVar24 = (ulonglong)uVar11;
  if (uVar11 == 0) {
    recovered_18006f2b0();
    return;
  }
  uVar11 = recovered_180069360(uVar24 + 0x50);
  iVar10 = 0;
  if (uVar11 != 0) {
    iVar10 = recovered_180069360((ulonglong)uVar11 + 0x8c);
  }
  if (DAT_181b2b581 == '\0') {
LAB_1800741b0:
    _DAT_181b302f8 = 0;
    _DAT_181b302fc = 0;
    DAT_181b302fa = '\0';
LAB_1800741c7:
    if (uVar11 == 0) {
      recovered_18006f2b0();
      return;
    }
    if (iVar10 == 0) {
      recovered_18006f2b0();
      return;
    }
    if (iVar10 != 1) {
      recovered_18006f2b0();
      return;
    }
  }
  else {
    if ((uVar11 == 0) || (iVar10 != 1)) {
      recovered_180067b80(&uStackX_8);
      if (DAT_181b302fa == '\0') {
        DAT_181b302fa = '\x01';
        _DAT_181b30308 = uStackX_8;
      }
      else if (1999999999 < (longlong)(uStackX_8 - _DAT_181b30308)) goto LAB_1800741b0;
      goto LAB_1800741c7;
    }
    DAT_181b302fa = '\0';
    if (uVar11 == _DAT_181b302fc) {
      if (((DAT_181b302f8 != '\0') && (DAT_181b302f9 == '\0')) &&
         (iVar10 = recovered_1800705d0(), iVar10 < 1)) {
        _DAT_181b302f8 = CONCAT11(1,DAT_181b302f8);
      }
    }
    else {
      _DAT_181b302fc = uVar11;
      puVar15 = (undefined8 *)recovered_180067b80(&uStackX_8);
      _DAT_181b30300 = *puVar15;
      _DAT_181b302f8 = 1;
      DAT_181b302fa = '\0';
    }
  }
  uVar12 = recovered_180069360((ulonglong)uVar11 + 0x94);
  uStackX_18 = uVar12;
  if (uVar12 == 0) {
LAB_18007421a:
    iVar10 = recovered_180069360(uVar11 + 0xb4);
    if (iVar10 != 0) goto LAB_180074229;
LAB_180074247:
    uStackX_20 = (uint *)CONCAT44(uStackX_20._4_4_,uVar12);
    uVar14 = uStackX_18;
    uVar11 = uVar12;
    if (uVar12 == 0) {
      return;
    }
  }
  else {
    iVar10 = recovered_180069360(uVar12 + 0xb4);
    if (iVar10 == 0) goto LAB_18007421a;
LAB_180074229:
    uVar11 = recovered_180069360(iVar10 + 0x28);
    uStackX_20 = (uint *)CONCAT44(uStackX_20._4_4_,uVar11);
    uVar14 = uVar11;
    if (uVar11 == 0) goto LAB_180074247;
  }
  uStackX_18 = uVar14;
  uVar28 = (ulonglong)uVar11;
  _DAT_181b2bebc = uVar11;
  if (DAT_181b2b5ef == '\0') {
    if (DAT_181b4efd3 != '\0') {
      LOCK();
      DAT_181b2f6d8 = 0;
      UNLOCK();
      DAT_181b2b5ef = '\0';
      DAT_181b4efd3 = '\0';
    }
  }
  else if (DAT_181b4efd3 == '\0') {
    recovered_18006f9b0();
    DAT_181b4efd3 = '\x01';
  }
  if (DAT_181b2b5fc == '\0') {
    if (_DAT_181b30314 != 0) {
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b30314 + 0x24,&uStackX_10);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_14,uStackX_10),&UNK_1819d7950,4);
      }
      _DAT_181b30314 = 0;
    }
  }
  else {
    uStackX_8 = uStackX_8 & 0xffffffff00000000;
    cVar9 = recovered_180067cc0(uVar24 + 0x10,&uStackX_10);
    if ((cVar9 != '\0') &&
       (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_14,uStackX_10),&uStackX_8,4),
       iVar10 == 0)) {
      if ((float)uStackX_8 != 0.0) {
        _DAT_181b30314 = (uint)(float)uStackX_8;
        cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x24,&uStackX_10);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_14,uStackX_10),&UNK_1819d7910,4);
        }
      }
    }
  }
  uStack_1c8 = uVar28;
  iVar10 = recovered_180069360(uVar28 + 0x28c);
  if (iVar10 == 0) {
    return;
  }
  uStack_178 = 0;
  uStack_170 = 0;
  recovered_18006bd40(iVar10,&uStack_178);
  _DAT_181b2beb0 = (undefined4)uStack_178;
  _DAT_181b2beb4 = uStack_178._4_4_;
  _DAT_181b2beb8 = uStack_170;
  uVar12 = recovered_180069360(uVar28 + 0x494);
  if (uVar12 == 0) {
    return;
  }
  iVar10 = recovered_180069360((ulonglong)uVar12 + 0x18);
  if (iVar10 == 0) {
    return;
  }
  uVar12 = recovered_180069360(iVar10 + 8);
  if (uVar12 == 0) {
    return;
  }
  _auStack_128 = ZEXT816(0);
  _auStack_118 = ZEXT816(0);
  _auStack_f8 = ZEXT816(0);
  _auStack_108 = _auStack_128;
  cVar9 = recovered_180067cc0((ulonglong)uVar12 + 0xe8,&uStackX_8);
  if (cVar9 == '\0') {
    if (_DAT_181b4ef90 == 0) {
      uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                   &UNK_1819d77a0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar18,&DAT_180069ca0);
    }
  }
  else {
    (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,auStack_128,0x40);
  }
  lVar17 = _DAT_181b2bde0;
  DAT_181b2bec4 = '\x01';
  _DAT_181b2be70 = auStack_128._0_4_;
  _DAT_181b2be74 = auStack_128._4_4_;
  _DAT_181b2be78 = uStack_120;
  _DAT_181b2be7c = uStack_11c;
  _DAT_181b2be80 = auStack_118._0_4_;
  _DAT_181b2be84 = auStack_118._4_4_;
  _DAT_181b2be88 = uStack_110;
  _DAT_181b2be8c = uStack_10c;
  _DAT_181b2be90 = auStack_108._0_4_;
  _DAT_181b2be94 = auStack_108._4_4_;
  _DAT_181b2be98 = uStack_100;
  _DAT_181b2be9c = uStack_fc;
  _DAT_181b2bea0 = auStack_f8._0_4_;
  _DAT_181b2bea4 = auStack_f8._4_4_;
  uRam0000000181b2bea8 = uStack_f0;
  _DAT_181b2beac = uStack_ec;
  if (DAT_181b2bdd0 == '\0') {
    lVar26 = _DAT_181b2bdd8;
    uVar11 = uStackX_18;
    if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
      do {
        recovered_180066e40(lVar26 + 0x10);
        uVar11 = uStackX_18;
        lVar26 = lVar26 + 0x38;
      } while (lVar26 != lVar17);
      uVar33 = (uint)uStackX_20;
      _DAT_181b2bde0 = _DAT_181b2bdd8;
      uStackX_18 = uVar11;
      if (_DAT_181b2bdd8 != _DAT_181b2bde8) {
        recovered_180066d80(&DAT_181b2bdd8);
        uStackX_20 = (uint *)CONCAT44(uStackX_20._4_4_,uVar33);
        uStackX_18 = uVar11;
      }
    }
  }
  else {
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)uVar1 * 8) + 4) <
         _DAT_181b508d0) && (func_0x000180127a18(&DAT_181b508d0), _DAT_181b508d0 == -1)) {
      recovered_180067b80(&DAT_181b50830);
      func_0x0001801279ac(&DAT_181b508d0);
    }
    recovered_180067b80(&uStackX_8);
    uVar28 = uStackX_8;
    if (299999999 < (longlong)(uStackX_8 - _DAT_181b50830)) {
      recovered_18008c0f0(uVar24,&uStack_178);
      _DAT_181b50830 = uVar28;
    }
  }
  recovered_180067b80(&uStackX_8);
  if ((_DAT_181b4efc0 == 0) || (32999999 < (longlong)(uStackX_8 - _DAT_181b4efc0))) {
    uStackX_10 = CONCAT31(uStackX_10._1_3_,1);
    _DAT_181b4efc0 = uStackX_8;
  }
  else {
    uStackX_10 = (uint)uStackX_10._1_3_ << 8;
  }
  iVar10 = recovered_180069360(uVar24 + 0x68);
  if (iVar10 == 0) {
    recovered_18006f2b0();
    return;
  }
  iStack_13c = recovered_180069360(iVar10 + 0xc);
  if (iStack_13c == 0) {
    recovered_18006f2b0();
    return;
  }
  iStack_13c = iStack_13c + 0x1c;
  uVar13 = recovered_180069360(iVar10 + 0x10);
  uVar12 = _DAT_181b2bec0;
  uVar14 = _DAT_181b302f4;
  uStack_140 = uVar13;
  bVar4 = false;
  if (uVar13 != _DAT_181b2bec0) {
    iVar23 = uVar13 - _DAT_181b2bec0;
    iVar10 = -iVar23;
    if (0 < iVar23) {
      iVar10 = iVar23;
    }
    uVar12 = uVar13;
    uVar14 = uVar11;
    if ((5 < iVar10) || (bVar4 = false, _DAT_181b302f4 != uVar11)) {
      bVar4 = true;
      recovered_180078290(0x181b2be30);
      recovered_180069a10(&DAT_181b2bf20);
    }
  }
  _DAT_181b302f4 = uVar14;
  _DAT_181b2bec0 = uVar12;
  if (uVar13 == 0) {
    recovered_180073970();
    recovered_180073610();
    recovered_1800731b0();
    recovered_180070fd0();
    recovered_180072bf0();
    return;
  }
  if (DAT_181b2f2b9 == '\0') {
    LOCK();
    DAT_181b2f2b9 = '\x01';
    UNLOCK();
    uStackX_8 = func_0x000180127a94(1);
    auStack_168 = (undefined  [8])_beginthreadex(0,0,&DAT_18006a9f0,uStackX_8,0,&uStack_160);
    uVar33 = (undefined4)((ulonglong)uStack_160 >> 0x20);
    if (auStack_168 != (undefined  [8])0x0) {
      if (_DAT_181b2f458 != 0) {
        terminate();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar30 = SUB84(auStack_168,0);
      uVar32 = (undefined4)((ulonglong)auStack_168 >> 0x20);
      iVar10 = (int)uStack_160;
      _DAT_181b2f450 = _auStack_168;
      if (iVar10 == 0) {
        _auStack_168 = ZEXT816(0);
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      auStack_168._4_4_ = uVar32;
      auStack_168._0_4_ = uVar30;
      uStack_160._0_4_ = iVar10;
      uStack_160._4_4_ = uVar33;
      iVar10 = _Thrd_detach(auStack_168);
      if (iVar10 != 0) {
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      _DAT_181b2f450 = ZEXT816(0);
      goto LAB_1800747f8;
    }
    _auStack_168 = ZEXT812(0);
    uStack_160._4_4_ = uVar33;
    __Throw_Cpp_error_std__YAXH_Z(6);
LAB_1800748b4:
    if (_DAT_181b4ef90 == 0) {
      uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                   &UNK_1819d77a0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar18,&DAT_180069ca0);
    }
  }
  else {
LAB_1800747f8:
    puVar15 = _DAT_181b2f4e8;
    if (bVar4) {
      cVar9 = *(char *)((longlong)(longlong *)_DAT_181b2f4e8[1] + 0x19);
      plVar16 = (longlong *)_DAT_181b2f4e8[1];
      while (cVar9 == '\0') {
        func_0x000180023e30(&DAT_181b2f4e8,&DAT_181b2f4e8,plVar16[2]);
        plVar2 = (longlong *)*plVar16;
        func_0x000180127e40(plVar16,0x28);
        plVar16 = plVar2;
        cVar9 = *(char *)((longlong)plVar2 + 0x19);
      }
      puVar15[1] = puVar15;
      *puVar15 = puVar15;
      puVar15[2] = puVar15;
      _DAT_181b2f4f0 = 0;
    }
    unaff_R15 = uStack_1c8;
    if (DAT_181b2b400 == '\0') goto LAB_180074a27;
    uStackX_8 = 0;
    cVar9 = recovered_180067cc0(uStack_1c8 + 0x434,&uStack_1c8);
    if (cVar9 == '\0') goto LAB_1800748b4;
    (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,8);
  }
  uVar24 = uStackX_8;
  if (uStackX_8 != 0) {
    uStackX_8 = 0;
    cVar9 = recovered_180067cc0(uVar24 + 0x58,&uStack_1c8);
    if (cVar9 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                     &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar18,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,8);
    }
    uVar24 = uStackX_8;
    if (uStackX_8 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0xc,&uStack_1c8);
      if (cVar9 == '\0') {
        if (_DAT_181b4ef90 == 0) {
          uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                       ,&UNK_1819d77a0);
          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                    (uVar18,&DAT_180069ca0);
        }
      }
      else {
        (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
      }
      if ((float)uStackX_8 != 0.0) {
        uStackX_8 = uStackX_8 & 0xffffffff00000000;
        cVar9 = recovered_180067cc0(uVar24 + 0xc,&uStack_1c8);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
        }
      }
    }
  }
LAB_180074a27:
  lVar17 = unaff_R15 + 0x500;
  if (DAT_181b2b5c0 == '\0') {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffffffffff00;
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xc1,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  else {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = CONCAT71(uStackX_8._1_7_,1);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xc1,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  if (DAT_181b2bc68 == '\0') {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffffffffff00;
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xe0,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  else {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = CONCAT71(uStackX_8._1_7_,1);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xe0,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  if (DAT_181b2b5e9 == '\0') {
    uVar11 = recovered_180069360(lVar17);
    fVar40 = _DAT_181a03230;
    if (uVar11 != 0) {
      uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3f800000);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + _DAT_181b2bf68,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
      }
    }
  }
  else {
    uVar11 = recovered_180069360(lVar17);
    fVar40 = _DAT_181a03230;
    if (uVar11 != 0) {
      uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3e99999a);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + _DAT_181b2bf68,&uStack_1c8);
      fVar40 = _DAT_181a03230;
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
        fVar40 = _DAT_181a03230;
      }
    }
  }
  lVar26 = *(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)uVar1 * 8);
  if ((*(int *)(lVar26 + 4) < _DAT_181b50880) &&
     (func_0x000180127a18(&DAT_181b50880), _DAT_181b50880 == -1)) {
    recovered_180077f30(&DAT_181b50890);
    func_0x000180127e28(&DAT_1801d07a0);
    func_0x0001801279ac(&DAT_181b50880);
  }
  if ((*(int *)(lVar26 + 4) < _DAT_181b508d4) &&
     (func_0x000180127a18(&DAT_181b508d4), _DAT_181b508d4 == -1)) {
    recovered_180077f30(0x181b508e0);
    func_0x000180127e28(&DAT_1801d0780);
    func_0x0001801279ac(&DAT_181b508d4);
  }
  if ((*(int *)(lVar26 + 4) < _DAT_181b50838) &&
     (func_0x000180127a18(&DAT_181b50838), _DAT_181b50838 == -1)) {
    recovered_180077f30(0x181b50840);
    func_0x000180127e28(&DAT_1801d0760);
    func_0x0001801279ac(&DAT_181b50838);
  }
  if (DAT_181b2b5f4 == '\0') {
    if (_DAT_181b4efb8 != 0) {
      uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
      cVar9 = recovered_180067cc0(lVar17,&uStack_1c8);
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), iVar10 == 0)) {
        if ((float)uStackX_8 != 0.0) {
          fStack_188 = 1.0;
          cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x1d8,&uStack_1c8);
          if (((cVar9 != '\0') &&
              (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&fStack_188,4), iVar10 == 0)) &&
             (_DAT_181a03114 < (float)((uint)(fStack_188 - fVar40) & _DAT_181a039d0))) {
            uVar24 = ((((uStackX_8 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       uStackX_8 >> 8 & 0xff) * 0x100000001b3 ^ uStackX_8 >> 0x10 & 0xff) *
                      0x100000001b3 ^ uStackX_8 >> 0x18 & 0xff) * 0x100000001b3 & _DAT_181b508c0;
            puVar15 = *(undefined8 **)(_DAT_181b508a8 + 8 + uVar24 * 0x10);
            puVar22 = puVar29;
            if (puVar15 != _DAT_181b50898) {
              for (; (puVar22 = puVar15, (float)uStackX_8 != (float)*(int *)(puVar15 + 2) &&
                     (puVar22 = puVar29, puVar15 != *(undefined8 **)(_DAT_181b508a8 + uVar24 * 0x10)
                     )); puVar15 = (undefined8 *)puVar15[1]) {
              }
            }
            puVar15 = _DAT_181b50898;
            if (puVar22 != (undefined8 *)0x0) {
              puVar15 = puVar22;
            }
            lVar17 = (uStackX_8 & 0xffffffff) + 0x1d8;
            if (puVar15 == _DAT_181b50898) {
              uStack_1c8 = CONCAT44(uStack_1c8._4_4_,0x3f800000);
              cVar9 = recovered_180067cc0(lVar17,&iStack_1a8);
              if (cVar9 != '\0') {
                (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStack_1c8,4);
              }
            }
            else {
              cVar9 = recovered_180067cc0(lVar17,&uStack_1c8);
              if (cVar9 != '\0') {
                (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,(longlong)puVar15 + 0x14,4);
              }
            }
          }
        }
      }
    }
    _DAT_181b4efb8 = 0;
    fVar31 = _DAT_181b4efb0;
  }
  else {
    if (DAT_181b2b5f5 == '\0') {
      DAT_181b2b5f5 = '\x01';
    }
    uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
    cVar9 = recovered_180067cc0(lVar17,&uStack_1c8);
    fVar31 = _DAT_181b4efb0;
    if (((cVar9 != '\0') &&
        (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), fVar31 = _DAT_181b4efb0
        , iVar10 == 0)) && ((float)uStackX_8 != 0.0)) {
      if ((_DAT_181b4efb8 != 0) && ((float)_DAT_181b4efb8 != (float)uStackX_8)) {
        recovered_180077e30(&DAT_181b50890);
        recovered_180077e30(0x181b508e0);
        recovered_180077e30(0x181b50840);
        _DAT_181b4efb0 = 0.0;
      }
      fVar36 = _DAT_181a033a0;
      fVar35 = (_DAT_181b2b5f8 - fVar40) * _DAT_181a033a0;
      fStack_188 = 1.0;
      _DAT_181b4efb8 = (uint)(float)uStackX_8;
      cVar9 = recovered_180067cc0((ulonglong)(uint)(float)uStackX_8 + 0x1d8,&uStack_1c8);
      fVar31 = _DAT_181b4efb0;
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&fStack_188,4), fVar5 = fStack_188,
         fVar31 = _DAT_181b4efb0, iVar10 == 0)) {
        uVar24 = ((((uStackX_8 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^ uStackX_8 >> 8 & 0xff)
                   * 0x100000001b3 ^ uStackX_8 >> 0x10 & 0xff) * 0x100000001b3 ^
                 uStackX_8 >> 0x18 & 0xff) * 0x100000001b3 & _DAT_181b508c0;
        puVar15 = *(undefined8 **)(_DAT_181b508a8 + 8 + uVar24 * 0x10);
        puVar22 = puVar29;
        if (puVar15 != _DAT_181b50898) {
          for (; (puVar22 = puVar15, (float)uStackX_8 != (float)*(int *)(puVar15 + 2) &&
                 (puVar22 = puVar29, puVar15 != *(undefined8 **)(_DAT_181b508a8 + uVar24 * 0x10)));
              puVar15 = (undefined8 *)puVar15[1]) {
          }
        }
        puVar15 = _DAT_181b50898;
        if (puVar22 != (undefined8 *)0x0) {
          puVar15 = puVar22;
        }
        uVar18 = extraout_XMM0_Qa;
        if (puVar15 == _DAT_181b50898) {
          plVar16 = (longlong *)recovered_180078a40(puVar22,&uStack_138,&uStackX_8);
          *(float *)(*plVar16 + 0x14) = fVar5;
          uVar18 = extraout_XMM0_Qa_00;
        }
        plVar16 = (longlong *)recovered_180078a40(uVar18,&uStack_138,&uStackX_8);
        fVar31 = (fVar35 / fVar36) * _DAT_181a031ec + *(float *)(*plVar16 + 0x14);
        uStack_1c8 = CONCAT44(uStack_1c8._4_4_,fVar31);
        if (((_DAT_181a03114 < (float)((uint)(fStack_188 - fVar31) & _DAT_181a039d0)) ||
            (fVar31 = _DAT_181b4efb0,
            _DAT_181a03114 < (float)((uint)(_DAT_181b4efb0 - fVar35) & _DAT_181a039d0))) &&
           (cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x1d8,&iStack_1a8),
           fVar31 = fVar35, cVar9 != '\0')) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStack_1c8,4);
        }
      }
    }
  }
  _DAT_181b4efb0 = fVar31;
  uVar1 = uStackX_18;
  recovered_180071ae0(uStackX_18);
  if (DAT_181b2b630 == '\0') {
    if (_DAT_181b2f470 != 0) {
      recovered_1800721a0();
    }
    plVar16 = (longlong *)recovered_180067b80(&uStackX_18);
    _DAT_181b302e0 = *plVar16;
  }
  else {
    iVar10 = 6;
    if (0 < _DAT_181b2b638) {
      iVar10 = _DAT_181b2b638;
    }
    recovered_180067b80(&uStackX_18);
    lVar17 = CONCAT44(uStackX_1c,uStackX_18);
    if ((((longlong)iVar10 * 1000000 <= lVar17 - _DAT_181b302e0) &&
        (_DAT_181b302e0 = lVar17, 0 < _DAT_181b2bec8)) &&
       ((0 < _DAT_181b2becc && ((DAT_181b2bec4 != '\0' && (uVar1 != 0)))))) {
      uStackX_8 = uStackX_8 & 0xffffffffffffff00;
      cVar9 = recovered_180067cc0(_DAT_181b50778 + unaff_R15,&uStackX_18);
      if ((cVar9 == '\0') ||
         ((iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,1),
          iVar10 != 0 || ((char)uStackX_8 == '\0')))) {
        recovered_1800721a0();
      }
      else {
        lVar17 = recovered_180072400(_DAT_181b2b634 == 1,_DAT_181b2b634 == 1);
        if (lVar17 == 0) {
          recovered_1800721a0();
        }
        else {
          recovered_1800727b0(lVar17);
        }
      }
    }
  }
  if (DAT_181b2b60d == '\0') {
    if (((DAT_181b4efc9 != '\0') && (DAT_181b4efe0 != '\0')) && (_DAT_181b2bebc != 0)) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_18);
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4),
         iVar10 == 0)) {
        if (((float)uStackX_8 != 0.0) &&
           (cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 100,&uStackX_18), cVar9 != '\0'))
        {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&DAT_181b4efd4,4);
        }
      }
    }
    DAT_181b4efc9 = '\0';
    DAT_181b4efe0 = '\0';
    fVar36 = _DAT_181a03364;
    fVar31 = _DAT_181a03124;
  }
  else {
    fVar36 = _DAT_181a03364;
    fVar31 = _DAT_181a03124;
    if (_DAT_181b2bebc != 0) {
      uStackX_18 = 0;
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_8);
      fVar36 = _DAT_181a03364;
      fVar31 = _DAT_181a03124;
      if (((cVar9 != '\0') &&
          (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,&uStackX_18,4),
          fVar36 = _DAT_181a03364, fVar31 = _DAT_181a03124, iVar10 == 0)) && (uStackX_18 != 0)) {
        if (DAT_181b4efe0 == '\0') {
          uStackX_8 = uStackX_8 & 0xffffffff00000000;
          cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 100,&iStack_1a8);
          if ((cVar9 != '\0') &&
             (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_8,4
                                        ), iVar10 == 0)) {
            _DAT_181b4efd4 = (float)uStackX_8;
            if ((DAT_181b4efc9 != '\0') &&
               (_DAT_181a03124 < (float)((uint)_DAT_181b4efcc & _DAT_181a039d0))) {
              _DAT_181b4efd4 =
                   (float)uStackX_8 -
                   (_DAT_181b4efcc / _DAT_181a03364 + _DAT_181b4efcc / _DAT_181a03364);
            }
            DAT_181b4efe0 = '\x01';
            DAT_181b4efc9 = '\x01';
          }
        }
        fVar36 = _DAT_181a03364;
        fVar31 = _DAT_181a03124;
        uStack_1c8 = CONCAT44(uStack_1c8._4_4_,
                              _DAT_181b2b610 / _DAT_181a03364 + _DAT_181b2b610 / _DAT_181a03364 +
                              _DAT_181b4efd4);
        cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 100,&uStackX_8);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_8,&uStack_1c8,4);
        }
        _DAT_181b4efcc = _DAT_181b2b610;
      }
    }
  }
  if (DAT_181b2b614 == '\0') {
    if (((DAT_181b4efc8 != '\0') && (DAT_181b4efd0 != '\0')) && (_DAT_181b2bebc != 0)) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_18);
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4),
         iVar10 == 0)) {
        if (((float)uStackX_8 != 0.0) &&
           (cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x68,&uStackX_18), cVar9 != '\0')
           ) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&DAT_181b4efe4,4);
        }
      }
    }
    DAT_181b4efc8 = '\0';
    DAT_181b4efd0 = '\0';
  }
  else if (_DAT_181b2bebc != 0) {
    uStackX_18 = 0;
    cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_8);
    if (((cVar9 != '\0') &&
        (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,&uStackX_18,4), iVar10 == 0)) &&
       (uStackX_18 != 0)) {
      if (DAT_181b4efd0 == '\0') {
        uStackX_8 = uStackX_8 & 0xffffffff00000000;
        cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 0x68,&iStack_1a8);
        if ((cVar9 != '\0') &&
           (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_8,4),
           iVar10 == 0)) {
          _DAT_181b4efe4 = (float)uStackX_8;
          if ((DAT_181b4efc8 != '\0') && (fVar31 < (float)((uint)_DAT_181b4efb4 & _DAT_181a039d0)))
          {
            _DAT_181b4efe4 = (float)uStackX_8 - (_DAT_181b4efb4 / fVar36 + _DAT_181b4efb4 / fVar36);
          }
          DAT_181b4efd0 = '\x01';
          DAT_181b4efc8 = '\x01';
        }
      }
      uStack_1c8 = CONCAT44(uStack_1c8._4_4_,
                            _DAT_181b2b618 / fVar36 + _DAT_181b2b618 / fVar36 + _DAT_181b4efe4);
      cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 0x68,&uStackX_8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_8,&uStack_1c8,4);
      }
      _DAT_181b4efb4 = _DAT_181b2b618;
    }
  }
  uStackX_18 = 0x42960000;
  uStack_1c8 = uStack_1c8 & 0xffffffff00000000;
  uStackX_8 = uStackX_8 & 0xffffffff00000000;
  cVar9 = recovered_180067cc0(unaff_R15 + 0x494,&iStack_1a8);
  if ((cVar9 != '\0') &&
     (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_8,4),
     iVar10 == 0)) {
    if ((float)uStackX_8 != 0.0) {
      if (DAT_181b2b60c == '\0') {
        if (DAT_181b4efca != '\0') {
          cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x48,&iStack_1a8);
          if (cVar9 != '\0') {
            (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStack_1c8,4);
          }
          DAT_181b4efca = '\0';
        }
      }
      else {
        cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x48,&iStack_1a8);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_18,4);
        }
        DAT_181b4efca = '\x01';
      }
    }
  }
  if (DAT_181b2b5f3 != '\0') {
    uStackX_8 = 0;
    cVar9 = recovered_180067cc0(unaff_R15 + 0x434,&uStackX_18);
    if (cVar9 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                     &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar18,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,8);
    }
    uVar24 = uStackX_8;
    if (uStackX_8 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x43c,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x44,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x444,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x448,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = 0;
      cVar9 = recovered_180067cc0(uVar24 + 0x58,&uStackX_18);
      if (cVar9 == '\0') {
        if (_DAT_181b4ef90 == 0) {
          uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                       ,&UNK_1819d77a0);
          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                    (uVar18,&DAT_180069ca0);
        }
      }
      else {
        (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,8);
      }
      uVar28 = uStackX_8;
      if (uStackX_8 != 0) {
        uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3a83126f);
        cVar9 = recovered_180067cc0(uVar28 + 0x120,&uStackX_18);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
        }
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x440,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
    }
  }
  if (DAT_181b2b58d != '\0') {
    uStackX_18 = 0;
    cVar9 = recovered_180067cc0(_DAT_181a2b148 + unaff_R15,&uStackX_8);
    if (((cVar9 != '\0') &&
        (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,&uStackX_18,4), iVar10 == 0)) &&
       (uStackX_18 != 0)) {
      uStack_198 = (uint *)0x0;
      fStack_190 = 0.0;
      cVar9 = recovered_180067cc0(uStackX_18 + 8,&uStack_1c8);
      if (((cVar9 != '\0') &&
          (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), iVar10 == 0)) &&
         (cVar9 = recovered_18006bd40(uStackX_8 & 0xffffffff,&uStack_198), fVar36 = fStack_190,
         uVar18 = uStack_198, puVar15 = _DAT_181b2be38, fVar31 = _DAT_181a032ec, cVar9 != '\0')) {
        fVar35 = _DAT_181b2b590;
        if (_DAT_181b2b590 <= _DAT_181a0315c) {
          fVar35 = fVar40;
        }
        puVar27 = (undefined8 *)*_DAT_181b2be38;
        fVar5 = (float)uStack_198;
        puVar22 = puVar29;
        fVar37 = _DAT_181a03460;
        while( true ) {
          fVar34 = (float)((ulonglong)uVar18 >> 0x20);
          if (puVar27 == puVar15) break;
          uVar11 = *(uint *)((longlong)puVar27 + 0x9c);
          if (((((uVar11 != 0) && (uVar11 != uVar1)) &&
               (*(char *)((longlong)puVar27 + 0x19) != '\0')) &&
              ((*(char *)((longlong)puVar27 + 0x1a) == '\0' && (*(int *)(puVar27 + 6) != 0)))) &&
             ((DAT_181b2b406 == '\0' || (*(char *)((longlong)puVar27 + 0x1b) == '\0')))) {
            uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
            cVar9 = recovered_180067cc0((ulonglong)uVar11 + _DAT_181a2b148,&iStack_1a8);
            if (((cVar9 != '\0') &&
                (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),
                                            &uStackX_8,4), iVar10 == 0)) &&
               ((float)uStackX_8 != 0.0)) {
              uStack_1b8 = 0;
              fStack_1b0 = 0.0;
              cVar9 = recovered_180067cc0((int)(float)uStackX_8 + 8,&fStack_188);
              if (((cVar9 != '\0') &&
                  (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_184,fStack_188),
                                              &uStack_1c8,4), iVar10 == 0)) &&
                 (cVar9 = recovered_18006bd40(uStack_1c8 & 0xffffffff,&uStack_1b8), cVar9 != '\0'))
              {
                auStack_168 = (undefined  [8])uVar18;
                fVar34 = fVar34 - uStack_1b8._4_4_;
                fVar34 = fVar34 * fVar34 + (fVar5 - (float)uStack_1b8) * (fVar5 - (float)uStack_1b8)
                         + (fVar36 - fStack_1b0) * (fVar36 - fStack_1b0);
                if (fVar34 < 0.0) {
                  fVar34 = (float)func_0x0001801cb525();
                }
                else {
                  fVar34 = SQRT(fVar34);
                }
                if ((fVar34 <= fVar31) && (fVar34 < fVar37)) {
                  puVar22 = puVar27 + 3;
                  fVar37 = fVar34;
                }
              }
            }
          }
          puVar27 = (undefined8 *)*puVar27;
        }
        if ((puVar22 != (undefined8 *)0x0) && (*(uint *)((longlong)puVar22 + 0x84) != uVar1)) {
          uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
          cVar9 = recovered_180067cc0((ulonglong)*(uint *)((longlong)puVar22 + 0x84) +
                                      _DAT_181a2b148,&uStack_1c8);
          if ((cVar9 != '\0') &&
             ((iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), iVar10 == 0 &&
              ((float)uStackX_8 != 0.0)))) {
            uStack_1b8 = 0;
            fStack_1b0 = 0.0;
            cVar9 = recovered_180067cc0((int)(float)uStackX_8 + 8,&iStack_1a8);
            if ((cVar9 != '\0') &&
               ((iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),
                                            &uStack_1c8,4), iVar10 == 0 &&
                (cVar9 = recovered_18006bd40(uStack_1c8 & 0xffffffff,&uStack_1b8), cVar9 != '\0'))))
            {
              fVar37 = (float)uStack_1b8 - fVar5;
              auStack_168 = (undefined  [8])uStack_1b8;
              fVar38 = (float)((ulonglong)uStack_1b8 >> 0x20) - uStack_198._4_4_;
              fVar39 = fStack_1b0 - fVar36;
              fVar31 = fVar38 * fVar38 + fVar37 * fVar37 + fVar39 * fVar39;
              if (fVar31 < 0.0) {
                fVar31 = (float)func_0x0001801cb525();
              }
              else {
                fVar31 = SQRT(fVar31);
              }
              if (fVar31 <= _DAT_181a0310c) {
                fVar37 = 0.0;
                fVar38 = 0.0;
              }
              else {
                fVar37 = fVar37 / fVar31;
                fVar38 = fVar38 / fVar31;
                fVar40 = fVar39 / fVar31;
              }
              fStack_1b0 = fVar36 + fVar35 * fVar40;
              uStack_1b8 = CONCAT44(fVar34 + fVar35 * fVar38,fVar37 * fVar35 + fVar5);
              fStack_188 = 0.0;
              cVar9 = recovered_180067cc0((int)(float)uStackX_8 + 8,&uStack_1c8);
              if (((cVar9 != '\0') &&
                  (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&fStack_188,4), iVar10 == 0)
                  ) && (fStack_188 != 0.0)) {
                iStack_1a8 = 0;
                cVar9 = recovered_180067cc0((int)fStack_188 + 8,&uStack_1c8);
                if (((cVar9 != '\0') &&
                    (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&iStack_1a8,4),
                    iVar10 == 0)) && (iStack_1a8 != 0)) {
                  uStack_1c8 = uStack_1c8 & 0xffffffff00000000;
                  cVar9 = recovered_180067cc0(iStack_1a8 + 0x20,&uStack_198);
                  if (((cVar9 != '\0') &&
                      (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_198,&uStack_1c8,4),
                      iVar10 == 0)) &&
                     (((float)uStack_1c8 != 0.0 &&
                      (cVar9 = recovered_180067cc0((int)(float)uStack_1c8 + 0x60,&uStack_198),
                      cVar9 != '\0')))) {
                    (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_198,&uStack_1b8,0xc);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar10 = iStack_13c;
  uVar1 = uStack_140;
  if ((char)uStackX_10 == '\0') {
    if (_DAT_181b2be40 != 0) {
      recovered_18006eb70(&uStack_178);
    }
    recovered_180073970();
    recovered_180073610();
    recovered_1800731b0();
    recovered_180070fd0();
    recovered_180072bf0();
    return;
  }
  puStack_158 = (uint *)0x0;
  puStack_150 = (uint *)0x0;
  puStack_148 = (uint *)0x0;
  uVar11 = (uint)uStackX_20;
  puVar15 = puVar29;
LAB_180076170:
  do {
    uVar12 = (uint)puVar15;
    if (uVar1 <= uVar12) {
      puVar15 = (undefined8 *)*_DAT_181b2be38;
      puVar25 = puStack_150;
      puVar19 = puStack_158;
      puVar7 = puStack_150;
      fVar40 = _DAT_181a0337c;
      if (puVar15 != _DAT_181b2be38) {
        do {
          puVar22 = _DAT_181b2be38;
          if (puStack_158 != puVar25) {
            puVar19 = puStack_158;
            do {
              if (*(uint *)(puVar15 + 2) == *puVar19) {
                puVar22 = (undefined8 *)*puVar15;
                goto LAB_1800762ef;
              }
              puVar19 = puVar19 + 1;
            } while (puVar19 != puVar25);
          }
          uVar24 = (((((ulonglong)*(byte *)(puVar15 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)puVar15 + 0x11)) * 0x100000001b3 ^
                    (ulonglong)*(byte *)((longlong)puVar15 + 0x12)) * 0x100000001b3 ^
                   (ulonglong)*(byte *)((longlong)puVar15 + 0x13)) * 0x100000001b3 & _DAT_181b2be60;
          lVar17 = _DAT_181b2be48 + uVar24 * 0x10;
          puVar27 = *(undefined8 **)(_DAT_181b2be48 + uVar24 * 0x10);
          if (*(undefined8 **)(lVar17 + 8) == puVar15) {
            if (puVar27 == puVar15) {
              *(undefined8 **)(_DAT_181b2be48 + uVar24 * 0x10) = _DAT_181b2be38;
              *(undefined8 **)(lVar17 + 8) = puVar22;
            }
            else {
              *(undefined8 *)(lVar17 + 8) = puVar15[1];
            }
          }
          else if (puVar27 == puVar15) {
            *(undefined8 *)(_DAT_181b2be48 + uVar24 * 0x10) = *puVar15;
          }
          puVar22 = (undefined8 *)*puVar15;
          _DAT_181b2be40 = _DAT_181b2be40 + -1;
          *(undefined8 **)puVar15[1] = puVar22;
          puVar22[1] = puVar15[1];
          recovered_180066e40(puVar15 + 0xf);
          recovered_180066e40(puVar15 + 0xb);
          recovered_180066e40(puVar15 + 7);
          func_0x000180127e40(puVar15,400);
          puVar25 = puStack_150;
LAB_1800762ef:
          puVar15 = puVar22;
          puVar19 = puStack_158;
          puVar7 = puVar25;
          fVar40 = _DAT_181a0337c;
        } while (puVar22 != _DAT_181b2be38);
      }
      for (; uStack_198 = puVar7, uStackX_20 = puVar19, puVar19 != uStack_198; puVar19 = puVar19 + 1
          ) {
        uVar1 = *puVar19;
        uStackX_8 = CONCAT44(uStackX_8._4_4_,uVar1);
        uVar24 = ((((ulonglong)((int)uVar1 >> 8 & 0xff) ^
                   ((ulonglong)uVar1 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3) * 0x100000001b3 ^
                  (ulonglong)((int)uVar1 >> 0x10 & 0xff)) * 0x100000001b3 ^
                 (ulonglong)((int)uVar1 >> 0x18 & 0xff)) * 0x100000001b3 & _DAT_181b2be60;
        puVar15 = *(undefined8 **)(_DAT_181b2be48 + 8 + uVar24 * 0x10);
        puVar22 = puVar29;
        if (puVar15 != _DAT_181b2be38) {
          for (; (puVar22 = puVar15, uVar1 != *(uint *)(puVar15 + 2) &&
                 (puVar22 = puVar29, puVar15 != *(undefined8 **)(_DAT_181b2be48 + uVar24 * 0x10)));
              puVar15 = (undefined8 *)puVar15[1]) {
          }
        }
        puVar15 = _DAT_181b2be38;
        if (puVar22 != (undefined8 *)0x0) {
          puVar15 = puVar22;
        }
        uVar24 = (ulonglong)uVar1;
        if (puVar15 == _DAT_181b2be38) {
          uStackX_10 = uVar1;
          puVar15 = (undefined8 *)recovered_180078f90(0x181b2be30,auStack_d0,&uStackX_10);
          puVar15 = (undefined8 *)*puVar15;
          *(float *)((longlong)puVar15 + 0x9c) = (float)uStackX_8;
          puVar20 = (undefined4 *)recovered_180078170(extraout_XMM0_Qa_01,&uStackX_8);
          *puVar20 = 0;
          uVar24 = uStackX_8;
        }
        if (puVar15 + 3 == (undefined8 *)0x0) {
          uStack_1c8 = 0;
          fVar31 = 0.0;
        }
        else {
          uStack_1c8 = puVar15[0x14];
          fVar31 = *(float *)(puVar15 + 0x15);
        }
        fStack_1c0 = fVar31;
        cVar9 = recovered_1800767b0(uVar24 & 0xffffffff,puVar15 + 3,&uStack_178);
        if (cVar9 == '\0') {
          piVar21 = (int *)recovered_180078170(extraout_XMM0_Qa_02,&uStackX_8);
          if (*piVar21 < 5) {
            piVar21 = (int *)recovered_180078170(extraout_XMM0_Qa_03,&uStackX_8);
            *piVar21 = *piVar21 + 1;
          }
          else {
            uStackX_18 = (uint)(float)uStackX_8;
            recovered_180078370(0x181b2be30,&uStackX_18);
            cVar9 = *(char *)((longlong)(undefined8 *)_DAT_181b2f4e8[1] + 0x19);
            puVar15 = (undefined8 *)_DAT_181b2f4e8[1];
            uStack_160 = _DAT_181b2f4e8;
            auStack_168 = (undefined  [8])_DAT_181b2f4e8;
            while (puVar22 = puVar15, cVar9 == '\0') {
              if (*(uint *)((longlong)puVar22 + 0x1c) < (uint)(float)uStackX_8) {
                puVar15 = (undefined8 *)puVar22[2];
                puVar22 = (undefined8 *)auStack_168;
              }
              else {
                if ((*(char *)((longlong)uStack_160 + 0x19) != '\0') &&
                   ((uint)(float)uStackX_8 < *(uint *)((longlong)puVar22 + 0x1c))) {
                  uStack_160 = puVar22;
                }
                puVar15 = (undefined8 *)*puVar22;
              }
              cVar9 = *(char *)((longlong)puVar15 + 0x19);
              auStack_168 = (undefined  [8])puVar22;
            }
            puVar15 = _DAT_181b2f4e8 + 1;
            if (*(char *)((longlong)uStack_160 + 0x19) == '\0') {
              puVar15 = uStack_160;
            }
            cVar9 = *(char *)((longlong)(undefined8 *)*puVar15 + 0x19);
            puVar15 = (undefined8 *)*puVar15;
            while (cVar9 == '\0') {
              if ((uint)(float)uStackX_8 < *(uint *)((longlong)puVar15 + 0x1c)) {
                puVar22 = (undefined8 *)*puVar15;
                uStack_160 = puVar15;
              }
              else {
                puVar22 = (undefined8 *)puVar15[2];
              }
              puVar15 = puVar22;
              cVar9 = *(char *)((longlong)puVar22 + 0x19);
            }
            auVar6 = _auStack_168;
            auStack_168._4_4_ = (undefined4)((ulonglong)auStack_168 >> 0x20);
            uStack_160._4_4_ = (undefined4)((ulonglong)uStack_160 >> 0x20);
            uStack_138 = auStack_168._0_4_;
            uStack_134 = auStack_168._4_4_;
            uStack_130 = (undefined4)uStack_160;
            uStack_12c = uStack_160._4_4_;
            _auStack_168 = auVar6;
            recovered_180079580(puVar15,&uStack_138);
          }
        }
        else {
          puVar20 = (undefined4 *)recovered_180078170(extraout_XMM0_Qa_02,&uStackX_8);
          *puVar20 = 0;
          fVar36 = fStack_1c0;
          if ((((float)uStack_1c8 != 0.0) || (uStack_1c8._4_4_ != 0.0)) ||
             (fVar36 = fVar31, fVar31 != 0.0)) {
            uVar18 = puVar15[0x14];
            uStack_1b8._4_4_ = (float)((ulonglong)uVar18 >> 0x20);
            fVar31 = uStack_1b8._4_4_ - uStack_1c8._4_4_;
            uStack_1b8 = uVar18;
            if ((float *)((longlong)puVar15 + 0x184) != afStack_e0) {
              *(float *)((longlong)puVar15 + 0x184) = ((float)uVar18 - (float)uStack_1c8) * fVar40;
              *(float *)(puVar15 + 0x31) = fVar31 * fVar40;
              *(float *)((longlong)puVar15 + 0x18c) = (*(float *)(puVar15 + 0x15) - fVar36) * fVar40
              ;
            }
          }
          if (puVar15 + 0x2f != puVar15 + 0x14) {
            *(undefined4 *)(puVar15 + 0x2f) = *(undefined4 *)(puVar15 + 0x14);
            *(undefined4 *)((longlong)puVar15 + 0x17c) = *(undefined4 *)((longlong)puVar15 + 0xa4);
            *(undefined4 *)(puVar15 + 0x30) = *(undefined4 *)(puVar15 + 0x15);
          }
        }
        puVar25 = puStack_150;
        puVar7 = uStack_198;
      }
      puVar15 = (undefined8 *)*_DAT_181b2f4e8;
      puVar22 = _DAT_181b2f4e8;
      if (puVar15 != _DAT_181b2f4e8) {
        do {
          puVar19 = puStack_158;
          if (puStack_158 != puVar25) {
LAB_180076681:
            if (*(uint *)((longlong)puVar15 + 0x1c) != *puVar19) goto code_r0x00018007668a;
            puVar27 = (undefined8 *)puVar15[2];
            if (*(char *)((longlong)puVar27 + 0x19) == '\0') {
              cVar9 = *(char *)((longlong)(undefined8 *)*puVar27 + 0x19);
              puVar15 = puVar27;
              puVar27 = (undefined8 *)*puVar27;
              while (cVar9 == '\0') {
                cVar9 = *(char *)((longlong)(undefined8 *)*puVar27 + 0x19);
                puVar15 = puVar27;
                puVar27 = (undefined8 *)*puVar27;
              }
            }
            else {
              cVar9 = *(char *)((longlong)(undefined8 *)puVar15[1] + 0x19);
              puVar8 = (undefined8 *)puVar15[1];
              puVar27 = puVar15;
              while ((puVar15 = puVar8, cVar9 == '\0' && (puVar27 == (undefined8 *)puVar15[2]))) {
                cVar9 = *(char *)((longlong)(undefined8 *)puVar15[1] + 0x19);
                puVar8 = (undefined8 *)puVar15[1];
                puVar27 = puVar15;
              }
            }
            goto LAB_1800766aa;
          }
LAB_180076693:
          puVar15 = (undefined8 *)recovered_180079700(puVar19,puVar15);
          puVar25 = puStack_150;
          puVar22 = _DAT_181b2f4e8;
LAB_1800766aa:
        } while (puVar15 != puVar22);
      }
      _DAT_181b2bee0 = 0;
      for (puVar15 = (undefined8 *)*_DAT_181b2be38; puVar15 != _DAT_181b2be38;
          puVar15 = (undefined8 *)*puVar15) {
        if ((*(char *)((longlong)puVar15 + 0x19) != '\0') &&
           (*(char *)((longlong)puVar15 + 0x1a) == '\0')) {
          puVar29 = (undefined8 *)(ulonglong)((int)puVar29 + 1);
        }
        _DAT_181b2bee0 = SUB84(puVar29,0);
      }
      recovered_180073970();
      recovered_180073610();
      recovered_1800731b0();
      recovered_180070fd0();
      recovered_180072bf0();
      recovered_180079780(&puStack_158);
      return;
    }
    uVar14 = recovered_180069360(uVar12 * 0x10 + iVar10);
    uStackX_8 = CONCAT44(uStackX_8._4_4_,uVar14);
    if ((uVar14 == 0) || (uVar14 == uVar11)) {
LAB_1800761d2:
      puVar15 = (undefined8 *)(ulonglong)(uVar12 + 1);
      goto LAB_180076170;
    }
    if (puStack_150 == puStack_148) {
      recovered_18007a050(&puStack_158,puStack_150,&uStackX_8);
      goto LAB_1800761d2;
    }
    *puStack_150 = uVar14;
    puStack_150 = puStack_150 + 1;
    puVar15 = (undefined8 *)(ulonglong)(uVar12 + 1);
  } while( true );
code_r0x00018007668a:
  puVar19 = puVar19 + 1;
  if (puVar19 == puVar25) goto LAB_180076693;
  goto LAB_180076681;
}



/* ===== ANALYSIS FUNCTION 0x1800767b0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint recovered_1800767b0(uint param_1,char *param_2,undefined8 *param_3)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 *******pppppppuVar9;
  int *piVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  float extraout_XMM0_Da;
  float fVar13;
  float fVar14;
  float fVar15;
  uint auStackX_20 [2];
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined8 uStack_1e8;
  undefined8 uStack_1b8;
  undefined8 *******apppppppuStack_1b0 [2];
  longlong lStack_1a0;
  ulonglong uStack_198;
  int aiStack_188 [2];
  char *pcStack_180;
  undefined4 uStack_178;
  char *pcStack_170;
  undefined4 uStack_168;
  char *pcStack_160;
  undefined4 uStack_158;
  char *pcStack_150;
  undefined4 uStack_148;
  char *pcStack_140;
  undefined4 uStack_138;
  char *pcStack_130;
  undefined4 uStack_128;
  char *pcStack_120;
  undefined4 uStack_118;
  char *pcStack_110;
  undefined4 uStack_108;
  char *pcStack_100;
  undefined4 uStack_f8;
  char *pcStack_f0;
  undefined4 uStack_e8;
  char *pcStack_e0;
  undefined4 uStack_d8;
  char *pcStack_d0;
  undefined4 uStack_c8;
  char *pcStack_c0;
  undefined4 uStack_b8;
  char *pcStack_b0;
  undefined4 uStack_a8;
  char *pcStack_a0;
  undefined4 uStack_98;
  char *pcStack_90;
  undefined4 uStack_88;
  char *pcStack_80;
  undefined4 uStack_78;
  char *pcStack_70;
  int aiStack_68 [2];
  undefined8 uStack_60;
  undefined8 uStack_54;
  undefined8 auStack_48 [4];
  
  uVar12 = (ulonglong)param_1;
  uVar3 = recovered_180069360(uVar12 + 0x504);
  if ((uVar3 != 0) && (uVar3 = recovered_180069360((ulonglong)uVar3 + 0xa8), uVar3 != 0)) {
    auStackX_20[0] = auStackX_20[0] & 0xffffff00;
    cVar1 = recovered_180067cc0((ulonglong)uVar3 + 0x95,&uStack_1f8);
    if (cVar1 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                    &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar7,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
    }
    param_2[4] = (char)auStackX_20[0];
    uVar3 = recovered_180069360((ulonglong)uVar3 + 0x14);
    if (uVar3 != 0) {
      auStackX_20[0] = auStackX_20[0] & 0xffffff00;
      cVar1 = recovered_180067cc0((ulonglong)uVar3 + 0x59,&uStack_1f8);
      if (cVar1 == '\0') {
        if (_DAT_181b4ef90 == 0) {
          uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                      ,&UNK_1819d77a0);
          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                    (uVar7,&DAT_180069ca0);
        }
      }
      else {
        (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
      }
      iVar6 = 0;
      *(uint *)(param_2 + 0x18) = (uint)((char)auStackX_20[0] == '\0');
      param_2[1] = (char)auStackX_20[0] == '\0';
      if ((char)auStackX_20[0] == '\0') {
        uVar3 = recovered_180069360(uVar12 + 0x1a60);
        if (uVar3 != 0) {
          auStackX_20[0] = 0;
          cVar1 = recovered_180067cc0((ulonglong)uVar3 + 0x78,&uStack_1f8);
          if (cVar1 == '\0') {
            if (_DAT_181b4ef90 == 0) {
              uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                          ,&UNK_1819d77a0);
              __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                        (uVar7,&DAT_180069ca0);
            }
          }
          else {
            (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,4);
          }
          param_2[3] = auStackX_20[0] == 8;
        }
        uVar2 = recovered_18006e7e0(uVar12);
        *(undefined2 *)(param_2 + 0x12) = uVar2;
        auStackX_20[0] = auStackX_20[0] & 0xffffff00;
        cVar1 = recovered_180067cc0(uVar12 + 0x50,&uStack_1f8);
        if (cVar1 == '\0') {
          if (_DAT_181b4ef90 == 0) {
            uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                        ,&UNK_1819d77a0);
            __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                      (uVar7,&DAT_180069ca0);
          }
        }
        else {
          (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
        }
        param_2[2] = (char)auStackX_20[0];
        auStackX_20[0] = auStackX_20[0] & 0xffffff00;
        cVar1 = recovered_180067cc0(uVar12 + 0x324,&uStack_1f8);
        if (cVar1 == '\0') {
          if (_DAT_181b4ef90 == 0) {
            uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                        ,&UNK_1819d77a0);
            __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                      (uVar7,&DAT_180069ca0);
          }
        }
        else {
          (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
        }
        *param_2 = (char)auStackX_20[0];
        *(uint *)(param_2 + 0x84) = param_1;
        iVar4 = recovered_180069360(uVar12 + 0x48);
        if (((iVar4 != 0) && (iVar4 = recovered_180069360(iVar4 + 8), iVar4 != 0)) &&
           (iVar4 = recovered_180069360(iVar4 + 0x10), iVar4 != 0)) {
          auStackX_20[0] = auStackX_20[0] & 0xffff0000;
          cVar1 = recovered_180067cc0(iVar4 + 0x10,&uStack_1f8);
          if (cVar1 == '\0') {
            if (_DAT_181b4ef90 == 0) {
              uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                          ,&UNK_1819d77a0);
              __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                        (uVar7,&DAT_180069ca0);
            }
          }
          else {
            (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,2);
          }
          *(undefined2 *)(param_2 + 0x10) = (undefined2)auStackX_20[0];
        }
        aiStack_188[0] = _DAT_181a2b110;
        pcStack_180 = param_2 + 0x88;
        uStack_178 = _DAT_181a2b0f0;
        pcStack_170 = param_2 + 0x94;
        uStack_168 = _DAT_181a2b118;
        pcStack_160 = param_2 + 0xac;
        uStack_158 = _DAT_181a2b0f8;
        pcStack_150 = param_2 + 0xa0;
        uStack_148 = _DAT_181a2b100;
        pcStack_140 = param_2 + 0xc4;
        uStack_138 = _DAT_181a2b120;
        pcStack_130 = param_2 + 0xb8;
        uStack_128 = _DAT_181a2b108;
        pcStack_120 = param_2 + 0xdc;
        uStack_118 = _DAT_181a2b150;
        pcStack_110 = param_2 + 0xd0;
        uStack_108 = _DAT_181a2b178;
        pcStack_100 = param_2 + 0xe8;
        uStack_f8 = _DAT_181a2b160;
        pcStack_f0 = param_2 + 0xf4;
        uStack_e8 = _DAT_181a2b128;
        pcStack_e0 = param_2 + 0x100;
        uStack_d8 = _DAT_181a2b168;
        pcStack_d0 = param_2 + 0x10c;
        uStack_c8 = _DAT_181a2b148;
        pcStack_c0 = param_2 + 0x148;
        uStack_b8 = _DAT_181a2b140;
        pcStack_b0 = param_2 + 0x154;
        uStack_a8 = _DAT_181a2b170;
        pcStack_a0 = param_2 + 0x124;
        uStack_98 = _DAT_181a2b158;
        pcStack_90 = param_2 + 0x118;
        uStack_88 = _DAT_181a2b138;
        pcStack_80 = param_2 + 0x130;
        uStack_78 = _DAT_181a2b130;
        pcStack_70 = param_2 + 0x13c;
        piVar10 = aiStack_188;
        do {
          while( true ) {
            if (piVar10 == aiStack_68) {
              if ((((float)*(undefined8 *)(param_2 + 0x88) != 0.0) ||
                  (uStack_1e8._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x88) >> 0x20),
                  uStack_1e8._4_4_ != 0.0)) || (*(float *)(param_2 + 0x90) != 0.0)) {
                uStack_1e8 = *(undefined8 *)(param_2 + 0x88);
                fVar14 = (float)*param_3 - (float)uStack_1e8;
                fVar13 = (float)((ulonglong)*param_3 >> 0x20);
                fVar15 = fVar13 - (float)((ulonglong)uStack_1e8 >> 0x20);
                fVar14 = fVar15 * fVar15 + fVar14 * fVar14 +
                         (*(float *)(param_3 + 1) - *(float *)(param_2 + 0x90)) *
                         (*(float *)(param_3 + 1) - *(float *)(param_2 + 0x90));
                if (fVar14 < 0.0) {
                  func_0x0001801cb525(CONCAT44(fVar13,fVar14));
                  fVar14 = extraout_XMM0_Da;
                }
                else {
                  fVar14 = SQRT(fVar14);
                }
                *(float *)(param_2 + 0xc) = fVar14;
              }
              uVar7 = *(undefined8 *)(param_2 + 0x88);
              if ((((float)uVar7 == 0.0) &&
                  (uStack_1e8._4_4_ = (float)((ulonglong)uVar7 >> 0x20), uStack_1e8._4_4_ == 0.0))
                 && (*(float *)(param_2 + 0x90) == 0.0)) {
                return 0;
              }
              uStack_1e8 = uVar7;
              if (*(longlong *)(param_2 + 0x30) == 0) {
                recovered_18006b9b0(apppppppuStack_1b0,uVar12);
                if ((lStack_1a0 != 0) &&
                   ((undefined8 ********)(param_2 + 0x20) != apppppppuStack_1b0)) {
                  pppppppuVar9 = apppppppuStack_1b0;
                  if (0xf < uStack_198) {
                    pppppppuVar9 = apppppppuStack_1b0[0];
                  }
                  recovered_1800676d0(param_2 + 0x20,pppppppuVar9);
                }
                recovered_180066e40(apppppppuStack_1b0);
              }
              if (*(longlong *)(param_2 + 0x50) == 0) {
                puVar11 = (undefined8 *)(param_2 + 0x40);
                if (*param_2 == '\0') {
                  *(undefined8 *)(param_2 + 0x70) = 0;
                  pcVar8 = param_2 + 0x60;
                  if (0xf < *(ulonglong *)(param_2 + 0x78)) {
                    pcVar8 = *(char **)(param_2 + 0x60);
                  }
                  *pcVar8 = '\0';
                  if (param_1 == 0) {
                    *(undefined8 *)(param_2 + 0x50) = 0;
                    if (0xf < *(ulonglong *)(param_2 + 0x58)) {
                      puVar11 = (undefined8 *)*puVar11;
                    }
                    *(undefined *)puVar11 = 0;
                  }
                  else {
                    auStackX_20[0] = 0;
                    cVar1 = recovered_180067cc0(uVar12 + 0x18cc,&uStack_1e8);
                    if (((cVar1 == '\0') ||
                        (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1e8,auStackX_20,4),
                        iVar4 != 0)) || (auStackX_20[0] == 0)) {
                      recovered_1800676d0(puVar11,&DAT_18020e770,7);
                    }
                    else {
                      uVar5 = recovered_180069360((ulonglong)auStackX_20[0] + 0x5c);
                      recovered_18006c300(uVar5,puVar11,param_2 + 0x60);
                    }
                    auStackX_20[0] = 0;
                    cVar1 = recovered_180067cc0(uVar12 + 0x18cc,&uStack_1e8);
                    if (((cVar1 != '\0') &&
                        (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1e8,auStackX_20,4),
                        iVar4 == 0)) &&
                       ((iVar6 = 0, 0xffff < auStackX_20[0] &&
                        (iVar6 = recovered_180069360((ulonglong)auStackX_20[0] + 0x14),
                        199 < iVar6 - 1U)))) {
                      iVar4 = recovered_180069360((ulonglong)auStackX_20[0] + 0x14);
                      iVar6 = 0;
                      if (iVar4 - 1U < 200) {
                        iVar6 = iVar4;
                      }
                    }
                  }
                  *(int *)(param_2 + 0x80) = iVar6;
                }
                else {
                  recovered_1800676d0(puVar11,&UNK_1819d7890,3);
                }
              }
              return 1;
            }
            auStackX_20[0] = 0;
            cVar1 = recovered_180067cc0(*piVar10 + param_1,&uStack_1b8);
            if (((cVar1 != '\0') &&
                (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b8,auStackX_20,4), iVar4 == 0)) &&
               (auStackX_20[0] != 0)) break;
            puVar11 = *(undefined8 **)(piVar10 + 2);
            if (puVar11 != auStack_48) {
              *puVar11 = 0;
              *(undefined4 *)(puVar11 + 1) = 0;
            }
LAB_180076e3c:
            piVar10 = piVar10 + 4;
          }
          puVar11 = *(undefined8 **)(piVar10 + 2);
          cVar1 = recovered_180067cc0(auStackX_20[0] + 8,&uStack_1e8);
          if ((cVar1 == '\0') ||
             (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1e8,&uStack_1f8,4), iVar4 != 0)) {
            if (puVar11 != &uStack_60) {
              *puVar11 = 0;
              *(undefined4 *)(puVar11 + 1) = 0;
            }
          }
          else {
            cVar1 = recovered_18006bd40(uStack_1f8,puVar11);
            if (cVar1 != '\0') goto LAB_180076e3c;
          }
          if (puVar11 == &uStack_54) goto LAB_180076e3c;
          *puVar11 = 0;
          *(undefined4 *)(puVar11 + 1) = 0;
          piVar10 = piVar10 + 4;
        } while( true );
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* ===== ANALYSIS FUNCTION 0x180077c40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180077c40(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  int iVar3;
  undefined8 *puVar4;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  uStack_10 = auStack_18;
  if (DAT_181b2f64a != '\0') {
    return;
  }
  LOCK();
  DAT_181b2f64a = 1;
  UNLOCK();
  DAT_181b2f64b = 0;
  puVar4 = (undefined8 *)func_0x000180127a94(8);
  *puVar4 = &DAT_180077be0;
  auStack_18 = (undefined  [8])_beginthreadex(0,0,&DAT_180079df0,puVar4,0,auStack_18 + 8);
  if (auStack_18 != (undefined  [8])0x0) {
    if (_DAT_181b2f500 != 0) {
      terminate();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _DAT_181b2f500 = uStack_10;
    _DAT_181b2f4f8 = auStack_18;
    auVar2 = ZEXT816(0);
    if ((int)uStack_10 != 0) {
      iVar3 = _Thrd_detach(auStack_18);
      auVar2 = _auStack_18;
      if (iVar3 == 0) {
        _DAT_181b2f4f8 = ZEXT816(0);
        return;
      }
    }
    _auStack_18 = auVar2;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_10._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x180077d30 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 recovered_180077d30(undefined8 param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined2 auStackX_10 [4];
  undefined8 auStackX_18 [2];
  
  auStackX_10[0] = 0;
  cVar1 = recovered_180067cc0(param_1,auStackX_18);
  if (cVar1 != '\0') {
    (*_DAT_181b4ef88)(_DAT_181b4ef90,auStackX_18[0],auStackX_10,2);
    return auStackX_10[0];
  }
  if (_DAT_181b4ef90 == 0) {
    uVar2 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819d77a0);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar2,&DAT_180069ca0);
  }
  return auStackX_10[0];
}



/* ===== ANALYSIS FUNCTION 0x180077e30 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180077e30(longlong param_1)

{
  uint uVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  
  pplVar2 = *(longlong ***)(param_1 + 8);
  pplVar6 = (longlong **)
            (((((((ulonglong)(byte)_DAT_181b4efb8 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                (ulonglong)(_DAT_181b4efb8 >> 8 & 0xff)) * 0x100000001b3 ^
               (ulonglong)(_DAT_181b4efb8 >> 0x10 & 0xff)) * 0x100000001b3 ^
              (ulonglong)(_DAT_181b4efb8 >> 0x18)) * 0x100000001b3 & *(ulonglong *)(param_1 + 0x30))
             * 0x10 + *(longlong *)(param_1 + 0x18));
  pplVar3 = (longlong **)pplVar6[1];
  if (pplVar3 == pplVar2) {
LAB_180077ec1:
    pplVar5 = (longlong **)0x0;
  }
  else {
    uVar1 = *(uint *)(pplVar3 + 2);
    pplVar5 = pplVar3;
    while (_DAT_181b4efb8 != uVar1) {
      if (pplVar5 == (longlong **)*pplVar6) goto LAB_180077ec1;
      pplVar5 = (longlong **)pplVar5[1];
      uVar1 = *(uint *)(pplVar5 + 2);
    }
  }
  if (pplVar5 != (longlong **)0x0) {
    if (pplVar3 == pplVar5) {
      if ((longlong **)*pplVar6 == pplVar5) {
        *pplVar6 = (longlong *)pplVar2;
        pplVar6[1] = (longlong *)pplVar2;
      }
      else {
        pplVar6[1] = pplVar5[1];
      }
    }
    else if ((longlong **)*pplVar6 == pplVar5) {
      *pplVar6 = *pplVar5;
    }
    plVar4 = *pplVar5;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
    *pplVar5[1] = (longlong)plVar4;
    plVar4[1] = (longlong)pplVar5[1];
    func_0x000180127e40(pplVar5,0x18);
    return 1;
  }
  return 0;
}



/* ===== ANALYSIS FUNCTION 0x180077f30 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x000180078034) */
/* WARNING: Removing unreachable block (ram,0x000180078041) */
/* WARNING: Removing unreachable block (ram,0x000180078046) */

undefined4 * recovered_180077f30(undefined4 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong lVar8;
  
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  lVar4 = func_0x000180127a94(0x18);
  *(longlong *)lVar4 = lVar4;
  *(longlong *)(lVar4 + 8) = lVar4;
  *(longlong *)(param_1 + 2) = lVar4;
  *(undefined8 *)(param_1 + 6) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 7;
  *(undefined8 *)(param_1 + 0xe) = 8;
  *param_1 = 0x3f800000;
  uVar2 = *(undefined8 *)(param_1 + 2);
  puVar5 = (undefined8 *)func_0x000180127a94(0x80);
  lVar4 = *(longlong *)(param_1 + 6);
  lVar6 = *(longlong *)(param_1 + 10) - lVar4 >> 3;
  if (lVar6 != 0) {
    lVar8 = lVar4;
    if ((0xfff < (ulonglong)(lVar6 * 8)) &&
       (lVar8 = *(longlong *)(lVar4 + -8), 0x1f < (lVar4 - lVar8) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      puVar7 = (undefined4 *)(*pcVar3)();
      return puVar7;
    }
    func_0x000180127e40(lVar8);
  }
  *(undefined8 **)(param_1 + 6) = puVar5;
  puVar1 = puVar5 + 0x10;
  *(undefined8 **)(param_1 + 8) = puVar1;
  *(undefined8 **)(param_1 + 10) = puVar1;
  for (; puVar5 != puVar1; puVar5 = puVar5 + 1) {
    *puVar5 = uVar2;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180078100 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180078100(void)

{
  char cVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  
  lVar4 = _DAT_181b2f4e8;
  cVar1 = *(char *)((longlong)*(longlong **)(_DAT_181b2f4e8 + 8) + 0x19);
  plVar3 = *(longlong **)(_DAT_181b2f4e8 + 8);
  while (cVar1 == '\0') {
    func_0x000180023e30(&DAT_181b2f4e8,&DAT_181b2f4e8,plVar3[2]);
    plVar2 = (longlong *)*plVar3;
    func_0x000180127e40(plVar3,0x28);
    plVar3 = plVar2;
    cVar1 = *(char *)((longlong)plVar2 + 0x19);
  }
  *(longlong *)(lVar4 + 8) = lVar4;
  *(longlong *)lVar4 = lVar4;
  *(longlong *)(lVar4 + 0x10) = lVar4;
  _DAT_181b2f4f0 = 0;
  return;
}



/* ===== ANALYSIS FUNCTION 0x180078170 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * recovered_180078170(undefined8 param_1,uint *param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong **pplVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  bool bVar8;
  longlong *plStack_38;
  undefined8 uStack_30;
  longlong *plStack_28;
  uint uStack_20;
  undefined4 uStack_1c;
  
  plVar6 = _DAT_181b2f4e8;
  plStack_28 = (longlong *)_DAT_181b2f4e8[1];
  uStack_20 = 0;
  plVar5 = _DAT_181b2f4e8;
  if (*(char *)((longlong)plStack_28 + 0x19) == '\0') {
    plVar2 = plStack_28;
    plVar7 = _DAT_181b2f4e8;
    do {
      plStack_28 = plVar2;
      bVar8 = *param_2 <= *(uint *)((longlong)plStack_28 + 0x1c);
      plVar3 = plStack_28;
      plVar5 = plStack_28;
      if (!bVar8) {
        plVar3 = plStack_28 + 2;
        plVar5 = plVar7;
      }
      uStack_20 = (uint)bVar8;
      plVar2 = (longlong *)*plVar3;
      plVar7 = plVar5;
    } while (*(char *)((longlong)(longlong *)*plVar3 + 0x19) == '\0');
  }
  if ((*(char *)((longlong)plVar5 + 0x19) != '\0') ||
     (*param_2 < *(uint *)((longlong)plVar5 + 0x1c))) {
    if (_DAT_181b2f4f0 == 0x666666666666666) {
      func_0x000180003a20();
      pcVar1 = (code *)swi(3);
      plVar6 = (longlong *)(*pcVar1)();
      return plVar6;
    }
    plStack_38 = (longlong *)&DAT_181b2f4e8;
    uStack_30 = 0;
    pplVar4 = (longlong **)func_0x000180127a94(0x28);
    *(uint *)((longlong)pplVar4 + 0x1c) = *param_2;
    *(undefined4 *)(pplVar4 + 4) = 0;
    *pplVar4 = plVar6;
    pplVar4[1] = plVar6;
    pplVar4[2] = plVar6;
    *(undefined2 *)(pplVar4 + 3) = 0;
    plStack_38 = plStack_28;
    uStack_30 = CONCAT44(uStack_1c,uStack_20);
    plVar5 = (longlong *)func_0x000180023e90(&DAT_181b2f4e8,&plStack_38);
  }
  return plVar5 + 4;
}



/* ===== ANALYSIS FUNCTION 0x180078290 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180078290(longlong param_1)

{
  longlong **pplVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong **pplVar4;
  undefined8 *puVar5;
  longlong **in_RAX;
  longlong **pplVar6;
  longlong **pplVar7;
  longlong **pplVar8;
  longlong **pplVar9;
  longlong **pplVar10;
  longlong **pplVar11;
  longlong **pplVar12;
  
  if (*(ulonglong *)(param_1 + 0x10) != 0) {
    pplVar1 = *(longlong ***)(param_1 + 8);
    if (*(ulonglong *)(param_1 + 0x10) < *(ulonglong *)(param_1 + 0x38) >> 3) {
      pplVar11 = (longlong **)*pplVar1;
      if (pplVar11 == pplVar1) {
        return pplVar1;
      }
      lVar3 = *(longlong *)(param_1 + 0x18);
      pplVar4 = *(longlong ***)(param_1 + 8);
      pplVar12 = (longlong **)pplVar11[1];
      pplVar6 = (longlong **)
                ((((ulonglong)*(byte *)((longlong)pplVar11 + 0x13) ^
                  ((((ulonglong)*(byte *)(pplVar11 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                   (ulonglong)*(byte *)((longlong)pplVar11 + 0x11)) * 0x100000001b3 ^
                  (ulonglong)*(byte *)((longlong)pplVar11 + 0x12)) * 0x100000001b3) * 0x100000001b3
                 & *(ulonglong *)(param_1 + 0x30)) * 0x10 + lVar3);
      pplVar8 = (longlong **)*pplVar6;
      pplVar10 = (longlong **)pplVar6[1];
      pplVar7 = pplVar11;
      do {
        pplVar9 = (longlong **)*pplVar7;
        recovered_180066e40(pplVar7 + 0xf);
        recovered_180066e40(pplVar7 + 0xb);
        recovered_180066e40(pplVar7 + 7);
        func_0x000180127e40(pplVar7,400);
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
        if (pplVar7 == pplVar10) {
          pplVar10 = pplVar12;
          if (pplVar8 == pplVar11) {
            *pplVar6 = (longlong *)pplVar4;
            pplVar10 = pplVar4;
          }
          pplVar6[1] = (longlong *)pplVar10;
          while (pplVar9 != pplVar1) {
            pplVar10 = (longlong **)
                       (((((((ulonglong)*(byte *)(pplVar9 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3
                           ^ (ulonglong)*(byte *)((longlong)pplVar9 + 0x11)) * 0x100000001b3 ^
                          (ulonglong)*(byte *)((longlong)pplVar9 + 0x12)) * 0x100000001b3 ^
                         (ulonglong)*(byte *)((longlong)pplVar9 + 0x13)) * 0x100000001b3 &
                        *(ulonglong *)(param_1 + 0x30)) * 0x10 + lVar3);
            pplVar11 = (longlong **)pplVar10[1];
            pplVar8 = pplVar9;
            while( true ) {
              pplVar9 = (longlong **)*pplVar8;
              recovered_180066e40(pplVar8 + 0xf);
              recovered_180066e40(pplVar8 + 0xb);
              recovered_180066e40(pplVar8 + 7);
              func_0x000180127e40(pplVar8,400);
              *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
              if (pplVar8 == pplVar11) break;
              pplVar8 = pplVar9;
              if (pplVar9 == pplVar1) {
                *pplVar10 = (longlong *)pplVar9;
                goto LAB_180079a66;
              }
            }
            *pplVar10 = (longlong *)pplVar4;
            pplVar10[1] = (longlong *)pplVar4;
          }
          goto LAB_180079a66;
        }
        pplVar7 = pplVar9;
      } while (pplVar9 != pplVar1);
      if (pplVar8 == pplVar11) {
        *pplVar6 = (longlong *)pplVar9;
      }
LAB_180079a66:
      *pplVar12 = (longlong *)pplVar9;
      pplVar9[1] = (longlong *)pplVar12;
      return pplVar1;
    }
    *pplVar1[1] = 0;
    puVar5 = *pplVar1;
    while (puVar5 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar5;
      recovered_180066e40(puVar5 + 0xf);
      recovered_180066e40(puVar5 + 0xb);
      recovered_180066e40(puVar5 + 7);
      func_0x000180127e40(puVar5,400);
      puVar5 = puVar2;
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



/* ===== ANALYSIS FUNCTION 0x180078370 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 recovered_180078370(longlong param_1,int *param_2)

{
  int iVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  
  pplVar2 = *(longlong ***)(param_1 + 8);
  pplVar5 = (longlong **)
            (((((((ulonglong)*(byte *)param_2 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                (ulonglong)*(byte *)((longlong)param_2 + 1)) * 0x100000001b3 ^
               (ulonglong)*(byte *)((longlong)param_2 + 2)) * 0x100000001b3 ^
              (ulonglong)*(byte *)((longlong)param_2 + 3)) * 0x100000001b3 &
             *(ulonglong *)(param_1 + 0x30)) * 0x10 + *(longlong *)(param_1 + 0x18));
  pplVar3 = (longlong **)pplVar5[1];
  if (pplVar3 == pplVar2) {
LAB_1800783f4:
    pplVar6 = (longlong **)0x0;
  }
  else {
    iVar1 = *(int *)(pplVar3 + 2);
    pplVar6 = pplVar3;
    while (*param_2 != iVar1) {
      if (pplVar6 == (longlong **)*pplVar5) goto LAB_1800783f4;
      pplVar6 = (longlong **)pplVar6[1];
      iVar1 = *(int *)(pplVar6 + 2);
    }
  }
  if (pplVar6 != (longlong **)0x0) {
    if (pplVar3 == pplVar6) {
      if ((longlong **)*pplVar5 == pplVar6) {
        *pplVar5 = (longlong *)pplVar2;
        pplVar5[1] = (longlong *)pplVar2;
      }
      else {
        pplVar5[1] = pplVar6[1];
      }
    }
    else if ((longlong **)*pplVar5 == pplVar6) {
      *pplVar5 = *pplVar6;
    }
    plVar4 = *pplVar6;
    *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
    *pplVar6[1] = (longlong)plVar4;
    plVar4[1] = (longlong)pplVar6[1];
    recovered_180066e40(pplVar6 + 0xf);
    recovered_180066e40(pplVar6 + 0xb);
    recovered_180066e40(pplVar6 + 7);
    func_0x000180127e40(pplVar6,400);
    return 1;
  }
  return 0;
}



/* ===== ANALYSIS FUNCTION 0x1800785e0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong * recovered_1800785e0(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong *plVar6;
  longlong lVar7;
  
  if (param_1 != param_2) {
    if (0xf < (ulonglong)param_1[3]) {
      lVar1 = *param_1;
      lVar7 = lVar1;
      if ((0xfff < param_1[3] + 1U) &&
         (lVar7 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar7) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        plVar6 = (longlong *)(*pcVar2)();
        return plVar6;
      }
      func_0x000180127e40(lVar7);
    }
    param_1[3] = 0xf;
    param_1[2] = 0;
    *(undefined *)param_1 = 0;
    uVar3 = *(undefined4 *)((longlong)param_2 + 4);
    uVar4 = *(undefined4 *)(param_2 + 1);
    uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined4 *)((longlong)param_1 + 4) = uVar3;
    *(undefined4 *)(param_1 + 1) = uVar4;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar5;
    uVar3 = *(undefined4 *)((longlong)param_2 + 0x14);
    uVar4 = *(undefined4 *)(param_2 + 3);
    uVar5 = *(undefined4 *)((longlong)param_2 + 0x1c);
    *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar3;
    *(undefined4 *)(param_1 + 3) = uVar4;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar5;
    param_2[2] = 0;
    param_2[3] = 0xf;
    *(undefined *)param_2 = 0;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180078780 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180078780(undefined (*param_1) [16],longlong param_2,longlong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined (*pauVar4) [16];
  ulonglong uVar5;
  ulonglong uVar6;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  if (param_2 == param_3) {
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    (*param_1)[0] = 0;
  }
  else {
    uVar6 = param_3 - param_2;
    if (0x7fffffffffffffff < uVar6) {
      func_0x000180052a50();
      pcVar1 = (code *)swi(3);
      pauVar4 = (undefined (*) [16])(*pcVar1)();
      return pauVar4;
    }
    if (uVar6 < 0x10) {
      *(ulonglong *)param_1[1] = uVar6;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      func_0x0001801ca88d(0,param_2,uVar6);
      *(undefined *)(uVar6 + (longlong)param_1) = 0;
    }
    else {
      uVar2 = uVar6 | 0xf;
      uVar5 = 0x7fffffffffffffff;
      if ((uVar2 < 0x8000000000000000) && (uVar5 = uVar2, uVar2 < 0x16)) {
        uVar5 = 0x16;
      }
      lVar3 = func_0x000180024110(uVar5 + 1);
      *(longlong *)*param_1 = lVar3;
      *(ulonglong *)param_1[1] = uVar6;
      *(ulonglong *)(param_1[1] + 8) = uVar5;
      func_0x0001801ca88d(lVar3,param_2,uVar6);
      *(undefined *)(lVar3 + uVar6) = 0;
    }
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180078870 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong * recovered_180078870(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 uVar6;
  longlong lVar7;
  
  uVar6 = 0;
  uVar4 = *(ulonglong *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1);
  if (((longlong)uVar4 < 1) || (uVar4 <= param_3)) {
    lVar7 = 0;
  }
  else {
    lVar7 = uVar4 - param_3;
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  cVar2 = _good_ios_base_std__QEBA_NXZ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
  if (cVar2 == '\0') {
    cVar2 = '\0';
  }
  else {
    plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x50 + (longlong)param_1);
    if ((plVar1 == (longlong *)0x0) || (plVar1 == param_1)) {
      cVar2 = '\x01';
    }
    else {
      _flush___basic_ostream_DU__char_traits_D_std___std__QEAAAEAV12_XZ();
      cVar2 = _good_ios_base_std__QEBA_NXZ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
    }
  }
  if (cVar2 == '\0') {
    uVar6 = 4;
  }
  else {
    lVar5 = *param_1;
    if ((*(uint *)((longlong)*(int *)(lVar5 + 4) + 0x18 + (longlong)param_1) & 0x1c0) != 0x40) {
      for (; lVar7 != 0; lVar7 = lVar7 + -1) {
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) {
          uVar6 = 4;
          goto LAB_180078970;
        }
      }
      lVar5 = *param_1;
    }
    uVar4 = _sputn___basic_streambuf_DU__char_traits_D_std___std__QEAA_JPEBD_J_Z
                      (*(undefined8 *)((longlong)*(int *)(lVar5 + 4) + 0x48 + (longlong)param_1),
                       param_2,param_3);
    if (uVar4 == param_3) {
LAB_180078970:
      do {
        if (lVar7 == 0) goto LAB_180078998;
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) break;
        lVar7 = lVar7 + -1;
      } while( true );
    }
    uVar6 = 4;
LAB_180078998:
    *(undefined8 *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1) = 0;
  }
  _setstate___basic_ios_DU__char_traits_D_std___std__QEAAXH_N_Z
            ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1,uVar6,0);
  cVar2 = _uncaught_exception_std__YA_NXZ();
  if (cVar2 == '\0') {
    __Osfx___basic_ostream_DU__char_traits_D_std___std__QEAAXXZ(param_1);
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180078a40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
recovered_180078a40(undefined8 param_1,undefined8 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  float fVar12;
  float fVar13;
  
  uVar9 = (((((ulonglong)*(byte *)param_3 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
            (ulonglong)*(byte *)((longlong)param_3 + 1)) * 0x100000001b3 ^
           (ulonglong)*(byte *)((longlong)param_3 + 2)) * 0x100000001b3 ^
          (ulonglong)*(byte *)((longlong)param_3 + 3)) * 0x100000001b3;
  uVar7 = uVar9 & _DAT_181b508c0;
  puVar8 = (undefined8 *)(uVar7 * 2);
  puVar5 = *(undefined8 **)(_DAT_181b508a8 + 8 + uVar7 * 0x10);
  puVar10 = _DAT_181b50898;
  if (puVar5 != _DAT_181b50898) {
    puVar8 = *(undefined8 **)(_DAT_181b508a8 + uVar7 * 0x10);
    iVar1 = *(int *)(puVar5 + 2);
    puVar10 = puVar5;
    while( true ) {
      if (*param_3 == iVar1) {
        *param_2 = puVar10;
        *(undefined *)(param_2 + 1) = 0;
        return param_2;
      }
      if (puVar10 == puVar8) break;
      puVar10 = (undefined8 *)puVar10[1];
      iVar1 = *(int *)(puVar10 + 2);
    }
  }
  if (_DAT_181b508a0 == 0xaaaaaaaaaaaaaaa) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar3 = (code *)swi(3);
    puVar5 = (undefined8 *)(*pcVar3)();
    return puVar5;
  }
  puVar5 = (undefined8 *)func_0x000180127a94(0x18,puVar8,param_3,param_4,&DAT_181b50898,0);
  *(int *)(puVar5 + 2) = *param_3;
  *(undefined4 *)((longlong)puVar5 + 0x14) = 0;
  uVar4 = _DAT_181b508c8;
  uVar7 = _DAT_181b508a0 + 1;
  if ((longlong)uVar7 < 0) {
    fVar12 = (float)(uVar7 >> 1 | (ulonglong)((uint)uVar7 & 1));
    fVar12 = fVar12 + fVar12;
  }
  else {
    fVar12 = (float)uVar7;
  }
  if ((longlong)_DAT_181b508c8 < 0) {
    fVar13 = (float)(_DAT_181b508c8 >> 1 | (ulonglong)((uint)_DAT_181b508c8 & 1));
    fVar13 = fVar13 + fVar13;
  }
  else {
    fVar13 = (float)_DAT_181b508c8;
  }
  if (_DAT_181b50890 < fVar12 / fVar13) {
    fVar12 = (float)func_0x0001801cb4e3(fVar12 / _DAT_181b50890);
    lVar6 = 0;
    if ((_DAT_181a03458 <= fVar12) && (fVar12 = fVar12 - _DAT_181a03458, fVar12 < _DAT_181a03458)) {
      lVar6 = -0x8000000000000000;
    }
    uVar7 = 8;
    if (8 < (ulonglong)((longlong)fVar12 + lVar6)) {
      uVar7 = (longlong)fVar12 + lVar6;
    }
    uVar11 = uVar4;
    if ((uVar4 < uVar7) && ((0x1ff < uVar4 || (uVar11 = uVar4 * 8, uVar4 * 8 < uVar7)))) {
      uVar11 = uVar7;
    }
    recovered_18007ac10(uVar7,uVar11);
    puVar8 = *(undefined8 **)(_DAT_181b508a8 + 8 + (_DAT_181b508c0 & uVar9) * 0x10);
    puVar10 = _DAT_181b50898;
    if (puVar8 != _DAT_181b50898) {
      iVar1 = *(int *)(puVar8 + 2);
      puVar10 = puVar8;
      while (*(int *)(puVar5 + 2) != iVar1) {
        if (puVar10 == *(undefined8 **)(_DAT_181b508a8 + (_DAT_181b508c0 & uVar9) * 0x10))
        goto LAB_180078c88;
        puVar10 = (undefined8 *)puVar10[1];
        iVar1 = *(int *)(puVar10 + 2);
      }
      puVar10 = (undefined8 *)*puVar10;
    }
  }
LAB_180078c88:
  puVar8 = (undefined8 *)puVar10[1];
  _DAT_181b508a0 = _DAT_181b508a0 + 1;
  *puVar5 = puVar10;
  puVar5[1] = puVar8;
  *puVar8 = puVar5;
  puVar10[1] = puVar5;
  lVar6 = _DAT_181b508a8;
  uVar9 = _DAT_181b508c0 & uVar9;
  puVar2 = *(undefined8 **)(_DAT_181b508a8 + uVar9 * 0x10);
  if (puVar2 == _DAT_181b50898) {
    *(undefined8 **)(_DAT_181b508a8 + uVar9 * 0x10) = puVar5;
  }
  else {
    if (puVar2 == puVar10) {
      *(undefined8 **)(_DAT_181b508a8 + uVar9 * 0x10) = puVar5;
      goto LAB_180078ce7;
    }
    if (*(undefined8 **)(_DAT_181b508a8 + 8 + uVar9 * 0x10) != puVar8) goto LAB_180078ce7;
  }
  *(undefined8 **)(lVar6 + 8 + uVar9 * 0x10) = puVar5;
LAB_180078ce7:
  *param_2 = puVar5;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x180078f90 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong ** recovered_180078f90(float *param_1,longlong **param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  longlong **pplVar2;
  code *pcVar3;
  longlong **pplVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong **pplVar9;
  ulonglong uVar10;
  longlong **pplVar11;
  float fVar12;
  float fVar13;
  
  uVar5 = (((((ulonglong)*(byte *)param_3 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
            (ulonglong)*(byte *)((longlong)param_3 + 1)) * 0x100000001b3 ^
           (ulonglong)*(byte *)((longlong)param_3 + 2)) * 0x100000001b3 ^
          (ulonglong)*(byte *)((longlong)param_3 + 3)) * 0x100000001b3;
  uVar8 = uVar5 & *(ulonglong *)(param_1 + 0xc);
  pplVar9 = (longlong **)(uVar8 * 2);
  pplVar2 = *(longlong ***)(*(longlong *)(param_1 + 6) + 8 + uVar8 * 0x10);
  pplVar4 = (longlong **)(param_1 + 2);
  pplVar11 = (longlong **)*pplVar4;
  if (pplVar2 != pplVar11) {
    pplVar9 = *(longlong ***)(*(longlong *)(param_1 + 6) + uVar8 * 0x10);
    iVar1 = *(int *)(pplVar2 + 2);
    while (*param_3 != iVar1) {
      pplVar11 = pplVar2;
      if (pplVar2 == pplVar9) goto LAB_18007905a;
      pplVar2 = (longlong **)pplVar2[1];
      iVar1 = *(int *)(pplVar2 + 2);
    }
    pplVar11 = (longlong **)*pplVar2;
    if (pplVar2 != (longlong **)0x0) {
      *param_2 = (longlong *)pplVar2;
      *(undefined *)(param_2 + 1) = 0;
      return param_2;
    }
  }
LAB_18007905a:
  if (*(longlong *)(param_1 + 4) == 0xa3d70a3d70a3d7) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar3 = (code *)swi(3);
    pplVar4 = (longlong **)(*pcVar3)();
    return pplVar4;
  }
  pplVar4 = (longlong **)func_0x000180127a94(400,pplVar9,pplVar4,param_4,pplVar4,0);
  *(int *)(pplVar4 + 2) = *param_3;
  func_0x0001801ca899(pplVar4 + 3,0,0x178);
  func_0x00018007af90(pplVar4 + 3);
  uVar8 = *(ulonglong *)(param_1 + 0xe);
  uVar6 = *(longlong *)(param_1 + 4) + 1;
  if ((longlong)uVar6 < 0) {
    fVar12 = (float)(uVar6 >> 1 | (ulonglong)((uint)uVar6 & 1));
    fVar12 = fVar12 + fVar12;
  }
  else {
    fVar12 = (float)uVar6;
  }
  if ((longlong)uVar8 < 0) {
    fVar13 = (float)(uVar8 >> 1 | (ulonglong)((uint)uVar8 & 1));
    fVar13 = fVar13 + fVar13;
  }
  else {
    fVar13 = (float)uVar8;
  }
  if (*param_1 < fVar12 / fVar13) {
    fVar12 = (float)func_0x0001801cb4e3(fVar12 / *param_1);
    lVar7 = 0;
    if ((_DAT_181a03458 <= fVar12) && (fVar12 = fVar12 - _DAT_181a03458, fVar12 < _DAT_181a03458)) {
      lVar7 = -0x8000000000000000;
    }
    uVar6 = 8;
    if (8 < (ulonglong)((longlong)fVar12 + lVar7)) {
      uVar6 = (longlong)fVar12 + lVar7;
    }
    uVar10 = uVar8;
    if ((uVar8 < uVar6) && ((0x1ff < uVar8 || (uVar10 = uVar8 * 8, uVar8 * 8 < uVar6)))) {
      uVar10 = uVar6;
    }
    recovered_18007add0(param_1,uVar10);
    pplVar2 = *(longlong ***)
               (*(longlong *)(param_1 + 6) + 8 + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10);
    pplVar11 = *(longlong ***)(param_1 + 2);
    if (pplVar2 != pplVar11) {
      iVar1 = *(int *)(pplVar2 + 2);
      pplVar11 = pplVar2;
      while (*(int *)(pplVar4 + 2) != iVar1) {
        if (pplVar11 ==
            *(longlong ***)
             (*(longlong *)(param_1 + 6) + (*(ulonglong *)(param_1 + 0xc) & uVar5) * 0x10))
        goto LAB_1800791f7;
        pplVar11 = (longlong **)pplVar11[1];
        iVar1 = *(int *)(pplVar11 + 2);
      }
      pplVar11 = (longlong **)*pplVar11;
    }
  }
LAB_1800791f7:
  pplVar2 = (longlong **)pplVar11[1];
  *(longlong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + 1;
  *pplVar4 = (longlong *)pplVar11;
  pplVar4[1] = (longlong *)pplVar2;
  *pplVar2 = (longlong *)pplVar4;
  pplVar11[1] = (longlong *)pplVar4;
  uVar5 = *(ulonglong *)(param_1 + 0xc) & uVar5;
  lVar7 = *(longlong *)(param_1 + 6);
  pplVar9 = *(longlong ***)(lVar7 + uVar5 * 0x10);
  if (pplVar9 == *(longlong ***)(param_1 + 2)) {
    *(longlong ***)(lVar7 + uVar5 * 0x10) = pplVar4;
  }
  else {
    if (pplVar9 == pplVar11) {
      *(longlong ***)(lVar7 + uVar5 * 0x10) = pplVar4;
      goto LAB_180079241;
    }
    if (*(longlong ***)(lVar7 + 8 + uVar5 * 0x10) != pplVar2) goto LAB_180079241;
  }
  *(longlong ***)(lVar7 + 8 + uVar5 * 0x10) = pplVar4;
LAB_180079241:
  *param_2 = (longlong *)pplVar4;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x180079270 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180079270(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  if (0x7ffffffffffffffe < param_3) {
    func_0x000180052a50();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (param_3 < 8) {
    param_1[2] = param_3;
    param_1[3] = 7;
    func_0x0001801ca88d(param_1,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + (longlong)param_1) = 0;
  }
  else {
    uVar2 = param_3 | 7;
    if (uVar2 < 0x7fffffffffffffff) {
      if (uVar2 < 10) {
        uVar2 = 10;
      }
      uVar4 = uVar2 + 1;
      if (0x7fffffffffffffff < uVar4) {
        func_0x000180003980();
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      uVar4 = 0x7fffffffffffffff;
      uVar2 = 0x7ffffffffffffffe;
    }
    lVar3 = func_0x000180024110(uVar4 * 2);
    param_1[2] = param_3;
    *param_1 = lVar3;
    param_1[3] = uVar2;
    func_0x0001801ca88d(lVar3,param_2,param_3 * 2);
    *(undefined2 *)(param_3 * 2 + lVar3) = 0;
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180079580 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong recovered_180079580(undefined8 param_1,longlong **param_2)

{
  char cVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  undefined8 uVar7;
  longlong **pplVar8;
  longlong lVar9;
  
  pplVar2 = (longlong **)*param_2;
  lVar9 = 0;
  pplVar3 = (longlong **)param_2[1];
  pplVar4 = pplVar2;
  while (pplVar4 != pplVar3) {
    pplVar8 = (longlong **)pplVar4[2];
    lVar9 = lVar9 + 1;
    if (*(char *)((longlong)pplVar8 + 0x19) == '\0') {
      cVar1 = *(char *)((longlong)*pplVar8 + 0x19);
      pplVar4 = pplVar8;
      pplVar8 = (longlong **)*pplVar8;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((longlong)*pplVar8 + 0x19);
        pplVar4 = pplVar8;
        pplVar8 = (longlong **)*pplVar8;
      }
    }
    else {
      cVar1 = *(char *)((longlong)pplVar4[1] + 0x19);
      pplVar6 = (longlong **)pplVar4[1];
      pplVar8 = pplVar4;
      while ((pplVar4 = pplVar6, cVar1 == '\0' && (pplVar8 == (longlong **)pplVar4[2]))) {
        cVar1 = *(char *)((longlong)pplVar4[1] + 0x19);
        pplVar6 = (longlong **)pplVar4[1];
        pplVar8 = pplVar4;
      }
    }
  }
  if ((pplVar2 == (longlong **)*_DAT_181b2f4e8) && (*(char *)((longlong)pplVar3 + 0x19) != '\0')) {
    recovered_180078100();
    return lVar9;
  }
  while (pplVar2 != pplVar3) {
    pplVar4 = (longlong **)pplVar2[2];
    if (*(char *)((longlong)pplVar4 + 0x19) == '\0') {
      cVar1 = *(char *)((longlong)*pplVar4 + 0x19);
      pplVar8 = pplVar4;
      pplVar6 = (longlong **)*pplVar4;
      while (cVar1 == '\0') {
        cVar1 = *(char *)((longlong)*pplVar6 + 0x19);
        pplVar8 = pplVar6;
        pplVar6 = (longlong **)*pplVar6;
      }
      pplVar4 = (longlong **)*pplVar4;
      cVar1 = *(char *)((longlong)pplVar4 + 0x19);
      while (cVar1 == '\0') {
        pplVar4 = (longlong **)*pplVar4;
        cVar1 = *(char *)((longlong)pplVar4 + 0x19);
      }
    }
    else {
      cVar1 = *(char *)((longlong)pplVar2[1] + 0x19);
      pplVar6 = (longlong **)pplVar2[1];
      pplVar4 = pplVar2;
      while ((pplVar8 = pplVar6, cVar1 == '\0' && (pplVar4 == (longlong **)pplVar8[2]))) {
        cVar1 = *(char *)((longlong)pplVar8[1] + 0x19);
        pplVar6 = (longlong **)pplVar8[1];
        pplVar4 = pplVar8;
      }
      cVar1 = *(char *)((longlong)pplVar2[1] + 0x19);
      pplVar6 = (longlong **)pplVar2[1];
      pplVar4 = pplVar2;
      while ((pplVar5 = pplVar6, cVar1 == '\0' && (pplVar4 == (longlong **)pplVar5[2]))) {
        cVar1 = *(char *)((longlong)pplVar5[1] + 0x19);
        pplVar6 = (longlong **)pplVar5[1];
        pplVar4 = pplVar5;
      }
    }
    uVar7 = recovered_18007a550(&DAT_181b2f4e8,pplVar2);
    func_0x000180127e40(uVar7,0x28);
    pplVar2 = pplVar8;
  }
  return lVar9;
}



/* ===== ANALYSIS FUNCTION 0x180079700 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180079700(undefined8 param_1,longlong **param_2)

{
  char cVar1;
  longlong **pplVar2;
  undefined8 uVar3;
  longlong **pplVar4;
  
  pplVar4 = (longlong **)param_2[2];
  if (*(char *)((longlong)pplVar4 + 0x19) == '\0') {
    cVar1 = *(char *)((longlong)*pplVar4 + 0x19);
    pplVar2 = (longlong **)*pplVar4;
    while (cVar1 == '\0') {
      cVar1 = *(char *)((longlong)*pplVar2 + 0x19);
      pplVar4 = pplVar2;
      pplVar2 = (longlong **)*pplVar2;
    }
  }
  else {
    cVar1 = *(char *)((longlong)param_2[1] + 0x19);
    pplVar2 = (longlong **)param_2[1];
    while ((pplVar4 = pplVar2, cVar1 == '\0' && (param_2 == (longlong **)pplVar4[2]))) {
      cVar1 = *(char *)((longlong)pplVar4[1] + 0x19);
      pplVar2 = (longlong **)pplVar4[1];
      param_2 = pplVar4;
    }
  }
  uVar3 = recovered_18007a550(&DAT_181b2f4e8);
  func_0x000180127e40(uVar3,0x28);
  return pplVar4;
}



/* ===== ANALYSIS FUNCTION 0x180079780 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180079780(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  lVar1 = *param_1;
  if (lVar1 != 0) {
    lVar3 = lVar1;
    if ((0xfff < (param_1[2] - lVar1 & 0xfffffffffffffffcU)) &&
       (lVar3 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(lVar3);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180079c40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16]
recovered_180079c40(undefined (*param_1) [16],undefined8 param_2,undefined8 *param_3,
                   undefined8 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined (*pauVar10) [16];
  ulonglong uVar11;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  uVar2 = param_3[2];
  uVar3 = param_4[2];
  uVar1 = uVar3 + uVar2;
  if ((param_3[3] - uVar2 < uVar3) || ((ulonglong)param_3[3] < (ulonglong)param_4[3])) {
    if (param_4[3] - uVar3 < uVar2) {
      if (0x7fffffffffffffff - uVar2 < uVar3) {
        func_0x000180052a50();
        pcVar4 = (code *)swi(3);
        pauVar10 = (undefined (*) [16])(*pcVar4)();
        return pauVar10;
      }
      uVar8 = uVar1 | 0xf;
      uVar11 = 0x7fffffffffffffff;
      if ((uVar8 < 0x8000000000000000) && (uVar11 = uVar8, uVar8 < 0x16)) {
        uVar11 = 0x16;
      }
      lVar9 = func_0x000180024110(uVar11 + 1);
      *(longlong *)*param_1 = lVar9;
      *(ulonglong *)param_1[1] = uVar1;
      *(ulonglong *)(param_1[1] + 8) = uVar11;
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (undefined8 *)*param_3;
      }
      func_0x0001801ca88d(lVar9,param_3,uVar2);
      if (0xf < (ulonglong)param_4[3]) {
        param_4 = (undefined8 *)*param_4;
      }
      func_0x0001801ca88d(lVar9 + uVar2,param_4,uVar3 + 1);
    }
    else {
      uVar5 = *(undefined4 *)((longlong)param_4 + 4);
      uVar6 = *(undefined4 *)(param_4 + 1);
      uVar7 = *(undefined4 *)((longlong)param_4 + 0xc);
      *(undefined4 *)*param_1 = *(undefined4 *)param_4;
      *(undefined4 *)(*param_1 + 4) = uVar5;
      *(undefined4 *)(*param_1 + 8) = uVar6;
      *(undefined4 *)(*param_1 + 0xc) = uVar7;
      uVar5 = *(undefined4 *)((longlong)param_4 + 0x14);
      uVar6 = *(undefined4 *)(param_4 + 3);
      uVar7 = *(undefined4 *)((longlong)param_4 + 0x1c);
      *(undefined4 *)param_1[1] = *(undefined4 *)(param_4 + 2);
      *(undefined4 *)(param_1[1] + 4) = uVar5;
      *(undefined4 *)(param_1[1] + 8) = uVar6;
      *(undefined4 *)(param_1[1] + 0xc) = uVar7;
      param_4[2] = 0;
      *(undefined *)param_4 = 0;
      param_4[3] = 0xf;
      lVar9 = *(longlong *)*param_1;
      func_0x0001801ca893(lVar9 + uVar2,lVar9,uVar3 + 1);
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (undefined8 *)*param_3;
      }
      func_0x0001801ca88d(lVar9,param_3,uVar2);
      *(ulonglong *)param_1[1] = uVar1;
    }
  }
  else {
    uVar5 = *(undefined4 *)((longlong)param_3 + 4);
    uVar6 = *(undefined4 *)(param_3 + 1);
    uVar7 = *(undefined4 *)((longlong)param_3 + 0xc);
    *(undefined4 *)*param_1 = *(undefined4 *)param_3;
    *(undefined4 *)(*param_1 + 4) = uVar5;
    *(undefined4 *)(*param_1 + 8) = uVar6;
    *(undefined4 *)(*param_1 + 0xc) = uVar7;
    uVar5 = *(undefined4 *)((longlong)param_3 + 0x14);
    uVar6 = *(undefined4 *)(param_3 + 3);
    uVar7 = *(undefined4 *)((longlong)param_3 + 0x1c);
    *(undefined4 *)param_1[1] = *(undefined4 *)(param_3 + 2);
    *(undefined4 *)(param_1[1] + 4) = uVar5;
    *(undefined4 *)(param_1[1] + 8) = uVar6;
    *(undefined4 *)(param_1[1] + 0xc) = uVar7;
    param_3[2] = 0;
    param_3[3] = 0xf;
    *(undefined *)param_3 = 0;
    pauVar10 = param_1;
    if (0xf < *(ulonglong *)(param_1[1] + 8)) {
      pauVar10 = *(undefined (**) [16])*param_1;
    }
    if (0xf < (ulonglong)param_4[3]) {
      param_4 = (undefined8 *)*param_4;
    }
    func_0x0001801ca88d(*pauVar10 + uVar2,param_4,uVar3 + 1);
    *(ulonglong *)param_1[1] = uVar1;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180079e50 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 * recovered_180079e50(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  longlong lVar12;
  
  lVar3 = *param_1;
  lVar12 = (param_1[1] - lVar3) / 0x28;
  if (lVar12 == 0x666666666666666) {
    recovered_18006aad0();
    pcVar4 = (code *)swi(3);
    puVar9 = (undefined4 *)(*pcVar4)();
    return puVar9;
  }
  uVar1 = lVar12 + 1;
  uVar2 = (param_1[2] - lVar3) / 0x28;
  if (0x666666666666666 - (uVar2 >> 1) < uVar2) {
    uVar10 = 0x666666666666666;
  }
  else {
    uVar2 = (uVar2 >> 1) + uVar2;
    uVar10 = uVar1;
    if (uVar1 <= uVar2) {
      uVar10 = uVar2;
    }
    if (0x666666666666666 < uVar10) {
      func_0x000180003980();
      pcVar4 = (code *)swi(3);
      puVar9 = (undefined4 *)(*pcVar4)();
      return puVar9;
    }
  }
  puVar8 = (undefined4 *)func_0x000180024110(uVar10 * 0x28);
  uVar5 = param_3[1];
  uVar6 = param_3[2];
  uVar7 = param_3[3];
  puVar9 = puVar8 + ((param_2 - lVar3) / 0x28) * 10;
  *puVar9 = *param_3;
  puVar9[1] = uVar5;
  puVar9[2] = uVar6;
  puVar9[3] = uVar7;
  uVar5 = param_3[5];
  uVar6 = param_3[6];
  uVar7 = param_3[7];
  puVar9[4] = param_3[4];
  puVar9[5] = uVar5;
  puVar9[6] = uVar6;
  puVar9[7] = uVar7;
  *(undefined8 *)(puVar9 + 8) = *(undefined8 *)(param_3 + 8);
  lVar3 = *param_1;
  if (param_2 == param_1[1]) {
    lVar12 = param_1[1] - lVar3;
    puVar11 = puVar8;
    param_2 = lVar3;
  }
  else {
    func_0x0001801ca893(puVar8,lVar3,param_2 - lVar3);
    puVar11 = puVar9 + 10;
    lVar12 = param_1[1] - param_2;
  }
  func_0x0001801ca893(puVar11,param_2,lVar12);
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar12 = lVar3;
    if ((0xfff < (ulonglong)(((param_1[2] - lVar3) / 0x28) * 0x28)) &&
       (lVar12 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar12) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar4 = (code *)swi(3);
      puVar9 = (undefined4 *)(*pcVar4)();
      return puVar9;
    }
    func_0x000180127e40(lVar12);
  }
  *param_1 = (longlong)puVar8;
  param_1[1] = (longlong)(puVar8 + uVar1 * 10);
  param_1[2] = (longlong)(puVar8 + uVar10 * 10);
  return puVar9;
}



/* ===== ANALYSIS FUNCTION 0x18007a050 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong recovered_18007a050(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  
  lVar5 = *param_1;
  lVar8 = param_2 - lVar5 >> 2;
  lVar3 = param_1[1] - lVar5 >> 2;
  if (lVar3 == 0x3fffffffffffffff) {
    recovered_18006aad0();
    pcVar2 = (code *)swi(3);
    lVar5 = (*pcVar2)();
    return lVar5;
  }
  uVar6 = param_1[2] - lVar5 >> 2;
  uVar1 = lVar3 + 1;
  if (0x3fffffffffffffff - (uVar6 >> 1) < uVar6) {
    uVar7 = 0x3fffffffffffffff;
  }
  else {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar7 = uVar1;
    if (uVar1 <= uVar6) {
      uVar7 = uVar6;
    }
    if (0x3fffffffffffffff < uVar7) {
      func_0x000180003980();
      pcVar2 = (code *)swi(3);
      lVar5 = (*pcVar2)();
      return lVar5;
    }
  }
  lVar4 = func_0x000180024110(uVar7 * 4);
  *(undefined4 *)(lVar4 + lVar8 * 4) = *param_3;
  lVar3 = *param_1;
  lVar5 = lVar4 + lVar8 * 4;
  if (param_2 == param_1[1]) {
    lVar9 = param_1[1] - lVar3;
    lVar8 = lVar4;
    param_2 = lVar3;
  }
  else {
    func_0x0001801ca893(lVar4,lVar3,param_2 - lVar3);
    lVar8 = lVar5 + 4;
    lVar9 = param_1[1] - param_2;
  }
  func_0x0001801ca893(lVar8,param_2,lVar9);
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar8 = lVar3;
    if ((0xfff < (param_1[2] - lVar3 & 0xfffffffffffffffcU)) &&
       (lVar8 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar8) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      lVar5 = (*pcVar2)();
      return lVar5;
    }
    func_0x000180127e40(lVar8);
  }
  *param_1 = lVar4;
  param_1[1] = lVar4 + uVar1 * 4;
  param_1[2] = uVar7 * 4 + lVar4;
  return lVar5;
}



/* ===== ANALYSIS FUNCTION 0x18007a480 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18007a480(longlong *param_1,longlong param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  lVar1 = *param_1;
  if (lVar1 != 0) {
    lVar3 = lVar1;
    if ((0xfff < (ulonglong)(((param_1[2] - lVar1) / 0x28) * 0x28)) &&
       (lVar3 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(lVar3);
  }
  *param_1 = param_2;
  param_1[1] = param_2 + param_3 * 0x28;
  param_1[2] = param_2 + param_4 * 0x28;
  return;
}



/* ===== ANALYSIS FUNCTION 0x18007a550 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_18007a550(longlong *param_1,longlong **param_2)

{
  char cVar1;
  undefined uVar2;
  longlong **pplVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong **pplVar6;
  longlong **pplVar7;
  longlong **pplVar8;
  longlong **pplVar9;
  longlong **pplVar10;
  
  pplVar7 = (longlong **)param_2[2];
  pplVar8 = param_2 + 2;
  if (*(char *)((longlong)pplVar7 + 0x19) == '\0') {
    cVar1 = *(char *)((longlong)*pplVar7 + 0x19);
    pplVar6 = pplVar7;
    pplVar3 = (longlong **)*pplVar7;
    while (cVar1 == '\0') {
      cVar1 = *(char *)((longlong)*pplVar3 + 0x19);
      pplVar6 = pplVar3;
      pplVar3 = (longlong **)*pplVar3;
    }
  }
  else {
    cVar1 = *(char *)((longlong)param_2[1] + 0x19);
    pplVar9 = (longlong **)param_2[1];
    pplVar3 = param_2;
    while ((pplVar6 = pplVar9, cVar1 == '\0' && (pplVar3 == (longlong **)pplVar6[2]))) {
      cVar1 = *(char *)((longlong)pplVar6[1] + 0x19);
      pplVar9 = (longlong **)pplVar6[1];
      pplVar3 = pplVar6;
    }
  }
  pplVar10 = param_2 + 1;
  pplVar3 = (longlong **)*param_2;
  pplVar9 = pplVar7;
  if (((*(char *)((longlong)pplVar3 + 0x19) == '\0') &&
      (pplVar9 = pplVar3, *(char *)((longlong)pplVar7 + 0x19) == '\0')) &&
     (pplVar9 = (longlong **)pplVar6[2], pplVar6 != param_2)) {
    pplVar3[1] = (longlong *)pplVar6;
    *pplVar6 = *param_2;
    pplVar7 = pplVar6;
    if (pplVar6 != (longlong **)*pplVar8) {
      pplVar7 = (longlong **)pplVar6[1];
      if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
        pplVar9[1] = (longlong *)pplVar7;
      }
      *pplVar7 = (longlong *)pplVar9;
      pplVar6[2] = *pplVar8;
      (*pplVar8)[1] = (longlong)pplVar6;
    }
    if (*(longlong ***)(*param_1 + 8) == param_2) {
      *(longlong ***)(*param_1 + 8) = pplVar6;
    }
    else {
      pplVar8 = (longlong **)*pplVar10;
      if ((longlong **)*pplVar8 == param_2) {
        *pplVar8 = (longlong *)pplVar6;
      }
      else {
        pplVar8[2] = (longlong *)pplVar6;
      }
    }
    uVar2 = *(undefined *)(pplVar6 + 3);
    pplVar6[1] = *pplVar10;
    *(undefined *)(pplVar6 + 3) = *(undefined *)(param_2 + 3);
    *(undefined *)(param_2 + 3) = uVar2;
  }
  else {
    pplVar7 = (longlong **)*pplVar10;
    if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
      pplVar9[1] = (longlong *)pplVar7;
    }
    if (*(longlong ***)(*param_1 + 8) == param_2) {
      *(longlong ***)(*param_1 + 8) = pplVar9;
    }
    else if ((longlong **)*pplVar7 == param_2) {
      *pplVar7 = (longlong *)pplVar9;
    }
    else {
      pplVar7[2] = (longlong *)pplVar9;
    }
    if (*(longlong ***)(longlong **)*param_1 == param_2) {
      pplVar8 = pplVar7;
      if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
        cVar1 = *(char *)((longlong)*pplVar9 + 0x19);
        pplVar6 = (longlong **)*pplVar9;
        pplVar8 = pplVar9;
        while (pplVar3 = pplVar6, cVar1 == '\0') {
          pplVar6 = (longlong **)*pplVar3;
          cVar1 = *(char *)((longlong)pplVar6 + 0x19);
          pplVar8 = pplVar3;
        }
      }
      *(longlong **)*param_1 = (longlong *)pplVar8;
    }
    lVar4 = *param_1;
    if (*(longlong ***)(lVar4 + 0x10) == param_2) {
      if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
        cVar1 = *(char *)((longlong)pplVar9[2] + 0x19);
        pplVar8 = (longlong **)pplVar9[2];
        pplVar6 = pplVar9;
        while (pplVar3 = pplVar8, cVar1 == '\0') {
          pplVar8 = (longlong **)pplVar3[2];
          cVar1 = *(char *)((longlong)pplVar8 + 0x19);
          pplVar6 = pplVar3;
        }
        *(longlong ***)(lVar4 + 0x10) = pplVar6;
      }
      else {
        *(longlong ***)(lVar4 + 0x10) = pplVar7;
      }
    }
  }
  if (*(char *)(param_2 + 3) == '\x01') {
    if ((pplVar9 != *(longlong ***)(*param_1 + 8)) &&
       (pplVar8 = pplVar9, *(char *)(pplVar9 + 3) == '\x01')) {
      do {
        pplVar9 = pplVar7;
        pplVar7 = (longlong **)*pplVar9;
        if (pplVar8 == pplVar7) {
          pplVar7 = (longlong **)pplVar9[2];
          if (*(char *)(pplVar7 + 3) == '\0') {
            *(undefined *)(pplVar7 + 3) = 1;
            pplVar7 = (longlong **)pplVar9[2];
            *(undefined *)(pplVar9 + 3) = 0;
            pplVar9[2] = *pplVar7;
            if (*(char *)((longlong)*pplVar7 + 0x19) == '\0') {
              (*pplVar7)[1] = (longlong)pplVar9;
            }
            pplVar6 = pplVar9 + 1;
            pplVar7[1] = pplVar9[1];
            if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
              *(longlong ***)(*param_1 + 8) = pplVar7;
              *pplVar7 = (longlong *)pplVar9;
              *pplVar6 = (longlong *)pplVar7;
              pplVar7 = (longlong **)pplVar9[2];
            }
            else {
              pplVar3 = (longlong **)*pplVar6;
              if (pplVar9 == (longlong **)*pplVar3) {
                *pplVar3 = (longlong *)pplVar7;
                *pplVar7 = (longlong *)pplVar9;
                *pplVar6 = (longlong *)pplVar7;
                pplVar7 = (longlong **)pplVar9[2];
              }
              else {
                pplVar3[2] = (longlong *)pplVar7;
                *pplVar7 = (longlong *)pplVar9;
                *pplVar6 = (longlong *)pplVar7;
                pplVar7 = (longlong **)pplVar9[2];
              }
            }
          }
          if (*(char *)((longlong)pplVar7 + 0x19) == '\0') {
            if ((*(char *)(*pplVar7 + 3) != '\x01') || (*(char *)(pplVar7[2] + 3) != '\x01')) {
              if (*(char *)(pplVar7[2] + 3) == '\x01') {
                *(undefined *)(*pplVar7 + 3) = 1;
                plVar5 = *pplVar7;
                *(undefined *)(pplVar7 + 3) = 0;
                *pplVar7 = (longlong *)plVar5[2];
                if (*(char *)(plVar5[2] + 0x19) == '\0') {
                  *(longlong ***)(plVar5[2] + 8) = pplVar7;
                }
                plVar5[1] = (longlong)pplVar7[1];
                if (pplVar7 == *(longlong ***)(*param_1 + 8)) {
                  *(longlong **)(*param_1 + 8) = plVar5;
                }
                else {
                  pplVar6 = (longlong **)pplVar7[1];
                  if (pplVar7 == (longlong **)pplVar6[2]) {
                    pplVar6[2] = plVar5;
                  }
                  else {
                    *pplVar6 = plVar5;
                  }
                }
                plVar5[2] = (longlong)pplVar7;
                pplVar7[1] = plVar5;
                pplVar7 = (longlong **)pplVar9[2];
              }
              *(undefined *)(pplVar7 + 3) = *(undefined *)(pplVar9 + 3);
              *(undefined *)(pplVar9 + 3) = 1;
              *(undefined *)(pplVar7[2] + 3) = 1;
              pplVar7 = (longlong **)pplVar9[2];
              pplVar9[2] = *pplVar7;
              if (*(char *)((longlong)*pplVar7 + 0x19) == '\0') {
                (*pplVar7)[1] = (longlong)pplVar9;
              }
              pplVar7[1] = pplVar9[1];
              if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
                *(longlong ***)(*param_1 + 8) = pplVar7;
                *pplVar7 = (longlong *)pplVar9;
              }
              else {
                pplVar6 = (longlong **)pplVar9[1];
                if (pplVar9 == (longlong **)*pplVar6) {
                  *pplVar6 = (longlong *)pplVar7;
                  *pplVar7 = (longlong *)pplVar9;
                }
                else {
                  pplVar6[2] = (longlong *)pplVar7;
                  *pplVar7 = (longlong *)pplVar9;
                }
              }
LAB_18007aa1a:
              pplVar9[1] = (longlong *)pplVar7;
              pplVar9 = pplVar8;
              break;
            }
LAB_18007a8b0:
            *(undefined *)(pplVar7 + 3) = 0;
          }
        }
        else {
          if (*(char *)(pplVar7 + 3) == '\0') {
            *(undefined *)(pplVar7 + 3) = 1;
            plVar5 = *pplVar9;
            *(undefined *)(pplVar9 + 3) = 0;
            *pplVar9 = (longlong *)plVar5[2];
            if (*(char *)(plVar5[2] + 0x19) == '\0') {
              *(longlong ***)(plVar5[2] + 8) = pplVar9;
            }
            pplVar7 = pplVar9 + 1;
            plVar5[1] = (longlong)pplVar9[1];
            if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar5;
              plVar5[2] = (longlong)pplVar9;
              *pplVar7 = plVar5;
              pplVar7 = (longlong **)*pplVar9;
            }
            else {
              pplVar6 = (longlong **)*pplVar7;
              if (pplVar9 == (longlong **)pplVar6[2]) {
                pplVar6[2] = plVar5;
                plVar5[2] = (longlong)pplVar9;
                *pplVar7 = plVar5;
                pplVar7 = (longlong **)*pplVar9;
              }
              else {
                *pplVar6 = plVar5;
                plVar5[2] = (longlong)pplVar9;
                *pplVar7 = plVar5;
                pplVar7 = (longlong **)*pplVar9;
              }
            }
          }
          if (*(char *)((longlong)pplVar7 + 0x19) == '\0') {
            if ((*(char *)(pplVar7[2] + 3) != '\x01') || (*(char *)(*pplVar7 + 3) != '\x01')) {
              if (*(char *)(*pplVar7 + 3) == '\x01') {
                *(undefined *)(pplVar7[2] + 3) = 1;
                pplVar6 = (longlong **)pplVar7[2];
                *(undefined *)(pplVar7 + 3) = 0;
                pplVar7[2] = *pplVar6;
                if (*(char *)((longlong)*pplVar6 + 0x19) == '\0') {
                  (*pplVar6)[1] = (longlong)pplVar7;
                }
                pplVar6[1] = pplVar7[1];
                if (pplVar7 == *(longlong ***)(*param_1 + 8)) {
                  *(longlong ***)(*param_1 + 8) = pplVar6;
                }
                else {
                  pplVar3 = (longlong **)pplVar7[1];
                  if (pplVar7 == (longlong **)*pplVar3) {
                    *pplVar3 = (longlong *)pplVar6;
                  }
                  else {
                    pplVar3[2] = (longlong *)pplVar6;
                  }
                }
                *pplVar6 = (longlong *)pplVar7;
                pplVar7[1] = (longlong *)pplVar6;
                pplVar7 = (longlong **)*pplVar9;
              }
              *(undefined *)(pplVar7 + 3) = *(undefined *)(pplVar9 + 3);
              *(undefined *)(pplVar9 + 3) = 1;
              *(undefined *)(*pplVar7 + 3) = 1;
              pplVar7 = (longlong **)*pplVar9;
              *pplVar9 = pplVar7[2];
              if (*(char *)((longlong)pplVar7[2] + 0x19) == '\0') {
                pplVar7[2][1] = (longlong)pplVar9;
              }
              pplVar7[1] = pplVar9[1];
              if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
                *(longlong ***)(*param_1 + 8) = pplVar7;
              }
              else {
                pplVar6 = (longlong **)pplVar9[1];
                if (pplVar9 == (longlong **)pplVar6[2]) {
                  pplVar6[2] = (longlong *)pplVar7;
                }
                else {
                  *pplVar6 = (longlong *)pplVar7;
                }
              }
              pplVar7[2] = (longlong *)pplVar9;
              goto LAB_18007aa1a;
            }
            goto LAB_18007a8b0;
          }
        }
        if ((pplVar9 == *(longlong ***)(*param_1 + 8)) ||
           (pplVar7 = (longlong **)pplVar9[1], pplVar8 = pplVar9, *(char *)(pplVar9 + 3) != '\x01'))
        break;
      } while( true );
    }
    *(undefined *)(pplVar9 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x18007ac10 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18007ac10(undefined8 param_1,ulonglong param_2)

{
  longlong **pplVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong **pplVar4;
  longlong **pplVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong **pplVar8;
  longlong **pplVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong **pplVar12;
  
  pplVar9 = _DAT_181b50898;
  for (lVar11 = 0x3f; 0xfffffffffffffffU >> lVar11 == 0; lVar11 = lVar11 + -1) {
  }
  if ((ulonglong)(1L << ((byte)lVar11 & 0x3f)) < param_2) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d7808);
    pcVar7 = (code *)swi(3);
    (*pcVar7)();
    return;
  }
  uVar10 = param_2 - 1 | 1;
  lVar11 = 0x3f;
  if (uVar10 != 0) {
    for (; uVar10 >> lVar11 == 0; lVar11 = lVar11 + -1) {
    }
  }
  lVar11 = 1L << ((char)lVar11 + 1U & 0x3f);
  func_0x0001800674b0(&DAT_181b508a8,lVar11 * 2,_DAT_181b50898);
  _DAT_181b508c0 = lVar11 - 1;
  _DAT_181b508c8 = lVar11;
  pplVar8 = (longlong **)*_DAT_181b50898;
joined_r0x00018007ac92:
  do {
    while( true ) {
      while( true ) {
        if (pplVar8 == pplVar9) {
          return;
        }
        pplVar1 = (longlong **)*pplVar8;
        pplVar12 = (longlong **)
                   (((((((ulonglong)*(byte *)(pplVar8 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       (ulonglong)*(byte *)((longlong)pplVar8 + 0x11)) * 0x100000001b3 ^
                      (ulonglong)*(byte *)((longlong)pplVar8 + 0x12)) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)pplVar8 + 0x13)) * 0x100000001b3 &
                    _DAT_181b508c0) * 0x10 + _DAT_181b508a8);
        if ((longlong **)*pplVar12 != pplVar9) break;
        *pplVar12 = (longlong *)pplVar8;
        pplVar12[1] = (longlong *)pplVar8;
        pplVar8 = pplVar1;
      }
      pplVar2 = (longlong **)pplVar12[1];
      if (*(int *)(pplVar8 + 2) != *(int *)(pplVar2 + 2)) break;
      pplVar2 = (longlong **)*pplVar2;
      if (pplVar2 != pplVar8) {
        pplVar3 = (longlong **)pplVar8[1];
        *pplVar3 = (longlong *)pplVar1;
        pplVar4 = (longlong **)pplVar1[1];
        *pplVar4 = (longlong *)pplVar2;
        pplVar5 = (longlong **)pplVar2[1];
        *pplVar5 = (longlong *)pplVar8;
        pplVar2[1] = (longlong *)pplVar4;
        pplVar1[1] = (longlong *)pplVar3;
        pplVar8[1] = (longlong *)pplVar5;
      }
      pplVar12[1] = (longlong *)pplVar8;
      pplVar8 = pplVar1;
    }
    do {
      if ((longlong **)*pplVar12 == pplVar2) {
        pplVar3 = (longlong **)pplVar8[1];
        *pplVar3 = (longlong *)pplVar1;
        plVar6 = pplVar1[1];
        *plVar6 = (longlong)pplVar2;
        pplVar4 = (longlong **)pplVar2[1];
        *pplVar4 = (longlong *)pplVar8;
        pplVar2[1] = plVar6;
        pplVar1[1] = (longlong *)pplVar3;
        pplVar8[1] = (longlong *)pplVar4;
        *pplVar12 = (longlong *)pplVar8;
        pplVar8 = pplVar1;
        goto joined_r0x00018007ac92;
      }
      pplVar2 = (longlong **)pplVar2[1];
    } while (*(int *)(pplVar8 + 2) != *(int *)(pplVar2 + 2));
    lVar11 = (longlong)*pplVar2;
    pplVar12 = (longlong **)pplVar8[1];
    *pplVar12 = (longlong *)pplVar1;
    plVar6 = pplVar1[1];
    *plVar6 = lVar11;
    pplVar2 = *(longlong ***)(lVar11 + 8);
    *pplVar2 = (longlong *)pplVar8;
    *(longlong **)(lVar11 + 8) = plVar6;
    pplVar1[1] = (longlong *)pplVar12;
    pplVar8[1] = (longlong *)pplVar2;
    pplVar8 = pplVar1;
  } while( true );
}



/* ===== ANALYSIS FUNCTION 0x18007add0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18007add0(longlong param_1,ulonglong param_2)

{
  longlong **pplVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong **pplVar5;
  longlong *plVar6;
  longlong *plVar7;
  code *pcVar8;
  longlong **pplVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong **pplVar12;
  
  for (lVar11 = 0x3f; 0xfffffffffffffffU >> lVar11 == 0; lVar11 = lVar11 + -1) {
  }
  if ((ulonglong)(1L << ((byte)lVar11 & 0x3f)) < param_2) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d7808);
    pcVar8 = (code *)swi(3);
    (*pcVar8)();
    return;
  }
  pplVar1 = *(longlong ***)(param_1 + 8);
  uVar10 = param_2 - 1 | 1;
  lVar11 = 0x3f;
  if (uVar10 != 0) {
    for (; uVar10 >> lVar11 == 0; lVar11 = lVar11 + -1) {
    }
  }
  lVar11 = 1L << ((char)lVar11 + 1U & 0x3f);
  func_0x0001800674b0(param_1 + 0x18,lVar11 * 2,pplVar1);
  *(longlong *)(param_1 + 0x38) = lVar11;
  *(longlong *)(param_1 + 0x30) = lVar11 + -1;
  pplVar9 = (longlong **)**(undefined8 **)(param_1 + 8);
joined_r0x00018007ae4f:
  do {
    while( true ) {
      while( true ) {
        if (pplVar9 == pplVar1) {
          return;
        }
        pplVar2 = (longlong **)*pplVar9;
        pplVar12 = (longlong **)
                   (((((((ulonglong)*(byte *)(pplVar9 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       (ulonglong)*(byte *)((longlong)pplVar9 + 0x11)) * 0x100000001b3 ^
                      (ulonglong)*(byte *)((longlong)pplVar9 + 0x12)) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)pplVar9 + 0x13)) * 0x100000001b3 &
                    *(ulonglong *)(param_1 + 0x30)) * 0x10 + *(longlong *)(param_1 + 0x18));
        if ((longlong **)*pplVar12 != pplVar1) break;
        *pplVar12 = (longlong *)pplVar9;
        pplVar12[1] = (longlong *)pplVar9;
        pplVar9 = pplVar2;
      }
      pplVar3 = (longlong **)pplVar12[1];
      if (*(int *)(pplVar9 + 2) != *(int *)(pplVar3 + 2)) break;
      pplVar3 = (longlong **)*pplVar3;
      if (pplVar3 != pplVar9) {
        plVar4 = pplVar9[1];
        *plVar4 = (longlong)pplVar2;
        pplVar5 = (longlong **)pplVar2[1];
        *pplVar5 = (longlong *)pplVar3;
        plVar6 = pplVar3[1];
        *plVar6 = (longlong)pplVar9;
        pplVar3[1] = (longlong *)pplVar5;
        pplVar2[1] = plVar4;
        pplVar9[1] = plVar6;
      }
      pplVar12[1] = (longlong *)pplVar9;
      pplVar9 = pplVar2;
    }
    do {
      if ((longlong **)*pplVar12 == pplVar3) {
        plVar4 = pplVar9[1];
        *plVar4 = (longlong)pplVar2;
        pplVar5 = (longlong **)pplVar2[1];
        *pplVar5 = (longlong *)pplVar3;
        plVar6 = pplVar3[1];
        *plVar6 = (longlong)pplVar9;
        pplVar3[1] = (longlong *)pplVar5;
        pplVar2[1] = plVar4;
        pplVar9[1] = plVar6;
        *pplVar12 = (longlong *)pplVar9;
        pplVar9 = pplVar2;
        goto joined_r0x00018007ae4f;
      }
      pplVar3 = (longlong **)pplVar3[1];
    } while (*(int *)(pplVar9 + 2) != *(int *)(pplVar3 + 2));
    plVar4 = *pplVar3;
    plVar6 = pplVar9[1];
    *plVar6 = (longlong)pplVar2;
    pplVar12 = (longlong **)pplVar2[1];
    *pplVar12 = plVar4;
    plVar7 = (longlong *)plVar4[1];
    *plVar7 = (longlong)pplVar9;
    plVar4[1] = (longlong)pplVar12;
    pplVar2[1] = plVar6;
    pplVar9[1] = plVar7;
    pplVar9 = pplVar2;
  } while( true );
}



/* ===== ANALYSIS FUNCTION 0x18007b0b0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18007b0b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined4 *puVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined auStack_78 [4];
  undefined auStack_74 [2];
  undefined auStack_72 [2];
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined auStack_58 [16];
  undefined auStack_48 [8];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined uStack_36;
  
  lVar9 = _DAT_181b2f550;
  if ((_DAT_181b4efe8 != 4) || (_DAT_181b2f548 == _DAT_181b2f550)) {
    lVar11 = _DAT_181b2f548;
    if (_DAT_181b2f548 != _DAT_181b2f550) {
      do {
        recovered_180066e40(lVar11 + 0x20);
        recovered_180066e40(lVar11);
        lVar11 = lVar11 + 0x48;
      } while (lVar11 != lVar9);
      _DAT_181b2f550 = _DAT_181b2f548;
    }
    lVar9 = _DAT_181b2f550;
    lVar11 = (_DAT_181b2f550 - _DAT_181b2f548) / 0x12 + (_DAT_181b2f550 - _DAT_181b2f548 >> 0x3f);
    uVar13 = (lVar11 >> 2) - (lVar11 >> 0x3f);
    if (uVar13 < 0x61a9) {
      lVar11 = _DAT_181b2f550;
      if (uVar13 < 25000) {
        if ((ulonglong)((_DAT_181b2f558 - _DAT_181b2f548) / 0x48) < 25000) {
          recovered_1800802c0();
          lVar11 = _DAT_181b2f550;
        }
        else {
          lVar11 = func_0x000180080520(_DAT_181b2f550,25000 - uVar13);
        }
      }
    }
    else {
      lVar11 = _DAT_181b2f548 + 1800000;
      for (lVar12 = lVar11; lVar12 != lVar9; lVar12 = lVar12 + 0x48) {
        recovered_180066e40(lVar12 + 0x20);
        recovered_180066e40(lVar12);
      }
    }
    _DAT_181b2f550 = lVar11;
    lVar9 = _DAT_181b2f548;
    uVar7 = _UNK_181a0355c;
    uVar6 = _UNK_181a03558;
    uVar5 = _UNK_181a03554;
    uVar4 = _DAT_181a03550;
    _DAT_181b4efe8 = 4;
    uStack_68 = _DAT_181a035d0;
    uStack_60 = _UNK_181a035d8;
    uStack_70._0_4_ = _DAT_1819d7988;
    _auStack_78 = _DAT_1819d7980;
    uStack_70._4_4_ = 0;
    auStack_48._4_4_ = _UNK_181a03554;
    auStack_48._0_4_ = _DAT_181a03550;
    uStack_40 = _UNK_181a03558;
    uStack_3c = _UNK_181a0355c;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7990 & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x69c00,auStack_78);
    recovered_1800785e0(lVar9 + 0x69c20,auStack_58);
    *(undefined *)(lVar9 + 0x69c40) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x69c41) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x69c42) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a035b0;
    uStack_60 = _UNK_181a035b8;
    uStack_70._0_2_ = _DAT_1819d79a0;
    _auStack_78 = _DAT_1819d7998;
    uStack_70._2_6_ = 0;
    auStack_48._4_4_ = uVar5;
    auStack_48._0_4_ = uVar4;
    uStack_40 = uVar6;
    uStack_3c = uVar7;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7990 & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0xafe30,auStack_78);
    recovered_1800785e0(lVar9 + 0xafe50,auStack_58);
    *(undefined *)(lVar9 + 0xafe70) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0xafe71) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0xafe72) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    _auStack_78 = ZEXT816(0);
    puVar10 = (undefined4 *)func_0x000180024110(0x20);
    uVar3 = _UNK_1819d79b4;
    uVar2 = _UNK_1819d79b0;
    uVar1 = _UNK_1819d79ac;
    _auStack_78 = puVar10;
    uStack_68 = CONCAT44(_UNK_181a03614,_DAT_181a03610);
    uStack_60 = CONCAT44(_UNK_181a0361c,_UNK_181a03618);
    *puVar10 = _DAT_1819d79a8;
    puVar10[1] = uVar1;
    puVar10[2] = uVar2;
    puVar10[3] = uVar3;
    *(undefined2 *)(puVar10 + 4) = _DAT_1819d79b8;
    *(undefined *)((longlong)puVar10 + 0x12) = 0;
    lVar9 = _DAT_181b2f548;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d79bc & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0xa6920,auStack_78);
    recovered_1800785e0(lVar9 + 0xa6940,auStack_58);
    *(undefined *)(lVar9 + 0xa6960) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0xa6961) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0xa6962) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    _auStack_78 = ZEXT816(0);
    puVar10 = (undefined4 *)func_0x000180024110(0x20);
    uVar3 = _UNK_1819d79cc;
    uVar2 = _UNK_1819d79c8;
    uVar1 = _UNK_1819d79c4;
    _auStack_78 = puVar10;
    uStack_68 = CONCAT44(_UNK_181a03634,_DAT_181a03630);
    uStack_60 = CONCAT44(_UNK_181a0363c,_UNK_181a03638);
    *puVar10 = _DAT_1819d79c0;
    puVar10[1] = uVar1;
    puVar10[2] = uVar2;
    puVar10[3] = uVar3;
    *(undefined8 *)(puVar10 + 4) = _DAT_1819d79d0;
    *(undefined2 *)(puVar10 + 6) = _DAT_1819d79d8;
    *(undefined *)((longlong)puVar10 + 0x1a) = 0;
    lVar9 = _DAT_181b2f548;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d79bc & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0xa69f8,auStack_78);
    recovered_1800785e0(lVar9 + 0xa6a18,auStack_58);
    *(undefined *)(lVar9 + 0xa6a38) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0xa6a39) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0xa6a3a) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a035f0;
    uStack_60 = _UNK_181a035f8;
    uStack_70._0_4_ = _DAT_1819d79e8;
    _auStack_78 = _DAT_1819d79e0;
    uStack_70._4_2_ = _DAT_1819d79ec;
    uStack_70._6_2_ = 0;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d79bc & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x171288,auStack_78);
    recovered_1800785e0(lVar9 + 0x1712a8,auStack_58);
    *(undefined *)(lVar9 + 0x1712c8) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x1712c9) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x1712ca) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uVar8 = _UNK_181a0356c;
    uVar3 = _UNK_181a03568;
    uVar2 = _UNK_181a03564;
    uVar1 = _DAT_181a03560;
    uStack_68 = CONCAT44(_UNK_181a03564,_DAT_181a03560);
    uStack_60 = CONCAT44(_UNK_181a0356c,_UNK_181a03568);
    stack0xffffffffffffff8d = SUB1611(ZEXT816(0),5);
    _auStack_78 = 0x3039354d;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d79f8 & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x1712d0,auStack_78);
    recovered_1800785e0(lVar9 + 0x1712f0,auStack_58);
    *(undefined *)(lVar9 + 0x171310) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x171311) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x171312) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(uVar2,uVar1);
    uStack_60 = CONCAT44(uVar8,uVar3);
    stack0xffffffffffffff8d = SUB1611(ZEXT816(0),5);
    _auStack_78 = 0x74736946;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a04 & 0xffffff;
    uStack_38 = 1;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x1717e0,auStack_78);
    recovered_1800785e0(lVar9 + 0x171800,auStack_58);
    *(undefined *)(lVar9 + 0x171820) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x171821) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x171822) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(uVar2,uVar1);
    uStack_60 = CONCAT44(uVar8,uVar3);
    stack0xffffffffffffff8d = SUB1611(ZEXT816(0),5);
    _auStack_78 = 0x37344b41;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a10 & 0xffffff;
    uStack_38 = 0;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548,auStack_78);
    recovered_1800785e0(lVar9 + 0x20,auStack_58);
    *(undefined *)(lVar9 + 0x40) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x41) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x42) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(uVar2,uVar1);
    uStack_60 = CONCAT44(uVar8,uVar3);
    stack0xffffffffffffff8d = SUB1611(ZEXT816(0),5);
    _auStack_78 = 0x3141344d;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a1c & 0xffffff;
    uStack_38 = 0;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x90,auStack_78);
    recovered_1800785e0(lVar9 + 0xb0,auStack_58);
    *(undefined *)(lVar9 + 0xd0) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0xd1) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0xd2) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03580;
    uStack_60 = _UNK_181a03588;
    auStack_74 = (undefined  [2])_DAT_1819d7a24;
    auStack_78 = (undefined  [4])_DAT_1819d7a20;
    stack0xffffffffffffff8f = SUB169(ZEXT816(0),7);
    auStack_72[0] = 0;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a1c & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x1680,auStack_78);
    recovered_1800785e0(lVar9 + 0x16a0,auStack_58);
    *(undefined *)(lVar9 + 0x16c0) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x16c1) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x16c2) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03590;
    uStack_60 = _UNK_181a03598;
    _auStack_78 = CONCAT24(_DAT_1819d7a2c,_DAT_1819d7a28);
    _auStack_78 = CONCAT16(DAT_1819d7a2e,_auStack_78);
    _auStack_78 = ZEXT716(_auStack_78);
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a1c & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x16c8,auStack_78);
    recovered_1800785e0(lVar9 + 0x16e8,auStack_58);
    *(undefined *)(lVar9 + 0x1708) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x1709) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x170a) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(_UNK_181a035a4,_DAT_181a035a0);
    uStack_60 = CONCAT44(_UNK_181a035ac,_UNK_181a035a8);
    _auStack_78 = (unkuint9)0x4949492d3141344d;
    uStack_70._1_7_ = 0;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a1c & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x1710,auStack_78);
    recovered_1800785e0(lVar9 + 0x1730,auStack_58);
    *(undefined *)(lVar9 + 0x1750) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x1751) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x1752) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(uVar2,uVar1);
    uStack_60 = CONCAT44(uVar8,uVar3);
    stack0xffffffffffffff8d = SUB1611(ZEXT816(0),5);
    _auStack_78 = 0x37344b41;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a10 & 0xffffff;
    uStack_38 = 0;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x1b0,auStack_78);
    recovered_1800785e0(lVar9 + 0x1d0,auStack_58);
    *(undefined *)(lVar9 + 0x1f0) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x1f1) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x1f2) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(uVar5,uVar4);
    uStack_60 = CONCAT44(uVar7,uVar6);
    _auStack_74 = SUB1612(ZEXT816(0),4);
    auStack_78 = (undefined  [4])(_DAT_1819d7a3c & 0xffffff);
    auStack_58._0_4_ = _DAT_1819d7a40 & 0xffffff;
    auStack_58._4_12_ = _auStack_74;
    uStack_38 = 0;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x318,auStack_78);
    recovered_1800785e0(lVar9 + 0x338,auStack_58);
    *(undefined *)(lVar9 + 0x358) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x359) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x35a) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03570;
    uStack_60 = _UNK_181a03578;
    auStack_74[0] = DAT_1819d7a48;
    auStack_78 = (undefined  [4])_DAT_1819d7a44;
    _auStack_72 = SUB1610(ZEXT816(0),6);
    auStack_74[1] = 0;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a40 & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x11b8,auStack_78);
    recovered_1800785e0(lVar9 + 0x11d8,auStack_58);
    *(undefined *)(lVar9 + 0x11f8) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x11f9) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x11fa) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03580;
    uStack_60 = _UNK_181a03588;
    auStack_74 = (undefined  [2])_DAT_1819d7a50;
    auStack_78 = (undefined  [4])_DAT_1819d7a4c;
    stack0xffffffffffffff8f = SUB169(ZEXT816(0),7);
    auStack_72[0] = 0;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a40 & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x2370,auStack_78);
    recovered_1800785e0(lVar9 + 0x2390,auStack_58);
    *(undefined *)(lVar9 + 0x23b0) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x23b1) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x23b2) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03590;
    uStack_60 = _UNK_181a03598;
    _auStack_78 = CONCAT24(_DAT_1819d7a5c,_DAT_1819d7a58);
    _auStack_78 = CONCAT16(DAT_1819d7a5e,_auStack_78);
    _auStack_78 = ZEXT716(_auStack_78);
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a40 & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x23b8,auStack_78);
    recovered_1800785e0(lVar9 + 0x23d8,auStack_58);
    *(undefined *)(lVar9 + 0x23f8) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x23f9) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x23fa) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = CONCAT44(uVar2,uVar1);
    uStack_60 = CONCAT44(uVar8,uVar3);
    stack0xffffffffffffff8d = SUB1611(ZEXT816(0),5);
    _auStack_78 = 0x52414353;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a68 & 0xffffff;
    uStack_38 = 0;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x360,auStack_78);
    recovered_1800785e0(lVar9 + 0x380,auStack_58);
    *(undefined *)(lVar9 + 0x3a0) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x3a1) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x3a2) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03580;
    uStack_60 = _UNK_181a03588;
    auStack_74 = (undefined  [2])_DAT_1819d7a70;
    auStack_78 = (undefined  [4])_DAT_1819d7a6c;
    stack0xffffffffffffff8f = SUB169(ZEXT816(0),7);
    auStack_72[0] = 0;
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a68 & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x3210,auStack_78);
    recovered_1800785e0(lVar9 + 0x3230,auStack_58);
    *(undefined *)(lVar9 + 0x3250) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x3251) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x3252) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    lVar9 = _DAT_181b2f548;
    uStack_68 = _DAT_181a03590;
    uStack_60 = _UNK_181a03598;
    _auStack_78 = CONCAT24(_DAT_1819d7a7c,_DAT_1819d7a78);
    _auStack_78 = CONCAT16(DAT_1819d7a7e,_auStack_78);
    _auStack_78 = ZEXT716(_auStack_78);
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7a68 & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    recovered_1800785e0(_DAT_181b2f548 + 0x3258,auStack_78);
    recovered_1800785e0(lVar9 + 0x3278,auStack_58);
    *(undefined *)(lVar9 + 0x3298) = (undefined)uStack_38;
    *(undefined *)(lVar9 + 0x3299) = uStack_38._1_1_;
    *(undefined *)(lVar9 + 0x329a) = uStack_36;
    recovered_180066e40(auStack_58);
    recovered_180066e40(auStack_78);
    auStack_58 = ZEXT816(0);
    uStack_68 = CONCAT44(_UNK_181a035a4,_DAT_181a035a0);
    uStack_60 = CONCAT44(_UNK_181a035ac,_UNK_181a035a8);
    _auStack_78 = (unkuint9)0x4949492d52414353;
    uStack_70._1_7_ = 0;
    _auStack_48 = ZEXT816(0);
    uVar14 = recovered_180066cc0(auStack_58,&DAT_1819d7a68,3);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xb4);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7a8c);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7a94);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xe);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7a98);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7a94);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x46);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7aa0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7aa8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x18);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ab0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7aa8);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x43);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ab8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7aa8);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x82);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ac8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7aa8);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x83);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ad4);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7ad8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x1c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7adc);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7ae4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x21);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ae8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7af0);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x27);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7af4);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7af8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x2e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7afc);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7af8);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xc1);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b04);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7af8);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xc2);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b10);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7af8);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xc3);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b18);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b20);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x2f);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b24);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b2c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x96);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b30);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b34);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x49);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b38);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b34);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x4a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b40);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b44);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x12);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b48);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b4c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x1a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b50);
    auStack_58._4_12_ = SUB1612(ZEXT816(0),4);
    auStack_58._0_4_ = _DAT_1819d7b4c & 0xffffff;
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180();
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b58);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b64);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x30);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b58);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b64);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x39);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b68);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b70);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x6d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b74);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b7c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x59);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b80);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x13);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b8c);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b88);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x47);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b94);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b98);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x1e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7b9c);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b98);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x3d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ba4);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b98);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x7a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bb0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b98);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x7b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bb8);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x36);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bc0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7bc4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,7);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bc8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bcc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,8);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bd0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bcc);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x3c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bd8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bcc);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x78);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7be0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bcc);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x79);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7be8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bec);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xd);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bf0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bec);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x3e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7bf8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bec);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x7c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c00);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7bec);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x7d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c08);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c10);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xf);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c14);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c18);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x20);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c1c);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c24);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x23);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c28);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c34);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x2b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c38);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c40);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x31);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c48);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c58);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x45);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c5c);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c64);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x58);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c68);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c64);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xe4);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c70);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c64);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xe5);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c80);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7c64);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xe6);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c8c);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7c94);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,5);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7c98);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7c94);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xb8);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ca0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7c94);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xb9);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7cb0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7c94);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xba);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7cbc);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7cc4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x1d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7cc8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7cd0);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x29);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7cd8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7cd0);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x77);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ce0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7ce8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x32);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7cf0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7cd0);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x56);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d00);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d10);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xb5);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d18);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d10);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xb6);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d28);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7d2c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,4);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d30);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7d2c);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x41);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d38);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x15);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d48);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x40);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d58);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x80);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d68);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x81);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d74);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d7c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x2d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d80);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d84);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x4b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d88);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d84);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x4e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d94);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d9c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xc5);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7da0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7da4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,3);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7da8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7db0);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x38);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7db8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7dc8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,9);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7dcc);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7dd0);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,10);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7dd4);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7ddc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x14);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7de0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7de8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x19);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7dec);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7df4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x37);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7df8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e04);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x3a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&DAT_1819d79e0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x5d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e08);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7e0c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x10);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e10);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e18);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x11);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e1c);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e20);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x1b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e24);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e18);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x22);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e2c);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e34);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x33);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e38);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e44);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x35);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d79fc);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7a04);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,1);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e48);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x259);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e50);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e60);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x25b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e68);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e78);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x25a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e80);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e8c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x260);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e90);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e94);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x17);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7e98);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d7c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x24);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ea0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x25);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ea8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b20);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x2c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7eb0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e94);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0xc4);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7eb8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b7c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x57);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ec0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b98);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x60);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ec8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7ed4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x62);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ed8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7b20);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x65);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7d88);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d84);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x66);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ee0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7a68);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x67);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7eec);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7a1c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x68);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ef8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x5a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ef8);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x69);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f08);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x6a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f18);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7d40);
    uStack_38 = 0x100;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x6b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f28);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x4c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f38);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b44);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x88);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f48);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7dc8);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x89);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f58);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e8c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x8a);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f60);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7f70);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x8b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f78);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7f88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x8e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f90);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x25c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7fa0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7f88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,100);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7fb0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,99);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7fc0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e8c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x269);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7fd0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x579);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7fe0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x3ee);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7ff0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x3f7);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8000);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x5b);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8010);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7f88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x5c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8020);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x5e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8030);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x5f);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8040);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7ed4);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x61);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d804c);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x6e);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8058);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x6f);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8068);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x70);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8078);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x71);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8088);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x72);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8098);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x73);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80a8);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x74);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80b4);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x75);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80b8);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7b44);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x76);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80c0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7f70);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x84);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80d0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7f88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x85);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80e0);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x86);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d80f0);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e8c);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x87);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d7f90);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7990);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x8c);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8100);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d79bc);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x8d);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8110);
    uVar14 = recovered_180066c80(auStack_58,&DAT_1819d7f88);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x8f);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8120);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7e04);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x90);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
    recovered_180066c80(auStack_78,&UNK_1819d8130);
    uVar14 = recovered_180066c80(auStack_58,&UNK_1819d7f70);
    uStack_38 = 0;
    uStack_36 = 0;
    uVar14 = func_0x000180080180(uVar14,0x91);
    recovered_18007e980(uVar14,auStack_78);
    recovered_18007e960(auStack_78);
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18007e960 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18007e960(longlong *param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  recovered_180066e40(param_1 + 4);
  if (0xf < (ulonglong)param_1[3]) {
    lVar1 = *param_1;
    lVar3 = lVar1;
    if ((0xfff < param_1[3] + 1U) &&
       (lVar3 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar3) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(lVar3);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined *)param_1 = 0;
  return;
}



/* ===== ANALYSIS FUNCTION 0x18007e980 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong recovered_18007e980(longlong param_1,longlong param_2)

{
  recovered_1800785e0();
  recovered_1800785e0(param_1 + 0x20,param_2 + 0x20);
  *(undefined *)(param_1 + 0x40) = *(undefined *)(param_2 + 0x40);
  *(undefined *)(param_1 + 0x41) = *(undefined *)(param_2 + 0x41);
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_2 + 0x42);
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18007ea60 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_18007ea60(void)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = func_0x00018007e9d0();
  iVar1 = (int)uVar2;
  if ((-1 < iVar1) &&
     (uVar2 = (_DAT_181b2f550 - _DAT_181b2f548) * 0xe38e38e38e38e39,
     iVar1 < (int)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) {
    return CONCAT71((int7)(uVar2 >> 8),
                    *(char *)(_DAT_181b2f548 + 0x42 + (longlong)iVar1 * 0x48) == '\0');
  }
  return uVar2 & 0xffffffffffffff00;
}



/* ===== ANALYSIS FUNCTION 0x18007eac0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_18007eac0(undefined (*param_1) [16],undefined2 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = 0;
  iVar1 = func_0x00018007e9d0(param_2);
  lVar2 = (longlong)iVar1;
  if ((((-1 < iVar1) && (iVar1 < (int)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) &&
      (*(char *)(_DAT_181b2f548 + 0x42 + lVar2 * 0x48) == (char)lVar3)) &&
     ((*(longlong *)(_DAT_181b2f548 + 0x10 + lVar2 * 0x48) != lVar3 ||
      (*(char *)(_DAT_181b2f548 + 0x40 + lVar2 * 0x48) != (char)lVar3)))) {
    recovered_180080190(param_1,_DAT_181b2f548 + lVar2 * 0x48);
    return param_1;
  }
  *param_1 = ZEXT816(0);
  *(longlong *)param_1[1] = lVar3;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18007eb60 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_18007eb60(undefined (*param_1) [16],undefined2 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  undefined *puVar6;
  undefined (*pauVar7) [16];
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined uStackX_18;
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined auStack_38 [16];
  ulonglong uStack_28;
  
  iVar4 = func_0x00018007e9d0(param_2);
  if ((-1 < iVar4) &&
     ((ulonglong)(longlong)iVar4 < (ulonglong)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) {
    lVar8 = (longlong)iVar4 * 0x48;
    if (*(char *)(lVar8 + 0x42 + _DAT_181b2f548) != '\0') {
      *param_1 = ZEXT816(0);
      *(undefined8 *)param_1[1] = 0;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      (*param_1)[0] = 0;
      return param_1;
    }
    puVar10 = (undefined8 *)(_DAT_181b2f548 + lVar8);
    if (*(longlong *)(lVar8 + 0x30 + _DAT_181b2f548) != 0) {
      if (*(char *)(lVar8 + 0x41 + _DAT_181b2f548) == '\0') {
        recovered_180080190(param_1,puVar10 + 4);
        return param_1;
      }
      recovered_18007fe70(auStack_38,puVar10);
      puVar10 = (undefined8 *)(_DAT_181b2f548 + lVar8);
      auStack_58 = ZEXT816(0);
      auStack_48 = ZEXT816(0);
      if ((ulonglong)puVar10[2] < uStack_28) {
        recovered_180067b60();
      }
      else {
        lVar5 = puVar10[2] - uStack_28;
        lVar9 = -1;
        if (lVar5 != -1) {
          lVar9 = lVar5;
        }
        if (0xf < (ulonglong)puVar10[3]) {
          puVar10 = (undefined8 *)*puVar10;
        }
        recovered_180066cc0(auStack_58,uStack_28 + (longlong)puVar10,lVar9);
        puVar10 = (undefined8 *)(_DAT_181b2f548 + 0x20 + lVar8);
        if ((ulonglong)auStack_48._0_8_ <= 0x7fffffffffffffff - puVar10[2]) {
          puVar11 = puVar10;
          if (0xf < (ulonglong)puVar10[3]) {
            puVar11 = (undefined8 *)*puVar10;
          }
          puVar6 = auStack_58;
          if (0xf < (ulonglong)auStack_48._8_8_) {
            puVar6 = (undefined *)auStack_58._0_8_;
          }
          recovered_180067040(param_1,uStackX_18,puVar10,puVar11,puVar10[2],puVar6,auStack_48._0_8_)
          ;
          if (0xf < (ulonglong)auStack_48._8_8_) {
            if ((0xfff < auStack_48._8_8_ + 1) &&
               (0x1f < (auStack_58._0_8_ - *(longlong *)(auStack_58._0_8_ + -8)) - 8U)) {
              _invoke_watson(0,0,0,0,0);
              pcVar3 = (code *)swi(3);
              pauVar7 = (undefined (*) [16])(*pcVar3)();
              return pauVar7;
            }
            func_0x000180127e40();
          }
          recovered_180066e40(auStack_38);
          return param_1;
        }
      }
      func_0x000180052a50();
      pcVar3 = (code *)swi(3);
      pauVar7 = (undefined (*) [16])(*pcVar3)();
      return pauVar7;
    }
    uVar2 = puVar10[2];
    if (uVar2 != 0) {
      puVar11 = puVar10;
      if (0xf < (ulonglong)puVar10[3]) {
        puVar11 = (undefined8 *)*puVar10;
      }
      if (((uVar2 < 3) ||
          (lVar8 = func_0x0001801278a0(puVar11,(longlong)puVar11 + uVar2,&UNK_1819d7d28,3),
          lVar8 == (longlong)puVar11 + uVar2)) || (lVar8 - (longlong)puVar11 == -1)) {
        puVar11 = puVar10;
        if (0xf < (ulonglong)puVar10[3]) {
          puVar11 = (undefined8 *)*puVar10;
        }
        if ((((ulonglong)puVar10[2] < 5) ||
            (lVar8 = puVar10[2] + (longlong)puVar11,
            lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8140,5), lVar9 == lVar8)) ||
           (lVar9 - (longlong)puVar11 == -1)) {
          puVar11 = puVar10;
          if (0xf < (ulonglong)puVar10[3]) {
            puVar11 = (undefined8 *)*puVar10;
          }
          if ((((ulonglong)puVar10[2] < 3) ||
              (lVar8 = puVar10[2] + (longlong)puVar11,
              lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8148,3), lVar9 == lVar8)) ||
             (lVar9 - (longlong)puVar11 == -1)) {
            puVar11 = puVar10;
            if (0xf < (ulonglong)puVar10[3]) {
              puVar11 = (undefined8 *)*puVar10;
            }
            if ((((ulonglong)puVar10[2] < 3) ||
                (lVar8 = puVar10[2] + (longlong)puVar11,
                lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7d80,3), lVar9 == lVar8)) ||
               (lVar9 - (longlong)puVar11 == -1)) {
              puVar11 = puVar10;
              if (0xf < (ulonglong)puVar10[3]) {
                puVar11 = (undefined8 *)*puVar10;
              }
              if ((((ulonglong)puVar10[2] < 6) ||
                  (lVar8 = puVar10[2] + (longlong)puVar11,
                  lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d814c,6), lVar9 == lVar8)) ||
                 (lVar9 - (longlong)puVar11 == -1)) {
                puVar11 = puVar10;
                if (0xf < (ulonglong)puVar10[3]) {
                  puVar11 = (undefined8 *)*puVar10;
                }
                if ((((ulonglong)puVar10[2] < 3) ||
                    (lVar8 = puVar10[2] + (longlong)puVar11,
                    lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7b48,3), lVar9 == lVar8)) ||
                   (lVar9 - (longlong)puVar11 == -1)) {
                  puVar11 = puVar10;
                  if (0xf < (ulonglong)puVar10[3]) {
                    puVar11 = (undefined8 *)*puVar10;
                  }
                  if ((((ulonglong)puVar10[2] < 3) ||
                      (lVar8 = puVar10[2] + (longlong)puVar11,
                      lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8154,3), lVar9 == lVar8))
                     || (lVar9 - (longlong)puVar11 == -1)) {
                    puVar11 = puVar10;
                    if (0xf < (ulonglong)puVar10[3]) {
                      puVar11 = (undefined8 *)*puVar10;
                    }
                    if ((((ulonglong)puVar10[2] < 10) ||
                        (lVar8 = puVar10[2] + (longlong)puVar11,
                        lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7ef8,10), lVar9 == lVar8
                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                      puVar11 = puVar10;
                      if (0xf < (ulonglong)puVar10[3]) {
                        puVar11 = (undefined8 *)*puVar10;
                      }
                      if ((((ulonglong)puVar10[2] < 5) ||
                          (lVar8 = puVar10[2] + (longlong)puVar11,
                          lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7c8c,5),
                          lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                        puVar11 = puVar10;
                        if (0xf < (ulonglong)puVar10[3]) {
                          puVar11 = (undefined8 *)*puVar10;
                        }
                        if ((((ulonglong)puVar10[2] < 4) ||
                            (lVar8 = puVar10[2] + (longlong)puVar11,
                            lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8158,4),
                            lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                          puVar11 = puVar10;
                          if (0xf < (ulonglong)puVar10[3]) {
                            puVar11 = (undefined8 *)*puVar10;
                          }
                          if ((((ulonglong)puVar10[2] < 5) ||
                              (lVar8 = puVar10[2] + (longlong)puVar11,
                              lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7cc8,5),
                              lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                            puVar11 = puVar10;
                            if (0xf < (ulonglong)puVar10[3]) {
                              puVar11 = (undefined8 *)*puVar10;
                            }
                            if ((((ulonglong)puVar10[2] < 3) ||
                                (lVar8 = puVar10[2] + (longlong)puVar11,
                                lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8160,3),
                                lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                              puVar11 = puVar10;
                              if (0xf < (ulonglong)puVar10[3]) {
                                puVar11 = (undefined8 *)*puVar10;
                              }
                              if ((((ulonglong)puVar10[2] < 7) ||
                                  (lVar8 = puVar10[2] + (longlong)puVar11,
                                  lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8168,7),
                                  lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                puVar11 = puVar10;
                                if (0xf < (ulonglong)puVar10[3]) {
                                  puVar11 = (undefined8 *)*puVar10;
                                }
                                if ((((ulonglong)puVar10[2] < 6) ||
                                    (lVar8 = puVar10[2] + (longlong)puVar11,
                                    lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8170,6),
                                    lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                  puVar11 = puVar10;
                                  if (0xf < (ulonglong)puVar10[3]) {
                                    puVar11 = (undefined8 *)*puVar10;
                                  }
                                  if ((((ulonglong)puVar10[2] < 0xd) ||
                                      (lVar8 = puVar10[2] + (longlong)puVar11,
                                      lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7cf0,0xd),
                                      lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                    puVar11 = puVar10;
                                    if (0xf < (ulonglong)puVar10[3]) {
                                      puVar11 = (undefined8 *)*puVar10;
                                    }
                                    if ((((ulonglong)puVar10[2] < 4) ||
                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d79f0,4),
                                        lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                      puVar11 = puVar10;
                                      if (0xf < (ulonglong)puVar10[3]) {
                                        puVar11 = (undefined8 *)*puVar10;
                                      }
                                      if ((((ulonglong)puVar10[2] < 3) ||
                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7bc0,3
                                                                     ), lVar9 == lVar8)) ||
                                         (lVar9 - (longlong)puVar11 == -1)) {
                                        puVar11 = puVar10;
                                        if (0xf < (ulonglong)puVar10[3]) {
                                          puVar11 = (undefined8 *)*puVar10;
                                        }
                                        if ((((ulonglong)puVar10[2] < 3) ||
                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                            lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7bc8
                                                                        ,3), lVar9 == lVar8)) ||
                                           (lVar9 - (longlong)puVar11 == -1)) {
                                          puVar11 = puVar10;
                                          if (0xf < (ulonglong)puVar10[3]) {
                                            puVar11 = (undefined8 *)*puVar10;
                                          }
                                          if ((((ulonglong)puVar10[2] < 4) ||
                                              (lVar8 = puVar10[2] + (longlong)puVar11,
                                              lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                          &UNK_1819d7c08,4),
                                              lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1))
                                          {
                                            puVar11 = puVar10;
                                            if (0xf < (ulonglong)puVar10[3]) {
                                              puVar11 = (undefined8 *)*puVar10;
                                            }
                                            if ((((ulonglong)puVar10[2] < 8) ||
                                                (lVar8 = puVar10[2] + (longlong)puVar11,
                                                lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                            &UNK_1819d7c28,8),
                                                lVar9 == lVar8)) ||
                                               (lVar9 - (longlong)puVar11 == -1)) {
                                              puVar11 = puVar10;
                                              if (0xf < (ulonglong)puVar10[3]) {
                                                puVar11 = (undefined8 *)*puVar10;
                                              }
                                              if ((((ulonglong)puVar10[2] < 3) ||
                                                  (lVar8 = puVar10[2] + (longlong)puVar11,
                                                  lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                              &UNK_1819d7c14,3),
                                                  lVar9 == lVar8)) ||
                                                 (lVar9 - (longlong)puVar11 == -1)) {
                                                puVar11 = puVar10;
                                                if (0xf < (ulonglong)puVar10[3]) {
                                                  puVar11 = (undefined8 *)*puVar10;
                                                }
                                                if ((((ulonglong)puVar10[2] < 6) ||
                                                    (lVar8 = puVar10[2] + (longlong)puVar11,
                                                    lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                &UNK_1819d7c38,6),
                                                    lVar9 == lVar8)) ||
                                                   (lVar9 - (longlong)puVar11 == -1)) {
                                                  puVar11 = puVar10;
                                                  if (0xf < (ulonglong)puVar10[3]) {
                                                    puVar11 = (undefined8 *)*puVar10;
                                                  }
                                                  if ((((ulonglong)puVar10[2] < 5) ||
                                                      (lVar8 = puVar10[2] + (longlong)puVar11,
                                                      lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                  &UNK_1819d7c5c,5),
                                                      lVar9 == lVar8)) ||
                                                     (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 3) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7be8,3
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 4) ||
                                                          (lVar8 = (longlong)puVar11 + puVar10[2],
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7b80
                                                                                      ,4),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 3) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7b94,3), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 4) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7bb8,4
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 7) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7ec0
                                                                                      ,7),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 7) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7e48,7), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 4) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d8178,4
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = (longlong)puVar11 + puVar10[2],
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7e90
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 3) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d8180,3), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 3) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d8184,3
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d8188
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 8) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d8190,8), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 7) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81a0,7
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7e08
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 6) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7e10,6), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 7) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81a8,7
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 6) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7e24
                                                                                      ,6),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 6) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7e2c,6), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 3) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7e1c,3
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 4) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d81b0
                                                                                      ,4),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 9) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d81b8,9), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 5) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81c4,5
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d80b4
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 5) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d81cc,5), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 5) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81d4,5
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 5) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d81dc
                                                                                      ,5),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 7) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7f58,7), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 8) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7f38,8
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d80b8
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 3) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7b40,3), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 7) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7b68,7
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar1 = puVar10 + 2;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar10 = (undefined8 *)*puVar10;
                                                      }
                                                      if (((5 < *puVar1) &&
                                                          (lVar8 = *puVar1 + (longlong)puVar10,
                                                          lVar9 = func_0x0001801278a0(puVar10,lVar8,
                                                                                      &UNK_1819d81e4
                                                                                      ,6),
                                                          lVar9 != lVar8)) &&
                                                         (lVar9 - (longlong)puVar10 != -1)) {
                                                        *param_1 = ZEXT816(0);
                                                        *(undefined8 *)param_1[1] = 3;
                                                        *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                        *(short *)*param_1 = (short)_DAT_1819d79bc;
                                                        (*param_1)[2] =
                                                             (char)((uint)_DAT_1819d79bc >> 0x10);
                                                        (*param_1)[3] = 0;
                                                        return param_1;
                                                      }
                                                      *param_1 = ZEXT816(0);
                                                      *(undefined8 *)param_1[1] = 3;
                                                      *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                      *(short *)*param_1 = (short)_DAT_1819d7a10;
                                                      (*param_1)[2] =
                                                           (char)((uint)_DAT_1819d7a10 >> 0x10);
                                                      (*param_1)[3] = 0;
                                                      return param_1;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7b44;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7b44 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7f88;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7f88 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d79bc;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d79bc >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7e0c;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7e0c >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7990;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7990 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7b88;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7b88 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      *param_1 = ZEXT816(0);
                                      *(undefined8 *)param_1[1] = 3;
                                      *(undefined8 *)(param_1[1] + 8) = 0xf;
                                      *(short *)*param_1 = (short)_DAT_1819d7bc4;
                                      (*param_1)[2] = (char)((uint)_DAT_1819d7bc4 >> 0x10);
                                      (*param_1)[3] = 0;
                                      return param_1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      *param_1 = ZEXT816(0);
                      *(undefined8 *)param_1[1] = 3;
                      *(undefined8 *)(param_1[1] + 8) = 0xf;
                      *(short *)*param_1 = (short)_DAT_1819d7c94;
                      (*param_1)[2] = (char)((uint)_DAT_1819d7c94 >> 0x10);
                      (*param_1)[3] = 0;
                      return param_1;
                    }
                  }
                }
              }
            }
          }
        }
      }
      *param_1 = ZEXT816(0);
      *(undefined8 *)param_1[1] = 3;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      *(short *)*param_1 = (short)_DAT_1819d7d2c;
      (*param_1)[2] = (char)((uint)_DAT_1819d7d2c >> 0x10);
      (*param_1)[3] = 0;
      return param_1;
    }
  }
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18007fe70 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16]
recovered_18007fe70(undefined (*param_1) [16],undefined8 *param_2,undefined8 param_3)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  byte *pbVar10;
  undefined (*pauVar11) [16];
  ulonglong uVar12;
  undefined8 uVar13;
  longlong lVar14;
  byte *pbVar15;
  ulonglong uVar16;
  longlong lVar17;
  bool bVar18;
  undefined auStack_40 [16];
  longlong lStack_30;
  ulonglong uStack_28;
  
  puVar9 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar9 = (undefined8 *)*param_2;
  }
  uVar8 = recovered_180080250(puVar9,param_2[2],param_3,0x2d);
  if (uVar8 == 0xffffffffffffffff) goto LAB_1800800c8;
  uVar16 = uVar8 + 1;
  auStack_40 = ZEXT816(0);
  lStack_30 = 0;
  uStack_28 = 0;
  if ((ulonglong)param_2[2] < uVar16) {
    recovered_180067b60();
    pcVar2 = (code *)swi(3);
    pauVar11 = (undefined (*) [16])(*pcVar2)();
    return pauVar11;
  }
  lVar14 = param_2[2] - uVar16;
  lVar17 = -1;
  if (lVar14 != -1) {
    lVar17 = lVar14;
  }
  puVar9 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar9 = (undefined8 *)*param_2;
  }
  recovered_180066cc0(auStack_40,uVar16 + (longlong)puVar9,lVar17);
  uVar16 = uStack_28;
  pbVar15 = (byte *)auStack_40._0_8_;
  pbVar10 = auStack_40;
  if (0xf < uStack_28) {
    pbVar10 = (byte *)auStack_40._0_8_;
  }
  uVar7 = 0;
  if (lStack_30 != 1) {
LAB_18007ff3f:
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 2) {
      bVar1 = *pbVar10;
      if ((bVar1 != 0x49) || (bVar1 = pbVar10[1], uVar6 = uVar7, bVar1 != 0x49)) {
        uVar6 = -(uint)(bVar1 < 0x49) | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 3) {
      bVar18 = *pbVar10 < 0x49;
      if (((*pbVar10 != 0x49) || (bVar18 = pbVar10[1] < 0x49, pbVar10[1] != 0x49)) ||
         (bVar18 = pbVar10[2] < 0x49, uVar6 = uVar7, pbVar10[2] != 0x49)) {
        uVar6 = -(uint)bVar18 | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 1) {
      uVar6 = uVar7;
      if (*pbVar10 != 0x58) {
        uVar6 = -(uint)(*pbVar10 < 0x58) | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 1) {
      uVar6 = uVar7;
      if (*pbVar10 != 0x59) {
        uVar6 = -(uint)(*pbVar10 < 0x59) | 1;
      }
      if (uVar6 == 0) goto LAB_180080013;
    }
    pbVar10 = auStack_40;
    if (0xf < uStack_28) {
      pbVar10 = (byte *)auStack_40._0_8_;
    }
    if (lStack_30 == 1) {
      if (*pbVar10 != 0x32) {
        uVar7 = -(uint)(*pbVar10 < 0x32) | 1;
      }
      if (uVar7 == 0) goto LAB_180080013;
    }
    if (0xf < uStack_28) {
      if ((0xfff < uStack_28 + 1) &&
         (pbVar15 = *(byte **)(auStack_40._0_8_ + -8),
         (byte *)0x1f < (byte *)(auStack_40._0_8_ + (-8 - (longlong)pbVar15)))) goto LAB_1800800aa;
      func_0x000180127e40(pbVar15);
    }
LAB_1800800c8:
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    uVar8 = param_2[2];
    if (0xf < (ulonglong)param_2[3]) {
      param_2 = (undefined8 *)*param_2;
    }
    if (uVar8 < 0x8000000000000000) {
      if (uVar8 < 0x10) {
        *(ulonglong *)param_1[1] = uVar8;
        *(undefined8 *)(param_1[1] + 8) = 0xf;
        uVar3 = *(undefined4 *)((longlong)param_2 + 4);
        uVar4 = *(undefined4 *)(param_2 + 1);
        uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
        *(undefined4 *)*param_1 = *(undefined4 *)param_2;
        *(undefined4 *)(*param_1 + 4) = uVar3;
        *(undefined4 *)(*param_1 + 8) = uVar4;
        *(undefined4 *)(*param_1 + 0xc) = uVar5;
      }
      else {
        uVar12 = uVar8 | 0xf;
        uVar16 = 0x7fffffffffffffff;
        if ((uVar12 < 0x8000000000000000) && (uVar16 = uVar12, uVar12 < 0x16)) {
          uVar16 = 0x16;
        }
        uVar13 = func_0x000180024110(uVar16 + 1);
        *(undefined8 *)*param_1 = uVar13;
        *(ulonglong *)param_1[1] = uVar8;
        *(ulonglong *)(param_1[1] + 8) = uVar16;
        func_0x0001801ca88d(uVar13,param_2,uVar8 + 1);
      }
      return param_1;
    }
    func_0x000180052a50();
    pcVar2 = (code *)swi(3);
    pauVar11 = (undefined (*) [16])(*pcVar2)();
    return pauVar11;
  }
  uVar6 = uVar7;
  if (*pbVar10 != 0x49) {
    uVar6 = -(uint)(*pbVar10 < 0x49) | 1;
  }
  if (uVar6 != 0) goto LAB_18007ff3f;
LAB_180080013:
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  if ((ulonglong)param_2[2] < uVar8) {
    uVar8 = param_2[2];
  }
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  recovered_180066cc0(param_1,param_2,uVar8);
  if (uVar16 < 0x10) {
    return param_1;
  }
  pbVar10 = pbVar15;
  if ((uVar16 + 1 < 0x1000) ||
     (pbVar10 = *(byte **)(pbVar15 + -8), pbVar15 + (-8 - (longlong)pbVar10) < (byte *)0x20)) {
    func_0x000180127e40(pbVar10);
    return param_1;
  }
LAB_1800800aa:
  _invoke_watson(0,0,0,0,0);
  pcVar2 = (code *)swi(3);
  pauVar11 = (undefined (*) [16])(*pcVar2)();
  return pauVar11;
}



/* ===== ANALYSIS FUNCTION 0x180080190 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180080190(undefined (*param_1) [16],undefined8 *param_2)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined (*pauVar8) [16];
  ulonglong uVar9;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  uVar1 = param_2[2];
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  if (uVar1 < 0x8000000000000000) {
    if (uVar1 < 0x10) {
      *(ulonglong *)param_1[1] = uVar1;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      uVar3 = *(undefined4 *)((longlong)param_2 + 4);
      uVar4 = *(undefined4 *)(param_2 + 1);
      uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
      *(undefined4 *)*param_1 = *(undefined4 *)param_2;
      *(undefined4 *)(*param_1 + 4) = uVar3;
      *(undefined4 *)(*param_1 + 8) = uVar4;
      *(undefined4 *)(*param_1 + 0xc) = uVar5;
    }
    else {
      uVar6 = uVar1 | 0xf;
      uVar9 = 0x7fffffffffffffff;
      if ((uVar6 < 0x8000000000000000) && (uVar9 = uVar6, uVar6 < 0x16)) {
        uVar9 = 0x16;
      }
      uVar7 = func_0x000180024110(uVar9 + 1);
      *(undefined8 *)*param_1 = uVar7;
      *(ulonglong *)param_1[1] = uVar1;
      *(ulonglong *)(param_1[1] + 8) = uVar9;
      func_0x0001801ca88d(uVar7,param_2,uVar1 + 1);
    }
    return param_1;
  }
  func_0x000180052a50();
  pcVar2 = (code *)swi(3);
  pauVar8 = (undefined (*) [16])(*pcVar2)();
  return pauVar8;
}



/* ===== ANALYSIS FUNCTION 0x180080250 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong recovered_180080250(longlong param_1,longlong param_2,undefined8 param_3,undefined param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    lVar2 = -1;
    if (param_2 + -1 != -1) {
      lVar2 = param_2 + -1;
    }
    lVar3 = lVar2 + 1 + param_1;
    lVar1 = func_0x000180127870(param_1,lVar3,param_4);
    lVar2 = -1;
    if (lVar1 != lVar3) {
      lVar2 = lVar1 - param_1;
    }
    return lVar2;
  }
  return -1;
}



/* ===== ANALYSIS FUNCTION 0x1800802c0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800802c0(void)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  lVar8 = ((longlong)_DAT_181b2f550 - (longlong)_DAT_181b2f548) / 0x12 +
          ((longlong)_DAT_181b2f550 - (longlong)_DAT_181b2f548 >> 0x3f);
  uVar10 = 25000;
  lVar8 = (lVar8 >> 2) - (lVar8 >> 0x3f);
  uVar1 = (_DAT_181b2f558 - (longlong)_DAT_181b2f548) / 0x48;
  if (0x38e38e38e38e38e - (uVar1 >> 1) < uVar1) {
    uVar10 = 0x38e38e38e38e38e;
  }
  else {
    uVar1 = (uVar1 >> 1) + uVar1;
    if ((24999 < uVar1) && (uVar10 = uVar1, 0x38e38e38e38e38e < uVar1)) {
      func_0x000180003980();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  lVar6 = func_0x000180024110(uVar10 * 0x48);
  func_0x000180080520(lVar6 + lVar8 * 0x48,25000 - lVar8);
  puVar12 = _DAT_181b2f550;
  if (_DAT_181b2f548 != _DAT_181b2f550) {
    puVar7 = (undefined8 *)(lVar6 + 0x38);
    puVar9 = (undefined8 *)(_DAT_181b2f548 + 0xe);
    puVar11 = _DAT_181b2f548;
    do {
      *(undefined (*) [16])(puVar7 + -7) = ZEXT816(0);
      puVar7[-5] = 0;
      puVar7[-4] = 0;
      uVar3 = puVar11[1];
      uVar4 = puVar11[2];
      uVar5 = puVar11[3];
      *(undefined4 *)(puVar7 + -7) = *puVar11;
      *(undefined4 *)((longlong)puVar7 + -0x34) = uVar3;
      *(undefined4 *)(puVar7 + -6) = uVar4;
      *(undefined4 *)((longlong)puVar7 + -0x2c) = uVar5;
      uVar3 = puVar11[5];
      uVar4 = puVar11[6];
      uVar5 = puVar11[7];
      *(undefined4 *)(puVar7 + -5) = puVar11[4];
      *(undefined4 *)((longlong)puVar7 + -0x24) = uVar3;
      *(undefined4 *)(puVar7 + -4) = uVar4;
      *(undefined4 *)((longlong)puVar7 + -0x1c) = uVar5;
      puVar9[-5] = 0;
      puVar9[-4] = 0xf;
      *(undefined *)puVar11 = 0;
      puVar11 = puVar11 + 0x12;
      *(undefined (*) [16])(puVar7 + -3) = ZEXT816(0);
      puVar7[-1] = 0;
      *puVar7 = 0;
      uVar3 = *(undefined4 *)((longlong)puVar9 + -0x14);
      uVar4 = *(undefined4 *)(puVar9 + -2);
      uVar5 = *(undefined4 *)((longlong)puVar9 + -0xc);
      *(undefined4 *)(puVar7 + -3) = *(undefined4 *)(puVar9 + -3);
      *(undefined4 *)((longlong)puVar7 + -0x14) = uVar3;
      *(undefined4 *)(puVar7 + -2) = uVar4;
      *(undefined4 *)((longlong)puVar7 + -0xc) = uVar5;
      uVar3 = *(undefined4 *)((longlong)puVar9 + -4);
      uVar4 = *(undefined4 *)puVar9;
      uVar5 = *(undefined4 *)((longlong)puVar9 + 4);
      *(undefined4 *)(puVar7 + -1) = *(undefined4 *)(puVar9 + -1);
      *(undefined4 *)((longlong)puVar7 + -4) = uVar3;
      *(undefined4 *)puVar7 = uVar4;
      *(undefined4 *)((longlong)puVar7 + 4) = uVar5;
      puVar9[-1] = 0;
      *puVar9 = 0xf;
      *(undefined *)(puVar9 + -3) = 0;
      *(undefined *)(puVar7 + 1) = *(undefined *)(puVar9 + 1);
      *(undefined *)((longlong)puVar7 + 9) = *(undefined *)((longlong)puVar9 + 9);
      *(undefined *)((longlong)puVar7 + 10) = *(undefined *)((longlong)puVar9 + 10);
      puVar7 = puVar7 + 9;
      puVar9 = puVar9 + 9;
    } while (puVar11 != puVar12);
  }
  puVar11 = _DAT_181b2f550;
  puVar12 = _DAT_181b2f548;
  if (_DAT_181b2f548 != (undefined4 *)0x0) {
    for (; puVar12 != puVar11; puVar12 = puVar12 + 0x12) {
      recovered_180066e40(puVar12 + 8);
      recovered_180066e40(puVar12);
    }
    puVar12 = _DAT_181b2f548;
    if ((0xfff < (ulonglong)(((_DAT_181b2f558 - (longlong)_DAT_181b2f548) / 0x48) * 0x48)) &&
       (puVar12 = *(undefined4 **)(_DAT_181b2f548 + -2),
       (undefined *)0x1f < (undefined *)((longlong)_DAT_181b2f548 + (-8 - (longlong)puVar12)))) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(puVar12);
  }
  _DAT_181b2f550 = (undefined4 *)(lVar6 + 1800000);
  _DAT_181b2f548 = (undefined4 *)lVar6;
  _DAT_181b2f558 = uVar10 * 0x48 + lVar6;
  return;
}



/* ===== ANALYSIS FUNCTION 0x180080590 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_180080590(undefined (*param_1) [16],int **param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined4 uVar5;
  longlong lVar6;
  int *piVar7;
  undefined (*pauVar8) [16];
  int iVar9;
  int **ppiVar10;
  ulonglong uVar11;
  undefined *puVar12;
  ulonglong uVar13;
  undefined *puStackX_10;
  undefined auStack_80 [16];
  undefined auStack_70 [16];
  undefined auStack_60 [4];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined auStack_40 [16];
  undefined8 uStack_30;
  ulonglong uStack_28;
  
  piVar7 = param_2[2];
  if (piVar7 != (int *)0x0) {
    piVar1 = param_2[3];
    ppiVar10 = param_2;
    if ((int *)0xf < piVar1) {
      ppiVar10 = (int **)*param_2;
    }
    if (piVar7 == (int *)0x3) {
      iVar9 = *(ushort *)ppiVar10 - 0x4f42;
      if (iVar9 == 0) {
        iVar9 = *(byte *)((longlong)ppiVar10 + 2) - 0x54;
      }
      if (iVar9 == 0) goto LAB_180080825;
    }
    ppiVar10 = param_2;
    if ((int *)0xf < piVar1) {
      ppiVar10 = (int **)*param_2;
    }
    if (piVar7 == (int *)0x7) {
      iVar9 = *(int *)ppiVar10 + -0x6e6b6e55;
      if ((iVar9 == 0) && (iVar9 = *(ushort *)((longlong)ppiVar10 + 4) - 0x776f, iVar9 == 0)) {
        iVar9 = *(byte *)((longlong)ppiVar10 + 6) - 0x6e;
      }
      if (iVar9 == 0) goto LAB_180080825;
    }
    ppiVar10 = param_2;
    if ((int *)0xf < piVar1) {
      ppiVar10 = (int **)*param_2;
    }
    lVar6 = recovered_180080250(ppiVar10,piVar7,piVar7,CONCAT71((int7)((ulonglong)piVar1 >> 8),0x28)
                               );
    ppiVar10 = param_2;
    if ((int *)0xf < param_2[3]) {
      ppiVar10 = (int **)*param_2;
    }
    piVar7 = (int *)recovered_180080250(ppiVar10,param_2[2]);
    if (((lVar6 != -1) && (piVar7 != (int *)0xffffffffffffffff)) &&
       (piVar1 = (int *)(lVar6 + 1), piVar1 < piVar7)) {
      auStack_80 = ZEXT816(0);
      auStack_70 = ZEXT816(0);
      if (param_2[2] < piVar1) {
        recovered_180067b60();
        pcVar2 = (code *)swi(3);
        pauVar8 = (undefined (*) [16])(*pcVar2)();
        return pauVar8;
      }
      uVar13 = (longlong)piVar7 + (-1 - lVar6);
      uVar11 = (longlong)param_2[2] - (longlong)piVar1;
      if (uVar11 < uVar13) {
        uVar13 = uVar11;
      }
      if ((int *)0xf < param_2[3]) {
        param_2 = (int **)*param_2;
      }
      recovered_180066cc0(auStack_80,(longlong)param_2 + (longlong)piVar1,uVar13);
      piVar7 = (int *)_errno();
      puVar12 = auStack_80;
      if (0xf < (ulonglong)auStack_70._8_8_) {
        puVar12 = (undefined *)auStack_80._0_8_;
      }
      *piVar7 = 0;
      uVar5 = strtol(puVar12,&puStackX_10,10);
      if (puVar12 == puStackX_10) {
        __Xinvalid_argument_std__YAXPEBD_Z(&UNK_1819d8238);
      }
      if (*piVar7 == 0x22) {
        __Xout_of_range_std__YAXPEBD_Z(&UNK_1819d8250);
      }
      if (0xf < (ulonglong)auStack_70._8_8_) {
        if ((0xfff < auStack_70._8_8_ + 1) &&
           (0x1f < (auStack_80._0_8_ - *(longlong *)(auStack_80._0_8_ + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          pauVar8 = (undefined (*) [16])(*pcVar2)();
          return pauVar8;
        }
        func_0x000180127e40();
      }
      uStack_30 = _DAT_181a03530;
      uStack_28 = _UNK_181a03538;
      auStack_40._1_15_ = SUB1615(ZEXT816(0),1);
      auVar3[15] = 0;
      auVar3._0_15_ = auStack_40._1_15_;
      auStack_40 = auVar3 << 8;
      uStack_50 = _DAT_181a03530;
      uStack_48 = _UNK_181a03538;
      stack0xffffffffffffffa1 = SUB1615(ZEXT816(0),1);
      auVar4[15] = 0;
      auVar4._0_15_ = stack0xffffffffffffffa1;
      _auStack_60 = auVar4 << 8;
      recovered_18006c300(uVar5,auStack_40,auStack_60);
      *(undefined (*) [4])*param_1 = auStack_60;
      *(undefined4 *)(*param_1 + 4) = uStack_5c;
      *(undefined4 *)(*param_1 + 8) = uStack_58;
      *(undefined4 *)(*param_1 + 0xc) = uStack_54;
      *(undefined4 *)param_1[1] = (undefined4)uStack_50;
      *(undefined4 *)(param_1[1] + 4) = uStack_50._4_4_;
      *(undefined4 *)(param_1[1] + 8) = (undefined4)uStack_48;
      *(undefined4 *)(param_1[1] + 0xc) = uStack_48._4_4_;
      if (uStack_28 < 0x10) {
        return param_1;
      }
      if ((0xfff < uStack_28 + 1) &&
         (0x1f < (auStack_40._0_8_ - *(longlong *)(auStack_40._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        pauVar8 = (undefined (*) [16])(*pcVar2)();
        return pauVar8;
      }
      func_0x000180127e40();
      return param_1;
    }
  }
LAB_180080825:
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180080860 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


bool recovered_180080860(longlong param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  ulonglong uVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined (*pauVar10) [16];
  longlong lVar11;
  undefined *puVar12;
  undefined auStack_28 [16];
  undefined auStack_18 [16];
  
  uVar1 = *(ulonglong *)(param_1 + 0x30);
  if (uVar1 == 0) {
    return true;
  }
  pauVar10 = (undefined (*) [16])(param_1 + 0x20);
  auStack_28 = ZEXT816(0);
  auStack_18 = ZEXT816(0);
  if (0xf < *(ulonglong *)(param_1 + 0x38)) {
    pauVar10 = *(undefined (**) [16])*pauVar10;
  }
  if (0x7fffffffffffffff < uVar1) {
    func_0x000180052a50();
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return (bool)uVar3;
  }
  if (uVar1 < 0x10) {
    auStack_18._0_8_ = uVar1;
    auStack_18._8_8_ = 0xf;
    auStack_28 = *pauVar10;
  }
  else {
    uVar4 = uVar1 | 0xf;
    uVar7 = 0x7fffffffffffffff;
    if ((uVar4 < 0x8000000000000000) && (uVar7 = uVar4, uVar4 < 0x16)) {
      uVar7 = 0x16;
    }
    uVar5 = func_0x000180024110(uVar7 + 1);
    auStack_28._0_8_ = uVar5;
    auStack_18._0_8_ = uVar1;
    auStack_18._8_8_ = uVar7;
    func_0x0001801ca88d(uVar5,pauVar10,uVar1 + 1);
  }
  puVar12 = auStack_28;
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar12 = (undefined *)auStack_28._0_8_;
  }
  puVar9 = puVar12 + auStack_18._0_8_;
  puVar8 = auStack_28;
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar8 = (undefined *)auStack_28._0_8_;
  }
  if (puVar8 != puVar9) {
    lVar11 = (longlong)puVar12 - (longlong)puVar8;
    do {
      uVar3 = tolower(*puVar8);
      puVar8[lVar11] = uVar3;
      puVar8 = puVar8 + 1;
    } while (puVar8 != puVar9);
  }
  puVar12 = auStack_28;
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar12 = (undefined *)auStack_28._0_8_;
  }
  puVar8 = (undefined *)auStack_28._0_8_;
  if (7 < (ulonglong)auStack_18._0_8_) {
    puVar9 = puVar12 + auStack_18._0_8_;
    puVar6 = (undefined *)func_0x0001801278a0(puVar12,puVar9,&UNK_1819d8270,8);
    puVar8 = (undefined *)auStack_28._0_8_;
    if (puVar6 != puVar9) {
      lVar11 = (longlong)puVar6 - (longlong)puVar12;
      goto LAB_1800809c8;
    }
  }
  lVar11 = -1;
LAB_1800809c8:
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar12 = puVar8;
    if ((0xfff < auStack_18._8_8_ + 1) &&
       (puVar12 = *(undefined **)(puVar8 + -8),
       (undefined *)0x1f < puVar8 + (-8 - (longlong)puVar12))) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return (bool)uVar3;
    }
    func_0x000180127e40(puVar12);
  }
  return lVar11 != -1;
}



/* ===== ANALYSIS FUNCTION 0x180080a40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180080a40(float param_1,float param_2,float param_3,float param_4,undefined8 *param_5
                        ,undefined4 param_6,float param_7,undefined8 param_8,char param_9,
                        char param_10)

{
  undefined4 uVar1;
  longlong lVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  undefined8 uStack_140;
  undefined4 uStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  
  lVar2 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar2 = func_0x00018000a880(**(undefined8 **)(lVar2 + 0x4908),0,&UNK_18020ed28);
  if (lVar2 != 0) {
    fVar4 = param_4 * _DAT_181a03184;
    fVar9 = param_3 * _DAT_181a03184;
    fStack_150 = fVar4;
    if (DAT_181b2bc70 == '\0') {
      fStack_160 = fVar9;
      if ((param_9 != '\0') && (DAT_181b2b4b0 != '\0')) {
        if (param_10 == '\0') {
          uVar1 = func_0x000180004f90(0x181b2b4b4);
        }
        else {
          uVar1 = 0x2d0000ff;
        }
        fStack_178 = param_1 + param_3;
        fStack_174 = param_2 + param_4;
        fStack_14c = param_1;
        fStack_148 = param_2;
        func_0x000180027d60(lVar2,&fStack_14c,&fStack_178,uVar1,0,0);
      }
      param_3 = param_3 + param_1;
      param_4 = param_4 + param_2;
      iVar3 = (int)param_7;
      if (iVar3 < 1) {
        fVar4 = fVar9 + param_1;
        fVar5 = param_2 + fVar4;
      }
      else {
        fStack_154 = fVar4 + param_2;
        fStack_158 = fVar9 + param_1;
        fStack_14c = param_3 - fVar9;
        fStack_178 = param_4 - fVar4;
        do {
          fStack_134 = ((_DAT_181a03230 - (float)iVar3 / param_7) * _DAT_181a03330) / _DAT_181a033ec
          ;
          if (param_10 == '\0') {
            uStack_140 = *param_5;
            uStack_138 = *(undefined4 *)(param_5 + 1);
          }
          else {
            uStack_140 = 0x3f800000;
            uStack_138 = 0;
          }
          fVar4 = (float)iVar3 * _DAT_181a031bc;
          fVar5 = param_2 - fVar4;
          fVar10 = param_1 - fVar4;
          fVar8 = fVar4 + fStack_158;
          fStack_130 = fVar8;
          fStack_12c = fVar5;
          fStack_128 = fVar10;
          fStack_124 = fVar5;
          uVar1 = func_0x000180004f90(&uStack_140);
          func_0x000180027b00(lVar2,&fStack_128,&fStack_130,uVar1,param_6);
          fVar9 = fVar4 + fStack_154;
          fStack_120 = fVar10;
          fStack_11c = fVar9;
          fStack_118 = fVar10;
          fStack_114 = fVar5;
          func_0x000180027b00(lVar2,&fStack_118,&fStack_120,uVar1,param_6);
          fVar6 = fStack_14c - fVar4;
          fVar7 = param_3 + fVar4;
          fStack_110 = fVar6;
          fStack_10c = fVar5;
          fStack_108 = fVar7;
          fStack_104 = fVar5;
          func_0x000180027b00(lVar2,&fStack_108,&fStack_110,uVar1,param_6);
          fStack_100 = fVar7;
          fStack_fc = fVar9;
          fStack_f8 = fVar7;
          fStack_f4 = fVar5;
          func_0x000180027b00(lVar2,&fStack_f8,&fStack_100,uVar1,param_6);
          fVar9 = param_4 + fVar4;
          fStack_f0 = fVar8;
          fStack_ec = fVar9;
          fStack_e8 = fVar10;
          fStack_e4 = fVar9;
          func_0x000180027b00(lVar2,&fStack_e8,&fStack_f0,uVar1,param_6);
          fVar4 = fStack_178 - fVar4;
          fStack_e0 = fVar10;
          fStack_dc = fVar4;
          fStack_d8 = fVar10;
          fStack_d4 = fVar9;
          func_0x000180027b00(lVar2,&fStack_d8,&fStack_e0,uVar1,param_6);
          fStack_d0 = fVar6;
          fStack_cc = fVar9;
          fStack_c8 = fVar7;
          fStack_c4 = fVar9;
          func_0x000180027b00(lVar2,&fStack_c8,&fStack_d0,uVar1,param_6);
          fStack_170 = fVar7;
          fStack_16c = fVar4;
          fStack_168 = fVar7;
          fStack_164 = fVar9;
          func_0x000180027b00(lVar2,&fStack_168,&fStack_170,uVar1,param_6);
          iVar3 = iVar3 + -1;
          fVar4 = fStack_158;
          fVar9 = fStack_160;
          fVar5 = fStack_154;
        } while (0 < iVar3);
      }
      fStack_170 = param_1;
      fStack_16c = param_2;
      fStack_168 = fVar4;
      fStack_164 = param_2;
      uVar1 = func_0x000180004f90(param_5);
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_1;
      fStack_16c = param_2;
      fStack_168 = param_1;
      fStack_164 = fVar5;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_2;
      fStack_168 = param_3 - fVar9;
      fStack_164 = param_2;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_2;
      fStack_168 = param_3;
      fStack_164 = fVar5;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_1;
      fStack_16c = param_4;
      fStack_168 = fVar4;
      fStack_164 = param_4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fVar4 = param_4 - fStack_150;
      fStack_170 = param_1;
      fStack_16c = param_4;
      fStack_168 = param_1;
      fStack_164 = fVar4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_4;
      fStack_168 = param_3 - fVar9;
      fStack_164 = param_4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_4;
      fStack_168 = param_3;
      fStack_164 = fVar4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
    }
    else {
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = fVar9 + param_1;
      fStack_15c = param_2;
      uVar1 = func_0x000180004f90(param_5);
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = param_1;
      fStack_15c = fVar4 + param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      param_3 = param_1 + param_3;
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3 - fVar9;
      fStack_15c = param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3;
      fStack_15c = fVar4 + param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      param_2 = param_2 + param_4;
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = fVar9 + param_1;
      fStack_15c = param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fVar9 = param_2 - fStack_150;
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = param_1;
      fStack_15c = fVar9;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3 - fVar9;
      fStack_15c = param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3;
      fStack_15c = fVar9;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180081370 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180081370(short param_1,undefined8 param_2,undefined8 param_3,float param_4,
                        char param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  longlong lVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  undefined8 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined8 uStack_108;
  float afStack_100 [4];
  float fStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  
  lVar5 = _DAT_181b2f2c0;
  uStack_108 = param_3;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar5 = func_0x00018000a880(**(undefined8 **)(lVar5 + 0x4908),0,&UNK_18020ed28);
  fVar1 = _DAT_181a03230;
  if (lVar5 != 0) {
    afStack_100[2] = 1.0;
    afStack_100[0] = 0.0;
    afStack_100[1] = (float)(int)param_1 / _DAT_181a033d8;
    pfVar7 = afStack_100;
    if (0.0 <= afStack_100[1]) {
      pfVar7 = afStack_100 + 1;
    }
    pfVar6 = afStack_100 + 2;
    if (afStack_100[1] <= _DAT_181a03230) {
      pfVar6 = pfVar7;
    }
    fVar13 = *pfVar6;
    fVar16 = fVar13 * param_4;
    if (param_5 == '\0') {
      fStack_118 = _DAT_181a03850;
      fStack_114 = (float)_UNK_181a03854;
      uStack_110 = _UNK_181a03858;
      uStack_10c = _UNK_181a0385c;
      fStack_e0 = _DAT_181a03840;
      uStack_dc = _UNK_181a03844;
      uStack_d8 = _UNK_181a03848;
      uStack_d4 = _UNK_181a0384c;
      fStack_f0 = _DAT_181a03860;
      uStack_ec = _UNK_181a03864;
      uStack_e8 = _UNK_181a03868;
      uStack_e4 = _UNK_181a0386c;
      if (fVar13 <= _DAT_181a031bc) {
        fStack_120 = (_DAT_181a031bc - fVar13) + (_DAT_181a031bc - fVar13);
        fStack_124 = _DAT_181a03230 - fStack_120;
        fStack_120 = fStack_120 * 0.0;
        fStack_128 = fStack_120 + _DAT_181a03230;
        fStack_11c = fStack_128;
      }
      else {
        fStack_120 = (_DAT_181a03230 - fVar13) + (_DAT_181a03230 - fVar13);
        fStack_128 = fStack_120 + 0.0;
        fStack_120 = fStack_120 * 0.0;
        fStack_124 = fStack_120 + _DAT_181a03230;
        fStack_11c = fStack_124;
      }
      fStack_120 = fStack_120 + 0.0;
      if (fVar13 <= _DAT_181a031bc) {
        pfVar7 = &fStack_f0;
        if (fVar13 <= _DAT_181a03184) {
          pfVar7 = &fStack_e0;
        }
      }
      else {
        pfVar7 = &fStack_118;
      }
      fVar13 = *pfVar7;
      fVar15 = pfVar7[1];
      fVar14 = pfVar7[2];
    }
    else {
      fStack_128 = _DAT_181b2b568;
      fStack_124 = _DAT_181b2b56c;
      fStack_120 = _DAT_181b2b570;
      fStack_11c = _DAT_181b2b574;
      fVar13 = _DAT_181b2b568;
      fVar14 = _DAT_181b2b570;
      fVar15 = _DAT_181b2b56c;
    }
    uVar4 = func_0x000180004f90(&fStack_128);
    fVar3 = (float)uStack_108;
    fVar12 = uStack_108._4_4_;
    fVar17 = (float)uStack_108 + _DAT_181a03284;
    fVar10 = uStack_108._4_4_ + param_4;
    fStack_128 = (float)uStack_108;
    fStack_124 = uStack_108._4_4_;
    uVar9 = 0x80000000;
    if (param_5 != '\0') {
      uVar9 = 0xb4000050;
    }
    fStack_118 = fVar17;
    fStack_114 = fVar10;
    func_0x000180027d60(lVar5,&fStack_128,&fStack_118,uVar9,0,0);
    fVar2 = _DAT_181a032ec;
    fStack_118 = fVar3;
    if (DAT_181b2bc70 == '\0') {
      fVar14 = fVar14 * _DAT_181a033ec;
      iVar8 = 10;
      fVar15 = fVar15 * _DAT_181a033ec;
      fVar13 = fVar13 * _DAT_181a033ec;
      fVar3 = (float)uStack_108;
      do {
        fVar11 = (float)iVar8;
        fStack_128 = fVar11 + fVar17;
        fStack_124 = fVar11 + fVar10;
        fStack_118 = fVar3 - fVar11;
        fStack_114 = ((param_4 - fVar16) + fVar12) - fVar11;
        func_0x000180027d60(lVar5,&fStack_118,&fStack_128,
                            (((int)((fVar1 - fVar11 / fVar2) * _DAT_181a0330c) << 8 | (int)fVar14)
                             << 8 | (int)fVar15) << 8 | (int)fVar13,0,0);
        iVar8 = iVar8 + -1;
      } while (0 < iVar8);
      fStack_118 = (float)uStack_108;
    }
    if (param_5 == '\0') {
      fVar12 = (param_4 - fVar16) + fVar12;
      param_4 = fVar16;
    }
    fStack_124 = param_4 + fVar12;
    fStack_128 = fVar17;
    fStack_114 = fVar12;
    func_0x000180027d60(lVar5,&fStack_118,&fStack_128,uVar4,0,0);
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180081850 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180081850(short param_1,undefined8 param_2,float param_3,float param_4,float param_5,
                        float param_6,char param_7)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  longlong lVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStackX_10;
  float afStack_128 [4];
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  
  lVar4 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar4 = func_0x00018000a880(**(undefined8 **)(lVar4 + 0x4908),0,&UNK_18020ed28);
  fVar10 = _DAT_181a03230;
  fVar8 = _DAT_181a031bc;
  if (lVar4 != 0) {
    afStack_128[2] = 1.0;
    afStack_128[0] = 0.0;
    afStack_128[1] = (float)(int)param_1 / _DAT_181a033d8;
    pfVar6 = afStack_128;
    if (0.0 <= afStack_128[1]) {
      pfVar6 = afStack_128 + 1;
    }
    pfVar5 = afStack_128 + 2;
    if (afStack_128[1] <= _DAT_181a03230) {
      pfVar5 = pfVar6;
    }
    fVar9 = *pfVar5;
    if (param_7 == '\0') {
      fStackX_10 = fVar9 * param_5;
      fStack_118 = _DAT_181a03850;
      fStack_114 = (float)_UNK_181a03854;
      uStack_110 = _UNK_181a03858;
      uStack_10c = _UNK_181a0385c;
      fStack_f8 = _DAT_181a03860;
      uStack_f4 = _UNK_181a03864;
      uStack_f0 = _UNK_181a03868;
      uStack_ec = _UNK_181a0386c;
      fStack_e8 = _DAT_181a03840;
      uStack_e4 = _UNK_181a03844;
      uStack_e0 = _UNK_181a03848;
      uStack_dc = _UNK_181a0384c;
      if (fVar9 <= _DAT_181a031bc) {
        fVar14 = (_DAT_181a031bc - fVar9) + (_DAT_181a031bc - fVar9);
        fStack_104 = _DAT_181a03230 - fVar14;
        fVar14 = fVar14 * 0.0;
        fStack_108 = fVar14 + _DAT_181a03230;
        fStack_100 = fVar14 + 0.0;
        fStack_fc = fStack_108;
      }
      else {
        fVar13 = (_DAT_181a03230 - fVar9) + (_DAT_181a03230 - fVar9);
        fVar14 = fVar13 * 0.0;
        fStack_108 = fVar13 + 0.0;
        fStack_104 = fVar14 + _DAT_181a03230;
        fStack_fc = fStack_104;
        fStack_100 = fVar14 + 0.0;
      }
      if (fVar9 <= _DAT_181a031bc) {
        pfVar6 = &fStack_f8;
        if (fVar9 <= _DAT_181a03184) {
          pfVar6 = &fStack_e8;
        }
      }
      else {
        pfVar6 = &fStack_118;
      }
      fVar9 = *pfVar6;
      fVar14 = pfVar6[1];
      fVar13 = pfVar6[2];
    }
    else {
      fStackX_10 = param_5;
      fStack_108 = _DAT_181b2b568;
      fStack_104 = _DAT_181b2b56c;
      fStack_100 = _DAT_181b2b570;
      fStack_fc = _DAT_181b2b574;
      fVar9 = _DAT_181b2b568;
      fVar13 = _DAT_181b2b570;
      fVar14 = _DAT_181b2b56c;
    }
    uVar3 = func_0x000180004f90(&fStack_108);
    fVar2 = _DAT_181a0330c;
    fVar12 = _DAT_181a031f4;
    fVar1 = _DAT_181a03164;
    if (DAT_181b2bc70 == '\0') {
      fVar13 = fVar13 * _DAT_181a033ec;
      iVar7 = 8;
      fVar9 = fVar9 * _DAT_181a033ec;
      fVar15 = param_4 + param_6 + _DAT_181a032a0;
      fVar14 = fVar14 * _DAT_181a033ec;
      fVar11 = fVar15 + _DAT_181a032a0;
      do {
        fVar8 = (float)iVar7;
        fStack_114 = fVar11 + fVar8;
        fStack_118 = fVar8 + fStackX_10 + param_3;
        fStack_104 = fVar15 - fVar8;
        fStack_108 = param_3 - fVar8;
        func_0x000180027d60(lVar4,&fStack_108,&fStack_118,
                            (((int)((fVar10 - fVar8 * fVar1) * fVar2) << 8 | (int)fVar13) << 8 |
                            (int)fVar14) << 8 | (int)fVar9,fVar12,0);
        iVar7 = iVar7 + -1;
        fVar8 = _DAT_181a031bc;
      } while (0 < iVar7);
    }
    fVar10 = param_4 + param_6 + _DAT_181a032a0;
    fStack_108 = param_3 + param_5;
    fVar9 = fVar10 + _DAT_181a032a0;
    fStack_118 = param_3;
    fStack_114 = fVar10;
    fStack_104 = fVar9;
    func_0x000180027c60(lVar4,&fStack_118,&fStack_108,0xc8000000,fVar12,0xf0,_DAT_181a03248);
    if (0.0 < fStackX_10) {
      if (fStackX_10 < _DAT_181a03250) {
        fVar12 = fStackX_10 * fVar8;
      }
      fVar14 = fStackX_10 + param_3;
      fStack_118 = param_3;
      fStack_114 = fVar10;
      fStack_108 = fVar14;
      fStack_104 = fVar9;
      func_0x000180027d60(lVar4,&fStack_118,&fStack_108,uVar3,fVar12,0xf0);
      if (fStackX_10 < param_5) {
        fStack_108 = fVar14 + fVar8;
        fStack_118 = fVar14 - fVar8;
        fStack_114 = fVar10;
        fStack_104 = fVar9;
        func_0x000180027d60(lVar4,&fStack_118,&fStack_108,0xc8000000,0,0);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180081e00 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180081e00(short param_1,undefined8 param_2,float param_3,float param_4,float param_5,
                        undefined8 param_6,char param_7)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  longlong lVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float afStack_118 [4];
  float fStack_108;
  float fStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  
  lVar4 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar4 = func_0x00018000a880(**(undefined8 **)(lVar4 + 0x4908),0,&UNK_18020ed28);
  fVar15 = _DAT_181a03230;
  fVar8 = _DAT_181a031bc;
  if (lVar4 != 0) {
    fVar9 = (param_4 - _DAT_181a032a0) - _DAT_181a032a8;
    afStack_118[2] = 1.0;
    afStack_118[0] = 0.0;
    afStack_118[1] = (float)(int)param_1 / _DAT_181a033d8;
    pfVar6 = afStack_118;
    if (0.0 <= afStack_118[1]) {
      pfVar6 = afStack_118 + 1;
    }
    pfVar5 = afStack_118 + 2;
    if (afStack_118[1] <= _DAT_181a03230) {
      pfVar5 = pfVar6;
    }
    fVar10 = *pfVar5;
    if (param_7 == '\0') {
      fVar11 = fVar10 * param_5;
      fStack_108 = _DAT_181a03850;
      fStack_104 = (float)_UNK_181a03854;
      uStack_100 = _UNK_181a03858;
      uStack_fc = _UNK_181a0385c;
      fStack_d8 = _DAT_181a03840;
      uStack_d4 = _UNK_181a03844;
      uStack_d0 = _UNK_181a03848;
      uStack_cc = _UNK_181a0384c;
      fStack_e8 = _DAT_181a03860;
      uStack_e4 = _UNK_181a03864;
      uStack_e0 = _UNK_181a03868;
      uStack_dc = _UNK_181a0386c;
      if (fVar10 <= _DAT_181a031bc) {
        fVar16 = (_DAT_181a031bc - fVar10) + (_DAT_181a031bc - fVar10);
        fStack_f4 = _DAT_181a03230 - fVar16;
        fVar16 = fVar16 * 0.0;
        fStack_f8 = fVar16 + _DAT_181a03230;
        fStack_f0 = fVar16 + 0.0;
        fStack_ec = fStack_f8;
      }
      else {
        fVar14 = (_DAT_181a03230 - fVar10) + (_DAT_181a03230 - fVar10);
        fVar16 = fVar14 * 0.0;
        fStack_f8 = fVar14 + 0.0;
        fStack_f4 = fVar16 + _DAT_181a03230;
        fStack_ec = fStack_f4;
        fStack_f0 = fVar16 + 0.0;
      }
      if (fVar10 <= _DAT_181a031bc) {
        pfVar6 = &fStack_e8;
        if (fVar10 <= _DAT_181a03184) {
          pfVar6 = &fStack_d8;
        }
      }
      else {
        pfVar6 = &fStack_108;
      }
      fVar10 = *pfVar6;
      fVar16 = pfVar6[1];
      fVar14 = pfVar6[2];
    }
    else {
      fStack_f8 = _DAT_181b2b568;
      fStack_f4 = _DAT_181b2b56c;
      fStack_f0 = _DAT_181b2b570;
      fStack_ec = _DAT_181b2b574;
      fVar10 = _DAT_181b2b568;
      fVar11 = param_5;
      fVar14 = _DAT_181b2b570;
      fVar16 = _DAT_181b2b56c;
    }
    uVar3 = func_0x000180004f90(&fStack_f8);
    fVar2 = _DAT_181a0330c;
    fVar13 = _DAT_181a031f4;
    fVar1 = _DAT_181a03164;
    if (DAT_181b2bc70 == '\0') {
      fVar14 = fVar14 * _DAT_181a033ec;
      iVar7 = 8;
      fVar12 = fVar9 + _DAT_181a032a0;
      fVar10 = fVar10 * _DAT_181a033ec;
      fVar16 = fVar16 * _DAT_181a033ec;
      do {
        fVar8 = (float)iVar7;
        fStack_104 = fVar12 + fVar8;
        fStack_108 = fVar8 + fVar11 + param_3;
        fStack_f4 = fVar9 - fVar8;
        fStack_f8 = param_3 - fVar8;
        func_0x000180027d60(lVar4,&fStack_f8,&fStack_108,
                            (((int)((fVar15 - fVar8 * fVar1) * fVar2) << 8 | (int)fVar14) << 8 |
                            (int)fVar16) << 8 | (int)fVar10,fVar13,0);
        iVar7 = iVar7 + -1;
        fVar8 = _DAT_181a031bc;
      } while (0 < iVar7);
    }
    fStack_f8 = param_3 + param_5;
    fVar15 = fVar9 + _DAT_181a032a0;
    fStack_108 = param_3;
    fStack_104 = fVar9;
    fStack_f4 = fVar15;
    func_0x000180027c60(lVar4,&fStack_108,&fStack_f8,0xc8000000,fVar13,0xf0,_DAT_181a03248);
    if (0.0 < fVar11) {
      if (fVar11 < _DAT_181a03250) {
        fVar13 = fVar11 * fVar8;
      }
      fVar10 = fVar11 + param_3;
      fStack_108 = param_3;
      fStack_104 = fVar9;
      fStack_f8 = fVar10;
      fStack_f4 = fVar15;
      func_0x000180027d60(lVar4,&fStack_108,&fStack_f8,uVar3,fVar13,0xf0);
      if (fVar11 < param_5) {
        fStack_f8 = fVar10 + fVar8;
        fStack_108 = fVar10 - fVar8;
        fStack_104 = fVar9;
        fStack_f4 = fVar15;
        func_0x000180027d60(lVar4,&fStack_108,&fStack_f8,0xc8000000,0,0);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180082360 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180082360(void)

{
  double dVar1;
  code *pcVar2;
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  float fVar6;
  longlong lVar7;
  ulonglong uVar8;
  char cVar9;
  char cVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  longlong lVar17;
  undefined (*pauVar18) [16];
  longlong lVar19;
  undefined *puVar20;
  longlong *plVar21;
  longlong **pplVar22;
  longlong **pplVar23;
  undefined8 ****ppppuVar24;
  undefined *puVar25;
  undefined8 ****ppppuVar26;
  longlong *****ppppplVar27;
  longlong **pplVar28;
  ulonglong uVar29;
  undefined8 *puVar30;
  undefined8 *puVar31;
  longlong **pplVar32;
  undefined8 ****ppppuVar33;
  ulonglong uVar34;
  char *pcVar35;
  float fVar37;
  longlong *plVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  undefined8 uVar42;
  undefined8 extraout_XMM0_Qb;
  float fVar43;
  float fVar44;
  float fVar45;
  undefined auVar46 [16];
  undefined auVar47 [16];
  undefined auVar48 [16];
  float fVar49;
  float fStackX_8;
  float fStackX_c;
  float fStackX_10;
  float fStackX_14;
  undefined8 uStackX_18;
  float afStackX_20 [2];
  longlong *****in_stack_fffffffffffffa48;
  undefined4 uVar50;
  longlong *****in_stack_fffffffffffffa50;
  undefined8 *in_stack_fffffffffffffa58;
  undefined7 uVar51;
  float fStack_588;
  float fStack_584;
  longlong lStack_580;
  int iStack_578;
  int iStack_574;
  longlong **pplStack_570;
  longlong *aplStack_568 [2];
  longlong *aplStack_558 [2];
  float fStack_548;
  float fStack_544;
  undefined auStack_538 [16];
  longlong *plStack_528;
  undefined *puStack_520;
  undefined4 uStack_518;
  undefined4 uStack_514;
  undefined4 uStack_510;
  undefined4 uStack_50c;
  float fStack_508;
  undefined auStack_4f8 [16];
  undefined8 uStack_4e8;
  ulonglong uStack_4e0;
  undefined4 uStack_4d8;
  undefined4 uStack_4d4;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined auStack_4c8 [16];
  undefined auStack_4b8 [16];
  undefined auStack_4a8 [16];
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined auStack_488 [16];
  float fStack_478;
  float fStack_474;
  float fStack_470;
  float fStack_46c;
  float fStack_468;
  float fStack_464;
  float fStack_460;
  float fStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  float afStack_450 [2];
  float fStack_448;
  float fStack_444;
  float fStack_440;
  float fStack_43c;
  float fStack_438;
  float fStack_434;
  undefined auStack_430 [8];
  undefined4 uStack_428;
  undefined4 uStack_424;
  undefined auStack_420 [16];
  undefined auStack_410 [16];
  undefined auStack_400 [16];
  undefined auStack_3f0 [16];
  undefined auStack_3e0 [16];
  undefined auStack_3d0 [16];
  ulonglong uStack_3c0;
  ulonglong uStack_3b8;
  undefined auStack_3a8 [16];
  char acStack_394 [12];
  float fStack_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  undefined4 uStack_368;
  undefined4 uStack_364;
  undefined8 uStack_360;
  float fStack_358;
  float fStack_354;
  float fStack_350;
  float fStack_34c;
  float fStack_348;
  float fStack_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  undefined8 auStack_338 [2];
  undefined auStack_328 [16];
  float fStack_318;
  float fStack_314;
  float fStack_310;
  float fStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined8 uStack_300;
  float fStack_2f8;
  float fStack_2f4;
  float fStack_2f0;
  float fStack_2ec;
  float fStack_2e8;
  float fStack_2e4;
  float fStack_2e0;
  float fStack_2dc;
  undefined auStack_2d8 [12];
  undefined2 uStack_2cc;
  undefined2 uStack_2ca;
  undefined4 uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined8 uStack_2b8;
  float fStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  undefined4 uStack_29c;
  undefined8 ****appppuStack_298 [2];
  longlong lStack_288;
  ulonglong uStack_280;
  longlong *****appppplStack_278 [2];
  longlong lStack_268;
  ulonglong uStack_260;
  undefined auStack_258 [8];
  undefined auStack_250 [8];
  undefined auStack_248 [8];
  undefined auStack_240 [8];
  undefined auStack_238 [8];
  undefined8 uStack_230;
  undefined auStack_228 [4];
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined auStack_218 [16];
  undefined8 ****appppuStack_208 [2];
  ulonglong uStack_1f8;
  ulonglong uStack_1f0;
  float *pfStack_1e8;
  undefined4 *puStack_1e0;
  float *pfStack_1d8;
  undefined4 *puStack_1d0;
  float *pfStack_1c8;
  undefined4 *puStack_1c0;
  undefined4 *puStack_1b8;
  float *pfStack_1b0;
  undefined4 *puStack_1a8;
  undefined8 *puStack_1a0;
  undefined4 *puStack_198;
  undefined8 ****appppuStack_188 [2];
  ulonglong uStack_178;
  ulonglong uStack_170;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined auStack_118 [16];
  undefined auStack_108 [96];
  char *pcVar36;
  
  lVar19 = _DAT_181b2f2c0;
  fVar37 = 0.0;
  fStackX_10 = 0.0;
  fStackX_8 = 0.0;
  if (DAT_181b2b46c != '\0') {
    DAT_181b2f6da = '\0';
    if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
      _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
    }
    lStack_580 = func_0x00018000a880(**(undefined8 **)(lVar19 + 0x4908),0,&UNK_18020ed28);
    if (lStack_580 != 0) {
      recovered_18007b0b0();
      fVar6 = _DAT_181a03230;
      iStack_574 = _DAT_181b2bec8;
      iStack_578 = _DAT_181b2becc;
      pplStack_570 = _DAT_181b2be38;
      pplVar28 = (longlong **)*_DAT_181b2be38;
      pplVar22 = _DAT_181b2be38;
      fVar45 = _DAT_181a031bc;
      if (pplVar28 != _DAT_181b2be38) {
        do {
          uVar42 = 0;
          if (((*(char *)((longlong)pplVar28 + 0x19) != '\0') &&
              (*(char *)((longlong)pplVar28 + 0x1a) == '\0')) &&
             ((DAT_181b2bedc != '\0' || (*(char *)((longlong)pplVar28 + 0x1c) != '\0')))) {
            auVar48._4_4_ = _DAT_181b2b56c;
            auVar48._0_4_ = _DAT_181b2b568;
            auVar48._8_4_ = _DAT_181b2b570;
            auVar48._12_4_ = _DAT_181b2b574;
            cVar10 = *(char *)((longlong)pplVar28 + 0x1b);
            fVar39 = fVar6;
            fVar40 = fVar6;
            fVar41 = fVar6;
            if ((DAT_181b2bc70 == '\0') && (DAT_181b2b564 != '\0')) {
              dVar1 = *(double *)(_DAT_181b2f2c0 + 0x3e60);
              fVar39 = (float)func_0x0001801cb519((float)dVar1 + _DAT_181a032a8);
              fVar40 = (float)func_0x0001801cb519((float)dVar1 + _DAT_181a03270);
              fVar41 = (float)func_0x0001801cb519();
              fVar39 = fVar39 * fVar45 + fVar45;
              fVar40 = fVar40 * fVar45 + fVar45;
              fVar41 = fVar41 * fVar45 + fVar45;
            }
            fStack_2a8 = fVar41;
            fStack_2a4 = fVar40;
            uStack_29c = 0x3f800000;
            fStack_2a0 = fVar39;
            if ((DAT_181b2b565 == '\0') ||
               (cVar9 = recovered_180080860(pplVar28 + 3), pplVar22 = pplStack_570, cVar9 == '\0'))
            {
              aplStack_558[0] = pplVar28[0x14];
              fVar39 = _DAT_181b2beb0 - SUB84(aplStack_558[0],0);
              fVar40 = _DAT_181b2beb4 - (float)((ulonglong)aplStack_558[0] >> 0x20);
              fVar39 = fVar40 * fVar40 + fVar39 * fVar39 +
                       (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15)) *
                       (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15));
              if (fVar39 < 0.0) {
                fStack_508 = (float)func_0x0001801cb525();
              }
              else {
                fStack_508 = SQRT(fVar39);
              }
              pplVar22 = pplStack_570;
              if (fStack_508 <= (float)_DAT_181b2b57c) {
                uVar29 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),_DAT_181b2becc
                                 );
                recovered_180067e80(&fStack_448,&DAT_181b2be70,pplVar28 + 0x14,_DAT_181b2bec8,uVar29
                                   );
                in_stack_fffffffffffffa48 = (longlong *****)(uVar29 & 0xffffffff00000000);
                recovered_180067e80(&fStack_350,&DAT_181b2be70,pplVar28 + 0x2c);
                fVar40 = fStack_444;
                fVar39 = fStack_448;
                uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                pplVar22 = pplStack_570;
                if (((((fVar6 <= fStack_448) && (fVar6 <= fStack_444)) && (fVar6 <= fStack_350)) &&
                    ((fVar45 = _DAT_181a031bc, fVar6 <= fStack_34c &&
                     (fStack_448 <= (float)iStack_574)))) && (fStack_444 <= (float)iStack_578)) {
                  plVar21 = pplVar28[0x14];
                  uStack_2b8 = plVar21;
                  plVar21 = uStack_2b8;
                  fVar45 = _DAT_181a0317c;
                  if (cVar10 != '\0') {
                    fVar45 = _DAT_181a03160;
                  }
                  uStack_2b8._4_4_ = (float)((ulonglong)plVar21 >> 0x20);
                  fVar45 = fVar45 + uStack_2b8._4_4_;
                  if ((iStack_574 < 1) || (iStack_578 < 1)) {
LAB_180082811:
                    uStackX_18 = CONCAT44(fStack_444,fStack_448);
                    fVar44 = fStack_444;
                  }
                  else {
                    uStack_2b8._0_4_ = SUB84(plVar21,0);
                    fVar41 = *(float *)(pplVar28 + 0x15);
                    fVar43 = (float)uStack_2b8 * _DAT_181b2be7c + fVar45 * _DAT_181b2be8c +
                             fVar41 * _DAT_181b2be9c + _DAT_181b2beac;
                    if ((fVar43 < _DAT_181a03124) ||
                       ((fVar49 = (float)iStack_574 * _DAT_181a031bc,
                        fVar44 = (float)iStack_578 * _DAT_181a031bc,
                        fVar44 = fVar44 - (fVar44 * ((float)uStack_2b8 * _DAT_181b2be74 +
                                                     fVar45 * _DAT_181b2be84 +
                                                     fVar41 * _DAT_181b2be94 + _DAT_181b2bea4)) /
                                          fVar43,
                        (fVar49 * ((float)uStack_2b8 * _DAT_181b2be70 + fVar45 * _DAT_181b2be80 +
                                   fVar41 * _DAT_181b2be90 + _DAT_181b2bea0)) / fVar43 + fVar49 <
                        fVar6 || (fVar44 < fVar6)))) goto LAB_180082811;
                  }
                  fVar41 = (float)((uint)(fStack_34c - fVar44) & _DAT_181a039d0);
                  if (fVar41 < _DAT_181a032e0) {
                    fVar41 = _DAT_181a032e0;
                  }
                  uStackX_18 = CONCAT44(uStackX_18._4_4_,fVar41);
                  fStack_584 = _DAT_181a031c8;
                  if (cVar10 != '\0') {
                    fStack_584 = _DAT_181a031fc;
                  }
                  fStack_584 = fVar41 * fStack_584;
                  afStack_450[0] = (fStack_350 + fStack_448) * _DAT_181a031bc;
                  afStackX_20[0] = afStack_450[0] - fStack_584 * _DAT_181a031bc;
                  fStack_588 = fStack_34c;
                  if (fVar44 <= fStack_34c) {
                    fStack_588 = fVar44;
                  }
                  if (cVar10 == '\0') {
                    auStack_538._4_4_ = fStack_2a4;
                    auStack_538._0_4_ = fStack_2a8;
                    auStack_538._8_4_ = fStack_2a0;
                    auStack_538._12_4_ = uStack_29c;
                    auStack_400 = auStack_538;
                    if ((DAT_181b2bc70 == '\0') && (DAT_181b2b564 != '\0')) {
                      auStack_4f8 = auStack_538;
                    }
                    else {
                      auStack_4f8 = _DAT_181b2b478;
                    }
                    if ((((DAT_181b2bc70 == '\0') && (auVar48 = auStack_538, DAT_181b2b564 != '\0'))
                        || (auVar48 = _DAT_181b2b4a0, DAT_181b2bc70 == '\0')) &&
                       (DAT_181b2b564 != '\0')) {
                      _auStack_430 = auStack_538;
LAB_180082975:
                      if (DAT_181b2b564 == '\0') goto LAB_180082989;
                      auStack_4b8 = auStack_538;
LAB_18008299f:
                      if (DAT_181b2b564 == '\0') goto LAB_1800829b1;
                      auStack_328 = auStack_538;
LAB_1800829c8:
                      if (DAT_181b2b564 == '\0') goto LAB_1800829da;
                      auStack_3a8 = auStack_538;
LAB_1800829f2:
                      if (DAT_181b2b564 == '\0') goto LAB_180082a01;
LAB_180082a15:
                      if (DAT_181b2b564 != '\0') goto LAB_180082a2d;
                    }
                    else {
                      _auStack_430 = _DAT_181b2b53c;
                      if (DAT_181b2bc70 == '\0') goto LAB_180082975;
LAB_180082989:
                      auStack_4b8 = _DAT_181b2b4c8;
                      if (DAT_181b2bc70 == '\0') goto LAB_18008299f;
LAB_1800829b1:
                      auStack_328 = _DAT_181b2b4dc;
                      if (DAT_181b2bc70 == '\0') goto LAB_1800829c8;
LAB_1800829da:
                      auStack_3a8 = _DAT_181b2b4f0;
                      if (DAT_181b2bc70 == '\0') goto LAB_1800829f2;
LAB_180082a01:
                      auStack_538 = _DAT_181b2b508;
                      if (DAT_181b2bc70 == '\0') goto LAB_180082a15;
                    }
                    auStack_400 = _DAT_181b2b550;
                  }
                  else {
                    auStack_4f8 = auVar48;
                    _auStack_430 = auVar48;
                    auStack_4b8 = auVar48;
                    auStack_328 = auVar48;
                    auStack_3a8 = auVar48;
                    auStack_400 = auVar48;
                    auStack_538 = auVar48;
                  }
LAB_180082a2d:
                  auVar46 = auStack_4b8;
                  uVar15 = _DAT_181a03240;
                  uStack_2b8 = plVar21;
                  if (DAT_181b2b46d != '\0') {
                    if (_DAT_181b2f2c0 == 0) {
                      _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
                    }
                    fVar45 = _DAT_181b2b578;
                    if (_DAT_181b2b578 <= _DAT_181a03314) {
                      fVar45 = _DAT_181a03314;
                    }
                    fVar44 = fVar45 * _DAT_181a031bc;
                    fVar43 = *(float *)(_DAT_181b2f2c0 + 0x10) * _DAT_181a031bc - fVar44;
                    fVar41 = _DAT_181a032fc;
                    if (_DAT_181b2b470 != 0) {
                      if (_DAT_181b2b470 == 1) {
                        fVar41 = *(float *)(_DAT_181b2f2c0 + 0x14) * _DAT_181a031bc - fVar44;
                      }
                      else {
                        fVar41 = (*(float *)(_DAT_181b2f2c0 + 0x14) - fVar45) - _DAT_181a032fc;
                      }
                    }
                    aplStack_568[0] = (longlong *)CONCAT44(fVar41,fVar43);
                    aplStack_558[0] = (longlong *)CONCAT44(fVar44 + fVar41,fVar44 + fVar43);
                    fStack_348 = fVar39;
                    fStack_344 = fVar40;
                    uVar11 = func_0x000180004f90(auStack_4f8);
                    uVar15 = _DAT_181a03240;
                    in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,_DAT_181a03240);
                    func_0x000180027b00(lStack_580,&fStack_348,aplStack_558,uVar11,
                                        in_stack_fffffffffffffa48);
                    uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa50 >> 0x20);
                    if (((_DAT_181b2b474 == 0) || (DAT_181b2f6da != '\0')) || (_DAT_181b2f3d0 == 0))
                    {
                      fVar41 = (float)uStackX_18;
                    }
                    else {
                      if (DAT_181b2bc70 == '\0') {
                        uStack_340 = 0x3f800000;
                        uStack_33c = 0x3f800000;
                        auStack_338[0] = 0;
                        fStack_318 = fVar45 + fVar43 + _DAT_181a03270;
                        fStack_314 = fVar45 + fVar41 + _DAT_181a03270;
                        fStack_310 = fVar43 - _DAT_181a03270;
                        fStack_30c = fVar41 - _DAT_181a03270;
                        in_stack_fffffffffffffa58 =
                             (undefined8 *)
                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffa58 >> 0x20),0x5affffff
                                     );
                        puVar16 = &uStack_340;
                        func_0x000180028a10(lStack_580,_DAT_181b2f3d0,&fStack_310,&fStack_318,
                                            auStack_338,puVar16,in_stack_fffffffffffffa58);
                        uVar50 = (undefined4)((ulonglong)puVar16 >> 0x20);
                      }
                      lVar7 = lStack_580;
                      lVar17 = _DAT_181b2f3d0;
                      uStack_308 = 0x3f800000;
                      uStack_304 = 0x3f800000;
                      uStack_300 = 0;
                      fStack_2f8 = fVar45 + fVar43;
                      fStack_2f4 = fVar45 + fVar41;
                      lVar19 = *(longlong *)(lStack_580 + 0x98);
                      if (_DAT_181b2f3d0 != lVar19) {
                        func_0x0001800255e0(lStack_580,_DAT_181b2f3d0);
                      }
                      func_0x000180025660(lVar7,6,4);
                      in_stack_fffffffffffffa50 = (longlong *****)CONCAT44(uVar50,0xffffffff);
                      in_stack_fffffffffffffa48 = (longlong *****)&uStack_308;
                      func_0x0001800257a0(lVar7,aplStack_568,&fStack_2f8,&uStack_300,
                                          in_stack_fffffffffffffa48,in_stack_fffffffffffffa50);
                      if (lVar17 != lVar19) {
                        if (*(int *)(lVar7 + 0x68) < 1) {
                          _wassert(&UNK_180213518,&UNK_18020d8d0,0x758);
                        }
                        iVar14 = *(int *)(lVar7 + 0x68);
                        iVar12 = iVar14 + -1;
                        *(int *)(lVar7 + 0x68) = iVar12;
                        if (iVar12 != 0) {
                          uVar42 = *(undefined8 *)
                                    (*(longlong *)(lVar7 + 0x70) + -0x10 + (longlong)iVar14 * 8);
                        }
                        *(undefined8 *)(lVar7 + 0x98) = uVar42;
                        func_0x000180025310(lVar7);
                      }
                      DAT_181b2f6da = '\x01';
                      fVar41 = (float)uStackX_18;
                      fVar37 = fStackX_10;
                    }
                  }
                  fVar40 = fStack_584;
                  fVar39 = fStack_588;
                  fVar45 = afStackX_20[0];
                  lVar19 = _DAT_181b2f2c0;
                  if (DAT_181b2b498 != '\0') {
                    if (_DAT_181b2b49c == 0) {
                      auStack_4f8 = auVar48;
                      if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
                        _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
                      }
                      lVar19 = func_0x00018000a880(**(undefined8 **)(lVar19 + 0x4908),0,
                                                   &UNK_18020ed28);
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa58 >> 0x20);
                      if (lVar19 != 0) {
                        if ((DAT_181b2b4b0 != '\0') && (DAT_181b2bc70 == '\0')) {
                          if (cVar10 == '\0') {
                            uVar11 = func_0x000180004f90(0x181b2b4b4);
                          }
                          else {
                            uVar11 = 0x2d0000ff;
                          }
                          fStack_2f0 = fVar40 + fVar45;
                          fStack_2ec = fVar39 + fVar41;
                          in_stack_fffffffffffffa50 =
                               (longlong *****)
                               ((ulonglong)in_stack_fffffffffffffa50 & 0xffffffff00000000);
                          in_stack_fffffffffffffa48 =
                               (longlong *****)
                               ((ulonglong)in_stack_fffffffffffffa48 & 0xffffffff00000000);
                          fStack_2e8 = fVar45;
                          fStack_2e4 = fVar39;
                          func_0x000180027d60(lVar19,&fStack_2e8,&fStack_2f0,uVar11,
                                              in_stack_fffffffffffffa48,in_stack_fffffffffffffa50);
                        }
                        fStack_2e0 = fVar40 + fVar45;
                        fStack_2dc = fVar39 + fVar41;
                        fStack_388 = fVar45;
                        fStack_384 = fVar39;
                        uVar11 = func_0x000180004f90(auStack_4f8);
                        in_stack_fffffffffffffa58 = (undefined8 *)CONCAT44(uVar50,uVar15);
                        in_stack_fffffffffffffa50 =
                             (longlong *****)
                             ((ulonglong)in_stack_fffffffffffffa50 & 0xffffffff00000000);
                        in_stack_fffffffffffffa48 =
                             (longlong *****)
                             ((ulonglong)in_stack_fffffffffffffa48 & 0xffffffff00000000);
                        func_0x000180027c60(lVar19,&fStack_388,&fStack_2e0,uVar11,
                                            in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,
                                            in_stack_fffffffffffffa58);
                      }
                    }
                    else {
                      if (_DAT_181b2b49c != 1) goto LAB_180082f28;
                      in_stack_fffffffffffffa58 =
                           (undefined8 *)
                           CONCAT44((int)((ulonglong)in_stack_fffffffffffffa58 >> 0x20),
                                    _DAT_181a032fc);
                      in_stack_fffffffffffffa50 =
                           (longlong *****)
                           CONCAT44((int)((ulonglong)in_stack_fffffffffffffa50 >> 0x20),uVar15);
                      in_stack_fffffffffffffa48 = (longlong *****)auStack_4f8;
                      auStack_4f8 = auVar48;
                      recovered_180080a40();
                    }
                    fVar41 = (float)uStackX_18;
                  }
LAB_180082f28:
                  fVar45 = fStack_588;
                  if (DAT_181b2b51c != '\0') {
                    if ((_DAT_181b2b524 == 0) || (_DAT_181b2b524 == 1)) {
                      in_stack_fffffffffffffa48 =
                           (longlong *****)
                           CONCAT71((int7)((ulonglong)in_stack_fffffffffffffa48 >> 8),cVar10);
                      recovered_180081370(*(undefined2 *)(pplVar28 + 5));
                    }
                    else {
                      uVar51 = (undefined7)((ulonglong)in_stack_fffffffffffffa58 >> 8);
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                      if (_DAT_181b2b524 == 2) {
                        in_stack_fffffffffffffa58 = (undefined8 *)CONCAT71(uVar51,cVar10);
                        in_stack_fffffffffffffa50 =
                             (longlong *****)
                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffa50 >> 0x20),fVar41);
                        in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,fStack_584);
                        recovered_180081850(*(undefined2 *)(pplVar28 + 5));
                      }
                      else if (_DAT_181b2b524 == 3) {
                        in_stack_fffffffffffffa58 = (undefined8 *)CONCAT71(uVar51,cVar10);
                        in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,fStack_584);
                        recovered_180081e00(*(undefined2 *)(pplVar28 + 5));
                      }
                    }
                  }
                  uStack_510 = 0x40800000;
                  uStack_50c = 0x40800000;
                  uStack_518 = 0x40800000;
                  uStack_458 = 0;
                  uStack_514 = 0x40800000;
                  uStack_454 = 0;
                  if (DAT_181b2b51c != '\0') {
                    if (_DAT_181b2b524 == 0) {
                      uStack_518 = 0x41200000;
                    }
                    else if (_DAT_181b2b524 == 1) {
                      uStack_514 = 0x41200000;
                    }
                    else if (_DAT_181b2b524 == 2) {
                      uStack_50c = 0x41300000;
                    }
                    else if (_DAT_181b2b524 == 3) {
                      uStack_510 = 0x41300000;
                    }
                  }
                  pfStack_1e8 = afStackX_20;
                  puStack_1e0 = &uStack_518;
                  pfStack_1d8 = &fStack_588;
                  puStack_1d0 = &uStack_458;
                  pfStack_1c8 = &fStack_584;
                  puStack_1c0 = &uStack_514;
                  puStack_1b8 = &uStack_454;
                  pfStack_1b0 = afStack_450;
                  puStack_1a8 = &uStack_510;
                  puStack_1a0 = &uStackX_18;
                  puStack_198 = &uStack_50c;
                  aplStack_568[0] = &lStack_580;
                  if (DAT_181b2b4c4 != '\0') {
                    plVar21 = pplVar28[9];
                    if (plVar21 == (longlong *)0x0) {
                      uStack_2c8 = _DAT_181a035f0;
                      uStack_2c4 = _UNK_181a035f4;
                      uStack_2c0 = _UNK_181a035f8;
                      uStack_2bc = _UNK_181a035fc;
                      auStack_2d8._8_4_ = _DAT_1819d8288;
                      auStack_2d8._0_8_ = _DAT_1819d8280;
                      uStack_2cc = _DAT_1819d828c;
                      uStack_2ca = 0;
                      puVar16 = (undefined4 *)auStack_2d8;
                      fVar37 = (float)((uint)fVar37 | 1);
                    }
                    else {
                      pauVar18 = (undefined (*) [16])(pplVar28 + 7);
                      if ((longlong *)0xf < pplVar28[10]) {
                        pauVar18 = *(undefined (**) [16])*pauVar18;
                      }
                      auStack_4f8 = ZEXT816(0);
                      if ((longlong *)0x7fffffffffffffff < plVar21) goto LAB_180084f07;
                      if (plVar21 < (longlong *)0x10) {
                        uStack_4e8 = plVar21;
                        uStack_4e0 = 0xf;
                        auStack_4f8 = *pauVar18;
                      }
                      else {
                        uVar29 = (ulonglong)plVar21 | 0xf;
                        if (uVar29 < 0x8000000000000000) {
                          if (uVar29 < 0x16) {
                            uVar29 = 0x16;
                          }
                        }
                        else {
                          uVar29 = 0x7fffffffffffffff;
                        }
                        uVar42 = func_0x000180024110(uVar29 + 1);
                        auStack_4f8._0_8_ = uVar42;
                        uStack_4e8 = plVar21;
                        uStack_4e0 = uVar29;
                        func_0x0001801ca88d(uVar42,pauVar18,(longlong)plVar21 + 1);
                      }
                      puVar16 = (undefined4 *)auStack_4f8;
                      fVar37 = (float)((uint)fStackX_10 | 2);
                    }
                    uStack_498 = *puVar16;
                    uStack_494 = puVar16[1];
                    uStack_490 = puVar16[2];
                    uStack_48c = puVar16[3];
                    auStack_488 = *(undefined (*) [16])(puVar16 + 4);
                    *(undefined8 *)(puVar16 + 4) = 0;
                    *(undefined8 *)(puVar16 + 6) = 0xf;
                    *(undefined *)puVar16 = 0;
                    fStackX_8 = fVar37;
                    fStackX_10 = fVar37;
                    ppppplVar27 = in_stack_fffffffffffffa50;
                    if (((uint)fVar37 & 2) != 0) {
                      fVar37 = (float)((uint)fVar37 & 0xfffffffd);
                      fStackX_8 = fVar37;
                      fStackX_10 = fVar37;
                      recovered_180066e40(auStack_4f8);
                      ppppplVar27 = in_stack_fffffffffffffa50;
                    }
                    if (((uint)fVar37 & 1) == 0) {
LAB_180083286:
                      lVar19 = _DAT_181b2f2c0;
                      plVar21 = _DAT_181b4f000;
                      if ((((_DAT_181b4f000 != (longlong *)0x0) ||
                           (plVar21 = _DAT_181b4f020, _DAT_181b4f020 != (longlong *)0x0)) ||
                          (plVar21 = _DAT_181b4f008, _DAT_181b4f008 != (longlong *)0x0)) ||
                         (((plVar21 = _DAT_181b4eff0, _DAT_181b4eff0 != (longlong *)0x0 ||
                           (plVar21 = _DAT_181b4f018, _DAT_181b4f018 != (longlong *)0x0)) ||
                          ((plVar21 = _DAT_181b4eff8, _DAT_181b4eff8 != (longlong *)0x0 ||
                           (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                           plVar21 != (longlong *)0x0)))))) {
                        aplStack_558[0] = plVar21;
                        func_0x0001800149b0(plVar21);
                        func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                        func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                            *(undefined8 *)(plVar21[8] + 8));
                      }
                      fVar39 = _DAT_181a0348c;
                      in_stack_fffffffffffffa50 = (longlong *****)&uStack_498;
                      if (0xf < (ulonglong)auStack_488._8_8_) {
                        in_stack_fffffffffffffa50 = (longlong *****)CONCAT44(uStack_494,uStack_498);
                      }
                      if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                        fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                        in_stack_fffffffffffffa50 = ppppplVar27;
                        fVar40 = 0.0;
                      }
                      else {
                        in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                        in_stack_fffffffffffffa48 =
                             (longlong *****)
                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),
                                      _DAT_181a0348c);
                        func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_440,
                                            *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                            in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,0);
                        fStack_440 = (float)(int)(fStack_440 + _DAT_181a03228);
                        fVar41 = fStack_43c;
                        fVar40 = fStack_440;
                      }
                      if (plVar21 != (longlong *)0x0) {
                        func_0x000180014ae0();
                      }
                      recovered_180084f20(&pfStack_1e8,&fStack_548,_DAT_181b2b528,
                                          CONCAT44(fVar41,fVar40));
                      if (plVar21 == (longlong *)0x0) {
                        fVar40 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                      }
                      else {
                        fVar40 = *(float *)((longlong)plVar21 + 0x14);
                      }
                      if (DAT_181b2bc70 == '\0') {
                        puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                        uVar29 = auStack_488._8_8_;
                        lVar19 = lStack_580;
                        fVar45 = fStack_544;
                        fVar37 = fVar39;
                        fVar43 = fStack_548;
                        fVar44 = fVar39;
                        do {
                          uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                          if ((fVar44 != 0.0) || (fVar37 != 0.0)) {
                            puVar30 = (undefined8 *)&uStack_498;
                            if (0xf < uVar29) {
                              puVar30 = puVar31;
                            }
                            fStack_380 = fVar43 + fVar44;
                            fStack_37c = fVar45 + fVar37;
                            lVar17 = -1;
                            do {
                              lVar17 = lVar17 + 1;
                            } while (*(char *)((longlong)puVar30 + lVar17) != '\0');
                            fVar41 = fVar40;
                            if (puVar30 != (undefined8 *)((longlong)puVar30 + lVar17)) {
                              plVar38 = plVar21;
                              if (plVar21 == (longlong *)0x0) {
                                plVar38 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                              }
                              if (fVar40 == 0.0) {
                                fVar41 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                              }
                              if (*(longlong *)(plVar38[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                                _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                              }
                              uStack_128 = *(undefined4 *)(lVar19 + 0x88);
                              uStack_124 = *(undefined4 *)(lVar19 + 0x8c);
                              uStack_120 = *(undefined4 *)(lVar19 + 0x90);
                              uStack_11c = *(undefined4 *)(lVar19 + 0x94);
                              in_stack_fffffffffffffa50 = (longlong *****)&uStack_128;
                              in_stack_fffffffffffffa48 =
                                   (longlong *****)CONCAT44(uVar50,0xc8000000);
                              func_0x000180030c90(plVar38,lVar19,fVar41,&fStack_380,
                                                  in_stack_fffffffffffffa48,
                                                  in_stack_fffffffffffffa50,puVar30,
                                                  (undefined8 *)((longlong)puVar30 + lVar17),0,0);
                              puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                              uVar29 = auStack_488._8_8_;
                              lVar19 = lStack_580;
                              fVar45 = fStack_544;
                              in_stack_fffffffffffffa58 = puVar30;
                              fVar43 = fStack_548;
                            }
                          }
                          fVar37 = fVar37 + fVar6;
                        } while ((fVar37 <= fVar6) ||
                                (fVar44 = fVar44 + fVar6, fVar37 = fVar39, fVar44 <= fVar6));
                        puVar30 = (undefined8 *)&uStack_498;
                        if (0xf < uVar29) {
                          puVar30 = puVar31;
                        }
                        uVar13 = func_0x000180004f90(auStack_4b8);
                        uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                        fStack_378 = fVar43 + _DAT_181a031d8;
                        fStack_374 = fVar45;
                        if ((uVar13 & 0xff000000) != 0) {
                          lVar17 = -1;
                          do {
                            lVar17 = lVar17 + 1;
                          } while (*(char *)((longlong)puVar30 + lVar17) != '\0');
                          if (puVar30 != (undefined8 *)((longlong)puVar30 + lVar17)) {
                            plVar38 = plVar21;
                            if (plVar21 == (longlong *)0x0) {
                              plVar38 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                            }
                            fVar37 = fVar40;
                            if (fVar40 == 0.0) {
                              fVar37 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                            }
                            if (*(longlong *)(plVar38[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                            }
                            uStack_168 = *(undefined4 *)(lVar19 + 0x88);
                            uStack_164 = *(undefined4 *)(lVar19 + 0x8c);
                            uStack_160 = *(undefined4 *)(lVar19 + 0x90);
                            uStack_15c = *(undefined4 *)(lVar19 + 0x94);
                            in_stack_fffffffffffffa50 = (longlong *****)&uStack_168;
                            in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,uVar13);
                            func_0x000180030c90(plVar38,lVar19,fVar37,&fStack_378,
                                                in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,
                                                puVar30,(undefined8 *)((longlong)puVar30 + lVar17),0
                                                ,0);
                            puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                            uVar29 = auStack_488._8_8_;
                            lVar19 = lStack_580;
                            in_stack_fffffffffffffa58 = puVar30;
                          }
                        }
                        puVar30 = (undefined8 *)&uStack_498;
                        if (0xf < uVar29) {
                          puVar30 = puVar31;
                        }
                        uVar13 = func_0x000180004f90(auStack_4b8);
                        uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                        fVar37 = fStackX_10;
                        if ((uVar13 & 0xff000000) != 0) {
                          lVar17 = -1;
                          do {
                            lVar17 = lVar17 + 1;
                          } while (*(char *)((longlong)puVar30 + lVar17) != '\0');
                          if (puVar30 != (undefined8 *)((longlong)puVar30 + lVar17)) {
                            if (plVar21 == (longlong *)0x0) {
                              plVar21 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                            }
                            if (fVar40 == 0.0) {
                              fVar40 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                            }
                            if (*(longlong *)(plVar21[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                            }
                            uStack_158 = *(undefined4 *)(lVar19 + 0x88);
                            uStack_154 = *(undefined4 *)(lVar19 + 0x8c);
                            uStack_150 = *(undefined4 *)(lVar19 + 0x90);
                            uStack_14c = *(undefined4 *)(lVar19 + 0x94);
                            in_stack_fffffffffffffa50 = (longlong *****)&uStack_158;
                            in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,uVar13);
                            func_0x000180030c90(plVar21,lVar19,fVar40,&fStack_548,
                                                in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,
                                                puVar30,(undefined8 *)((longlong)puVar30 + lVar17),0
                                                ,0);
                            fVar37 = fStackX_10;
                            in_stack_fffffffffffffa58 = puVar30;
                          }
                        }
                      }
                      else {
                        puVar31 = (undefined8 *)&uStack_498;
                        if (0xf < (ulonglong)auStack_488._8_8_) {
                          puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                        }
                        auStack_4f8 = auVar46;
                        if ((puVar31 != (undefined8 *)0x0) && (*(char *)puVar31 != '\0')) {
                          lVar19 = lStack_580;
                          fVar37 = fVar39;
                          fVar40 = fVar39;
                          if (plVar21 == (longlong *)0x0) {
                            fVar45 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                          }
                          else {
                            fVar45 = *(float *)((longlong)plVar21 + 0x14);
                          }
                          do {
                            uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                            if ((fVar40 != 0.0) || (fVar37 != 0.0)) {
                              fStack_370 = fStack_548 + fVar40;
                              fStack_36c = fStack_544 + fVar37;
                              lVar17 = -1;
                              do {
                                lVar17 = lVar17 + 1;
                              } while (*(char *)((longlong)puVar31 + lVar17) != '\0');
                              fVar41 = fVar45;
                              if (puVar31 != (undefined8 *)((longlong)puVar31 + lVar17)) {
                                plVar38 = plVar21;
                                if (plVar21 == (longlong *)0x0) {
                                  plVar38 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                                }
                                if (fVar45 == 0.0) {
                                  fVar41 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                                }
                                if (*(longlong *)(plVar38[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                                  _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                                }
                                uStack_148 = *(undefined4 *)(lVar19 + 0x88);
                                uStack_144 = *(undefined4 *)(lVar19 + 0x8c);
                                uStack_140 = *(undefined4 *)(lVar19 + 0x90);
                                uStack_13c = *(undefined4 *)(lVar19 + 0x94);
                                in_stack_fffffffffffffa50 = (longlong *****)&uStack_148;
                                in_stack_fffffffffffffa48 =
                                     (longlong *****)CONCAT44(uVar50,0xc8000000);
                                in_stack_fffffffffffffa58 = puVar31;
                                func_0x000180030c90(plVar38,lVar19,fVar41,&fStack_370,
                                                    in_stack_fffffffffffffa48,
                                                    in_stack_fffffffffffffa50,puVar31,
                                                    (undefined8 *)((longlong)puVar31 + lVar17),0,0);
                                lVar19 = lStack_580;
                              }
                            }
                            fVar37 = fVar37 + fVar6;
                          } while ((fVar37 <= fVar6) ||
                                  (fVar40 = fVar40 + fVar6, fVar37 = fVar39, fVar40 <= fVar6));
                          uVar13 = func_0x000180004f90(auStack_4f8);
                          uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                          fVar37 = fStackX_10;
                          if ((uVar13 & 0xff000000) != 0) {
                            lVar17 = -1;
                            do {
                              lVar17 = lVar17 + 1;
                            } while (*(char *)((longlong)puVar31 + lVar17) != '\0');
                            if (puVar31 != (undefined8 *)((longlong)puVar31 + lVar17)) {
                              if (plVar21 == (longlong *)0x0) {
                                plVar21 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                              }
                              if (fVar45 == 0.0) {
                                fVar45 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                              }
                              if (*(longlong *)(plVar21[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                                _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                              }
                              uStack_138 = *(undefined4 *)(lVar19 + 0x88);
                              uStack_134 = *(undefined4 *)(lVar19 + 0x8c);
                              uStack_130 = *(undefined4 *)(lVar19 + 0x90);
                              uStack_12c = *(undefined4 *)(lVar19 + 0x94);
                              in_stack_fffffffffffffa50 = (longlong *****)&uStack_138;
                              in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,uVar13);
                              func_0x000180030c90(plVar21,lVar19,fVar45,&fStack_548,
                                                  in_stack_fffffffffffffa48,
                                                  in_stack_fffffffffffffa50,puVar31,
                                                  (undefined8 *)((longlong)puVar31 + lVar17),0,0);
                              fVar37 = fStackX_10;
                              in_stack_fffffffffffffa58 = puVar31;
                            }
                          }
                        }
                      }
                      recovered_180066e40(&uStack_498);
                      goto LAB_180083751;
                    }
                    fVar37 = (float)((uint)fVar37 & 0xfffffffe);
                    fStackX_8 = fVar37;
                    fStackX_10 = fVar37;
                    if (CONCAT44(uStack_2bc,uStack_2c0) < 0x10) goto LAB_180083286;
                    if ((CONCAT44(uStack_2bc,uStack_2c0) + 1 < 0x1000) ||
                       ((auStack_2d8._0_8_ - *(longlong *)(auStack_2d8._0_8_ + -8)) - 8U < 0x20)) {
                      func_0x000180127e40();
                      goto LAB_180083286;
                    }
                    _invoke_watson(0,0,0,0,0);
LAB_180084cc3:
                    _invoke_watson(0,0,0,0,0);
LAB_180084cd9:
                    _invoke_watson(0,0,0,0,0);
                    goto LAB_180084cef;
                  }
LAB_180083751:
                  uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                  pplVar22 = (longlong **)0x0;
                  if (DAT_181b2b4d8 != '\0') {
                    fVar39 = (float)func_0x0001801cb513();
                    uVar13 = (uint)fVar39;
                    pcVar35 = (char *)((longlong)&uStack_4e8 + 5);
                    if ((int)uVar13 < 0) {
                      uVar13 = -uVar13;
                      do {
                        pcVar36 = pcVar35;
                        pcVar35 = pcVar36 + -1;
                        *pcVar35 = (char)uVar13 + (char)((ulonglong)uVar13 / 10) * -10 + '0';
                        uVar13 = (uint)((ulonglong)uVar13 / 10);
                      } while (uVar13 != 0);
                      pcVar35 = pcVar36 + -2;
                      *pcVar35 = '-';
                    }
                    else {
                      do {
                        pcVar35 = pcVar35 + -1;
                        *pcVar35 = (char)uVar13 + (char)((ulonglong)uVar13 / 10) * -10 + '0';
                        uVar13 = (uint)((ulonglong)uVar13 / 10);
                      } while (uVar13 != 0);
                    }
                    recovered_180078780(auStack_2d8,pcVar35,(longlong)&uStack_4e8 + 5,&fStackX_8);
                    pauVar18 = (undefined (*) [16])recovered_180066ec0(auStack_2d8,&UNK_1819d8290,1)
                    ;
                    auStack_4b8 = *pauVar18;
                    auStack_4a8 = pauVar18[1];
                    *(undefined8 *)pauVar18[1] = 0;
                    *(undefined8 *)(pauVar18[1] + 8) = 0xf;
                    (*pauVar18)[0] = 0;
                    fStackX_8 = (float)((uint)fVar37 | 0x1c);
                    fStackX_10 = fStackX_8;
                    recovered_180066e40(auStack_2d8);
                    lVar19 = _DAT_181b2f2c0;
                    plVar21 = _DAT_181b4eff8;
                    if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                       (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                       ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                      aplStack_558[0] = plVar21;
                      func_0x0001800149b0(plVar21);
                      func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                      func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                          *(undefined8 *)(plVar21[8] + 8));
                      ppppplVar27 = in_stack_fffffffffffffa50;
                    }
                    in_stack_fffffffffffffa50 = (longlong *****)auStack_4b8;
                    if (0xf < (ulonglong)auStack_4a8._8_8_) {
                      in_stack_fffffffffffffa50 = (longlong *****)auStack_4b8._0_8_;
                    }
                    if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                      fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                      in_stack_fffffffffffffa50 = ppppplVar27;
                      fVar37 = 0.0;
                    }
                    else {
                      in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                      func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_438,
                                          *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                          CONCAT44(uVar50,_DAT_181a0348c),in_stack_fffffffffffffa50,
                                          0);
                      fStack_438 = (float)(int)(fStack_438 + _DAT_181a03228);
                      fVar41 = fStack_434;
                      fVar37 = fStack_438;
                    }
                    if (plVar21 != (longlong *)0x0) {
                      func_0x000180014ae0();
                    }
                    recovered_180084f20(&pfStack_1e8,auStack_250,_DAT_181b2b52c,
                                        CONCAT44(fVar41,fVar37));
                    in_stack_fffffffffffffa48 = (longlong *****)auStack_4b8;
                    if (0xf < (ulonglong)auStack_4a8._8_8_) {
                      in_stack_fffffffffffffa48 = (longlong *****)auStack_4b8._0_8_;
                    }
                    recovered_180085090(aplStack_568,plVar21,auStack_250,auStack_328,
                                        in_stack_fffffffffffffa48);
                    if (0xf < (ulonglong)auStack_4a8._8_8_) {
                      if ((0xfff < auStack_4a8._8_8_ + 1) &&
                         (0x1f < (ulonglong)
                                 (auStack_4b8._0_8_ +
                                 (-8 - (longlong)*(longlong ****)(auStack_4b8._0_8_ + -8)))))
                      goto LAB_180084cc3;
                      func_0x000180127e40();
                    }
                    auStack_4a8 = _DAT_181a03530;
                    auVar46[15] = 0;
                    auVar46._0_15_ = auStack_4b8._1_15_;
                    auStack_4b8 = auVar46 << 8;
                  }
                  auVar48 = _DAT_181a03530;
                  if ((DAT_181b2b4ec != '\0') &&
                     ((pplVar28[0x11] != (longlong *)0x0 || (pplVar28[0xd] != (longlong *)0x0)))) {
                    lVar19 = recovered_180085590();
                    if (*(longlong *)(lVar19 + 0x10) == 0) {
                      recovered_180085a10(_DAT_181b2f350);
                    }
                    pauVar18 = (undefined (*) [16])(pplVar28 + 0xf);
                    auStack_3f0 = ZEXT816(0);
                    auStack_3e0 = ZEXT816(0);
                    pplVar32 = (longlong **)pplVar28[0x11];
                    if ((longlong *)0xf < pplVar28[0x12]) {
                      pauVar18 = *(undefined (**) [16])*pauVar18;
                    }
                    if ((longlong **)0x7fffffffffffffff < pplVar32) {
                      func_0x000180052a50();
                      pcVar2 = (code *)swi(3);
                      (*pcVar2)();
                      return;
                    }
                    if (pplVar32 < (longlong **)0x10) {
                      uVar29 = 0xf;
                      auStack_3e0._8_8_ = 0xf;
                      auStack_3e0._0_8_ = pplVar32;
                      puVar20 = *(undefined **)*pauVar18;
                      auStack_3f0 = *pauVar18;
                    }
                    else {
                      uVar29 = (ulonglong)pplVar32 | 0xf;
                      if (uVar29 < 0x8000000000000000) {
                        if (uVar29 < 0x16) {
                          uVar29 = 0x16;
                        }
                      }
                      else {
                        uVar29 = 0x7fffffffffffffff;
                      }
                      puVar20 = (undefined *)func_0x000180024110(uVar29 + 1);
                      auStack_3f0._0_8_ = puVar20;
                      auStack_3e0._8_8_ = uVar29;
                      auStack_3e0._0_8_ = pplVar32;
                      func_0x0001801ca88d(puVar20,pauVar18,(undefined *)((longlong)pplVar32 + 1));
                    }
                    if (pplVar32 == (longlong **)0x0) {
                      pauVar18 = (undefined (*) [16])recovered_180080590(auStack_108,pplVar28 + 0xb)
                      ;
                      if (&auStack_3f0 != pauVar18) {
                        if (0xf < uVar29) {
                          puVar25 = puVar20;
                          if ((0xfff < uVar29 + 1) &&
                             (puVar25 = *(undefined **)(puVar20 + -8),
                             (undefined *)0x1f < puVar20 + (-8 - (longlong)puVar25)))
                          goto LAB_180084cd9;
                          func_0x000180127e40(puVar25);
                        }
                        puVar20 = *(undefined **)*pauVar18;
                        auStack_3f0 = *pauVar18;
                        auStack_3e0 = pauVar18[1];
                        pplVar32 = auStack_3e0._0_8_;
                        *(undefined8 *)pauVar18[1] = 0;
                        *(undefined8 *)(pauVar18[1] + 8) = 0xf;
                        (*pauVar18)[0] = 0;
                        uVar29 = auStack_3e0._8_8_;
                      }
                      recovered_180066e40(auStack_108);
                      if (pplVar32 != (longlong **)0x0) goto LAB_180083df3;
LAB_180083fc7:
                      lVar19 = _DAT_181b2f2c0;
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                      if (pplVar28[0xd] != (longlong *)0x0) {
                        plVar21 = _DAT_181b4eff8;
                        if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                           (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                           ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                          aplStack_558[0] = plVar21;
                          func_0x0001800149b0(plVar21);
                          func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                          func_0x0001800255e0(*(undefined8 *)
                                               (*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                              *(undefined8 *)(plVar21[8] + 8));
                          ppppplVar27 = in_stack_fffffffffffffa50;
                        }
                        in_stack_fffffffffffffa48 = (longlong *****)(pplVar28 + 0xb);
                        in_stack_fffffffffffffa50 = in_stack_fffffffffffffa48;
                        if ((longlong *)0xf < pplVar28[0xe]) {
                          in_stack_fffffffffffffa50 = (longlong *****)*in_stack_fffffffffffffa48;
                        }
                        if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                          fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                          in_stack_fffffffffffffa50 = ppppplVar27;
                          fVar37 = 0.0;
                        }
                        else {
                          in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                          func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_470,
                                              *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                              CONCAT44(uVar50,_DAT_181a0348c),
                                              in_stack_fffffffffffffa50,0);
                          fStack_470 = (float)(int)(fStack_470 + _DAT_181a03228);
                          fVar41 = fStack_46c;
                          fVar37 = fStack_470;
                        }
                        if (plVar21 != (longlong *)0x0) {
                          func_0x000180014ae0();
                        }
                        recovered_180084f20(&pfStack_1e8,auStack_248,_DAT_181b2b500,
                                            CONCAT44(fVar41,fVar37));
                        if ((longlong *)0xf < pplVar28[0xe]) {
                          in_stack_fffffffffffffa48 = (longlong *****)*in_stack_fffffffffffffa48;
                        }
                        recovered_180085090(aplStack_568,plVar21,auStack_248,auStack_3a8,
                                            in_stack_fffffffffffffa48);
                      }
                    }
                    else {
LAB_180083df3:
                      lVar19 = recovered_180085590();
                      if (*(longlong *)(lVar19 + 0x10) == 0) {
                        recovered_180085a10(_DAT_181b2f350);
                      }
                      plVar21 = (longlong *)recovered_180085590();
                      puVar25 = auStack_3f0;
                      if (0xf < uVar29) {
                        puVar25 = puVar20;
                      }
                      uVar34 = 0xcbf29ce484222325;
                      pplVar23 = pplVar22;
                      if (pplVar32 != (longlong **)0x0) {
                        do {
                          uVar34 = (uVar34 ^ (byte)puVar25[(longlong)pplVar23]) * 0x100000001b3;
                          pplVar23 = (longlong **)((longlong)pplVar23 + 1);
                        } while (pplVar23 < pplVar32);
                      }
                      aplStack_558[0] = plVar21;
                      lVar19 = recovered_180085cb0(plVar21,auStack_118,auStack_3f0,uVar34);
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa50 >> 0x20);
                      lVar19 = *(longlong *)(lVar19 + 8);
                      if (((lVar19 == 0) || (lVar19 == plVar21[1])) ||
                         (lVar19 = *(longlong *)(lVar19 + 0x30), lVar19 == 0)) goto LAB_180083fc7;
                      fVar37 = _DAT_181a03334;
                      recovered_180084f20(&pfStack_1e8,&fStack_478,_DAT_181b2b500,
                                          CONCAT44(_DAT_181a03334,_DAT_181a03334));
                      lVar7 = lStack_580;
                      uStack_368 = 0x3f800000;
                      uStack_364 = 0x3f800000;
                      uStack_360 = 0;
                      fStack_358 = fStack_478 + fVar37;
                      fStack_354 = fStack_474 + fVar37;
                      lVar17 = *(longlong *)(lStack_580 + 0x98);
                      if (lVar19 != lVar17) {
                        func_0x0001800255e0(lStack_580,lVar19);
                      }
                      func_0x000180025660(lVar7,6,4);
                      in_stack_fffffffffffffa50 = (longlong *****)CONCAT44(uVar50,0xffffffff);
                      in_stack_fffffffffffffa48 = (longlong *****)&uStack_368;
                      func_0x0001800257a0(lVar7,&fStack_478,&fStack_358,&uStack_360,
                                          in_stack_fffffffffffffa48,in_stack_fffffffffffffa50);
                      if (lVar19 != lVar17) {
                        if (*(int *)(lVar7 + 0x68) < 1) {
                          _wassert(&UNK_180213518,&UNK_18020d8d0,0x758);
                        }
                        iVar14 = *(int *)(lVar7 + 0x68);
                        iVar12 = iVar14 + -1;
                        *(int *)(lVar7 + 0x68) = iVar12;
                        if (iVar12 == 0) {
                          *(undefined8 *)(lVar7 + 0x98) = 0;
                          func_0x000180025310(lVar7);
                        }
                        else {
                          *(undefined8 *)(lVar7 + 0x98) =
                               *(undefined8 *)
                                (*(longlong *)(lVar7 + 0x70) + -0x10 + (longlong)iVar14 * 8);
                          func_0x000180025310(lVar7);
                        }
                      }
                    }
                    if (0xf < uVar29) {
                      puVar25 = puVar20;
                      if ((0xfff < uVar29 + 1) &&
                         (puVar25 = *(undefined **)(puVar20 + -8),
                         (undefined *)0x1f < puVar20 + (-8 - (longlong)puVar25))) {
LAB_180084cef:
                        _invoke_watson(0,0,0,0,0);
                        pcVar2 = (code *)swi(3);
                        (*pcVar2)();
                        return;
                      }
                      func_0x000180127e40(puVar25);
                    }
                  }
                  uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                  pplVar32 = pplVar28 + 3;
                  if ((DAT_181b2b504 != '\0') &&
                     (uVar13 = *(uint *)(pplVar28 + 0x13), 0 < (int)uVar13)) {
                    pcVar35 = acStack_394 + 1;
                    do {
                      pcVar35 = pcVar35 + -1;
                      *pcVar35 = (char)uVar13 + (char)((ulonglong)uVar13 / 10) * -10 + '0';
                      uVar13 = (uint)((ulonglong)uVar13 / 10);
                    } while (uVar13 != 0);
                    recovered_180078780(appppuStack_298,pcVar35,acStack_394 + 1,&fStackX_8);
                    fVar37 = fStackX_10;
                    if (uStack_280 - lStack_288 < 3) {
                      in_stack_fffffffffffffa50 = (longlong *****)0x0;
                      uVar50 = 1;
                      pauVar18 = (undefined (*) [16])
                                 recovered_1800678e0(appppuStack_298,3,lStack_288,0,&UNK_1819d8294,3
                                                    );
                    }
                    else {
                      ppppuVar33 = appppuStack_298;
                      if (0xf < uStack_280) {
                        ppppuVar33 = appppuStack_298[0];
                      }
                      if ((&UNK_1819d8296 < ppppuVar33) ||
                         ((undefined *)(lStack_288 + (longlong)ppppuVar33) < &UNK_1819d8294)) {
                        pplVar23 = (longlong **)0x3;
                      }
                      else {
                        pplVar23 = pplVar22;
                        if (&UNK_1819d8294 < ppppuVar33) {
                          pplVar23 = (longlong **)((longlong)ppppuVar33 + -0x1819d8294);
                        }
                      }
                      lVar19 = lStack_288 + 1;
                      lStack_288 = lStack_288 + 3;
                      func_0x0001801ca893((undefined *)((longlong)ppppuVar33 + 3),ppppuVar33,lVar19)
                      ;
                      func_0x0001801ca88d(ppppuVar33,&UNK_1819d8294,pplVar23);
                      func_0x0001801ca88d((undefined *)((longlong)ppppuVar33 + (longlong)pplVar23),
                                          &UNK_1819d8297 + (longlong)pplVar23,3 - (longlong)pplVar23
                                         );
                      pauVar18 = (undefined (*) [16])appppuStack_298;
                    }
                    auStack_420 = ZEXT816(0);
                    auStack_410 = ZEXT816(0);
                    auStack_420 = *pauVar18;
                    auStack_410 = pauVar18[1];
                    *(undefined8 *)pauVar18[1] = 0;
                    *(undefined8 *)(pauVar18[1] + 8) = 0xf;
                    (*pauVar18)[0] = 0;
                    fStackX_8 = (float)((uint)fVar37 | 0xe0);
                    fStackX_10 = fStackX_8;
                    recovered_180066e40(appppuStack_298);
                    lVar19 = _DAT_181b2f2c0;
                    plVar21 = _DAT_181b4eff8;
                    if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                       (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                       ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                      aplStack_558[0] = plVar21;
                      func_0x0001800149b0(plVar21);
                      func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                      func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                          *(undefined8 *)(plVar21[8] + 8));
                      ppppplVar27 = in_stack_fffffffffffffa50;
                    }
                    in_stack_fffffffffffffa50 = (longlong *****)auStack_420;
                    if (0xf < (ulonglong)auStack_410._8_8_) {
                      in_stack_fffffffffffffa50 = (longlong *****)auStack_420._0_8_;
                    }
                    if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                      fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                      in_stack_fffffffffffffa50 = ppppplVar27;
                      fVar37 = 0.0;
                    }
                    else {
                      in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                      func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_468,
                                          *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                          CONCAT44(uVar50,_DAT_181a0348c),in_stack_fffffffffffffa50,
                                          0);
                      fStack_468 = (float)(int)(fStack_468 + _DAT_181a03228);
                      fVar41 = fStack_464;
                      fVar37 = fStack_468;
                    }
                    if (plVar21 != (longlong *)0x0) {
                      func_0x000180014ae0();
                    }
                    recovered_180084f20(&pfStack_1e8,auStack_240,_DAT_181b2b518,
                                        CONCAT44(fVar41,fVar37));
                    in_stack_fffffffffffffa48 = (longlong *****)auStack_420;
                    if (0xf < (ulonglong)auStack_410._8_8_) {
                      in_stack_fffffffffffffa48 = (longlong *****)auStack_420._0_8_;
                    }
                    recovered_180085090(aplStack_568,plVar21,auStack_240,auStack_538,
                                        in_stack_fffffffffffffa48);
                    if ((ulonglong)auStack_410._8_8_ < 0x10) {
LAB_18008448b:
                      auStack_410 = auVar48;
                      auVar3[15] = 0;
                      auVar3._0_15_ = auStack_420._1_15_;
                      auStack_420 = auVar3 << 8;
                      goto LAB_18008449b;
                    }
                    if ((auStack_410._8_8_ + 1 < 0x1000) ||
                       ((ulonglong)
                        (auStack_420._0_8_ +
                        (-8 - (longlong)*(longlong ****)(auStack_420._0_8_ + -8))) < 0x20)) {
                      func_0x000180127e40();
                      goto LAB_18008448b;
                    }
                    _invoke_watson(0,0,0,0,0);
LAB_180084d1b:
                    _invoke_watson(0,0,0,0,0);
LAB_180084d31:
                    in_stack_fffffffffffffa48 = (longlong *****)0x0;
                    _invoke_watson(0,0,0,0,0);
                    goto LAB_180084d47;
                  }
LAB_18008449b:
                  auVar46 = auStack_400;
                  if (DAT_181b2b54c != '\0') {
                    uVar29 = (ulonglong)*(ushort *)((longlong)pplVar28 + 0x2a);
                    cVar10 = recovered_18007ea60(uVar29);
                    auVar46 = auStack_400;
                    if (cVar10 != '\0') {
                      recovered_18007eac0(appppplStack_278,uVar29 & 0xffff);
                      lVar19 = _DAT_181b2f2c0;
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                      auVar46 = auStack_400;
                      if (lStack_268 != 0) {
                        plVar21 = _DAT_181b4eff8;
                        if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                           (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                           ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                          aplStack_558[0] = plVar21;
                          func_0x0001800149b0(plVar21);
                          func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                          func_0x0001800255e0(*(undefined8 *)
                                               (*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                              *(undefined8 *)(plVar21[8] + 8));
                          ppppplVar27 = in_stack_fffffffffffffa50;
                        }
                        in_stack_fffffffffffffa50 = (longlong *****)appppplStack_278;
                        if (0xf < uStack_260) {
                          in_stack_fffffffffffffa50 = appppplStack_278[0];
                        }
                        if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                          fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                          in_stack_fffffffffffffa50 = ppppplVar27;
                          fVar37 = 0.0;
                        }
                        else {
                          in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                          func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_460,
                                              *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                              CONCAT44(uVar50,_DAT_181a0348c),
                                              in_stack_fffffffffffffa50,0);
                          fStack_460 = (float)(int)(fStack_460 + _DAT_181a03228);
                          fVar41 = fStack_45c;
                          fVar37 = fStack_460;
                        }
                        if (plVar21 != (longlong *)0x0) {
                          func_0x000180014ae0();
                        }
                        recovered_180084f20(&pfStack_1e8,auStack_238,_DAT_181b2b534,
                                            CONCAT44(fVar41,fVar37));
                        auVar46 = auStack_400;
                        in_stack_fffffffffffffa48 = (longlong *****)appppplStack_278;
                        if (0xf < uStack_260) {
                          in_stack_fffffffffffffa48 = appppplStack_278[0];
                        }
                        auStack_538 = auStack_400;
                        recovered_180085090(aplStack_568,plVar21,auStack_238,auStack_538,
                                            in_stack_fffffffffffffa48);
                      }
                      recovered_180066e40(appppplStack_278);
                    }
                  }
                  if (DAT_181b2b54d != '\0') {
                    uVar29 = (ulonglong)*(ushort *)((longlong)pplVar28 + 0x2a);
                    cVar10 = recovered_18007ea60(uVar29);
                    if ((((cVar10 != '\0') &&
                         (iVar14 = func_0x00018007e9d0(uVar29 & 0xffff), -1 < iVar14)) &&
                        (uVar34 = (ulonglong)iVar14,
                        uVar34 < (ulonglong)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) &&
                       ((*(char *)(_DAT_181b2f548 + 0x42 + uVar34 * 0x48) == '\0' &&
                        (*(longlong *)(_DAT_181b2f548 + 0x30 + uVar34 * 0x48) != 0)))) {
                      recovered_18007eb60(&uStack_4d8,uVar29 & 0xffff);
                      recovered_18007eac0(appppuStack_208,*(undefined2 *)((longlong)pplVar28 + 0x2a)
                                         );
                      recovered_18007fe70(appppuStack_188,appppuStack_208);
                      uVar8 = uStack_178;
                      uVar34 = uStack_1f0;
                      uVar29 = uStack_1f8;
                      ppppuVar33 = appppuStack_208[0];
                      ppppuVar26 = appppuStack_208;
                      if (0xf < uStack_1f0) {
                        ppppuVar26 = appppuStack_208[0];
                      }
                      ppppuVar24 = appppuStack_188;
                      if (0xf < uStack_170) {
                        ppppuVar24 = appppuStack_188[0];
                      }
                      if ((uStack_178 != uStack_1f8) ||
                         ((uStack_178 != 0 &&
                          (iVar14 = func_0x0001801ca8a5(ppppuVar24,ppppuVar26,uStack_178),
                          iVar14 != 0)))) {
                        auStack_3d0 = ZEXT816(0);
                        uStack_3c0 = 0;
                        uStack_3b8 = 0;
                        if (uVar29 < uVar8) {
                          recovered_180067b60();
LAB_180084f07:
                          func_0x000180052a50();
                          pcVar2 = (code *)swi(3);
                          (*pcVar2)();
                          return;
                        }
                        lVar17 = uVar29 - uVar8;
                        lVar19 = -1;
                        if (lVar17 != -1) {
                          lVar19 = lVar17;
                        }
                        ppppuVar26 = appppuStack_208;
                        if (0xf < uVar34) {
                          ppppuVar26 = ppppuVar33;
                        }
                        recovered_180066cc0(auStack_3d0,(longlong)ppppuVar26 + uVar8,lVar19);
                        fVar37 = fStackX_10;
                        fStackX_8 = (float)((uint)fStackX_10 | 0x100);
                        ppppplVar27 = (longlong *****)&uStack_4d8;
                        if (0xf < (ulonglong)auStack_4c8._8_8_) {
                          ppppplVar27 = (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                        }
                        fStackX_10 = fStackX_8;
                        if ((uStack_3c0 <= (ulonglong)auStack_4c8._0_8_) &&
                           ((pplVar23 = pplVar22, uStack_3c0 == 0 ||
                            ((lVar17 = auStack_4c8._0_8_ + (longlong)ppppplVar27,
                             lVar19 = func_0x0001801278a0(ppppplVar27,lVar17), lVar19 != lVar17 &&
                             (pplVar23 = (longlong **)(lVar19 - (longlong)ppppplVar27),
                             (longlong **)(lVar19 - (longlong)ppppplVar27) !=
                             (longlong **)0xffffffffffffffff)))))) {
                          _auStack_228 = ZEXT816(0);
                          auStack_218 = ZEXT816(0);
                          if ((ulonglong)auStack_4c8._0_8_ < pplVar23) {
                            pplVar23 = (longlong **)auStack_4c8._0_8_;
                          }
                          ppppplVar27 = (longlong *****)&uStack_4d8;
                          if (0xf < (ulonglong)auStack_4c8._8_8_) {
                            ppppplVar27 = (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                          }
                          recovered_180066cc0(auStack_228,ppppplVar27,pplVar23);
                          fStackX_8 = (float)((uint)fVar37 | 0x300);
                          fStackX_10 = fStackX_8;
                          if (0xf < (ulonglong)auStack_4c8._8_8_) {
                            if ((0xfff < auStack_4c8._8_8_ + 1) &&
                               (0x1f < (CONCAT44(uStack_4d4,uStack_4d8) -
                                       *(longlong *)(CONCAT44(uStack_4d4,uStack_4d8) + -8)) - 8U))
                            goto LAB_180084d1b;
                            func_0x000180127e40();
                          }
                          uStack_4d8 = auStack_228;
                          uStack_4d4 = uStack_224;
                          uStack_4d0 = uStack_220;
                          uStack_4cc = uStack_21c;
                          auStack_4c8 = auStack_218;
                          auStack_218 = auVar48;
                          auVar4[15] = 0;
                          auVar4._0_15_ = stack0xfffffffffffffdd9;
                          _auStack_228 = auVar4 << 8;
                          recovered_180066e40(auStack_228);
                        }
                        if (0xf < uStack_3b8) {
                          if ((0xfff < uStack_3b8 + 1) &&
                             (0x1f < (auStack_3d0._0_8_ - *(longlong *)(auStack_3d0._0_8_ + -8)) -
                                     8U)) goto LAB_180084d31;
                          func_0x000180127e40();
                        }
                        uStack_3c0 = 0;
                        uStack_3b8 = 0xf;
                        auVar5[15] = 0;
                        auVar5._0_15_ = auStack_3d0._1_15_;
                        auStack_3d0 = auVar5 << 8;
                      }
                      lVar19 = _DAT_181b4f010;
                      if (((_DAT_181b4f010 != 0) ||
                          (lVar19 = *(longlong *)(_DAT_181b2f2c0 + 0x3c30), lVar19 != 0)) &&
                         (auStack_4c8._0_8_ != 0)) {
                        in_stack_fffffffffffffa50 = (longlong *****)&uStack_4d8;
                        if (0xf < (ulonglong)auStack_4c8._8_8_) {
                          in_stack_fffffffffffffa50 =
                               (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                        }
                        in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                        func_0x000180030a70(lVar19,&uStack_230,*(undefined4 *)(lVar19 + 0x14),
                                            _DAT_181a03460,
                                            (ulonglong)in_stack_fffffffffffffa48 &
                                            0xffffffff00000000,in_stack_fffffffffffffa50,0);
                        recovered_180084f20(&pfStack_1e8,auStack_258,_DAT_181b2b530,uStack_230);
                        in_stack_fffffffffffffa48 = (longlong *****)&uStack_4d8;
                        if (0xf < (ulonglong)auStack_4c8._8_8_) {
                          in_stack_fffffffffffffa48 =
                               (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                        }
                        auStack_538 = auVar46;
                        recovered_180085090(aplStack_568,lVar19,auStack_258,auStack_538,
                                            in_stack_fffffffffffffa48);
                      }
                      recovered_180066e40(appppuStack_188);
                      recovered_180066e40(appppuStack_208);
                      recovered_180066e40(&uStack_4d8);
                    }
                  }
                  pplVar22 = pplStack_570;
                  fVar45 = _DAT_181a031bc;
                  fVar37 = fStackX_10;
                  if (DAT_181b2b538 != '\0') {
                    auStack_538._8_8_ = &iStack_578;
                    auStack_538._0_8_ = &iStack_574;
                    plStack_528 = &lStack_580;
                    puStack_520 = auStack_430;
                    recovered_180085390(auStack_538,pplVar28 + 0x14,(longlong)pplVar28 + 0xac);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xac,pplVar28 + 0x23);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xac,
                                        (longlong)pplVar28 + 0xc4);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xc4,
                                        (longlong)pplVar28 + 0xdc);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xdc,
                                        (longlong)pplVar28 + 0xf4);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xac,pplVar28 + 0x17);
                    recovered_180085390(auStack_538,pplVar28 + 0x17,pplVar28 + 0x1a);
                    recovered_180085390(auStack_538,pplVar28 + 0x1a,pplVar28 + 0x1d);
                    recovered_180085390(auStack_538,pplVar28 + 0x23,(longlong)pplVar28 + 0x124);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0x124,
                                        (longlong)pplVar28 + 0x13c);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0x124,pplVar28 + 0x26);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0x13c,pplVar28 + 0x29);
                    recovered_180085390(auStack_538,pplVar28 + 0x26,(longlong)pplVar28 + 0x154);
                    pplVar22 = pplStack_570;
                    fVar45 = _DAT_181a031bc;
                    fVar37 = fStackX_10;
                  }
                }
              }
            }
          }
          pplVar28 = (longlong **)*pplVar28;
        } while (pplVar28 != pplVar22);
      }
      auVar48 = ZEXT416(_DAT_181a03460);
      pplVar22 = (longlong **)0x0;
      if ((DAT_181b2b46e != '\0') &&
         (pplVar28 = (longlong **)*_DAT_181b2be38, pplVar32 = _DAT_181b2be38,
         fVar41 = _DAT_181a0331c, pplVar28 != _DAT_181b2be38)) {
        do {
          if (((((*(char *)((longlong)pplVar28 + 0x19) != '\0') &&
                (*(char *)((longlong)pplVar28 + 0x1a) == '\0')) &&
               ((DAT_181b2bedc != '\0' || (*(char *)((longlong)pplVar28 + 0x1c) != '\0')))) &&
              ((DAT_181b2b565 == '\0' ||
               (cVar10 = recovered_180080860(pplVar28 + 3), cVar10 == '\0')))) &&
             ((DAT_181b2b406 == '\0' || (*(char *)((longlong)pplVar28 + 0x1b) == '\0')))) {
            fVar37 = _DAT_181b2beb0 - SUB84(pplVar28[0x14],0);
            fVar39 = _DAT_181b2beb4 - (float)((ulonglong)pplVar28[0x14] >> 0x20);
            fVar37 = fVar39 * fVar39 + fVar37 * fVar37 +
                     (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15)) *
                     (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15));
            if (fVar37 < 0.0) {
LAB_180084d47:
              uVar42 = func_0x0001801cb525();
              auVar47._8_4_ = (int)extraout_XMM0_Qb;
              auVar47._0_8_ = uVar42;
              auVar47._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
            }
            else {
              auVar47 = ZEXT416((uint)SQRT(fVar37));
            }
            if ((auVar47._0_4_ < auVar48._0_4_) && (auVar47._0_4_ < fVar41)) {
              in_stack_fffffffffffffa48 =
                   (longlong *****)
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),iStack_578);
              recovered_180067e80(&fStackX_8,&DAT_181b2be70,pplVar28 + 0x14,iStack_574,
                                  in_stack_fffffffffffffa48);
              if ((fVar6 <= fStackX_8) && (fVar6 <= fStackX_c)) {
                pplVar22 = pplVar28 + 3;
                auVar48 = auVar47;
              }
            }
          }
          pplVar28 = (longlong **)*pplVar28;
        } while (pplVar28 != pplVar32);
        if (pplVar22 != (longlong **)0x0) {
          uVar42 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),iStack_578);
          iVar14 = iStack_574;
          iVar12 = iStack_578;
          recovered_180067e80(&fStackX_8,&DAT_181b2be70,pplVar22 + 0x11,iStack_574,uVar42);
          uVar50 = (undefined4)((ulonglong)uVar42 >> 0x20);
          if ((fVar6 <= fStackX_8) && (fVar6 <= fStackX_c)) {
            fStackX_10 = (float)iVar14 * fVar45;
            fStackX_14 = (float)iVar12 * fVar45;
            auStack_430._0_4_ = _DAT_181b2b488;
            auStack_430._4_4_ = uRam0000000181b2b48c;
            uStack_428 = uRam0000000181b2b490;
            uStack_424 = uRam0000000181b2b494;
            if (*(char *)((longlong)pplVar22 + 3) != '\0') {
              auStack_430._0_4_ = _DAT_181b2b568;
              auStack_430._4_4_ = _DAT_181b2b56c;
              uStack_428 = _DAT_181b2b570;
              uStack_424 = _DAT_181b2b574;
            }
            uVar15 = func_0x000180004f90(auStack_430);
            func_0x000180027b00(lStack_580,&fStackX_10,&fStackX_8,uVar15,CONCAT44(uVar50,fVar6));
          }
        }
      }
      if ((DAT_181b2b581 != '\0') && (DAT_181b2bc70 == '\0')) {
        recovered_18006fb50();
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180084f20 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * recovered_180084f20(float **param_1,float *param_2,int param_3,undefined8 param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fStack_18;
  float fStack_14;
  
  param_2[1] = 0.0;
  fStack_18 = (float)param_4;
  fStack_14 = (float)((ulonglong)param_4 >> 0x20);
  if (param_3 == 0) {
    pfVar4 = param_1[3];
    fVar5 = (**param_1 - fStack_18) - *param_1[1];
  }
  else {
    if (param_3 != 1) {
      pfVar4 = param_1[7];
      if (param_3 == 2) {
        pfVar3 = param_1[8];
        fVar5 = *param_1[2];
        *param_2 = *pfVar4 - fStack_18 * _DAT_181a031bc;
        fVar1 = *pfVar3;
        *pfVar3 = fStack_14 + _DAT_181a03270 + *pfVar3;
        param_2[1] = (fVar5 - fStack_14) - fVar1;
        return param_2;
      }
      if (param_3 != 3) {
        pfVar3 = param_1[2];
        *param_2 = *pfVar4;
        param_2[1] = *pfVar3;
        return param_2;
      }
      fVar5 = *param_1[9];
      *param_2 = *pfVar4 - fStack_18 * _DAT_181a031bc;
      pfVar4 = param_1[10];
      fVar1 = *param_1[2];
      fVar2 = *pfVar4;
      *pfVar4 = fStack_14 + _DAT_181a03270 + *pfVar4;
      param_2[1] = fVar5 + fVar1 + fVar2;
      return param_2;
    }
    pfVar4 = param_1[6];
    fVar5 = *param_1[4] + **param_1 + *param_1[5];
  }
  fVar1 = *pfVar4;
  pfVar3 = param_1[2];
  *param_2 = fVar5;
  fVar5 = *pfVar3;
  *pfVar4 = fStack_14 + _DAT_181a03270 + fVar1;
  param_2[1] = fVar1 + fVar5;
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x180085090 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180085090(longlong **param_1,longlong param_2,float *param_3,undefined8 param_4,
                        char *param_5)

{
  char *pcVar1;
  longlong lVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  
  pcVar5 = param_5;
  fVar4 = _DAT_181a0348c;
  fVar3 = _DAT_181a03230;
  if ((param_5 != (char *)0x0) && (*param_5 != '\0')) {
    if (param_2 == 0) {
      fVar13 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
    }
    else {
      fVar13 = *(float *)(param_2 + 0x14);
    }
    lVar9 = -1;
    fVar10 = fVar4;
    fVar12 = _DAT_181a0348c;
    do {
      if ((fVar12 != 0.0) || (fVar10 != 0.0)) {
        param_5._0_4_ = fVar12 + *param_3;
        param_5._4_4_ = fVar10 + param_3[1];
        lVar2 = **param_1;
        lVar7 = -1;
        do {
          pcVar1 = pcVar5 + 1 + lVar7;
          lVar7 = lVar7 + 1;
        } while (*pcVar1 != '\0');
        if (pcVar5 != pcVar5 + lVar7) {
          lVar8 = param_2;
          if (param_2 == 0) {
            lVar8 = *(longlong *)(*(longlong *)(lVar2 + 0x38) + 8);
          }
          fVar11 = fVar13;
          if (fVar13 == 0.0) {
            fVar11 = *(float *)(*(longlong *)(lVar2 + 0x38) + 0x10);
          }
          if (*(longlong *)(*(longlong *)(lVar8 + 0x40) + 8) != *(longlong *)(lVar2 + 0x98)) {
            _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
          }
          uStack_a8 = *(undefined4 *)(lVar2 + 0x88);
          uStack_a4 = *(undefined4 *)(lVar2 + 0x8c);
          uStack_a0 = *(undefined4 *)(lVar2 + 0x90);
          uStack_9c = *(undefined4 *)(lVar2 + 0x94);
          func_0x000180030c90(lVar8,lVar2,fVar11,&param_5,0xc8000000,&uStack_a8,pcVar5,
                              pcVar5 + lVar7,0,0);
        }
      }
      fVar10 = fVar10 + fVar3;
    } while ((fVar10 <= fVar3) || (fVar12 = fVar12 + fVar3, fVar10 = fVar4, fVar12 <= fVar3));
    lVar7 = **param_1;
    uVar6 = func_0x000180004f90(param_4);
    if ((uVar6 & 0xff000000) != 0) {
      do {
        pcVar1 = pcVar5 + 1 + lVar9;
        lVar9 = lVar9 + 1;
      } while (*pcVar1 != '\0');
      if (pcVar5 != pcVar5 + lVar9) {
        if (param_2 == 0) {
          param_2 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
        }
        if (fVar13 == 0.0) {
          fVar13 = *(float *)(*(longlong *)(lVar7 + 0x38) + 0x10);
        }
        if (*(longlong *)(*(longlong *)(param_2 + 0x40) + 8) != *(longlong *)(lVar7 + 0x98)) {
          _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
        }
        uStack_a8 = *(undefined4 *)(lVar7 + 0x88);
        uStack_a4 = *(undefined4 *)(lVar7 + 0x8c);
        uStack_a0 = *(undefined4 *)(lVar7 + 0x90);
        uStack_9c = *(undefined4 *)(lVar7 + 0x94);
        func_0x000180030c90(param_2,lVar7,fVar13,param_3,uVar6,&uStack_a8,pcVar5,pcVar5 + lVar9,0,0)
        ;
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180085390 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180085390(int **param_1,float *param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float fVar6;
  float fStackX_10;
  float fStackX_14;
  float fStackX_20;
  float fStackX_24;
  
  if ((((*param_2 != 0.0) || (param_2[1] != 0.0)) || (param_2[2] != 0.0)) &&
     (((*param_3 != 0.0 || (param_3[1] != 0.0)) || (param_3[2] != 0.0)))) {
    iVar1 = *param_1[1];
    iVar5 = **param_1;
    recovered_180067e80(&fStackX_10,&DAT_181b2be70,param_2,iVar5,iVar1);
    recovered_180067e80(&fStackX_20,&DAT_181b2be70,param_3);
    fVar3 = fStackX_14;
    fVar2 = fStackX_10;
    if (((_DAT_181a03230 <= fStackX_10) && (_DAT_181a03230 <= fStackX_14)) &&
       ((_DAT_181a03230 <= fStackX_20 &&
        ((((_DAT_181a03230 <= fStackX_24 && (fStackX_10 <= (float)iVar5)) &&
          (fVar6 = (float)iVar1, fStackX_14 <= fVar6)) &&
         ((fStackX_20 <= (float)iVar5 && (fStackX_24 <= fVar6)))))))) {
      uVar4 = func_0x000180004f90(param_1[3]);
      fStackX_10 = fStackX_20;
      fStackX_14 = fStackX_24;
      fStackX_20 = fVar2;
      fStackX_24 = fVar3;
      func_0x000180027b00(*(undefined8 *)param_1[2],&fStackX_20,&fStackX_10,uVar4,_DAT_181a03240);
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180085590 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * recovered_180085590(void)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined *puVar5;
  longlong lVar6;
  longlong unaff_GS_OFFSET;
  
  if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8) +
               4) < _DAT_181b50980) && (func_0x000180127a18(&DAT_181b50980), _DAT_181b50980 == -1))
  {
    _DAT_181b50940 = 0;
    _DAT_181b50948 = 0;
    _DAT_181b50950 = 0;
    lVar3 = func_0x000180127a94(0x38);
    *(longlong *)lVar3 = lVar3;
    *(longlong *)(lVar3 + 8) = lVar3;
    _DAT_181b50958 = (longlong *)0x0;
    _DAT_181b50960 = ZEXT816(0);
    _DAT_181b50970 = 7;
    _DAT_181b50978 = 8;
    _DAT_181b50940 = 0x3f800000;
    _DAT_181b50948 = lVar3;
    plVar4 = (longlong *)func_0x000180127a94(0x80);
    lVar6 = _DAT_181b50968 - (longlong)_DAT_181b50958 >> 3;
    if (lVar6 != 0) {
      if ((0xfff < (ulonglong)(lVar6 * 8)) &&
         (0x1f < ((longlong)_DAT_181b50958 - *(longlong *)((longlong)_DAT_181b50958 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        puVar5 = (undefined *)(*pcVar2)();
        return puVar5;
      }
      func_0x000180127e40();
    }
    plVar1 = plVar4 + 0x10;
    _DAT_181b50968 = (longlong)plVar1;
    _DAT_181b50960 = plVar1;
    _DAT_181b50958 = plVar4;
    for (; plVar4 != plVar1; plVar4 = plVar4 + 1) {
      *plVar4 = lVar3;
    }
    func_0x000180127e28(&DAT_1801d0900);
    func_0x0001801279ac(&DAT_181b50980);
  }
  return &DAT_181b50940;
}



/* ===== ANALYSIS FUNCTION 0x180085710 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180085710(longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined *puVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong *plVar15;
  longlong lStackX_10;
  undefined auStack_2f8 [16];
  undefined auStack_2e8 [16];
  undefined auStack_2d8 [16];
  undefined auStack_2c8 [16];
  undefined auStack_2b8 [16];
  undefined auStack_2a8 [16];
  undefined auStack_298 [16];
  undefined auStack_288 [16];
  undefined auStack_278 [16];
  undefined auStack_268 [16];
  undefined auStack_258 [16];
  undefined auStack_248 [16];
  undefined auStack_238 [528];
  
  plVar15 = (longlong *)&UNK_1802f5b80;
  uVar14 = 0;
  while( true ) {
    uVar8 = 0;
    uVar6 = recovered_180085590();
    auStack_2f8 = ZEXT816(0);
    auStack_2e8 = ZEXT816(0);
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (*(char *)(*plVar15 + lVar11) != '\0');
    recovered_180066cc0(auStack_2f8);
    puVar3 = (undefined *)auStack_2f8._0_8_;
    uVar4 = auStack_2e8._8_8_;
    puVar9 = auStack_2f8;
    if (0xf < (ulonglong)auStack_2e8._8_8_) {
      puVar9 = (undefined *)auStack_2f8._0_8_;
    }
    uVar13 = 0xcbf29ce484222325;
    if (auStack_2e8._0_8_ != 0) {
      do {
        uVar13 = (uVar13 ^ (byte)puVar9[uVar8]) * 0x100000001b3;
        uVar8 = uVar8 + 1;
      } while (uVar8 < (ulonglong)auStack_2e8._0_8_);
    }
    lVar11 = recovered_180085cb0(uVar6,auStack_258,auStack_2f8,uVar13);
    lVar11 = *(longlong *)(lVar11 + 8);
    if (0xf < uVar4) {
      puVar9 = puVar3;
      if ((0xfff < uVar4 + 1) &&
         (puVar9 = *(undefined **)(puVar3 + -8),
         (undefined *)0x1f < puVar3 + (-8 - (longlong)puVar9))) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40(puVar9);
    }
    if (lVar11 == 0) break;
LAB_1800859a9:
    uVar14 = uVar14 + 0x18;
    plVar15 = plVar15 + 3;
    if (0x35f < uVar14) {
      return;
    }
  }
  auStack_2d8 = ZEXT816(0);
  auStack_2c8 = ZEXT816(0);
  auStack_2b8 = ZEXT816(0);
  auStack_2a8 = ZEXT816(0);
  auStack_298 = ZEXT816(0);
  auStack_288 = ZEXT816(0);
  auStack_278 = ZEXT816(0);
  auStack_268 = ZEXT816(0);
  MultiByteToWideChar(0xfde9,0,*plVar15,0xffffffff,auStack_2d8,0x40);
  puVar10 = (undefined8 *)0x181a2b180;
LAB_180085880:
  func_0x0001801ca899(auStack_238,0,0x208);
  func_0x000180085be0(auStack_238,&UNK_1819d8458,*puVar10,auStack_2d8);
  lVar11 = *plVar15;
  if (((param_1 == 0) || (lVar11 == 0)) || (iVar5 = GetFileAttributesW(auStack_238), iVar5 == -1))
  goto LAB_180085900;
  lStackX_10 = 0;
  iVar5 = D3DX11CreateShaderResourceViewFromFileW(param_1,auStack_238,0,0,&lStackX_10,0);
  lVar2 = lStackX_10;
  if ((iVar5 < 0) || (lStackX_10 == 0)) goto LAB_180085900;
  uVar6 = recovered_180085590();
  auStack_2f8 = ZEXT816(0);
  auStack_2e8 = ZEXT816(0);
  lVar12 = -1;
  do {
    lVar12 = lVar12 + 1;
  } while (*(char *)(lVar11 + lVar12) != '\0');
  recovered_180066cc0(auStack_2f8,lVar11);
  plVar7 = (longlong *)recovered_180085d80(uVar6,auStack_248,auStack_2f8);
  *(longlong *)(*plVar7 + 0x30) = lVar2;
  if (0xf < (ulonglong)auStack_2e8._8_8_) {
    if ((0xfff < auStack_2e8._8_8_ + 1) &&
       (0x1f < (auStack_2f8._0_8_ - *(longlong *)(auStack_2f8._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  goto LAB_1800859a9;
LAB_180085900:
  puVar10 = puVar10 + 1;
  if (puVar10 == (undefined8 *)0x181a2b190) goto LAB_1800859a9;
  goto LAB_180085880;
}



/* ===== ANALYSIS FUNCTION 0x180085a10 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool recovered_180085a10(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  undefined uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong lVar10;
  bool bVar11;
  longlong lStackX_8;
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined auStack_38 [16];
  
  if ((param_1 == 0) && (param_1 = _DAT_181b2f350, _DAT_181b2f350 == 0)) {
    bVar11 = false;
  }
  else {
    lVar6 = recovered_180085590();
    if (*(longlong *)(lVar6 + 0x10) == 0) {
      uVar9 = 0;
      do {
        lVar1 = *(longlong *)(&UNK_1802f5b80 + uVar9);
        if ((((param_1 != 0) && (lVar1 != 0)) && (*(longlong *)(&UNK_1802f5b88 + uVar9) != 0)) &&
           (*(ulonglong *)(&UNK_1802f5b90 + uVar9) != 0)) {
          lStackX_8 = 0;
          iVar5 = D3DX11CreateShaderResourceViewFromMemory
                            (param_1,*(longlong *)(&UNK_1802f5b88 + uVar9),
                             *(ulonglong *)(&UNK_1802f5b90 + uVar9) & 0xffffffff,0,0,&lStackX_8,0);
          lVar3 = lStackX_8;
          if ((-1 < iVar5) && (lStackX_8 != 0)) {
            uVar7 = recovered_180085590();
            auStack_48 = ZEXT816(0);
            auStack_38 = ZEXT816(0);
            lVar10 = -1;
            do {
              lVar10 = lVar10 + 1;
            } while (*(char *)(lVar1 + lVar10) != '\0');
            recovered_180066cc0(auStack_48,lVar1);
            plVar8 = (longlong *)recovered_180085d80(uVar7,auStack_58,auStack_48);
            *(longlong *)(*plVar8 + 0x30) = lVar3;
            if (0xf < (ulonglong)auStack_38._8_8_) {
              if (0xfff < auStack_38._8_8_ + 1) {
                if (0x1f < (auStack_48._0_8_ - *(longlong *)(auStack_48._0_8_ + -8)) - 8U) {
                  _invoke_watson(0,0,0,0,0);
                  pcVar2 = (code *)swi(3);
                  uVar4 = (*pcVar2)();
                  return (bool)uVar4;
                }
              }
              func_0x000180127e40();
            }
          }
        }
        uVar9 = uVar9 + 0x18;
      } while (uVar9 < 0x360);
      if (*(ulonglong *)(lVar6 + 0x10) < 0x24) {
        recovered_180085710(param_1);
      }
      bVar11 = *(longlong *)(lVar6 + 0x10) != 0;
    }
    else {
      bVar11 = true;
    }
  }
  return bVar11;
}



/* ===== ANALYSIS FUNCTION 0x180085cb0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong **
recovered_180085cb0(longlong param_1,longlong **param_2,undefined8 *param_3,ulonglong param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong **pplVar5;
  longlong **pplVar6;
  longlong **pplVar7;
  
  pplVar7 = (longlong **)
            ((*(ulonglong *)(param_1 + 0x30) & param_4) * 0x10 + *(longlong *)(param_1 + 0x18));
  pplVar6 = (longlong **)pplVar7[1];
  if (pplVar6 == *(longlong ***)(param_1 + 8)) {
    *param_2 = (longlong *)*(longlong ***)(param_1 + 8);
    param_2[1] = (longlong *)0x0;
    return param_2;
  }
  pplVar7 = (longlong **)*pplVar7;
  plVar1 = (longlong *)param_3[2];
  uVar2 = param_3[3];
  while( true ) {
    pplVar5 = pplVar6 + 2;
    if ((longlong *)0xf < pplVar6[5]) {
      pplVar5 = (longlong **)*pplVar5;
    }
    puVar4 = param_3;
    if (0xf < uVar2) {
      puVar4 = (undefined8 *)*param_3;
    }
    if ((plVar1 == pplVar6[4]) &&
       ((plVar1 == (longlong *)0x0 ||
        (iVar3 = func_0x0001801ca8a5(puVar4,pplVar5,plVar1), iVar3 == 0)))) break;
    if (pplVar6 == pplVar7) {
      *param_2 = (longlong *)pplVar6;
      param_2[1] = (longlong *)0x0;
      return param_2;
    }
    pplVar6 = (longlong **)pplVar6[1];
  }
  *param_2 = *pplVar6;
  param_2[1] = (longlong *)pplVar6;
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x180085d80 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * recovered_180085d80(float *param_1,longlong *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  float fVar15;
  float fVar16;
  undefined8 *puStack_38;
  longlong lStack_30;
  
  puVar8 = param_3;
  if (0xf < (ulonglong)param_3[3]) {
    puVar8 = (undefined8 *)*param_3;
  }
  uVar14 = 0xcbf29ce484222325;
  uVar9 = 0;
  if (param_3[2] != 0) {
    do {
      uVar14 = (uVar14 ^ *(byte *)((longlong)puVar8 + uVar9)) * 0x100000001b3;
      uVar9 = uVar9 + 1;
    } while (uVar9 < (ulonglong)param_3[2]);
  }
  recovered_180085cb0(param_1,&puStack_38,param_3,uVar14);
  if (lStack_30 != 0) {
    *param_2 = lStack_30;
    *(undefined *)(param_2 + 1) = 0;
    return param_2;
  }
  if (*(longlong *)(param_1 + 4) == 0x492492492492492) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar2 = (code *)swi(3);
    plVar7 = (longlong *)(*pcVar2)();
    return plVar7;
  }
  puVar8 = (undefined8 *)func_0x000180127a94(0x38);
  *(undefined (*) [16])(puVar8 + 2) = ZEXT816(0);
  puVar8[4] = 0;
  puVar8[5] = 0;
  uVar3 = *(undefined4 *)((longlong)param_3 + 4);
  uVar4 = *(undefined4 *)(param_3 + 1);
  uVar5 = *(undefined4 *)((longlong)param_3 + 0xc);
  *(undefined4 *)(puVar8 + 2) = *(undefined4 *)param_3;
  *(undefined4 *)((longlong)puVar8 + 0x14) = uVar3;
  *(undefined4 *)(puVar8 + 3) = uVar4;
  *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar5;
  uVar3 = *(undefined4 *)((longlong)param_3 + 0x14);
  uVar4 = *(undefined4 *)(param_3 + 3);
  uVar5 = *(undefined4 *)((longlong)param_3 + 0x1c);
  *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(param_3 + 2);
  *(undefined4 *)((longlong)puVar8 + 0x24) = uVar3;
  *(undefined4 *)(puVar8 + 5) = uVar4;
  *(undefined4 *)((longlong)puVar8 + 0x2c) = uVar5;
  param_3[2] = 0;
  param_3[3] = 0xf;
  *(undefined *)param_3 = 0;
  puVar8[6] = 0;
  uVar9 = *(ulonglong *)(param_1 + 0xe);
  uVar10 = *(longlong *)(param_1 + 4) + 1;
  if ((longlong)uVar10 < 0) {
    fVar15 = (float)(uVar10 >> 1 | (ulonglong)((uint)uVar10 & 1));
    fVar15 = fVar15 + fVar15;
  }
  else {
    fVar15 = (float)uVar10;
  }
  if ((longlong)uVar9 < 0) {
    fVar16 = (float)(uVar9 >> 1 | (ulonglong)((uint)uVar9 & 1));
    fVar16 = fVar16 + fVar16;
  }
  else {
    fVar16 = (float)uVar9;
  }
  if (*param_1 < fVar15 / fVar16) {
    fVar15 = (float)func_0x0001801cb4e3(fVar15 / *param_1);
    lVar11 = 0;
    if ((_DAT_181a03458 <= fVar15) && (fVar15 = fVar15 - _DAT_181a03458, fVar15 < _DAT_181a03458)) {
      lVar11 = -0x8000000000000000;
    }
    uVar10 = 8;
    if (8 < (ulonglong)((longlong)fVar15 + lVar11)) {
      uVar10 = (longlong)fVar15 + lVar11;
    }
    uVar13 = uVar9;
    if ((uVar9 < uVar10) && ((0x1ff < uVar9 || (uVar13 = uVar9 * 8, uVar9 * 8 < uVar10)))) {
      uVar13 = uVar10;
    }
    func_0x0001800860a0(param_1,uVar13);
    puVar12 = *(undefined8 **)
               (*(longlong *)(param_1 + 6) + 8 + (*(ulonglong *)(param_1 + 0xc) & uVar14) * 0x10);
    puStack_38 = *(undefined8 **)(param_1 + 2);
    if (puVar12 != *(undefined8 **)(param_1 + 2)) {
      puVar1 = *(undefined8 **)
                (*(longlong *)(param_1 + 6) + (*(ulonglong *)(param_1 + 0xc) & uVar14) * 0x10);
      lVar11 = puVar8[4];
      puStack_38 = puVar12;
      while( true ) {
        plVar7 = puStack_38 + 2;
        if (0xf < (ulonglong)puStack_38[5]) {
          plVar7 = (longlong *)*plVar7;
        }
        puVar12 = puVar8 + 2;
        if (0xf < (ulonglong)puVar8[5]) {
          puVar12 = (undefined8 *)puVar8[2];
        }
        if ((lVar11 == puStack_38[4]) &&
           ((lVar11 == 0 || (iVar6 = func_0x0001801ca8a5(puVar12,plVar7,lVar11), iVar6 == 0))))
        break;
        if (puStack_38 == puVar1) goto LAB_180085fe6;
        puStack_38 = (undefined8 *)puStack_38[1];
      }
      puStack_38 = (undefined8 *)*puStack_38;
    }
  }
LAB_180085fe6:
  puVar12 = (undefined8 *)puStack_38[1];
  *(longlong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + 1;
  *puVar8 = puStack_38;
  puVar8[1] = puVar12;
  *puVar12 = puVar8;
  puStack_38[1] = puVar8;
  uVar14 = *(ulonglong *)(param_1 + 0xc) & uVar14;
  lVar11 = *(longlong *)(param_1 + 6);
  puVar1 = *(undefined8 **)(lVar11 + uVar14 * 0x10);
  if (puVar1 == *(undefined8 **)(param_1 + 2)) {
    *(undefined8 **)(lVar11 + uVar14 * 0x10) = puVar8;
  }
  else {
    if (puVar1 == puStack_38) {
      *(undefined8 **)(lVar11 + uVar14 * 0x10) = puVar8;
      goto LAB_180086030;
    }
    if (*(undefined8 **)(lVar11 + 8 + uVar14 * 0x10) != puVar12) goto LAB_180086030;
  }
  *(undefined8 **)(lVar11 + 8 + uVar14 * 0x10) = puVar8;
LAB_180086030:
  *param_2 = (longlong)puVar8;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}



/* ===== ANALYSIS FUNCTION 0x1800898f0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_1800898f0(undefined (*param_1) [16],undefined4 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 ****ppppuVar9;
  undefined8 ****ppppuVar10;
  ulonglong uVar11;
  longlong lVar12;
  char *pcVar13;
  undefined auStackX_18 [8];
  char acStack_3c [4];
  undefined8 ****appppuStack_38 [2];
  longlong lStack_28;
  ulonglong uStack_20;
  
  ppppuVar9 = (undefined8 ****)0x0;
  if (DAT_181b2f6db == '\0') {
    func_0x000180086370();
    func_0x000180088770();
    func_0x000180089280();
    DAT_181b2f6db = '\x01';
  }
  uVar6 = func_0x000180089860(param_2);
  plVar7 = (longlong *)
           (((((ulonglong)(uVar6 >> 0x10) & 0xff ^
              ((ulonglong)(uVar6 >> 8 & 0xff) ^
              ((ulonglong)uVar6 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3) * 0x100000001b3) *
              0x100000001b3 ^ (ulonglong)(uVar6 >> 0x18)) * 0x100000001b3 & _DAT_181b30370) * 0x10 +
           _DAT_181b30358);
  lVar12 = plVar7[1];
  if (lVar12 == _DAT_181b30348) {
LAB_1800899c1:
    lVar12 = 0;
  }
  else {
    uVar1 = *(uint *)(lVar12 + 0x10);
    while (uVar6 != uVar1) {
      if (lVar12 == *plVar7) goto LAB_1800899c1;
      lVar12 = *(longlong *)(lVar12 + 8);
      uVar1 = *(uint *)(lVar12 + 0x10);
    }
  }
  lVar8 = _DAT_181b30348;
  if (lVar12 != 0) {
    lVar8 = lVar12;
  }
  if (lVar8 == _DAT_181b30348) {
    pcVar13 = acStack_3c + 1;
    uVar11 = (ulonglong)uVar6;
    do {
      pcVar13 = pcVar13 + -1;
      uVar2 = uVar11 / 10;
      *pcVar13 = (char)uVar11 + (char)uVar2 * -10 + '0';
      uVar11 = uVar2;
    } while ((int)uVar2 != 0);
    recovered_180078780(appppuStack_38,pcVar13,acStack_3c + 1,auStackX_18);
    if (uStack_20 - lStack_28 < 5) {
      ppppuVar9 = (undefined8 ****)
                  recovered_1800678e0(appppuStack_38,5,lStack_28,0,&UNK_1819d8940,5);
    }
    else {
      ppppuVar10 = appppuStack_38;
      if (0xf < uStack_20) {
        ppppuVar10 = appppuStack_38[0];
      }
      if ((&UNK_1819d8944 < ppppuVar10) ||
         ((undefined *)(lStack_28 + (longlong)ppppuVar10) < &UNK_1819d8940)) {
        ppppuVar9 = (undefined8 ****)0x5;
      }
      else if (&UNK_1819d8940 < ppppuVar10) {
        ppppuVar9 = ppppuVar10 + -0x3033b128;
      }
      lVar12 = lStack_28 + 1;
      lStack_28 = lStack_28 + 5;
      func_0x0001801ca893((undefined *)((longlong)ppppuVar10 + 5),ppppuVar10,lVar12);
      func_0x0001801ca88d(ppppuVar10,&UNK_1819d8940,ppppuVar9);
      func_0x0001801ca88d((undefined *)((longlong)ppppuVar10 + (longlong)ppppuVar9),
                          &UNK_1819d8945 + (longlong)ppppuVar9,5 - (longlong)ppppuVar9);
      ppppuVar9 = appppuStack_38;
    }
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    uVar3 = *(undefined4 *)((longlong)ppppuVar9 + 4);
    uVar4 = *(undefined4 *)(ppppuVar9 + 1);
    uVar5 = *(undefined4 *)((longlong)ppppuVar9 + 0xc);
    *(undefined4 *)*param_1 = *(undefined4 *)ppppuVar9;
    *(undefined4 *)(*param_1 + 4) = uVar3;
    *(undefined4 *)(*param_1 + 8) = uVar4;
    *(undefined4 *)(*param_1 + 0xc) = uVar5;
    uVar3 = *(undefined4 *)((longlong)ppppuVar9 + 0x14);
    uVar4 = *(undefined4 *)(ppppuVar9 + 3);
    uVar5 = *(undefined4 *)((longlong)ppppuVar9 + 0x1c);
    *(undefined4 *)param_1[1] = *(undefined4 *)(ppppuVar9 + 2);
    *(undefined4 *)(param_1[1] + 4) = uVar3;
    *(undefined4 *)(param_1[1] + 8) = uVar4;
    *(undefined4 *)(param_1[1] + 0xc) = uVar5;
    ppppuVar9[2] = (undefined8 ***)0x0;
    ppppuVar9[3] = (undefined8 ***)0xf;
    *(undefined *)ppppuVar9 = 0;
    recovered_180066e40(appppuStack_38);
  }
  else {
    recovered_180080190(param_1,lVar8 + 0x18);
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180089b40 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 * recovered_180089b40(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_0x000180089860(param_2);
  if (((((iVar1 == 0x135) || (iVar1 == 0x4b5)) || (iVar1 == 0x15e1)) ||
      ((iVar1 - 0x46U < 0x3a &&
       ((0x200000000001c01U >> ((ulonglong)(iVar1 - 0x46U) & 0x3f) & 1) != 0)))) || (iVar1 == 0xb4))
  {
    *param_1 = 0x3f800000;
    param_1[1] = 0x3f59999a;
    param_1[2] = 0x3e4ccccd;
    param_1[3] = 0x3f800000;
    return param_1;
  }
  if (((iVar1 != 0x12f) && (iVar1 != 0x132)) &&
     ((iVar1 != 0x193 &&
      (((0x28 < iVar1 - 0x1f7U ||
        ((0x10000100401U >> ((ulonglong)(iVar1 - 0x1f7U) & 0x3f) & 1) == 0)) && (iVar1 != 0x2bf)))))
     ) {
    if (((iVar1 != 0x12e) && (iVar1 != 0x131)) &&
       (((iVar1 != 0x192 &&
         ((0x28 < iVar1 - 0x1f6U ||
          ((0x10000100401U >> ((ulonglong)(iVar1 - 0x1f6U) & 0x3f) & 1) == 0)))) && (iVar1 != 0x2be)
        ))) {
      if ((((iVar1 != 0x12d) && (iVar1 != 0x130)) && (iVar1 != 0x191)) &&
         (((0x28 < iVar1 - 0x1f5U ||
           ((0x10000100401U >> ((ulonglong)(iVar1 - 0x1f5U) & 0x3f) & 1) == 0)) &&
          ((iVar1 != 0x2bd && (iVar1 != 0x66)))))) {
        if ((iVar1 - 0xc9U < 7) && ((0x5dU >> (iVar1 - 0xc9U & 0x1f) & 1) != 0)) {
          *param_1 = 0x3f4ccccd;
          param_1[1] = 0x3f4ccccd;
          param_1[2] = 0x3f4ccccd;
          param_1[3] = 0x3f800000;
          return param_1;
        }
        *param_1 = 0x3f733333;
        param_1[1] = 0x3f733333;
        param_1[2] = 0x3f733333;
        param_1[3] = 0x3f800000;
        return param_1;
      }
      *param_1 = 0x3eb851ec;
      param_1[1] = 0x3f666666;
      param_1[2] = 0x3eeb851f;
      param_1[3] = 0x3f800000;
      return param_1;
    }
    *param_1 = 0x3e3851ec;
    param_1[1] = 0x3f266666;
    param_1[2] = 0x3f70a3d7;
    param_1[3] = 0x3f800000;
    return param_1;
  }
  *param_1 = 0x3f4f5c29;
  param_1[1] = 0x3ec28f5c;
  param_1[2] = 0x3f70a3d7;
  param_1[3] = 0x3f800000;
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18008bca0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool recovered_18008bca0(uint param_1,uint *param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint auStackX_8 [2];
  uint auStackX_10 [2];
  uint auStackX_18 [2];
  int aiStackX_20 [2];
  int aiStack_68 [2];
  undefined8 uStack_60;
  undefined8 auStack_58 [3];
  
  uVar9 = (ulonglong)param_1;
  *param_2 = 0;
  auStackX_18[0] = 0;
  cVar2 = recovered_180067cc0(uVar9 + 0xdc,&uStack_60);
  if ((((cVar2 != '\0') &&
       (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_18,4), iVar3 == 0)) &&
      (auStackX_18[0] != 0)) ||
     (((cVar2 = recovered_180067cc0(uVar9 + 0xc4,&uStack_60), cVar2 != '\0' &&
       (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_18,4), iVar3 == 0)) &&
      (auStackX_18[0] != 0)))) {
    aiStackX_20[0] = 0;
    aiStack_68[0] = 0;
    cVar2 = recovered_180067cc0(auStackX_18[0] + 8,&uStack_60);
    if (((cVar2 != '\0') &&
        (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,aiStackX_20,4), iVar3 == 0)) &&
       ((aiStackX_20[0] != 0 &&
        (((cVar2 = recovered_180067cc0(auStackX_18[0] + 0xc,&uStack_60), cVar2 != '\0' &&
          (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,aiStack_68,4), iVar3 == 0)) &&
         (0 < aiStack_68[0])))))) {
      aiStackX_20[0] = aiStackX_20[0] + 0x10;
      auStackX_10[0] = 0;
      cVar2 = recovered_180067cc0(aiStackX_20[0],&uStack_60);
      if (((cVar2 != '\0') &&
          (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_10,4), iVar3 == 0)) &&
         (uVar7 = (ulonglong)auStackX_10[0], auStackX_10[0] != 0)) {
        plVar8 = (longlong *)&UNK_1819d89a0;
        do {
          lVar1 = *plVar8;
          if ((int)uVar7 == 0) {
LAB_18008beb0:
            *param_2 = 0;
          }
          else {
            auStackX_8[0] = auStackX_8[0] & 0xffff0000;
            cVar2 = recovered_180067cc0(uVar7 + lVar1,&uStack_60);
            if ((cVar2 == '\0') ||
               (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_8,2), iVar3 != 0)) {
LAB_18008bead:
              uVar7 = (ulonglong)auStackX_10[0];
              goto LAB_18008beb0;
            }
            if ((short)auStackX_8[0] == 0) goto LAB_18008bead;
            iVar3 = (short)auStackX_8[0] + 25000;
            if (-1 < (short)auStackX_8[0]) {
              iVar3 = (int)(short)auStackX_8[0];
            }
            uVar4 = func_0x000180089860(iVar3);
            *param_2 = uVar4;
            if (uVar4 != 0) goto LAB_18008c0b5;
            uVar7 = (ulonglong)auStackX_10[0];
          }
          if ((int)uVar7 == 0) {
LAB_18008bf97:
            *param_2 = 0;
          }
          else {
            auStackX_8[0] = 0;
            cVar2 = recovered_180067cc0(uVar7 + lVar1,auStack_58);
            if (((cVar2 == '\0') ||
                (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_58[0],auStackX_8,4), iVar3 != 0))
               || (auStackX_8[0] == 0)) {
              uVar7 = (ulonglong)auStackX_10[0];
              goto LAB_18008bf97;
            }
            uVar4 = auStackX_8[0] + 25000;
            if (-1 < (int)auStackX_8[0]) {
              uVar4 = auStackX_8[0];
            }
            if ((int)uVar4 < 0x10000) {
              if ((int)uVar4 < 20000) goto LAB_18008bf83;
              if ((int)uVar4 < 21000) {
                uVar6 = uVar4 - 20000;
joined_r0x00018008bf81:
                if ((int)uVar6 < 1) goto LAB_18008bf83;
              }
              else {
                if (21999 < (int)uVar4) goto LAB_18008bf83;
                uVar6 = uVar4 - 21000;
                if (uVar6 == 1) {
                  uVar6 = 0x5209;
                }
                else if (uVar6 == 2) {
                  uVar6 = 0x520a;
                }
                else if (uVar6 == 6) {
                  uVar6 = 0x520e;
                }
                else {
                  if (uVar6 != 0x14) goto joined_r0x00018008bf81;
                  uVar6 = 1;
                }
              }
            }
            else {
              uVar6 = uVar4 & 0xffff;
              if (uVar6 - 1 < 499) goto LAB_18008bf85;
LAB_18008bf83:
              uVar6 = uVar4;
            }
LAB_18008bf85:
            *param_2 = uVar6;
            if (uVar6 != 0) goto LAB_18008c0b5;
            uVar7 = (ulonglong)auStackX_10[0];
          }
          plVar8 = plVar8 + 1;
        } while (plVar8 != (longlong *)&UNK_1819d89e0);
        plVar8 = (longlong *)&UNK_1819d8948;
        do {
          lVar1 = *plVar8;
          if (param_1 == 0) {
LAB_18008c025:
            *param_2 = 0;
          }
          else {
            auStackX_8[0] = auStackX_8[0] & 0xffff0000;
            cVar2 = recovered_180067cc0(uVar9 + lVar1,auStack_58);
            if ((cVar2 == '\0') ||
               (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_58[0],auStackX_8,2), iVar3 != 0))
            goto LAB_18008c025;
            if ((short)auStackX_8[0] == 0) goto LAB_18008c025;
            iVar3 = (short)auStackX_8[0] + 25000;
            if (-1 < (short)auStackX_8[0]) {
              iVar3 = (int)(short)auStackX_8[0];
            }
            uVar4 = func_0x000180089860(iVar3);
            *param_2 = uVar4;
            if (uVar4 != 0) goto LAB_18008c0b5;
          }
          uVar4 = func_0x00018008bb30(uVar9,lVar1,0);
          *param_2 = uVar4;
          if (uVar4 != 0) goto LAB_18008c0b5;
          plVar8 = plVar8 + 1;
        } while (plVar8 != (longlong *)&UNK_1819d8978);
        uVar4 = recovered_180069360((ulonglong)auStackX_10[0] + 0x434);
        if (uVar4 != 0) {
          uVar5 = recovered_180069360((ulonglong)uVar4 + 0x494);
          uVar6 = func_0x000180089860(uVar5);
          *param_2 = uVar6;
          if ((uVar6 == 0) && (uVar4 = recovered_180069360((ulonglong)uVar4 + 0x58), uVar4 != 0)) {
            plVar8 = (longlong *)&UNK_1819d8978;
            do {
              uVar5 = recovered_180069360(*plVar8 + (ulonglong)uVar4);
              uVar6 = func_0x000180089860(uVar5);
              *param_2 = uVar6;
              if (uVar6 != 0) break;
              plVar8 = plVar8 + 1;
            } while (plVar8 != (longlong *)&UNK_1819d8998);
          }
        }
LAB_18008c0b5:
        return *param_2 != 0;
      }
    }
  }
  return false;
}



/* ===== ANALYSIS FUNCTION 0x18008c0f0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18008c0f0(uint param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined4 uVar6;
  undefined auVar7 [16];
  undefined auVar8 [16];
  undefined auVar9 [16];
  undefined auVar10 [16];
  float fVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char cVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  int *piVar21;
  undefined (*pauVar22) [16];
  undefined8 *puVar23;
  int *piVar24;
  undefined4 *puVar25;
  int iVar26;
  undefined8 *puVar27;
  undefined8 *puVar28;
  longlong lVar29;
  longlong lVar30;
  int iVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  int iStackX_18;
  undefined4 uStackX_1c;
  int aiStackX_20 [2];
  int iStack_218;
  int iStack_214;
  undefined8 uStack_210;
  float fStack_208;
  int iStack_200;
  uint uStack_1fc;
  int aiStack_1f8 [2];
  undefined auStack_1f0 [16];
  int *piStack_1e0;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  int iStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  int iStack_1bc;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  int iStack_178;
  undefined8 uStack_174;
  float fStack_16c;
  undefined auStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  float fStack_148;
  int iStack_140;
  undefined8 uStack_13c;
  float fStack_134;
  undefined auStack_130 [4];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  float fStack_110;
  undefined auStack_f8 [192];
  
  lVar30 = _DAT_181b2bde0;
  if ((DAT_181b2bdd0 == '\0') || (param_1 == 0)) {
    lVar29 = _DAT_181b2bdd8;
    if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
      do {
        recovered_180066e40(lVar29 + 0x10);
        lVar29 = lVar29 + 0x38;
      } while (lVar29 != lVar30);
      _DAT_181b2bde0 = _DAT_181b2bdd8;
    }
  }
  else {
    auStack_1f0 = ZEXT816(0);
    iVar31 = 0;
    piStack_1e0 = (int *)0x0;
    puVar20 = (undefined4 *)func_0x000180024110(0x1c00);
    puVar28 = (undefined8 *)auStack_1f0._8_8_;
    if (auStack_1f0._0_8_ != auStack_1f0._8_8_) {
      puVar23 = (undefined8 *)(puVar20 + 10);
      puVar25 = puVar20;
      puVar27 = (undefined8 *)(auStack_1f0._0_8_ + 0x28);
      do {
        *puVar25 = *(undefined4 *)(puVar27 + -5);
        *(undefined8 *)((longlong)puVar23 + -0x24) = *(undefined8 *)((longlong)puVar27 + -0x24);
        *(undefined4 *)((longlong)puVar23 + -0x1c) = *(undefined4 *)((longlong)puVar27 + -0x1c);
        *(undefined (*) [16])(puVar23 + -3) = ZEXT816(0);
        puVar23[-1] = 0;
        *puVar23 = 0;
        uVar6 = *(undefined4 *)((longlong)puVar27 + -0x14);
        uVar38 = *(undefined4 *)(puVar27 + -2);
        uVar39 = *(undefined4 *)((longlong)puVar27 + -0xc);
        *(undefined4 *)(puVar23 + -3) = *(undefined4 *)(puVar27 + -3);
        *(undefined4 *)((longlong)puVar23 + -0x14) = uVar6;
        *(undefined4 *)(puVar23 + -2) = uVar38;
        *(undefined4 *)((longlong)puVar23 + -0xc) = uVar39;
        uVar6 = *(undefined4 *)((longlong)puVar27 + -4);
        uVar38 = *(undefined4 *)puVar27;
        uVar39 = *(undefined4 *)((longlong)puVar27 + 4);
        *(undefined4 *)(puVar23 + -1) = *(undefined4 *)(puVar27 + -1);
        *(undefined4 *)((longlong)puVar23 + -4) = uVar6;
        *(undefined4 *)puVar23 = uVar38;
        *(undefined4 *)((longlong)puVar23 + 4) = uVar39;
        puVar27[-1] = 0;
        *puVar27 = 0xf;
        *(undefined *)(puVar27 + -3) = 0;
        *(undefined4 *)(puVar23 + 1) = *(undefined4 *)(puVar27 + 1);
        puVar25 = puVar25 + 0xe;
        puVar23 = puVar23 + 7;
        puVar1 = puVar27 + 2;
        puVar27 = puVar27 + 7;
      } while (puVar1 != (undefined8 *)auStack_1f0._8_8_);
    }
    if ((undefined8 *)auStack_1f0._0_8_ != (undefined8 *)0x0) {
      puVar23 = (undefined8 *)auStack_1f0._0_8_;
      if (auStack_1f0._0_8_ != auStack_1f0._8_8_) {
        do {
          recovered_180066e40(puVar23 + 2);
          puVar23 = puVar23 + 7;
        } while (puVar23 != puVar28);
      }
      puVar28 = (undefined8 *)auStack_1f0._0_8_;
      if ((0xfff < (ulonglong)((((longlong)piStack_1e0 - auStack_1f0._0_8_) / 0x38) * 0x38)) &&
         (puVar28 = *(undefined8 **)(auStack_1f0._0_8_ + -8),
         0x1f < (ulonglong)(auStack_1f0._0_8_ + (-8 - (longlong)puVar28)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      func_0x000180127e40(puVar28);
    }
    auStack_1f0._8_8_ = puVar20;
    auStack_1f0._0_8_ = puVar20;
    piStack_1e0 = puVar20 + 0x700;
    iStack_1bc = 500;
    iStack_1c0 = 0x14;
    piVar24 = &iStack_1c0;
    if (0x13 < _DAT_181b2bdd4) {
      piVar24 = (int *)&DAT_181b2bdd4;
    }
    piVar21 = &iStack_1bc;
    if (_DAT_181b2bdd4 < 0x1f5) {
      piVar21 = piVar24;
    }
    iVar2 = *piVar21;
    iStack_1c8 = 0;
    iStack_1c4 = 0;
    cVar16 = recovered_180067cc0((ulonglong)param_1 + 0x60,&iStackX_18);
    if (cVar16 != '\0') {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_1c8,4);
    }
    cVar16 = recovered_180067cc0((ulonglong)param_1 + 100,&iStackX_18);
    if (cVar16 != '\0') {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_1c4,4);
    }
    lVar30 = _DAT_181b2bde0;
    iVar15 = _UNK_181a0353c;
    iVar14 = _UNK_181a03538;
    iVar13 = _UNK_181a03534;
    iVar12 = _DAT_181a03530;
    fVar11 = _DAT_181a0313c;
    if ((iStack_1c8 == 0) && (iStack_1c4 == 0)) {
      lVar29 = _DAT_181b2bdd8;
      if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
        do {
          recovered_180066e40(lVar29 + 0x10);
          lVar29 = lVar29 + 0x38;
        } while (lVar29 != lVar30);
        _DAT_181b2bde0 = _DAT_181b2bdd8;
      }
    }
    else {
      if (iStack_1c8 != 0) {
        iStack_200 = 0;
        cVar16 = recovered_180067cc0(iStack_1c8 + 0xc,&iStackX_18);
        if (((cVar16 != '\0') &&
            (iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_200,4
                                       ), iVar17 == 0)) && (iStack_200 != 0)) {
          iStack_218 = 0;
          cVar16 = recovered_180067cc0(iStack_200 + 0x10,&iStackX_18);
          if (((cVar16 != '\0') &&
              (iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_218
                                          ,4), iVar17 == 0)) && (iStack_218 - 1U < 200)) {
            iStack_214 = 0;
            cVar16 = recovered_180067cc0(iStack_200 + 0xc,&iStackX_18);
            if (((cVar16 != '\0') &&
                (iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),
                                            &iStack_214,4), iVar17 == 0)) &&
               ((iStack_214 != 0 &&
                (iStack_214 = iStack_214 + 0x10, iVar17 = iVar31, 0 < iStack_218)))) {
              do {
                if (0x1c1 < (ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                break;
                iVar26 = iVar17 * 0x10 + iStack_214;
                iStack_1d8 = 0;
                cVar16 = recovered_180067cc0(iVar26,&uStack_1b8);
                if (((cVar16 != '\0') &&
                    (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b8,&iStack_1d8,4),
                    iVar18 == 0)) && (-1 < iStack_1d8)) {
                  iStack_1d4 = 0;
                  cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_1b0);
                  if (((cVar16 != '\0') &&
                      (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b0,&iStack_1d4,4),
                      iVar26 = iStack_1d4, iVar18 == 0)) && (iStack_1d4 != 0)) {
                    if ((ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38) <
                        0x1c2) {
                      iStackX_18 = 0;
                      cVar16 = recovered_180067cc0(iStack_1d4 + 0x10,&uStack_1a8);
                      if (((cVar16 != '\0') &&
                          (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a8,&iStackX_18,4),
                          iVar18 == 0)) && (iStackX_18 - 1U < 800)) {
                        aiStackX_20[0] = 0;
                        cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_1a0);
                        if ((((cVar16 != '\0') &&
                             (iVar26 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a0,aiStackX_20,4),
                             iVar26 == 0)) && (aiStackX_20[0] != 0)) &&
                           (aiStackX_20[0] = aiStackX_20[0] + 0x10, iVar26 = iVar31, 0 < iStackX_18)
                           ) {
                          do {
                            if (0x1c1 < (ulonglong)
                                        ((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                            break;
                            iVar18 = iVar26 * 0x10 + aiStackX_20[0];
                            iStack_1d0 = 0;
                            cVar16 = recovered_180067cc0(iVar18,&uStack_198);
                            if (((cVar16 != '\0') &&
                                (iVar19 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_198,&iStack_1d0,4)
                                , iVar19 == 0)) && (-1 < iStack_1d0)) {
                              uStack_1fc = 0;
                              cVar16 = recovered_180067cc0(iVar18 + 0xc,&uStack_190);
                              if (((cVar16 != '\0') &&
                                  (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_190,&uStack_1fc,
                                                              4), iVar18 == 0)) && (uStack_1fc != 0)
                                 ) {
                                iStack_1cc = 0;
                                cVar16 = recovered_18008bca0(uStack_1fc,&iStack_1cc);
                                if (cVar16 != '\0') {
                                  uStack_210 = 0;
                                  fStack_208 = 0.0;
                                  aiStack_1f8[0] = 0;
                                  cVar16 = recovered_180067cc0((ulonglong)uStack_1fc + 0x3c,
                                                               &uStack_188);
                                  if ((((cVar16 != '\0') &&
                                       (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_188,
                                                                   aiStack_1f8,4), iVar18 == 0)) &&
                                      (aiStack_1f8[0] != 0)) &&
                                     (((cVar16 = recovered_18006bd40(aiStack_1f8[0],&uStack_210),
                                       cVar16 != '\0' &&
                                       (((fVar34 = (float)uStack_210, (float)uStack_210 != 0.0 ||
                                         (uStack_210._4_4_ != 0.0)) || (fStack_208 != 0.0)))) ||
                                      (((cVar16 = recovered_180067cc0(aiStack_1f8[0] + 0x3c,
                                                                      &uStack_180), cVar16 != '\0'
                                        && (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_180,
                                                                       &uStack_210,0xc), iVar18 == 0
                                           )) && ((fVar34 = (float)uStack_210,
                                                  (float)uStack_210 != 0.0 ||
                                                  ((uStack_210._4_4_ != 0.0 || (fStack_208 != 0.0)))
                                                  ))))))) {
                                    fVar32 = (float)*param_2 - fVar34;
                                    fVar33 = (float)((ulonglong)*param_2 >> 0x20) - uStack_210._4_4_
                                    ;
                                    fVar32 = fVar33 * fVar33 + fVar32 * fVar32 +
                                             (*(float *)(param_2 + 1) - fStack_208) *
                                             (*(float *)(param_2 + 1) - fStack_208);
                                    if (fVar32 < 0.0) {
                                      fVar32 = (float)func_0x0001801cb525(fVar32);
                                    }
                                    else {
                                      fVar32 = SQRT(fVar32);
                                    }
                                    iVar18 = iStack_1cc;
                                    fVar33 = fStack_208;
                                    if ((fVar32 <= (float)iVar2) && (fVar11 <= fVar32)) {
                                      iStack_158 = iVar12;
                                      iStack_154 = iVar13;
                                      iStack_150 = iVar14;
                                      iStack_14c = iVar15;
                                      stack0xfffffffffffffe99 = SUB1615(ZEXT816(0),1);
                                      auVar7[15] = 0;
                                      auVar7._0_15_ = stack0xfffffffffffffe99;
                                      _auStack_168 = auVar7 << 8;
                                      iStack_178 = iStack_1cc;
                                      uVar6 = uStack_210._4_4_;
                                      uStack_174 = CONCAT44(uStack_210._4_4_,fVar34);
                                      fStack_16c = fStack_208;
                                      fStack_148 = fVar32;
                                      pauVar22 = (undefined (*) [16])
                                                 recovered_1800898f0(auStack_f8,iStack_1cc);
                                      if ((undefined (*) [16])auStack_168 == pauVar22) {
                                        uVar38 = auStack_168;
                                        uVar39 = uStack_164;
                                        uVar40 = uStack_160;
                                        uVar41 = uStack_15c;
                                        iVar19 = iVar12;
                                        iVar35 = iVar13;
                                        iVar36 = iVar14;
                                        iVar37 = iVar15;
                                      }
                                      else {
                                        uVar38 = *(undefined4 *)*pauVar22;
                                        uVar39 = *(undefined4 *)(*pauVar22 + 4);
                                        uVar40 = *(undefined4 *)(*pauVar22 + 8);
                                        uVar41 = *(undefined4 *)(*pauVar22 + 0xc);
                                        _auStack_168 = *pauVar22;
                                        iStack_158 = *(int *)pauVar22[1];
                                        iStack_154 = *(int *)(pauVar22[1] + 4);
                                        iStack_150 = *(int *)(pauVar22[1] + 8);
                                        iStack_14c = *(int *)(pauVar22[1] + 0xc);
                                        *(undefined8 *)pauVar22[1] = 0;
                                        *(undefined8 *)(pauVar22[1] + 8) = 0xf;
                                        (*pauVar22)[0] = 0;
                                        iVar19 = iStack_158;
                                        iVar35 = iStack_154;
                                        iVar36 = iStack_150;
                                        iVar37 = iStack_14c;
                                      }
                                      recovered_180066e40(auStack_f8);
                                      if ((int *)auStack_1f0._8_8_ == piStack_1e0) {
                                        recovered_18008d1e0(auStack_1f0,auStack_1f0._8_8_,
                                                            &iStack_178);
                                      }
                                      else {
                                        *(int *)auStack_1f0._8_8_ = iVar18;
                                        uStack_174 = CONCAT44(uVar6,fVar34);
                                        *(ulonglong *)(auStack_1f0._8_8_ + 4) =
                                             CONCAT44(uVar6,fVar34);
                                        *(float *)(auStack_1f0._8_8_ + 0xc) = fVar33;
                                        auVar4._4_4_ = uVar39;
                                        auVar4._0_4_ = uVar38;
                                        auVar4._8_4_ = uVar40;
                                        auVar4._12_4_ = uVar41;
                                        *(undefined (*) [16])(auStack_1f0._8_8_ + 0x10) = auVar4;
                                        *(int *)(auStack_1f0._8_8_ + 0x20) = iVar19;
                                        *(int *)(auStack_1f0._8_8_ + 0x24) = iVar35;
                                        *(int *)(auStack_1f0._8_8_ + 0x28) = iVar36;
                                        *(int *)(auStack_1f0._8_8_ + 0x2c) = iVar37;
                                        iStack_158 = iVar12;
                                        iStack_154 = iVar13;
                                        iStack_150 = iVar14;
                                        iStack_14c = iVar15;
                                        auVar8[15] = 0;
                                        auVar8._0_15_ = stack0xfffffffffffffe99;
                                        _auStack_168 = auVar8 << 8;
                                        *(float *)(auStack_1f0._8_8_ + 0x30) = fVar32;
                                        auStack_1f0._8_8_ = (int *)(auStack_1f0._8_8_ + 0x38);
                                      }
                                      recovered_180066e40(auStack_168);
                                    }
                                  }
                                }
                              }
                            }
                            iVar26 = iVar26 + 1;
                          } while (iVar26 < iStackX_18);
                        }
                      }
                    }
                  }
                }
                iVar17 = iVar17 + 1;
              } while (iVar17 < iStack_218);
            }
          }
        }
      }
      if ((iStack_1c4 != 0) && (iStack_1c4 != iStack_1c8)) {
        aiStack_1f8[0] = 0;
        cVar16 = recovered_180067cc0(iStack_1c4 + 0xc,&iStackX_18);
        if ((cVar16 != '\0') &&
           ((iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),aiStack_1f8,4
                                       ), iVar17 == 0 && (aiStack_1f8[0] != 0)))) {
          iStack_214 = 0;
          cVar16 = recovered_180067cc0(aiStack_1f8[0] + 0x10,&iStackX_18);
          if ((cVar16 != '\0') &&
             ((iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_214
                                          ,4), iVar17 == 0 && (iStack_214 - 1U < 200)))) {
            iStack_218 = 0;
            cVar16 = recovered_180067cc0(aiStack_1f8[0] + 0xc,&iStackX_18);
            if ((cVar16 != '\0') &&
               (((iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),
                                             &iStack_218,4), iVar17 == 0 && (iStack_218 != 0)) &&
                (iStack_218 = iStack_218 + 0x10, iVar17 = iVar31, 0 < iStack_214)))) {
              do {
                if (0x1c1 < (ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                break;
                iVar26 = iVar17 * 0x10 + iStack_218;
                iStack_1cc = 0;
                cVar16 = recovered_180067cc0(iVar26,&uStack_180);
                if (((cVar16 != '\0') &&
                    (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_180,&iStack_1cc,4),
                    iVar18 == 0)) && (-1 < iStack_1cc)) {
                  iStack_1d0 = 0;
                  cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_188);
                  if (((cVar16 != '\0') &&
                      (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_188,&iStack_1d0,4),
                      iVar26 = iStack_1d0, iVar18 == 0)) && (iStack_1d0 != 0)) {
                    if ((ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38) <
                        0x1c2) {
                      iStackX_18 = 0;
                      cVar16 = recovered_180067cc0(iStack_1d0 + 0x10,&uStack_190);
                      if (((cVar16 != '\0') &&
                          (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_190,&iStackX_18,4),
                          iVar18 == 0)) && (iStackX_18 - 1U < 800)) {
                        aiStackX_20[0] = 0;
                        cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_198);
                        if (((cVar16 != '\0') &&
                            (iVar26 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_198,aiStackX_20,4),
                            iVar26 == 0)) &&
                           ((aiStackX_20[0] != 0 &&
                            (aiStackX_20[0] = aiStackX_20[0] + 0x10, iVar26 = iVar31, 0 < iStackX_18
                            )))) {
                          do {
                            if (0x1c1 < (ulonglong)
                                        ((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                            break;
                            iVar18 = iVar26 * 0x10 + aiStackX_20[0];
                            iStack_1d4 = 0;
                            cVar16 = recovered_180067cc0(iVar18,&uStack_1a0);
                            if (((cVar16 != '\0') &&
                                (iVar19 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a0,&iStack_1d4,4)
                                , iVar19 == 0)) && (-1 < iStack_1d4)) {
                              uStack_1fc = 0;
                              cVar16 = recovered_180067cc0(iVar18 + 0xc,&uStack_1a8);
                              if (((cVar16 != '\0') &&
                                  (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a8,&uStack_1fc,
                                                              4), iVar18 == 0)) && (uStack_1fc != 0)
                                 ) {
                                iStack_1d8 = 0;
                                cVar16 = recovered_18008bca0(uStack_1fc,&iStack_1d8);
                                if (cVar16 != '\0') {
                                  uStack_210 = 0;
                                  fStack_208 = 0.0;
                                  iStack_200 = 0;
                                  cVar16 = recovered_180067cc0((ulonglong)uStack_1fc + 0x3c,
                                                               &uStack_1b0);
                                  if (((cVar16 != '\0') &&
                                      (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b0,
                                                                  &iStack_200,4), iVar18 == 0)) &&
                                     ((iStack_200 != 0 &&
                                      (((cVar16 = recovered_18006bd40(iStack_200,&uStack_210),
                                        cVar16 != '\0' &&
                                        (((fVar34 = (float)uStack_210, (float)uStack_210 != 0.0 ||
                                          (uStack_210._4_4_ != 0.0)) || (fStack_208 != 0.0)))) ||
                                       (((cVar16 = recovered_180067cc0(iStack_200 + 0x3c,&uStack_1b8
                                                                      ), cVar16 != '\0' &&
                                         (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b8,
                                                                     &uStack_210,0xc), iVar18 == 0))
                                        && ((fVar34 = (float)uStack_210, (float)uStack_210 != 0.0 ||
                                            ((uStack_210._4_4_ != 0.0 || (fStack_208 != 0.0)))))))))
                                      ))) {
                                    fVar32 = (float)*param_2 - fVar34;
                                    fVar33 = (float)((ulonglong)*param_2 >> 0x20) - uStack_210._4_4_
                                    ;
                                    fVar32 = fVar33 * fVar33 + fVar32 * fVar32 +
                                             (*(float *)(param_2 + 1) - fStack_208) *
                                             (*(float *)(param_2 + 1) - fStack_208);
                                    if (fVar32 < 0.0) {
                                      fVar32 = (float)func_0x0001801cb525(fVar32);
                                    }
                                    else {
                                      fVar32 = SQRT(fVar32);
                                    }
                                    iVar18 = iStack_1d8;
                                    fVar33 = fStack_208;
                                    if ((fVar32 <= (float)iVar2) && (fVar11 <= fVar32)) {
                                      iStack_120 = iVar12;
                                      iStack_11c = iVar13;
                                      iStack_118 = iVar14;
                                      iStack_114 = iVar15;
                                      stack0xfffffffffffffed1 = SUB1615(ZEXT816(0),1);
                                      auVar9[15] = 0;
                                      auVar9._0_15_ = stack0xfffffffffffffed1;
                                      _auStack_130 = auVar9 << 8;
                                      iStack_140 = iStack_1d8;
                                      uVar6 = uStack_210._4_4_;
                                      uStack_13c = CONCAT44(uStack_210._4_4_,fVar34);
                                      fStack_134 = fStack_208;
                                      fStack_110 = fVar32;
                                      pauVar22 = (undefined (*) [16])
                                                 recovered_1800898f0(auStack_f8,iStack_1d8);
                                      if ((undefined (*) [16])auStack_130 == pauVar22) {
                                        uVar38 = auStack_130;
                                        uVar39 = uStack_12c;
                                        uVar40 = uStack_128;
                                        uVar41 = uStack_124;
                                        iVar19 = iVar12;
                                        iVar35 = iVar13;
                                        iVar36 = iVar14;
                                        iVar37 = iVar15;
                                      }
                                      else {
                                        uVar38 = *(undefined4 *)*pauVar22;
                                        uVar39 = *(undefined4 *)(*pauVar22 + 4);
                                        uVar40 = *(undefined4 *)(*pauVar22 + 8);
                                        uVar41 = *(undefined4 *)(*pauVar22 + 0xc);
                                        _auStack_130 = *pauVar22;
                                        iStack_120 = *(int *)pauVar22[1];
                                        iStack_11c = *(int *)(pauVar22[1] + 4);
                                        iStack_118 = *(int *)(pauVar22[1] + 8);
                                        iStack_114 = *(int *)(pauVar22[1] + 0xc);
                                        *(undefined8 *)pauVar22[1] = 0;
                                        *(undefined8 *)(pauVar22[1] + 8) = 0xf;
                                        (*pauVar22)[0] = 0;
                                        iVar19 = iStack_120;
                                        iVar35 = iStack_11c;
                                        iVar36 = iStack_118;
                                        iVar37 = iStack_114;
                                      }
                                      recovered_180066e40(auStack_f8);
                                      if ((int *)auStack_1f0._8_8_ == piStack_1e0) {
                                        recovered_18008d1e0(auStack_1f0,auStack_1f0._8_8_,
                                                            &iStack_140);
                                      }
                                      else {
                                        *(int *)auStack_1f0._8_8_ = iVar18;
                                        uStack_13c = CONCAT44(uVar6,fVar34);
                                        *(ulonglong *)(auStack_1f0._8_8_ + 4) =
                                             CONCAT44(uVar6,fVar34);
                                        *(float *)(auStack_1f0._8_8_ + 0xc) = fVar33;
                                        auVar5._4_4_ = uVar39;
                                        auVar5._0_4_ = uVar38;
                                        auVar5._8_4_ = uVar40;
                                        auVar5._12_4_ = uVar41;
                                        *(undefined (*) [16])(auStack_1f0._8_8_ + 0x10) = auVar5;
                                        *(int *)(auStack_1f0._8_8_ + 0x20) = iVar19;
                                        *(int *)(auStack_1f0._8_8_ + 0x24) = iVar35;
                                        *(int *)(auStack_1f0._8_8_ + 0x28) = iVar36;
                                        *(int *)(auStack_1f0._8_8_ + 0x2c) = iVar37;
                                        iStack_120 = iVar12;
                                        iStack_11c = iVar13;
                                        iStack_118 = iVar14;
                                        iStack_114 = iVar15;
                                        auVar10[15] = 0;
                                        auVar10._0_15_ = stack0xfffffffffffffed1;
                                        _auStack_130 = auVar10 << 8;
                                        *(float *)(auStack_1f0._8_8_ + 0x30) = fVar32;
                                        auStack_1f0._8_8_ = (int *)(auStack_1f0._8_8_ + 0x38);
                                      }
                                      recovered_180066e40(auStack_130);
                                    }
                                  }
                                }
                              }
                            }
                            iVar26 = iVar26 + 1;
                          } while (iVar26 < iStackX_18);
                        }
                      }
                    }
                  }
                }
                iVar17 = iVar17 + 1;
              } while (iVar17 < iStack_214);
            }
          }
        }
      }
      recovered_180066d80(&DAT_181b2bdd8);
      _DAT_181b2bdd8 = auStack_1f0._0_8_;
      _DAT_181b2bde0 = auStack_1f0._8_8_;
      _DAT_181b2bde8 = piStack_1e0;
      auStack_1f0 = ZEXT816(0);
      piStack_1e0 = (int *)0x0;
    }
    if (auStack_1f0._0_8_ != 0) {
      lVar30 = auStack_1f0._8_8_;
      lVar29 = auStack_1f0._0_8_;
      if (auStack_1f0._0_8_ != auStack_1f0._8_8_) {
        do {
          recovered_180066e40(lVar29 + 0x10);
          lVar29 = lVar29 + 0x38;
        } while (lVar29 != lVar30);
      }
      lVar30 = auStack_1f0._0_8_;
      if ((0xfff < (ulonglong)((((longlong)piStack_1e0 - auStack_1f0._0_8_) / 0x38) * 0x38)) &&
         (lVar30 = *(longlong *)(auStack_1f0._0_8_ + -8), 0x1f < (auStack_1f0._0_8_ - lVar30) - 8U))
      {
        _invoke_watson(0,0,0,0,0);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      func_0x000180127e40(lVar30);
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18008d1e0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 * recovered_18008d1e0(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  longlong lVar9;
  longlong lVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  
  lVar10 = *param_1;
  lVar9 = (param_1[1] - lVar10) / 0x38;
  if (lVar9 == 0x492492492492492) {
    recovered_18006aad0();
    pcVar3 = (code *)swi(3);
    puVar8 = (undefined4 *)(*pcVar3)();
    return puVar8;
  }
  uVar1 = lVar9 + 1;
  uVar2 = (param_1[2] - lVar10) / 0x38;
  if (0x492492492492492 - (uVar2 >> 1) < uVar2) {
    uVar11 = 0x492492492492492;
  }
  else {
    uVar2 = (uVar2 >> 1) + uVar2;
    uVar11 = uVar1;
    if (uVar1 <= uVar2) {
      uVar11 = uVar2;
    }
    if (0x492492492492492 < uVar11) {
      func_0x000180003980();
      pcVar3 = (code *)swi(3);
      puVar8 = (undefined4 *)(*pcVar3)();
      return puVar8;
    }
  }
  puVar7 = (undefined4 *)func_0x000180024110(uVar11 * 0x38);
  puVar12 = puVar7 + ((param_2 - lVar10) / 0x38) * 0xe;
  *puVar12 = *param_3;
  *(undefined8 *)(puVar12 + 1) = *(undefined8 *)(param_3 + 1);
  puVar12[3] = param_3[3];
  *(undefined (*) [16])(puVar12 + 4) = ZEXT816(0);
  *(undefined8 *)(puVar12 + 8) = 0;
  *(undefined8 *)(puVar12 + 10) = 0;
  uVar4 = param_3[5];
  uVar5 = param_3[6];
  uVar6 = param_3[7];
  puVar12[4] = param_3[4];
  puVar12[5] = uVar4;
  puVar12[6] = uVar5;
  puVar12[7] = uVar6;
  uVar4 = param_3[9];
  uVar5 = param_3[10];
  uVar6 = param_3[0xb];
  puVar12[8] = param_3[8];
  puVar12[9] = uVar4;
  puVar12[10] = uVar5;
  puVar12[0xb] = uVar6;
  *(undefined8 *)(param_3 + 8) = 0;
  *(undefined8 *)(param_3 + 10) = 0xf;
  *(undefined *)(param_3 + 4) = 0;
  puVar12[0xc] = param_3[0xc];
  lVar10 = param_1[1];
  lVar9 = *param_1;
  puVar8 = puVar7;
  if (param_2 != lVar10) {
    func_0x00018007a1d0(*param_1,param_2,puVar7);
    lVar10 = param_1[1];
    puVar8 = puVar12 + 0xe;
    lVar9 = param_2;
  }
  func_0x00018007a1d0(lVar9,lVar10,puVar8);
  func_0x00018007ab00(param_1,puVar7,uVar1,uVar11);
  return puVar12;
}



/* ===== ANALYSIS FUNCTION 0x18008d390 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18008d390(void)

{
  uint uVar1;
  float fVar2;
  code *pcVar3;
  longlong lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  longlong lVar18;
  longlong **pplVar19;
  undefined8 uVar20;
  longlong **pplVar21;
  longlong **pplVar22;
  undefined *puVar23;
  int iVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  undefined (*pauVar27) [16];
  longlong lVar28;
  ulonglong uVar29;
  uint *puVar30;
  undefined (*pauVar31) [16];
  float fVar32;
  float fVar33;
  float fVar34;
  float fStackX_20;
  float fStackX_24;
  undefined8 in_stack_fffffffffffffe18;
  undefined4 uVar35;
  undefined8 in_stack_fffffffffffffe20;
  undefined4 uVar36;
  undefined auStack_1c8 [16];
  undefined auStack_1b8 [16];
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  float fStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  float fStack_16c;
  char acStack_168 [296];
  
  lVar18 = _DAT_181b2f2c0;
  if ((DAT_181b2bdd0 != '\0') && (DAT_181b2bec4 != '\0')) {
    if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
      _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
    }
    lVar18 = func_0x00018000a880(**(undefined8 **)(lVar18 + 0x4908),0,&UNK_18020ed28);
    iVar14 = _DAT_181b2becc;
    uVar13 = _DAT_181b2bec8;
    puVar12 = _DAT_181b2bde0;
    fVar11 = _DAT_181a034a0;
    fVar10 = _DAT_181a0348c;
    uVar9 = _DAT_181a03460;
    fVar8 = _DAT_181a03354;
    fVar7 = _DAT_181a03230;
    fVar6 = _DAT_181a03228;
    fVar5 = _DAT_181a031bc;
    if (lVar18 != 0) {
      uVar29 = (ulonglong)_DAT_181b2bec8;
      iVar24 = 0;
      pplVar21 = (longlong **)*_DAT_181b2bdf8;
      if (pplVar21 != _DAT_181b2bdf8) {
        do {
          iVar15 = iVar24 + 1;
          if (*(char *)((longlong)pplVar21 + 0x14) == '\0') {
            iVar15 = iVar24;
          }
          iVar24 = iVar15;
          pplVar21 = (longlong **)*pplVar21;
        } while (pplVar21 != _DAT_181b2bdf8);
        if ((0 < iVar24) && (_DAT_181b2bdd8 != _DAT_181b2bde0)) {
          pauVar31 = (undefined (*) [16])(_DAT_181b2bdd8 + 4);
          pplVar21 = _DAT_181b2bdf8;
          puVar30 = _DAT_181b2bdd8;
          do {
            uVar26 = (ulonglong)*puVar30;
            if (*puVar30 != 0) {
              uVar16 = func_0x000180089860(uVar26);
              uVar25 = (((((ulonglong)(uVar16 & 0xff) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                         (ulonglong)(uVar16 >> 8 & 0xff)) * 0x100000001b3 ^
                        (ulonglong)(uVar16 >> 0x10) & 0xff) * 0x100000001b3 ^
                       (ulonglong)(uVar16 >> 0x18)) * 0x100000001b3 & _DAT_181b2be20;
              pplVar19 = *(longlong ***)(_DAT_181b2be08 + 8 + uVar25 * 0x10);
              if (pplVar19 == pplVar21) {
LAB_18008d5b3:
                pplVar19 = (longlong **)0x0;
              }
              else {
                uVar1 = *(uint *)(pplVar19 + 2);
                while (uVar16 != uVar1) {
                  if (pplVar19 == *(longlong ***)(_DAT_181b2be08 + uVar25 * 0x10))
                  goto LAB_18008d5b3;
                  pplVar19 = (longlong **)pplVar19[1];
                  uVar1 = *(uint *)(pplVar19 + 2);
                }
              }
              pplVar22 = pplVar21;
              if (pplVar19 != (longlong **)0x0) {
                pplVar22 = pplVar19;
              }
              if ((pplVar22 != pplVar21) && (*(char *)((longlong)pplVar22 + 0x14) != '\0')) {
                in_stack_fffffffffffffe18 =
                     CONCAT44((int)((ulonglong)in_stack_fffffffffffffe18 >> 0x20),iVar14);
                recovered_180067e80(&fStack_1a0,&DAT_181b2be70,(uint *)((longlong)pauVar31[-1] + 4))
                ;
                fVar34 = fStack_19c;
                fVar33 = fStack_1a0;
                uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffe20 >> 0x20);
                uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe18 >> 0x20);
                if ((fVar11 <= fStack_1a0) &&
                   (((fVar11 <= fStack_19c && (fStack_1a0 <= (float)(int)uVar29 + fVar8)) &&
                    (fStack_19c <= (float)iVar14 + fVar8)))) {
                  recovered_180089b40(&uStack_188,uVar26 & 0xffffffff);
                  uStack_178 = uStack_188;
                  uStack_174 = uStack_184;
                  uStack_170 = uStack_180;
                  fStack_16c = fStack_17c * *(float *)(_DAT_181b2f2c0 + 0x37d0);
                  uVar17 = func_0x000180004f90(&uStack_178);
                  auStack_1c8 = ZEXT816(0);
                  auStack_1b8 = ZEXT816(0);
                  uVar29 = *(ulonglong *)pauVar31[1];
                  pauVar27 = pauVar31;
                  if (0xf < *(ulonglong *)((longlong)pauVar31[1] + 8)) {
                    pauVar27 = *(undefined (**) [16])*pauVar31;
                  }
                  if (0x7fffffffffffffff < uVar29) {
                    func_0x000180052a50();
                    pcVar3 = (code *)swi(3);
                    (*pcVar3)();
                    return;
                  }
                  if (uVar29 < 0x10) {
                    auStack_1b8._8_8_ = 0xf;
                    auStack_1b8._0_8_ = uVar29;
                    auStack_1c8 = *pauVar27;
                  }
                  else {
                    uVar26 = uVar29 | 0xf;
                    if (uVar26 < 0x8000000000000000) {
                      if (uVar26 < 0x16) {
                        uVar26 = 0x16;
                      }
                    }
                    else {
                      uVar26 = 0x7fffffffffffffff;
                    }
                    uVar20 = func_0x000180024110(uVar26 + 1);
                    auStack_1c8._0_8_ = uVar20;
                    auStack_1b8._8_8_ = uVar26;
                    auStack_1b8._0_8_ = uVar29;
                    func_0x0001801ca88d(uVar20,pauVar27,uVar29 + 1);
                  }
                  if (DAT_181b2bdd2 != '\0') {
                    pauVar27 = pauVar31;
                    if (0xf < *(ulonglong *)((longlong)pauVar31[1] + 8)) {
                      pauVar27 = *(undefined (**) [16])*pauVar31;
                    }
                    uVar20 = CONCAT44(uVar35,(int)*(float *)pauVar31[2]);
                    recovered_18006b2f0(acStack_168,0x80,&UNK_1819d89e0,pauVar27,uVar20);
                    uVar35 = (undefined4)((ulonglong)uVar20 >> 0x20);
                    lVar28 = -1;
                    do {
                      lVar4 = lVar28 + 1;
                      lVar28 = lVar28 + 1;
                    } while (acStack_168[lVar4] != '\0');
                    recovered_1800676d0(auStack_1c8,acStack_168);
                  }
                  puVar23 = auStack_1c8;
                  if (0xf < (ulonglong)auStack_1b8._8_8_) {
                    puVar23 = (undefined *)auStack_1c8._0_8_;
                  }
                  if (puVar23 == (undefined *)0x0) {
                    fVar2 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                    fVar32 = 0.0;
                  }
                  else {
                    uVar20 = CONCAT44(uVar35,fVar10);
                    func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_1a8,
                                        *(float *)(_DAT_181b2f2c0 + 0x3c38),uVar9,uVar20,puVar23,0);
                    uVar35 = (undefined4)((ulonglong)uVar20 >> 0x20);
                    uVar36 = (undefined4)((ulonglong)puVar23 >> 0x20);
                    fStack_1a8 = (float)(int)(fStack_1a8 + fVar6);
                    fVar2 = fStack_1a4;
                    fVar32 = fStack_1a8;
                  }
                  fStackX_24 = (fVar34 - fVar2) - _DAT_181a032a8;
                  fStackX_20 = fVar33 - fVar32 * fVar5;
                  fStack_198 = fStackX_20 - _DAT_181a032dc;
                  fStack_194 = fVar2 * fVar5 + fStackX_24;
                  in_stack_fffffffffffffe20 = CONCAT44(uVar36,9);
                  in_stack_fffffffffffffe18 = CONCAT44(uVar35,_DAT_181a032b8);
                  func_0x0001800272e0(lVar18,&fStack_198,_DAT_181a03298,0,in_stack_fffffffffffffe18,
                                      in_stack_fffffffffffffe20);
                  func_0x000180026810(lVar18,*(undefined8 *)(lVar18 + 0x80),
                                      *(undefined4 *)(lVar18 + 0x78),0xffffffff);
                  *(undefined4 *)(lVar18 + 0x78) = 0;
                  fVar33 = fVar10;
                  puVar23 = auStack_1c8;
                  fVar34 = fVar10;
                  if (0xf < (ulonglong)auStack_1b8._8_8_) {
                    puVar23 = (undefined *)auStack_1c8._0_8_;
                  }
                  do {
                    if ((fVar34 != 0.0) || (fVar33 != 0.0)) {
                      fStack_190 = fVar34 + fStackX_20;
                      fStack_18c = fVar33 + fStackX_24;
                      func_0x000180028900(lVar18,&fStack_190,0xdc000000,puVar23);
                    }
                    fVar33 = fVar33 + fVar7;
                  } while ((fVar33 <= fVar7) ||
                          (fVar34 = fVar34 + fVar7, fVar33 = fVar10, fVar34 <= fVar7));
                  func_0x000180028900(lVar18,&fStackX_20,uVar17,puVar23);
                  if (0xf < (ulonglong)auStack_1b8._8_8_) {
                    if ((0xfff < auStack_1b8._8_8_ + 1) &&
                       (0x1f < (auStack_1c8._0_8_ - *(longlong *)(auStack_1c8._0_8_ + -8)) - 8U)) {
                      _invoke_watson(0,0,0,0,0);
                      pcVar3 = (code *)swi(3);
                      (*pcVar3)();
                      return;
                    }
                    func_0x000180127e40();
                  }
                  uVar29 = (ulonglong)uVar13;
                  pplVar21 = _DAT_181b2bdf8;
                }
              }
            }
            puVar30 = puVar30 + 0xe;
            pauVar31 = (undefined (*) [16])((longlong)pauVar31[3] + 8);
          } while (puVar30 != puVar12);
        }
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180094470 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180094470(undefined8 *param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined auStack_78 [8];
  undefined8 *puStack_70;
  undefined8 *puStack_68;
  uint uStack_50;
  longlong lStack_48;
  ulonglong uStack_40;
  longlong lStack_30;
  int iStack_28;
  
  GetSystemInfo(auStack_78);
  puVar8 = puStack_70;
  if (((undefined8 *)0x40000000 < param_1) && (puStack_70 < param_1 + -0x8000000)) {
    puVar8 = param_1 + -0x8000000;
  }
  puVar9 = param_1 + 0x8000000;
  if (puStack_68 <= param_1 + 0x8000000) {
    puVar9 = puStack_68;
  }
  puVar9 = (undefined8 *)((longlong)puVar9 - 0xfff);
  for (puVar4 = _DAT_181b50ee0; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4) {
    if (((puVar8 <= puVar4) && (puVar4 < puVar9)) && (puVar4[1] != 0)) {
      return puVar4;
    }
  }
  uVar7 = 0x40;
  puVar3 = (undefined8 *)0x0;
  puVar4 = param_1;
  if (puVar8 <= param_1) {
    do {
      uVar5 = (ulonglong)uStack_50;
      puVar4 = (undefined8 *)((longlong)puVar4 + (-uVar5 - (ulonglong)puVar4 % uVar5));
      while( true ) {
        if ((puVar4 < puVar8) || (lVar2 = VirtualQuery(puVar4,&lStack_48,0x30), lVar2 == 0))
        goto LAB_180094579;
        if (iStack_28 == 0x10000) break;
        if (uStack_40 < uVar5) goto LAB_180094579;
        puVar4 = (undefined8 *)(uStack_40 - uVar5);
      }
      if (puVar4 == (undefined8 *)0x0) {
LAB_180094579:
        if (puVar3 != (undefined8 *)0x0) goto LAB_180094660;
        break;
      }
      puVar3 = (undefined8 *)VirtualAlloc(puVar4,0x1000,0x3000,0x40);
      if (puVar3 != (undefined8 *)0x0) goto LAB_18009465b;
    } while (puVar8 <= puVar4);
  }
  if (param_1 <= puVar9) {
    do {
      uVar1 = uStack_50;
      uVar5 = (ulonglong)uStack_50;
      param_1 = (undefined8 *)
                (((ulonglong)uStack_50 - (ulonglong)param_1 % uVar5) + (longlong)param_1);
      while( true ) {
        if ((puVar9 < param_1) || (lVar2 = VirtualQuery(param_1,&lStack_48,0x30), lVar2 == 0))
        goto LAB_18009465b;
        if (iStack_28 == 0x10000) break;
        uVar6 = (ulonglong)(uVar1 - 1) + lStack_30 + lStack_48;
        param_1 = (undefined8 *)(uVar6 - uVar6 % uVar5);
      }
    } while (((param_1 != (undefined8 *)0x0) &&
             (puVar3 = (undefined8 *)VirtualAlloc(param_1,0x1000,0x3000,0x40),
             puVar3 == (undefined8 *)0x0)) && (param_1 <= puVar9));
LAB_18009465b:
    if (puVar3 != (undefined8 *)0x0) {
LAB_180094660:
      *(undefined4 *)(puVar3 + 2) = 0;
      puVar9 = (undefined8 *)0x0;
      puVar8 = puVar3;
      do {
        puVar8 = puVar8 + 8;
        *puVar8 = puVar9;
        puVar3[1] = puVar8;
        uVar7 = uVar7 + 0x40;
        puVar9 = puVar8;
      } while (uVar7 < 0xfc1);
      *puVar3 = _DAT_181b50ee0;
      _DAT_181b50ee0 = puVar3;
    }
  }
  return puVar3;
}



/* ===== ANALYSIS FUNCTION 0x180095090 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180095090(longlong *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint auStack_38 [2];
  int iStack_30;
  int iStack_2c;
  ulonglong uVar7;
  
  uVar7 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  bVar1 = false;
  lVar4 = CreateToolhelp32Snapshot(4,0);
  if (lVar4 != -1) {
    auStack_38[0] = 0x1c;
    iVar3 = Thread32First(lVar4,auStack_38);
    if (iVar3 != 0) {
      bVar1 = true;
      do {
        if (((0xf < auStack_38[0]) && (iVar3 = GetCurrentProcessId(), iStack_2c == iVar3)) &&
           (iVar3 = GetCurrentThreadId(), uVar2 = _DAT_181b2f2e0, iStack_30 != iVar3)) {
          lVar5 = *param_1;
          if (lVar5 == 0) {
            *(undefined4 *)(param_1 + 1) = 0x80;
            lVar5 = HeapAlloc(uVar2,0,0x200);
            *param_1 = lVar5;
            if (lVar5 == 0) goto LAB_1800951bc;
          }
          else if (*(uint *)(param_1 + 1) <= *(uint *)((longlong)param_1 + 0xc)) {
            uVar6 = *(uint *)(param_1 + 1) * 2;
            *(uint *)(param_1 + 1) = uVar6;
            lVar5 = HeapReAlloc(uVar2,0,lVar5,(ulonglong)uVar6 << 2);
            if (lVar5 == 0) goto LAB_1800951bc;
            *param_1 = lVar5;
          }
          uVar6 = *(uint *)((longlong)param_1 + 0xc);
          *(int *)(lVar5 + (ulonglong)uVar6 * 4) = iStack_30;
          *(uint *)((longlong)param_1 + 0xc) = uVar6 + 1;
        }
        auStack_38[0] = 0x1c;
        iVar3 = Thread32Next(lVar4,auStack_38);
      } while (iVar3 != 0);
      iVar3 = GetLastError();
      if (iVar3 != 0x12) {
LAB_1800951bc:
        bVar1 = false;
        if (*param_1 != 0) {
          HeapFree(_DAT_181b2f2e0,0);
          *param_1 = 0;
        }
      }
    }
    CloseHandle(lVar4);
    if (bVar1) {
      if (*param_1 == 0) {
        return 0;
      }
      if (*(int *)((longlong)param_1 + 0xc) == 0) {
        return 0;
      }
      do {
        lVar4 = OpenThread(0x5a,0,*(undefined4 *)(uVar7 * 4 + *param_1));
        if (lVar4 == 0) {
LAB_180095253:
          *(undefined4 *)(uVar7 * 4 + *param_1) = 0;
        }
        else {
          iVar3 = SuspendThread(lVar4);
          if (iVar3 == -1) {
            CloseHandle(lVar4);
            goto LAB_180095253;
          }
          func_0x000180094f00(lVar4,param_2,param_3);
          CloseHandle(lVar4);
        }
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
        if (*(uint *)((longlong)param_1 + 0xc) <= uVar6) {
          return 0;
        }
      } while( true );
    }
  }
  return 9;
}



/* ===== ANALYSIS FUNCTION 0x180095290 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180095290(ulonglong param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  byte bVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 auStackX_8 [2];
  
  puVar5 = (undefined8 *)((param_1 & 0xffffffff) * 0x38 + _DAT_181b50ed0);
  puVar6 = (undefined4 *)((longlong)(undefined4 *)*puVar5 + -5);
  if ((*(byte *)(puVar5 + 4) & 1) == 0) {
    puVar6 = (undefined4 *)*puVar5;
  }
  cVar1 = (*(byte *)(puVar5 + 4) & 1) * '\x02' + '\x05';
  iVar2 = VirtualProtect(puVar6,cVar1,0x40,auStackX_8);
  if (iVar2 == 0) {
    uVar3 = 10;
  }
  else {
    if (param_2 == 0) {
      bVar4 = *(byte *)(puVar5 + 4);
      *puVar6 = *(undefined4 *)(puVar5 + 3);
      if ((bVar4 & 1) == 0) {
        *(undefined *)(puVar6 + 1) = *(undefined *)((longlong)puVar5 + 0x1c);
      }
      else {
        *(undefined2 *)(puVar6 + 1) = *(undefined2 *)((longlong)puVar5 + 0x1c);
        *(undefined *)((longlong)puVar6 + 6) = *(undefined *)((longlong)puVar5 + 0x1e);
      }
    }
    else {
      *(undefined *)puVar6 = 0xe9;
      *(int *)((longlong)puVar6 + 1) = (*(int *)(puVar5 + 1) - (int)puVar6) + -5;
      if ((*(byte *)(puVar5 + 4) & 1) != 0) {
        *(undefined2 *)*puVar5 = 0xf9eb;
      }
    }
    VirtualProtect(puVar6,cVar1,auStackX_8[0],auStackX_8);
    uVar3 = GetCurrentProcess();
    FlushInstructionCache(uVar3,puVar6,cVar1);
    bVar4 = ((char)param_2 * '\x02' ^ *(byte *)(puVar5 + 4)) & 2 ^ *(byte *)(puVar5 + 4);
    *(byte *)(puVar5 + 4) = ((char)param_2 << 2 ^ bVar4) & 4 ^ bVar4;
    uVar3 = 0;
  }
  return uVar3;
}



/* ===== ANALYSIS FUNCTION 0x1800953a0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_1800953a0(uint param_1)

{
  uint uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  int *piVar6;
  ulonglong uVar7;
  uint uVar8;
  int *piStack_18;
  uint uStack_c;
  
  uVar5 = 0;
  if (_DAT_181b50edc != 0) {
    pbVar2 = (byte *)(_DAT_181b50ed0 + 0x20);
    do {
      if ((*pbVar2 >> 1 & 1) != param_1) {
        if (uVar5 == 0xffffffff) {
          return 0;
        }
        uVar3 = recovered_180095090(&piStack_18,0xffffffff,param_1 != 0);
        uVar7 = uVar3 & 0xffffffff;
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        uVar8 = _DAT_181b50edc;
        if (_DAT_181b50edc <= uVar5) goto LAB_18009546c;
        goto LAB_180095430;
      }
      uVar5 = uVar5 + 1;
      pbVar2 = pbVar2 + 0x38;
    } while (uVar5 < _DAT_181b50edc);
  }
  return 0;
LAB_180095430:
  do {
    if ((*(byte *)((ulonglong)uVar5 * 0x38 + 0x20 + _DAT_181b50ed0) >> 1 & 1) != param_1) {
      uVar1 = recovered_180095290(uVar5,param_1);
      uVar7 = (ulonglong)uVar1;
      uVar8 = _DAT_181b50edc;
      if (uVar1 != 0) break;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < uVar8);
LAB_18009546c:
  if (piStack_18 != (int *)0x0) {
    if (uStack_c != 0) {
      uVar3 = (ulonglong)uStack_c;
      piVar6 = piStack_18;
      do {
        if ((*piVar6 != 0) && (lVar4 = OpenThread(0x5a,0), lVar4 != 0)) {
          ResumeThread(lVar4);
          CloseHandle(lVar4);
        }
        piVar6 = piVar6 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    HeapFree(_DAT_181b2f2e0,0,piStack_18);
  }
  return uVar7;
}



/* ===== ANALYSIS FUNCTION 0x1800954f0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_1800954f0(undefined4 *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined4 *puStack_48;
  undefined *puStack_40;
  undefined8 *puStack_38;
  undefined8 uStack_30;
  int iStack_28;
  uint uStack_24;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  uVar8 = 0;
  uVar7 = 0;
  LOCK();
  bVar9 = _DAT_181b2f2d8 == 0;
  if (bVar9) {
    _DAT_181b2f2d8 = 1;
  }
  UNLOCK();
  while (!bVar9) {
    Sleep(0x1f < uVar7);
    uVar7 = uVar7 + 1;
    LOCK();
    bVar9 = _DAT_181b2f2d8 == 0;
    if (bVar9) {
      _DAT_181b2f2d8 = 1;
    }
    UNLOCK();
  }
  if (_DAT_181b2f2e0 == 0) {
    uVar8 = 2;
    goto LAB_1800957a3;
  }
  VirtualQuery(param_1,&puStack_48,0x30);
  if ((((iStack_28 != 0x1000) || ((uStack_24 & 0xf0) == 0)) ||
      (VirtualQuery(&UNK_180095f90,&puStack_48,0x30), iStack_28 != 0x1000)) ||
     ((uStack_24 & 0xf0) == 0)) {
    uVar8 = 7;
    goto LAB_1800957a3;
  }
  uVar2 = 0;
  puVar6 = _DAT_181b50ed0;
  if (_DAT_181b50edc != 0) {
    do {
      if (param_1 == (undefined4 *)*puVar6) {
        if (uVar2 != 0xffffffff) {
          uVar8 = 3;
          goto LAB_1800957a3;
        }
        break;
      }
      uVar2 = uVar2 + 1;
      puVar6 = puVar6 + 7;
    } while (uVar2 < _DAT_181b50edc);
  }
  lVar4 = recovered_180094470(param_1);
  if (lVar4 != 0) {
    puVar6 = *(undefined8 **)(lVar4 + 8);
    uVar1 = *puVar6;
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    *(undefined8 *)(lVar4 + 8) = uVar1;
    if (puVar6 != (undefined8 *)0x0) {
      puStack_40 = &UNK_180095f90;
      puStack_48 = param_1;
      puStack_38 = puVar6;
      iVar3 = recovered_180095b80(&puStack_48);
      if (iVar3 == 0) {
        uVar8 = 8;
        func_0x0001800946d0(puVar6);
        goto LAB_1800957a3;
      }
      if (_DAT_181b50ed0 == (undefined8 *)0x0) {
        _DAT_181b50ed8 = 0x20;
        _DAT_181b50ed0 = (undefined8 *)HeapAlloc(_DAT_181b2f2e0,0,0x700);
        if (_DAT_181b50ed0 != (undefined8 *)0x0) goto LAB_1800956d8;
      }
      else {
        if (_DAT_181b50ed8 <= _DAT_181b50edc) {
          puVar5 = (undefined8 *)
                   HeapReAlloc(_DAT_181b2f2e0,0,_DAT_181b50ed0,
                               (ulonglong)(_DAT_181b50ed8 * 2) * 0x38);
          if (puVar5 == (undefined8 *)0x0) goto LAB_180095664;
          _DAT_181b50ed8 = _DAT_181b50ed8 * 2;
          _DAT_181b50ed0 = puVar5;
        }
LAB_1800956d8:
        uVar7 = (ulonglong)_DAT_181b50edc;
        _DAT_181b50edc = _DAT_181b50edc + 1;
        puVar5 = _DAT_181b50ed0 + uVar7 * 7;
        if (puVar5 != (undefined8 *)0x0) {
          *(uint *)((longlong)puVar5 + 0x24) = *(uint *)((longlong)puVar5 + 0x24) & 0xfffffff0;
          *puVar5 = puStack_48;
          puVar5[1] = uStack_30;
          puVar5[2] = puStack_38;
          *(byte *)(puVar5 + 4) = (byte)iStack_28 & 1 | *(byte *)(puVar5 + 4) & 0xf8;
          *(uint *)((longlong)puVar5 + 0x24) = *(uint *)((longlong)puVar5 + 0x24) | uStack_24 & 0xf;
          puVar5[5] = uStack_20;
          puVar5[6] = uStack_18;
          if (iStack_28 == 0) {
            *(undefined4 *)(puVar5 + 3) = *param_1;
            *(undefined *)((longlong)puVar5 + 0x1c) = *(undefined *)(param_1 + 1);
            _DAT_181b4ef88 = puStack_38;
          }
          else {
            *(undefined4 *)(puVar5 + 3) = *(undefined4 *)((longlong)param_1 + -5);
            *(undefined2 *)((longlong)puVar5 + 0x1c) = *(undefined2 *)((longlong)param_1 + -1);
            *(undefined *)((longlong)puVar5 + 0x1e) = *(undefined *)((longlong)param_1 + 1);
            _DAT_181b4ef88 = puStack_38;
          }
          goto LAB_1800957a3;
        }
      }
LAB_180095664:
      uVar8 = 9;
      func_0x0001800946d0(puVar6);
      goto LAB_1800957a3;
    }
  }
  uVar8 = 9;
LAB_1800957a3:
  LOCK();
  _DAT_181b2f2d8 = 0;
  UNLOCK();
  return uVar8;
}



/* ===== ANALYSIS FUNCTION 0x1800957d0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_1800957d0(void)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  int *piVar13;
  bool bVar14;
  int *piStack_28;
  uint uStack_1c;
  
  lVar7 = _DAT_181b4ef88;
  uVar11 = 0;
  LOCK();
  bVar14 = _DAT_181b2f2d8 == 0;
  if (bVar14) {
    _DAT_181b2f2d8 = 1;
  }
  UNLOCK();
  uVar10 = uVar11;
  while (!bVar14) {
    Sleep(0x1f < uVar10);
    uVar10 = uVar10 + 1;
    LOCK();
    bVar14 = _DAT_181b2f2d8 == 0;
    if (bVar14) {
      _DAT_181b2f2d8 = 1;
    }
    UNLOCK();
  }
  if (_DAT_181b2f2e0 == 0) {
    uVar11 = 2;
  }
  else {
    plVar8 = _DAT_181b50ed0;
    uVar10 = uVar11;
    if (_DAT_181b50edc != 0) {
      do {
        uVar9 = (uint)uVar10;
        if (lVar7 == *plVar8) {
          if (uVar9 != 0xffffffff) {
            if ((*(byte *)(_DAT_181b50ed0 + uVar10 * 7 + 4) & 2) == 0) goto LAB_18009591c;
            uVar6 = recovered_180095090(&piStack_28,uVar10,0);
            uVar11 = (ulonglong)uVar6;
            if (uVar6 == 0) {
              uVar6 = recovered_180095290(uVar10,0);
              uVar11 = (ulonglong)uVar6;
              if (piStack_28 != (int *)0x0) {
                if (uStack_1c != 0) {
                  uVar12 = (ulonglong)uStack_1c;
                  piVar13 = piStack_28;
                  do {
                    if ((*piVar13 != 0) && (lVar7 = OpenThread(0x5a,0), lVar7 != 0)) {
                      ResumeThread(lVar7);
                      CloseHandle(lVar7);
                    }
                    piVar13 = piVar13 + 1;
                    uVar12 = uVar12 - 1;
                  } while (uVar12 != 0);
                }
                HeapFree(_DAT_181b2f2e0,0,piStack_28);
              }
              if (uVar6 != 0) goto LAB_1800959bd;
LAB_18009591c:
              func_0x0001800946d0(_DAT_181b50ed0[uVar10 * 7 + 2]);
              plVar8 = _DAT_181b50ed0;
              _DAT_181b50edc = _DAT_181b50edc - 1;
              if (uVar9 < _DAT_181b50edc) {
                uVar12 = (ulonglong)_DAT_181b50edc;
                plVar1 = _DAT_181b50ed0 + uVar12 * 7;
                uVar3 = *(undefined4 *)((longlong)plVar1 + 4);
                uVar4 = *(undefined4 *)(plVar1 + 1);
                uVar5 = *(undefined4 *)((longlong)plVar1 + 0xc);
                plVar2 = _DAT_181b50ed0 + uVar10 * 7;
                *(undefined4 *)plVar2 = *(undefined4 *)plVar1;
                *(undefined4 *)((longlong)plVar2 + 4) = uVar3;
                *(undefined4 *)(plVar2 + 1) = uVar4;
                *(undefined4 *)((longlong)plVar2 + 0xc) = uVar5;
                plVar1 = plVar8 + uVar12 * 7 + 2;
                uVar3 = *(undefined4 *)((longlong)plVar1 + 4);
                uVar4 = *(undefined4 *)(plVar1 + 1);
                uVar5 = *(undefined4 *)((longlong)plVar1 + 0xc);
                plVar2 = plVar8 + uVar10 * 7 + 2;
                *(undefined4 *)plVar2 = *(undefined4 *)plVar1;
                *(undefined4 *)((longlong)plVar2 + 4) = uVar3;
                *(undefined4 *)(plVar2 + 1) = uVar4;
                *(undefined4 *)((longlong)plVar2 + 0xc) = uVar5;
                plVar1 = plVar8 + uVar12 * 7 + 4;
                uVar3 = *(undefined4 *)((longlong)plVar1 + 4);
                uVar4 = *(undefined4 *)(plVar1 + 1);
                uVar5 = *(undefined4 *)((longlong)plVar1 + 0xc);
                plVar2 = plVar8 + uVar10 * 7 + 4;
                *(undefined4 *)plVar2 = *(undefined4 *)plVar1;
                *(undefined4 *)((longlong)plVar2 + 4) = uVar3;
                *(undefined4 *)(plVar2 + 1) = uVar4;
                *(undefined4 *)((longlong)plVar2 + 0xc) = uVar5;
                plVar8[uVar10 * 7 + 6] = plVar8[uVar12 * 7 + 6];
              }
              if (((0x1f < _DAT_181b50ed8 >> 1) && (_DAT_181b50edc <= _DAT_181b50ed8 >> 1)) &&
                 (plVar8 = (longlong *)
                           HeapReAlloc(_DAT_181b2f2e0,0,_DAT_181b50ed0,
                                       (ulonglong)(_DAT_181b50ed8 >> 1) * 0x38),
                 plVar8 != (longlong *)0x0)) {
                _DAT_181b50ed8 = _DAT_181b50ed8 >> 1;
                _DAT_181b50ed0 = plVar8;
              }
            }
            goto LAB_1800959bd;
          }
          break;
        }
        plVar8 = plVar8 + 7;
        uVar10 = (ulonglong)(uVar9 + 1);
      } while (uVar9 + 1 < _DAT_181b50edc);
    }
    uVar11 = 4;
  }
LAB_1800959bd:
  LOCK();
  _DAT_181b2f2d8 = 0;
  UNLOCK();
  return uVar11;
}



/* ===== ANALYSIS FUNCTION 0x1800959f0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int recovered_1800959f0(longlong param_1,uint param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  int *piVar6;
  ulonglong uVar7;
  bool bVar8;
  int *piStack_18;
  uint uStack_c;
  
  uVar7 = 0;
  LOCK();
  bVar8 = _DAT_181b2f2d8 == 0;
  if (bVar8) {
    _DAT_181b2f2d8 = 1;
  }
  UNLOCK();
  uVar5 = uVar7;
  while (!bVar8) {
    Sleep(0x1f < uVar5);
    uVar5 = uVar5 + 1;
    LOCK();
    bVar8 = _DAT_181b2f2d8 == 0;
    if (bVar8) {
      _DAT_181b2f2d8 = 1;
    }
    UNLOCK();
  }
  if (_DAT_181b2f2e0 == 0) {
    iVar1 = 2;
  }
  else if (param_1 == 0) {
    iVar1 = recovered_1800953a0(param_2);
  }
  else {
    plVar2 = _DAT_181b50ed0;
    if (_DAT_181b50edc != 0) {
      do {
        if (param_1 == *plVar2) {
          if ((int)uVar7 != -1) {
            if ((*(byte *)(_DAT_181b50ed0 + uVar7 * 7 + 4) >> 1 & 1) == param_2) {
              iVar1 = 6 - (uint)(param_2 != 0);
            }
            else {
              iVar1 = recovered_180095090(&piStack_18,uVar7,1);
              if ((iVar1 == 0) &&
                 (iVar1 = recovered_180095290(uVar7,param_2), piStack_18 != (int *)0x0)) {
                if (uStack_c != 0) {
                  uVar7 = (ulonglong)uStack_c;
                  piVar6 = piStack_18;
                  do {
                    if ((*piVar6 != 0) && (lVar3 = OpenThread(0x5a,0), lVar3 != 0)) {
                      ResumeThread(lVar3);
                      CloseHandle(lVar3);
                    }
                    piVar6 = piVar6 + 1;
                    uVar7 = uVar7 - 1;
                  } while (uVar7 != 0);
                }
                HeapFree(_DAT_181b2f2e0,0,piStack_18);
              }
            }
            goto LAB_180095b4d;
          }
          break;
        }
        uVar4 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar4;
        plVar2 = plVar2 + 7;
      } while (uVar4 < _DAT_181b50edc);
    }
    iVar1 = 4;
  }
LAB_180095b4d:
  LOCK();
  _DAT_181b2f2d8 = 0;
  UNLOCK();
  return iVar1;
}



/* ===== ANALYSIS FUNCTION 0x180095b80 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 recovered_180095b80(longlong *param_1)

{
  char cVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined *puVar12;
  char *pcVar13;
  undefined8 *puVar14;
  byte bStackX_8;
  byte bStackX_10;
  undefined2 uStack_a8;
  undefined4 uStack_a6;
  undefined2 uStack_a2;
  undefined4 uStack_a0;
  undefined2 uStack_9c;
  undefined8 uStack_98;
  undefined8 *puStack_90;
  undefined2 uStack_88;
  undefined4 uStack_86;
  undefined2 uStack_82;
  undefined8 uStack_80;
  undefined8 auStack_78 [2];
  byte abStack_68 [11];
  byte bStack_5d;
  byte bStack_5c;
  byte bStack_5b;
  char cStack_59;
  int iStack_53;
  undefined4 uStack_4b;
  uint uStack_47;
  
  puVar14 = (undefined8 *)0x0;
  uStack_88 = 0x15ff;
  uStack_86 = 2;
  uStack_82 = 0x8eb;
  bStackX_8 = 0;
  uStack_80 = (undefined *)0x0;
  uStack_a8 = 0x25ff;
  uStack_a6 = 0;
  uStack_a2 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0x25ff0e70;
  puStack_90 = (undefined8 *)0x0;
  bStackX_10 = 0;
  param_1[4] = 0;
  puVar9 = puVar14;
  do {
    puVar10 = (undefined8 *)((ulonglong)bStackX_10 + *param_1);
    lVar7 = param_1[2];
    uVar3 = func_0x000180094750(puVar10,abStack_68);
    uVar5 = uStack_47;
    uVar3 = uVar3 & 0xffffffff;
    if ((uStack_47 >> 0xc & 1) != 0) {
      return 0;
    }
    puVar8 = puVar9;
    if (bStackX_10 < 5) {
      if ((bStack_5b & 199) == 5) {
        uVar4 = (ulonglong)abStack_68[0];
        puVar9 = puVar10;
        puVar11 = auStack_78;
        for (uVar6 = uVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined *)puVar11 = *(undefined *)puVar9;
          puVar9 = (undefined8 *)((longlong)puVar9 + 1);
          puVar11 = (undefined8 *)((longlong)puVar11 + 1);
        }
        *(uint *)((longlong)auStack_78 + (uVar4 - (uVar5 >> 2 & 0xf)) + -4) =
             ((int)puVar10 - ((uint)bStackX_8 + (int)lVar7)) + uStack_4b;
        puVar11 = auStack_78;
        if ((bStack_5d == 0xff) && (cStack_59 == '\x04')) {
          puVar14 = (undefined8 *)0x1;
        }
      }
      else if (bStack_5d == 0xe8) {
        puVar11 = (undefined8 *)&uStack_88;
        uStack_80 = (undefined *)
                    ((longlong)puVar10 + (ulonglong)abStack_68[0] + (longlong)iStack_53);
LAB_180095db8:
        uVar3 = 0x10;
        puVar8 = puVar9;
      }
      else {
        puVar11 = puVar10;
        if ((bStack_5d & 0xfd) == 0xe9) {
          lVar7 = (longlong)(char)iStack_53;
          if (bStack_5d != 0xeb) {
            lVar7 = (longlong)iStack_53;
          }
          puVar8 = (undefined8 *)((longlong)puVar10 + lVar7 + (ulonglong)abStack_68[0]);
          if ((puVar8 < (undefined8 *)*param_1) ||
             ((undefined8 *)((longlong)(undefined8 *)*param_1 + 5U) <= puVar8)) {
            uStack_a2 = SUB82(puVar8,0);
            uStack_a0 = (undefined4)((ulonglong)puVar8 >> 0x10);
            uStack_9c = (undefined2)((ulonglong)puVar8 >> 0x30);
            puVar14 = (undefined8 *)(ulonglong)(puVar9 <= puVar10);
            uVar3 = 0xe;
            puVar11 = (undefined8 *)&uStack_a8;
            puVar8 = puVar9;
          }
          else if (puVar8 <= puVar9) {
            puVar8 = puVar9;
          }
        }
        else if ((((bStack_5d & 0xf0) == 0x70) || ((bStack_5d & 0xfc) == 0xe0)) ||
                ((bStack_5c & 0xf0) == 0x80)) {
          if (((bStack_5d & 0xf0) == 0x70) ||
             (lVar7 = (longlong)iStack_53, (bStack_5d & 0xfc) == 0xe0)) {
            lVar7 = (longlong)(char)iStack_53;
          }
          puVar8 = (undefined8 *)((longlong)puVar10 + lVar7 + (ulonglong)abStack_68[0]);
          if ((puVar8 < (undefined8 *)*param_1) ||
             ((undefined8 *)((longlong)(undefined8 *)*param_1 + 5U) <= puVar8)) {
            if ((bStack_5d & 0xfc) == 0xe0) {
              return 0;
            }
            bVar2 = bStack_5d;
            if (bStack_5d == 0xf) {
              bVar2 = bStack_5c;
            }
            puStack_90 = puVar8;
            puVar11 = &uStack_98;
            uStack_98 = CONCAT71(uStack_98._1_7_,bVar2) & 0xffffffffffffff0f ^ 0x71;
            goto LAB_180095db8;
          }
          if (puVar8 <= puVar9) {
            puVar8 = puVar9;
          }
        }
        else if ((bStack_5d & 0xfe) == 0xc2) {
          puVar14 = (undefined8 *)(ulonglong)(puVar9 <= puVar10);
        }
      }
    }
    else {
      uStack_a2 = SUB82(puVar10,0);
      uStack_a0 = (undefined4)((ulonglong)puVar10 >> 0x10);
      uStack_9c = (undefined2)((ulonglong)puVar10 >> 0x30);
      uVar3 = 0xe;
      puVar14 = (undefined8 *)0x1;
      puVar11 = (undefined8 *)&uStack_a8;
    }
    if ((puVar10 < puVar8) && ((uint)uVar3 != (uint)abStack_68[0])) {
      return 0;
    }
    uVar6 = (ulonglong)bStackX_8;
    if (0x32 < (uint)uVar3 + (uint)bStackX_8) {
      return 0;
    }
    if (7 < *(uint *)((longlong)param_1 + 0x24)) {
      return 0;
    }
    *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x24) + 0x28 + (longlong)param_1) =
         bStackX_10;
    *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x24) + 0x30 + (longlong)param_1) = bStackX_8
    ;
    bStackX_8 = bStackX_8 + (char)uVar3;
    *(int *)((longlong)param_1 + 0x24) = *(int *)((longlong)param_1 + 0x24) + 1;
    puVar12 = (undefined *)(uVar6 + param_1[2]);
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar12 = *(undefined *)puVar11;
      puVar11 = (undefined8 *)((longlong)puVar11 + 1);
      puVar12 = puVar12 + 1;
    }
    bStackX_10 = bStackX_10 + abStack_68[0];
    puVar9 = puVar8;
  } while ((int)puVar14 == 0);
  if (bStackX_10 < 5) {
    pcVar13 = (char *)((ulonglong)bStackX_10 + *param_1);
    cVar1 = *pcVar13;
    if (((cVar1 != '\0') && (cVar1 != -0x70)) && (cVar1 != -0x34)) {
LAB_180095e62:
      if (bStackX_10 < 2) {
        if (((cVar1 != '\0') && (cVar1 != -0x70)) && (cVar1 != -0x34)) {
          return 0;
        }
        uVar3 = 1;
        if (1 < 2 - bStackX_10) {
          do {
            if (pcVar13[uVar3] != cVar1) {
              return 0;
            }
            uVar5 = (int)uVar3 + 1;
            uVar3 = (ulonglong)uVar5;
          } while (uVar5 < 2 - bStackX_10);
        }
      }
      VirtualQuery(*param_1 + -5,abStack_68,0x30);
      if ((CONCAT31((undefined3)uStack_47,uStack_4b._3_1_) == 0x1000) &&
         ((uStack_47 & 0xf0000000) != 0)) {
        cVar1 = *(char *)(*param_1 + -5);
        if ((cVar1 == '\0') || ((cVar1 == -0x70 || (cVar1 == -0x34)))) {
          uVar5 = 1;
          pcVar13 = (char *)(*param_1 + -4);
          do {
            if (*pcVar13 != cVar1) {
              return 0;
            }
            uVar5 = uVar5 + 1;
            pcVar13 = pcVar13 + 1;
          } while (uVar5 < 5);
          *(undefined4 *)(param_1 + 4) = 1;
          goto LAB_180095f06;
        }
      }
      return 0;
    }
    uVar3 = 1;
    if (1 < 5 - bStackX_10) {
      do {
        if (pcVar13[uVar3] != cVar1) goto LAB_180095e62;
        uVar5 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar5;
      } while (uVar5 < 5 - bStackX_10);
    }
  }
LAB_180095f06:
  lVar7 = param_1[1];
  uStack_a2 = (undefined2)lVar7;
  uStack_a0 = (undefined4)((ulonglong)lVar7 >> 0x10);
  uStack_9c = (undefined2)((ulonglong)lVar7 >> 0x30);
  puVar9 = (undefined8 *)((ulonglong)bStackX_8 + param_1[2]);
  param_1[3] = (longlong)puVar9;
  *puVar9 = CONCAT26(uStack_a2,CONCAT42(uStack_a6,uStack_a8));
  *(undefined4 *)(puVar9 + 1) = uStack_a0;
  *(undefined2 *)((longlong)puVar9 + 0xc) = uStack_9c;
  return 1;
}



/* ===== ANALYSIS FUNCTION 0x180095fb0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180095fb0(undefined (*param_1) [16],undefined8 *param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined (*pauVar6) [16];
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined4 auStackX_10 [2];
  int aiStackX_18 [2];
  longlong lStackX_20;
  longlong lStack_170;
  longlong lStack_168;
  int iStack_13c;
  undefined *apuStack_138 [2];
  undefined auStack_128 [16];
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_f8;
  ulonglong *puStack_f0;
  int *piStack_e0;
  ulonglong uStack_c8;
  uint uStack_c0;
  undefined auStack_b0 [112];
  
  auStackX_10[0] = 0;
  puVar7 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar7 = (undefined8 *)*param_2;
  }
  uVar2 = GetFileVersionInfoSizeA(puVar7,auStackX_10);
  uVar8 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    (*param_1)[0] = 0;
    return param_1;
  }
  lVar4 = func_0x000180024110(uVar8);
  func_0x0001801ca899(lVar4,0,uVar8);
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  iVar3 = GetFileVersionInfoA(param_2,auStackX_10[0],uVar8,lVar4);
  if (iVar3 != 0) {
    lStackX_20 = 0;
    aiStackX_18[0] = 0;
    iVar3 = VerQueryValueA(lVar4,&UNK_1819d8bec,&lStackX_20,aiStackX_18);
    if (((iVar3 != 0) && (aiStackX_18[0] != 0)) && (lStackX_20 != 0)) {
      apuStack_138[0] = &UNK_1819d8e48;
      __0__basic_ios_DU__char_traits_D_std___std__IEAA_XZ(auStack_b0);
      __0__basic_ostream_DU__char_traits_D_std___std__QEAA_PEAV__basic_streambuf_DU__char_traits_D_std___1__N_Z
                (apuStack_138,apuStack_138 + 1,0,0);
      *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) =
           &UNK_180201ff8;
      *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
           *(int *)(apuStack_138[0] + 4) + -0x88;
      __0__basic_streambuf_DU__char_traits_D_std___std__IEAA_XZ(apuStack_138 + 1);
      apuStack_138[1] = &UNK_1801f2638;
      uStack_c8 = 0;
      uStack_c0 = 4;
      uVar5 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                        (apuStack_138,*(undefined2 *)(lStackX_20 + 10));
      uVar5 = recovered_180069ac0(uVar5,&UNK_1819d8bf0);
      uVar5 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                        (uVar5,*(undefined2 *)(lStackX_20 + 8));
      uVar5 = recovered_180069ac0(uVar5,&UNK_1819d8bf0);
      uVar5 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                        (uVar5,*(undefined2 *)(lStackX_20 + 0xe));
      uVar5 = recovered_180069ac0(uVar5,&UNK_1819d8bf0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                (uVar5,*(undefined2 *)(lStackX_20 + 0xc));
      *param_1 = ZEXT816(0);
      *(undefined8 *)param_1[1] = 0;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      (*param_1)[0] = 0;
      if ((((byte)uStack_c0 & 0x22) == 2) || (uVar10 = *puStack_f0, uVar10 == 0)) {
        if (((uStack_c0 & 4) == 0) && (*plStack_f8 != 0)) {
          lStack_170 = *plStack_118;
          lStack_168 = (*piStack_e0 - lStack_170) + *plStack_f8;
        }
        else {
          lStack_168 = 0;
          lStack_170 = 0;
        }
      }
      else {
        lStack_170 = *plStack_110;
        if (uVar10 < uStack_c8) {
          uVar10 = uStack_c8;
        }
        lStack_168 = uVar10 - lStack_170;
      }
      if (lStack_170 != 0) {
        recovered_1800676d0(param_1,lStack_170,lStack_168);
      }
      *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) =
           &UNK_180201ff8;
      *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
           *(int *)(apuStack_138[0] + 4) + -0x88;
      apuStack_138[1] = &UNK_1801f2638;
      recovered_1800985e0(apuStack_138 + 1);
      __1__basic_streambuf_DU__char_traits_D_std___std__UEAA_XZ(apuStack_138 + 1);
      __1__basic_ostream_DU__char_traits_D_std___std__UEAA_XZ(auStack_128);
      __1__basic_ios_DU__char_traits_D_std___std__UEAA_XZ(auStack_b0);
      goto LAB_1800962b6;
    }
  }
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
LAB_1800962b6:
  if (lVar4 != 0) {
    lVar9 = lVar4;
    if (0xfff < uVar8) {
      uVar8 = uVar8 + 0x27;
      lVar9 = *(longlong *)(lVar4 + -8);
      if (0x1f < (lVar4 - lVar9) - 8U) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        pauVar6 = (undefined (*) [16])(*pcVar1)();
        return pauVar6;
      }
    }
    func_0x000180127e40(lVar9,uVar8);
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x1800963a0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_1800963a0(undefined (*param_1) [16],longlong param_2)

{
  undefined *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  int iVar11;
  undefined4 *puVar12;
  longlong lVar13;
  longlong lVar14;
  char *pcVar15;
  undefined *puVar16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined (*pauVar19) [16];
  undefined *puVar20;
  undefined8 *******pppppppuVar21;
  ulonglong uVar22;
  char *pcVar23;
  ulonglong uVar24;
  char *pcVar25;
  int aiStackX_10 [2];
  uint auStackX_18 [4];
  undefined auStack_728 [16];
  ulonglong uStack_718;
  ulonglong uStack_710;
  undefined4 uStack_708;
  undefined auStack_700 [8];
  undefined8 uStack_6f8;
  ulonglong uStack_6f0;
  ulonglong uStack_6e8;
  undefined auStack_6e0 [16];
  undefined8 uStack_6d0;
  ulonglong uStack_6c8;
  undefined auStack_6c0 [16];
  ulonglong uStack_6b0;
  ulonglong uStack_6a8;
  undefined auStack_6a0 [16];
  ulonglong uStack_690;
  ulonglong uStack_688;
  undefined auStack_680 [16];
  undefined8 uStack_670;
  ulonglong uStack_668;
  undefined8 *******apppppppuStack_660 [2];
  longlong lStack_650;
  ulonglong uStack_648;
  int iStack_63c;
  undefined *apuStack_638 [2];
  undefined auStack_628 [16];
  longlong *plStack_618;
  longlong *plStack_610;
  longlong *plStack_5f8;
  ulonglong *puStack_5f0;
  int *piStack_5e0;
  ulonglong uStack_5c8;
  uint uStack_5c0;
  undefined auStack_5b0 [104];
  char acStack_548 [256];
  undefined auStack_448 [1040];
  
  uStack_708 = 0;
  if (param_2 == 0) {
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    puVar12 = (undefined4 *)func_0x000180024110(0x20);
    *(undefined4 **)*param_1 = puVar12;
    *(undefined8 *)param_1[1] = 0x11;
    *(undefined8 *)(param_1[1] + 8) = 0x1f;
    uVar9 = _UNK_1819d8c04;
    uVar8 = _UNK_1819d8c00;
    uVar7 = _UNK_1819d8bfc;
    *puVar12 = _DAT_1819d8bf8;
    puVar12[1] = uVar7;
    puVar12[2] = uVar8;
    puVar12[3] = uVar9;
    *(undefined *)(puVar12 + 4) = DAT_1819d8c08;
    *(undefined *)((longlong)puVar12 + 0x11) = 0;
    return param_1;
  }
  func_0x0001801ca899(acStack_548,0,0x100);
  GetWindowTextA(param_2,acStack_548,0xff);
  auStack_6a0 = ZEXT816(0);
  uStack_690 = 0;
  uStack_688 = 0;
  lVar13 = -1;
  do {
    lVar14 = lVar13 + 1;
    lVar13 = lVar13 + 1;
  } while (acStack_548[lVar14] != '\0');
  recovered_180066cc0(auStack_6a0,acStack_548);
  aiStackX_10[0] = 0;
  GetWindowThreadProcessId(param_2,aiStackX_10);
  if ((aiStackX_10[0] == 0) || (lVar13 = OpenProcess(0x1000,0), lVar13 == 0)) {
    uStack_6b0 = 0;
    uStack_6a8 = 0xf;
    auStack_6c0._1_15_ = SUB1615(ZEXT816(0),1);
    auVar5[15] = 0;
    auVar5._0_15_ = auStack_6c0._1_15_;
    auStack_6c0 = auVar5 << 8;
  }
  else {
    func_0x0001801ca899(auStack_448,0,0x410);
    auStackX_18[0] = 0x410;
    uStack_6f0 = 0;
    uStack_6e8 = 0xf;
    stack0xfffffffffffff901 = SUB1615(ZEXT816(0),1);
    auVar4[15] = 0;
    auVar4._0_15_ = stack0xfffffffffffff901;
    _auStack_700 = auVar4 << 8;
    iVar11 = QueryFullProcessImageNameA(lVar13,0,auStack_448,auStackX_18);
    if (iVar11 != 0) {
      uVar24 = (ulonglong)auStackX_18[0];
      if (uVar24 < 0x10) {
        uStack_6f0 = uVar24;
        func_0x0001801ca893(auStack_700,auStack_448,auStackX_18[0]);
        auStack_700[uVar24] = 0;
      }
      else {
        uVar22 = uVar24 | 0xf;
        if (uVar22 < 0x16) {
          uVar22 = 0x16;
        }
        lVar14 = func_0x000180024110(uVar22 + 1);
        uStack_6f0 = uVar24;
        uStack_6e8 = uVar22;
        func_0x0001801ca88d(lVar14,auStack_448,uVar24);
        *(undefined *)(lVar14 + uVar24) = 0;
        auStack_700 = (undefined  [8])lVar14;
      }
    }
    CloseHandle(lVar13);
    auStack_6c0 = _auStack_700;
    uStack_6b0 = uStack_6f0;
    uStack_6a8 = uStack_6e8;
  }
  recovered_180095fb0(apppppppuStack_660,auStack_6c0);
  uVar24 = uStack_690;
  uStack_6d0 = 7;
  uStack_6c8 = 0xf;
  auStack_6e0 = ZEXT716((uint7)CONCAT16(DAT_18020e776,CONCAT24(_DAT_18020e774,_DAT_18020e770)));
  auStack_728 = ZEXT816(0);
  uStack_718 = 0;
  uStack_710 = 0;
  pauVar19 = &auStack_6a0;
  if (0xf < uStack_688) {
    pauVar19 = (undefined (*) [16])auStack_6a0._0_8_;
  }
  if (0x7fffffffffffffff < uStack_690) {
    func_0x000180052a50();
    pcVar3 = (code *)swi(3);
    pauVar19 = (undefined (*) [16])(*pcVar3)();
    return pauVar19;
  }
  if (uStack_690 < 0x10) {
    uStack_718 = uStack_690;
    uStack_710 = 0xf;
    auStack_728 = *pauVar19;
  }
  else {
    uVar22 = uStack_690 | 0xf;
    if (uVar22 < 0x8000000000000000) {
      if (uVar22 < 0x16) {
        uVar22 = 0x16;
      }
    }
    else {
      uVar22 = 0x7fffffffffffffff;
    }
    uVar18 = func_0x000180024110(uVar22 + 1);
    auStack_728._0_8_ = uVar18;
    uStack_718 = uVar24;
    uStack_710 = uVar22;
    func_0x0001801ca88d(uVar18,pauVar19,uVar24 + 1);
  }
  pcVar23 = auStack_728;
  if (0xf < uStack_710) {
    pcVar23 = (char *)auStack_728._0_8_;
  }
  pcVar25 = auStack_728;
  if (0xf < uStack_710) {
    pcVar25 = (char *)auStack_728._0_8_;
  }
  pcVar25 = pcVar25 + uStack_718;
  if (pcVar23 != pcVar25) {
    do {
      cVar10 = tolower((int)*pcVar23);
      *pcVar23 = cVar10;
      pcVar23 = pcVar23 + 1;
    } while (pcVar23 != pcVar25);
  }
  pcVar23 = auStack_728;
  if (0xf < uStack_710) {
    pcVar23 = (char *)auStack_728._0_8_;
  }
  pcVar25 = (char *)auStack_728._0_8_;
  if (uStack_718 < 10) {
LAB_180096733:
    puVar20 = auStack_6c0;
    if (0xf < uStack_6a8) {
      puVar20 = (undefined *)auStack_6c0._0_8_;
    }
    if (9 < uStack_6b0) {
      puVar1 = puVar20 + uStack_6b0;
      puVar16 = (undefined *)func_0x0001801278a0(puVar20,puVar1,&UNK_1819d8c20,10);
      if ((puVar16 != puVar1) && ((longlong)puVar16 - (longlong)puVar20 != -1)) goto LAB_180096775;
      pcVar25 = (char *)auStack_728._0_8_;
    }
    pcVar23 = auStack_728;
    if (0xf < uStack_710) {
      pcVar23 = pcVar25;
    }
    if (((uStack_718 < 3) ||
        (pcVar25 = pcVar23 + uStack_718,
        pcVar15 = (char *)func_0x0001801278a0(pcVar23,pcVar25,&UNK_1819d8c2c,3), pcVar15 == pcVar25)
        ) || ((longlong)pcVar15 - (longlong)pcVar23 == -1)) {
      puVar20 = auStack_6c0;
      if (0xf < uStack_6a8) {
        puVar20 = (undefined *)auStack_6c0._0_8_;
      }
      if (((uStack_6b0 < 3) ||
          (puVar1 = puVar20 + uStack_6b0,
          puVar16 = (undefined *)func_0x0001801278a0(puVar20,puVar1,&UNK_1819d8c30,3),
          puVar16 == puVar1)) || ((longlong)puVar16 - (longlong)puVar20 == -1)) goto LAB_18009691b;
    }
    uVar24 = uStack_6c8;
    if (uStack_6c8 < 0xe) {
      uVar22 = 0x7fffffffffffffff;
      if (uStack_6c8 <= 0x7fffffffffffffff - (uStack_6c8 >> 1)) {
        uVar2 = uStack_6c8 + (uStack_6c8 >> 1);
        uVar22 = 0xf;
        if (0xf < uVar2) {
          uVar22 = uVar2;
        }
      }
      puVar17 = (undefined8 *)func_0x000180024110(uVar22 + 1);
      uStack_6d0 = 0xe;
      *puVar17 = _DAT_1819d8c38;
      *(undefined4 *)(puVar17 + 1) = _DAT_1819d8c40;
      *(undefined2 *)((longlong)puVar17 + 0xc) = _DAT_1819d8c44;
      *(undefined *)((longlong)puVar17 + 0xe) = 0;
      uStack_6c8 = uVar22;
      if (0xf < uVar24) {
        if ((0xfff < uVar24 + 1) &&
           (0x1f < (auStack_6e0._0_8_ - *(longlong *)(auStack_6e0._0_8_ + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          pauVar19 = (undefined (*) [16])(*pcVar3)();
          return pauVar19;
        }
        func_0x000180127e40();
      }
      auStack_6e0._0_8_ = puVar17;
    }
    else {
      puVar20 = auStack_6e0;
      if (0xf < uStack_6c8) {
        puVar20 = (undefined *)auStack_6e0._0_8_;
      }
      uStack_6d0 = 0xe;
      func_0x0001801ca893(puVar20,&DAT_1819d8c38,0xe);
      puVar20[0xe] = 0;
    }
  }
  else {
    pcVar25 = pcVar23 + uStack_718;
    pcVar15 = (char *)func_0x0001801278a0(pcVar23,pcVar25,&UNK_1819d8c10,10);
    if ((pcVar15 == pcVar25) || ((longlong)pcVar15 - (longlong)pcVar23 == -1)) {
      pcVar25 = (char *)auStack_728._0_8_;
      goto LAB_180096733;
    }
LAB_180096775:
    recovered_1800676d0(auStack_6e0,&UNK_1819d8c20,10);
  }
LAB_18009691b:
  apuStack_638[0] = &UNK_1819d8e48;
  __0__basic_ios_DU__char_traits_D_std___std__IEAA_XZ(auStack_5b0);
  uStack_708 = 0x22;
  __0__basic_ostream_DU__char_traits_D_std___std__QEAA_PEAV__basic_streambuf_DU__char_traits_D_std___1__N_Z
            (apuStack_638,apuStack_638 + 1,0,0);
  *(undefined **)((longlong)apuStack_638 + (longlong)*(int *)(apuStack_638[0] + 4)) = &UNK_180201ff8
  ;
  *(int *)((longlong)&iStack_63c + (longlong)*(int *)(apuStack_638[0] + 4)) =
       *(int *)(apuStack_638[0] + 4) + -0x88;
  __0__basic_streambuf_DU__char_traits_D_std___std__IEAA_XZ(apuStack_638 + 1);
  apuStack_638[1] = &UNK_1801f2638;
  uStack_5c8 = 0;
  uStack_5c0 = 4;
  puVar20 = auStack_6e0;
  if (0xf < uStack_6c8) {
    puVar20 = (undefined *)auStack_6e0._0_8_;
  }
  recovered_180078870(apuStack_638,puVar20,uStack_6d0);
  if (lStack_650 != 0) {
    uVar18 = recovered_180069ac0(apuStack_638,&UNK_1819d8c48);
    pppppppuVar21 = apppppppuStack_660;
    if (0xf < uStack_648) {
      pppppppuVar21 = apppppppuStack_660[0];
    }
    recovered_180078870(uVar18,pppppppuVar21,lStack_650);
  }
  uStack_670 = _DAT_181a03530;
  uStack_668 = _UNK_181a03538;
  auStack_680._1_15_ = SUB1615(ZEXT816(0),1);
  auVar6[15] = 0;
  auVar6._0_15_ = auStack_680._1_15_;
  auStack_680 = auVar6 << 8;
  uStack_708 = 0x2a;
  uStack_6f0 = 0;
  if ((((byte)uStack_5c0 & 0x22) == 2) || (uVar24 = *puStack_5f0, uVar24 == 0)) {
    if (((uStack_5c0 & 4) == 0) && (*plStack_5f8 != 0)) {
      auStack_700 = (undefined  [8])*plStack_618;
      uStack_6f8 = ((longlong)*piStack_5e0 - (longlong)auStack_700) + *plStack_5f8;
    }
    else {
      uStack_6f8 = 0;
      auStack_700 = (undefined  [8])0x0;
    }
  }
  else {
    auStack_700 = (undefined  [8])*plStack_610;
    if (uVar24 < uStack_5c8) {
      uVar24 = uStack_5c8;
    }
    uStack_6f8 = uVar24 - (longlong)auStack_700;
  }
  if (auStack_700 != (undefined  [8])0x0) {
    lVar13 = uStack_6f8;
    _auStack_700 = ZEXT816(0);
    recovered_1800676d0(auStack_680,_DAT_181a03530,lVar13);
  }
  uStack_6f0 = _DAT_181a035b0;
  uStack_6e8 = _UNK_181a035b8;
  uStack_6f8._0_2_ = _DAT_1819d8c58;
  auStack_700 = (undefined  [8])_DAT_1819d8c50;
  uStack_6f8._2_6_ = 0;
  recovered_180079c40(param_1,(undefined)aiStackX_10[0],auStack_700,auStack_680);
  if (0xf < uStack_6e8) {
    if ((0xfff < uStack_6e8 + 1) &&
       (0x1f < ((longlong)auStack_700 - *(longlong *)((longlong)auStack_700 + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      pauVar19 = (undefined (*) [16])(*pcVar3)();
      return pauVar19;
    }
    func_0x000180127e40();
  }
  if (0xf < uStack_668) {
    if ((0xfff < uStack_668 + 1) &&
       (0x1f < (auStack_680._0_8_ - *(longlong *)(auStack_680._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      pauVar19 = (undefined (*) [16])(*pcVar3)();
      return pauVar19;
    }
    func_0x000180127e40();
  }
  *(undefined **)((longlong)apuStack_638 + (longlong)*(int *)(apuStack_638[0] + 4)) = &UNK_180201ff8
  ;
  *(int *)((longlong)&iStack_63c + (longlong)*(int *)(apuStack_638[0] + 4)) =
       *(int *)(apuStack_638[0] + 4) + -0x88;
  apuStack_638[1] = &UNK_1801f2638;
  recovered_1800985e0(apuStack_638 + 1);
  __1__basic_streambuf_DU__char_traits_D_std___std__UEAA_XZ(apuStack_638 + 1);
  __1__basic_ostream_DU__char_traits_D_std___std__UEAA_XZ(auStack_628);
  __1__basic_ios_DU__char_traits_D_std___std__UEAA_XZ(auStack_5b0);
  recovered_180066e40(auStack_728);
  recovered_180066e40(auStack_6e0);
  recovered_180066e40(apppppppuStack_660);
  recovered_180066e40(auStack_6c0);
  recovered_180066e40(auStack_6a0);
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x180096f60 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180096f60(void)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  float fVar9;
  char cVar10;
  undefined auVar11 [16];
  undefined auVar12 [16];
  short sVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  undefined (*pauVar20) [16];
  undefined8 *puVar21;
  longlong *plVar22;
  char *pcVar23;
  char *pcVar24;
  char *pcVar25;
  ulonglong uVar26;
  longlong unaff_GS_OFFSET;
  bool bVar27;
  undefined **ppuStackX_8;
  longlong lStackX_10;
  undefined8 uStackX_18;
  undefined auStackX_20 [8];
  undefined8 in_stack_fffffffffffffd98;
  longlong *plVar28;
  undefined8 *puVar29;
  undefined8 uVar30;
  undefined8 in_stack_fffffffffffffda8;
  undefined auStack_238 [8];
  undefined8 uStack_230;
  longlong lStack_228;
  longlong lStack_220;
  undefined2 uStack_210;
  undefined4 uStack_20c;
  undefined8 uStack_208;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  int iStack_1f0;
  undefined4 uStack_1ec;
  undefined auStack_1e8 [16];
  undefined8 uStack_1d8;
  undefined *puStack_1d0;
  undefined *puStack_1c8;
  undefined uStack_1c0;
  undefined uStack_1bf;
  undefined uStack_1be;
  undefined uStack_1bd;
  longlong *plStack_1b8;
  undefined **ppuStack_198;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined8 uStack_180;
  undefined2 uStack_178;
  undefined uStack_176;
  undefined auStack_170 [16];
  undefined auStack_160 [16];
  undefined auStack_150 [16];
  undefined auStack_140 [8];
  undefined auStack_138 [16];
  undefined auStack_128 [16];
  undefined auStack_118 [16];
  undefined auStack_108 [16];
  undefined auStack_f8 [16];
  undefined auStack_e8 [16];
  undefined auStack_d8 [16];
  undefined8 uStack_c8;
  
  pcVar25 = (char *)0x0;
  lVar17 = GetModuleHandleA(&UNK_1819d8cb0);
  uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
  if (lVar17 != 0) {
    lVar18 = GetProcAddress(lVar17,&UNK_1819d8cc0);
    uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
    if (lVar18 != 0) {
      LOCK();
      bVar27 = _DAT_181b2f2d8 == 0;
      if (bVar27) {
        _DAT_181b2f2d8 = 1;
      }
      UNLOCK();
      pcVar24 = pcVar25;
      while (!bVar27) {
        Sleep((char *)0x1f < pcVar24);
        pcVar24 = pcVar24 + 1;
        LOCK();
        bVar27 = _DAT_181b2f2d8 == 0;
        if (bVar27) {
          _DAT_181b2f2d8 = 1;
        }
        UNLOCK();
      }
      if (_DAT_181b2f2e0 == 0) {
        _DAT_181b2f2e0 = HeapCreate(0,0,0);
      }
      LOCK();
      _DAT_181b2f2d8 = 0;
      UNLOCK();
      iVar14 = recovered_1800954f0(lVar18);
      uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
      if (iVar14 == 0) {
        iVar14 = recovered_1800959f0(lVar18,1);
        uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
        if (iVar14 == 0) {
          while (_DAT_181b4f040 == 0) {
            Sleep(10);
            uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
          }
          _DAT_181b4efa0 = (code *)GetProcAddress(lVar17,&UNK_1819d8cd0);
          if (((_DAT_181b4efa0 != (code *)0x0) &&
              (_DAT_181b4ef78 = GetProcAddress(lVar17,&UNK_1819d8ce0), _DAT_181b4ef78 != 0)) &&
             (_DAT_181b4efa8 = GetProcAddress(lVar17,&UNK_1819d8cf8), _DAT_181b4efa8 != 0)) {
            _DAT_181b4ef90 = _DAT_181b4f040;
            (*_DAT_181b4efa0)(_DAT_181b4f040,0);
            recovered_180069a10(&DAT_181b2bf20);
            uVar19 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                         ,&UNK_1819d8d18);
            uVar19 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_PEBX_Z
                               (uVar19,_DAT_181b4ef90);
            __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                      (uVar19,&DAT_180069ca0);
            DAT_181b2f2bd = '\x01';
            goto LAB_18009715c;
          }
        }
      }
    }
  }
  if (DAT_181b2f2bd == '\0') {
    MessageBoxW(0,&UNK_1819d8d90,&UNK_1819d8d80,0);
  }
LAB_18009715c:
  ppuStackX_8 = (undefined **)func_0x000180127a94(1);
  uVar26 = (ulonglong)uVar16 << 0x20;
  auStack_238 = (undefined  [8])_beginthreadex(0,0,&DAT_1800986d0,ppuStackX_8,uVar26,&uStack_230);
  auVar12 = _auStack_238;
  if (auStack_238 != (undefined  [8])0x0) {
    if ((int)uStack_230 != 0) {
      auStack_238._4_4_ = (undefined4)((ulonglong)auStack_238 >> 0x20);
      uStack_1f8 = auStack_238._0_4_;
      uStack_1f4 = auStack_238._4_4_;
      iStack_1f0 = (int)uStack_230;
      uStack_1ec = uStack_230._4_4_;
      _auStack_238 = auVar12;
      iVar14 = _Thrd_detach(&uStack_1f8);
      auVar12 = _auStack_238;
      if (iVar14 == 0) {
        _auStack_238 = ZEXT816(0);
        ppuStackX_8 = (undefined **)func_0x000180127a94(1);
        puVar29 = &uStack_230;
        lVar17 = _beginthreadex(0,0,&DAT_180098700,ppuStackX_8,uVar26 & 0xffffffff00000000,puVar29);
        auVar12 = _auStack_238;
        auStack_238 = (undefined  [8])lVar17;
        auVar11 = _auStack_238;
        if (lVar17 != 0) {
          uStack_230._0_4_ = auVar12._8_4_;
          if ((int)uStack_230 != 0) {
            auStack_238._0_4_ = (undefined4)lVar17;
            auStack_238._4_4_ = (undefined4)((ulonglong)lVar17 >> 0x20);
            uStack_230._4_4_ = auVar12._12_4_;
            uStack_1f8 = auStack_238._0_4_;
            uStack_1f4 = auStack_238._4_4_;
            iStack_1f0 = (int)uStack_230;
            uStack_1ec = uStack_230._4_4_;
            _auStack_238 = auVar11;
            iVar14 = _Thrd_detach(&uStack_1f8);
            auVar11 = _auStack_238;
            if (iVar14 == 0) {
              _auStack_238 = ZEXT816(0);
              _DAT_181b2f368 = recovered_18009b420();
              if (_DAT_181b2f368 != 0) {
                GetClientRect(_DAT_181b2f368,&DAT_181b2f378);
                MapWindowPoints(_DAT_181b2f368,0,&DAT_181b2f378,2);
                DAT_181b2f2f9 = 1;
              }
              recovered_18009a390();
              if (((DAT_181b2f2fa != '\0') && (DAT_181b2f2fb != '\0')) &&
                 ((DAT_181b2f2f8 != '\0' && ((_DAT_181b2f350 != 0 && (_DAT_181b2f358 != 0)))))) {
                uStack_210 = 0;
                uStack_20c = 0;
                plVar28 = _DAT_181b2f360;
                uVar19 = func_0x0001800b0520(&lStack_228,_DAT_181b2f358,_DAT_181b2f368,
                                             _DAT_181b2f350,_DAT_181b2f360);
                _DAT_181b2f2f0 = &lStack_228;
                puStack_1d0 = &UNK_1819d8e18;
                puStack_1c8 = &DAT_1800b5a10;
                uStack_1c0 = ppuStackX_8._0_1_;
                uStack_1bf = ppuStackX_8._0_1_;
                uStack_1be = ppuStackX_8._0_1_;
                uStack_1bd = ppuStackX_8._0_1_;
                plStack_1b8 = &lStack_228;
                ppuStack_198 = &puStack_1d0;
                ppuStackX_8 = &puStack_1d0;
                recovered_18009acc0(uVar19,&puStack_1d0);
                if (ppuStack_198 != (undefined **)0x0) {
                  (**(code **)(*ppuStack_198 + 0x20))(ppuStack_198,ppuStack_198 != &puStack_1d0);
                  ppuStack_198 = (undefined **)0x0;
                }
                fVar9 = _DAT_181a03454;
                uVar8 = _DAT_181a032cc;
                fVar7 = _DAT_181a032a0;
                fVar6 = _DAT_181a03298;
                uVar5 = _DAT_181a03230;
                fVar4 = _DAT_181a031bc;
                fVar3 = _DAT_181a03134;
                auStack_170 = ZEXT816(0);
                uVar26 = (ulonglong)__tls_index;
                lVar17 = *(longlong *)(unaff_GS_OFFSET + 0x58);
                auStack_160 = auStack_170;
                auStack_150 = auStack_170;
                do {
                  if (_DAT_181b2f358 == 0) {
                    uVar19 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                                 ,&UNK_1819d8dc0);
                    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                              (uVar19,&DAT_180069ca0);
                    break;
                  }
                  plVar28 = (longlong *)CONCAT44((int)((ulonglong)plVar28 >> 0x20),1);
                  iVar14 = PeekMessageA(auStack_170,_DAT_181b2f358,0,0,plVar28);
                  if (iVar14 != 0) {
                    TranslateMessage(auStack_170);
                    DispatchMessageA(auStack_170);
                  }
                  if (_DAT_181b2f2c0 != 0) {
                    *(char *)(_DAT_181b2f2c0 + 0x60) = (char)uStack_210;
                  }
                  if ((uStack_208._4_4_ != 0) || ((int)uStack_208 != 0)) {
                    if (_DAT_181b2f388 != (longlong *)0x0) {
                      (**(code **)(*_DAT_181b2f388 + 0x10))();
                      _DAT_181b2f388 = (longlong *)0x0;
                    }
                    DAT_181b2f2f8 = '\0';
                    if (_DAT_181b2f370 != (longlong *)0x0) {
                      puVar29 = (undefined8 *)((ulonglong)puVar29 & 0xffffffff00000000);
                      plVar28 = (longlong *)((ulonglong)plVar28 & 0xffffffff00000000);
                      (**(code **)(*_DAT_181b2f370 + 0x68))
                                (_DAT_181b2f370,0,uStack_208 & 0xffffffff,uStack_208._4_4_,plVar28,
                                 puVar29);
                      uStack_208 = 0;
                      recovered_18009aa70();
                    }
                  }
                  if ((((lStack_228 != 0) && (iVar14 = IsWindow(), iVar14 != 0)) &&
                      (uStack_208._4_4_ == 0)) && ((int)uStack_208 == 0)) {
                    sVar13 = GetAsyncKeyState(_DAT_181ade1f8);
                    uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffda8 >> 0x20);
                    if (sVar13 < 0) {
                      if (DAT_181b4f0a0 == '\0') {
                        DAT_181b4f0a0 = '\x01';
                        bVar27 = (char)uStack_210 == '\0';
                        uStack_210 = CONCAT11(uStack_210._1_1_,bVar27);
                        if (bVar27) {
                          SetWindowLongPtrA();
                          SetForegroundWindow(lStack_228);
                          if (_DAT_181b2f2c0 != 0) {
                            *(undefined *)(_DAT_181b2f2c0 + 0x60) = 1;
                          }
                        }
                        else {
                          SetWindowLongPtrA(lStack_228,0xffffffec);
                          lVar18 = _DAT_181b2f2c0;
                          if (_DAT_181b2f2c0 != 0) {
                            *(undefined *)(_DAT_181b2f2c0 + 0x60) = 0;
                            *(undefined2 *)(lVar18 + 0xda) = 0;
                            func_0x00018000a180(0,0);
                          }
                          if ((lStack_220 != 0) && (iVar14 = IsWindow(), iVar14 != 0)) {
                            SetForegroundWindow(lStack_220);
                          }
                        }
                        in_stack_fffffffffffffda8 = CONCAT44(uVar15,0x33);
                        puVar29 = (undefined8 *)((ulonglong)puVar29 & 0xffffffff00000000);
                        plVar28 = (longlong *)((ulonglong)plVar28 & 0xffffffff00000000);
                        SetWindowPos(lStack_228,0xffffffffffffffff,0,0,plVar28,puVar29,
                                     in_stack_fffffffffffffda8);
                      }
                    }
                    else {
                      DAT_181b4f0a0 = '\0';
                    }
                  }
                  if ((*(int *)(*(longlong *)(lVar17 + uVar26 * 8) + 4) < _DAT_181b509a8) &&
                     (func_0x000180127a18(&DAT_181b509a8), _DAT_181b509a8 == -1)) {
                    _DAT_181b50998 = ZEXT816(0xf) << 0x40;
                    DAT_181b50988_1 = SUB1615(ZEXT816(0),1);
                    auVar12[15] = 0;
                    auVar12._0_15_ = DAT_181b50988_1;
                    _DAT_181b50988 = auVar12 << 8;
                    func_0x000180127e28(&DAT_1801d0cb0);
                    func_0x0001801279ac(&DAT_181b509a8);
                  }
                  if (DAT_181b4f060 == '\0') {
                    DAT_181b4f060 = '\x01';
                    recovered_180067b80(auStackX_20);
                    pauVar20 = (undefined (*) [16])recovered_1800963a0(&uStack_190,_DAT_181b2f368);
                    if (pauVar20 != (undefined (*) [16])&DAT_181b50988) {
                      if (0xf < _DAT_181b509a0) {
                        if ((0xfff < _DAT_181b509a0 + 1) &&
                           (0x1f < (_DAT_181b50988 - *(longlong *)(_DAT_181b50988 + -8)) - 8U)) {
                          _invoke_watson(0,0,0,0,0);
                          pcVar1 = (code *)swi(3);
                          (*pcVar1)();
                          return;
                        }
                        func_0x000180127e40();
                      }
                      _DAT_181b50988 = *pauVar20;
                      _DAT_181b50998 = pauVar20[1];
                      *(undefined8 *)pauVar20[1] = 0;
                      *(undefined8 *)(pauVar20[1] + 8) = 0xf;
                      (*pauVar20)[0] = 0;
                    }
                    recovered_180066e40(&uStack_190);
                  }
                  recovered_180067b80(&lStackX_10);
                  cVar10 = DAT_181b2f2dc;
                  if ((DAT_181b2f2dc != '\0') && (DAT_181b4f038 == '\0')) {
                    puVar21 = (undefined8 *)recovered_180067b80(auStack_140);
                    _DAT_181b4f050 = *puVar21;
                    DAT_181b4f038 = '\x01';
                  }
                  if (((DAT_181b2f2df == '\0') || (DAT_181b2f2be == '\0')) ||
                     (DAT_181b2f2dd == '\0')) {
                    if (DAT_181b4f061 != '\0') goto LAB_180097789;
                  }
                  else {
                    if (DAT_181b4f061 == '\0') {
                      if (cVar10 != '\0') goto LAB_1800978a3;
                      plVar22 = (longlong *)recovered_180067b80(auStack_138);
                      _DAT_181b4f058 = *plVar22;
                      DAT_181b4f061 = '\x01';
                    }
LAB_180097789:
                    if (((DAT_181b4f048 == '\0') && (cVar10 == '\0')) &&
                       (fVar6 <= (float)(lStackX_10 - _DAT_181b4f058) / fVar9)) {
                      auStack_1e8 = ZEXT816(0);
                      uStack_c8 = 0;
                      uStack_1d8 = 0;
                      auStack_128._4_12_ = auStack_1e8._4_12_;
                      auStack_128._0_4_ = 0x68;
                      auStack_f8._0_12_ = auStack_1e8._0_12_;
                      auStack_f8._12_4_ = 1;
                      auStack_e8._2_14_ = auStack_1e8._2_14_;
                      auVar11._14_2_ = 0;
                      auVar11._0_14_ = auStack_e8._2_14_;
                      auStack_e8 = auVar11 << 0x10;
                      uStack_190 = _DAT_1819d8df0;
                      uStack_18c = _UNK_1819d8df4;
                      uStack_188 = _UNK_1819d8df8;
                      uStack_184 = _UNK_1819d8dfc;
                      uStack_180 = _DAT_1819d8e00;
                      uStack_178 = _DAT_1819d8e08;
                      uStack_176 = DAT_1819d8e0a;
                      in_stack_fffffffffffffda8 = 0;
                      puVar29 = (undefined8 *)CONCAT44((int)((ulonglong)puVar29 >> 0x20),0x8000000);
                      plVar28 = (longlong *)((ulonglong)plVar28 & 0xffffffff00000000);
                      auStack_118 = auStack_1e8;
                      auStack_108 = auStack_1e8;
                      auStack_d8 = auStack_1e8;
                      iVar14 = CreateProcessA(0,&uStack_190,0,0,plVar28,puVar29,0,0,auStack_128,
                                              auStack_1e8);
                      if (iVar14 != 0) {
                        WaitForSingleObject(auStack_1e8._0_8_,3000);
                        CloseHandle(auStack_1e8._0_8_);
                        CloseHandle(auStack_1e8._8_8_);
                      }
                      DAT_181b4f048 = '\x01';
                    }
                  }
LAB_1800978a3:
                  recovered_18009a990();
                  if (DAT_181b2bc70 != DAT_181b4f062) {
                    DAT_181b4f062 = DAT_181b2bc70;
                    uVar15 = 0x20;
                    if (DAT_181b2bc70 != '\0') {
                      uVar15 = 0x4000;
                    }
                    uVar19 = GetCurrentProcess();
                    SetPriorityClass(uVar19,uVar15);
                  }
                  if (((_DAT_181b2bec8 < 1) || (_DAT_181b2becc < 1)) ||
                     (iVar14 = IsIconic(_DAT_181b2f368), iVar14 != 0)) {
                    uStackX_18 = 0x14;
                    recovered_1800693e0(&uStackX_18);
                  }
                  else {
                    if (DAT_181b2bc6d != DAT_181b4f049) {
                      DAT_181b4f049 = DAT_181b2bc6d;
                      SetWindowDisplayAffinity(_DAT_181b2f358,-(DAT_181b2bc6d != '\0') & 0x11);
                    }
                    pcVar24 = pcVar25;
                    if ((_DAT_181b2f2c0 == 0) ||
                       (pcVar24 = *(char **)(_DAT_181b2f2c0 + 0xa0), pcVar24 == (char *)0x0)) {
                      _wassert(&UNK_1819d69d0,&UNK_1819d62f0);
                    }
                    if (*(longlong *)(pcVar24 + 0x48) == 0) {
                      func_0x00018004ff90();
                    }
                    func_0x0001800513f0();
                    if (DAT_181b2bc70 == '\0') {
                      if (_DAT_181b2f2c0 == 0) {
                        _wassert(&UNK_18020e450,&UNK_18020daf0);
                      }
                      *(float *)(_DAT_181b2f2c0 + 0xe18) =
                           *(float *)(_DAT_181b2f2c0 + 0xe18) * fVar7;
                    }
                    func_0x00018000b290();
                    if (_DAT_181b2f2c0 == 0) {
                      _wassert(&UNK_18020e450,&UNK_18020daf0);
                    }
                    fVar2 = *(float *)(_DAT_181b2f2c0 + 0x1c);
                    if (fVar3 <= *(float *)(_DAT_181b2f2c0 + 0x1c)) {
                      fVar2 = fVar3;
                    }
                    *(float *)(_DAT_181b2f2c0 + 0x1c) = fVar2;
                    if (DAT_181b2f2bd != '\0') {
                      recovered_180073f10();
                    }
                    if (DAT_181b2b46c != '\0') {
                      recovered_180082360();
                    }
                    if (DAT_181b2bdd0 != '\0') {
                      recovered_18008d390();
                    }
                    recovered_1800b1990(&lStack_228);
                    lVar18 = _DAT_181b2f2c0;
                    if ((DAT_181b2b5b5 != '\0') && (DAT_181b2bc70 == '\0')) {
                      uStack_1f8 = _DAT_181b2b5cc;
                      uStack_1f4 = uRam0000000181b2b5d0;
                      iStack_1f0 = iRam0000000181b2b5d4;
                      uStack_1ec = uRam0000000181b2b5d8;
                      if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
                        _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
                      }
                      lVar18 = func_0x00018000a880(**(undefined8 **)(lVar18 + 0x4908),0);
                      uVar16 = func_0x000180004f90(&uStack_1f8);
                      ppuStackX_8 = (undefined **)
                                    CONCAT44((float)_DAT_181b2becc * fVar4,
                                             (float)_DAT_181b2bec8 * fVar4);
                      if (((uVar16 & 0xff000000) != 0) && (fVar4 <= _DAT_181b2b410)) {
                        uVar30 = CONCAT44((int)((ulonglong)puVar29 >> 0x20),0x167);
                        uVar19 = CONCAT44((int)((ulonglong)plVar28 >> 0x20),uVar8);
                        func_0x0001800272e0(lVar18,&ppuStackX_8,_DAT_181b2b410 - fVar4,0,uVar19,
                                            uVar30);
                        puVar29 = (undefined8 *)CONCAT44((int)((ulonglong)uVar30 >> 0x20),uVar5);
                        plVar28 = (longlong *)CONCAT44((int)((ulonglong)uVar19 >> 0x20),1);
                        func_0x0001800258f0(lVar18,*(undefined8 *)(lVar18 + 0x80),
                                            *(undefined4 *)(lVar18 + 0x78),uVar16,plVar28,puVar29);
                        *(undefined4 *)(lVar18 + 0x78) = 0;
                      }
                    }
                    func_0x00018000d260();
                    func_0x00018000d750();
                    if ((_DAT_181b2f360 != (longlong *)0x0) && (_DAT_181b2f388 != (longlong *)0x0))
                    {
                      (**(code **)(*_DAT_181b2f360 + 0x108))(_DAT_181b2f360,1,&DAT_181b2f388);
                      (**(code **)(*_DAT_181b2f360 + 400))(_DAT_181b2f360,_DAT_181b2f388);
                    }
                    lVar18 = _DAT_181b2f2c0;
                    if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
                      _wassert(&UNK_180213478,&UNK_18020d8d0);
                    }
                    pcVar23 = (char *)(**(longlong **)(lVar18 + 0x4908) + 0x48);
                    pcVar24 = pcVar25;
                    if (*pcVar23 != '\0') {
                      pcVar24 = pcVar23;
                    }
                    func_0x00018004f320(pcVar24);
                    if (_DAT_181b2f370 != (longlong *)0x0) {
                      (**(code **)(*_DAT_181b2f370 + 0x40))(_DAT_181b2f370,1);
                    }
                    uStackX_18 = 1;
                    recovered_1800693e0(&uStackX_18);
                    if ((cVar10 != '\0') && (DAT_181b4f038 != '\0')) {
                      recovered_180067b80(auStack_238);
                    }
                    if (DAT_181b2bc6c != '\0') {
                      recovered_180099200();
                      if (_DAT_181b2f2f0 != (longlong *)0x0) {
                        func_0x0001800b5a60();
                        _DAT_181b2f2f0 = (longlong *)0x0;
                      }
                      if (_DAT_181b4ef88 != 0) {
                        iVar14 = recovered_1800959f0(_DAT_181b4ef88,0);
                        if (iVar14 != 0) {
                          uVar19 = recovered_180069ac0(
                                                  _cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                                  ,&UNK_1819d8c60);
                          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                                    (uVar19,&DAT_180069ca0);
                        }
                        iVar14 = recovered_1800957d0();
                        if (iVar14 != 0) {
                          uVar19 = recovered_180069ac0(
                                                  _cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                                  ,&UNK_1819d8c88);
                          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                                    (uVar19,&DAT_180069ca0);
                        }
                      }
                      LOCK();
                      bVar27 = _DAT_181b2f2d8 == 0;
                      if (bVar27) {
                        _DAT_181b2f2d8 = 1;
                      }
                      UNLOCK();
                      while (!bVar27) {
                        Sleep((char *)0x1f < pcVar25);
                        pcVar25 = pcVar25 + 1;
                        LOCK();
                        bVar27 = _DAT_181b2f2d8 == 0;
                        if (bVar27) {
                          _DAT_181b2f2d8 = 1;
                        }
                        UNLOCK();
                      }
                      if ((_DAT_181b2f2e0 != 0) &&
                         (iVar14 = recovered_1800953a0(0), puVar29 = _DAT_181b50ee0, iVar14 == 0)) {
                        _DAT_181b50ee0 = (undefined8 *)0x0;
                        while (puVar29 != (undefined8 *)0x0) {
                          puVar21 = (undefined8 *)*puVar29;
                          VirtualFree(puVar29,0,0x8000);
                          puVar29 = puVar21;
                        }
                        HeapFree(_DAT_181b2f2e0,0,_DAT_181b50ed0);
                        HeapDestroy(_DAT_181b2f2e0);
                        _DAT_181b2f2e0 = 0;
                        _DAT_181b50ed0 = 0;
                        _DAT_181b50ed8 = 0;
                      }
                      LOCK();
                      _DAT_181b2f2d8 = 0;
                      UNLOCK();
                      FreeConsole();
                      uVar19 = __acrt_iob_func(1);
                      fclose(uVar19);
                      DAT_181b2f2bf = 1;
                      if (_DAT_181b2f2e8 != 0) {
                        FreeLibraryAndExitThread(_DAT_181b2f2e8,0);
                      }
                      func_0x0001800b5a60(&lStack_228);
                      return;
                    }
                  }
                } while (auStack_170._8_4_ != 0x12);
                func_0x0001800b5a60(&lStack_228);
              }
              return;
            }
          }
          _auStack_238 = auVar11;
          __Throw_Cpp_error_std__YAXH_Z(1);
        }
        uStack_230._0_4_ = 0;
        __Throw_Cpp_error_std__YAXH_Z(6);
        auVar12 = _auStack_238;
      }
    }
    _auStack_238 = auVar12;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_230._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800985e0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800985e0(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  
  if ((*(byte *)(param_1 + 0x70) & 1) != 0) {
    if (**(longlong **)(param_1 + 0x40) == 0) {
      lVar3 = (longlong)**(int **)(param_1 + 0x50) + **(longlong **)(param_1 + 0x38);
    }
    else {
      lVar3 = (longlong)**(int **)(param_1 + 0x58) + **(longlong **)(param_1 + 0x40);
    }
    lVar1 = **(longlong **)(param_1 + 0x18);
    if ((0xfff < (ulonglong)(lVar3 - lVar1)) && (0x1f < (lVar1 - *(longlong *)(lVar1 + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40();
  }
  **(undefined8 **)(param_1 + 0x18) = 0;
  **(undefined8 **)(param_1 + 0x38) = 0;
  **(undefined4 **)(param_1 + 0x50) = 0;
  **(undefined8 **)(param_1 + 0x20) = 0;
  **(undefined8 **)(param_1 + 0x40) = 0;
  **(undefined4 **)(param_1 + 0x58) = 0;
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffffe;
  *(undefined8 *)(param_1 + 0x68) = 0;
  return;
}



/* ===== ANALYSIS FUNCTION 0x180098800 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x000180098af2) */
/* WARNING: Removing unreachable block (ram,0x000180098a82) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180098800(char *param_1)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  int iVar5;
  undefined (*pauVar6) [16];
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined *puVar10;
  longlong lVar11;
  undefined *puVar12;
  undefined8 in_stack_fffffffffffffea8;
  uint uVar13;
  longlong lStack_128;
  undefined *puStack_120;
  undefined auStack_110 [8];
  undefined4 uStack_108;
  undefined uStack_104;
  undefined3 uStack_103;
  undefined8 uStack_100;
  ulonglong uStack_f8;
  undefined auStack_f0 [16];
  undefined auStack_e0 [16];
  undefined auStack_d0 [16];
  undefined auStack_c0 [16];
  undefined auStack_b0 [16];
  undefined8 uStack_a0;
  undefined auStack_98 [16];
  undefined auStack_88 [16];
  undefined auStack_78 [16];
  undefined auStack_68 [16];
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined8 uStack_38;
  
  uVar13 = (uint)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    auStack_b0 = ZEXT816(0);
    uStack_38 = 0;
    uStack_a0 = 0;
    auStack_98._4_12_ = auStack_b0._4_12_;
    auStack_98._0_4_ = 0x68;
    auStack_68._0_12_ = auStack_b0._0_12_;
    auStack_68._12_4_ = 1;
    auStack_58._2_14_ = auStack_b0._2_14_;
    auVar2._14_2_ = 0;
    auVar2._0_14_ = auStack_58._2_14_;
    auStack_58 = auVar2 << 0x10;
    uStack_100 = _DAT_181a035e0;
    uStack_f8 = _UNK_181a035e8;
    uStack_108 = _DAT_1819d8e60;
    auStack_110 = (undefined  [8])_DAT_1819d8e58;
    uStack_104 = DAT_1819d8e64;
    uStack_103 = 0;
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (param_1[lVar11] != '\0');
    auStack_88 = auStack_b0;
    auStack_78 = auStack_b0;
    auStack_48 = auStack_b0;
    pauVar6 = (undefined (*) [16])recovered_180066ec0(auStack_110,param_1);
    auStack_d0 = *pauVar6;
    auStack_c0 = pauVar6[1];
    *(undefined8 *)pauVar6[1] = 0;
    *(undefined8 *)(pauVar6[1] + 8) = 0xf;
    (*pauVar6)[0] = 0;
    pauVar6 = (undefined (*) [16])recovered_180066ec0(auStack_d0,&UNK_1819d8e50,6);
    auStack_f0 = *pauVar6;
    auStack_e0 = pauVar6[1];
    *(undefined8 *)pauVar6[1] = 0;
    *(undefined8 *)(pauVar6[1] + 8) = 0xf;
    (*pauVar6)[0] = 0;
    if (0xf < (ulonglong)auStack_c0._8_8_) {
      if ((0xfff < auStack_c0._8_8_ + 1) &&
         (0x1f < (auStack_d0._0_8_ - *(longlong *)(auStack_d0._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_c0._8_8_ = _UNK_181a03538;
    auStack_c0._0_8_ = _DAT_181a03530;
    auVar3[15] = 0;
    auVar3._0_15_ = auStack_d0._1_15_;
    auStack_d0 = auVar3 << 8;
    if (0xf < uStack_f8) {
      if ((0xfff < uStack_f8 + 1) &&
         (0x1f < ((longlong)auStack_110 - *(longlong *)((longlong)auStack_110 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    uStack_100 = _DAT_181a03530;
    uStack_f8 = _UNK_181a03538;
    auVar4[15] = 0;
    auVar4._0_15_ = stack0xfffffffffffffef1;
    _auStack_110 = auVar4 << 8;
    puVar10 = auStack_f0;
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      puVar10 = (undefined *)auStack_f0._0_8_;
    }
    puVar12 = auStack_f0;
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      puVar12 = (undefined *)auStack_f0._0_8_;
    }
    lStack_128 = 0;
    puStack_120 = (undefined *)0x0;
    puVar10 = puVar10 + (auStack_e0._0_8_ - (longlong)puVar12);
    if (puVar10 != (undefined *)0x0) {
      if ((undefined *)0x7fffffffffffffff < puVar10) goto LAB_180098ca6;
      lStack_128 = func_0x000180024110(puVar10);
      puStack_120 = puVar10 + lStack_128;
      func_0x0001801ca893(lStack_128,puVar12,puVar10);
    }
    lVar11 = (longlong)puStack_120 - lStack_128;
    if (lVar11 == 0x7fffffffffffffff) {
      recovered_18006aad0();
LAB_180098ca6:
      recovered_18006aad0();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar8 = (longlong)puStack_120 - lStack_128;
    uVar9 = 0x7fffffffffffffff;
    if ((uVar8 <= 0x7fffffffffffffff - (uVar8 >> 1)) &&
       (uVar9 = uVar8 + (uVar8 >> 1), uVar9 < lVar11 + 1U)) {
      uVar9 = lVar11 + 1U;
    }
    lVar7 = func_0x000180024110(uVar9);
    *(undefined *)(lVar7 + lVar11) = 0;
    func_0x0001801ca893(lVar7,lStack_128,(longlong)puStack_120 - lStack_128);
    if (lStack_128 != 0) {
      if ((0xfff < (ulonglong)((longlong)puStack_120 - lStack_128)) &&
         (0x1f < (lStack_128 - *(longlong *)(lStack_128 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    iVar5 = CreateProcessA(0,lVar7,0,0,(ulonglong)uVar13 << 0x20,0x8000000,0,0,auStack_98,auStack_b0
                          );
    if (iVar5 != 0) {
      WaitForSingleObject(auStack_b0._0_8_,5000);
      CloseHandle(auStack_b0._0_8_);
      CloseHandle(auStack_b0._8_8_);
    }
    if (lVar7 != 0) {
      if ((0xfff < uVar9) && (0x1f < (lVar7 - *(longlong *)(lVar7 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      if ((0xfff < auStack_e0._8_8_ + 1) &&
         (0x1f < (auStack_f0._0_8_ - *(longlong *)(auStack_f0._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180098ef0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180098ef0(void)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 auStack_908 [2];
  undefined4 uStack_900;
  short asStack_8dc [266];
  undefined4 auStack_6c8 [2];
  undefined4 uStack_6c0;
  short asStack_69c [266];
  undefined4 auStack_488 [2];
  uint uStack_480;
  short asStack_45c [266];
  undefined4 auStack_248 [2];
  undefined4 uStack_240;
  short asStack_21c [266];
  
  uVar6 = 0;
  uVar7 = 0;
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_908[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_908);
    while (uVar4 = uVar6, uVar7 = 0, iVar1 != 0) {
      while (uVar3 = uVar4 + 1, asStack_8dc[uVar4] == *(short *)(&UNK_1819d8e6e + uVar3 * 2)) {
        uVar4 = uVar3;
        uVar7 = uStack_900;
        if (uVar3 == 8) goto LAB_180098f7c;
      }
      iVar1 = Process32NextW(lVar2,auStack_908);
    }
LAB_180098f7c:
    CloseHandle(lVar2);
  }
  lVar2 = OpenProcess(1,0,uVar7);
  if (lVar2 != 0) {
    TerminateProcess(lVar2,0);
    CloseHandle(lVar2);
  }
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_6c8[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_6c8);
    while (uVar4 = uVar6, iVar1 != 0) {
      while (uVar3 = uVar4 + 1, asStack_69c[uVar4] == *(short *)(&UNK_1819d8e6e + uVar3 * 2)) {
        uVar4 = uVar3;
        if (uVar3 == 8) {
          CloseHandle(lVar2);
          func_0x000180099d20(uStack_6c0);
          goto LAB_180099066;
        }
      }
      iVar1 = Process32NextW(lVar2,auStack_6c8);
    }
    CloseHandle(lVar2);
  }
LAB_180099066:
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_488[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_488);
    while (iVar1 != 0) {
      lVar5 = -1;
      do {
        if (asStack_45c[lVar5 + 1] != *(short *)(&UNK_1819d8e82 + lVar5 * 2)) break;
        lVar5 = lVar5 + 2;
        if (lVar5 == 0xb) {
          uVar6 = (ulonglong)uStack_480;
          goto LAB_1800990ff;
        }
      } while (asStack_45c[lVar5] == *(short *)(&UNK_1819d8e80 + lVar5 * 2));
      iVar1 = Process32NextW(lVar2,auStack_488);
    }
LAB_1800990ff:
    CloseHandle(lVar2);
  }
  lVar2 = OpenProcess(1,0,uVar6);
  if (lVar2 != 0) {
    TerminateProcess(lVar2,0);
    CloseHandle(lVar2);
  }
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_248[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_248);
    while (iVar1 != 0) {
      lVar5 = -1;
      do {
        if (asStack_21c[lVar5 + 1] != *(short *)(&UNK_1819d8e82 + lVar5 * 2)) break;
        lVar5 = lVar5 + 2;
        if (lVar5 == 0xb) {
          CloseHandle(lVar2);
          func_0x000180099d20(uStack_240);
          return;
        }
      } while (asStack_21c[lVar5] == *(short *)(&UNK_1819d8e80 + lVar5 * 2));
      iVar1 = Process32NextW(lVar2,auStack_248);
    }
    CloseHandle(lVar2);
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x180099200 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180099200(void)

{
  ulonglong uVar1;
  char *pcVar2;
  short *psVar3;
  code *pcVar4;
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  int iVar8;
  undefined (*pauVar9) [16];
  undefined *puVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined *puVar14;
  ulonglong uVar15;
  undefined *puVar16;
  short **ppsVar17;
  undefined auStack_244 [4];
  undefined4 uStack_240;
  undefined auStack_21c [156];
  undefined8 uStack_180;
  undefined8 uStack_158;
  undefined4 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined *puStack_138;
  undefined *puStack_130;
  undefined auStack_128 [16];
  undefined *puStack_118;
  undefined auStack_110 [8];
  undefined4 uStack_108;
  undefined uStack_104;
  undefined3 uStack_103;
  undefined8 uStack_100;
  ulonglong uStack_f8;
  undefined auStack_f0 [16];
  undefined auStack_e0 [16];
  undefined auStack_d0 [16];
  undefined auStack_c0 [16];
  undefined auStack_b0 [16];
  undefined8 uStack_a0;
  undefined auStack_98 [16];
  undefined auStack_88 [16];
  undefined auStack_78 [16];
  undefined auStack_68 [16];
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined8 uStack_38;
  
  ppsVar17 = (short **)0x181ade2f0;
  do {
    psVar3 = *ppsVar17;
    if (((psVar3 != (short *)0x0) && (*psVar3 != 0)) &&
       (lVar11 = CreateToolhelp32Snapshot(2,0), lVar11 != -1)) {
      func_0x0001801ca899(auStack_244,0,0x234);
      iVar8 = Process32FirstW(lVar11);
      while (iVar8 != 0) {
        iVar8 = _wcsicmp(auStack_21c,psVar3);
        if ((iVar8 == 0) && (lVar12 = OpenProcess(1,0,uStack_240), lVar12 != 0)) {
          TerminateProcess(lVar12,0);
          CloseHandle(lVar12);
        }
        iVar8 = Process32NextW(lVar11);
      }
      CloseHandle(lVar11);
    }
    ppsVar17 = ppsVar17 + 1;
  } while (ppsVar17 != (short **)0x181ade358);
  recovered_180098ef0();
  recovered_180098800(&UNK_1819d9018);
  recovered_180098800(&UNK_1819d9028);
  recovered_180098800(&UNK_1819d9038);
  recovered_180098800(&UNK_1819d9040);
  recovered_180098800(&UNK_1819d9050);
  recovered_180098800(&UNK_1819d9060);
  recovered_180098800(&UNK_1819d9070);
  recovered_180098800(&UNK_1819d9080);
  if (UNK_1819d9098 != '\0') {
    auStack_b0 = ZEXT816(0);
    uStack_38 = 0;
    uStack_a0 = 0;
    auStack_98._4_12_ = auStack_b0._4_12_;
    auStack_98._0_4_ = 0x68;
    auStack_68._0_12_ = auStack_b0._0_12_;
    auStack_68._12_4_ = 1;
    auStack_58._2_14_ = auStack_b0._2_14_;
    auVar5._14_2_ = 0;
    auVar5._0_14_ = auStack_58._2_14_;
    auStack_58 = auVar5 << 0x10;
    uStack_100 = _DAT_181a035e0;
    uStack_f8 = _UNK_181a035e8;
    uStack_108 = _DAT_1819d8e60;
    auStack_110 = (undefined  [8])_DAT_1819d8e58;
    uStack_104 = DAT_1819d8e64;
    uStack_103 = 0;
    lVar11 = -1;
    do {
      pcVar2 = &UNK_1819d9099 + lVar11;
      lVar11 = lVar11 + 1;
    } while (*pcVar2 != '\0');
    uStack_180 = 0x1800988c8;
    auStack_88 = auStack_b0;
    auStack_78 = auStack_b0;
    auStack_48 = auStack_b0;
    pauVar9 = (undefined (*) [16])recovered_180066ec0(auStack_110,&UNK_1819d9098);
    auStack_d0 = *pauVar9;
    auStack_c0 = pauVar9[1];
    *(undefined8 *)pauVar9[1] = 0;
    *(undefined8 *)(pauVar9[1] + 8) = 0xf;
    (*pauVar9)[0] = 0;
    uStack_180 = 0x18009890b;
    pauVar9 = (undefined (*) [16])recovered_180066ec0(auStack_d0,&UNK_1819d8e50,6);
    auStack_f0 = *pauVar9;
    auStack_e0 = pauVar9[1];
    *(undefined8 *)pauVar9[1] = 0;
    *(undefined8 *)(pauVar9[1] + 8) = 0xf;
    (*pauVar9)[0] = 0;
    if (0xf < (ulonglong)auStack_c0._8_8_) {
      if ((0xfff < auStack_c0._8_8_ + 1) &&
         (0x1f < (auStack_d0._0_8_ - *(longlong *)(auStack_d0._0_8_ + -8)) - 8U)) {
        uStack_158 = 0;
        uStack_180 = 0x18009897f;
        _invoke_watson(0,0,0,0);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      uStack_180 = 0x180098985;
      func_0x000180127e40();
    }
    auStack_c0._8_8_ = _UNK_181a03538;
    auStack_c0._0_8_ = _DAT_181a03530;
    auVar6[15] = 0;
    auVar6._0_15_ = auStack_d0._1_15_;
    auStack_d0 = auVar6 << 8;
    if (0xf < uStack_f8) {
      if ((0xfff < uStack_f8 + 1) &&
         (0x1f < ((longlong)auStack_110 - *(longlong *)((longlong)auStack_110 + -8)) - 8U)) {
        uStack_158 = 0;
        uStack_180 = 0x1800989de;
        _invoke_watson(0,0,0,0);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      uStack_180 = 0x1800989e4;
      func_0x000180127e40();
    }
    uStack_100 = _DAT_181a03530;
    uStack_f8 = _UNK_181a03538;
    auVar7[15] = 0;
    auVar7._0_15_ = stack0xfffffffffffffef1;
    _auStack_110 = auVar7 << 8;
    puVar16 = auStack_f0;
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      puVar16 = (undefined *)auStack_f0._0_8_;
    }
    puVar10 = auStack_f0;
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      puVar10 = (undefined *)auStack_f0._0_8_;
    }
    auStack_128._0_8_ = (undefined *)0x0;
    auStack_128._8_8_ = (undefined *)0x0;
    puStack_118 = (undefined *)0x0;
    puVar16 = puVar16 + (auStack_e0._0_8_ - (longlong)puVar10);
    if (puVar16 != (undefined *)0x0) {
      if ((undefined *)0x7fffffffffffffff < puVar16) goto LAB_180098ca6;
      uStack_180 = 0x180098a4b;
      lVar11 = func_0x000180024110(puVar16);
      auStack_128._8_8_ = lVar11;
      auStack_128._0_8_ = lVar11;
      uStack_180 = 0x180098a6c;
      puStack_118 = puVar16 + lVar11;
      func_0x0001801ca893(lVar11,puVar10,puVar16);
      auStack_128._8_8_ = puVar16 + lVar11;
    }
    puVar16 = (undefined *)auStack_128._8_8_;
    if ((undefined *)auStack_128._8_8_ == puStack_118) {
      lVar11 = auStack_128._8_8_ - auStack_128._0_8_;
      if (lVar11 == 0x7fffffffffffffff) {
        uStack_180 = 0x180098ca5;
        recovered_18006aad0();
LAB_180098ca6:
        uStack_180 = 0x180098cab;
        recovered_18006aad0();
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      uVar1 = lVar11 + 1;
      uVar13 = (longlong)puStack_118 - auStack_128._0_8_;
      uVar15 = 0x7fffffffffffffff;
      if ((uVar13 <= 0x7fffffffffffffff - (uVar13 >> 1)) &&
         (uVar15 = uVar13 + (uVar13 >> 1), uVar15 < uVar1)) {
        uVar15 = uVar1;
      }
      uStack_180 = 0x180098ad3;
      puVar10 = (undefined *)func_0x000180024110(uVar15);
      puVar10[lVar11] = 0;
      if (puVar16 == (undefined *)auStack_128._8_8_) {
        lVar12 = auStack_128._8_8_ - auStack_128._0_8_;
        puVar14 = puVar10;
        puVar16 = (undefined *)auStack_128._0_8_;
      }
      else {
        uStack_180 = 0x180098afd;
        func_0x0001801ca893(puVar10,auStack_128._0_8_,(longlong)puVar16 - auStack_128._0_8_);
        lVar12 = auStack_128._8_8_ - (longlong)puVar16;
        puVar14 = puVar10 + lVar11 + 1;
      }
      uStack_180 = 0x180098b14;
      func_0x0001801ca893(puVar14,puVar16,lVar12);
      if ((undefined *)auStack_128._0_8_ != (undefined *)0x0) {
        if ((0xfff < (ulonglong)((longlong)puStack_118 - auStack_128._0_8_)) &&
           ((undefined *)0x1f <
            (undefined *)(auStack_128._0_8_ + (-8 - *(longlong *)(auStack_128._0_8_ + -8))))) {
          uStack_158 = 0;
          uStack_180 = 0x180098b5c;
          _invoke_watson(0,0,0,0);
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        uStack_180 = 0x180098b62;
        func_0x000180127e40();
      }
      auStack_128._8_8_ = puVar10 + uVar1;
      auStack_128._0_8_ = puVar10;
      puStack_118 = puVar10 + uVar15;
    }
    else {
      *(undefined *)auStack_128._8_8_ = 0;
      auStack_128._8_8_ = (undefined *)(auStack_128._8_8_ + 1);
      puVar10 = (undefined *)auStack_128._0_8_;
    }
    puStack_130 = auStack_b0;
    puStack_138 = auStack_98;
    uStack_140 = 0;
    uStack_148 = 0;
    uStack_150 = 0x8000000;
    uStack_158 = (ulonglong)uStack_158._4_4_ << 0x20;
    uStack_180 = 0x180098bb3;
    iVar8 = CreateProcessA(0,puVar10,0,0);
    if (iVar8 != 0) {
      uStack_180 = 0x180098bc6;
      WaitForSingleObject(auStack_b0._0_8_,5000);
      uStack_180 = 0x180098bd0;
      CloseHandle(auStack_b0._0_8_);
      uStack_180 = 0x180098bda;
      CloseHandle(auStack_b0._8_8_);
    }
    if (auStack_128._0_8_ != 0) {
      if ((0xfff < (ulonglong)((longlong)puStack_118 - auStack_128._0_8_)) &&
         (0x1f < (auStack_128._0_8_ - *(longlong *)(auStack_128._0_8_ + -8)) - 8U)) {
        uStack_158 = 0;
        uStack_180 = 0x180098c23;
        _invoke_watson(0,0,0,0);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      uStack_180 = 0x180098c29;
      func_0x000180127e40();
      auStack_128 = ZEXT816(0);
      puStack_118 = (undefined *)0x0;
    }
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      if ((0xfff < auStack_e0._8_8_ + 1) &&
         (0x1f < (auStack_f0._0_8_ - *(longlong *)(auStack_f0._0_8_ + -8)) - 8U)) {
        uStack_158 = 0;
        uStack_180 = 0x180098c7e;
        _invoke_watson(0,0,0,0);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      uStack_180 = 0x180098c84;
      func_0x000180127e40();
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18009a390 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009a390(void)

{
  code *pcVar1;
  ulonglong uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined8 ******ppppppuVar13;
  undefined8 *puVar14;
  longlong lVar15;
  char *pcVar16;
  longlong *plStackX_8;
  undefined4 uStackX_10;
  undefined4 uStackX_14;
  undefined8 in_stack_fffffffffffffed8;
  undefined8 in_stack_fffffffffffffef0;
  undefined4 uVar17;
  undefined auStack_e8 [16];
  undefined auStack_d8 [16];
  undefined8 ******appppppuStack_c8 [2];
  undefined8 uStack_b8;
  ulonglong uStack_b0;
  uint uStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined8 uStack_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined8 uStack_84;
  undefined8 uStack_7c;
  undefined4 uStack_74;
  undefined8 uStack_70;
  longlong lStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  char acStack_34 [12];
  
  if (DAT_181b2f2f9 == '\0') {
    uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819da800);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar7,&DAT_180069ca0);
    return;
  }
  uVar4 = _time64(0);
  srand(uVar4);
  auStack_e8 = ZEXT816(0);
  auStack_d8 = ZEXT816(0);
  puVar8 = (undefined8 *)func_0x000180024110(0x20);
  uVar9 = _UNK_181a035b8;
  auStack_e8._0_8_ = puVar8;
  auStack_d8._0_8_ = _DAT_181a035b0;
  auStack_d8._8_8_ = _UNK_181a035b8;
  *puVar8 = 0;
  puVar8[1] = 0;
  *(undefined4 *)(puVar8 + 2) = 0;
  *(undefined2 *)((longlong)puVar8 + 0x14) = 0;
  puVar14 = (undefined8 *)auStack_e8;
  if (7 < uVar9) {
    puVar14 = puVar8;
  }
  lVar15 = 10;
  do {
    iVar5 = rand();
    uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
    uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
    uVar9 = (ulonglong)iVar5;
    lVar10 = uVar9 + ((uVar9 - uVar9 / 7 >> 1) + uVar9 / 7 >> 2) * -7;
    *(short *)puVar14 = (short)(char)(&UNK_1819da768)[lVar10];
    puVar14 = (undefined8 *)((longlong)puVar14 + 2);
    lVar15 = lVar15 + -1;
  } while (lVar15 != 0);
  puVar11 = auStack_e8;
  if (7 < (ulonglong)auStack_d8._8_8_) {
    puVar11 = (undefined *)auStack_e8._0_8_;
  }
  puVar12 = auStack_e8;
  if (7 < (ulonglong)auStack_d8._8_8_) {
    puVar12 = (undefined *)auStack_e8._0_8_;
  }
  recovered_18009ab00(lVar10,puVar12,puVar11 + auStack_d8._0_8_ * 2);
  _DAT_181b2f340 = &DAT_181ade288;
  if (0xf < _DAT_181ade2a0) {
    _DAT_181b2f340 = _DAT_181ade288;
  }
  UnregisterClassA(_DAT_181b2f340,_DAT_181b2f318);
  _DAT_181b2f300 = 0x50;
  _DAT_181b2f304 = 3;
  _DAT_181b2f308 = &DAT_18009a300;
  _DAT_181b2f310 = 0;
  _DAT_181b2f318 = GetModuleHandleA(0);
  _DAT_181b2f320 = 0;
  _DAT_181b2f328 = LoadCursorA(0,0x7f00);
  _DAT_181b2f330 = CreateSolidBrush(0);
  _DAT_181b2f338 = 0;
  _DAT_181b2f348 = 0;
  sVar3 = RegisterClassExA(&DAT_181b2f300);
  if (sVar3 == 0) {
    uVar6 = GetLastError();
    uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819da840);
    pcVar16 = acStack_34 + 1;
    uVar9 = (ulonglong)uVar6;
    do {
      pcVar16 = pcVar16 + -1;
      uVar2 = uVar9 / 10;
      *pcVar16 = (char)uVar9 + (char)uVar2 * -10 + '0';
      uVar9 = uVar2;
    } while ((int)uVar2 != 0);
    recovered_180078780(appppppuStack_c8,pcVar16,acStack_34 + 1,&plStackX_8);
    ppppppuVar13 = appppppuStack_c8;
    if (0xf < uStack_b0) {
      ppppppuVar13 = appppppuStack_c8[0];
    }
    uVar7 = recovered_180078870(uVar7,ppppppuVar13,uStack_b8);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar7,&DAT_180069ca0);
    recovered_180066e40(appppppuStack_c8);
  }
  else {
    uVar7 = GetModuleHandleA(0);
    _DAT_181b2f358 =
         CreateWindowExA(0x80800a8,_DAT_181b2f340,&UNK_18020df8a,0x90000000,
                         CONCAT44(uVar4,_DAT_181b2f378),_DAT_181b2f37c,
                         _DAT_181b2f380 - _DAT_181b2f378,
                         CONCAT44(uVar17,_DAT_181b2f384 - _DAT_181b2f37c),0,0,uVar7,0);
    if (_DAT_181b2f358 == 0) {
      uVar6 = GetLastError();
      uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                  &UNK_1819da880);
      pcVar16 = acStack_34 + 1;
      uVar9 = (ulonglong)uVar6;
      do {
        pcVar16 = pcVar16 + -1;
        uVar2 = uVar9 / 10;
        *pcVar16 = (char)uVar9 + (char)uVar2 * -10 + '0';
        uVar9 = uVar2;
      } while ((int)uVar2 != 0);
      recovered_180078780(appppppuStack_c8,pcVar16,acStack_34 + 1,&plStackX_8);
      ppppppuVar13 = appppppuStack_c8;
      if (0xf < uStack_b0) {
        ppppppuVar13 = appppppuStack_c8[0];
      }
      uVar7 = recovered_180078870(uVar7,ppppppuVar13,uStack_b8);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar7,&DAT_180069ca0);
      recovered_180066e40(appppppuStack_c8);
    }
    else {
      uStack_a8 = _DAT_181b2f378;
      iStack_a4 = _DAT_181b2f37c;
      iStack_a0 = _DAT_181b2f380 - _DAT_181b2f378;
      iStack_9c = _DAT_181b2f384 - _DAT_181b2f37c;
      DwmExtendFrameIntoClientArea(_DAT_181b2f358,&uStack_a8);
      SetLayeredWindowAttributes(_DAT_181b2f358,0,0xff,2);
      ShowWindow(_DAT_181b2f358,10);
      UpdateWindow(_DAT_181b2f358);
      DAT_181b2f2fa = 1;
      uStack_84 = 0;
      uStack_70 = 2;
      uStack_58 = 2;
      uStack_98 = 0;
      uStack_90 = 0x4b;
      uStack_8c = 1;
      uStack_88 = 0x1c;
      uStack_7c = 1;
      uStack_74 = 0x20;
      lStack_68 = _DAT_181b2f358;
      uStack_60 = 1;
      uStackX_10 = 0xb000;
      uStackX_14 = 0xa000;
      iVar5 = D3D11CreateDeviceAndSwapChain
                        (0,1,0,0,&uStackX_10,2,7,&uStack_98,&DAT_181b2f370,&DAT_181b2f350,
                         &plStackX_8,&DAT_181b2f360);
      pcVar1 = _cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref;
      if (iVar5 == 0) {
        DAT_181b2f2fb = '\x01';
      }
      else {
        uVar6 = GetLastError();
        uVar7 = recovered_180069ac0(pcVar1,&UNK_1819da7b0 + uVar6);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar7,&DAT_180069ca0);
        if (DAT_181b2f2fb == '\0') goto LAB_18009a922;
      }
      if (((_DAT_181b2f370 != (longlong *)0x0) && (_DAT_181b2f350 != (longlong *)0x0)) &&
         (iVar5 = (**(code **)(*_DAT_181b2f370 + 0x48))(_DAT_181b2f370,0,&UNK_1819da758,&plStackX_8)
         , -1 < iVar5)) {
        (**(code **)(*_DAT_181b2f350 + 0x48))(_DAT_181b2f350,plStackX_8,0,&DAT_181b2f388);
        (**(code **)(*plStackX_8 + 0x10))();
        DAT_181b2f2f8 = 1;
        if (_DAT_181b2f360 != (longlong *)0x0) {
          (**(code **)(*_DAT_181b2f360 + 0x108))(_DAT_181b2f360,1,&DAT_181b2f388,0);
        }
      }
    }
  }
LAB_18009a922:
  if (7 < (ulonglong)auStack_d8._8_8_) {
    if ((0xfff < auStack_d8._8_8_ * 2 + 2U) &&
       (0x1f < (auStack_e8._0_8_ - *(longlong *)(auStack_e8._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18009a990 ===== */

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



/* ===== ANALYSIS FUNCTION 0x18009aa70 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009aa70(void)

{
  int iVar1;
  longlong *aplStackX_8 [4];
  
  if ((_DAT_181b2f370 != (longlong *)0x0) && (_DAT_181b2f350 != (longlong *)0x0)) {
    iVar1 = (**(code **)(*_DAT_181b2f370 + 0x48))(_DAT_181b2f370,0,&UNK_1819da758,aplStackX_8);
    if (-1 < iVar1) {
      (**(code **)(*_DAT_181b2f350 + 0x48))(_DAT_181b2f350,aplStackX_8[0],0,&DAT_181b2f388);
      (**(code **)(*aplStackX_8[0] + 0x10))();
      DAT_181b2f2f8 = 1;
      if (_DAT_181b2f360 != (longlong *)0x0) {
        (**(code **)(*_DAT_181b2f360 + 0x108))(_DAT_181b2f360,1,&DAT_181b2f388,0);
      }
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x18009ab00 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * recovered_18009ab00(undefined8 param_1,undefined *param_2,undefined *param_3)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  undefined *puVar13;
  ulonglong uVar14;
  undefined *puVar15;
  longlong lVar16;
  undefined auStack_28 [4];
  undefined4 uStack_24;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  _auStack_28 = ZEXT816(0);
  uStack_10 = 0xf;
  if (param_2 == param_3) {
    uStack_18 = 0;
    auVar2[15] = 0;
    auVar2._0_15_ = stack0xffffffffffffffd9;
    _auStack_28 = auVar2 << 8;
  }
  else {
    uVar14 = (longlong)param_3 - (longlong)param_2 >> 1;
    uStack_18 = 0;
    if (0x7fffffffffffffff < uVar14) {
      func_0x000180052a50();
      pcVar1 = (code *)swi(3);
      puVar13 = (undefined *)(*pcVar1)();
      return puVar13;
    }
    if (uVar14 < 0x10) {
      _auStack_28 = (undefined *)0x0;
      puVar13 = _auStack_28;
    }
    else {
      uVar12 = uVar14 | 0xf;
      if (uVar12 < 0x8000000000000000) {
        if (uVar12 < 0x16) {
          uVar12 = 0x16;
        }
      }
      else {
        uVar12 = 0x7fffffffffffffff;
      }
      puVar13 = (undefined *)func_0x000180024110(uVar12 + 1);
      _auStack_28 = puVar13;
      uStack_10 = uVar12;
    }
    uVar12 = uVar14;
    puVar3 = auStack_28;
    puVar15 = auStack_28;
    if (0xf < uStack_10) {
      puVar3 = puVar13;
      puVar15 = puVar13;
    }
    for (; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar3 = *param_2;
      param_2 = param_2 + 2;
      puVar3 = puVar3 + 1;
    }
    uStack_18 = uVar14;
    puVar15[uVar14] = 0;
  }
  uVar11 = uRam0000000181ade2a4;
  uVar10 = _DAT_181ade2a0;
  uVar9 = uRam0000000181ade29c;
  uVar8 = _DAT_181ade298;
  uVar7 = uRam0000000181ade294;
  uVar6 = uRam0000000181ade290;
  uVar5 = uRam0000000181ade28c;
  uVar4 = _DAT_181ade288;
  if (CONCAT44(uRam0000000181ade2a4,_DAT_181ade2a0) < uStack_10) {
    _DAT_181ade288 = auStack_28;
    uRam0000000181ade28c = uStack_24;
    uRam0000000181ade290 = (undefined4)uStack_20;
    uRam0000000181ade294 = uStack_20._4_4_;
    _DAT_181ade298 = (undefined4)uStack_18;
    uRam0000000181ade29c = uStack_18._4_4_;
    _DAT_181ade2a0 = (undefined4)uStack_10;
    uRam0000000181ade2a4 = uStack_10._4_4_;
    uStack_24 = uVar5;
    auStack_28 = (undefined  [4])uVar4;
    uStack_20._0_4_ = uVar6;
    uStack_20._4_4_ = uVar7;
    uStack_18 = CONCAT44(uVar9,uVar8);
    uStack_10 = CONCAT44(uVar11,uVar10);
    puVar13 = &DAT_181ade288;
  }
  else {
    puVar13 = auStack_28;
    if (0xf < uStack_10) {
      puVar13 = _auStack_28;
    }
    puVar13 = (undefined *)recovered_1800676d0(&DAT_181ade288,puVar13,uStack_18);
  }
  if (0xf < uStack_10) {
    lVar16 = (longlong)_auStack_28;
    if ((0xfff < uStack_10 + 1) &&
       (lVar16 = *(longlong *)((longlong)_auStack_28 + -8),
       0x1f < ((longlong)_auStack_28 - lVar16) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      puVar13 = (undefined *)(*pcVar1)();
      return puVar13;
    }
    func_0x000180127e40(lVar16);
  }
  return puVar13;
}



/* ===== ANALYSIS FUNCTION 0x18009acc0 ===== */

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



/* ===== ANALYSIS FUNCTION 0x18009b020 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 * recovered_18009b020(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined4 auStack_248 [2];
  undefined4 auStack_240 [9];
  short asStack_21c [266];
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  lVar3 = CreateToolhelp32Snapshot(2,0);
  if (lVar3 != -1) {
    auStack_248[0] = 0x238;
    iVar2 = Process32FirstW(lVar3,auStack_248);
    while (iVar2 != 0) {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (asStack_21c[lVar4] != 0);
      puVar5 = param_2;
      if (7 < (ulonglong)param_2[3]) {
        puVar5 = (undefined8 *)*param_2;
      }
      if ((param_2[2] == lVar4) &&
         ((param_2[2] == 0 || (iVar2 = func_0x00018009ae70(puVar5,asStack_21c), iVar2 == 0)))) {
        puVar1 = (undefined4 *)param_1[1];
        if (puVar1 == (undefined4 *)param_1[2]) {
          recovered_18007a050(param_1,puVar1,auStack_240);
        }
        else {
          *puVar1 = auStack_240[0];
          param_1[1] = param_1[1] + 4;
        }
      }
      iVar2 = Process32NextW(lVar3,auStack_248);
    }
    CloseHandle(lVar3);
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x18009b420 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_18009b420(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined4 **ppuVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puStack_68;
  undefined auStack_60 [16];
  undefined auStack_50 [16];
  undefined auStack_40 [16];
  undefined auStack_30 [16];
  undefined auStack_20 [24];
  
  auStack_50 = ZEXT816(0);
  auStack_40 = ZEXT816(0);
  recovered_180079270(auStack_50,&UNK_1819d8ef0,0xe);
  recovered_18009b020(&puStack_68,auStack_50);
  if (7 < (ulonglong)auStack_40._8_8_) {
    if ((0xfff < auStack_40._8_8_ * 2 + 2U) &&
       (0x1f < (auStack_50._0_8_ - *(longlong *)(auStack_50._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    func_0x000180127e40();
  }
  puVar5 = puStack_68;
  puVar6 = (undefined4 *)auStack_60._0_8_;
  if (puStack_68 == (undefined4 *)auStack_60._0_8_) {
    auStack_30 = ZEXT816(0);
    auStack_20._0_16_ = ZEXT816(0);
    recovered_180079270(auStack_30,&UNK_1819d8e98,0xd);
    ppuVar3 = (undefined4 **)recovered_18009b020(auStack_50,auStack_30);
    if (&puStack_68 != ppuVar3) {
      if (puStack_68 != (undefined4 *)0x0) {
        if ((0xfff < (auStack_60._8_8_ - (longlong)puStack_68 & 0xfffffffffffffffcU)) &&
           (0x1f < (ulonglong)((longlong)puStack_68 + (-8 - *(longlong *)(puStack_68 + -2))))) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          uVar2 = (*pcVar1)();
          return uVar2;
        }
        func_0x000180127e40();
      }
      puStack_68 = *ppuVar3;
      auStack_60 = *(undefined (*) [16])(ppuVar3 + 1);
      *ppuVar3 = (undefined4 *)0x0;
      ppuVar3[1] = (undefined4 *)0x0;
      ppuVar3[2] = (undefined4 *)0x0;
    }
    recovered_180079780(auStack_50);
    if (7 < (ulonglong)auStack_20._8_8_) {
      if ((0xfff < auStack_20._8_8_ * 2 + 2U) &&
         (0x1f < (auStack_30._0_8_ - *(longlong *)(auStack_30._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
      func_0x000180127e40();
    }
    puVar5 = puStack_68;
    puVar6 = (undefined4 *)auStack_60._0_8_;
    if (puStack_68 == (undefined4 *)auStack_60._0_8_) {
      uVar2 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                  &UNK_1819da8f0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar2,&DAT_180069ca0);
      uVar2 = 0;
      goto LAB_18009b671;
    }
  }
  do {
    lVar4 = OpenProcess(0x1fffff,0,*puVar5);
    if (lVar4 != 0) {
      EnumWindows(&DAT_18009b3d0);
      CloseHandle(lVar4);
    }
    puVar5 = puVar5 + 1;
    uVar2 = _DAT_181b2f390;
  } while (puVar5 != puVar6);
LAB_18009b671:
  recovered_180079780(&puStack_68);
  return uVar2;
}



/* ===== ANALYSIS FUNCTION 0x18009bbb0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009bbb0(undefined8 param_1,longlong param_2,ulonglong param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined4 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined4 uVar9;
  ulonglong auStackX_18 [2];
  undefined auStack_28 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  _auStack_28 = ZEXT816(0);
  _auStack_18 = ZEXT816(0);
  lVar8 = -1;
  do {
    lVar8 = lVar8 + 1;
  } while (*(char *)(param_2 + lVar8) != '\0');
  auStackX_18[0] = param_3;
  recovered_180066cc0(auStack_28);
  puVar6 = _DAT_181b302b0;
  if (_DAT_181b302b0 == _DAT_181b302b8) {
    uVar9 = func_0x0001800baad0(&DAT_181b302a8,_DAT_181b302b0,auStack_28);
    uVar7 = uStack_10;
  }
  else {
    uVar9 = auStack_28;
    *_DAT_181b302b0 = auStack_28;
    puVar6[1] = uStack_24;
    puVar6[2] = uStack_20;
    puVar6[3] = uStack_1c;
    puVar6[4] = auStack_18._0_4_;
    puVar6[5] = auStack_18._4_4_;
    puVar6[6] = (undefined4)uStack_10;
    puVar6[7] = uStack_10._4_4_;
    auVar4[15] = 0;
    auVar4._0_15_ = stack0xffffffffffffffd9;
    _auStack_28 = auVar4 << 8;
    _DAT_181b302b0 = _DAT_181b302b0 + 8;
    uVar7 = 0xf;
  }
  if (0xf < uVar7) {
    if (0xfff < uVar7 + 1) {
      if (0x1f < (_auStack_28 - *(longlong *)(_auStack_28 + -8)) - 8U) goto LAB_18009bd41;
    }
    uVar9 = func_0x000180127e40();
  }
  puVar6 = _DAT_181b2f698;
  if (_DAT_181b2f698 == _DAT_181b2f6a0) {
    func_0x0001800ba940(uVar9,_DAT_181b2f698,param_4);
  }
  else {
    uVar9 = param_4[1];
    uVar2 = param_4[2];
    uVar3 = param_4[3];
    *_DAT_181b2f698 = *param_4;
    puVar6[1] = uVar9;
    puVar6[2] = uVar2;
    puVar6[3] = uVar3;
    _DAT_181b2f698 = _DAT_181b2f698 + 4;
  }
  _auStack_28 = ZEXT816(0);
  _auStack_18 = ZEXT816(0);
  recovered_180066cc0(auStack_28,&UNK_1819dcb88,3);
  puVar6 = _DAT_181b2f6b0;
  if (_DAT_181b2f6b0 == _DAT_181b2f6b8) {
    uVar9 = func_0x0001800baad0(&DAT_181b2f6a8,_DAT_181b2f6b0,auStack_28);
    uVar7 = uStack_10;
  }
  else {
    uVar9 = auStack_28;
    *_DAT_181b2f6b0 = auStack_28;
    puVar6[1] = uStack_24;
    puVar6[2] = uStack_20;
    puVar6[3] = uStack_1c;
    puVar6[4] = auStack_18._0_4_;
    puVar6[5] = auStack_18._4_4_;
    puVar6[6] = (undefined4)uStack_10;
    puVar6[7] = uStack_10._4_4_;
    auVar5[15] = 0;
    auVar5._0_15_ = stack0xffffffffffffffd9;
    _auStack_28 = auVar5 << 8;
    _DAT_181b2f6b0 = _DAT_181b2f6b0 + 8;
    uVar7 = 0xf;
  }
  if (0xf < uVar7) {
    if (0xfff < uVar7 + 1) {
      if (0x1f < (_auStack_28 - *(longlong *)(_auStack_28 + -8)) - 8U) {
LAB_18009bd41:
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    uVar9 = func_0x000180127e40();
  }
  auStackX_18[0] = auStackX_18[0] & 0xffffffff00000000;
  if (_DAT_181b2f6c8 == _DAT_181b2f6d0) {
    func_0x0001800ba620(uVar9,_DAT_181b2f6c8,auStackX_18);
  }
  else {
    *_DAT_181b2f6c8 = 0;
    _DAT_181b2f6c8 = _DAT_181b2f6c8 + 1;
  }
  auStackX_18[0] = (ulonglong)_DAT_181a034ac;
  if (_DAT_181b2f8b8 != _DAT_181b2f8c0) {
    *_DAT_181b2f8b8 = (ulonglong)_DAT_181a034ac;
    _DAT_181b2f8b8 = _DAT_181b2f8b8 + 1;
    return;
  }
  func_0x0001800ba7b0(_DAT_181a034ac,_DAT_181b2f8b8,auStackX_18);
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800a4920 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800a4920(undefined4 param_1)

{
  code *pcVar1;
  undefined auStack_38 [56];
  
  func_0x0001800a4870(auStack_38,param_1);
  func_0x0001801ca8c3(auStack_38,&UNK_181a249e0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800a8c60 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined * recovered_1800a8c60(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = recovered_1800a8cf0(&UNK_1819d9040);
  if (iVar1 != 0) {
    return &UNK_1819d9040;
  }
  iVar1 = recovered_1800a8cf0(&UNK_1819dbec8);
  if (iVar1 != 0) {
    return &UNK_1819dbec8;
  }
  iVar1 = recovered_1800a8cf0(&UNK_1819dbf78);
  if (iVar1 != 0) {
    return &UNK_1819dbf78;
  }
  iVar1 = recovered_1800a8cf0(&UNK_1819dbfc8);
  if (iVar1 != 0) {
    return &UNK_1819dbfc8;
  }
  puVar2 = (undefined *)recovered_1800a8cf0(&UNK_1819dbe90);
  if ((int)puVar2 != 0) {
    puVar2 = &UNK_1819dbe90;
  }
  return puVar2;
}



/* ===== ANALYSIS FUNCTION 0x1800a8cf0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 recovered_1800a8cf0(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 auStack_458 [2];
  undefined4 uStack_450;
  uint uStack_43c;
  undefined auStack_42c [532];
  undefined auStack_218 [528];
  
  if (param_1 == 0) {
    return 0;
  }
  MultiByteToWideChar(0xfde9,0,param_1,0xffffffff,auStack_218,0x104);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = CreateToolhelp32Snapshot(2,0);
  auStack_458[0] = 0x238;
  Process32FirstW(uVar2,auStack_458);
  do {
    iVar1 = _wcsicmp(auStack_42c,auStack_218);
    if ((iVar1 == 0) && (uVar3 < uStack_43c)) {
      uVar3 = uStack_43c;
      uVar4 = uStack_450;
    }
    iVar1 = Process32NextW(uVar2,auStack_458);
  } while (iVar1 != 0);
  return uVar4;
}



/* ===== ANALYSIS FUNCTION 0x1800a8dd0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800a8dd0(undefined8 param_1,longlong **param_2)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  longlong **pplVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined8 uStackX_8;
  undefined4 auStackX_18 [2];
  longlong lStackX_20;
  undefined auStack_d8 [16];
  undefined auStack_c8 [16];
  longlong lStack_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined auStack_90 [16];
  undefined auStack_80 [16];
  undefined auStack_70 [8];
  undefined8 uStack_68;
  undefined8 uStack_60;
  
  uStackX_8 = param_1;
  recovered_180069a10(0x181b2f740);
  recovered_180069a10(0x181b2f780);
  recovered_180069a10(0x181b2f7c0);
  recovered_180069a10(0x181b2f800);
  if (_DAT_181b2f880 != _DAT_181b2f888) {
    _DAT_181b2f888 = _DAT_181b2f880;
  }
  GetSystemInfo(auStack_70);
  uStackX_8 = uStack_60;
  uVar4 = recovered_1800a8c60();
  iVar3 = recovered_1800a8cf0(uVar4);
  if ((iVar3 == 0) ||
     (_DAT_181b2f6e0 = iVar3, _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar3), _DAT_181b2f6e8 == 0))
  {
    puVar9 = &UNK_1819dc778;
  }
  else {
    plVar7 = param_2[2];
    if (0x7fffffffffffffffU - (longlong)plVar7 < 7) {
      func_0x000180052a50();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    pplVar6 = param_2;
    if ((longlong *)0xf < param_2[3]) {
      pplVar6 = (longlong **)*param_2;
    }
    auStack_d8 = ZEXT816(0);
    auStack_c8 = ZEXT816(0);
    uVar11 = (longlong)plVar7 + 7;
    uVar10 = 0xf;
    puVar5 = (undefined4 *)auStack_d8;
    if (0xf < uVar11) {
      uVar10 = uVar11 | 0xf;
      if (uVar10 < 0x8000000000000000) {
        if (uVar10 < 0x16) {
          uVar10 = 0x16;
        }
      }
      else {
        uVar10 = 0x7fffffffffffffff;
      }
      puVar5 = (undefined4 *)func_0x000180024110(uVar10 + 1);
      auStack_d8._0_8_ = puVar5;
    }
    auStack_c8._8_8_ = uVar10;
    auStack_c8._0_8_ = uVar11;
    *puVar5 = _DAT_1819dc7a8;
    *(undefined2 *)(puVar5 + 1) = _DAT_1819dc7ac;
    *(undefined *)((longlong)puVar5 + 6) = DAT_1819dc7ae;
    func_0x0001801ca88d((longlong)puVar5 + 7,pplVar6,plVar7);
    *(undefined *)((longlong)puVar5 + uVar11) = 0;
    puVar5 = (undefined4 *)recovered_180066ec0(auStack_d8,&UNK_1819dc768,0xc);
    uStack_b0 = *puVar5;
    uStack_ac = puVar5[1];
    uStack_a8 = puVar5[2];
    uStack_a4 = puVar5[3];
    uStack_a0 = puVar5[4];
    uStack_9c = puVar5[5];
    uStack_98 = puVar5[6];
    uStack_94 = puVar5[7];
    uVar11 = 0;
    *(undefined8 *)(puVar5 + 4) = 0;
    *(undefined8 *)(puVar5 + 6) = 0xf;
    *(undefined *)puVar5 = 0;
    uVar12 = recovered_1800785e0(&DAT_181ade2c0,&uStack_b0);
    if (0xf < CONCAT44(uStack_94,uStack_98)) {
      if ((0xfff < CONCAT44(uStack_94,uStack_98) + 1) &&
         (0x1f < (CONCAT44(uStack_ac,uStack_b0) - *(longlong *)(CONCAT44(uStack_ac,uStack_b0) + -8))
                 - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar12 = func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_c8._8_8_) {
      if ((0xfff < auStack_c8._8_8_ + 1) &&
         (0x1f < (auStack_d8._0_8_ - *(longlong *)(auStack_d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar12 = func_0x000180127e40();
    }
    if (DAT_181ade204 == '\0') {
      recovered_1800a9bf0(uVar12,uStack_68,uStackX_8,_DAT_181b2f898,&DAT_181b2f880);
    }
    else {
      recovered_1800a9510();
    }
    if (_DAT_181b2f880 != _DAT_181b2f888) {
      if (_DAT_181b2f888 - _DAT_181b2f880 >> 3 != 0) {
        do {
          plVar7 = param_2[2];
          plVar1 = param_2[3];
          pplVar6 = param_2;
          if ((longlong *)0xf < plVar1) {
            pplVar6 = (longlong **)*param_2;
          }
          if ((plVar7 == (longlong *)0x8) && (*pplVar6 == (longlong *)0x6b63654e7466654c)) {
            lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x188;
            lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
          }
          else {
            pplVar6 = param_2;
            if ((longlong *)0xf < plVar1) {
              pplVar6 = (longlong **)*param_2;
            }
            if (plVar7 == (longlong *)0x9) {
              lVar8 = (longlong)*pplVar6 + -0x63654e7468676952;
              if (lVar8 == 0) {
                lVar8 = (ulonglong)*(byte *)(pplVar6 + 1) - 0x6b;
              }
              if (lVar8 == 0) {
                lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x184;
                lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
                goto LAB_1800a9203;
              }
            }
            pplVar6 = param_2;
            if ((longlong *)0xf < plVar1) {
              pplVar6 = (longlong **)*param_2;
            }
            if (plVar7 == (longlong *)0xc) {
              lVar8 = (longlong)*pplVar6 + -0x756f68537466654c;
              if (lVar8 == 0) {
                lVar8 = (ulonglong)*(uint *)(pplVar6 + 1) - 0x7265646c;
              }
              if (lVar8 == 0) {
                lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x194;
                lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
                goto LAB_1800a9203;
              }
            }
            pplVar6 = param_2;
            if ((longlong *)0xf < plVar1) {
              pplVar6 = (longlong **)*param_2;
            }
            if (plVar7 == (longlong *)0xd) {
              lVar8 = (longlong)*pplVar6 + -0x6f68537468676952;
              if ((lVar8 == 0) &&
                 (lVar8 = (ulonglong)*(uint *)(pplVar6 + 1) - 0x65646c75, lVar8 == 0)) {
                lVar8 = (ulonglong)*(byte *)((longlong)pplVar6 + 0xc) - 0x72;
              }
              if (lVar8 == 0) {
                lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x198;
                lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
                goto LAB_1800a9203;
              }
            }
            lStackX_20 = *(longlong *)(uVar11 * 8 + _DAT_181b2f880) + 0xb6;
            lStack_b8 = *(longlong *)(uVar11 * 8 + _DAT_181b2f880) + 0xb2;
          }
LAB_1800a9203:
          iVar3 = ReadProcessMemory(_DAT_181b2f6e8,lStack_b8,auStackX_18,4,0);
          uVar12 = auStackX_18[0];
          if (iVar3 == 0) {
            uVar4 = 0x23;
            puVar9 = &UNK_1819dc7b0;
            goto LAB_1800a94db;
          }
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f740,auStack_90,&lStack_b8);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          iVar3 = ReadProcessMemory(_DAT_181b2f6e8,lStackX_20,&uStackX_8,4,0);
          if (iVar3 == 0) {
            uVar4 = 0x24;
            puVar9 = &UNK_1819dc800;
            goto LAB_1800a94db;
          }
          uVar12 = (undefined4)uStackX_8;
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f780,auStack_80,&lStackX_20);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          iVar3 = WriteProcessMemory(_DAT_181b2f6e8,lStack_b8,&uStackX_8,4,0);
          if (iVar3 == 0) {
            uVar4 = 0x24;
            puVar9 = &UNK_1819dc7d8;
            goto LAB_1800a94db;
          }
          uVar12 = (undefined4)uStackX_8;
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f7c0,&uStack_b0,&lStack_b8);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          iVar3 = WriteProcessMemory(_DAT_181b2f6e8,lStackX_20,auStackX_18,4,0);
          uVar12 = auStackX_18[0];
          if (iVar3 == 0) {
            uVar4 = 0x25;
            puVar9 = &UNK_1819dc848;
            goto LAB_1800a94db;
          }
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f800,auStack_d8,&lStackX_20);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          uVar11 = uVar11 + 1;
        } while (uVar11 < (ulonglong)(_DAT_181b2f888 - _DAT_181b2f880 >> 3));
      }
      plVar7 = param_2[2];
      if (0x7fffffffffffffffU - (longlong)plVar7 < 7) {
        func_0x000180052a50();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      if ((longlong *)0xf < param_2[3]) {
        param_2 = (longlong **)*param_2;
      }
      auStack_d8 = ZEXT816(0);
      auStack_c8 = ZEXT816(0);
      uVar11 = (longlong)plVar7 + 7;
      uVar10 = 0xf;
      puVar5 = (undefined4 *)auStack_d8;
      if (0xf < uVar11) {
        uVar10 = uVar11 | 0xf;
        if (uVar10 < 0x8000000000000000) {
          if (uVar10 < 0x16) {
            uVar10 = 0x16;
          }
        }
        else {
          uVar10 = 0x7fffffffffffffff;
        }
        puVar5 = (undefined4 *)func_0x000180024110(uVar10 + 1);
        auStack_d8._0_8_ = puVar5;
      }
      auStack_c8._8_8_ = uVar10;
      auStack_c8._0_8_ = uVar11;
      *puVar5 = _DAT_1819dc7a8;
      *(undefined2 *)(puVar5 + 1) = _DAT_1819dc7ac;
      *(undefined *)((longlong)puVar5 + 6) = DAT_1819dc7ae;
      func_0x0001801ca88d((longlong)puVar5 + 7,param_2,plVar7);
      *(undefined *)((longlong)puVar5 + uVar11) = 0;
      puVar5 = (undefined4 *)recovered_180066ec0(auStack_d8,&UNK_1819dc828,0x18);
      uStack_b0 = *puVar5;
      uStack_ac = puVar5[1];
      uStack_a8 = puVar5[2];
      uStack_a4 = puVar5[3];
      uStack_a0 = puVar5[4];
      uStack_9c = puVar5[5];
      uStack_98 = puVar5[6];
      uStack_94 = puVar5[7];
      *(undefined8 *)(puVar5 + 4) = 0;
      *(undefined8 *)(puVar5 + 6) = 0xf;
      *(undefined *)puVar5 = 0;
      recovered_1800785e0(&DAT_181ade2c0,&uStack_b0);
      if (0xf < CONCAT44(uStack_94,uStack_98)) {
        if ((0xfff < CONCAT44(uStack_94,uStack_98) + 1) &&
           (0x1f < (CONCAT44(uStack_ac,uStack_b0) -
                   *(longlong *)(CONCAT44(uStack_ac,uStack_b0) + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        func_0x000180127e40();
      }
      recovered_180066e40(auStack_d8);
      return;
    }
    puVar9 = &UNK_1819dc790;
  }
  uVar4 = 0x12;
LAB_1800a94db:
  recovered_1800676d0(&DAT_181ade2c0,puVar9,uVar4);
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800a9510 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x0001800a9683) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
recovered_1800a9510(undefined8 param_1,undefined *param_2,undefined *param_3,undefined8 param_4,
                   undefined8 param_5)

{
  ulonglong uVar1;
  longlong **pplVar2;
  int iVar3;
  longlong *plVar4;
  longlong **pplVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  longlong **pplVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  longlong **pplVar13;
  ulonglong uVar14;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_20;
  undefined auStack_198 [16];
  undefined4 *puStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined auStack_170 [16];
  longlong **pplStack_160;
  longlong **pplStack_158;
  undefined8 *puStack_150;
  undefined8 *puStack_148;
  undefined4 *puStack_140;
  undefined8 uStack_138;
  longlong **applStack_130 [3];
  longlong lStack_118;
  int iStack_110;
  uint uStack_10c;
  undefined4 auStack_f8 [2];
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined auStack_e0 [16];
  undefined auStack_d0 [16];
  undefined auStack_c0 [16];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  
  uStackX_8 = param_1;
  uStackX_20 = param_4;
  uStackX_8 = _msize(param_4);
  auStack_198 = ZEXT816(0);
  puStack_188 = (undefined4 *)0x0;
  lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,applStack_130,0x30);
  while( true ) {
    if (lVar7 == 0) break;
    if (param_3 <= param_2) break;
    if (((iStack_110 == 0x1000) && ((uStack_10c >> 8 & 1) == 0)) && (uStack_10c != 1)) {
      uStack_180 = applStack_130[0];
      uStack_178 = lStack_118;
      if ((undefined4 *)auStack_198._8_8_ == puStack_188) {
        lVar7 = (longlong)(auStack_198._8_8_ - auStack_198._0_8_) >> 4;
        if (lVar7 == 0xfffffffffffffff) {
          recovered_18006aad0();
          goto LAB_1800a9a7c;
        }
        uVar1 = lVar7 + 1;
        uVar11 = (longlong)puStack_188 - auStack_198._0_8_ >> 4;
        if (0xfffffffffffffff - (uVar11 >> 1) < uVar11) {
          uVar14 = 0xfffffffffffffff;
        }
        else {
          uVar11 = uVar11 + (uVar11 >> 1);
          uVar14 = uVar1;
          if (uVar1 <= uVar11) {
            uVar14 = uVar11;
          }
          if (0xfffffffffffffff < uVar14) goto LAB_1800a9a70;
        }
        lVar8 = func_0x000180024110(uVar14 * 0x10);
        puVar12 = (undefined4 *)(lVar7 * 0x10 + lVar8);
        *puVar12 = (undefined4)uStack_180;
        puVar12[1] = uStack_180._4_4_;
        puVar12[2] = (undefined4)uStack_178;
        puVar12[3] = uStack_178._4_4_;
        func_0x0001801ca893(lVar8,auStack_198._0_8_,auStack_198._8_8_ - auStack_198._0_8_);
        if ((undefined4 *)auStack_198._0_8_ != (undefined4 *)0x0) {
          if ((0xfff < ((longlong)puStack_188 - auStack_198._0_8_ & 0xfffffffffffffff0U)) &&
             (0x1f < (ulonglong)(auStack_198._0_8_ + (-8 - *(longlong *)(auStack_198._0_8_ + -8)))))
          goto LAB_1800a99af;
          func_0x000180127e40();
        }
        auStack_198._8_8_ = uVar1 * 0x10 + lVar8;
        auStack_198._0_8_ = lVar8;
        puStack_188 = (undefined4 *)(lVar8 + uVar14 * 0x10);
      }
      else {
        uStack_180._0_4_ = SUB84(applStack_130[0],0);
        uStack_180._4_4_ = (undefined4)((ulonglong)applStack_130[0] >> 0x20);
        uStack_178._0_4_ = (undefined4)lStack_118;
        uStack_178._4_4_ = (undefined4)((ulonglong)lStack_118 >> 0x20);
        *(undefined4 *)auStack_198._8_8_ = (undefined4)uStack_180;
        *(undefined4 *)(auStack_198._8_8_ + 4) = uStack_180._4_4_;
        *(undefined4 *)(auStack_198._8_8_ + 8) = (undefined4)uStack_178;
        *(undefined4 *)(auStack_198._8_8_ + 0xc) = uStack_178._4_4_;
        auStack_198._8_8_ = (undefined4 *)(auStack_198._8_8_ + 0x10);
      }
    }
    param_2 = (undefined *)(lStack_118 + (longlong)applStack_130[0]);
    lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,applStack_130,0x30);
  }
  auStack_e0 = ZEXT816(0);
  auStack_d0 = ZEXT816(0);
  auStack_c0 = ZEXT816(0);
  uStack_f0 = 0;
  uStack_e8 = 0;
  uStack_b0 = 0xffffffff;
  auStack_f8[0] = 2;
  uStack_ac = 0;
  pplStack_158 = (longlong **)&DAT_181b2f6e0;
  auStack_170 = ZEXT816(0);
  pplStack_160 = (longlong **)0x0;
  puStack_150 = &uStackX_20;
  puStack_148 = &uStackX_8;
  puStack_140 = auStack_f8;
  uStack_138 = param_5;
  puVar12 = (undefined4 *)auStack_198._0_8_;
  do {
    if (puVar12 == (undefined4 *)auStack_198._8_8_) {
      pplVar9 = (longlong **)auStack_170._8_8_;
      pplVar13 = (longlong **)auStack_170._0_8_;
      if (auStack_170._0_8_ != auStack_170._8_8_) {
        do {
          pplVar5 = (longlong **)*pplVar13;
          *pplVar13 = (longlong *)0x0;
          uStack_178 = CONCAT71(uStack_178._1_7_,1);
          uStack_180 = pplVar5;
          if ((pplVar5 == (longlong **)0x0) || (*(char *)(pplVar5 + 0x17) != '\0')) {
            recovered_1800a4920(4);
LAB_1800a9a70:
            func_0x000180003980();
            pcVar6 = (code *)swi(3);
            uVar10 = (*pcVar6)();
            return uVar10;
          }
          (*(code *)(*pplVar5)[2])(pplVar5,1);
          LOCK();
          pplVar2 = pplVar5 + 1;
          iVar3 = *(int *)pplVar2;
          *(int *)pplVar2 = *(int *)pplVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            plVar4 = pplVar5[0x19];
            if (plVar4 == (longlong *)0x0) {
              (*(code *)**pplVar5)(pplVar5,1);
            }
            else {
              (**(code **)*plVar4)(plVar4,pplVar5);
            }
          }
          pplVar13 = pplVar13 + 2;
        } while (pplVar13 != pplVar9);
      }
      if ((longlong **)auStack_170._0_8_ != (longlong **)0x0) {
        func_0x0001800bad80(auStack_170._0_8_,auStack_170._8_8_);
        if ((0xfff < ((longlong)pplStack_160 - auStack_170._0_8_ & 0xfffffffffffffff0U)) &&
           (0x1f < (auStack_170._0_8_ - *(longlong *)(auStack_170._0_8_ + -8)) - 8U)) {
LAB_1800a99af:
          _invoke_watson(0,0,0,0,0);
          pcVar6 = (code *)swi(3);
          uVar10 = (*pcVar6)();
          return uVar10;
        }
        func_0x000180127e40();
        auStack_170 = ZEXT816(0);
        pplStack_160 = (longlong **)0x0;
      }
      if ((undefined4 *)auStack_198._0_8_ != (undefined4 *)0x0) {
        puVar12 = (undefined4 *)auStack_198._0_8_;
        if ((0xfff < ((longlong)puStack_188 - auStack_198._0_8_ & 0xfffffffffffffff0U)) &&
           (puVar12 = *(undefined4 **)(auStack_198._0_8_ + -8),
           0x1f < (ulonglong)(auStack_198._0_8_ + (-8 - (longlong)puVar12)))) {
          _invoke_watson(0,0,0,0,0);
          pcVar6 = (code *)swi(3);
          uVar10 = (*pcVar6)();
          return uVar10;
        }
        func_0x000180127e40(puVar12);
      }
      return 1;
    }
    uStack_a8 = *puVar12;
    uStack_a4 = puVar12[1];
    uStack_a0 = puVar12[2];
    uStack_9c = puVar12[3];
    uStack_98 = 0x81b2f6e0;
    uStack_94 = 1;
    uStack_78 = param_5;
    uStack_88 = &uStackX_8;
    uStack_80 = auStack_f8;
    uStack_90 = &uStackX_20;
    uStackX_10 = func_0x000180127a94(0x120);
    pplVar9 = (longlong **)func_0x0001800b9940(uStackX_10,&uStack_a8);
    puStack_150 = (undefined8 *)((ulonglong)puStack_150 & 0xffffffffffffff00);
    puStack_148 = (undefined8 *)((ulonglong)puStack_148 & 0xffffffffffffff00);
    pplStack_158 = pplVar9;
    if (pplVar9 == (longlong **)0x0) {
LAB_1800a9a7c:
      recovered_1800a4920(4);
      pcVar6 = (code *)swi(3);
      uVar10 = (*pcVar6)();
      return uVar10;
    }
    uStack_178 = CONCAT71(uStack_178._1_7_,1);
    LOCK();
    *(int *)(pplVar9 + 1) = *(int *)(pplVar9 + 1) + 1;
    UNLOCK();
    LOCK();
    pplVar13 = pplVar9 + 1;
    iVar3 = *(int *)pplVar13;
    *(int *)pplVar13 = *(int *)pplVar13 + -1;
    UNLOCK();
    uStack_180 = pplVar9;
    if (iVar3 == 1) {
      plVar4 = pplVar9[0x19];
      if (plVar4 == (longlong *)0x0) {
        (*(code *)**pplVar9)(pplVar9,1);
      }
      else {
        (**(code **)*plVar4)(plVar4,pplVar9);
      }
    }
    if ((longlong **)auStack_170._8_8_ == pplStack_160) {
      func_0x0001800b9e30(auStack_170,auStack_170._8_8_,&uStack_180);
      pplVar9 = uStack_180;
    }
    else {
      *(longlong ***)auStack_170._8_8_ = pplVar9;
      *(undefined *)(auStack_170._8_8_ + 8) = 1;
      auStack_170._8_8_ = (longlong **)(auStack_170._8_8_ + 0x10);
      pplVar9 = (longlong **)0x0;
    }
    if (pplVar9 != (longlong **)0x0) {
      LOCK();
      pplVar13 = pplVar9 + 1;
      iVar3 = *(int *)pplVar13;
      *(int *)pplVar13 = *(int *)pplVar13 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        plVar4 = pplVar9[0x19];
        if (plVar4 == (longlong *)0x0) {
          (*(code *)**pplVar9)(pplVar9,1);
        }
        else {
          (**(code **)*plVar4)(plVar4,pplVar9);
        }
      }
    }
    puVar12 = puVar12 + 4;
  } while( true );
}



/* ===== ANALYSIS FUNCTION 0x1800a9bf0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x0001800a9dcf) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
recovered_1800a9bf0(ulonglong param_1,ulonglong param_2,ulonglong param_3,char *param_4,
                   undefined8 param_5)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  char *pcVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  ulonglong uStackX_8;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined auStack_98 [16];
  undefined8 *puStack_88;
  longlong alStack_80 [2];
  uint uStack_70;
  longlong lStack_68;
  int iStack_60;
  uint uStack_5c;
  
  uStackX_8 = param_1;
  uVar5 = recovered_1800a8c60();
  iVar4 = recovered_1800a8cf0(uVar5);
  if ((iVar4 == 0) ||
     (_DAT_181b2f6e0 = iVar4, _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar4), _DAT_181b2f6e8 == 0))
  {
    uVar5 = 0;
  }
  else {
    uVar5 = recovered_1800a8c60();
    iVar4 = recovered_1800a8cf0(uVar5);
    if (iVar4 != 0) {
      _DAT_181b2f6e0 = iVar4;
      _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar4);
    }
    auStack_98 = ZEXT816(0);
    puStack_88 = (undefined8 *)0x0;
    lStack_68 = 0x1000;
    uVar6 = _msize(param_4);
    lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,alStack_80,0x30);
    while( true ) {
      puVar13 = (undefined8 *)auStack_98._0_8_;
      if (((lVar7 == 0) || (param_3 <= param_2)) || (param_2 + lStack_68 <= param_2)) break;
      if ((((iStack_60 == 0x1000) && ((uStack_5c >> 8 & 1) == 0)) && (uStack_5c != 1)) &&
         ((uStack_70 & 0x200) == 0)) {
        uStack_a8 = (undefined4)alStack_80[0];
        uStack_a4 = (undefined4)((ulonglong)alStack_80[0] >> 0x20);
        uStack_a0 = (undefined4)lStack_68;
        uStack_9c = (undefined4)((ulonglong)lStack_68 >> 0x20);
        if ((undefined8 *)auStack_98._8_8_ == puStack_88) {
          lVar7 = (longlong)(auStack_98._8_8_ - auStack_98._0_8_) >> 4;
          if (lVar7 == 0xfffffffffffffff) {
            recovered_18006aad0();
LAB_1800aa073:
            func_0x000180003980();
            pcVar2 = (code *)swi(3);
            uVar5 = (*pcVar2)();
            return uVar5;
          }
          uVar11 = lVar7 + 1;
          uVar9 = (longlong)puStack_88 - auStack_98._0_8_ >> 4;
          if (0xfffffffffffffff - (uVar9 >> 1) < uVar9) {
            uVar12 = 0xfffffffffffffff;
          }
          else {
            uVar9 = (uVar9 >> 1) + uVar9;
            uVar12 = uVar11;
            if (uVar11 <= uVar9) {
              uVar12 = uVar9;
            }
            if (0xfffffffffffffff < uVar12) goto LAB_1800aa073;
          }
          lVar10 = func_0x000180024110(uVar12 * 0x10);
          puVar1 = (undefined4 *)(lVar7 * 0x10 + lVar10);
          *puVar1 = uStack_a8;
          puVar1[1] = uStack_a4;
          puVar1[2] = uStack_a0;
          puVar1[3] = uStack_9c;
          func_0x0001801ca893(lVar10,auStack_98._0_8_,auStack_98._8_8_ - auStack_98._0_8_);
          if ((undefined8 *)auStack_98._0_8_ != (undefined8 *)0x0) {
            if ((0xfff < ((longlong)puStack_88 - auStack_98._0_8_ & 0xfffffffffffffff0U)) &&
               (0x1f < (ulonglong)(auStack_98._0_8_ + (-8 - *(longlong *)(auStack_98._0_8_ + -8)))))
            {
              _invoke_watson(0,0,0,0,0);
              pcVar2 = (code *)swi(3);
              uVar5 = (*pcVar2)();
              return uVar5;
            }
            func_0x000180127e40();
          }
          auStack_98._8_8_ = uVar11 * 0x10 + lVar10;
          auStack_98._0_8_ = lVar10;
          puStack_88 = (undefined8 *)(uVar12 * 0x10 + lVar10);
        }
        else {
          *(undefined4 *)auStack_98._8_8_ = uStack_a8;
          *(undefined4 *)(auStack_98._8_8_ + 4) = uStack_a4;
          *(undefined4 *)(auStack_98._8_8_ + 8) = uStack_a0;
          *(undefined4 *)(auStack_98._8_8_ + 0xc) = uStack_9c;
          auStack_98._8_8_ = (undefined8 *)(auStack_98._8_8_ + 0x10);
        }
      }
      param_2 = alStack_80[0] + lStack_68;
      lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,alStack_80);
    }
    for (; puVar13 != (undefined8 *)auStack_98._8_8_; puVar13 = puVar13 + 2) {
      uVar3 = *puVar13;
      uStackX_8 = 0;
      uVar5 = puVar13[1];
      lVar7 = func_0x000180127f44(uVar5);
      func_0x0001801ca899(lVar7,0,uVar5);
      ReadProcessMemory(_DAT_181b2f6e8,uVar3,lVar7,uVar5,&uStackX_8);
      if (0 < (int)uStackX_8) {
        lVar10 = 0;
        uVar11 = 0;
        if (uStackX_8 != 0) {
          do {
            uVar9 = 0;
            if (uVar6 != 0) {
              pcVar8 = param_4;
              do {
                if ((pcVar8[(lVar7 - (longlong)param_4) + uVar11] != *pcVar8) && (*pcVar8 != '?'))
                goto LAB_1800a9f2e;
                uVar9 = uVar9 + 1;
                pcVar8 = pcVar8 + 1;
              } while (uVar9 < uVar6);
            }
            if (uVar9 == uVar6) {
              if ((int)uVar11 != -1) goto LAB_1800a9f60;
              break;
            }
LAB_1800a9f2e:
            uVar11 = uVar11 + 1;
          } while (uVar11 < uStackX_8);
        }
      }
LAB_1800a9fd7:
      func_0x000180127e40(lVar7);
    }
    if ((undefined8 *)auStack_98._0_8_ != (undefined8 *)0x0) {
      puVar13 = (undefined8 *)auStack_98._0_8_;
      if ((0xfff < ((longlong)puStack_88 - auStack_98._0_8_ & 0xfffffffffffffff0U)) &&
         (puVar13 = *(undefined8 **)(auStack_98._0_8_ + -8),
         0x1f < (ulonglong)(auStack_98._0_8_ + (-8 - (longlong)puVar13)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        uVar5 = (*pcVar2)();
        return uVar5;
      }
      func_0x000180127e40(puVar13);
    }
    uVar5 = 1;
  }
  return uVar5;
LAB_1800a9f60:
  recovered_1800694f0(param_5);
  lVar10 = lVar10 + (int)uVar11 + uVar6;
  uVar9 = 0;
  if (uStackX_8 - lVar10 == uVar6) goto LAB_1800a9fd7;
  while( true ) {
    uVar11 = 0;
    if (uVar6 != 0) {
      pcVar8 = param_4;
      do {
        if ((pcVar8[((lVar10 + lVar7) - (longlong)param_4) + uVar9] != *pcVar8) && (*pcVar8 != '?'))
        goto LAB_1800a9fc4;
        uVar11 = uVar11 + 1;
        pcVar8 = pcVar8 + 1;
      } while (uVar11 < uVar6);
    }
    if (uVar11 == uVar6) break;
LAB_1800a9fc4:
    uVar9 = uVar9 + 1;
    if ((uStackX_8 - lVar10) - uVar6 <= uVar9) goto LAB_1800a9fd7;
  }
  uVar11 = uVar9 & 0xffffffff;
  if ((int)uVar9 == -1) goto LAB_1800a9fd7;
  goto LAB_1800a9f60;
}



/* ===== ANALYSIS FUNCTION 0x1800abdc0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800abdc0(undefined4 param_1,undefined param_2,undefined8 param_3,longlong param_4,
                        longlong param_5)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uStack_c8;
  int iStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined uStack_b4;
  undefined8 uStack_b0;
  longlong alStack_a8 [7];
  longlong *plStack_70;
  longlong alStack_68 [7];
  longlong *plStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  plStack_70 = (longlong *)0x0;
  puVar1 = *(undefined8 **)(param_4 + 0x38);
  uStack_b8 = param_1;
  uStack_b4 = param_2;
  uStack_b0 = param_3;
  if (puVar1 != (undefined8 *)0x0) {
    plStack_70 = (longlong *)(**(code **)*puVar1)(puVar1,alStack_a8);
  }
  plStack_30 = (longlong *)0x0;
  puVar1 = *(undefined8 **)(param_5 + 0x38);
  if (puVar1 != (undefined8 *)0x0) {
    plStack_30 = (longlong *)(**(code **)*puVar1)(puVar1,alStack_68);
  }
  puVar4 = (undefined4 *)func_0x000180127a94(0x90);
  *puVar4 = uStack_b8;
  *(undefined *)(puVar4 + 1) = uStack_b4;
  *(undefined8 *)(puVar4 + 2) = uStack_b0;
  *(undefined8 *)(puVar4 + 0x12) = 0;
  if (plStack_70 != (longlong *)0x0) {
    uVar5 = (**(code **)*plStack_70)(plStack_70,puVar4 + 4);
    *(undefined8 *)(puVar4 + 0x12) = uVar5;
  }
  *(undefined8 *)(puVar4 + 0x22) = 0;
  if (plStack_30 != (longlong *)0x0) {
    uVar5 = (**(code **)*plStack_30)(plStack_30,puVar4 + 0x14);
    *(undefined8 *)(puVar4 + 0x22) = uVar5;
  }
  lVar6 = _beginthreadex(0,0,&DAT_1800b9aa0,puVar4,0,&iStack_c0);
  uStack_bc = (undefined4)((ulonglong)uStack_c8 >> 0x20);
  if (lVar6 != 0) {
    iStack_c0 = (int)uStack_c8;
    if (iStack_c0 != 0) {
      uStack_c8._0_4_ = (undefined4)lVar6;
      uStack_c8._4_4_ = (undefined4)((ulonglong)lVar6 >> 0x20);
      uStack_28 = (undefined4)uStack_c8;
      uStack_24 = uStack_c8._4_4_;
      iStack_20 = iStack_c0;
      uStack_1c = uStack_bc;
      iVar3 = _Thrd_detach(&uStack_28);
      if (iVar3 == 0) {
        if (plStack_30 != (longlong *)0x0) {
          (**(code **)(*plStack_30 + 0x20))(plStack_30,plStack_30 != alStack_68);
          plStack_30 = (longlong *)0x0;
        }
        if (plStack_70 != (longlong *)0x0) {
          (**(code **)(*plStack_70 + 0x20))(plStack_70,plStack_70 != alStack_a8);
        }
        return;
      }
    }
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800ad030 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_1800ad030(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_181ade2c0;
  if (0xf < _DAT_181ade2d8) {
    puVar3 = _DAT_181ade2c0;
  }
  if (((_DAT_181ade2d0 < (undefined *)0x6) ||
      (puVar1 = _DAT_181ade2d0 + (longlong)puVar3,
      puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dc9b4,6), puVar2 == puVar1))
     || (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
    puVar3 = &DAT_181ade2c0;
    if (0xf < _DAT_181ade2d8) {
      puVar3 = _DAT_181ade2c0;
    }
    if (((_DAT_181ade2d0 < (undefined *)0x9) ||
        (puVar1 = _DAT_181ade2d0 + (longlong)puVar3,
        puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dc9a8,9), puVar2 == puVar1)
        ) || (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
      puVar3 = &DAT_181ade2c0;
      if (0xf < _DAT_181ade2d8) {
        puVar3 = _DAT_181ade2c0;
      }
      if (((_DAT_181ade2d0 < (undefined *)0x9) ||
          (puVar1 = _DAT_181ade2d0 + (longlong)puVar3,
          puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dc9d8,9),
          puVar2 == puVar1)) ||
         (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
        puVar3 = &DAT_181ade2c0;
        if (0xf < _DAT_181ade2d8) {
          puVar3 = _DAT_181ade2c0;
        }
        if (((_DAT_181ade2d0 < (undefined *)0xd) ||
            (puVar1 = puVar3 + (longlong)_DAT_181ade2d0,
            puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dca28,0xd),
            puVar2 == puVar1)) ||
           (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
          puVar3 = &DAT_181ade2c0;
          if (0xf < _DAT_181ade2d8) {
            puVar3 = _DAT_181ade2c0;
          }
          if (((_DAT_181ade2d0 < (undefined *)0xc) ||
              (puVar1 = puVar3 + (longlong)_DAT_181ade2d0,
              puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dcbf0,0xc),
              puVar2 == puVar1)) ||
             (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
            puVar3 = &DAT_181ade2c0;
            if (0xf < _DAT_181ade2d8) {
              puVar3 = _DAT_181ade2c0;
            }
            puVar2 = _DAT_181ade2d0;
            if (((_DAT_181ade2d0 < (undefined *)0x13) ||
                (puVar1 = puVar3 + (longlong)_DAT_181ade2d0,
                puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dcc20,0x13),
                puVar2 == puVar1)) ||
               (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
              return (ulonglong)puVar2 & 0xffffffffffffff00;
            }
          }
        }
      }
    }
  }
  return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
}



/* ===== ANALYSIS FUNCTION 0x1800ad260 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800ad260(char *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  ulonglong uVar14;
  char cVar15;
  int iVar16;
  undefined (*pauVar17) [16];
  undefined4 *puVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined auVar22 [16];
  undefined4 auStackX_8 [2];
  undefined auStack_88 [5];
  undefined auStack_83 [3];
  undefined8 uStack_80;
  ulonglong uStack_78;
  ulonglong uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined auStack_48 [16];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  auStackX_8[0] = 0;
  _DAT_181ade2d0 = 0;
  pauVar17 = (undefined (*) [16])&DAT_181ade2c0;
  if (0xf < _DAT_181ade2d8) {
    pauVar17 = _DAT_181ade2c0;
  }
  (*pauVar17)[0] = 0;
  uVar13 = _UNK_181a0393c;
  uVar12 = _UNK_181a03938;
  uVar11 = _UNK_181a03934;
  uVar10 = _DAT_181a03930;
  if (*param_1 == '\0') {
    uVar20 = recovered_1800a8c60();
    iVar16 = recovered_1800a8cf0(uVar20);
    if ((iVar16 != 0) &&
       (_DAT_181b2f6e0 = iVar16, _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar16),
       puVar2 = _DAT_181b2f748, _DAT_181b2f6e8 != 0)) {
      puVar6 = _DAT_181b2f788;
      for (puVar1 = (undefined8 *)*_DAT_181b2f748; _DAT_181b2f788 = puVar6, puVar1 != puVar2;
          puVar1 = (undefined8 *)*puVar1) {
        auStackX_8[0] = *(undefined4 *)(puVar1 + 3);
        WriteProcessMemory(_DAT_181b2f6e8,puVar1[2],auStackX_8,4,0);
        puVar6 = _DAT_181b2f788;
      }
      for (puVar2 = (undefined8 *)*puVar6; puVar2 != puVar6; puVar2 = (undefined8 *)*puVar2) {
        auStackX_8[0] = *(undefined4 *)(puVar2 + 3);
        WriteProcessMemory(_DAT_181b2f6e8,puVar2[2],auStackX_8,4,0);
      }
      CloseHandle(_DAT_181b2f6e8);
    }
    DAT_181b30435 = 0;
    LOCK();
    DAT_181b2f6df = 0;
    UNLOCK();
    stack0xffffffffffffff7c = uVar11;
    auStack_88._0_4_ = uVar10;
    uStack_80._0_4_ = uVar12;
    uStack_80._4_4_ = uVar13;
  }
  else {
    uStack_78 = _DAT_181a03560;
    uStack_70 = _UNK_181a03568;
    _auStack_83 = SUB1611(ZEXT816(0),5);
    auStack_88 = (undefined  [5])0x6b63654e;
    recovered_1800a8dd0(param_1,auStack_88);
    if (0xf < uStack_70) {
      if ((0xfff < uStack_70 + 1) && (0x1f < (_auStack_88 - *(longlong *)(_auStack_88 + -8)) - 8U))
      goto LAB_1800ad53a;
      func_0x000180127e40();
    }
    cVar15 = recovered_1800ad030();
    uVar14 = _DAT_181ade2d0;
    if (cVar15 != '\0') {
      DAT_181b30435 = 0;
      LOCK();
      DAT_181b2f6df = 0;
      UNLOCK();
      auVar22 = ZEXT816(0);
      if (_DAT_181ade2d0 == 0) {
        auStack_48 = auVar22;
        puVar18 = (undefined4 *)func_0x000180024110(0x20);
        uVar9 = _UNK_1819dcc14;
        uVar8 = _UNK_1819dcc10;
        uVar7 = _UNK_1819dcc0c;
        auStack_48._0_8_ = puVar18;
        uStack_38 = _DAT_181a03620;
        uStack_34 = _UNK_181a03624;
        uStack_30 = _UNK_181a03628;
        uStack_2c = _UNK_181a0362c;
        *puVar18 = _DAT_1819dcc08;
        puVar18[1] = uVar7;
        puVar18[2] = uVar8;
        puVar18[3] = uVar9;
        *(undefined2 *)(puVar18 + 4) = _DAT_1819dcc18;
        *(undefined *)((longlong)puVar18 + 0x12) = DAT_1819dcc1a;
        *(undefined *)((longlong)puVar18 + 0x13) = 0;
        puVar18 = (undefined4 *)auStack_48;
        bVar5 = true;
        bVar4 = false;
      }
      else {
        pauVar17 = (undefined (*) [16])&DAT_181ade2c0;
        if (0xf < _DAT_181ade2d8) {
          pauVar17 = _DAT_181ade2c0;
        }
        _auStack_88 = auVar22;
        if (0x7fffffffffffffff < _DAT_181ade2d0) {
          func_0x000180052a50();
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        if (_DAT_181ade2d0 < 0x10) {
          uStack_78 = _DAT_181ade2d0;
          uStack_70 = 0xf;
          _auStack_88 = *pauVar17;
        }
        else {
          uVar19 = _DAT_181ade2d0 | 0xf;
          uVar21 = 0x7fffffffffffffff;
          if ((uVar19 < 0x8000000000000000) && (uVar21 = uVar19, uVar19 < 0x16)) {
            uVar21 = 0x16;
          }
          uVar20 = func_0x000180024110(uVar21 + 1);
          _auStack_88 = uVar20;
          uStack_78 = uVar14;
          uStack_70 = uVar21;
          func_0x0001801ca88d(uVar20,pauVar17,uVar14 + 1);
        }
        puVar18 = (undefined4 *)auStack_88;
        bVar5 = false;
        bVar4 = true;
      }
      uStack_68 = *puVar18;
      uStack_64 = puVar18[1];
      uStack_60 = puVar18[2];
      uStack_5c = puVar18[3];
      uStack_58 = puVar18[4];
      uStack_54 = puVar18[5];
      uStack_50 = puVar18[6];
      uStack_4c = puVar18[7];
      *(undefined8 *)(puVar18 + 4) = 0;
      *(undefined8 *)(puVar18 + 6) = 0xf;
      *(undefined *)puVar18 = 0;
      if ((bVar4) && (0xf < uStack_70)) {
        if ((0xfff < uStack_70 + 1) && (0x1f < (_auStack_88 - *(longlong *)(_auStack_88 + -8)) - 8U)
           ) {
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        func_0x000180127e40();
      }
      if ((bVar5) && (0xf < CONCAT44(uStack_2c,uStack_30))) {
        if ((0xfff < CONCAT44(uStack_2c,uStack_30) + 1) &&
           (0x1f < (auStack_48._0_8_ - *(longlong *)(auStack_48._0_8_ + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        func_0x000180127e40();
      }
      stack0xffffffffffffff7c = uVar11;
      auStack_88._0_4_ = uVar10;
      uStack_80._0_4_ = uVar12;
      uStack_80._4_4_ = uVar13;
      recovered_18009bbb0();
      if (0xf < CONCAT44(uStack_4c,uStack_50)) {
        if ((0xfff < CONCAT44(uStack_4c,uStack_50) + 1) &&
           (0x1f < (CONCAT44(uStack_64,uStack_68) -
                   *(longlong *)(CONCAT44(uStack_64,uStack_68) + -8)) - 8U)) {
LAB_1800ad53a:
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        func_0x000180127e40();
      }
      goto LAB_1800ad66f;
    }
    DAT_181b30435 = 1;
    LOCK();
    DAT_181b2f6df = 1;
    UNLOCK();
    stack0xffffffffffffff7c = _DAT_181a2aff4;
    auStack_88._0_4_ = _DAT_181a2aff0;
    uStack_80._0_4_ = _DAT_181a2aff8;
    uStack_80._4_4_ = _DAT_181a2affc;
  }
  recovered_18009bbb0();
LAB_1800ad66f:
  LOCK();
  DAT_181b2f8cb = 0;
  UNLOCK();
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800ad6a0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x0001800aded0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800ad6a0(void)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined uVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  char cVar15;
  undefined auVar16 [16];
  undefined auVar17 [16];
  short sVar18;
  int iVar19;
  undefined8 uVar20;
  longlong lVar21;
  bool bVar22;
  bool bVar23;
  longlong lStackX_20;
  undefined **in_stack_fffffffffffffcd8;
  longlong lStack_318;
  int iStack_310;
  undefined4 uStack_30c;
  undefined auStack_308 [8];
  undefined8 uStack_300;
  undefined auStack_2f8 [8];
  undefined8 uStack_2f0;
  undefined auStack_2e8 [8];
  undefined8 uStack_2e0;
  undefined *apuStack_2d8 [7];
  undefined **ppuStack_2a0;
  undefined *apuStack_298 [7];
  undefined **ppuStack_260;
  undefined *apuStack_258 [7];
  undefined **ppuStack_220;
  undefined *apuStack_218 [7];
  undefined **ppuStack_1e0;
  undefined *apuStack_1d8 [7];
  undefined **ppuStack_1a0;
  undefined *apuStack_198 [7];
  undefined **ppuStack_160;
  undefined *apuStack_158 [7];
  undefined **ppuStack_120;
  undefined *apuStack_118 [7];
  undefined **ppuStack_e0;
  undefined *apuStack_d8 [7];
  undefined **ppuStack_a0;
  undefined *apuStack_98 [7];
  undefined **ppuStack_60;
  
  uVar14 = _UNK_181a0393c;
  iVar13 = _UNK_181a03938;
  uVar12 = _UNK_181a03934;
  uVar11 = _DAT_181a03930;
  bVar8 = false;
  bVar9 = false;
  bVar2 = false;
  bVar3 = false;
  bVar4 = false;
  bVar5 = false;
  bVar6 = false;
  bVar22 = false;
  bVar10 = false;
  do {
    if ((_DAT_181b2f3a4 != 0) && (sVar18 = GetAsyncKeyState(), sVar18 < 0)) {
      if (bVar8) goto LAB_1800ad7b3;
      DAT_181b30590 = 1;
      uVar20 = func_0x000180127a94(1);
      in_stack_fffffffffffffcd8 =
           (undefined **)((ulonglong)in_stack_fffffffffffffcd8 & 0xffffffff00000000);
      lVar21 = _beginthreadex(0,0,&DAT_1800b9bb0,uVar20,in_stack_fffffffffffffcd8,&uStack_300);
      auVar17 = _auStack_308;
      auStack_308 = (undefined  [8])lVar21;
      auVar16 = _auStack_308;
      if (lVar21 != 0) {
        uStack_300._0_4_ = auVar17._8_4_;
        if ((int)uStack_300 != 0) {
          uStack_300._4_4_ = auVar17._12_4_;
          iStack_310 = (int)uStack_300;
          uStack_30c = uStack_300._4_4_;
          lStack_318 = lVar21;
          _auStack_308 = auVar16;
          iVar19 = _Thrd_detach(&lStack_318);
          auVar16 = _auStack_308;
          if (iVar19 == 0) {
            _auStack_308 = ZEXT816(0);
            bVar8 = true;
            goto LAB_1800ad7b3;
          }
        }
        _auStack_308 = auVar16;
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      uStack_300._0_4_ = 0;
      __Throw_Cpp_error_std__YAXH_Z(6);
      auVar17 = _auStack_2f8;
      goto LAB_1800ae40b;
    }
    bVar8 = false;
LAB_1800ad7b3:
    if ((_DAT_181b2f3a0 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar9 = false;
    }
    else if (!bVar9) {
      DAT_181b30592 = 1;
      uVar20 = func_0x000180127a94(1);
      in_stack_fffffffffffffcd8 =
           (undefined **)((ulonglong)in_stack_fffffffffffffcd8 & 0xffffffff00000000);
      lVar21 = _beginthreadex(0,0,&DAT_1800b9c30,uVar20,in_stack_fffffffffffffcd8,&uStack_2f0);
      auVar16 = _auStack_2f8;
      auStack_2f8 = (undefined  [8])lVar21;
      auVar17 = _auStack_2f8;
      if (lVar21 != 0) {
        uStack_2f0._0_4_ = auVar16._8_4_;
        if ((int)uStack_2f0 != 0) {
          uStack_2f0._4_4_ = auVar16._12_4_;
          iStack_310 = (int)uStack_2f0;
          uStack_30c = uStack_2f0._4_4_;
          lStack_318 = lVar21;
          _auStack_2f8 = auVar17;
          iVar19 = _Thrd_detach(&lStack_318);
          auVar17 = _auStack_2f8;
          if (iVar19 == 0) {
            _auStack_2f8 = ZEXT816(0);
            bVar9 = true;
            goto LAB_1800ad868;
          }
        }
LAB_1800ae40b:
        _auStack_2f8 = auVar17;
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      uStack_2f0._0_4_ = 0;
      __Throw_Cpp_error_std__YAXH_Z(6);
      auVar17 = _auStack_2e8;
LAB_1800ae427:
      _auStack_2e8 = auVar17;
      __Throw_Cpp_error_std__YAXH_Z(1);
LAB_1800ae433:
      uStack_2e0._0_4_ = 0;
      __Throw_Cpp_error_std__YAXH_Z(6);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
LAB_1800ad868:
    if ((_DAT_181b32b7c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar22 = false;
      if ((_DAT_181b30424 == 2) && (DAT_181b2f8c9 != '\0')) {
        DAT_181b2f8c9 = '\x01';
LAB_1800ad94b:
        DAT_181b2b432 = 0;
        DAT_181b2b403 = 0;
        _DAT_181b2b430 = 0;
      }
    }
    else if (_DAT_181b30424 == 2) {
      if (DAT_181b2f8c9 == '\0') {
        DAT_181b2f8c9 = '\0';
        goto LAB_1800ad94b;
      }
    }
    else if (!bVar22) {
      DAT_181b2f8c9 = DAT_181b2f8c9 == '\0';
      _DAT_181b2b430 = 0;
      uVar7 = 0;
      DAT_181b2b403 = uVar7;
      DAT_181b2b432 = uVar7;
      if ((bool)DAT_181b2f8c9) {
        if (_DAT_181b30424 != 0) {
          if (_DAT_181b30424 == 1) {
            _DAT_181b2b430 = 1;
            bVar22 = true;
          }
          else {
            if (_DAT_181b30424 != 3) goto LAB_1800ad91c;
            DAT_181b2b432 = 1;
            bVar22 = true;
          }
          goto LAB_1800ad954;
        }
        DAT_181b2b403 = 1;
      }
LAB_1800ad91c:
      bVar22 = true;
    }
LAB_1800ad954:
    if ((_DAT_181b32b64 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar2 = false;
    }
    else if (!bVar2) {
      apuStack_198[0] = &UNK_1819de468;
      ppuStack_160 = apuStack_198;
      apuStack_2d8[0] = &UNK_181a03050;
      ppuStack_2a0 = apuStack_2d8;
      DAT_181b3044e = DAT_181b3044e == '\0';
      in_stack_fffffffffffffcd8 = apuStack_198;
      recovered_1800abdc0(0x1e,DAT_181b3044e,&UNK_1819dcc68,apuStack_2d8,in_stack_fffffffffffffcd8);
      if (ppuStack_2a0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_2a0 + 0x20))();
        ppuStack_2a0 = (undefined **)0x0;
      }
      if (ppuStack_160 != (undefined **)0x0) {
        (**(code **)(*ppuStack_160 + 0x20))();
      }
      bVar2 = true;
    }
    if ((_DAT_181b32b4c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar3 = false;
    }
    else if (!bVar3) {
      apuStack_158[0] = &UNK_1819ddf88;
      ppuStack_120 = apuStack_158;
      apuStack_298[0] = &UNK_1819de280;
      ppuStack_260 = apuStack_298;
      DAT_181b3044f = DAT_181b3044f == '\0';
      in_stack_fffffffffffffcd8 = apuStack_158;
      recovered_1800abdc0(0x1f,DAT_181b3044f,&UNK_1819dcc58,apuStack_298,in_stack_fffffffffffffcd8);
      if (ppuStack_260 != (undefined **)0x0) {
        (**(code **)(*ppuStack_260 + 0x20))();
        ppuStack_260 = (undefined **)0x0;
      }
      if (ppuStack_120 != (undefined **)0x0) {
        (**(code **)(*ppuStack_120 + 0x20))();
      }
      bVar3 = true;
    }
    if ((_DAT_181b303bc == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar4 = false;
    }
    else if (!bVar4) {
      apuStack_118[0] = &UNK_1819ddc88;
      ppuStack_e0 = apuStack_118;
      apuStack_258[0] = &UNK_181a02f68;
      ppuStack_220 = apuStack_258;
      DAT_181b3049f = DAT_181b3049f == '\0';
      in_stack_fffffffffffffcd8 = apuStack_118;
      recovered_1800abdc0(0x6f,DAT_181b3049f,&UNK_1819dcc88,apuStack_258,in_stack_fffffffffffffcd8);
      if (ppuStack_220 != (undefined **)0x0) {
        (**(code **)(*ppuStack_220 + 0x20))();
        ppuStack_220 = (undefined **)0x0;
      }
      if (ppuStack_e0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_e0 + 0x20))();
      }
      bVar4 = true;
    }
    if ((_DAT_181b30428 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar5 = false;
    }
    else if (!bVar5) {
      apuStack_d8[0] = &UNK_1819ddd78;
      ppuStack_a0 = apuStack_d8;
      apuStack_218[0] = &UNK_1819de2d8;
      ppuStack_1e0 = apuStack_218;
      DAT_181b3055d = DAT_181b3055d == '\0';
      in_stack_fffffffffffffcd8 = apuStack_d8;
      recovered_1800abdc0(0x12d,DAT_181b3055d,&UNK_1819dcc78,apuStack_218,in_stack_fffffffffffffcd8)
      ;
      if (ppuStack_1e0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_1e0 + 0x20))();
        ppuStack_1e0 = (undefined **)0x0;
      }
      if (ppuStack_a0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_a0 + 0x20))();
      }
      bVar5 = true;
    }
    if ((_DAT_181b303b8 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar6 = false;
    }
    else if (!bVar6) {
      apuStack_98[0] = &UNK_1819ddcf8;
      ppuStack_60 = apuStack_98;
      apuStack_1d8[0] = &UNK_1819ddf18;
      ppuStack_1a0 = apuStack_1d8;
      DAT_181b30438 = DAT_181b30438 == '\0';
      in_stack_fffffffffffffcd8 = apuStack_98;
      recovered_1800abdc0(8,DAT_181b30438,&UNK_1819dcca8,apuStack_1d8,in_stack_fffffffffffffcd8);
      if (ppuStack_1a0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_1a0 + 0x20))();
        ppuStack_1a0 = (undefined **)0x0;
      }
      if (ppuStack_60 != (undefined **)0x0) {
        (**(code **)(*ppuStack_60 + 0x20))();
      }
      bVar6 = true;
    }
    if ((_DAT_181ade2b8 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar10 = false;
    }
    else if (!bVar10) {
      recovered_180067b80(&lStackX_20);
      if (249999999 < lStackX_20 - _DAT_181b4f0d0) {
        _DAT_181b4f0d0 = lStackX_20;
        DAT_181b2bedd = 1;
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
      }
      bVar10 = true;
    }
    if ((_DAT_181b2f3c8 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f115 = '\0';
    }
    else if (DAT_181b4f115 == '\0') {
      DAT_181b2bc6d = DAT_181b2bc6d == '\0';
      if ((bool)DAT_181b2bc6d) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f115 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f115 = '\x01';
      }
    }
    if ((_DAT_181b32b48 == 0) || (sVar18 = GetAsyncKeyState(), cVar15 = DAT_181b2f8cb, -1 < sVar18))
    {
      DAT_181b4f0e0 = '\0';
    }
    else if (DAT_181b4f0e0 == '\0') {
      bVar23 = DAT_181b2f6df == '\0';
      LOCK();
      DAT_181b2f8cb = '\x01';
      UNLOCK();
      DAT_181b30435 = bVar23;
      if (cVar15 == '\0') {
        if ((DAT_181b2f6df != '\0') && (DAT_181b2f6df == '\0')) {
          DAT_181b30435 = DAT_181b2f6df;
          LOCK();
          DAT_181b2f8cb = '\0';
          UNLOCK();
          DAT_181b4f0e0 = '\x01';
          goto LAB_1800adf72;
        }
        lStack_318 = func_0x000180127a94(1);
        *(bool *)lStack_318 = bVar23;
        in_stack_fffffffffffffcd8 =
             (undefined **)((ulonglong)in_stack_fffffffffffffcd8 & 0xffffffff00000000);
        lVar21 = _beginthreadex(0,0,&DAT_1800b9b80,lStack_318,in_stack_fffffffffffffcd8,&uStack_2e0)
        ;
        auVar16 = _auStack_2e8;
        auStack_2e8 = (undefined  [8])lVar21;
        auVar17 = _auStack_2e8;
        if (lVar21 == 0) goto LAB_1800ae433;
        uStack_2e0._0_4_ = auVar16._8_4_;
        if ((int)uStack_2e0 == 0) goto LAB_1800ae427;
        uStack_2e0._4_4_ = auVar16._12_4_;
        iStack_310 = (int)uStack_2e0;
        uStack_30c = uStack_2e0._4_4_;
        lStack_318 = lVar21;
        _auStack_2e8 = auVar17;
        iVar19 = _Thrd_detach(&lStack_318);
        auVar17 = _auStack_2e8;
        if (iVar19 != 0) goto LAB_1800ae427;
        _auStack_2e8 = ZEXT816(0);
      }
      DAT_181b4f0e0 = '\x01';
    }
LAB_1800adf72:
    if ((_DAT_181b2b44c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0e2 = '\0';
    }
    else if (DAT_181b4f0e2 == '\0') {
      DAT_181b2b444 = DAT_181b2b444 == '\0';
      if ((bool)DAT_181b2b444) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0e2 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0e2 = '\x01';
      }
    }
    if ((_DAT_181b32b78 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0e3 = '\0';
    }
    else if (DAT_181b4f0e3 == '\0') {
      DAT_181b2b5e9 = DAT_181b2b5e9 == '\0';
      if ((bool)DAT_181b2b5e9) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0e3 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0e3 = '\x01';
      }
    }
    if ((_DAT_181b3042c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0b0 = '\0';
    }
    else if (DAT_181b4f0b0 == '\0') {
      DAT_181b2bedc = DAT_181b2bedc == '\0';
      if ((bool)DAT_181b2bedc) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0b0 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0b0 = '\x01';
      }
    }
    if ((_DAT_181b32b40 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f07c = '\0';
    }
    else if (DAT_181b4f07c == '\0') {
      DAT_181b2b5b6 = DAT_181b2b5b6 == '\0';
      if ((bool)DAT_181b2b5b6) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f07c = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f07c = '\x01';
      }
    }
    if ((_DAT_181b2f39c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0a1 = '\0';
    }
    else if (DAT_181b4f0a1 == '\0') {
      DAT_181b2b5f1 = DAT_181b2b5f1 == '\0';
      if ((bool)DAT_181b2b5f1) {
        recovered_180077c40();
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
      }
      else {
        LOCK();
        DAT_181b2f64a = 0;
        UNLOCK();
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
      }
      recovered_18009bbb0();
      DAT_181b4f0a1 = '\x01';
    }
    if (DAT_181b2b5f1 == '\0') {
      if (DAT_181b4f114 != '\0') {
        LOCK();
        DAT_181b2f64a = 0;
        UNLOCK();
        DAT_181b4f114 = '\0';
      }
    }
    else if (DAT_181b4f114 == '\0') {
      recovered_180077c40();
      DAT_181b4f114 = '\x01';
    }
    if (((_DAT_181b30424 == 2) && (DAT_181b2f8c9 != '\0')) && (_DAT_181b2f398 != 0)) {
      sVar18 = GetAsyncKeyState();
      if (sVar18 < 0) {
        DAT_181b2b403 = 1;
        _DAT_181b2b414 = _DAT_181b2f398;
      }
      else {
        DAT_181b2b403 = 0;
        _DAT_181b2b414 = 1;
      }
    }
    if ((_DAT_181b30420 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0a2 = '\0';
    }
    else if (DAT_181b4f0a2 == '\0') {
      DAT_181b2b5ef = DAT_181b2b5ef == '\0';
      if ((bool)DAT_181b2b5ef) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0a2 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0a2 = '\x01';
      }
    }
    if ((_DAT_181b32b54 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0c1 = '\0';
    }
    else if (DAT_181b4f0c1 == '\0') {
      DAT_181b2b58d = DAT_181b2b58d == '\0';
      if ((bool)DAT_181b2b58d) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0c1 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0c1 = '\x01';
      }
    }
    if ((_DAT_181b32b50 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0e1 = '\0';
    }
    else if (DAT_181b4f0e1 == '\0') {
      DAT_181b2b5fc = DAT_181b2b5fc == '\0';
      if ((bool)DAT_181b2b5fc) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0e1 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0e1 = '\x01';
      }
    }
    lStack_318 = 10;
    recovered_1800693e0(&lStack_318);
  } while( true );
}



/* ===== ANALYSIS FUNCTION 0x1800ae560 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_1800ae560(undefined (*param_1) [16])

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [12];
  longlong lVar5;
  int iVar6;
  undefined (*pauVar7) [16];
  undefined *puVar8;
  longlong lVar9;
  undefined auStack_1a8 [16];
  undefined auStack_198 [8];
  undefined8 uStack_190;
  undefined auStack_188 [8];
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined auStack_178 [8];
  undefined8 uStack_170;
  undefined auStack_160 [16];
  undefined auStack_150 [8];
  undefined8 uStack_148;
  undefined auStack_140 [16];
  undefined auStack_130 [24];
  char acStack_118 [272];
  longlong lVar10;
  
  func_0x0001801ca899(acStack_118,0,0x104);
  iVar6 = SHGetFolderPathA(0,0x1c,0,0,acStack_118);
  auStack_160 = ZEXT816(0);
  if (iVar6 < 0) {
    *param_1 = auStack_160;
    *(undefined8 *)param_1[1] = 8;
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    *(undefined8 *)*param_1 = 0x6574695861766f4e;
    (*param_1)[8] = 0;
  }
  else {
    _auStack_150 = ZEXT816(0);
    lVar10 = -1;
    do {
      lVar5 = lVar10 + 1;
      lVar10 = lVar10 + 1;
    } while (acStack_118[lVar5] != '\0');
    recovered_180066cc0(auStack_160,acStack_118);
    pauVar7 = (undefined (*) [16])recovered_180066ec0(auStack_160,&UNK_1819dce78,0x12);
    _auStack_188 = *pauVar7;
    _auStack_178 = pauVar7[1];
    *(undefined8 *)pauVar7[1] = 0;
    *(undefined8 *)(pauVar7[1] + 8) = 0xf;
    (*pauVar7)[0] = 0;
    if (0xf < uStack_148) {
      if (0xfff < uStack_148 + 1) {
        if (0x1f < (auStack_160._0_8_ - *(longlong *)(auStack_160._0_8_ + -8)) - 8U) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar1)();
          return pauVar7;
        }
      }
      func_0x000180127e40();
    }
    auStack_150._4_4_ = _UNK_181a03534;
    auStack_150._0_4_ = _DAT_181a03530;
    uStack_148._0_4_ = _UNK_181a03538;
    uStack_148._4_4_ = _UNK_181a0353c;
    auVar2[15] = 0;
    auVar2._0_15_ = auStack_160._1_15_;
    auStack_160 = auVar2 << 8;
    auStack_140 = ZEXT816(0);
    auStack_130._0_16_ = ZEXT816(0);
    lVar10 = -1;
    do {
      lVar9 = lVar10 + 1;
      lVar5 = lVar10 + 1;
      lVar10 = lVar9;
    } while (acStack_118[lVar5] != '\0');
    recovered_180066cc0(auStack_140,acStack_118,lVar9);
    pauVar7 = (undefined (*) [16])recovered_180066ec0(auStack_140,&UNK_1819dcea8,9);
    auVar4 = *(undefined (*) [12])*pauVar7;
    auVar2 = *pauVar7;
    _auStack_198 = pauVar7[1];
    *(undefined8 *)pauVar7[1] = 0;
    *(undefined8 *)(pauVar7[1] + 8) = 0xf;
    (*pauVar7)[0] = 0;
    auStack_1a8._0_8_ = auStack_1a8;
    if (0xf < uStack_190) {
      auStack_1a8._0_8_ = auVar4._0_8_;
    }
    puVar8 = (undefined *)auStack_1a8._0_8_;
    auStack_1a8 = auVar2;
    CreateDirectoryA(puVar8,0);
    if (0xf < uStack_190) {
      if (0xfff < uStack_190 + 1) {
        if (0x1f < (auStack_1a8._0_8_ - *(longlong *)(auStack_1a8._0_8_ + -8)) - 8U) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar1)();
          return pauVar7;
        }
      }
      func_0x000180127e40();
    }
    auStack_198._4_4_ = _UNK_181a03534;
    auStack_198._0_4_ = _DAT_181a03530;
    uStack_190._4_4_ = _UNK_181a0353c;
    uStack_190._0_4_ = _UNK_181a03538;
    auVar3[15] = 0;
    auVar3._0_15_ = auStack_1a8._1_15_;
    auStack_1a8 = auVar3 << 8;
    if (0xf < (ulonglong)auStack_130._8_8_) {
      if (0xfff < auStack_130._8_8_ + 1) {
        if (0x1f < (auStack_140._0_8_ - *(longlong *)(auStack_140._0_8_ + -8)) - 8U) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar1)();
          return pauVar7;
        }
      }
      func_0x000180127e40();
    }
    puVar8 = auStack_188;
    if (0xf < uStack_170) {
      puVar8 = (undefined *)auStack_188;
    }
    CreateDirectoryA(puVar8,0);
    *(undefined4 *)*param_1 = auStack_188._0_4_;
    *(undefined4 *)(*param_1 + 4) = auStack_188._4_4_;
    *(undefined4 *)(*param_1 + 8) = uStack_180;
    *(undefined4 *)(*param_1 + 0xc) = uStack_17c;
    *(undefined4 *)param_1[1] = auStack_178._0_4_;
    *(undefined4 *)(param_1[1] + 4) = auStack_178._4_4_;
    *(undefined4 *)(param_1[1] + 8) = (undefined4)uStack_170;
    *(undefined4 *)(param_1[1] + 0xc) = uStack_170._4_4_;
  }
  return param_1;
}



/* ===== ANALYSIS FUNCTION 0x1800aeb50 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800aeb50(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  undefined (*pauVar8) [16];
  longlong lVar9;
  undefined *puVar10;
  undefined auStack_1a8 [16];
  longlong lStack_198;
  ulonglong uStack_190;
  longlong lStack_188;
  undefined8 uStack_180;
  undefined auStack_178 [16];
  undefined auStack_168 [16];
  undefined8 uStack_158;
  undefined8 uStack_150;
  int iStack_13c;
  undefined *apuStack_138 [3];
  undefined auStack_120 [48];
  longlong alStack_f0 [6];
  undefined8 uStack_c0;
  undefined uStack_b7;
  undefined8 uStack_b4;
  undefined uStack_ac;
  undefined8 uStack_a8;
  undefined auStack_88 [112];
  
  uVar7 = recovered_1800ae560(&uStack_158);
  pauVar8 = (undefined (*) [16])recovered_180066ec0(uVar7,&UNK_1819dceb8,0xc);
  auStack_178 = *pauVar8;
  auStack_168 = pauVar8[1];
  *(undefined8 *)pauVar8[1] = 0;
  *(undefined8 *)(pauVar8[1] + 8) = 0xf;
  (*pauVar8)[0] = 0;
  recovered_180066e40(&uStack_158);
  puVar10 = auStack_178;
  if (0xf < (ulonglong)auStack_168._8_8_) {
    puVar10 = (undefined *)auStack_178._0_8_;
  }
  apuStack_138[0] = &UNK_1819de2c8;
  __0__basic_ios_DU__char_traits_D_std___std__IEAA_XZ(auStack_88);
  __0__basic_istream_DU__char_traits_D_std___std__QEAA_PEAV__basic_streambuf_DU__char_traits_D_std___1__N_Z
            (apuStack_138,apuStack_138 + 2,0,0);
  *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) = &UNK_1801f22f0
  ;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
       *(int *)(apuStack_138[0] + 4) + -0xb0;
  __0__basic_streambuf_DU__char_traits_D_std___std__IEAA_XZ(apuStack_138 + 2);
  apuStack_138[2] = &UNK_1801f2270;
  uStack_ac = 0;
  uStack_b7 = 0;
  __Init___basic_streambuf_DU__char_traits_D_std___std__IEAAXXZ(apuStack_138 + 2);
  uStack_a8 = 0;
  uStack_b4 = _DAT_181b50d48;
  uStack_c0 = 0;
  lVar9 = func_0x0001800bbbc0(apuStack_138 + 2,puVar10,0x21,0x40);
  if (lVar9 == 0) {
    _setstate___basic_ios_DU__char_traits_D_std___std__QEAAXH_N_Z
              ((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4),2,0);
  }
  *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) = &UNK_1801f22f0
  ;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
       *(int *)(apuStack_138[0] + 4) + -0xb0;
  if (0xf < (ulonglong)auStack_168._8_8_) {
    if ((0xfff < auStack_168._8_8_ + 1) &&
       (0x1f < (auStack_178._0_8_ - *(longlong *)(auStack_178._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  auStack_168._8_8_ = _UNK_181a03538;
  auStack_168._0_8_ = _DAT_181a03530;
  auVar2[15] = 0;
  auVar2._0_15_ = auStack_178._1_15_;
  auStack_178 = auVar2 << 8;
  cVar5 = __7ios_base_std__QEBA_NXZ
                    ((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4));
  if (cVar5 == '\0') {
    uStack_158 = 0;
    uStack_150 = CONCAT62(uStack_150._2_6_,1);
    uVar7 = uStack_150;
    lStack_188 = *(longlong *)((longlong)alStack_f0 + (longlong)*(int *)(apuStack_138[0] + 4));
    auStack_1a8 = ZEXT816(0);
    lStack_198 = 0;
    uStack_190 = 0;
    if (lStack_188 != 0) {
      iVar6 = _sgetc___basic_streambuf_DU__char_traits_D_std___std__QEAAHXZ();
      if (iVar6 == -1) {
        lStack_188 = 0;
        uStack_180 = CONCAT71(uStack_180._1_7_,1);
      }
      else {
        uStack_180 = CONCAT71(CONCAT61(uStack_180._2_6_,(char)iVar6),1);
      }
    }
    if (lStack_188 == 0) {
      lStack_198 = 0;
      uStack_190 = 0xf;
      auVar3[15] = 0;
      auVar3._0_15_ = auStack_1a8._1_15_;
      auStack_1a8 = auVar3 << 8;
    }
    else {
      uStack_158 = 0;
      uStack_150 = uVar7;
      func_0x0001800b82b0(auStack_1a8,&lStack_188,&uStack_158);
      while (lStack_198 != 0) {
        puVar10 = auStack_1a8;
        if (0xf < uStack_190) {
          puVar10 = (undefined *)auStack_1a8._0_8_;
        }
        if (puVar10[lStack_198 + -1] != '\r') {
          puVar10 = auStack_1a8;
          if (0xf < uStack_190) {
            puVar10 = (undefined *)auStack_1a8._0_8_;
          }
          if (puVar10[lStack_198 + -1] != '\n') {
            if (lStack_198 == 0) goto LAB_1800aeecc;
            puVar10 = auStack_1a8;
            if (0xf < uStack_190) {
              puVar10 = (undefined *)auStack_1a8._0_8_;
            }
            strncpy_s(0x181b2bcf8,0x80,puVar10,0xffffffffffffffff);
            break;
          }
        }
        lStack_198 = lStack_198 + -1;
        puVar10 = auStack_1a8;
        if (0xf < uStack_190) {
          puVar10 = (undefined *)auStack_1a8._0_8_;
        }
        puVar10[lStack_198] = 0;
      }
    }
LAB_1800aeecc:
    if (0xf < uStack_190) {
      if ((0xfff < uStack_190 + 1) &&
         ((undefined *)0x1f <
          (undefined *)(auStack_1a8._0_8_ + (-8 - *(longlong *)(auStack_1a8._0_8_ + -8))))) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    lStack_198 = 0;
    uStack_190 = 0xf;
    auVar4[15] = 0;
    auVar4._0_15_ = auStack_1a8._1_15_;
    auStack_1a8 = auVar4 << 8;
  }
  *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) = &UNK_1801f22f0
  ;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
       *(int *)(apuStack_138[0] + 4) + -0xb0;
  func_0x0001800b7db0(apuStack_138 + 2);
  __1__basic_istream_DU__char_traits_D_std___std__UEAA_XZ(auStack_120);
  __1__basic_ios_DU__char_traits_D_std___std__UEAA_XZ(auStack_88);
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800aefe0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_1800aefe0(undefined8 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  longlong lVar5;
  
  lVar5 = fread(&DAT_181b2b400,0x6c,1,param_1);
  fVar1 = _DAT_181b2b410;
  if (lVar5 == 1) {
    _DAT_181b2b418 = 0;
    sVar4 = func_0x0001801cb4cb(_DAT_181b2b410);
    fVar3 = _DAT_181b2b428;
    fVar2 = _DAT_181a03428;
    if (((0 < sVar4) || (fVar1 < 0.0)) || (_DAT_181a03428 < fVar1)) {
      _DAT_181b2b410 = 1200.0;
    }
    if ((_DAT_181b2b420 & 0xfffffffd) != 0) {
      _DAT_181b2b420 = 0;
    }
    if (1 < _DAT_181b2b424) {
      _DAT_181b2b424 = 0;
    }
    sVar4 = func_0x0001801cb4cb(_DAT_181b2b428);
    if (((0 < sVar4) || (fVar3 < 0.0)) || (fVar2 < fVar3)) {
      _DAT_181b2b428 = 1200.0;
    }
    lVar5 = fread(&DAT_181b2b46c,0x118,1,param_1);
    if (lVar5 == 1) {
      if (2 < _DAT_181b2b470) {
        _DAT_181b2b470 = 0;
      }
      if (1 < _DAT_181b2b474) {
        _DAT_181b2b474 = 1;
      }
      if ((_DAT_181b2b578 < _DAT_181a03340) || (_DAT_181a033b4 < _DAT_181b2b578)) {
        _DAT_181b2b578 = 64.0;
      }
      if (3 < _DAT_181b2b520) {
        _DAT_181b2b520 = 2;
      }
      if (3 < _DAT_181b2b524) {
        _DAT_181b2b524 = 0;
      }
      if (3 < _DAT_181b2b528) {
        _DAT_181b2b528 = 2;
      }
      if (3 < _DAT_181b2b52c) {
        _DAT_181b2b52c = 3;
      }
      if (3 < _DAT_181b2b500) {
        _DAT_181b2b500 = 2;
      }
      if (3 < _DAT_181b2b518) {
        _DAT_181b2b518 = 3;
      }
      if (3 < _DAT_181b2b530) {
        _DAT_181b2b530 = 3;
      }
      if (3 < _DAT_181b2b534) {
        _DAT_181b2b534 = 2;
      }
      if (3 < _DAT_181b2b560) {
        _DAT_181b2b560 = 1;
      }
      if (1 < _DAT_181b2b49c) {
        _DAT_181b2b49c = 1;
      }
      lVar5 = fread(0x181b2b584,0x6e8,1,param_1);
      fVar2 = _DAT_181b2b5bc;
      fVar1 = _DAT_181a032ec;
      if (lVar5 == 1) {
        if (499 < _DAT_181b2b638 - 1U) {
          _DAT_181b2b638 = 8;
        }
        if ((_DAT_181b2b63c < _DAT_181a03230) || (_DAT_181a03414 < _DAT_181b2b63c)) {
          _DAT_181b2b63c = 200.0;
        }
        if ((_DAT_181b2b640 < _DAT_181a03230) || (_DAT_181a0336c < _DAT_181b2b640)) {
          _DAT_181b2b640 = 8.0;
        }
        if ((_DAT_181b2b644 < _DAT_181a0315c) || (_DAT_181a032ec < _DAT_181b2b644)) {
          _DAT_181b2b644 = 0.5;
        }
        if (1 < _DAT_181b2b634) {
          _DAT_181b2b634 = 0;
        }
        if ((_DAT_181b2b628 < _DAT_181a03230) || (_DAT_181a0336c < _DAT_181b2b628)) {
          _DAT_181b2b628 = 8.0;
        }
        if ((_DAT_181b2b62c < _DAT_181a0315c) || (_DAT_181a032ec < _DAT_181b2b62c)) {
          _DAT_181b2b62c = 1.0;
        }
        if (1 < _DAT_181b2b620) {
          _DAT_181b2b620 = 0;
        }
        if ((_DAT_181b2b590 < _DAT_181a0315c) || (_DAT_181a032b0 < _DAT_181b2b590)) {
          _DAT_181b2b590 = 1.0;
        }
        if ((_DAT_181b2bc64 < _DAT_181a03230) || (_DAT_181a0330c < _DAT_181b2bc64)) {
          _DAT_181b2bc64 = 5.0;
        }
        if (1 < _DAT_181b2b5b8) {
          _DAT_181b2b5b8 = 1;
        }
        sVar4 = func_0x0001801cb4cb(_DAT_181b2b5bc);
        if ((0 < sVar4) || (fVar2 < fVar1)) {
          _DAT_181b2b5bc = 500.0;
        }
        else if (_DAT_181a03434 < fVar2) {
          _DAT_181b2b5bc = 3000.0;
        }
        lVar5 = fread(&DAT_181b2bc6c,0x10c,1,param_1);
        if (((((lVar5 == 1) && (lVar5 = fread(0x181b30430,9999,1,param_1), lVar5 == 1)) &&
             (lVar5 = fread(&DAT_181b2f8c9,1,1,param_1), lVar5 == 1)) &&
            ((lVar5 = fread(0x181b32b80,0x2f90,1,param_1), lVar5 == 1 &&
             (lVar5 = fread(&DAT_181b32b7c,4,1,param_1), lVar5 == 1)))) &&
           ((((lVar5 = fread(&DAT_181b303b8,4,1,param_1), lVar5 == 1 &&
              ((lVar5 = fread(&DAT_181b32b54,4,1,param_1), lVar5 == 1 &&
               (lVar5 = fread(&DAT_181b32b64,4,1,param_1), lVar5 == 1)))) &&
             (lVar5 = fread(&DAT_181b32b4c,4,1,param_1), lVar5 == 1)) &&
            ((((lVar5 = fread(&DAT_181b303bc,4,1,param_1), lVar5 == 1 &&
               (lVar5 = fread(&DAT_181b30428,4,1,param_1), lVar5 == 1)) &&
              (lVar5 = fread(&DAT_181b30420,4,1,param_1), lVar5 == 1)) &&
             (((lVar5 = fread(&DAT_181b32b50,4,1,param_1), lVar5 == 1 &&
               (lVar5 = fread(&DAT_181ade2b8,4,1,param_1), lVar5 == 1)) &&
              ((lVar5 = fread(&DAT_181b32b78,4,1,param_1), lVar5 == 1 &&
               ((lVar5 = fread(&DAT_181b3042c,4,1,param_1), lVar5 == 1 &&
                (lVar5 = fread(&DAT_181b2bede,1,1,param_1), lVar5 == 1)))))))))))) {
          lVar5 = fread(&DAT_181ade1f8,4,1,param_1);
          if ((lVar5 != 1) || ((0xfd < _DAT_181ade1f8 - 1U || (_DAT_181ade1f8 == 0x24)))) {
            _DAT_181ade1f8 = 0x77;
          }
          lVar5 = fread(&DAT_181ade204,1,1,param_1);
          if (lVar5 != 1) {
            DAT_181ade204 = 1;
          }
          lVar5 = fread(&DAT_181b32b48,4,1,param_1);
          if (lVar5 != 1) {
            _DAT_181b32b48 = 0;
          }
          lVar5 = fread(&DAT_181b32b40,4,1,param_1);
          if (lVar5 != 1) {
            _DAT_181b32b40 = 0;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}



/* ===== ANALYSIS FUNCTION 0x1800af0d6 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_1800af0d6(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  longlong lVar4;
  uint unaff_EDI;
  
  if (2 < _DAT_181b2b470) {
    _DAT_181b2b470 = unaff_EDI;
  }
  if (1 < _DAT_181b2b474) {
    _DAT_181b2b474 = 1;
  }
  if ((_DAT_181b2b578 < _DAT_181a03340) || (_DAT_181a033b4 < _DAT_181b2b578)) {
    _DAT_181b2b578 = 64.0;
  }
  if (3 < _DAT_181b2b520) {
    _DAT_181b2b520 = 2;
  }
  if (3 < _DAT_181b2b524) {
    _DAT_181b2b524 = unaff_EDI;
  }
  if (3 < _DAT_181b2b528) {
    _DAT_181b2b528 = 2;
  }
  if (3 < _DAT_181b2b52c) {
    _DAT_181b2b52c = 3;
  }
  if (3 < _DAT_181b2b500) {
    _DAT_181b2b500 = 2;
  }
  if (3 < _DAT_181b2b518) {
    _DAT_181b2b518 = 3;
  }
  if (3 < _DAT_181b2b530) {
    _DAT_181b2b530 = 3;
  }
  if (3 < _DAT_181b2b534) {
    _DAT_181b2b534 = 2;
  }
  if (3 < _DAT_181b2b560) {
    _DAT_181b2b560 = 1;
  }
  if (1 < _DAT_181b2b49c) {
    _DAT_181b2b49c = 1;
  }
  lVar4 = fread(0x181b2b584,0x6e8,1);
  fVar2 = _DAT_181b2b5bc;
  fVar1 = _DAT_181a032ec;
  if (lVar4 == 1) {
    if (499 < _DAT_181b2b638 - 1U) {
      _DAT_181b2b638 = 8;
    }
    if ((_DAT_181b2b63c < _DAT_181a03230) || (_DAT_181a03414 < _DAT_181b2b63c)) {
      _DAT_181b2b63c = 200.0;
    }
    if ((_DAT_181b2b640 < _DAT_181a03230) || (_DAT_181a0336c < _DAT_181b2b640)) {
      _DAT_181b2b640 = 8.0;
    }
    if ((_DAT_181b2b644 < _DAT_181a0315c) || (_DAT_181a032ec < _DAT_181b2b644)) {
      _DAT_181b2b644 = 0.5;
    }
    if (1 < _DAT_181b2b634) {
      _DAT_181b2b634 = unaff_EDI;
    }
    if ((_DAT_181b2b628 < _DAT_181a03230) || (_DAT_181a0336c < _DAT_181b2b628)) {
      _DAT_181b2b628 = 8.0;
    }
    if ((_DAT_181b2b62c < _DAT_181a0315c) || (_DAT_181a032ec < _DAT_181b2b62c)) {
      _DAT_181b2b62c = 1.0;
    }
    if (1 < _DAT_181b2b620) {
      _DAT_181b2b620 = unaff_EDI;
    }
    if ((_DAT_181b2b590 < _DAT_181a0315c) || (_DAT_181a032b0 < _DAT_181b2b590)) {
      _DAT_181b2b590 = 1.0;
    }
    if ((_DAT_181b2bc64 < _DAT_181a03230) || (_DAT_181a0330c < _DAT_181b2bc64)) {
      _DAT_181b2bc64 = 5.0;
    }
    if (1 < _DAT_181b2b5b8) {
      _DAT_181b2b5b8 = 1;
    }
    sVar3 = func_0x0001801cb4cb(_DAT_181b2b5bc);
    if ((0 < sVar3) || (fVar2 < fVar1)) {
      _DAT_181b2b5bc = 500.0;
    }
    else if (_DAT_181a03434 < fVar2) {
      _DAT_181b2b5bc = 3000.0;
    }
    lVar4 = fread(&DAT_181b2bc6c,0x10c,1);
    if ((((((lVar4 == 1) && (lVar4 = fread(0x181b30430,9999,1), lVar4 == 1)) &&
          (lVar4 = fread(&DAT_181b2f8c9,1,1), lVar4 == 1)) &&
         ((lVar4 = fread(0x181b32b80,0x2f90,1), lVar4 == 1 &&
          (lVar4 = fread(&DAT_181b32b7c,4,1), lVar4 == 1)))) &&
        (((lVar4 = fread(&DAT_181b303b8,4,1), lVar4 == 1 &&
          ((lVar4 = fread(&DAT_181b32b54,4,1), lVar4 == 1 &&
           (lVar4 = fread(&DAT_181b32b64,4,1), lVar4 == 1)))) &&
         (lVar4 = fread(&DAT_181b32b4c,4,1), lVar4 == 1)))) &&
       ((((lVar4 = fread(&DAT_181b303bc,4,1), lVar4 == 1 &&
          (lVar4 = fread(&DAT_181b30428,4,1), lVar4 == 1)) &&
         (lVar4 = fread(&DAT_181b30420,4,1), lVar4 == 1)) &&
        (((lVar4 = fread(&DAT_181b32b50,4,1), lVar4 == 1 &&
          (lVar4 = fread(&DAT_181ade2b8,4,1), lVar4 == 1)) &&
         ((lVar4 = fread(&DAT_181b32b78,4,1), lVar4 == 1 &&
          ((lVar4 = fread(&DAT_181b3042c,4,1), lVar4 == 1 &&
           (lVar4 = fread(&DAT_181b2bede,1,1), lVar4 == 1)))))))))) {
      lVar4 = fread(&DAT_181ade1f8,4,1);
      if ((lVar4 != 1) || ((0xfd < _DAT_181ade1f8 - 1U || (_DAT_181ade1f8 == 0x24)))) {
        _DAT_181ade1f8 = 0x77;
      }
      lVar4 = fread(&DAT_181ade204,1,1);
      if (lVar4 != 1) {
        DAT_181ade204 = 1;
      }
      lVar4 = fread(&DAT_181b32b48,4,1);
      if (lVar4 != 1) {
        _DAT_181b32b48 = unaff_EDI;
      }
      lVar4 = fread(&DAT_181b32b40,4,1);
      if (lVar4 != 1) {
        _DAT_181b32b40 = unaff_EDI;
      }
      return 1;
    }
  }
  return 0;
}



/* ===== ANALYSIS FUNCTION 0x1800af710 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800af710(void)

{
  longlong lVar1;
  
  lVar1 = fopen(&UNK_1819dce90,&UNK_1819dcedc);
  if (lVar1 != 0) {
    fwrite(&DAT_181b2b400,0x6c,1,lVar1);
    fwrite(&DAT_181b2b46c,0x118,1,lVar1);
    fwrite(0x181b2b584,0x6e8,1,lVar1);
    fwrite(&DAT_181b2bc6c,0x10c,1,lVar1);
    fwrite(0x181b30430,9999,1,lVar1);
    fwrite(&DAT_181b2f8c9,1,1,lVar1);
    fwrite(0x181b32b80,0x2f90,1,lVar1);
    fwrite(&DAT_181b32b7c,4,1,lVar1);
    fwrite(&DAT_181b303b8,4,1,lVar1);
    fwrite(&DAT_181b32b54,4,1,lVar1);
    fwrite(&DAT_181b32b64,4,1,lVar1);
    fwrite(&DAT_181b32b4c,4,1,lVar1);
    fwrite(&DAT_181b303bc,4,1,lVar1);
    fwrite(&DAT_181b30428,4,1,lVar1);
    fwrite(&DAT_181b30420,4,1,lVar1);
    fwrite(&DAT_181b32b50,4,1,lVar1);
    fwrite(&DAT_181ade2b8,4,1,lVar1);
    fwrite(&DAT_181b32b78,4,1,lVar1);
    fwrite(&DAT_181b3042c,4,1,lVar1);
    fwrite(&DAT_181b2bede,1,1,lVar1);
    fwrite(&DAT_181ade1f8,4,1,lVar1);
    fwrite(&DAT_181ade204,1,1,lVar1);
    fwrite(&DAT_181b32b48,4,1,lVar1);
    fwrite(&DAT_181b32b40,4,1,lVar1);
                    /* WARNING: Could not recover jumptable at 0x0001800af9bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    fclose(lVar1);
    return;
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800afa60 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800afa60(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined8 uVar17;
  undefined4 *puVar18;
  undefined8 *puVar19;
  longlong lVar20;
  undefined8 *puVar21;
  longlong lVar22;
  undefined8 uStack_6fc;
  undefined4 uStack_6f4;
  undefined uStack_6f0;
  undefined auStack_6ef [16];
  undefined auStack_6df [16];
  undefined auStack_6cf [16];
  undefined8 uStack_6bf;
  undefined8 uStack_6b7;
  undefined auStack_6af [16];
  undefined auStack_69f [16];
  undefined auStack_68f [16];
  undefined8 uStack_67f;
  undefined8 uStack_677;
  undefined auStack_66f [16];
  undefined auStack_65f [16];
  undefined auStack_64f [16];
  undefined auStack_63f [16];
  undefined auStack_62f [16];
  undefined auStack_61f [16];
  undefined auStack_60f [16];
  undefined8 uStack_5ff;
  undefined4 uStack_5f7;
  undefined2 uStack_5f3;
  undefined uStack_5f1;
  
  _DAT_181b2b468 = 0;
  _DAT_181b2b400 = 0;
  uRam0000000181b2b404 = 0;
  uRam0000000181b2b408 = 0;
  _DAT_181b2b40c = 100;
  _DAT_181b2b410 = 0x44960000;
  _DAT_181b2b414 = 1;
  _DAT_181b2b418 = 0;
  uRam0000000181b2b41c = 0;
  _DAT_181b2b420 = 0;
  _DAT_181b2b424 = 0;
  _DAT_181b2b428 = 0x44960000;
  uRam0000000181b2b42c = 0x3f800000;
  _DAT_181b2b430 = 0;
  uRam0000000181b2b434 = 0x3f800000;
  uRam0000000181b2b438 = 0;
  uRam0000000181b2b43c = 0;
  _DAT_181b2b440 = 0;
  _DAT_181b2b444 = 0;
  uRam0000000181b2b448 = _DAT_181a036d0;
  _DAT_181b2b44c = _UNK_181a036d4;
  _DAT_181b2b460 = 0x42f0000000000096;
  _DAT_181b2b450 = _UNK_181a036d8;
  uRam0000000181b2b454 = _UNK_181a036dc;
  uRam0000000181b2b458 = 5;
  uRam0000000181b2b45c = 0x14;
  func_0x0001801ca899(&uStack_6fc,0,0x118);
  puVar15 = (undefined4 *)func_0x000180052c60(&uStack_6fc);
  lVar22 = 2;
  lVar20 = 2;
  puVar13 = (undefined4 *)&DAT_181b2b46c;
  do {
    puVar18 = puVar13;
    puVar16 = puVar15;
    uVar1 = puVar16[1];
    uVar2 = puVar16[2];
    uVar3 = puVar16[3];
    *puVar18 = *puVar16;
    puVar18[1] = uVar1;
    puVar18[2] = uVar2;
    puVar18[3] = uVar3;
    uVar1 = puVar16[5];
    uVar2 = puVar16[6];
    uVar3 = puVar16[7];
    puVar18[4] = puVar16[4];
    puVar18[5] = uVar1;
    puVar18[6] = uVar2;
    puVar18[7] = uVar3;
    uVar1 = puVar16[9];
    uVar2 = puVar16[10];
    uVar3 = puVar16[0xb];
    puVar18[8] = puVar16[8];
    puVar18[9] = uVar1;
    puVar18[10] = uVar2;
    puVar18[0xb] = uVar3;
    uVar1 = puVar16[0xd];
    uVar2 = puVar16[0xe];
    uVar3 = puVar16[0xf];
    puVar18[0xc] = puVar16[0xc];
    puVar18[0xd] = uVar1;
    puVar18[0xe] = uVar2;
    puVar18[0xf] = uVar3;
    uVar1 = puVar16[0x11];
    uVar2 = puVar16[0x12];
    uVar3 = puVar16[0x13];
    puVar18[0x10] = puVar16[0x10];
    puVar18[0x11] = uVar1;
    puVar18[0x12] = uVar2;
    puVar18[0x13] = uVar3;
    uVar1 = puVar16[0x15];
    uVar2 = puVar16[0x16];
    uVar3 = puVar16[0x17];
    puVar18[0x14] = puVar16[0x14];
    puVar18[0x15] = uVar1;
    puVar18[0x16] = uVar2;
    puVar18[0x17] = uVar3;
    uVar1 = puVar16[0x19];
    uVar2 = puVar16[0x1a];
    uVar3 = puVar16[0x1b];
    puVar18[0x18] = puVar16[0x18];
    puVar18[0x19] = uVar1;
    puVar18[0x1a] = uVar2;
    puVar18[0x1b] = uVar3;
    uVar1 = puVar16[0x1d];
    uVar2 = puVar16[0x1e];
    uVar3 = puVar16[0x1f];
    puVar18[0x1c] = puVar16[0x1c];
    puVar18[0x1d] = uVar1;
    puVar18[0x1e] = uVar2;
    puVar18[0x1f] = uVar3;
    lVar20 = lVar20 + -1;
    puVar15 = puVar16 + 0x20;
    puVar13 = puVar18 + 0x20;
  } while (lVar20 != 0);
  uVar1 = puVar16[0x21];
  uVar2 = puVar16[0x22];
  uVar3 = puVar16[0x23];
  puVar18[0x20] = puVar16[0x20];
  puVar18[0x21] = uVar1;
  puVar18[0x22] = uVar2;
  puVar18[0x23] = uVar3;
  _DAT_181b2b4a8 = _UNK_181a03978;
  _DAT_181b2b4a0 = _DAT_181a03970;
  *(undefined8 *)(puVar18 + 0x24) = *(undefined8 *)(puVar16 + 0x24);
  DAT_181b2b46c = 1;
  _DAT_181b2b57c = 0xa0;
  _DAT_181b2b478 = 0x3f800000;
  _DAT_181b2b47c = 0x3f800000;
  _DAT_181b2b480 = 0x3f800000;
  _DAT_181b2b484 = 0x3f800000;
  _DAT_181b2b53c = 0x3f800000;
  _DAT_181b2b540 = 0x3f800000;
  _DAT_181b2b544 = 0x3f800000;
  _DAT_181b2b548 = 0x3f800000;
  _DAT_181b2b4c8 = 0x3f800000;
  _DAT_181b2b4cc = 0x3f800000;
  _DAT_181b2b4d0 = 0x3f800000;
  _DAT_181b2b4d4 = 0x3f800000;
  _DAT_181b2b4dc = 0x3f800000;
  _DAT_181b2b4e0 = 0x3f800000;
  _DAT_181b2b4e4 = 0x3f800000;
  _DAT_181b2b4e8 = 0x3f800000;
  _DAT_181b2b550 = _DAT_181b2b4a0;
  uRam0000000181b2b558 = _DAT_181b2b4a8;
  func_0x0001801ca899(&uStack_6fc,0,0x6e8);
  uVar17 = func_0x000180052e70(&uStack_6fc);
  func_0x0001800afec0(0x181b2b584,uVar17);
  func_0x0001801ca899(&uStack_6fc,0,0x10c);
  auStack_6ef = ZEXT816(0);
  uStack_6fc._2_4_ = 1;
  uStack_6f4 = 1;
  uStack_6bf = 0;
  auStack_6df = auStack_6ef;
  uStack_6b7 = 0;
  auStack_6cf = auStack_6ef;
  uStack_67f = 0;
  auStack_6af = auStack_6ef;
  uStack_677 = 0;
  auStack_69f = auStack_6ef;
  uStack_5ff = 0;
  auStack_68f = auStack_6ef;
  uStack_5f7 = 0;
  auStack_66f = auStack_6ef;
  uStack_5f3 = 0;
  auStack_65f = auStack_6ef;
  uStack_5f1 = 0;
  auStack_64f = auStack_6ef;
  uStack_6f0 = 0;
  auStack_63f = auStack_6ef;
  auStack_62f = auStack_6ef;
  auStack_61f = auStack_6ef;
  auStack_60f = auStack_6ef;
  puVar12 = (undefined8 *)&DAT_181b2bc6c;
  puVar14 = &uStack_6fc;
  do {
    puVar21 = puVar14;
    puVar19 = puVar12;
    uVar1 = *(undefined4 *)((longlong)puVar21 + 4);
    uVar2 = *(undefined4 *)(puVar21 + 1);
    uVar3 = *(undefined4 *)((longlong)puVar21 + 0xc);
    uVar4 = *(undefined4 *)(puVar21 + 2);
    uVar5 = *(undefined4 *)((longlong)puVar21 + 0x14);
    uVar6 = *(undefined4 *)(puVar21 + 3);
    uVar7 = *(undefined4 *)((longlong)puVar21 + 0x1c);
    *(undefined4 *)puVar19 = *(undefined4 *)puVar21;
    *(undefined4 *)((longlong)puVar19 + 4) = uVar1;
    *(undefined4 *)(puVar19 + 1) = uVar2;
    *(undefined4 *)((longlong)puVar19 + 0xc) = uVar3;
    uVar1 = *(undefined4 *)(puVar21 + 4);
    uVar2 = *(undefined4 *)((longlong)puVar21 + 0x24);
    uVar3 = *(undefined4 *)(puVar21 + 5);
    uVar8 = *(undefined4 *)((longlong)puVar21 + 0x2c);
    *(undefined4 *)(puVar19 + 2) = uVar4;
    *(undefined4 *)((longlong)puVar19 + 0x14) = uVar5;
    *(undefined4 *)(puVar19 + 3) = uVar6;
    *(undefined4 *)((longlong)puVar19 + 0x1c) = uVar7;
    uVar4 = *(undefined4 *)(puVar21 + 6);
    uVar5 = *(undefined4 *)((longlong)puVar21 + 0x34);
    uVar6 = *(undefined4 *)(puVar21 + 7);
    uVar7 = *(undefined4 *)((longlong)puVar21 + 0x3c);
    *(undefined4 *)(puVar19 + 4) = uVar1;
    *(undefined4 *)((longlong)puVar19 + 0x24) = uVar2;
    *(undefined4 *)(puVar19 + 5) = uVar3;
    *(undefined4 *)((longlong)puVar19 + 0x2c) = uVar8;
    uVar1 = *(undefined4 *)(puVar21 + 8);
    uVar2 = *(undefined4 *)((longlong)puVar21 + 0x44);
    uVar3 = *(undefined4 *)(puVar21 + 9);
    uVar8 = *(undefined4 *)((longlong)puVar21 + 0x4c);
    *(undefined4 *)(puVar19 + 6) = uVar4;
    *(undefined4 *)((longlong)puVar19 + 0x34) = uVar5;
    *(undefined4 *)(puVar19 + 7) = uVar6;
    *(undefined4 *)((longlong)puVar19 + 0x3c) = uVar7;
    uVar4 = *(undefined4 *)(puVar21 + 10);
    uVar5 = *(undefined4 *)((longlong)puVar21 + 0x54);
    uVar6 = *(undefined4 *)(puVar21 + 0xb);
    uVar7 = *(undefined4 *)((longlong)puVar21 + 0x5c);
    *(undefined4 *)(puVar19 + 8) = uVar1;
    *(undefined4 *)((longlong)puVar19 + 0x44) = uVar2;
    *(undefined4 *)(puVar19 + 9) = uVar3;
    *(undefined4 *)((longlong)puVar19 + 0x4c) = uVar8;
    uVar8 = *(undefined4 *)(puVar21 + 0xc);
    uVar9 = *(undefined4 *)((longlong)puVar21 + 100);
    uVar10 = *(undefined4 *)(puVar21 + 0xd);
    uVar11 = *(undefined4 *)((longlong)puVar21 + 0x6c);
    *(undefined4 *)(puVar19 + 10) = uVar4;
    *(undefined4 *)((longlong)puVar19 + 0x54) = uVar5;
    *(undefined4 *)(puVar19 + 0xb) = uVar6;
    *(undefined4 *)((longlong)puVar19 + 0x5c) = uVar7;
    uVar1 = *(undefined4 *)(puVar21 + 0xe);
    uVar2 = *(undefined4 *)((longlong)puVar21 + 0x74);
    uVar3 = *(undefined4 *)(puVar21 + 0xf);
    uVar4 = *(undefined4 *)((longlong)puVar21 + 0x7c);
    *(undefined4 *)(puVar19 + 0xc) = uVar8;
    *(undefined4 *)((longlong)puVar19 + 100) = uVar9;
    *(undefined4 *)(puVar19 + 0xd) = uVar10;
    *(undefined4 *)((longlong)puVar19 + 0x6c) = uVar11;
    *(undefined4 *)(puVar19 + 0xe) = uVar1;
    *(undefined4 *)((longlong)puVar19 + 0x74) = uVar2;
    *(undefined4 *)(puVar19 + 0xf) = uVar3;
    *(undefined4 *)((longlong)puVar19 + 0x7c) = uVar4;
    lVar22 = lVar22 + -1;
    puVar12 = puVar19 + 0x10;
    puVar14 = puVar21 + 0x10;
  } while (lVar22 != 0);
  puVar19[0x10] = puVar21[0x10];
  *(undefined4 *)(puVar19 + 0x11) = *(undefined4 *)(puVar21 + 0x11);
  DAT_181b2bc6e = 1;
  func_0x0001801ca899(0x181b30430,0,9999);
  func_0x0001801ca899(0x181b32b80,0,0x2f90);
  DAT_181b2f8c9 = 0;
  _DAT_181b32b7c = 0;
  _DAT_181b303b8 = 0;
  _DAT_181b32b54 = 0;
  _DAT_181b32b64 = 0;
  _DAT_181b32b4c = 0;
  _DAT_181b303bc = 0;
  _DAT_181b30428 = 0;
  _DAT_181b30420 = 0;
  _DAT_181b32b50 = 0;
  _DAT_181ade2b8 = 0;
  _DAT_181b32b78 = 0;
  _DAT_181b3042c = 0;
  _DAT_181b32b48 = 0;
  _DAT_181b32b40 = 0;
  _DAT_181ade1f8 = 0x77;
  DAT_181ade204 = 1;
  _DAT_181b32b60 = 0;
  DAT_181b2f6dd = 1;
  DAT_181b2bede = 0;
                    /* WARNING: Could not recover jumptable at 0x0001800afeab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  remove(&UNK_1819dce90);
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800b16a0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800b16a0(longlong *param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  uint **ppuVar5;
  undefined8 *puVar6;
  int aiStackX_8 [2];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  uint *apuStack_88 [14];
  uint *puStack_18;
  undefined4 uStack_10;
  
  *(undefined *)(param_1 + 3) = 1;
  if (*param_1 != 0) {
    iVar3 = IsWindow();
    if (iVar3 != 0) {
      SetWindowLongPtrA(*param_1,0xffffffec,0x88);
      SetForegroundWindow(*param_1);
      SetWindowPos(*param_1,0xffffffffffffffff,0,0,0,0,0x23);
      iVar3 = InitOnceBeginInitialize(0x181b4f0d8,0,aiStackX_8,0);
      if (iVar3 == 0) {
        abort();
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (aiStackX_8[0] != 0) {
        puStack_18 = (uint *)0x181b4f0d8;
        uStack_10 = 4;
        func_0x00018013c850(0x181b50a20);
        iVar3 = InitOnceComplete(0x181b4f0d8,0,0);
        if (iVar3 == 0) {
          func_0x00018012791c();
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      lVar4 = fopen(&UNK_1819dce90,&UNK_180213188);
      if (lVar4 != 0) {
        cVar2 = recovered_1800aefe0(lVar4);
        if (cVar2 == '\0') {
          fclose(lVar4);
        }
        else {
          _DAT_181b32b60 = (uint)(DAT_181ade204 == '\0');
          DAT_181b2f6dd = 1;
          apuStack_88[0] = (uint *)&DAT_181b32b7c;
          apuStack_88[1] = (uint *)&DAT_181b303b8;
          apuStack_88[2] = (uint *)&DAT_181b32b54;
          apuStack_88[3] = (uint *)&DAT_181b32b64;
          apuStack_88[4] = (uint *)&DAT_181b32b4c;
          apuStack_88[5] = (uint *)&DAT_181b303bc;
          apuStack_88[6] = (uint *)&DAT_181b30428;
          apuStack_88[7] = (uint *)&DAT_181b30420;
          apuStack_88[8] = (uint *)&DAT_181b32b50;
          apuStack_88[9] = (uint *)&DAT_181ade2b8;
          apuStack_88[10] = (uint *)&DAT_181b32b78;
          apuStack_88[11] = (uint *)&DAT_181b3042c;
          apuStack_88[12] = (uint *)&DAT_181b32b48;
          apuStack_88[13] = (uint *)&DAT_181b32b40;
          ppuVar5 = apuStack_88;
          do {
            if (0xff < **ppuVar5) {
              **ppuVar5 = 0;
            }
            ppuVar5 = ppuVar5 + 1;
          } while (ppuVar5 != &puStack_18);
          fclose(lVar4);
          uStack_b8 = _DAT_181a03720;
          uStack_b0 = _UNK_181a03728;
          uStack_a8 = _DAT_181a03750;
          uStack_a4 = _UNK_181a03754;
          uStack_a0 = _UNK_181a03758;
          uStack_9c = _UNK_181a0375c;
          uStack_98 = 0x172b;
          uStack_94 = 0x23c2;
          puVar6 = &uStack_b8;
          do {
            *(undefined *)((longlong)*(int *)puVar6 + 0x181b30430) = 0;
            puVar6 = (undefined8 *)((longlong)puVar6 + 4);
          } while (puVar6 != &uStack_90);
          DAT_181b2b58c = 0;
          LOCK();
          DAT_181b2f6d9 = 0;
          UNLOCK();
          _DAT_181b3031c = 0;
          DAT_181b2bc60 = 0;
          LOCK();
          DAT_181b2f64c = 0;
          UNLOCK();
          DAT_181b2f64d = 0;
          DAT_181b2bc69 = 0;
          DAT_181b2b5f1 = 0;
          LOCK();
          DAT_181b2f64a = 0;
          UNLOCK();
          DAT_181b2f8c9 = 0;
          DAT_181b2b403 = 0;
          _DAT_181b2b430 = 0;
          DAT_181b2b432 = 0;
          LOCK();
          DAT_181b2f6df = 0;
          UNLOCK();
          LOCK();
          DAT_181b2f8cb = 0;
          UNLOCK();
          DAT_181b2bc71 = 0;
          DAT_181b2bc6c = 0;
          DAT_181a2b040 = DAT_181b2bc70 == '\0';
        }
      }
      recovered_1800aeb50();
    }
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800b1990 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800b1990(longlong param_1)

{
  double dVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  undefined8 uVar19;
  longlong lVar20;
  longlong lVar21;
  longlong *plVar22;
  float *pfVar23;
  float *pfVar24;
  longlong lVar25;
  longlong lVar26;
  undefined *puVar27;
  ulonglong uVar28;
  undefined8 *puVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  longlong unaff_GS_OFFSET;
  float fVar32;
  float fVar33;
  float fVar34;
  undefined8 uVar35;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qb;
  undefined auVar36 [16];
  undefined auVar37 [16];
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  undefined8 in_stack_fffffffffffffde8;
  undefined8 uVar43;
  undefined8 *in_stack_fffffffffffffdf0;
  ulonglong uVar44;
  undefined8 **ppuVar45;
  undefined8 in_stack_fffffffffffffdf8;
  undefined8 in_stack_fffffffffffffe00;
  undefined *puVar46;
  undefined8 uStack_1e8;
  undefined8 *apuStack_1e0 [3];
  undefined auStack_1c8 [16];
  undefined8 *puStack_1b8;
  undefined8 **ppuStack_1a8;
  float fStack_1a0;
  float fStack_19c;
  undefined8 *puStack_198;
  undefined4 uStack_190;
  float fStack_18c;
  undefined8 uStack_188;
  int iStack_180;
  float fStack_17c;
  undefined4 uStack_178;
  undefined8 *apuStack_168 [7];
  undefined8 **ppuStack_130;
  undefined8 uStack_128;
  float fStack_120;
  float fStack_11c;
  undefined8 uStack_118;
  int iStack_110;
  float fStack_10c;
  undefined8 uStack_108;
  float afStack_100 [2];
  longlong lStack_f8;
  
  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffdf8 >> 0x20);
  uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffe00 >> 0x20);
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffde8 >> 0x20);
  DAT_181b2bc71 = *(undefined *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x18) == '\0') {
    func_0x00018009bde0();
    return;
  }
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0xbe8);
  }
  lVar26 = _DAT_181b2f2c0;
  fVar40 = _DAT_181a03230;
  lStack_f8 = _DAT_181b2f2c0;
  if ((DAT_181b2bc6e != '\0') && (DAT_181b2bc70 == '\0')) {
    func_0x0001801cb4f5((float)*(double *)(_DAT_181b2f2c0 + 0x3e60) * _DAT_181a0315c);
    in_stack_fffffffffffffdf0 = &uStackX_8;
    uVar7 = (undefined4)((ulonglong)&uStackX_10 >> 0x20);
    func_0x0001800050f0();
    puVar13 = (undefined4 *)func_0x000180002310(&uStack_188);
    _DAT_181a2aff0 = *puVar13;
    _DAT_181a2aff4 = puVar13[1];
    _DAT_181a2aff8 = puVar13[2];
    _DAT_181a2affc = (float)puVar13[3];
  }
  uVar30 = (ulonglong)__tls_index;
  lVar25 = *(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + uVar30 * 8);
  uVar28 = 0;
  if ((*(int *)(lVar25 + 4) < _DAT_181b50e68) &&
     (func_0x000180127a18(&DAT_181b50e68), _DAT_181b50e68 == -1)) {
    _DAT_181b509b8 = ZEXT816(0);
    _DAT_181b509c8 = (undefined8 *)0x0;
    func_0x000180127e28(&UNK_1801d1260);
    func_0x0001801279ac(&DAT_181b50e68);
  }
  if (DAT_181b4f07a == '\0') {
    uStackX_8 = &UNK_1819dcee0;
    puVar14 = (undefined8 *)func_0x000180024110(8);
    puVar18 = puVar14 + 1;
    *puVar14 = uStackX_8;
    uStackX_10 = &UNK_1819dcf0c;
    auStack_1c8 = ZEXT816(0);
    puStack_1b8 = (undefined8 *)0x0;
    apuStack_1e0[0] = puVar14;
    apuStack_1e0[1] = puVar18;
    apuStack_1e0[2] = puVar18;
    puVar15 = (undefined8 *)func_0x000180024110(8);
    puVar16 = puVar15 + 1;
    *puVar15 = uStackX_10;
    auStack_1c8._8_8_ = puVar16;
    auStack_1c8._0_8_ = puVar15;
    puVar29 = _DAT_181b509c0;
    if (_DAT_181b509c0 == _DAT_181b509c8) {
      puStack_1b8 = puVar16;
      func_0x0001800ba260(uStackX_10,_DAT_181b509c0,apuStack_1e0);
    }
    else {
      apuStack_1e0[2] = (undefined8 *)0x0;
      apuStack_1e0[1] = (undefined8 *)0x0;
      apuStack_1e0[0] = (undefined8 *)0x0;
      *_DAT_181b509c0 = puVar14;
      puVar29[1] = puVar18;
      puVar29[2] = puVar18;
      puStack_1b8 = (undefined8 *)0x0;
      auStack_1c8 = ZEXT816(0);
      puVar29[3] = puVar15;
      puVar29[4] = puVar16;
      puVar29[5] = puVar16;
      _DAT_181b509c0 = (undefined8 *)((longlong)_DAT_181b509c0 + 0x30);
    }
    func_0x000180066b10(auStack_1c8);
    func_0x000180066b10(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf08;
    puVar14 = (undefined8 *)func_0x000180024110(8);
    puVar18 = puVar14 + 1;
    *puVar14 = uStackX_8;
    uStackX_10 = &UNK_1819dcf14;
    auStack_1c8 = ZEXT816(0);
    puStack_1b8 = (undefined8 *)0x0;
    apuStack_1e0[0] = puVar14;
    apuStack_1e0[1] = puVar18;
    apuStack_1e0[2] = puVar18;
    puVar15 = (undefined8 *)func_0x000180024110(8);
    puVar16 = puVar15 + 1;
    *puVar15 = uStackX_10;
    auStack_1c8._8_8_ = puVar16;
    auStack_1c8._0_8_ = puVar15;
    puVar29 = _DAT_181b509c0;
    if (_DAT_181b509c0 == _DAT_181b509c8) {
      puStack_1b8 = puVar16;
      func_0x0001800ba260(uStackX_10,_DAT_181b509c0,apuStack_1e0);
    }
    else {
      apuStack_1e0[2] = (undefined8 *)0x0;
      apuStack_1e0[1] = (undefined8 *)0x0;
      apuStack_1e0[0] = (undefined8 *)0x0;
      *_DAT_181b509c0 = puVar14;
      puVar29[1] = puVar18;
      puVar29[2] = puVar18;
      puStack_1b8 = (undefined8 *)0x0;
      auStack_1c8 = ZEXT816(0);
      puVar29[3] = puVar15;
      puVar29[4] = puVar16;
      puVar29[5] = puVar16;
      _DAT_181b509c0 = (undefined8 *)((longlong)_DAT_181b509c0 + 0x30);
    }
    func_0x000180066b10(auStack_1c8);
    func_0x000180066b10(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf10;
    puVar14 = (undefined8 *)func_0x000180024110(8);
    puVar18 = puVar14 + 1;
    *puVar14 = &UNK_1819dcf10;
    uStackX_10 = &UNK_1819dcf20;
    auStack_1c8 = ZEXT816(0);
    puStack_1b8 = (undefined8 *)0x0;
    apuStack_1e0[0] = puVar14;
    apuStack_1e0[1] = puVar18;
    apuStack_1e0[2] = puVar18;
    puVar15 = (undefined8 *)func_0x000180024110(8);
    puVar16 = puVar15 + 1;
    *puVar15 = &UNK_1819dcf20;
    auStack_1c8._8_8_ = puVar16;
    auStack_1c8._0_8_ = puVar15;
    puVar29 = _DAT_181b509c0;
    if (_DAT_181b509c0 == _DAT_181b509c8) {
      puStack_1b8 = puVar16;
      func_0x0001800ba260(puVar16,_DAT_181b509c0,apuStack_1e0);
    }
    else {
      apuStack_1e0[2] = (undefined8 *)0x0;
      apuStack_1e0[1] = (undefined8 *)0x0;
      apuStack_1e0[0] = (undefined8 *)0x0;
      *_DAT_181b509c0 = puVar14;
      puVar29[1] = puVar18;
      puVar29[2] = puVar18;
      puStack_1b8 = (undefined8 *)0x0;
      auStack_1c8 = ZEXT816(0);
      puVar29[3] = puVar15;
      puVar29[4] = puVar16;
      puVar29[5] = puVar16;
      _DAT_181b509c0 = (undefined8 *)((longlong)_DAT_181b509c0 + 0x30);
    }
    func_0x0001800b59f0(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf1c;
    apuStack_168[0] = &uStackX_8;
    apuStack_168[1] = &uStackX_10;
    func_0x0001800b7070(apuStack_1e0,apuStack_168);
    uStackX_10 = &UNK_1819dcf30;
    apuStack_168[0] = &uStackX_10;
    apuStack_168[1] = &uStackX_18;
    uVar35 = func_0x0001800b7070(auStack_1c8,apuStack_168);
    func_0x0001800b6ee0(uVar35,apuStack_1e0);
    func_0x0001800b59f0(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf28;
    apuStack_168[0] = &uStackX_8;
    apuStack_168[1] = &uStackX_10;
    func_0x0001800b7070(apuStack_1e0,apuStack_168);
    uStackX_10 = &UNK_180213280;
    apuStack_168[0] = &uStackX_10;
    apuStack_168[1] = &uStackX_18;
    uVar35 = func_0x0001800b7070(auStack_1c8,apuStack_168);
    func_0x0001800b6ee0(uVar35,apuStack_1e0);
    func_0x0001800b59f0(apuStack_1e0);
    DAT_181b4f07a = '\x01';
    lVar26 = lStack_f8;
  }
  if ((*(int *)(lVar25 + 4) < _DAT_181b50a1c) &&
     (func_0x000180127a18(&DAT_181b50a1c), _DAT_181b50a1c == -1)) {
    uVar35 = func_0x0001800b6f60(apuStack_1e0);
    func_0x0001800a0b40(extraout_XMM0_Qa,uVar35);
    func_0x000180127e28(&UNK_1801d1250);
    func_0x0001801279ac(&DAT_181b50a1c);
  }
  if ((*(int *)(lVar25 + 4) < _DAT_181b509b0) &&
     (func_0x000180127a18(&DAT_181b509b0), _DAT_181b509b0 == -1)) {
    func_0x0001800a0fd0();
    func_0x000180127e28(&UNK_1801d1240);
    func_0x0001801279ac(&DAT_181b509b0);
  }
  _DAT_181b32b68 = _DAT_181b2f370;
  _DAT_181b32b58 = _DAT_181b2f388;
  if ((((_DAT_181b2f370 != 0) && (_DAT_181b2f388 != 0)) && (_DAT_181b32b70 != 0)) &&
     (_DAT_181b35b10 != 0)) {
    DAT_181a2b040 = DAT_181b2bc70 == '\0';
    func_0x00018009c7f0();
    func_0x00018009c6b0();
    if (DAT_181b2bc70 == '\0') {
      apuStack_168[0] = (undefined8 *)CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
      apuStack_168[1] = (undefined8 *)CONCAT44(_DAT_181a2affc,_DAT_181a2aff8);
      func_0x0001800a1ad0();
      apuStack_168[0] = (undefined8 *)CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
      apuStack_168[1] = (undefined8 *)CONCAT44(_DAT_181a2affc,_DAT_181a2aff8);
      func_0x0001800a2d10();
    }
  }
  if (DAT_181b4f090 == '\0') {
    func_0x0001800a1030();
    recovered_180085a10(_DAT_181b2f350);
    DAT_181b4f090 = '\x01';
  }
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
  }
  lVar20 = _DAT_181b2f2c0;
  fVar38 = *(float *)(_DAT_181b2f2c0 + 0x1c) * _DAT_181a03314;
  if (DAT_181b2f8ca == '\0') {
    _DAT_181b32b44 = (0.0 - _DAT_181b32b44) * fVar38 + _DAT_181b32b44;
  }
  else {
    _DAT_181b32b44 = _DAT_181b32b44 + (_DAT_181a03420 - _DAT_181b32b44) * fVar38;
    if ((float)((uint)(_DAT_181b32b44 - _DAT_181a03420) & _DAT_181a039d0) < _DAT_181a0333c) {
      DAT_181b2f8ca = '\0';
    }
  }
  *(uint *)(_DAT_181b2f2c0 + 0x47f8) = *(uint *)(_DAT_181b2f2c0 + 0x47f8) | 2;
  *(ulonglong *)(lVar20 + 0x4818) = CONCAT44(_DAT_181b2b284,_DAT_181b2b280);
  *(undefined4 *)(lVar20 + 0x4800) = 1;
  func_0x000180011340(&UNK_1819d8b00,0,0x20c3);
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
  }
  lVar21 = _DAT_181b2f2c0;
  _DAT_181b4eed0 = *(float *)(_DAT_181b2f2c0 + 0x1c) * _DAT_181a032fc;
  lVar20 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
  fVar38 = *(float *)(undefined8 *)(lVar20 + 0x20);
  uStackX_8 = (undefined *)CONCAT44(uStackX_8._4_4_,fVar38);
  fVar41 = *(float *)(lVar20 + 0x24);
  uStackX_18 = *(undefined8 *)(lVar20 + 0x20);
  uStackX_10 = (undefined *)CONCAT44(uStackX_10._4_4_,fVar41);
  _DAT_181ade2e0 = (fVar40 - _DAT_181ade2e0) * _DAT_181b4eed0 + _DAT_181ade2e0;
  *(undefined *)(lVar20 + 0xb8) = 1;
  lVar20 = *(longlong *)(lVar21 + 0x3f10);
  _DAT_181b4eec4 = *(float *)(lVar20 + 0x24);
  _DAT_181b4eecc = _DAT_181b4eec4 + *(float *)(lVar20 + 0x2c);
  _DAT_181b4eec0 = *(float *)(lVar20 + 0x20);
  _DAT_181b4eec8 = _DAT_181b4eec0 + *(float *)(lVar20 + 0x28);
  uStack_108 = uStackX_18;
  func_0x000180016100(0,0,0);
  *(float *)(lVar26 + 0x37d0) = _DAT_181ade2e0;
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181a2b0a4,_DAT_181a2b0a0);
  uStack_190 = _DAT_181a2b0a8;
  fStack_18c = _DAT_181a2b0ac * *(float *)(lVar26 + 0x37d0);
  uStackX_20 = CONCAT44(fVar41 + _DAT_181b2b284,fVar38 + _DAT_181b2b280);
  uVar5 = func_0x000180004f90(&puStack_198);
  uVar31 = (ulonglong)in_stack_fffffffffffffdf0 & 0xffffffff00000000;
  uVar19 = CONCAT44(uVar7,_DAT_181a032ec);
  func_0x000180027d60(uVar35,&uStack_108,&uStackX_20,uVar5,uVar19,uVar31);
  lVar20 = _DAT_181b2f2c0;
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar5 = (undefined4)(uVar31 >> 0x20);
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  fVar34 = _DAT_181a03298;
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181a2b0a4,_DAT_181a2b0a0);
  uStack_190 = _DAT_181a2b0a8;
  fStack_18c = (_DAT_181a2b0ac * *(float *)(lVar26 + 0x37d0)) / _DAT_181a03298;
  fVar39 = fVar41 + _DAT_181a0338c;
  uStackX_20 = CONCAT44(fVar39,fVar38 + _DAT_181b2b280);
  uVar6 = func_0x000180004f90(&puStack_198);
  puVar18 = (undefined8 *)CONCAT44(uVar5,0x30);
  uVar19 = CONCAT44(uVar7,_DAT_181a032ec);
  func_0x000180027d60(uVar35,&uStack_108,&uStackX_20,uVar6,uVar19,puVar18);
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
  }
  lVar21 = _DAT_181b2f2c0;
  fVar32 = fVar38 + _DAT_181b2b280;
  *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
  lVar20 = *(longlong *)(lVar21 + 0x3f10);
  fVar33 = (float)uStackX_18;
  *(float *)(lVar20 + 0x100) = (float)uStackX_18;
  fVar42 = uStackX_18._4_4_;
  *(float *)(lVar20 + 0x104) = uStackX_18._4_4_;
  *(undefined *)(lVar20 + 0x141) = 1;
  uStackX_18 = CONCAT44(fVar39 - fVar41,fVar32 - fVar38);
  func_0x000180038c00(&UNK_1819dcf48,&uStackX_18);
  cVar4 = func_0x00018000a3e0(0);
  if ((cVar4 != '\0') && (cVar4 = func_0x000180016380(0), cVar4 != '\0')) {
    uStackX_18 = *(undefined8 *)(lVar21 + 0xfc);
    lVar20 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    uVar35 = func_0x00018009b6a0(&puStack_198,&uStackX_20,&uStackX_18);
    func_0x000180015010(lVar20,uVar35,0);
  }
  lVar21 = _DAT_181b2f2c0;
  *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
  lVar20 = *(longlong *)(lVar21 + 0x3f10);
  *(float *)(lVar20 + 0x100) = fVar33;
  *(float *)(lVar20 + 0x104) = fVar42;
  *(undefined *)(lVar20 + 0x141) = 1;
  if (DAT_181b2bc70 == '\0') {
    lVar20 = *(longlong *)(lVar21 + 0x3f10);
    uStackX_18 = *(undefined8 *)(lVar20 + 0x28);
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    puVar16 = (undefined8 *)func_0x00018009b6a0(afStack_100,&uStackX_20,&uStackX_18);
    uVar35 = *puVar16;
    uVar19 = *(undefined8 *)(lVar20 + 0x20);
    uVar17 = func_0x00018000a9e0();
    uVar43 = CONCAT44(uVar7,_DAT_181a031fc);
    func_0x000180055330(uVar17,uVar19,uVar35,_DAT_181a032bc,uVar43);
    uVar7 = (undefined4)((ulonglong)uVar43 >> 0x20);
    if (DAT_181b2bc70 == '\0') {
      uVar35 = func_0x00018000a9e0();
      uStackX_18 = 0;
      uStackX_20 = *(undefined8 *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0x28);
      uStack_128 = *(undefined8 *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0x20);
      lVar20 = _DAT_181b2f2c0;
      func_0x00018009b6a0(&fStack_1a0,&uStack_128,&uStackX_20);
      uStackX_20 = *(undefined8 *)(*(longlong *)(lVar20 + 0x3f10) + 0x20);
      func_0x000180004f90(&DAT_181a2b0a0);
      puVar18 = &uStackX_18;
      func_0x00018002a070(uVar35,&uStackX_20);
    }
    fVar38 = (float)uStackX_8;
    fVar41 = (float)uStackX_10;
  }
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181a2b0a4,_DAT_181a2b0a0);
  uStack_190 = _DAT_181a2b0a8;
  fStack_18c = _DAT_181a2b0ac * *(float *)(lVar26 + 0x37d0);
  uStackX_18 = CONCAT44(fVar41 + _DAT_181b2b284,fVar38 + _DAT_181b2b280);
  fVar39 = fVar41 + _DAT_181a03384;
  uStackX_20 = CONCAT44(fVar39,fVar38 + 0.0);
  uVar5 = func_0x000180004f90(&puStack_198);
  uVar44 = (ulonglong)puVar18 & 0xffffffff00000000;
  uVar31 = CONCAT44(uVar7,_DAT_181a032ec);
  func_0x000180027d60(uVar35,&uStackX_20,&uStackX_18,uVar5,uVar31,uVar44);
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181b4f19c,_DAT_181b4f198);
  uStack_190 = _DAT_181b4f1a0;
  fStack_18c = _DAT_181b4f1a4 * *(float *)(_DAT_181b2f2c0 + 0x37d0);
  uStackX_18 = CONCAT44(fVar41 + _DAT_181a03388,fVar38 + _DAT_181b2b280);
  uStackX_20 = CONCAT44(fVar39,fVar38 + 0.0);
  uVar7 = func_0x000180004f90(&puStack_198);
  func_0x000180027d60(uVar35,&uStackX_20,&uStackX_18,uVar7,uVar31 & 0xffffffff00000000,
                      uVar44 & 0xffffffff00000000);
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  apuStack_168[0] = (undefined8 *)CONCAT44(_UNK_181a03814,_DAT_181a03810);
  apuStack_168[1] = (undefined8 *)CONCAT44(_UNK_181a0381c,_UNK_181a03818);
  uStackX_18 = 0x3f8000003f800000;
  uStackX_20 = 0;
  fStack_1a0 = fVar38 + _DAT_181b2b280;
  fStack_19c = fVar41 + _DAT_181b2b284;
  uVar7 = func_0x000180004f90(apuStack_168);
  puVar27 = (undefined *)CONCAT44(uVar12,_DAT_181a032ec);
  puVar18 = &uStackX_20;
  func_0x000180028b00(uVar35,_DAT_181b2f3a8,&uStack_108,&fStack_1a0,puVar18,&uStackX_18,
                      CONCAT44(uVar11,uVar7),puVar27);
  uVar7 = (undefined4)((ulonglong)puVar18 >> 0x20);
  if (DAT_181b2bc70 == '\0') {
    fVar38 = _DAT_181a2affc / _DAT_181a03248;
    lVar20 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    uStackX_18 = *(undefined8 *)(lVar20 + 0x28);
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    puVar18 = (undefined8 *)func_0x00018009b6a0(&puStack_198,&uStackX_20,&uStackX_18);
    uVar35 = *puVar18;
    uStackX_18 = 0;
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    puVar18 = (undefined8 *)func_0x00018009b6a0(&uStack_128,&uStackX_20,&uStackX_18);
    uVar19 = *puVar18;
    uVar17 = func_0x00018000a9e0();
    uVar43 = CONCAT44(uVar7,fVar38);
    func_0x0001800a1f00(uVar17,uVar19,uVar35,_DAT_181a032ec,uVar43);
    uVar7 = (undefined4)((ulonglong)uVar43 >> 0x20);
    fVar38 = (float)uStackX_8;
    fVar34 = _DAT_181a03298;
  }
  if ((*(int *)(lVar25 + 4) < _DAT_181b509d4) &&
     (func_0x000180127a18(&DAT_181b509d4), _DAT_181b509d4 == -1)) {
    _DAT_181b50a00 = GetTickCount();
    func_0x0001801279ac(&DAT_181b509d4);
  }
  iVar8 = GetTickCount();
  if (0xf < (uint)(iVar8 - _DAT_181b50a00)) {
    if (DAT_181b4f092 == '\0') {
      if (_DAT_181b4f110 < 0x35) {
        _DAT_181b4f110 = _DAT_181b4f110 + 1;
      }
      else {
        DAT_181b4f092 = '\x01';
      }
    }
    else if (_DAT_181b4f110 < 1) {
      DAT_181b4f092 = '\0';
    }
    else {
      _DAT_181b4f110 = _DAT_181b4f110 + -1;
    }
    _DAT_181b50a00 = GetTickCount();
  }
  lVar20 = _DAT_181b2f2c0;
  uStackX_18 = _DAT_181b4f0c8;
  lVar25 = _DAT_181b4f0c8;
  if ((_DAT_181b4f0c8 == 0) && (lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x50), lVar25 == 0)) {
    lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x40);
    if (*(int *)(lVar25 + 0x58) < 1) {
      _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
    }
    lVar25 = **(longlong **)(lVar25 + 0x60);
  }
  uStackX_18 = lVar25;
  func_0x0001800149b0();
  func_0x000180022d70(lVar20 + 0x4888,&uStackX_18);
  func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar20 + 0x3f10) + 0x298),
                      *(undefined8 *)(*(longlong *)(lVar25 + 0x40) + 8));
  uVar11 = _DAT_181a03460;
  apuStack_1e0[0] = (undefined8 *)&UNK_1819dcf64;
  apuStack_1e0[1] = (undefined8 *)&UNK_1819dcf58;
  apuStack_1e0[2] = (undefined8 *)&UNK_1819dcf7c;
  fVar32 = fVar38 + _DAT_181b2b280;
  uVar12 = 0;
  ppuVar45 = (undefined8 **)&UNK_1819dcf70;
  uVar35 = CONCAT44(uVar7,_DAT_181a0348c);
  func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&uStackX_18,
                      *(undefined4 *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,uVar35,&UNK_1819dcf70,
                      0);
  fVar41 = _DAT_181a031bc;
  uVar7 = (undefined4)((ulonglong)uVar35 >> 0x20);
  fStack_120 = ((fVar32 - fVar33) * _DAT_181a031bc + fVar33) -
               (float)(int)((float)uStackX_18 + _DAT_181a03228) * _DAT_181a031bc;
  fStack_11c = ((fVar39 - fVar42) * _DAT_181a031bc + fVar42) - uStackX_18._4_4_ * _DAT_181a031bc;
  if (DAT_181b2bc70 == '\0') {
    uVar19 = CONCAT44(uVar7,0x96);
    uVar35 = func_0x000180024180(&uStack_188,0,0,0,uVar19);
    uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar9 = func_0x000180004f90(uVar35);
    uVar31 = (ulonglong)uVar9;
    uVar35 = func_0x0001800152b0();
    uStackX_18 = 0x3f8000003f800000;
    uVar19 = func_0x00018009b6a0(&uStackX_20,&fStack_120,&uStackX_18);
    func_0x000180028900(uVar35,uVar19,uVar31 & 0xffffffff,&UNK_1819dcf3c);
    lVar25 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    func_0x000180025190(*(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298),&DAT_1800a2a80,0);
    lVar25 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    uVar35 = *(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298);
    uVar17 = CONCAT44(uVar7,0xff);
    uVar19 = func_0x000180024180(&uStack_188,0xff,0xff,0xff,uVar17);
    uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar7 = func_0x000180004f90(uVar19);
    func_0x000180028900(uVar35,&fStack_120,uVar7,&UNK_1819dcf3c);
    uVar35 = func_0x0001800152b0();
    func_0x000180025190(uVar35,&DAT_1800a2cc0,0);
    uVar7 = _DAT_181a0348c;
    uVar19 = CONCAT44(uVar5,_DAT_181a0348c);
    func_0x00018000dc20(&uStackX_18,&UNK_1819dcf3c,0,0,uVar19);
    uStackX_20 = CONCAT44(uStackX_20._4_4_,fStack_11c + 0.0);
    fVar33 = fStack_120 + (float)uStackX_18;
    uStackX_18._0_4_ = fVar38 + _DAT_181b2b280;
    uStackX_18._4_4_ = fStack_11c + _DAT_181a0336c;
    fStack_19c = fStack_11c - _DAT_181a032ec;
    fStack_1a0 = fVar33;
    func_0x00018000c9e0(&fStack_1a0,&uStackX_18,1);
    lVar25 = _DAT_181b2f2c0;
    dVar1 = *(double *)(_DAT_181b2f2c0 + 0x3e60);
    uVar35 = func_0x0001801cb4f5();
    uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
    fVar39 = (float)uVar35;
    uVar9 = (int)((float)dVar1 / fVar34) & 0x80000001;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
    }
    puStack_198 = apuStack_1e0[(int)uVar9];
    lVar20 = -1;
    do {
      lVar20 = lVar20 + 1;
    } while (*(char *)((longlong)puStack_198 + lVar20) != '\0');
    uStackX_18 = (ulonglong)(uint)uStackX_18._4_4_ << 0x20;
    uVar31 = uVar28;
    if (0 < (longlong)(int)lVar20) {
      do {
        uVar9 = _DAT_181a03a00;
        uStack_1e8._0_1_ = *(undefined *)((longlong)puStack_198 + uVar31);
        uStack_1e8._1_1_ = 0;
        uVar12 = 0;
        ppuVar45 = (undefined8 **)&uStack_1e8;
        uVar19 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),uVar7);
        func_0x000180030a70(*(undefined8 *)(lVar25 + 0x3c30),afStack_100,
                            *(undefined4 *)(lVar25 + 0x3c38),uVar11,uVar19,ppuVar45,0);
        fVar42 = (float)(int)(afStack_100[0] + _DAT_181a03228);
        fVar38 = (float)(int)uVar28 * _DAT_181a0313c;
        fVar34 = fVar38 + _DAT_181a03280;
        afStack_100[0] = fVar42;
        if (fVar34 <= fVar39) {
          fVar38 = fVar40;
          if (fVar39 <= fVar34 + fVar41) {
            fVar38 = (fVar39 - fVar34) + (fVar39 - fVar34);
          }
          fVar34 = fVar40 - fVar38;
          fVar38 = (float)((uint)(fVar38 * fVar38 * (fVar38 * _DAT_181a03290 - _DAT_181a03254)) ^
                          uVar9);
        }
        else {
          if (fVar38 <= fVar39) {
            if (fVar39 <= fVar38 + fVar41) {
              fVar32 = (fVar39 - fVar38) + (fVar39 - fVar38);
              uVar11 = (int)((ulonglong)uVar35 >> 0x20);
              uVar5 = (int)extraout_XMM0_Qb;
              uVar6 = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
            }
            else {
              fVar32 = fVar40;
              uVar11 = 0;
              uVar5 = 0;
              uVar6 = 0;
            }
          }
          else {
            fVar32 = 0.0;
            uVar11 = 0;
            uVar5 = 0;
            uVar6 = 0;
          }
          auVar36._4_4_ = uVar11;
          auVar36._0_4_ = fVar32;
          auVar36._8_4_ = uVar5;
          auVar36._12_4_ = uVar6;
          auVar37._4_12_ = auVar36._4_12_;
          auVar37._0_4_ = ((fVar32 - _DAT_181a03150) * _DAT_181a032d0) / _DAT_181a0318c;
          fVar38 = (float)func_0x0001801cb519(auVar37._0_8_);
          fVar34 = (float)func_0x0001801cb50d();
          fVar38 = fVar38 * fVar34 + fVar40;
          if (fVar40 <= fVar32) {
            fVar38 = fVar40;
          }
          if (fVar32 <= 0.0) {
            fVar38 = 0.0;
          }
          fVar32 = fVar32 * _DAT_181a03248;
          if (0.0 <= fVar32) {
            fVar34 = fVar40;
            if (fVar32 <= fVar40) {
              fVar34 = fVar32;
            }
          }
          else {
            fVar34 = 0.0;
          }
          fVar38 = fVar40 - fVar38;
          uVar11 = _DAT_181a03460;
        }
        iVar8 = (int)uVar28;
        if (_DAT_181a03124 < fVar34) {
          fStack_1a0 = fVar33 + 0.0;
          fStack_19c = fVar38 * _DAT_181a03330 + (float)uStackX_20;
          uStack_118 = 0;
          iStack_110 = 0;
          fStack_10c = fVar34 * _DAT_181a031cc;
          uVar9 = func_0x000180004f90(&uStack_118);
          apuStack_168[0] = (undefined8 *)0x3f8000003f800000;
          apuStack_168[1] =
               (undefined8 *)
               CONCAT44((float)(int)(fVar34 * _DAT_181a033ec) * _DAT_181a03118,0x3f800000);
          uVar10 = func_0x000180004f90(apuStack_168);
          lVar26 = _DAT_181b2f2c0;
          uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          lVar26 = *(longlong *)(*(longlong *)(lVar26 + 0x3f10) + 0x298);
          uStack_128 = CONCAT44(fStack_19c + fVar40,fStack_1a0 + fVar40);
          if ((uVar9 & 0xff000000) != 0) {
            lVar25 = -1;
            do {
              lVar21 = lVar25;
              lVar25 = lVar21 + 1;
            } while (*(char *)((longlong)&uStack_1e8 + lVar21 + 1) != '\0');
            puVar46 = (undefined *)((longlong)&uStack_1e8 + lVar21 + 1);
            if (&uStack_1e8 != (undefined8 *)puVar46) {
              lVar25 = *(longlong *)(*(longlong *)(lVar26 + 0x38) + 8);
              uVar12 = *(undefined4 *)(*(longlong *)(lVar26 + 0x38) + 0x10);
              if (*(longlong *)(*(longlong *)(lVar25 + 0x40) + 8) != *(longlong *)(lVar26 + 0x98)) {
                _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
              }
              apuStack_1e0[0] = *(undefined8 **)(lVar26 + 0x88);
              apuStack_1e0[1] = *(undefined8 **)(lVar26 + 0x90);
              puVar27 = (undefined *)&uStack_1e8;
              ppuVar45 = apuStack_1e0;
              uVar19 = CONCAT44(uVar5,uVar9);
              func_0x000180030c90(lVar25,lVar26,uVar12,&uStack_128,uVar19,ppuVar45,puVar27,puVar46,0
                                  ,0);
              uVar12 = (undefined4)((ulonglong)puVar27 >> 0x20);
              puVar27 = puVar46;
            }
          }
          lVar26 = _DAT_181b2f2c0;
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          func_0x000180025190(*(undefined8 *)(*(longlong *)(lVar26 + 0x3f10) + 0x298),&DAT_1800a2a80
                              ,0);
          lVar26 = _DAT_181b2f2c0;
          uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          lVar26 = *(longlong *)(*(longlong *)(lVar26 + 0x3f10) + 0x298);
          if ((uVar10 & 0xff000000) != 0) {
            lVar25 = -1;
            do {
              lVar21 = lVar25;
              lVar25 = lVar21 + 1;
            } while (*(char *)((longlong)&uStack_1e8 + lVar21 + 1) != '\0');
            puVar46 = (undefined *)((longlong)&uStack_1e8 + lVar21 + 1);
            if (&uStack_1e8 != (undefined8 *)puVar46) {
              lVar25 = *(longlong *)(*(longlong *)(lVar26 + 0x38) + 8);
              uVar12 = *(undefined4 *)(*(longlong *)(lVar26 + 0x38) + 0x10);
              if (*(longlong *)(*(longlong *)(lVar25 + 0x40) + 8) != *(longlong *)(lVar26 + 0x98)) {
                _wassert(&UNK_1819d1c30,&UNK_1819d1a00);
              }
              uStack_188._0_4_ = *(undefined4 *)(lVar26 + 0x88);
              uStack_188._4_4_ = *(undefined4 *)(lVar26 + 0x8c);
              iStack_180 = *(int *)(lVar26 + 0x90);
              fStack_17c = *(float *)(lVar26 + 0x94);
              puVar27 = (undefined *)&uStack_1e8;
              ppuVar45 = (undefined8 **)&uStack_188;
              uVar19 = CONCAT44(uVar5,uVar10);
              func_0x000180030c90(lVar25,lVar26,uVar12,&fStack_1a0,uVar19,ppuVar45,puVar27,puVar46,0
                                  ,0);
              uVar12 = (undefined4)((ulonglong)puVar27 >> 0x20);
              puVar27 = puVar46;
            }
          }
          lVar26 = _DAT_181b2f2c0;
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          func_0x000180025190(*(undefined8 *)(*(longlong *)(lVar26 + 0x3f10) + 0x298),&DAT_1800a2cc0
                              ,0);
          iVar8 = (int)(float)uStackX_18;
        }
        uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
        fVar33 = fVar33 + fVar42;
        uVar28 = (ulonglong)(iVar8 + 1U);
        uStackX_18 = CONCAT44(uStackX_18._4_4_,iVar8 + 1U);
        uVar31 = uVar31 + 1;
        lVar25 = _DAT_181b2f2c0;
      } while ((longlong)uVar31 < (longlong)(int)lVar20);
      uVar30 = (ulonglong)__tls_index;
      lVar26 = lStack_f8;
      fVar38 = (float)uStackX_8;
    }
    func_0x00018000ca90();
  }
  else {
    uVar35 = func_0x0001800152b0();
    uVar17 = CONCAT44(uVar7,0xff);
    uVar19 = func_0x000180024180(&uStack_188,0xff,0xff,0xff,uVar17);
    uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar7 = func_0x000180004f90(uVar19);
    func_0x000180028900(uVar35,&fStack_120,uVar7,&UNK_1819dcf70);
  }
  func_0x000180014ae0();
  lVar25 = _DAT_181b2f2c0;
  *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
  apuStack_168[0] = (undefined8 *)CONCAT44(_DAT_181b4f19c,_DAT_181b4f198);
  apuStack_168[1] =
       (undefined8 *)CONCAT44(_DAT_181b4f1a4 * *(float *)(lVar25 + 0x37d0),_DAT_181b4f1a0);
  uStackX_8 = (undefined *)CONCAT44((float)uStackX_10 + _DAT_181b2b284,fVar38 + _DAT_181b2b280);
  uVar7 = func_0x000180004f90(apuStack_168);
  puVar18 = (undefined8 *)((ulonglong)ppuVar45 & 0xffffffff00000000);
  puVar16 = (undefined8 *)CONCAT44(uVar5,_DAT_181a032ec);
  func_0x000180027c60(*(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298),&uStack_108,&uStackX_8
                      ,uVar7,puVar16,puVar18,CONCAT44(uVar12,fVar40));
  lVar25 = _DAT_181b2f2c0;
  uVar7 = (undefined4)((ulonglong)puVar18 >> 0x20);
  if (DAT_181b2f8c8 == '\0') {
    fVar38 = _DAT_181b32b44 + _DAT_181a0338c;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    fVar40 = _DAT_181a0331c;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x100) =
         (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + _DAT_181a0331c;
    *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar38;
    *(undefined *)(lVar25 + 0x141) = 1;
    func_0x000180019310();
    lVar20 = _DAT_181b2f2c0;
    lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
       (pfVar23 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
      pfVar23 = (float *)(lVar25 + 0x220);
    }
    fVar38 = *pfVar23 - *(float *)(lVar25 + 0x100);
    fVar40 = (((pfVar23[1] - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810)) - fVar40) +
             _DAT_181b32b44;
    uStackX_10 = (undefined *)CONCAT44(fVar40,fVar38);
    *(undefined *)(lVar25 + 0xb8) = 1;
    uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(2,&uStackX_8);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(0xe,&uStackX_8);
    uVar11 = func_0x000180009d10(uVar35,&UNK_1819dcfa0);
    func_0x000180057580(&UNK_1819dcfa0,uVar11,&uStackX_10);
    lVar26 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    lVar26 = *(longlong *)(lVar26 + 0x3f10);
    fVar40 = fVar40 - _DAT_181a033f0;
    *(float *)(lVar26 + 0x100) =
         (*(float *)(lVar26 + 0x20) - *(float *)(lVar26 + 0x84)) +
         (fVar38 - _DAT_181a03410) * fVar41;
    *(float *)(lVar26 + 0x104) =
         (*(float *)(lVar26 + 0x24) - *(float *)(lVar26 + 0x88)) + fVar40 * fVar41;
    *(undefined *)(lVar26 + 0x141) = 1;
    func_0x000180019310();
    lVar25 = _DAT_181b2f2c0;
    uStackX_8 = (undefined *)_DAT_181b4f028;
    lVar26 = _DAT_181b4f028;
    if ((_DAT_181b4f028 == 0) && (lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x50), lVar26 == 0)) {
      lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x40);
      if (*(int *)(lVar26 + 0x58) < 1) {
        _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
      }
      lVar26 = **(longlong **)(lVar26 + 0x60);
    }
    uStackX_8 = (undefined *)lVar26;
    func_0x0001800149b0();
    func_0x000180022d70(lVar25 + 0x4888,&uStackX_8);
    func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298),
                        *(undefined8 *)(*(longlong *)(lVar26 + 0x40) + 8));
    func_0x000180037ef0(&UNK_1819dcf88);
    func_0x000180014ae0();
    lVar26 = _DAT_181b2f2c0;
    uStack_188._0_4_ = 0;
    uStack_188._4_4_ = *(undefined4 *)(_DAT_181b2f2c0 + 0x38bc);
    iStack_180 = *(int *)(_DAT_181b2f2c0 + 0x38c0);
    fStack_17c = *(float *)(_DAT_181b2f2c0 + 0x38c4);
    uStack_178 = *(undefined4 *)(_DAT_181b2f2c0 + 0x38c8);
    func_0x000180022be0(_DAT_181b2f2c0 + 0x4868,&uStack_188);
    *(undefined4 *)(lVar26 + 0x38bc) = 0x3f34b4b5;
    *(undefined4 *)(lVar26 + 0x38c0) = 0x3f34b4b5;
    *(undefined4 *)(lVar26 + 0x38c4) = 0x3f3ebebf;
    *(undefined4 *)(lVar26 + 0x38c8) = 0x3f800000;
    func_0x0001800380d0(&UNK_1819dcfe8);
    func_0x0001800069f0(1);
    lVar26 = _DAT_181b2f2c0;
    if (DAT_181b2f2dc != '\0') {
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
        uStackX_8 = (undefined *)0x0;
        func_0x000180018c50(&uStackX_8);
      }
      lVar26 = _DAT_181b2f2c0;
      uStack_188._0_4_ = 0;
      uStack_188._4_4_ = *(undefined4 *)(_DAT_181b2f2c0 + 0x38bc);
      iStack_180 = *(int *)(_DAT_181b2f2c0 + 0x38c0);
      fStack_17c = *(float *)(_DAT_181b2f2c0 + 0x38c4);
      uStack_178 = *(undefined4 *)(_DAT_181b2f2c0 + 0x38c8);
      func_0x000180022be0(_DAT_181b2f2c0 + 0x4868,&uStack_188);
      *(undefined4 *)(lVar26 + 0x38bc) = 0x3f800000;
      *(undefined4 *)(lVar26 + 0x38c0) = 0x3e99999a;
      *(undefined4 *)(lVar26 + 0x38c4) = 0x3e99999a;
      *(undefined4 *)(lVar26 + 0x38c8) = 0x3f800000;
      func_0x000180037ef0(&UNK_1819dcfb0);
      func_0x0001800069f0(1);
    }
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + uVar30 * 8) + 4) <
         _DAT_181b509ac) && (func_0x000180127a18(&DAT_181b509ac), _DAT_181b509ac == -1)) {
      func_0x000180078760(&DAT_181b50d78);
      func_0x000180127e28(&DAT_1801d1230);
      func_0x0001801279ac(&DAT_181b509ac);
    }
    lVar26 = _DAT_181b2f2c0;
    if (_DAT_181b50d88 != 0) {
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
        uStackX_8 = (undefined *)0x0;
        func_0x000180018c50(&uStackX_8);
      }
      lVar26 = _DAT_181b2f2c0;
      uStack_188._0_4_ = 0;
      uStack_188._4_4_ = *(undefined4 *)(_DAT_181b2f2c0 + 0x38bc);
      iStack_180 = *(int *)(_DAT_181b2f2c0 + 0x38c0);
      fStack_17c = *(float *)(_DAT_181b2f2c0 + 0x38c4);
      uStack_178 = *(undefined4 *)(_DAT_181b2f2c0 + 0x38c8);
      func_0x000180022be0(_DAT_181b2f2c0 + 0x4868,&uStack_188);
      *(undefined4 *)(lVar26 + 0x38bc) = 0x3f800000;
      *(undefined4 *)(lVar26 + 0x38c0) = 0x3eb33333;
      *(undefined4 *)(lVar26 + 0x38c4) = 0x3eb33333;
      *(undefined4 *)(lVar26 + 0x38c8) = 0x3f800000;
      puVar27 = &DAT_181b50d78;
      if (0xf < _DAT_181b50d90) {
        puVar27 = _DAT_181b50d78;
      }
      func_0x0001800380d0(&UNK_18021328c,puVar27);
      func_0x0001800069f0(1);
    }
    lVar26 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
      uStackX_8 = (undefined *)0x0;
      func_0x000180018c50(&uStackX_8);
    }
    lVar26 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
      uStackX_8 = (undefined *)0x0;
      func_0x000180018c50(&uStackX_8);
    }
    lVar25 = _DAT_181b2f2c0;
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    *(undefined *)(lVar26 + 0xb8) = 1;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x104) =
         (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) +
         (*(float *)(lVar26 + 0x104) - *(float *)(lVar26 + 0x24)) + *(float *)(lVar26 + 0x88) +
         _DAT_181a032a8;
    *(undefined *)(lVar25 + 0x141) = 1;
    uStackX_8 = (undefined *)0x4260000043dc0000;
    func_0x00018003f4e0(&UNK_1819dd020,&UNK_1819dd030,0x181b2bcf8,0x80,&uStackX_8,
                        CONCAT44(uVar7,0x100),&DAT_1800ae450,0);
    lVar25 = _DAT_181b2f2c0;
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    *(undefined *)(lVar26 + 0xb8) = 1;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x104) =
         (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) +
         (*(float *)(lVar26 + 0x104) - *(float *)(lVar26 + 0x24)) + *(float *)(lVar26 + 0x88) +
         _DAT_181a03308;
    *(undefined *)(lVar25 + 0x141) = 1;
    if (DAT_181b4f078 == '\0') {
      uStackX_8 = (undefined *)0x4240000043dc0000;
      cVar4 = func_0x000180058040(&UNK_1819dd058,&uStackX_8);
      if (cVar4 != '\0') {
        DAT_181b4f078 = '\x01';
        func_0x0001800785c0(&DAT_181b50d78);
        uStack_188._0_4_ = _DAT_181a2aff0;
        uStack_188._4_4_ = _DAT_181a2aff4;
        iStack_180 = _DAT_181a2aff8;
        fStack_17c = _DAT_181a2affc;
        recovered_18009bbb0();
        recovered_180066c80(apuStack_168,0x181b2bcf8);
        recovered_180080190(apuStack_1e0,apuStack_168);
        uVar35 = func_0x0001800b5b30(&uStack_188,apuStack_1e0);
        func_0x000180067c80(uVar35);
        if (iStack_180 != 0) {
          terminate();
        }
        recovered_180066e40(apuStack_1e0);
        recovered_180066e40(apuStack_168);
      }
    }
    else {
      func_0x000180014d80();
      uStackX_8 = (undefined *)0x4240000043dc0000;
      func_0x000180058040(&UNK_1819dd078,&uStackX_8);
      func_0x000180014e10();
    }
    func_0x000180019460();
  }
  else {
    func_0x0001800a0be0();
    lVar25 = _DAT_181b2f2c0;
    fVar39 = _DAT_181a033a0;
    fVar34 = _DAT_181a0338c;
    fVar38 = _DAT_181a0331c;
    uVar7 = (undefined4)((ulonglong)puVar27 >> 0x20);
    if (_DAT_181b50d50 == 0) {
      fVar33 = _DAT_181b32b44 + _DAT_181a0338c;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar33;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      uVar7 = (undefined4)((ulonglong)puVar16 >> 0x20);
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar11 = func_0x000180009d10(uVar35,&UNK_1819dcf0c);
      func_0x000180057580(&UNK_1819dcf0c,uVar11,&uStackX_10);
      cVar4 = func_0x000180059d50(&UNK_1819dd098,&UNK_1819dd060,&DAT_181b2f8c9);
      if (cVar4 != '\0') {
        DAT_181b2f8c9 = DAT_181b2f8c9 == '\0';
        recovered_1800acfd0();
      }
      if ((DAT_181b2f8c9 != '\0') &&
         (cVar4 = func_0x00018005d100(&UNK_1819dd0c0,&UNK_1819dd088,&DAT_181b30424,0x181ade2e8,
                                      CONCAT44(uVar7,1)), cVar4 != '\0')) {
        DAT_181b2f8c9 = '\0';
        recovered_1800acfd0();
      }
      func_0x000180059d50(&UNK_1819dd0e8,&UNK_1819dd0a0,&DAT_181b2b5b5);
      func_0x000180059d50(&UNK_1819dd108,&UNK_1819dd0d0,&DAT_181b2b400);
      func_0x000180059d50(&UNK_1819dd130,&UNK_1819dd0f8,&DAT_181b2b5c0);
      func_0x000180059d50(&UNK_1819dd158,&UNK_1819dd118,&DAT_181b2b407);
      func_0x000180059d50(&UNK_1819dd178,&UNK_1819dd140,&DAT_181b2b406);
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      uStackX_10._4_4_ =
           (((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810)) - fVar39) +
           _DAT_181b32b44;
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_10._0_4_ = *pfVar23 - *(float *)(lVar25 + 0x100);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8._0_4_ = 13.0;
      uStackX_8._4_4_ = 0x41500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar35,&UNK_1819dd168);
      func_0x000180057580(&UNK_1819dd168,uVar7,&uStackX_10);
      uStackX_8._0_4_ = 1200.0;
      uStackX_10._0_4_ = 0.0;
      uVar28 = (ulonglong)puVar27 & 0xffffffff00000000;
      func_0x0001800610a0(&UNK_1819dd188,&UNK_1819dd198,8,&DAT_181b2b410,&uStackX_10,&uStackX_8,
                          &UNK_180213290,uVar28);
      uStackX_8 = (undefined *)CONCAT44(uStackX_8._4_4_,200);
      uStackX_10 = (undefined *)((ulonglong)(uint)uStackX_10._4_4_ << 0x20);
      uVar28 = uVar28 & 0xffffffff00000000;
      puVar18 = &uStackX_8;
      puVar16 = &uStackX_10;
      func_0x0001800610a0(&UNK_1819dd1e0,&UNK_1819dd1b0,4,&DAT_181b2b40c,puVar16,puVar18,
                          &UNK_1819dd1c4,uVar28);
      uVar7 = (undefined4)(uVar28 >> 0x20);
      cVar4 = func_0x000180059d50(&UNK_1819dd208,&UNK_1819dd1c8,0x181b31b5b);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819de310;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de210;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x172b,&UNK_1819dd208,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x000180059d50(&UNK_1819dd230,&UNK_1819dd1f0,&DAT_181b2b5b6);
      if (DAT_181b2b5b6 != '\0') {
        puVar16 = (undefined8 *)CONCAT44((int)((ulonglong)puVar16 >> 0x20),2);
        func_0x00018005d100(&UNK_1819dd260,&UNK_1819dd218,&DAT_181b2b5b8,0x181ade2a8,puVar16);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dcca8,&UNK_1819dd240,&DAT_181b30438);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819ddf50;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_181a03018;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(8,&UNK_1819dcca8,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    uVar11 = (undefined4)((ulonglong)puVar18 >> 0x20);
    if (_DAT_181b50d50 == 1) {
      fVar33 = _DAT_181b32b44 + fVar34;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar33;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar12 = func_0x000180009d10(uVar35,&UNK_1819dd290);
      func_0x000180057580(&UNK_1819dd290,uVar12,&uStackX_10);
      func_0x000180059d50(&UNK_1819dd298,&UNK_1819dd278,&DAT_181b2b46c);
      apuStack_1e0[0] = (undefined8 *)&UNK_1819dd294;
      apuStack_1e0[1] = (undefined8 *)&UNK_1819dd2ac;
      apuStack_1e0[2] = (undefined8 *)&UNK_1819dd2a4;
      uVar19 = CONCAT44(uVar7,0x2000128);
      uVar35 = CONCAT44(uVar11,3);
      func_0x0001800640d0(&UNK_1819dd2b8,&UNK_1819dd2c8,&DAT_181b2b46d,&DAT_181b2b470,apuStack_1e0,
                          uVar35,&DAT_181b2b478,uVar19);
      uVar7 = (undefined4)((ulonglong)uVar35 >> 0x20);
      uVar11 = (undefined4)((ulonglong)uVar19 >> 0x20);
      if (2 < _DAT_181b2b470) {
        _DAT_181b2b470 = 0;
      }
      if (DAT_181b2b46d != '\0') {
        uStackX_8 = (undefined *)CONCAT71(uStackX_8._1_7_,_DAT_181b2b474 != 0);
        cVar4 = func_0x000180059d50(&UNK_1819dd2e8,&UNK_1819dd2f8,&uStackX_8);
        if (cVar4 != '\0') {
          _DAT_181b2b474 = (uint)((char)uStackX_8 != '\0');
        }
      }
      apuStack_168[0] = (undefined8 *)&UNK_1819dd320;
      apuStack_168[1] = (undefined8 *)&UNK_1819dd310;
      uVar28 = CONCAT44(uVar11,0x2000128);
      ppuVar45 = apuStack_168;
      func_0x0001800640d0(&UNK_1819dd328,&UNK_1819dd330,&DAT_181b2b498,&DAT_181b2b49c,ppuVar45,
                          CONCAT44(uVar7,2),&DAT_181b2b4a0,uVar28);
      if (1 < _DAT_181b2b49c) {
        _DAT_181b2b49c = 0;
      }
      uVar35 = CONCAT44((int)((ulonglong)ppuVar45 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd348,&UNK_1819dd358,&DAT_181b2b538,&DAT_181b2b53c,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd370,&UNK_1819dd380,&DAT_181b2b4c4,&DAT_181b2b4c8,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd398,&UNK_1819dd3a8,&DAT_181b2b4d8,&DAT_181b2b4dc,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd3c0,&UNK_1819dd3d0,&DAT_181b2b4ec,&DAT_181b2b4f0,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd3e8,&UNK_1819dd3f8,&DAT_181b2b504,&DAT_181b2b508,uVar35);
      uVar7 = (undefined4)((ulonglong)uVar35 >> 0x20);
      func_0x000180059d50(&UNK_1819dd410,&UNK_1819dd420,&DAT_181b2b51c);
      func_0x000180059d50(&UNK_1819da980,&UNK_1819dd450,&DAT_181b2b54d);
      func_0x000180059d50(&UNK_1819da9a8,&UNK_1819dd438,&DAT_181b2b54c);
      func_0x000180059d50(&UNK_1819dd460,&UNK_1819dd470,&DAT_181b2b46e);
      func_0x000180059d50(&UNK_1819dd490,&UNK_1819dd4a0,&DAT_181b2bedc);
      func_0x000180059d50(&UNK_1819dd4b8,&UNK_1819dd4c8,&DAT_181b2bdd0);
      if (DAT_181b2bdd0 != '\0') {
        func_0x0001800627e0(&UNK_1819dd4e0,&UNK_1819dd4f0,&DAT_181b2bdd4,0x14,CONCAT44(uVar7,500));
        func_0x000180059d50(&UNK_1819dd508,&UNK_1819dd518,&DAT_181b2bdd1);
      }
      uStackX_8 = (undefined *)CONCAT44(uStackX_8._4_4_,200);
      uStackX_10 = (undefined *)((ulonglong)uStackX_10 & 0xffffffff00000000);
      puVar18 = &uStackX_8;
      puVar16 = &uStackX_10;
      func_0x0001800610a0(&UNK_1819dd530,&UNK_1819dd540,4,&DAT_181b2b57c,puVar16,puVar18,
                          &UNK_1819dd1c4,uVar28 & 0xffffffff00000000);
      func_0x000180059d50(&UNK_1819dd558,&UNK_1819dd568,&DAT_181b2b581);
      func_0x000180059d50(&UNK_1819dd580,&UNK_1819dd590,&DAT_181b2b564);
      func_0x000180059d50(&UNK_1819dd5a8,&UNK_1819dd5c0,&DAT_181b2b565);
      uStackX_8 = (undefined *)0x420c000043c80000;
      cVar4 = func_0x000180058040(&UNK_1819dd5e8,&uStackX_8);
      if (cVar4 != '\0') {
        recovered_180067b80(&uStackX_8);
        lVar25 = (longlong)uStackX_8;
        uStackX_8 = (undefined *)((longlong)uStackX_8 - _DAT_181b4f0b8);
        plVar22 = (longlong *)func_0x0001800694c0(&uStackX_10,&uStackX_8);
        if (0xf9 < *plVar22) {
          DAT_181b2bedd = 1;
          uStack_188._0_4_ = _DAT_181a2aff0;
          uStack_188._4_4_ = _DAT_181a2aff4;
          iStack_180 = _DAT_181a2aff8;
          fStack_17c = _DAT_181a2affc;
          _DAT_181b4f0b8 = lVar25;
          recovered_18009bbb0();
        }
      }
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,*pfVar24 - *(float *)(lVar25 + 0x100));
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar35,&UNK_1819dd5d8);
      func_0x000180057580(&UNK_1819dd5d8,uVar7,&uStackX_10);
      func_0x00018009c940(&DAT_181b2fd70);
      func_0x00018009d460(&DAT_181b2fd70);
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    uVar7 = _DAT_181a0330c;
    if (_DAT_181b50d50 == 2) {
      fVar33 = _DAT_181b32b44 + fVar34;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar33;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar11 = func_0x000180009d10(uVar35,&UNK_1819dcf20);
      func_0x000180057580(&UNK_1819dcf20,uVar11,&uStackX_10);
      func_0x000180059d50(&UNK_1819dd5f8,&UNK_1819dd608,&DAT_181b2b5fc);
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
        pfVar23 = (float *)(lVar25 + 0x250);
      }
      else {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar25 + 0x100));
      cVar4 = func_0x000180058040(&UNK_1819dd640,&uStackX_8);
      if (cVar4 != '\0') {
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de418;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac840(&UNK_1819dcc58,apuStack_1e0);
        func_0x0001800553f0(apuStack_1e0);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dcc58,&UNK_1819dd620,&DAT_181b3044f);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_181a02fa0;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_181a02ef8;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x1f,&UNK_1819dcc58,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
        pfVar23 = (float *)(lVar25 + 0x250);
      }
      else {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar25 + 0x100));
      cVar4 = func_0x000180058040(&UNK_1819dd670,&uStackX_8);
      if (cVar4 != '\0') {
        apuStack_1e0[0] = (undefined8 *)&UNK_181a030a8;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac840(&UNK_1819dcc78,apuStack_1e0);
        func_0x0001800553f0(apuStack_1e0);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dcc78,&UNK_1819dd650,&DAT_181b3055d);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819dde90;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de060;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x12d,&UNK_1819dcc78,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
        pfVar23 = (float *)(lVar25 + 0x250);
      }
      else {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar25 + 0x100));
      cVar4 = func_0x000180058040(&UNK_1819dd6a0,&uStackX_8);
      if (cVar4 != '\0') {
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de028;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac840(&UNK_1819dd688,apuStack_1e0);
        func_0x0001800553f0(apuStack_1e0);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dd688,&UNK_1819dd6c8,&DAT_181b3049f);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819dde20;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de3a0;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x6f,&UNK_1819dcc88,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,*pfVar24 - *(float *)(lVar25 + 0x100));
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar11 = func_0x000180009d10(uVar35,&UNK_1819dd6b8);
      func_0x000180057580(&UNK_1819dd6b8,uVar11,&uStackX_10);
      func_0x000180059d50(&UNK_1819dd6e8,&UNK_1819dd6f8,&DAT_181b2b5e9);
      func_0x000180059d50(&UNK_1819dd710,&UNK_1819dd720,&DAT_181b2b60c);
      cVar4 = func_0x000180059d50(&UNK_1819dd738,&UNK_1819dd748,&DAT_181b2bc60);
      if (cVar4 != '\0') {
        if (DAT_181b2bc60 == '\0') {
          LOCK();
          DAT_181b2f6d9 = 0;
          UNLOCK();
          _DAT_181b3031c = 0;
          puVar16 = (undefined8 *)CONCAT44((int)((ulonglong)puVar16 >> 0x20),0xff);
          puVar13 = (undefined4 *)func_0x000180024180(apuStack_1e0,0xff,0x50,0x50,puVar16);
          uStack_188._0_4_ = *puVar13;
          uStack_188._4_4_ = puVar13[1];
          iStack_180 = puVar13[2];
          fStack_17c = (float)puVar13[3];
        }
        else {
          func_0x0001800776a0();
          uStack_188._0_4_ = _DAT_181a2aff0;
          uStack_188._4_4_ = _DAT_181a2aff4;
          iStack_180 = _DAT_181a2aff8;
          fStack_17c = _DAT_181a2affc;
        }
        recovered_18009bbb0();
      }
      if (DAT_181b2bc60 != '\0') {
        puVar18 = (undefined8 *)&UNK_1819dd7a8;
        puVar16 = (undefined8 *)CONCAT44((int)((ulonglong)puVar16 >> 0x20),uVar7);
        func_0x000180062790(&UNK_1819dd7d0,&UNK_1819dd790,&DAT_181b2bc64,fVar40,puVar16,
                            &UNK_1819dd7a8);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dd7f0,&UNK_1819dd7b0,0x181b327f2);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819ddec8;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_181a02f30;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x23c2,&UNK_1819dd7f0,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    if (_DAT_181b50d50 == 3) {
      fVar40 = _DAT_181b32b44 + fVar34;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar40;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar35,&UNK_1819dd7e0);
      func_0x000180057580(&UNK_1819dd7e0,uVar7,&uStackX_10);
      uVar28 = (ulonglong)puVar16 & 0xffffffffffffff00;
      func_0x000180056290(&UNK_1819dd800,&UNK_1819dd810,&DAT_181ade1f8,0x181b32d10,uVar28);
      uVar35 = CONCAT71((int7)(uVar28 >> 8),1);
      func_0x000180056290(&UNK_1819dd828,&UNK_1819dd838,&DAT_181b32b7c,0x181b32b80,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd850,&UNK_1819dd868,&DAT_181b2f398,0x181b32bd8,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd878,&UNK_1819dd890,&DAT_181b303b8,0x181b32ba0,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd8a8,&UNK_1819dd8c0,&DAT_181b32b40,0x181b32bf0,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd8e0,&UNK_1819dd8f8,&DAT_181b2f3c8,0x181b32bd4,uVar35);
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,*pfVar24 - *(float *)(lVar25 + 0x100));
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar19 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar19,&UNK_1819dd928);
      func_0x000180057580(&UNK_1819dd928,uVar7,&uStackX_10);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd950,&UNK_1819dd910,&DAT_181b32b50,0x181b32ba4,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd978,&UNK_1819dd938,&DAT_181b32b4c,0x181b32bbc,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd9a0,&UNK_1819dd960,&DAT_181b303bc,0x181b32bc0,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd9c8,&UNK_1819dd988,&DAT_181b30428,0x181b32bc4,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd9f0,&UNK_1819dd9b0,&DAT_181ade2b8,0x181b32ce0,uVar35);
      puVar16 = (undefined8 *)CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dda18,&UNK_1819dd9d8,&DAT_181b3042c,0x181b32be8,puVar16);
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    if (_DAT_181b50d50 != 4) goto LAB_1800b3b57;
    fVar34 = _DAT_181b32b44 + fVar34;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
    *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar34;
    *(undefined *)(lVar25 + 0x141) = 1;
    func_0x000180019310();
    lVar20 = _DAT_181b2f2c0;
    lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
       (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
      pfVar23 = (float *)(lVar25 + 0x224);
    }
    if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
       (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
      pfVar24 = (float *)(lVar25 + 0x220);
    }
    uStackX_10 = (undefined *)
                 CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810)) -
                          fVar39) + _DAT_181b32b44,(*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41)
    ;
    *(undefined *)(lVar25 + 0xb8) = 1;
    uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(2,&uStackX_8);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(0xe,&uStackX_8);
    uVar7 = func_0x000180009d10(uVar35,&UNK_1819dda00);
    func_0x000180057580(&UNK_1819dda00,uVar7,&uStackX_10);
    cVar4 = func_0x000180059d50(&UNK_1819dda28,&UNK_1819dda40,&DAT_181b30590);
    if ((cVar4 != '\0') && (DAT_181b30590 != '\0')) {
      func_0x0001800b5bd0(&uStack_118);
      func_0x000180067c80(&uStack_118);
      if (iStack_110 != 0) {
        terminate();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    cVar4 = func_0x000180059d50(&UNK_1819dda58,&UNK_1819dda70,&DAT_181b30592);
    if ((cVar4 != '\0') && (DAT_181b30592 != '\0')) {
      func_0x0001800b5c40(&uStack_118);
      func_0x000180067c80(&uStack_118);
      if (iStack_110 != 0) {
        terminate();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    func_0x000180059d50(&UNK_1819dda90,&UNK_1819ddaa0,&DAT_181b2bc6d);
    func_0x000180059d50(&UNK_1819ddab8,&UNK_1819ddad0,&DAT_181b2bc70);
    lVar26 = _DAT_181b2f2c0;
    if (DAT_181b2f6dd == '\0') {
      _DAT_181b32b60 = 0;
      DAT_181ade204 = 1;
      DAT_181b2f6dd = '\x01';
    }
    apuStack_168[0] = (undefined8 *)&UNK_1819ddb38;
    apuStack_168[1] = (undefined8 *)&UNK_1819ddb20;
    if ((_DAT_181b32b60 < 0) || (1 < _DAT_181b32b60)) {
      _DAT_181b32b60 = 0;
    }
    puVar29 = (undefined8 *)&UNK_18020df8a;
    if (apuStack_168[_DAT_181b32b60] != (undefined8 *)0x0) {
      puVar29 = apuStack_168[_DAT_181b32b60];
    }
    cVar4 = func_0x00018005b350(&UNK_1819ddb50,&UNK_1819ddb60,puVar29,2,
                                (ulonglong)puVar16 & 0xffffffffffffff00,
                                (ulonglong)puVar18 & 0xffffffff00000000);
    if (cVar4 != '\0') {
      bVar3 = false;
      uStackX_8 = (undefined *)0x4170000041700000;
      func_0x000180006ac0(0xe,&uStackX_8);
      puVar18 = (undefined8 *)&UNK_1819d4fc8;
      if (apuStack_168[0] != (undefined8 *)0x0) {
        puVar18 = apuStack_168[0];
      }
      func_0x000180015530(0);
      iVar8 = _DAT_181b32b60;
      uStackX_8 = (undefined *)0x0;
      cVar4 = func_0x00018005d120(puVar18,_DAT_181b32b60 == 0,0,&uStackX_8);
      if ((cVar4 != '\0') && (_DAT_181b32b60 != 0)) {
        bVar3 = true;
        _DAT_181b32b60 = 0;
      }
      if (iVar8 == 0) {
        func_0x000180015390();
      }
      func_0x0001800155b0();
      puVar27 = &UNK_1819d4fc8;
      if (apuStack_168[1] != (undefined8 *)0x0) {
        puVar27 = (undefined *)apuStack_168[1];
      }
      func_0x000180015530(1);
      iVar8 = _DAT_181b32b60;
      uStackX_8 = (undefined *)0x0;
      cVar4 = func_0x00018005d120(puVar27,_DAT_181b32b60 == 1,0,&uStackX_8);
      if ((cVar4 != '\0') && (_DAT_181b32b60 != 1)) {
        bVar3 = true;
        _DAT_181b32b60 = 1;
      }
      if (iVar8 == 1) {
        func_0x000180015390();
      }
      func_0x0001800155b0();
      func_0x000180006ba0(1);
      func_0x000180013b80();
      if (bVar3) {
        func_0x00018000a300(*(undefined4 *)(lVar26 + 0x47b8));
        DAT_181ade204 = _DAT_181b32b60 == 0;
        uStack_188._0_4_ = _DAT_181a2aff0;
        uStack_188._4_4_ = _DAT_181a2aff4;
        iStack_180 = _DAT_181a2aff8;
        fStack_17c = _DAT_181a2affc;
        puVar27 = &UNK_1819ddb88;
        if (_DAT_181b32b60 == 0) {
          puVar27 = &UNK_1819ddba0;
        }
        recovered_18009bbb0(&UNK_1819ddba0,puVar27);
      }
    }
    func_0x000180059d50(&UNK_1819ddbb8,&UNK_1819ddbc8,&DAT_181b2bc6e);
    if (DAT_181b2bc6e == '\0') {
      func_0x00018005dc00(&UNK_1819ddbe8,&UNK_1819ddbf8,&DAT_181a2aff0,0x30120);
    }
    cVar4 = func_0x000180059d50(&UNK_1819ddc18,&UNK_1819ddc30,&DAT_181b305c0);
    if ((cVar4 != '\0') && (DAT_181b305c0 != '\0')) {
      func_0x0001800af680();
    }
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar26 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
      pfVar23 = (float *)(lVar26 + 0x250);
    }
    else {
      pfVar23 = (float *)(lVar26 + 0x220);
    }
    uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar26 + 0x100));
    cVar4 = func_0x000180058040(&UNK_1819ddc70,&uStackX_8);
    if (cVar4 != '\0') {
      func_0x0001800af9d0();
    }
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar26 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
      pfVar23 = (float *)(lVar26 + 0x250);
    }
    else {
      pfVar23 = (float *)(lVar26 + 0x220);
    }
    uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar26 + 0x100));
    cVar4 = func_0x000180058040(&UNK_1819ddc60,&uStackX_8);
    if (cVar4 != '\0') {
      uVar35 = func_0x0001800b5cb0(&uStack_188);
      func_0x000180067c80(uVar35);
      if (iStack_180 != 0) {
        terminate();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
  }
  func_0x0001800579c0();
  func_0x000180019460();
LAB_1800b3b57:
  func_0x00018009bde0();
  func_0x000180013b80();
  if (((_DAT_181b50d50 == 1) && (DAT_181b2bdd0 != '\0')) && (DAT_181b2bdd1 != '\0')) {
    func_0x000180091c60(1);
  }
  return;
}



/* ===== ANALYSIS FUNCTION 0x1800acfd0 ===== */

/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800acfd0(void)

{
  char cVar1;
  
  cVar1 = DAT_181b2f8c9;
  DAT_181b2b403 = 0;
  _DAT_181b2b430 = 0;
  DAT_181b2f8c9 = DAT_181b2f8c9 == '\0';
  DAT_181b2b432 = 0;
  if (cVar1 == '\0') {
    if (_DAT_181b30424 == 0) {
      DAT_181b2b403 = 1;
    }
    else {
      if (_DAT_181b30424 == 1) {
        _DAT_181b2b430 = 1;
        return;
      }
      if (_DAT_181b30424 == 3) {
        DAT_181b2b432 = 1;
        return;
      }
    }
  }
  return;
}

