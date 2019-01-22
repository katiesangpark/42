__attribute__ ((naked))
void ft_strcmp(void)
{
	asm(".intel_syntax;\
			movsx eax, BYTE ptr[rdi];\
			movsx ecx, BYTE ptr[rsi];\
			test eax, -1;\
			jz	RETVAL;\
			inc rdi;\
			inc rsi;\
			cmp eax, ecx;\
			je	_ft_strcmp;\
		RETVAL:\
			sub eax, ecx;\
			ret;");
}
