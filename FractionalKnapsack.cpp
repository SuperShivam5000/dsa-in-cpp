//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  static bool cmp(Item a,Item b){
      double avalue=(double)a.value/a.weight;
      double bvalue=(double)b.value/b.weight;
      return avalue>bvalue;
  }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, cmp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<=w){
                ans=ans+arr[i].value;
                w=w-arr[i].weight;
            }
            else {
                ans=ans+arr[i].value*((double)w/arr[i].weight);
                w=0;
            }
            if(w==0) break;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends