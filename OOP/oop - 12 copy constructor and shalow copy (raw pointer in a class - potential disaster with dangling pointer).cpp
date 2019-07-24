#include <iostream>


// having a raw pointer in a class 
// - constructor allocates memory dynamically and sets the pointer 
// - destructor releases the memory (it has to be done manually!!)
// - but default copy constructor copies only the pointer and NOT the data it points to
// - !!! PROBLEM !!! is that after relasing the memory from the source object or from the copied object (based on which one was destructed first),
// the other one still points to the same location which is now deleted --> danglic pointer

class Shallow 
{
private:
	int *ptr;
public:
	// simple constructor - here i cannot us init list
	Shallow(int number) : ptr{ new int(number) }
	{
		//this->ptr = new int(number); //alternativelly
		std::cout << "object constructed, allocated " << *this->ptr << " at address: " << this->ptr << "\n"; 
	}
	// copy constructor 
	Shallow(Shallow const &source) : ptr{source.ptr}
	{
		std::cout << "copying object - value: " << *this->ptr << " at address: " << this->ptr << "\n";
	}
	//destructor
	~Shallow()
	{
		delete ptr;
		std::cout << "object destructed, deallocated \n";
	}
	
	void display_ptr_value() { std::cout << *this->ptr << "\n"; }

};



int main()
{
	Shallow one(1);
	one.display_ptr_value();

	{
		Shallow copy_one{ one };
		copy_one.display_ptr_value();
	} //here it gets deleted --> one will still be pointing to an invalid address

	one.display_ptr_value(); // using invalid memory now!! --> i get the garbage data

	return 0;
}