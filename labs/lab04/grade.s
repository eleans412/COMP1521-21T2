# read a mark and print the corresponding UNSW grade

main:
    la          $a0, prompt    # printf("Enter a mark: ");
    li          $v0, 4
    syscall

    li          $v0, 5         # scanf("%d", mark);
    syscall
    move        $a0, $v0

    # If the mark is FAIL
    blt         $a0, 50, fail
    
    # If the mark is PASS
    blt         $a0, 65, pass

    
    # If the mark is CREDIT
    blt         $a0, 75, credit
    

    # If the mark is DIS
    blt         $a0, 85, dis
    

    # If the mark is HD
    ble         $a0, 100, highdis
    


fail: 
    la          $a0, fl        # printf("FL\n");
    li          $v0, 4
    syscall
    j           end 

pass:
    la          $a0, ps        # printf("PS\n");
    li          $v0, 4
    syscall
    j           end


credit:
        la      $a0, cr        # printf("CR\n");
        li      $v0, 4
        syscall
        j       end

dis:
        la      $a0, dn        # printf("DN\n");
        li      $v0, 4
        syscall
        j       end

highdis:
        la      $a0, hd        # printf("HD\n");
        li      $v0, 4
        syscall
        j        end


end:
        jr      $ra            # return

        .data

prompt:
        .asciiz "Enter a mark: "
fl:
        .asciiz "FL\n"
ps:
        .asciiz "PS\n"
cr:
        .asciiz "CR\n"
dn:
        .asciiz "DN\n"
hd:
        .asciiz "HD\n"


