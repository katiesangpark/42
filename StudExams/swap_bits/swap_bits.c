
__attribute__ ((naked))
void	swap(void)
{
	asm(".intel_syntax; mov rax, rdi; shr rax, 4; shl rdi, 4; or rax, rdi; ret;");
}

unsigned char	swap_bits(unsigned char octet)
{
	return (((unsigned char(*)(unsigned char))&swap)(octet));
}
