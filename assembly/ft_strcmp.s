.intel_syntax noprefix
.globl  _ft_strcmp
_ft_strcmp:                             ## @ft_strlen
		xor 	al, al
        cmp		rdi, 0
        je 		end	
        cmp		rsi, 0
        je 		end
        xor		rcx, rcx
compare:
		mov		bh, BYTE ptr[rdi + rcx]
		mov		cl, BYTE ptr[rsi + rcx]
		mov     al, bh
		sub 	al, cl
		cmp 	bh, 0
		jz		end
		inc 	rcx
		cmp 	al, 0
		jz		compare
end:
		movsx 	rax, al
        ret
