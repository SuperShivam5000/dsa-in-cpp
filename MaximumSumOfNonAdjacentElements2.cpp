#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums){ //tabulation approach(bottom-up)
    vector<int> memo(nums.size(),-1);
    memo[0]=nums[0];
    memo[1]=max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++){
        int excl=memo[i-1];
        int incl=nums[i]+memo[i-2];
        memo[i]=max(excl,incl);
    }
    return memo[memo.size()-1];
}