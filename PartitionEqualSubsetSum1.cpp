//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sum(vector<int> &arr){
        int s=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
        }
        return s;
    }
    bool solve(vector<int> &arr, int i, int s, vector<vector<int>> &memo){
        if(s==0) return true;
        if(i==arr.size()) return false;
        if(memo[i][s]!=-1) return memo[i][s];
        
        bool include=false,exclude=false;
        if(s-arr[i]>=0) include=solve(arr,i+1,s-arr[i],memo);
        exclude=solve(arr,i+1,s,memo);
        
        return memo[i][s] = include||exclude;
    }
    bool equalPartition(vector<int> &arr) { //recursion+memoization approach(top-down)
        int s=sum(arr);
        if(s%2==1) return false;
        
        vector<vector<int>> memo(arr.size(),vector<int>(s/2+1,-1));
        return solve(arr,0,s/2,memo);
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends