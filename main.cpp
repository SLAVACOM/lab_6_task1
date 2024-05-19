#include <iostream>
#include <cstdlib>

#include <Windows.h>

#include "bit_operations_t11.h"
#include "bit_operations_t12.h"
#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 4) {
        cerr << "Wrong command: " << argv[0] << " <number> <shift>" << endl;
        return 1;
    }

    if (!isValidNumber(argv[2])) {
        cerr << "Error: The argument of the number must be a valid floating point number." << endl;
        return 1;
    }

    if(!isValidShift(argv[3])){
        cerr << "Error: The shift argument must be an integer in the range from 0 to 64, not inclusive." << endl;
        return 1;
    }

    string task = argv[1];
    uint64_t number = std::strtoull(argv[2], nullptr, 10);
    int shift = std::atoi(argv[3]);
    uint64_t result;
    if(task == "task11"){
        result = bit_shift_odd_right(number, shift);
    } else if(task == "task12"){
        result = bit_shift_odd_left(number, shift);
    } else {
        cerr<<"Incorrect task name!"<<endl;
        return 1;
    }
    cout << "Input number: "<< number << endl;
    cout << "Converted number: " << result << endl;

    return 0;
}
