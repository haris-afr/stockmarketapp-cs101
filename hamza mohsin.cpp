#include<iostream>
using namespace std;


float dash(int value, float fluctuation){
    float x,y;
    x=(fluctuation-value)*100;
    if (fluctuation>0){
        y=(value+x/100)/value;    
    }
     else if (fluctuation<0)
        {
            y=(value-x/100)/value;
        }

        return y;
        


}
int main(){
	//testing code
	int a = dash(100,110);
	if(a>1){
		cout<<"value is positive";
	}
	else if(a<1){
		cout<<"value is negative";
	}
    
}

