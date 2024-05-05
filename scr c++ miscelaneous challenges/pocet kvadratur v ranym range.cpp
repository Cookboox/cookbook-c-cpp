#include <iostream>
#include <math.h>


bool is_integer(float k) { return std::floor(k) == k; }


int main()
{
	int pocet_kvadratur = 0;
	for (int i = -1000; i < 1000; i++)	{ if (is_integer(sqrt(abs(i)))) { pocet_kvadratur++; } };

	std::cout << pocet_kvadratur;

	return 0; //
}
