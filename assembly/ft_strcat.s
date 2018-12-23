.intel_syntax noprefix
.globl _ft_strcat
_ft_strcat:
	mov		rax, rdi
	xor		r8, r8
checkloop:
	mov		cl, BYTE ptr[rdi + r8]
	inc 	r8
	test	cl, -1
	jnz		checkloop
	xor		r9, r9
	dec		r8
	add		rdi, r8
cpy:
	mov		cl, BYTE ptr[rsi + r9]
	mov		BYTE ptr[rdi + r9], cl
	inc		r9
	test	cl ,cl
	jnz		cpy
end:
	ret