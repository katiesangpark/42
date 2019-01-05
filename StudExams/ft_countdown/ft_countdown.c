__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax;\
			mov rax, 0x2000004;\
			mov rdi, 1;\
			lea rsi, [rip + L._str];\
			mov rdx, 11;\
			SYSCALL;\
			xor eax, eax;\
			ret;\
		L._str:\
			.asciz \"9876543210\n\"");
}
