//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(vector<vector<int>> &mat,int i,int j,int &maxi, vector<vector<int>> &memo){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        int right=solve(mat,i+1,j,maxi,memo);
        int down=solve(mat,i,j+1,maxi,memo);
        int diagonal=solve(mat,i+1,j+1,maxi,memo);
        
        if(mat[i][j]==1) {
            int ans=1+min(right,min(down,diagonal));
            maxi=max(maxi,ans);
            memo[i][j]=ans;
            return memo[i][j];
        }
        else {
            memo[i][j]=0;
            return memo[i][j];
        }
    }
    int maxSquare(vector<vector<int>> &mat) { //recursion+memoization solution (top-down)
        int maxi=0;
        vector<vector<int>> memo(mat.size(),vector<int>(mat[0].size(),-1));
        solve(mat,0,0,maxi,memo);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends