# read a number n and print the integers 1..n one per line

main:                 # int main(void)
        la          $a0, prompt  # printf("Enter a number: ");
        li          $v0, 4
        syscall

        li          $v0, 5       # scanf("%d", number);
        syscall
        move        $t1, $v0

        li          $t0, 1 # int i = 1

loop: 
        bgt         $t0, $t1, end # if (i == scanned num) goto end
        
        move        $a0, $t0 # printf("%d", i);
        li          $v0, 1 # prints integers
        syscall
        
        li          $a0, '\n'
        li          $v0, 11 # prints characters
        syscall

        addi        $t0, $t0, 1 # i++;
        j           loop

end:
        jr          $ra          # return

        .data
prompt:
        .asciiz "Enter a number: "
