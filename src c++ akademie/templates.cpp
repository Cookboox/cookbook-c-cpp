#include<iostream>

//
///********* SABLONY *********/
//
////sablony pouzivam kdyz chci funkcionalitu uzitou pro jakejkoliv datovej typ. sablonovat muzu foo, nebo class.
////udelam to takle:
//
////template < > //muzou byt pazdne, ale neni to typicky
//template <typename T> //T je placeholder, T, S, U, V se pouzivaji typicky, budu li ale sablonovat na specifickym objektem, pak je doby placeholder pojmenovat ... muzu pracovat i s &T, T* apod.
//int size(T const &item) 
//{
//    return sizeof(item);
//}
//
////vsechno co v te sablone delam musi byt legalni operace..
////mam li sablonu a zaroven nejaky nesablonovy petizeni. prvni co se kompilator pokusi zjistit je perfect match. tedy ze nejaka funkce mimo sablonu presne sedi, kdyz nesedi tak se pokusi vytvorit foo z T
////s tim souvis tzv. SFINAE - selhani specializace neni chyba - kompilator se snazi do sablony nasadit nejaky typy a kdyz neuspeje, neni to chyba a kompilace jede dal
//
////sablonovat muzu vice typu, a muzu uvnitr jedne sablony mit dalsi sablony..
//template <typename T, typename S> 
//int size(T const &item)
//{
//    return sizeof(item);
//}
////sablony maji takovu vlastnost ze jejich definice MUSI prijit do hlavicky (.H) !! potrebuje mit kompletni definici ty T funkce pro kazdou prekladovou jednotku - jde samozrejme vozit hlavicku ktera obsahuje dafinici do hlavniho .H soubou
////klasickou foo napisu hlavicku - tu dam tdo .H a definici napisu do zdrojovyho souboru
////muzu predat defaultni hodnoty, ale musim ty defaultni mit
//template <template T = int, std::size_t S = 1>
//
////nekdy je potreba explicitni specializace - tzn. ze nad konkretni sablonou mu reknu jak to nasablonovat -
//template <>  //absolutni specializace - prazdny diamant jmenny prostor std nedovoli nic pridavat. jedina vyjimka je absolutni specializace, kupr chci upravit jak pacuji algoritmy pro std::vector SCOTT MAYERS EFFECTIVE STL
//int size<bool>(bool const &intem) //kazdej ten parametr sablony kterej chci explicitne specializovat, tak musim napsat
//{
//    //
//}
//
////problemtictejsi je sablonovat pro T, ktery je slozitejsi, kupr. trida ktera uvnitr sebe ktera ma uvnitr sebe nejaky odvozeny datovy typy (kupr iteratory) 
////kdyz mam datovej typ, kterej neodpovida tomu, co po nem ta sablona chce, selze kompilace
////je mozny udelat ze Template se sepne jenom na urcity traity (char/w_char/char_32) .. vynutim tim selhani specializace .. SFINAE (neni to chyba) .. 
//
///************* ELIPSY = VARIADY *************/
//
////potrebuju nejakej pocet argumentu,ale nevim dopredu kolik
////elipsis symbol jsou ... (tri tecky) ty patri DYCKY  za KOMPLETNI nazev datoveho typu
//template <typename T ...>
//int size(T const &... item)
//{
//    //cecovej postup
//    va_start();
//    va_arg();
//    return sizeof(item);
//    //{item.. } inicializacni seznam 
//
//}
////variadicky funkce muzu napsat jak nad variadickou sablonou, tak nad normalni
//
////makra - funcki makra se hodne pouzivaji v testovacich frameworcich. pro makro je VSECHNO RETEZEC
////#define vypada to jako funkce ale neni to funkce
//// 
//#define TRACE(x) (xxx) // funkce ktera prijme jakykoliv x, bez ohledu na typ - define je tedy typove nebezpecny
//#define TRACE(...) //toto makro je ochotny prijmout libovolne mnozstvi parametru
//    "__VA_ARGS__" //ty argumenty lze jenom udelat do uvozovek a udelat tak z toho retezec..
//
//


#include<string>


template<typename T, typename S>  //typename std::enable_if_t < std::is_floating_point<T>{} && std::is_floating_point<S>{}, bool type = true
    T add(T const &lhv, S const &rhv) //kdyz dam double.. nebo je mozne pouzit std::enable_is
    {
        return static_cast<T>(lhv + rhv);
    }

template<>//pretizenej absolutni template
int add<int, int> (int const &lhv, int const &rhv)
{
    std::cout << "here" << '\n';
    return lhv + rhv;
}

int main()
{
    std::cout << add(2, 3) << '\n';
    std::cout << add(2.4, 3.4) << '\n';
    std::cout << add(2.3, 3) << '\n';
    std::cout << add(2, 3.4) << '\n';
    std::cout << add(std::string{ "hello " }, std::string{ "world" }) << '\n';
       

    std::cin.get();
    return 0;
}