#include<iostream>
#include<cmath>
#include <iomanip>

//REQUIRES: aVal, bVal, and eVal must all be positive integers
//EFFECTS: Returns the difference between the C value 
// (A^E + B^E)^(1/E) and its nearest integer
std::pair<double, int> difference(const int aVal, const int bVal, const int eVal)
{
	const long double c = pow(pow(aVal, eVal) + pow(bVal, eVal), static_cast<double>(1.0 / eVal));
	return { abs(c - static_cast<int>(c)), c };
}

//Will loop through different exponents and integers 
//to determine which A^E + B^E = C^E comes closest 
//to satisfying Fermat's Last Theorem
int main(int argc, char* argv[])
{
	double bestMin = 1;
	int bestA = 0;
	int bestB = 0;
	int bestE = 0;

	//Argv[] -- 0:exec, 1:search_limit, 2:exponent_limit
	for (int e = 3; e < atoi(argv[2]); ++e)  //The choice of 6 and 5 was to eliminit obviously wrong solutions 
	{										 //that were simply close by a factor of some small number to the k
		for (int a = 2; a < atoi(argv[1]); ++a)
		{										
			for (int b = 1; b < a; ++b)
			{
				const std::pair<double, int> result = difference(a, b, e);
				const double min = result.first;
				if (min < bestMin && a != result.second && b != result.second)
				{
					bestMin = min;
					bestA = a;
					bestB = b;
					bestE = e;
					//std::cout << min << "\n";
				}
			}
		}
	}

	int cApprox = pow(pow(bestA, bestE) + pow(bestB, bestE), static_cast<double>(1.0 / bestE));

	std::cout << std::setprecision(50) << "Your closest match was the following: " << bestA << "^" << bestE << " + "
		<< bestB << "^" << bestE << " = " << cApprox
		<< "^" << bestE << std::endl << "Here's how close you got!\n" << pow(bestA, bestE) + pow(bestB, bestE) << std::endl
		<< pow(cApprox, bestE) << std::endl << "         ^     ^\n" 
											<< "       Calc   IPhone\n";

	return 0;
}
