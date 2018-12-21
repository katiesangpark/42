	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_ft_tolower
	.p2align	4, 0x90
_ft_tolower:                            ## @ft_tolower
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -8(%rbp)
	cmpl	$65, -8(%rbp)
	jl	LBB0_4
## BB#1:
	cmpl	$90, -8(%rbp)
	jg	LBB0_4
	addl	$32, -8(%rbp)
LBB0_4:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
