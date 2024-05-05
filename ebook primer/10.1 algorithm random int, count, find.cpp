#include <algorithm>
#include <iostream>
#include <random>
#include <list>
#include <string>



//fill the vec with random numbers and check, how many times each number is there.. 
void fill_the_vector()
{
    std::random_device device;
    std::mt19937 mt{ device() };
    std::uniform_int_distribution<int> distr{ 1, 10 };
    std::vector<int> v;

    for (int i = 0; i < 10; ++i)
    {
        v.push_back(distr(mt));
    }

    for (auto i : v)
    {
        std::cout << i << "\n";
    }

    int x = 4;
    int y = 5;

    std::cout << x << " is there "<< std::count(v.cbegin(), v.cend(), x) << " times " << "\n";
    std::cout << y << " is there " << std::count(v.cbegin(), v.cend(), y) << " times " << "\n";
}

//fill the list and check how many times each string is there.. 

void fill_the_listofstrings()
{
    std::list<std::string> l{ "jarda", "karel", "pepa", "pepa", "franta", "milda", "lukas" };

    for (auto i : l)
    {
        std::cout << i << "\n";
    }

    std::string x = "pepa";
    std::string y = "libor";

    std::cout << x << " is there " << std::count(l.cbegin(), l.cend(), x) << " times " << "\n";
    std::cout << y << " is there " << std::count(l.cbegin(), l.cend(), y) << " times " << "\n";

}





int main()
{
    fill_the_vector();
    fill_the_listofstrings();


    return 0;
}