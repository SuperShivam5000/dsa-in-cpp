#include <bits/stdc++.h>
#define MOD 1000000007

long long solve(int n,vector<int> &memo){
    if(n==1) return 0;
    if(n==2) return 1;
    if(memo[n]!=-1) return memo[n];

    memo[n]=((n-1)%MOD*(solve(n-1,memo)%MOD+solve(n-2,memo)%MOD))%MOD;
    return memo[n];
}

long long int countDerangements(int n) { //recursion+memoization approach(top-down)
    vector<int> memo(n+1,-1);
    return solve(n,memo)%MOD;
}