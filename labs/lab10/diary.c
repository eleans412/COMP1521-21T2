/*
Write a C program, diary.c, which appends 1 line to $HOME/.diary.
The line should be its command-line arguments separated by a space followed by a '\n'.
diary.c should print nothing on stdout. It should only append to $HOME/.diary.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
    // Open the file

    // Get the file name and path
    char *home_path_name = getenv("HOME");
    char *diary = ".diary";

    int len = strlen(home_path_name) + strlen(diary) + 2;
    char *path_name = malloc(len);
    snprintf(path_name, len, "%s/%s", home_path_name, diary);

    // Open file to append to
    FILE *fp = fopen(path_name, "a");

    // Error checking
    if (fp == NULL) {
        perror("unable to open file\n");
    }

    // Loop to add all the command line arguments
    // to the diary file
    int i = 1;
    while (argv[i] != NULL) {
        fprintf(fp, "%s", argv[i]);
        fprintf(fp, "%s", " ");
        i++;
    }
    // New line character after entering all the arguments
    fprintf(fp, "%s", "\n");

    // Close the file
    fclose(fp);
    return 0;
}