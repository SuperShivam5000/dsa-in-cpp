class Solution {
    int solve(int s,int e, vector<vector<int>> &memo){
        if(s>=e) return 0;
        if(memo[s][e]!=-1) return memo[s][e];
        int maxi=INT_MAX;
        for(int i=s;i<=e;i++){
            maxi=min(maxi,i+max(solve(s,i-1,memo),solve(i+1,e,memo))); //max because worst case, min because minimum money
        }
        return memo[s][e] = maxi;
    }
public:
    int getMoneyAmount(int n) { //recursion+memoization solution(top-down)
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return solve(1,n,memo);
    }
};