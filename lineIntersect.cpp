#include<iostream>

using namespace std;

struct Point{
	int x;
	int y;
};

int direction(Point i,Point j,Point k){
	return ((k.x-i.x)*(j.y-i.y)-(k.y-i.y)*(j.x-i.x));
}

bool onsegment(Point i,Point j,Point k){
	if((min(i.x,j.x)<=k.x && k.x<=max(i.x,j.x)) && (min(i.y,j.y)<=k.y && k.y<=max(i.y,j.y))){
		return true;
	}else{
		return false;
	}
}

bool segIntersect(Point p1,Point p2,Point p3,Point p4){
	int d1=direction(p3,p4,p1);
	int d2=direction(p3,p4,p2);
	int d3=direction(p1,p2,p3);
	int d4=direction(p1,p2,p4);
	if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0))){
		return true;
	}
	else if(d1==0 && onsegment(p3,p4,p1)){
		return true;
	}
	else if(d2==0 && onsegment(p3,p4,p2)){
		return true;
	}
	else if(d3==0 && onsegment(p1,p2,p3)){
		return true;
	}
	else if(d4==0 && onsegment(p1,p2,p4)){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	Point a,b,c,d;
	cout<<"Enter x coordinates of points:\t";
	cin>>a.x>>b.x>>c.x>>d.x;
	cout<<"\n";
	cout<<"Enter y coordinates of points:\t";
	cin>>a.y>>b.y>>c.y>>d.y;
	cout<<"\n";
	cout<<"Whether segments ab and cd intersect: "<<segIntersect(a,b,c,d)<<endl;
	return 0;
}
