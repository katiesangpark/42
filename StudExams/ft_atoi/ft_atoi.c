void _atoi(void)
{
	asm(".intel_syntax; padloop: xor rax, rax; mov cl, BYTE ptr[rdi]; test cl, -1; jz return; cmp cl, 32; jg padloopend; inc rdi; jmp padloop; padloopend:xor r9, r9; mov cl, BYTE ptr[rdi]; cmp cl, '+'; je plus; cmp cl, '-'; je minus; jmp mainloop; minus: mov r9, 1; plus: inc rdi; mainloop: movsx rcx, BYTE ptr[rdi]; cmp rcx, '0'; jl end; cmp rcx, '9'; jg end; sub rcx, '0'; imul rax, 10; add rax, rcx; inc rdi; jmp mainloop; end: test r9, -1; jz return; neg rax; return:");
}

int ft_atoi(char *str)
{
	return (((int(*)(char*))&_atoi)(str));
}
