// knapsack problem

#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
using namespace std;

void calc(int * val,int * wts,int n,int w){

    int dp[n+1][w+1];
    loop(i,0,n+1) dp[i][0] = 0;    // case when target weight is zero
    loop(i,0,w+1) dp[0][i] = 0;  // case when no weight is present

    loop(i,1,n+1){
        loop(j,1,w+1){
            if(j< wts[i-1]){
                dp[i][j] = dp[i-1][j];  // if current weight is greater than target weight discard this weight and copy answer of upper row
            }
            else{
                dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-wts[i-1]]);
                //  max(dont select , select)
            }
        }
    }
    loop(i,0,n+1){
        loop(j,0,w+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // tracing the path
//    int ans = dp[n][w];
//    int j=w;
//    stack st;
//    for(int i=n-1;i>=0;i--){
//        if( ans != dp[i][j] ){
//            st.push(1);
//            ans -= val[i+1];
//        }
//        else{
//            st.push(0);
//            while(dp[i-1][j])
//        }
//    }

}
int main()
{
    int val[] = {1,2,5,6}; // or profits for the corresponding weight
    int wts[] = {2,3,4,5};
    int n = sizeof(val)/sizeof(val[0]);  // number of weights available
    int w = 8;   // total weight must be less than equal to this
    calc(val,wts,n,w);

    return 0;
}