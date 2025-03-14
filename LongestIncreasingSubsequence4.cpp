//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int lis(vector<int> &arr) { //dp with binary search solution(most optimal) takes time complexity nlogn only instead of n^2
        int n=arr.size();
        vector<int> v;
        v.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>v.back()){ //back function returns last element of vector
                v.push_back(arr[i]);
            }
            else {
                int index=lower_bound(v.begin(),v.end(),arr[i]) - v.begin(); //element just bigger than arr[i]
                v[index]=arr[i];
            }
        }
        return v.size();
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