#include<iostream>
#include<algorithm>
#include<random>
#include<numeric>

int x()
{
    return 10000;
}

float y()
{
    return 10000.00000;
}

void acc_vec_int()
{
    std::random_device dev;
    std::mt19937 mt_engine{ dev() };
    std::uniform_int_distribution<int> distr {1, 100};
    std::vector<int> v;

    int i = 0;
    while (i < 10)
    {
        std::cout << distr(mt_engine) << "\n";
        v.push_back(distr(mt_engine));
        ++i;
    }

    int sum = std::accumulate(v.begin(), v.end(), x());
    std::cout << sum << "\n";

}

void acc_vec_double()
{
    std::random_device dev;
    std::mt19937 mt_engine{ dev() };
    std::uniform_real_distribution<double> distr{ 1.0,10.0 };
    std::vector<double> v;

    int i = 0;
    while (i < 10)
    {
        std::cout << distr(mt_engine) << "\n";
        v.push_back(distr(mt_engine));
        ++i;
    }

    int sum = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << sum << "\n";
}

int main()
{
    acc_vec_int();
    acc_vec_double();

    return 0;
}