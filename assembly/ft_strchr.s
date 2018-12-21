.intel_syntax noprefix
.globl _ft_strchr
_ft_strchr:
	mov 	rax, rdi
compare:
	mov		cl, BYTE ptr[rax]
	cmp 	cl, sil
	je 		end
	test	cl, cl
	jz 		retzero
	inc 	rax
	jmp 	compare
retzero:
	xor rax, rax
end:
        ret