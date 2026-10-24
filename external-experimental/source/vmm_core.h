#ifndef NOVA_VMM_CORE_H
#define NOVA_VMM_CORE_H
#include <stdint.h>
#include <stddef.h>
typedef int (*remote_read)(void*,uint64_t,void*,size_t);
typedef int (*remote_write)(void*,uint64_t,const void*,size_t);
typedef struct {void *opaque;remote_read read;remote_write write;uint64_t vm;unsigned cpus;} vmm_backend;
int vmm_validate_uvm(vmm_backend*,uint64_t);
uint64_t vmm_cpu(vmm_backend*,unsigned);
int vmm_phys_host(vmm_backend*,uint64_t,int,uint64_t*);
int vmm_phys_read(vmm_backend*,uint64_t,void*,size_t);
int vmm_phys_write(vmm_backend*,uint64_t,const void*,size_t);
int vmm_translate(vmm_backend*,uint64_t,uint64_t,uint64_t*);
#endif
