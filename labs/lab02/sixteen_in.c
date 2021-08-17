// Convert string of binary digits to 16-bit signed integer

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define N_BITS 16

int16_t sixteen_in(char *bits);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        printf("%d\n", sixteen_in(argv[arg]));
    }

    return 0;
}

//
// given a string of binary digits ('1' and '0')
// return the corresponding signed 16 bit integer
//
int16_t sixteen_in(char *bits) {

    // Ensure the type returned is 16 bits
    int16_t decimal = 0;
    int i = 0;

    // Loop until looped through each bit in this bit string
    while (i < N_BITS) {
        // if there is a set value in the bit string, convert this to decimal form
        // Ignore if it is a 0 because this has no value in conversions
        if (bits[i] == '1') {
            // Shift to the next bit and or this to the existing value
            decimal |= 1 << (N_BITS - i - 1);
        }
        i++;
    }
    return decimal;
}

