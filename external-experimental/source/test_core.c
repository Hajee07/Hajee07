#include "vmm_core.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
static unsigned char memory[0x1000000];
static int rd(void*x,uint64_t a,void*p,size_t n){(void)x;if(a>sizeof memory||n>sizeof memory-a)return 0;memcpy(p,memory+a,n);return 1;}
static int wr(void*x,uint64_t a,const void*p,size_t n){(void)x;if(a>sizeof memory||n>sizeof memory-a)return 0;memcpy(memory+a,p,n);return 1;}
static void q(uint64_t a,uint64_t v){memcpy(memory+a,&v,8);}static void d(uint64_t a,uint32_t v){memcpy(memory+a,&v,4);}
static vmm_backend fixture(void){
 memset(memory,0,sizeof memory);vmm_backend b={0,rd,wr,0x100000,2};uint64_t vm=b.vm,rr=0x500000;
 d(0x400000,0x19700823);d(0x400004,2);q(0x400008,vm);q(vm+0x18,0x400000);d(vm,5);d(vm+0x3c,2);
 q(vm+0x11fe00,0x300000);q(vm+0x11fe08,0x340000);memory[0x300000+0x1101c]=5;memory[0x340000+0x1101c]=5;
 q(rr,0);q(rr+8,0x400000);q(rr+0x30,0x800000);memory[vm+0x106019]=1;q(vm+0x106098,rr);
 for(unsigned i=0;i<8;i++)q(vm+0x106050+i*8,rr);
 for(unsigned i=0;i<1024;i++){q(rr+0x70+i*16,UINT64_C(1)<<48|UINT64_C(1)<<51);d(rr+0x78+i*16,1);}
 return b;
}
int main(void){
 unsigned checks=0;vmm_backend b=fixture();uint64_t out;char bytes[16];
 assert(vmm_validate_uvm(&b,0x400000)&&vmm_cpu(&b,0)==0x300000&&vmm_cpu(&b,2)==0);checks++;
 d(0x400000,0);assert(!vmm_validate_uvm(&b,0x400000));checks++;b=fixture();q(b.vm+0x18,0);assert(!vmm_validate_uvm(&b,0x400000));checks++;
 b=fixture();memcpy(memory+0x801234,"test",4);assert(vmm_phys_read(&b,0x1234,bytes,4)&&!memcmp(bytes,"test",4));checks++;
 assert(vmm_phys_write(&b,0x1ffe,"abcdefgh",8)&&!memcmp(memory+0x801ffe,"abcdefgh",8));checks++;
 q(0x500000+0x70+3*16,UINT64_C(1)<<51);assert(vmm_phys_read(&b,0x3123,bytes,4)&&!memcmp(bytes,"\0\0\0\0",4));assert(!vmm_phys_write(&b,0x3123,"no",2));checks++;
 assert(!vmm_phys_read(&b,0x500000,bytes,4));checks++;
 b=fixture();q(0x500000+0x70+2*16,UINT64_C(1)<<51);memcpy(memory+0x801ffe,"KEEP",4);assert(!vmm_phys_write(&b,0x1ffe,"change",6)&&!memcmp(memory+0x801ffe,"KEEP",4));checks++;
 b=fixture();memory[b.vm+0x106019]=0;uint64_t slot=b.vm+0x106860+7*16;q(slot,7);q(slot+8,0x600000);d(0x600010,7);q(0x600028,0x800000);d(0x500000+0x78+0x12*16,7*512+0x12);assert(vmm_phys_host(&b,0x12345,0,&out)&&out==0x812345);checks++;
 q(slot,0);q(b.vm+0x106c60,0x600000);assert(vmm_phys_host(&b,0x12345,0,&out)&&out==0x812345);checks++;
 b=fixture();q(0x300000+0x19170,0x1000);q(0x801000,0x2001);q(0x802000,0x3001);q(0x803000+((0x12345000>>21)&511)*8,0x4001);q(0x804000+((0x12345000>>12)&511)*8,0x5001);
 assert(vmm_translate(&b,0x300000,0x12345678,&out)&&out==0x5678);checks++;
 q(0x804000+((0x12345000>>12)&511)*8,0);assert(!vmm_translate(&b,0x300000,0x12345678,&out));checks++;
 assert(!vmm_translate(&b,0x300000,UINT64_C(0x1000000000000),&out));checks++;
 q(0x802000,UINT64_C(0x40000081));assert(vmm_translate(&b,0x300000,0x12345678,&out)&&out==UINT64_C(0x52345678));checks++;
 b=fixture();memory[0x300000+0x1101c]=4;q(0x300000+0x19170,0x1000);q(0x801000,0x2001);q(0x802000+((0x12345000>>21)&511)*8,0x3001);q(0x803000+((0x12345000>>12)&511)*8,0x6001);assert(vmm_translate(&b,0x300000,0x12345678,&out)&&out==0x6678);checks++;
 b=fixture();memory[0x300000+0x1101c]=3;q(0x300000+0x19170,0x1000);d(0x801000+((0x12345000>>22)&1023)*4,0x2001);d(0x802000+((0x12345000>>12)&1023)*4,0x7001);assert(vmm_translate(&b,0x300000,0x12345678,&out)&&out==0x7678);checks++;
 assert(!vmm_translate(&b,0x300000,UINT64_C(0x100000000),&out));checks++;
 d(0x801000+((0x12345000>>22)&1023)*4,0x800081);q(0x300000+0x19178,16);assert(vmm_translate(&b,0x300000,0x12345678,&out)&&out==0xb45678);checks++;
 assert(!vmm_translate(&b,0x350000,0x1234,&out));checks++;
 d(0x300000+0x11018,2);assert(!vmm_translate(&b,0x300000,0x12345678,&out));checks++;
 b=fixture();q(0x500000+0x70,UINT64_C(1)<<48|UINT64_C(7)<<51);assert(!vmm_phys_read(&b,0,bytes,4)&&!vmm_phys_write(&b,0,"no",2));checks++;
 printf("{\"core_fixture_checks_passed\":%u,\"scope\":\"synthetic memory, no Windows/emulator access\"}\n",checks);return 0;
}
