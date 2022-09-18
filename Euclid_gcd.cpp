#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a; // because gcd(0,x)=x
    cout<<a<<" "<<b<<endl;
    return gcd(b,a%b);
}
int main()
{
    cout<<gcd(60,24);

    return 0;
}