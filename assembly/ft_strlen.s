.intel_syntax noprefix
.globl  _ft_strlen
_ft_strlen:                             ## @ft_strlen
        xor     rax, rax
        cmp		rdi, 0
        je 		end	
compare:
        mov     cl, BYTE ptr[rdi + rax]
        inc     rax
        cmp     cl, 0
        jne     compare
        dec     rax
end:
        ret