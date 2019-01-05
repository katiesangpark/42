char *ft_strcpy(char *dest, char *src)
{
	(void)src;
	asm(".intel_syntax; xor rax, rax; mainloop: mov cl, BYTE ptr[rsi + rax]; mov BYTE ptr[rdi + rax], cl; inc rax; test cl, -1; jnz mainloop;");
	return (dest);
}
