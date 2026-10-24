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

