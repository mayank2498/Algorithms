#include <iostream>
#include <deque>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
deque<int>::iterator it;

void display(deque<int> Q){
    cout<<endl;
    for(it=Q.begin();it!=Q.end();it++){ cout<<*it<<" "; }
}

void max_in_a_window(int arr[],int n,int k){
    deque<int> Q(k);
    loop(i,0,k){

        while( !Q.empty() && arr[i]>=arr[Q.back()] )
            {   Q.pop_back();}
        Q.push_back(i);
    }

    int * ans = new int[n-k+1];

    loop(i,k,n){
        cout<<arr[Q.front()]<<" ";
        ans[i-k] = Q.front();
        if(  !Q.empty() && Q.front() < i-k+1 ){
            Q.pop_front();
        }
        while( !Q.empty() && arr[i]>=arr[Q.back()] )
            Q.pop_back();
        Q.push_back(i);
    }
    cout<<arr[Q.front()];
}

int main()
{
    int arr[] = {5,3,4,1,6,2,2,4,3,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    max_in_a_window(arr,n,k);
    return 0;
}
