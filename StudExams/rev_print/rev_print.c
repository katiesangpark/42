

__attribute__ ((naked))
int main(void)
{
	asm(".intel_syntax;\
			cmp 	edi, 2;\
			jne		NEWLINE;\
			mov 	rsi, QWORD ptr[rsi + 8];\
			xor		rax, rax;\
		LENLOOP:\
			mov		cl, BYTE ptr[rsi + rax];\
			inc 	rax;\
			test	cl, -1;\
			jnz		LENLOOP;\
			dec		rax;\
			mov		r8, rax;\
			dec		rax;\
			xor		rdi, rdi;\
		REVLOOP:\
			mov		cl, BYTE ptr[rsi + rdi];\
			mov		dl, BYTE ptr[rsi + rax];\
			mov		BYTE ptr[rsi + rdi], dl;\
			mov		BYTE ptr[rsi + rax], cl;\
			inc 	rdi;\
			dec		rax;\
			cmp		rdi, rax;\
			jl		REVLOOP;\
			mov		rax, 0x2000004;\
			mov		rdi, 1;\
			lea		rsi, [rsi];\
			mov		rdx, r8;\
			SYSCALL;\
		NEWLINE:\
			push 	0xa;\
			mov		rax, 0x2000004;\
			mov		edi, 1;\
			lea		rsi, [rsp];\
			mov		edx, 1;\
			SYSCALL;\
			pop 	rdi;\
			xor 	eax, eax;\
			ret;");
}
