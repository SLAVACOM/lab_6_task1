#include <iostream>
#include <cstdlib>

#include <Windows.h>

#include "bit_operations_t11.h"
#include "bit_operations_t12.h"
#include "approximate.h"
#include "utils.h"

using namespace std;

int main(int argc, char* argv[]) {

    string task = argv[1];
    
    if (argc == 4) {
        if(task == "task11")task11(argv);
        else if(task == "task12")task12(argv);
    } 
    else if (task == "approximate") doApproximatelyEqual(argc, argv);
    else {
        cerr<<"Incorrect task name!"<<endl;
        return 1;
    }
    return 0;
}
