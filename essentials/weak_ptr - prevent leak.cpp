/*
 *  std::weak_ptr<T>
 *
 * - point to an object of type T on the heap
 * - provides non-owing "weak" reference
 * - always created from a std::shared_ptr !!!
 * - does not have any reference counter
 * - used to prevent reference cycles
 * --------------------------------------------
 * - strong cycle reference : A refers to B with shared_ptr and B refers to A with shared_ptr
 * - solution? make A refer to B with shared_ptr and B refers to A with weak_ptr *
 */

#include <iostream>
#include <memory>

class B;

class A
{
private:
    std::weak_ptr<B> ptr_to_b;
public:
    A(){std::cout << "A constructor " <<"\n";}
    ~A(){std::cout << "A destructor " <<"\n";}

    // weird signature right? - this is actually a reference to the pointer, so something like int &*ptr
    void set_reference(std::shared_ptr<B> &b)
    {
        this->ptr_to_b = b;
    }
};

class B
{
private:
    std::weak_ptr<A> ptr_to_a; // make it weak to avoid strong cirle reference
public:
    B(){std::cout << "B constructor " <<"\n";}
    ~B(){std::cout << "B destructor " <<"\n";}

    void set_reference(std::shared_ptr<A> &a)
    {
        this->ptr_to_a = a;
    }
};


int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>(); // no leak because B doesnt own A

    a->set_reference(b);
    b->set_reference(a);

    return 0;
}