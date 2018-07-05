// longest increasing subsequence
// recursive
// O(2^n)


#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int LIS(int * arr,int n,int prev,int index){

    if(index==n){return 0;}

    int taken = 0;
    if(prev<arr[index]){
        taken = 1 + LIS(arr,n,arr[index],index+1);
    }
    int nottaken = LIS(arr,n,prev,index+1);
    return max(taken,nottaken);
}


int main()
{
    int a[] = {-1,2,-2,3,13,4,-1};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<LIS(a,size,INT_MIN,0);
    return 0;
}

