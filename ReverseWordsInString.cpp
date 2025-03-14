//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        if(str=="") return "";
        int l=str.length();
        string current="";
        for(int i=l-1;i>=0;i--){
            if(str[i]=='.'){
                return current+"."+reverseWords(str.substr(0,i));
            } //write this
            current=str[i]+current;
        }
        return current;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends