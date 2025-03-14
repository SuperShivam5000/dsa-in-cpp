class Solution {
    public:
        int maxProfit(vector<int> &prices) { //tabulation solution(bottom-up)
            int n=prices.size();
            vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(2,vector<int>(3,0)));

            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    for(int limit=1;limit<=2;limit++){
                        if(buy){
                            int a = -prices[i] + memo[i+1][0][limit];
                            int b = memo[i+1][1][limit];
                            memo[i][buy][limit] = max(a,b);
                        }
                        else{
                            int a = prices[i] + memo[i+1][1][limit-1];
                            int b = memo[i+1][0][limit];
                            memo[i][buy][limit] = max(a,b);
                        }
                    }
                }
            }
            
            return memo[0][1][2];
        }
    };