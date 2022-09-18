#include<bits/stdc++.h>
using namespace std;
#define ll long long
int substring(string s,int i,string current,int count){
    if(i==s.length()){
       return count;
    }
    substring(s,i+1,current+s[i],count++);
    substring(s,i+1,current,count++);
    return count;
}
int main()
{
string s="pal";
cout<<substring(s,0," ",0);

    return 0;
}