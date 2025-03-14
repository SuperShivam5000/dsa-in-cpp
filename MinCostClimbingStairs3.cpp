class Solution {
    int solve(vector<int>& cost,int n){
        vector<int> dp(n+1,-1);
        int a=cost[0];
        int b=cost[1];
        int c;
        for(int i=2;i<n;i++){
            c=min(a,b)+cost[i];
            a=b;
            b=c;
        }
        return min(a,b); //remember that nth stair doesnt have its cost included since we dont jump from there
    }
public:
    int minCostClimbingStairs(vector<int>& cost) { //space optimized solution (SC=o(1))
        int n=cost.size();
        return solve(cost,n);
    }
};