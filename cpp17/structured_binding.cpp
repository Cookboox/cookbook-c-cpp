#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int, double> getDataPosition(){
	// some code..
	// returning multiple values
	return {"NQ", 100, 4455.98};
}

// the old terrible way
void foo1(){
	std::tuple<std::string, int, double> positionData = getDataPosition(); // auto..
	std::string symbol = std::get<0>(positionData);
	int volume = std::get<1>(positionData);
	double price = std::get<2>(positionData);

	// use the values ..
}

// the old better way
void foo2(){
	std::string symbol;
	int volume;
	double price;

	std::tie(symbol, volume,  price) = getDataPosition();
	
	// use the values..
}

// the new best way 
void foo3(){
	auto[symbol, volume, price] = getDataPosition();

	// use the values ..

}


int main(){

	// foo1();
	// foo2();
	// foo3();
	auto[symbol, volume, price] = getDataPosition();
}
