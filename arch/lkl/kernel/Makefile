extra-y := vmlinux.lds mach-o-linker.o vmlinux-mach-o.lds vmlinux-mach-o.o

obj-y = setup.o threads.o irq.o time.o syscalls.o misc.o console.o \
	syscalls_32.o cpu.o atomic.o signal.o

$(obj)/vmlinux-mach-o.o: $(src)/vmlinux-mach-o.lds FORCE
	$(Q)$(AS) -c -o $@ $<
