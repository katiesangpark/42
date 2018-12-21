.intel_syntax noprefix
.globl _ft_memset
_ft_memset:
	cmp rdi, 0
	je end
mainloop:
	dec rdx
	cmp rdx, 0
	jl end
	mov BYTE ptr[rdi + rdx], sil
	jmp mainloop
end:
	ret