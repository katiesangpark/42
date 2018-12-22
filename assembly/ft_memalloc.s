.intel_syntax noprefix
.globl _ft_memalloc
_ft_memalloc:
	mov		rsi, rdi
	push 	rdi
	call	_malloc
	pop		rdi
	mov		rdi, rax
	call	_ft_bzero
	ret