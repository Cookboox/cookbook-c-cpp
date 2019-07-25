#include <iostream>

//operator overloading is syntactic sugar, behind the scenes we still call functions

//when we use raw pointers in a class we need to provide our our version of = operator
//asignemt operator is the only one that the compiler provides default behaviour for
//except these five all operators can be overloaded (::, :*, :?, ., sizeof)

//---RULES---
//u cannot change precendence and associativity of operators
//u cannot change "arity" (binary needs to stya binary, unary needs to stay unary)
//u cannot change the bahaviour with build in types (+ stays + with numbers)
//u cannot create new operator that are not used in c++ now
//these four operators must be implemented as member methods only (->, [], (), =)
//all other operators can be implemented either as member methods, or as global functions

//lets say i have a class Complex and i want to do some math with it (i need to overload arithmetic operators)
//i also want to do console output (i need to overload << operator)
//i also want to do comparision (i need to overload logical operators <, >, =)

class Complex
{
private:
	double real;
	double img;
public:
	Complex(double real = 0, double img = 0) : real{ real }, img{ img } { }
	Complex(Complex const& source) : real{ source.real }, img{ source.img } {}
	~Complex() {}

	double get_real() { return this->real; }
	double get_img() { return this->img; }

	// operator overloading is basicaly a function that is sort of special - suppose i want to use + operator, that is the same as function add. 
	// so i will write add function
	Complex add(Complex x)
	{
		Complex temp;
		temp.real = this->real + x.real; // real part is a sum of real part of this object and real part of the passed object x
		temp.img = this->img + x.img; // img part is a sum of img part of this object and img part of the passed object x
		return temp;
	}

	// this is completely the same function except the name is now operator+
	// this is how i overloaded + operator
	//Complex operator+(Complex x)
	//{
	//	Complex temp;
	//	temp.real = this->real + x.real; // real part is a sum of real part of this object and real part of the passed object x
	//	temp.img = this->img + x.img; // img part is a sum of img part of this object and img part of the passed object x
	//	return temp;
	//}

	//now i can do the same for all other aritmetic operators..

	//subtraction
	Complex operator-(Complex x)
	{
		Complex temp;
		temp.real = this->real - x.real; 
		temp.img = this->img - x.img; 
		return temp;
	}

	//multiplication
	Complex operator*(Complex x)
	{
		Complex temp;
		temp.real = this->real * x.real;
		temp.img = this->img * x.img; 
		return temp;
	}

	//division
	Complex operator/(Complex x)
	{
		Complex temp;
		temp.real = this->real / x.real; 
		temp.img = this->img / x.img; 
		return temp;
	}

	//the same can be done with the help of outside friend function
	friend Complex operator+(Complex a, Complex b);

};

Complex operator+(Complex a, Complex b)
{
	Complex result;
	result.real = a.real + b.real;
	result.img = a.img + b.img;
	return result;
}





int main()
{
	Complex c1{ 3, 16 };
	Complex c2{ 2, 5 };
	Complex c3;

	//the function add in class Complex will now allow me to do something like this
	c3 = c1.add(c2);
	std::cout << c3.get_real() << ", " << c3.get_img() << "\n";

	std::cout << "-------------------\n";

	//but the point is that i dont want to use a function - i want to use operator (+) i want this thing: c3 = c1 + c2 
	//how to do it? simply change the name of te function from add to operator+
	c3 = c1 + c2;
	std::cout << c3.get_real() << ", " << c3.get_img() << "\n";

	c3 = c1 - c2;
	std::cout << c3.get_real() << ", " << c3.get_img() << "\n";

	c3 = c1 * c2;
	std::cout << c3.get_real() << ", " << c3.get_img() << "\n";

	c3 = c1 / c2;
	std::cout << c3.get_real() << ", " << c3.get_img() << "\n";
	


	return 0;
}