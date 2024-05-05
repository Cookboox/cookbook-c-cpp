#include<iostream>

int main()
{
    //********************************** SMARTPOINTERY **********************************
    //tri typy - 
    //unique_pointer, je zodpovednej za smazani dat, ktere drzi. vim kdo ty data vytvoril, a kdo je za ne zodpoveddnej
    //toto by mela bejt nase defaultni volba, je unikatni a neni kopirovatelnej, tj. nejde sdilet!!
    std::unique_ptr<int> up{ new int {9} }; //kdyz se odskopuje tak smaze data ktera drzi, ale porad muze leaknout pamet.. 
    std::cout << *up << '\n';
    auto upp{ std::make_unique<int>(99) }; //mnohem lepsi, neleakne pamet, stara se o dynamickou pamet. jde drzet v kontainerech.
    std::cout << *upp << '\n';
   
    //shared_pointer - je kopirovatelnej, tzn. ze na nekolika mistech muzu drzet pointer na ty stejny data (to u unique pointeru nejde),
    //ale aby dokazal smazat ty data ktery drzi, tak se musi smazat odevsad ze vsech mist kde byl. z unique_pointeru muzu dycky udelat shared_pointeru. 
    //naopak je to ale temer nemozny. kdyz budu z toho share pointeru chtit kopii, musim ho kopirovat s shared pointeru, kterej uz vlastnim.
    std::shared_ptr<int> sp{ new int {999} };
    std::cout << *sp << '\n';

    //weak_pointer - v mnoha ohledech je to shared pointer ale nezvysuje counter. musim ho dykcy vytvaret ze sharedpointeru a kdyz ho pouzivam tak z 
    //nej docasne vytvoarim shared_pointer
    std::weak_ptr<int>;

    //raw pointery - je potreba rozlisovat, jestli jsou owning, nebo non-owning, jesli vlastni data nebo ne. typicky v C-API, v C-knihovnach
    int i = 10;
    int *ptr = &i;
    std::cout << *ptr << '\n';
    
    /* std::observer<...*> - navrh standartu, ktery rika, ze pointer je nonowning
    gsl::owner<...*> - pointer, ktery jasne rika, ze ty data vlastnis, a mas je smazat*/

    //********************************* ITERATORY **********************************
    //.begin() - vrati iterator na zacatek containeru
    //.cbegin() - vrati konstatni iterator na zacatek containeru
    //.end() - vrati tzv. dangling interator na konci kontejneru
    //.cend() - vrati tzv. dangling constat interator na konci kontejneru

    std::cin.get();
    return 0;


}