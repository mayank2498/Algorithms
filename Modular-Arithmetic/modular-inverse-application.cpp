// dp approach
// is useful for nCr % p where p is prime

#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
typedef long long ll;
using namespace std;

// usually 10^6
const int n_max = 5500;

ll fact[n_max];
ll facti[n_max];

ll power( ll x , ll y, ll p){
    ll res = 1;
    x = x%p;
    while(y){
        if( y&1 )
            res = (res * x)%p;
        x = (x*x)%p;
        y = y>>1;
    }
    return res;
}


void build_fact(){
    fact[0] = fact[1] = 1;
    loop(i,2,n_max){
        fact[i] = ( i*fact[i-1] ) %MOD;
        facti[i] = power(fact[i],MOD-2,MOD);
    }
}

int main()
{
    build_fact();
}


