#include <iostream>
#include <cstdlib>

#include <Windows.h>

#include "bit_operations.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cerr << "Wrong command: " << argv[0] << " <number> <shift>" << endl;
        return 1;
    }
    if (!isValidFloat(argv[1])) {
        cerr << "Error: The argument of the number must be a valid floating point number." << endl;
        return 1;
    }

    if(!isValidShift(argv[2])){
        cerr << "Error: The shift argument must be an integer in the range from 0 to 64, not inclusive." << endl;
        return 1;
    }

    uint64_t number = std::strtoull(argv[1], nullptr, 10);
    int shift = std::atoi(argv[2]);

    uint64_t result = bit_shift_odd_right(number, shift);

    cout << "Input number: "<< number << endl;
    cout << "Converted number: " << result << endl;

    return 0;
}
