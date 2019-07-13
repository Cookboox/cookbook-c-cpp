#include <iostream>
#include <memory>
#include <vector>


class Test
{
private:
    int data;
public:
    Test(): data{0} {std::cout << "no args constructor for " << data << "\n";}
    Test(int d): data {d} {std::cout << "one arg constructor for " << data << "\n";}
    int get_data() {return this->data;}
    ~Test() {std::cout << "destructor called " << data << "\n";}
};


int main() {

    if (true)
    {
        Test t1{100};
        Test t2{};
    }  // on the stack so here it will be removed


    if (true)
    {
        Test *t1 = new Test{100};
        Test *t2 = new Test{};
    } // on the heap and no delete was called ---> leak


    if (true)
    {
        Test *t1 = new Test{100};
        Test *t2 = new Test{};

        delete t1;
        delete t2;
    } // explicitly deleted ---> no leak


    if (true)
    {
        std::unique_ptr<Test> t1 {new Test{111}};
        std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
        std::unique_ptr<Test> t3 = std::make_unique<Test>();
        auto t4 = std::make_unique<Test>(99);
    } // DESTRUCTOR AUTOMATICALLY CALLED


    if (true)
    {
        std::unique_ptr<Test> ptr1 = std::make_unique<Test>(42);
        std::unique_ptr<Test> ptr2;
        if(!ptr1) {std::cout << "ptr1 is now null" << "\n";} else {std::cout << "ptr1 holds value" << "\n";}

        // assignement not allowed!! - coping not allowed either
        // ptr2 = ptr1;

        // but we can transfer the ownership with move
        std::unique_ptr<Test> ptr3 = std::move(ptr1);
        if(!ptr1) {std::cout << "ptr1 is now null" << "\n";} else {std::cout << "ptr1 holds value" << "\n";}
        std::cout << ptr3->get_data() << "\n";
    }

    if (true)
    {
        std::vector<std::unique_ptr<Test>> tests;

        // generating pointer to objects on the heap
        for (size_t i = 0; i < 5; ++i)
        {
            tests.push_back(std::make_unique<Test>(i+1000000));
        }

        for (auto const &i: tests) // for loop is copying that is why i need to do const ref
        {
            std::cout << "object contains this value: " << i->get_data() << "\n";
        }
    }


    return 0;
}