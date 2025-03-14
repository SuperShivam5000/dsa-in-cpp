class Solution {
    public:
        int maxProfit(int k, vector<int> &prices) { //space optimized solution using transaction no. logic
            int n=prices.size();

            vector<int> curr(2*k+1,0); //memo[i]
            vector<int> next(2*k+1,0); //memo[i+1]
            
            for(int i=n-1;i>=0;i--){
                for(int transactionNo=2*k-1;transactionNo>=0;transactionNo--){
                    if(transactionNo%2==0){
                        int a = -prices[i] + next[transactionNo+1];
                        int b = next[transactionNo];
                        curr[transactionNo] = max(a,b);
                    }
                    else{
                        int a = prices[i] + next[transactionNo+1];
                        int b = next[transactionNo];
                        curr[transactionNo] = max(a,b);
                    }
                }
                next=curr;
            }

            return next[0];
        }
    };