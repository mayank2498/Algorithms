#define loop(i,a,b) for(int i=a;i<b;i++)
#include<bits/stdc++.h>
#define MIN -100000
#include<math.h>
typedef long long ll;
using namespace std;

ll max_size;
priority_queue<ll> q;

ll initialise(ll * segTree,ll A[],int l,int r,int pos){
    if ( l==r ){ segTree[pos] = A[l]; return A[l];}
    int mid = (r+l)/2;
    segTree[pos] = max(initialise(segTree,A,l,mid,2*pos+1),initialise(segTree,A,mid+1,r,2*pos+2));
    return segTree[pos];
}

ll update(ll * segTree,int left,int right,int l,int r,int pos){

    if( l==r && l==left ){
        segTree[pos] = right;
        return right;
    }
    // no overlap
    if( left<l || left>r ){
        return segTree[pos];
    }
    int mid=(l+r)/2;
    segTree[pos] =  max(update(segTree,left,right,l,mid,2*pos+1),update(segTree,left,right,mid+1,r,2*pos+2));
    return segTree[pos];


}

void display(priority_queue<ll> q){
    cout<<endl<<endl;
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<"\nend displaying";
}

ll check(priority_queue<ll> x){
    priority_queue<ll> pq = x;
    if( pq.size() < 3 ){
        return -1;
    }
    else{
        while(!pq.empty()){
            if(pq.size()<3){break;}
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();
            ll third = pq.top();
            if( second+third>=first ){ return first+second+third; }
            pq.push(second);
        }
        cout<<"No answer ..."<<endl;
        return -1;
    }
}


void perimeter(ll * segTree,int left,int right,int l,int r,int pos,priority_queue<ll> pq,ll inserted){
    cout<<"\nThis call, pos = "<<pos<<endl;
     display(pq);
    if( segTree[pos] == 0 ){ return; }
    if( pos>=max_size){ return; }
    int mid = (l+r)/2;

    // no overlap
    if( l>right || left>r ){
        return ;
    }

    // complete overlap
    if ( l>=left && right>=r ) {

        //coming from a partial overlap to complete overlap
        if(inserted==-1){
            pq.push(segTree[pos]); q.push(segTree[pos]);
            cout<<"\nInserted "<<segTree[pos]<<endl;
            inserted = segTree[pos];
            if(check(pq)>-1){ return; }
        }

        if( segTree[2*pos+1]==0 || segTree[2*pos+2]==0 || l==r ){ return; }


        if( segTree[2*pos+1] == inserted ){
            perimeter(segTree,left,right,l,mid,2*pos+1,pq,inserted);
            pq.push(segTree[2*pos+2]); q.push(segTree[2*pos+2]);
            cout<<"\nInserted "<<segTree[2*pos+2]<<endl;
            if (check(pq)>-1){ return; }
            perimeter(segTree,left,right,mid+1,r,2*pos+2,pq,segTree[2*pos+2]);
            return;
        }
        else{
            pq.push(segTree[2*pos+1]); q.push(segTree[2*pos+1]);
            cout<<"\nInserted "<<segTree[2*pos+1]<<endl;
            if(check(pq)>-1){ return; }
            perimeter(segTree,left,right,l,mid,2*pos+1,pq,segTree[2*pos+1]);
            perimeter(segTree,left,right,mid+1,r,2*pos+2,pq,inserted);
            return;
        }
    }

    // partial overlap
    else{
        cout<<"partial overlap\n";
        perimeter(segTree,left,right,l,mid,2*pos+1,pq,-1);
        perimeter(segTree,left,right,mid+1,r,2*pos+2,pq,-1);
    }
}

int main() {
    int n,Q;
    cin>>n>>Q;
    ll A[n];
    max_size = pow(2,ceil(log2(n))+1) - 1;
    ll * segTree = new ll[max_size];
    memset(segTree,MIN,sizeof(segTree));
    loop(i,0,n) cin>>A[i];
    ll x = initialise(segTree,A,0,n-1,0);
    cout<<endl<<"Segment tree is ...";
    loop(i,0,max_size){ cout<<segTree[i]<<" "; }
    int type,l,r;
    while(Q--){
        cin>>type>>l>>r;

        if(type==1){
            update(segTree,l-1,r,0,n-1,0);
            cout<<"Updated ST";
            cout<<endl<<"Segment tree is ...";
            loop(i,0,max_size){ cout<<segTree[i]<<" "; }
        }
        else{
            q = priority_queue<ll>();
            while( !q.empty() ) q.pop();
            priority_queue<ll> pq;
            pq = priority_queue<ll>();


            perimeter(segTree,l-1,r-1,0,n-1,0,pq,-1);
            cout<<"\n\nNow this is final 'q' ";
            display(q);
            cout<<"\n Now this is the final answer ";
            cout<<check(q);
        }


    }
    return 0;
}

