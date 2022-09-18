    #include <bits/stdc++.h>
    using namespace std;
#define ll long long
    int main() {
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            vector<ll> a(n);
            for (ll i = 0; i < n; i++) {
                cin>>a[i];
                }
                sort(a.begin(),a.end());
                ll minn=1e18;
        ll maxx=max(a[0]*a[0],a[n-1]*a[n-1]);
        if(a[0]<0 &&a[n-1]>0){
                minn=a[0]*a[n-1];
        }
        else{
           for (ll   i = 0; i < n; i++)
           {
            minn=min(minn,a[i]*a[i]);
           }
           
        }
        cout<<minn<<" "<<maxx<<endl;
        }
        return 0;
    }