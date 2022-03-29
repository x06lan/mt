.text
	main:
	
	#a[6]
	addi $t4,$s6,6
	lw $t0,6($t4)
	#b[j+2]
	addi $s4,$s4,2
	add $s7,$s4,$s7
	lw $t1,0($s7)
	#a[i+3]
	addi $s3,$s3,3
	addi $s6,$s3,$s6
	subi $t2,$t0,$t1
	sw $t2,$s3($s6)
	
a+8
t0=a[8]
t0=t0*4
t1=i*4
t1=b[i*4]	
g=f+b[i*4]+a[8]



lw s4 128 a2

7
addi $s0,$s0,5
sll $s0,$s0,2
add $s2,$s2,$s0
lw $t0,($s2)
slr $s1,$s2,8






