#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int bcd(int bcd_value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= 0x0909);
        int bcd_value = l;

        printf("%d\n", bcd(bcd_value));
    }

    return 0;
}

// given a  BCD encoded value between 0 .. 99
// return corresponding integer
int bcd(int bcd_value) {

    // Find the size of the int and multiply by 2 so that the correct number of digits
    // are extracted
    int size_of_dec = sizeof(bcd_value) * 2;

    // Get the value of the end digit and it so that we have the correct 
    // value ready for conversion
    // And to get the value of the ones decimal column
    int ones = bcd_value & 0xF;
    // Shift to get the start digit and it so in the right form
    // for conversion
    // And to get the value of the tens decimal column
    int tens = (bcd_value >> size_of_dec) & 0xF;
    // Combine the digits for conversion
    int value = tens * 10 + ones;
    return value;
}

