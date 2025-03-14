//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool checkcelebrity(int p, vector<vector<int> >& mat, int size){
      for(int i=0;i<size;i++){
            if(i==p) continue;
            if(mat[p][i]!=0) return false;
        }
        for(int i=0;i<size;i++){
            if(i==p) continue;
            if(mat[i][p]!=1) return false;
        }
        return true;
  }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int size=mat.size();
        stack<int> s;
        for(int i=0;i<size;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(mat[a][b]==1) s.push(b);
            else s.push(a);
        }
        int potentialcelebrity = s.top();
        if(checkcelebrity(potentialcelebrity,mat,size)) return potentialcelebrity;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends