	.file	"teste_estatico.c"
	.text
	.globl	_Z8estaticov
	.type	_Z8estaticov, @function
_Z8estaticov:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_ZZ8estaticovE1i, %eax
	addl	$1, %eax
	movl	%eax, _ZZ8estaticovE1i
	movl	_ZZ8estaticovE1i, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	_Z8estaticov, .-_Z8estaticov
	.section	.rodata
.LC0:
	.string	"O valor \303\251: %d\n"
.LC1:
	.string	"\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	movl	$0, -12(%ebp)
.L5:
	cmpl	$9, -12(%ebp)
	jg	.L4
	call	_Z8estaticov
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	addl	$1, -12(%ebp)
	jmp	.L5
.L4:
	subl	$12, %esp
	pushl	$.LC1
	call	puts
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.local	_ZZ8estaticovE1i
	.comm	_ZZ8estaticovE1i,4,4
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
