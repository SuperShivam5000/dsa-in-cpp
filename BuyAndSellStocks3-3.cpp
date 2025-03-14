class Solution {
    public:
        int maxProfit(vector<int> &prices) { //space optimized solution
            int n=prices.size();
            
            vector<vector<int>> curr(2,vector<int>(3,0)); //memo[i]
            vector<vector<int>> next(2,vector<int>(3,0)); //memo[i+1]

            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    for(int limit=1;limit<=2;limit++){
                        if(buy){
                            int a = -prices[i] + next[0][limit];
                            int b = next[1][limit];
                            curr[buy][limit] = max(a,b);
                        }
                        else{
                            int a = prices[i] + next[1][limit-1];
                            int b = next[0][limit];
                            curr[buy][limit] = max(a,b);
                        }
                    }
                    next=curr;
                }
            }

            return next[1][2];
        }
    };