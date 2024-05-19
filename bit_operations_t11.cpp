#include "bit_operations_t11.h"

#include <regex>
#include <iostream>

uint64_t bit_shift_odd_right(uint64_t number, int shift) {
    const unsigned int evenMask =  0b01010101010101010101010101010101;
    const unsigned int oddMask = 0b10101010101010101010101010101010;
    
    unsigned int oddBits = number & oddMask;
    unsigned int evenBits = number & evenMask;

    unsigned int shiftedOddBits = oddBits >> shift;
    uint64_t result = shiftedOddBits | evenBits;
    return result;
}