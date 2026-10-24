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

