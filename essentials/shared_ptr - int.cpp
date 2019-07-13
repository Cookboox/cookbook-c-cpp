/*
 *      --- std::shared_ptr<T> ---
 *
 *  - points to object of type T on the heap
 *  - there can be may shared_ptr on the same object
 *  - can be assigned or copied
 *  - can be moved
 *  - doesnt support managing arrays
 *  - counter that holds the number of objects it points to --> ptr.use_count()
 */


#include <iostream>
#include <memory>
#include <vector>

int main() {

    {
        std::shared_ptr<int> p1 {new int{42}};
        std::cout << p1.use_count() << "\n"; // 1

        std::shared_ptr<int> p2 {p1}; // assigning p1 to p2 --> p1 and p2 both point to the same memory
        std::cout << p1.use_count() << "\n"; // 2
        std::cout << p2.use_count() << "\n"; // 2


        std::shared_ptr<int> p3 = p2;
        std::cout << p1.use_count() << "\n"; // 3
        std::cout << p2.use_count() << "\n"; // 3
        std::cout << p3.use_count() << "\n"; // 3

        std::shared_ptr<int> p4(p1);
        std::cout << p1.use_count() << "\n"; // 4
        std::cout << p2.use_count() << "\n"; // 4
        std::cout << p3.use_count() << "\n"; // 4
        std::cout << p3.use_count() << "\n"; // 4

        p1.reset(); // p1 becomes nullptr
        std::cout << p1.use_count() << "\n"; // 0
        std::cout << p2.use_count() << "\n"; // 3
        std::cout << p3.use_count() << "\n"; // 3
        std::cout << p3.use_count() << "\n"; // 3

    } // automatically deleted

std::cout << "------------------" << "\n";

    // shared_ptr and containers
    {

       std::vector<std::shared_ptr<int>> vec;
       std::shared_ptr<int> p {new int{134}};

       vec.push_back(p); // this is allowed since i have shared_ptr, for unique_ptr this is invalid

       std::cout << p.use_count() << "\n";

       for (size_t i = 0; i < 5; ++i) {vec.push_back(p);}
       std::cout << p.use_count() << "\n";

    }

std::cout << "------------------" << "\n";

    // better way is using make_shared
    {
        std::shared_ptr<int> ptr1 = std::make_shared<int>(99);
        std::shared_ptr<int> ptr2 {ptr1}; // copying
        std::shared_ptr<int> ptr3; // uninitialized --> nullptr

        std::cout << ptr1.use_count() << ", " << ptr2.use_count() << "\n";

        ptr3 = ptr1;

        std::cout << ptr1.use_count() << ", " << ptr2.use_count() << "\n";
    }



    return 0;
}

/*
 *
    ---------------------------------------------
    --- filling a vector with unique pointers ---
    ---------------------------------------------

    std::vector<std::unique_ptr<int>> vec;
    for (int i=0; i<5; ++i) vec.push_back(std::make_unique<int>(i+10));
    for (auto const &i : vec) std::cout << *i << "\n";



    ---------------------------------------------
    --- filling a vector with shared pointers ---
    ---------------------------------------------

    std::vector<std::shared_ptr<int>> vec;
    std::shared_ptr<int> ptr {new int(43)};

    for (int i = 0; i < 5; ++i) vec.push_back(ptr);
    for (auto const &i : vec) std::cout << *i << "\n";

 */