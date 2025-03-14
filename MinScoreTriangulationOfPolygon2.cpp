class Solution {
    public:
        int minScoreTriangulation(vector<int> &values) { //tabulation approach(bottom-up)
            int n=values.size();
            vector<vector<int>> memo(n,vector<int>(n,0));
            for(int i=n-1;i>=0;i--){
                for(int j=i+2;j<n;j++){ //i+2 because if i+1==j then ans is 0
                    int mini=INT_MAX;
                    for(int k=i+1;k<j;k++){
                        mini=min(mini,values[i]*values[j]*values[k]+memo[i][k]+memo[k][j]);
                    }
                    memo[i][j]=mini;
                }
            }
            return memo[0][n-1];
        }
    };