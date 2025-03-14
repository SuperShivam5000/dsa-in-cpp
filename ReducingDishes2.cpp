class Solution {
    public:
        int maxSatisfaction(vector<int> &satisfaction) { //tabulation approach(bottom-up)
            int n=satisfaction.size();
            sort(satisfaction.begin(),satisfaction.end());
            vector<vector<int>> memo(n+1,vector<int>(n+1,0));
            for(int index=n-1;index>=0;index--){
                for(int time=index;time>=0;time--){
                    int include=satisfaction[index]*(time+1)+memo[index+1][time+1];
                    int exclude=memo[index+1][time];
                    memo[index][time] = max(include,exclude);
                }
            }
            return memo[0][0];
        }
    };