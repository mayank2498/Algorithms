#define loop(i,a,b) for(int i=a;i<b;i++)
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

long long permutations = 0;

void display(char * result,int size){
    loop(i,0,size){ cout<<result[i]<<" "; }
    cout<<endl;
}

void permute(char*unique,int*count,int size,int res_len,char*result,int level){
    if ( level == res_len  ){
        ::permutations++;
        display(result,res_len);
        return;
    }
    else{
        loop(i,0,size){
            if( count[i] > 0 ){
                count[i]--;
                result[level] = unique[i];
                permute(unique,count,size,res_len,result,level+1);
                count[i]++;
            }
        }
    }
}

void initialise_map(string str){
  unordered_map<char,int> mymap;
  set<char> myset;
  set<char>:: iterator it;
  loop(i,0,str.length()){
    if( myset.find(str[i]) == myset.end() ){
        myset.insert(str[i]);
        mymap[str[i]] = 1;
    }
    else{
        mymap[str[i]]++;
    }
  }
  char * unique = new char[myset.size()];
  int * count = new int[myset.size()];
  int i=0;
  for(it=myset.begin();it!=myset.end();it++){
    unique[i] = *it;
    count[i++] = mymap[*it];
  }


  char * result = new char[str.length()];
  permute(unique,count,myset.size(),str.length(),result,0);
}

int main ()
{


  string str = "aabcdefg";
  initialise_map(str);
  cout<<"\nNumber of permutations : "<<::permutations;
  return 0;
}
