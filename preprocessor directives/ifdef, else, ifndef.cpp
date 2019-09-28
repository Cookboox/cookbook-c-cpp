#include<iostream>

void macro()
{
#define NAME

#ifdef NAME
	std::cout << "yes\n";
#else
	std::cout << "no\n";
#endif 
}



void simple_macro()
{
#define WINDOWS 1
#define MAC 2
#define LINUX 3

#define OS WINDOWS

#if OS == WINDOWS
	std::cout << "compiling win\n";
#elif OS == MAC
	std::cout << "compiling mac\n"; 
#else 
	std::cout << "compiling linux\n";
#endif
}


void less_simple_macro()
{
#if !defined(WINDOWS) && !defined(MAC) && !defined(LINUX)
	#define WINDOWS 1
	#define MAC 2
	#define LINUX 3
#endif
	#define OS MAC

#if OS == WINDOWS
	std::cout << "compiling win\n";
#elif OS == MAC
	std::cout << "compiling mac\n";
#else 
	std::cout << "compiling linux\n";

#endif
}




int main()
{
	macro();
	simple_macro();
	less_simple_macro();






}