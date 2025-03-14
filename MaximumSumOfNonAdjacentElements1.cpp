#include <bits/stdc++.h>
int solve(vector<int> &nums,int i, vector<int> &memo){ //recursion + memoization approach(top-down)
    if(i>=nums.size()) return 0;
    if(memo[i]!=-1) return memo[i];
    int excl=solve(nums,i+1,memo);
    int incl=nums[i]+solve(nums,i+2,memo);
    memo[i] = max(excl,incl); //in this code we go left to right, we can also go right to left like we do in tabulation approach
    return memo[i];
} 
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> memo(nums.size(),-1);
    return solve(nums,0,memo);
}