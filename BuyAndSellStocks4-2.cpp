class Solution {
    public:
        int solve(int i, int transactionNo, int k, vector<int> &prices, vector<vector<int>> &memo){
            if(i==prices.size() || transactionNo==2*k) return 0;
            if(memo[i][transactionNo]!=-1) return memo[i][transactionNo];
    
            if(transactionNo%2==0){
                int a = -prices[i] + solve(i+1,transactionNo+1,k,prices,memo);
                int b = solve(i+1,transactionNo,k,prices,memo);
                return memo[i][transactionNo] = max(a,b);
            }
            else{
                int a = prices[i] + solve(i+1,transactionNo+1,k,prices,memo);
                int b = solve(i+1,transactionNo,k,prices,memo);
                return memo[i][transactionNo] = max(a,b);
            }
        }
        int maxProfit(int k, vector<int> &prices) { //recursion+memoization solution(top-down) using transaction no. logic
            int n=prices.size();
            vector<vector<int>> memo(n,vector<int>(2*k,-1));
            return solve(0,0,k,prices,memo);
        }
    };