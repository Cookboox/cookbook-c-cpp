#include <iostream>
#include <memory>

class Base
{
public:
    //making the foo virtual so that in base class pointer derived class object the derived will be called
    virtual void foo()
    {
        std::cout << "this is a function of a Base class" << "\n";
    }
};

class Derived:public Base
{
public:
    void foo() override //for explicity i call it overiride
    {
        std::cout << "this is a function of a Derived class" << "\n";
    }
};


int main()
{

    //making two regular objects
    Base b;
    b.foo(); //prints "this is a function of a Base class"

    Derived d;
    d.foo(); //prints "this is a function of a Derived class"

    //but here is the point - when i make base class pointer derived class object
    Base *ptr = new Derived;
    ptr->foo(); // the derived class foo will be call because i have the word virtual in base
}