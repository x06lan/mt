.data
	msg1: .asciiz "Give a number: "
	list : .space 400 #400 byte for 100 int 

.text
.globl main
main:
    li $v0,  4
    la $a0,  msg1
    syscall             # print msg
    li $v0,  5
    syscall             # read an int
    add $a0, $v0, $zero # move to $a0

	
	la $t0 ,list
	sw 1,0($t0)
	sw 1,4($t0)
    jal fb


    li $v0, 1
    syscall
    li $v0, 10
    syscall
fb:
	addi $sp,$sp,-8
	sw $ra,0($sp)
	sw $a0,4($sp)
	beq $a0,-2,fbout

	add $t0,$t0,$a0
	addi $a0,$a0,-1
	jal fb
fbout:
	lw $ra,0($sp)
	lw $t3,4($sp)
	addi $sp,$sp,8

	lw $t2 $t3($t0)
	addi $t3 $t3 4
	lw $t4 $t3($t0)
	add $t5 $t2 $t4
	addi $t3 $t3 4
	sw $t5 $t3(t0)
	
	jr $ra
