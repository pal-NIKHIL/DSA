#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int n)
{
	int max_sum = INT_MIN; //INT_MIN means largest negative value
	int curr_sum = 0;

	for (int i = 0; i < n; i++)
	{
	    curr_sum+=a[i];
	    if(max_sum<curr_sum){
	        max_sum=curr_sum;
	    }
	    if(curr_sum<0){
	        curr_sum=0;
	    }
	}
	return max_sum;
}
int main()
{
	int a[] = {-2, 6, -4, 1, 2, -1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<maxSubArraySum(a, n);
	return 0;
}

