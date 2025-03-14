class Solution {
    public:
        void precomputemax(vector<int> &arr, int n, vector<vector<int>> &maxi){
            for(int i=0;i<n;i++){
                int currmax=INT_MIN;
                for(int j=i;j<n;j++){
                    currmax=max(currmax,arr[j]);
                    maxi[i][j]=currmax;
                }
            }
        }
    
        int solve(vector<int> &arr,vector<vector<int>> &maxi,int s,int e,vector<vector<int>> &memo){
            if(s==e) return 0;
            if(memo[s][e]!=-1) return memo[s][e];
            int ans=INT_MAX;
            for(int i=s;i<e;i++){
                ans=min(ans,maxi[s][i]*maxi[i+1][e]+solve(arr,maxi,s,i,memo)+solve(arr,maxi,i+1,e,memo));
            }
            return memo[s][e] = ans;
        }
    
        int mctFromLeafValues(vector<int> &arr) { //recursion+memoization solution(top-down, o(n^3)) can be solved in o(n) using stack
            int n=arr.size();

            vector<vector<int>> maxi(n,vector<int>(n,-1));
            precomputemax(arr,n,maxi);
    
            vector<vector<int>> memo(n,vector<int>(n,-1));
            return solve(arr,maxi,0,n-1,memo);
        }
    };