# Read a number and print positive multiples of 7 or 11 < n

main:                           # int main(void) {

    la          $a0, prompt   # printf("Enter a number: ");
    li           $v0, 4
    syscall

    li          $v0, 5         # scanf("%d", number);
    syscall
    move        $t1, $v0

    li          $t0, 1 # int i = 1

    li          $t4, 7
    li          $t5, 11


loop: 
    bge         $t0, $t1, end # if (i >= scanned num) goto end
    
    # If this is divisible by 7
    div         $t0, $t4
    mfhi        $t2 # $t2 = i % 7
    beq         $t2, 0, match_seven # if (i % 7 == 0) go match_seven

    # If this is divisible by 11
    div         $t0, $t5
    mfhi        $t3 # $t3 = i % 11
    beq         $t3, 0, match_eleven # if (i % 11 == 0) go match_eleven


    addi        $t0, $t0, 1 # i++;
    j           loop

match_seven:
    move        $a0, $t0 # printf("%d", i);
    li          $v0, 1 # prints integers
    syscall
    
    li          $a0, '\n'
    li          $v0, 11 # prints characters
    syscall

    addi        $t0, $t0, 1 # i++;

    j           loop

match_eleven:
    move        $a0, $t0 # printf("%d", i);
    li          $v0, 1 # prints integers
    syscall
    
    li          $a0, '\n'
    li          $v0, 11 # prints characters
    syscall

    addi        $t0, $t0, 1 # i++;

    j   loop

end:
    jr          $ra           # return

    .data
prompt:
    .asciiz "Enter a number: "
