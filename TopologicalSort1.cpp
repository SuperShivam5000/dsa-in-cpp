#include <bits/stdc++.h>
void createAdj(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges, int e){
    for(int i=0;i<e;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
    }
}

void dfsTraversal(int i,vector<int> &visited, unordered_map<int,vector<int>> &adj, stack<int> &temp){
    visited[i]=true;
    for(int j=0;j<adj[i].size();j++){
        if(!visited[adj[i][j]]) dfsTraversal(adj[i][j],visited,adj,temp);
    }
    temp.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  { //this method use DFS, is easier
    unordered_map<int,vector<int>> adj;
    createAdj(adj,edges,e);
    vector<int> visited(v,false);
    stack<int> temp;
    for(int i=0;i<v;i++){
        if(!visited[i]) dfsTraversal(i,visited,adj,temp);
    }
    vector<int> ans;
    while(!temp.empty()){
        ans.push_back(temp.top());
        temp.pop();
    }
    return ans;
}