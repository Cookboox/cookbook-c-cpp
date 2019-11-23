#include <iostream>
#include <string>
#include <functional>

//1] starting example --------------------------------------------------------------------------------------
//just print the value to the screen. 
template<typename T>
void print(const T& t)
{
	std::cout << t << '\n';
}

//template<typename T>
//std::string return_string(const T& t)
//{
//	std::stringstream ss; //make stream object
//	ss << t; // send the value to the stream object
//	return ss.str(); // make string out of the streamobject
//}


//2] example of VARIADIC TEMPLATE -----------------------------------------------------------------------------
// print whatever i passed - arbitrary number of parametrs
template<typename Type>
void display(const Type& t) { std::cout << t << '\n'; }

template<typename Type, typename... Args>
void display(const Type& t, const Args&... args)
{
	std::cout << t << '\n';
	display(args...);
}


//3] another example of VARIADIC TEMPLATE ------------------------------------------------------------------------
//concatenate whatever is pass using operator+ BUT the types must be the same :{
template<typename T>
T add(const T& x) //stop condition, when arg will be one
{
	return x;
} 

template<typename T, typename... Args>
T add(const T& x, Args... args) 
{
	return x + add(args...); //recursive call to add
}

template<typename T, typename... Args>
std::function<T(Args...)> f_add = add;



int main()
{
	display("hi", 881, 3.4);

	std::string one{ "retro" }, two{ "helo" }, three{"sada"};
	std::cout << add(one, two, three);
	   	  
	return 0;
}
