.data
    input:      .space  80
    input_size: .word   80
    prompt:     .asciiz "Enter Text: "
    output:     .asciiz "echo: "

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

