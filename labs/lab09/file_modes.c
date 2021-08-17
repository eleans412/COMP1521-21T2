/*
We would like to print the access permissions for a set of files
Write a C program, file_modes.c, which is given one or more pathnames as command line arguments. 
It should print one line for each pathnames which gives the permissions of 
the file or directory.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

    // Check number of arguments
    // Needs to have at least one argument 
    if (argc < 1) {
        perror("incorrect number of arguments. Need 3 arguments\n");
        return 1;
    }
    int i = 1;
    // Loop to check all given files
    while (argv[i] != NULL) {
       
        struct stat st;

        if (stat(argv[i], &st) == -1) {
            perror("stat error");
            return 1;
        }

        // Format how we want to print this out 
        printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x" : "-");
        printf(" %s", argv[i]);
        printf("\n");
        i++;
    }
    
    return 0;
}