#include<bits/stdc++.h>
void toposort(int i,unordered_map<int,vector<int>> &adj,stack<int> &s,
vector<bool> &visited){
	visited[i]=true;
	for(auto &j:adj[i]){
		if(!visited[j]) toposort(j,adj,s,visited);
	}
	s.push(i);
}

void dfsTraversal(int i,unordered_map<int,vector<int>> &adj,
vector<bool> &visited){
	visited[i]=true;
	for(auto &j:adj[i]){
		if(!visited[j]) dfsTraversal(j,adj,visited);
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) //kosarajus algorithm for strongly connected components
{
	unordered_map<int,vector<int>> adj;
	unordered_map<int,vector<int>> transpose;

	//create adjacency list and transpose
	for(int i=0;i<edges.size();i++){
		int a=edges[i][0];
		int b=edges[i][1];

		adj[a].push_back(b);
		transpose[b].push_back(a);
	}

	//topological sort
	stack<int> s;
	vector<bool> visited(v,false);
	for(int i=0;i<v;i++){
		if(!visited[i]) toposort(i,adj,s,visited);
	}

	//perform dfs of transpose in topological sort order
	for(int i=0;i<v;i++) visited[i]=false; //reset visited vector
	int cnt=0;
	while(!s.empty()){
		int top=s.top();
		s.pop();
		if(!visited[top]){
			cnt++;
			dfsTraversal(top,transpose,visited);
		}
	}
	return cnt;
}