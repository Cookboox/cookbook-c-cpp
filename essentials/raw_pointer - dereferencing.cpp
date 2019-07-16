#include <iostream>
#include <string>
#include <vector>

int main()
{
    int value {12};
    int *value_ptr {&value};

    //addresses
    std::cout << &value << "\n";
    std::cout << value_ptr << "\n";

    //values on that address
    std::cout << value << "\n";
    std::cout << *value_ptr << "\n"; // this is dereferencing --> getting the old value

    *value_ptr = 99; // this is dereferencing --> changing the old value for the new one

    //new values on that address
    std::cout << value << "\n";
    std::cout << *value_ptr << "\n";



    //-------------------------------------//

    double high_score {100};
    double advanced_score {85.5};
    double average_score {70.2};
    double low_score {64.3};

    auto *score_ptr = &low_score; // this guy can point to any of the above

    std::cout << *score_ptr << "\n"; // here i dereference and see the value it points to



    //-------------------------------------//

    std::string name = "john";
    std::string *name_ptr = &name;

    std::cout << *name_ptr << "\n"; //prints john

    name = "frank";

    std::cout << *name_ptr << "\n"; //same statemen;t, but now prints frank

    std::cout <<"-----------------------------------\n";




    std::vector<std::string> names {"paul", "mike", "dave", "brian"};
    std::vector<std::string> *names_ptr = &names;

    std::cout << (*names_ptr).at(0) << "\n";

    //print all the names directly
    for (auto const &i : names) std::cout << i << "\t";

    //print all the names indirectly using pointer
    for (auto const &i : *names_ptr) std::cout << i << "\t";
    for (size_t i = 0; i < names.size(); ++i) std::cout << (*names_ptr).at(i) << "\t";



    return 0;
}