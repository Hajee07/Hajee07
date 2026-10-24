/* Fresh inferred Ghidra pseudocode from original APK DT_INIT recovery.
 * NOT original source; no Android/game runtime validation.
 */


void core_thread_3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  double dVar10;
  undefined auStack_12c [11];
  undefined auStack_121 [245];
  int iStack_2c;
  
  piVar6 = *(int **)(iRam10189e08 + 0x1018954c);
  iStack_2c = *piVar6;
  iVar2 = func_0x1018933c();
  if (iVar2 != 0) {
    func_0x1010a94c(4,iRam10189e30 + 0x10189570,iRam10189e34 + 0x10189574);
    iVar2 = *piVar6 - iStack_2c;
    if (iVar2 == 0) {
      return;
    }
    func_0x1010a7cc(iVar2);
  }
  iVar1 = iRam10189e14;
  iVar2 = iRam10189e0c;
  puVar8 = (undefined4 *)(iRam10189e0c + 0x101895b8);
  iVar7 = iRam10189e10 + 0x101895c0;
  iVar9 = iRam10189e18 + 0x101895c8;
  do {
    do {
      iVar3 = func_0x10189f4c(puVar8);
    } while (iVar3 == 0);
    uVar4 = func_0x1010a9c4(iRam10189e1c + 0x101895ec,0x1c);
    if (*(char *)(iVar2 + 0x101895d4) != '\0') {
      uVar5 = *(undefined4 *)(iVar2 + 0x101895bc);
      iVar3 = iRam10189e20 + 0x1018960c;
      while (iVar3 = func_0x1010a9d0(uVar5,iVar3,uVar4), 0 < iVar3) {
        if (*(char *)(iVar2 + 0x101895d4) == '\0') goto LAB_10189da8;
        iVar3 = func_0x1010a9dc(*(undefined4 *)(iVar2 + 0x101895bc),auStack_12c,0xff);
        if (iVar3 < 1) {
          iVar3 = iRam10189e38 + 0x10189e08;
          goto LAB_10189da0;
        }
        auStack_12c[iVar3] = 0;
        func_0x1010a94c(4,iVar7,iRam10189e3c + 0x10189654,auStack_12c);
        iVar3 = func_0x1010a940(auStack_12c,iRam10189e40 + 0x10189668,0xe);
        if (iVar3 == 0) {
          *(undefined *)(iVar1 + 0x101895e8) = 1;
          iVar3 = iRam10189e44 + 0x10189a24;
LAB_10189d64:
          func_0x1010a94c(4,iVar7,iVar3);
        }
        else {
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e48 + 0x10189684,0xf);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895e8) = 0;
            iVar3 = iRam10189e4c + 0x10189a3c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e50 + 0x101896a0,0xe);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018960f) = 1;
            iVar3 = iRam10189e54 + 0x10189a54;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e58 + 0x101896bc,0xf);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018960f) = 0;
            iVar3 = iRam10189e5c + 0x10189a6c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e60 + 0x101896d8,0xe);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189613) = 1;
            iVar3 = iRam10189e64 + 0x10189a84;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e68 + 0x101896f4,0xf);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189613) = 0;
            iVar3 = iRam10189e6c + 0x10189a9c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e70 + 0x10189710,0xb);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895c6) = 1;
            iVar3 = iRam10189e74 + 0x10189ab4;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e78 + 0x1018972c,0xc);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895c6) = 0;
            iVar3 = iRam10189e7c + 0x10189acc;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e80 + 0x10189748,0xf);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189624) = 1;
            iVar3 = iRam10189e84 + 0x10189ae4;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e88 + 0x10189764,0x10);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189624) = 0;
            iVar3 = iRam10189e8c + 0x10189afc;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e90 + 0x10189780,0x10);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189612) = 1;
            iVar3 = iRam10189e94 + 0x10189b14;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189e98 + 0x1018979c,0x11);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189612) = 0;
            iVar3 = iRam10189e9c + 0x10189b2c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ea0 + 0x101897b8,0xb);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018961e) = 1;
            iVar3 = iRam10189ea4 + 0x10189b44;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ea8 + 0x101897d4,0xc);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018961e) = 0;
            iVar3 = iRam10189eac + 0x10189b5c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189eb0 + 0x101897f0,0xf);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189611) = 1;
            iVar3 = iRam10189eb4 + 0x10189b74;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189eb8 + 0x1018980c,0x10);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189611) = 0;
            iVar3 = iRam10189ebc + 0x10189b8c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ec0 + 0x10189828,0xf);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189620) = 1;
            iVar3 = iRam10189ec4 + 0x10189ba4;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ec8 + 0x10189844,0x10);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189620) = 0;
            iVar3 = iRam10189ecc + 0x10189bbc;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ed0 + 0x10189860,0x13);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018961c) = 1;
            *(undefined *)(iVar1 + 0x101895d6) = 1;
            iVar3 = iRam10189ed4 + 0x10189be0;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ed8 + 0x1018987c,0x14);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018961c) = 0;
            *(undefined *)(iVar1 + 0x101895d6) = 0;
            iVar3 = iRam10189edc + 0x10189bfc;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ee0 + 0x10189898,0x17);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018961c) = 1;
            *(undefined *)(iVar1 + 0x1018961a) = 1;
            *(undefined *)(iVar1 + 0x1018961f) = 1;
            iVar3 = iRam10189ee4 + 0x10189c24;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ee8 + 0x101898b4,0x18);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x1018961c) = 0;
            *(undefined *)(iVar1 + 0x1018961a) = 0;
            *(undefined *)(iVar1 + 0x1018961f) = 0;
            iVar3 = iRam10189eec + 0x10189c44;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ef0 + 0x101898d0,0xd);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189622) = 1;
            iVar3 = iRam10189ef4 + 0x10189c5c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189ef8 + 0x101898ec,0xe);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189622) = 0;
            iVar3 = iRam10189efc + 0x10189c74;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f00 + 0x10189908,0xb);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895ca) = 1;
            iVar3 = iRam10189f04 + 0x10189c8c;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f08 + 0x10189924,0xc);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895ca) = 0;
            iVar3 = iRam10189f0c + 0x10189ca4;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f10 + 0x10189940,0x10);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895d0) = 1;
            iVar3 = iRam10189f14 + 0x10189cbc;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f18 + 0x1018995c,0x11);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895d0) = 0;
            iVar3 = iRam10189f1c + 0x10189cd4;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f20 + 0x10189978,0x12);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895f4) = 1;
            iVar3 = iRam10189f24 + 0x10189cec;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f28 + 0x10189994,0x13);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x101895f4) = 0;
            iVar3 = iRam10189f2c + 0x10189d04;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f30 + 0x101899b0,0xb);
          if (iVar3 == 0) {
            dVar10 = (double)func_0x1010a9e8(auStack_121,0);
            *(float *)(iVar1 + 0x101895e4) = (float)dVar10;
            iVar3 = iRam10189f34 + 0x10189d38;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f38 + 0x101899cc,0x13);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189623) = 1;
            iVar3 = iRam10189f3c + 0x10189d50;
            goto LAB_10189d64;
          }
          iVar3 = func_0x1010a940(auStack_12c,iRam10189f40 + 0x101899e8,0x14);
          if (iVar3 == 0) {
            *(undefined *)(iVar1 + 0x10189623) = 0;
            iVar3 = iRam10189f44 + 0x10189d68;
            goto LAB_10189d64;
          }
          func_0x1010a94c(4,iVar7,iRam10189f48 + 0x10189a08,auStack_12c);
        }
        uVar4 = func_0x1010a9c4(iVar9,3);
        if (*(char *)(iVar2 + 0x101895d4) == '\0') goto LAB_10189da8;
        uVar5 = *(undefined4 *)(iVar2 + 0x101895bc);
        iVar3 = iVar9;
      }
      iVar3 = iRam10189e24 + 0x10189da4;
LAB_10189da0:
      func_0x1010a94c(4,iVar7,iVar3);
      *(undefined *)(iVar2 + 0x101895d4) = 0;
    }
LAB_10189da8:
    func_0x1010a94c(4,iVar7,iRam10189e28 + 0x10189dbc);
    if (-1 < *(int *)(iVar2 + 0x101895bc)) {
      func_0x1010a97c();
      *(undefined4 *)(iVar2 + 0x101895bc) = 0xffffffff;
    }
    if (-1 < *(int *)(iRam10189e2c + 0x10189de0)) {
      func_0x1010a97c();
      *puVar8 = 0xffffffff;
    }
    *(undefined *)(iVar2 + 0x101895d4) = 0;
  } while( true );
}

