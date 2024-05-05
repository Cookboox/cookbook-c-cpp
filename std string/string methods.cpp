#include <iostream>
#include <string>

 std::string s1 = "hello";
 std::string s2 = "world";

 void append()
 {
     std::string final;
     std::cout << final.append(s1) << "\n";

     std::cout << final.append(3, 'D') << "\n";


     


 }




int main()
{
    append();

   
    //std::cout << s1 << s2 << "\n";


    //



    ////lenght
    //std::cout << s1.length() << "\n"; 
   
    ////swap two strings
    //s1.swap(s2);
    //std::cout << s1 << s2 << "\n";

    ////check if empty
    //bool is_empty = s1.empty();
    //std::cout << std::boolalpha << is_empty << "\n";

    ////

	return 0;
}
