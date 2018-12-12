	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_ft_sqrt
	.p2align	4, 0x90
_ft_sqrt:                               ## @ft_sqrt
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
	movl	%edi, -4(%rbp)
	movl	$2, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	imull	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_1
LBB0_3:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$1, -8(%rbp)
	jne	LBB1_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	callq	_ft_putendl
	movl	$0, -4(%rbp)
	jmp	LBB1_6
LBB1_2:
	leaq	-24(%rbp), %rsi
	movq	$0, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_read_file
	cmpl	$0, %eax
	je	LBB1_4
## BB#3:
	movq	-24(%rbp), %rdi
	callq	_validate_block_shapes
	cmpl	$0, %eax
	jne	LBB1_5
LBB1_4:
	movq	-24(%rbp), %rdi
	callq	_lst_clear
	leaq	L_.str.1(%rip), %rdi
	callq	_ft_putendl
	movl	$0, -4(%rbp)
	jmp	LBB1_6
LBB1_5:
	movq	-24(%rbp), %rdi
	callq	_correct_blocks_starting_pos
	movq	-24(%rbp), %rdi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	callq	_lst_size
	shll	$2, %eax
	movl	%eax, %edi
	callq	_ft_sqrt
	movl	%eax, -28(%rbp)
	movq	-24(%rbp), %rdi
	movq	-24(%rbp), %rsi
	movl	-28(%rbp), %eax
	movb	%al, %cl
	movsbl	%cl, %edx
	callq	_solve
	movsbl	%al, %edx
	movl	%edx, -28(%rbp)
	movq	-24(%rbp), %rdi
	movl	-28(%rbp), %esi
	callq	_print_map
	movq	-24(%rbp), %rdi
	callq	_lst_clear
	movl	$0, -4(%rbp)
LBB1_6:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"usage: fillit source_file"

L_.str.1:                               ## @.str.1
	.asciz	"error"


.subsections_via_symbols
