#include "bit_operations_t12.h"
#include "utils.h"

#include <regex>
#include <iostream>
#include <bitset>

uint64_t bit_shift_odd_left(uint64_t number,  int shift) {
    const uint64_t evenMask = 0x5555555555555555ULL; 
    const int numBits = sizeof(number) * 8;

    shift %=64;
    uint64_t evenBits = number & evenMask;

    uint64_t shiftedEvenBits = ((evenBits << shift) & evenMask) | ((evenBits >> (numBits - shift)) & evenMask);

    uint64_t oddBits = number & ~evenMask;

    uint64_t result = shiftedEvenBits | oddBits;
    return result;
}
void task12(char* args[]){
    if(validArgs12(args)){
        uint64_t number = std::strtoull(args[2], nullptr, 10);
        int shift = std::atoi(args[3]);
        uint64_t result = bit_shift_odd_left(number, shift);
        std::cout << "Input  number: "<< number << std::endl;
        std::cout << "Input  binary: "<< std::bitset<64>(number) << std::endl;
        std::cout << "Result binary: "<< std::bitset<64>(result) << std::endl;
        std::cout << "Converted number: " << result << std::endl;
    }
}