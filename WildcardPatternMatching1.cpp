class Solution {
    public:
        bool solve(int i, int j, string &s, string &p, vector<vector<int>> &memo){
            if(i<0&&j<0) return true;
            if(i>=0&&j<0) return false;
            if(i<0&&j>=0){ //all characters in pattern must be *
                for(int k=0;k<=j;k++){
                    if(p[k]!='*') return false;
                }
                return true;
            }
            
            if(memo[i][j]!=-1) return memo[i][j];
    
            if(s[i]==p[j] || p[j]=='?') return memo[i][j] = solve(i-1,j-1,s,p,memo);
            else if(p[j]=='*') {
                bool a=solve(i,j-1,s,p,memo); //replace * with empty string
                bool b=solve(i-1,j,s,p,memo); //replace * with *x where x is a character
                return memo[i][j] = a||b;
            }
            else return memo[i][j] = false;
        }
        bool isMatch(string &s, string &p) { //recursion+memoization solution(top-down)
            int n=s.size();
            int m=p.size();
    
            vector<vector<int>> memo(n,vector<int>(m,-1));
            return solve(n-1,m-1,s,p,memo);
        }
    };