.data
    input_text:     .asciiz "Enter int: "
    output_odd:     .asciiz "The number is odd"
    output_even:     .asciiz "The number is even"

.text
la $a0,input_text 
li $v0, 4
syscall

li $v0,5 #set value 
syscall
move $t0, $v0
loop:
	
	bne $t0,1,exitodd
	bne $t0,0,exiteven
	srl $t0,$t0,1
	j loop
	

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

