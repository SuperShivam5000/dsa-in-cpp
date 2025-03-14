#include <bits/stdc++.h> 
int solve(vector<int> &num, int x, vector<int> &memo){
    if(x==0) return 0;
    if(x<0) return INT_MAX; //invalid
    if(memo[x]!=-1) return memo[x];

    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i],memo);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    memo[x] = mini;
    return memo[x];
}
int minimumElements(vector<int> &num, int x) //recursion+memo approach(top-down)
{
    vector<int> memo(x+1,-1);
    int mini=solve(num,x,memo);
    if(mini==INT_MAX) return -1;
    else return mini;
}