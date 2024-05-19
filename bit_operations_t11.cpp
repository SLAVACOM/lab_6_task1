#include "bit_operations_t11.h"
#include "utils.h"
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

void task11(char* args[]){
    if(validArgs11_12(args)){
        uint64_t number = std::strtoull(args[2], nullptr, 10);
        int shift = std::atoi(args[3]);
        uint64_t result = bit_shift_odd_right(number, shift);
        std::cout << "Input number: "<< number << std::endl;
        std::cout << "Converted number: " << result << std::endl;
    }
}