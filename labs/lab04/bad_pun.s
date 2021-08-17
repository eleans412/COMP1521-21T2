# MIPS program that is the equivalent to bad_pun.c
main:
        la          $a0, string # load the string
        li          $v0, 4 # print the string
        syscall

        li          $a0, '\n'
        li          $v0, 11
        syscall

        li          $v0, 0
        jr          $ra

        .data

string:
        .asciiz "I MIPS you!"
