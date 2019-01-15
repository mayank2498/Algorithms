
//      https://www.geeksforgeeks.org/print-matrix-zag-zag-fashion/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define M 100
#define N 100

void zigzag(int A[M][N],int R,int C){

    loop(i,0,R){
        if(i%2){
            if(i<C){
                int col = i;
                int row = 0;
                while(col>=0 && row<R){
                    cout<<A[row++][col--]<<" ";
                }
            }else{
                int row = i+1-C;
                int col = C-1;
                while(col>=0 && row<R)
                    cout<<A[row++][col--]<<" ";
            }

        }else{
            int row = i;
            int col = 0;
            while(row>=0 && col<C){
                cout<<A[row--][col++]<<" ";
            }
        }
    }
}


int main() {
    int A[M][N]; int r,c;
    cin>>r>>c;
    loop(i,0,r) loop(j,0,c) cin>>A[i][j];
    zigzag(A,r,c);
	return 0;
}

