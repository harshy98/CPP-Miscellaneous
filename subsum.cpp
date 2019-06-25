#include<iostream>
#include<iomanip>
using namespace std;

bool subsetsum(int a[],int n,int s){

	bool T[n][s];
	
    for(int j=0;j<n;j++){
        T[j][0]=true;
    }
    for(int k=1;k<n;k++){
        T[0][k]=false;
        for(int l=1;l<=s;l++){
            if((a[k]<s) && ((subsetsum(a,n-1,s-a[k])) || (subsetsum(a,n-1,s)))){
                T[k][l]=true;
            }
            else{
                T[k][l]=false;
            }
        }
    }
    return T[n-1][s-1];
}   

int main(){
    int n,s;
	
    cout<<"Enter number of elements:\n";
    cin>>n;
    cout<<"Enter sum required\n";
    cin>>s;

	int a[n];
	
	cout<<"Enter elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<std::boolalpha<<subsetsum(a,n,s);
}
