.intel_syntax noprefix
.globl _ft_atoi
_ft_atoi:
	cmp		BYTE ptr[rdi], 32
	jne		start
	inc		rdi
	jmp		_ft_atoi
start:
	xor 	rax, rax
	xor		sil, sil
	cmp		BYTE ptr[rdi], 45
	sete	sil
	jne 	mainloop
	inc		rdi
mainloop:
	movsx 	rcx, BYTE ptr[rdi]
	cmp 	cl, 48
	jl		end
	cmp		cl, 57
	jg		end
	imul	rax, 10
	sub		cl, 48
	add 	rax, rcx
	inc 	rdi
	jmp 	mainloop
end:
	test	sil, -1
	jz		r
	neg 	rax
r:
	ret
