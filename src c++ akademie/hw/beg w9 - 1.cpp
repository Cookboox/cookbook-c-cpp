//1. Napi� jednoduch� program, kter� bude obsahovat t��du Animal. T��da obsahuje t�i �leny typu string name, species, a call.

#include<iostream>
#include<string>

class Animal
{
public:
    std::string name = "ferda";
    std::string species;
    std::string call;
};

struct Animal2
{
    std::string name;
    std::string species = "mravenec";
    std::string call;
};

Animal x;
Animal2 y;


int main()
{
    std::cout << x.name << '\n';
    std::cout << y.species << '\n';
    return 0;
}