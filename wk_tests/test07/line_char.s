#  read a line from stdin and and then an integer n
#  Print the character in the nth-position

# n in $t0

main:
        la      $a0, str0               # printf("Enter a line of input: ");
        li      $v0, 4
        syscall

        la      $a0, line               # fgets(buffer, 256, stdin)
        la      $a1, 256                # Each character allocated 1 BYTE space 
        li      $v0, 8
        syscall

        la      $a0, str1               # printf("Enter a position: ");
        li      $v0, 4
        syscall

        li      $v0, 5                  # scanf("%d");
        syscall
        move    $t0, $v0                # t0: n

        la      $t1, line
        add     $t2, $t0, $t1           # Find the location of the charcter at line[n]

        la      $a0, str2               # printf("Character is: ");
        li      $v0, 4
        syscall


        lb      $a0, ($t2)              # printf("%c", n);
        li      $v0, 11           
        syscall


        li      $a0, '\n'               # printf("%c", '\n');
        li      $v0, 11
        syscall

        li      $v0, 0                  # return 0
        jr      $ra

.data
str0:
    .asciiz "Enter a line of input: "
str1:
    .asciiz "Enter a position: "
str2:
    .asciiz "Character is: "


# line of input stored here
line:
    .space 256

