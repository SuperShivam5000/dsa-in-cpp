class Solution {
    public:
        int maxSatisfaction(vector<int> &satisfaction) { //space optimized approach, can be further optimized similar to 01Knapsack question
            int n=satisfaction.size();
            sort(satisfaction.begin(),satisfaction.end());
            vector<int> curr(n+1,0); //memo[index]
            vector<int> next(n+1,0); //memo[index+1]
    
            for(int index=n-1;index>=0;index--){
                for(int time=index;time>=0;time--){
                    int include=satisfaction[index]*(time+1)+next[time+1];
                    int exclude=next[time];
                    curr[time] = max(include,exclude);
                }
                next=curr;
            }
            return curr[0];
        }
    };