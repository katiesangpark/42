__attribute__ ((naked))
void cmp(void)
{
	asm(".intel_syntax; xor r8, r8; mainloop: movsx rcx, BYTE ptr[rdi + r8]; movsx rdx, BYTE ptr[rsi + r8]; mov rax, rcx; sub rax, rdx; inc r8; test rax, -1; jnz end; test rcx, -1; jz end; jmp mainloop; end: ret;");
}

int ft_strcmp(char *s1, char *s2)
{
	return (((int(*)(void))&cmp)());
}

