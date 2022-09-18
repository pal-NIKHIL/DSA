#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
        int a[]={3,1,2,2,4,1,3,2};
        int size=sizeof(a)/sizeof(a[0]);
        int left[size]={a[0]};
        int right[size];
        right[size-1]=a[size-1];
        for (int i = 1; i < size; i++)
        {
            left[i]=max(left[i-1],a[i]);    
        }
        for (int i = size-2; i >=0; i--)
        {
             right[i]=max(right[i+1],a[i]);    
        }
        int ans=0;
        for (int i = 0; i < size; i++)
        {
            ans+=abs(a[i]-min(left[i],right[i]));
        }
        cout<<ans;
        
}