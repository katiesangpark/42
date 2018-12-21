.intel_syntax noprefix
.globl _ft_bzero
_ft_bzero:
	cmp rdi, 0
	je end
mainloop:
	dec rsi
	cmp rsi, 0
	jl end
	mov BYTE ptr[rdi + rsi], 0
	jmp mainloop
end:
	ret