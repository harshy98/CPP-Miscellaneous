#include<iostream>
#include<vector>
using namespace std;

int minimumBribes(vector<int> q) {
    int count=0;
    for(int i=q.size()-1;i>=0;i--){
        //if the position of any person is more than 2 from original position
        if (q[i] - (i + 1) > 2) {
        cout << "Too chaotic\n";
        return -1;
        }
        else {
        //count number of times a person is displaced from his original place
        for (int j = max(0, q[i] - 2); j < i; j++)
          if (q[j] > q[i])
            count++;
        }
    }
    return count;
}

int main(){
	int n;
	cout<<"Enter number of people:\n";
	cin>>n;
	vector<int> q(n);
	cout<<"Enter the bribed configuration:\n";
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	cout<<"The number of bribes:\t"<<minimumBribes(q);
}
