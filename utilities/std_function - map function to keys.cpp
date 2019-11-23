#include <iostream>
#include <functional>
#include <map>
#include <variant>
#include <cassert>

//same return type and parameters for all
void jarda() { std::cout << "hi i am jarda\n";}
void pepa() { std::cout << "hi i am pepa\n"; }
void milan() { std::cout << "hi i am milan\n"; }

void map_functions1()
{
	//functions cannot be delared inside other fuctions
	/*double divide(double a, double b)
	{
		return a / b;
	}

	void jarda()
	{
		std::cout << "hi i am  jarda\n";
	}

	void pepa()
	{
		std::cout << "hi i am pepa\n";
	}

	void milan()
	{
		std::cout << "hi i am milan\n";
	}*/

	//functors can be decla
	//lambda can be 

	std::function<void()> f_pepa = pepa;
	std::function<void()> f_milan = milan;
	std::function<void()> f_jarda = jarda;

	std::map<std::string, std::function<void()>> map_of_print_functions;
	map_of_print_functions.insert({ {"pepa",f_pepa}, {"milan",f_milan}, {"jarda",f_jarda} });
	map_of_print_functions.at("milan")();
	//alternatively
	map_of_print_functions["milan"]();
}

int add(int a, int b) { return a + b; }
int subtracts(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(double a, double b) { return a / b; }

//different return types and params, but convetible
void map_functions2()
{
	std::function<int(int, int)> f_add = add;
	std::function<int(int, int)> f_sub = subtracts;
	std::function<double(double, double)> f_div = divide;
	std::function<int(int, int)> f_mult = multiply;

	//std::cout << f_add(100, 8) << "\n";
	//std::cout << f_sub(100, 8) << "\n";
	//std::cout << f_div(100, 8) << "\n";
	//std::cout << f_mult(100, 8) << "\n";

	//cast to double - to wider type
	std::map<std::string, std::function<double(double, double)>> map_of_func{ {"add", f_add}, {"sub",f_sub}, {"div", f_div}, {"mult", f_mult} };
	std::cout << map_of_func["add"](100, 8) << "\n";
	std::cout << map_of_func["div"](100, 8) << "\n";

	for (auto i : map_of_func)
		std::cout << i.second(100, 8) << "\n";

	for(int i{}; i < 10; ++i)
		std::cout << map_of_func["add"](i, 10) << "\n";
}

