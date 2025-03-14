#include <bits/stdc++.h> 

int solve(int nStairs, int i,vector<int> &memo){
    if(i==nStairs) return 1;
    if(i>nStairs) return 0;
    if(memo[i]!=-1) return memo[i];
    int ans=solve(nStairs,i+1,memo) + solve(nStairs,i+2,memo);
    int MOD = 1e9 + 7;// question did not specify to do this but its neccessary to pass testcase
    ans=ans%MOD;
    memo[i]=ans;
    return ans;
}

int countDistinctWays(int nStairs) {
    vector<int> memo(nStairs,-1);
    int i=0;
    int c=solve(nStairs,i,memo);
    return c;
}