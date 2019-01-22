__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax;\
			cmp edi, 2;\
			jne	NEWLINE;\
			mov rdi, QWORD ptr[rsi + 8];\
			call _ft_putstr;\
		NEWLINE:\
			push '\n';\
			mov rax, 0x2000004;\
			mov rdi, 1;\
			lea rsi, [rsp];\
			mov rdx, 1;\
			SYSCALL;\
			pop rax;\
			xor eax, eax;\
			ret;\
			\
		_majInvert:\
			mov al, dil;\
			cmp al, 'A';\
			jl	FUNCEND;\
			cmp al, 'Z';\
			jg	MAJEND;\
			add al, 32;\
			jmp FUNCEND;\
		MAJEND:\
			cmp al, 'a';\
			jl	FUNCEND;\
			cmp al, 'z';\
			jg	MAJEND;\
			sub al, 32;\
		FUNCEND:\
			ret;\
		_ft_putstr:\
			mov r8, rdi;\
			lea rsi, [r8];\
			xor rdx, rdx;\
		SLEN:\
			movsx rdi, BYTE ptr[r8 + rdx];\
			call _majInvert;\
			mov BYTE ptr[r8 + rdx], al;\
			inc rdx;\
			test rdi, -1;\
			jnz SLEN;\
			dec rdx;\
			mov rdi, 1;\
			mov rax, 0x2000004;\
			SYSCALL;\
			ret;");
}
