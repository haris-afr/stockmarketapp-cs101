#include<iostream>
#include<random>
#include<string>
using namespace std;

double trend=0;

void updateprice(double &price, double &volatility, string &stock)
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
    if (price < 1)
    {
        price=1;
    }

    trend *=.9;


     cout<< "Stock: "<< stock<< " ";
    cout<< "price: "<< price << endl;
}






int main(){
    string stock;
    double price, volatility;

    cout<<"Enter stock name: ";
    cin>> stock;

     cout<<"Enter price: ";
    cin>> price;

     cout<<"Enter volatility: ";
    cin>> volatility;

    for(int i=0; i<22; i++)
    {
        updateprice(price, volatility, stock);
    }

    
}