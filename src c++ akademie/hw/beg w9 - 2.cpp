//2. Modifikuj p�edchoz� program.Enkapsuluj datov� �leny, napi� jednoduch� konstruktor pro jejich inicializaci.


#include<iostream>
#include<string>

class Animal
{
private:
    std::string name;
    std::string species;
    std::string call;     
public:
    Animal() { name = "Ferda "; species = "Mravenec"; call = "tadyto je neco co ma zavolat "; } //no args constructor
};

Animal x;

int main()
{
    return 0;
}