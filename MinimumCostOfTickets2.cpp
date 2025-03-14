int minimumCoins(int n, vector<int> &days, vector<int> &cost) //tabulation approach(bottom-up)
{
    vector<int> memo(n+1,INT_MAX);
    memo[n]=0;
    for(int k=n-1;k>=0;k--){
        //1 day
        int c1=cost[0]+memo[k+1];

        //7 day
        int j=k;
        while(j<n&&days[j]<days[k]+7) j++;
        int c2=cost[1]+memo[j];

        //30 day
        j=k;
        while(j<n&&days[j]<days[k]+30) j++;
        int c3=cost[2]+memo[j];

        memo[k] = min(c1,min(c2,c3));
    }
    
    return memo[0];
}