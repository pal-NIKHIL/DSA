#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   string s="nikhilanaijfajnfajianfanfnfanffffapkfainhil";
   int arr[26];
   memset(arr,0,sizeof(arr));
   
   for (int i = 0; i < s.length(); i++)
   {
    arr[s[i]-97]++;
   }
   int p=*max_element(arr,arr+25);
   for (int i = 0; i < 26; i++)
   {
    if(arr[i]==p) cout<<char(97+i)<<endl;
   }
   
   cout<<p;
   
   
    return 0;
}