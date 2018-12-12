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
	movl	4(%rax), %ecx
	shll	$24, %ecx
	sarl	$24, %ecx
	movq	-24(%rbp), %rax
	movl	4(%rax), %edx
	shll	$24, %edx
	sarl	$24, %edx
	subl	%edx, %ecx
	movl	%ecx, -32(%rbp)
	movq	-16(%rbp), %rax
	movl	4(%rax), %ecx
	shll	$16, %ecx
	sarl	$24, %ecx
	movq	-24(%rbp), %rax
	movl	4(%rax), %edx
	shll	$16, %edx
	sarl	$24, %edx
	subl	%edx, %ecx
	movl	%ecx, -36(%rbp)
	movl	-32(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	4(%rax), %edx
	shll	$8, %edx
	sarl	$24, %edx
	cmpl	%edx, %ecx
	jg	LBB0_13
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-36(%rbp), %eax
	movq	-24(%rbp), %rcx
	movl	4(%rcx), %edx
	sarl	$24, %edx
	cmpl	%edx, %eax
	jg	LBB0_13
## BB#4:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
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
	andl	(%rcx), %eax
	cmpl	$0, %eax
	je	LBB0_12
## BB#11:
	movl	$1, -4(%rbp)
	jmp	LBB0_15
LBB0_12:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_13
LBB0_13:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	LBB0_1
LBB0_14:
	movl	$0, -4(%rbp)
LBB0_15:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
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
	subq	$32, %rsp
	movb	%dl, %al
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movb	%al, -25(%rbp)
	movq	-24(%rbp), %rsi
	movl	4(%rsi), %edx
	sarl	$24, %edx
	movb	%dl, %al
	movb	%al, -26(%rbp)
	movq	-24(%rbp), %rsi
	movl	4(%rsi), %edx
	shll	$8, %edx
	sarl	$24, %edx
	movb	%dl, %al
	movb	%al, -27(%rbp)
	movq	-24(%rbp), %rsi
	movl	4(%rsi), %edx
	andl	$-65281, %edx           ## imm = 0xFFFF00FF
	movl	%edx, 4(%rsi)
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	shll	$16, %ecx
	sarl	$24, %ecx
	movsbl	-26(%rbp), %edx
	addl	%edx, %ecx
	movsbl	-25(%rbp), %edx
	cmpl	%edx, %ecx
	jge	LBB1_10
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	andl	$-256, %ecx
	movl	%ecx, 4(%rax)
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	shll	$24, %ecx
	sarl	$24, %ecx
	movsbl	-27(%rbp), %edx
	addl	%edx, %ecx
	movsbl	-25(%rbp), %edx
	cmpl	%edx, %ecx
	jge	LBB1_9
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=2
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rsi
	callq	_overlap
	cmpl	$0, %eax
	jne	LBB1_8
## BB#5:                                ##   in Loop: Header=BB1_3 Depth=2
	movq	-24(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB1_7
## BB#6:                                ##   in Loop: Header=BB1_3 Depth=2
	movq	-16(%rbp), %rdi
	movq	-24(%rbp), %rax
	movq	8(%rax), %rsi
	movsbl	-25(%rbp), %edx
	callq	_solve
	movsbl	%al, %edx
	cmpl	$0, %edx
	je	LBB1_8
LBB1_7:
	movb	-25(%rbp), %al
	movb	%al, -1(%rbp)
	jmp	LBB1_14
LBB1_8:                                 ##   in Loop: Header=BB1_3 Depth=2
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	shll	$24, %ecx
	sarl	$24, %ecx
	addl	$1, %ecx
	movl	4(%rax), %edx
	andl	$255, %ecx
	andl	$-256, %edx
	orl	%ecx, %edx
	movl	%edx, 4(%rax)
	jmp	LBB1_3
LBB1_9:                                 ##   in Loop: Header=BB1_1 Depth=1
	movq	-24(%rbp), %rax
	movl	4(%rax), %ecx
	shll	$16, %ecx
	sarl	$24, %ecx
	addl	$1, %ecx
	movl	4(%rax), %edx
	andl	$255, %ecx
	shll	$8, %ecx
	andl	$-65281, %edx           ## imm = 0xFFFF00FF
	orl	%ecx, %edx
	movl	%edx, 4(%rax)
	jmp	LBB1_1
LBB1_10:
	movq	-16(%rbp), %rax
	cmpq	-24(%rbp), %rax
	jne	LBB1_12
## BB#11:
	movq	-16(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movsbl	-25(%rbp), %eax
	addl	$1, %eax
	movb	%al, %cl
	movsbl	%cl, %edx
	callq	_solve
	movsbl	%al, %edx
	movl	%edx, -32(%rbp)         ## 4-byte Spill
	jmp	LBB1_13
LBB1_12:
	xorl	%eax, %eax
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jmp	LBB1_13
LBB1_13:
	movl	-32(%rbp), %eax         ## 4-byte Reload
	movb	%al, %cl
	movb	%cl, -1(%rbp)
LBB1_14:
	movsbl	-1(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
