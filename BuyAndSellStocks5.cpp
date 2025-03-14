class Solution {
    public:
        int maxProfit(vector<int> &prices, int fee) { //space optimized solution, same logic as BuyAndSellStocks2-3 just with fees
            int n=prices.size();
    
            vector<int> curr(2,0); //memo[i]
            vector<int> next(2,0); //memo[i+1]
    
            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    if(buy){
                        int a = -prices[i] + next[0];
                        int b = next[1];
                        curr[buy] = max(a,b);
                    }
                    else{
                        int a = prices[i] + next[1] - fee;
                        int b = next[0];
                        curr[buy] = max(a,b);
                    }
                }
                next=curr;
            }
            
            return next[1];
        }
    };