.data
msg1: .asciiz "Give a number: "

.text
.globl main
main:
    li $v0,  4
    la $a0,  msg1
    syscall             # print msg
    li $v0,  5
    syscall             # read an int
    add $a0, $v0, $zero # move to $a0

	li $t0,0
    jal recode
    add $a0, $v0, $zero # move to $a0
    add $a0, $t0, $zero # move to $a0
    li $v0, 1
    syscall


    li $v0, 10
    syscall
recode:
	addi $sp,$sp,-8
	sw $ra,0($sp)
	sw $v0,4($sp)
	beq $a0,0,out

	add $t0,$t0,$a0
	addi $a0,$a0,-1
	jal recode
out:
	lw $ra,0($sp)
	lw $v0,4($sp)
	addi $sp,$sp,8
	jr $ra

