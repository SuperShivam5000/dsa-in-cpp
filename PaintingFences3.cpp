#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a,int b){ //remember this function it is helpful when MOD
    return (0LL+a+b)%MOD;
}

int mul(int a,int b){ //remember this function it is helpful when MOD
    return (1LL*a*b)%MOD;
}

int numberOfWays(int n, int k) { //space optimized approach
    int a=k;
    int b=add(k,mul(k,k-1));
    int c;
    for(int i=3;i<=n;i++){
        c=add(mul(a,k-1),mul(b,k-1));
        a=b;
        b=c;
    }
    return b;
}
