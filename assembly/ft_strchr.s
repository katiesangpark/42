.intel_syntax noprefix
.globl _ft_strchr
_ft_strchr:
	cmp rdi, 0
	jz retzero
	mov rax, rdi
compare:
	mov	cl, BYTE ptr[rax]
	cmp cl, sil
	je end
	cmp cl, 0
	jz retzero
	inc rax
	jmp compare
retzero:
	xor rax, rax
end:
        ret