#include <asm/vmlinux.lds.h>
#include <asm/thread_info.h>
#include <asm/page.h>
#include <asm/cache.h>

#undef INIT_CALLS_LEVEL
#define INIT_CALLS_LEVEL(level)			\
	.section	__DATA,.initcall##level;	\
	.globl  	___initcall##level##_start;	\
	.p2align        3;				\
___initcall##level##_start:

#undef VMLINUX_SYMBOL
#define VMLINUX_SYMBOL(x) _##x

#undef INIT_CALLS
# XXX: dunno why crash INIT_CALLS_LEVEL(early);
#define INIT_CALLS						\
	.section __DATA,.initcall_start; .globl ___initcall_start; \
	.p2align        3; ___initcall_start:		\
	INIT_CALLS_LEVEL(early);				\
	INIT_CALLS_LEVEL(0)					\
	INIT_CALLS_LEVEL(1)					\
	INIT_CALLS_LEVEL(2)					\
	INIT_CALLS_LEVEL(3)					\
	INIT_CALLS_LEVEL(4)					\
	INIT_CALLS_LEVEL(5)					\
	INIT_CALLS_LEVEL(rootfs)				\
	INIT_CALLS_LEVEL(6)					\
	INIT_CALLS_LEVEL(7)					\
	.section __DATA,.initcall_end; .globl ___initcall_end; \
	.p2align        3; ___initcall_end:

#define INIT_PARAMS					\
	.section __DATA,__param0; .globl ___start___param;	\
	.p2align        3; ___start___param = .; ___start___param:\
	.section __DATA,__param; .globl ___param;		\
	.p2align        3; ___param:				\
	.section __DATA,__param1; .globl ___stop___param;	\
	.p2align        3; ___stop___param = .; ___stop___param:

#undef INIT_SETUP
#define INIT_SETUP						\
	.section __DATA,.init.setup0; .globl ___setup_start;	\
	.p2align        3; ___setup_start = .;  ___setup_start:\
	.section __DATA,.init.setup; .globl ___init_setup;	\
	.p2align        3; ___init_setup:			\
	.section __DATA,.init.setup1; .globl ___setup_end;	\
	.p2align        3; ___setup_end = .; ___setup_end:

#define INIT_MODVER						\
	.section __DATA,___modver0; .globl ___start___modver;	\
	.p2align        3; ___start___modver = .;  ___start___modver:\
	.section __DATA,___modver; .globl ___modver;	\
	.p2align        3; ___modver:			\
	.section __DATA,___modver1; .globl ___stop___modver;	\
	.p2align        3; ___stop___modver = .; ___stop___modver:

# definitions
	.section __DATA,.jiffies; .globl _jiffies;
	.p2align        3; _jiffies = .; _jiffies:

VMLINUX_SYMBOL(_stext) = . ;
VMLINUX_SYMBOL(_text) = . ;
VMLINUX_SYMBOL(text) = . ;
INIT_SETUP
INIT_CALLS
INIT_PARAMS
INIT_MODVER
