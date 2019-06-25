#include<iostream>

using namespace std;

//node is the entry number in tree[] where elements from left to right are found
build(int A[],int tree[],int node,int left,int right){
	if(left==right)
		tree[node]=A[left];
	else{
		int mid = (left + right)/2;
		build(A,tree,2*node+1,left,mid);
		build(A,tree,2*node+2,mid+1,right);
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}

update(int A[],int tree[],int node,int left,int right,int i,int val){
	if(left==right){
		A[i]=val;
		tree[node]=val;
	}
	else{
		int mid = (left+right)/2;
		if(left<=i && i<=mid)
			update(A,tree,2*node+1,left,mid,i,val);
		else
			update(A,tree,2*node+2,mid+1,right,i,val);
		tree[node] = tree[2*node+1] + tree[2*node+2];
	}
}

int query(int A[],int tree[],int node,int left,int right,int l,int r){
	if(left>r || l>right){
		return 0;
	}
	if(l<= left && r>=right){
		return tree[node];
	}
	int mid = (left+right)/2;
	int s1 = query(A,tree,2*node+1,left,mid,l,r);
	int s2 = query(A,tree,2*node+2,mid+1,right,l,r);
	return (s1+s2);
}

int main(){
	int n,index,val,l,r;
	cout<<"Enter n:\n";
	cin>>n;
	int arr[n];
	cout<<"Enter elements:\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int tree[4*n];
	for(int i=0;i<4*n;i++)
		tree[i]=0;
	build(arr,tree,0,0,n-1);
	cout<<"The segment tree:\t";
	for(int i=0;i<4*n;i++)
		cout<<tree[i]<<"\t";
	cout<<endl;
	cout<<"Enter index of element you want to update and the updated value:\n";
	cin>>index>>val;
	update(arr,tree,0,0,n-1,index,val);
	cout<<"The segment tree:\t";
	for(int i=0;i<4*n;i++)
		cout<<tree[i]<<"\t";
	cout<<endl;
	cout<<"Enter range of indexes to query:\n";
	cin>>l>>r;
	cout<<query(arr,tree,0,0,n-1,l,r);
	return 0;
}
