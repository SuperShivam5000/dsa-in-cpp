//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k,vector<int> &arr) {
        deque<int> dq;
        vector<int> ans;

        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            // Remove elements smaller than the current element from the back
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            // Add the current element's index to the deque
            dq.push_back(i);
        }

        // Process the rest of the array
        for (int i = k; i < arr.size(); i++) {
            // The element at the front of the deque is the largest in the previous window
            ans.push_back(arr[dq.front()]);

            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);
        }

        // Add the maximum for the last window
        ans.push_back(arr[dq.front()]);

        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends