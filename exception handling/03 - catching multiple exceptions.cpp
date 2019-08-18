#include <iostream>
#include <string>

//i need to have more than one catch block
// IMPORTANT!!! the types thrown needs to be different 

//function can throw:
// - zero division
// - negative numbers
double miles_per_km(char miles, double km)
{
	if (km == 0)
		throw 0;
	if (miles < 0 || km < 0)
		throw std::string{ "negative numbers not allowed\n" };
	if (miles == 'k')
		throw 'k';
	return miles / km;
}


int main()
{
	char miles{};
	double km{};
	double result{};

	std::cout << "how many miles?\n";
	std::cin >> miles;
	std::cout << "how many kilometers?\n";
	std::cin >> km;

	//exception handling
	try
	{
		result = miles_per_km(miles, km);
		std::cout << result << "\n";
	}
	catch (const int &e) // zero div catch
	{
		std::cout << "no division by zero allowed\n";
	}
	catch (const std::string& e) // negativ nr catch
	{
		std::cout << e;
	}
	catch (...) // whatever else catch
	{
		std::cout << "unknow exception\n";
	}

	return 0;
}