/*
Write a C program, print_bytes, 
which takes one argument, a filename, and which should should read the specifed file and print 
one line for each byte of the file. The line should show the byte in decimal and hexadecimal. 
If that byte is a an ASCII printable character, its ASCII value should also be printed.

Assume ASCII printable characters are those for which the ctype.h function isprint returns 
a non-zero value.
*/

#include <ctype.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

    // Check number of arguments
    // Needs to have at least one argument 
    if (argc < 1) {
        perror("incorrect number of arguments. Need 3 arguments\n");
    }

    // Open the file to read from 
    FILE *fp = fopen(argv[1], "r");

    // Read each character in the file
    int ch;
    long i = 0;
    while ((ch = fgetc(fp)) != EOF) {
        printf("byte ");
        printf("%4ld: ", i);
        // Not sure what is happening with those fancy characters. Not sure how to resolve this
        // Print the byte in decimal
        printf("%3d ", ch);
        // Print the byte in hex
        printf("0x%02x ", ch);
        // Check each character if they are ascii printable
        
        if (isprint(ch)) {
            // Print the character
            printf("'");
            fputc(ch, stdout);
            printf("'");
        }
        printf("\n");
        i++;
    }
    fclose(fp);
    return 0;
}