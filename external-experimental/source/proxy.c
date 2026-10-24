#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vmm_core.h"
static HANDLE target;static DWORD target_pid;static vmm_backend backend;static volatile LONG active,read_errors,write_errors,reads,writes;
static CRITICAL_SECTION gate;
HANDLE WINAPI NovaGuardOpenProcess(DWORD rights,BOOL inherit,DWORD pid){
 if(pid!=GetCurrentProcessId())rights&=(PROCESS_QUERY_INFORMATION|PROCESS_QUERY_LIMITED_INFORMATION|PROCESS_VM_READ|PROCESS_VM_WRITE|PROCESS_VM_OPERATION|SYNCHRONIZE);
 if(pid!=target_pid&&pid!=GetCurrentProcessId())rights&=~(PROCESS_VM_WRITE|PROCESS_VM_OPERATION|PROCESS_TERMINATE|PROCESS_SUSPEND_RESUME);
 return OpenProcess(rights,inherit,pid);
}
HANDLE WINAPI NovaGuardOpenThread(DWORD rights,BOOL inherit,DWORD id){
 HANDLE h=OpenThread(rights,inherit,id);if(h&&GetProcessIdOfThread(h)!=GetCurrentProcessId()){CloseHandle(h);SetLastError(ERROR_ACCESS_DENIED);return 0;}return h;
}
FARPROC WINAPI NovaGuardGetProc(HMODULE module,LPCSTR name){
 if((uintptr_t)name<=0xffff){SetLastError(ERROR_ACCESS_DENIED);return 0;}
 {
  const char*deny[]={"CreateRemoteThread","CreateRemoteThreadEx","NtCreateThreadEx","RtlCreateUserThread","VirtualAllocEx","NtAllocateVirtualMemory","NtMapViewOfSection","QueueUserAPC","QueueUserAPC2","NtQueueApcThread","SetWindowsHookExA","SetWindowsHookExW",0};
  for(unsigned i=0;deny[i];i++)if(!strcmp(name,deny[i])){SetLastError(ERROR_ACCESS_DENIED);return 0;}
  if(!strcmp(name,"OpenProcess"))return(FARPROC)NovaGuardOpenProcess;
  if(!strcmp(name,"OpenThread"))return(FARPROC)NovaGuardOpenThread;
 }
 return GetProcAddress(module,name);
}

static int rpm(void*x,uint64_t a,void*p,size_t n){SIZE_T got=0;(void)x;return ReadProcessMemory(target,(void*)(uintptr_t)a,p,n,&got)&&got==n;}
static int wpm(void*x,uint64_t a,const void*p,size_t n){SIZE_T got=0;(void)x;return WriteProcessMemory(target,(void*)(uintptr_t)a,p,n,&got)&&got==n;}
static int readable(DWORD p){return !(p&(PAGE_GUARD|PAGE_NOACCESS))&&(p&0xff)!=0;}
static int find_vm(unsigned timeout){
 SYSTEM_INFO si;GetSystemInfo(&si);uint64_t limit=(uint64_t)(uintptr_t)si.lpMaximumApplicationAddress;
 MEMORY_BASIC_INFORMATION mi;ULONGLONG start=GetTickCount64();unsigned char*buf=malloc(0x100000);if(!buf)return 0;
 for(int phase=0;phase<2;phase++){
  for(uint64_t a=0x10000;a<limit;){
   if(!VirtualQueryEx(target,(void*)(uintptr_t)a,&mi,sizeof mi))break;
   uint64_t base=(uint64_t)(uintptr_t)mi.BaseAddress,size=(uint64_t)mi.RegionSize,next=base+size;
   if(next<=a)break;
   if(GetTickCount64()-start>timeout*1000){free(buf);return 0;}
   if(mi.State==MEM_COMMIT&&mi.Type==MEM_PRIVATE&&readable(mi.Protect)&&size>=0x1000){
    if(!phase){uint32_t magic=0;if(rpm(0,base,&magic,4)&&magic==0x19700823&&vmm_validate_uvm(&backend,base)){free(buf);return 1;}}
    else if(size<=0x4000000){
     for(uint64_t at=base;at<next;){size_t n=(size_t)(next-at);if(n>0x100000)n=0x100000;
      if(rpm(0,at,buf,n)){for(size_t off=0;off+16<=n;off+=0x1000){uint32_t magic;memcpy(&magic,buf+off,4);if(magic==0x19700823&&vmm_validate_uvm(&backend,at+off)){free(buf);return 1;}}}
      else{for(size_t off=0;off+16<=n;off+=0x1000){uint32_t magic=0;if(rpm(0,at+off,&magic,4)&&magic==0x19700823&&vmm_validate_uvm(&backend,at+off)){free(buf);return 1;}}}
      at+=n;if(GetTickCount64()-start>timeout*1000){free(buf);return 0;}
     }
    }
   }a=next;
  }
 }free(buf);return 0;
}
__declspec(dllexport) void* __cdecl VMMGetCpuById(void*vm,unsigned id){if((uintptr_t)vm!=backend.vm)return 0;return(void*)(uintptr_t)vmm_cpu(&backend,id);}
__declspec(dllexport) int __cdecl PGMPhysGCPtr2GCPhys(void*cpu,uint64_t address,uint64_t*physical){
 if(!physical)return -2;EnterCriticalSection(&gate);int ok=vmm_translate(&backend,(uint64_t)(uintptr_t)cpu,address,physical);LeaveCriticalSection(&gate);return ok?0:-1665;
}
/* Kept uninlined so the original engine can hook this LOCAL proxy export.
   No function or hook is installed in the emulator. */
