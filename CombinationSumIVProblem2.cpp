#include <bits/stdc++.h> 

int findWays(vector<int> &num, int tar) //tabulation approach(bottom-up)
{
    vector<int> memo(tar+1,0);
    memo[0]=1;
    for(int i=1;i<=tar;i++){
        int ways=0;
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0) ways+=memo[i-num[j]];
        }
        memo[i]=ways;
    }
    return memo[tar];
}