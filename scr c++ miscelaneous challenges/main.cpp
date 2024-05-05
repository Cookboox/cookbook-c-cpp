#include<iostream>
#include<chrono>

constexpr int limit_long{ 2 };



int main()
{

    auto current_time_in_seconds = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::cout << current_time_in_seconds << '\n';

    


	return 0;
}
