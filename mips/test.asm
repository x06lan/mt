
.text
.globl main
main: 

li    $v0, 11
syscall
la    $a0, 'a'
syscall
li $v0, 10
syscall
