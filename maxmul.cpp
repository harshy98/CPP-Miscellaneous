#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;


long long solve(vector<int> A,int N) {
    int largest=A[0],seclargest=A[0],smallest=A[0],secsmallest=A[0],temp1,temp2;
    for(int i=0;i<A.size();i++){
        if(A[i]>largest){
            largest=A[i];
            temp1=i;
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i]>seclargest && i!=temp1){
            seclargest=A[i];
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i]<smallest){
            smallest=A[i];
            temp2=i;
        }
    }
    for(int i=0;i<A.size();i++){
        if(A[i]<secsmallest && i!=temp2){
            secsmallest=A[i];
        }
    }
    cout<<largest<<seclargest<<smallest<<secsmallest;
    if((largest*seclargest)>(smallest*secsmallest)){
       return (largest*seclargest);
   }
   else{
       return (smallest*secsmallest);
   }
   /*int maxpos=INT_MIN,secmaxpos=INT_MIN;
   int maxneg=INT_MIN,secmaxneg=INT_MIN;
   for(int i=0;i<N;i++){
       if(A[i]>maxpos){
           secmaxpos=maxpos;
           maxpos=A[i];
       }
       else if(secmaxpos<A[i]){
            secmaxpos=A[i];
       }
            
        if(A[i]<0 && abs(maxneg)<abs(A[i])){
            secmaxneg=maxneg;
            maxneg=A[i];
        }
        else if(A[i]<0 && abs(secmaxneg)<abs(A[i])){
            secmaxneg=A[i];
        }
   }
   if((maxneg*secmaxneg)<(maxpos*secmaxpos)){
       return (maxpos*secmaxpos);
   }
   else{
       return (maxneg*secmaxneg);
   }*/
}

int main() {
    
    int T;
    cin >> T;
    
    for(int t_i=0; t_i<T; t_i++)
    {   int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A=0; i_A<N; i_A++)
        {
        	cin >> A[i_A];
        }
        long long out_;
        out_ = solve(A,N);
        cout << out_;
        cout << "\n";
    }
}
