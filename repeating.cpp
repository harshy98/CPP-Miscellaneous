#include<iostream>

using namespace std;

int main(){
	//when x=-0.618 f(x) is always a different final value
	//otherwise f(x) is always 1.61803
	int n;float x;
	cout<<"Enter no of iterations:";
	cin>>n;
	cout<<"Initial value of x:";
	cin>>x;
	while(n>0){
		x=1.0+1.0/x;
		cout<<"Iteration "<<n<<" : "<<x<<endl;
		n--;
	}
	cout<<"Final value of x:"<<x;
	return 0;
}
