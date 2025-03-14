class Solution {
    public:
        int solve(vector<int> &satisfaction,int index,int time,vector<vector<int>> &memo){
            if(index==satisfaction.size()) return 0;
            if(memo[index][time]!=-1) return memo[index][time];
            int include=satisfaction[index]*time+solve(satisfaction,index+1,time+1,memo);
            int exclude=solve(satisfaction,index+1,time,memo);
            return memo[index][time] = max(include,exclude);
        }
        int maxSatisfaction(vector<int> &satisfaction) { //recursion+memoization approach(top-down)
            sort(satisfaction.begin(),satisfaction.end());
            vector<vector<int>> memo(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
            return solve(satisfaction,0,1,memo);
        }
    };