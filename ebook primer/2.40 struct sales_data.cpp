
#include<iostream>
#include<string>


struct Sales_data
{
    std::string book_name;
    std::string book_isbn;
    unsigned int year_of_release{2000};
    unsigned int units_sold{11};
    double price{10};
};

Sales_data test;

int main()
{
    std::cout << test.book_name << test.book_isbn << test.year_of_release << test.units_sold << test.price << '\n';

    return 0;
}