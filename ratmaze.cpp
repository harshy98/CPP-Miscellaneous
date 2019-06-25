#include<iostream>
#define N 3
using namespace std;

int sol[N][N]={{0,0,0},
				{0,0,0},
				{0,0,0}};

bool mazeSolve(int maze[N][N],int x,int y){
	
	if(x==N-1 && y==N-1){
		sol[x][y]=1;
		return true;
	}
	if((x>=0 && x<N)&&(y>=0 && y<N) && maze[x][y]==1){
		sol[x][y]=1;
		if(mazeSolve(maze,x+1,y)==true){
			return true;
		}
		if(mazeSolve(maze,x,y+1)==true){
			return true;
		}
		if(mazeSolve(maze,x-1,y)==true){
			return true;
		}
		if(mazeSolve(maze,x,y-1)==true){
			return true;
		}
		sol[x][y]=0;
		return false;
	}
	return false;
}

int main(){
	int maze[N][N];
	cout<<"Enter config of maze:\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>maze[i][j];
		}
	}
	if(mazeSolve(maze,0,0)==true){
		cout<<"The path that the rat must take is:(SRC is topleft and DEST is bottomright)\n";
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<sol[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
	else{
		cout<<"Solution does not exist\n";
	}
	return 0;
}
