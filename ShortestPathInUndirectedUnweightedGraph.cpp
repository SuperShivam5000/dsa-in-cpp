#include<bits/stdc++.h>
void createAdj(unordered_map<int,vector<int>> &adj, vector<pair<int,int>> &edges, int m){
	for(int i=0;i<m;i++){
		int a=edges[i].first;
		int b=edges[i].second;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t){
	unordered_map<int,vector<int>> adj;
	createAdj(adj,edges,m);
	vector<bool> visited(n+1);
	vector<int> parent(n+1);
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(auto &i: adj[top]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=top;
				q.push(i);
			}
		}
	}
	vector<int> ans;
	for(int i=t;i!=s;i=parent[i]){
		ans.push_back(i);
	}
	ans.push_back(s);
	reverse(ans.begin(),ans.end());
	return ans;
}
