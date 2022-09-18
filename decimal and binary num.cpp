#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num=45;
    vector<int> binarynums;
    while(nums!=0){
        binarynums.push_back(num%2);
        num=num/10;
    }
    for (int i = 0; i < binarynums.size(); i++)
    {
        cout<<binarynums[i]<<" ";
    }
    
    return 0;
}