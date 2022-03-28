.text
    main:
        addi $a0, $0, 10
        jal  f
		add $t0,$v0,$0
		addi $v0,$0,1
		addi $a0,$t0,0
		syscall
    f:
		addi $sp ,$sp,-8
        addi $a0, $a0, -1         #return 1
		addi $v0, $a0,0
		jal f
		beq $v0,1,end
        jr   $ra
	end:
		addi $v0,$0,1
		syscall
		addi $v0,$0,10
		syscall
