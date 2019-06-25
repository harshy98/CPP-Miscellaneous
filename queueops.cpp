#include<iostream>

using namespace std;

void inserttoback(int q[],int &rear,int val,int size){
	if(rear==size){
		cout<<"Overflow\n";
		return;
	}
	q[rear]=val;
	rear++;
}

void inserttofront(int q[],int &front,int &rear,int val,int size){
	if(rear==size){
		cout<<"Overflow\n";
		return;
	}
	for(int i=rear;i>front;i--){
		q[i]=q[i-1];
	}
	q[front]=val;
	rear++;
}

void deletefromfront(int q[],int &front,int &rear){
	if(front==rear){
		cout<<"Underflow\n";
		return;
	}
	q[front]=0;
	front++;
}

void deletefromback(int q[],int &front,int &rear){
	if(front==rear){
		cout<<"Underflow\n";
		return;
	}
	rear--;
	q[rear]=0;
}

int main(){
	int q[10]={0,0,0,0,0,0,0,0,0,0};
	int front=0,rear=0;
	int ch=0,n;
	while(ch!=5){
		cout<<"\n1.insert to back\n2.delete from front\n3.insert to front\n4.delete from back\n5.Exit\n";
		cout<<"What u wanna do?\n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter number:\n";
					cin>>n;
					inserttoback(q,rear,n,10);
					for(int i=0;i<10;i++){
						cout<<q[i]<<"\t";
					}
					break;
			case 2: deletefromfront(q,front,rear);
					for(int i=0;i<10;i++){
						cout<<q[i]<<"\t";
					}
					break;
			case 3: cout<<"Enter number:\n";
					cin>>n;
					inserttofront(q,front,rear,n,10);
					for(int i=0;i<10;i++){
						cout<<q[i]<<"\t";
					}
					break;
			case 4: deletefromback(q,front,rear);
					for(int i=0;i<10;i++){
						cout<<q[i]<<"\t";
					}
					break;
			case 5: exit(0);
		}
	}
	return 0;
}
