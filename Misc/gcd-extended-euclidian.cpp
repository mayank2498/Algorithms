#define loop(i,a,b) for(ll i=a;i<b;i++)

#include <bits/stdc++.h>
#include<iostream>
typedef long long ll;
using namespace std;
#define MOD 1000000007
int count = 0;

int gcd(int a,int b){
    ::count++;
    if(a==0){return b;}
    if(a==b){return a;}
    if(a>b) return gcd(a-b,b);
    return gcd(b-a,a);
}

int main()
{
    int a = 10001232,b=6123723;
    cout<<gcd(a,b)<<endl;
    cout<<"Iterations = "<<::count;
    return 0;
}

