#include"approximate.h"
#include"utils.h"

using namespace std;

bool approximatelyEqual(double a, double b, double epsilon){
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
	float diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}


void doApproximate(int countArgs, char* args[]) {
	if(countArgs == 5){
		if(validArgsApproximate(countArgs, args)){
			double num1 = std::stof(args[2]);
			double num2 = std::stof(args[3]);
			double epsilon= std::stof(args[4]);
			cout << "Numbers: " << num1 << " and " <<num2 << (approximatelyEqual(num1, num2, epsilon) ? " equals" : " no equals") << endl;
		}
	}
	else if(countArgs == 6){
		if(validArgsApproximate(countArgs, args)){
			double num1 = std::stof(args[2]);
			double num2 = std::stof(args[3]);
			double absEpsilon = std::stof(args[4]);
			double relEpsilon= std::stof(args[5]);
			cout << "Numbers: " << num1 << " and " <<num2 << (approximatelyEqualAbsRel(num1, num2, absEpsilon, relEpsilon) ? " equals" : " no equals") << endl;
		}
	}else cerr<<"Incorrect arguments"<<endl;
}

