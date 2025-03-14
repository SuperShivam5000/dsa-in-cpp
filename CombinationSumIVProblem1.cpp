#include <bits/stdc++.h>

int solve(vector<int> &num, int tar, vector<int> &memo){
    if(tar==0) return 1;
    if(tar<0) return 0;
    if(memo[tar]!=-1) return memo[tar];

    int ways=0;
    for(int i=0;i<num.size();i++){
        ways+=solve(num,tar-num[i],memo);
    }
    memo[tar]=ways;
    return memo[tar];
}

int findWays(vector<int> &num, int tar) //recursion + memoization approach(top-down)
{
    vector<int> memo(tar+1,-1);
    return solve(num,tar,memo);
}