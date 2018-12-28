
void	_strlen(void)
{
	asm(".intel_syntax; xor rax, rax; mainloop: mov cl, BYTE ptr[rdi + rax]; inc rax; test cl, -1; jnz mainloop; dec rax;");
}

int		ft_strlen(char *str)
{
	return (((int(*)(char*))&_strlen)(str));
}
