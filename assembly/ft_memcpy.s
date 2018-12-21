.intel_syntax noprefix
.globl _ft_memcpy
_ft_memcpy:
	test 	rdx, rdx
	jz 		end
	dec 	rdx
	mov 	cl, BYTE ptr[rsi + rdx]
	mov 	BYTE ptr[rdi + rdx], cl
	jmp 	_ft_memcpy	
end:
	mov	rdi, rax
	ret