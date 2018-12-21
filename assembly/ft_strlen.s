.intel_syntax noprefix
.globl  _ft_strlen
_ft_strlen:                             ## @ft_strlen
        xor     rax, rax
compare:
        mov     cl, BYTE ptr[rdi + rax]
        inc     rax
        test    cl, cl
        jnz     compare
        dec     rax
end:
        ret