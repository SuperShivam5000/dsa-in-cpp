class Solution {
    public:
        int solve(vector<int> &values, int i, int j, vector<vector<int>> &memo){
            if(i+1==j) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
    
            int mini=INT_MAX;
            for(int k=i+1;k<j;k++){
                mini=min(mini,values[i]*values[j]*values[k]+solve(values,i,k,memo)+solve(values,k,j,memo));
            }
            memo[i][j]=mini;
            return memo[i][j];
        }
        int minScoreTriangulation(vector<int> &values) { //recursion+memoization approach(top-down)
            int n=values.size();
            vector<vector<int>> memo(n,vector<int>(n,-1));
            return solve(values,0,n-1,memo);
        }
    };