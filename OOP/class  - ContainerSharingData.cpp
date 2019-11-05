#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

//Here a prototype of class that allocates string on the heap and WILL SHARE IT with all it copyies.


class ContainerSharingData
{
	friend std::ostream& operator<<(std::ostream &os, ContainerSharingData &rhs)
	{
		os << "[ ";
		auto it = rhs.m_data->cbegin();
		while (it != rhs.m_data->cend())
		{
			os << *it << " - " << &(*it) << " ";
			it++;
		}
		os << "]";
		return os;
	}



private:
	std::shared_ptr<std::vector<std::string>> m_data;
public:
	ContainerSharingData() :
		m_data {new std::vector<std::string>} 
	{}

	ContainerSharingData(std::initializer_list<std::string> l) :
		m_data{ new std::vector<std::string> }
	{
		for (auto i : l)
		{
			m_data->push_back(i);
		}
	}

	std::string get_first() { return m_data->front(); };
	std::string get_last() { return m_data->back(); };
	void add_element(std::string const &s) { m_data->emplace_back(s); }
	//void delete_element(int pos) { m_data->erase(pos); }
	bool is_empty() { return m_data->empty(); }
};




int main()
{
	ContainerSharingData c{ "pepa", "franta", "jakub", "marek" };

	//std::cout << c.get_first();
	//std::cout << c.get_last();


	ContainerSharingData d{ c };

	//std::cout << d.get_first();
	//std::cout << d.get_last();
	
	d.add_element("andrea");

	std::cout << d;
	std::cout << "\n";
	std::cout << c;

	//std::cout << d.get_first();
	//std::cout << d.get_last();

	//std::cout << c.get_first();
	//std::cout << c.get_last();


	return 0;
}