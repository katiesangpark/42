	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_ft_putchar
	.p2align	4, 0x90
_ft_putchar:                            ## @ft_putchar
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
	subq	$16, %rsp
	movb	%dil, %al
	movl	$1, %edi
	leaq	-1(%rbp), %rsi
	movl	$1, %ecx
	movl	%ecx, %edx
	movb	%al, -1(%rbp)
	callq	_write
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ft_putnbr
	.p2align	4, 0x90
_ft_putnbr:                             ## @ft_putnbr
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
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
	cmpl	$0, -4(%rbp)
	jge	LBB1_5
## BB#1:
	movl	$45, %edi
	callq	_ft_putchar
	movslq	-4(%rbp), %rax
	cmpq	$-2147483648, %rax      ## imm = 0x80000000
	jne	LBB1_3
## BB#2:
	movl	$2147483647, -4(%rbp)   ## imm = 0x7FFFFFFF
	movl	$1, -8(%rbp)
	jmp	LBB1_4
LBB1_3:
	xorl	%eax, %eax
	subl	-4(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB1_4:
	jmp	LBB1_5
LBB1_5:
	cmpl	$10, -4(%rbp)
	jl	LBB1_7
## BB#6:
	movl	$10, %eax
	movl	-4(%rbp), %ecx
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-12(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	%eax, %edi
	callq	_ft_putnbr
LBB1_7:
	movl	$10, %eax
	movl	-4(%rbp), %ecx
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-16(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	addl	$48, %edx
	addl	-8(%rbp), %edx
	movb	%dl, %sil
	movsbl	%sil, %edi
	callq	_ft_putchar
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ft_putstr
	.p2align	4, 0x90
_ft_putstr:                             ## @ft_putstr
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	$0, -12(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	movslq	-12(%rbp), %rcx
	cmpb	$0, (%rax,%rcx)
	je	LBB2_3
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB2_1
LBB2_3:
	movl	$1, %edi
	movq	-8(%rbp), %rsi
	movslq	-12(%rbp), %rdx
	callq	_write
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_ft_printf
	.p2align	4, 0x90
_ft_printf:                             ## @ft_printf
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	subq	$528, %rsp              ## imm = 0x210
	testb	%al, %al
	movaps	%xmm7, -256(%rbp)       ## 16-byte Spill
	movaps	%xmm6, -272(%rbp)       ## 16-byte Spill
	movaps	%xmm5, -288(%rbp)       ## 16-byte Spill
	movaps	%xmm4, -304(%rbp)       ## 16-byte Spill
	movaps	%xmm3, -320(%rbp)       ## 16-byte Spill
	movaps	%xmm2, -336(%rbp)       ## 16-byte Spill
	movaps	%xmm1, -352(%rbp)       ## 16-byte Spill
	movaps	%xmm0, -368(%rbp)       ## 16-byte Spill
	movq	%rdi, -376(%rbp)        ## 8-byte Spill
	movq	%r9, -384(%rbp)         ## 8-byte Spill
	movq	%r8, -392(%rbp)         ## 8-byte Spill
	movq	%rcx, -400(%rbp)        ## 8-byte Spill
	movq	%rdx, -408(%rbp)        ## 8-byte Spill
	movl	%esi, -412(%rbp)        ## 4-byte Spill
	je	LBB3_25
## BB#24:
	movaps	-368(%rbp), %xmm0       ## 16-byte Reload
	movaps	%xmm0, -192(%rbp)
	movaps	-352(%rbp), %xmm1       ## 16-byte Reload
	movaps	%xmm1, -176(%rbp)
	movaps	-336(%rbp), %xmm2       ## 16-byte Reload
	movaps	%xmm2, -160(%rbp)
	movaps	-320(%rbp), %xmm3       ## 16-byte Reload
	movaps	%xmm3, -144(%rbp)
	movaps	-304(%rbp), %xmm4       ## 16-byte Reload
	movaps	%xmm4, -128(%rbp)
	movaps	-288(%rbp), %xmm5       ## 16-byte Reload
	movaps	%xmm5, -112(%rbp)
	movaps	-272(%rbp), %xmm6       ## 16-byte Reload
	movaps	%xmm6, -96(%rbp)
	movaps	-256(%rbp), %xmm7       ## 16-byte Reload
	movaps	%xmm7, -80(%rbp)
LBB3_25:
	movq	-384(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -200(%rbp)
	movq	-392(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -208(%rbp)
	movq	-400(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -216(%rbp)
	movq	-408(%rbp), %rsi        ## 8-byte Reload
	movq	%rsi, -224(%rbp)
	movl	-412(%rbp), %edi        ## 4-byte Reload
	movq	-376(%rbp), %r8         ## 8-byte Reload
	leaq	-32(%rbp), %r9
	movq	___stack_chk_guard@GOTPCREL(%rip), %r10
	movq	(%r10), %r10
	movq	%r10, -8(%rbp)
	movq	%r8, -48(%rbp)
	movl	%edi, -52(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -56(%rbp)
	leaq	-240(%rbp), %r8
	movq	%r8, 16(%r9)
	leaq	16(%rbp), %r8
	movq	%r8, 8(%r9)
	movl	$48, 4(%r9)
	movl	$16, (%r9)
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-48(%rbp), %rax
	movslq	-60(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$0, %edx
	je	LBB3_16
## BB#2:                                ##   in Loop: Header=BB3_1 Depth=1
	movq	-48(%rbp), %rax
	movslq	-60(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$37, %edx
	jne	LBB3_15
## BB#3:                                ##   in Loop: Header=BB3_1 Depth=1
	movq	-48(%rbp), %rax
	movslq	-60(%rbp), %rcx
	movsbl	1(%rax,%rcx), %edx
	movl	%edx, %esi
	subl	$32, %esi
	movl	%edx, -416(%rbp)        ## 4-byte Spill
	movl	%esi, -420(%rbp)        ## 4-byte Spill
	je	LBB3_12
	jmp	LBB3_20
LBB3_20:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-416(%rbp), %eax        ## 4-byte Reload
	subl	$37, %eax
	movl	%eax, -424(%rbp)        ## 4-byte Spill
	je	LBB3_12
	jmp	LBB3_21
LBB3_21:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-416(%rbp), %eax        ## 4-byte Reload
	subl	$99, %eax
	movl	%eax, -428(%rbp)        ## 4-byte Spill
	je	LBB3_12
	jmp	LBB3_22
LBB3_22:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-416(%rbp), %eax        ## 4-byte Reload
	subl	$100, %eax
	movl	%eax, -432(%rbp)        ## 4-byte Spill
	je	LBB3_8
	jmp	LBB3_23
LBB3_23:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-416(%rbp), %eax        ## 4-byte Reload
	subl	$115, %eax
	movl	%eax, -436(%rbp)        ## 4-byte Spill
	jne	LBB3_13
	jmp	LBB3_4
LBB3_4:                                 ##   in Loop: Header=BB3_1 Depth=1
	leaq	-32(%rbp), %rax
	movl	-32(%rbp), %ecx
	cmpl	$40, %ecx
	movq	%rax, -448(%rbp)        ## 8-byte Spill
	movl	%ecx, -452(%rbp)        ## 4-byte Spill
	ja	LBB3_6
## BB#5:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-452(%rbp), %eax        ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-448(%rbp), %rdx        ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -464(%rbp)        ## 8-byte Spill
	jmp	LBB3_7
LBB3_6:                                 ##   in Loop: Header=BB3_1 Depth=1
	movq	-448(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -464(%rbp)        ## 8-byte Spill
LBB3_7:                                 ##   in Loop: Header=BB3_1 Depth=1
	movq	-464(%rbp), %rax        ## 8-byte Reload
	movq	(%rax), %rdi
	callq	_ft_putstr
	movl	-60(%rbp), %ecx
	addl	$1, %ecx
	movl	%ecx, -60(%rbp)
	jmp	LBB3_14
LBB3_8:                                 ##   in Loop: Header=BB3_1 Depth=1
	leaq	-32(%rbp), %rax
	movl	-32(%rbp), %ecx
	cmpl	$40, %ecx
	movq	%rax, -472(%rbp)        ## 8-byte Spill
	movl	%ecx, -476(%rbp)        ## 4-byte Spill
	ja	LBB3_10
## BB#9:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-476(%rbp), %eax        ## 4-byte Reload
	movslq	%eax, %rcx
	movq	-472(%rbp), %rdx        ## 8-byte Reload
	addq	16(%rdx), %rcx
	addl	$8, %eax
	movl	%eax, (%rdx)
	movq	%rcx, -488(%rbp)        ## 8-byte Spill
	jmp	LBB3_11
LBB3_10:                                ##   in Loop: Header=BB3_1 Depth=1
	movq	-472(%rbp), %rax        ## 8-byte Reload
	movq	8(%rax), %rcx
	movq	%rcx, %rdx
	addq	$8, %rcx
	movq	%rcx, 8(%rax)
	movq	%rdx, -488(%rbp)        ## 8-byte Spill
LBB3_11:                                ##   in Loop: Header=BB3_1 Depth=1
	movq	-488(%rbp), %rax        ## 8-byte Reload
	movl	(%rax), %edi
	callq	_ft_putnbr
	movl	-60(%rbp), %edi
	addl	$1, %edi
	movl	%edi, -60(%rbp)
	jmp	LBB3_14
LBB3_12:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	$1, %edi
	movl	$1, %eax
	movl	%eax, %edx
	movq	-48(%rbp), %rcx
	movslq	-60(%rbp), %rsi
	addq	%rsi, %rcx
	addq	$1, %rcx
	movq	%rcx, %rsi
	callq	_write
	movl	-60(%rbp), %edi
	addl	$1, %edi
	movl	%edi, -60(%rbp)
	movq	%rax, -496(%rbp)        ## 8-byte Spill
	jmp	LBB3_14
LBB3_13:
	leaq	L_.str(%rip), %rdi
	movl	$1, %esi
	movq	-48(%rbp), %rax
	movl	-60(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	movsbl	(%rax,%rdx), %edx
	movb	$0, %al
	callq	_ft_printf
	movl	$-1, -36(%rbp)
	movl	%eax, -500(%rbp)        ## 4-byte Spill
	jmp	LBB3_17
LBB3_14:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	LBB3_1
LBB3_15:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	$1, %edi
	movl	$1, %eax
	movl	%eax, %edx
	movq	-48(%rbp), %rcx
	movslq	-60(%rbp), %rsi
	addq	%rsi, %rcx
	movq	%rcx, %rsi
	callq	_write
	movl	-60(%rbp), %edi
	addl	$1, %edi
	movl	%edi, -60(%rbp)
	movq	%rax, -512(%rbp)        ## 8-byte Spill
	jmp	LBB3_1
LBB3_16:
	leaq	-32(%rbp), %rax
	movl	-56(%rbp), %ecx
	movl	%ecx, -36(%rbp)
	movq	%rax, -520(%rbp)        ## 8-byte Spill
LBB3_17:
	movl	-36(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -524(%rbp)        ## 4-byte Spill
	jne	LBB3_19
## BB#18:
	movl	-524(%rbp), %eax        ## 4-byte Reload
	addq	$528, %rsp              ## imm = 0x210
	popq	%rbp
	retq
LBB3_19:
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi12:
	.cfi_def_cfa_offset 16
Lcfi13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi14:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str.1(%rip), %rax
	movl	$1, %ecx
	leaq	L_.str.2(%rip), %rdx
	movl	$475, %r8d              ## imm = 0x1DB
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, %rdi
	movl	%ecx, %esi
	movl	%r8d, %ecx
	movb	$0, %al
	callq	_ft_printf
	xorl	%ecx, %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\n<<<!!! ft_printf Error! Unknown argument %%c !!!>>>\n"

L_.str.1:                               ## @.str.1
	.asciz	"Salut! %s %d"

L_.str.2:                               ## @.str.2
	.asciz	"test"


.subsections_via_symbols
