class Solution {
    public:
        int minDistance(string &word1, string &word2) { //space optimized solution
            int n=word1.size();
            int m=word2.size();
            
            vector<int> curr(m+1,0); //memo[i]
            vector<int> next(m+1,0); //memo[i+1]
    
            for(int i=n;i>=0;i--){
                for(int j=m;j>=0;j--){
                    if(i==n) curr[j] = m-j; //moved base cases here for easy
                    else if(j==m) curr[j] = n-i;
                    else if(word1[i]==word2[j]) curr[j] = next[j+1];
                    else {
                        int a=1+curr[j+1]; //insert
                        int b=1+next[j]; //delete
                        int c=1+next[j+1]; //replace
                        curr[j] = min(a,min(b,c));
                    }
                }
                next=curr;
            }
            
            return next[0];
        }
    };