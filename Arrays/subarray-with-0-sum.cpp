//   https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
int main() {
    unordered_map<int,int> m;
	int t;
	cin>>t;
	while(t--){
	    m.clear();
	    int n,x,sum=0;
	    bool flag = false;
	    cin>>n;
	    loop(i,0,n){
	        cin>>x;
	        sum += x;
	        if(m.find(sum)!=m.end()){
	            flag=true;
	        }else{
	            m[sum] = 0;
	        }
	    }
	    if(flag==true || m.find(0)!=m.end())
	        cout<<"Yes\n";
	    else
	        cout<<"No\n";
	}
	return 0;
}
