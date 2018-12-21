.intel_syntax noprefix
.globl  _slen
_slen:                             ## @ft_strlen
        xor     rax, rax
blabla:
        mov     cl, BYTE ptr[rdi + rax]
        inc     rax
        cmp     cl, 0
        jne     blabla
end:
        dec     rax
        ret