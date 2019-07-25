#include <iostream>

//having the class Complex i want to display the object in form 4 + i6 using << operstor

class Complex
{
private:
	int real;
	int img;
public:
	Complex(int real = 0, int img = 0) : real{ real }, img{ img } {}
	Complex(Complex const& source) : real{ source.real }, img{ source.img } {}
	~Complex() {}

	//i can output it using this function
	void display()
	{
		std::cout << this->real << "+i" << this->img << "\n";
	}

	// to overload i need to rewrite the signature of the function just like for arithmetic operators
	// the function has three specifics:
	// 1) it takes two parames, ostrema object and the object of class and both need to be passed by reference. why? 
	// 2) the return type is ostream object again by reference. why? - this is the reference to the original ostream object so that you can combine insertions 
	// 3) it needs to be defined outside class, since it takes ostream which is not part of the class
	friend std::ostream& operator<<(std::ostream& output, Complex const& c); //i am using const because i just display it

	// the input stream overload is pretty much the same
	friend std::istream& operator>>(std::istream& input, Complex & c);
};

//this is the outside friend function
std::ostream& operator<<(std::ostream& output, Complex const& c) 
{
	return std::cout << c.real << "+i" << c.img; 
}


std::istream& operator>>(std::istream& input, Complex & c)
{
	return std::cin >> c.real >> c.img;
}



int main()
{
	Complex a{4,6};
	Complex copy_a{ a };

	//i can display, the point is i dont want to use this function, i want to use << directly
	a.display();
	std::cout << a << ", " << copy_a << "\n";

	std::cout << "-----------------\n";

	Complex user_input;
	std::cout << "enter the complex nr\n";
	std::cin >> user_input;
	std::cout << user_input;


	return 0;
}