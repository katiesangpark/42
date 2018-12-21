.intel_syntax noprefix
.globl _ft_bzero
_ft_bzero:
	test 	rdx, rdx
	jz 		end
	dec 	rdx
	mov 	BYTE ptr[rdi + rdx], 0
	jmp 	_ft_bzero
end:
	ret