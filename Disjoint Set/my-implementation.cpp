// Disjoint set Union and Find methods
// Using path compression

#define f(i,a,b) for(int i=a;i<b;i++)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);

struct cell {
    int data;
    cell * parent ;
    int rankk;
};

map<int,cell *> m;

void Insert(int x){
    cell * mycell = new cell ;
    mycell->data = x;
    mycell->parent = mycell;
    mycell->rankk = 0;
    m[x] = mycell;
}

cell * find_leader(cell * element){
    if( element->parent == element ){
        return element;
    }
    element->parent = find_leader(element->parent);
    return element->parent;
}

void Union(int x,int y){
    cell * p = m[x];
    cell * q = m[y];
    cell * leader_p = find_leader(p);
    cell * leader_q = find_leader(q);

    if(leader_p->rankk >= leader_q->rankk){
        // make leader of p as the root and increment its rank
        leader_q->parent = leader_p;
        leader_p->rankk++;
    }else {
        // make leader of q as the root and make p his child & increment rank
        leader_p->parent = leader_q;
        leader_q->rankk++;
    }
}

int leader(int x){
    return find_leader(m[x])->data;
}

int main() {
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);

    Union(1,2);
    Union(3,4);

    cout<<leader(2)<<endl;
    cout<<leader(3)<<endl;

    Union(1,3);

    cout<<leader(4)<<leader(3)<<leader(2)<<endl;
    return 0;
}

