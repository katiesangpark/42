
__attribute__ ((naked))
int main()
{
	asm(".intel_syntax;\
		push 32;\
		mov rax, 0x2000004;\
		mov rdi, 1;\
		lea rsi, [rip + L_.str];\
		mov rdx, 27;\
		SYSCALL;\
		pop rdi;\
		xor rax, rax;\
		ret;\
		L_.str:\
			.asciz \"zYxWvUtSrQpOnMlKjIhGfEdCbA\n\"");
}
