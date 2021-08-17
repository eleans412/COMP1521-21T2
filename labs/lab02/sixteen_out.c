// Convert a 16-bit signed integer to a string of binary digits

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BITS 16

char *sixteen_out(int16_t value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= INT16_MIN && l <= INT16_MAX);
        int16_t value = l;

        char *bits = sixteen_out(value);
        printf("%s\n", bits);

        free(bits);
    }

    return 0;
}

// given a signed 16 bit integer
// return a null-terminated string of 16 binary digits ('1' and '0')
// storage for string is allocated using malloc
char *sixteen_out(int16_t value) {

    
    // Malloc storage for the string (array of chars)
    char *conversion = malloc((N_BITS + 1) * sizeof(char));
    
    // Initalise a counter
    int i = 0;

    
    while (i < N_BITS) {
        // Check if this bit digit would be set
        // And the value to see if it will derive a value other than 0
        // Initialise the comparison for value anding
        int16_t comparison =  1 << (N_BITS - i - 1);
        // If the anding results in a number other than 0, input a 1 in 
        // this position
        if ((value & comparison) != 0) {
            conversion[i] = '1';
        }
        // If the anding does not derive a value, put a 0 in the string space
        else {
            conversion[i] = '0';
        }
        i++;
    }
    // Ensure there is a NULL terminator at the end of the bit string
    conversion[N_BITS] = '\0';
    return conversion;

}

