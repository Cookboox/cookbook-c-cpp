// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
	
	Savings_Account s;
	std::cout << s << "\n";

	Checking_Account c;
	std::cout << c << "\n";

	Account* p = new Trust_Account;
	std::cout << *p << "\n";

	s.deposit(1000);
	std::cout << s << "\n";
	s.withdraw(300);
	std::cout << s << *p << "\n";
	   
	std::cout << " \n\n------------DYNAMIC POLYMORPHISM----------------\n\n";
	   
	Account* ptr_sav1 = new Savings_Account{ "FirstSavingAccountOnHeap", 1000, 0.02 };
	Account* ptr_sav2 = new Savings_Account{ "Second¨SavingAccountOnHeap", 2000, 0.05 };

	Account* ptr_check1= new Checking_Account{ "FirstCheckingAccountOnHeap", 100 };
	Account* ptr_check2 = new Checking_Account{ "SecondCheckingAccountOnHeap", 200 };

	Account *ptr_trust1 = new Trust_Account{ "FirstTrustAccountOnHeap", 10000, 0.02 };
	Account* ptr_trust2 = new Trust_Account{ "SecondTrustAccountOnHeap", 20000, 0.05 };

	std::vector<Account*> va{ ptr_check1, ptr_check2, ptr_sav1, ptr_sav2, ptr_trust1, ptr_trust2 };

	display(va);
	deposit(va, 100);
	withdraw(va, 200);

	delete ptr_check1;
	delete ptr_check2;
	delete ptr_sav1;
	delete ptr_sav2;
	delete ptr_trust1;
	delete ptr_trust2;

	return 0;
}

