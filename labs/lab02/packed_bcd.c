#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BCD_DIGITS 8

uint32_t packed_bcd(uint32_t packed_bcd);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= UINT32_MAX);
        uint32_t packed_bcd_value = l;

        printf("%lu\n", (unsigned long)packed_bcd(packed_bcd_value));
    }

    return 0;
}

// given a packed BCD encoded value between 0 .. 99999999
// return the corresponding integer
uint32_t packed_bcd(uint32_t packed_bcd_value) {


    int value = 0;
    int dec = 0;
    // Make sure that the loop does not go beyond the length of the packed_bcd_value
    int count = N_BCD_DIGITS - 1;

    // Loop until you reach 8 because this is how long the length of the packed
    // bcd is
    while (count >= 0) {
        // Shift the bcd value by 4 and the count (keeps the hierarchy of the values)
        // And with 0xF to get the value necessary for conversion
        // Shift to maintain position of the bit string
        dec = (packed_bcd_value >> (4 * count)) & 0xF;

        // Convert to decimal value
        // Add this to update the return value
        value = value * 10 + dec;
        
        // Repeat for the next bit in the packed_bcd_value
        count--;
    }
    return value;
}
