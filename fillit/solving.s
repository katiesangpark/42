	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_overlap
	.p2align	4, 0x90
_overlap:                               ## @overlap
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
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	cmpq	-24(%rbp), %rax
	je	LBB0_14
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	subl	(%rax), %ecx
	movl	%ecx, -32(%rbp)
	movq	-16(%rbp), %rax
	movl	4(%rax), %ecx
	movq	-24(%rbp), %rax
	subl	4(%rax), %ecx
	movl	%ecx, -36(%rbp)
	movl	-32(%rbp), %ecx
	movq	-24(%rbp), %rax
	cmpl	8(%rax), %ecx
	jg	LBB0_13
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-36(%rbp), %eax
	movq	-24(%rbp), %rcx
	cmpl	12(%rcx), %eax
	jg	LBB0_13
## BB#4:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-24(%rbp), %rax
	movl	16(%rax), %ecx
	movl	%ecx, -28(%rbp)
	cmpl	$0, -32(%rbp)
	jl	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$3840, %eax             ## imm = 0xF00
	movl	$240, %ecx
	movl	$15, %edx
	movl	-28(%rbp), %esi
	movl	-32(%rbp), %edi
	movl	%ecx, -40(%rbp)         ## 4-byte Spill
	movl	%edi, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %esi
	movl	-32(%rbp), %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %edx
	andl	%edx, %esi
	movl	-28(%rbp), %edx
	movl	-32(%rbp), %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %edx
	andl	$240, %edx
	movl	-32(%rbp), %ecx
                                        ## kill: %CL<def> %ECX<kill>
	movl	-40(%rbp), %edi         ## 4-byte Reload
	sarl	%cl, %edi
	andl	%edi, %edx
	orl	%edx, %esi
	movl	-28(%rbp), %edx
	movl	-32(%rbp), %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %edx
	andl	$3840, %edx             ## imm = 0xF00
	movl	-32(%rbp), %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %eax
	andl	%eax, %edx
	orl	%edx, %esi
	movl	-28(%rbp), %eax
	movl	-32(%rbp), %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %eax
	andl	$61440, %eax            ## imm = 0xF000
	orl	%eax, %esi
	movl	%esi, -44(%rbp)         ## 4-byte Spill
	jmp	LBB0_7
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	$61440, %eax            ## imm = 0xF000
	xorl	%ecx, %ecx
	movl	$3840, %edx             ## imm = 0xF00
	movl	$240, %esi
	movl	-28(%rbp), %edi
	movl	%ecx, %r8d
	subl	-32(%rbp), %r8d
	movl	%ecx, -48(%rbp)         ## 4-byte Spill
	movl	%r8d, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %edi
	andl	$15, %edi
	movl	-28(%rbp), %r8d
	movl	-48(%rbp), %r9d         ## 4-byte Reload
	subl	-32(%rbp), %r9d
	movl	%r9d, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %r8d
	andl	$240, %r8d
	movl	-48(%rbp), %r9d         ## 4-byte Reload
	subl	-32(%rbp), %r9d
	movl	%r9d, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %esi
	andl	%esi, %r8d
	orl	%r8d, %edi
	movl	-28(%rbp), %esi
	movl	-48(%rbp), %r8d         ## 4-byte Reload
	subl	-32(%rbp), %r8d
	movl	%r8d, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %esi
	andl	$3840, %esi             ## imm = 0xF00
	movl	-48(%rbp), %r8d         ## 4-byte Reload
	subl	-32(%rbp), %r8d
	movl	%r8d, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %edx
	andl	%edx, %esi
	orl	%esi, %edi
	movl	-28(%rbp), %edx
	movl	-48(%rbp), %esi         ## 4-byte Reload
	subl	-32(%rbp), %esi
	movl	%esi, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %edx
	movl	-48(%rbp), %esi         ## 4-byte Reload
	subl	-32(%rbp), %esi
	movl	%esi, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	shll	%cl, %eax
	andl	%eax, %edx
	orl	%edx, %edi
	movl	%edi, -44(%rbp)         ## 4-byte Spill
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-44(%rbp), %eax         ## 4-byte Reload
	movl	%eax, -28(%rbp)
	cmpl	$0, -36(%rbp)
	jl	LBB0_9
