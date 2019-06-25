#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long sumDigit(string n) 
{ 
    long sum = 0; 
    for(int i=0;i<n.length();i++){
        sum+= n[i]-'0';
    } 
    return sum; 
}

long superDigitHelper(long n){
    if(n<10)
        return n;
    else{
        long num=0;
        while(n>0){
            num+=n%10;
            n=n/10;
        }
        return superDigitHelper(num);
    }
}

// Complete the superDigit function below.
int superDigit(string n,int k) {
    long s=sumDigit(n);
    s=superDigitHelper(s*k);
    return (int)s;
    /*int d=n.length();
    if(d==1)
        return stoi(n);
    string s = to_string(sumDigit(n));
    return superDigit(s);*/

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];
    
    int k = stoi(nk[1]);

    int result = superDigit(n,k);

    fout << result << "\n";

    fout.close();

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
