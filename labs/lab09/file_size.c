/*
We are worried about disk usage and would like to know how much space is used used by a set of files
Write a C program, file_sizes.c, which is given one or more filenames as command line arguments. 
It should print one line for each filename which gives the size in bytes of the file. 
It should also print a line giving the combined number of bytes in the files.

*/
#include <stdio.h>
#include <sys/stat.h>


int main (int argc, char *argv[]) {

    // Check number of arguments
    // Needs to have at least one argument 
    if (argc < 1) {
        perror("incorrect number of arguments. Need 3 arguments\n");
        return 1;
    }

    
    int i = 1;
    double total = 0;
    // Loop to check all given files
    while (argv[i] != NULL) {
        double byte_size = 0;
        
        struct stat st;
        stat(argv[i], &st);

        if (stat(argv[i], &st) == -1) {
            perror("stat error");
            return 1;
        }

        byte_size = st.st_size;

        // Print to terminal
        printf("%s: %ld bytes\n", argv[i], st.st_size);
        total = total + byte_size;
        i++;
    }
    
    printf("Total: %.0f bytes\n", total);
    return 0;
}

