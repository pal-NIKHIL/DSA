#include<bits/stdc++.h>
using namespace std;
int bs(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        if(arr[low]<arr[mid]){
            if(key>=arr[low] && key<arr[mid]){
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else{
                if(key<=arr[high] && key>arr[mid]){
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                 140, 160, 170};
    cout << bs(arr,12 ,3 );
    return 0;
}