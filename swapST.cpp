#include<iostream>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int val){
	node* n=new node();
	n->data=val;
	n->left=NULL;
	n->right=NULL;
	return n;
}
//because we have to swap pointers to reflect changes in entire subtree, not data
void swap(node** a,node** b){
	node* temp=*a;
	*a=*b;
	*b=temp;
}

void swapKNodes(node* root,int lvl,int k){
	if(root==NULL || (root->left==NULL && root->right==NULL)){
		return;
	}
	if((lvl+1)%k==0){
		swap(&root->left,&root->right);
	}
	swapKNodes(root->left,lvl+1,k);
	swapKNodes(root->right,lvl+1,k);
}

void inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

int main(){
	int k=2;
	node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	cout<<"Inorder before:\t";
	inorder(root);
	cout<<"\n";
	swapKNodes(root,1,k);
	cout<<"Inorder after:\t";
	inorder(root);
	cout<<"\n";
	return 0;
}
