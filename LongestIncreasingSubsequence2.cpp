//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int> &arr) { //tabulation solution(bottom-up)
        int n=arr.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int l=i-1;l>=-1;l--){
                //include
                int include=0;
                if(l==-1 || arr[i]>arr[l]) include = 1+memo[i+1][i+1];
                
                //exclude
                int exclude = memo[i+1][l+1];
                
                memo[i][l+1] = max(include,exclude);
            }
        }
        return memo[0][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends