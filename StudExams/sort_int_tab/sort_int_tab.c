
void sort_int_tab(int *tab, unsigned int size)
{
	(void)tab;
	(void)size;
	asm(".intel_syntax;\
			test rdi, -1;\
			jz end;\
			cmp esi, 1;\
			jbe end;\
		INIT:\
			mov r8, rdi;\
			xor eax, eax;\
		MAINLOOP:\
			inc eax;\
			cmp eax, esi;\
			je 	end;\
			mov r10d, DWORD ptr[r8];\
			mov r11d, DWORD ptr[r8 + 4];\
			cmp r10d, r11d;\
			jle	LOOPITER;\
			mov DWORD ptr[r8], r11d;\
			mov DWORD ptr[r8 + 4], r10d;\
			jmp INIT;\
		LOOPITER:\
			add r8, 4;\
			jmp	MAINLOOP;\
		end:");
}
