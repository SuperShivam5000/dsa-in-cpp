class Solution {
    public:
        bool isMatch(string &s, string &p) { //tabulation solution(bottom-up), tabulation index starting from 1
            int n=s.size();
            int m=p.size();
    
            vector<vector<bool>> memo(n+1,vector<bool>(m+1,false));

            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    if(i==0&&j==0) memo[i][j] = true; //moved base cases here for easy
                    else if(i>0&&j==0) memo[i][j] = false;
                    else if(i==0&&j>0){ //all characters in pattern must be *
                        bool status=true;
                        for(int k=0;k<j;k++){
                            if(p[k]!='*') {
                                status = false;
                                break;
                            }
                        }
                        memo[i][j] = status;
                    }
                    else if(s[i-1]==p[j-1] || p[j-1]=='?') memo[i][j] = memo[i-1][j-1];
                    else if(p[j-1]=='*') {
                        bool a=memo[i][j-1]; //replace * with empty string
                        bool b=memo[i-1][j]; //replace * with *x where x is a character
                        memo[i][j] = a||b;
                    }
                    else memo[i][j] = false;
                }
            }

            return memo[n][m];
        }
    };