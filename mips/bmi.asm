.data
    input_h: .word 80
    input_w: .word 80
    input_bmi: .word 80
    prompt_h:     .asciiz "high: "
    prompt_w:     .asciiz "weigh: "
	prompt_bmi:		.asciiz "bmi:"
    output:     .asciiz "echo: "

.text
	input_h_d:
		la $a0, prompt_h
		li $v0, 4
		syscall

		li $v0, 6
		syscall

		mov.s $f2, $f0
	input_w_d:
		la $a0, prompt_w
		li $v0, 4
		syscall

		li $v0, 6
		syscall

		mov.s $f3, $f0
	output_bmi:
		mul.s $f4 $f2 $f2
		div.s $f5 $f3 $f4
		mov.s $f12 $f5
		li $v0 ,2
		syscall
