#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums){ //space optimized approach
    int a=nums[0];
    int b=max(nums[0],nums[1]);
    int c;
    for(int i=2;i<nums.size();i++){
        int incl=nums[i]+a;
        int excl=b;
        c=max(excl,incl);
        a=b;
        b=c;
    }
    return b;
}