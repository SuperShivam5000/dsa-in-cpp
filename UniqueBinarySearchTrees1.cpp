class Solution {
    public:
        int solve(int n, vector<int> &memo) {
            if(n==0 || n==1) return 1;
            if(memo[n]!=-1) return memo[n];
            int ans=0;
            for(int i=1;i<=n;i++){
                ans += solve(i-1,memo)*solve(n-i,memo);
            }
            return memo[n] = ans;
        }
        int numTrees(int n) { //recursion+memoizaion solution(top-down)
            vector<int> memo(n+1,-1);
            return solve(n,memo);
        }
    };