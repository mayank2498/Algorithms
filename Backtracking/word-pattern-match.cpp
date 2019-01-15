// Match a pattern and String without using regular expressions
// for example

//Input:
//string - GraphTreesGraph
//pattern - aba


//Output:
//a->Graph
//b->Trees


#include<bits/stdc++.h>
#include <string.h>
#define loop(i,a,b) for(long i=a;i<b;i++)

using namespace std;


void displayMap(unordered_map<char,string> map){
    for (auto it = map.begin(); it != map.end(); it++)
    cout << it->first << "->" << it->second << endl;
}

bool recurr(string str,int m,int i,string pat,int n,int j,unordered_map<char,string> &map){
    cout<<"i = "<<i<<" , j= "<<j<<" "<<endl;
    //displayMap(map);
    cout<<endl;

    if(i==m && j==n){
     cout<<"FOUNDDDDDDDDDDDDD!";
     return true;
    }

    if (i == m || j == n)
    {return false;}


    char ch = pat[j];

    cout<<"ch =  "<<ch<<endl;
    // if ch is already in map check str

    if(map.find(ch)!=map.end()){
        string s = map[ch];
        string snew = str.substr(i,s.size());
        cout<<"s = "<<s<<" , snew = "<<snew<<" : "<<(s==snew)<<endl;
        if ( s == snew ){
            cout<<"Equal\n";
            return recurr(str,m,i+s.size(),pat,n,j+1,map);
        }
        return false;
    }

    // if ch is not present in map
    loop(len,1,m-i+1){
        map[ch] = str.substr(i,len);
        if  ( recurr(str,m,i+len,pat,n,j+1,map)  ) {
            return true;
        }
        map.erase(ch);
    }
    return false;
}


bool patternMatch(string str,string pat,int m,int n){
    if(n>m){ return false; }
    unordered_map<char,string> map;
    bool result = recurr(str,m,0,pat,n,0,map);
    if(result){cout<<endl<<endl; displayMap(map);   return true;}
    return false;
}

int main()
{
    string str = "xyzxy", pat = "aba";
    int m = str.size(), n = pat.size();
    if ( !patternMatch(str,pat,m,n) ){
        cout<<"Does not exists...";
    }
    return 1;
}