.intel_syntax noprefix
.globl 	_ft_putstr
_ft_putstr:
	call	_ft_strlen
	mov 	RDX, RAX
	MOV 	RAX, 0x2000004
	LEA 	RSI, [RDI]
	MOV 	RDI, 1
	SYSCALL
	ret