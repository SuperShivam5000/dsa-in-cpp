//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n,vector<int> &memo) {
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i,memo));
        }
        memo[n] = ans;
        return memo[n];
    }
    int MinSquares(int n) { //recursion+memoization solution (top-down)
        vector<int> memo(n+1,-1);
        return solve(n,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends