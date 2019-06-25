#include<iostream>

bool isPrime(int n){
	if(n<1)
		return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}

int main(){
	int i=2;
	for(int nprimes=0;;++i){
		if(isPrime(i)){
			//just change the limit to nth prime number you want
			if(++nprimes == 10001){
				std::cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}
