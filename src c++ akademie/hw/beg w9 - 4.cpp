//4. Modifikuj pøedchozí program.Napiš dvì èlenské funkce.Funkce calls vrací èlen call, 
//funkce label vrací spojení èlenù species a name s mezerou uprostøed("Makak Tonda").


#include<iostream>
#include<string>

class Animal
{
private:
    std::string name;
    std::string species;
    std::string call;
public:
    Animal() { name = "Ferda"; species = "Mravenec"; call = "tadyto je neco co ma zavolat "; } //no args constructor
    std::string get_call() { return this->call; }
    std::string get_label() { return (this->name + " " + this->species); }
};

Animal x;

int main()
{

    std::cout << x.get_call() << '\n';
    std::cout << x.get_label() << '\n';
    return 0;
}