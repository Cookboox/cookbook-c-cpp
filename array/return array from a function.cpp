#include <iostream>

//incorrect - returning local variable
//int* return_array()
//{
//	int arr[5]{ 1,2,3,4,5 };
//	return arr;
//}

////correct - make it static
//int* return_array()
//{
//	static int arr[5]{ 1,2,3,4,5 };
//	return arr;
//}

//correct - make it on heap
//int* return_array()
//{
//	int* arr = new int[5];
//	for (int i{0}; i <= 5; ++i)
//		arr[i] = i;
//	return arr;
//}


//correct - make it global (nonlocal)
int A[5]{ };
int* return_array(int arr[])
{
	for (int i{}; i < 5; ++i)
	{
		arr[i] = i;
	}
	return arr;
}

int main()
{

	int* arr = return_array(A);

	for (int i{}; i < 5; ++i)
		std::cout << arr[i] << "\n";

	return 0;
}