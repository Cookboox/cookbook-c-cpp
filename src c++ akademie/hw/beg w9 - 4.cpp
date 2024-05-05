//4. Modifikuj p�edchoz� program.Napi� dv� �lensk� funkce.Funkce calls vrac� �len call, 
//funkce label vrac� spojen� �len� species a name s mezerou uprost�ed("Makak Tonda").


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