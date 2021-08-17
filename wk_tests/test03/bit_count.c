// count bits in a uint64_t

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

// return how many 1 bits value contains
int bit_count(uint64_t value) {

    // Loop through the bits of the value
    int count = 0;
    int mask = 0x01;
    // Shift the bits right to continue the loop until 
    // value is just 0
    while (value > 0x00) {
        // Check if the bit value is 1 
        // Use the and operation to extract bit to check this
        if ((value & mask) == 1) {
            count++;
        }
        // Shift one bit to the right
        value >>= 1;
    }
    
    return count;
}
