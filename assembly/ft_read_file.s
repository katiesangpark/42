.intel_syntax noprefix
.text
.globl _ft_read_file
_ft_read_file:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 48
openfile:
	mov		rax, 0x2000005
	mov		rsi, 0
	SYSCALL
	test	rax, rax
	js		end
	mov 	r9, rax
readfile:
    mov		rax, 0x2000003
    mov     rdi, r9
    lea     rsi, [rbp - 32]
    mov     rdx, 32
	SYSCALL
    cmp		rax, 0
    je		closefile
    jl		end
writefile:
    mov		rdx, rax
    mov		rax, 0x2000004
    mov		rdi, 1
  	SYSCALL
  	jmp		readfile
closefile:
	mov		rdi, r9
	mov		rax, 0x2000006
	SYSCALL
end:
    add     rsp, 48
    pop     rbp
    ret
