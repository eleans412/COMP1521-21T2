/*
Write a C program, compare_file.c, which takes two arguments, both filenames.

compare_file.c should print one line of output.

If the two files are different compare_file.c should print the location of the first byte whether they differ. Use the same format as the example below.

If the one file is shorter than the other but the bytes it contains are identical to the other file, compare_file.c should print a message indicating this. Use the same format as the example below.

If the 2 files contain exactly the same bytes compare_file.c should print a message indicating this. Again use the same format as the example below.
*/
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char *file1 = argv[1];
    char *file2 = argv[2];


    // Open file 1
    FILE *fp1 = fopen(file1, "r");
    // Open file 2
    FILE *fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        perror("unable to open file\n");
        return 1;
    }
    int ch1 = getc(fp1);
    int ch2 = getc(fp2);
    int byte = 0;
    while (ch1 != EOF && ch2 != EOF && (ch1 == ch2)) {
        ch1 = getc(fp1);
        ch2 = getc(fp2);  
        byte++;
    }

    // If there is an EOF, stop and print which file has the EOF
    if (ch1 == EOF && ch1 != ch2) {
        printf("EOF on %s\n", file1);
        return 0;
    }
    if (ch2 == EOF && ch1 != ch2) {
        printf("EOF on %s\n", file2);
        return 0;
    }

    // If the files are differet print the location of where they differ
    if (ch1 == ch2) {
        printf("Files are identical\n");
    }
    // Else print that they are not identical
    else {
        printf("Files differ at byte %d\n", byte);
    }   

    fclose(fp1);
    fclose(fp2);
    return 0;
}