class Solution {
    public:
        int numTrees(int n) { //tabulation approach(bottom-up)
            vector<int> memo(n+1,1);
            for(int i=2;i<=n;i++){
                int ans=0;
                for(int j=1;j<=i;j++){
                    ans += memo[j-1]*memo[i-j];
                }
                memo[i] = ans;
            }
            return memo[n];
        }
    };