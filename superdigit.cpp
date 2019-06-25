#include <bits/stdc++.h>

using namespace std;

int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
}

long sumDigit(long long n) 
{ 
    long sum = 0; 
    while (n != 0) {
        sum += n % 10; 
        n = n / 10;  
    } 
    return sum; 
}

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(long long m) {

    int d=countDigit(m);
    if(d==1){
        return m;
    }
    long s=sumDigit(m);
    return superDigit(s);

}

int main()
{
    
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    string n1=n;

    for(int i=0;i<k-1;i++){
        n+=n1;
    }
	
	for(int i=0;i<n.length();i++){
		cout<<n[i];
	}
	cout<<"\n";
    long long m=stoll(n);

    int result = superDigit(m);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

