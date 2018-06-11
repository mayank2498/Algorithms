// a program to implement modular exponentiation
// calculating  (x^y)%p  in log(y) time

#include<iostream>
using namespace std;


int modExponentiation(int x,int y,int p){
    int res = 1;
    x = x%p;
    while(y){
        //cout<<"x : "<<x<<endl;

        // check last bit of y , if it is set
        if( y&1 ){
            res = ( res * x ) % p;
        }

        // right shift y to get next bit in next iteration
        y = y>>1;

        x = (x*x) % p;
    }
    return res;
}


int main(){
    int x = 5;
    int y = 40;
    int p = 7;

    cout<<modExponentiation(x,y,p);
}






















