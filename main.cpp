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
#include<iostream>
#include<cmath>
#include <iomanip>
#include <string>
#include <algorithm>


	//REQUIRES: Ints are both positive 
	//EFFECTS: Returns the first n digits in the two numbers that are identical
	int sameDigits(unsigned long long int num1, unsigned long long int num2, bool debug)
	{
		if (debug)
		{
			std::cout << "First number is " << num1 << "\n";
			std::cout << "Second number is " << num2 << "\n";
		}

		int count = 0;
		std::string str1(std::to_string(num1));
		std::string str2(std::to_string(num2));
		for (int i = 0; i < std::min(str1.length(), str2.length()); ++i)
		{
			if (str1.at(i) != str2.at(i)) break;
			count++;
		}

		if (debug) std::cout << "Count is " << count << "\n";

		return count;
	}


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
		int bestDigitCount = 0;
		int bestA = 0;
		int bestB = 0;
		int bestE = 0;
		bool debug = false;
		if (argc > 3) { if (std::string(argv[3]) == "debug") debug = true; }

		//Argv[] -- 0:exec, 1:search_limit, 2:exponent_limit, 3:debug (optional)
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
						const int digitCount = sameDigits(pow(result.second, e), pow(a, e) + pow(b, e), debug);
						if (digitCount > bestDigitCount)
						{
							bestDigitCount = digitCount;
							bestA = a;
							bestB = b;
							bestE = e;
						}
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
