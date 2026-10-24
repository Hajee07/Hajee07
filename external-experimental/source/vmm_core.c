/* Layout-specific reconstruction from uploaded BstkVMM.dll SHA256
09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a.
No function here executes code in the emulator or changes its VM metadata.
Only normal, already-mapped RAM is supported; device/COW handlers fail closed.
Page walking is an external x86 architectural implementation, not copied SDK source. */
#include "vmm_core.h"
#include <string.h>
#define PAGE UINT64_C(0x1000)
static int r(vmm_backend*b,uint64_t a,void*p,size_t n){return b->read&&a<UINT64_C(0x800000000000)&&n<UINT64_C(0x800000000000)-a&&b->read(b->opaque,a,p,n);}
static uint64_t q(vmm_backend*b,uint64_t a){uint64_t v=0;return r(b,a,&v,8)?v:0;}
static uint32_t d(vmm_backend*b,uint64_t a){uint32_t v=0;return r(b,a,&v,4)?v:0;}
static unsigned byte(vmm_backend*b,uint64_t a){unsigned char v=0;return r(b,a,&v,1)?v:0;}
static int ptr(uint64_t p){return p>=0x1000&&p<UINT64_C(0x800000000000);}
int vmm_validate_uvm(vmm_backend*b,uint64_t u){
 uint32_t h[2];uint64_t vm;
 if(!ptr(u)||(u&4095)||!r(b,u,h,8)||h[0]!=0x19700823||!h[1]||h[1]>64)return 0;
 vm=q(b,u+8);
 if(!ptr(vm)||(vm&4095)||d(b,vm)>=30||q(b,vm+0x18)!=u||d(b,vm+0x3c)!=h[1])return 0;
 uint64_t cpu=q(b,vm+0x11fe00);unsigned mode;
 if(!ptr(cpu)||!r(b,cpu+0x1101c,&mode,1))return 0;
 /* Zero is a boot/uninitialized mode, allowed for discovery but not translation. */
 mode=byte(b,cpu+0x1101c);if(mode>5)return 0;
 b->vm=vm;b->cpus=h[1];return 1;
}
uint64_t vmm_cpu(vmm_backend*b,unsigned id){return id<b->cpus?q(b,b->vm+0x11fe00+(uint64_t)id*8):0;}
static uint64_t range_for(vmm_backend*b,uint64_t phys){
 uint64_t n=q(b,b->vm+0x106050+((phys>>20)&7)*8),base,size;
 if(n){base=q(b,n);size=q(b,n+8);if(phys>=base&&phys-base<size)return n;}
 n=q(b,b->vm+0x106098);
 for(unsigned steps=0;n&&steps<128;steps++){
  if(!ptr(n))return 0;base=q(b,n);size=q(b,n+8);
  if(phys>=base&&phys-base<size)return n;
  uint64_t next=q(b,n+(phys<base?0x50:0x58));if(next==n)return 0;n=next;
 }
 return 0;
}
/* SDK chunk-map creation1800DA070 proves AVL key@16; links@0/8. */
static uint64_t chunk_for(vmm_backend*b,uint32_t id){
 uint64_t slot=b->vm+0x106860+(uint64_t)(id&63)*16;
 if(d(b,slot)==id){uint64_t p=q(b,slot+8);if(p&&d(b,p+16)==id)return p;}
 uint64_t p=q(b,b->vm+0x106c60);
 for(unsigned steps=0;p&&steps<128;steps++){
  uint32_t key=d(b,p+16);if(key==id)return p;
  uint64_t next=q(b,p+(id<key?0:8));if(next==p)return 0;p=next;
 }
 return 0;
}
int vmm_phys_host(vmm_backend*b,uint64_t phys,int writing,uint64_t*out){
 uint64_t rr=range_for(b,phys);if(!rr)return 0;
 uint64_t off=phys-q(b,rr),pg=rr+0x70+(off>>12)*16,desc;
 if(!r(b,pg,&desc,8))return 0;unsigned type=(unsigned)(desc>>48)&7;
 unsigned handler=(unsigned)(desc>>51)&7,allocation=(unsigned)desc&3;
 if(allocation==3||handler!=1||type>3)return 0; /* supported normal-RAM kind only */
 if(writing&&(type!=1||allocation>1))return 0;
 uint64_t tlb=b->vm+0x106c80+((phys>>12)&255)*32;
 if(q(b,tlb)==(phys&~UINT64_C(4095))){uint64_t p=q(b,tlb+24);if(ptr(p)){*out=p+(phys&4095);return 1;}}
 if((type&3)==0){if(writing)return 0;*out=b->vm+0x104000+(phys&4095);return 1;}
 if(byte(b,b->vm+0x106019)){
  uint64_t p=q(b,rr+0x30);if(!ptr(p))return 0;*out=p+off;return 1;
 }
 uint32_t id=d(b,pg+8),chunk=id>>9;
 if(chunk){uint64_t m=chunk_for(b,chunk);if(!m)return 0;uint64_t p=q(b,m+0x28);if(!ptr(p))return 0;*out=p+(uint64_t)(id&511)*PAGE+(phys&4095);return 1;}
 if(id)return 0;
 if(type!=4&&((desc&UINT64_C(0x7000000000000))||(desc&UINT64_C(0xfffffffff000))!=q(b,b->vm+0x106000)))return 0;
 if(writing)return 0;*out=b->vm+0x104000+(phys&4095);return 1;
}
int vmm_phys_read(vmm_backend*b,uint64_t phys,void*data,size_t n){
 if(n>0x1000000||phys+n<phys)return 0;
 while(n){uint64_t host;size_t step=4096-(phys&4095);if(step>n)step=n;
  if(!vmm_phys_host(b,phys,0,&host)||!r(b,host,data,step))return 0;
  phys+=step;data=(char*)data+step;n-=step;
 }return 1;
}
int vmm_phys_write(vmm_backend*b,uint64_t phys,const void*data,size_t n){
 if(!b->write||n>0x1000000||phys+n<phys)return 0;
 /* Validate the complete destination before the first write. Recheck each page at use. */
 size_t total=n;uint64_t a=phys;
 while(total){uint64_t host;size_t step=4096-(a&4095);if(step>total)step=total;if(!vmm_phys_host(b,a,1,&host))return 0;a+=step;total-=step;}
 while(n){uint64_t host;size_t step=4096-(phys&4095);if(step>n)step=n;
  if(!vmm_phys_host(b,phys,1,&host)||!b->write(b->opaque,host,data,step))return 0;
  phys+=step;data=(const char*)data+step;n-=step;
 }return 1;
}
static int p64(vmm_backend*b,uint64_t a,uint64_t*out){return vmm_phys_read(b,a,out,8);}
static int p32(vmm_backend*b,uint64_t a,uint32_t*out){return vmm_phys_read(b,a,out,4);}
int vmm_translate(vmm_backend*b,uint64_t cpu,uint64_t va,uint64_t*pa){
 int known=0;for(unsigned i=0;i<b->cpus;i++)if(vmm_cpu(b,i)==cpu)known=1;if(!known)return 0;
 unsigned mode=byte(b,cpu+0x1101c);uint64_t cr3,e;if(!r(b,cpu+0x19170,&cr3,8)||d(b,cpu+0x11018)==2)return 0;
 if(mode==1||mode==2){if(d(b,cpu+0x11018)==2)return 0;*pa=va;return 1;}
 if(mode==3){uint32_t pde,pte;if(va>UINT32_MAX||!p32(b,(cr3&~UINT64_C(4095))+((va>>22)&1023)*4,&pde)||!(pde&1))return 0;
  if(pde&128){if(!(q(b,cpu+0x19178)&16))return 0;*pa=(pde&UINT64_C(0xffc00000))|((uint64_t)(pde&0x1fe000)<<19)|(va&0x3fffff);return 1;}
  if(!p32(b,(pde&0xfffff000)+((va>>12)&1023)*4,&pte)||!(pte&1))return 0;*pa=(pte&0xfffff000)|(va&4095);return 1;
 }
 if(mode==4){
  if(va>UINT32_MAX||!p64(b,(cr3&~UINT64_C(31))+((va>>30)&3)*8,&e)||!(e&1))return 0;
  if(!p64(b,(e&UINT64_C(0xffffffffff000))+((va>>21)&511)*8,&e)||!(e&1))return 0;
  if(e&128){*pa=(e&UINT64_C(0xfffffffe00000))|(va&0x1fffff);return 1;}
  if(!p64(b,(e&UINT64_C(0xffffffffff000))+((va>>12)&511)*8,&e)||!(e&1))return 0;*pa=(e&UINT64_C(0xffffffffff000))|(va&4095);return 1;
 }
 if(mode==5){
  uint64_t sign=va>>47;if(sign!=0&&sign!=UINT64_C(0x1ffff))return 0;
  if(!p64(b,(cr3&UINT64_C(0xffffffffff000))+((va>>39)&511)*8,&e)||!(e&1))return 0;
  if(!p64(b,(e&UINT64_C(0xffffffffff000))+((va>>30)&511)*8,&e)||!(e&1))return 0;
  if(e&128){*pa=(e&UINT64_C(0xfffffc0000000))|(va&0x3fffffff);return 1;}
  if(!p64(b,(e&UINT64_C(0xffffffffff000))+((va>>21)&511)*8,&e)||!(e&1))return 0;
  if(e&128){*pa=(e&UINT64_C(0xfffffffe00000))|(va&0x1fffff);return 1;}
  if(!p64(b,(e&UINT64_C(0xffffffffff000))+((va>>12)&511)*8,&e)||!(e&1))return 0;*pa=(e&UINT64_C(0xffffffffff000))|(va&4095);return 1;
 }
 return 0;
}
