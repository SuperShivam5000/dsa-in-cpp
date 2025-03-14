class Solution {
    public:
        int minDistance(string &word1, string &word2) { //tabulation solution(bottom-up)
            int n=word1.size();
            int m=word2.size();
    
            vector<vector<int>> memo(n+1,vector<int>(m+1,0));
            for(int i=0;i<n;i++) memo[i][m]=word1.size() - i;
            for(int j=0;j<m;j++) memo[n][j]=word2.size() - j;
    
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(word1[i]==word2[j]) memo[i][j] = memo[i+1][j+1];
                    else {
                        int a=1+memo[i][j+1]; //insert
                        int b=1+memo[i+1][j]; //delete
                        int c=1+memo[i+1][j+1]; //replace
                        memo[i][j] = min(a,min(b,c));
                    }
                }
            }
            return memo[0][0];
        }
    };