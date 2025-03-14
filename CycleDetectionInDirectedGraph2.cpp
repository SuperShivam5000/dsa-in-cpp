#include <bits/stdc++.h>
void createAdj(unordered_map<int,vector<int>> &adj, vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int a=edges[i].first;
        int b=edges[i].second;
        adj[a].push_back(b);
    }
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) { //this method use Kahn's Algo/BFS and is harder
  unordered_map<int,vector<int>> adj;
  createAdj(adj,edges);
  vector<int> indegree(n+1,0); //n+1 because 1 based indexing
  for(int i=0;i<edges.size();i++){
      indegree[edges[i].second]++;
  }
  queue<int> q;
  for(int i=1;i<=n;i++){ //loop running 1 to <=n because 1 based indexing
      if(indegree[i]==0) q.push(i);
  }
  int cnt=0;
  while(!q.empty()){
      int top = q.front();
      q.pop();
      cnt++;
      for(auto &i: adj[top]){
          indegree[i]--;
          if(indegree[i]==0) q.push(i);
      }
  }
  if(cnt==n) return false;
  else return true;
}