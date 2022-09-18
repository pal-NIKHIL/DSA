#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int t){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
cin>>arr[i];
}
vector<bool> data(n);
data.assign(n,false);
int ans;
for (int i = 0; i < n; i++)
{
    if(arr[i]>-1){
        data[i]=true;
    }
}
for (int i = 1; i < n; i++)
{
    if(data[i]==1 && data[i-1]==1){
        cout<<ceil((arr[i]+arr[i-1])/2);
    }
}



}
int main()
{
int t;
cin>>t;
solve(t);
    return 0;
}