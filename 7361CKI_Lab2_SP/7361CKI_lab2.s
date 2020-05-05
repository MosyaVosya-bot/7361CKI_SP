.data
	out:
	.long 0
	massive:
		.short -13214, -156, 10, 1500, -10, -200, 24536, 500, -70, -3230, 2100, 61
		size = . - massive
	string:
		.ascii "      \n"
.text
.global _start 
_start:
	movl $12, %ecx
	movl $massive, %esi
	movl $out, %edx
	checkmas:
		movw (%esi), %bx
	cmpw $0, %bx                   
	jg pos                           	 
	xorw $0xffff, %bx
	addw $0x0001, %bx
	pos:
		andl $0x0000ffff, %ebx  	     
		addl %ebx, (%edx)
		addl $2, %esi
	loop checkmas	                	 		
	movw (%edx), %ax
	movl $string, %esp
	addl $4, %esp
	pfo:
		movw $10, %bx
		xorl %edx, %edx
		divw %bx
		addb $48, %dl               	
		movb %dl, (%esp)
		subl $1, %esp
		cmpw $0, %ax
		je co
	loop pfo
	co:
		movl $4, %eax
		movl $1, %ebx
		movl $7, %edx
		movl $string, %ecx                   
		int $0x80
		movl $1, %eax
		movl $0, %ebx
		int $0x80
