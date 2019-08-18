#include <iostream>

//exception handling should be used only for synchronys conde, not asynchronous
//it is all about how to deal with exceptional state
//what causes exceptional state?
//-insufficient resources (memory..)
//-missing resources (file not found..)
//-invalid operations (devided by zero..)
//-range violation (out of bound..)
//-underflow or overflow (?)

//exception safe code handles all exception --> extremely difficult with c++ 
//exception is an object of primitivet type signalizing an error has occured

//two parts:
//1) throwing an exception
//an error occured in some part of program that doesnt know how to deal with it --> it throws and hopes other part of the program catch it and solves it
//2) catching an exception
//code that handles the exception --> may or may not cause the terminantion of the program

//three keywords:
//1) throw - throws an exception, followed by an argument
//2) try {code that may throw exception } - in try block is a vulnerable code. if it throws, the block is exited and control flow goes to the catch block, if no cathc block exist, program terminates
//3) catch {code that handles exception} - may terminate or not, multiple cathc blocks are allowed


void no_exception_handler()
{
	double miles{};
	double km{};
	double miles_per_km{};

	std::cout << "how many miles?\n";
	std::cin >> miles;
	std::cout << "how many kilometers?\n";
	std::cin >> km;

	//classicall if to skip the problematic piece
	if (km == 0)
		std::cerr << "division by zero not allowed\n";
	else
	{
		miles_per_km = miles / km;
		std::cout << miles_per_km << "\n";
	}	
}


void exception_handler()
{
	double miles{};
	double km{};
	double miles_per_km{};

	std::cout << "how many miles?\n";
	std::cin >> miles;
	std::cout << "how many kilometers?\n";
	std::cin >> km;

	try
	{
		if (km == 0)
			throw 0; //here i am throwing and all other parts of the try block will be skipped --> it will look for a catch block, it it is there, ok, if not, program terminates
		else
		{
			miles_per_km = miles / km;
			std::cout << miles_per_km << "\n";
		}			
	}
	catch(int &e) //catching the same type by reference
	{
		std::cerr << "division by zero not allowed\n";
	}
}


int main()
{
	no_exception_handler();
	exception_handler();

	return 0;
}