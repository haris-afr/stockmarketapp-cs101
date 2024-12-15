#include<iostream>
#include<random>
#include<string>
using namespace std;

double trend=0;

double updateprice(double price, double volatility)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> randomchange(-volatility,volatility);
    uniform_real_distribution<> rareEvent(0,1);

    double change=randomchange(gen) + trend;

    if(rareEvent(gen) < .05)
    {
        change+= randomchange(gen) * 5;         // for big changes
    }

    price +=change;

    trend *=.9;


	return price;
}
