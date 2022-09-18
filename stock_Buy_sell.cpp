#include<bits/stdc++.h>
using namespace std;
#define ll long long
// //using brute force
// int max_profit(int arr[],int n){
//     int maxprofit=INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if(maxprofit<arr[j]-arr[i]){
//                 maxprofit=arr[j]-arr[i];
//             }
//         }     
//     }
//     return maxprofit;
// }

// //using auxillary array
// int max_profit(int arr[],int n){
//     int aux[n];
//     aux[n-1]=arr[n-1];
//     for (int i = n-2; i >-1; i--)
//     {
//         if(arr[i]>aux[i+1]){
//             aux[i]=arr[i];
//         }
//         else{
//             aux[i]=aux[i+1];
//         }
//     }
//     int max=INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         if(max<aux[i]-arr[i]){
//             max=aux[i]-arr[i];
//         }
//     }
//     return max;   
// }

// //3rd method
// int max_profit(int arr[],int n){
//     int maxprofit=0;
//     int minn=INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]<minn) minn=arr[i];        
//         if(arr[i]-minn>maxprofit) maxprofit=arr[i]-minn;
//     }
//     return maxprofit;
// }

//2nd type question very buy ans sell is multiple time
int max_profit(int arr[],int n){
    int maxprofit=0;
  for (int i = 1; i < n; i++)
  {
    if(arr[i]>arr[i-1]){
        maxprofit+=(arr[i]-arr[i-1]);
    }
  }
  
    return maxprofit;
}
int main()  
{
int arr[]={5,2,7,3,6,1,2,4};
int size=sizeof(arr)/sizeof(arr[0]);
cout<<max_profit(arr,size);
    return 0;   
}