//3. Modifikuj předchozí program.Explicitně smaž defaultní konstruktor, explicitně nastav defaultní destrukt.


#include<iostream>
#include<string>

class Animal
{
private:
    std::string name;
    std::string species;
    std::string call;
public:
    //Animal() = delete; //ERROR 'Animal::Animal(void)': member function already defined or declared, note: see declaration of 'Animal::Animal'
    Animal() { name = "Ferda "; species = "Mravenec"; call = " "; } //no args constructor
    //~Animal() = default; 
};

Animal x;

int main()
{
    //std::cout << x.name << x.species << '\n';
    return 0;
}