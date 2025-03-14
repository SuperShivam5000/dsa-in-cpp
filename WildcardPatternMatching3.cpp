class Solution {
    public:
        bool isMatch(string &s, string &p) { //space optimized solution, tabulation index starting from 1
            int n=s.size();
            int m=p.size();
    
            vector<bool> prev(m+1,false); //memo[i-1]
            vector<bool> curr(m+1,false); //memo[i]

            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    if(i==0&&j==0) curr[j] = true; //move base cases here for easy
                    else if(i>0&&j==0) curr[j] = false;
                    else if(i==0&&j>0){ //all characters in pattern must be *
                        bool status=true;
                        for(int k=0;k<j;k++){
                            if(p[k]!='*') {
                                status = false;
                                break;
                            }
                        }
                        curr[j] = status;
                    }
                    else if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j] = prev[j-1];
                    else if(p[j-1]=='*') {
                        bool a=curr[j-1]; //replace * with empty string
                        bool b=prev[j]; //replace * with *x where x is a character
                        curr[j] = a||b;
                    }
                    else curr[j] = false;
                }
                prev=curr;
            }

            return curr[m];
        }
    };