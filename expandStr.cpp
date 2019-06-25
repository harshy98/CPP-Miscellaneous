#include<iostream>
#include<string>
using namespace std;

bool isSpace(char c){
	if(c==' '){
		return false;
	}
	return true;
}

bool isAlpha(char c){
	if((int)c>=97 && (int)c<=122){
		return true;
	}
	return false;
}

bool isNum(char c){
	if((int)c>=48 && (int)c<=57){
		return true;
	}
	return false;
}

bool isHyphen(char c){
	if((int)c==45){
		return true;
	}
	return false;
}

string expandRange(string s){
	int i=0;
	string res="";
	for(;i<s.length();){
		if(isSpace(s[i])){
			i++;
		}
		if(isAlpha(s[i])){
			char castart=s[i];
			while(isAlpha(s[i+1]) && !isNum(s[i+1]) && isHyphen(s[i+1])){
				i++;
			}
			if(isNum(s[i+1])){
				return "INVALID";
			}else{
				char caend=s[i];
				for(int j=(int)castart;i<=(int)caend;i++){
					res+=(char)j;
				}
			}
		}
		if(isNum(s[i])){
			char cnstart=s[i];
			while(isNum(s[i+1]) && !isAlpha(s[i+1]) && isHyphen(s[i+1])){
				i++;
			}
			if(isAlpha(s[i+1])){
				return "INVALID";
			}else{
				char cnend=s[i];
				for(int j=(int)cnstart;i<=(int)cnend;i++){
					res+=(char)j;
				}
			}
		}
	}
	return res;
}

int main(){
	string range;
	cout<<"Enter the range string:\n";
	cin>>range;
	cout<<"The expanded string:\n";
	cout<<expandRange(range);
	return 0;
}
