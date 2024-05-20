#include "bit_operations_t11.h"
#include "utils.h"
#include <regex>
#include <iostream>
#include <bitset>

uint64_t bit_shift_odd_right(uint64_t number, int shift) {
    const uint64_t evenMask =  0x5555555555555555ULL;
    const uint64_t oddMask = ~evenMask;
    
    uint64_t oddBits = number & oddMask;
    uint64_t evenBits = number & evenMask;

    uint64_t shiftedOddBits = oddBits >> shift;
    uint64_t result = shiftedOddBits | evenBits;
    return result;
}

void task11(char* args[]){
    if(validArgs11(args)){
        uint64_t number = std::strtoull(args[2], nullptr, 10);
        int shift = std::atoi(args[3]);
        uint64_t result = bit_shift_odd_right(number, shift);
        std::cout << "Input  number: "<< number << std::endl;
        std::cout << "Input  binary: "<< std::bitset<64>(number) << std::endl;
        std::cout << "Result binary: "<< std::bitset<64>(result) << std::endl;
        std::cout << "Converted number: " << result << std::endl;
    }
}