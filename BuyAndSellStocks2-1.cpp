class Solution {
    public:
        int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &memo){
            if(i==prices.size()) return 0;
            if(memo[i][buy]!=-1) return memo[i][buy];
    
            if(buy){
                int a = -prices[i] + solve(i+1,0,prices,memo);
                int b = solve(i+1,1,prices,memo);
                return memo[i][buy] = max(a,b);
            }
            else{
                int a = prices[i] + solve(i+1,1,prices,memo);
                int b = solve(i+1,0,prices,memo);
                return memo[i][buy] = max(a,b);
            }
        }
        int maxProfit(vector<int> &prices) { //recursion+memoization solution(top-down)
            vector<vector<int>> memo(prices.size(),vector<int>(2,-1));
            return solve(0,1,prices,memo);
        }
    };