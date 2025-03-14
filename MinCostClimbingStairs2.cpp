class Solution {
    int solve(vector<int>& cost,int n){
        vector<int> dp(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        dp[n]=min(dp[n-1],dp[n-2]); //remember that nth stair doesnt have its cost included since we dont jump from there
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) { //tabulation method(bottom up)
        int n=cost.size();
        return solve(cost,n);
    }
};