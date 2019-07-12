// smart pointer are wrapper classes implemented as templates (similar to vector etc..)
// u cannot do pointer arithmetic as with raw pointer
// they are following RAII concepts

/*-------------------------------------------------------------------------------------
    generaly:

  {
      std::smart_pointer<type> ptr {new type}
      ptr->attribute;
      ptr->method();
      std::cout << (*ptr) << std::endl;
  }
     here ptr will be automatically destroyed with the object it points to

--------------------------------------------------------------------------------------

std::unique_ptr<T>

 - points to type T on the heap
 - is unique, one heap object has only one unique ptr
 - cannot be assigned or copied
 - can be moved
 - owns the object it points to !!!
 - when destroyed, releases the memory it is pointing

*/

#include <memory>
#include <iostream>
#include <vector>

int main()
{
    {
        // old and bad way of making a new object on the heap
        int *p = new int(99);
        std::cout << *p << "\n"; // 99 - gets the value
        std::cout << p << "\n"; // gets the address 0x5567ab0a0e70

        // lets say i will save the memory address - just for fun
        //        #include <cstdint>
        //        uintptr_t address_p = 0x5567ab0a0e70;
        //        std::cout << address_p << "\n"; // prints the address in decimal value
        //        int value_p = *reinterpret_cast<int *>(p);
        //        std::cout << value_p << "\n"; // prints the address in decimal value

    }   // here p is destroyed, but the value 99 is still there in the heap ---> memory leak

    std::cout << "-----------------------" << "\n";

    {
        // better way using smart pointer but not the best practise (i need to call new)
        std::unique_ptr<int> int_ptr {new int {10}};
        if (!int_ptr) std::cout << "is null " << "\n";
        else std::cout << "is not null" << "\n";

        // the dereference operator works the same as raw pointer
        std::cout << *int_ptr << "\n"; // 10

        // get method gets the addres of the object that the ptr points to
        std::cout << int_ptr.get() << "\n";

        // assigning new value to the same object
        *int_ptr = 20;

        std::cout << *int_ptr << "\n"; // 20

        //reset method nulls the pointer
        int_ptr.reset();
        if (!int_ptr) std::cout << "is null " << "\n";
        else std::cout << "is not null" << "\n" ;

    } // int_ptr no longer existing in this scope, but the object it pointed to was deleted ---> no memory leak


            std::cout << "-----------------------" << "\n";

    {
        //since c++ 14 i should use std::make_unique function to initialize unique ptr
        std::unique_ptr<int> x = std::make_unique<int>(11);
        if (!x) std::cout << "is null " << "\n";
        else std::cout << "is not null" << "\n";

        // the dereference operator works the same as raw pointer
        std::cout << *x << "\n"; // 10

        // get method gets the addres of the object that the ptr points to
        std::cout << x.get() << "\n";

        // assigning new value to the same object
        *x = 22;

        // the dereference operator works the same as raw pointer
        std::cout << *x << "\n"; // 11

        //reset method nulls the pointer
        x.reset();
        if (!x) std::cout << "is null " << "\n";
        else std::cout << "is not null" << "\n" ;

    }

    return 0;
}

/*
conclusion:

    int *ptr {new int(42)}; // old bad way
    int *ptr {new int{42}}; // old bad way
    int *ptr = new int(42); // old bad way
    int *ptr = new int{42}; // old bad way

    std::unique_ptr<int> ptr {new int(42)}; // better way;
    std::unique_ptr<int> ptr {new int{42}}; // better way;
    std::unique_ptr<int> ptr = new int(42); // = sign not working !!

    std::unique_ptr<int> ptr {std::make_unique<int>(42)}; // best way
    std::unique_ptr<int> ptr = std::make_unique<int>(42); // best way
*/
