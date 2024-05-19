#include "utils.h"


#include <regex>
#include <iostream>

bool isValidNumber(const char* str) {
    std::regex numberRegex("[1-9][0-9]*");
    return std::regex_match(str, numberRegex);
}

bool isValidShift(const char* str) {
    std::regex shiftRegex("^([0-5]?[0-9]|6[0-3])$");
    return std::regex_match(str, shiftRegex);
}




bool validArgs11_12(char* args[]){
    if (!isValidNumber(args[2])) {
        std::cerr << "Error: The argument of the number must be a valid floating point number." << std::endl;
        return false;
    }
    if(!isValidShift(args[3])){
        std::cerr << "Error: The shift argument must be an integer in the range from 0 to 64, not inclusive." << std::endl;
        return false;
    }
    return true;
}
