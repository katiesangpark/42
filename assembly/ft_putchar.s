.intel_syntax noprefix
.globl _ft_putchar
_ft_putchar:
	MOV 	RAX, 0x2000004
	PUSH	RDI
	LEA 	RSI, [RSP]
	MOV 	RDI, 1
	MOV 	RDX, 1
	SYSCALL
	POP		RDI
	ret