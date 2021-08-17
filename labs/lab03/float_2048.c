// Multiply a float by 2048 using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

// float_2048 is given the bits of a float f as a uint32_t
// it uses bit operations and + to calculate f * 2048
// and returns the bits of this value as a uint32_t
//
// if the result is too large to be represented as a float +inf or -inf is returned
//
// if f is +0, -0, +inf or -inf, or Nan it is returned unchanged
//
// float_2048 assumes f is not a denormal number
//


// Have to separate the components, using the code from 
// float_2048 to generate the necessary components to complete this code

// separate out the 3 components of a float
float_components_t float_bits(uint32_t f) {

    uint32_t mask = 0;
    uint32_t flo = f;
    float_components_t section;
    // 0| 000 0000 0 |000 0000 0000 0000 0000 0000
    // There are 23 bits left in the float
    // Mask should be all 1's to extract the fraction value
    mask = 0x007fffff;
    section.fraction = (mask & flo);
    // Shift so that exponent is at the right most location
    flo >>= 23;
    // There are 8 bits for the exponent
    mask = 0x000000ff;
    section.exponent = (mask & flo);
    // Shift up again to get the sign
    flo >>=8;
    // There is 1 bit to represent the sign
    mask = 0x00000001;
    section.sign = (mask & flo);
    return section;
}


uint32_t combine_float(float_components_t f) {
    uint32_t result = 0;

    result = f.sign;
    // Shift to the next 8 bits to set them (set using or operation)
    result <<= 8;
    result |= f.exponent;
    result <<= 23;
    // Shift to the next 23 bits to set the fraction (using or operation)
    result |= f.fraction;

    return result;
}
// Using the is_nan, is_positive_infinity and is_negative_infinity
// to check if the result able to be represented as a float
// given the 3 components of a float
// return 1 if it is NaN, 0 otherwise
int is_nan(float_components_t f) {

    // If the trailing fraction is greater than the highest
    // number that floats can represent
    int result = 0;
    if (f.fraction != 0x00000000 && f.exponent == 0x000000ff) {
        result = 1;
    }

    return result;
}

int is_zero(float_components_t f) {

    int result = 0;
    // Because if the exponent is equivalent to 0
    // and if the trailing fraction bits are 0
    // the number is 0
    if (f.fraction == 0x00000000 && f.exponent == 0x00000000) {
        result = 1;
    }

    return result;
}

int is_infinity (float_components_t f) {
    // >= Because if the exponent was any larger than 1111 1111 it would still represent 
    // something greater than what can be represented
    // accounts for infinity, the negative and positive is just in the sign part
    // of the float
    int result = 0;
    // Infinity is where the exponent is all 1's
    // 1 for negative sign
    if (f.exponent >= 0x000000ff) {
        result = 1;
    }
    return result;
}


uint32_t float_2048(uint32_t f) {

    // Multiply using bit operations by 2048
    // Note that 2^11 = 2048
    // uint32_t result = result = (f << 11);

    // Have to break up f so that we can use the existing functions from
    // float_bits.c
    float_components_t flo = float_bits(f);

    // If the float is a nan, then return f in its original form
    if (is_nan(flo)) {
        return combine_float(flo);
    }
    // If the float made is not 0, then manipulate the exponent to multiply by
    // 2048
    if (is_zero(flo) != 1) {
        // Multiply by adding 11 to the exponent because 2^11 if 2048
        flo.exponent += 11;
    }

    // Check the exponent to check if +/- inf
    // Fraction is not checked here because this is checked in the is_nan
    // check
    if (is_infinity(flo) == 1) {
        flo.exponent = 0x000000ff;
        flo.fraction = 0x00000000;
    }
   // Combine the float back together after changes
    return combine_float(flo);
}
