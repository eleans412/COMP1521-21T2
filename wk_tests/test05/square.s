main:
        li      $v0, 5         #   scanf("%d", &x);
        syscall             #
        move    $t0, $v0

        li      $t1, 0         # t1 = i = 0

outer__while:
        bge     $t1, $t0, end

        li      $t2, 0         # t2 = j = 0

inner__while:
        bge     $t2, $t0, newline

        li      $a0, '*'      #   printf("*");
        li      $v0, 11
        syscall

        addi    $t2, $t2, 1
        j inner__while

newline:

        li      $a0, '\n'        #   printf("\n");
        li      $v0, 11
        syscall

        addi    $t1, $t1, 1 

        j outer__while 

end:

        li   $v0, 0         # return 0
        jr   $ra
