.intel_syntax noprefix
.globl _ft_memcpy
_ft_memcpy:
	cmp rdi, 0
	jz end
	cmp rsi, 0
	jz end
mainloop:
	cmp rdx, 0
	jz end
	dec rdx
	mov cl, BYTE ptr[rsi + rdx]
	mov BYTE ptr[rdi + rdx], cl
	jmp mainloop	
end:
	ret