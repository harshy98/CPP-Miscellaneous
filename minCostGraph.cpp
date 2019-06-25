#include<iostream>
#include<vector>
using namespace std;

class minCost{
	public:
		vector<vector<int>>adjCities;
		int connComps;
		vector<bool>visited;
		
		void dfs(int city){
			visited[city]=true;
			for(int i=0;i<adjCities[city].size();i++){
				while(!visited[adjCities[city][i]]){
					dfs(adjCities[city][i]);
				}
			}
		}
};

int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		minCost cst;
		int c,r,c_lib,c_road;
		cin>>c>>r>>c_lib>>c_road;
		cst.adjCities.resize(c+1);
		cst.visited.resize(c+1);
		cst.connComps=0;
		for(int i=0;i<r;i++){
			int c1,c2;
			cin>>c1>>c2;
			cst.adjCities[c1].push_back(c2);
			cst.adjCities[c2].push_back(c1);
		} 
		if(c_lib<=c_road || r==0){
			cout<<c_lib*c<<"\n";
		continue;
		}
		else{
			for(int i=1;i<=c;i++){
				if(!cst.visited[i]){
					cst.dfs(i);
					cst.connComps++;
				}
			}
			cout<<c_road*(c-cst.connComps)+c_lib*cst.connComps<<"\n";
		}
	}
	return 0;
}
