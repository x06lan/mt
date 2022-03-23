.data
    input_text:     .asciiz "Enter int: "
	out_q:			.asciiz " quarter,"
	out_d:			.asciiz " dime, "
	out_n:			.asciiz " nickel,"
	out_p:			.asciiz " penny"
	text_and: .asciiz "and"

.text

li $v0, 4
la $a0,input_text 
syscall

li $v0,5 #set value 
syscall
move $s0, $v0

#q
qb:
	li $t0, 25
	div $s0,$t0
	mfhi $s0
	li $v0, 1
	mflo $a0
	beq $a0,$zero,db
print_q:
	syscall
	#beq $s0,$zero,
	li $v0, 4
	la $a0,out_q
	syscall
#d
db:
	li $t0, 10
	div $s0,$t0
	mfhi $s0
	li $v0, 1
	mflo $a0
	beq $a0,$zero,bn
print_d:
	syscall
	li $v0, 4
	la $a0,out_d
	syscall
#n
bn:
	li $t0, 5
	div $s0,$t0
	mfhi $s0
	li $v0, 1
	mflo $a0
	beq $a0,$zero,pn
print_n:
	syscall
	li $v0, 4
	la $a0,out_n
	syscall
#p
pn:
	li $t0, 1
	div $s0,$t0
	mfhi $s0
	li $v0, 1
	mflo $a0
	beq $a0,$zero,print_p
print_p:
	syscall
	li $v0, 4
	la $a0,out_p
	syscall
