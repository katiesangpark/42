

__attribute__ ((naked))
void	condition(void)
{
	asm(".intel_syntax;\
			xor 	eax, eax;\
			xor 	r8b, r8b;\
			test	edi, 1;\
			jnz		RETURN;\
		MAINLOOP:\
			test 	edi, -1;\
			jz		END;\
			test 	edi, 1;\
			jz		LOOPITER;\
			inc		r8b;\
		LOOPITER:\
			shr		edi, 1;\
			jmp		MAINLOOP;\
		END:\
			cmp		r8b, 1;\
			jne		RETURN;\
			or		eax, 1;\
		RETURN:\
			ret;");
}

int	    is_power_of_2(unsigned int n)
{
	(void)n;
	return (((int(*)())&condition)());
}
