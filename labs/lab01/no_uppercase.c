#include <stdio.h>
#include <ctype.h>

int main(void) {
    
    // Continue running until EOF is called
    while (1) {
        // Declare variables that will store the converted characters
        // as well as receive the input
        int lower;
        int upper;
        upper = getchar();
        // If EOF is called end the program
        if (upper == EOF) {
            return 0;
        }
        // Otherwise, convert to lower case
        else {
            lower = tolower(upper);
            putchar(lower);
        }
        
    };

	return 0;
}
