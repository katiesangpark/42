.intel_syntax noprefix
.globl _ft_bzero
_ft_bzero:
	test 	rsi, rsi
	jz 		end
	dec 	rsi
	mov 	BYTE ptr[rdi + rsi], 0
	jmp 	_ft_bzero
end:
	mov	rdi, rax
	ret