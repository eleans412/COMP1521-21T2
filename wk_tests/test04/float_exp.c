#include "float_exp.h"

// given the 32 bits of a float return the exponent
uint32_t float_exp(uint32_t f) {
    uint32_t exp = 0;
    uint32_t mask = 0xff; // 8 bits in the exponent

    // Shift the bits til the exponent is at the rightmost end
    // And this with the mask to extract the exp
    // Shift 23 because this is the number of bits in fraction
    f = f >> 23; 
    exp = mask & f;
    
    return exp; 
}
