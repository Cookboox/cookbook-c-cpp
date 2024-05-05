//shufle the deck of card, every time new shuffle

#include <random>
#include <algorithm>
#include <iterator>
#include <array>
#include <iostream>



int main()
{





    std::array<int, 52> a;
    for (int i = 0; i < a.size(); ++i) a[i] = 1 + i;
    std::cout << "before shuffle: \n";  
    for (int i = 0; i < a.size(); ++i) std::cout << a[i] << "\n";

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(a.begin(), a.end(), g);

    std::cout << "\n after shuffle: \n";
    for (int i = 0; i < a.size(); ++i) std::cout << a[i] << "\n";
    return 0;



}
