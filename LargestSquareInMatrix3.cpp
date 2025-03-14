//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(vector<vector<int>> &mat) { //space optimized approach, but can be further optimized from o(m) to o(1)
        int maxi=0;
        int row=mat.size();
        int col=mat[0].size();
        
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=next[j];
                int down=curr[j+1];
                int diagonal=next[j+1];
                
                if(mat[i][j]==1) {
                    int ans=1+min(right,min(down,diagonal));
                    maxi=max(maxi,ans);
                    curr[j]=ans;
                }
                else {
                    curr[j]=0;
                }
            }
            next=curr;
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