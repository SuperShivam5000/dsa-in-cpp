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
    bool equalPartition(vector<int> &arr) { //tabulation approach(bottom-up)
        int s=sum(arr);
        if(s%2==1) return false;
        
        vector<vector<int>> memo(arr.size()+1,vector<int>(s/2+1,0));
        for(int i=0;i<arr.size()+1;i++){ //base case
            memo[i][0]=1;
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            for(int j=s/2;j>=0;j--){
                bool include=false,exclude=false;
                if(j-arr[i]>=0) include=memo[i+1][j-arr[i]];
                exclude=memo[i+1][j];
                memo[i][j] = include||exclude;
            }
        }
        return memo[0][s/2];
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