.data
    input_text:     .asciiz "Enter int: "
    output_odd:     .asciiz "The number is odd"
    output_even:     .asciiz "The number is even"

.text
li $v0, 4
la $a0,input_text 
syscall

li $v0,5 #set value 
syscall
move $s0, $v0

srl $s1,$s0,1
sll $s1,$s1,1

beq $s0,$s1,exiteven


exitodd:
	li $v0, 4
	la $a0, output_odd
	syscall
	j end


exiteven:
	li $v0, 4
	la $a0, output_even
	syscall
end:

