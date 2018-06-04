#define loop(i,a,b) for(int i=a;i<b;i++)
#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int wild_card_matching(int ** dp,int rows,int cols,string str,string pattern){
    dp[0][0] = 1; // empty strings always match
    if( pattern[0] == '*' ) { dp[0][1] = 1; }

    loop(i,1,rows){
        loop(j,1,cols){
            if(pattern[j-1]=='?' || pattern[j-1]==str[i-1] ){
                dp[i][j] = dp[i-1][j-1];
            }
            else if( pattern[j-1] == '*' ){
                dp[i][j] =  dp[i][j-1] || dp[i-1][j] ;
            }
        }
    }
    return dp[rows-1][cols-1];
}

int ** construct_dp(int rows,int cols){
    int ** dp = new int *[rows];
    loop(i,0,rows){
        dp[i] = new int[cols];
        //initialise all elements of dp matrix as 0
        loop(k,0,cols){ dp[i][k] = 0; }
    }
    return dp;
}

int main() {
    string str = "xaylmz"; int rows = str.size();
    string pattern = "x?y*z"; int cols = pattern.size();
    // 2d matrix with 0 initial values

    int **dp = construct_dp(rows+1,cols+1);

    if ( wild_card_matching(dp,rows+1,cols+1,str,pattern) == 1 ){
        cout<<"Pattern matches\n";
    }
    else{
        cout<<"DOEST NOT MATCH\n";
    }

    // display dp table
    cout<<"\n\n DP TABLE : \n\n";
    loop(i,0,rows+1){
        loop(j,0,cols+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

