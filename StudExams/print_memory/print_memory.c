#include <string.h>

void	print_memory(const void *addr, size_t size)
{
	(void)addr;
	(void)size;
    asm(".intel_syntax noprefix;push rbp;mov r9,rdi;mov r10,rsi;_0:xor r8,r8;\
_1:mov r11,32;mov r12,32;cmp r8,r10;jge _3;movzx r11,BYTE ptr[\
r9+r8];mov r12,r11;shr r11,4;and r12,0xF;and r11,0xF;cmp r11,10;jae _2;add \
r11,48;jmp _3;_2:add r11,87;_3:push r11;mov rax,33554436;\
mov rdi,1;mov rsi,rsp;mov rdx,1;SYSCALL;pop r11;cmp r8,r10;jge _5;cmp \
r12,10;jae _4;add r12,48;jmp _5;_4:add r12,87;_5:\
push r12;mov rax,33554436;mov rdx,1;SYSCALL;pop r12;inc r8;test r8,1;jnz _6;\
push 32;mov rax,33554436;mov rdx,1;SYSCALL;pop r12;_6:cmp r8,16;jl _1;\
_7:xor r8,r8;_8:test r10,-1;jz _A;movsx r11,BYTE ptr[r9+r8];mov rcx,\
46;cmp r11,32;jl _9;cmp r11,127;jge _9;mov rcx,r11;_9:push \
rcx;mov rax,33554436;mov rdx,1;SYSCALL;pop rcx;inc r8;cmp r8,r10;jge _A;cmp \
r8,16;jge _A;jmp _8;_A:push 10;mov rax,33554436;mov rdx,1;SYSCALL;\
pop rcx;cmp r10,16;jle _B;sub r10,16;add r9,16;jmp _0;_B:pop rbp;");
}
