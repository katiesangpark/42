
__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax; jmp mainfunc; _get_count: call _is_alpha; test rax, -1; jz count_end; add rax, rdi; cmp rdi, 'Z'; jle caps; sub rax, 'a'; jmp count_end; caps: sub rax, 'A'; count_end: ret; _is_alpha: xor rax, rax; cmp rdi, 'A'; jl alphafuncend; cmp rdi, 'z'; jg alphafuncend; cmp rdi, 'a'; jge good; cmp rdi, 'Z'; jle good; good: mov rax, 1; alphafuncend: ret; _ft_putchar: mov rax, 0x2000004; push rdi; mov rdi, 1; lea rsi, [rsp]; mov rdx, 1; SYSCALL; pop rdi; ret; mainfunc: cmp rdi, 2; jne newline; mov r8, QWORD ptr[rsi + 8]; mainloop: movsx rdi, BYTE ptr[r8]; test rdi, -1; jz newline; inc r8; call _get_count; mov r9, rax; printloop: call _ft_putchar; dec r9; cmp r9, 0; jle mainloop;  jmp printloop; newline: mov rdi, '\n'; call _ft_putchar; xor rax, rax; ret;");
}
