class Solution {
    public:
        int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &memo){
            if(i==text1.size() || j==text2.size()) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
            
            if(text1[i]==text2[j]) return memo[i][j] = 1+solve(i+1,j+1,text1,text2,memo);
            else return memo[i][j] = max(solve(i+1,j,text1,text2,memo),solve(i,j+1,text1,text2,memo));
        }
        int longestCommonSubsequence(string &text1, string &text2) { //recursion+memoization solution(top-down)
            vector<vector<int>> memo(text1.size(),vector<int>(text2.size(),-1));
            return solve(0,0,text1,text2,memo);
        }
    };