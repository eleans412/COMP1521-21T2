#include "sign_flip.h"

// given the 32 bits of a float return it with its sign flipped
uint32_t sign_flip(uint32_t f) {
    uint32_t result = 0x0;
    uint32_t sign = 0;
    uint32_t exp = 0;
    uint32_t frac = 0;

    // Separate the bits of the float so that
    // sign, exp and fraction are separate

    // Separate the fraction
    int frac_mask = 0x007fffff;
    frac = f & frac_mask; 

    f = f >> 23;
    // Separate the exponent
    int exp_mask = 0x000000ff;
    exp = f & exp_mask;

    f = f >> 8;
    // Separate the sign
    int sign_mask = 1;
    sign = f & sign_mask;

    // Negate the sign
    sign = ~sign;

    // Reassemble the float with the flipped sign (OR them together)
    // Set the sign
    result = sign;

    // Set the exponent
    result = result << 8;
    result = result | exp;

    // Set the fraction
    result = result << 23;
    result = result | frac;


    return result; 
}
