#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#include <bcrypt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
extern unsigned char _binary_engine_bin_start[],_binary_engine_bin_end[];
extern unsigned char _binary_proxy_bin_start[],_binary_proxy_bin_end[];
static const char expected_sdk[]="09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a";
static int hash_file(const WCHAR*path,char*out){
 BCRYPT_ALG_HANDLE alg=0;BCRYPT_HASH_HANDLE hash=0;DWORD object_size=0,got=0;PUCHAR object=0;HANDLE file=INVALID_HANDLE_VALUE;int ok=0;
 if(BCryptOpenAlgorithmProvider(&alg,BCRYPT_SHA256_ALGORITHM,0,0)<0)goto end;
 if(BCryptGetProperty(alg,BCRYPT_OBJECT_LENGTH,(PUCHAR)&object_size,sizeof object_size,&got,0)<0)goto end;
 object=malloc(object_size);if(!object)goto end;
 if(BCryptCreateHash(alg,&hash,object,object_size,0,0,0)<0)goto end;
 file=CreateFileW(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);if(file==INVALID_HANDLE_VALUE)goto end;
 unsigned char buffer[65536],digest[32];
 for(;;){if(!ReadFile(file,buffer,sizeof buffer,&got,0))goto end;if(!got)break;if(BCryptHashData(hash,buffer,got,0)<0)goto end;}
 if(BCryptFinishHash(hash,digest,sizeof digest,0)<0)goto end;
 for(unsigned i=0;i<32;i++)sprintf(out+i*2,"%02x",digest[i]);out[64]=0;ok=1;
 end:if(file!=INVALID_HANDLE_VALUE)CloseHandle(file);if(hash)BCryptDestroyHash(hash);if(alg)BCryptCloseAlgorithmProvider(alg,0);free(object);return ok;
}
static DWORD choose_pid(DWORD wanted){
 HANDLE s=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);if(s==INVALID_HANDLE_VALUE)return 0;
 PROCESSENTRY32W e={0};e.dwSize=sizeof e;DWORD chosen=0,threads=0;
 if(Process32FirstW(s,&e)){do{if(!_wcsicmp(e.szExeFile,L"HD-Player.exe")&&(!wanted||e.th32ProcessID==wanted)){
   printf("HD-Player candidate PID%lu, threads%lu\n",(unsigned long)e.th32ProcessID,(unsigned long)e.cntThreads);
   if(wanted||e.cntThreads>threads){chosen=e.th32ProcessID;threads=e.cntThreads;}
 }}while(Process32NextW(s,&e));}CloseHandle(s);return chosen;
}
static int find_sdk(DWORD pid,WCHAR*path,WCHAR*directory){
 HANDLE s=INVALID_HANDLE_VALUE;for(unsigned i=0;i<3;i++){s=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE|TH32CS_SNAPMODULE32,pid);if(s!=INVALID_HANDLE_VALUE||GetLastError()!=ERROR_BAD_LENGTH)break;}
 if(s==INVALID_HANDLE_VALUE)return 0;MODULEENTRY32W m={0};m.dwSize=sizeof m;int found=0;
 if(Module32FirstW(s,&m)){do{if(!_wcsicmp(m.szModule,L"BstkVMM.dll")){
  wcsncpy(path,m.szExePath,MAX_PATH-1);wcsncpy(directory,m.szExePath,MAX_PATH-1);WCHAR*slash=wcsrchr(directory,L'\\');if(slash)*slash=0;found=1;break;
 }}while(Module32NextW(s,&m));}CloseHandle(s);return found;
}
static int write_payload(const WCHAR*file,const unsigned char*a,const unsigned char*z){
 HANDLE f=CreateFileW(file,GENERIC_WRITE,0,0,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,0);if(f==INVALID_HANDLE_VALUE)return 0;
 size_t n=(size_t)(z-a);DWORD wrote=0;BOOL ok=n<=0xffffffff&&WriteFile(f,a,(DWORD)n,&wrote,0)&&wrote==n;CloseHandle(f);return ok;
}
static int fail(const char*message){fprintf(stderr,"\nNOVA External: %s\nWindows error:%lu\n",message,(unsigned long)GetLastError());fprintf(stderr,"This experimental build has NOT established working game integration.\n");MessageBoxA(0,message,"NOVA External - experimental startup failed",MB_OK|MB_ICONERROR);return 1;}
int main(int argc,char**argv){
 setvbuf(stdout,0,_IONBF,0);
 puts("NOVA External -- experimental native-engine host");
 puts("This program loads its engine/proxy DLLs into THIS process only.");
 puts("The HD-Player connection uses process query/read/write; no remote DLL/thread is created.");
 puts("Original controls retained; live Windows/game behavior is not verified.\n");
 DWORD requested=0;if(argc>1){char*end=0;unsigned long v=strtoul(argv[1],&end,10);if(!v||*end)return fail("Usage: NOVA-External-Experimental.exe [HD-Player PID]");requested=(DWORD)v;}
 DWORD pid=choose_pid(requested);if(!pid)return fail("No matching HD-Player.exe found. Start the emulator/game first.");
 WCHAR sdk[MAX_PATH]={0},directory[MAX_PATH]={0};if(!find_sdk(pid,sdk,directory))return fail("BstkVMM.dll is not listed in the selected emulator.");
 char digest[65];if(!hash_file(sdk,digest))return fail("Cannot read installed SDK file for version verification.");
 if(strcmp(digest,expected_sdk)){fprintf(stderr,"Installed BstkVMM.dll SHA256:%s\n",digest);return fail("SDK differs from the uploaded/analyzed DLL. No engine was started.");}
 printf("Verified SDK hash; selected PID%lu\n",(unsigned long)pid);
 WCHAR temp[MAX_PATH],folder[MAX_PATH],engine_path[MAX_PATH],proxy_path[MAX_PATH];
 if(!GetTempPathW(MAX_PATH,temp))return fail("Cannot locate a private temporary directory.");
 if(_snwprintf(folder,MAX_PATH,L"%lsNOVA_external_%lu_%llu",temp,(unsigned long)GetCurrentProcessId(),(unsigned long long)GetTickCount64())<0)return fail("Temporary path too long.");
 if(!CreateDirectoryW(folder,0))return fail("Cannot create private engine directory.");
 if(_snwprintf(engine_path,MAX_PATH,L"%ls\\NOVA-engine.dll",folder)<0||_snwprintf(proxy_path,MAX_PATH,L"%ls\\BstkVMM.dll",folder)<0)return fail("Engine path too long.");
 if(!write_payload(proxy_path,_binary_proxy_bin_start,_binary_proxy_bin_end)||!write_payload(engine_path,_binary_engine_bin_start,_binary_engine_bin_end))return fail("Cannot extract the local engine components.");
 /* The existing installation is read-only; payload files are in our private temp folder. */
 SetDllDirectoryW(directory);SetCurrentDirectoryW(directory);
 HMODULE proxy=LoadLibraryExW(proxy_path,0,LOAD_WITH_ALTERED_SEARCH_PATH);if(!proxy)return fail("Cannot load the proxy into the external host.");
 typedef int(__cdecl*init_fn)(DWORD);typedef uint64_t(__cdecl*vm_fn)(void);typedef void(__cdecl*stats_fn)(LONG*);
 init_fn initialize=(init_fn)GetProcAddress(proxy,"NovaInitialize");vm_fn get_vm=(vm_fn)GetProcAddress(proxy,"NovaGetVM");stats_fn stats=(stats_fn)GetProcAddress(proxy,"NovaStats");
 if(!initialize||!get_vm||!stats)return fail("Invalid local proxy exports.");
 puts("Looking for a validated UVM/VM structure using external reads(up to45seconds)...");
 int result=initialize(pid);if(result!=1){fprintf(stderr,"Backend initialization result:%d\n",result);if(result==-7)fprintf(stderr,"VM was found but this paging/RAM state is unsupported or not ready.\n");return fail("External VM discovery/attachment did not complete. Original engine was not started.");}
 printf("VM candidate validated at0x%llx. Starting original engine in host PID%lu.\n",(unsigned long long)get_vm(),(unsigned long)GetCurrentProcessId());
 HMODULE engine=LoadLibraryExW(engine_path,0,LOAD_WITH_ALTERED_SEARCH_PATH);if(!engine)return fail("Original local engine dependencies could not be loaded. Check Windows error above.");
 unsigned char*ready=(unsigned char*)((uintptr_t)engine+0x1b2f2bd);
 for(unsigned i=0;i<300&&!*ready;i++)Sleep(100);
 if(!*ready)return fail("Original engine did not acknowledge the external backend. No successful gameplay is claimed.");
 puts("Native engine acknowledged the proxy. Menu/ESP window belongs to this external process.");
 puts("Feature behavior still requires verification on this Windows/game instance. Close this console to stop the host.");
 for(;;){LONG data[4];stats(data);printf("RAM operations: read OK%ld / failed%ld; write OK%ld / failed%ld\n",data[0],data[1],data[2],data[3]);Sleep(10000);}
}
