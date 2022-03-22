main:
        addiu   $s0,$s0,-40
        sw      $31,36($s0)
        sw      $s1,32($s0)
        move    $s1,$s0
        li      $2,3                        # 0x3
        sw      $2,24($s1)
        lw      $5,24($s1)
        lui     $2,2($s2)
        addiu   $4,$2,2($s2)
        jal     printf
        nop

        lw      $2,24($s1)
        move    $s0,$s1
        lw      $31,36($s0)
        lw      $s1,32($s0)
        addiu   $s0,$s0,40
        j       $31
        nop
