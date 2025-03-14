#include <bits/stdc++.h>
#define MOD 1000000007

long long int countDerangements(int n) { //tabulation method(bottom-up)
    vector<long long int> memo(n+1,-1);
    memo[1]=0;
    memo[2]=1;
    for(int i=3;i<=n;i++){
        memo[i]=((i-1)%MOD*(memo[i-1]%MOD+memo[i-2]%MOD))%MOD;
    }
    return memo[n];
}