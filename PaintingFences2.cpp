#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a,int b){ //remember this function it is helpful when MOD
    return (0LL+a+b)%MOD;
}

int mul(int a,int b){ //remember this function it is helpful when MOD
    return (1LL*a*b)%MOD;
}

int numberOfWays(int n, int k) { //tabulation approach(bottom-up)
    vector<int> memo(n+1,-1);
    memo[1]=k;
    memo[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        memo[i]=add(mul(memo[i-2],k-1),mul(memo[i-1],k-1));
    }
    return memo[n];
}
