class Solution {
    int solve(vector<int> &memo,vector<int>& cost,int n){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        if(memo[n]!=-1) return memo[n];
        memo[n]=cost[n]+min(solve(memo,cost,n-1),solve(memo,cost,n-2));
        return memo[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) { //recursion + memoization approach (top-down)
        int n=cost.size();
        vector<int> memo(n+1,-1);
        memo[n]=min(solve(memo,cost,n-1),solve(memo,cost,n-2)); //remember that nth stair doesnt have its cost included since we dont jump from there
        return memo[n];
    }
};