.intel_syntax noprefix
.globl	_ft_strdup
_ft_strdup:
	call 	_ft_strlen
	inc		rax
	mov		r15, rax
	push	rdi
	mov		rdi, rax
	call	_malloc
	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax
	mov		rdx, r15
	call	_ft_memcpy
	ret