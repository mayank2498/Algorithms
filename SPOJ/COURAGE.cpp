#define loop(i,a,b) for(ll i=a;i<b;i++)
#include <iostream>
#include<math.h>
#include<bits/stdc++.h>
#define MAX 1000000000
#define garbage -100
typedef long long ll;
using namespace std;

pair<ll,ll> * makeSegmentTree(ll size){
    pair<ll,ll> * A = new pair<ll,ll> [size];
    loop(i,0,size){ A[i].first = garbage;}
    return A;
}

ll initialise(ll * A,pair<ll,ll> * segTree,ll low,ll high,ll pos){
    if ( high==low ){
        segTree[pos].first = segTree[pos].second = A[low]; return A[low];
    }
    ll mid = (low+high)/2;
    ll x = initialise(A,segTree,low,mid,2*pos+1);
    ll y = initialise(A,segTree,mid+1,high,2*pos+2);
    segTree[pos].first = min(x,y);
    segTree[pos].second = segTree[2*pos+1].second + segTree[2*pos+2].second;
    return min(x,y);
}

void update(ll x,ll y,pair<ll,ll> *segTree,ll low,ll high,ll pos){
    if(low==high){
        if(low==y){
            segTree[pos].first += x;
            segTree[pos].second += x;
            return;
        }
    }
    else{
        if(y >= low && high>= y){
            ll  mid = (low+high)/2;
            update(x,y,segTree,low,mid,2*pos+1);
            update(x,y,segTree,mid+1,high,2*pos+2);
            segTree[pos].first = min(segTree[2*pos+1].first,segTree[2*pos+2].first);
            segTree[pos].second += x;
        }
        else{ return; }
    }
}

ll find_MIN(pair<ll,ll> * segTree,ll l,ll r,ll low,ll high,ll pos){
    if ( low>=l && high<=r ) {
        return segTree[pos].first;
    }
    // no overlap
    if ( low > r || high < l ) { return MAX; }

    //partial overlapŝ
    ll mid = (high+low)/2;
    return min( find_MIN(segTree,l,r,low,mid,2*pos+1) , find_MIN(segTree,l,r,mid+1,high,2*pos+2));
}

ll find_SUM(pair<ll,ll> * segTree,ll l,ll r,ll low,ll high,ll pos){
    // total overlap
    if ( low>=l && high<=r ) {
        return segTree[pos].second;
    }

    // no overlap
    if ( low > r || high < l ) { return 0; }

    //partial overlap
    ll  mid = (high+low)/2;
    return find_SUM(segTree,l,r,low,mid,2*pos+1) + find_SUM(segTree,l,r,mid+1,high,2*pos+2);
}


void display(pair<ll,ll> * x,ll n){
    loop(i,0,n){
        cout<<x[i].first<<" "<<x[i].second<<endl;
     }
}

int main()
{
    int N,p,x,y; cin>>N;
    ll A[N];
    loop(i,0,N) cin>>A[i];
    ll max_size = pow(2,ceil(log2(N))+1) - 1;
    pair<ll,ll> * segTree = makeSegmentTree(max_size);
    initialise(A,segTree,0,N-1,0);

    cin>>p;
    string s;
    while(p--){
        cin>>s>>x>>y;
        if( s == "COUNT" ){
            ll Sum = find_SUM(segTree,x,y,0,N-1,0);
            ll MIN = find_MIN(segTree,x,y,0,N-1,0);
            cout<<Sum-MIN<<endl;

        }
        else if ( s == "GROW" ){
            update(x,y,segTree,0,N-1,0);
        }
        else{
            update(-1*x,y,segTree,0,N-1,0);
        }

    }
    return 0;
}
