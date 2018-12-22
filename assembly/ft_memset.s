.intel_syntax noprefix
.globl _ft_memset
_ft_memset:
	test 	rdx, rdx
	jz 		end
	dec 	rdx
	mov 	BYTE ptr[rdi + rdx], sil
	jmp 	_ft_memset
end:
	mov	rdi, rax
	ret