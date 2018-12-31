#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	(void)cmp;
	asm(".intel_syntax;\
			mov 	r8, rdi;\
			mov 	r9, rsi;\
			mov 	r10, r8;\
			test	rdi, -1;\
			jz 		end;
			MAINLOOP: mov r15, QWORD ptr[r10 + 8];\
			test 	r15, -1;\
			jz 		end;\
			mov		edi, DWORD ptr[r10];\
			mov		esi, DWORD ptr[r15];\
			call	r9;\
			jnz		NEXTELEM;\
			mov		edi, DWORD ptr[r10];\
			mov		esi, DWORD ptr[r15];\
			mov		DWORD ptr[r10], esi;\
			mov		DWORD ptr[r15], edi;\
			mov		r10, r8;\
			jmp		MAINLOOP;\
			NEXTELEM: mov		r10, r15;\
			jmp 	MAINLOOP;\
			end:");
	return (lst);
}
