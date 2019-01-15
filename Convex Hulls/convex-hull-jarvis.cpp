#define l(i,a,b) for(int i=a;i<b;i++)
#include <iostream>
#include <vector>
#include<stdlib.h>
using namespace std;

struct Point{
	int x,y;
};


int orientation(Point p1,Point p2,Point p3){
	int val =  (p2.y-p1.y)*(p3.x-p2.x) - (p3.y-p2.y)*(p2.x-p1.x);
	if(val>0) return 1; // clockwise p1 p2 p3
	if(val==0) return 0; // collinear
	// val < 0 means anti clockwise 
	return 2;
}

void convexHull(Point * points,int n){
	int start=0;
	l(i,0,n){
		if( points[i].x < points[start].x )
			start = i;
	}
	vector<int> v;

	int p = start;
	do{
		v.push_back(p);

		int q = (p+2)%n;
		l(i,0,n){
			if( orientation(points[p],points[q],points[i]) == 2 )
				q = i;
		}
		p = q;
	}while(p!=start);

	l(i,0,v.size()){
		cout<<"( "<<points[v[i]].x<<","<<points[v[i]].y<<" )"<<endl;
	}
}


int main(){
	

	Point points[] = {{1,1},{4,3},{2,6},{6,8},{3,9},{-2,3}};
	convexHull(points,sizeof(points)/sizeof(points[0]));
	return 1;
}


