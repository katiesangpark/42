.intel_syntax noprefix
.globl _ft_putchar
L_.str:                                 ## @.str
	.asciz	"SALUT"
_ft_putchar:
	MOV 	RAX, 0x2000004
	LEA 	RSI, [RDI]
	MOV 	RDI, 1
	MOV 	RDX, 1
	SYSCALL
	ret