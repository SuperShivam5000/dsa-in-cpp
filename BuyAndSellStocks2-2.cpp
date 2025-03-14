class Solution {
    public:
        int maxProfit(vector<int> &prices) { //tabulation solution(bottom-up)
            int n=prices.size();
            vector<vector<int>> memo(n+1,vector<int>(2,0));
            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    if(buy){
                        int a = -prices[i] + memo[i+1][0];
                        int b = memo[i+1][1];
                        memo[i][buy] = max(a,b);
                    }
                    else{
                        int a = prices[i] + memo[i+1][1];
                        int b = memo[i+1][0];
                        memo[i][buy] = max(a,b);
                    }
                }
            }
            return memo[0][1];
        }
    };