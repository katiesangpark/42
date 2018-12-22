.intel_syntax noprefix
.globl 	_sys_write
_sys_write:
	MOV 	RAX, 0x2000004
	SYSCALL
	ret