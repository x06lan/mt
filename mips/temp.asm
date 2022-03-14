lw $t0,8($s0)
lw $t1,12($s0)
bne $t0,$t1,tblock
fblock:
	lw $t0,16($s0)
	sw $t0,24($s0)
	j end

tblock:
	lw $t0,16($s0)
	lw $t1,4($s0)
	add $t2,$t1,$t0
	sw $t2,20($s0)
end:
	#end
