#include <iostream>

//this is where the real exception handling comes into play..
//we have a function that does something and it has no idea how to handle potential exception --> so it must throw and hope, that other function or other part of code will handle

//function can throw so i need to catch it
double miles_per_km(double miles, double km)
{
	if (km == 0) 
		throw 0;
	return miles / km;	
}



int main()
{
	double miles{};
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
	catch(const int &e)
	{
		std::cout << "sorry, no division by zero\n";
	}
	

	return 0;
}