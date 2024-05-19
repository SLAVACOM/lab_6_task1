#include "bit_operations_t12.h"

#include <regex>
#include <iostream>

uint64_t bit_shift_odd_left(uint64_t number,  int shift) {
    const uint64_t evenMask = 0x5555555555555555ULL; 
    uint64_t evenBits = number & evenMask;
    const int numBits = sizeof(number) * 8;

    uint64_t shiftedEvenBits = ((evenBits << shift) & evenMask) | ((evenBits >> (numBits - shift)) & evenMask);

    uint64_t oddBits = number & ~evenMask;

    uint64_t result = shiftedEvenBits | oddBits;
    return result;
}
