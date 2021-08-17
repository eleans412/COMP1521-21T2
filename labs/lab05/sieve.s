# Sieve of Eratosthenes
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
main:

        # PUT YOUR CODE
        li      $t0, 0

first_loop:

        bge     $t0, 1000, end_first_loop       # while (i >= 1000)

        la      $t1, prime                      # prime[i] = 1
        add     $t2, $t1, $t0

        li      $s0, 1
        sb      $s0, ($t2)

        addi    $t0, $t0, 1                     # i++
        j       first_loop

end_first_loop:
        
        li      $t0, 2                          # i = 2
        li      $t2, 0

second_loop:
        bge     $t0, 1000, end                  # while (i >= 1000)

        la      $t1, prime                      # prime[i]
        add     $t2, $t1, $t0                   

        lb      $s3, ($t2)                      

if:
        bne     $s3, 1, add_i                   # If there is an element then go to add_i

        move    $a0, $t0
        li      $v0, 1
        syscall

        li      $a0, '\n'
        li      $v0, 11
        syscall

        mul     $t3, $t0, 2                     # int j = 2 * i


third_loop:
        bge     $t3, 1000, add_i                # while (j >= 1000)

        la      $t1, prime
        add     $t4, $t1, $t3

        li      $s1, 0
        sb      $s1, ($t4)                      # prime[j] = 0

        add     $t3, $t3, $t0                   # j = j + i
        j       third_loop                      # continue loop


add_i: 
        addi    $t0, $t0, 1                     # i++;
        j       second_loop


end:
        li $v0, 0                               # return 0
        jr $31

        .data
prime:
        .space 1000