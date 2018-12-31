
__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax; jmp mainfunc; _ft_putchar: mov rax, 0x2000004; push rdi; mov rdi, 1; lea rsi, [rsp]; mov rdx, 1; SYSCALL; pop rdi; ret; mainfunc: mov rdi, 'z'; call _ft_putchar; mov rdi, '\n'; call _ft_putchar; xor rax, rax; ret;");
}
