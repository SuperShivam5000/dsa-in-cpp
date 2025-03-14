class Solution {
    public:
        int maxProfit(int k, vector<int> &prices) { //tabulation solution(bottom-up) using transaction no. logic
            int n=prices.size();
            vector<vector<int>> memo(n+1,vector<int>(2*k+1,0));
            
            for(int i=n-1;i>=0;i--){
                for(int transactionNo=2*k-1;transactionNo>=0;transactionNo--){
                    if(transactionNo%2==0){
                        int a = -prices[i] + memo[i+1][transactionNo+1];
                        int b = memo[i+1][transactionNo];
                        memo[i][transactionNo] = max(a,b);
                    }
                    else{
                        int a = prices[i] + memo[i+1][transactionNo+1];
                        int b = memo[i+1][transactionNo];
                        memo[i][transactionNo] = max(a,b);
                    }
                }
            }

            return memo[0][0];
        }
    };