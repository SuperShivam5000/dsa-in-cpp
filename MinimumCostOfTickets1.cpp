int solve(int n, vector<int> &days, vector<int> &cost,int i, vector<int> &memo){
    if(i>=n) return 0;
    if(memo[i]!=-1) return memo[i];

    //1 day
    int c1=cost[0]+solve(n,days,cost,i+1,memo);

    //7 day
    int j=i;
    while(j<n&&days[j]<days[i]+7) j++;
    int c2=cost[1]+solve(n,days,cost,j,memo);

    //30 day
    j=i;
    while(j<n&&days[j]<days[i]+30) j++;
    int c3=cost[2]+solve(n,days,cost,j,memo);

    memo[i] = min(c1,min(c2,c3));
    return memo[i];
}

int minimumCoins(int n, vector<int> &days, vector<int> &cost) //recursion + memoization approach(top-down)
{
    vector<int> memo(n,-1);
    return solve(n,days,cost,0,memo);
}