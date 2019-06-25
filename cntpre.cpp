#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long solve (vector<long long> A, int Q, long long K, int R, int L) {
   
       int cnt=0;
       for(int j=L-1;j<R;j++){
       	if(A[j]%K==0){
       		cnt++;
		   }
	   }
	   if(cnt==0){
	   	return -1;
	   }
	   else{
	   	return (L+cnt-1);
	   }
       /*while(A[index]/K==0 && index<=R-1){
           if(A[index]/K==0){
               count++;
           }
           index++;
       }
       cout<<index;
        if(count!=0){
            return (L+count);
        }
        else{
            return -1;
        }*/
}

int main() {

    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }
    int Q;
    cin >> Q;
    int L[Q],R[Q];
    long long K[Q];
	for(int i=0;i<Q;i++){
    cin >> L[i];
    cin >> R[i];
    cin >> K[i];
	}
	for(int i=0;i<Q;i++){
    long long out_;
    out_ = solve(A, Q, K[i], R[i], L[i]);
    cout << out_;
	}
    return 0;
}
