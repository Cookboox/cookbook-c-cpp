#include <iostream>
#include <vector>
#include <memory>

//in order to use dynamic binding at runtime, we need to have
// 1) inheritence hierarchy
// 2) base class pointer or base class reference
// 3) virtual functions in base class

// !! virtual functions are dynamically bound only when we call them via bas class pointer or reference, otherwise they are statically bound !!

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
	std::cout << "\n----RawPointers--------------\n";
	Account* p1 = new Account();
	Account* p2 = new CheckingAccount();
	Account* p3 = new SavingAccount();
	Account* p4 = new TrustAccount();

	p1->withdraw(1);
	p2->withdraw(1);
	p3->withdraw(1);
	p4->withdraw(1);

	std::cout << "\n----Smart(unique)Pointers--------------\n";
	std::unique_ptr<Account> sp1{ std::make_unique<Account>() };
	std::unique_ptr<Account> sp2{ std::make_unique<CheckingAccount>() };
	std::unique_ptr<Account> sp3{ std::make_unique<SavingAccount>() };
	std::unique_ptr<Account> sp4{ std::make_unique<TrustAccount>() };

	sp1->withdraw(1);
	sp2->withdraw(1);
	sp3->withdraw(1);
	sp4->withdraw(1);

	std::cout << "\n----Smart(shared)Pointers--------------\n";
	std::shared_ptr<Account> sps1{ std::make_shared<Account>() };
	std::shared_ptr<Account> sps2{ std::make_shared<CheckingAccount>() };
	std::shared_ptr<Account> sps3{ std::make_shared<SavingAccount>() };
	std::shared_ptr<Account> sps4{ std::make_shared<TrustAccount>() };

	sps1->withdraw(1);
	sps2->withdraw(1);
	sps3->withdraw(1);
	sps4->withdraw(1);

	std::cout << "\n----ArrayOfRawPointers--------------\n";
	Account* arr[]{ p1,p2,p3,p4 };
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		arr[i]->withdraw(1);

	std::cout << "\n----VectorOfRawPointers--------------\n";
	std::vector<Account*> vec_raw_ptr{ p1,p2,p3,p4 };
	for (auto const& i : vec_raw_ptr)
		i->withdraw(1);

	std::cout << "\n----ArrayOfSmart(unique)Pointers--------------\n";
	std::unique_ptr<Account> smart_arr_un[]{ std::move(sp1), std::move(sp2), std::move(sp3), std::move(sp4) };
	for (size_t i = 0; i < sizeof(smart_arr_un) / sizeof(smart_arr_un[0]); ++i)
		smart_arr_un[i]->withdraw(9);

	
	//std::unique_ptr<int> one{ std::make_unique<int>(1) };
	//std::unique_ptr<int> two{ std::make_unique<int>(2) };
	//std::unique_ptr<int> three{ std::make_unique<int>(3) };

	//std::vector<std::unique_ptr<int>> vint{ };

	//vint.push_back(std::move(one));
	//vint.push_back(std::move(two));
	//vint.push_back(std::move(three));

	//for (auto& i : vint) std::cout << *i;

	std::cout << "\n----VectorOfSmart(unique)Pointers--------------\n";
	std::vector<std::unique_ptr<Account>> vec_uniq_ptr{};
	vec_uniq_ptr.push_back(std::move(sp1));
	vec_uniq_ptr.push_back(std::move(sp2));
	vec_uniq_ptr.push_back(std::move(sp3));
	//std::cout << "pocet prvku " << vec_uniq_ptr.size();
	for (size_t i = 0; i < vec_uniq_ptr.size(); ++i)
	//	//std::cout << 1;
		vec_uniq_ptr[i]->withdraw(9); // bug??

	std::cout << "\n----ArrayOfSmart(shared)Pointers--------------\n";
		std::shared_ptr<Account> smart_arr[]{ sps1,sps2,sps3,sps4 };
	for (size_t i = 0; i < sizeof(smart_arr) / sizeof(smart_arr[0]); ++i) 
		smart_arr[i]->withdraw(1);

	std::cout << "\n----VectorOfSmart(shared)Pointers--------------\n";
	std::vector<std::shared_ptr<Account>> vec_shared_ptr{ sps1,sps2,sps3,sps4 };
	for (auto const& i : vec_shared_ptr) i->withdraw(3);


	std::cout << "\n-----DeletingPointers--------------\n";
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}