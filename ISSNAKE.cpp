#define loop(i,a,b) for(int i=a;i<b;i++)
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include<math.h>
using namespace std;

void makeA(int *A,int n,string s[]){
    loop(i,0,n)  {
    if( s[0][i] == '.'){
        if(s[1][i] == '.'){ A[i] = 0; }
        else { A[i] = 1; }
    }
    else{
        if( s[1][i] == '.' ){ A[i] = 2; }
        else{ A[i]=3; }
    }
  }
}

bool check12(int x,int y){

   if (   ( x==1  && y==2 ) || (x==2 && y==1)   ){ return true; }
    else{ return false; }
}

bool check_odd(int x,int y){
    if( check12(x,y)  ){ return true; }
    if(y==0 || x==0){ return true; }
    return false;
}
bool check_even(int x,int y){
    if( x==y && (x==1 || x==2)  ){ return true; }
    if( y==0 || x==0){ return true; }
    return false;
}

bool check123(int x){
    if( x==1 || x==2 || x==3 ){ return true; }
    else { return false; }
}

int main ()
{
    string s[2];
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;

  cin>>s[0];
  cin>>s[1];
  int A[n];
  makeA(A,n,s);
  //loop(i,0,n){ cout<<A[i]<<" "; }cout<<endl;
    int start = 0;
  loop(i,0,n){
    if( A[i]!=0 ){
        start = i; break;
    }
  }


  bool flag = 1;

    int ctr = 0;

  loop(i,1+start,n){


    if( ctr>1 ){ flag=0; break; }

    if ( A[i] == 0 ){
        if( check123(A[i-1]) ){
            ctr++;
        }
        if ( i+1<n ){
            if( check123(A[i+1]) ){
                flag = 0; break;
            }
        }
    }


    if ( check123(A[i]) ){
        if( A[i-1] == 0 ){
            ctr++;
        }
    }

    if ( check12(A[i-1],A[i]) ){  flag = 0; break; }
    if(A[i-1]==3){ continue; }
    if( A[i]== 3){
        int threes = 0;
        int j=i;
        while(A[j]==3){ threes++; j++; }
        if(j<n){
            if( threes % 2 == 1 ){
                if( !check_odd(A[i-1],A[j]) ){ flag=0; break; }
            }
            else{
                if( !check_even(A[i-1],A[j]) ){ flag=0; break; }
            }
            i=j;
        }
    }

  }


  if( flag ){ cout<<"yes\n"; }
  else{ cout<<"no\n"; }
  }
  return 0;
}























