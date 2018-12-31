
__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax; jmp mainstart; _ft_putchar: push rdi; mov rax, 0x2000004; mov rdi, 1; lea rsi, [rsp]; mov rdx, 1; SYSCALL; pop rdi; ret; _ft_putnbr: mov dx, 0; mov ax, di; mov bx, 10; div bx; movsx rdi, dx; test ax, -1; jz printchar; push rdi; movsx rdi, ax; call _ft_putnbr; pop rdi; printchar: add rdi, '0'; call _ft_putchar; ret; mainstart: dec rdi; call _ft_putnbr; mov rdi, '\n'; call _ft_putchar; xor rax, rax; ret;");
}
