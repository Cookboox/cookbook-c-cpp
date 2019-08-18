#include <iostream>
#include <memory>
#include <vector>


class Test
{
private:
public:	
	int data;
	Test(int a) : data{ a } { std::cout << "\tconstruction object with value: " << this->data << "\n"; }
	~Test() { std::cout << "\tdestruction object with value: " << this->data << "\n"; }
	void get_data() { std::cout << data << "\n"; }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
	auto ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
	return ptr;
}

void fill(std::vector<std::shared_ptr<Test>>& v, int const& number_of_elems)
{
	std::cout << ">> vector with " << number_of_elems << " data points was created << \n";
	std::cout << "========================================================\n";
	int number{};

	for (int i = 0; i < number_of_elems; ++i)
	{
		std::cout << "please enter the " << i + 1 << ". element\n";
		std::cin >> number;
		v.push_back(std::make_unique<Test>(number));
	}
}

void display(const std::vector<std::shared_ptr<Test>>& v)
{
	std::cout << "\n-------vector holds pointers to these data: ---------\n";
	for (auto const& i : v) std::cout << i->data << "\n";
	std::cout << "-------------------------------------------------------\n";
}

int main()
{
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();

	std::cout << "how many elements do u want to hold in vector? \n";
	int amount{};
	std::cin >> amount;
	fill(*vec_ptr, amount);
	display(*vec_ptr);

	return 0;
}