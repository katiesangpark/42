__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax; cmp rdi, 1; je newline; mov rsi, QWORD ptr[rsi + 8]; mainloop: mov cl, BYTE ptr[rsi]; cmp cl, 'a'; je print; test cl, -1; jz newline; inc rsi;  jmp mainloop; print: push 'a'; mov rax, 0x2000004; mov rdi, 1; lea rsi, [rsp]; mov rdx, 1;SYSCALL; pop rax; newline: push 0xa; mov rax, 0x2000004; mov rdi, 1; lea rsi, [rsp]; mov rdx, 1;SYSCALL; pop rax; xor eax, eax; ret;");
}
