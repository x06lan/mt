.data
    input_h: .word 80
    input_w: .word 80
    input_bmi: .word 80
    prompt_h:     .asciiz "high: "
    prompt_w:     .asciiz "weigh: "
    output:     .asciiz "echo: "

.text
    la $a0, prompt_h
    li $v0, 4
    syscall

    li $v0, 6 #set value 
    syscall

	mov.s $f12, $f0
	li $v0,2
	syscall
