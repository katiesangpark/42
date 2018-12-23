.intel_syntax noprefix
.globl _ft_print_memory
_ft_print_memory:
    push    rbp
   	mov		r9, rdi
   	mov		r10, rsi
print:
	xor 	r8, r8
printhex:
	mov 	r11, 32
	mov 	r12, 32

	cmp		r8, r10
	jge		printhexchar_1
	movzx	r11, BYTE ptr[r9 + r8]
	mov 	r12, r11
	shr		r11, 4
	and		r12, 0xF
	and		r11, 0xF

	cmp		r11, 10
	jae		alpha_1
	add		r11, 48	
	jmp		printhexchar_1
alpha_1:
	add		r11, 87
printhexchar_1:
	push	r11
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rsi, rsp
	mov		rdx, 1
	SYSCALL
	pop		r11

	cmp		r8, r10
	jge		printhexchar_2
	cmp		r12, 10
	jae		alpha_2
	add		r12, 48
	jmp		printhexchar_2
alpha_2:
	add		r12, 87
printhexchar_2:
	push	r12
	mov		rax, 0x2000004
	mov		rdx, 1
	SYSCALL
	pop		r12

	inc 	r8
	test	r8, 1
	jnz		loopback
	push	32
	mov		rax, 0x2000004
	mov		rdx, 1
	SYSCALL
	pop		r12
loopback:
	cmp		r8, 16
	jl		printhex
	push	32
	mov		rax, 0x2000004
	mov		rdi, 1
	mov		rdx, 1
	SYSCALL
	pop		r11
test:
	xor		r8, r8
charloop:
	movsx	r11, BYTE ptr[r9 + r8]
	mov 	rcx, 46 
	cmp		r11, 32
	jl		printchar
	cmp		r11, 127
	jg		printchar
	mov		rcx, r11
printchar:
	push 	rcx
	mov		rax, 0x2000004
	mov		rdx, 1
	SYSCALL
	pop		rcx
	inc 	r8
	dec		r10
	cmp		r8, r10
	jge		newline
	cmp		r8, 16
	jl		charloop
newline:
	push	10
	mov		rax, 0x2000004
	mov		rdx, 1
	SYSCALL
	pop		rcx
	cmp		r10, 16
	jl		end
	add		r9, 16
	jmp		print
end:
	pop 	rbp
	ret
