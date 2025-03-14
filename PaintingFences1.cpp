#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a,int b){ //remember this function it is helpful when MOD
    return (0LL+a+b)%MOD;
}

int mul(int a,int b){ //remember this function it is helpful when MOD
    return (1LL*a*b)%MOD;
}

int solve(int n, int k, vector<int>& memo) { //recursion + memoization approach(top-down)
    if (n == 1) return k;
    if (n == 2) return add(k,mul(k,k-1));
    if (memo[n] != -1) return memo[n];

    memo[n] = add(mul(solve(n-2,k,memo),k-1),mul(solve(n-1,k,memo),k-1));
    return memo[n];
}

int numberOfWays(int n, int k) {
    vector<int> memo(n+1,-1);
    return solve(n,k,memo);
}
