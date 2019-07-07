#include<iostream>

//array can be passe to functions just as reugular parameter, but THEY CAN BE PASSED ONLY BY ADDRES, NEVER BY VALUE - address is a pointer to the first element in array 


// this function takes an array and print its values - better to use CONST modifier to be more explicit
//void print_the_arr_values(int arr[], int size_of_arr) // same as void change_the_arr_values(int *arr, int size_of_arr) since array is always passed by addres
//{
//	for (int i = 0; i < size_of_arr; ++i) 
//	{
//		std::cout << arr[i] << "\n"; 
//	}
//}
//
//// this function takes an array and revrites it values - cannot be used with CONST modifier
//void change_the_arr_values(int arr[], int size_of_arr)
//{
//	for (int i = 0; i < size_of_arr; ++i) 
//	{ 
//		arr[i] = 99;
//		std::cout << arr[i] << "\n";
//	}
//}


void change_the_arr_values_2(int arr[])
{
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) // sizeof(arr)/sizeof(int) determines the elements of array
	{
		arr[i] = 77;
		std::cout << arr[i] << "\n";
	}
}


int main()
{
	int arr[] = { 10, 20, 30, 40, 50};

	/*print_the_arr_values(arr, 5);
	change_the_arr_values(arr, 5);*/

	change_the_arr_values_2(arr);



	std::cout << sizeof(arr) / sizeof(int);

	return 0;
}