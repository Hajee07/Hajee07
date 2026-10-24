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

