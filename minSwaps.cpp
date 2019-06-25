#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]=i;
        cout<<arr[i]<<"->"<<i<<endl;
    }
    int swaps=0;
    int temp;
    for(int i=0;i<arr.size();i++){
        //if value is not equal to position
        if(arr[i]!=i+1){
            swaps++;
            temp=arr[i];
            cout<<"temp="<<temp<<endl;
            arr[i]=i+1; //set entry to position
            cout<<"arr["<<i<<"]="<<arr[i]<<endl;
            arr[m[i+1]]=temp;   //place swapped out element at its intended position
            cout<<"arr["<<m[i+1]<<"]="<<arr[m[i+1]]<<endl;
            m[temp]=m[i+1]; //update map to reflect change in positions
            cout<<"m["<<temp<<"]="<<m[temp]<<endl;
        }
    }
    return swaps;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
		cin>>arr[i];
    }

    int res = minimumSwaps(arr);

    cout << res << "\n";

    return 0;
}
