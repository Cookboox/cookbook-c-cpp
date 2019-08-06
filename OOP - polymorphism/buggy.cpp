#include <iostream>
#include <vector>
#include <memory>
#include <utility>

class Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in Account::withdraw\n"; }
};

class CheckingAccount : public Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in CheckingAccount::withdraw\n"; }
};

class SavingAccount : public Account 
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in SavingAccount::withdraw\n"; }
};

class TrustAccount : public Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in TrustAccount::withdraw\n"; }
};


int main()
{

	std::unique_ptr<Account> sp1{ std::make_unique<Account>() };
	std::unique_ptr<Account> sp2{ std::make_unique<CheckingAccount>() };
	std::unique_ptr<Account> sp3{ std::make_unique<SavingAccount>() };
	
	std::cout << "\n----ArrayOfSmart(unique)Pointers--------------\n";
	std::unique_ptr<Account> smart_arr_un[]{ std::move(sp1), std::move(sp2), std::move(sp3) }; //works ok
	for (size_t i = 0; i < sizeof(smart_arr_un) / sizeof(smart_arr_un[0]); ++i)
		smart_arr_un[i]->withdraw(100); 


	std::cout << "\n----VectorOfSmart(unique)Pointers--------------\n";
	//std::vector<std::unique_ptr<Account>> vec_uniq_ptr{ std::move(sp1), std::move(sp2), std::move(sp3)}; //does not work - i need to push back -- WHY?
	
	std::vector<std::unique_ptr<Account>> vec_uniq_ptr{ };
	vec_uniq_ptr.push_back(std::move(sp1));
	vec_uniq_ptr.push_back(std::move(sp2));
	vec_uniq_ptr.push_back(std::move(sp3));
	for (auto &i : vec_uniq_ptr)
		i->withdraw(100); // bug??

	return 0;
}