

int main(void)
{
	asm(".intel_syntax\
		push rbp;\
        mov  rbp, rsp;\
		cmp	rdi, 2;\
		jne	newline;\
		xor	r10, r10;\
		mov	rdi, QWORD ptr[rbp - 16];\
		mov	rdi, QWORD ptr[rsi + 8];\
		\
		leadremoval:\
		mov	cl,BYTE ptr [rdi];\
		test cl, -1;\
		jz wordend;\
		inc 	rdi;\
		cmp	cl, 32;\
		je	leadremoval;\
		cmp	cl, 9;\
		je	leadremoval;\
		dec rdi;\
		mainloop:\
		mov	cl,BYTE ptr [rdi + r10];\
		inc r10;\
		test cl, -1;\
		jz wordend;\
		cmp	cl, 32;\
		je	wordend;\
		cmp	cl, 9;\
		je	wordend;\
		jmp	mainloop;\
		wordend:\
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
		pop rbp;\
		\
		");
}
