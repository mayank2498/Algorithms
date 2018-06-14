// longest palidromic subsequence
// dynamic programming


#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;


void showdp(int * dp[],int size){
    loop(i,0,size){
        loop(j,0,size){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int lps(char x[],int size){
    int dp[size][size];

    // consider the case of aaa
    // we will need to set values to 0
    memset(dp,0,sizeof(dp));


    // single letters will be palindromic of length = 1
    loop(i,0,size){ dp[i][i] = 1;}


    int len = size-1;

    while(len!=0){
        int i = 0;
        loop(j,size-len,size){
            //cout<<"i = "<<i<<" , j = "<<j<<endl;
            if( x[i] == x[j] ){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
            i++;
        }
        len--;
    }


    // displaying the dp table
    int * dpnew[size];
    loop(i,0,size) { dpnew[i] = dp[i]; }
    showdp(dpnew,size);


    return dp[0][size-1];
}


int main()
{
    char input[] = "geeksforgeeks";
    int len = strlen(input);
    cout<<"Longest palindromic subsequence : "<<lps(input,len);

    return 0;
}

