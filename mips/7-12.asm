.data
    input_text:     .asciiz "Enter int: "
	out_q:			.asciiz " quarters,"
	out_d:			.asciiz " dime, "
	out_n:			.asciiz " nickel, and "
	out_p:			.asciiz " penny"

.text

li $v0, 4
la $a0,input_text 
syscall

li $v0,5 #set value 
syscall
move $s0, $v0

#q
li $t0, 25
div $s0,$t0
mfhi $s0

li $v0, 1
mflo $a0
syscall
li $v0, 4
la $a0,out_q
syscall

#d
li $t0, 10
div $s0,$t0
mfhi $s0

li $v0, 1
mflo $a0
syscall
li $v0, 4
la $a0,out_d
syscall
#d
li $t0, 5
div $s0,$t0
mfhi $s0

li $v0, 1
mflo $a0
syscall
li $v0, 4
la $a0,out_n
syscall
#p
li $t0, 1
div $s0,$t0
mfhi $s0

li $v0, 1
mflo $a0
syscall
li $v0, 4
la $a0,out_p
syscall
