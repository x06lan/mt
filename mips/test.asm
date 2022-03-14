.data 
	newline:.asciiz "\n"
.text


main:
    li $t0,0
    li $t1,0
    li $t3,0
loop:
    li $v0,1
	addi  $a0,$t0,0
	syscall
    li $v0,4
	la $a0,newline
	syscall

    addi $t0,$t0,1
    bgt $t0,14,exit
	
    j loop
exit:
    li $v0,0
