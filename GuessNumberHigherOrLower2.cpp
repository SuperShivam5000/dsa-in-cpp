class Solution {
    public:
        int getMoneyAmount(int n) { //tabulation solution(bottom-up)
            vector<vector<int>> memo(n+2,vector<int>(n+2,0));
            for(int s=n;s>=1;s--){
                for(int e=s+1;e<=n;e++){
                    int maxi=INT_MAX;
                    for(int i=s;i<=e;i++){
                        maxi=min(maxi,i+max(memo[s][i-1],memo[i+1][e])); //max because worst case, min because minimum money
                    }
                    memo[s][e] = maxi;
                }
            }
            return memo[1][n];
        }
    };