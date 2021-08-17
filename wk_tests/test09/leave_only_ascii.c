/*
Write a C program, leave_only_ascii.c, which takes one argument, a filename.

leave_only_ascii.c should remove all non-ASCII bytes from the file.

After it is run the file should contain only a ASCII bytes.

It should print nothing on stdout. It should only change the file.

Assume a byte is non-ASCII if it contains a value between 128..255 inclusive.
*/

#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char *filename = argv[1];
    // Open the file
    FILE *fp = fopen(filename, "r");
    
    // Copy all the contents from the file to another temp file
    FILE *tmp = fopen("temp", "w");
    int ch; 
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, tmp);
    }
    fclose(fp);
    fclose(tmp);

    // Reopen the files to write to 
    FILE *fp_wr = fopen(filename, "w");
    FILE *tmp_r = fopen("temp", "r");
    // Check the contents of temp file and write to the filename, skipping non-ascii characters
    int c;
    while ((c = fgetc(tmp_r)) != EOF) {
        // If ascii then add it else skip it
        if (!(c < 0 || c > 127)) {
            fputc(c, fp_wr);
        }
    }
    // Close the files
    fclose(tmp_r);
    fclose(fp_wr);
    return 0;
}

