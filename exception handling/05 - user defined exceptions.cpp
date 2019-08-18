#include <iostream>

//best practise is:
//throw objects not primitives
//throw by value and catch by (const) reference


class DivideByZeroError{};
class NegativeValueError{};

double miles_per_km(double miles, double km)
{
	if (km == 0) throw DivideByZeroError();
	if (miles < 0 || km < 0) throw NegativeValueError();
	return miles / km;
}


int main()
{
	double miles{};
	double km{};
	double result{};

	std::cout << "how many miles\n";
	std::cin >> miles;
	std::cout << "how many km\n";
	std::cin >> km;

	try
	{
		result = miles_per_km(miles, km);
		std::cerr << "result is: " << result << "\n";
	}
	catch (const DivideByZeroError& e)
	{
		std::cout << "u cant devide by zero\n";
	}
	catch (const NegativeValueError& e)
	{
		std::cerr << "u cant provide negative values\n";
	}

	return 0;
}