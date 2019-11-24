#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

struct City
{
	std::string name;
	int population;
	int price;
};

struct Country
{
	std::string name;
	std::vector<City> cities;
};

struct Table
{
	std::string heading;
	std::vector<Country> countries;
};

void handler()
{
	std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890\n";
}


constexpr int total_width{ 70 };
constexpr int country_width{ 20 };
constexpr int city_width{ 20 };
constexpr int population_width{ 15 };
constexpr int price_width{ 15 };

void display(Table& t)
{
	handler();
	std::cout << std::endl;
	std::cout << std::setw((total_width - t.heading.size()) / 2) << "" << t.heading << "\n" ; //displays the heading in the center

	std::cout << std::setw(country_width) << std::left << "COUNTRY";
	std::cout << std::setw(city_width) << std::left << "CITY";
	std::cout << std::setw(population_width) << std::right << "POPULATION";
	std::cout << std::setw(price_width) << std::right << "PRICE\n" << std::endl;

	std::cout << std::setw(total_width) << std::setfill('-') << "" << "\n"; //makes total width dashes
	std::cout << std::setfill(' '); //reseting back to nothing .. otherwise this would last even through different functions

	for (auto country : t.countries)
	{
		int index = 0;
		for (auto city : country.cities)
		{		
			std::cout << std::setw(country_width) << std::left << ((index == 0) ? country.name : "") //if i a on the first line print country name, otherwise dont prina anything
					  << std::setw(city_width) << std::left << city.name
				      << std::setw(population_width) << std::right << city.population
					  << std::setw(price_width) << std::right << city.price << "\n";
			++index;
		}
	}
}


int main()
{
	Country Germany{ "Germany", {{"Berlin", 5000000, 1230}, {"Munich", 3800000, 1400},{"Dresden", 1300000, 950}} };
	Country Polland{ "Polland", {{"Wroclaw", 1500000, 230}, {"Krakow", 800000, 124},{"Warsaw", 2300000, 450}} };
	Country Austria{ "Austria", {{"Wien", 2000000, 810}} };

	Table TripsFromUK {"Trips From UK", {Germany, Polland, Austria}};

	display(TripsFromUK);

	return 0;
}