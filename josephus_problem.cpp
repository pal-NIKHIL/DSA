#include<bits/stdc++.h>
using namespace std;
#define ll long long
int josephus(int n,int k){
    if(n==1) return 0;
    return (josephus(n-1,k)+k)%n;
}
int main()
{
cout<<(josephus(5,2));
    return 0;
}