__declspec(dllexport) __attribute__((noinline,optnone)) int __cdecl PGMPhysRead(void*vm,uint64_t physical,void*data,size_t size){
 if((uintptr_t)vm!=backend.vm||!data||size>0x1000000)return -2;
 if(size==0)return 0; /* local initialization probe is not a successful guest read */
 EnterCriticalSection(&gate);int ok=vmm_phys_read(&backend,physical,data,size);LeaveCriticalSection(&gate);
 InterlockedIncrement(ok?&reads:&read_errors);return ok?0:-1665;
}
__declspec(dllexport) int __cdecl PGMPhysSimpleWriteGCPhys(void*vm,uint64_t physical,const void*data,size_t size){
 if((uintptr_t)vm!=backend.vm||!data||size>0x1000000)return -2;
 EnterCriticalSection(&gate);uint64_t uvm=0;vmm_backend check=backend;
 int valid=rpm(0,backend.vm+0x18,&uvm,8)&&vmm_validate_uvm(&check,uvm)&&check.vm==backend.vm;
 int ok=valid&&vmm_phys_write(&backend,physical,data,size);LeaveCriticalSection(&gate);
 InterlockedIncrement(ok?&writes:&write_errors);return ok?0:-1665;
}
static DWORD WINAPI capture_thread(void*unused){
 (void)unused;typedef int(__cdecl*reader)(void*,uint64_t,void*,size_t);HMODULE self=GetModuleHandleA("BstkVMM.dll");
 reader volatile fn=(reader)GetProcAddress(self,"PGMPhysRead");unsigned char dummy=0;
 while(InterlockedCompareExchange(&active,1,1)){if(fn)fn((void*)(uintptr_t)backend.vm,0,&dummy,0);Sleep(100);}
 return 0;
}
__declspec(dllexport) int __cdecl NovaInitialize(DWORD pid){
 if(target)return 0;InitializeCriticalSection(&gate);target_pid=pid;
 target=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ|PROCESS_VM_WRITE|PROCESS_VM_OPERATION,FALSE,pid);
 if(!target)return -1000-(int)GetLastError();
 char path[32768];DWORD length=sizeof path;if(!QueryFullProcessImageNameA(target,0,path,&length)){CloseHandle(target);target=0;return -3;}
 char*name=strrchr(path,'\\');name=name?name+1:path;
 if(_stricmp(name,"HD-Player.exe")){CloseHandle(target);target=0;return -4;}
 backend.opaque=0;backend.read=rpm;backend.write=wpm;
 if(!find_vm(45)){CloseHandle(target);target=0;return -5;}
 int usable=0;
 for(unsigned id=0;id<backend.cpus;id++){
  uint64_t cpu=vmm_cpu(&backend,id),cr3=0;unsigned char mode=0;unsigned slat=0;unsigned char bytes[8];
  if(!cpu)continue;rpm(0,cpu+0x1101c,&mode,1);rpm(0,cpu+0x11018,&slat,4);rpm(0,cpu+0x19170,&cr3,8);
  printf("CPU%u: guest mode%u, translation mode%u, CR3=0x%llx\n",id,(unsigned)mode,slat,(unsigned long long)cr3);
  uint64_t root=(mode==4)?(cr3&~UINT64_C(31)):(cr3&~UINT64_C(4095));
  if(mode>=3&&mode<=5&&slat!=2&&cr3&&vmm_phys_read(&backend,root,bytes,sizeof bytes))usable=1;
 }
 if(!usable){CloseHandle(target);target=0;return -7;}
 active=1;HANDLE thread=CreateThread(0,0,capture_thread,0,0,0);if(thread)CloseHandle(thread);else{active=0;return -6;}
 return 1;
}
__declspec(dllexport) uint64_t __cdecl NovaGetVM(void){return backend.vm;}
__declspec(dllexport) void __cdecl NovaStats(LONG*out){if(out){out[0]=reads;out[1]=read_errors;out[2]=writes;out[3]=write_errors;}}
BOOL WINAPI DllMain(HINSTANCE h,DWORD reason,LPVOID reserved){(void)h;(void)reserved;if(reason==DLL_PROCESS_DETACH)active=0;return TRUE;}
