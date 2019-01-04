#include "list.h"

__attribute__ ((naked))
void _l(void)
{
	asm(".intel_syntax;\
			xor 	eax, eax;\
		MAINLOOP:\
			test 		rdi, -1;\
			jz			END;\
			mov rdi, 	QWORD ptr[rdi];\
			inc 		eax;\
			jmp			MAINLOOP;\
			\
		END:\
			ret;");
}

int	ft_list_size(t_list *begin_list)
{
	return (((int(*)(void*))&_l)(begin_list));
}
