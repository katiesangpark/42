.intel_syntax noprefix
.globl 	_sys_close
_sys_close:
	MOV 	RAX, 0x2000006
	SYSCALL
	ret