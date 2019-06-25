#include<iostream>
#include<cmath>
using namespace std;

bool isSpecial(string s,int start,int end){
	int i=start;int j=end;
	int mid;
	if((end-start+1)%2==0){
		mid=(end-start+1)/2;
	}
	else{
		mid=floor((end-start+1)/2);
	}
	if((end-start+1)%2==1){
	for(int t=0;t<mid;t++){
		if((s[i]==s[j])&&(s[i]==s[start])&&(s[j]==s[start])){
			i++;
			j--;
		}
		else{
			return false;
		}
	}
	}
	if((end-start+1)%2==0){
		for(int t=start;t<end;t++){
			if(s[t]==s[t+1]){
				continue;
			}
			else
				return false;
		}
	}	
	return true;
}

int numSpecials(int n,string s){
	int cnt=s.length();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(isSpecial(s,i,j)){
				cout<<i<<"\t"<<j<<endl;
				cnt++;
				for(int t=i;t<=j;t++)
					cout<<s[t]<<"\t";
				cout<<endl;
			}
		}
	}
	return cnt;
}

int main(){
	string s;
	cout<<"Enter string:";
	getline(cin,s);
	int n=s.length();
	cout<<numSpecials(n,s);
	return 0;
}
