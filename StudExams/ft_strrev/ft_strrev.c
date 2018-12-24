char 	*ft_strrev(char *str)
{
	asm(".intel_syntax;\
			test	rdi, -1;\
			jz		end;\
			xor		rsi, rsi;\
			len:\
			mov		cl, BYTE ptr[rdi + rsi];\
			inc 	rsi;\
			test	cl, -1;\
			jnz 	len;\
			sub		rsi, 2;\
			xor		rcx, rcx;\
			rev:\
			cmp		rcx, rsi;\
			jge		end;\
			mov		r8b,	BYTE ptr[rdi + rcx];\
			mov		r9b,	BYTE ptr[rdi + rsi];\
			mov		BYTE ptr[rdi + rcx], r9b;\
			mov		BYTE ptr[rdi + rsi], r8b;\
			inc 	rcx;\
			dec		rsi;\
			jmp		rev;\
			end:\
		");
	return (str);
}
