
__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax\
			jmp PROGRAMSTART;\
		_is_alpha:\
			xor al, al;\
			cmp dil, 'A';\
			jl	ALPHAEND;\
			cmp	dil, 'z';\
			jg	ALPHAEND;\
			cmp dil, 'Z';\
			jle	ALPHA;\
			cmp	dil, 'a';\
			jge	ALPHA;\
			jmp	ALPHAEND;\
		ALPHA:\
			and al, 1;\
		ALPHAEND:\
			ret;\
		PROGRAMSTART:\
			cmp	rdi, 2;\
			jne	NEWLINE;\
			xor	r10, r10;\
			xor	rdi, rdi;\
			mov	r8, QWORD ptr[rsi + 8];\
		\
		MAINLOOP:\
			mov	cl,BYTE ptr [r8 + r10];\
			test cl, -1;\
			jz PRINTSTR;\
			mov dil, cl;\
			call _is_alpha;\
			jnz	LOOPITER;\
			inc cl;\
			cmp cl, 91;\
			je SUBSTRACT;\
			cmp cl, 123;\
			je SUBSTRACT;\
			jmp	SAVECHAR;\
			SUBSTRACT:\
			sub cl, 26;\
			SAVECHAR:\
			mov BYTE ptr [r8 + r10], cl;\
			LOOPITER:\
			inc r10;\
			jmp MAINLOOP;\
		PRINTSTR:\
			mov rdx, r10;\
			lea rsi, [r8];\
			mov rdi, 1;\
			mov rax, 0x2000004;\
			SYSCALL;\
		\
		NEWLINE:\
			push 0x0A;\
			mov rax, 0x2000004;\
			mov	rdi, 1;\
			mov	rsi, rsp;\
			mov	rdx, 1;\
			SYSCALL;\
			pop	rax;\
			xor	rax, rax;\
			ret;");
}
