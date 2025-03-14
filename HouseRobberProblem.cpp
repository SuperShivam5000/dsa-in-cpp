#include <bits/stdc++.h> 

long long int rob(vector<int>& nums)
{
    long long int a=nums[0];
    long long int b=max(nums[0],nums[1]);
    long long int c;
	for(int i=2;i<nums.size();i++)
	{
		long long int incl=nums[i]+a;
		long long int excl=b;
		c=max(incl,excl);
		a=b;
		b=c;
	}
	return b;
}

long long int houseRobber(vector<int>& valueInHouse) //special case of MaximumSumOfNonAdjacentElements
{
    vector<int> arr1=valueInHouse;
    vector<int> arr2=valueInHouse;
    
    arr1.erase(arr1.begin());
    arr2.erase(arr2.end()-1);

    long long int a1=rob(arr1);
    long long int a2=rob(arr2);
    return max(a1,a2);
}