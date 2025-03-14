class Solution {
    public:
        int longestCommonSubsequence(string &text1, string &text2) {
            int n=text1.size();
            int m=text2.size();
    
            vector<int> curr(m+1,0); //memo[i]
            vector<int> next(m+1,0); //memo[i+1]
    
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(text1[i]==text2[j]) curr[j] = 1+next[j+1];
                    else curr[j] = max(next[j],curr[j+1]);
                }
                next=curr;
            }
    
            return next[0];
        }
        int longestPalindromeSubseq(string s1) { //space optimized solution, based on LongestCommonSubsequence3
            string s2=s1;
            reverse(s2.begin(),s2.end());
            
            return longestCommonSubsequence(s1,s2);
        }
    };