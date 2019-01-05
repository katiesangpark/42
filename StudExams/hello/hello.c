__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax;\
			mov rax, 0x2000004;\
			mov rdi, 1;\
			lea rsi, [rip + message];\
			mov rdx, 13;\
			SYSCALL;\
			xor eax, eax;\
			ret;\
			\
			message:\
				.asciz \"Hello world!\n\";");	
}
