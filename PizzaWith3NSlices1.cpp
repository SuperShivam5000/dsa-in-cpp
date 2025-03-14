class Solution {
    public:
        int solve(vector<int> &slices, int index, int n, int end, vector<vector<int>> &memo) {
            if(n==0||index>end) return 0;
            if(memo[index][n]!=-1) return memo[index][n];
            int include= slices[index] + solve(slices,index+2,n-1,end,memo);
            int exclude= solve(slices,index+1,n,end,memo);
            return memo[index][n] = max(include, exclude);
        }
        int maxSizeSlices(vector<int> &slices) { //recursion+memoization approach (top-down)
            int k=slices.size();
            vector<vector<int>> memo1(k,vector<int>(k,-1));
            vector<vector<int>> memo2(k,vector<int>(k,-1));
            int case1=solve(slices,0,k/3,k-2,memo1);
            int case2=solve(slices,1,k/3,k-1,memo2);
            return max(case1,case2);
        }
    };