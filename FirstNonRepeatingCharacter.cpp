//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char,int> m;
		    string ans;
		    for(int i=0;i<A.size();i++){
		        char c=A[i];
		        m[c]++;
		        bool foundnonrepeating=false;
		        for(int i=0;i<A.size();i++){
		            if(m[A[i]]==1) {
		                ans.push_back(i);
		                foundnonrepeating=true;
		                break;
		            }
		        }
		        if(!foundnonrepeating) ans.push_back('#');
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends