#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool checkpalindrome(string s,int l,int r){
   if(l>=r) return true;
   if(s[l]!=s[r]) return false;
   return checkpalindrome(s,l+1,r-1);
}
int main()
{           
   if(checkpalindrome("racecar",0,6)) cout<<"YES";
   else cout<<"no";
}   