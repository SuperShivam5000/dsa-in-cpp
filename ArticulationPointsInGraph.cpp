//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void dfsTraversal(int i,int parent,vector<int> adj[],int &timer,vector<int> &discoverytime,
        vector<int> &lowesttime,vector<bool> &visited,set<int> &result){
            visited[i]=true;
            discoverytime[i]=timer;
            lowesttime[i]=timer;
            timer++;
            int child=0;
            for(auto &j: adj[i]){
                if(j==parent) continue;
                if(!visited[j]){
                    dfsTraversal(j,i,adj,timer,discoverytime,lowesttime,visited,result);
                    lowesttime[i]=min(lowesttime[i],lowesttime[j]);
                    if(lowesttime[j]>=discoverytime[i]&&parent!=-1) result.insert(i);
                    child++;
                }else{
                    lowesttime[i]=min(lowesttime[i],discoverytime[j]);
                }
            }
            if(parent==-1 && child>1) result.insert(i);
        }

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) { //this solution uses tarjan's algo similar to bridges in a graph question
        int parent=-1;
        int timer=0;
        vector<int> discoverytime(V,-1);
        vector<int> lowesttime(V,-1);
        vector<bool> visited(V,false);
        set<int> result; //we use set for to filter out repeated vertices
        
        for(int i=0;i<V;i++){
            if(!visited[i]) dfsTraversal(i,parent,adj,timer,discoverytime,lowesttime,visited,result);
        }
        vector<int> ans; //add all elements from set to vector before returning
        for(auto &i: result){
            ans.push_back(i);
        }
        if(ans.empty()) ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends