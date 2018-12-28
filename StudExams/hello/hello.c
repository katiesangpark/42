
int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	(void)(char*){"Hello World!\n"};
	asm(".intel_syntax; mov rax, 0x2000004; mov rdi, 1; lea rsi, [rip + L_.str]; mov rdx, 13; SYSCALL;");
	return (0);
}
