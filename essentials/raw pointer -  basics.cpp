#include <iostream>
#include <string>


/*

 pointer is a variable whose value can be an addres. What can be at that address?
    1) another variable
    2) a function
    3) a class ?? can a pointer point to a class?

 general declaration:
    variable_ptr *ptr_name;

*/

int main() {

    // ptr can point to anything - primitive types, std classes, my defined classes

    //now they containg garbage - pointer pointing anywhere
    int *int_ptr;
    double *double_ptr;
    char *char_ptr;
    std::string *string_ptr;
    // myclass *myClass_ptr;

    // std::cout << char_ptr << "\n"; // nonsencial data


    // initializing a pointer
    int *int_ptr2 {};
    int *double_ptr2 {nullptr}; // c++ 11 nullptr = adress zero

   // std::cout << int_ptr2 << "\n"; //default init zero
   // std::cout << double_ptr2 << "\n"; //default init zero


    // pointers are variables and as other variables they sit somewhere in a memory.
    int *ptr {nullptr};
    //std::cout << ptr << "\n"; // print zero because it holds zero address
    //std::cout << &ptr << "\n"; // prints the address where it sits
    //std::cout << *ptr << "\n"; // nullptr (address zero) cannot be dereferenced

    int *ptr_to_twelve = new int(12);
    std::cout << ptr_to_twelve << "\n"; // prints the address of the 12 it points to
    std::cout << &ptr_to_twelve << "\n"; // prints the address the pointer itself sits
    std::cout << *ptr_to_twelve << "\n"; // can be dereferenced

    // pointer has always the same size, no matter where it points to
    // pointer to an int has the same size as pointer to a complex structure



    // ALLWAYS INITIALIZE YOUR POINTER !!
    // initialize them either to
    // 1) nullptr                               -- int *p {nullptr};
    // 2) a particular address                  -- int *p = &some_number;
    // 3) a particular address of heap          -- int *p = new int(some_number);




    // declaring a pointer to an int on a stack
    int i{10};
    std::cout << &i << "\n"; //print the address of i

    int *pi = &i;
    std::cout << pi << "\n"; // print the address of i
    std::cout << *pi << "\n"; // print the value of the object pi point to
    std::cout << sizeof(pi) << "\n"; // how many bytes a pointer takes
    std::cout << sizeof(i) << "\n";

    // declaring a pointer to a new int on heap
    int *pih = new int(43);
    std::cout << pih << "\n"; // print the address of i
    std::cout << *pih << "\n"; // print the value of the object pi point to
    std::cout << sizeof(pih) << "\n"; // how many bytes a pointer takes


    // making it more complicated -- declaring a pointer to a pointer
    int **ppih = &pih; //ppih now points to address where pih sits
    std::cout << &pih << "\n"; // address of pih
    std::cout << &*ppih << "\n"; // address that ppih holds / these two are the same
    //dereferencing a pointer to a pointer
    std::cout << *pih << "\n"; // the value pih points to
    std::cout << **ppih << "\n"; // the value ppih points to / these are the same


    return 0;
}