#include <iostream>



class Deep
{
private:
	int* ptr;
public:
	//constructor
	Deep(int number)
	{
		this->ptr = new int(number);
		std::cout << "object constructed, allocated " << *this->ptr << " at address: " << this->ptr << "\n";
	}
	//copy constructor
	Deep(Deep const& source) : ptr{ new int(*source.ptr) } //this is where i make a pointer pointing to new memory address
	{
		//this->ptr = new int(*source.ptr); // alternativelly to list init
		std::cout << "copying object - value: " << *this->ptr << " at address: " << this->ptr << "\n";
	}
	//destructor
	~Deep() 
	{
		delete ptr;
		std::cout << "object destructed, deallocated \n";
	}

	void display_ptr_value() { std::cout << *this->ptr << "\n"; }
};


int main()
{
	Deep one(99);
	one.display_ptr_value();

	{
		Deep copy_one(one);
		copy_one.display_ptr_value();
	}

	one.display_ptr_value();

	return 0;
}