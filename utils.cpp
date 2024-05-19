#include "utils.h"


#include <regex>
#include <iostream>

bool isValidNumber(const char* str) {
    std::regex floatRegex("[1-9][0-9]*");
    return std::regex_match(str, floatRegex);
}

bool isValidShift(const char* str) {
    std::regex numberRegex("^([0-5]?[0-9]|6[0-3])$");
    return std::regex_match(str, numberRegex);
}