/*
Write a C program, non_ascii.c, which takes one argument, a filename.

It should print one line of output.

If the file contains a non-ASCII byte, non_ascii.c should print the location of the first non-ASCII byte. Use the same format as the example below.

If the file contains no non-ASCII byte non_ascii.c should print a message indicating this. Again use the same format as the example below.
*/

#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char *filename = argv[1];
    // Open the file
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("unable to open file");
        return 1; 
    }
    int ch;
    ch = fgetc(fp);
    int byte = 0; 
    while ((ch = fgetc(fp)) != EOF) {
        // If the byte was non-Ascii
        if ((ch < 0 || ch > 127)) {
            // Accounting for the first byte
            if (byte != 0) {
                byte++;
            }
            printf("%s: byte %d is non-ASCII\n", filename, byte);
            return 0;
        }
        byte++;
    }
    // Else print that everything was ASCII
    printf("%s is all ASCII\n", filename);
    fclose(fp);
    return 0;
}