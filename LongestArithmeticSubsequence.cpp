//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) { //can also be done using recursion/memoization and tabulation but this is simplest and most optimal solution
        int n=arr.size();
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int lastno=arr[i];
                int diff=arr[j]-arr[i];
                int cnt=2;
                for(int k=i-1;k>=0;k--){
                    if(lastno-diff==arr[k]){
                        cnt++;
                        lastno=arr[k];
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends