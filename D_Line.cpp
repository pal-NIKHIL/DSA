#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int t){
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
       ll sum=0;
       vector<ll> current(n,0),change(n,0);
        for (ll i = 0; i < n; i++)
        {
            if(s[i]=='L') current[i]=max(0LL,i);
            else current[i]=max(0LL,n-i-1);
            change[i]=n-1-current[i];
            cout<<current[i]<<" "<<change[i]<<endl;
            change[i]-=current[i];
            cout<<change[i]<<endl;
            sum+=current[i];
        }
            cout<<"sum"<<sum<<endl;
         sort(change.begin(),change.end(), greater<long long>());
        for(long long k=1;k<=n;k++){
            if(change[k-1]>0){
                sum+=change[k-1];
            }
            cout<<sum<<" ";
        }
        cout<<endl;
        
    }
}
int main()
{
int t;
cin>>t;
solve(t);
    return 0;
}