# read a line and print whether it is a palindrom

main:
        la      $a0, str0       # printf("Enter a line of input: ");
        li      $v0, 4
        syscall

        la      $a0, line
        la      $a1, 256
        li      $v0, 8                          # fgets(buffer, 256, stdin)
        syscall              


        li      $t0, 0                          # i = 0

loop0:

        la      $t1, line
        add     $t2, $t0, $t1                   # Get the character at the position
        lb      $t3, ($t2)

        beq     $t3, 0, end_loop0               # while (line[i] != 0)

        addi    $t0, $t0, 1                     # i++

        j       loop0                           # Continue looping 

end_loop0:
        li      $t4, 0                          # j = 0
        sub     $t5, $t0, 2                     # k = i - 2

loop1:
        bge     $t4, $t5, palindrome_print      # while (j < k)

if_cond:
        la      $t1, line
        add     $t2, $t4, $t1                   # Get the character at the j position
        lb      $t6, ($t2)

        la      $t1, line
        add     $t2, $t5, $t1                   # Get the character at the k position
        lb      $t7, ($t2)

        beq     $t6, $t7, cont_loop

        j       not_palindrome_print

cont_loop:
        addi    $t4, $t4, 1                     # j++;
        sub     $t5, $t5, 1                     # k--;

        j       loop1


not_palindrome_print:
        la      $a0, not_palindrome             # print not_palindrome
        li      $v0, 4
        syscall

        j       end                             # end program

palindrome_print:               
        la      $a0, palindrome                 # print palindrome
        li      $v0, 4
        syscall


end:
        li      $v0, 0          # return 0
        jr      $ra


.data
str0:
    .asciiz "Enter a line of input: "
palindrome:
    .asciiz "palindrome\n"
not_palindrome:
    .asciiz "not palindrome\n"


# line of input stored here
line:
    .space 256

