//   https://practice.geeksforgeeks.org/problems/count-total-set-bits/0
//   https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
	


#include<iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main()
{   
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int len = log2(n)+1;
        int ans = 0;
        loop(i,0,len){
            int b = pow(2,i+1);
            int x = (n+1)/b;
            ans += x*(b/2);
            int rem = (n+1)%b;
            if(rem>b/2){
                ans += rem-(b/2);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}