## BB#8:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-28(%rbp), %eax
	movl	-36(%rbp), %ecx
	shll	$2, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	sarl	%cl, %eax
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	jmp	LBB0_10
LBB0_9:                                 ##   in Loop: Header=BB0_1 Depth=1
	xorl	%eax, %eax
	movl	-28(%rbp), %ecx
	subl	-36(%rbp), %eax
	shll	$2, %eax
	movl	%ecx, -56(%rbp)         ## 4-byte Spill
	movl	%eax, %ecx
                                        ## kill: %CL<def> %ECX<kill>
	movl	-56(%rbp), %eax         ## 4-byte Reload
	shll	%cl, %eax
	movl	%eax, -52(%rbp)         ## 4-byte Spill
LBB0_10:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-52(%rbp), %eax         ## 4-byte Reload
	movq	-16(%rbp), %rcx
	andl	16(%rcx), %eax
	cmpl	$0, %eax
	je	LBB0_12
## BB#11:
	movl	$1, -4(%rbp)
	jmp	LBB0_15
LBB0_12:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_13
LBB0_13:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	LBB0_1
LBB0_14:
	movl	$0, -4(%rbp)
LBB0_15:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_solve2
	.p2align	4, 0x90
_solve2:                                ## @solve2
	.cfi_startproc
## BB#0:
	## InlineAsm Start
	movb	12(%rsi), %r15b
	movb	$0, 4(%rsi)
YLOOP:
	movb	$0, (%rsi)
	movb	8(%rsi), %r14b
XLOOP:
	pushq	%rdi
	pushq	%rsi
	callq	_overlap
	popq	%rdi
	popq	%rsi
	incb	(%rsi)
	incb	%r14b
	cmpb	%bl, %r14b
	jl	XLOOP
	incb	4(%rsi)
	incb	%r15b
	cmpb	%bl, %r15b
	jl	YLOOP
end:
	retq

	## InlineAsm End
	.cfi_endproc

	.globl	_solve
	.p2align	4, 0x90
_solve:                                 ## @solve
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
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movq	-24(%rbp), %rsi
	movl	12(%rsi), %edx
	movl	%edx, -32(%rbp)
	movq	-24(%rbp), %rsi
	movl	8(%rsi), %edx
	movl	%edx, -36(%rbp)
	movq	-24(%rbp), %rsi
	movl	$0, 4(%rsi)
LBB2_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_3 Depth 2
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	addl	-32(%rbp), %ecx
	cmpl	-28(%rbp), %ecx
	jge	LBB2_10
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	-24(%rbp), %rax
	movl	$0, (%rax)
LBB2_3:                                 ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	addl	-36(%rbp), %ecx
	cmpl	-28(%rbp), %ecx
	jge	LBB2_9
## BB#4:                                ##   in Loop: Header=BB2_3 Depth=2
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	_overlap
	cmpl	$0, %eax
	jne	LBB2_8
## BB#5:                                ##   in Loop: Header=BB2_3 Depth=2
	movq	-24(%rbp), %rax
	cmpq	$0, 32(%rax)
	je	LBB2_7
## BB#6:                                ##   in Loop: Header=BB2_3 Depth=2
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rax
	movq	32(%rax), %rsi
	movl	-28(%rbp), %edx
	callq	_solve
	cmpl	$0, %eax
	je	LBB2_8
LBB2_7:
	movl	-28(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	LBB2_14
LBB2_8:                                 ##   in Loop: Header=BB2_3 Depth=2
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	jmp	LBB2_3
LBB2_9:                                 ##   in Loop: Header=BB2_1 Depth=1
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, 4(%rax)
	jmp	LBB2_1
LBB2_10:
	movq	-16(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jne	LBB2_12
## BB#11:
	movq	-16(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	callq	_solve
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB2_13
LBB2_12:
	xorl	%eax, %eax
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB2_13
LBB2_13:
	movl	-40(%rbp), %eax         ## 4-byte Reload
	movl	%eax, -4(%rbp)
LBB2_14:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.comm	_abcd,4,2               ## @abcd

.subsections_via_symbols
