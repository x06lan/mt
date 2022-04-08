.data
	msg1: .asciiz "Give a number: "
	list: .space 400

.text
.globl main
main:
    li $v0,  4
    la $a0,  msg1
    syscall             # print msg
    li $v0,  5
    syscall             # read an int
    add $a0, $v0, $zero # move to $a0

	
	addi $s1,$a0,0
	la $t0,list
	li $t6,1
	sw $t6,0($t0)
	sw $t6,4($t0)

    jal fb

	addi $a0,$a0,-1
	sll $a0,$a0,2
	add $t0,$t0,$a0
	lw $a0,($t0)
    li $v0, 1
    syscall
    li $v0, 10
    syscall
fb:
	addi $sp,$sp,-8
	sw $ra,0($sp)
	sw $a0,4($sp)
	beq $a0,0,fbout
	addi $a0,$a0,-1
	jal fb
fbout:
	lw $ra,0($sp)
	lw $t2,4($sp)
	addi $sp,$sp,8
	
	addi $a0,$t2,0 # keep $a0 as input

	addi $t1,$t0,0
	sll $t2,$t2,2

	add $t1,$t1,$t2 #a[i]
	lw $t3,0($t1)

	addi $t1,$t1,4 #a[i+1]
	lw $t4,0($t1)

	add $t5,$t3,$t4 #a[i+2]=a[i]+a[i+1]
	addi $t1,$t1,4
	sw $t5,($t1)

	jr $ra
