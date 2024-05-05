

# include <iostream>
# include <map>
# include <string>

std::multimap < std::string, double > m;

int
main()
{
    m.insert({{"pepa", 1.5}, {"franta", 2.5}, {"jarda", 41.5}, {"pepa", 51.5}, {"karel", 2.5}, {"petr", 2.9},
              {"pepa", 2.255}, {"franta", 2.25}, {"karel", 3.5}, {"pepa", 3.6}});

for (auto i: m)
std::cout << i.first << " " << i.second << "\n";

std::cout << "----------\n";

auto
p = m.equal_range("pepa");

for (auto i = p.first; i != p.second; ++i)
std::cout << i->first << " " << i->second << "\n";

std::cout << "*----------\n";
auto
lowerbound = m.lower_bound("pepa");
auto
upperbound = m.upper_bound("pepa");

std::cout << lowerbound->first << lowerbound->second << " lowerbound \n";
std::cout << upperbound->first << upperbound->second << " upperbound \n";
