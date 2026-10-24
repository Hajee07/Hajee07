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

