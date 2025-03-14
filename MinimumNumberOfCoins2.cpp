#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x) //tabulation approach(bottom up)
{
    vector<int> memo(x+1,INT_MAX);
    memo[0]=0;
    for(int i=1;i<=x;i++){//for every number we solve
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && memo[i-num[j]]!=INT_MAX) memo[i]=min(memo[i],1 + memo[i-num[j]]);
        }
    }
    if(memo[x]==INT_MAX) return -1;
    else return memo[x];
}