#include "bit_rotate.h"

// return the value bits rotated left n_rotations
uint16_t bit_rotate(int n_rotations, uint16_t bits) {
    uint16_t result = 0;

    // Have the mask so that it can AND with the number of rotations
    // sizeof only gives the size in BYTES, have to multiply this by 8
    // to get the correct size we are looking for 
    int mask = (8 * sizeof(bits)) - 1;

    // And mask and rotations
    n_rotations = n_rotations & mask;

    // Shift bits the number of rotations neccessary
    result = (bits << (n_rotations));
    
    // Combine the shifted bits with the bits that have been shifted that
    // otherwise would have disappeared in the shift
    result = result | (bits >> (-n_rotations & mask));

    return result; 
}
