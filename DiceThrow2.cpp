//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int noOfWays(int m, int n, int x) { //tabulation approach(bottom-up)
        vector<vector<int>> memo(n+1,vector<int>(x+1,0));
        memo[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++){
                int temp=0;
                for(int k=1;k<=m;k++){
                    if(j-k>=0) temp+=memo[i-1][j-k];
                }
                memo[i][j] = temp;
            }
        }
        return memo[n][x];
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