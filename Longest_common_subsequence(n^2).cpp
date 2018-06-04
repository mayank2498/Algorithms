#define loop(i,a,b) for(int i=a;i<b;i++)
#include <cmath>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void LCS(string A, string B,int m, int n){
    int dp[m+1][n+1];
    loop(i,0,m+1){
        loop(j,0,n+1){
            if( i==0 || j==0 ){ dp[i][j] = 0; }

            else if ( A[i-1] == B[j-1] ){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
            }

        }
    }

    loop(i,0,m+1){
        loop(j,0,n+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}





int main() {

    //LCS(str1,str2,str1.length(),str2.length());

    return 0;
}
