#include <bits/stdc++.h>
using namespace std;
#define ll long long
// int countDistinct(int arr[],int n){
//     int res=1;
//     for (int i = 1; i < n; i++)
//     {
//         int j=0;
//         for (j = 0; j <i; j++)
//         {
//             if(arr[i]==arr[j]) break;
//         }
//          if(i==j) 
//          {
//             cout<<i<<" "<<j<<endl;
//             cout<<"YES"<<endl;
//             res++;
//          }
//     }
//     return res;
// }
// int countDistinct(int arr[], int n)
// {
//     // First sort the array so that all
//     // occurrences become consecutive
//     sort(arr, arr + n);
 
//     // Traverse the sorted array
//     int res = 0;
//     for (int i = 0; i < n; i++) {
 
//         // Move the index ahead while
//         // there are duplicates
//         while (i < n - 1 && arr[i] == arr[i + 1])
//             i++;
 
//         res++;
//     }
 
//     return res;
// }
int countDistinct(int arr[],int n){
    unordered_set<int> s;
    int res=0;
    for (int i = 0; i < n; i++)
    {
        if(!s.count(arr[i])){
            s.insert(arr[i]);
            res++;
        }
    }
    return res;
    
}
int main()
{   
    int arr[] = { 2, 9, 10, 10, 10, 12, 45, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countDistinct(arr, n);
    return 0;
}