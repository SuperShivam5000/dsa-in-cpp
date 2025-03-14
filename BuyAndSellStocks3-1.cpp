class Solution {
    public:
        int solve(int i, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &memo){
            if(i==prices.size() || limit==0) return 0;
            if(memo[i][buy][limit]!=-1) return memo[i][buy][limit];
    
            if(buy){
                int a = -prices[i] + solve(i+1,0,limit,prices,memo);
                int b = solve(i+1,1,limit,prices,memo);
                return memo[i][buy][limit] = max(a,b);
            }
            else{
                int a = prices[i] + solve(i+1,1,limit-1,prices,memo);
                int b = solve(i+1,0,limit,prices,memo);
                return memo[i][buy][limit] = max(a,b);
            }
        }
        int maxProfit(vector<int> &prices) { //recursion+memoization solution(top-down)
            vector<vector<vector<int>>> memo(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
            return solve(0,1,2,prices,memo);
        }
    };