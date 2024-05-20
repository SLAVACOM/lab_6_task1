#include <cmath>
#include <string>
#include <iostream>

bool approximatelyEqual(double a, double b, double epsilon);
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);

void doApproximate(int countArgs, char* args[]);