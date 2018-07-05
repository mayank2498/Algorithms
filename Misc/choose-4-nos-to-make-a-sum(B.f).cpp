// https://practice.geeksforgeeks.org/problems/four-elements/0
// choose 4 numbers from an array to make the sum of these numbers as given sum
// recursive brute force solution
// time complexity  O(N^4)

#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
vector<int> v;

bool check(int * arr,int size,int sum,int turn,int start){
    cout<<"sum = "<<sum<<" turn = "<<turn<<"\n";
    if(turn > 4){return false;}

    if(turn == 4 ){
        if(sum==0) return true;
        else return false;
    }

    if(sum<0){return false;}

    loop(i,start,size){
        if ( check(arr,size,sum-arr[i],turn+1,i+1)){ v.push_back(arr[i]); return true;}
    }
    return false;
}

int main()
{

    int a[] = {1,0,0,3,2,4};
    int size = sizeof(a)/sizeof(a[0]);
    int sum = 8;
    cout<<check(a,size,sum,0,0)<<endl;

    cout<<"Chosen numbers are ";
    loop(i,0,v.size()){
        cout<<v[i]<<" ";
    }
    return 0;
}

