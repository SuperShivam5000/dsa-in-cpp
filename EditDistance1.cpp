class Solution {
    public:
        int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &memo){
            if(i == word1.size()) return word2.size() - j;
            if(j == word2.size()) return word1.size() - i;
    
            if(memo[i][j]!=-1) return memo[i][j];
    
            if(word1[i]==word2[j]) return memo[i][j] = solve(i+1,j+1,word1,word2,memo);
            int a=1+solve(i,j+1,word1,word2,memo); //insert
            int b=1+solve(i+1,j,word1,word2,memo); //delete
            int c=1+solve(i+1,j+1,word1,word2,memo); //replace
            return memo[i][j] = min(a,min(b,c));
        }
        int minDistance(string &word1, string &word2) { //recursion+memoization solution(top-down)
            vector<vector<int>> memo(word1.size(),vector<int>(word2.size(),-1));
            return solve(0,0,word1,word2,memo);
        }
    };