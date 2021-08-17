// generate the opcode for an addi instruction

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "addi.h"

// return the MIPS opcode for addi $t,$s, i
uint32_t addi(int t, int s, int i) {
    // Set result to 0 to be manipulated 
    uint32_t result = 0x00000000;
    uint32_t mask = 0x20000000;
    uint32_t extractor = 0x0000ffff;

    if (i >= 0) {
        // Set the necessary bits from i
        result = result | i;
        // Shift t 16 spaces to get the 
        t = t << 16;
        // Set result from t
        result = result | t;
        s = s << 21;
        // Set result from s 
        result = result | s;
        result = result | mask;
    }
    else {
        // If i is less than 0, extract the relevant bits
        i = i & extractor;
        result = result | i;
        t = t << 16;
        // Set result from t
        result = result | t;
        s = s << 21;
        // Set result from s 
        result = result | s;
        result = result | mask;
    }

    return result; 

}
