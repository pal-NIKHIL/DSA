#include<bits/stdc++.h>
using namespace std;
//1 20 7 spiral order mean printing like[1 20 7 5 20 8 9 20 6]
//20 6 5
//9 8 20
int main()
{   int row=4,col=4;
    int arr[row][col]={{1,2,3,14},
                       {4,5,6,15},
                       {7,8,9,16},
                       {10,11,12,13}};
    for (int i = 0; i < row; i++)
    {
        for (int j = i+1; j < col; j++)
        {
            if(i!=j){
                swap(arr[i][j],arr[j][i]);
            }
        }
        
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}