/*
Write a C program, create_integers_file, which takes 3 arguments:

a filename,
the beginning of a range of integers, and
the end of a range of integers; 
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    // Arg[1] = filename
    // arg[2] = beginning of a range of integers
    // arg[3] = end of a range of integers

    // Check if correct number of arguments given
    if (argc < 3) {
        perror("incorrect number of arguments. Need 3 arguments\n");
    }

    // Open the text file 
    FILE *fp = fopen(argv[1], "w");

    if (fp == NULL) {
        perror("file could not be opened\n");
    }

    // Loop to input the integers into the file
    
    int beginning = atoi(argv[2]);
    int end = atoi(argv[3]);

    while (beginning <= end) {
        fprintf(fp, "%d", beginning);
        fprintf(fp, "\n");
        beginning++;
    }


    fclose(fp);
    return 0;

}