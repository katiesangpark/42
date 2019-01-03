
__attribute__ ((naked))
void _s(void)
{
	asm(".intel_syntax; mov al, dil; ror al, 4; ret;");
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((unsigned char(*)(unsigned char))&_s)(octet);
}
