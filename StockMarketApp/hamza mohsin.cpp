#include<iostream>
#include <stdlib.h>
using namespace std;

int DaysOfExtreme(){
	int days;
	days = rand() % 7;
}

float extremePrice(bool flag, int days){
    float magnitude;
    magnitude = rand() % 80 + 80 + days * 10;
    magnitude /= 100.0;
    if(flag){
    	return magnitude;
	}
	else if(!flag){
		return 1/magnitude;
	}
}
