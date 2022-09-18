#include <bits/stdc++.h>
using namespace std;
#define ll long long
int findSubarraySum(int arr[], int n, int k)
{
    int curr_sum = 0;
    int count = 0;
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        curr_sum+=arr[i];
        if(curr_sum==k){
            count++;
        }
        if(map.find(curr_sum-k)!=map.end()){
            count+=(map[curr_sum-k]);
            cout<<map[curr_sum-k];
        }
        map[curr_sum]++;
        
    }
    cout<<endl;
    return count;
}
int main()
{
    int arr[] = {10, 2, -2, -20, 10,5,-5};   
    int sum = -10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findSubarraySum(arr, n, sum);
    return 0;
}