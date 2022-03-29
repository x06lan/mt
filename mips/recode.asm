.data
	msg1: .asciiz "Give a number: "
	A : .byte 'a', 'e', 'i', 'o', 'u'
	pow2: .word 1, 2, 4, 8, 16, 32, 64, 128
	list: .space 1000

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
    #jal recode
    #jal fb

	la $t0 ,list
	lw $a0,2($t0)

    #add $a0, $v0, $zero # move to $a0
    li $v0, 1
    syscall


    li $v0, 10
    syscall
#1+...+n
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

fb:
	addi $sp,$sp,-8
	sw $ra,0($sp)
	beq $a0,0,fbout

	add $t0,$t0,$a0
	addi $a0,$a0,-1
	jal fb
fbout:
	lw $ra,0($sp)
	addi $sp,$sp,8
	jr $ra
