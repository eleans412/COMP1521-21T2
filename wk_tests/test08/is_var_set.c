/*
Write a C program, is_var_set.c, which 
takes one argument, the name of environment variable

If the environment variable is set to a non-empty string, 
it should print 1, otherwise it should print 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *env;
    env = getenv(argv[1]);
    if (env != NULL && strcmp(env, "") != 0) {
        printf("1\n");
        return 1;
    }

    // If the environment variable is empty
    printf("0\n");
    return 0;
    
}
