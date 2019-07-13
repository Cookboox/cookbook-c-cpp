#include <iostream>
#include <memory>
#include <vector>


class Test
{
private:
    int data;
public:
    Test() {}
    Test(int data) {this->data = data;}
    int get_data() {return this->data;}

    ~Test(){std::cout << "destructor called for " << this->data << "\n";}
};

void foo(std::shared_ptr<Test> x)
{
    std::cout << "counter in the foo is: " << x.use_count() << "\n";
    std::cout << "value in the foo is: " << x->get_data() <<"\n";

} // here one object gets destroyed --> counter goes down


int main() {

    std::shared_ptr<Test> ptr1 = std::make_shared<Test>(100);
    std::cout << "counter in main block is " << ptr1.use_count() <<"\n"; // 1
    std::cout << "value in the main block is: " << ptr1->get_data() <<"\n"; // 100

    {
        std::shared_ptr<Test> ptr2 = ptr1;
        std::cout << "counter in nested block is: " << ptr2.use_count() <<"\n"; // 2
        std::cout << "value in the nested block is: " << ptr2->get_data() <<"\n"; // 100

    } // object holded by ptr2 gets destroyed --> counter goes down

    std::cout << "counter after nested block is : " << ptr1.use_count() <<"\n"; // 1
    std::cout << "value in the nested block is: " << ptr1->get_data() <<"\n"; // 100

    foo(ptr1);
    std::cout << "counter after foo call is : " << ptr1.use_count() <<"\n"; // 1

    ptr1.reset(); // destructor called for 100

    std::cout << "counter after reset is : " << ptr1.use_count() <<"\n";

    return 0;
}