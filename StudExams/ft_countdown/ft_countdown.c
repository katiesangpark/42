
int main(void)
{
	(void)(char*){"9876543210\n"};
	asm(".intel_syntax;mov rax, 0x2000004; mov rdi, 1; lea rsi, [rip+L_.str]; mov rdx, 11; SYSCALL;");
	return (0);
}
