#include<bits/stdc++.h>
using namespace std;
#define ll long long
void permutation_string(string s,int l,int r){
   if(l==r){
    cout<<s<<endl;
    return;
   }
   for (int i = l; i <=r; i++)
   {
    swap(s[l],s[i]);
    permutation_string(s,l+1,r);
    swap(s[l],s[i]);
   }
   

    
}
int main()
{
string s="pal";
permutation_string(s,0,2);

    return 0;
}