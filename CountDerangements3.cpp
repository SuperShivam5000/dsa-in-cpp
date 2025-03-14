#include <bits/stdc++.h>
#define MOD 1000000007

long long int countDerangements(int n) { //space optimized approach
    long long int a=0;
    long long int b=1;
    long long int c;
    for(int i=3;i<=n;i++){
        c=((i-1)%MOD*(a%MOD+b%MOD))%MOD;
        a=b;
        b=c;
    }
    return b;
}