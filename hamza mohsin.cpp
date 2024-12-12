#include<iostream>
using namespace std;


float dash(bool flag,float magnitude){
    float y;
    if(flag){
    	return magnitude;
	}
	else if(!flag)
        return 1/magnitude;
        


}
int main(){
	
	float a =100,b;
	b=dash(0,2);
	a=a*b;
	cout<<a;
}

