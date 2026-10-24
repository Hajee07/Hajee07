/* Fresh inferred Ghidra pseudocode from original APK DT_INIT recovery.
 * NOT original source; no Android/game runtime validation.
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void core_thread_2(void)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  byte *pbVar19;
  undefined *puVar20;
  undefined4 uVar21;
  byte *pbVar22;
  int iVar23;
  uint uVar24;
  uint extraout_r1;
  undefined4 *puVar25;
  uint uVar26;
  undefined (*pauVar27) [16];
  int *piVar28;
  int iVar29;
  undefined2 unaff_r9;
  undefined2 *in_r12;
  bool bVar30;
  undefined auVar31 [16];
  undefined auVar32 [16];
  undefined auVar33 [16];
  undefined8 uVar34;
  undefined8 uStack_29d8;
  undefined8 uStack_29d0;
  undefined8 uStack_29c8;
  undefined8 uStack_29c0;
  undefined4 uStack_29b8;
  undefined4 uStack_29b4;
  float fStack_29b0;
  undefined auStack_29a8 [8];
  undefined8 uStack_29a0;
  undefined8 uStack_2998;
  undefined4 uStack_2990;
  undefined4 uStack_298c;
  undefined8 uStack_28f0;
  undefined8 uStack_28e8;
  undefined4 uStack_28e0;
  undefined4 uStack_28dc;
  undefined8 uStack_2840;
  undefined8 uStack_2838;
  undefined4 uStack_2830;
  undefined4 uStack_282c;
  undefined8 uStack_2790;
  undefined8 uStack_2788;
  undefined4 uStack_2780;
  undefined4 uStack_277c;
  undefined8 uStack_26e0;
  undefined8 uStack_26d8;
  undefined4 uStack_26d0;
  undefined4 uStack_26cc;
  undefined8 uStack_2630;
  undefined8 uStack_2628;
  undefined4 uStack_2620;
  undefined4 uStack_261c;
  undefined8 uStack_2580;
  undefined8 uStack_2578;
  undefined4 uStack_2570;
  undefined4 uStack_256c;
  undefined8 uStack_24d0;
  undefined8 uStack_24c8;
  undefined4 uStack_24c0;
  undefined4 uStack_24bc;
  undefined8 uStack_2420;
  undefined8 uStack_2418;
  undefined4 uStack_2410;
  undefined4 uStack_240c;
  undefined8 uStack_2370;
  undefined8 uStack_2368;
  undefined4 uStack_2360;
  undefined4 uStack_235c;
  undefined8 uStack_22c0;
  undefined8 uStack_22b8;
  undefined4 uStack_22b0;
  undefined4 uStack_22ac;
  undefined8 uStack_2210;
  undefined8 uStack_2208;
  undefined4 uStack_2200;
  undefined4 uStack_21fc;
  undefined8 uStack_2160;
  undefined8 uStack_2158;
  undefined4 uStack_2150;
  undefined4 uStack_214c;
  undefined8 uStack_20b0;
  undefined8 uStack_20a8;
  undefined4 uStack_20a0;
  undefined4 uStack_209c;
  undefined8 uStack_2000;
  undefined8 uStack_1ff8;
  undefined4 uStack_1ff0;
  undefined4 uStack_1fec;
  undefined8 uStack_1f50;
  undefined8 uStack_1f48;
  undefined4 uStack_1f40;
  undefined4 uStack_1f3c;
  undefined8 uStack_1ea0;
  undefined8 uStack_1e98;
  undefined4 uStack_1e90;
  undefined4 uStack_1e8c;
  undefined8 uStack_1df0;
  undefined8 uStack_1de8;
  undefined4 uStack_1de0;
  undefined4 uStack_1ddc;
  undefined8 uStack_1d40;
  undefined8 uStack_1d38;
  undefined4 uStack_1d30;
  undefined4 uStack_1d2c;
  undefined8 uStack_1c90;
  undefined8 uStack_1c88;
  undefined4 uStack_1c80;
  undefined4 uStack_1c7c;
  undefined8 uStack_1be0;
  undefined8 uStack_1bd8;
  undefined4 uStack_1bd0;
  undefined4 uStack_1bcc;
  undefined8 uStack_1b30;
  undefined8 uStack_1b28;
  undefined4 uStack_1b20;
  undefined4 uStack_1b1c;
  undefined8 uStack_1a80;
  undefined8 uStack_1a78;
  undefined4 uStack_1a70;
  undefined4 uStack_1a6c;
  undefined8 uStack_19d0;
  undefined8 uStack_19c8;
  undefined4 uStack_19c0;
  undefined4 uStack_19bc;
  undefined8 uStack_1920;
  undefined8 uStack_1918;
  undefined4 uStack_1910;
  undefined4 uStack_190c;
  undefined8 uStack_1870;
  undefined8 uStack_1868;
  undefined4 uStack_1860;
  undefined4 uStack_185c;
  undefined8 uStack_17c0;
  undefined8 uStack_17b8;
  undefined4 uStack_17b0;
  undefined4 uStack_17ac;
  undefined8 uStack_1710;
  undefined8 uStack_1708;
  undefined4 uStack_1700;
  undefined4 uStack_16fc;
  undefined8 uStack_1660;
  undefined8 uStack_1658;
  undefined4 uStack_1650;
  undefined4 uStack_164c;
  undefined8 uStack_15b0;
  undefined8 uStack_15a8;
  undefined4 uStack_15a0;
  undefined4 uStack_159c;
  undefined8 uStack_1500;
  undefined8 uStack_14f8;
  undefined4 uStack_14f0;
  undefined4 uStack_14ec;
  undefined8 uStack_1450;
  undefined8 uStack_1448;
  undefined4 uStack_1440;
  undefined4 uStack_143c;
  undefined8 uStack_13a0;
  undefined8 uStack_1398;
  undefined4 uStack_1390;
  undefined4 uStack_138c;
  undefined8 uStack_12f0;
  undefined8 uStack_12e8;
  undefined4 uStack_12e0;
  undefined4 uStack_12dc;
  undefined8 uStack_1240;
  undefined8 uStack_1238;
  undefined4 uStack_1230;
  undefined4 uStack_122c;
  undefined8 uStack_1190;
  undefined8 uStack_1188;
  undefined4 uStack_1180;
  undefined4 uStack_117c;
  undefined8 uStack_10e0;
  undefined8 uStack_10d8;
  undefined4 uStack_10d0;
  undefined4 uStack_10cc;
  undefined8 uStack_1030;
  undefined8 uStack_1028;
  undefined4 uStack_1020;
  undefined4 uStack_101c;
  undefined8 uStack_f80;
  undefined8 uStack_f78;
  undefined4 uStack_f70;
  undefined4 uStack_f6c;
  undefined8 uStack_ed0;
  undefined8 uStack_ec8;
  undefined4 uStack_ec0;
  undefined4 uStack_ebc;
  undefined8 uStack_e20;
  undefined8 uStack_e18;
  undefined4 uStack_e10;
  undefined4 uStack_e0c;
  undefined8 uStack_d70;
  undefined8 uStack_d68;
  undefined4 uStack_d60;
  undefined4 uStack_d5c;
  undefined8 uStack_cc0;
  undefined8 uStack_cb8;
  undefined4 uStack_cb0;
  undefined4 uStack_cac;
  undefined8 uStack_c10;
  undefined8 uStack_c08;
  undefined4 uStack_c00;
  undefined4 uStack_bfc;
  undefined8 uStack_b60;
  undefined8 uStack_b58;
  undefined4 uStack_b50;
  undefined4 uStack_b4c;
  undefined8 uStack_ab0;
  undefined8 uStack_aa8;
  undefined4 uStack_aa0;
  undefined4 uStack_a9c;
  undefined8 uStack_a00;
  undefined8 uStack_9f8;
  undefined4 uStack_9f0;
  undefined4 uStack_9ec;
  undefined8 uStack_950;
  undefined8 uStack_948;
  undefined4 uStack_940;
  undefined4 uStack_93c;
  undefined8 uStack_8a0;
  undefined8 uStack_898;
  undefined4 uStack_890;
  undefined4 uStack_88c;
  undefined8 uStack_7f0;
  undefined8 uStack_7e8;
  undefined4 uStack_7e0;
  undefined4 uStack_7dc;
  undefined8 uStack_740;
  undefined8 uStack_738;
  undefined4 uStack_730;
  undefined4 uStack_72c;
  undefined8 uStack_690;
  undefined8 uStack_688;
  undefined4 uStack_680;
  undefined4 uStack_67c;
  undefined8 uStack_5e0;
  undefined8 uStack_5d8;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  undefined8 uStack_530;
  undefined8 uStack_528;
  undefined4 uStack_520;
  undefined4 uStack_51c;
  undefined8 uStack_480;
  undefined8 uStack_478;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  undefined8 uStack_3d0;
  undefined8 uStack_3c8;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined8 uStack_320;
  undefined8 uStack_318;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_48;
  
  piVar28 = *(int **)(iRam1012de38 + 0x1012d134);
  iStack_48 = *piVar28;
  iVar17 = func_0x101aa730(iRam1012de3c + 0x1012d144);
  if (((iVar17 == 0) || (iVar17 = func_0x101aa764(iRam1012de40 + 0x1012d158), iVar17 == 0)) ||
     (iVar17 = func_0x101aa864(iRam1012de44 + 0x1012d16c), iVar17 == 0)) {
    iVar17 = *piVar28 - iStack_48;
    bVar30 = iVar17 == 0;
    if (bVar30) {
      return;
    }
    func_0x1010a7cc(iVar17);
    if (bVar30) {
      *in_r12 = unaff_r9;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  auVar31 = ZEXT816(0);
  iVar17 = iRam1012e444 + 0x1012d458;
  do {
    do {
      iVar18 = func_0x101aa8b4(iVar17);
    } while (iVar18 == 0);
    uStack_29d8 = auVar31._0_8_;
    uStack_29d0 = auVar31._8_8_;
    uStack_29c8 = uStack_29d8;
    uStack_29c0 = uStack_29d0;
    iVar17 = func_0x101aaa18(iVar17);
    while (iVar17 != 0) {
      func_0x1010a8f8(auStack_29a8,0x2960);
      uStack_2990 = 0;
      uStack_29a0 = auVar31._0_8_;
      uStack_2998 = auVar31._8_8_;
      uStack_298c = 0;
      uStack_28dc = 0;
      uStack_28e0 = 0;
      uStack_2830 = 0;
      uStack_282c = 0;
      uStack_2780 = 0;
      uStack_277c = 0;
      uStack_26d0 = 0;
      uStack_26cc = 0;
      uStack_2620 = 0;
      uStack_261c = 0;
      uStack_2570 = 0;
      uStack_256c = 0;
      uStack_24c0 = 0;
      uStack_24bc = 0;
      uStack_2410 = 0;
      uStack_240c = 0;
      uStack_2360 = 0;
      uStack_235c = 0;
      uStack_22b0 = 0;
      uStack_22ac = 0;
      uStack_2200 = 0;
      uStack_21fc = 0;
      uStack_2150 = 0;
      uStack_214c = 0;
      uStack_20a0 = 0;
      uStack_209c = 0;
      uStack_1ff0 = 0;
      uStack_1fec = 0;
      uStack_1f40 = 0;
      uStack_1f3c = 0;
      uStack_1e90 = 0;
      uStack_1e8c = 0;
      uStack_1de0 = 0;
      uStack_1ddc = 0;
      uStack_1d30 = 0;
      uStack_1d2c = 0;
      uStack_1c80 = 0;
      uStack_1c7c = 0;
      uStack_1bd0 = 0;
      uStack_1bcc = 0;
      uStack_1b20 = 0;
      uStack_1b1c = 0;
      uStack_1a70 = 0;
      uStack_1a6c = 0;
      uStack_19c0 = 0;
      uStack_19bc = 0;
      uStack_1910 = 0;
      uStack_190c = 0;
      uStack_1860 = 0;
      uStack_185c = 0;
      uStack_17b0 = 0;
      uStack_17ac = 0;
      uStack_1700 = 0;
      uStack_16fc = 0;
      uStack_1650 = 0;
      uStack_164c = 0;
      uStack_15a0 = 0;
      uStack_159c = 0;
      uStack_14f0 = 0;
      uStack_14ec = 0;
      uStack_1440 = 0;
      uStack_143c = 0;
      uStack_1390 = 0;
      uStack_138c = 0;
      uStack_12e0 = 0;
      uStack_12dc = 0;
      uStack_1230 = 0;
      uStack_122c = 0;
      uStack_1180 = 0;
      uStack_117c = 0;
      uStack_10d0 = 0;
      uStack_10cc = 0;
      uStack_1020 = 0;
      uStack_101c = 0;
      uStack_f70 = 0;
      uStack_f6c = 0;
      uStack_ec0 = 0;
      uStack_ebc = 0;
      uStack_e10 = 0;
      uStack_e0c = 0;
      uStack_d60 = 0;
      uStack_d5c = 0;
      uStack_cb0 = 0;
      uStack_cac = 0;
      uStack_c00 = 0;
      uStack_bfc = 0;
      uStack_b50 = 0;
      uStack_b4c = 0;
      uStack_aa0 = 0;
      uStack_a9c = 0;
      uStack_9f0 = 0;
      uStack_9ec = 0;
      uStack_940 = 0;
      uStack_93c = 0;
      uStack_890 = 0;
      uStack_88c = 0;
      uStack_7e0 = 0;
      uStack_7dc = 0;
      uStack_730 = 0;
      uStack_72c = 0;
      uStack_680 = 0;
      uStack_67c = 0;
      uStack_5d0 = 0;
      uStack_5cc = 0;
      uStack_520 = 0;
      uStack_51c = 0;
      uStack_470 = 0;
      uStack_46c = 0;
      uStack_3c0 = 0;
      uStack_3bc = 0;
      uStack_310 = 0;
      uStack_30c = 0;
      uStack_260 = 0;
      uStack_25c = 0;
      uStack_1b0 = 0;
      uStack_1ac = 0;
      uStack_100 = 0;
      uStack_fc = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_28f0 = uStack_29a0;
      uStack_28e8 = uStack_2998;
      uStack_2840 = uStack_29a0;
      uStack_2838 = uStack_2998;
      uStack_2790 = uStack_29a0;
      uStack_2788 = uStack_2998;
      uStack_26e0 = uStack_29a0;
      uStack_26d8 = uStack_2998;
      uStack_2630 = uStack_29a0;
      uStack_2628 = uStack_2998;
      uStack_2580 = uStack_29a0;
      uStack_2578 = uStack_2998;
      uStack_24d0 = uStack_29a0;
      uStack_24c8 = uStack_2998;
      uStack_2420 = uStack_29a0;
      uStack_2418 = uStack_2998;
      uStack_2370 = uStack_29a0;
      uStack_2368 = uStack_2998;
      uStack_22c0 = uStack_29a0;
      uStack_22b8 = uStack_2998;
      uStack_2210 = uStack_29a0;
      uStack_2208 = uStack_2998;
      uStack_2160 = uStack_29a0;
      uStack_2158 = uStack_2998;
      uStack_20b0 = uStack_29a0;
      uStack_20a8 = uStack_2998;
      uStack_2000 = uStack_29a0;
      uStack_1ff8 = uStack_2998;
      uStack_1f50 = uStack_29a0;
      uStack_1f48 = uStack_2998;
      uStack_1ea0 = uStack_29a0;
      uStack_1e98 = uStack_2998;
      uStack_1df0 = uStack_29a0;
      uStack_1de8 = uStack_2998;
      uStack_1d40 = uStack_29a0;
      uStack_1d38 = uStack_2998;
      uStack_1c90 = uStack_29a0;
      uStack_1c88 = uStack_2998;
      uStack_1be0 = uStack_29a0;
      uStack_1bd8 = uStack_2998;
      uStack_1b30 = uStack_29a0;
      uStack_1b28 = uStack_2998;
      uStack_1a80 = uStack_29a0;
      uStack_1a78 = uStack_2998;
      uStack_19d0 = uStack_29a0;
      uStack_19c8 = uStack_2998;
      uStack_1920 = uStack_29a0;
      uStack_1918 = uStack_2998;
      uStack_1870 = uStack_29a0;
      uStack_1868 = uStack_2998;
      uStack_17c0 = uStack_29a0;
      uStack_17b8 = uStack_2998;
      uStack_1710 = uStack_29a0;
      uStack_1708 = uStack_2998;
      uStack_1660 = uStack_29a0;
      uStack_1658 = uStack_2998;
      uStack_15b0 = uStack_29a0;
      uStack_15a8 = uStack_2998;
      uStack_1500 = uStack_29a0;
      uStack_14f8 = uStack_2998;
      uStack_1450 = uStack_29a0;
      uStack_1448 = uStack_2998;
      uStack_13a0 = uStack_29a0;
      uStack_1398 = uStack_2998;
      uStack_12f0 = uStack_29a0;
      uStack_12e8 = uStack_2998;
      uStack_1240 = uStack_29a0;
      uStack_1238 = uStack_2998;
      uStack_1190 = uStack_29a0;
      uStack_1188 = uStack_2998;
      uStack_10e0 = uStack_29a0;
      uStack_10d8 = uStack_2998;
      uStack_1030 = uStack_29a0;
      uStack_1028 = uStack_2998;
      uStack_f80 = uStack_29a0;
      uStack_f78 = uStack_2998;
      uStack_ed0 = uStack_29a0;
      uStack_ec8 = uStack_2998;
      uStack_e20 = uStack_29a0;
      uStack_e18 = uStack_2998;
      uStack_d70 = uStack_29a0;
      uStack_d68 = uStack_2998;
      uStack_cc0 = uStack_29a0;
      uStack_cb8 = uStack_2998;
      uStack_c10 = uStack_29a0;
      uStack_c08 = uStack_2998;
      uStack_b60 = uStack_29a0;
      uStack_b58 = uStack_2998;
      uStack_ab0 = uStack_29a0;
      uStack_aa8 = uStack_2998;
      uStack_a00 = uStack_29a0;
      uStack_9f8 = uStack_2998;
      uStack_950 = uStack_29a0;
      uStack_948 = uStack_2998;
      uStack_8a0 = uStack_29a0;
      uStack_898 = uStack_2998;
      uStack_7f0 = uStack_29a0;
      uStack_7e8 = uStack_2998;
      uStack_740 = uStack_29a0;
      uStack_738 = uStack_2998;
      uStack_690 = uStack_29a0;
      uStack_688 = uStack_2998;
      uStack_5e0 = uStack_29a0;
      uStack_5d8 = uStack_2998;
      uStack_530 = uStack_29a0;
      uStack_528 = uStack_2998;
      uStack_480 = uStack_29a0;
      uStack_478 = uStack_2998;
      uStack_3d0 = uStack_29a0;
      uStack_3c8 = uStack_2998;
      uStack_320 = uStack_29a0;
      uStack_318 = uStack_2998;
      uStack_270 = uStack_29a0;
      uStack_268 = uStack_2998;
      uStack_1c0 = uStack_29a0;
      uStack_1b8 = uStack_2998;
      uStack_110 = uStack_29a0;
      uStack_108 = uStack_2998;
      func_0x1012af04();
      func_0x1012c100();
      func_0x1012cdd0();
      iVar16 = iRam1012f7ec;
      iVar15 = iRam1012f7e8;
      iVar14 = iRam1012f7a8;
      iVar13 = iRam1012f7a4;
      iVar12 = iRam1012f79c;
      iVar11 = iRam1012f798;
      iVar10 = iRam1012f794;
      iVar9 = iRam1012f780;
      iVar23 = iRam1012f4e4;
      iVar18 = iRam1012f3ec;
      iVar17 = iRam1012ed94;
      if (0x412 < (int)uStack_29d8) {
        iVar29 = iRam1012e880 + 0x1012d8a0;
        if ((int)uStack_29d8 < 0x161c) {
          if ((int)uStack_29d8 < 0x1389) {
            switch((int)uStack_29d8) {
            case 0x413:
              *(float *)(iRam1012e8e4 + 0x1012d97c) = (float)(longlong)(int)uStack_29d0;
              break;
            case 0x414:
              *(char *)(iRam1012f45c + 0x1012e510) = uStack_29d8._4_1_;
              break;
            case 0x415:
              *(char *)(iRam1012f454 + 0x1012e4f5) = uStack_29d8._4_1_;
              break;
            case 0x416:
              *(char *)(iRam1012f4e0 + 0x1012e55a) = uStack_29d8._4_1_;
              break;
            case 0x417:
              *(char *)(iRam1012f4e8 + 0x1012e57e) = uStack_29d8._4_1_;
              break;
            case 0x418:
              *(char *)(iRam1012f4dc + 0x1012e53b) = uStack_29d8._4_1_;
              break;
            case 0x419:
              *(char *)(iRam1012f450 + 0x1012e4d8) = uStack_29d8._4_1_;
              break;
            case 0x41a:
              *(char *)(iRam1012f44c + 0x1012e4c1) = uStack_29d8._4_1_;
              break;
            case 0x41b:
              *(char *)(iRam1012f460 + 0x1012e529) = uStack_29d8._4_1_;
              break;
            default:
              goto LAB_1012e610;
            case 0x41d:
              *(char *)(iRam1012f4e4 + 0x1012e59e) = uStack_29d8._4_1_;
              *(char *)(iVar23 + 0x1012e561) = uStack_29d8._4_1_;
              *(char *)(iVar23 + 0x1012e55b) = uStack_29d8._4_1_;
              break;
            case 0x41e:
              *(char *)(iRam1012f3ec + 0x1012e4c7) = uStack_29d8._4_1_;
              *(char *)(iVar18 + 0x1012e4c8) = uStack_29d8._4_1_;
              *(char *)(iVar18 + 0x1012e489) = uStack_29d8._4_1_;
              break;
            case 0x41f:
              *(char *)(iRam1012f448 + 0x1012e477) = uStack_29d8._4_1_;
              break;
            case 0x420:
              *(char *)(iRam1012f458 + 0x1012e53c) = uStack_29d8._4_1_;
            }
          }
          else if ((int)uStack_29d8 < 0x138b) {
            if ((int)uStack_29d8 == 0x1389) {
              *(char *)(iRam1012f4ec + 0x1012e59a) = uStack_29d8._4_1_;
            }
            else {
              if ((int)uStack_29d8 != 0x138a) goto LAB_1012e610;
              *(char *)(iRam1012ed24 + 0x1012ddd0) = uStack_29d8._4_1_;
            }
          }
          else if ((int)uStack_29d8 == 0x138b) {
            *(char *)(iRam1012f57c + 0x1012e655) = uStack_29d8._4_1_;
          }
          else {
            if ((int)uStack_29d8 == 0x1619) goto LAB_1012dd78;
            if ((int)uStack_29d8 != 0x161b) goto LAB_1012e610;
            *(char *)(iRam1012ec3c + 0x1012dc8c) = uStack_29d8._4_1_;
          }
        }
        else if ((int)uStack_29d8 < 0xdd02) {
          if ((int)uStack_29d8 < 0x1eba) {
            if ((int)uStack_29d8 == 0x161c) {
              iVar17 = (int)uStack_29d0;
              if ((int)uStack_29d0 < 0x10) {
                iVar17 = 0xf;
              }
              if (99 < iVar17) {
                iVar17 = 100;
              }
              *(int *)(iRam1012f4f0 + 0x1012e568) = iVar17;
              iVar17 = func_0x10119490();
              if ((iVar17 != 0) && (iVar17 = func_0x101178e0(), iVar17 != 0)) {
                func_0x10116860(&uStack_29b8);
                if (*(char *)(iRam1012f574 + 0x1012e598) != '\0') {
                  uStack_29b4 = *(undefined4 *)(iRam1012f578 + 0x1012e5ac);
                }
                func_0x1011e690(iVar17,uStack_29b8,uStack_29b4,fStack_29b0);
              }
              *(undefined4 *)(iRam1012f6e8 + 0x1012e834) = 0;
              *(undefined *)(iRam1012f6ec + 0x1012e840) = 0;
              *(undefined4 *)(iRam1012f6f0 + 0x1012e84c) = 0;
            }
            else {
              if ((int)uStack_29d8 != 0x1eb9) goto LAB_1012e610;
              *(char *)(iRam1012ed44 + 0x1012dd9d) = uStack_29d8._4_1_;
            }
          }
          else if ((int)uStack_29d8 == 0x1eba) {
            *(char *)(iRam1012ec6c + 0x1012dcc2) = uStack_29d8._4_1_;
          }
          else if ((int)uStack_29d8 == 0x1ebb) {
            *(char *)(iRam1012ec6c + 0x1012dcbe) = uStack_29d8._4_1_;
          }
          else {
            if ((int)uStack_29d8 != 0x9c44) goto LAB_1012e610;
            *(char *)(iRam1012eca0 + 0x1012dd0a) = uStack_29d8._4_1_;
          }
        }
        else {
          switch((int)uStack_29d8) {
          case 0xdd02:
            *(char *)(iRam1012eb04 + 0x1012db8c) = uStack_29d8._4_1_;
            break;
          case 0xdd03:
          case 0xdd0b:
            goto LAB_1012e610;
          case 0xdd04:
            *(char *)(iRam1012f364 + 0x1012e3dd) = uStack_29d8._4_1_;
            break;
          case 0xdd05:
            *(char *)(iRam1012f368 + 0x1012e3f3) = uStack_29d8._4_1_;
            break;
          case 0xdd06:
            *(char *)(iRam1012f3dc + 0x1012e41a) = uStack_29d8._4_1_;
            break;
          case 0xdd07:
            *(char *)(iRam1012f3e0 + 0x1012e430) = uStack_29d8._4_1_;
            break;
          case 0xdd08:
            *(char *)(iRam1012f3e4 + 0x1012e44c) = uStack_29d8._4_1_;
            break;
          case 0xdd09:
            *(char *)(iRam1012f35c + 0x1012e3ba) = uStack_29d8._4_1_;
            break;
          case 0xdd0a:
            *(char *)(iRam1012f36c + 0x1012e411) = uStack_29d8._4_1_;
            break;
          case 0xdd0c:
            *(char *)(iRam1012f358 + 0x1012e3af) = uStack_29d8._4_1_;
            break;
          case 0xdd0d:
            *(char *)(iRam1012f360 + 0x1012e3cf) = uStack_29d8._4_1_;
            break;
          case 0xdd0e:
            *(int *)(iRam1012f3e8 + 0x1012e45c) = (int)uStack_29d0;
            break;
          default:
            if ((int)uStack_29d8 == 0x8a21d) {
              *(char *)(iRam1012f580 + 0x1012e603) = uStack_29d8._4_1_;
            }
            else {
              if ((int)uStack_29d8 != 0x56552b) goto LAB_1012e610;
              *(char *)(iRam1012ecf8 + 0x1012dd4c) = uStack_29d8._4_1_;
            }
          }
        }
        goto LAB_1012e84c;
      }
      iVar29 = iRam1012e910 + 0x1012d92c;
      if (0xa5 < (int)uStack_29d8) {
        switch((int)uStack_29d8) {
        case 500:
          *(char *)(iRam1012ec04 + 0x1012dc41) = uStack_29d8._4_1_;
          break;
        case 0x1f5:
          *(char *)(iRam1012ed98 + 0x1012de23) = uStack_29d8._4_1_;
          break;
        case 0x1f6:
          *(char *)(iRam1012ed8c + 0x1012dde8) = uStack_29d8._4_1_;
          break;
        case 0x1f7:
        case 0x1fa:
        case 0x1fb:
        case 0x1fd:
        case 0x1fe:
        case 0x1ff:
        case 0x200:
        case 0x201:
        case 0x202:
        case 0x203:
        case 0x204:
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x209:
        case 0x20a:
        case 0x20b:
        case 0x20c:
        case 0x20e:
        case 0x212:
          goto LAB_1012e610;
        case 0x1f8:
          *(char *)(iRam1012ed94 + 0x1012de15) = uStack_29d8._4_1_;
          *(char *)(iVar17 + 0x1012de14) = uStack_29d8._4_1_;
          *(char *)(iVar17 + 0x1012de05) = uStack_29d8._4_1_;
          *(char *)(iVar17 + 0x1012de04) = uStack_29d8._4_1_;
          break;
        case 0x1f9:
          *(char *)(iRam1012ed90 + 0x1012ddec) = uStack_29d8._4_1_;
          break;
        case 0x1fc:
          *(char *)(iRam1012ed9c + 0x1012de35) = uStack_29d8._4_1_;
          break;
        case 0x20d:
          iVar17 = (int)uStack_29c0;
          *(int *)(iRam1012eda0 + 0x1012de60) = (int)uStack_29c0;
          if ((int)uStack_29c0 == 0) {
            *(undefined *)(iRam1012f74c + 0x1012e840) = 0;
            puVar20 = (undefined *)(iRam1012f750 + 0x1012e7ec);
          }
          else {
            *(undefined *)(iRam1012eda4 + 0x1012ded4) = 1;
            DataMemoryBarrier(0xb);
            if (((*(byte *)(iRam1012eda8 + 0x1012de80) & 1) == 0) &&
               (iVar23 = func_0x1010a874(iRam1012f6fc + 0x1012f2e0), iVar18 = iRam1012f700,
               iVar23 != 0)) {
              puVar25 = (undefined4 *)(iRam1012f700 + 0x1012f2fc);
              *puVar25 = 0x52d2548a;
              *(undefined4 *)(iVar18 + 0x1012f300) = 0x6e0b81e8;
              *(undefined4 *)(iVar18 + 0x1012f304) = 0x5ff264e6;
              *(undefined4 *)(iVar18 + 0x1012f308) = 0x391791e4;
              *(undefined4 *)(iVar18 + 0x1012f30c) = 0x37cd4baf;
              *(undefined *)(iVar18 + 0x1012f310) = 1;
              func_0x1010a7c0(iRam1012f704 + 0x1012f340,puVar25,iRam1012f708 + 0x1012f344);
              func_0x1010a880(iRam1012f70c + 0x1012f350);
            }
            if (*(char *)(iRam1012edac + 0x1012deac) != '\0') {
              auVar32._8_8_ = uRam1012e288;
              auVar32._0_8_ = uRam1012e280;
              pbVar19 = (byte *)(iRam1012edac + 0x1012deab);
              auVar32 = *(undefined (*) [16])(iRam1012edac + 0x1012de98) ^ auVar32;
              bVar2 = *(byte *)(iRam1012edb4 + 0x1012dee5);
              bVar3 = *pbVar19;
              bVar4 = *(byte *)(iRam1012edb8 + 0x1012def6);
              *(byte *)(iRam1012edbc + 0x1012df00) = *(byte *)(iRam1012edb0 + 0x1012ded4) ^ 0xcb;
              *(byte *)(iRam1012edc0 + 0x1012df11) = bVar2 ^ 0x27;
              *(byte *)(iRam1012edc4 + 0x1012df22) = bVar4 ^ 0xa1;
              *pbVar19 = bVar3 ^ 0x37;
              iVar18 = iRam1012edc8;
              *(longlong *)(iRam1012edc8 + 0x1012df24) = auVar32._0_8_;
              *(longlong *)(iVar18 + 0x1012df2c) = auVar32._8_8_;
              *(undefined *)(iVar18 + 0x1012df38) = 0;
            }
            DataMemoryBarrier(0xb);
            if (((*(byte *)(iRam1012edcc + 0x1012df34) & 1) == 0) &&
               (iVar23 = func_0x1010a874(iRam1012f710 + 0x1012f37c), iVar18 = iRam1012f714,
               iVar23 != 0)) {
              puVar25 = (undefined4 *)(iRam1012f714 + 0x1012f398);
              *(undefined4 *)(iRam1012f714 + 0x1012f3a0) = 0x4ec04b9b;
              *(undefined4 *)(iVar18 + 0x1012f39c) = 0x720a82c2;
              *puVar25 = 0x19f66888;
              *(undefined2 *)(iVar18 + 0x1012f3a4) = 0x185;
              func_0x1010a7c0(iRam1012f718 + 0x1012f3c8,puVar25,iRam1012f71c + 0x1012f3cc);
              func_0x1010a880(iRam1012f720 + 0x1012f3d8);
            }
            if (*(char *)(iRam1012edd0 + 0x1012df59) != '\0') {
              bVar2 = *(byte *)(iRam1012edd4 + 0x1012df69);
              bVar3 = *(byte *)(iRam1012edd8 + 0x1012df76);
              bVar4 = *(byte *)(iRam1012eddc + 0x1012df83);
              bVar5 = *(byte *)(iRam1012ede0 + 0x1012df91);
              bVar6 = *(byte *)(iRam1012ede4 + 0x1012dfa0);
              bVar7 = *(byte *)(iRam1012ede8 + 0x1012dfae);
              *(byte *)(iRam1012edec + 0x1012dfb8) = *(byte *)(iRam1012edd0 + 0x1012df4c) ^ 0xcb;
              bVar8 = *(byte *)(iRam1012edf0 + 0x1012dfcf);
              *(byte *)(iRam1012edf4 + 0x1012dfd9) = bVar2 ^ 0x27;
              bVar2 = *(byte *)(iRam1012edf8 + 0x1012dff0);
              *(byte *)(iRam1012edfc + 0x1012dff6) = bVar3 ^ 0xa1;
              bVar3 = *(byte *)(iRam1012ee00 + 0x1012e00d);
              *(byte *)(iRam1012ee04 + 0x1012e013) = bVar4 ^ 0x37;
              *(byte *)(iRam1012ee08 + 0x1012e024) = bVar6 ^ 0x85;
              *(byte *)(iRam1012ee0c + 0x1012e039) = bVar5 ^ 0xe3;
              *(byte *)(iRam1012ee10 + 0x1012e04e) = bVar7 ^ 0x67;
              iVar18 = iRam1012ee14;
              *(byte *)(iRam1012ee14 + 0x1012e063) = bVar8 ^ 0x17;
              *(byte *)(iVar18 + 0x1012e064) = bVar2 ^ 0xcb;
              *(byte *)(iVar18 + 0x1012e065) = bVar3 ^ 0x27;
              *(byte *)(iVar18 + 0x1012e066) = *(byte *)(iVar18 + 0x1012e066) ^ 0xa1;
              *(byte *)(iVar18 + 0x1012e067) = *(byte *)(iVar18 + 0x1012e067) ^ 0x37;
              *(undefined *)(iVar18 + 0x1012e069) = 0;
              *(byte *)(iVar18 + 0x1012e068) = *(byte *)(iVar18 + 0x1012e068) ^ 0x85;
            }
            DataMemoryBarrier(0xb);
            if (((*(byte *)(iRam1012ee18 + 0x1012e0a0) & 1) == 0) &&
               (iVar23 = func_0x1010a874(iRam1012f724 + 0x1012f3fc), iVar18 = iRam1012f728,
               iVar23 != 0)) {
              puVar25 = (undefined4 *)(iRam1012f728 + 0x1012f418);
              *puVar25 = 0x4ec04b9b;
              *(undefined4 *)(iVar18 + 0x1012f41c) = 0x16791e0;
              func_0x1010a7c0(iRam1012f72c + 0x1012f434,puVar25,iRam1012f730 + 0x1012f438);
              func_0x1010a880(iRam1012f734 + 0x1012f444);
            }
            if (*(char *)(iRam1012ee1c + 0x1012e0bf) != '\0') {
              bVar2 = *(byte *)(iRam1012ee1c + 0x1012e0b8);
              bVar3 = *(byte *)(iRam1012ee1c + 0x1012e0b9);
              bVar4 = *(byte *)(iRam1012ee20 + 0x1012e0da);
              bVar5 = *(byte *)(iRam1012ee24 + 0x1012e0e7);
              bVar6 = *(byte *)(iRam1012ee28 + 0x1012e0f5);
              *(undefined *)(iRam1012ee2c + 0x1012e107) = 0;
              bVar7 = *(byte *)(iRam1012ee30 + 0x1012e110);
              bVar8 = *(byte *)(iRam1012ee34 + 0x1012e11e);
              *(byte *)(iRam1012ee38 + 0x1012e128) = bVar2 ^ 0xcb;
              *(byte *)(iRam1012ee3c + 0x1012e139) = bVar3 ^ 0x27;
              iVar18 = iRam1012ee40;
              *(byte *)(iRam1012ee40 + 0x1012e14a) = bVar4 ^ 0xa1;
              *(byte *)(iVar18 + 0x1012e14b) = bVar5 ^ 0x37;
              *(byte *)(iVar18 + 0x1012e14c) = bVar7 ^ 0x85;
              *(byte *)(iVar18 + 0x1012e14d) = bVar6 ^ 0xe3;
              *(byte *)(iVar18 + 0x1012e14e) = bVar8 ^ 0x67;
            }
            DataMemoryBarrier(0xb);
            if (((*(byte *)(iRam1012ee44 + 0x1012e17c) & 1) == 0) &&
               (iVar23 = func_0x1010a874(iRam1012f738 + 0x1012f470), iVar18 = iRam1012f73c,
               iVar23 != 0)) {
              puVar25 = (undefined4 *)(iRam1012f73c + 0x1012f48c);
              *(undefined4 *)(iRam1012f73c + 0x1012f498) = 0x720a82cb;
              *(undefined4 *)(iVar18 + 0x1012f494) = 0x5cc24e85;
              *(undefined4 *)(iVar18 + 0x1012f490) = 0x7b068dec;
              *puVar25 = 0x50c85584;
              *(undefined2 *)(iVar18 + 0x1012f49c) = 0x1cb;
              func_0x1010a7c0(iRam1012f740 + 0x1012f4c8,puVar25,iRam1012f744 + 0x1012f4cc);
              func_0x1010a880(iRam1012f748 + 0x1012f4d8);
            }
            func_0x10198ef0(iRam1012ee48 + 0x1012e194);
            iVar18 = func_0x101a4900(iRam1012ee4c + 0x1012e1a8,iRam1012ee50 + 0x1012e1b0,
                                     iRam1012ee54 + 0x1012e1b4,iRam1012ee58 + 0x1012e1b8);
            iVar17 = *(int *)(iVar18 + iVar17);
            puVar20 = (undefined *)(iRam1012ee5c + 0x1012e1cc);
            if (iVar17 != 0) {
              iVar18 = func_0x101278d0(iVar17);
              puVar20 = (undefined *)(iRam1012ee60 + 0x1012e1f0);
              if (iVar18 != 0) {
                uVar21 = func_0x101278d0(iVar17);
                func_0x1010a8a4(iRam1012ee64 + 0x1012e20c,uVar21,0x7f);
                *(undefined *)(iRam1012ee68 + 0x1012e218) = 0;
                break;
              }
            }
          }
          *puVar20 = 0;
          break;
        case 0x20f:
          *(char *)(iRam1012f21c + 0x1012e2b4) = uStack_29d8._4_1_;
          break;
        case 0x210:
          *(char *)(iRam1012ed80 + 0x1012de11) = uStack_29d8._4_1_;
          break;
        case 0x211:
          *(char *)((int)&iRam1012de38 + iRam1012ed88 + 2) = uStack_29d8._4_1_;
          break;
        case 0x213:
          *(char *)(iRam1012f218 + 0x1012e2a4) = uStack_29d8._4_1_;
          break;
        case 0x214:
          *(char *)(iRam1012ed84 + 0x1012de29) = uStack_29d8._4_1_;
          break;
        default:
          if ((int)uStack_29d8 == 0xa6) {
            *(char *)(iRam1012f5f0 + 0x1012e632) = uStack_29d8._4_1_;
            if (uStack_29d8._4_1_ == '\0') {
              iVar17 = func_0x101aa630(iRam1012f6f4 + 0x1012e7fc);
              if (iVar17 != 0) {
                func_0x101aa680(iRam1012f6f8 + 0x1012e810);
              }
            }
            else {
              func_0x1012cf34();
            }
          }
          else {
            if ((int)uStack_29d8 != 0x379) goto LAB_1012e610;
            *(char *)(iRam1012eccc + 0x1012dd33) = uStack_29d8._4_1_;
          }
        }
        goto LAB_1012e84c;
      }
      switch((int)uStack_29d8) {
      case 1:
        break;
      default:
LAB_1012e610:
        switch((int)uStack_29d8) {
        case 0x1b59:
          *(char *)(iRam1012f758 + 0x1012e85a) = uStack_29d8._4_1_;
          break;
        case 0x1b5a:
          *(char *)(iRam1012f75c + 0x1012ea47) = uStack_29d8._4_1_;
          break;
        case 0x1b5b:
          *(char *)(iRam1012f760 + 0x1012e9e4) = uStack_29d8._4_1_;
          break;
        case 0x1b5c:
          *(char *)(iRam1012f764 + 0x1012e9f9) = uStack_29d8._4_1_;
          break;
        case 0x1b5d:
          *(int *)(iRam1012f768 + 0x1012ea3c) = (int)uStack_29d0;
          break;
        case 0x1b5e:
          *(char *)(iRam1012f76c + 0x1012ea12) = uStack_29d8._4_1_;
          break;
        case 0x1b5f:
          *(char *)(iRam1012f770 + 0x1012ea63) = uStack_29d8._4_1_;
          break;
        case 0x1b60:
          *(char *)(iRam1012f774 + 0x1012ea89) = uStack_29d8._4_1_;
          break;
        case 0x1b61:
          *(char *)(iRam1012f778 + 0x1012ea7c) = uStack_29d8._4_1_;
          break;
        case 0x1b62:
          *(char *)(iRam1012f77c + 0x1012ea4c) = uStack_29d8._4_1_;
          break;
        case 0x1b63:
          *(char *)(iRam1012f788 + 0x1012ea2e) = uStack_29d8._4_1_;
          break;
        case 0x1b64:
          *(char *)(iRam1012f78c + 0x1012e9bf) = uStack_29d8._4_1_;
          break;
        case 0x1b65:
          *(char *)(iRam1012f790 + 0x1012eabc) = uStack_29d8._4_1_;
          break;
        case 0x1b66:
        case 0x1b67:
        case 0x1b68:
        case 0x1b69:
        case 0x1b6a:
        case 0x1b6b:
        case 0x1b6d:
        case 0x1b6e:
        case 0x1b6f:
        case 0x1b70:
        case 0x1b71:
        case 0x1b72:
        case 0x1b73:
        case 0x1b74:
        case 0x1b75:
        case 0x1b76:
        case 0x1b77:
        case 0x1b78:
        case 0x1b79:
        case 0x1b7a:
        case 0x1b7b:
        case 0x1b7c:
        case 0x1b7d:
        case 0x1b7e:
        case 0x1b7f:
        case 0x1b80:
        case 0x1b81:
        case 0x1b82:
        case 0x1b83:
        case 0x1b84:
        case 0x1b85:
        case 0x1b86:
        case 0x1b87:
        case 0x1b88:
        case 0x1b89:
        case 0x1b8a:
        case 0x1b8b:
        case 0x1b8c:
        case 0x1b8d:
        case 0x1b8e:
        case 0x1b8f:
        case 0x1b90:
        case 0x1b91:
        case 0x1b92:
        case 0x1b93:
        case 0x1b94:
        case 0x1b95:
        case 0x1b96:
        case 0x1b97:
        case 0x1b98:
        case 0x1b99:
        case 0x1b9a:
        case 0x1b9b:
        case 0x1b9c:
        case 0x1b9d:
        case 0x1b9e:
        case 0x1b9f:
        case 0x1ba0:
        case 0x1ba1:
        case 0x1ba2:
        case 0x1ba3:
        case 0x1ba4:
        case 0x1ba5:
        case 0x1ba6:
        case 0x1ba7:
        case 0x1ba8:
        case 0x1ba9:
        case 0x1baa:
        case 0x1bab:
        case 0x1bac:
        case 0x1bad:
        case 0x1bae:
        case 0x1baf:
        case 0x1bb0:
        case 0x1bb1:
        case 0x1bb2:
        case 0x1bb3:
        case 0x1bb4:
        case 0x1bb5:
        case 0x1bb6:
        case 0x1bb7:
        case 0x1bb8:
        case 0x1bb9:
        case 0x1bba:
        case 0x1bbb:
LAB_1012e8b0:
          if ((int)uStack_29d8 - 0x1bbeU < 0x14) {
            if (uStack_29d8._4_1_ != '\0') {
              *(undefined *)(iRam1012f79c + 0x1012e988) = 1;
              *(undefined *)(iVar12 + 0x1012e980) = 1;
              *(uint *)(iVar12 + 0x1012e984) = (int)uStack_29d8 - 0x1bbeU;
            }
            goto LAB_1012eafc;
          }
          if (0x437 < (int)uStack_29d8) {
            if ((int)uStack_29d8 < 0x146e) {
              if ((int)uStack_29d8 < 0x1389) {
                if ((int)uStack_29d8 == 0x438) {
                  *(char *)(iRam1012f7a4 + 0x1012eb58) = uStack_29d8._4_1_;
                  *(char *)(iVar13 + 0x1012eb32) = uStack_29d8._4_1_;
                  if (uStack_29d8._4_1_ != '\0') {
                    *(undefined *)(iVar13 + 0x1012eb31) = 0;
                  }
                }
                else {
                  if ((int)uStack_29d8 != 1099) goto LAB_1012e854;
                  *(char *)(iRam1012f7a8 + 0x1012ec42) = uStack_29d8._4_1_;
                  if (uStack_29d8._4_1_ == '\0') {
                    *(undefined *)(iVar14 + 0x1012ec41) = 0;
                  }
                }
              }
              else if ((int)uStack_29d8 == 0x1389) {
                *(char *)(iRam1012f7a4 + 0x1012eb86) = uStack_29d8._4_1_;
              }
              else {
                if ((int)uStack_29d8 != 0x144a) {
                  if ((int)uStack_29d8 == 0x144e) {
                    if ((uStack_29d8._4_1_ != '\0') && (iVar17 = func_0x10121720(), iVar17 != 0)) {
                      uVar21 = func_0x101178e0();
                      func_0x10116860(&uStack_29b8,uVar21);
                      fStack_29b0 = fStack_29b0 + 1.5;
                      *(undefined *)(iRam1012f7ac + 0x1012eba4) = 1;
                      iVar17 = iRam1012f7b0;
                      *(ulonglong *)(iRam1012f7b0 + 0x1012eba4) = CONCAT44(uStack_29b4,uStack_29b8);
                      *(float *)(iVar17 + 0x1012ebac) = fStack_29b0;
                    }
                    *(undefined *)(iRam1012f7b4 + 0x1012ebc3) = 0;
                    break;
                  }
                  goto LAB_1012e854;
                }
                *(char *)(iRam1012f7a4 + 0x1012ebb4) = uStack_29d8._4_1_;
              }
            }
            else if ((int)uStack_29d8 < 0x1eda) {
              if ((int)uStack_29d8 == 0x146e) {
                *(char *)(iRam1012f7b8 + 0x1012ebf6) = uStack_29d8._4_1_;
              }
              else {
                if ((int)uStack_29d8 != 0x1ed8) goto LAB_1012e854;
                *(char *)(iRam1012f7bc + 0x1012ecb5) = uStack_29d8._4_1_;
              }
            }
            else if ((int)uStack_29d8 == 0x1eda) {
              *(char *)(iRam1012f7b8 + 0x1012ec1a) = uStack_29d8._4_1_;
            }
            else if ((int)uStack_29d8 == 0x5afe) {
              *(char *)(iRam1012f7b8 + 0x1012ebe5) = uStack_29d8._4_1_;
            }
            else {
              if ((int)uStack_29d8 != 0x8812) goto LAB_1012e854;
              *(char *)(iRam1012f7c0 + 0x1012ec02) = uStack_29d8._4_1_;
            }
            goto LAB_1012eafc;
          }
          switch((int)uStack_29d8) {
          case 0x1fb:
            *(char *)(iRam1012f7e0 + 0x1012eb11) = uStack_29d8._4_1_;
            break;
          case 0x1fc:
          case 0x1ff:
          case 0x200:
          case 0x201:
          case 0x202:
            goto LAB_1012e854;
          case 0x1fd:
            *(char *)(iRam1012f7c8 + 0x1012eceb) = uStack_29d8._4_1_;
            break;
          case 0x1fe:
            *(char *)(iRam1012f7dc + 0x1012ecc7) = uStack_29d8._4_1_;
            break;
          case 0x203:
            *(char *)(iRam1012f7cc + 0x1012ed1e) = uStack_29d8._4_1_;
            break;
          case 0x204:
            *(char *)(iRam1012f7d0 + 0x1012ed37) = uStack_29d8._4_1_;
            break;
          case 0x205:
            *(char *)(iRam1012f7d4 + 0x1012ed50) = uStack_29d8._4_1_;
            break;
          case 0x206:
            *(char *)(iRam1012f7d8 + 0x1012ed65) = uStack_29d8._4_1_;
            break;
          case 0x207:
            *(char *)(iRam1012f7e4 + 0x1012ed78) = uStack_29d8._4_1_;
            break;
          case 0x208:
            *(char *)(iRam1012f7e8 + 0x1012ed4e) = uStack_29d8._4_1_;
            if (uStack_29d8._4_1_ != '\0') {
              *(undefined *)((int)&iRam1012ed94 + iVar15) = 1;
            }
            break;
          case 0x209:
            *(char *)((int)&iRam1012edb4 + iRam1012f7ec + 3) = uStack_29d8._4_1_;
            if (uStack_29d8._4_1_ != '\0') {
              *(undefined *)((int)&iRam1012edb4 + iVar16) = 1;
              *(undefined *)((int)&iRam1012edb0 + iVar16 + 2) = 1;
            }
            break;
          case 0x20a:
            *(char *)((int)&iRam1012eda4 + iRam1012f7f0 + 1) = uStack_29d8._4_1_;
            break;
          case 0x20b:
            *(char *)(iRam1012f7f4 + 0x1012eee0) = uStack_29d8._4_1_;
            if (((uStack_29d8._4_1_ != '\0') && (*(int *)(iRam1012f7f8 + 0x1012ee90) == 0)) &&
               (uVar26 = *(uint *)(iRam1012f7fc + 0x1012eea0), uVar26 != 0)) {
              *(uint *)(iRam1012f800 + 0x1012eeb8) = uVar26;
              DataMemoryBarrier(0xb);
              uVar24 = uVar26;
              if ((*(byte *)(iRam1012f804 + 0x1012eec4) & 1) == 0) {
                uVar34 = func_0x1010a874(iRam1012f808 + 0x1012f500,uVar26);
                iVar17 = iRam1012f80c;
                uVar24 = (uint)((ulonglong)uVar34 >> 0x20);
                if ((int)uVar34 != 0) {
                  puVar25 = (undefined4 *)(iRam1012f80c + 0x1012f51c);
                  *puVar25 = 0xd0ee3a50;
                  *(undefined4 *)(iVar17 + 0x1012f520) = 0xa6457356;
                  *(undefined4 *)(iVar17 + 0x1012f524) = 0xddce0a3c;
                  *(undefined4 *)(iVar17 + 0x1012f528) = 0xf159635a;
                  *(undefined4 *)(iVar17 + 0x1012f52c) = 0xb5f12575;
                  *(undefined *)(iVar17 + 0x1012f530) = 1;
                  func_0x1010a7c0(iRam1012f810 + 0x1012f560,puVar25,iRam1012f814 + 0x1012f564);
                  func_0x1010a880(iRam1012f818 + 0x1012f570);
                  uVar24 = extraout_r1;
                }
              }
              iVar17 = iRam1012f81c;
              pauVar27 = (undefined (*) [16])(iRam1012f81c + 0x1012eedc);
              if (*(char *)(iRam1012f81c + 0x1012eef0) != '\0') {
                auVar33._8_8_ = uRam1012f2c8;
                auVar33._0_8_ = uRam1012f2c0;
                pbVar22 = (byte *)(iRam1012f81c + 0x1012eeef);
                auVar33 = *pauVar27 ^ auVar33;
                pbVar19 = (byte *)(iRam1012f81c + 0x1012eeed);
                bVar2 = *(byte *)(iRam1012f81c + 0x1012eeee);
                bVar3 = *pbVar22;
                *(byte *)(iRam1012f81c + 0x1012eeec) = *(byte *)(iRam1012f81c + 0x1012eeec) ^ 0x11;
                *(byte *)(iVar17 + 0x1012eeed) = *pbVar19 ^ 0x49;
                *(byte *)(iVar17 + 0x1012eeee) = bVar2 ^ 0x9d;
                uVar24 = bVar3 ^ 0xb5;
                *pbVar22 = (byte)uVar24;
                *(longlong *)*pauVar27 = auVar33._0_8_;
                *(longlong *)(iVar17 + 0x1012eee4) = auVar33._8_8_;
                *(undefined *)(iVar17 + 0x1012eef0) = 0;
              }
              DataMemoryBarrier(0xb);
              if (((*(byte *)(iRam1012f820 + 0x1012ef44) & 1) == 0) &&
                 (iVar18 = func_0x1010a874(iRam1012f824 + 0x1012f590,uVar24), iVar17 = iRam1012f828,
                 iVar18 != 0)) {
                puVar25 = (undefined4 *)(iRam1012f828 + 0x1012f5ac);
                *(undefined4 *)(iRam1012f828 + 0x1012f5b4) = 0xccfc2541;
                *(undefined4 *)(iVar17 + 0x1012f5b0) = 0xba44707c;
                *puVar25 = 0x9bca0652;
                *(undefined2 *)(iVar17 + 0x1012f5b8) = 0x13b;
                func_0x1010a7c0(iRam1012f82c + 0x1012f5dc,puVar25,iRam1012f830 + 0x1012f5e0);
                func_0x1010a880(iRam1012f834 + 0x1012f5ec);
              }
              if (*(char *)(iRam1012f838 + 0x1012ef69) != '\0') {
                bVar2 = *(byte *)(iRam1012f83c + 0x1012ef79);
                bVar3 = *(byte *)(iRam1012f840 + 0x1012ef86);
                bVar4 = *(byte *)(iRam1012f844 + 0x1012ef93);
                bVar5 = *(byte *)(iRam1012f848 + 0x1012efa1);
                bVar6 = *(byte *)(iRam1012f84c + 0x1012efb0);
                bVar7 = *(byte *)(iRam1012f850 + 0x1012efbe);
                *(byte *)(iRam1012f854 + 0x1012efc8) = *(byte *)(iRam1012f838 + 0x1012ef5c) ^ 0x11;
                bVar8 = *(byte *)(iRam1012f858 + 0x1012efdf);
                *(byte *)(iRam1012f85c + 0x1012efe9) = bVar2 ^ 0x49;
                bVar2 = *(byte *)(iRam1012f860 + 0x1012f000);
                *(byte *)(iRam1012f864 + 0x1012f006) = bVar3 ^ 0x9d;
                bVar3 = *(byte *)(iRam1012f868 + 0x1012f01d);
                *(byte *)(iRam1012f86c + 0x1012f023) = bVar4 ^ 0xb5;
                *(byte *)(iRam1012f870 + 0x1012f034) = bVar6 ^ 0x3b;
                *(byte *)(iRam1012f874 + 0x1012f049) = bVar5 ^ 0x11;
                *(byte *)(iRam1012f878 + 0x1012f05e) = bVar7 ^ 0x29;
                iVar17 = iRam1012f87c;
                *(byte *)(iRam1012f87c + 0x1012f073) = bVar8 ^ 0xdf;
                *(byte *)(iVar17 + 0x1012f074) = bVar2 ^ 0x11;
                *(byte *)(iVar17 + 0x1012f075) = bVar3 ^ 0x49;
                *(byte *)(iVar17 + 0x1012f076) = *(byte *)(iVar17 + 0x1012f076) ^ 0x9d;
                *(byte *)(iVar17 + 0x1012f077) = *(byte *)(iVar17 + 0x1012f077) ^ 0xb5;
                *(undefined *)(iVar17 + 0x1012f079) = 0;
                *(byte *)(iVar17 + 0x1012f078) = *(byte *)(iVar17 + 0x1012f078) ^ 0x3b;
              }
              DataMemoryBarrier(0xb);
              if (((*(byte *)(iRam1012f880 + 0x1012f0b0) & 1) == 0) &&
                 (iVar18 = func_0x1010a874(iRam1012f884 + 0x1012f600), iVar17 = iRam1012f888,
                 iVar18 != 0)) {
                puVar25 = (undefined4 *)(iRam1012f888 + 0x1012f61c);
                *puVar25 = 0xccfc2541;
                *(undefined4 *)(iVar17 + 0x1012f620) = 0x129635e;
                func_0x1010a7c0(iRam1012f88c + 0x1012f638,puVar25,iRam1012f890 + 0x1012f63c);
                func_0x1010a880(iRam1012f894 + 0x1012f648);
              }
              if (*(char *)(iRam1012f898 + 0x1012f0cf) != '\0') {
                bVar2 = *(byte *)(iRam1012f898 + 0x1012f0c8);
                bVar3 = *(byte *)(iRam1012f898 + 0x1012f0c9);
                bVar4 = *(byte *)(iRam1012f89c + 0x1012f0ea);
                bVar5 = *(byte *)(iRam1012f8a0 + 0x1012f0f7);
                bVar6 = *(byte *)(iRam1012f8a4 + 0x1012f105);
                *(undefined *)(iRam1012f8a8 + 0x1012f117) = 0;
                bVar7 = *(byte *)(iRam1012f8ac + 0x1012f120);
                bVar8 = *(byte *)(iRam1012f8b0 + 0x1012f12e);
                *(byte *)(iRam1012f8b4 + 0x1012f138) = bVar2 ^ 0x11;
                *(byte *)(iRam1012f8b8 + 0x1012f149) = bVar3 ^ 0x49;
                iVar17 = iRam1012f8bc;
                *(byte *)(iRam1012f8bc + 0x1012f15a) = bVar4 ^ 0x9d;
                *(byte *)(iVar17 + 0x1012f15b) = bVar5 ^ 0xb5;
                *(byte *)(iVar17 + 0x1012f15c) = bVar7 ^ 0x3b;
                *(byte *)(iVar17 + 0x1012f15d) = bVar6 ^ 0x11;
                *(byte *)(iVar17 + 0x1012f15e) = bVar8 ^ 0x29;
              }
              DataMemoryBarrier(0xb);
              if (((*(byte *)(iRam1012f8c0 + 0x1012f18c) & 1) == 0) &&
                 (iVar18 = func_0x1010a874(iRam1012f8c4 + 0x1012f658), iVar17 = iRam1012f8c8,
                 iVar18 != 0)) {
                puVar25 = (undefined4 *)(iRam1012f8c8 + 0x1012f674);
                *(undefined4 *)(iRam1012f8c8 + 0x1012f680) = 0xba447075;
                *(undefined4 *)(iVar17 + 0x1012f67c) = 0xdefe205f;
                *(undefined4 *)(iVar17 + 0x1012f678) = 0xb3487f52;
                *puVar25 = 0xd2f43b5e;
                *(undefined2 *)(iVar17 + 0x1012f684) = 0x111;
                func_0x1010a7c0(iRam1012f8cc + 0x1012f6b0,puVar25,iRam1012f8d0 + 0x1012f6b4);
                func_0x1010a880(iRam1012f8d4 + 0x1012f6c0);
              }
              func_0x10198f40(iRam1012f8d8 + 0x1012f1a4);
              iVar17 = func_0x101a4900(iRam1012f8dc + 0x1012f1b8,iRam1012f8e0 + 0x1012f1c0,
                                       iRam1012f8e4 + 0x1012f1c4,iRam1012f8e8 + 0x1012f1c8);
              iVar17 = *(int *)(iVar17 + uVar26);
              if ((iVar17 != 0) && (iVar18 = func_0x101278d0(iVar17), iVar18 != 0)) {
                uVar21 = func_0x101278d0(iVar17);
                func_0x1010a8a4(iRam1012f8ec + 0x1012f208,uVar21,0x7f);
              }
              *(undefined *)(iRam1012f8f0 + 0x1012f214) = 0;
            }
            break;
          case 0x20c:
            *(char *)(iRam1012f7c4 + 0x1012f291) = uStack_29d8._4_1_;
            break;
          default:
            if ((int)uStack_29d8 == 0x95) {
              *(char *)(iRam1012f7a0 + 0x1012ec8c) = uStack_29d8._4_1_;
              break;
            }
            goto LAB_1012e854;
          }
          goto LAB_1012eafc;
        case 0x1b6c:
          *(char *)(iRam1012f780 + 0x1012e93d) = uStack_29d8._4_1_;
          if (uStack_29d8._4_1_ == '\0') {
            *(undefined2 *)(iVar9 + 0x1012e909) = 0;
          }
          else {
            *(undefined *)(iVar9 + 0x1012e90a) = 1;
            *(undefined *)(iVar9 + 0x1012e902) = 1;
            *(undefined *)(iVar9 + 0x1012e984) = 1;
          }
          goto LAB_1012eafc;
        case 0x1bbc:
          *(char *)(iRam1012f794 + 0x1012eae4) = uStack_29d8._4_1_;
          if (uStack_29d8._4_1_ != '\0') {
            iVar17 = *(int *)(iVar10 + 0x1012eae8);
            if (iVar17 == -1 || iVar17 + 1 < 0 != SCARRY4(iVar17,1)) {
              *(undefined4 *)(iVar10 + 0x1012eae8) = 0;
            }
            *(undefined *)(iVar10 + 0x1012eaec) = 1;
          }
LAB_1012eafc:
          auStack_29a8[0] = 1;
          goto LAB_1012e854;
        case 0x1bbd:
          pcVar1 = (char *)(iRam1012f798 + 0x1012e9e0);
          *(char *)(iRam1012f798 + 0x1012e9e1) = uStack_29d8._4_1_;
          if (*pcVar1 != '\0') {
            *(undefined *)(iVar11 + 0x1012e9e8) = 1;
          }
          break;
        default:
          if ((int)uStack_29d8 == 0xea06) {
            *(char *)(iRam1012f784 + 0x1012eb03) = uStack_29d8._4_1_;
          }
          else {
            if ((int)uStack_29d8 != 0xea08) goto LAB_1012e8b0;
            *(char *)(iRam1012f754 + 0x1012e94c) = uStack_29d8._4_1_;
          }
        }
        break;
      case 3:
        *(char *)(iRam1012eaf0 + 0x1012db34) = uStack_29d8._4_1_;
        break;
      case 0xd:
        *(char *)(iRam1012f250 + 0x1012e297) = uStack_29d8._4_1_;
        break;
      case 0x13:
        *(char *)(iRam1012f240 + 0x1012e29c) = uStack_29d8._4_1_;
        break;
      case 0x15:
        *(char *)(iRam1012f260 + 0x1012e2c5) = uStack_29d8._4_1_;
        break;
      case 0x21:
        *(char *)(iRam1012f2a4 + 0x1012e391) = uStack_29d8._4_1_;
        break;
      case 0x38:
        *(char *)(iRam1012f2ac + 0x1012e332) = uStack_29d8._4_1_;
        break;
      case 99:
        *(undefined4 *)(iRam1012f294 + 0x1012e2a8) = uStack_29d0._4_4_;
        auStack_29a8[0] = 1;
        *(undefined4 *)(iRam1012f298 + 0x1012e2b8) = (undefined4)uStack_29c8;
        func_0x10124630(auStack_29a8);
        iVar29 = iRam1012f29c + 0x1012e2d0;
        goto LAB_1012e854;
      case 100:
        *(char *)(iRam1012f2a8 + 0x1012e322) = uStack_29d8._4_1_;
        break;
      case 0x66:
        *(char *)(iRam1012f2a0 + 0x1012e37e) = uStack_29d8._4_1_;
        break;
      case 0x68:
        *(float *)(iRam1012f354 + 0x1012e37c) = (float)(longlong)(int)uStack_29d0;
        break;
      case 0x6c:
        *(char *)(iRam1012f2d0 + 0x1012e360) = uStack_29d8._4_1_;
        break;
      case 0x6d:
        *(char *)(iRam1012f2b0 + 0x1012e358) = uStack_29d8._4_1_;
        break;
      case 0x6f:
LAB_1012dd78:
        *(char *)(iRam1012ed68 + 0x1012dd8e) = uStack_29d8._4_1_;
      }
LAB_1012e84c:
      auStack_29a8[0] = 1;
LAB_1012e854:
      func_0x101aa8fc(iVar29,auStack_29a8,0x2960);
      iVar17 = func_0x101aaa18(iVar29,&uStack_29d8);
    }
    iVar17 = iRam1012e448 + 0x1012d464;
  } while( true );
}

