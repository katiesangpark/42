.intel_syntax noprefix
.globl _ft_strstr
_ft_strstr:
cmpchars:
	mov 	cl, BYTE ptr[rdi]
	mov 	bl, BYTE ptr[rsi]
	test	cl, -1
	jz		retzero
	cmp 	cl, bl
	je		lstart
	inc		rdi
	jmp		cmpchars
lstart:
	mov		rax, 1
lmain:
	mov 	cl, BYTE ptr[rdi + rax]
	mov 	bl, BYTE ptr[rsi + rax]
	test	bl, -1
	jz		found
	cmp 	cl, bl
	jne		cmpchars
	inc		rax
	jmp		lmain
found:
	mov		rax, rdi
	jmp		ret
retzero:
	xor		rax, rax
ret:
	ret