#include <linux/init.h>
#include <linux/gfp.h>
#include <linux/slab.h>


/* XXX: end should firster than start */
initcall_t __con_initcall_end[1], __con_initcall_start[1];

char __start_rodata[1], __end_rodata[1];
char text[1], _stext[1], _etext[1];
char _data[1], _sdata[1], _edata[1];
char _sinittext[1], _einittext[1];
char _end[1];
char __bss_start[1], __bss_stop[1];
char __init_begin[1], __init_end[1];
uintptr_t __cpuidle_text_end, __cpuidle_text_start;
uintptr_t __sched_text_end, __sched_text_start;
uintptr_t __stop___ex_table, __start___ex_table;
uintptr_t __stop_notes, __start_notes;


uintptr_t kallsyms_num_syms;
uintptr_t kallsyms_relative_base;
uintptr_t kallsyms_markers;
uintptr_t kallsyms_names;
uintptr_t kallsyms_token_index;
uintptr_t kallsyms_token_table;
uintptr_t kallsyms_offsets;
uintptr_t kallsyms_addresses;

/* XXX: if can do weak alias then this can be deleted  */
long probe_kernel_read(void *dst, const void *src, size_t size)
{
	return 0;
}

extern uintptr_t __start___param, __stop___param;

void macho_linker(void)
{
	__start___param = (uintptr_t) &__start___param;
	__stop___param = (uintptr_t) &__stop___param;
}

/* XXX: when initcall3 (arch_initcall) is missing, linker locates
 * the section after initcall4, which makes do_one_initcall() puzzled.
 */
static int dummy(void)
{
	return 0;
}
arch_initcall(dummy);

void *sys_acct;
void *sys_add_key;
void *sys_bpf;
void *sys_delete_module;
void *sys_fadvise64_64;
void *sys_fanotify_init;
void *sys_fanotify_mark;
void *sys_finit_module;
void *sys_flock;
void *sys_get_mempolicy;
void *sys_init_module;
void *sys_inotify_add_watch;
void *sys_inotify_init;
void *sys_inotify_init1;
void *sys_inotify_rm_watch;
void *sys_io_cancel;
void *sys_io_destroy;
void *sys_io_getevents;
void *sys_io_setup;
void *sys_io_submit;
void *sys_kcmp;
void *sys_kexec_load;
void *sys_keyctl;
void *sys_lookup_dcookie;
void *sys_madvise;
void *sys_mbind;
void *sys_memfd_create;
void *sys_migrate_pages;
void *sys_mincore;
void *sys_mlock;
void *sys_mlock2;
void *sys_mlockall;
void *sys_move_pages;
void *sys_mprotect;
void *sys_mq_getsetattr;
void *sys_mq_notify;
void *sys_mq_open;
void *sys_mq_timedreceive;
void *sys_mq_timedsend;
void *sys_mq_unlink;
void *sys_msgctl;
void *sys_msgget;
void *sys_msgrcv;
void *sys_msgsnd;
void *sys_msync;
void *sys_munlock;
void *sys_munlockall;
void *sys_perf_event_open;
void *sys_pkey_alloc;
void *sys_pkey_free;
void *sys_pkey_mprotect;
void *sys_process_vm_readv;
void *sys_process_vm_writev;
void *sys_quotactl;
void *sys_remap_file_pages;
void *sys_request_key;
void *sys_seccomp;
void *sys_semctl;
void *sys_semget;
void *sys_semop;
void *sys_semtimedop;
void *sys_set_mempolicy;
void *sys_shmat;
void *sys_shmctl;
void *sys_shmdt;
void *sys_shmget;
void *sys_signalfd;
void *sys_signalfd4;
void *sys_swapoff;
void *sys_swapon;
void *sys_uselib;
void *sys_userfaultfd;
void *sys_virtio_mmio_device_add;
void *sys_timerfd_create;
void *sys_timerfd_gettime;
void *sys_timerfd_settime;
void *sys_futex;
void *sys_get_robust_list;
void *sys_set_robust_list;
