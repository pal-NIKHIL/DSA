#include<iostream>
using namespace std;
#define ll long long
int main()
{
 for (int i = 1; i <=5; i++)
 {
    int j;
   for (j = 1; j <=5-i; j++)
   {
    cout<<" ";
   }
   int k=i;
   for(;j<=5;j++){
    cout<<k--;
   }
   k=2;
   for(;j<=5+i-1;j++){
    cout<<k++;
   }
    cout<<endl;
 }
 
}