// Word break problem using simple recursion - inefficient

#include<bits/stdc++.h>
#include <iostream>
#define loop(i,a,b) for(long i=a;i<b;i++)


using namespace std;

bool dictionaryContains(string s){
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    loop(i,0,size){
        if( dictionary[i].compare(s) == 0 )
        return true;
    }
    return false;
}

bool wordbreak(string s){
    cout<<s;
    int size = s.size();
    if( size==0 ){ return true; }
    loop(i,0,size+1){
        if( dictionaryContains(s.substr(0,i)) ){
            cout<<"  Sending "<<s.substr(i,size-i)<<endl;
            return wordbreak(s.substr(i,size-i));
        }
    }
    return false;
}

int main()
{
    if( wordbreak("ilikesamsungmobi") ) { cout<<"YES"; }
    else { cout<<"No"; }
    return 1;
}

