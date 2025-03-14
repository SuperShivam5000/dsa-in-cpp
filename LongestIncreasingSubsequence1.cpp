//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int solve(vector<int> &arr, int i, int l, vector<vector<int>> &memo) {
        if(i==arr.size()) return 0;
        if(memo[i][l]!=-1) return memo[i][l];
        //include
        int include=0;
        if(l==-1 || arr[i]>arr[l]) include = 1+solve(arr,i+1,i,memo);
        
        //exclude
        int exclude = solve(arr,i+1,l,memo);
        
        return memo[i][l] = max(include,exclude);
    }
    int lis(vector<int> &arr) { //recursion+memoization solution(top-down)
        int n=arr.size();
        vector<vector<int>> memo(n, vector<int>(n+1,-1));
        return solve(arr,0,-1,memo);
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