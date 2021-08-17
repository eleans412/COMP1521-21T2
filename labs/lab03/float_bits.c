// Extract the 3 parts of a float using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

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

// given the 3 components of a float
// return 1 if it is inf, 0 otherwise
int is_positive_infinity(float_components_t f) {

    // Infinity is where the exponent is all 1's and fraction is all 0's
    // 0 for positive sign
    int result = 0;
    if (f.sign == 0x00000000 && f.exponent == 0x000000ff && f.fraction == 0x00000000) {
        result = 1;
    }
    return result;
}

// given the 3 components of a float
// return 1 if it is -inf, 0 otherwise
int is_negative_infinity(float_components_t f) {

    int result = 0;
    // Infinity is where the exponent is all 1's
    // 1 for negative sign
    if (f.sign == 0x00000001 && f.exponent == 0x000000ff && f.fraction == 0x00000000) {
        result = 1;
    }
    return result;
}

// given the 3 components of a float
// return 1 if it is 0 or -0, 0 otherwise
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
