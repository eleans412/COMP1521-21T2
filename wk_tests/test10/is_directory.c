/*
Write a C program, is_directory.c, which takes one argument a pathname.

If the pathname exists and is a directory, it should print 1, otherwise it should print 0.

Written by Len Au
*/

#include <dirent.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    char *dir = argv[1];
    // Open the directory to see if it exists
    DIR* direc = opendir(dir);
    // If directory is found return true
    if (direc) {
        closedir(direc);
        printf("1\n");
    }
    // Otherwise return false if directory not found
    else {
        printf("0\n");
    }
    return 0;
}