// swap pairs of bits of a 64-bit value, using bitwise operators

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

// return value with pairs of bits swapped
uint64_t bit_swap(uint64_t value) {

    // This is a 64 bit value
    // 4 -> 8
    // 8 -> 4
    // 5 -> a
    // a -> 5
    
    // Find the bits in the odd or even place after anding
    // Even mask looks at every other bit (i.e. 1010 1010...1010)
    // Odd mask looks at the other bits (i.e. 0101 0101...0101)
    uint64_t e_mask = 0xAAAAAAAAAAAAAAAA;
    uint64_t o_mask = 0x5555555555555555;
    uint64_t result = 0;

    uint64_t evens = e_mask & value;
    uint64_t odds = o_mask & value; 

    // Shift odd and even so the bits with values can be 
    // or-ed together
    evens >>= 1;
    odds <<= 1;

    // Combine even and odd to give the swapped final result
    result = (evens | odds);

    return result;


}
