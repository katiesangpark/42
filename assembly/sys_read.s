.intel_syntax noprefix
.globl 	_sys_read
_sys_read:
	MOV 	RAX, 0x2000003
	SYSCALL
	ret