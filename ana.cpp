#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

unordered_map<char,int> countOccurences(string s){
	unordered_map<char,int> m;
	for(int c=0;c<s.length();c++){ 
		if(s[c]!=' '){
			m[std::toupper(s[c])]++;
		}
	}
	return m;
}

int main(){
	string s1,s2;
	cout<<"Enter two strings to be checked:\n";
	cin>>s1;
	cin>>s2;
	unordered_map<char,int> m1,m2;
	m1 = countOccurences(s1);
	m2 = countOccurences(s2);
	/*for(int i=0;i<m1.size();i++){
		if(m1[i]!=0)
		cout<<m1[i]<<endl;
	}
	for(int i=0;i<m2.size();i++){
		if(m2[i]!=0)
		cout<<m2[i]<<endl;
	}*/
	for(int i=0;i<=255;i++){
		if(m1[i]!=m2[i]){
			cout<<"Strings are not anagrams\n";
			return 0;
		}
	}
	cout<<"Strings are anagrams\n";
	return 0;
}
