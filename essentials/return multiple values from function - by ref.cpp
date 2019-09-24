#include <iostream>
#include<string>
#include<cctype>
#include<algorithm>


void vrat_vysledky(double& vysl_nas, double& vysl_del, double& vysl_sc, double& vysl_odc, int a, int b)
{
	vysl_nas = a * b;
	vysl_del = a / b;
	vysl_odc = a - b;
	vysl_sc = a + b;
}

int main()
{	
	double vysledek_nasobeni {};
	double vysledek_deleni {};
	double vysledek_scitani {};
	double vysledek_odcitani {};

	vrat_vysledky(vysledek_nasobeni, vysledek_deleni, vysledek_scitani, vysledek_odcitani, 100, 5);

	std::cout << vysledek_nasobeni << "\t" << vysledek_deleni << "\t" << vysledek_scitani << "\t" << vysledek_odcitani << "\n";

	return 0;
}
