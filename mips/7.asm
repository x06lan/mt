.data
    input:      .space  81
    input_size: .word   80
    prompt:     .asciiz "Enter Text: "
    output:     .asciiz "Fuck "

.text
    la $a0, prompt
    li $v0, 4
    syscall

    li $v0, 8 #set value 
    la $a0, input  #same to li but can use label
    lw $a1,input_size
    syscall

    li $v0, 4
    la $a0, output
    syscall

    li $v0, 4
    la $a0, input
    syscall

