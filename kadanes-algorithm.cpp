// maximum sum subarray
// kadanes algorithm

#include<iostream>

#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;


int max_SubArray_Sum(int * A,int n){
    int sum=0 ,ans=0;
    loop(i,0,n){
        sum = sum + A[i];
        ans = max(ans,sum);
        if(sum<0){sum=0;}
    }
    return ans;
}

int main(){
    int A[] = {1,-3,2,-5,7,6,-1,-4,11,-23};
    cout<<"MAX sub array sum : "<<max_SubArray_Sum(A,sizeof(A)/sizeof(A[0]));
}

