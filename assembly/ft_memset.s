.intel_syntax noprefix
.globl _ft_memset
_ft_memset:
	cmp rdi, 0
	jz end
mainloop:
	cmp rdx, 0
	jz end
	dec rdx
	mov BYTE ptr[rdi + rdx], sil
	jmp mainloop
end:
	ret