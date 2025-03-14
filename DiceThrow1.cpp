//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int n, int x, vector<vector<int>> &memo){
        if(n==0){
            if(x==0) return 1;
            else return 0;
        }
        if(memo[n][x]!=-1) return memo[n][x];
        
        int temp=0;
        for(int i=1;i<=m;i++){
            if(x-i>=0) temp+=solve(m,n-1,x-i,memo);
        }
        return memo[n][x] = temp;
    }
    int noOfWays(int m, int n, int x) { //recursion+memoization approach(top-down)
        vector<vector<int>> memo(n+1,vector<int>(x+1,-1));
        return solve(m,n,x,memo);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        int m, n, x;
        cin >> m >> n >> x;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends