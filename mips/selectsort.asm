.data
	msg1: .asciiz "Give a number: "
	list: .space 400
	list1: .word  1,6,7,6,9,7,0,2

.text
.globl main
main:
	la $s0,list1
	li $t0,32 #8*4
	li $t1,0 #i
	li $t2,0 #j
	li $t3,0 #max

	
loopi:

	addi $t2,$t1,0
	add $s1,$s0,$t1
	add $t3,$t1,$0

	loopj:
		addi $t2,$t2,4
		add $s2,$s0,$t2
		add $s3,$s0,$t3
	
		lw $t4,($s2)
		lw $t5,($s3)
		bgt $t5,$t4,notchange
		addi $t3,$t2,0
	notchange:
		bgt $t0,$t2,loopj
	
	
	add $s3,$s0,$t3 # swap
	lw $t6,($s1)
	lw $t7,($s3)
	addi $t8,$t6,0
	sw $t7,($s1)
	sw $t8,($s3)
	addi $t1,$t1,4
	bgt $t0,$t1,loopi

li $t1,0
loop:
	add $s1,$s0,$t1
	lw $a0,($s1)
	li $v0,1
	syscall
	addi $t1,$t1,4
	bgt $t0,$t1,loop
end:
    li $v0, 10
    syscall
