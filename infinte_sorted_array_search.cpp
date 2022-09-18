#include <bits/stdc++.h>
using namespace std;
#define ll long long
int bs(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return bs(arr, low, high - 1, key);
        else
            return bs(arr, mid + 1, high, key);
    }
    return -1;
}

int infintesearch(int arr[], int low, int key)
{
    int high = 1;
    while(key>arr[high]){
        low=high;
        high*=2;
    }
    return bs(arr, low, high, key);
}
int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                 140, 160, 170};
    cout << infintesearch(arr, 0, 3);
    return 0;
}