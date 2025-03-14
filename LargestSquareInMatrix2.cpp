//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(vector<vector<int>> &mat) { //tabulation approach(bottom-up)
        int maxi=0;
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> memo(row+1,vector<int>(col+1,0));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=memo[i+1][j];
                int down=memo[i][j+1];
                int diagonal=memo[i+1][j+1];
                
                if(mat[i][j]==1) {
                    int ans=1+min(right,min(down,diagonal));
                    maxi=max(maxi,ans);
                    memo[i][j]=ans;
                }
                else {
                    memo[i][j]=0;
                }
            }
        }
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