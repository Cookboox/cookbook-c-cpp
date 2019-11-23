#include <iostream>
#include <functional>
#include <map>
#include <variant>
#include <cassert>
#include <string>

//same return type and parameters for all
void jarda() { std::cout << "hi i am jarda\n";}
void pepa() { std::cout << "hi i am pepa\n"; }
void milan() { std::cout << "hi i am milan\n"; }

void map_functions1()
{
	std::function<void()> f_pepa = pepa;
	std::function<void()> f_milan = milan;
	std::function<void()> f_jarda = jarda;
	
	f_pepa();
	f_jarda();

	std::map<std::string, std::function<void()>> map_of_print_functions;
	map_of_print_functions.insert({ {"pepa",f_pepa}, {"milan",f_milan}, {"jarda",f_jarda} });
	map_of_print_functions.at("milan")();
	//alternatively
	map_of_print_functions["milan"]();
}

//different return types and params, but convetible
int add(int a, int b) { return a + b; }
int subtracts(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(double a, double b) { return a / b; }

void map_functions2()
{
	std::function<int(int, int)> f_add = add;
	std::function<int(int, int)> f_sub = subtracts;
	std::function<double(double, double)> f_div = divide;
	std::function<int(int, int)> f_mult = multiply;

	std::cout << f_add(100, 8) << "\n";
	std::cout << f_sub(100, 8) << "\n";
	std::cout << f_div(100, 8) << "\n";
	std::cout << f_mult(100, 8) << "\n";

	//cast to double - to wider type
	std::map<std::string, std::function<double(double, double)>> map_of_func{ {"add", f_add}, {"sub",f_sub}, {"div", f_div}, {"mult", f_mult} };
	std::cout << map_of_func["add"](100, 8) << "\n";
	std::cout << map_of_func["div"](100, 8) << "\n";

	for (auto i : map_of_func)
		std::cout << i.second(100, 8) << "\n";

	for(int i{}; i < 10; ++i)
		std::cout << map_of_func["add"](i, 10) << "\n";
}


//different types of params, the same return type
void one_arg(int a) { std::cout << a << "\n"; }
void two_args(int a, double b) { std::cout << a << " " << b << "\n"; }
void three_args(int a, double b, const char* c) { std::cout << a << " " << b << " " << c << "\n"; }

void map_functions3()
{
	//wrap up the functions to the same type
	std::function<void()> f_onearg = std::bind(one_arg, 10);
	std::function<void()> f_twoargs = std::bind(two_args, 10, 3.14);
	std::function<void()> f_threeargs = std::bind(three_args, 10, 3.14, "helo");

	//call one by one
	f_onearg();
	f_twoargs();
	f_threeargs();

	//map those functions to string keys
	std::map<std::string, std::function<void()>> map_of_func{ {"one", f_onearg}, {"two", f_twoargs}, {"three", f_threeargs} };

	//call oen by one
	map_of_func["one"]();
	map_of_func["two"]();	
	map_of_func["three"]();

	//call all in loop
	for (const auto& i : map_of_func) i.second();
}


//different types of params, different return types 
double divid(double a, double b) { return a / b; }
int addi(int a, int b) { return a + b; }
std::string prints(std::string s) { return s + s; }
bool iam() { return true; }

void map_functions4()
{
	//wrap plain old functions into class std::function<std::variant<double, int, std::string, bool>()>
	//i have four functions with 4 variants of return types, that is why std::variant<double, int, std::string, bool>()> is placeholder of return type
	std::function<std::variant<double, int, std::string, bool>()> f_divid = std::bind(divid, 100, 8);
	std::function<std::variant<double, int, std::string, bool>()> f_addi = std::bind(addi, 100, 8);
	std::function<std::variant<double, int, std::string, bool>()> f_prints = std::bind(prints, "something ");
	std::function<std::variant<double, int, std::string, bool>()> f_iam = std::bind(iam);

	std::variant<double, int, std::string, bool> ret; //placeholder for the return type
	
	ret  = f_divid(); //store the result from this function in it, which one of the 4 four types it will be? double
	auto result_of_devide = std::get<double>(ret); // that is why i use <double> as the type for std::get which will fetch the value (if i put different type, it will crash due to strong type safetyness)
	std::cout << result_of_devide << '\n';
	
	ret = f_prints(); //the same for others... 
	auto result_of_prints = std::get<std::string>(ret);
	std::cout << result_of_prints << '\n';
	
	ret = f_iam();
	auto result_of_iam = std::get<bool>(ret);
	std::cout << std::boolalpha << std::get<bool>(ret) << '\n';
	   
	//... do whatever.....

	//ok, now map those functions. string is the KEY and std::function with variant return types is VALUE
	std::map<std::string, std::function<std::variant<double, int, std::string, bool>()>> map_of_func;
	map_of_func.insert({ { "div", f_divid }, { "add", f_addi }, { "pr", f_prints }, {"iam", f_iam} }); //fill the map

	std::variant<double, int, std::string, bool> var = map_of_func["pr"](); //call a print function and store its result in variant
	auto var_value = std::get<std::string>(var); // it is supposed to be string 
	std::cout << var_value << '\n';

	//call all in loop (not in the same order as they are writen but based on lexicograhical key comparision)
	for (auto const& i : map_of_func)
	{
		var = i.second(); // second parametr in the map is the callable

		if		(std::get_if<double>(&var))			{ std::cout << std::get<double>(var) << '\n'; }
		else if (std::get_if<int>(&var))			{ std::cout << std::get<int>(var) << '\n'; }
		else if (std::get_if<std::string>(&var))	{ std::cout << std::get<std::string>(var) << '\n'; }
		else if (std::get_if<bool>(&var))			{ std::cout << std::get<bool>(var) << '\n'; }
	}
}

int main()
{

	map_functions4();


	return 0;
}
