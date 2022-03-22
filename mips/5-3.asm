
.data
result1: .ascii "\nfirst value = "
result2: .ascii "\nsecond value = "

.text
main:
    li $v0, 4
    la $a0, result1
    syscall
    li $v0, 1
    li $a0, 4
    syscall
