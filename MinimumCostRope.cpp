//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long,vector<long long>,greater<long long>> h;
        for(int i=0;i<arr.size();i++){
            h.push(arr[i]);
        }
        long long totalcost=0;
        while(h.size()>1){
            long long a=h.top();
            h.pop();
            long long b=h.top();
            h.pop();
            long long c=a+b;
            totalcost+=c;
            h.push(c);
        }
        return totalcost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends