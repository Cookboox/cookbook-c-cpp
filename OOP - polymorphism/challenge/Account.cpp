#include "Account.h"
#include <iostream>

Account::Account(std::string name, double balance) : name{name}, balance{balance} {}

//pure virtual function - implemented
bool Account::deposit(double amount) 
{
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

//pure virtual function - implemented
bool Account::withdraw(double amount)
{
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

//pure virtual function from ABC Interface - implemented
void Account::print(std::ostream& os) const 
{
	std::cout << "[Account: " << this->name << ": " << this->balance << "]";
} 
