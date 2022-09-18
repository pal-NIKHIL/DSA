#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   
int a=22;
int b=27;
a=a^b;
int count=0;
// for(int i=0;i<3;i++){
//     if(a&1){
//         count++;
//     }
//     a>>1;
// }
while(a!=0){
    count++;
    a=a&(a-1);
}
cout<<count;
    return 0;
} 