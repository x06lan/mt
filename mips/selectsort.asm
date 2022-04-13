.data
	msg1: .asciiz "Give a number: "
	list: .space 400
	list1: .word 1,5,7,3,5,7,0,2

.text
.globl main
main:
	la $s0,list
	li $t6,1
	sw $t6,0($s0)
	sw $t6,4($s0)
	li $t0,7
	li $t1,0
	li $t2,0
	
loopi:

	lw $t0,0($s0)
	li $t2,1
	addi $t1,$t1,1

	loopj:

		lw $t0,0($s0)
		lw $t0,0($s0)
		addi $t2,$t2,1
		beq		$t2, $t1, outj# if $t0 == $t1 then target
		j loopj
		outj:

	beq		$t0, $t1, outi# if $t0 == $t1 then target
	j loopi
	
outi:
swap:
	sw $t0,0($s1)
	sw $t0,0($s1)
	j loopi
	
end:
    li $v0, 10
    syscall