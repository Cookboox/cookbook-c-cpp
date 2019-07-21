#include <iostream>



int main()
{
	int a = 1;
	int& aref = a; 
	int& arefref = aref; //reference to a reference

	std::cout << "address a: " << &a << " value a: "<< a << "\n";
	std::cout << "address aref: " << &a << " value aref: " << aref << "\n";
	std::cout << "address arefef: " << &a << " value arefref: " << arefref << "\n";

	int* aptr = &a;
	int* aptref = &aref; //pointer to a reference
	int& arefptr = aptr; //reference to a pointer is invalid

	std::cout << "address aptr: " << aptr << " value aptr: " << *aptr << "\n";
	std::cout << "address aptref: " << aptref << " value aptr: " << *aptref << "\n";

	
	return 0;
}