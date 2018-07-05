
#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void solve(int m,int n,int k){
    
    int nums = pow(2,n);
    int last_index = k/nums;
    int rem = k%nums;
    //cout<<"Lies in group"<<last_index<<endl;


    bool flip = true;
    while(rem>1){
        if( rem&1 ){ flip = !flip; }
        rem = rem>>1;
    }
    //cout<<"Flip = "<<flip<<endl;

    int a[100],x=0;
    for(;m>0;x++){
        a[x] = m%2;
        m = m/2;
    }


    int ans = a[x-1-last_index];
    //cout<<"\n ans = "<<ans<<endl;

    if(rem == 0){cout<<ans<<endl; return;}

    if(flip){cout<<!ans<<endl;}
    else{cout<<ans<<endl;}
}

int main()
{
    int m=5;
    int k=5;
    int n=3;
    int t;
    cin>>t;
    while(t--){
        cin>>m>>k>>n;
        solve(m,n,k);
    }
    return 0;
}

