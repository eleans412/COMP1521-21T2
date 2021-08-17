/*

Write a C program, create_binary_file, which takes at least one argument: 
a filename, and subsequently, integers in the range 0…255 inclusive specifying byte values. 
It should create a file of the specified name, containing the specified bytes.

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    //argv[1] = filename

    // Check number of arguments
    // Needs to have at least one argument 
    if (argc < 1) {
        perror("incorrect number of arguments. Need 3 arguments\n");
    }

    // Check that the integers input are within the range of 0-255
    int check_counter = 0;
    int integer_check = 2;
    while (check_counter < argc) {
        if (atoi(argv[integer_check]) < 0 || atoi(argv[integer_check]) > 255) {
            perror("Numbers not in the range of 0..255\n");
        }
        check_counter++;
    }
    

    // Check if the file is binary or a txt file
    // Open the text file 
    FILE *fp = fopen(argv[1], "wb");

    if (fp == NULL) {
        perror("file could not be opened\n");
        return 1;
    }

    // Input the ints into the file
    int i = 2;
    while (argv[i] != NULL) {
        fputc(atoi(argv[i]), fp);
        i++;
    }
    
    
    // Close the file
    fclose(fp);
    return 0;
}