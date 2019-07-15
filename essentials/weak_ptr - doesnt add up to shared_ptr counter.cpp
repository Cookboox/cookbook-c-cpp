#include <iostream>
#include <memory>

// weak ptr never adds up to shared ptr counter

int main() {

    std::shared_ptr<int> ptr(new int(1234));

    std::cout << *ptr <<"\n";
    std::cout << ptr.use_count() <<"\n"; // 1

    std::weak_ptr<int> ptr_w1(ptr); // making a weak ptr from a shared pointer doesnt add up to shared pointer counter
    std::cout << ptr.use_count() <<"\n";  // still 1!!!
    std::cout << ptr_w1.use_count() <<"\n"; // also 1
    // std::cout << *ptr_w1 << "\n"; // i cannot dereference weak pointer, i have to use lock
    std::cout << *ptr_w1.lock() << "\n"; // lock check if the object stil exists, if so, it returns shared_ptr to it --> so we can dereference it
    if (ptr_w1.lock()) {std::cout << "pointer validni" << "\n";}


    std::weak_ptr<int> ptr_w2(ptr_w1); // making a weak ptr from weak ptr is available, no add up to shared pointer counter
    std::cout << ptr.use_count() <<"\n";  // still 1 !!!
    std::cout << ptr_w1.use_count() <<"\n"; // also 1
    std::cout << ptr_w2.use_count() <<"\n"; // also 1
    std::cout << ptr_w1.expired() << "\n";

    ptr_w2.reset();
    std::cout << ptr.use_count() <<"\n";  // still 1!!!
    std::cout << ptr_w1.use_count() <<"\n"; // also 1
    std::cout << "expired? " << ptr_w2.use_count() <<"\n"; // now zero

    ptr.reset();
    std::cout << ptr.use_count() <<"\n";  // all zeroed out
    std::cout << ptr_w1.use_count() <<"\n"; // all zero
    std::cout << ptr_w2.use_count() <<"\n"; // zero


    return 0;
}