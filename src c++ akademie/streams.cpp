#include<iostream>
#include<fstream> //souborovy vstupni a vystupni proudy

#include<sstream> //neni za tim zadny vstupni nebo vytupni medium, jen je za nim nejakej string v pameti 
//bude mit lepsi praci s pameti, kdyz concatenuju vice stringu
//muzu z neja zapisovat i z nej cist. je to specialni proudovej objekt, slouzici k formatovani nejakych interaktivnich proudu

#include<iomanip>   //manipulatory cpp:manipulators


int main()
{
    std::ofstream ofs{ "C:\\dev\\testing.txt" }; // vystupni souborovej proud
    ofs << "hello" << "\n";
  
         


    return 0;
}