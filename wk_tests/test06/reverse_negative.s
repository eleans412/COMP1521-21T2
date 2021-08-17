# Read numbers into an array until a negative number is entered
# then print the numbers in reverse order

# i in register $t0
# registers $t1, $t2 & $t3 used to hold temporary results

main:

        li      $t1, 0                  # int i = 0
f_while:
        bge     $t1, 1000, s_while      # while (i < 1000)
        
        li      $v0, 5                  # scanf("%d", &x);
        syscall
        move    $t0, $v0

        blt     $t0, 0, s_while         # if (x < 0) break

        mul     $t2, $t1, 4    # calculate &numbers[i]
        la      $t3, numbers   #
        add     $t4, $t2, $t3  #
        sw      $t0, ($t4)     # numbers[i] = x

        addi    $t1, $t1, 1    # i++;
        
        j       f_while


s_while:
        beq     $t1, 0, end     # if i == 0, goto end
        
        addi     $t1, $t1, -1     # i--

        mul     $t2, $t1, 4    # calculate &numbers[i]
        la      $t3, numbers   #
        add     $t4, $t2, $t3  #
        lw      $a0, ($t4)     # numbers[i] = x

      
        li      $v0, 1          # printf("%d", x)
        syscall

        li      $a0, '\n'      # printf("%c", '\n');
        li      $v0, 11
        syscall

        j       s_while

end:
        li      $v0, 0         # return 0
        jr      $ra


.data

numbers:
        .space 4000           # int numbers[1000];

