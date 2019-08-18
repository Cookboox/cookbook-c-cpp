#include <iostream>

//stack unwinding is a process of looking for a exception handler
//if an exception is thrown but not caught in the current scope, c++ tries to find a handler in upper level

//KEYNOTES:
//function in which exception occurss either solves the exception by itself, or throw, is unwind and terminates
//the caller of the function either solves it, or is again unwind
//each time a catch block is checked for a matching exception type - if no catch block is matching, that means the function doesnt handles the exception, and function unwinds
//if exception is not handled in final main(), program terminates
//local variables are destroyed during unwinding --> RAII principle is critically important. objects needs to free the resources in their destructors !! 



//---------------------NO EXCEPTION --> NORMAL CONTROL FLOW----------------------/
//void f1();
//void f2();
//void f3();
//
//void f1()
//{
//	std::cout << "f1 started...\n";
//	f2();
//	std::cout << "f1 ended...\n";
//}
//
//void f2()
//{
//	std::cout << "f2 started...\n";
//	f3();
//	std::cout << "f2 ended...\n";
//}
//
//void f3()
//{
//	std::cout << "f3 started...\n";
//	std::cout << "f3 ended...\n";
//}
//
//
//int main()
//{
//	std::cout << "main started...\n";
//	f1();
//	std::cout << "main ended...\n";
//	
//	return 0;
//}


////--------------------- EXCEPTION IN F3, HANDLER IN MAIN --> ALL THE INTERMEDIATE CALLER WILL NOT BE FINISHED NORMALLY ----------------------/
//void f1();
//void f2();
//void f3();
//
//void f1()
//{
//	std::cout << "f1 started...\n";
//	f2();
//	std::cout << "f1 ended...\n";
//}
//
//void f2()
//{
//	std::cout << "f2 started...\n";
//	f3();
//	std::cout << "f2 ended...\n";
//}
//
//void f3()
//{
//	std::cout << "f3 started...\n";
//	throw 1;
//	std::cout << "f3 ended...\n";
//}
//
//
//int main()
//{
//	std::cout << "main started...\n";
//	try
//	{
//		f1();
//	}
//	catch (int& e)
//	{
//		std::cerr << "exception caught in main\n";
//	}
//
//	std::cout << "main ended...\n";
//
//	return 0;
//}



////--------------------- EXCEPTION IN F3, HANDLER IN F2, THE DIRECT CALLED --> ONLY THE F3 WHERE EXCEPTION OCCURS WILL NOT BE FINISHED NORMALLY ----------------------/
//void f1();
//void f2();
//void f3();
//
//void f1()
//{
//	std::cout << "f1 started...\n";
//	f2();
//	std::cout << "f1 ended...\n";
//}
//
//void f2()
//{
//	std::cout << "f2 started...\n";
//	try
//	{
//		f3();
//	}
//	catch(int &e) 
//	{
//		std::cerr << "exception caught in f2\n";
//	}
//	
//	std::cout << "f2 ended...\n";
//}
//
//void f3()
//{
//	std::cout << "f3 started...\n";
//	throw 1;
//	std::cout << "f3 ended...\n";
//}
//
//
//int main()
//{
//	std::cout << "main started...\n";
//	f1();
//	std::cout << "main ended...\n";
//
//	return 0;
//}



//--------------------- EXCEPTION IN F3, HANDLER IN F3 --> THE FUNCTION ITSELF HANDLES THE EXCEPTION --> ALL FUNCTIONS WILL END NORMALY ----------------------/
void f1();
void f2();
void f3();

void f1()
{
	std::cout << "f1 started...\n";
	f2();
	std::cout << "f1 ended...\n";
}

void f2()
{
	std::cout << "f2 started...\n";
	f3();
	std::cout << "f2 ended...\n";
}

void f3()
{
	std::cout << "f3 started...\n";
	try
	{
		//something..
		throw 1;
	}
	catch (int& e)
	{
		std::cerr << "exception caught in f3\n";
	}
	std::cout << "f3 ended...\n";
}


int main()
{
	std::cout << "main started...\n";
	f1();
	std::cout << "main ended...\n";

	return 0;
}
