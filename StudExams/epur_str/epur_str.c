

__attrbute__ ((naked))
int main(void)
{
	asm(".intel_syntax;\
			push 	rbp;\
			mov		rbp, rsp;\
			cmp 	rdi, 2;\
			jne		newline;\
			mov		r8, QWORD ptr[rsi + 8];\
			pad:	\
			mov		cl, BYTE ptr[r8];\
			inc 	r8;\
			cmp		cl, 32;\
			je		pad;\
			cmp		cl, 9;\
			je		pad;\
			dec		r8;\
			xor 	rax, rax;\
			len:	\
			mov		cl, BYTE ptr[r8 + rax];\
			inc 	rax;\
			test	cl, -1;\
			jnz		len;\
			dec		rax;\
			mov		r9, rax;\
			mainloop:\
			cmp		r9, 0;\
			jle		newline;\
			dec		r9;\
			mov	cl, BYTE ptr[r8 + r9];\
			cmp		cl, 32;\
			je		mainloop;\
			cmp		cl, 9;\
			je		mainloop;\
			writeword:\
			inc 	r9;\
			xor		r10, r10;\
			writewordloop:\
			cmp		r10, r9;\
			jge		newline;\
			movsx	rcx, BYTE ptr[r8 + r10];\
			inc 	r10;\
			cmp		rcx, 32;\
			je		printtwospaces;\
			cmp		rcx, 9;\
			je		printtwospaces;\
			push	rcx;\
			mov 	rax, 0x2000004;\
			mov 	rdi, 1;\
			mov 	rdx, 1;\
			lea 	rsi, [rsp];\
			SYSCALL;\
			pop		rcx;\
			jmp		writewordloop;\
			printtwospaces:\
			push 	32;\
			mov 	rax, 0x2000004;\
			mov		rdi, 1;\
			lea 	rsi, [rsp];\
			mov		rdx, 1;\
			SYSCALL;	\
			pop 	rdi;\
			spaceloop:\
			mov		cl, BYTE ptr[r8 + r10];\
			inc 	r10;\
			cmp		cl, 32;\
			je		spaceloop;\
			cmp		cl, 9;\
			je		spaceloop;\
			dec 	r10;\
			jmp		writewordloop;\
			newline:\
			push 	0x0a;\
			mov 	rax, 0x2000004;\
			mov		rdi, 1;\
			lea 	rsi, [rsp];\
			mov		rdx, 1;\
			SYSCALL;	\
			pop 	rdi;\
			end:	\
			pop 	rbp;\
			xor 	eax, eax;\
			ret;\
		");
}
