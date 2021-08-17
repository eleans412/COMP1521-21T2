#  print the minimum of two integers
main:
        li          $v0, 5         #   scanf("%d", &x);
        syscall             #
        move        $t0, $v0

        li          $v0, 5         #   scanf("%d", &y);
        syscall             #
        move        $t1, $v0

        bge         $t0, $t1, main__if     # If x < y
        
        move        $a0, $t0        #   printf("%d\n", x);
        li          $v0, 1
        syscall
        li          $a0, '\n'      #   printf("%c", '\n');
        li          $v0, 11
        syscall

        j           end

main__if:
        move        $a0, $t1                #   printf("%d\n", y);
        li          $v0, 1
        syscall
        li          $a0, '\n'               #   printf("%c", '\n');
        li          $v0, 11
        syscall

        j   end


end:

        li          $v0, 0         # return 0
        jr          $ra
main:
        li      $v0, 5          #   scanf("%d", &x);
        syscall                 #
        move    $t0, $v0

        li      $v0, 5          #   scanf("%d", &y);
        syscall                 #
        move    $t1, $v0

        li      $t2, 0
        addi    $t2, $t0, 1                # int i = x + 1

        li      $t3, 13

main__while:
        bge     $t2, $t1, end               # while (i < y)

        bne     $t2, $t3, main__if           # if (i != 13)

        addi    $t2, $t2, 1                # i = i + 1;

        j       main__while

main__if:
        move    $a0, $t2        #   printf("%d\n", i);
        li      $v0, 1
        syscall
        li      $a0, '\n'      #   printf("%c", '\n');
        li      $v0, 11
        syscall

        addi    $t2, $t2, 1

        j       main__while

end:

        li      $v0, 0         # return 0
        jr       $ra
