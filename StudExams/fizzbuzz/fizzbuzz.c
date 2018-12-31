
__attribute__ ((naked))
int main()
{
	asm(".intel_syntax;\
		jmp MAINSTART;\
		_divb3:\
		mov		dx, 0;\
		mov		ax, di;\
		mov		bx, 3;\
		div		bx;\
		xor 	ax, ax;\
		test	dx, -1;\
		jnz		DIV3END;\
		mov		ax, 1;\
		DIV3END:\
		ret;\
		_divb5:\
		mov		dx, 0;\
		mov		ax, di;\
		mov		bx, 5;\
		div		bx;\
		xor 	ax, ax;\
		test	dx, -1;\
		jnz		DIV5END;\
		mov		ax, 1;\
		DIV5END:\
		ret;\
		_putnbr:\
		mov		dx, 0;\
		mov		ax, di;\
		mov		bx, 10;\
		div		bx;\
		test	ax, -1;\
		mov		di, dx;\
		jz		PRINTNBRCHAR;\
		push	di;\
		mov		di, ax;\
		call	_putnbr;\
		pop 	di;\
		PRINTNBRCHAR:\
		add		di, '0';\
		call	_ftputchar;\
		ret;\
		_ftputchar:\
		push 	di;\
		mov 	rax, 0x2000004;\
		mov 	di, 1;\
		lea 	rsi, [rsp];\
		mov 	rdx, 1;\
		SYSCALL;\
		pop 	di;\
		ret;\
		_ft_putstr:\
		mov 	rsi, rdi;\
		mov 	rax, 0x2000004;\
		mov 	rdi, 1;\
		mov 	rdx, 4;\
		SYSCALL;\
		ret;\
		MAINSTART:\
		xor		r8w, r8w;\
		mainloop:\
		inc 	r8w;\
		mov		di, r8w;\
		call	_divb3;\
		test 	ax, -1;\
		jz		BUZZ;\
		lea		rdi, [rip + L_.str];\
		call 	_ft_putstr;\
		BUZZ:\
		mov		di, r8w;\
		call	_divb5;\
		test 	ax, -1;\
		jz		PRINTNBR;\
		lea		rdi, [rip + L_.str2];\
		call 	_ft_putstr;\
		jmp		NEWLINE;\
		PRINTNBR:\
		mov		di, r8w;\
		call	_divb3;\
		test 	ax, -1;\
		jnz		NEWLINE;\
		mov		di, r8w;\
		call	_putnbr;\
		NEWLINE:\
		mov		di, '\n';\
		call 	_ftputchar;\
		cmp		r8w, 100;\
		jl		mainloop;\
		xor 	rax, rax;\
		ret;\
		L_.str:\
			.asciz \"fizz\";\
		L_.str2:\
			.asciz \"buzz\";");
}
