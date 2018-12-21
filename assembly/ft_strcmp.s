.intel_syntax noprefix
.globl  _ft_strcmp
_ft_strcmp:                             ## @ft_strlen
		xor 	al, al
        xor		rcx, rcx
compare:
		mov		bh, BYTE ptr[rdi + rcx]
		mov		cl, BYTE ptr[rsi + rcx]
		mov     al, bh
		sub 	al, cl
		test 	bh, bh
		jz		end
		inc 	rcx
		test 	al, al
		jz		compare
end:
		movsx 	rax, al
        ret
