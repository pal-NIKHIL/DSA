#include<bits/stdc++.h>
using namespace std;
#define ll long long
int majority(int arr[],int n){
    int candidate=-1,votes=0;
    for (int i = 0; i < n; i++)
    {
        if(votes==0){
            candidate=arr[i];
            votes=1;
        }
        else{
            if(arr[i]==candidate) votes++;
            else votes--;
        }
    }
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==candidate) count++;
    }
    if (count > n / 2)
        return candidate;
    return -1;
    
}
int main()
{
int arr[] = {1,5,1,2};
int size=sizeof(arr)/sizeof(arr[0]);
cout<<majority(arr,size);
    return 0;
}