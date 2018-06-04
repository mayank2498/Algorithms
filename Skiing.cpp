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

    // to print the longest common subsequence

    int i=m,j=n,ctr=0;
    char ans[100000];
    while(i>0 && j>0){
        if ( dp[i][j] != dp[i-1][j] && dp[i][j] != dp[i][j-1]  ) {
            //cout<<dp[i][j]<<" : "<<B[j-1]<<" ";
            ans[ctr++] = B[j-1];
            i--; j--;
        }
        else if ( dp[i-1][j] == dp[i][j] ){
            i--;
        }
        else{
            j--;
        }
    }

    cout<<ctr<<endl;
    loop(i,0,ctr){ cout<<ans[ctr-i-1]; }

}


int main() {
    string str1 = "AXYT";
    string str2 = "AYZX";
    LCS(str1,str2,str1.length(),str2.length());

    return 0;
}
