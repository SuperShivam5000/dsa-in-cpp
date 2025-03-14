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
    bool equalPartition(vector<int> &arr) { //space optimized approach
        int s=sum(arr);
        if(s%2==1) return false;
        
        vector<int> next(s/2+1,0); //memo[i+1]
        vector<int> curr(s/2+1,0); //memo[i]
        next[0]=1;
        
        for(int i=arr.size()-1;i>=0;i--){
            for(int j=s/2;j>=0;j--){
                bool include=false,exclude=false;
                if(j-arr[i]>=0) include=next[j-arr[i]];
                exclude=next[j];
                curr[j] = include||exclude;
            }
            next=curr;
        }
        return next[s/2];
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