//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MinSquares(int n) { //tabulation approach(bottom-up)
        vector<int> memo(n+1,INT_MAX);
        memo[0]=0;
        for(int i=1;i<=n;i++){
            int ans=INT_MAX;
            for(int j=1;j*j<=i;j++){
                if(i-j*j>=0) ans=min(ans,1+memo[i-j*j]);
            }
            memo[i]=ans;
        }
        return memo[n];
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