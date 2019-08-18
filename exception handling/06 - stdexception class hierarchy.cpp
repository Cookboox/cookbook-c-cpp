#include <iostream>
#include <exception>

//c++ provides a class hierarchy of exception classes
//std::exception is base class and all subclasses implement the what() virtual function -- (virtual const char *what() const noexcept;)

//class hierarchy - https://prnt.sc/oqw9j7 - we can derive from these and all we have to do is to implement what()


//mz exception that inherited..
class IllegalBallanceException : public std::exception
{
private:
	//code..
public:
	//code..
	virtual char const* what() const noexcept { return "this is illegal ballance ecxeption"; }
};

int main()
{



	return 0;
}