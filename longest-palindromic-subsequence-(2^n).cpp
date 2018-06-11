// longest palidromic subsequence

// recursive exponential solution 2^n

#include<bits/stdc++.h>
using namespace std;

int count = 0;
int lps(char x[],int i,int j){
    ::count++;
    //cout<<"i = "<<i<<" , j = "<<j<<endl;
    if(i==j){
        return 1;
    }

    // if last 2 characters are equal

    if(x[i] == x[j]){
        if(i+1==j){
            return 2;
        }
        else{
            return 2+lps(x,i+1,j-1);
        }
    }

    // if last 2 characters are unequal

    return max( lps(x,i,j-1) , lps(x,i+1,j));
}

int main()
{
    char input[] = "abgbda";
    int len = strlen(input);
    cout<<lps(input,0,len-1);
    cout<<endl<<"\n\n called "<<::count<<"  times";
    return 0;
}

