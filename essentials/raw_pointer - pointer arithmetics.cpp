#include <iostream>

void print_values_using_arr_signature()
{
	int arr[]{ 92, 45, 34, 6, 77, 0 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "address: " << arr + i << "\t" << "value: " << *(arr + i) << "\n";
	}

	//while (*arr != 0)
	//{
	//	std::cout << "address: " << arr << "\t" << "value: " << *arr << "\n";
	//	arr++; // compile error ++ needs l-value
	//}
}

void print_values_using_ptr_signature()
{
	int arr[]{ 92, 45, 34, 6, 77, 0 };
	int* arr_ptr{ arr };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "address: " << arr_ptr + i << "\t" << "value: " << *(arr_ptr + i) << "\n";
	}


	while (*arr_ptr != 0)
	{
		std::cout << "address: " << arr_ptr << "\t" << "value: " << *arr_ptr << "\n";
		arr_ptr++;
	}


	while (*arr_ptr != 0)
	{
		std::cout << "address: " << arr_ptr << "\t" << "value: " << *arr_ptr++ << "\n"; //better then previous
	}


}






int main()
{
	print_values_using_arr_signature();
	std::cout << "---------------\n";
	print_values_using_ptr_signature();


	return 0;
}