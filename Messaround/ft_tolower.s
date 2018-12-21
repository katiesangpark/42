.globl	_ft_tolower

_ft_tolower:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%edi, %eax
	cmpl	$65, %eax
	jl	RETURNVALUE
	cmpl	$90, %eax
	jg	RETURNVALUE
	addl	$32, %eax
	
RETURNVALUE:
	popq	%rbp
	retq