
__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax\
			cmp	rdi, 1;\
			je	newline;\
			xor	r10, r10;\
			dec rdi;\
			RDILOOP:\
			dec rdi;\
			add	rsi, 8;\
			test rdi, -1;\
			jnz	RDILOOP;\
			mov	rdi, QWORD ptr[rsi];\
			\
		mainloop:\
			mov	cl,BYTE ptr [rdi + r10];\
			inc r10;\
			test cl, -1;\
			jnz mainloop;\
			dec r10;\
			\
			mov rdx, r10;\
			lea rsi, [rdi];\
			mov rdi, 1;\
			mov rax, 0x2000004;\
			SYSCALL;\
		\
		newline:\
			push 0x0A;\
			mov rax, 0x2000004;\
			mov	rdi, 1;\
			mov	rsi, rsp;\
			mov	rdx, 1;\
			SYSCALL;\
			pop	rax;\
			mov	rax, 0;\
			ret;\
		");
}
