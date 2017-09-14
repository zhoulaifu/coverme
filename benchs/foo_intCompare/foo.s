	.text
	.file	"foo.c"
	.globl	foo
	.align	16, 0x90
	.type	foo,@function
foo:                                    # @foo
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -8(%rbp)
	movl	$0, -12(%rbp)
	cmpl	$2, -12(%rbp)
	jg	.LBB0_2
# BB#1:                                 # %if.then
	jmp	.LBB0_2
.LBB0_2:                                # %if.end
	popq	%rbp
	retq
.Lfunc_end0:
	.size	foo, .Lfunc_end0-foo
	.cfi_endproc


	.ident	"clang version 3.7.0 (trunk 234701)"
	.section	".note.GNU-stack","",@progbits
