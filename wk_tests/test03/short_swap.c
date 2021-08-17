// Swap bytes of a short

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// given uint16_t value return the value with its bytes swapped
uint16_t short_swap(uint16_t value) {

    // Swap the 2nd with the 4th hex - there are 16 bits
    // So need to create 2 masks for each byte
    // Need to join the masks with an and operation
    int f_mask = 0xff00;
    int s_mask = 0x00ff;
    int swapped = 0x0000;

    // Extract the values from the 2nd bit in the hex
    f_mask = f_mask & value;
    
    // Extract the values from the 4th bit in the hex
    s_mask = s_mask & value;

    // Shift the mask so they are in the swapped areas
    f_mask >>= 8;
    s_mask <<= 8;

    // or this together so the final value has the swapped values
    swapped = swapped | f_mask;
    swapped = swapped | s_mask;

    return swapped;
}
