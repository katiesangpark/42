.intel_syntax noprefix
.globl 	_sys_open
_sys_open:
	MOV 	RAX, 0x2000005
	SYSCALL
	ret